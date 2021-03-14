object Solution {
  def pathSum(root: TreeNode, targetSum: Int): List[List[Int]] = {
    val res = new scala.collection.mutable.ListBuffer[List[Int]]
    def dfs(node: TreeNode, sum: Int, tmp: List[Int]): Unit = {
      if (node != null) {
        val newList = node.value :: tmp
        if (node.left == null && node.right == null && node.value == sum) {
          res += newList.reverse
        } else {
          val newSum = sum - node.value
          dfs(node.left, newSum, newList)
          dfs(node.right, newSum, newList)
        }
      }
    }
    dfs(root, targetSum, Nil)
    res.toList
  }
}
