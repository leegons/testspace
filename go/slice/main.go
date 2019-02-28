package main

import "fmt"

type Item struct {
	name string
}

func main() {
	arr := []Item{{"one"}, {"two"}, {"three"}}

	arr1 := []*Item{}
	arr2 := []*Item{}

	for index, item1 := range arr {
		item2 := arr[index]
		arr1 = append(arr1, &item1)
		arr2 = append(arr2, &item2)
	}
	fmt.Printf("%+v\n", arr1)
	fmt.Printf("%+v\n", arr2)

	t := make([]string, 0)
	fmt.Println(t == nil, len(t))

	m := map[string]string{}
	fmt.Printf("%s|%s\n", m["a"], m["b"])
}
