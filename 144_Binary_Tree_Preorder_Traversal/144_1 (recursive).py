class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        return [root.val] +  self.preorderTraversal(root.left) + self.preorderTraversal(root.right)