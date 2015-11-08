# Quick GCD test
#
#	Usage: python gcd_test <a> <b>
#
# 	LU: 11/8/15

import sys

def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def main():

	a = int(sys.argv[1])
	b = int(sys.argv[2])

	print gcd(a,b)
	return

if __name__ == '__main__':
	main()