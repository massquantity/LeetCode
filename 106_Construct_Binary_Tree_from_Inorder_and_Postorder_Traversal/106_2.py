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
        
        root = TreeNode(postorder[-1])
        mid = inorder.index(postorder[-1])
        root.left  = self.buildTree(inorder[:mid], postorder[:mid])
        root.right = self.buildTree(inorder[mid+1: ], postorder[mid: -1])
        return root

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
