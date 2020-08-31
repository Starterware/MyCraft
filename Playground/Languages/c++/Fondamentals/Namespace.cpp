#include <gmock\gmock-matchers.h>

using namespace ::testing;

namespace first {
	std::string fct(const std::string& s) { 
		return "first"; 
	}
}

namespace second {
	std::string fct(const char* s) {
		return "second";
	}
}

TEST(Namespace, test_prefix) {
	ASSERT_THAT(first::fct("test"), Eq("first"));
}

// namespace can be used in blocks of code or for the complete file
TEST(Namespace, test_using_namespace) {
	using namespace first;
	ASSERT_THAT(fct("test"), Eq("first"));
}

TEST(Namespace, test_using_namespace_issue) {
	using namespace first;
	using namespace second;
	// was hoping for the first namespace but due to implicit conversion requirement by the first namespace 
	// for this reason is better to avoid using "using namespace" of outside libraries
	ASSERT_THAT(fct("test"), Eq("second")); 
}

