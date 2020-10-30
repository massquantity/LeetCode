class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        first, second, pre = None, None, TreeNode(float("-inf"))
        stack = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not first and root.val < pre.val:
                first = pre
            if first and root.val < pre.val:
                second = root
            pre = root
            root = root.right
        tmp = first.val
        first.val = second.val
        second.val = tmp