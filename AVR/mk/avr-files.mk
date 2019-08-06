# source files
CSRCS	:= $(wildcard src/*.c)
CXXSRCS	:= $(wildcard src/*.cpp)
SSRCS	:= $(wildcard src/*.S)

# required object files
COBJS	:= $(CSRCS:.c=.o)
CXXOBJS	:= $(CXXSRCS:.cpp=.o)
SOBJS	:= $(SSRCS:.S=.o)
OBJS	:= $(COBJS) $(CXXOBJS) $(SOBJS)
LST		:= $(TARGET).lst