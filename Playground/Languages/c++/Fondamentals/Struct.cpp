#include <gmock\gmock-matchers.h>

using namespace ::testing;

/*
	Struct are like classes except that their attributes and member functions are public by default instead of private.
	Therefore they are mostly use for datastructures containing multiple types of data types.
*/
struct s {
	int x = 5;
};

TEST(Struct, test) {
	ASSERT_THAT(s().x, Eq(5));
}
