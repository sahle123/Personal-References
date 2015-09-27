// Method1.scala

def multiplyByTwo(x:Int):Int = {
	println("Inside multiplyByTwo")
	return (x*2) // You do not have to use the return keyword
}

val r = multiplyByTwo(5) // Method call
println(r)