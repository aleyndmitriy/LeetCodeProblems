//
//  LoginYandexPresenter.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 18.04.23.
//

#import <Foundation/Foundation.h>
#import "LoginViewInteractorOutput.h"
@protocol LoginViewCellInput;
@protocol LoginViewInteractorInput;
@protocol LoginViewRouterInput;
NS_ASSUME_NONNULL_BEGIN

@interface LoginYandexPresenter : NSObject<LoginViewInteractorOutput>
@property (nonatomic, weak) id<LoginViewCellInput> view;
-(instancetype)initWith:(id<LoginViewInteractorInput>)interactor router:(id<LoginViewRouterInput>)router;
@end

NS_ASSUME_NONNULL_END
