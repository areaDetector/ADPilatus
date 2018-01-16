TOP = ..
include $(TOP)/configure/CONFIG

DIRS := $(DIRS) cbfSrc
DIRS := $(DIRS) src
src_DEPEND_DIRS += cbfSrc
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard *db*))
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard *Db*))
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard *op*))

include $(TOP)/configure/RULES_DIRS

