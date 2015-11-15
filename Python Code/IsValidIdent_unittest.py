#IsValudIdent_unittest.py
#
#	Unittest for IsVlaidIdent.py
#
#	LU: 11/15/15

import unittest
from IsValidIdent import is_valid

class isValidTests (unittest.TestCase):

	def testAll(self): 	
		#self.assertEqual(mixed_fraction('42/9'), '4 2/3')

		#self.describe("isValid")
		#self.it("should return true for valid identifiers")
		self.assertEqual(is_valid("okay_ok1"), True, "Wrong result for 'okay_ok1'")
		self.assertEqual(is_valid("$ok"), True, "Wrong result for '$ok'")
		self.assertEqual(is_valid("___"), True, "Wrong result for '___'")
		self.assertEqual(is_valid("str_STR"), True, "Wrong result for 'str_STR'")
		self.assertEqual(is_valid("myIdentf"), True, "Wrong result for 'myIdentf'")

		#self.it("should return false for invalid identifiers")
		self.assertEqual(is_valid("1ok0okay"), False, "Wrong result for '1ok0okay'")
		self.assertEqual(is_valid("!Ok"), False, "Wrong result for '!Ok'")
		self.assertEqual(is_valid(""), False, "Wrong result for an empty string")
		self.assertEqual(is_valid("str-str"), False, "Wrong result for 'str-str'")
		self.assertEqual(is_valid("no no"), False, "Wrong result for 'no no'")

# Run the code in unittest. Raw_inputs will skipped.
unittest.main()