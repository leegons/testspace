package main

import (
	"fmt"
	"strings"
)

func mprint(s string) {
	fmt.Printf("[%d]:", len(s))
	fmt.Printf("'%s'\n", s)
}

func startWith(query, key string) (string, bool) {
	if len(query) < len(key) {
		return "", false
	}
	if query[:len(key)] == key {
		return query[len(key):], true
	}
	return "", false
}

func main() {
	r := strings.Split("a", "\n")
	fmt.Println(len(r), r)

	mprint(strings.Join([]string{}, ","))
	mprint(strings.Join([]string{"a"}, ","))

	l, ok := startWith("你是好人", "你是")
	fmt.Println(l, ok)
}
