#####################################################################
#	Ref.py
# This will serve as a referrence program to help me bettr
# understand python. 
#
# Python is a dynamic, interpreted language. Source code does 
# not declare the types of variables, parameters or methods.
# This makes the code short and flexible and you lose the
# compile-time type checking in the source code.
# Python tracks all the type of all values at runtime and
# flag code that does not make sense as it runs. (Frm. Google code)

# When declaring varibles, the data type does not need to be
# specified, however, I believe you need to respect what
# data are already inside of it.

# Python code does NOT need compilation. It can be run from
# the command prompt by typing the './' and then the code file.
# (Or you could type 'python' before it.)

# 'import' is sort of the same as 'include' in C. This will
# let you pull out 'modules' (as python calls it) to perform
# certain functions. 

# 'def' allows you to define functions follow by the ':' to indicate
# where the function starts.

# braces (delimiters) are NOT used in python in order to start
# a function's code, you must indent. At the end of the function
# remove the indentation.

## Standard boilerplate to call the main() function to begin
# the program
#if __name__ == '__main__':
#	main()
# 
# This is always needed apparently... Will learn of it later.

#####################################################################

# import modules used here -- sys is a very standard module.
import sys

# Gather our code in a main() function
def main():
	print 'Hello there', sys.argv[1]
	# Commmand line args are in sys.argv[1], sys.argv[2]...
	# sys.argv[0] is the script name itself and can be ignored
	print repeat('Yay', False)
	print repeat('Woo Hoo', True)
	

def repeat(s, exclaim):
	result = s + s + s
	if exclaim:
		result = result + '!!!'
	return result

# Standard boilerplate to call the main() function to begin
# the program
if __name__ == '__main__':
	main()