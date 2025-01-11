#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "doc.h"
#include "sut.h"

using namespace std;
using namespace ::testing;

const char *actualValTrue  = "hello gtest";
const char *actualValFalse = "hello gtest";

class MockDOC: public DOC {
public:
    MOCK_METHOD0(foo, std::string());
};

TEST(SutTest, UseMock){
    MockDOC mock_doc;
    SUT sut(mock_doc);

    EXPECT_CALL(mock_doc, foo())
    .WillRepeatedly(Return("Hello, Googletest!"));

    bool res = sut.foo(true, true);

	EXPECT_STREQ(actualValFalse, actualValTrue) << "Hello, gtest_ex1" << endl;;
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
