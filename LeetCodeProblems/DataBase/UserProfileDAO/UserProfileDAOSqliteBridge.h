//
//  UserProfileDAOSqliteBridge.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 7.08.23.
//

#import <Foundation/Foundation.h>
#import "IUserProfileDAOBridge.h"
@class SQLiteDataBaseBridge;
NS_ASSUME_NONNULL_BEGIN

@interface UserProfileDAOSqliteBridge : NSObject<IUserProfileDAOBridge>
-(instancetype) init:(SQLiteDataBaseBridge*) dataBase;
@end

NS_ASSUME_NONNULL_END
