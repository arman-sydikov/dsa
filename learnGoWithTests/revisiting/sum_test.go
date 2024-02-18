package main

import (
	"testing"
)

func TestReduce(t *testing.T) {
	t.Run("multiplication of all elements", func(t *testing.T) {
		multiply := func(x, y int) int {
			return x * y
		}
		AssertEqual(t, Reduce([]int{1, 2, 3}, multiply, 1), 6)
	})
	t.Run("concatenate strings", func(t *testing.T) {
		concat := func(x, y string) string {
			return x + y
		}
		AssertEqual(t, Reduce([]string{"hello", "world"}, concat, ""), "helloworld")
	})
}

func TestBadBank(t *testing.T) {
	transactions := []Transaction{
		{
			From: "Chris",
			To:   "Riya",
			Sum:  100,
		},
		{
			From: "Adil",
			To:   "Chris",
			Sum:  25,
		},
	}

	AssertEqual(t, BalanceFor(transactions, "Riya"), 100.0)
	AssertEqual(t, BalanceFor(transactions, "Chris"), -75.0)
	AssertEqual(t, BalanceFor(transactions, "Adil"), -25.0)
}

func AssertEqual(t testing.TB, got, want any) {
	t.Helper()
	if got != want {
		t.Errorf("got %+v, want %+v", got, want)
	}
}
