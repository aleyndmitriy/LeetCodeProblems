//
//  LoginViewModuleInitializer.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.04.23.
//

#import "LoginViewModuleInitializer.h"
#import "LoginViewController.h"
#import "LoginViewInteractor.h"
#import "LoginViewPresenter.h"
#import "LoginViewRouter.h"
@implementation LoginViewModuleInitializer

+(LoginViewController* _Nonnull) createLoginViewController
{
    LoginViewRouter* router = [[LoginViewRouter alloc] init];
    LoginViewInteractor* interactor = [[LoginViewInteractor alloc] init];
    if (router == nil || interactor == nil) {
        [NSException raise:NSGenericException format:@"Can't create login interactor and login router"];
    }
    LoginViewPresenter* presenter = [[LoginViewPresenter alloc] initWith:interactor router:router];
    if(presenter == nil) {
        [NSException raise:NSGenericException format:@"Can't create main presenter"];
    }
    [interactor setInteractorOutput:presenter];
    LoginViewController* controller = [[LoginViewController alloc] initWith:presenter];
    if(controller == nil)
    {
        [NSException raise:NSGenericException format:@"Can't create main controller"];
    }
    presenter.view = controller;
    return controller;
}
@end
