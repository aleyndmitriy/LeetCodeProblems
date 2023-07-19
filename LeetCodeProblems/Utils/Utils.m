//
//  Utils.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 14.04.23.
//

#import "Utils.h"
NSString* _Nullable convertToString(id _Nullable object)
{
    if(object != nil && [object isKindOfClass:[NSString class]])
    {
        return (NSString*)object;
    } else {
        return nil;
    }
}

NSString* _Nullable getFileAddress(NSString* _Nonnull fileName)
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString * documentsDirectory = [[NSString alloc] initWithString: [paths objectAtIndex:0]];
    NSString * writableFilePath = [NSString stringWithString: [documentsDirectory stringByAppendingPathComponent:fileName]];
    return writableFilePath;
}
