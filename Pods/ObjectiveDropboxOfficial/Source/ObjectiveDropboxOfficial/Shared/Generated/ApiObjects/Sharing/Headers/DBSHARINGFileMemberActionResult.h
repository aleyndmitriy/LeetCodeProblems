///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBSHARINGFileMemberActionIndividualResult;
@class DBSHARINGFileMemberActionResult;
@class DBSHARINGMemberSelector;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `FileMemberActionResult` struct.
///
/// Per-member result for `addFileMember`.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBSHARINGFileMemberActionResult : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// One of specified input members.
@property (nonatomic, readonly) DBSHARINGMemberSelector *member;

/// The outcome of the action on this member.
@property (nonatomic, readonly) DBSHARINGFileMemberActionIndividualResult *result;

/// The SHA-1 encrypted shared content key.
@property (nonatomic, readonly, copy, nullable) NSString *sckeySha1;

/// The sharing sender-recipient invitation signatures for the input member_id.
/// A member_id can be a group and thus have multiple users and multiple
/// invitation signatures.
@property (nonatomic, readonly, nullable) NSArray<NSString *> *invitationSignature;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param member One of specified input members.
/// @param result The outcome of the action on this member.
/// @param sckeySha1 The SHA-1 encrypted shared content key.
/// @param invitationSignature The sharing sender-recipient invitation
/// signatures for the input member_id. A member_id can be a group and thus have
/// multiple users and multiple invitation signatures.
///
/// @return An initialized instance.
///
- (instancetype)initWithMember:(DBSHARINGMemberSelector *)member
                        result:(DBSHARINGFileMemberActionIndividualResult *)result
                     sckeySha1:(nullable NSString *)sckeySha1
           invitationSignature:(nullable NSArray<NSString *> *)invitationSignature;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param member One of specified input members.
/// @param result The outcome of the action on this member.
///
/// @return An initialized instance.
///
- (instancetype)initWithMember:(DBSHARINGMemberSelector *)member
                        result:(DBSHARINGFileMemberActionIndividualResult *)result;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `FileMemberActionResult` struct.
///
@interface DBSHARINGFileMemberActionResultSerializer : NSObject

///
/// Serializes `DBSHARINGFileMemberActionResult` instances.
///
/// @param instance An instance of the `DBSHARINGFileMemberActionResult` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBSHARINGFileMemberActionResult` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBSHARINGFileMemberActionResult *)instance;

///
/// Deserializes `DBSHARINGFileMemberActionResult` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBSHARINGFileMemberActionResult` API object.
///
/// @return An instantiation of the `DBSHARINGFileMemberActionResult` object.
///
+ (DBSHARINGFileMemberActionResult *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END