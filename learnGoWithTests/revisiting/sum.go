package main

func Reduce[A any](collection []A, accumulator func(A, A) A, initialValue A) A {
	for _, x := range collection {
		initialValue = accumulator(initialValue, x)
	}
	return initialValue
}

func Sum(numbers []int) (sum int) {
	add := func(acc, x int) int { return acc + x }
	return Reduce(numbers, add, 0)
}

func SumAll(slices ...[]int) (sums []int) {
	for _, slice := range slices {
		sums = append(sums, Sum(slice))
	}
	return
}

func SumAllTails(slices ...[]int) []int {
	sumTail := func(acc, x []int) []int {
		if len(x) > 0 {
			tail := x[1:]
			return append(acc, Sum(tail))
		} else {
			return append(acc, 0)
		}
	}
	return Reduce(slices, sumTail, []int{})
}

type Transaction struct {
	From, To string
	Sum      float64
}

func BalanceFor(transactions []Transaction, name string) float64 {
	var balance float64
	for _, t := range transactions {
		if t.From == name {
			balance -= t.Sum
		} else if t.To == name {
			balance += t.Sum
		}
	}
	return balance
}
