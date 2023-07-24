///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGPaperEnabledUsersGroupRemovalDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `PaperEnabledUsersGroupRemovalDetails` struct.
///
/// Removed users from Paper-enabled users list.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGPaperEnabledUsersGroupRemovalDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @return An initialized instance.
///
- (instancetype)initDefault;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `PaperEnabledUsersGroupRemovalDetails`
/// struct.
///
@interface DBTEAMLOGPaperEnabledUsersGroupRemovalDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGPaperEnabledUsersGroupRemovalDetails *)instance;

///
/// Deserializes `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` API object.
///
/// @return An instantiation of the
/// `DBTEAMLOGPaperEnabledUsersGroupRemovalDetails` object.
///
+ (DBTEAMLOGPaperEnabledUsersGroupRemovalDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END