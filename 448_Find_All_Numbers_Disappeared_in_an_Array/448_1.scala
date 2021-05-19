object Solution {
  def findDisappearedNumbers(nums: Array[Int]): List[Int] = {
    val n = nums.length
    nums.foreach { num =>
      val index = (num - 1) % n
      nums(index) += n
    }
    (for ((num, i) <- nums.zipWithIndex; if num <= n) 
      yield i + 1).toList
  }
}
