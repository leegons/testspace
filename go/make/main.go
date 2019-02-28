package main

import "fmt"

func main() {
	t0 := make([]int, 0)
	fmt.Println(t0, len(t0), cap(t0))

	t00 := make([]int, 0, 0)
	fmt.Println(t00, len(t00), cap(t00))

	t01 := make([]int, 0, 1)
	fmt.Println(t01, len(t01), cap(t01))
	t01 = append(t01, 1)
	fmt.Println(t01, len(t01), cap(t01))
}
