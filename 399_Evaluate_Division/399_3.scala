import scala.collection.mutable.ListBuffer

object Solution {
  def calcEquation(equations: List[List[String]],
                   values: Array[Double],
                   queries: List[List[String]]): Array[Double] = {
    var num = 0
    var variables = Map.empty[String, Int]
    equations.foreach { equ =>
      val node1 = equ.head
      if (!variables.contains(node1)) {
        variables += (node1 -> num)
        num += 1
      }
      val node2 = equ.tail.head
      if (!variables.contains(node2)) {
        variables += (node2 -> num)
        num += 1
      }
    }

    val parents = (0 until num).toArray
    val weights = Array.fill[Double](num)(1.0)
    equations.indices.foreach { i =>
      val x1 = variables(equations(i).head)
      val x2 = variables(equations(i).tail.head)
      merge(parents, weights, x1, x2, values(i))
    }

    val res = ListBuffer.empty[Double]
    queries.foreach { query =>
      var singleRes = -1.0
      (variables.get(query.head), variables.get(query.tail.head)) match {
        case (Some(node1), Some(node2)) =>
          val root1 = find(parents, weights, node1)
          val root2 = find(parents, weights, node2)
          if (root1 == root2) {
            singleRes = weights(node1) / weights(node2)
          }
        case _ =>
      }
      res += singleRes
    }
    res.toArray
  }

  def find(parents: Array[Int], weights: Array[Double], x: Int): Int = {
    if (parents(x) != x) {
      val p = find(parents, weights, parents(x))
      weights(x) *= weights(parents(x))
      parents(x) = p
    }
    parents(x)
  }

  def merge(parents: Array[Int], weights: Array[Double], x1: Int, x2: Int, v: Double): Unit = {
    val px1 = find(parents, weights, x1)
    val px2 = find(parents, weights, x2)
    parents(px1) = px2
    weights(px1) = v * weights(x2) / weights(x1)
  }

  def main(args: Array[String]): Unit = {
    calcEquation(List(List("a","b"), List("b","c")),
      Array(2.0, 3.0),
      List(List("a","c"), List("b","a"), List("a","e"), List("a","a"), List("x", "x")))
  }
}
