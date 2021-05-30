func movingCount(m int, n int, k int) int {
    visited := make([][]bool, m)
    for i := range visited {
        visited[i] = make([]bool, n)
    }
    return dfs(m, n, k, visited, 0, 0)
}

func dfs(m, n, k int, visited [][]bool, r, c int) int {
    if r < 0 || r == m || c < 0 || c == n || visited[r][c] || (r / 10 + r % 10 + c / 10 + c % 10) > k {
        return 0
    }
    visited[r][c] = true
    return 1 + dfs(m, n, k, visited, r + 1, c) + dfs(m, n, k, visited, r, c + 1)
}
