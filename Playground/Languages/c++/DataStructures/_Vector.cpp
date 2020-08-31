#include "gmock/gmock.h"

#include <vector>

using namespace ::testing;

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
