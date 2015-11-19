import scala.util.parsing.combinator._
import scala.io.StdIn

class Calculator extends RegexParsers {
  def expr: Parser[BigInt] = factor~rep("+"~factor | "-"~factor | "*"~factor) ^^ {
    case factor ~ list => list.foldLeft(factor) {
      case(x, "+" ~ y) => BigInt(x.toString) + BigInt(y.toString)
      case(x, "-" ~ y) => BigInt(x.toString) - BigInt(y.toString)
      case(x, "*" ~ y) => BigInt(x.toString) * BigInt(y.toString)
    }
  }

  def factor: Parser[BigInt] = """\d+""".r ^^ { BigInt(_) } | expr

  def apply(input: String):BigInt = parseAll(expr, input) match {
    case Success(result, _) => result
    case failure : NoSuccess => scala.sys.error(failure.msg)
  }
}

object Main extends Calculator {
  def read(){
    StdIn.readLine() match {
      case line: String => {
        val result = this(line.slice(0,line.length - 1))
        if(result.toString.length > 100000){
          println("E")
        }
        else{
          if(0 <= result.toInt && result.toInt < 10000){
            println(result)
          }
          else{
            println("E")
          }
        }
        read()
      }
      case _ => return
    }
  }
  def main(args: Array[String]){
    read()
  }
}
