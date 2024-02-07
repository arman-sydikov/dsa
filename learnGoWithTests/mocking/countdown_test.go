package main

import (
	"bytes"
	"testing"
)

type SpySleeper struct {
	Calls int
}

func (s *SpySleeper) Sleep() {
	s.Calls++
}

func TestCountdown(t *testing.T) {
	// Dependency
	buffer := &bytes.Buffer{}
	spySleeper := &SpySleeper{}

	// Test method
	Countdown(buffer, spySleeper)
	got := buffer.String()
	want := `3
2
1
Go!`

	// Assertion
	if got != want {
		t.Errorf("got %q want %q", got, want)
	}
	if spySleeper.Calls != 3 {
		t.Errorf("not enough calls to sleeper, want 3 got %d", spySleeper.Calls)
	}
}
