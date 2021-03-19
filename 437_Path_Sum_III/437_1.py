class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        count = {0: 1}
        def dfs(node, sum_, cur_sum):
            if not node:
                return 0
            res = 0
            cur_sum += node.val
            res += count.get(cur_sum - sum_, 0)
            count[cur_sum] = count.get(cur_sum, 0) + 1
            res += dfs(node.left, sum_, cur_sum)
            res += dfs(node.right, sum_, cur_sum)
            count[cur_sum] -= 1
            return res
        return dfs(root, sum, 0)
