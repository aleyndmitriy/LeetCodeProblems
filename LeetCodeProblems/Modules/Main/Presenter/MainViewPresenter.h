//
//  MainViewPresenter.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//

#import <Foundation/Foundation.h>
#import "MainViewOutput.h"
#import "MainViewInteractorOutput.h"

NS_ASSUME_NONNULL_BEGIN
@protocol MainViewInput;
@protocol MainViewInteractorInput;
@protocol MainViewRouterInput;

@interface MainViewPresenter : NSObject<MainViewOutput,MainViewInteractorOutput>
@property (nonatomic, weak) id<MainViewInput> view;

-(instancetype)initWith:(id<MainViewInteractorInput>)interactor router:(id<MainViewRouterInput>)router;

@end

NS_ASSUME_NONNULL_END
