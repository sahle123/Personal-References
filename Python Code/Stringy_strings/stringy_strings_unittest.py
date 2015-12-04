# stringy_strings_unittest.py
#
#	Unittest for stringy_strings.py
#	
#	Usage: python stringy_strings.unittest.py
#
#	LU: 12/04/15

import unittest
from stringy_strings import stringy

class MyTest (unittest.TestCase):

	def testEverything(test): # <-- Make sure this method starts with the string "test."

		test.assertEqual(str(type(stringy(5)))[1:-1],"type 'str'","stringy() should return a string")
		test.assertEqual(stringy(10)[0],'1',"Whoops your string doesn't start with a '1'")

		for i in xrange(1,5):
		  test.assertEqual(len(stringy(i)),i,"Make sure your string is the right length")

		test.assertEqual(stringy(3), '101', 'oops try again')
		test.assertEqual(stringy(5), '10101', 'oops try again')
		test.assertEqual(stringy(12), '101010101010', 'oops try again')
		test.assertEqual(stringy(26), '10101010101010101010101010', 'oops try again')
		test.assertEqual(stringy(28), '1010101010101010101010101010', 'oops try again')

# Starts the unittest in main. Raw_inputs are skipped.
unittest.main()