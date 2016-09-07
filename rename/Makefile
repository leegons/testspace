SRCS := $(wildcard *.cc)
BINS := $(patsubst %.cc, %, ${SRCS})

.PHONY: all
all: $(BINS)

%: %.cc
	g++ -g -std=c++11 $@.cc -o $@
