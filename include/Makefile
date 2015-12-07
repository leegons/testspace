INCPATH=./

SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc, %.o, ${SRCS})
LIBOBJS := $(filter-out main.o , $(OBJS))

.PHONY:all
all:libts.a main
	@echo all done

.PHONY:main
main: $(OBJS)
	g++ $(OBJS) libts.a -I. -o main


libts.a : $(LIBOBJS)
	ar crs libts.a $(LIBOBJS)

%.o : %.cc
	g++ -c -I. -o $@ $<

.PHONY:clean
clean:
	@rm -rf *.o *.a main
	@echo clean done
