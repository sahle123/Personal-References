#stringy_strings.py
#
#	Takes an input and outputs alternating 1s and 0s equal to the passed in input.
#
#	LU: 12/04/15

def main():

	leInput = raw_input("Size: ")
	
	print stringy(int(leInput))

	return "Exit successful!"

def stringy(size):

	result = ""

	# We need at least 1 input
	if size < 1:
		return "Size must be greater than 1!"
	
	for i in range(0, size/2):
		result += "10"
	
	# If the string is odd, pad 1 at the end
	if ((size % 2) == 1):
		result += "1"

	return result


# Boilerplate code
if __name__ == '__main__':
	main()