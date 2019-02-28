package main

import (
	"fmt"
	"math/rand"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func(idx int) {
			defer wg.Done()
			for i := 0; i < 3; i++ {
				fmt.Println(idx, rand.Int31())
			}
		}(i)
	}
	wg.Wait()
}
