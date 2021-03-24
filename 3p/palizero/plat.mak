PLAT=unx
SOEXT ?= .so

ifneq (,$(wildcard macos))
PLAT=mac
endif

ifneq (,$(wildcard mingw))
PLAT=mgw
SOEXT=.dll.a
endif


