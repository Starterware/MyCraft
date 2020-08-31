#include "gmock/gmock.h"

using namespace ::testing;

TEST(ContainerMatchers, testIsEmpty) {
	std::vector<int> v;
	ASSERT_THAT(v, IsEmpty());
}

TEST(ContainerMatchers, testContains) {
	std::vector<int> v{ 1, 3, 5 };
	ASSERT_THAT(v, Contains(5));
}

TEST(ContainerMatchers, testElementsAre) {
	std::vector<int> v{ 1, 3, 5 };
	ASSERT_THAT(v, ElementsAre(1, 3, 5));
}

TEST(ContainerMatchers, testUnorderedElementsAre) {
	std::vector<int> v{ 1, 3, 5 };
	ASSERT_THAT(v, UnorderedElementsAre(3, 5, 1));
}

TEST(ContainerMatchers, testIsSupersetOf) {
	std::vector<int> v{ 1, 3, 5 };
	ASSERT_THAT(v, IsSupersetOf({ 3, 5 }));
}

TEST(ContainerMatchers, testIsSubsetOf) {
	std::vector<int> v{ 1, 3, 5 };
	ASSERT_THAT(v, IsSubsetOf({1, 2, 3, 5 }));
}
