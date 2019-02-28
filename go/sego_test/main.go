package main

import (
	"bufio"
	"os"
	"strings"
)

func main() {
	seg := NewSegmenter("dictionary.txt")

	f, _ := os.Open("input.txt")
	defer f.Close()

	r := bufio.NewReader(f)
	for {
		if s, err := r.ReadString('\n'); err == nil {
			seg.ParseAndPrint(strings.Trim(s, " \r\n\t"))
		} else {
			break
		}
	}
}
