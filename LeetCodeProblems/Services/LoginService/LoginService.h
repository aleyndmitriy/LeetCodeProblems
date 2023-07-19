//
//  LoginService.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 11.04.23.
//

#import <Foundation/Foundation.h>
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

@interface LoginService : NSObject
+(LoginService*)loginServiceWithType:(RemoteServiceType)type;

@end

NS_ASSUME_NONNULL_END
