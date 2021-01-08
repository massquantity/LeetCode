int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = *gridColSize;
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                if (i - 1 < 0  || (i - 1 >= 0 && grid[i - 1][j] != 1)) res++;
                if (i + 1 >= m || (i + 1 < m  && grid[i + 1][j] != 1)) res++;
                if (j - 1 < 0  || (j - 1 >= 0 && grid[i][j - 1] != 1)) res++;
                if (j + 1 >= n || (j + 1 < n  && grid[i][j + 1] != 1)) res++;
            }
        }
    }
    return res;
}
