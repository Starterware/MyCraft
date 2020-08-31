#include "gmock/gmock.h"

using namespace ::testing;

TEST(String, test_concatenation_slow)
{
	std::string s{ "hello" };
	std::string s2{ "world" };

	EXPECT_THAT(s + " " + s2, Eq("hello world")); // Slow way of concatenating. Copies all the strings to another place
}

TEST(String, test_concatenation_fast_1)
{
	std::string s{ "hello" };
	std::string s2{ "world" };

	s += " " + s2; // Faster way of concatenating. Appends the second string to the first one.
	EXPECT_THAT(s, Eq("hello world"));
}

TEST(String, test_concatenation_fast_2)
{
	std::string s{ "hello world" };
	s.append("!"); // Same as +=. Appends the second string to the first one.
	EXPECT_THAT(s, Eq("hello world!"));
}

TEST(String, test_loop_1) 
{
	std::string s{ "he**o wor*d!" };
	for (char& c : s) {
		if (c == '*')
			c = 'l';
	}
	EXPECT_THAT(s, Eq("hello world!")); 
}

TEST(String, test_loop_2) 
{
	std::string s{ "he**o wor*d!" };
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*')
			s[i] = 'l';
	}
	EXPECT_THAT(s, Eq("hello world!")); 
}

TEST(String, test_iterator) 
{
	std::string s{ "he**o wor*d!" };
	std::replace(s.begin(), s.end(), '*', 'l');
	EXPECT_THAT(s, Eq("hello world!")); 
}

TEST(String, test_find_substring) {
	std::string s{ "abcdefabcdef" };

	ASSERT_THAT(s.find("abc", 0), Eq(0));
	ASSERT_THAT(s.find("abc", 3), Eq(6));
	ASSERT_THAT(s.find("abc", 9), Eq(std::string::npos));
}

TEST(String, test_compare) {
	std::string s{ "abcdef" };

	ASSERT_THAT(s.compare("abcdef"), Eq(0));
	ASSERT_THAT(s.compare("abcdd"), Gt(0));
	ASSERT_THAT(s.compare("abcdf"), Lt(0));
}

TEST(Stringstream, test_concatenation)
{
	std::stringstream ss;
	ss << "hello" << 1 << "world";
	EXPECT_THAT(ss.str(), "hello1world"); // Not as fast as concatenation but better for concatenating non string variables.
}
