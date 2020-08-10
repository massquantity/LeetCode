from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools
    
class Solution:
    def verifyPostorder(self, postorder: [int]) -> bool:
        stack, root = [], float("+inf")
        for i in reversed(range(len(postorder))):
            if (postorder[i] > root):
                return False
            while (stack and postorder[i] < stack[-1]):
                root = stack.pop()
            stack.append(postorder[i])
        return True


if __name__ == "__main__":
    post = [4, 8, 6, 12, 16, 14, 10]
    s = Solution()
    print(s.verifyPostorder(post))
