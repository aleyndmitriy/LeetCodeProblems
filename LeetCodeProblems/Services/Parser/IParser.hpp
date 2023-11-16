//
//  IParser.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.09.23.
//

#ifndef IParser_hpp
#define IParser_hpp
#include<string>
class IParser {
public:
    virtual void Parse(std::string && input) = 0;
    virtual ~IParser(){};
}

#endif /* IParser_h */
