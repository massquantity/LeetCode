#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int N, M;
int res;
int minv[21], mins[21];
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void dfs(int v, int s, int depth, int r, int h) {
    if (depth == 0) {
        if (v == N && s < res) res = s;
        return;
    }

    if (v + minv[depth - 1] > N || s + mins[depth - 1] > res ||
        2 * (N - v) / r + s >= res)  return;  // 剪枝 1,2,3

    for (int i = r - 1; i >= depth; --i) {
        if (depth == M) s = i * i;
        int maxH = MIN((N - minv[depth - 1] - v) / (i * i), h - 1); // 剪枝 4
        for (int j = maxH; j >= depth; --j) {
            dfs(v + i * i * j, s + 2 * i * j, depth - 1, i, j);
        }
    }
}

int main(void) {
    minv[0] = 0;
    mins[0] = 0;
    for (int i = 1; i <= 20; ++i) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }

    while (scanf("%d %d", &N, &M) == 2) {
        res = 1 << 30;
        dfs(0, 0, M, N + 1, N + 1);
        res = (res == 1 << 30 ? 0 : res);
        printf("%d\n", res);
    }
}