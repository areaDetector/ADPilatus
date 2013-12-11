TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

LIBRARY_IOC_Linux = pilatusDetector
LIBRARY_IOC_Darwin = pilatusDetector

USR_INCLUDES += -I$(TOP)/pilatusApp/cbfSrc

LIB_SRCS += pilatusDetector.cpp

DBD += pilatusDetectorSupport.dbd

include $(ADCORE)/ADApp/commonLibraryMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

