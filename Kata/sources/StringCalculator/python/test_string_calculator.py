# -*- coding: utf-8 -*-

import unittest
import calculator
 
class TestStringCalculator(unittest.TestCase):
    
    def setUp(self):
        self.calculator = calculator.StringCalculator();
        
    def testAdditionOfNothing(self):
        self.assertEqual(self.calculator.add(""), 0)
        
    def testAdditionOfOneNumber(self):
        self.assertEqual(self.calculator.add("5"), 5)
        
    def testAdditionOfCommaSepartedNumbers(self):
        self.assertEqual(self.calculator.add("3,7,43,6,11"), 70)

    def testAdditionAllowsNewLinesAsDelimiter(self):
        self.assertEqual(self.calculator.add("101\n14,42\n1"), 158)
        
    def testAdditionAllowsAUserDefinedDelimiter(self):
        self.assertEqual(self.calculator.add("//;\n23;37,21"), 81)
        
    def testAdditionDoesNotAllowNegatifNumbers(self):
        with self.assertRaises(ValueError) as context:
            self.calculator.add("3,-4,-2")
        self.assertTrue("-4,-2" in str(context.exception))
        
    def testAdditionIgnoresNumbersAboveOneThuisand(self):
        self.assertEqual(self.calculator.add("12,1001"), 12)
        
    def testAdditionAllowsUserDefinedMultiCharsDelimiters(self):
        self.assertEqual(self.calculator.add("//[***]\n2***3***4"), 9)
        
    def testAdditionAllowsMultipleUserDefinedDelimiters(self):
        self.assertEqual(self.calculator.add("//[;][~~]\n1~~3;4,7"), 15)
        
if __name__ == '__main__':
    unittest.main()