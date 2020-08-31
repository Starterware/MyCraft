#include "gmock/gmock.h"

using namespace ::testing;

// ==== Fast way to create Matchers ====

// use negation if you want a better message when using Not()
MATCHER(MyCustomMatcher, std::string{ "to" } + (negation ? " not" : "") + " be equal to 5") { 
	if (arg == 5)  // arg is the value we are verifying
		return true;
	if (arg >= 3 && arg <= 7)
		*result_listener << "close but not quite there"; // additional information added in parentheses next to the obtained value
	return false;
};

MATCHER_P(MyCustomMatcher, value, "is absolute value of") {
	return abs(arg) == value;
}

MATCHER_P2(MyCustomMatcher, value1, value2, std::string{ "to be equal to " } + std::to_string(value1*value2)) {
	return arg == value1 * value2;
}

// ==== Slower way to create Matchers ====

class MonomorphicCustomMatcher : public MatcherInterface<int> {
public:
	MonomorphicCustomMatcher(int param) : param(param) {}

	bool MatchAndExplain(int n, MatchResultListener* /* listener */) const override {
		return abs(n) == param;
	}

	void DescribeTo(std::ostream* os) const override {
		*os << "is absolute value of " << param;
	}

	void DescribeNegationTo(std::ostream* os) const override {
		*os << "isn't absolute value of " << param;
	}

protected:
	int param;
};

Matcher<int> MyMonomorphicCustomMatcher(int param) {
	return MakeMatcher(new MonomorphicCustomMatcher(param));
}

class PolymorphicCustomMatcher {
public:
	PolymorphicCustomMatcher(int param) : param(param) {}

	template <typename T>
	bool MatchAndExplain(T n, MatchResultListener* /* listener */) const {
		return abs(n) == (T)param;
	}

	void DescribeTo(std::ostream* os) const {
		*os << "is absolute value of " << param;
	}

	void DescribeNegationTo(std::ostream* os) const {
		*os << "isn't absolute value of " << param;
	}

protected:
	int param;
};

PolymorphicMatcher<PolymorphicCustomMatcher> MyPolymorphicCustomMatcher(int param) {
	return MakePolymorphicMatcher(PolymorphicCustomMatcher(param));
}

// ===== Tests =====

TEST(CustomMatcher, testCustomMatcherWithoutParameter) {
	ASSERT_THAT(5, MyCustomMatcher());
}

TEST(CustomMatcher, testCustomMatcherWithNot) {
	ASSERT_THAT(3, Not(MyCustomMatcher()));
}

TEST(CustomMatcher, testCustomMatcherWithParameter) {
	ASSERT_THAT(-5, MyCustomMatcher(5));
}

TEST(CustomMatcher, testCustomMatcherWith2Parameters) {
	ASSERT_THAT(10, MyCustomMatcher(5, 2));
}

TEST(CustomMatcher, testMonomorphicCustomMatcher) {
	ASSERT_THAT(-10, MyMonomorphicCustomMatcher(10));
	// ASSERT_THAT(-10.0, MyMonomorphicCustomMatcher(10)); // Not possible because -10.0 is not an int
}

TEST(CustomMatcher, testPolymorphicCustomMatcher) {
	ASSERT_THAT(-10, MyPolymorphicCustomMatcher(10));
	ASSERT_THAT(-10.0, MyPolymorphicCustomMatcher(10)); 
}

