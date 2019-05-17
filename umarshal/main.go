package main

import (
	"encoding/json"
	"log"
)

func main() {
	s := `{"a":[],"b":1,"c":"s"}`
	var v interface{}
	if err := json.Unmarshal([]byte(s), &v); err != nil {
		log.Println(err)
	}
	log.Printf("v:%+v\n", v)
	log.Println(v.(map[string]interface{})["a"])
}
