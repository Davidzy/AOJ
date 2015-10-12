import scala.io.StdIn

object Main {
  def main(args: Array[String]){
    val input = StdIn.readLine().split(" ").map(_.toInt)
    val x = input(0)
    val y = input(1)
    println(s"${x * y} ${2 * x + 2 * y}")
  }
}
