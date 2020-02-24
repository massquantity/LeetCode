class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        queue = list()
        queue.append(root.left)
        queue.append(root.right)
        while queue:
            first = queue.pop(0)
            second = queue.pop(0)
            if not first and not second: continue
            if not first or not second:  return False
            if first.val != second.val:  return False
            queue.append(first.left)
            queue.append(second.right)
            queue.append(first.right)
            queue.append(second.left)
        return True