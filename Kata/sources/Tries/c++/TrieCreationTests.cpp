#include "gmock/gmock.h"

#include <vector>
#include "Trie.hpp"

using namespace ::testing;

class TrieTest : public ::testing::Test
{
protected:

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

	Trie trie;
};

TEST_F(TrieTest, DoesNotFindEmptyWhenNotInserted)
{
	ASSERT_THAT(trie.search(""), Eq(false));
}

TEST_F(TrieTest, FindsEmptyWhenInserted)
{
	trie.insert("");
	ASSERT_THAT(trie.search(""), Eq(true));
}

TEST_F(TrieTest, DoesNotFindWordWhenOnlyPrefixIsInserted)
{
	trie.insert("ab");
	ASSERT_THAT(trie.search("abc"), Eq(false));
}

TEST_F(TrieTest, FindsWordWhenInserted)
{
	trie.insert("abc");
	ASSERT_THAT(trie.search("abc"), Eq(true));
}

TEST_F(TrieTest, CanInsertMultipleWordsAtOnce)
{
	std::vector<std::string> words{ "abcdef", "ghijkl", "abc", "abd", "abxyz" };
	trie.insert(words);
	ASSERT_THAT(trie.search("abc"), Eq(true));
}
