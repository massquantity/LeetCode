object Solution {
  def pathSum(root: TreeNode, sum: Int): Int = {
    val prefixSumCount = Map(0 -> 1)
    dfs(root, prefixSumCount, sum, 0)
  }

  def dfs(node: TreeNode, prefixSumCount: Map[Int, Int], target: Int, curSum: Int): Int = {
    if (node == null) return 0
    var count = 0
    val tmp = curSum + node.value
    count += prefixSumCount.getOrElse(tmp - target, 0)
    val tmpMap = prefixSumCount + (tmp -> (prefixSumCount.getOrElse(tmp, 0) + 1))
    count += dfs(node.left, tmpMap, target, tmp)
    count += dfs(node.right, tmpMap, target, tmp)
    count
  }
}
