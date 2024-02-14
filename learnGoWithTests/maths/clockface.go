package clockface

import (
	"math"
	"time"
)

const (
	secondHandLength   = 90
	minuteHandLength   = 80
	hourHandLength     = 50
	clockCentreX       = 150
	clockCentreY       = 150
	secondsInHalfClock = 30
	minutesInHalfClock = 30
	hoursInHalfClock   = 6
	hoursInClock       = 2 * hoursInHalfClock
)

type Point struct {
	X float64
	Y float64
}

func secondsInRadians(t time.Time) float64 {
	return math.Pi / (secondsInHalfClock / float64(t.Second()))
}

func minutesInRadians(t time.Time) float64 {
	return secondsInRadians(t)/60 + math.Pi/(minutesInHalfClock/float64(t.Minute()))
}

func hoursInRadians(t time.Time) float64 {
	return minutesInRadians(t)/hoursInClock + math.Pi/(hoursInHalfClock/float64(t.Hour()%hoursInClock))
}

func secondHandPoint(t time.Time) Point {
	return angleToPoint(secondsInRadians(t))
}

func minuteHandPoint(t time.Time) Point {
	return angleToPoint(minutesInRadians(t))
}

func hourHandPoint(t time.Time) Point {
	return angleToPoint(hoursInRadians(t))
}

func angleToPoint(angle float64) Point {
	x := math.Sin(angle)
	y := math.Cos(angle)
	return Point{x, y}
}
