///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMPOLICIESSharedLinkCreatePolicy;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharedLinkCreatePolicy` union.
///
/// Policy governing the visibility of shared links. This policy can apply to
/// newly created shared links, or all shared links.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMPOLICIESSharedLinkCreatePolicy : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMPOLICIESSharedLinkCreatePolicyTag` enum type represents the
/// possible tag states with which the `DBTEAMPOLICIESSharedLinkCreatePolicy`
/// union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBTEAMPOLICIESSharedLinkCreatePolicyTag){
    /// By default, anyone can access newly created shared links. No login will
    /// be required to access the shared links unless overridden.
    DBTEAMPOLICIESSharedLinkCreatePolicyDefaultPublic,

    /// By default, only members of the same team can access newly created
    /// shared links. Login will be required to access the shared links unless
    /// overridden.
    DBTEAMPOLICIESSharedLinkCreatePolicyDefaultTeamOnly,

    /// Only members of the same team can access all shared links. Login will be
    /// required to access all shared links.
    DBTEAMPOLICIESSharedLinkCreatePolicyTeamOnly,

    /// Only people invited can access newly created links. Login will be
    /// required to access the shared links unless overridden.
    DBTEAMPOLICIESSharedLinkCreatePolicyDefaultNoOne,

    /// (no description).
    DBTEAMPOLICIESSharedLinkCreatePolicyOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMPOLICIESSharedLinkCreatePolicyTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "default_public".
///
/// Description of the "default_public" tag state: By default, anyone can access
/// newly created shared links. No login will be required to access the shared
/// links unless overridden.
///
/// @return An initialized instance.
///
- (instancetype)initWithDefaultPublic;

///
/// Initializes union class with tag state of "default_team_only".
///
/// Description of the "default_team_only" tag state: By default, only members
/// of the same team can access newly created shared links. Login will be
/// required to access the shared links unless overridden.
///
/// @return An initialized instance.
///
- (instancetype)initWithDefaultTeamOnly;

///
/// Initializes union class with tag state of "team_only".
///
/// Description of the "team_only" tag state: Only members of the same team can
/// access all shared links. Login will be required to access all shared links.
///
/// @return An initialized instance.
///
- (instancetype)initWithTeamOnly;

///
/// Initializes union class with tag state of "default_no_one".
///
/// Description of the "default_no_one" tag state: Only people invited can
/// access newly created links. Login will be required to access the shared
/// links unless overridden.
///
/// @return An initialized instance.
///
- (instancetype)initWithDefaultNoOne;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "default_public".
///
/// @return Whether the union's current tag state has value "default_public".
///
- (BOOL)isDefaultPublic;

///
/// Retrieves whether the union's current tag state has value
/// "default_team_only".
///
/// @return Whether the union's current tag state has value "default_team_only".
///
- (BOOL)isDefaultTeamOnly;

///
/// Retrieves whether the union's current tag state has value "team_only".
///
/// @return Whether the union's current tag state has value "team_only".
///
- (BOOL)isTeamOnly;

///
/// Retrieves whether the union's current tag state has value "default_no_one".
///
/// @return Whether the union's current tag state has value "default_no_one".
///
- (BOOL)isDefaultNoOne;

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
/// The serialization class for the `DBTEAMPOLICIESSharedLinkCreatePolicy`
/// union.
///
@interface DBTEAMPOLICIESSharedLinkCreatePolicySerializer : NSObject

///
/// Serializes `DBTEAMPOLICIESSharedLinkCreatePolicy` instances.
///
/// @param instance An instance of the `DBTEAMPOLICIESSharedLinkCreatePolicy`
/// API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMPOLICIESSharedLinkCreatePolicy` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMPOLICIESSharedLinkCreatePolicy *)instance;

///
/// Deserializes `DBTEAMPOLICIESSharedLinkCreatePolicy` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMPOLICIESSharedLinkCreatePolicy` API object.
///
/// @return An instantiation of the `DBTEAMPOLICIESSharedLinkCreatePolicy`
/// object.
///
+ (DBTEAMPOLICIESSharedLinkCreatePolicy *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
