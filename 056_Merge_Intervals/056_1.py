class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) <= 1:
            return intervals
        intervals = sorted(intervals, key=lambda x : x.start)
        res = []
        init = intervals[0]
        for array in intervals[1:]:
            if init.end < array.start:
                res.append(init)
                init = array
            else:
                init.end = max(init.end, array.end)
        res.append(init)
        return res