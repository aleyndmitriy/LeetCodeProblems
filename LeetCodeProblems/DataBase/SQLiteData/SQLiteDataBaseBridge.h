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

@property(nonatomic, readonly, unsafe_unretained) SQLiteDataBase* database;
@property(nonatomic, readonly, copy) NSString* databasePath;
@end

NS_ASSUME_NONNULL_END
