all: test prints

test: test.cc
	g++ -g -std=c++11 -lcurses test.cc -o test

prints: prints.cc
	g++ -g -std=c++11 -lcurses prints.cc -o prints

clean:
	rm test prints
