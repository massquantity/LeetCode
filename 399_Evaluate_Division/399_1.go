package main

import "fmt"

func main() {
	equations := [][]string{
		[]string{"x1","x2"}, 
		[]string{"x2","x3"}, 
		[]string{"x3","x4"}, 
		[]string{"x4","x5"}}
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

	type edge struct {
		to 	    int
		weight  float64
	}
	graph := make([][]edge, len(id))
	for i, eq := range equations {
		v, w := id[eq[0]], id[eq[1]]
		graph[v] = append(graph[v], edge{w, values[i]})
		graph[w] = append(graph[w], edge{v, 1 / values[i]})
	}

	bfs := func(start, end int) float64 {
		ratios := make([]float64, len(graph))
		ratios[start] = 1
		queue := []int{start}
		for len(queue) > 0 {
			v := queue[0]
			queue = queue[1:]
			if v == end {
				return ratios[v]
			}
			for _, e := range graph[v] {
				if w := e.to; ratios[w] == 0 {
					ratios[w] = ratios[v] * e.weight
					queue = append(queue, w)
				}
			}
		}
		return -1
	}

	res := make([]float64, len(queries))
	for i, q := range queries {
		start, hasS := id[q[0]]
		end, hasE := id[q[1]]
		if !hasS || !hasE {
			res[i] = -1
		} else {
			res[i] = bfs(start, end)
		}
	}
	return res
}
