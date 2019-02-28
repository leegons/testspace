package main

import (
	"encoding/json"
	"log"
)

type Node struct {
	Val  int
	Next *Node
}

func main() {
	n := &Node{100, nil}
	n.Next = n

	log.Println("begin marshal")
	if s, err := json.Marshal(n); err != nil {
		log.Printf("err: %+v\n", err)
	} else {
		log.Printf("ok, n:%+v ret:%+v\n", n, string(s))
	}
}
