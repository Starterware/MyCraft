#include "gmock/gmock.h"

TEST(string_tests, concatenation)
{
	std::string s{ "hello" };
	std::string s2{ "world" };

	EXPECT_THAT(s + " " + s2, "hello world"); // Slow way of concatenating. Copies all the strings to another place

	s += " " + s2; // Faster way of concatenating. Appends the second string to the first one.
	EXPECT_THAT(s, "hello world"); 

	s.append("!"); // Same as +=. Appends the second string to the first one.
	EXPECT_THAT(s, "hello world!"); 
}

TEST(string_tests, stringstream)
{
	std::stringstream ss;

	ss << "hello" << " " << "world";

	EXPECT_THAT(ss.str(), "hello world"); // Not as fast as concatenation but better for concatinating non string variables.
}
