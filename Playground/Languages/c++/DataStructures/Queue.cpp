#include "gmock/gmock.h"

#include <queue>
#include <functional>
#include <xstddef>

using namespace ::testing;

/*
queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out),
where elements are inserted into one end of the container and extracted from the other.
The standard container classes deque and list fulfill these requirements.
*/

class Queue : public Test {
protected:
	std::queue<std::pair<int, char>> q;
};

TEST_F(Queue, test_empty)
{
	ASSERT_THAT(q.empty(), Eq(true));
}

TEST_F(Queue, test_size)
{
	ASSERT_THAT(q.size(), Eq(0));
}

TEST_F(Queue, test_add_element) // O(1)
{
	q.push({ 1, 'A' });
	ASSERT_THAT(q.size(), Eq(1));
}

TEST_F(Queue, test_see_first_element) // O(1)
{
	q.push({ 1, 'A' });
	q.push({ 2, 'B' });
	ASSERT_THAT(q.front(), Eq(std::make_pair(1, 'A')));
}

TEST_F(Queue, test_see_last_element) // O(1)
{
	q.push({ 1, 'A' });
	q.push({ 2, 'B' });
	ASSERT_THAT(q.back(), Eq(std::make_pair(2, 'B')));
}

TEST_F(Queue, test_remove_element) // O(1)
{
	q.push({ 1, 'A' });
	q.push({ 2, 'B' });
	q.pop();
	ASSERT_THAT(q.front(), Eq(std::make_pair(2, 'B')));
}

TEST(QueueBasedOnDifferentContainer, test_creation)
{
	std::queue<int, std::vector<int>> s;
	s.push(3);
	ASSERT_THAT(s.front(), Eq(3));
}

TEST(QueueInitFromContainer, test_creation)
{
	std::queue<int> s(std::deque<int> {1, 2, 3});
	ASSERT_THAT(s.front(), Eq(1));
}

