package common

import (
	"bufio"
	"os"
	"strings"
)

// DealFile until cb return false
func DealFile(filename string, cb func(string) bool) bool {
	f, err := os.Open(filename)
	if err != nil {
		return false
	}
	defer f.Close()

	r := bufio.NewReader(f)
	for {
		if s, err := r.ReadString('\n'); err == nil {
			if ok := cb(strings.Trim(s, "\r\n")); !ok {
				return false
			}
		} else {
			break
		}
	}
	return true
}
