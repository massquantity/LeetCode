object Solution {
  def firstMissingPositive(nums: Array[Int]): Int = {
    def swap(a: Int, b: Int): Unit = {
      val tmp = nums(a)
      nums(a) = nums(b)
      nums(b) = tmp
    }

    val n = nums.length
    nums.indices.foreach { i =>
      while (nums(i) > 0 && nums(i) -1 < n && nums(i) != nums(nums(i) - 1)) {
        swap(i, nums(i) - 1)
      }
    }

    nums.zipWithIndex.find {
      case (num, i) => num != i + 1
    } match {
      case Some((_, i)) => i + 1
      case None => n + 1
    }
  }
}
