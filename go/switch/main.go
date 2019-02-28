package main

import "fmt"

func main() {
	a, b := 1, 2

	switch {
	case a == 1:
		fmt.Println("a==1")
	case b == 2:
		fmt.Println("b==2")
	}
}
