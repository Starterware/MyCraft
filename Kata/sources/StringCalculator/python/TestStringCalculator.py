# -*- coding: utf-8 -*-

import unittest
from StringCalculator import StringCalculator
 
class TestStringCalculator(unittest.TestCase):
    __calculator = StringCalculator();
        
    def test_additionOfNoNumbersGivesZero(self):
        self.assertEqual(self.__calculator.add(""), 0)
        
    def test_additionOfOneNumbersGivesThatNumber(self):
        self.assertEqual(self.__calculator.add("5"), 5)
        
    def test_additionOfMultipleCommaSepartedNumbersGivesTheAdditionOfThoseNumbers(self):
        self.assertEqual(self.__calculator.add("3,7,43,6,11"), 70)

    def test_additionAllowsNewLinesAsDelimiters(self):
        self.assertEqual(self.__calculator.add("101\n14,42\n1"), 158)
        
    def test_additionAllowsUserDefinedDelimiters(self):
        self.assertEqual(self.__calculator.add("//;\n23;37,21"), 81)
        
    def test_additionDoesNotAllowNegatifNumbers(self):
        with self.assertRaises(ValueError) as context:
            self.__calculator.add("3,-4,-2")
        self.assertTrue("-4,-2" in str(context.exception))
        
    def test_additionIgnoresNumbersAboveOneThuisand(self):
        self.assertEqual(self.__calculator.add("12,1001"), 12)
        
    def test_additionAllowsMultiCharsDelimiters(self):
        self.assertEqual(self.__calculator.add("//[***]\n2***3***4"), 9)
        
    def test_additionAllowsMultipleUserDefinedDelimiters(self):
        self.assertEqual(self.__calculator.add("//[;][~~]\n1~~3;4,7"), 15)
        
if __name__ == '__main__':
    unittest.main()