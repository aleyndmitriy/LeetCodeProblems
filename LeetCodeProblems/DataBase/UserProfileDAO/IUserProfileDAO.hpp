//
//  IUserProfileDAO.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.05.23.
//

#ifndef IUserProfileDAO_hpp
#define IUserProfileDAO_hpp

#include "CUserProfileData.h"
#import <optional>
class IUserProfileDAO
{
public:
    virtual int SaveUserProfile(const CUserProfileData& user) = 0;
    virtual std::optional<CUserProfileData> GetUserProfile(int type) = 0;
    virtual int DeleteUserProfile(int type) = 0;
    virtual ~IUserProfileDAO() {
        
    };
};

#endif /* IUserProfileDAO_hpp */
