#include "gmock/gmock.h"

using namespace ::testing;

TEST(SimpleTest, testAssertThat) {
	ASSERT_THAT(1, Eq(1));
	ASSERT_THAT(2, Eq(2)); // Does not run if the first assert fails
}

TEST(SimpleTest, testExpectThat) {
	EXPECT_THAT(1, Eq(1)); // EXPECT_THAT is not blocking on failure
	EXPECT_THAT(2, Eq(2)); // This line is ran even if the previous one failed
}
