///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGDropboxPasswordsPolicy;
@class DBTEAMLOGDropboxPasswordsPolicyChangedDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `DropboxPasswordsPolicyChangedDetails` struct.
///
/// Changed Dropbox Passwords policy for team.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGDropboxPasswordsPolicyChangedDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// To.
@property (nonatomic, readonly) DBTEAMLOGDropboxPasswordsPolicy *dNewValue;

/// From.
@property (nonatomic, readonly) DBTEAMLOGDropboxPasswordsPolicy *previousValue;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param dNewValue To.
/// @param previousValue From.
///
/// @return An initialized instance.
///
- (instancetype)initWithDNewValue:(DBTEAMLOGDropboxPasswordsPolicy *)dNewValue
                    previousValue:(DBTEAMLOGDropboxPasswordsPolicy *)previousValue;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DropboxPasswordsPolicyChangedDetails`
/// struct.
///
@interface DBTEAMLOGDropboxPasswordsPolicyChangedDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGDropboxPasswordsPolicyChangedDetails *)instance;

///
/// Deserializes `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` API object.
///
/// @return An instantiation of the
/// `DBTEAMLOGDropboxPasswordsPolicyChangedDetails` object.
///
+ (DBTEAMLOGDropboxPasswordsPolicyChangedDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
