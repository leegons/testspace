LIBS=head.o sort.o traversal.o
TARGET=link_test tree_test traversal_test

.PHONY: output clean
output: $(LIBS) $(TARGET)


clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.cc
	g++ -std=c++11 -c $^ -o $@

$(TARGET): % : $(LIBS) %.o
	g++ -std=c++11 $^ -o $@

