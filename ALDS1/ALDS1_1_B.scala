import scala.io.StdIn

object Main {
  def main(args: Array[String]){
    val input = StdIn.readLine().split(" ").map(_.toInt)
    println(gcd(input.max,input.min))
  }

  def gcd(x: Int, y: Int):Int = {
    if(0 < y && y < x) { gcd(y, x % y) } 
    else { x }
  }
}
