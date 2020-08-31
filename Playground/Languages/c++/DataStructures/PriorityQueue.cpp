
#include <queue>

#include <gtest/gtest.h>
#include <gmock\gmock-matchers.h>

using namespace ::testing;

/*
A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
at the expense of logarithmic insertion and extraction.
*/

class PriorityQueue : public Test {
protected:
	std::priority_queue<std::pair<int, char>> p;
};

TEST_F(PriorityQueue, test_empty) {
	ASSERT_THAT(p.empty(), Eq(true));
}

TEST_F(PriorityQueue, test_size) {
	ASSERT_THAT(p.size(), Eq(0));
}

TEST_F(PriorityQueue, test_add_element) { // O(log(n))
	p.push({ 3, 'A' });

	ASSERT_THAT(p.size(), Eq(1));
}

TEST_F(PriorityQueue, test_remove_element) { // O(log(n))
	p.push({ 3, 'A' });
	p.pop();

	ASSERT_THAT(p.size(), Eq(0));
}

TEST_F(PriorityQueue, test_see_next_element) { // O(1)
	p.push({ 3, 'A' });
	ASSERT_THAT(p.top(), Eq(std::make_pair(3, 'A')));
}

TEST_F(PriorityQueue, test_default_priority) {
	p.push({ 3, 'A' });
	p.push({ 7, 'B' });
	p.push({ 1, 'C' });

	ASSERT_THAT(p.top().second, Eq('B'));
}

TEST(ReversedPriorityQueue, test_priority) {
	std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<>> p;

	p.push({ 3, 'A' });
	p.push({ 7, 'B' });
	p.push({ 1, 'C' });

	ASSERT_THAT(p.top().second, Eq('C'));
}

TEST(LambdaComparatorPriorityQueue, test_priority) {
	auto comp = [](const std::pair<int, char>& p1, const std::pair<int, char>& p2) { return p1.second > p2.second; };
	std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, decltype(comp)> p(comp);

	p.push({ 3, 'A' });
	p.push({ 7, 'B' });
	p.push({ 1, 'C' });

	ASSERT_THAT(p.top().second, Eq('A'));
}

TEST(CustomComparatorPriorityQueue, test_priority) {
	class comparator {
	public:
		bool operator()(const std::pair<int, char>& a, const std::pair<int, char>& b) {
			return a.second < b.second;
		}
	};

	std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, comparator> p;

	p.push({ 3, 'A' });
	p.push({ 7, 'B' });
	p.push({ 1, 'C' });

	ASSERT_THAT(p.top().second, Eq('C'));
}
