#include "gmock/gmock.h"

#include <list>

using namespace ::testing;

class List : public Test {
protected:
	std::list<int> l;
};

TEST_F(List, test_empty)
{
	ASSERT_THAT(l.empty(), Eq(true));
}

TEST_F(List, test_size)
{
	ASSERT_THAT(l.size(), Eq(0));
}

TEST_F(List, test_add_element_back) // O(1)
{
	l.push_back(1);
	ASSERT_THAT(l.size(), Eq(1));
}

TEST_F(List, test_add_element_front) // O(1)
{
	l.push_front(1);
	ASSERT_THAT(l.size(), Eq(1));
}

TEST_F(List, test_see_element_back) // O(1)
{
	l.push_back(1);
	l.push_back(2);

	ASSERT_THAT(l.back(), Eq(2));
}

TEST_F(List, test_see_element_front) // O(1)
{
	l.push_front(1);
	l.push_front(2);

	ASSERT_THAT(l.front(), Eq(2));
}

TEST_F(List, test_remove_element_back) // O(1)
{
	l.push_back(1);
	l.push_back(2);
	l.pop_back();

	ASSERT_THAT(l.back(), Eq(1));
}

TEST_F(List, test_remove_element_front) // O(1)
{
	l.push_front(1);
	l.push_front(2);
	l.pop_front();

	ASSERT_THAT(l.front(), Eq(1));
}

TEST_F(List, test_insert) // How to insert - 0(1) / How to search - O(n)
{
	l.insert(l.end(), 4);
	EXPECT_THAT(std::find(l.begin(), l.end(), 4) != l.end(), Eq(true));
}

TEST_F(List, test_sort) 
{
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.sort(std::greater<>());
	EXPECT_THAT(l, ElementsAre(4, 3, 2, 1));
}

