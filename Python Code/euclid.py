#
#Uses the simple euclidian algorithm to find the greatest common
#divisor.
#
def main():
	a = input("Please enter a value: ");
	b = input("Enter a value less then the last one: ");
	result = euclid(a, b);
	print "the greatest common divisor is...", result;

# Precondition: 'a' must be greater than 'b'. (a >= b >= 0) 
# postcondition: the greatest common divisor is computed via Euclid of Alexandria's algorithm.
def euclid(a, b):
	if b == 0: 
		return a;
	return euclid(b, a%b);

main();