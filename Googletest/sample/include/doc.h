#pragma once

#include <string>


// class DOC {
// public:
// 	virtual std::string foo()
// 	{
//         return "Hello, World!";
// 	}
// };


template<typename T>
class DOC {
public:
    virtual std::string foo(T param)
    {
        return "I'm foo!";
    }
};
