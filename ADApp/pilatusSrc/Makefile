TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#USR_CFLAGS += 
#USR_CXXFLAGS +=

LIBRARY_IOC = pilatusDetector
LIB_SRCS += pilatusDetector.cpp
LIB_SRCS += drvPilatusDetectorEpics.c
LIB_LIBS += ADBase ADPlugin netCDF
LIB_LIBS += sscan autosave
LIB_LIBS += asyn
LIB_LIBS += $(EPICS_BASE_IOC_LIBS)

#==================================
PROD_IOC += pilatusDetectorApp
# <name>.dbd will be created from <name>Include.dbd
DBD += pilatusDetectorApp.dbd
DBD += pilatusDetectorSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
pilatusDetectorApp_SRCS_DEFAULT += pilatusDetectorApp_registerRecordDeviceDriver.cpp pilatusDetectorAppMain.cpp
pilatusDetectorApp_SRCS_vxWorks += pilatusDetectorApp_registerRecordDeviceDriver.cpp

# Add locally compiled object code
pilatusDetectorApp_LIBS += pilatusDetector
pilatusDetectorApp_LIBS += ADPlugin ADBase netCDF
pilatusDetectorApp_LIBS += sscan autosave 
pilatusDetectorApp_LIBS += asyn
pilatusDetectorApp_LIBS += $(EPICS_BASE_IOC_LIBS)

pilatusDetectorCCDApp_SYS_LIBS_cygwin32 += rpc

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

