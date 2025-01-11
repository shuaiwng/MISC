#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut.h"

template<typename T>
class MockDOC : public DOC<T>{
public:
    MOCK_METHOD1_T(foo, string(T param));
};


TEST(SutTest, UseMock)
{
    DOC<int> doc;
    SUT sut(doc);

    MockDOC<int> mock_doc;
    SUT mock_sut(mock_doc);

    EXPECT_CALL(mock_doc, foo(_)).WillOnce(Return("I'm mocked foo"));

    sut.foo();
    mock_sut.foo();
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
