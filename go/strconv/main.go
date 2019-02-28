package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	fmt.Println("----")
	var t int64 = (1 << 63) - 1
	fmt.Println(t)
	s := fmt.Sprintf("%d", t)
	fmt.Println(s)
	res, err := strconv.ParseInt(s, 10, 64)
	fmt.Println(res, err, reflect.TypeOf(res))

	res2, err2 := strconv.Atoi(s)
	fmt.Println(res2, err2, reflect.TypeOf(res2))

	var x uintptr = 11111111111111111111
	fmt.Printf("%v\n", x)
}
