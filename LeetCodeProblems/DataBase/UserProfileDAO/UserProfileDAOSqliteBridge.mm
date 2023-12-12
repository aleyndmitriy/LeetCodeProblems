//
//  UserProfileDAOSqliteBridge.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 7.08.23.
//

#import "UserProfileDAOSqliteBridge.h"
#import <future>
#import <memory>
#import "UserProfileDAOSqliteImpl.hpp"
#import "IUserProfileDAO.hpp"

#import "SQLiteDataBaseBridge.h"

@implementation UserProfileDAOSqliteBridge
{
    std::unique_ptr<IUserProfileDAO> impl;
}
-(instancetype) init
{
    if([super init]) {
        
        impl = std::make_unique<UserProfileDAOSqliteImpl>([SQLiteDataBaseBridge sharedInstance].database);
        return self;
    }
    return nil;
}
- (void)deleteUserProfile:(RemoteServiceType)type {
    
}

- (UserProfileData *)getUserProfile:(RemoteServiceType)type {
    
    
  
    return nil;
}

- (NSInteger)saveUserProfile:(UserProfileData *)user {
    return 0;
}

@end
