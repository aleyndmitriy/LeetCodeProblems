//
//  MainViewPresenter.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//

#import "MainViewPresenter.h"

#import "MainViewInteractorInput.h"
#import "MainViewInput.h"
#import "MainViewRouterInput.h"

@interface MainViewPresenter ()
@property (nonatomic, strong) id<MainViewInteractorInput> interactor;
@property (nonatomic, strong) id<MainViewRouterInput> router;
@end

@implementation MainViewPresenter

-(instancetype)initWith:(id<MainViewInteractorInput>)interactor router:(id<MainViewRouterInput>)router
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
