package main

import (
	"encoding/json"
	"fmt"
	"log"
	"sync"
)

type Test struct {
	NilTest map[string]interface{} `json:"nil_test"`
	TestInt *int                   `json:"nil_int"`
}

func main2() {
	defer func() {
		recover()
	}()
	t := &Test{}
	data, err := json.Marshal(t)
	if err != nil {
		log.Fatalln(err)
	}
	fmt.Printf("go res:'%+v'\n", string(data))

	m := map[string]string{}

	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer func() { recover() }()
		for i := 0; i < 100; i++ {
			m[fmt.Sprintf("a%d", i)] = "testa"
		}
		wg.Done()
	}()
	//wg.Wait()
	wg.Add(1)
	go func() {
		defer func() { recover() }()
		for i := 0; i < 100; i++ {
			m[fmt.Sprintf("b%d", i)] = "testb"
		}
		wg.Done()
	}()
	wg.Wait()
}

func main() {
	defer func() {
		// TODO: remove it
		log.Println("lijian.f==== test1")
	}()
	defer func() {
		if x := recover(); x != nil {
			// TODO: remove it
			log.Printf("x = %+v\n", x)
		}
		// TODO: remove it
		log.Println("lijian.f==== test2")
	}()
	defer func() {
		// TODO: remove it
		log.Println("lijian.f==== test3")
	}()
	panic("test")
}
