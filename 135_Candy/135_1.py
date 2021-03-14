class Solution:
    def candy(self, ratings: List[int]) -> int:
        left = [1] * len(ratings)
        right = left[:]
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        
        res = left[-1]
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
            res += max(left[i], right[i])
        return res
