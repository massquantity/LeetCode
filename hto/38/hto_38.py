from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools


class Solution:
    def permutation(self, s: str) -> List[str]:
        return list(set(map(lambda x: "".join(x), itertools.permutations(s))))


if __name__ == "__main__":
    s = Solution()
    string = "abc"
    print(s.permutation(string))
