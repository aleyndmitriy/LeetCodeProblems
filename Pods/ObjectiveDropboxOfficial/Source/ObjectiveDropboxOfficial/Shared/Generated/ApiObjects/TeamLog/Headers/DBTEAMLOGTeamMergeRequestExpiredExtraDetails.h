///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGPrimaryTeamRequestExpiredDetails;
@class DBTEAMLOGSecondaryTeamRequestExpiredDetails;
@class DBTEAMLOGTeamMergeRequestExpiredExtraDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `TeamMergeRequestExpiredExtraDetails` union.
///
/// Team merge request expiration details
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGTeamMergeRequestExpiredExtraDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMLOGTeamMergeRequestExpiredExtraDetailsTag` enum type represents
/// the possible tag states with which the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBTEAMLOGTeamMergeRequestExpiredExtraDetailsTag){
    /// Team merge request canceled details shown to the primary team.
    DBTEAMLOGTeamMergeRequestExpiredExtraDetailsPrimaryTeam,

    /// Team merge request canceled details shown to the secondary team.
    DBTEAMLOGTeamMergeRequestExpiredExtraDetailsSecondaryTeam,

    /// (no description).
    DBTEAMLOGTeamMergeRequestExpiredExtraDetailsOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMLOGTeamMergeRequestExpiredExtraDetailsTag tag;

/// Team merge request canceled details shown to the primary team. @note Ensure
/// the `isPrimaryTeam` method returns true before accessing, otherwise a
/// runtime exception will be raised.
@property (nonatomic, readonly) DBTEAMLOGPrimaryTeamRequestExpiredDetails *primaryTeam;

/// Team merge request canceled details shown to the secondary team. @note
/// Ensure the `isSecondaryTeam` method returns true before accessing, otherwise
/// a runtime exception will be raised.
@property (nonatomic, readonly) DBTEAMLOGSecondaryTeamRequestExpiredDetails *secondaryTeam;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "primary_team".
///
/// Description of the "primary_team" tag state: Team merge request canceled
/// details shown to the primary team.
///
/// @param primaryTeam Team merge request canceled details shown to the primary
/// team.
///
/// @return An initialized instance.
///
- (instancetype)initWithPrimaryTeam:(DBTEAMLOGPrimaryTeamRequestExpiredDetails *)primaryTeam;

///
/// Initializes union class with tag state of "secondary_team".
///
/// Description of the "secondary_team" tag state: Team merge request canceled
/// details shown to the secondary team.
///
/// @param secondaryTeam Team merge request canceled details shown to the
/// secondary team.
///
/// @return An initialized instance.
///
- (instancetype)initWithSecondaryTeam:(DBTEAMLOGSecondaryTeamRequestExpiredDetails *)secondaryTeam;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "primary_team".
///
/// @note Call this method and ensure it returns true before accessing the
/// `primaryTeam` property, otherwise a runtime exception will be thrown.
///
/// @return Whether the union's current tag state has value "primary_team".
///
- (BOOL)isPrimaryTeam;

///
/// Retrieves whether the union's current tag state has value "secondary_team".
///
/// @note Call this method and ensure it returns true before accessing the
/// `secondaryTeam` property, otherwise a runtime exception will be thrown.
///
/// @return Whether the union's current tag state has value "secondary_team".
///
- (BOOL)isSecondaryTeam;

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
/// The serialization class for the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` union.
///
@interface DBTEAMLOGTeamMergeRequestExpiredExtraDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGTeamMergeRequestExpiredExtraDetails *)instance;

///
/// Deserializes `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` API object.
///
/// @return An instantiation of the
/// `DBTEAMLOGTeamMergeRequestExpiredExtraDetails` object.
///
+ (DBTEAMLOGTeamMergeRequestExpiredExtraDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END