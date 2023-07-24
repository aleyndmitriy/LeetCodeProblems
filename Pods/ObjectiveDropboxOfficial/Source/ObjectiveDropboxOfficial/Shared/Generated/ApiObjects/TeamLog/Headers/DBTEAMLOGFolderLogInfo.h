///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"
#import "DBTEAMLOGFileOrFolderLogInfo.h"

@class DBTEAMLOGFolderLogInfo;
@class DBTEAMLOGPathLogInfo;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `FolderLogInfo` struct.
///
/// Folder's logged information.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGFolderLogInfo : DBTEAMLOGFileOrFolderLogInfo <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// Number of files within the folder.
@property (nonatomic, readonly, nullable) NSNumber *fileCount;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param path Path relative to event context.
/// @param displayName Display name.
/// @param fileId Unique ID.
/// @param fileSize File or folder size in bytes.
/// @param fileCount Number of files within the folder.
///
/// @return An initialized instance.
///
- (instancetype)initWithPath:(DBTEAMLOGPathLogInfo *)path
                 displayName:(nullable NSString *)displayName
                      fileId:(nullable NSString *)fileId
                    fileSize:(nullable NSNumber *)fileSize
                   fileCount:(nullable NSNumber *)fileCount;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param path Path relative to event context.
///
/// @return An initialized instance.
///
- (instancetype)initWithPath:(DBTEAMLOGPathLogInfo *)path;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `FolderLogInfo` struct.
///
@interface DBTEAMLOGFolderLogInfoSerializer : NSObject

///
/// Serializes `DBTEAMLOGFolderLogInfo` instances.
///
/// @param instance An instance of the `DBTEAMLOGFolderLogInfo` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGFolderLogInfo` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGFolderLogInfo *)instance;

///
/// Deserializes `DBTEAMLOGFolderLogInfo` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGFolderLogInfo` API object.
///
/// @return An instantiation of the `DBTEAMLOGFolderLogInfo` object.
///
+ (DBTEAMLOGFolderLogInfo *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END