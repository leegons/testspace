output: main

lib.so: lib.go
	go build -o $@ -buildmode=c-shared $<

main: lib.so test.cc
	gcc -v test.cc -o main ./lib.so

.PHONY: clean
clean:
	rm -f lib.so
	rm -f main
