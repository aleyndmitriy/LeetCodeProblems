//
//  IUserProfileDAOBridge.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 7.08.23.
//

#ifndef IUserProfileDAOBridge_h
#define IUserProfileDAOBridge_h
#import "UserProfileData.h"

@protocol IUserProfileDAOBridge <NSObject>
-(NSInteger)saveUserProfile:(UserProfileData*)user;
-(UserProfileData*)getUserProfile:(RemoteServiceType)type;
-(void)deleteUserProfile:(RemoteServiceType)type;
@end;

#endif /* IUserProfileDAOBridge_h */
