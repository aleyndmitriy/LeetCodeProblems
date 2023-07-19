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
-(void) logInToService:(RemoteServiceType)serviceType;
-(void) logOutFromService:(RemoteServiceType)serviceType;
-(void) loadStorage:(RemoteServiceType)serviceType;

@end

#endif /* LoginViewCellDelegate_h */
