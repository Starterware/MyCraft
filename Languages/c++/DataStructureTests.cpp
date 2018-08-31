#include "gmock/gmock.h"

#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>

#include <functional>
#include <algorithm>

using namespace ::testing;

TEST(DataStructureTests, arrays)
{
	// How to init 
	int v[4]{ 1, 2, 3};
	EXPECT_THAT(v, ElementsAre(1, 2, 3, 0));

	// How to access an element
	int elem = v[0];
	EXPECT_THAT(elem, Eq(1));

	// How to loop
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += v[i];
	EXPECT_THAT(sum, Eq(6));

	// How to search an element - O(n)
	int *p = std::find(v, v + 4, 2);
	EXPECT_THAT(p != v + 4, Eq(true));
	EXPECT_THAT(*p, Eq(2));
	p = std::find(v, v + 4, 5);
	EXPECT_THAT(p != v + 4, Eq(false));

	// How to sort - O(n log(n))
	std::sort(v, v+4, std::greater<>());
	EXPECT_THAT(v, ElementsAre(3, 2, 1, 0));
	std::sort(v, v+4);
	EXPECT_THAT(v, ElementsAre(0, 1, 2, 3));
}

TEST(DataStructureTests, vectors)
{
	// How to init
	std::vector<int> v {1, 2, 3};
	EXPECT_THAT(v, ElementsAre(1, 2, 3));

	// How to access an element
	int elem = v.at(0);
	EXPECT_THAT(elem, Eq(1));

	// How to append an element
	v.push_back(4); 
	EXPECT_THAT(v.size(), Eq(4));

	// How to access last element
	elem = v.back(); 
	EXPECT_THAT(elem, Eq(4));

	// How to loop
	int sum = 0;
	for (auto it = v.begin(); it != v.end(); it++) 
		sum += *it;
	EXPECT_THAT(sum, Eq(10));

	// How to search an element - O(n)
	auto pos = std::find(v.begin(), v.end(), 3);
	EXPECT_THAT(pos != v.end(), Eq(true));
	EXPECT_THAT(*pos, Eq(3));
	pos = std::find(v.begin(), v.end(), 5);
	EXPECT_THAT(pos != v.end(), Eq(false));

	// How to sort - O(n log(n))
	std::sort(v.begin(), v.end(), std::greater<>());
	EXPECT_THAT(v, ElementsAre(4, 3, 2, 1));
	std::sort(v.begin(), v.end());
	EXPECT_THAT(v, ElementsAre(1, 2, 3, 4));

	// You can also insert but linear on the number of elements inserted (copy/move construction) 
	// plus the number of elements after position (moving).
}

/*
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out).
The standard container classes vector, deque and list fulfill these requirements.
*/
TEST(DataStructureTests, Stacks)
{
	std::stack<int> s (std::deque<int> {1, 2, 3});

	// How to get top element - O(1)
	int elem = s.top();
	EXPECT_THAT(elem, Eq(3));

	// How to add an element - O(1) amortized time, reallocation may happen
	s.push(4);
	EXPECT_THAT(s.top(), Eq(4));

	// How to check if the stack is empty
	bool is_empty = s.empty();
	EXPECT_THAT(is_empty, Eq(false));

	// How to remove an element - O(1)
	s.pop();
	EXPECT_THAT(s.top(), Eq(3));
}

TEST(DataStructureTests, queues)
{
	//std::deque<int> q { 1, 2, 3 };
	//q.front();
	//q.back();
	//q.pop_back();
	//q.pop_front();
	//q.push_back(4);
	//q.push_front(5);
}

TEST(DataStructureTests, hash_tables)
{
	std::unordered_map<char, int> table { { 'a', 1 },{ 'b', 2 },{ 'c', 3 } };

}

TEST(DataStructureTests, linked_lists)
{
}

TEST(DataStructureTests, binary_trees)
{
	// map is often a binary search tree
	std::map<char, int> table { { 'a', 1 }, { 'b', 2 }, { 'c', 3 } };
	
	// Contains value - O(log(n))
	EXPECT_THAT(table.find('d') != table.end(), Eq(false));

	// Access element without creating an entry - O(log(n))
	EXPECT_THAT(table.at('a'), Eq(1)); 
	// TODO throws exception

	// Access element if not found, creates an entry - O(log(n))
	EXPECT_THAT(table['d'], Eq(0));
	
	// Put value - O(log(n))
	table['d'] = 4;
	EXPECT_THAT(table['d'], Eq(4));

	// TODO Loop
}

TEST(DataStructureTests, tries)
{

}
