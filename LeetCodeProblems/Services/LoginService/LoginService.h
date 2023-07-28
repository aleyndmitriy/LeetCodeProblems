//
//  LoginService.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 11.04.23.
//

#import <Foundation/Foundation.h>
@class UserProfileData;
const NSInteger ServicesCount = 3;

typedef NS_ENUM(NSUInteger, RemoteServiceType)
{
    Yandex = 0,
    DropBox,
    OneDrive
};

typedef NS_ENUM(NSUInteger, ProcessProgress)
{
    started = 0,
    finished,
    processing
};

typedef NS_ENUM(BOOL, RemoteServiceAuthState)
{
    SignOut = NO,
    SignIn = YES
};
NS_ASSUME_NONNULL_BEGIN

@protocol LoginService<NSObject>
@property (readwrite, copy, nullable) UserProfileData* userData;
-(void)signIn;
-(void)signOut;
-(BOOL)shareUrl:(nonnull NSURL*)url withKey:(nullable NSString*)key;
@end

NS_ASSUME_NONNULL_END
