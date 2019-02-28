package main

import (
	"fmt"
	"strconv"
	"strings"
	"sync"
)

type Test struct {
	i int
	s string
}

func test1() {
	fmt.Println(interface{}(3) == interface{}(3))
	fmt.Println(interface{}(Test{1, "hello"}) == interface{}(Test{1, "hello"}))

	t := Test{3, "John"}
	var i interface{} = t
	fmt.Println(i.(Test) == t)

	t.i = 9
	fmt.Println(i, t, i.(Test) == t)
}

type Item struct {
	Map map[string]interface{}
}

func test2() {
	var wg sync.WaitGroup
	results := make([]Item, 100)
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(index int) {
			defer wg.Done()
			weather := map[string]interface{}{
				"moji_city_id": float64(1.0),
				"other":        "test",
			}
			if m, found := weather["moji_city_id"]; found {
				if id, ok := m.(float64); ok {
					weather["extra"] = strings.Join([]string{
						"prefix",
						strconv.FormatFloat(id, 'f', -1, 64),
					}, ",")
				}
			}
			//fmt.Printf("weather%d: %+v\n", index, weather)
			results[index] = Item{weather}
		}(i)
	}
	wg.Wait()
	fmt.Println(results)
}

func main() {
	//test1()
	test2()
}
