//
//  MainViewInteractor.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//

#import "MainViewInteractor.h"
#import "MainViewInteractorOutput.h"

@interface MainViewInteractor()
@property (nonatomic, weak) id<MainViewInteractorOutput> output;
@end

@implementation MainViewInteractor

-(void)setInteractorOutput:(id<MainViewInteractorOutput>)output
{
    self.output = output;
}


@end
