#include <iostream>

#include "gmock/gmock.h"

using namespace ::testing;

class MyClassToMock {
public:
	virtual ~MyClassToMock() {} // Must have a virtual destructor

	virtual	int method() const { return -1; } // Mockable methods must be virtual

	virtual std::string methodWithArgs(const std::string& s, int n) {
		std::stringstream ss;
		ss << s << "_" << n;
		return ss.str();
	}

	virtual void methodWithRange(std::vector<int>& v) = 0;

	virtual int methodWithInts(int a, int b, int c) {
		return a + b + c;
	}

private:
	virtual int privateMethod() { return 1; }
};

class MockMyClass : public MyClassToMock { // Also possible to mock templates
public: // Methods to mock must be public (can do it with private and protected methods)
	MOCK_METHOD(int, method, (), (const, override));
	MOCK_METHOD(std::string, methodWithArgs, (const std::string&, int), (override));
	MOCK_METHOD(void, methodWithRange, (std::vector<int>& v), (override));
	MOCK_METHOD(int, methodWithInts, (int, int, int), (override));
	MOCK_METHOD(int, privateMethod, (), (override));
};

class MockWithRealCall : public MyClassToMock {
public:
	MockWithRealCall() {
		ON_CALL(*this, methodWithArgs).WillByDefault([this](const std::string& s, int n) {
			return MyClassToMock::methodWithArgs(s, n);
		});
	}

	MOCK_METHOD(void, methodWithRange, (std::vector<int>& v), (override));
	MOCK_METHOD(std::string, methodWithArgs, (const std::string&, int), (override));
};


TEST(Mocks, testMockTypes) {
	// NiceMock: ignores calls that where not expected
	// NaggyMock: gives warnings (the default)
	// StrictMock: will throw an error on an unexpected call
	NiceMock<MockMyClass> mock; 
	EXPECT_CALL(mock, method());
	mock.method();
}

TEST(Mocks, testOnCall) {
	NiceMock<MockMyClass> mock; // ON_CALL will always cause a warning in gmock
	ON_CALL(mock, method())
		.WillByDefault(Return(123));
	ASSERT_THAT(mock.method(), Eq(123));
}

TEST(Mocks, testOnCallMethodWithArgs) {
	NiceMock<MockMyClass> mock;
	ON_CALL(mock, methodWithArgs("test", 2))
		.WillByDefault(Return("mock_test_2"));
	ASSERT_THAT(mock.methodWithArgs("test", 2), Eq("mock_test_2"));
}

TEST(Mocks, testOnCallMethodWithAnyArgs) {
	NiceMock<MockMyClass> mock;
	ON_CALL(mock, methodWithArgs(_, _))
		.WillByDefault(Return("mock_test_2"));
	ASSERT_THAT(mock.methodWithArgs("test", 2), Eq("mock_test_2"));
}

TEST(Mocks, testOnCallWithMatchersOnMethodWithArgs) {
	NiceMock<MockMyClass> mock;
	ON_CALL(mock, methodWithArgs(Eq("test"), Gt(2)))
		.WillByDefault(Return("mock_test_2"));
	ASSERT_THAT(mock.methodWithArgs("test", 5), Eq("mock_test_2"));
}

TEST(Mocks, testOnCallPrivateMethod) {
	NiceMock<MockMyClass> mock;
	ON_CALL(mock, privateMethod())
		.WillByDefault(Return(321));
	ASSERT_THAT(mock.privateMethod(), Eq(321));
}

TEST(Mocks, testExpectCall) {
	MockMyClass mock;
	EXPECT_CALL(mock, method())
		.Times(2);
	mock.method();
	mock.method();
}

TEST(Mocks, testExpectCallWithArguments) {
	MockMyClass mock;
	EXPECT_CALL(mock, methodWithArgs(Eq(""), Gt(1)))
		.Times(1);
	mock.methodWithArgs("", 3);
}

TEST(Mocks, testExpectCallWillOnce) {
	MockMyClass mock;
	// WillOnce uses lambdas - Return is a predefined action
	EXPECT_CALL(mock, method())
		.WillOnce(Return(1))
		.WillOnce(Return(2));
	ASSERT_THAT(mock.method(), Eq(1));
	ASSERT_THAT(mock.method(), Eq(2));
}

TEST(Mocks, testExpectCallWillRepeatedly) {
	MockMyClass mock;
	// WillRepeatedly uses lambdas - Return is a predefined action
	EXPECT_CALL(mock, method())
		.WillOnce(Return(1))
		.WillRepeatedly(Return(2));
	ASSERT_THAT(mock.method(), Eq(1));
	ASSERT_THAT(mock.method(), Eq(2));
	ASSERT_THAT(mock.method(), Eq(2));
}

TEST(Mocks, testDelegateCallToRealObject) { 
	// Implementation done in the mock class - it can also be used for fakes
	MockWithRealCall mock;
	ASSERT_THAT(mock.methodWithArgs("real_call", 2), Eq("real_call_2"));
}

TEST(Mocks, testMultiArgumentMatcher) {
	MockMyClass mock;
	EXPECT_CALL(mock, methodWithInts)
		.With(AllOf(Args<0, 1>(Lt()), Args<1, 2>(Lt())));
	mock.methodWithInts(1, 2, 3);
}

