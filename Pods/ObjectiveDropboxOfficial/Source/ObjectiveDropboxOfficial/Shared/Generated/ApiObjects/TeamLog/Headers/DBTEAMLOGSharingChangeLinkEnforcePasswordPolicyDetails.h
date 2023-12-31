///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGChangeLinkExpirationPolicy;
@class DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharingChangeLinkEnforcePasswordPolicyDetails` struct.
///
/// Changed the password requirement for the links shared outside of the team.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// To.
@property (nonatomic, readonly) DBTEAMLOGChangeLinkExpirationPolicy *dNewValue;

/// From.
@property (nonatomic, readonly, nullable) DBTEAMLOGChangeLinkExpirationPolicy *previousValue;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param dNewValue To.
/// @param previousValue From.
///
/// @return An initialized instance.
///
- (instancetype)initWithDNewValue:(DBTEAMLOGChangeLinkExpirationPolicy *)dNewValue
                    previousValue:(nullable DBTEAMLOGChangeLinkExpirationPolicy *)previousValue;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param dNewValue To.
///
/// @return An initialized instance.
///
- (instancetype)initWithDNewValue:(DBTEAMLOGChangeLinkExpirationPolicy *)dNewValue;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the
/// `SharingChangeLinkEnforcePasswordPolicyDetails` struct.
///
@interface DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails`
/// instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails *)instance;

///
/// Deserializes `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails`
/// instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails` API object.
///
/// @return An instantiation of the
/// `DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails` object.
///
+ (DBTEAMLOGSharingChangeLinkEnforcePasswordPolicyDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
