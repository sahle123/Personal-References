# item_count.py
#
#	Finds the count of the most frequent integer in the list.
#
#	Completed: 12/10/15

def most_frequent_item_count(collection):
	current_unique_int = None	# The current int we are iterating through.
	counter = 1					# How many instances of $current_unique_int found in the list.
	length_list = []			# List that will hold each length of counters for each $current_unique_int.
	last_case = False 			# Fringe case for when the last length of integers is not appended to $length_list
	reset_counter = False			# Also helper variable part of the fringe case.

	# Check if $collection is empty
	if collection == []:
		return 0

	list.sort(collection)

	# Create new list of lengths for each unique integer instance
	for i in collection:
		if type(i) != int:
			return "ERROR: Passed in collection is not exclusively integers. Exiting."
		if reset_counter:
			counter = 1
			reset_counter = False
		if i == current_unique_int:
			counter += 1
			last_case = True
		else:
			current_unique_int = i
			length_list.append(counter)
			last_case = False
			reset_counter = True

	if last_case:
		length_list.append(counter)

	# Sort the $length_list and pop off top value (which should be the biggest value).
	list.sort(length_list)

	###print length_list

	return length_list.pop()

##########################################################################################

	#####
	# More elegant answer. From superrafek, jastrzebskib
	#####
	def most_frequent_item_count2(collection):
    if collection:
        return max([collection.count(item) for item in collection])
    return 0
