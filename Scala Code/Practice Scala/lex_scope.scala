/*
*	Dec. 15th, 2013
*	Tests Lexical scoping in Scala	
*	Output:
*		12
*		3
*/			

def first():Unit = {
	val a = 12
	def second():Unit = {
		val b = 3
		println(a)
		println(b)
	}
	second
}

first