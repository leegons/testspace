package main

import (
	"fmt"
	"time"
)

func main() {
	queue := make(chan int, 10)
	queue2 := make(chan int, 10)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println("product ", i)
			queue <- i
			time.Sleep(time.Duration(100) * time.Millisecond)
		}
	}()

	go func() {
		for i := 100; i < 120; i++ {
			fmt.Println("productB ", i)
			queue2 <- i
			time.Sleep(time.Duration(10) * time.Millisecond)
		}
	}()

	finish := make(chan int, 1)
	go func() {
		time.Sleep(time.Duration(500) * time.Second)
		close(finish)
	}()

	for i := 0; i < 10; i++ {
		select {
		case t := <-queue:
			fmt.Println("consumer:", t)
		case t := <-queue2:
			fmt.Println("consumer:", t)
		case <-finish:
			fmt.Println("finish")
			break
		}
	}
}
