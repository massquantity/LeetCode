#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    int t = 0;
    while (true) {
        bool noFresh = true;
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < *gridColSize; ++j) {
                if (grid[i][j] == -1)
                    grid[i][j] = 2;
                else if (grid[i][j] == 1) {
                    if ((i < gridSize - 1 && grid[i + 1][j] > 1) ||
                        (j < *gridColSize - 1 && grid[i][j + 1] > 1)) {
                        grid[i][j] = 2;
                        noFresh = false;
                    }
                }
                else if (grid[i][j] == 2) {
                    grid[i][j] = 4;
                    if (i < gridSize - 1 && grid[i + 1][j] == 1) {
                        grid[i + 1][j] = -1;
                        noFresh = false;
                    }
                    if (j < *gridColSize - 1 && grid[i][j + 1] == 1) {
                        grid[i][j + 1] = -1;
                        noFresh = false;
                    }
                }
            }
        }
        if (noFresh) break;
        else t++;
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j)
            if (grid[i][j] == 1)
                return -1;
    }
    return t;
}