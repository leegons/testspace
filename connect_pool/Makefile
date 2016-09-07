SRCS := $(wildcard *.cc)
BINS := $(patsubst %.cc, %, ${SRCS})

.PHONY: all
all: $(BINS)

%: %.cc
	g++ -g -lpthread -std=c++11 $@.cc -o $@
