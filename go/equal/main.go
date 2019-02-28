package main

import "fmt"

func main() {
	fmt.Println("vim-go")

	var i1 interface{}
	var i2 interface{}
	d1 := 1
	d2 := 2

	i1 = d1
	i2 = d2
	fmt.Println(i1, i2, i1 == i2)

	d2 = 1
	i2 = d2
	fmt.Println(i1, i2, i1 == i2)
}
