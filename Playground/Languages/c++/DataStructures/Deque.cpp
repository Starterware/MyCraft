#include "gmock/gmock.h"

#include <deque>
#include <functional>
#include <xstddef>

using namespace ::testing;

/*
deque (usually pronounced like "deck") is an irregular acronym of double-ended queue.
Double-ended queues are sequence containers with dynamic sizes that can be expanded 
or contracted on both ends (either its front or its back).
*/

class Deque : public Test {
protected:
	std::deque<int> q;
};

TEST_F(Deque, test_empty)
{
	ASSERT_THAT(q.empty(), Eq(true));
}

TEST_F(Deque, test_size)
{
	ASSERT_THAT(q.size(), Eq(0));
}

TEST_F(Deque, test_add_element_back) // O(1)
{
	q.push_back(1);
	ASSERT_THAT(q.size(), Eq(1));
}

TEST_F(Deque, test_add_element_front) // O(1)
{
	q.push_front(2);
	ASSERT_THAT(q.size(), Eq(1));
}

TEST_F(Deque, test_see_element_back) // O(1)
{
	q.push_back(1);
	q.push_back(2);
	q.push_front(3);

	ASSERT_THAT(q.back(), Eq(2));
}

TEST_F(Deque, test_see_element_front) // O(1)
{
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);

	ASSERT_THAT(q.front(), Eq(1));
}

TEST_F(Deque, test_remove_element_back) // O(1)
{
	q.push_back(1);
	q.push_back(2);
	q.pop_back();

	ASSERT_THAT(q.back(), Eq(1));
}

TEST_F(Deque, test_remove_element_front) // O(1)
{
	q.push_front(1);
	q.push_front(2);
	q.pop_front();

	ASSERT_THAT(q.front(), Eq(1));
}

TEST_F(Deque, test_iterator) // Random access iterator
{
	q.push_back(2);
	q.push_back(5);
	
	int sum = 0;
	for (auto it = q.begin(); it != q.end(); it++) {
		sum += *it;
	}

	ASSERT_THAT(sum, Eq(7));
}

