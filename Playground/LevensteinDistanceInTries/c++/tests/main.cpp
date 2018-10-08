#include <gmock/gmock.h>

int main(int argc, char **argv) 
{
	int result = 0;
	testing::InitGoogleMock(&argc, argv);
	result = RUN_ALL_TESTS();
	system("pause");
	return result;
}
