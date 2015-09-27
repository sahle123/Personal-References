# Code to test the extended euclid function.
#
#	Written By: Sahle "Nomad" Alturaigi
#	Algorithm taken from the book: "Algorithms" by Sanjoy Dasgupta, 
#   Christos Papadimitriou and Umesh Vazirani.
#

def main():
	m = input("\nPlease type in a value for m: ")
	n = input("Now for n: ")
	print("Bezout's Theorum, m*X + n*Y = 1")
	print("\nFormat: (X, Y, Greatest common divisor)")
	result = extended_euclid(m,n);
	print result
	

def extended_euclid(a, b):
	if b == 0:
		return (1,0,a)
	(x, y, d) = extended_euclid(b, (a%b))
	# m*X + n*y = d where d > 1
	# d can't divide both m and n (or else they wouldn't be relatively prime.
	# So we can write m = d*q + r where 0 < r < d
	# r = m - (d)*q
	# r = m - (m*x + n*y)*q
	# r = m(1-q*x) - n*(q*y)
	return(y,(x-(a/b)*y),d);

main()