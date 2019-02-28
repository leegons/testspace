package main

import (
	"fmt"
	"log"
	"regexp"
)

func main() {
	re, err := regexp.Compile(`<at.*at>(?s)(.*)$`)
	if err != nil {
		panic(err)
	}
	res := re.FindAllSubmatch([]byte(`<at id='fdsafdsa'>fdas
	af</at> hello`), 1)

	// TODO: remove it
	log.Printf("res = %+v\n", res)

	if len(res) != 1 || len(res[0]) != 2 {
		panic("fail")
	}
	need := string(res[0][1])
	fmt.Println(need)
}
