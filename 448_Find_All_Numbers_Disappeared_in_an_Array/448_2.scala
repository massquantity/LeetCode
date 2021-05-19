object Solution {
  def findDisappearedNumbers(nums: Array[Int]): List[Int] = {
    val n = nums.length
    nums.foreach { num =>
      val index = num.abs - 1
      if (nums(index) > 0) nums(index) = -nums(index)
    }
    (1 to nums.length).filter(i => nums(i - 1) > 0).toList
  }
}
