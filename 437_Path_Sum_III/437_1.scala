/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */

object Solution {
  def pathSum(root: TreeNode, sum: Int): Int = {
    def dfs(root: TreeNode, sum: Int): Int = {
      if (root == null) return 0
      val count = if (root.value == sum) 1 else 0
      val tmp = sum - root.value
      count + dfs(root.left, tmp) + dfs(root.right, tmp)
    }
    if (root == null) 0
    else dfs(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum)
  }
}
