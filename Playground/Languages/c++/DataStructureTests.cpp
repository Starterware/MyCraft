#include "gmock/gmock.h"

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>

#include <functional>
#include <algorithm>

using namespace ::testing;

TEST(data_stucture_tests, arrays)
{
	// How to init 
	int v[4]{ 1, 2, 3 };
	EXPECT_THAT(v, ElementsAre(1, 2, 3, 0));

	// How to access an element
	int elem = v[0];
	EXPECT_THAT(elem, Eq(1));

	// How to check if it is empty
	EXPECT_THAT(v == NULL, Eq(false));

	// How to check the size
	EXPECT_THAT(sizeof(v) / sizeof(v[0]), Eq(4));

	// How to loop
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += v[i];
	EXPECT_THAT(sum, Eq(6));

	// How to iterate
	sum = 0;
	for (const auto& elem : v)
		sum += elem;
	EXPECT_THAT(sum, Eq(6));

	// How to search an element - O(n)
	int *p = std::find(v, v + 4, 2);
	EXPECT_THAT(p != v + 4, Eq(true));
	EXPECT_THAT(*p, Eq(2));
	p = std::find(v, v + 4, 5);
	EXPECT_THAT(p != v + 4, Eq(false));

	// How to sort - O(n log(n))
	std::sort(v, v + 4, std::greater<>());
	EXPECT_THAT(v, ElementsAre(3, 2, 1, 0));
	std::sort(v, v + 4);
	EXPECT_THAT(v, ElementsAre(0, 1, 2, 3));
}

TEST(data_stucture_tests, vectors)
{
	// How to init
	std::vector<int> v{ 1, 2, 3 };
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

	// How to check if it is empty
	EXPECT_THAT(v.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(v.size(), Eq(4));

	// How to loop
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	EXPECT_THAT(sum, Eq(10));

	sum = 0;
	for (const auto& elem : v)
		sum += elem;
	EXPECT_THAT(sum, Eq(10));

	// How to search an element - O(n)
	auto pos = std::find(v.begin(), v.end(), 3);
	EXPECT_THAT(pos != v.end(), Eq(true));
	EXPECT_THAT(*pos, Eq(3));
	EXPECT_THAT(std::find(v.begin(), v.end(), 5) != v.end(), Eq(false));

	// How to sort - O(n log(n))
	std::sort(v.begin(), v.end(), std::greater<>());
	EXPECT_THAT(v, ElementsAre(4, 3, 2, 1));
	std::sort(v.begin(), v.end());
	EXPECT_THAT(v, ElementsAre(1, 2, 3, 4));

	// You can also insert but linear on the number of elements inserted (copy/move construction) 
	// plus the number of elements after position (moving).
}

TEST(data_stucture_tests, linked_lists)
{
	std::list<int> l{ 1, 2, 3 };

	// Access element - access to other elements O(n) due to search
	EXPECT_THAT(l.front(), Eq(1));
	EXPECT_THAT(l.back(), Eq(3));

	// How to add an element - O(1) 
	l.push_back(4);
	l.push_front(0);
	EXPECT_THAT(l.front(), Eq(0));
	EXPECT_THAT(l.back(), Eq(4));

	// How to remove an element - O(1)
	l.pop_back();
	l.pop_front();
	EXPECT_THAT(l.front(), Eq(1));
	EXPECT_THAT(l.back(), Eq(3));

	// How to check if it is empty
	EXPECT_THAT(l.empty(), Eq(false));

	// How to check the size
	EXPECT_THAT(l.size(), Eq(3));

	// How to insert - 0(1) / How to search - O(n)
	l.insert(l.end(), 4);
	EXPECT_THAT(std::find(l.begin(), l.end(), 4) != l.end(), Eq(true));

	// How to loop
	int sum = 0;
	for (const auto& elem : l)
		sum += elem;
	EXPECT_THAT(sum, Eq(10));

	// How to sort
	l.sort(std::greater<>());
	EXPECT_THAT(l, ElementsAre(4, 3, 2, 1));
}

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
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out).
The standard container classes vector, deque and list fulfill these requirements.
*/
TEST(data_stucture_tests, stacks)
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

/*
queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), 
where elements are inserted into one end of the container and extracted from the other.
The standard container classes deque and list fulfill these requirements.
*/
TEST(data_stucture_tests, queues)
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
