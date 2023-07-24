///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBFILESRelocationBatchArgBase.h"
#import "DBSerializableProtocol.h"

@class DBFILESRelocationBatchArg;
@class DBFILESRelocationPath;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `RelocationBatchArg` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILESRelocationBatchArg : DBFILESRelocationBatchArgBase <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// This flag has no effect.
@property (nonatomic, readonly) NSNumber *allowSharedFolder;

/// Allow moves by owner even if it would result in an ownership transfer for
/// the content being moved. This does not apply to copies.
@property (nonatomic, readonly) NSNumber *allowOwnershipTransfer;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param entries List of entries to be moved or copied. Each entry is
/// RelocationPath.
/// @param autorename If there's a conflict with any file, have the Dropbox
/// server try to autorename that file to avoid the conflict.
/// @param allowSharedFolder This flag has no effect.
/// @param allowOwnershipTransfer Allow moves by owner even if it would result
/// in an ownership transfer for the content being moved. This does not apply to
/// copies.
///
/// @return An initialized instance.
///
- (instancetype)initWithEntries:(NSArray<DBFILESRelocationPath *> *)entries
                     autorename:(nullable NSNumber *)autorename
              allowSharedFolder:(nullable NSNumber *)allowSharedFolder
         allowOwnershipTransfer:(nullable NSNumber *)allowOwnershipTransfer;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param entries List of entries to be moved or copied. Each entry is
/// RelocationPath.
///
/// @return An initialized instance.
///
- (instancetype)initWithEntries:(NSArray<DBFILESRelocationPath *> *)entries;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `RelocationBatchArg` struct.
///
@interface DBFILESRelocationBatchArgSerializer : NSObject

///
/// Serializes `DBFILESRelocationBatchArg` instances.
///
/// @param instance An instance of the `DBFILESRelocationBatchArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILESRelocationBatchArg` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBFILESRelocationBatchArg *)instance;

///
/// Deserializes `DBFILESRelocationBatchArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILESRelocationBatchArg` API object.
///
/// @return An instantiation of the `DBFILESRelocationBatchArg` object.
///
+ (DBFILESRelocationBatchArg *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
