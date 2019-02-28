package common

import "testing"

func TestSleepMS(t *testing.T) {
	x := 1
	go func() {
		SleepMS(10)
		x = 2
	}()

	SleepMS(9)
	if x != 1 {
		t.Error("fail")
	}

	SleepMS(2)
	if x != 2 {
		t.Error("fail")
	}
}

func TestRunAfterSleepMS(t *testing.T) {
	x := 1
	go RunAfterSleepMS(10, func() {
		x = 2
		t.Log("set x=2")
	})

	SleepMS(9)
	t.Log("test x=1")
	if x != 1 {
		t.Error("fail")
	}

	SleepMS(2)
	t.Log("test x=2")
	if x != 2 {
		t.Error("fail")
	}
}

func TestRandSleepMS(t *testing.T) {
	ch := make(chan int)
	x := 1
	go func() {
		// 100 * 100 / 2 = 5s +- (2s)
		for i := 0; i < 100; i++ {
			RandSleepMS(100)
		}
		x = 2
		ch <- 2
	}()

	SleepMS(3000)
	if x != 1 {
		t.Error("sorry")
	}

	SleepMS(4000)
	if x != 2 {
		t.Error("sorry")
	}

	<-ch
}
