import scala.collection.mutable
import scala.util.control.Breaks._

object Solution {
  val graph = mutable.Map.empty[String, Set[String]]
  val weight = mutable.Map.empty[(String, String), Double]
  val visited = mutable.Set.empty[String]

  def calcEquation(equations: List[List[String]],
                   values: Array[Double],
                   queries: List[List[String]]): Array[Double] = {
    graph.clear()
    weight.clear()
    equations.zip(values).foreach {
      case (equ, v) =>
        val node1 = equ.head
        val node2 = equ.tail.head
        graph(node1) = graph.getOrElse(node1, Set.empty) + node2
        graph(node2) = graph.getOrElse(node2, Set.empty) + node1
        weight((node1, node2)) = v
        weight((node2, node1)) = 1.0 / v
    }
    val res = Array.fill[Double](queries.size){0.0}
    queries.zipWithIndex.foreach {
      case (query, i) =>
        visited.clear()
        // val num = dfs(query.head, query.tail.head)
        // res(i) = if (num == 0.0) -1.0 else num
        res(i) = bfs(query.head, query.tail.head)
    }
    println(res.mkString(" "))
    res
  }

  def dfs(start: String, end: String): Double = {
    if (weight.contains((start, end))) return weight((start, end))
    if (!graph.contains(start) || !graph.contains(end)) return 0.0
    if (visited.contains(start)) return 0.0
    visited += start
    var res = 0.0
    breakable {
      for (node <- graph(start)) {
        res = dfs(node, end) * weight((start, node))
        if (res != 0) {
          weight((start, end)) = res
          break
        }
      }
    }
    visited -= start
    res
  }

  def bfs(start: String, end: String): Double = {
    if (weight.contains((start, end))) return weight((start, end))
    if (!graph.contains(start) || !graph.contains(end)) return -1.0
    if (start == end) return 1.0
    visited += start
    val queue = mutable.Queue[(String, Double)]()
    graph(start).foreach(tmp => queue += ((tmp, weight(start, tmp))))
    while (queue.nonEmpty) {
      val (n, w) = queue.dequeue()
      if (n == end) return w
      visited += n
      graph(n).foreach { neig =>
        if (!visited.contains(neig)) {
          weight((start, neig)) = w * weight((n, neig))
          queue += ((neig, weight((start, neig))))
        }
      }
    }
    -1.0
  }

  def main(args: Array[String]): Unit = {
    calcEquation(List(List("a","b"), List("b","c")),
      Array(2.0, 3.0),
      List(List("a","c"), List("b","a"), List("a","e"), List("a","a"), List("x", "x")))
  }
}
