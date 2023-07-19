//
//  LoginViewRouter.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.04.23.
//
#import <UIKit/UIKit.h>
#import "LoginViewRouter.h"

@interface LoginViewRouter()
@property (nonatomic, weak) UIViewController* controller;
@end

@implementation LoginViewRouter

- (void)popBack {
    [self.controller.navigationController popViewControllerAnimated:YES];
}

@end
