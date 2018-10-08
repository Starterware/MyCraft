#include "gmock/gmock.h"

#include "LevensteinDistanceMatrix.hpp"

using namespace ::testing;

class ALevensteinDistanceMatrix : public ::testing::Test
{
protected:
	LevensteinDistanceMatrix matrix;
};

TEST_F(ALevensteinDistanceMatrix, Returns0WhenWordsAreEqual)
{
	matrix.set_base_word("word");
	matrix.append_string_to_compared_word("word");
	ASSERT_THAT(matrix.get_result(), Eq(0));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsFirstWordSizeWhenSecondWordIsEmpty)
{
	matrix.set_base_word("word");
	ASSERT_THAT(matrix.get_result(), Eq(4));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsSecondWordSizeWhenFirstWordIsEmpty)
{
	matrix.set_base_word("");
	matrix.append_string_to_compared_word("word");
	ASSERT_THAT(matrix.get_result(), Eq(4));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfAdditionalCharsInFirstWord)
{
	matrix.set_base_word("_wo_rd_");
	matrix.append_string_to_compared_word("word");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfAdditionalCharsInSecondWord)
{
	matrix.set_base_word("word");
	matrix.append_string_to_compared_word("_wo_rd_");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfDifferentCharsInSameLengthWords)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bununu");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, CanRetrieveTheSearchedWord)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bununa");
	ASSERT_THAT(matrix.get_compared_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, CanRetrieveThePotentialBestResult)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bunun");
	ASSERT_THAT(matrix.get_potential_best_result(), Eq(2));
}

TEST_F(ALevensteinDistanceMatrix, MultiplePushesOfCharsArePossible)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bun");
	matrix.append_char_to_compared_word('u');
	matrix.append_char_to_compared_word('n');
	matrix.append_char_to_compared_word('a');
	ASSERT_THAT(matrix.get_result(), Eq(2));
	ASSERT_THAT(matrix.get_compared_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, MultiplePushesOfStringsArePossible)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bunu");
	matrix.append_string_to_compared_word("na");
	ASSERT_THAT(matrix.get_result(), Eq(2));
	ASSERT_THAT(matrix.get_compared_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, PopRemovesTheLastCharOfTheComparedWord)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("bununa");
	matrix.pop_last_char_of_compared_word();
	ASSERT_THAT(matrix.get_result(), Eq(3));
	ASSERT_THAT(matrix.get_compared_word(), Eq("bunun"));
}

TEST_F(ALevensteinDistanceMatrix, PopOnEmptyComparedWordDoesNothing)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("");
	matrix.pop_last_char_of_compared_word();
	ASSERT_THAT(matrix.get_result(), Eq(6));
	ASSERT_THAT(matrix.get_compared_word(), Eq(""));
}

TEST_F(ALevensteinDistanceMatrix, CanClearTheComparedWord)
{
	matrix.set_base_word("banana");
	matrix.append_string_to_compared_word("banana");
	matrix.clear_compared_word();
	ASSERT_THAT(matrix.get_result(), Eq(6));
	ASSERT_THAT(matrix.get_compared_word(), Eq(""));
}

TEST_F(ALevensteinDistanceMatrix, TestWellKnownCases)
{
	matrix.set_base_word("kitten"); 
	matrix.append_string_to_compared_word("sitting");
	ASSERT_THAT(matrix.get_result(), Eq(3));
	matrix.clear_compared_word();

	matrix.set_base_word("saturday");
	matrix.append_string_to_compared_word("sunday");
	ASSERT_THAT(matrix.get_result(), Eq(3));
	matrix.clear_compared_word();

	matrix.set_base_word("gumbo");
	matrix.append_string_to_compared_word("gambol");
	ASSERT_THAT(matrix.get_result(), Eq(2));
}
