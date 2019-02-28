package main

import (
	"fmt"
)

type Status int

const (
	kOk      Status = iota // 0
	kWarning               // 1
	kFatal                 // 2
)

func main() {
	t := kWarning
	fmt.Println(t)
	fmt.Printf("%d\n", t)
}
