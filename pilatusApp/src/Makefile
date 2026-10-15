TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

LIBRARY_IOC_Linux = pilatusDetector
LIBRARY_IOC_Darwin = pilatusDetector

LIB_SRCS += pilatusDetector.cpp

ifeq ($(CBF_EXTERNAL), YES)
  USR_CPPFLAGS += -DCBF_EXTERNAL
  ifdef CBF_INCLUDE
    USR_INCLUDES += $(addprefix -I, $(CBF_INCLUDE))
  endif
endif

DBD += pilatusDetectorSupport.dbd

include $(ADCORE)/ADApp/commonLibraryMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

