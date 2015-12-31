# MontyHall_unittest.py
#
#	Unittest module for MontyHall.py
#
#	LU: 12/24/15

import unittest
from MontyHall import monty_hall

class MontyTests (unittest.TestCase):

	def testAll(self):

		self.assertEqual(monty_hall(1, [3,3,2,3,3,2,2,3,2,2,1,1,1,1]), 71)
		self.assertEqual(monty_hall(2, [3,3,2,3,3,2,2,3,2,2,1,1,1,1]), 64)
		self.assertEqual(monty_hall(3, [3,3,2,3,3,2,2,3,2,2,1,1,1,1]), 64)

# Run the unittest code.
unittest.main()