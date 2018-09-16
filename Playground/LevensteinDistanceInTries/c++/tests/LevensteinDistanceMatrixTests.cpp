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
	matrix.push("word");
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
	matrix.push("word");
	ASSERT_THAT(matrix.get_result(), Eq(4));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfAdditionalCharsInFirstWord)
{
	matrix.set_base_word("_wo_rd_");
	matrix.push("word");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfAdditionalCharsInSecondWord)
{
	matrix.set_base_word("word");
	matrix.push("_wo_rd_");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, ReturnsTheNumberOfDifferentCharsInSameLengthWords)
{
	matrix.set_base_word("banana");
	matrix.push("bununu");
	ASSERT_THAT(matrix.get_result(), Eq(3));
}

TEST_F(ALevensteinDistanceMatrix, CanRetrieveTheSearchedWord)
{
	matrix.set_base_word("banana");
	matrix.push("bununa");
	ASSERT_THAT(matrix.get_searched_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, CanConcatanateACharToComparedWorWithPush)
{
	matrix.set_base_word("banana");
	matrix.push("bunun");
	matrix.push('a');
	ASSERT_THAT(matrix.get_result(), Eq(2));
	ASSERT_THAT(matrix.get_searched_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, CanConcatanateAStringToComparedWordWithPush)
{
	matrix.set_base_word("banana");
	matrix.push("bunu");
	matrix.push("na");
	ASSERT_THAT(matrix.get_result(), Eq(2));
	ASSERT_THAT(matrix.get_searched_word(), Eq("bununa"));
}

TEST_F(ALevensteinDistanceMatrix, CanPopTheLastCharOfTheComparedWord)
{
	matrix.set_base_word("banana");
	matrix.push("bununa");
	matrix.pop();
	ASSERT_THAT(matrix.get_result(), Eq(3));
	ASSERT_THAT(matrix.get_searched_word(), Eq("bunun"));
}

TEST_F(ALevensteinDistanceMatrix, PopOnEmptyComparedWordDoesNothing)
{
	matrix.set_base_word("banana");
	matrix.push("");
	matrix.pop();
	ASSERT_THAT(matrix.get_result(), Eq(6));
	ASSERT_THAT(matrix.get_searched_word(), Eq(""));
}

TEST_F(ALevensteinDistanceMatrix, CanClearTheComparedWord)
{
	matrix.set_base_word("banana");
	matrix.push("banana");
	matrix.clear();
	ASSERT_THAT(matrix.get_result(), Eq(6));
	ASSERT_THAT(matrix.get_searched_word(), Eq(""));
}

TEST_F(ALevensteinDistanceMatrix, TestWellKnownCases)
{
	matrix.set_base_word("kitten"); 
	matrix.push("sitting");
	ASSERT_THAT(matrix.get_result(), Eq(3));
	matrix.clear();

	matrix.set_base_word("saturday");
	matrix.push("sunday");
	ASSERT_THAT(matrix.get_result(), Eq(3));
	matrix.clear();

	matrix.set_base_word("gumbo");
	matrix.push("gambol");
	ASSERT_THAT(matrix.get_result(), Eq(2));
}
