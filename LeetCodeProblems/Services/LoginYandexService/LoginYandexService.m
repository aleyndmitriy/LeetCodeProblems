//
//  LoginYandexService.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 11.04.23.
//

#import "LoginYandexService.h"
#import <YandexLoginSDK/YandexLoginSDK.h>
@interface LoginYandexService() <YXLObserver>

@end

@implementation LoginYandexService

// --YXLObserver methods
- (void)loginDidFinishWithError:(nonnull NSError *)error {
    
}

- (void)loginDidFinishWithResult:(nonnull id<YXLLoginResult>)result {
    
}

@end
