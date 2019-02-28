package main

import "fmt"

func main() {
	ch := make(chan string)
	var ch2 chan int

	fmt.Printf("ch:%+v\n", ch)
	fmt.Printf("ch2:%+v\n", ch2)
	fmt.Printf("ch2 == nil:%+v\n", ch2 == nil)
}
