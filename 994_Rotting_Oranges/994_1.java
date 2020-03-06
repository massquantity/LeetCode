import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;


class Solution {
	public int orangesRotting(int[][] grid) {
		int[] dx = new int[]{-1, 0, 1, 0};
		int[] dy = new int[]{0, -1, 0, 1};
		int row = grid.length;
		int col = grid[0].length;
		Queue<int []> queue = new ArrayDeque<>();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
				if (grid[i][j] == 2)
					queue.add(new int[]{i, j, 0});
		}

		int[] head = new int[3];
		while (!queue.isEmpty()) {
			head = queue.poll();
			for (int i = 0; i < 4; ++i) {
				int x = head[0] + dx[i];
				int y = head[1] + dy[i];
				if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1) {
					grid[x][y] = 2;
					queue.add(new int[]{x, y, head[2] + 1});
				}
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
				if (grid[i][j] == 1)
					return -1;
		}
		return head[2];
	}
}

public class leetcode {
	public static void main(String[] args) {
		int[][] aa = {{2,1,1},{1,1,0},{0,1,1}};
    	Solution s = new Solution();
    	System.out.println(s.orangesRotting(aa));
	}
}

