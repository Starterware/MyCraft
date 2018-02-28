# -*- coding: utf-8 -*-

import re

DEFAULT_DELIMITERS = [",", "\n"]
   
class StringCalculator(object):
    
    def add(self, s):
        numbers = self._extract_numbers(s)
        return sum(self._filter_numbers(numbers))
    
    def _extract_numbers(self, s):
        delimiters = DEFAULT_DELIMITERS
        if (s.startswith("//")):
            delimiters += self._extract_user_defined_delimiters(s)
            s = s[s.find("\n")+1:]
        return list(map(lambda x : int(x or 0), re.split("|".join(delimiters), s)))
    
    def _extract_user_defined_delimiters(self, s):
        s = s[2:].split("\n")[0]
        if s.startswith("["):
           return list(map(lambda x: re.escape(x), s[1:len(s)-1].split("][")))
        return list(s[0])
    
    def _filter_numbers(self, numbers):
        negatif_numbers = list(filter(lambda x : x < 0, numbers))
        if len(negatif_numbers) > 0:
            raise ValueError("The add method cannot take negative integers: " + ",".join(map(str, negatif_numbers)))  
        return list(filter(lambda n : n < 1000, numbers))