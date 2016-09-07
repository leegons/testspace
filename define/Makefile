test: a.o test.cc
	g++ -g -std=c++11 -I. -L. test.cc a.o -o test

%.o: %.cc
	g++ -g -std=c++11 $< -c
