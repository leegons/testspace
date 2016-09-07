SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc, %.o, ${SRCS})
BINS := $(patsubst %.cc, %, ${SRCS})

.PHONY: all clean
all: $(BINS)

$(OBJS): $(gcc -MM *.cc)
	g++ -g -std=c++11 $@

$(BINS): %: %.o
	g++ -g -std=c++11 $@.o -o $@

clean:
	rm -f $(BINS) $(OBJS)
