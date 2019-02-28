package main

import (
	"bytes"
	"fmt"
)

func main() {
	var buffer bytes.Buffer
	fmt.Printf("nil_buff:%+v\n", buffer.String())

	fmt.Printf("%s\n", []byte{229, 189, 169, 232, 155, 139})
}
