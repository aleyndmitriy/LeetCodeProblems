//
//  MainViewInteractorInput.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 3.04.23.
//

#ifndef MainViewInteractorInput_h
#define MainViewInteractorInput_h
@protocol MainViewInteractorOutput;

@protocol MainViewInteractorInput<NSObject>
-(void)setInteractorOutput:(id<MainViewInteractorOutput>)output;
@end

#endif /* MainViewInteractorInput_h */
