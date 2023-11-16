//
//  BoostUtils.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 19.08.23.
//

#include "BoostSessionHeader.hpp"

void fail(boost::beast::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}
