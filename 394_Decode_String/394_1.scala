object Solution {
    def decodeString(s: String): String = {
        val stack = scala.collection.mutable.Stack[(Int, String)]()
        var num = 0
        var res = new StringBuilder
        s.foreach { c =>
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0')
            } else if (c == '[') {
                stack.push((num, res.toString))
                num = 0
                res = new StringBuilder
            } else if (c == ']') {
                val tmp = new StringBuilder
                val (curNum, curStr) = stack.pop()
                (0 until curNum).foreach(_ => tmp ++= res)
                res = new StringBuilder(curStr + tmp)
            } else {
                res += c
            }
        }
        res.toString
    }
}
