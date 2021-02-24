class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        self.heap = []
        self.count = defaultdict(lambda: 0)
        for n in nums:
            self.count[n] += 1
        
        for n in self.count:
            if len(self.heap) < k:
                self.heap.append(n)
                self.swim(len(self.heap) - 1)
            else:
                if self.count[n] > self.count[self.heap[0]]:
                    self.heap[0] = n
                    self.sink(0)
        return self.heap

    def swim(self, k):
        while k > 0:
            j = (k - 1) >> 1
            if self.count[self.heap[j]] <= self.count[self.heap[k]]:
                break
            self.swap(k, j)
            k = j

    def sink(self, k):
        n = len(self.heap)
        while 2*k + 1 < n:
            j = 2*k + 1
            if j < n - 1 and self.count[self.heap[j]] > self.count[self.heap[j+1]]:
                j += 1
            if self.count[self.heap[k]] <= self.count[self.heap[j]]:
                break
            self.swap(k, j)
            k = j

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
