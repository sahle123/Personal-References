// This is just me playing around with what I have learned from chapter 2.
// CODE IS INCOMPLETE

// Setting up a function
val i = 100
val x = Console.readInt

def which_is_bigger(x: Int): Int = {

	if(x > i) {
		return x;
	}
	else {
		return i;	
	}
}

// Calling the "which_is_bigger()" function
val arg = which_is_bigger(x)

if(arg == x) {
	println("\nLooks like your number is bigger.");
}
else {
	println("\nMy number was bigger.");
}

