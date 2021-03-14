/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def hasPathSum(root: TreeNode, targetSum: Int): Boolean = {
        if (root == null) {
            false
        } else if (root.left == null && root.right == null) {
            root.value == targetSum
        } else {
            val tmp = targetSum - root.value
            hasPathSum(root.left, tmp) || hasPathSum(root.right, tmp)
        }
    }
}
