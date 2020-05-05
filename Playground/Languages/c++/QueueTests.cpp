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
TEST(queue_tests, queues)
{
	std::queue<int> q(std::deque<int> { 1, 2, 3 });

	// How to get front element - O(1)
	EXPECT_THAT(q.front(), Eq(1));

	// How to get back element - O(1)
	EXPECT_THAT(q.back(), Eq(3));

	// How to add an element - O(1)
	q.push(4);
	EXPECT_THAT(q.back(), Eq(4));

	// How to check if the queue is empty
	EXPECT_THAT(q.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(q.size(), Eq(4));

	// How to remove an element - O(1)
	q.pop();
	EXPECT_THAT(q.front(), Eq(2));
}

/*
A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
at the expense of logarithmic insertion and extraction.
*/
TEST(queue_tests, priority_queues)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	q.push(4);
	q.push(3);
	q.push(5);

	// queue elements depends on their priority
	EXPECT_THAT(q.top(), Eq(5));
	q.pop();
	EXPECT_THAT(q.top(), Eq(4));
	q.pop();
	EXPECT_THAT(q.top(), Eq(3));
}

