package main

import (
	"flag"
	"fmt"
)

var (
	appID string
)

func main() {
	flag.StringVar(&appID, "appid", "", "app id")
	flag.Parse()

	if appID == "" {
		flag.Usage()
		return
	}

	fmt.Println(appID)
}
