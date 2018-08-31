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

TEST_F(TrieTest, DoesNotFinds1LetterWordInTrieContainingEmpty)
{
	trie.insert("");
	ASSERT_THAT(trie.search("a"), Eq(false));
}

