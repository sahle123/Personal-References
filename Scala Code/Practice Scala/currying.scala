/*
*	Dec. 15, 2013
*/

def currying(a:Int)(b:Int)(c:Int) = {
	a+b+c
}

val d = currying(1)(1)(1)
println(d)