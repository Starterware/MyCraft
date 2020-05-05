#include "gmock/gmock.h"

#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>

#include <functional>
#include <algorithm>

using namespace ::testing;

TEST(data_stucture_tests, binary_trees)
{
	// map is often a binary search tree and is always sorted.
	std::map<char, int> table{ { 'a', 1 },{ 'b', 2 },{ 'c', 3 } };

	// Contains value - O(log(n))
	EXPECT_THAT(table.find('d') != table.end(), Eq(false));
	EXPECT_THAT(table.find('b') != table.end(), Eq(true));

	// Access element without creating an entry - O(log(n))
	EXPECT_THAT(table.at('a'), Eq(1));
	ASSERT_THROW(table.at('d'), std::out_of_range);

	// Access element if not found, creates an entry - O(log(n))
	EXPECT_THAT(table['d'], Eq(0));

	// How to check if it is empty
	EXPECT_THAT(table.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(table.size(), Eq(4));

	// Put value - O(log(n))
	table['d'] = 4;
	EXPECT_THAT(table['d'], Eq(4));

	// How to loop
	int sum = 0;
	for (const auto& elem : table)
		sum += elem.second;
	EXPECT_THAT(sum, Eq(10));
}

TEST(data_stucture_tests, hash_tables)
{
	std::unordered_map<char, int> table{ { 'a', 1 },{ 'b', 2 },{ 'c', 3 } };

	// Contains value - O(1)
	EXPECT_THAT(table.find('d') != table.end(), Eq(false));
	EXPECT_THAT(table.find('b') != table.end(), Eq(true));

	// Access element without creating an entry - O(1)
	EXPECT_THAT(table.at('a'), Eq(1));
	ASSERT_THROW(table.at('d'), std::out_of_range);

	// Access element if not found, creates an entry - O(1)
	EXPECT_THAT(table['d'], Eq(0));

	// How to check if it is empty
	EXPECT_THAT(table.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(table.size(), Eq(4));

	// Put value - O(1)
	table['d'] = 4;
	EXPECT_THAT(table['d'], Eq(4));
}

/*
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, 
then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C.
*/
TEST(data_stucture_tests, heaps)
{
	std::map<int, char> m = { { 1, 'a' },{ 2, 'b' },{ 3, 'c' } };

	// How to create a priority_queue O(n) 
	std::priority_queue<std::pair<int, char> > q (m.begin(), m.end());
	EXPECT_THAT(q.top().second, Eq('c'));

	// How to add an element O(log(n)
	q.push(std::make_pair<>(4, 'd'));
	EXPECT_THAT(q.top().second, Eq('d'));

	// How to remove best priority element O(log(n))
	q.pop();
	EXPECT_THAT(q.top().second, Eq('c'));

	// How to check if the heap is empty
	EXPECT_THAT(q.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(q.size(), Eq(3));
}
