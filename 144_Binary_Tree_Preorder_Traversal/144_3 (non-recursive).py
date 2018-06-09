class Solution:
    def preorderTraversal(self, root):
        ans = []
        if root:
            stack = [root]
        while (root and len(stack) != 0):
            root = stack.pop()
            ans.append(root.val)
            if root.right:
                stack.append(root.right)
            if root.left:
                stack.append(root.left)
        return ans