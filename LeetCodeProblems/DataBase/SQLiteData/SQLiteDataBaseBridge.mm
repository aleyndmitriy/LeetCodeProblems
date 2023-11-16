//
//  SQLiteDataBaseBridge.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.11.23.
//

#import "SQLiteDataBaseBridge.h"

#import "SQLiteConstants.h"
#include <memory>

@implementation SQLiteDataBaseBridge
{
    NSString* databasePath;
}

+ (instancetype)sharedInstance {
    static SQLiteDataBaseBridge* sharedInstance_ = nil;
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            sharedInstance_ = [[SQLiteDataBaseBridge alloc] init];
        });
        return sharedInstance_;
}

- (NSString * _Nonnull)getDatabaseAddress {
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString * documentsDirectory = [[NSString alloc] initWithString: [paths objectAtIndex:0]];
    NSString* baseName = [NSString stringWithCString:Db_DatabaseName encoding:NSASCIIStringEncoding];
    NSString * writableDBPath = [NSString stringWithString: [documentsDirectory stringByAppendingPathComponent:baseName]];
    return writableDBPath;
}

- (instancetype)init {
  if (self = [super init]) {
      databasePath = [self getDatabaseAddress];
      _database = new SQLiteDataBase{std::string{databasePath.UTF8String}};
      
  }
  return self;
}
@end
