#include "gmock/gmock.h"

#include <vector>
#include <functional>
#include <algorithm>

using namespace ::testing;

TEST(array_tests, arrays)
{
	// How to init 
	int v[4]{ 1, 2, 3 }; // uniform initialization
	// int v[] = { 1, 2, 3, 0 };
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
	int* p = std::find(v, v + 4, 2);
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

/*
	The initial capacity depends on the implementation (often starts at 0). Same for reallocation. 
*/
TEST(array_tests, vectors)
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
