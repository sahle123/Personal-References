# Mixed_fractions_unittest.py
#
#	Unittest for Mixed_fractions.py
#
#	LU: 11/8/15

import unittest
from Mixed_fractions import mixed_fraction

class FractionsTests (unittest.TestCase):

	def testAll(self): 	# <-- These fuckers right here always MUST start with 'test' as the function name. 
						# Otherwise, nothing will happen. Fuck that design choice...
		self.assertEqual(mixed_fraction('42/9'), '4 2/3')
		self.assertEqual(mixed_fraction('6/3'), '2')
		self.assertEqual(mixed_fraction('4/6'), '2/3')
		self.assertEqual(mixed_fraction('0/18891'), '0')
		self.assertEqual(mixed_fraction('-10/7'), '-1 3/7')
		self.assertEqual(mixed_fraction('-22/-7'), '3 1/7')
		self.assertRaises(ZeroDivisionError, lambda: mixed_fraction('0/0')) 
		self.assertRaises(ZeroDivisionError, lambda: mixed_fraction('3/0'))
		self.assertEqual(mixed_fraction('-2/4'), '-1/2')
		self.assertEqual(mixed_fraction('2/-4'), '-1/2')
		self.assertEqual(mixed_fraction('-2/-4'), '1/2')
		self.assertEqual(mixed_fraction('-6/4'), '-1 1/2')
		self.assertEqual(mixed_fraction('6/-4'), '-1 1/2')
		self.assertEqual(mixed_fraction('-6/-4'), '1 1/2')


# Run the code in unittest. Raw_inputs will skipped.
unittest.main()