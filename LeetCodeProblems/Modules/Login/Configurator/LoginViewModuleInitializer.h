//
//  LoginViewModuleInitializer.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.04.23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LoginViewController;
@class LoginViewCell;

@interface LoginViewModuleInitializer : NSObject
+(LoginViewController* _Nonnull) createLoginViewController;

@end

NS_ASSUME_NONNULL_END
