class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True;
        return self.isSymmetricLeftRight(root.left, root.right)

    def isSymmetricLeftRight(self, left: TreeNode, right: TreeNode):
        if not left and not right:
            return True
        if not left or not right:
           return False
        return left.val == right.val and \
            self.isSymmetricLeftRight(left.left, right.right) and \
            self.isSymmetricLeftRight(left.right, right.left)


if __name__ == "__main__":
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(2)
    d = TreeNode(3)
    e = TreeNode(4)
    f = TreeNode(4)
    g = TreeNode(3)
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g
    s = Solution()
    s.isSymmetric(a)