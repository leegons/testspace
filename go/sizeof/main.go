package main

import "fmt"
import "unsafe"

func main() {
	var t1 []interface{}  // = 24
	var t2 *[]interface{} // = 8
	var t3 bool           // = 1
	var t4 interface{}    // = 16
	var t5 byte           // = 1
	var t6 int            // = 8
	var t7 int32          // = 4
	var t8 int64          // = 8
	var t9 float32        // = 4
	var ta float64        // = 8

	fmt.Println(unsafe.Sizeof(t1))
	fmt.Println(unsafe.Sizeof(t2))
	fmt.Println(unsafe.Sizeof(t3))
	fmt.Println(unsafe.Sizeof(t4))
	fmt.Println(unsafe.Sizeof(t5))
	fmt.Println(unsafe.Sizeof(t6))
	fmt.Println(unsafe.Sizeof(t7))
	fmt.Println(unsafe.Sizeof(t8))
	fmt.Println(unsafe.Sizeof(t9))
	fmt.Println(unsafe.Sizeof(ta))

	var s1 struct {
		a int  // = 8
		b bool // = 1 (1/8)
	} // = 16
	fmt.Println(unsafe.Sizeof(s1))

	var s2 struct {
		a bool  // = 1
		b bool  // = 1 (1/4)
		c int32 // = 4
	} // = 8
	fmt.Println(unsafe.Sizeof(s2))

	type Node struct {
		a map[byte]*Node // = 8
		b bool           // = 1 (1/8)
	} // = 16
	s3 := Node{a: make(map[byte]*Node)}
	fmt.Println(unsafe.Sizeof(s3))
}
