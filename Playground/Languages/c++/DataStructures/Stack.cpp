#include "gmock/gmock.h"

#include <stack>

using namespace ::testing;

/*
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out).
The standard container classes vector, deque and list fulfill these requirements.
*/

class Stack : public Test {
protected:
	std::stack<int> s;
};

TEST_F(Stack, test_empty)
{
	ASSERT_THAT(s.empty(), Eq(true));
}

TEST_F(Stack, test_size)
{
	ASSERT_THAT(s.size(), Eq(0));
}

TEST_F(Stack, test_add_element) // O(1)
{
	s.push(1);
	ASSERT_THAT(s.size(), Eq(1));
}

TEST_F(Stack, test_see_next_element) // O(1)
{
	s.push(1);
	s.push(2);

	ASSERT_THAT(s.top(), Eq(2));
}

TEST_F(Stack, test_remove_element) // O(1)
{
	s.push(1);
	s.push(2);
	s.pop();

	ASSERT_THAT(s.top(), Eq(1));
}

TEST(StackBasedOnDifferentContainer, test_creation)
{
	std::stack<int, std::vector<int>> s;
	s.push(3);
	ASSERT_THAT(s.top(), Eq(3));
}

TEST(StackInitFromContainer, test_creation)
{
	std::stack<int> s(std::deque<int> {1, 2, 3});
	ASSERT_THAT(s.top(), Eq(3));
}

