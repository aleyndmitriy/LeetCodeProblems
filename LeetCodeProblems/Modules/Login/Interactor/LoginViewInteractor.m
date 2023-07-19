//
//  LoginViewInteractor.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 27.04.23.
//

#import "LoginViewInteractor.h"
#import "LoginViewInteractorOutput.h"
@interface LoginViewInteractor()
@property (nonatomic, weak) id<LoginViewInteractorOutput> output;
@end

@implementation LoginViewInteractor

-(void)setInteractorOutput:(id<LoginViewInteractorOutput>)output
{
    self.output = output;
}

@end
