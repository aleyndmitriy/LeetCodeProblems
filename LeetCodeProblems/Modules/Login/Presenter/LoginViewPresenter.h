//
//  LoginViewPresenter.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.04.23.
//

#import <Foundation/Foundation.h>
#import "LoginViewOutput.h"
#import "LoginViewInteractorOutput.h"
@protocol LoginViewInput;
@protocol LoginViewInteractorInput;
@protocol LoginViewRouterInput;

NS_ASSUME_NONNULL_BEGIN

@interface LoginViewPresenter : NSObject<LoginViewOutput,LoginViewInteractorOutput>
@property (nonatomic, weak) id<LoginViewInput> view;

-(instancetype)initWith:(id<LoginViewInteractorInput>)interactor router:(id<LoginViewRouterInput>)router;

@end

NS_ASSUME_NONNULL_END
