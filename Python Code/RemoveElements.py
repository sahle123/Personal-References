#RemoveElements.py
#
#	Remove entries from a list completely. Uses list comprehension.
#
#	Nov 3rd, 2015
#

class List(object):
    def remove_(self, integer_list, values_list):
		for i in values_list:
			integer_list = [val for val in integer_list if val != i]
        
		print integer_list
		return integer_list