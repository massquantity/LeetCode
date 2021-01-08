void dfs(int **isConnected, int i, int n, bool visited[n]) {
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = true;
            dfs(isConnected, j, n, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int n = isConnectedSize, count = 0;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            visited[i] = true;
            dfs(isConnected, i, n, visited);
        }
    }
    return count;
}
