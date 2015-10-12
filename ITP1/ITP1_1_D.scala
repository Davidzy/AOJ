import scala.io.StdIn

object Main {
  def main(args: Array[String]){
    val S = StdIn.readInt()
    println(s"${S / 3600}:${(S % 3600) / 60}:${S % 60}")
  }
}
