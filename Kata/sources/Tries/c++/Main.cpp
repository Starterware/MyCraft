#include <gmock/gmock.h>

#include <iostream>

int main(int argc, char **argv) 
{
  testing::InitGoogleMock(&argc, argv);
  int result = RUN_ALL_TESTS();
 
  system("pause");

  return result;
}