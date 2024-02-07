package main

import (
	"bytes"
	"reflect"
	"testing"
	"time"
)

const write = "write"
const sleep = "sleep"

type SpySleeper struct {
	Calls int
}

func (s *SpySleeper) Sleep() {
	s.Calls++
}

type SpyCoundownOperations struct {
	Calls []string
}

func (s *SpyCoundownOperations) Sleep() {
	s.Calls = append(s.Calls, sleep)
}

func (s *SpyCoundownOperations) Write(p []byte) (n int, err error) {
	s.Calls = append(s.Calls, write)
	return
}

type SpyTime struct {
	durationSlept time.Duration
}

func (s *SpyTime) Sleep(duration time.Duration) {
	s.durationSlept = duration
}

func TestCountdown(t *testing.T) {
	t.Run("prints 3 to Go!", func(t *testing.T) {
		// Dependency
		buffer := &bytes.Buffer{}

		// Test method
		Countdown(buffer, &SpyCoundownOperations{})
		got := buffer.String()
		want := `3
2
1
Go!`

		// Assertion
		if got != want {
			t.Errorf("got %q want %q", got, want)
		}
	})

	t.Run("sleep before every print", func(t *testing.T) {
		// Dependency
		spySleepPrinter := &SpyCoundownOperations{}

		// Test method
		Countdown(spySleepPrinter, spySleepPrinter)
		got := spySleepPrinter.Calls
		want := []string{
			write,
			sleep,
			write,
			sleep,
			write,
			sleep,
			write,
		}

		// Assertion
		if !reflect.DeepEqual(got, want) {
			t.Errorf("wanted calls %v got %v", want, got)
		}
	})
}

func TestConfigurableSleeper(t *testing.T) {
	// Dependency
	spyTime := &SpyTime{}

	// Test method
	want := 5 * time.Second
	sleeper := ConfigurableSleeper{want, spyTime.Sleep}
	sleeper.Sleep()
	got := spyTime.durationSlept

	if got != want {
		t.Errorf("should have slept for %v but slept for %v", want, got)
	}

}
