# Fibonacci sequence algorithm 1
#
#	Date: Sept. 10, 2012
#	Author: Sahle "Nomad" Alturaigi
#
import sys
from numpy import zeros

def main():
	result = input("Enter n for fib sequence: ");
	result = fib_seq(result)
	print(result);
	
	
def fib_seq(n):
	if n == 0:
		return 0;
	if n == 1:
		return 1;
	if n == 2:
		return 1;
		
	x = zeros((n), long)
	x[0] = 0;
	x[1] = 1;
	x[2] = 1;
	# Print out the array of x to see all the indices.
	# print x;
	
	for i in range(2, n):
		x[i] = (x[i-1] + x[i-2])
	print x;
	return x[n-1];	
	
main()