CXX		:= g++
TARGET	:= $(PROJNAME)$(EXT)

HDRS	:= $(shell python mk/pyfind.py include .h)

USRCS	:= $(wildcard src/*.cpp)
LSRCS	:= $(shell python mk/pyfind.py lib .cpp)
ALLSRCS := $(USRCS) $(LSRCS)

UOBJS   := $(USRCS:.cpp=.o)
LOBJS   := $(LSRCS:.cpp=.o)

DEPS	:= $(USRCS:.cpp=.d) $(LSRCS:.cpp=.d)

ifeq ($(PLATFORM), Windows)
	DOBJS := $(subst /,\,$(UOBJS)) $(subst /.\,$(LOBJS))
else
	DOBJS := $(UOBJS) $(LOBJS)
endif

CFLAGS	:= -std=c++11 -Iinclude -MMD

.PHONY: all
all: $(TARGET) ## build application (default)

$(TARGET):	$(UOBJS) $(LOBJS)
	g++ -o $@ $^ $(LFLAGS)

%.o:	%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

.PHONY:	run
run:	$(TARGET)	## launch primary build application
	$(PREFIX)$(TARGET)

.PHONY: clean
clean:	## remove all build artifacts
	$(RM) $(TARGET) $(DOBJS) $(DEPS)

-include $(DEPS)
