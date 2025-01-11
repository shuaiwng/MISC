#pragma once

#include <iostream>
#include "doc.h"

using namespace std;

// class SUT{
// public:
// 	SUT(DOC& doc) : doc_(doc) {}
// 	bool foo(bool, bool);
	
// private:
// 	DOC& doc_;
// };


class SUT{
public:
    SUT(DOC<int>& param) : doc(param) {}
    void foo() {cout << doc.foo(1) << endl;}

private:
    DOC<int>& doc;
};
