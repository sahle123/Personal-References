#consonant_count.py
#
#	Script that counts all the consonants in a string. Not efficient.
#
#	LU: 11/23/15

import re

def main():

	a = raw_input("Give me a string to count: ")

	print consonant_count(a)

	return 0

def consonant_count(s):
	count = 0
	
    # Escape vowels, whitespaces, and digits.
	s = re.sub(r"(?i)(a|e|i|o|u)|\s|\d","", s)
    # Escape special characters
	s = re.sub(r"_|-|=|\+|&|!|@|#|%|<|>|:|;|'|\"|\.|\*|\+|\?|\$|\^|\/|\\|\[|\{|\(|\)|\}|\]","", s)

	#print s

	for i in s:
		count += 1

	return count


## Below is a more effective solution made by stefannew

	#import re

	#def consonant_count(s):
	#   return len(re.sub(r'[aeiou\d\s\W\_]', '', s))