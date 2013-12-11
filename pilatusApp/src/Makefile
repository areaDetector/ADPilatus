TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#======== DETECTOR LIBRARY ==============

LIBRARY_IOC_Linux = pilatusDetector
LIBRARY_IOC_Darwin = pilatusDetector

USR_INCLUDES += -I$(TOP)/ADApp/cbfSrc

LIB_SRCS += pilatusDetector.cpp

DBD += pilatusDetectorSupport.dbd

#====== DETECTOR APPLICATION ============

ifeq ($(BUILD_APPS), YES)
PROD_NAME = pilatusDetectorApp
PROD_IOC_Linux  += $(PROD_NAME)
PROD_IOC_Darwin += $(PROD_NAME)

# <name>.dbd will be created from <name>Include.dbd
DBD += $(PROD_NAME).dbd
$(PROD_NAME)_DBD += pilatusDetectorSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
PROD_SRCS += $(PROD_NAME)_registerRecordDeviceDriver.cpp $(PROD_NAME)Main.cpp

# Add locally compiled object code
PROD_LIBS += pilatusDetector
PROD_LIBS += cbfad

include $(TOP)/ADApp/commonDriverMakefile
$(PROD_NAME)_DBD += drvAsynIPPort.dbd
endif

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

