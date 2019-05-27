package main

import (
	"errors"
	"fmt"
)

func main() {
	var (
		a = errors.New("timeout")
		b = a
		c = a
	)
	fmt.Printf("%+v == %+v ? %v\n", b, c, b == c)
}
