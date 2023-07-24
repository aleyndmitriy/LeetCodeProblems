///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBFILESFileLock;
@class DBFILESLockConflictError;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `LockConflictError` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILESLockConflictError : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The lock that caused the conflict.
@property (nonatomic, readonly) DBFILESFileLock *lock;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param lock The lock that caused the conflict.
///
/// @return An initialized instance.
///
- (instancetype)initWithLock:(DBFILESFileLock *)lock;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `LockConflictError` struct.
///
@interface DBFILESLockConflictErrorSerializer : NSObject

///
/// Serializes `DBFILESLockConflictError` instances.
///
/// @param instance An instance of the `DBFILESLockConflictError` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILESLockConflictError` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBFILESLockConflictError *)instance;

///
/// Deserializes `DBFILESLockConflictError` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILESLockConflictError` API object.
///
/// @return An instantiation of the `DBFILESLockConflictError` object.
///
+ (DBFILESLockConflictError *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
