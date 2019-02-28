package main

import (
	"fmt"
)

func testEmpty() {
	m := make(map[string]string, 0)
	fmt.Printf("%+v\n", m["fds"] == "") // true
}

func main() {
	testEmpty()
}
