func findNumberIn2DArray(matrix [][]int, target int) bool {
    if len(matrix) == 0 {
        return false
    }
    i, j := 0, len(matrix[0]) - 1
    for i < len(matrix) && j >= 0 {
        if target == matrix[i][j] {
            return true
        } else if target < matrix[i][j] {
            j--
        } else {
            i++
        }
    }
    return false
}
