//
//  LoginViewInteractorInput.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 27.04.23.
//

#ifndef LoginViewInteractorInput_h
#define LoginViewInteractorInput_h
@protocol LoginViewInteractorOutput;
@protocol LoginViewInteractorInput<NSObject>
-(void)setInteractorOutput:(id<LoginViewInteractorOutput>)output;
@end

#endif /* LoginViewInteractorInput_h */
