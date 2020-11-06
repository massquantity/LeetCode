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
        index_map = dict()
        for i in range(len(inorder)):
            index_map[inorder[i]] = i

        def buildBranch(first, left, right):
            if left > right:
                return
            root = TreeNode(preorder[first])
            mid = index_map[preorder[first]]
            root.left = buildBranch(first + 1, left, mid - 1)
            root.right = buildBranch(first + mid - left + 1, mid + 1, right)
            return root
        return buildBranch(0, 0, len(inorder) - 1)

def traverse(tree: TreeNode) -> None:
    if not tree:
        return
    print(tree.val, " ", end=" ")
    traverse(tree.left)
    traverse(tree.right)
        

if __name__ == "__main__":
    s = Solution()
    preorder = [3, 9, 1, 2, 20, 15, 7]
    inorder = [1, 9, 2, 3, 15, 20, 7]
    traverse(s.buildTree(preorder, inorder))
