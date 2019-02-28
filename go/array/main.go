package main

import (
	"fmt"
)

type Test struct {
	A int
	B string
}

func main() {
	arr := make([]Test, 0, 1)
	arr[0] = Test{0, "test"}
	fmt.Println(arr)
}

func test2() {
	var arr []int // = nil
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))

	fmt.Println("after----")

	arr = make([]int, 0, 10)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))
	arr = append(arr, 12)
	fmt.Println(arr, len(arr), cap(arr))

	fmt.Println("sec 2 ----")

	type Ty struct {
		Name  string
		Class string
	}

	t := Ty{"abc", "def"}
	fmt.Printf("%+v\n", t)

	/*
		for _, v := range arr[1:] {
			fmt.Println(v)
		}
	*/

	/* Error
	t := 2
	for range t {
		fmt.Print("hello")
	}
	*/

	/*
		fmt.Println("try print nil:")
		var emptyArr []int = nil
		for _, v := range emptyArr {
			fmt.Println(v)
		}
	*/
}
