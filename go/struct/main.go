package main

import (
	"fmt"
	"unsafe"
)

func main() {
	fmt.Printf("sizeof(struct{}):%d\n", unsafe.Sizeof(struct{}{}))

	m := map[string]struct{}{}
	m["abc"] = struct{}{}
	m["abcd"] = struct{}{}
	m["ab"] = struct{}{}
	m["a"] = struct{}{}
	m[""] = struct{}{}

	for key, _ := range m {
		fmt.Println(key)
	}
}
