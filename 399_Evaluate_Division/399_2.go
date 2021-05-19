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

	graph := make([][]float64, len(id))
	for i := range graph {
		graph[i] = make([]float64, len(id))
	}
	for i, eq := range equations {
		v, w := id[eq[0]], id[eq[1]]
		graph[v][w] = values[i]
		graph[w][v] = 1 / values[i]
	}

	for k := range graph {
		for i := range graph {
			for j := range graph {
				if graph[i][k] > 0 && graph[k][j] > 0 {
					graph[i][j] = graph[i][k] * graph[k][j]
				}
			}
		}
	}

	res := make([]float64, len(queries))
	for i, q := range queries {
		start, hasS := id[q[0]]
		end, hasE := id[q[1]]
		if !hasS || !hasE || graph[start][end] == 0 {
			res[i] = -1.0
		} else {
			res[i] = graph[start][end]
		}
	}
	return res
}
