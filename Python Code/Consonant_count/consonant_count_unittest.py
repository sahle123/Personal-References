

import unittest
from consonant_count import consonant_count

class MyTest (unittest.TestCase):

	def testAll(self):
		self.assertEqual(consonant_count(''), 0, 'Test string is empty string');
		self.assertEqual(consonant_count('aaaaa'), 0, 'Test string: "aaaaa"');
		self.assertEqual(consonant_count('XaeiouX'), 2, 'Test string: "XaeiouX"');
		self.assertEqual(consonant_count('AAAAA'), 0, 'Test string: "AAAAA"');
		self.assertEqual(consonant_count('Bbbbb'), 5, 'Test string: "Bbbbb"');
		self.assertEqual(consonant_count('helLo world'), 7, 'Test string: "helLo world"');
		self.assertEqual(consonant_count('h^$&^#$&^elLo world'), 7, 'Test string: "h^$&^#$&^elLo world"');
		self.assertEqual(consonant_count('0123456789'), 0, 'Test string: "0123456789"')
		self.assertEqual(consonant_count('012345_Cb'), 2, 'Test string: "012345_Cb"')

unittest.main()