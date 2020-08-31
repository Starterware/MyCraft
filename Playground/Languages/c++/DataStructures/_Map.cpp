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
