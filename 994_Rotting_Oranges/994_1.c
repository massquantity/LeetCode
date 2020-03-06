#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
	int t = 0;
	while (true) {
		bool noFresh = true;
		for (int i = 0; i < gridSize; ++i) {
			for (int j = 0; j < *gridColSize; ++j) {
				if (grid[i][j] == 3)
					grid[i][j] = 2;
				else if (grid[i][j] == 1) {
					if ((i < gridSize - 1 && grid[i + 1][j] == 2) || 
						(j < *gridColSize - 1 && grid[i][j + 1] == 2)) {
						grid[i][j] = 2;
						noFresh = false;
					}
				}
				else if (grid[i][j] == 2) {
					if (i < gridSize - 1 && grid[i + 1][j] == 1) {
						grid[i + 1][j] = 3;
						noFresh = false;				
					}
					if (j < *gridColSize - 1 && grid[i][j + 1] == 1) {
						grid[i][j + 1] = 3;
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


int main(void) {
	int array[3][3] = {{2,1,1},{1,1,0},{0,1,1}};
	size_t row = sizeof(array) / sizeof(array[0]);
	size_t col = sizeof(array[0]) / sizeof(int);
	int **a = (int **)malloc(sizeof(int *) * row * col);
	for (int i = 0; i < row; ++i) {
		*(a + i) = (int *)malloc(sizeof(int) * col);  // a[i]
		for (int j = 0; j < col; ++j) 
			*(*(a + i) + j) = array[i][j];        	  //a[i][j]
	}
//	for (int i = 0; i < row; ++i)
//		a[i] = array[i];
	printf("%d\n", orangesRotting(a, row, &col));
}