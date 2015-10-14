#sum_circles.py
#
#	Finds the sum of all the areas of the circles and adds them together
#	This code uses variable length parameters. Good ref.
#

import math
def sum_circles(*args):

	result = 0.0
	i = 0

	for i in args:
		result = result + getArea(i)

	result = int(round(result))

	return "We have this much circle: " + str(result)
    
def getArea(diameter):
	return math.pi*pow((diameter/2.0), 2)
