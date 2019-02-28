package main

import (
	"fmt"

	"github.com/leegons/testspace/go/common"
)

func newInt(x int) *int {
	v := x
	return &v
}

func withThread() {
	t := 1
	go func() {
		for {
			t += 1
			common.SleepMS(100)
			fmt.Println(t)
		}
	}()
}

func testWriteVar() {
	g := newInt(0)
	go func() {
		for {
			fmt.Println("thread1 g:", *g)
			common.RandSleepMS(100)
		}
	}()
	go func() {
		for {
			fmt.Println("thread2 g:", *g)
			common.RandSleepMS(200)
		}
	}()

	for i := 0; i < 1000; i++ {
		g = newInt(i)
		common.RandSleepMS(100)
	}
}

func main() {
	withThread()
	fmt.Println("back to main()")
	common.RandSleepMS(10000)
	fmt.Println("ready exit")
}
