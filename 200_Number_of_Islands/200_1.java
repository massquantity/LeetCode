class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    count++;
                }   
            }
        }
        return count;
    }

    private void bfs(char[][] grid, int i, int j, int m, int n) {
        Deque<int[]> queue = new ArrayDeque<>();
        queue.add(new int[] {i, j});
        while (!queue.isEmpty()) {
            int[] tmp = queue.removeFirst();
            i = tmp[0];
            j = tmp[1];
            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1') {
                grid[i][j] = '0';
                queue.add(new int[] {i - 1, j});
                queue.add(new int[] {i + 1, j});
                queue.add(new int[] {i, j - 1});
                queue.add(new int[] {i, j + 1});
            }
        }
    }
}