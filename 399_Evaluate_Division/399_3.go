package main

import "fmt"

func main() {
	equations := [][]string{[]string{"x1","x2"}, []string{"x2","x3"}, []string{"x3","x4"}, []string{"x4","x5"}}
	values := []float64{3.0, 4.0, 5.0, 6.0}
	queries := [][]string{
		[]string{"x1","x5"},
		[]string{"x5","x2"},
		[]string{"x2","x4"},
		[]string{"x2","x2"},
		[]string{"x2","x9"},
		[]string{"x9","x9"}}

	fmt.Println(calcEquation(equations, values, queries))
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	id := map[string]int{}
	for _, eq := range equations {
		a, b := eq[0], eq[1]
		if _, has := id[a]; !has {
			id[a] = len(id)
		}
		if _, has := id[b]; !has {
			id[b] = len(id)
		}
	}

	fa := make([]int, len(id))
	w := make([]float64, len(id))
	for i := range fa {
		fa[i] = i
		w[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			f := find(fa[x])
			w[x] *= w[fa[x]]
			fa[x] = f
		}
		return fa[x]
	}

	merge := func(from, to int, val float64) {
		fFrom, fTo := find(from), find(to)
		w[fFrom] = val * w[to] / w[from]
		fa[fFrom] = fTo
	}

	for i, eq := range equations {
		merge(id[eq[0]], id[eq[1]], values[i])
	}

	res := make([]float64, len(queries))
	for i, q := range queries {
		start, hasS := id[q[0]]
		end, hasE := id[q[1]]
		if hasS && hasE && find(start) == find(end) {
			res[i] = w[start] / w[end]
		} else {
			res[i] = -1.0
		}
	}
	return res
}
