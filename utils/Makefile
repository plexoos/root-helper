#
# Makefile for utils
#

ARCH         := $(shell root-config --arch)
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)
ROOTLDFLAGS  := $(shell root-config --nonew --ldflags)

# Linux with egcs, gcc 2.9x, gcc 3.x (>= RedHat 5.2)
CXX           = g++
INC_PATHS     = -I.

# if you plan to do a whole lot of debugging, remove '-O' switch(es)
CXXFLAGS      = -g -O -Wall -fPIC $(INC_PATHS) $(ROOTCFLAGS) -fno-inline

LD            = g++
LDFLAGS       = -g $(ROOTLDFLAGS)
SOFLAGS       = -shared $(LDFLAGS)
LIBS          = $(ROOTLIBS)

#------------------------------------------------------------------------------
LIB  = libutils.so

ROOT_DICT_SRC = utils_dict.cxx
ROOT_DICT_HDR = $(ROOT_DICT_SRC:.cxx=.h)
ROOT_DICT_OBJ = $(ROOT_DICT_SRC:.cxx=.o)
ROOT_DICT     = $(ROOT_DICT_SRC) $(ROOT_DICT_HDR) $(ROOT_DICT_OBJ)

SRCS_CC  = $(wildcard *.cc)
SRCS_CXX = $(wildcard *.cxx)
HDRS_CC  = $(SRCS_CC:.cc=.h)
HDRS_CXX = $(SRCS_CXX:.cxx=.h)
OBJS_CC  = $(SRCS_CC:.cc=.o)
OBJS_CXX = $(SRCS_CXX:.cxx=.o)

SRCS = $(SRCS_CC) $(SRCS_CXX)
HDRS = $(HDRS_CC) $(HDRS_CXX)
OBJS = $(OBJS_CC) $(OBJS_CXX) $(ROOT_DICT_OBJ)

#------------------------------------------------------------------------------
all: lib

lib: $(LIB)

$(LIB): $(OBJS)
	$(LD) $(SOFLAGS) $(OBJS) $(LIBS) -o $(LIB)
	@echo "$@ done"

$(ROOT_DICT_SRC): ValErrPair.h ProtoEvent.h PlotHelper.h LinkDef.h
	@echo "Generating dictionary $(ROOT_DICT_SRC)..."
	@echo rootcint -f $(ROOT_DICT_SRC) -c -I. $^
	@rootcint -f $(ROOT_DICT_SRC) -c -I. $^

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cxx %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(ROOT_DICT_OBJ) : $(ROOT_DICT_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "removing binaries and supplementary files..."
	rm -f $(OBJS)
	rm -f $(LIB)
	rm -f $(ROOT_DICT)

cleanall: clean
