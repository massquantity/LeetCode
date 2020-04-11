from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.res = [0 for _ in range(n)]
        self.result = []
        self.solve(0, n)
        return self.result

    def solve(self, row, n):
        if (row == n):
            self.printQueen(n)
            return
        for col in range(n):
            if self.isValid(row, col, n):
                self.res[row] = col
                self.solve(row + 1, n)

    def isValid(self, row, col, n):
        leftUp, rightUp = col - 1, col + 1
        for i in range(row - 1, -1, -1):
            if self.res[i] == col:
                return False
            if leftUp >= 0:
                if self.res[i] == leftUp:
                    return False
            if rightUp < n:
                if self.res[i] == rightUp:
                    return False
            leftUp  -= 1
            rightUp += 1
        return True

    def printQueen(self, n):
        res = []
        for i in range(n):
            s = ""
            for j in range(n):
                if self.res[i] == j:
                    print("Q", end="")
                    s += "Q"
                else:
                    print(".", end="")
                    s += "."
            res.append(s)
            print()
        print()
        self.result.append(res)


if __name__ == "__main__":
    s = Solution()
    res = s.solveNQueens(4)
    print(res)