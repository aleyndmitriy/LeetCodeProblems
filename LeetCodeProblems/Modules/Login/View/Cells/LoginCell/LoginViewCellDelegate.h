//
//  LoginViewCellDelegate.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 17.07.23.
//

#ifndef LoginViewCellDelegate_h
#define LoginViewCellDelegate_h
#import "LoginService.h"
@protocol LoginViewCellDelegate <NSObject>
-(void) logInToService;
-(void) logOutFromService;
-(void) loadStorage;

@end

#endif /* LoginViewCellDelegate_h */
