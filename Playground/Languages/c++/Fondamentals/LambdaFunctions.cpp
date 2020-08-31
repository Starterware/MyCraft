#include <gmock\gmock-matchers.h>

using namespace ::testing;

TEST(LambdaFunction, test_simple_function) {
	auto fct = [](const int& a, int b) { return a * b; };
	ASSERT_THAT(fct(1, 2), Eq(2));
}

TEST(LambdaFunction, test_outside_variables_by_reference) {
	int x = 1;
	int y = 1;
	auto fct = [&]() { 
		x++;
		y++;
	};
	fct();

	ASSERT_THAT(x, Eq(2));
	ASSERT_THAT(y, Eq(2));
}

TEST(LambdaFunction, test_outside_variables_by_value) {
	int x = 1;
	int y = 1;
	auto fct = [=]() { 
		return x + y;  // cannot modify x and y because they are not lvalues
	};
	ASSERT_THAT(fct(), Eq(2));
}

TEST(LambdaFunction, test_outside_variables_for_specific_one) {
	int x = 1;
	int y = 1;
	auto fct = [=, &x]() { 
		x++;
	};
	fct();
	ASSERT_THAT(x, Eq(2));
}

TEST(LambdaFunction, test_outside_variables_for_specific_one_2) {
	int x = 1;
	int y = 1;
	auto fct = [&x]() { 
		x++;
	};
	fct();
	ASSERT_THAT(x, Eq(2));
}
