import scala.io.StdIn

object Main {
  def main(args: Array[String]){
    val N = StdIn.readInt()
    var res = 0
    for(i <- 0 to N - 1){
      val num = StdIn.readInt()
      if((2 to math.sqrt(num).toInt).forall(num % _ != 0)){
        res = res + 1
      }
    }
    println(res)
  }
}
