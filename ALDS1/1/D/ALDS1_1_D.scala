import scala.io.StdIn

object Main {
  def main(args: Array[String]){
    val n = StdIn.readInt()
    var maxv = Int.MinValue
    var minv = Int.MaxValue

    for(i <- 0 to n - 1){
      val num = readInt()
      maxv = List(maxv,num - minv).max
      minv = List(minv,num).min
    }
    println(maxv)
  }
}
