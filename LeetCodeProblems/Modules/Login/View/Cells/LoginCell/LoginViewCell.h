//
//  LoginViewCell.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.04.23.
//

#import <UIKit/UIKit.h>
#import "LoginViewCellDelegate.h"
NS_ASSUME_NONNULL_BEGIN

typedef NSString * LCLoginState NS_STRING_ENUM;
FOUNDATION_EXPORT LCLoginState const LCLoginStateIn;
FOUNDATION_EXPORT LCLoginState const LCLoginStateOut;
FOUNDATION_EXPORT LCLoginState const LCLoginStateProcessing;
LCLoginState const LCLoginStateIn = @"LogIn";
LCLoginState const LCLoginStateOut = @"LogOut";
LCLoginState const LCLoginStateProcessing = @"Processing...";

@interface LoginViewCell: UITableViewCell
@property (nonatomic, assign) RemoteServiceAuthState loggedState;
@property (nonatomic, assign) ProcessProgress loginProcess;
@property (nonatomic, strong) id<LoginViewCellDelegate> cellDelegate;
-(void) labelText:(NSString* _Nonnull)text imageName:(NSString* _Nonnull)imgName;
-(void) updateLogInView;
-(void) updateLogOutView;
-(void) updateProcessingView;
@end

NS_ASSUME_NONNULL_END
