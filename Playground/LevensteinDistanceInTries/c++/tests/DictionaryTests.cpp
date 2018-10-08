#include "Trie.hpp"
#include "Set.hpp"
#include "RecursiveTrie.hpp"
#include "StringMetricCalculatorStub.hpp"

#include <vector>
#include <gmock/gmock.h>

using namespace ::testing;

template <typename T>
class DictionaryTest : public ::testing::Test
{
public:
	T dictionary;
};


using MyTypes = ::testing::Types<Trie, Set, RecursiveTrie>;
TYPED_TEST_CASE(DictionaryTest, MyTypes);

TYPED_TEST(DictionaryTest, DoesNotFindEmptyWhenNotInserted)
{
	ASSERT_THAT(dictionary.search(""), Eq(false));
}

TYPED_TEST(DictionaryTest, FindsEmptyWhenInserted)
{
	dictionary.insert("");
	ASSERT_THAT(dictionary.search(""), Eq(true));
}

TYPED_TEST(DictionaryTest, DoesNotFindWordWhenOnlyPrefixIsInserted)
{
	dictionary.insert("ab");
	ASSERT_THAT(dictionary.search("abc"), Eq(false));
}

TYPED_TEST(DictionaryTest, DoesNotFindPrefixWhenWordIsInserted)
{
	dictionary.insert("ab");
	ASSERT_THAT(dictionary.search("abc"), Eq(false));
}

TYPED_TEST(DictionaryTest, DoesNotFindWordWhenNotInserted)
{
	dictionary.insert("abc");
	ASSERT_THAT(dictionary.search("hello"), Eq(false));
}

TYPED_TEST(DictionaryTest, FindsWordWhenInserted)
{
	dictionary.insert("abc");
	ASSERT_THAT(dictionary.search("abc"), Eq(true));
}

TYPED_TEST(DictionaryTest, FindsPrefixWhenPrefixIsInsertedAfterWord)
{
	dictionary.insert("abc");
	dictionary.insert("ab");
	ASSERT_THAT(dictionary.search("ab"), Eq(true));
}

TYPED_TEST(DictionaryTest, CanInsertMultipleWordsAtOnce)
{
	std::vector<std::string> words{ "abcdef", "ghijkl", "abc", "abd", "abxyz" };
	dictionary.insert(words);
	ASSERT_THAT(dictionary.search("abc"), Eq(true));
}

TYPED_TEST(DictionaryTest, CanFindPrefixAsBestMatch)
{
	std::set<std::string> expected_matches{ "abc"};
	std::shared_ptr<StringMetricCalculator> calculator_stub(new StringMetricCalculatorStub(expected_matches, 2));

	for (auto& match : expected_matches)
		dictionary.insert(match);
	dictionary.insert("abcde");

	std::set<std::string> obtained_matches;
	int obtained_score = dictionary.search_best_matches(*calculator_stub, obtained_matches);

	ASSERT_THAT(obtained_matches, ContainerEq(expected_matches));
}

TYPED_TEST(DictionaryTest, CanFindAWordAsBestMatchWhenThePrefixIsAlsoInserted)
{
	std::set<std::string> expected_matches{ "abcde" };
	std::shared_ptr<StringMetricCalculator> calculator_stub(new StringMetricCalculatorStub(expected_matches, 2));

	for (auto& match : expected_matches)
		dictionary.insert(match);
	dictionary.insert("abc");

	std::set<std::string> obtained_matches;
	int obtained_score = dictionary.search_best_matches(*calculator_stub, obtained_matches);

	ASSERT_THAT(obtained_matches, ContainerEq(expected_matches));
}

TYPED_TEST(DictionaryTest, FindsAllTheBestMatchesWithTheSameScore)
{
	int expected_score = 2;
	std::set<std::string> expected_matches{ "abcde", "xyzab" };
	std::shared_ptr<StringMetricCalculator> calculator_stub(new StringMetricCalculatorStub(expected_matches, expected_score));

	for(auto& match : expected_matches)
		dictionary.insert(match);
	dictionary.insert("hello");
	dictionary.insert("world");

	std::set<std::string> obtained_matches;
	int obtained_score = dictionary.search_best_matches(*calculator_stub, obtained_matches);

	ASSERT_THAT(obtained_score, Eq(expected_score));
	ASSERT_THAT(obtained_matches, ContainerEq(expected_matches));
}
