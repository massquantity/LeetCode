from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum_: int) -> List[List[int]]:
        def dfs(root, tmp, sum_):
            if not root:
                return
            tmp.append(root.val)
            if not root.left and not root.right and sum_ == root.val:
                res.append(tmp[:])
                tmp.pop()
                return
            dfs(root.left,  tmp, sum_ - root.val)
            dfs(root.right, tmp, sum_ - root.val)
            tmp.pop()
        res = []
        dfs(root, [], sum_)
        return res

    def pathSum2(self, root: TreeNode, sum_: int) -> List[List[int]]:  # slow
        def dfs(root, tmp, sum_):
            if not root:
                return
            tmp.append(root.val)
            if not root.left and not root.right and sum_ == root.val:
                res.append(tmp)
            dfs(root.left,  tmp[:], sum_ - root.val)
            dfs(root.right, tmp[:], sum_ - root.val)
        res = []
        dfs(root, [], sum_)
        return res


if __name__ == "__main__":
    node1 = TreeNode(5)
    node2 = TreeNode(4)
    node3 = TreeNode(8)
    node4 = TreeNode(11)
    node5 = TreeNode(13)
    node6 = TreeNode(4)
    node7 = TreeNode(7)
    node8 = TreeNode(2)
    node9 = TreeNode(5)
    node10 = TreeNode(1)
    node1.left = node2
    node1.right = node3
    node2.left = node4
    node3.left = node5
    node3.right = node6
    node4.left = node7
    node4.right = node8
    node6.left = node9
    node6.right = node10
    s = Solution()
    print(s.pathSum(node1, 22))