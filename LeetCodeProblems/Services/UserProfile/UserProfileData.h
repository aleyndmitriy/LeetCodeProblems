//
//  UserProfileData.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 13.04.23.
//

#import <Foundation/Foundation.h>
#import "LoginService.h"
NS_ASSUME_NONNULL_BEGIN

@interface UserProfileData : NSObject<NSCopying, NSSecureCoding>
@property(nonatomic, readwrite, copy, nullable) NSString *userID;
@property(nonatomic, readwrite, copy, nullable) NSString *givenName;
@property(nonatomic, readwrite, copy, nullable) NSString *phone;
@property(nonatomic, readwrite, copy, nullable) NSString *email;
@property(nonatomic, readwrite, copy, nullable) NSString *name;
@property(nonatomic, readwrite, copy, nullable) NSString *familyName;
@property(nonatomic, assign) RemoteServiceType serviceType;
@property(nonatomic, readonly, copy, nonnull) NSString *accessToken;
-(instancetype)initWithToken:(NSString* _Nonnull)token;
@end

NS_ASSUME_NONNULL_END
