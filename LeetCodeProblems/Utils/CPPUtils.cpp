//
//  CPPUtils.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.05.23.
//

#include "CPPUtils.hpp"
#include <stdarg.h>
#include<new>
std::string getFormatingString(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int len = vsnprintf(nullptr, 0, format,args);
    if (len < 1) {
        return std::string();
    }
    char * buffer = new(std::nothrow)char[len+1];
    if(buffer == nullptr) {
        return std::string();
    }
    int resLen = vsnprintf(buffer,len + 1, format,args);
    if (resLen < len) {
        return std::string();
    }
    std::string res(buffer);
    delete [] buffer;
    va_end (args);
    return res;
}
