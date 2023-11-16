//
//  IUserProfileDAO.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.05.23.
//

#ifndef IUserProfileDAO_hpp
#define IUserProfileDAO_hpp

#include "CUserProfileData.h"
#import <string>
class IUserProfileDAO
{
public:
    virtual void SaveUserProfile(const CUserProfileData& user, std::string& err, int& state) = 0;
    virtual void GetUserProfile(CUserProfileData& user, std::string& err, int& state, int type) = 0;
    virtual void DeleteUserProfile(std::string& err, int& state, int type) = 0;
    virtual ~IUserProfileDAO() {
        
    };
};

#endif /* IUserProfileDAO_hpp */
