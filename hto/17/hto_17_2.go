package main

import (
	"fmt"
	"strconv"
)

func printNumbers(n int) []int {
	res := make([]int, 0)
	for digit := 1; digit <= n ; digit++ {
		for first := '1'; first <= '9'; first++ {
			num := make([]rune, digit)
			num[0] = first
			dfs(1, num, digit, &res)
		}
	}
	return res
}

func dfs(index int, num []rune, digit int, res *[]int) {
	if index == digit {
		v, _ := strconv.Atoi(string(num))
		*res = append(*res, v)
		return
	}
	for i := '0'; i <= '9'; i++ {
		num[index] = i
		dfs(index + 1, num, digit, res)
	}
}

func main() {
	fmt.Println(printNumbers(2))
}
