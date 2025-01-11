#include <iostream>
#include <stack>
#include "gtest/gtest.h"


using namespace std;
using namespace ::testing;


class StackTestP : public TestWithParam<int*> {
protected:
    stack<int> s;
    void SetUp() override {
        int* params = GetParam();
        s.push(params[0]);
        s.push(params[1]);
        s.push(params[2]);
        cout << "params: "<<params[0] <<", "<< params[1] << ", " << params[2];
    }
    void TearDown() override {}
};


static int d1[] = {1,2,3};
static int d2[] = {-1,-2,-3};
static vector<int*> data = {d1,d2};
INSTANTIATE_TEST_SUITE_P(StackTestData, StackTestP, ValuesIn(data));


TEST_P(StackTestP, Size)
{
    int cnt = s.size();
    for(int i=0; i<cnt; i++)
    {
        s.push(i);
    }
    ASSERT_EQ(cnt*2, s.size());
}

TEST_P(StackTestP, Empty)
{
    int cnt = s.size();
    for(int i=0; i<cnt; i++)
    {
        s.pop();
    }
    ASSERT_TRUE(s.empty());
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
