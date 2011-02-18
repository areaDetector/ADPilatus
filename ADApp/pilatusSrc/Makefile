TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

LIBRARY_IOC_Linux = pilatusDetector
LIBRARY_IOC_Darwin = pilatusDetector
PROD_IOC_Linux += pilatusDetectorApp
PROD_IOC_Darwin += pilatusDetectorApp

USR_INCLUDES += -I$(TOP)/ADApp/cbfSrc

LIB_SRCS += pilatusDetector.cpp
# <name>.dbd will be created from <name>Include.dbd
DBD += pilatusDetectorApp.dbd
DBD += pilatusDetectorSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
PROD_SRCS += pilatusDetectorApp_registerRecordDeviceDriver.cpp pilatusDetectorAppMain.cpp

# Add locally compiled object code
PROD_LIBS += pilatusDetector
PROD_LIBS += cbfad

include $(TOP)/ADApp/commonDriverMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

