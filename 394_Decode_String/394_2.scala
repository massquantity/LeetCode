object Solution {
    def decodeString(s: String): String = {
        val stack = scala.collection.mutable.Stack[(Int, String)]()
        var num = 0
        var res: String = ""
        s.foreach { c =>
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0')
            } else if (c == '[') {
                stack.push((num, res.toString))
                num = 0
                res = ""
            } else if (c == ']') {
                val (curNum, curStr) = stack.pop()
                res = curStr + List.fill[String](curNum)(res).mkString
                // res = curStr + res * curNum
            } else {
                res += c
            }
        }
        res.toString
    }
}
