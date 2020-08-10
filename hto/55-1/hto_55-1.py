class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def helper(root: TreeNode) -> int:
            if not root:
                return 0
            left = helper(root.left)
            if left == -1: 
                return -1
            right = helper(root.right)
            if right == -1:
                return -1
            return 1 + max(left, right) if abs(left - right) <= 1 else -1
        
        return helper(root) != -1