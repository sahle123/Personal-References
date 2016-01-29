# string_keyValue_pair.py 
#
#	Des:	A simple kata in where we put in a list of characters
#			and return a new list of characters with line numbers
#			appended. Similar to a associative array, but instead
#			of having explicit key, value pairs, these pairs are
#			inferred inside of the string list
#
#			e.g ["a", "b", "c"] ---> ["1: a", "2: b", "3: c"]
#
#
#	LU: 01/23/16

def number(lines):
	if (len(lines) == 0)|(lines == None):
		return []
	else:
		result = []
		j = 1
		for i in lines:
			result.append(str(j) + ": " + str(i))
			j += 1
		return result