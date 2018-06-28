class Solution:
    def getMinimumDifference(self, root):
        self.prev = None
        self.min_value = float("inf")

        def inorder(root):
            if not root: return
            inorder(root.left)
            if self.prev is not None:
                self.min_value = min(self.min_value, root.val - self.prev)
            self.prev = root.val
            inorder(root.right)

        inorder(root)
        return self.min_value