//
//  LoginYandexPresenter.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 18.04.23.
//

#import "LoginYandexPresenter.h"
#import <YandexLoginSDK/YandexLoginSDK.h>
#import "UserProfileData.h"
#import "LoginViewInteractorInput.h"
#import "LoginViewRouterInput.h"
@interface LoginYandexPresenter()<YXLObserver>
{
    UserProfileData* userData;
}
@property (nonatomic, strong) id<LoginViewInteractorInput> interactor;
@property (nonatomic, strong) id<LoginViewRouterInput> router;
@end

@implementation LoginYandexPresenter

-(instancetype)initWith:(id<LoginViewInteractorInput>)interactor router:(id<LoginViewRouterInput>)router
{
    self = [super init];
    if(self) {
        self.interactor = interactor;
        self.router = router;
        return self;
    }
    else {
        return nil;
    }
}


- (void)loginToService {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared addObserver:weakSelf];
    if(userData) {
        
    }
}

//YXLObserver
- (void)loginDidFinishWithError:(nonnull NSError *)error {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared removeObserver:weakSelf];
    
}

- (void)loginDidFinishWithResult:(nonnull id<YXLLoginResult>)result {
    __weak __typeof__(self) weakSelf = self;
    [YXLSdk.shared removeObserver:weakSelf];
    
}

@end
