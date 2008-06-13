/* pilatusDetector.cpp
 *
 * This is a driver for a Pilatus pixel array detector.
 *
 * Author: Mark Rivers
 *         University of Chicago
 *
 * Created:  June 11, 2008
 *
 */
 
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsEvent.h>
#include <epicsMutex.h>
#include <epicsString.h>
#include <epicsStdio.h>
#include <epicsMutex.h>
#include <cantProceed.h>

#include "ADStdDriverParams.h"
#include "NDArray.h"
#include "ADDriver.h"

#include "drvPilatusDetector.h"


static char *driverName = "pialtusDetector";

class pilatusDetector : public ADDriver {
public:
    pilatusDetector(const char *portName, const char *camserverPort,
                    int maxBuffers, size_t maxMemory);
                 
    /* These are the methods that we override from ADDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
    virtual asynStatus drvUserCreate(asynUser *pasynUser, const char *drvInfo, 
                                     const char **pptypeName, size_t *psize);
    void report(FILE *fp, int details);
                                        
    /* These are the methods that are new to this class */
    void pilatusTask();

    /* Our data */
    int imagesRemaining;
    epicsEventId startEventId;
    epicsEventId stopEventId;
};

/* If we have any private driver parameters they begin with ADFirstDriverParam and should end
   with ADLastDriverParam, which is used for setting the size of the parameter library table */
typedef enum {
    PilatusGainX 
        = ADFirstDriverParam,
    PilatusGainY,
    PilatusResetImage,
    ADLastDriverParam
} PilatusDetParam_t;

static asynParamString_t PilatusDetParamString[] = {
    {PilatusGainX,          "SIM_GAINX"},  
    {PilatusGainY,          "SIM_GAINY"},  
    {PilatusResetImage,     "RESET_IMAGE"},  
};

#define NUM_SIM_DET_PARAMS (sizeof(PilatusDetParamString)/sizeof(PilatusDetParamString[0]))

static void pilatusTaskC(void *drvPvt)
{
    pilatusDetector *pPvt = (pilatusDetector *)drvPvt;
    
    pPvt->pilatusTask();
}

void pilatusDetector::pilatusTask()
{
    /* This thread computes new image data and does the callbacks to send it to higher layers */
    int status = asynSuccess;
    int dataType;
    int addr=0;
    int imageSizeX, imageSizeY, imageSize;
    int imageCounter;
    int acquire, autoSave;
    ADStatus_t acquiring;
    NDArray *pImage;
    double acquireTime, acquirePeriod, delay;
    epicsTimeStamp startTime, endTime;
    double elapsedTime;
    static char *functionName = "pilatusTask";

    /* Loop forever */
    while (1) {
    
        epicsMutexLock(this->mutexId);

        /* Is acquisition active? */
        getIntegerParam(addr, ADAcquire, &acquire);
        
        /* If we are not acquiring then wait for a semaphore that is given when acquisition is started */
        if (!acquire) {
            setIntegerParam(addr, ADStatus, ADStatusIdle);
            callParamCallbacks(addr, addr);
            /* Release the lock while we wait for an event that says acquire has started, then lock again */
            epicsMutexUnlock(this->mutexId);
            asynPrint(this->pasynUser, ASYN_TRACE_FLOW, 
                "%s:%s: waiting for acquire to start\n", driverName, functionName);
            status = epicsEventWait(this->startEventId);
            epicsMutexLock(this->mutexId);
        }
        
        /* We are acquiring. */
        /* Get the current time */
        epicsTimeGetCurrent(&startTime);
        
        /* Get the exposure parameters */
        getDoubleParam(addr, ADAcquireTime, &acquireTime);
        getDoubleParam(addr, ADAcquirePeriod, &acquirePeriod);
        
        acquiring = ADStatusAcquire;
        setIntegerParam(addr, ADStatus, acquiring);

        /* Call the callbacks to update any changes */
        callParamCallbacks(addr, addr);

        /* Simulate being busy during the exposure time.  Use epicsEventWaitWithTimeout so that
         * manually stopping the acquisition will work */
        if (acquireTime >= epicsThreadSleepQuantum()) {
            epicsMutexUnlock(this->mutexId);
            status = epicsEventWaitWithTimeout(this->stopEventId, acquireTime);
            epicsMutexLock(this->mutexId);
        }
        
        /* Update the image */
        computeImage();
        pImage = this->pArrays[addr];
        
        epicsTimeGetCurrent(&endTime);
        elapsedTime = epicsTimeDiffInSeconds(&endTime, &startTime);

        /* Get the current parameters */
        getIntegerParam(addr, ADImageSizeX, &imageSizeX);
        getIntegerParam(addr, ADImageSizeY, &imageSizeY);
        getIntegerParam(addr, ADImageSize,  &imageSize);
        getIntegerParam(addr, ADDataType,   &dataType);
        getIntegerParam(addr, ADAutoSave,   &autoSave);
        getIntegerParam(addr, ADImageCounter, &imageCounter);
        imageCounter++;
        setIntegerParam(addr, ADImageCounter, imageCounter);
        
        /* Put the frame number and time stamp into the buffer */
        pImage->uniqueId = imageCounter;
        pImage->timeStamp = startTime.secPastEpoch + startTime.nsec / 1.e9;
        
        /* Call the NDArray callback */
        /* Must release the lock here, or we can get into a deadlock, because we can
         * block on the plugin lock, and the plugin can be calling us */
        epicsMutexUnlock(this->mutexId);
        asynPrint(this->pasynUser, ASYN_TRACE_FLOW, 
             "%s:%s: calling imageData callback\n", driverName, functionName);
        doCallbacksGenericPointer(pImage, NDArrayData, addr);
        epicsMutexLock(this->mutexId);

        /* See if acquisition is done */
        if (this->imagesRemaining > 0) this->imagesRemaining--;
        if (this->imagesRemaining == 0) {
            acquiring = ADStatusIdle;
            setIntegerParam(addr, ADAcquire, acquiring);
            asynPrint(this->pasynUser, ASYN_TRACE_FLOW, 
                  "%s:%s: acquisition completed\n", driverName, functionName);
        }
        
        /* Call the callbacks to update any changes */
        callParamCallbacks(addr, addr);
        
        
        /* If we are acquiring then sleep for the acquire period minus elapsed time. */
        if (acquiring) {
            /* We set the status to readOut to indicate we are in the period delay */
            setIntegerParam(addr, ADStatus, ADStatusReadout);
            callParamCallbacks(addr, addr);
            /* We are done accessing data structures, release the lock */
            epicsMutexUnlock(this->mutexId);
            delay = acquirePeriod - elapsedTime;
            asynPrint(this->pasynUser, ASYN_TRACE_FLOW, 
                     "%s:%s: delay=%f\n",
                      driverName, functionName, delay);            
            if (delay >= epicsThreadSleepQuantum())
                status = epicsEventWaitWithTimeout(this->stopEventId, delay);

        } else {
            /* We are done accessing data structures, release the lock */
            epicsMutexUnlock(this->mutexId);
        }
    }
}


asynStatus pilatusDetector::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int adstatus;
    int addr=0;
    asynStatus status = asynSuccess;

    /* Set the parameter and readback in the parameter library.  This may be overwritten when we read back the
     * status at the end, but that's OK */
    status = setIntegerParam(addr, function, value);

    /* For a real detector this is where the parameter is sent to the hardware */
    switch (function) {
    case ADAcquire:
        getIntegerParam(addr, ADStatus, &adstatus);
        if (value && (adstatus == ADStatusIdle)) {
            /* We need to set the number of images we expect to collect, so the image callback function
               can know when acquisition is complete.  We need to find out what mode we are in and how
               many images have been requested.  If we are in continuous mode then set the number of
               remaining images to -1. */
            int imageMode, numImages;
            status = getIntegerParam(addr, ADImageMode, &imageMode);
            status = getIntegerParam(addr, ADNumImages, &numImages);
            switch(imageMode) {
            case ADImageSingle:
                this->imagesRemaining = 1;
                break;
            case ADImageMultiple:
                this->imagesRemaining = numImages;
                break;
            case ADImageContinuous:
                this->imagesRemaining = -1;
                break;
            }
            /* Send an event to wake up the pilatus task.  
             * It won't actually start generating new images until we release the lock below */
            epicsEventSignal(this->startEventId);
        } 
        if (!value && (adstatus != ADStatusIdle)) {
            /* This was a command to stop acquisition */
            /* Send the stop event */
            epicsEventSignal(this->stopEventId);
        }
        break;
    case ADBinX:
    case ADBinY:
    case ADMinX:
    case ADMinY:
    case ADSizeX:
    case ADSizeY:
    case ADDataType:
        status = setIntegerParam(addr, PilatusResetImage, 1);
        break;
    case ADImageMode: 
        /* The image mode may have changed while we are acquiring, 
         * set the images remaining appropriately. */
        switch (value) {
        case ADImageSingle:
            this->imagesRemaining = 1;
            break;
        case ADImageMultiple: {
            int numImages;
            getIntegerParam(addr, ADNumImages, &numImages);
            this->imagesRemaining = numImages; }
            break;
        case ADImageContinuous:
            this->imagesRemaining = -1;
            break;
        }
        break;
    }
    
    /* Do callbacks so higher layers see any changes */
    callParamCallbacks(addr, addr);
    
    if (status) 
        asynPrint(pasynUser, ASYN_TRACE_ERROR, 
              "%s:writeInt32 error, status=%d function=%d, value=%d\n", 
              driverName, status, function, value);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:writeInt32: function=%d, value=%d\n", 
              driverName, function, value);
    return status;
}


asynStatus pilatusDetector::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
    int function = pasynUser->reason;
    asynStatus status = asynSuccess;
    int addr=0;

    /* Set the parameter and readback in the parameter library.  This may be overwritten when we read back the
     * status at the end, but that's OK */
    status = setDoubleParam(addr, function, value);

    /* Changing any of the following parameters requires recomputing the base image */
    switch (function) {
    case ADAcquireTime:
    case ADGain:
    case PilatusGainX:
    case PilatusGainY:
        status = setIntegerParam(addr, PilatusResetImage, 1);
        break;
    }

    /* Do callbacks so higher layers see any changes */
    callParamCallbacks(addr, addr);
    if (status) 
        asynPrint(pasynUser, ASYN_TRACE_ERROR, 
              "%s:writeFloat64 error, status=%d function=%d, value=%f\n", 
              driverName, status, function, value);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:writeFloat64: function=%d, value=%f\n", 
              driverName, function, value);
    return status;
}


/* asynDrvUser routines */
asynStatus pilatusDetector::drvUserCreate(asynUser *pasynUser,
                                      const char *drvInfo, 
                                      const char **pptypeName, size_t *psize)
{
    asynStatus status;
    int param;
    const char *functionName = "drvUserCreate";

    /* See if this is one of our standard parameters */
    status = findParam(PilatusDetParamString, NUM_SIM_DET_PARAMS, 
                       drvInfo, &param);
                                
    if (status == asynSuccess) {
        pasynUser->reason = param;
        if (pptypeName) {
            *pptypeName = epicsStrDup(drvInfo);
        }
        if (psize) {
            *psize = sizeof(param);
        }
        asynPrint(pasynUser, ASYN_TRACE_FLOW,
                  "%s:%s: drvInfo=%s, param=%d\n", 
                  driverName, functionName, drvInfo, param);
        return(asynSuccess);
    }
    
    /* If not, then see if it is a base class parameter */
    status = ADDriver::drvUserCreate(pasynUser, drvInfo, pptypeName, psize);
    return(status);  
}
    
void pilatusDetector::report(FILE *fp, int details)
{
    int addr=0;

    fprintf(fp, "Pilatus detector %s\n", this->portName);
    if (details > 0) {
        int nx, ny, dataType;
        getIntegerParam(addr, ADSizeX, &nx);
        getIntegerParam(addr, ADSizeY, &ny);
        getIntegerParam(addr, ADDataType, &dataType);
        fprintf(fp, "  NX, NY:            %d  %d\n", nx, ny);
        fprintf(fp, "  Data type:         %d\n", dataType);
    }
    /* Invoke the base class method */
    ADDriver::report(fp, details);
}

extern "C" int pilatusDetectorConfig(const char *portName, int maxSizeX, int maxSizeY, int dataType,
                                 int maxBuffers, size_t maxMemory)
{
    new pilatusDetector(portName, maxSizeX, maxSizeY, (NDDataType_t)dataType, maxBuffers, maxMemory);
    return(asynSuccess);
}

pilatusDetector::pilatusDetector(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
                         int maxBuffers, size_t maxMemory)

    : ADDriver(portName, 1, ADLastDriverParam, maxBuffers, maxMemory, 0, 0), 
      imagesRemaining(0), pRaw(NULL)

{
    int status = asynSuccess;
    char *functionName = "pilatusDetector";
    int addr=0;
    int dims[2];

    /* Create the epicsEvents for signaling to the pilatus task when acquisition starts and stops */
    this->startEventId = epicsEventCreate(epicsEventEmpty);
    if (!this->startEventId) {
        printf("%s:%s epicsEventCreate failure for start event\n", 
            driverName, functionName);
        return;
    }
    this->stopEventId = epicsEventCreate(epicsEventEmpty);
    if (!this->stopEventId) {
        printf("%s:%s epicsEventCreate failure for stop event\n", 
            driverName, functionName);
        return;
    }
    
    /* Allocate the raw buffer we use to compute images.  Only do this once */
    dims[0] = maxSizeX;
    dims[1] = maxSizeY;
    this->pRaw = this->pNDArrayPool->alloc(2, dims, dataType, 0, NULL);

    /* Set some default values for parameters */
    status =  setStringParam (addr, ADManufacturer, "Dectris");
    status |= setStringParam (addr, ADModel, "Pilatus");
    status |= setIntegerParam(addr, ADMaxSizeX, maxSizeX);
    status |= setIntegerParam(addr, ADMaxSizeY, maxSizeY);
    status |= setIntegerParam(addr, ADSizeX, maxSizeX);
    status |= setIntegerParam(addr, ADSizeX, maxSizeX);
    status |= setIntegerParam(addr, ADSizeY, maxSizeY);
    status |= setIntegerParam(addr, ADImageSizeX, maxSizeX);
    status |= setIntegerParam(addr, ADImageSizeY, maxSizeY);
    status |= setIntegerParam(addr, ADImageSize, 0);
    status |= setIntegerParam(addr, ADDataType, dataType);
    status |= setIntegerParam(addr, ADImageMode, ADImageContinuous);
    status |= setDoubleParam (addr, ADAcquireTime, .001);
    status |= setDoubleParam (addr, ADAcquirePeriod, .005);
    status |= setIntegerParam(addr, ADNumImages, 100);
    status |= setIntegerParam(addr, PilatusResetImage, 1);
    status |= setDoubleParam (addr, PilatusGainX, 1);
    status |= setDoubleParam (addr, PilatusGainY, 1);
    if (status) {
        printf("%s: unable to set camera parameters\n", functionName);
        return;
    }
    
    /* Create the thread that updates the images */
    status = (epicsThreadCreate("PilatusDetTask",
                                epicsThreadPriorityMedium,
                                epicsThreadGetStackSize(epicsThreadStackMedium),
                                (EPICSTHREADFUNC)pilatusTaskC,
                                this) == NULL);
    if (status) {
        printf("%s:%s epicsThreadCreate failure for image task\n", 
            driverName, functionName);
        return;
    }
}
