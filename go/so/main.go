package main

import (
	"fmt"
)

func Proc1() {
	fmt.Println("proc1")
}
func Proc2() {
	fmt.Println("proc2")
}

func deal(conf []string) {
	s := map[string]func(){
		"proc1": Proc1,
		"proc2": Proc2,
	}
	for _, v := range conf {
		s[v]()
	}
}

func main() {

	deal([]string{"proc1", "proc2", "proc1", "proc2"})
	deal([]string{"proc1", "proc2", "proc2", "proc1"})
}
