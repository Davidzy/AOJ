import scala.io.StdIn

object Main {
  def isInvalid(R1: Int, R2: Int):Boolean = {
    if(R1 < 0 || R1 >= 10000){
      return true
    }
    return false
  }

  def printResult(R1: Int, R2: Int){
    if(isInvalid(R1,R2)){
      println("E")
    }
    else{
      println(R1)
    }
  }
  def solve(line: String){
    line match {
      case line: String => {
        val digit = """(\d+)""".r
        var R1 = 0
        var R2 = 0
        var R3 = "+"
        val tokens = line.split("").toArray
        for(i <- 0 to tokens.length - 1){
          val x = tokens(i).toString
          x match {
            case digit(x) => {
              R2 = 10 * R2 + x.toInt
            }
            case "+"|"-"|"*" => {
              R3 match {
                case "+" => {
                  R1 = R1 + R2
                }
                case "-" => {
                  R1 = R1 - R2
                }
                case "*" => {
                  R1 = R1 * R2
                }
              }
              R2 = 0
              R3 = x
              if(isInvalid(R1,R2)){
                println("E")
                return
              }
            }
            case "=" => {
              R3 match {
                case "+" => {
                  R1 = R1 + R2
                  R2 = 0
                }
                case "-" => {
                  R1 = R1 - R2
                  R2 = 0
                }
                case "*" => {
                  R1 = R1 * R2
                  R2 = 0
                }
              }
              printResult(R1,R2)
              return
            }
            case _ => {
              return
            }
          }
        }
      }
      case _ => {
        return
      }
    }
  }

  def main(args: Array[String]){
    StdIn.readLine match {
      case line: String => {
        solve(line)
        main(args)
      }
      case _ => {
        return
      }
    }
  }
}
