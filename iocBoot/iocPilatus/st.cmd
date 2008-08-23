< envPaths
errlogInit(20000)

dbLoadDatabase("$(AD)/dbd/pilatusDetectorApp.dbd")
pilatusDetectorApp_registerRecordDeviceDriver(pdbbase) 

###
# Create the asyn port to talk to the Pilatus on port 41234.
drvAsynIPPortConfigure("camserver","gse-pilatus2:41234")
# Set the input and output terminators.
asynOctetSetInputEos("camserver", 0, "\030")
asynOctetSetOutputEos("camserver", 0, "\n")

pilatusDetectorConfig("Pil", "camserver", 487, 195, 50, 200000000)
dbLoadRecords("$(AD)/ADApp/Db/ADBase.template",   "P=13PIL1:,R=cam1:,PORT=Pil,ADDR=0,TIMEOUT=1")
dbLoadRecords("$(AD)/ADApp/Db/pilatus.template","P=13PIL1:,R=cam1:,PORT=Pil,ADDR=0,TIMEOUT=1,CAMSERVER_PORT=camserver")

# Create a standard arrays plugin
drvNDStdArraysConfigure("PilImage", 5, 0, "Pil", 0, -1)
dbLoadRecords("$(AD)/ADApp/Db/NDPluginBase.template","P=13PIL1:,R=image1:,PORT=PilImage,ADDR=0,TIMEOUT=1,NDARRAY_PORT=Pil,NDARRAY_ADDR=0")
dbLoadRecords("$(AD)/ADApp/Db/NDStdArrays.template", "P=13PIL1:,R=image1:,PORT=PilImage,ADDR=0,TIMEOUT=1,SIZE=32,FTVL=LONG,NELEMENTS=94965")

# Create an ROI plugin
drvNDROIConfigure("PilROI", 5, 0, "Pil", 0, 10, -1)
dbLoadRecords("$(AD)/ADApp/Db/NDPluginBase.template","P=13PIL1:,R=ROI1:,  PORT=PilROI,ADDR=0,TIMEOUT=1,NDARRAY_PORT=Pil,NDARRAY_ADDR=0")
dbLoadRecords("$(AD)/ADApp/Db/NDROI.template",       "P=13PIL1:,R=ROI1:,  PORT=PilROI,ADDR=0,TIMEOUT=1")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:0:,PORT=PilROI,ADDR=0,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:1:,PORT=PilROI,ADDR=1,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:2:,PORT=PilROI,ADDR=2,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:3:,PORT=PilROI,ADDR=3,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:4:,PORT=PilROI,ADDR=3,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:5:,PORT=PilROI,ADDR=3,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:6:,PORT=PilROI,ADDR=3,TIMEOUT=1,HIST_SIZE=256")
dbLoadRecords("$(AD)/ADApp/Db/NDROIN.template",      "P=13PIL1:,R=ROI1:7:,PORT=PilROI,ADDR=3,TIMEOUT=1,HIST_SIZE=256")


#asynSetTraceMask("Pil",0,255)
#asynSetTraceMask("PilROI",0,3)
#asynSetTraceIOMask("PilROI",0,4)

# Load scan records for scanning energy threshold
dbLoadRecords("$(SSCAN)/sscanApp/Db/scan.db", "P=13PIL1:cam1:,MAXPTS1=2000,MAXPTS2=200,MAXPTS3=20,MAXPTS4=10,MAXPTSH=10")

set_requestfile_path("./")
set_savefile_path("./autosave")
set_requestfile_path("$(AD)/ADApp/Db")
set_requestfile_path("$(SSCAN)/sscanApp/Db")
set_pass0_restoreFile("auto_settings.sav")
set_pass1_restoreFile("auto_settings.sav")
save_restoreSet_status_prefix("13PIL1:")
dbLoadRecords("$(AUTOSAVE)/asApp/Db/save_restoreStatus.db", "P=13PIL1:")

iocInit()

# save things every thirty seconds
create_monitor_set("auto_settings.req", 30,"P=13PIL1:,D=cam1:")
