import scala.io.StdIn

object Main {
  def isInvalid(R1: BigInt):Boolean = {
    if(R1 < BigInt(0) || R1 >= BigInt(10000)){
      true
    }
    false
  }

  def printResult(R1: BigInt) {
    if(R1 < BigInt(0) || R1 >= BigInt(10000)){
      println("E")
    }
    else{
      println(R1)
    }
  }
  def read(){
    StdIn.readLine() match {
      case line: String => {
        val digit = """(\d+)""".r
        var R1 = BigInt(0)
        var R2 = BigInt(0)
        var R3 = "+"
        val tokens = line.split("").toArray
        for(i <- 0 to tokens.length - 1){
          val x = tokens(i).toString
          x match {
            case digit(x) => {
              R2 = BigInt("10") * R2 + BigInt(x)
            }
            case "+"|"-"|"*" => {
              R3 match {
                case "+" => {
                  R1 = R1 + R2
                  R2 = BigInt("0")
                  if(isInvalid(R1)){
                    println("E")
                    read()
                  }
                }
                case "-" => {
                  R1 = R1 - R2
                  R2 = BigInt("0")
                  if(isInvalid(R1)){
                    println("E")
                    read()
                  }
                }
                case "*" => {
                  R1 = R1 * R2
                  R2 = BigInt("0")
                  if(isInvalid(R1)){
                    println("E")
                    read()
                  }
                }
              }
              R3 = x
            }
            case "=" => {
              R3 match {
                case "+" => {
                  R1 = R1 + R2
                  R2 = BigInt("0")
                  printResult(R1)
                }
                case "-" => {
                  R1 = R1 - R2
                  R2 = BigInt("0")
                  printResult(R1)
                }
                case "*" => {
                  R1 = R1 * R2
                  R2 = BigInt("0")
                  printResult(R1)
                }
                case _ => {
                  sys.exit()
                }
              }
            }
            case _ => {
              sys.exit()
            }
          }
        }
      }
      case _ => {
        return
      }
    }
    read()
  }
  def main(args: Array[String]){
    read()
  }
}
