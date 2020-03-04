from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rotten_list = []
        fresh_num = 0
        row_len = len(grid)
        col_len = len(grid[0])
        for i in range(row_len):
            for j in range(col_len):
                if grid[i][j] == 2:
                    rotten_list.append([i, j])

        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        rtime = 0
        while rotten_list:
            new_rot_list = []
            for x0, y0 in rotten_list:
                for k in range(4):
                    x = x0 + dx[k]
                    y = y0 + dy[k]
                    if 0 <= x < row_len and 0 <= y < col_len and grid[x][y] == 1:
                        grid[x][y] = 2
                        new_rot_list.append([x, y])
                #        fresh_num -= 1
            
            if not new_rot_list: break
            rotten_list =  new_rot_list[:]
            rtime += 1

        for row in grid:
            for i in row:
                if i == 1:
                    return -1
        return rtime


            
if __name__ =="__main__":
    aa = [[2,1,1],[1,1,0],[0,1,1]]
    s = Solution()
    print(s.orangesRotting(aa))