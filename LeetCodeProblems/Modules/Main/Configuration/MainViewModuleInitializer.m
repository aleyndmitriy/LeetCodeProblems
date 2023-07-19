//
//  MainViewModuleInitializer.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//

#import "MainViewModuleInitializer.h"
#import "MainViewController.h"
#import "MainViewInteractor.h"
#import "MainViewPresenter.h"
#import "MainViewRouter.h"

@implementation MainViewModuleInitializer

+(MainViewController* _Nonnull) createMainViewViewController
{
    MainViewRouter* router = [[MainViewRouter alloc] init];
    MainViewInteractor* interactor = [[MainViewInteractor alloc] init];
    if (router == nil || interactor == nil) {
        [NSException raise:NSGenericException format:@"Can't create main interactor or main router"];
    }
    MainViewPresenter* presenter = [[MainViewPresenter alloc] initWith:interactor router:router];
    if(presenter == nil) {
        [NSException raise:NSGenericException format:@"Can't create main presenter"];
    }
    [interactor setInteractorOutput:presenter];
    MainViewController* controller = [[MainViewController alloc] initWith:presenter];
    if(controller == nil)
    {
        [NSException raise:NSGenericException format:@"Can't create main controller"];
    }
    presenter.view = controller;
    return controller;
}

@end
