#include "gmock/gmock.h"

#include <vector>
#include <algorithm>

using namespace ::testing;

TEST(stl_algo, test_begin) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    ASSERT_THAT(begin(v), Eq(v.begin()));
}

TEST(stl_algo, test_end) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    ASSERT_THAT(end(v), Eq(v.end()));
}

TEST(stl_algo, test_make_heap) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::make_heap(v.begin(), v.end());

    ASSERT_THAT(*v.begin(), Eq(5));
}

TEST(stl_algo, test_push_heap) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::make_heap(v.begin(), v.end());

    v.push_back(6); // first add to end
    std::push_heap(v.begin(), v.end()); // then push heap

    ASSERT_THAT(*v.begin(), Eq(6));
}

TEST(stl_algo, test_pop_heap) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::make_heap(v.begin(), v.end());

    std::pop_heap(v.begin(), v.end()); // first pop_heap 
    v.pop_back(); // then remove element

    ASSERT_THAT(*v.begin(), Eq(4));
}

TEST(stl_algo, test_heap_with_comparator) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::make_heap(v.begin(), v.end(), std::greater<>());
    std::pop_heap(v.begin(), v.end(), std::greater<>());

    ASSERT_THAT(*v.begin(), Eq(2));
}

TEST(stl_algo, test_for_each) {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    int sum = 0;
    auto f = [&sum](const int& a) { sum += a; };
    std::for_each(v.begin(), v.end(), f);

    ASSERT_THAT(sum, Eq(15));
}
	//std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	//EXPECT_THAT(s, ::testing::Eq("HELLO WORLD!")); 

	//std::for_each(s.begin(), s.end(), [](char& c) { c = ::tolower(c); });
	//EXPECT_THAT(s, ::testing::Eq("hello world!")); 

	//std::replace(s.begin(), s.end(), 'l', '*');
	//EXPECT_THAT(s, ::testing::Eq("he**o wor*d!")); 

TEST(stl_algo, test_sort) {
    std::vector<int> v{ 2, 3, 1, 5, 4 };
    std::sort(v.begin(), v.end());
    ASSERT_THAT(v, ElementsAre(1, 2, 3, 4, 5));
}

TEST(stl_algo, test_sort_with_comparator) {
    std::vector<int> v{ 2, 3, 1, 5, 4 };
    std::sort(v.begin(), v.end(), std::greater<>());
    ASSERT_THAT(v, ElementsAre(5, 4, 3, 2, 1));
}

TEST(stl_algo, test_stable_sort) { // Keeps the elements in the encountered other in case of equality
    std::vector<std::pair<int, char>> v{ {2, 'A'}, {1, 'B'}, {2, 'C'}, {4, 'D'}, {2, 'E'} };
    std::sort(v.begin(), v.end());
    ASSERT_THAT(v, ElementsAre(std::make_pair<>(1, 'B'), std::make_pair<>(2, 'A'), std::make_pair<>(2, 'C'), std::make_pair<>(2, 'E'), std::make_pair<>(4, 'D')));
}
