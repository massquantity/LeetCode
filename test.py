class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root):
        ans = []
        stack = []
        if root:
            stack.append(root)
        while (root and stack != []):
            root = stack.pop()
            ans.append(root.val)
            if root.right:
                stack.append(root.right)
            if root.left:
                stack.append(root.left)
        return ans