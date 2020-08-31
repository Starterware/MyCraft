#include "gmock/gmock.h"

using namespace ::testing;

TEST(StringMatchers, testEndsWith) {
	std::string s = "start end";
	ASSERT_THAT(s, EndsWith("end"));
}

TEST(StringMatchers, testStartsWith) {
	std::string s = "start end";
	ASSERT_THAT(s, StartsWith("start"));
}

TEST(StringMatchers, testContainsRegex) {
	std::string s = "___abcd___";
	ASSERT_THAT(s, ContainsRegex("a.*d")); // uses simple regular expression
}

TEST(StringMatchers, testMatchesRegex) {
	std::string s = "++++abcd";
	ASSERT_THAT(s, MatchesRegex("\\+*\\w*")); // uses simple regular expression
}

TEST(StringMatchers, testHasSubstring) {
	std::string s = "start middle end";
	ASSERT_THAT(s, HasSubstr("middle"));
}

TEST(StringMatchers, testStringEqualCaseInsensitive) {
	std::string s = "TeST";
	ASSERT_THAT(s, StrCaseEq("test"));
}

