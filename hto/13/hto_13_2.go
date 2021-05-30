type Pair struct {
    x int
    y int
}

func movingCount(m int, n int, k int) int {
    queue := []Pair{Pair{0, 0}}
    visited := make(map[Pair]bool)
    for len(queue) > 0 {
        pair := queue[0]
        x, y := pair.x, pair.y
        queue = queue[1:]
        if x == m || y == n || visited[pair] || digitSum(x) + digitSum(y) > k {
            continue
        }
        visited[pair] = true
        queue = append(queue, Pair{x + 1, y})
        queue = append(queue, Pair{x, y + 1})
    }
    return len(visited)
}

func digitSum(x int) int {
    res := 0
    for x != 0 {
        res += x % 10
        x /= 10
    }
    return res
}

// using array as key
func movingCount2(m int, n int, k int) int {
    queue := [][2]int{[2]int{0, 0}}
    visited := make(map[[2]int]bool)
    for len(queue) > 0 {
        x, y := queue[0][0], queue[0][1]
        queue = queue[1:]
        if x == m || y == n || visited[[2]int{x, y}] || digitSum(x) + digitSum(y) > k {
            continue
        }
        visited[[2]int{x, y}] = true
        queue = append(queue, [2]int{x + 1, y})
        queue = append(queue, [2]int{x, y + 1})
    }
    return len(visited)
}
