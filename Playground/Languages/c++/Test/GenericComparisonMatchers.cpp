#include "gmock/gmock.h"

using namespace ::testing;

TEST(GenericComparisonMatchers, testEqual) {
	std::string s = "test";
	ASSERT_THAT(s, Eq("test"));
}

TEST(GenericComparisonMatchers, testNotEqual) {
	std::string s = "test";
	ASSERT_THAT(s, Ne("not_test"));
}

TEST(GenericComparisonMatchers, testGreaterThan) {
	ASSERT_THAT(10, Gt(5));
}

TEST(GenericComparisonMatchers, testGreaterOrEqualThan) {
	ASSERT_THAT(5, Ge(5));
	ASSERT_THAT(6, Ge(5));
}

TEST(GenericComparisonMatchers, testLessThan) {
	ASSERT_THAT(2, Lt(5));
}

TEST(GenericComparisonMatchers, testLessOrEqualThan) {
	ASSERT_THAT(5, Le(5));
	ASSERT_THAT(4, Le(5));
}

TEST(GenericComparisonMatchers, testIsTrue) {
	bool value = true;
	ASSERT_THAT(value, IsTrue());
}

TEST(GenericComparisonMatchers, testIsFalse) {
	bool value = false;
	ASSERT_THAT(value, IsFalse());
}

TEST(GenericComparisonMatchers, testIsNull) {
	void* value = nullptr;
	ASSERT_THAT(value, IsNull());
}

TEST(GenericComparisonMatchers, testIsNotNull) {
	int tmp = 5;
	int* value = &tmp;
	ASSERT_THAT(value, NotNull());
}

TEST(GenericComparisonMatchers, testNot) {
	ASSERT_THAT(5, Not(Eq(4)));
}

