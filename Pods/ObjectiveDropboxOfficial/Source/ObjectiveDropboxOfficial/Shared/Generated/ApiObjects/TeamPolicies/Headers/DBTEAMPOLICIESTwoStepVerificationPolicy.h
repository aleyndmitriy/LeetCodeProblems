///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMPOLICIESTwoStepVerificationPolicy;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `TwoStepVerificationPolicy` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMPOLICIESTwoStepVerificationPolicy : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMPOLICIESTwoStepVerificationPolicyTag` enum type represents the
/// possible tag states with which the `DBTEAMPOLICIESTwoStepVerificationPolicy`
/// union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBTEAMPOLICIESTwoStepVerificationPolicyTag){
    /// Enabled require two factor authorization.
    DBTEAMPOLICIESTwoStepVerificationPolicyRequireTfaEnable,

    /// Disabled require two factor authorization.
    DBTEAMPOLICIESTwoStepVerificationPolicyRequireTfaDisable,

    /// (no description).
    DBTEAMPOLICIESTwoStepVerificationPolicyOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMPOLICIESTwoStepVerificationPolicyTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "require_tfa_enable".
///
/// Description of the "require_tfa_enable" tag state: Enabled require two
/// factor authorization.
///
/// @return An initialized instance.
///
- (instancetype)initWithRequireTfaEnable;

///
/// Initializes union class with tag state of "require_tfa_disable".
///
/// Description of the "require_tfa_disable" tag state: Disabled require two
/// factor authorization.
///
/// @return An initialized instance.
///
- (instancetype)initWithRequireTfaDisable;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value
/// "require_tfa_enable".
///
/// @return Whether the union's current tag state has value
/// "require_tfa_enable".
///
- (BOOL)isRequireTfaEnable;

///
/// Retrieves whether the union's current tag state has value
/// "require_tfa_disable".
///
/// @return Whether the union's current tag state has value
/// "require_tfa_disable".
///
- (BOOL)isRequireTfaDisable;

///
/// Retrieves whether the union's current tag state has value "other".
///
/// @return Whether the union's current tag state has value "other".
///
- (BOOL)isOther;

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag state.
///
- (NSString *)tagName;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DBTEAMPOLICIESTwoStepVerificationPolicy`
/// union.
///
@interface DBTEAMPOLICIESTwoStepVerificationPolicySerializer : NSObject

///
/// Serializes `DBTEAMPOLICIESTwoStepVerificationPolicy` instances.
///
/// @param instance An instance of the `DBTEAMPOLICIESTwoStepVerificationPolicy`
/// API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMPOLICIESTwoStepVerificationPolicy` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMPOLICIESTwoStepVerificationPolicy *)instance;

///
/// Deserializes `DBTEAMPOLICIESTwoStepVerificationPolicy` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMPOLICIESTwoStepVerificationPolicy` API object.
///
/// @return An instantiation of the `DBTEAMPOLICIESTwoStepVerificationPolicy`
/// object.
///
+ (DBTEAMPOLICIESTwoStepVerificationPolicy *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
