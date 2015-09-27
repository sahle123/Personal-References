/*
*	Dec. 15th, 2013
*
*/			

val x = 1000
def first():Unit = {
	val a = 12
	def second():Unit = {
		val b = 3
		println(a)
		println(b)
		println(x)
	}
	second
}

first