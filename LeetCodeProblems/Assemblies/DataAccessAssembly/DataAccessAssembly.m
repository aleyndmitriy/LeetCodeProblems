//
//  DataAccessAssembly.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.11.23.
//

#import "DataAccessAssembly.h"
#import "UserProfileDAOSqliteBridge.h"
@implementation DataAccessAssembly

+(nonnull id<IUserProfileDAOBridge>)userProfileSqliteDAO {
    return [[UserProfileDAOSqliteBridge alloc] init];
}
@end


