//
//  LoginViewPresenter.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.04.23.
//

#import "LoginViewPresenter.h"

#import "LoginViewInteractorInput.h"
#import "LoginViewInput.h"
#import "LoginViewRouterInput.h"

@interface LoginViewPresenter ()
@property (nonatomic, strong) id<LoginViewInteractorInput> interactor;
@property (nonatomic, strong) id<LoginViewRouterInput> router;
@end
@implementation LoginViewPresenter

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

@end
