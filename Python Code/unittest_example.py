import unittest

# Here's our "unit".
def IsOdd(n):
    return n % 2 == 1

# Here's our "unit tests".
class IsOddTests(unittest.TestCase):

    def testOne(self):
        self.assertEqual(IsOdd(1), True)

    def testTwo(self):
        self.assertEqual(IsOdd(2), False)

def main():
    unittest.main()

if __name__ == '__main__':
    main()