package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	var err error
	var v map[string]interface{}
	err = json.Unmarshal([]byte(nil), &v)
	if err != nil {
		fmt.Println("err", err)
	} else {
		fmt.Println("ok", v)
	}
}
