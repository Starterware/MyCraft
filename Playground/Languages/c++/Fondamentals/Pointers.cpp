#include "gmock/gmock.h"

#include <memory>

using namespace ::testing;

class Object { 
public:
	int x = 4;
};

TEST(Pointers, test_addresses) {
	int x = 5;
	int* p = &x;
	int** pp = &p;

	ASSERT_THAT(*p, Eq(5));
	ASSERT_THAT(p, Eq(&x));

	p = nullptr;

	ASSERT_THAT(pp, Eq(&p));
	ASSERT_THAT(*pp, Eq(nullptr));
}

TEST(Pointers, test_new_primitive) {
	int* p = new int(4);
	delete p; 

	SUCCEED(); // No crash
}

TEST(Pointers, test_new_object) {
	Object* p = new Object();
	delete p;

	SUCCEED(); // No crash
}

TEST(Pointers, test_new_array) {
	int* p = new int[5];
	delete[] p;

	SUCCEED(); // No crash
}

TEST(Pointers, test_new_matrix) {
	int** p = new int*[5];
	for (int i = 0; i < 5; i++) 
		p[i] = new int[3];

	for (int i = 0; i < 5; i++)
		delete[] p[i];
	delete[] p;

	SUCCEED(); // No crash
}

/*
	Malloc puts the size of the allocation before the start of allocated memory.
	This is needed by free to know how much to free.
	Use calloc to initialize all the memory to 0.
	Use realloc to reallocate the memory and copy the content
*/
TEST(Pointers, test_malloc_object_or_primitive) {
	int* p = (int*)malloc(sizeof(int));
	free(p); 

	SUCCEED(); // No crash
}

TEST(Pointers, test_malloc_array) {
	int* p = (int*)malloc(sizeof(int)*10);
	p[9] = 5;
	free(p); 

	SUCCEED(); // No crash
}

TEST(Pointers, test_malloc_matrix) {
	int** p = (int**)malloc(sizeof(int*)*10);
	for (int i = 0; i < 5; i++) 
		p[i] = (int*)malloc(sizeof(int*)*2);

	for (int i = 0; i < 5; i++)
		free(p[i]);
	free(p); 

	SUCCEED(); // No crash
}

/*
	Using delete or free on a nullptr will result in a no-op
*/
TEST(Pointers, test_delete_nullptr) {
	int* p = nullptr;
	delete p; // No-op

	SUCCEED();
}

TEST(Pointers, test_shared_ptr_creation_1) {
	std::shared_ptr<int> p (new int(5));
	ASSERT_THAT(*p, Eq(5));
}

TEST(Pointers, test_shared_ptr_creation_2) {
	std::shared_ptr<int> p = std::make_shared<int>(5);
	ASSERT_THAT(*p, Eq(5));
}

TEST(Pointers, test_shared_ptr_use_count) {
	std::shared_ptr<int> p = std::make_shared<int>(5);
	std::shared_ptr<int> p2 = p;
	ASSERT_THAT(p.use_count(), Eq(2));
}

TEST(Pointers, test_weak_ptr_use_count) {
	std::shared_ptr<int> p = std::make_shared<int>(5);
	std::weak_ptr<int> p2 = p;
	ASSERT_THAT(p.use_count(), Eq(1));
}

TEST(Pointers, test_weak_ptr_usage) {
	std::shared_ptr<int> p = std::make_shared<int>(5);
	std::weak_ptr<int> weak_ptr = p;
	std::shared_ptr<int> p2 = weak_ptr.lock(); // only use it when weak_ptr use_count > 0

	ASSERT_THAT(*p2, Eq(5));
}

TEST(Pointers, test_unique_ptr) { // copy of unique_ptr does not work
	std::unique_ptr<int> p (new int(5));
	ASSERT_THAT(*p, Eq(5));
}

