//
//  SQLiteDataBaseBridge.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.11.23.
//

#import <Foundation/Foundation.h>
#import "SQLiteDataBase.hpp"
NS_ASSUME_NONNULL_BEGIN

@interface SQLiteDataBaseBridge : NSObject
+ (instancetype) sharedInstance;
@property(nonatomic, unsafe_unretained) SQLiteDataBase* database;
@end

NS_ASSUME_NONNULL_END
