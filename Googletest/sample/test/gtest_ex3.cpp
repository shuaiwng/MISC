#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;


void foo()
{
	char* ptr = (char*)malloc(1);
	*ptr = 0;
}

void bar()
{
	char* ptr = (char*)calloc(1, sizeof(char));
	*ptr = 0;
}

void baz()
{
	char* ptr = new char();
	*ptr = 0;
}


TEST(LeakTest, MallocCallocNew)
{
	foo();
	bar();
	baz();
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}