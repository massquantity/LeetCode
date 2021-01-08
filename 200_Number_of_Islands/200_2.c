bool valid(int x, int y, int m, int n) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

void dfs(char **grid, int i, int j, int m, int n, int directions[4][2], bool visited[m][n]) {
  visited[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int newX = i + directions[k][0];
    int newY = j + directions[k][1];
    if (valid(newX, newY, m, n) && grid[newX][newY] == '1' && !visited[newX][newY]) {
      dfs(grid, newX, newY, m, n, directions, visited);
    }
  }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
  int m = gridSize, n = *gridColSize;
  int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  bool visited[m][n];
  memset(visited, false, sizeof(visited));
  int count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        dfs(grid, i, j, m, n, directions, visited);
        count++;
      }
    }
  }
  return count;
}