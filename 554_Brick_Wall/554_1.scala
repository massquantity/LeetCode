import scala.collection.mutable

object Solution {
  def leastBricks(wall: List[List[Int]]): Int = {
    val map = mutable.HashMap[Int, Int](0 -> 0)
    wall.foreach { w =>
      var pos = 0
      for (brick <- w.init) {
        pos += brick
        map(pos) = map.getOrElse(pos, 0) + 1
      }
    }
    if (map.nonEmpty) wall.length - map.values.max else 0
  }
}
