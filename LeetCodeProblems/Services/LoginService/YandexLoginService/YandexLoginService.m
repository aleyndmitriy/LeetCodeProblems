//
//  YandexLoginService.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.07.23.
//

#import "YandexLoginService.h"
#import <YandexLoginSDK/YandexLoginSDK.h>
#import "UserProfileData.h"
@interface YandexLoginService()<YXLObserver>

@end;

@implementation YandexLoginService

@synthesize userData;

- (BOOL)shareUrl:(nonnull NSURL *)url withKey:(nullable NSString*)key{
    return [YXLSdk.shared handleOpenURL:url sourceApplication:key];
}

- (void)signIn {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared addObserver:weakSelf];
    [YXLSdk.shared authorize];
}

- (void)signOut {
    [YXLSdk.shared logout];
}

- (void)loginDidFinishWithError:(nonnull NSError *)error {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared removeObserver:weakSelf];
}

- (void)loginDidFinishWithResult:(nonnull id<YXLLoginResult>)result {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared removeObserver:weakSelf];
}

@end
