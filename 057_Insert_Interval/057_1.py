from typing import List, Dict

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        
        res = []
        i = 0
        while intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1
            if i == len(intervals):
                break
        
        res.append(newInterval)
        for j in range(i, len(intervals)):
            if intervals[j][0] > res[-1][1]:
                res.append(intervals[j])
            else:
                res[-1][0] = min(res[-1][0], intervals[j][0])
                res[-1][1] = max(res[-1][1], intervals[j][1])
        return res
        

if __name__ == "__main__":
    s = Solution()
    print(s.insert([[1,5]], [6,8]))
