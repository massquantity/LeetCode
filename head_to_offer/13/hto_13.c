#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int dfs(int m, int n, int k, bool visited[m][n], int r, int c) {
    if (r < 0 || r == m || c < 0 || c == n || visited[r][c]
        || (r / 10 + r % 10 + c / 10 + c % 10) > k) return 0;
    visited[r][c] = true;
    return dfs(m, n, k, visited, r + 1, c) +
           dfs(m, n, k, visited, r, c + 1) + 1;
}

int movingCount(int m, int n, int k){
    bool visited[m][n];
    memset(visited, 0, sizeof(visited));
    return dfs(m, n, k, visited, 0, 0);
}

int main(int argc, char *argv[])
{
    printf("%d\n", movingCount(2, 3, 1));
}