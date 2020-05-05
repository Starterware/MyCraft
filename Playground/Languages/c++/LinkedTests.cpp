#include "gmock/gmock.h"

#include <list>

using namespace ::testing;

TEST(linked_list_tests, list)
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
