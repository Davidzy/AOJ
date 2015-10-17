import scala.io.StdIn

object Main {

  def bubbleSort(A: Array[Int]){
    def swap(i: Int, j: Int) {
      val t = A(i); A(i) = A(j); A(j) = t
      ()
    }

    var count = 0
    for(i <- 0 to A.length - 1){
      for(j <- A.length - 1 to i + 1 by -1){
        if(A(j) < A(j-1)){
          swap(j,j-1)
          count += 1
        }
      }
    }

    println(A.mkString(" "))
    println(count)
  }

  def main(args: Array[String]){
    val N = StdIn.readInt()
    val input = StdIn.readLine().split(" ").map(_.toInt)
    bubbleSort(input)
  }
}
