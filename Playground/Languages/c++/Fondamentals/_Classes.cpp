#include <gmock\gmock-matchers.h>

using namespace ::testing;

// === Header (.hpp) === //

#ifndef NAMESPACE_CLASS_HPP
#define NAMESPACE_CLASS_HPP

class MyClass {
public:
	MyClass(); // default constructor
	MyClass(int x); // constructor
	~MyClass(); // destructor
	MyClass(const MyClass& other); // copy constructor
	MyClass& operator=(const MyClass& other); // assignment operator

	int get_x() const;
	int get_y() const;

	
	void set_x(int x);
	void set_y(int y);

private:
	void copy(const MyClass& other);

private:
	int x, y;
};


/*
There is no benefit to move data on types like ints.
Be careful with moves when there are pointers/resources. 
After the pointers have been copied, the other object must reset the pointer to nullptr.
This avoids the pointed data to be deleted.
Something like std::exchange(pointer, nullptr) can also be used instead of move.
There are no problems with types like shared_ptr.
*/
class MyClassWithMove {
public:
	MyClassWithMove() : moved(false), data(1) { }
	MyClassWithMove(const MyClassWithMove& other) : data(other.data) { moved = false; }
	MyClassWithMove(MyClassWithMove&& other) noexcept : data(std::move(other.data)) { moved = true; }
	MyClassWithMove& operator=(const MyClassWithMove& other) { 
		moved = false; 
		return *this; 
	}
	MyClassWithMove& operator=(const MyClassWithMove&& other) noexcept {
		data = std::move(other.data);
		moved = true; 
		return *this;
	}

	bool is_moved() { return moved; }
	void update_data(int x) { this->data = x; }

private:
	bool moved;
	int data;
};

/*
Rule of five:

If a copy constructor or assignment is defined for move or copy implement them all:
	• Destructor
	• Move constructor and assignment (not generated if there is a destructor or copy constructor)
	• Copy constructor and assignment (not generated if there is a move constructor)

Default keyword, uses default implementation. Do not use when the some of the attributes require special handling.
It is also possible to use = delete to remove a method.
*/
class MyClassWithDefault {
public:
	MyClassWithDefault() = default;
	MyClassWithDefault(const MyClassWithDefault& other) = default;
	MyClassWithDefault(MyClassWithDefault&& other) = default;
	MyClassWithDefault& operator=(const MyClassWithDefault& other) = default;
	MyClassWithDefault& operator=(MyClassWithDefault&& other) = default;

	void set_x(int x) { this->x = x; }
	int get_x() { return this->x; }

private:
	int x;
};

#endif

// === Source (.cpp) === //

MyClass::MyClass(): x(0) {
	y = 0;
}

MyClass::MyClass(int x) : x(x), y(0) {

}

MyClass::~MyClass() {
	// clean owned pointers and ressources
}

// Be careful with deep copy issues
MyClass::MyClass(const MyClass& other) {
	copy(other);
}

// Be careful with deep copy issues / pointers and ressources
MyClass& MyClass::operator=(const MyClass& other) {
	if (this != &other)
		copy(other);
	return *this;
}

void MyClass::copy(const MyClass& other) {
	this->x = other.x;
	this->y = other.y;
}

int MyClass::get_x() const {
	return this->x;
}

int MyClass::get_y() const {
	return this->x;
}

void MyClass::set_x(int x) {
	this->x = x;
}

void MyClass::set_y(int y) {
	this->y = y;
}

// === Tests === //

TEST(Classes, test_default_constructor) {
	MyClass c;
	ASSERT_THAT(c.get_x(), Eq(0));
}

TEST(Classes, test_constructor) {
	MyClass c(123);
	ASSERT_THAT(c.get_x(), Eq(123));
}

TEST(Classes, test_copy_constructor) {
	MyClass first(34);
	MyClass second(first);

	ASSERT_THAT(second.get_x(), Eq(34));
	ASSERT_THAT(&second, Ne(&first));
}

TEST(Classes, test_assignment_operator) {
	MyClass first(34);
	MyClass second = first;

	ASSERT_THAT(second.get_x(), Eq(34));
	ASSERT_THAT(&second, Ne(&first));
}

TEST(Classes, test_move_constructor_not_used) {
	MyClassWithMove to_copy;
	MyClassWithMove c(to_copy);
	ASSERT_THAT(c.is_moved(), Eq(false));
}

TEST(Classes, test_move_constructor) {
	std::vector<MyClassWithMove> v;
	v.push_back(MyClassWithMove());
	ASSERT_THAT(v[0].is_moved(), Eq(true));
}

TEST(Classes, test_move_assignement_operator_not_used) {
	MyClassWithMove to_copy;
	MyClassWithMove c = to_copy;
	ASSERT_THAT(c.is_moved(), Eq(false));
}

TEST(Classes, test_move_assignment_operator) {
	std::vector<MyClassWithMove> v(1);
	v[0] = MyClassWithMove();
	ASSERT_THAT(v[0].is_moved(), Eq(true));
}

TEST(Classes, test_default_method) {
	MyClassWithDefault c;
	c.set_x(5);
	MyClassWithDefault c2(c);
	ASSERT_THAT(c2.get_x(), Eq(5));
}
