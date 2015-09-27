/*
*	Dec. 15, 2013
*	Test for Dynamic scoping in Scala
*		This should FAIL.
*
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

def outside():Unit = {
	println(a)
}

first
outside
