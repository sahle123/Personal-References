#IsValidIdent.py
#
# 	Checks if input is a valid identifier. Below is the list.
#
#		1.) Each identifier must have at least one char.
#		2.) The first char my be picked from (alphabet), (underscore), or (dollar sign).
#		3.) Any char after the first can be any of number (2) as well as (digits).
#
#	LU: 11/15/15

import re 

def main():
	l = raw_input("Give a string: ")

	print is_valid(l)

	return 0

def is_valid(idn):

	# Check for rule 2.)
	if re.match(r"^[a-zA-Z_\$]", idn):
		# Check for rule 3.)
		for i in re.finditer(r"[^\w\$]", idn):
			if i:
				print "No match!"
				return False
		print "Match!"
		return True		
	
	# Otherwise, no match
	print "No match!"
	return False


if __name__ == "__main__":
	main()

# Another solution
#import re

#def is_valid(idn):
    # Your code here
#    line = re.match(r'[a-zA-Z_$]\w*$', idn)
#    if line:
#        return True
#    else:
#        return False