//
//  UserProfileDAOSqliteBridge.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 7.08.23.
//

#import <Foundation/Foundation.h>
#import "IUserProfileDAOBridge.h"
NS_ASSUME_NONNULL_BEGIN

@interface UserProfileDAOSqliteBridge : NSObject<IUserProfileDAOBridge>
-(instancetype) init;
@end

NS_ASSUME_NONNULL_END
