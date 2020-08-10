from typing import List, Dict

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return
        indexMap = dict()
        length = len(inorder)
        for i in range(length):
            indexMap[inorder[i]] = i
        return self.buildBranch(indexMap, preorder, 0, 0, length - 1)

    def buildBranch(self, indexMap: Dict, preorder: List[int], first: int, left: int, right: int) -> TreeNode:
        if left > right:
            return
        root = TreeNode(preorder[first])
        mid = indexMap[preorder[first]]
        root.left = self.buildBranch(indexMap, preorder, first + 1, left, mid - 1)
        root.right = self.buildBranch(indexMap, preorder, first + mid - left + 1, mid + 1, right)
        return root

    def traverse(self, root: TreeNode):
        if not root:
            return
        print(root.val, " ")
        self.traverse(root.left)
        self.traverse(root.right)

    
if __name__ == "__main__":
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    s = Solution()
    s.traverse(s.buildTree(preorder, inorder))