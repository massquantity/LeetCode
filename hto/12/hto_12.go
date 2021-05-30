func exist(board [][]byte, word string) bool {
    visited := make([][]bool, len(board))
    for i := range visited {
        visited[i] = make([]bool, len(board[0]))
    }
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            if dfs(board, word, visited, i, j, 0) {
                return true
            }
        }
    }
    return false
}

func dfs(board [][]byte, word string, visited [][]bool, i, j, k int) bool {
    if i < 0 || i == len(board) || j < 0 || j == len(board[0]) || board[i][j] != word[k] || visited[i][j] {
        return false
    }
    if k == len(word) - 1 {
        return true
    }
    visited[i][j] = true
    res := dfs(board, word, visited, i + 1, j, k + 1) || 
           dfs(board, word, visited, i - 1, j, k + 1) || 
           dfs(board, word, visited, i, j + 1, k + 1) || 
           dfs(board, word, visited, i, j - 1, k + 1)
    visited[i][j] = false
    return res
}
