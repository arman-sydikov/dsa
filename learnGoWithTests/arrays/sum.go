package main

func Sum(numbers []int) (sum int) {
	for _, number := range numbers {
		sum += number
	}
	return
}

func SumAll(slices ...[]int) (sums []int) {
	for _, slice := range slices {
		sums = append(sums, Sum(slice))
	}
	return
}

func SumAllTails(slices ...[]int) (tails []int) {
	for _, slice := range slices {
		sum := 0
		if len(slice) > 0 {
			sum = Sum(slice[1:])
		}
		tails = append(tails, sum)
	}
	return
}
