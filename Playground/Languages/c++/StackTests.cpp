#include "gmock/gmock.h"

#include <stack>

using namespace ::testing;

/*
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out).
The standard container classes vector, deque and list fulfill these requirements.
*/
TEST(stack_tests, stacks)
{
	std::stack<int> s(std::deque<int> {1, 2, 3});

	// How to get top element - O(1)
	EXPECT_THAT(s.top(), Eq(3));

	// How to add an element - O(1) amortized time, reallocation may happen
	s.push(4);
	EXPECT_THAT(s.top(), Eq(4));

	// How to check if the stack is empty
	EXPECT_THAT(s.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(s.size(), Eq(4));

	// How to remove an element - O(1)
	s.pop();
	EXPECT_THAT(s.top(), Eq(3));
}
