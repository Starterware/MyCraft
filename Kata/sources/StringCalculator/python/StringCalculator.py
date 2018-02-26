# -*- coding: utf-8 -*-

import re

class StringCalculator(object):
 
    def add(self, s):
        if len(s) > 0:
            addition = 0
            numbers = self.extract_numbers(s)
            if self.numbers_are_valid(numbers):
                for number in numbers:
                    addition += self.convert_to_int(number)
            return addition;
        return 0;
    
    def extract_numbers(self, s):
        delimiters = [",", "\n"]
        if (s.startswith("//")):
            delimiters += self.extract_user_defined_delimiters(s)
            s = s[s.find("\n")+1:]
        numbers = re.split("|".join(delimiters), s)
        return numbers
    
    def extract_user_defined_delimiters(self, s):
        delimiters = []
        if s[2] == '[':
            start_pos = 2
            while s[start_pos] == '[':
                end_pos = s[start_pos:].find("]") + start_pos
                delimiters.append(re.escape(s[start_pos+1:end_pos]))
                start_pos = end_pos + 1
        else:
            delimiters.append(re.escape(s[2]))
        return delimiters
                
    def convert_to_int(self, string_number):
        integer = int(string_number)
        if integer > 1000:
            integer = 0
        return integer
    
    def numbers_are_valid(self, numbers):
        negatif_numbers = []
        for number in numbers:
            if number.startswith("-"):
                negatif_numbers.append(number)
        if len(negatif_numbers) > 0:
            raise ValueError("The add method cannot take negative integers: " + ",".join(negatif_numbers))  
        return True