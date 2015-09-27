###############################################################################
#
#	Date: 09/06/12
# 	Author: Sahle A. Alturaigi
#	
#	Description: This program is just a small test to understand and see how
#				 shift operators work. 
#
###############################################################################

import sys

def main():
	
	# Declare x and assign 3 to it
	x = 3
	
	# (optional) Make x an interger data type
	int(x)
	print x
	print 'Testing shift operators now...'
	
	# Left shift x by 2 bits and pad the extra bits with 0s.
	x = x >> 2
	print x
	
	# Standard boilerplate to call the main() function to begin
	# the program
if __name__ == '__main__':
	main()