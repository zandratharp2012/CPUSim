TSTSRCS	:= $(wildcard tests/*.cpp)
TSTOBJS	:= $(TSTSRCS:.cpp=.o)
DOBJS	+= $(TSTOBJS)

TSTTGT	:= testapp$(EXT)

.PHONY:	test
test:	$(TSTTGT)	## Run project unit tests using catch.hpp
	$(PREFIX)$(TSTTGT)

$(TSTTGT):  $(TSTOBJS) $(LOBJS)
	$(CXX) $(LFLAGS) -o $@ $^