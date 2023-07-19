//
//  LoginViewController.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.04.23.
//

#import <UIKit/UIKit.h>
#import "LoginViewInput.h"
@protocol LoginViewOutput;
NS_ASSUME_NONNULL_BEGIN

@interface LoginViewController : UIViewController<LoginViewInput>
-(instancetype)initWith:(id<LoginViewOutput>)presenter;
@end

NS_ASSUME_NONNULL_END
