void dfs(char **grid, int i, int j, int row, int col) {
  if (i < 0 || i > row || j < 0 || j > col || grid[i][j] == '0') return;
  grid[i][j] = '0';
  dfs(grid, i - 1, j, row, col);
  dfs(grid, i + 1, j, row, col);
  dfs(grid, i, j - 1, row, col);
  dfs(grid, i, j + 1, row, col);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
  int count = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j] == '1') {
        dfs(grid, i, j, gridSize - 1, *gridColSize - 1);
        count++;
      }
    }
  }
  return count;
}