# Mixed_fractions.py
#
#	Takes an improper fraction and converts it to a mixed fraction.
#
#	LU: 11/8/15

import unittest

def main():

	leInput = raw_input("Give me a fraction (e.g: 32/5): ")

	print mixed_fraction(leInput)

	return 0

def mixed_fraction(s):

	numer = 0	# Numerator then later a dummy variable
	denom = 0	# Denominator
	c = 0 		# new numerator
	d = 0		# Whole number

	# Remove '/'' from fraction
	s = s.split("/")

	#####
	# Check for proper length
	#####
	if len(s) != 2:
		return "Syntax error or improper length input. \nMust be in the form: X/Y"
	print s

	#####
	# Check if we were supplied integers
	#####
	try:
		numer = int(s[0])
		denom = int(s[1])
		1/denom		# Check for division by zero
		s =[] 		# Empty the list. Will use as final answer variable
	except ValueError:
		return "Got back a ValueError. Did you supply integers?"

	# If the numerator is 0, then we're done here.
	if numer == 0:
		return '0'

	#####
	# Convert improper fraction to mixed fraction
	#####

	# Get new numerator and get whole number fraction
	# -X/-Y case
	if numer < 0 and denom < 0:
		numer = -numer
		denom = -denom
		c = numer % denom
		d = (numer - c)/denom

	# -X/Y or X/-Y case
	elif numer < 0 or denom < 0:
		c = abs(numer) % abs(denom)
		d = -(abs(numer) - c)/abs(denom)

		# If do not have a whole number, carry the -1 to 
		# the new numerator.
		if d == 0:
			c = -c


	# X/Y case
	else: 
		c = numer % denom
		d = (numer - c)/denom

	# Reduce fraction by its greatest common denominator
	numer = gcd(c, abs(denom))
	c = c/numer
	denom = abs(denom)/numer

	#####
	# Combine the inputs into the proper format as a stirng
	#####
	if c == 0:
		s = str(d)
	elif d == 0:
		s = str(c) + '/' + str(denom)
	else:
		s = str(d) + ' ' + str(c) + '/' + str(denom)

	return s


def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

if __name__ == '__main__':
	main()
