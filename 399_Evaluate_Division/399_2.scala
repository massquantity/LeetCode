import scala.collection.mutable.ListBuffer

object Solution {
  def calcEquation(equations: List[List[String]],
                   values: Array[Double],
                   queries: List[List[String]]): Array[Double] = {
    var nodes = Set.empty[String]
    var graph = Map.empty[(String, String), Double]
    equations.zip(values).foreach {
      case (equ, v) =>
        val node1 = equ.head
        val node2 = equ.tail.head
        nodes += node1
        nodes += node2
        graph += ((node1, node2) -> v)
        graph += ((node2, node1) -> 1.0 / v)
    }

    nodes.foreach { k =>
      nodes.foreach { i =>
        nodes.foreach { j =>
          if (!graph.contains((i, j))) {
            if (i == j) {
              graph += ((i, j) -> 1.0)
            } else if (graph.contains((i, k)) && graph.contains((k, j))) {
              graph += ((i, j) -> graph((i, k)) * graph((k, j)))
            }
          }
        }
      }
    }

    val res = ListBuffer[Double]()
    queries.foreach { query =>
      val node1 = query.head
      val node2 = query.tail.head
      res += graph.getOrElse((node1, node2), -1.0)
    }
    println(res.mkString(" "))
    res.toArray
  }

  def main(args: Array[String]): Unit = {
    calcEquation(List(List("a","b"), List("b","c")),
      Array(2.0, 3.0),
      List(List("a","c"), List("b","a"), List("a","e"), List("a","a"), List("x", "x")))
  }
}
