# MontyHall.py
#
#	Des:	A small exercise where an array of paricipant guesses
#			and the correct door number are passed. monty_hall changes
#			everyone's guess to the next and returns the win rate 
#			percentage. Uses list comprehensions
#	Status: Functional
#
#	LU: 12/24/15

import unittest

def monty_hall(correct_door_number, participant_guesses):
	temp = [i for i in participant_guesses if i != correct_door_number]
	result = float(len((temp)))/float(len(participant_guesses))
	return int(round(result*100))

def main():
	print "Percentage: " +str(monty_hall(1, [3,3,2,3,3,2,2,3,2,2,1,1,1,1]))

if __name__ == '__main__':
	main()