object Solution {
    def candy(ratings: Array[Int]): Int = {
        var res = 0
        val n = ratings.length
        val left = Array.fill[Int](n)(1)
        val right = Array.fill[Int](n)(1)
        // ratings.copyToArray(tmp)
        (1 until n).foreach { i =>
            if (ratings(i) > ratings(i - 1))
            left(i) = left(i - 1) + 1
        }
        res = left(n - 1)
        (n - 2 to 0 by -1).foreach { i =>
            if (ratings(i) > ratings(i + 1))
            right(i) = right(i + 1) + 1
            res += math.max(left(i), right(i))
        }
        res
    }
}
