//
//  DataAccessAssembly.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.11.23.
//

#import <Foundation/Foundation.h>
@protocol IUserProfileDAOBridge;
NS_ASSUME_NONNULL_BEGIN

@interface DataAccessAssembly : NSObject
+(nonnull id<IUserProfileDAOBridge>) userProfileSqliteDAO;
@end

NS_ASSUME_NONNULL_END
