//
//  MainViewRouter.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//
#import <UIKit/UIKit.h>
#import "MainViewRouter.h"

@interface MainViewRouter()
@property (nonatomic, weak) UIViewController* controller;
@end

@implementation MainViewRouter

- (void)popBack {
    [self.controller.navigationController popViewControllerAnimated:YES];
}

@end
