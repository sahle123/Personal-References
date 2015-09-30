// Algorithm that illustrates tail recursion--an important concept in CS.
// Date: 9/18/13
// Taken from the website below, kudos to you:
// http://stackoverflow.com/questions/33923/what-is-tail-recursion

def recsum(x: Int): Int =
{
	if (x == 1)
		return x;
	else
		return x + recsum(x - 1);
}

// Examples:
val result = recsum(5) // 5 + 4 + 3 + 2 + 1
println(s"The Result is: $result");

// Note: s will provide string literal to $result
// 		 f will provide float literal to $result
//		 raw will provide raw literal to $result. 
//       These are called interpolators
