package generics

import (
	"testing"
)

func TestAssertFunctions(t *testing.T) {
	t.Run("asserting on ingeters", func(t *testing.T) {
		AssertEqual(t, 1, 1)
		AssertNotEqual(t, 1, 2)
	})
	t.Run("asserting on strings", func(t *testing.T) {
		AssertEqual(t, "hello", "hello")
		AssertNotEqual(t, "hello", "Grace")
	})
}

func AssertNotEqual[T comparable](t *testing.T, got, want T) {
	t.Helper()
	if got == want {
		t.Errorf("didn't want %+v", got)
	}
}

func AssertEqual[T comparable](t *testing.T, got, want T) {
	t.Helper()
	if got != want {
		t.Errorf("got %+v, want %+v", got, want)
	}
}

func AssertTrue(t *testing.T, got bool) {
	t.Helper()
	if !got {
		t.Errorf("got %v, want true", got)
	}
}

func AssertFalse(t *testing.T, got bool) {
	t.Helper()
	if got {
		t.Errorf("got %v, want false", got)
	}
}

func TestStack(t *testing.T) {
	t.Run("integer stuck", func(t *testing.T) {
		stack := new(Stack[int])
		AssertTrue(t, stack.IsEmpty())
		stack.Push(123)
		AssertFalse(t, stack.IsEmpty())
		stack.Push(456)
		value, _ := stack.Pop()
		AssertEqual(t, value, 456)
		value, _ = stack.Pop()
		AssertEqual(t, value, 123)
		AssertTrue(t, stack.IsEmpty())

		// can get the numbers we put in as numbers, not untyped interface{}
		stack.Push(1)
		stack.Push(2)
		firstNum, _ := stack.Pop()
		secondNum, _ := stack.Pop()
		AssertEqual(t, firstNum+secondNum, 3)
	})
}
