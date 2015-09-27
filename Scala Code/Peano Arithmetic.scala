sealed abstract class N
case object Zero extends N
case class S(n: N) extends N

def same(a: N, b: N): Boolean =
  (a, b) match {
    case (Zero, Zero) =>
      true
    case (S(a_1), S(b_1)) =>
      same(a_1, b_1)
    case _ => false
  }

def add(a: N, b: N): N =
  (a, b) match {
    case (a, Zero) => a
    case (a, S(b_1)) =>
      S(add(a, b_1))
  }

def mult(a: N, b: N): N =
  (a, b) match {
    case (a, Zero) => Zero
    case (a, S(b_1)) =>
      add(a, mult(a, b_1))
  }


println(S(S(Zero)))

println(same(S(S(Zero)), S(S(S(Zero)))))
println(same(S(S(Zero)), S(S(Zero))))

println(add(S(Zero), Zero))
println(add(S(S(S(S(S(Zero))))), S(S(Zero))))

println(mult(S(Zero), Zero))
println(mult(Zero, S(S(Zero))))
println(mult(S(Zero), S(S(Zero))))
println(mult(S(S(Zero)), S(S(Zero))))