
#include "gmock/gmock.h"

using namespace ::testing;

class MyFixture : public Test {
protected:
	virtual void SetUp() override { // override allows to be sure to validate typos of the setup method
		my_data = new int(5);
	}

	virtual void TearDown() override { // override allows to be sure to validate typos of the setup method
		delete my_data;
	}

	static void SetUpTestSuite() {
		val = 123;
	}

	static void TearDownTestSuite() {
		// test suite tear down
	}

protected:
	int* my_data;
	static int val;
};

int MyFixture::val = 0;

class MyChildFixture : public MyFixture {
public:
	void SetUp() override {
		MyFixture::SetUp(); // Don't forget to call the parent setup 
		*my_data = 6;
	}

	void TearDown() override {
		MyFixture::TearDown(); // Don't forget to call the child setup
	}
};

class MyOtherFixture : public Test {
public:
	MyOtherFixture() { 
		my_data = new int(5);
	}
	~MyOtherFixture() {
		delete my_data;
	}

protected:
	int* my_data;
};

TEST_F(MyFixture, testSetUp) {
	ASSERT_THAT(*my_data, Eq(5));
}

TEST_F(MyFixture, testSetUpTestSuite) {
	ASSERT_THAT(val, Eq(123));
}

TEST_F(MyChildFixture, testSetUp) {
	ASSERT_THAT(*my_data, Eq(6));
}

TEST_F(MyChildFixture, testSetUpTestSuite) {
	ASSERT_THAT(val, Eq(123));
}

TEST_F(MyOtherFixture, testSetUpFromConstructor) {
	ASSERT_THAT(*my_data, Eq(5));
}

