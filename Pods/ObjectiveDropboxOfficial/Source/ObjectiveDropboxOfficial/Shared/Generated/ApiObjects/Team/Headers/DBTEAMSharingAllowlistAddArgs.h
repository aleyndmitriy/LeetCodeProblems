///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMSharingAllowlistAddArgs;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharingAllowlistAddArgs` struct.
///
/// Structure representing Approve List entries. Domain and emails are
/// supported. At least one entry of any supported type is required.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMSharingAllowlistAddArgs : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// List of domains represented by valid string representation (RFC-1034/5).
@property (nonatomic, readonly, nullable) NSArray<NSString *> *domains;

/// List of emails represented by valid string representation (RFC-5322/822).
@property (nonatomic, readonly, nullable) NSArray<NSString *> *emails;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param domains List of domains represented by valid string representation
/// (RFC-1034/5).
/// @param emails List of emails represented by valid string representation
/// (RFC-5322/822).
///
/// @return An initialized instance.
///
- (instancetype)initWithDomains:(nullable NSArray<NSString *> *)domains emails:(nullable NSArray<NSString *> *)emails;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
///
/// @return An initialized instance.
///
- (instancetype)initDefault;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SharingAllowlistAddArgs` struct.
///
@interface DBTEAMSharingAllowlistAddArgsSerializer : NSObject

///
/// Serializes `DBTEAMSharingAllowlistAddArgs` instances.
///
/// @param instance An instance of the `DBTEAMSharingAllowlistAddArgs` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMSharingAllowlistAddArgs` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMSharingAllowlistAddArgs *)instance;

///
/// Deserializes `DBTEAMSharingAllowlistAddArgs` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMSharingAllowlistAddArgs` API object.
///
/// @return An instantiation of the `DBTEAMSharingAllowlistAddArgs` object.
///
+ (DBTEAMSharingAllowlistAddArgs *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
