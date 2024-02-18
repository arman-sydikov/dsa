package main

func Reduce[A, B any](collection []A, accumulator func(B, A) B, initialValue B) B {
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

type Account struct {
	Name    string
	Balance float64
}

func NewTransaction(from, to Account, sum float64) Transaction {
	return Transaction{from.Name, to.Name, sum}
}

func BalanceFor(transactions []Transaction, name string) float64 {
	adjustBalance := func(currentBalance float64, t Transaction) float64 {
		if t.From == name {
			return currentBalance - t.Sum
		}
		if t.To == name {
			return currentBalance + t.Sum
		}
		return currentBalance
	}
	return Reduce(transactions, adjustBalance, 0.0)
}

func NewBalanceFor(a Account, transactions []Transaction) Account {
	return Reduce(transactions, applyTransaction, a)
}

func applyTransaction(a Account, t Transaction) Account {
	if t.From == a.Name {
		a.Balance -= t.Sum
	}
	if t.To == a.Name {
		a.Balance += t.Sum
	}
	return a
}

type Person struct {
	Name string
}

func Find[A any](numbers []A, eval func(A) bool) (A, bool) {
	for _, n := range numbers {
		if eval(n) {
			return n, true
		}
	}
	var value A
	return value, false
}
