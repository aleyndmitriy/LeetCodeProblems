///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMHasTeamSelectiveSyncValue;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `HasTeamSelectiveSyncValue` union.
///
/// The value for `hasTeamSelectiveSync` in `DBTEAMFeature`.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMHasTeamSelectiveSyncValue : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMHasTeamSelectiveSyncValueTag` enum type represents the possible
/// tag states with which the `DBTEAMHasTeamSelectiveSyncValue` union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBTEAMHasTeamSelectiveSyncValueTag){
    /// Does this team have team selective sync enabled.
    DBTEAMHasTeamSelectiveSyncValueHasTeamSelectiveSync,

    /// (no description).
    DBTEAMHasTeamSelectiveSyncValueOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMHasTeamSelectiveSyncValueTag tag;

/// Does this team have team selective sync enabled. @note Ensure the
/// `isHasTeamSelectiveSync` method returns true before accessing, otherwise a
/// runtime exception will be raised.
@property (nonatomic, readonly) NSNumber *hasTeamSelectiveSync;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "has_team_selective_sync".
///
/// Description of the "has_team_selective_sync" tag state: Does this team have
/// team selective sync enabled.
///
/// @param hasTeamSelectiveSync Does this team have team selective sync enabled.
///
/// @return An initialized instance.
///
- (instancetype)initWithHasTeamSelectiveSync:(NSNumber *)hasTeamSelectiveSync;

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
/// "has_team_selective_sync".
///
/// @note Call this method and ensure it returns true before accessing the
/// `hasTeamSelectiveSync` property, otherwise a runtime exception will be
/// thrown.
///
/// @return Whether the union's current tag state has value
/// "has_team_selective_sync".
///
- (BOOL)isHasTeamSelectiveSync;

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
/// The serialization class for the `DBTEAMHasTeamSelectiveSyncValue` union.
///
@interface DBTEAMHasTeamSelectiveSyncValueSerializer : NSObject

///
/// Serializes `DBTEAMHasTeamSelectiveSyncValue` instances.
///
/// @param instance An instance of the `DBTEAMHasTeamSelectiveSyncValue` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMHasTeamSelectiveSyncValue` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMHasTeamSelectiveSyncValue *)instance;

///
/// Deserializes `DBTEAMHasTeamSelectiveSyncValue` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMHasTeamSelectiveSyncValue` API object.
///
/// @return An instantiation of the `DBTEAMHasTeamSelectiveSyncValue` object.
///
+ (DBTEAMHasTeamSelectiveSyncValue *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
