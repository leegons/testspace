package main

import "fmt"

func a(x int) int {
	fmt.Println("a")
	return x
}

func f() int {
	x := 1
	defer func() {
		x = 3
		fmt.Println("defer")
	}()
	return a(x)
}

func prt(x int) {
	fmt.Println("got:", x)
}

func main() {
	t := f()
	fmt.Println(t)

	x := 0
	defer func() {
		prt(x)
	}()
	x = 100
}
