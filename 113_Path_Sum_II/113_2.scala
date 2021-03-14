object Solution {
  def pathSum(root: TreeNode, targetSum: Int): List[List[Int]] = {
    if (root == null) {
      Nil
    } else if (root.left == null && root.right == null && root.value == targetSum) {
      List(List(root.value))
    } else {
      val tmp = targetSum - root.value
      (pathSum(root.left, tmp) ++ pathSum(root.right, tmp)).map(path => root.value :: path)
    }
  }
}
