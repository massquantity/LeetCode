bool dfs(int cur, int n, int size, int index, int *res, bool *visited) {
    res[index] = cur;
    if (index == size - 1) return true;
    visited[cur] = true;
    for (int i = 0; i < n; i++) {
        int next = cur ^ (1 << i);
        if (!visited[next] && dfs(next, n, size, index + 1, res, visited))
            return true;
    }
    visited[cur] = false;
    return false;
}

int* grayCode(int n, int* returnSize){
    int size = 1 << n;
    int *res = (int *)malloc(sizeof(int) * size);
    memset(res, 0, sizeof(int) * size);
    if (n == 0) {
        *returnSize = size;
        res[0] = 0;
        return res;
    }
    bool visited[size];
    memset(visited, false, sizeof(visited));
    int index = 0;
    dfs(0, n, size, index, res, visited);
    *returnSize = size;
    return res;
}