import unittest

from prime import isPrime

class tests(unittest.TestCase):

    def test1(self):
        """Check that 1 is not prime"""
        self.assertFalse(isPrime(1))
    
    def test2(self):
        """Check that 2 is prime"""
        self.assertTrue(isPrime(2))
    
    def test8(self):
        """Check that 8 is not prime"""
        self.assertFalse(isPrime(8))
    
    def test11(self):
        """Check that 11 is prime"""
        self.assertTrue(isPrime(11))
    
    def test25(self):
        """Check that 25 is not prime"""
        self.assertFalse(isPrime(25))
    
    def test28(self):
        """Check that 28 is not prime"""
        self.assertFalse(isPrime(28))

if __name__ == "__main__":
    unittest.main()