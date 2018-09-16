//#include "gmock/gmock.h"
//
//#include "Set.hpp"
//
//using namespace ::testing;
//
//class AnEmptySet : public ::testing::Test
//{
//protected:
//	Set s;
//	std::set<std::string> results;
//	double score;
//};
//
//class ASetContainingEmpty : public AnEmptySet
//{
//	virtual void SetUp() {
//		s.insert("");
//	}
//};
//
//class ASetContainingAWord : public AnEmptySet
//{
//	virtual void SetUp() {
//		a_word = "word";
//		s.insert(a_word);
//	}
//
//	std::string a_word;
//};
//
//class ASetContainingWords : public AnEmptySet
//{
//	virtual void SetUp() {
//		words.insert("word");
//		words.insert("abcd");
//		words.insert("long_word");
//		s.insert(words);
//	}
//
//public:
//	std::set<std::string> smallest_words()
//	{
//		uint64_t smallest_size = UINT64_MAX;
//		std::set<std::string> smallest;
//		
//		for (auto& word : words)
//		{
//			if (word.length() < smallest_size) {
//				smallest.clear();
//				smallest_size = word.length();
//			}
//
//			if (word.length() == smallest_size)
//				smallest.insert(word);
//		}
//
//		return smallest;
//	}
//
//	std::set<std::string> words;
//};
//
//TEST_F(AnEmptySet, NoBestMatchOnSearch)
//{
//	s.search_best_matches("word", results, score);
//
//	ASSERT_THAT(results, IsEmpty());
//	ASSERT_THAT(score, Lt(0));
//}
//
//TEST_F(ASetContainingWords, ReturnsTheSmallestWordsOnEmptySearch)
//{
//	auto set_of_smallest_words = smallest_words();
//	s.search_best_matches("", results, score);
//
//	ASSERT_THAT(results, ContainerEq(set_of_smallest_words));
//	ASSERT_THAT(score, Eq(set_of_smallest_words.begin()->size()));
//}
//
//TEST_F(ASetContainingEmpty, ReturnsEmptyOnSearch)
//{
//	std::string word_to_search = "word";
//
//	s.search_best_matches(word_to_search, results, score);
//
//	ASSERT_THAT(results, UnorderedElementsAre(""));
//	ASSERT_THAT(score, Eq(word_to_search.size()));
//}
//
//TEST_F(AnEmptySet, ReturnsScoreEqualToTheNumberOfAdditionalChars)
//{
//	std::string word_to_search = "word";
//
//	s.search_best_matches(word_to_search, results, score);
//
//	ASSERT_THAT(results, UnorderedElementsAre(""));
//	ASSERT_THAT(score, Eq(word_to_search.size()));
//}
