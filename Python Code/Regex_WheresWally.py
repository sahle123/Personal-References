#Regex_WheresWally.py
#
#
#	LU: 09/27/15
#

import re

def wheres_wally(string):

    for i in re.finditer(r"(^|\s)Wally\b", string):
    	print '%i %s' % (i.start(), i.group(0))
        
	return i.start()

def main():

	string = raw_input("Please input string for wheres_wally: ")

	print "Final Answer is: " + str(wheres_wally(string))

	return


main()

# Some Regex notes in Python
#	1.) The 'r' prefix means to treat the string as a raw string (i.e. there will be no special characters)
#	2.) The '/' is the prefix and end to a regex. e.g. /regular expressions here/. I don't think this rule holds for python?
#	3.) 


# Here is the solution that worked

	# import re

	#def wheres_wally(string):

	#	for i in re.finditer(r"^Wally\b", string):
	#		return i.start()
	#	for i in re.finditer(r"\sWally\b", string):
	#		return i.start() + 1
	#  	return -1