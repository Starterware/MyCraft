[Home](https://github.com/Starterware/Training)

# String Calculator 

The complete description can be found at [link](http://osherove.com/tdd-kata-1/).

1. Create a simple string calculator method:
	* It can take 0, 1 or 2 numbers, and will return their sum (for an empty string it will return 0)
	* Ex: "" or "1" or "1,2"
	
2. Allow the method to handle an unknown amount of numbers

3. Allow the method to handle new lines between numbers (instead of commas)

4. Support different delimiters:
	* with format //delimiter\n[numbers...] for example “//;\n1;2”

5. Calling the method with a negative number will throw an exception with all the negative numbers in the exception message

6. Negative numbers must be ignored

7. Delimiters can be of any length with the format “//[delimiter]\n”

8. Allow multiple delimiters with the format “//[delim1][delim2]\n”
