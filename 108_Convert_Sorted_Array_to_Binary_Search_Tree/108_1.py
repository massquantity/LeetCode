from typing import List

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def build_tree(nums, lo, hi) -> TreeNode:
            if hi < lo: 
                return
            mid = (lo + hi) >> 1
            root = TreeNode(nums[mid])
            root.left  = build_tree(nums, lo, mid - 1)
            root.right = build_tree(nums, mid + 1, hi)
            return root

        return build_tree(nums, 0, len(nums) - 1)