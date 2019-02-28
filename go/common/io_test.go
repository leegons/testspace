package common

import (
	"testing"
	//    "fmt"
)

func TestDealFile(t *testing.T) {
	var s string
	DealFile("./test.txt", func(line string) bool {
		s += line
		//fmt.Println(line)
		return true
	})
	if s != "abc123test line" {
		t.Error("deal file fail")
	}
}
