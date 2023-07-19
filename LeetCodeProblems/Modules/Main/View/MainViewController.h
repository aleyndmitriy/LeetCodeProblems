//
//  ViewController.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 31.03.23.
//

#import <UIKit/UIKit.h>
#import "MainViewInput.h"
@protocol MainViewOutput;

@interface MainViewController : UIViewController <MainViewInput>
-(instancetype)initWith:(id<MainViewOutput>)presenter;
@end

