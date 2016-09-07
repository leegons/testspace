SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc, %.o, ${SRCS})
BINS := test

.PHONY: all
all: $(OBJS) $(BINS)

.PHONY: clean
clean:
	rm $(OBJS) -f
	rm $(BINS) -f

$(OBJS): %.o : %.cc
	g++ -c -g -std=c++11 $^ -o $@

$(BINS): % : %.cc
	g++ -g -std=c++11 ${OBJS} -o $@
