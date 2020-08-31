#include <gmock\gmock-matchers.h>

using namespace ::testing;

/*
	Template classes definition should be in the header file with the declaration. 
	This is needed for the instantiation of the templates types at compile time.
	Another solution is to put the definition in a .cpp file and to foward declare the wanted template types:
	=> template class MyTemplate<int>;
	This can be done even better by creating a second .cpp file containing all the declarations and inluding the first .cpp file.
*/

template<typename T>
class MyTemplate {
public:
	T get_x();
	void set_x(T x) { this->x = x; }

private:
	T x;
};

template<typename T>
T MyTemplate<T>::get_x() {
	return this->x;
}

template<>
double MyTemplate<double>::get_x() { // specialisation
	return this->x * 2.0;
}

template<typename T>
class MyTemplateChild : public MyTemplate<T> {
public:
	template<typename X> X fct(X x) { return x; }
	template<int X> int fct() { return X; }
};

TEST(Template, test_class) {
	MyTemplate<int> t;
	t.set_x(5);
	ASSERT_THAT(t.get_x(), Eq(5));
}

TEST(Template, test_class_with_special_behaviour_for_particular_type) {
	MyTemplate<double> t;
	t.set_x(5);
	ASSERT_THAT(t.get_x(), Eq(10));
}

TEST(Template, test_inheritance) {
	MyTemplateChild<int> t;
	t.set_x(5);
	ASSERT_THAT(t.get_x(), Eq(5));
}

TEST(Template, test_method) {
	MyTemplateChild<int> t;
	ASSERT_THAT(t.fct(5), Eq(5));
	ASSERT_THAT(t.fct<double>(5), Eq(5.0));
}

TEST(Template, test_templating_primitive) {
	MyTemplateChild<int> t;
	ASSERT_THAT(t.fct<5>(), Eq(5));
}
