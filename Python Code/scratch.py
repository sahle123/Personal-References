#Scratch pad to perform quick, numerous different algorithms
#Should document and save them later...

import sys


def main():
	a = input("Give value for a: ")
	b = input("Give value for b: ")
	z = multiply(a,b)
	print("Final answer:", z)
	

def multiply(x, y):
	if y == 0:
		return 0
	z = multiply(x, (y/2))
	print z
	if (y%2) == 0:
		return 2*z
	else:
		return x + 2*z

# For checking a carmichael number.
#def main():
#	a = 561
#	a = (a^(561 - 1) % 561)
#	print a


main()