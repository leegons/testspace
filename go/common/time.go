package common

import (
	"math/rand"
	"time"
)

func SleepMS(x int) {
	time.Sleep(time.Duration(x) * time.Millisecond)
}

func RunAfterSleepMS(x int, cb func()) {
	SleepMS(x)
	cb()
}

func RandSleepMS(x int) {
	SleepMS(rand.Intn(x))
}
