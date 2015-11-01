import scala.io.StdIn

object Main {
  def SelectionSort(A: Array[Int]):(Int,Array[Int]) = {
    var count = 0
    def swap(i: Int, j: Int){
      if(i != j){
        count += 1
      }
      val tmp = A(i)
      A(i) = A(j)
      A(j) = tmp
    }

    for(i <- 0 to A.length - 1){
      var mini = i
      for(j <- i + 1 to A.length - 1){
        if (A(j) < A(mini)){
          mini = j
        }
      }
      swap(i,mini)
    }
    (count,A)
  }


  def main(args: Array[String]){
    val N = StdIn.readInt()
    val input = StdIn.readLine().split(" ").map(_.toInt).toArray

    assert(input.length == N, "input length must equal to N")

    val result = SelectionSort(input)
    println(result._2.mkString(" "))
    println(result._1)
  }
}
