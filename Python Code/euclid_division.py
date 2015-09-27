#
#	Author: Sahle A. "Nomad" Alturaigi
#	Date: Sept. 17, 2012
#

def main():
	x = input("Please type in value (will be inverted) ")
	y = input("Now the modulus ")
	if (x < 0):
		print("Invalid values...")
		return
	result = extended_euclid(x,y);
	if (result[2] > 1):
		print("NULL")
		return
		
	x = result[0]
	print result[2]
	result = x % y
	print result
	
def extended_euclid(a, b):
	if b == 0:
		return (1,0,a)
	(x, y, d) = extended_euclid(b, (a%b))
	return(y,(x-(a/b)*y),d);
	
main()