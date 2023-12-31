///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGApplyNamingConventionDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `ApplyNamingConventionDetails` struct.
///
/// Applied naming convention.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGApplyNamingConventionDetails : NSObject <DBSerializable, NSCopying>

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
/// The serialization class for the `ApplyNamingConventionDetails` struct.
///
@interface DBTEAMLOGApplyNamingConventionDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGApplyNamingConventionDetails` instances.
///
/// @param instance An instance of the `DBTEAMLOGApplyNamingConventionDetails`
/// API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGApplyNamingConventionDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGApplyNamingConventionDetails *)instance;

///
/// Deserializes `DBTEAMLOGApplyNamingConventionDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGApplyNamingConventionDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGApplyNamingConventionDetails`
/// object.
///
+ (DBTEAMLOGApplyNamingConventionDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
