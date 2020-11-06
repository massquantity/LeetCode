from typing import List, Dict


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder:
            return
        
        def buildBranch(last, left, right):
            if left > right:
                return
            mid = inorder.index(postorder[last])
            root = TreeNode(postorder[last])
            root.left  = buildBranch(last - (right - mid) - 1, left, mid - 1)
            root.right = buildBranch(last - 1, mid + 1, right)
            return root
        return buildBranch(len(postorder) - 1, 0, len(inorder) - 1)

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
