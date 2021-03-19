import collection.JavaConverters._

object Solution {
    def reconstructQueue(people: Array[Array[Int]]): Array[Array[Int]] = {
        val pp = people.sortWith((a, b) => a(0) > b(0) || (a(0) == b(0) && a(1) < b(1)))
        val res: java.util.LinkedList[Array[Int]] = new java.util.LinkedList[Array[Int]]
        pp.foreach(p => res.add(p(1), p))
        res.toArray(new Array(res.size()))
        // res.asScala.toArray
    }
}
