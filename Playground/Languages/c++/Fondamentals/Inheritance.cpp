#include <gmock\gmock-matchers.h>

using namespace ::testing;

/*
	An abstract class is a class that contains at least one abstract method, i.e. a method without definition (=0).
	An abstract method must be virtual. An abstract class with only abstract methods can be considered as an interface.
*/
class MyAbstractClass {
public:
	virtual int virtual_method() = 0;
};

// While inheriting, we can specify the access modifier of the parent.
class MyParentClass : public MyAbstractClass {
public:
	MyParentClass() : MyParentClass(1) {}
	MyParentClass(int x) : x(x) {}

	virtual int virtual_method() { return 1; }
	int non_virtual_method() { return 1; }
	int get_x() { return x; }

private:
	int x;
};

class MyChildClass : public MyParentClass {
public:
	MyChildClass() : MyParentClass(2) {}

	virtual int virtual_method() { return 2; }
	int non_virtual_method() { return 2; }
	int get_augmented_x() { return MyParentClass::get_x() + 1; } // How to call parent functions
};

TEST(Inheritance, test_abstract_method_overload) {
	MyParentClass parent;
	MyAbstractClass* ptr = &parent;

	ASSERT_THAT(ptr->virtual_method(), Eq(1));
}

TEST(Inheritance, test_virtual_method_overload) {
	MyChildClass child;
	MyParentClass* ptr = &child;

	ASSERT_THAT(ptr->virtual_method(), Eq(2));
	ASSERT_THAT(child.virtual_method(), Eq(2));
}

TEST(Inheritance, test_non_virtual_method_overload) {
	MyChildClass child;
	MyParentClass* ptr = &child;

	ASSERT_THAT(ptr->non_virtual_method(), Eq(1));
	ASSERT_THAT(child.non_virtual_method(), Eq(2));
}

TEST(Inheritance, test_update_parent_attribute) {
	MyChildClass child;
	MyParentClass* ptr = &child;

	ASSERT_THAT(child.get_x(), Eq(2));
	ASSERT_THAT(ptr->get_x(), Eq(2));
}

TEST(Inheritance, test_use_parent_function_result) {
	MyChildClass child;
	MyParentClass* ptr = &child;

	ASSERT_THAT(child.get_augmented_x(), Eq(3));
}
