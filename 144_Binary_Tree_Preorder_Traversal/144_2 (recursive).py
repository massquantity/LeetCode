class Solution:
    def rr(self, root, ans):
        if root:
            ans.append(root.val)
        else:
            return
        if root.left:
            self.rr(root.left, ans)
        if root.right:
            self.rr(root.right, ans)
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        self.rr(root, ans)
        return ans