#include "gmock/gmock.h"

#include <array>
#include <vector>
#include <functional>
#include <algorithm>

using namespace ::testing;

TEST(Array, test_empty)
{
	std::array<int, 0> a;
	ASSERT_THAT(a.empty(), Eq(true)); // always returns true
}

TEST(Array, test_size)
{
	std::array<int, 10> a;
	ASSERT_THAT(a.size(), Eq(10));
}

TEST(Array, test_init)
{
	std::array<int, 4> a{ 10, 4 };
	ASSERT_THAT(a, ElementsAre(10, 4, 0, 0));
}

TEST(Array, test_init_with_fill) {
	std::array<int, 4> a;
	a.fill(1);
	EXPECT_THAT(a, ElementsAre(1, 1, 1, 1));
}

TEST(Array, test_get_element)
{
	std::array<int, 4> a{ 10, 4, 1, 4 };
	ASSERT_THAT(a.at(2), Eq(1));
	ASSERT_THAT(a[2], Eq(1));
}

TEST(Array, test_update_element)
{
	std::array<int, 4> a{ 10, 4, 1, 4 };
	ASSERT_THAT(a.at(2), Eq(1));
}

TEST(Array, test_loop)
{
	std::array<int, 4> a{ 10, 4, 1, 4 };

	int sum = 0;
	for (const auto& elem : a) 
		sum += elem;

	ASSERT_THAT(sum, Eq(19));
}

TEST(Array, test_loop_2)
{
	std::array<int, 4> a{ 10, 4, 1, 4 };

	int sum = 0;
	for (int i = 0; i < a.size(); i++) 
		sum += a[i];

	ASSERT_THAT(sum, Eq(19));
}

TEST(Array, test_iterate) // random access iterator
{
	std::array<int, 4> a{ 10, 4, 1, 4 };

	int sum = 0;
	for (auto it = a.begin(); it != a.end(); it++)
		sum += *it;

	ASSERT_THAT(sum, Eq(19));
}

TEST(Array, test_compare_same_size_array) // random access iterator
{
	std::array<int, 4> a{ 1, 2, 3, 4 };
	std::array<int, 4> a2{ 1, 2, 4, 4 };

	ASSERT_THAT(a == a2, IsFalse());
	ASSERT_THAT(a < a2, IsTrue()); // if first encountered element is smaller
}


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
	std::sort(v, v + 4, [](const int& a, const int& b) { return a > b; });
	EXPECT_THAT(v, ElementsAre(3, 2, 1, 0));
	std::sort(v, v + 4);
	EXPECT_THAT(v, ElementsAre(0, 1, 2, 3));
}
