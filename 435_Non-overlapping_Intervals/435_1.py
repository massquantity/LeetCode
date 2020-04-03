from typing import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[1])
        end = intervals[0][1]
        count = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < end:
                count += 1
            else:
                end = intervals[i][1]
        return count


if __name__ == "__main__":
    a = [[1,2], [2,3], [3,4], [1,3]]
    s = Solution()
    print(s.eraseOverlapIntervals(a))