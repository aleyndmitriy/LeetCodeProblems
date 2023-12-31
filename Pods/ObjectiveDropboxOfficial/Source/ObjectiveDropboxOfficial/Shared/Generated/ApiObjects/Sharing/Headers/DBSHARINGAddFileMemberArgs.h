///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBSHARINGAccessLevel;
@class DBSHARINGAddFileMemberArgs;
@class DBSHARINGMemberSelector;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `AddFileMemberArgs` struct.
///
/// Arguments for `addFileMember`.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBSHARINGAddFileMemberArgs : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// File to which to add members.
@property (nonatomic, readonly, copy) NSString *file;

/// Members to add. Note that even an email address is given, this may result in
/// a user being directly added to the membership if that email is the user's
/// main account email.
@property (nonatomic, readonly) NSArray<DBSHARINGMemberSelector *> *members;

/// Message to send to added members in their invitation.
@property (nonatomic, readonly, copy, nullable) NSString *customMessage;

/// Whether added members should be notified via email and device notifications
/// of their invitation.
@property (nonatomic, readonly) NSNumber *quiet;

/// AccessLevel union object, describing what access level we want to give new
/// members.
@property (nonatomic, readonly) DBSHARINGAccessLevel *accessLevel;

/// If the custom message should be added as a comment on the file.
@property (nonatomic, readonly) NSNumber *addMessageAsComment;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param file File to which to add members.
/// @param members Members to add. Note that even an email address is given,
/// this may result in a user being directly added to the membership if that
/// email is the user's main account email.
/// @param customMessage Message to send to added members in their invitation.
/// @param quiet Whether added members should be notified via email and device
/// notifications of their invitation.
/// @param accessLevel AccessLevel union object, describing what access level we
/// want to give new members.
/// @param addMessageAsComment If the custom message should be added as a
/// comment on the file.
///
/// @return An initialized instance.
///
- (instancetype)initWithFile:(NSString *)file
                     members:(NSArray<DBSHARINGMemberSelector *> *)members
               customMessage:(nullable NSString *)customMessage
                       quiet:(nullable NSNumber *)quiet
                 accessLevel:(nullable DBSHARINGAccessLevel *)accessLevel
         addMessageAsComment:(nullable NSNumber *)addMessageAsComment;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param file File to which to add members.
/// @param members Members to add. Note that even an email address is given,
/// this may result in a user being directly added to the membership if that
/// email is the user's main account email.
///
/// @return An initialized instance.
///
- (instancetype)initWithFile:(NSString *)file members:(NSArray<DBSHARINGMemberSelector *> *)members;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `AddFileMemberArgs` struct.
///
@interface DBSHARINGAddFileMemberArgsSerializer : NSObject

///
/// Serializes `DBSHARINGAddFileMemberArgs` instances.
///
/// @param instance An instance of the `DBSHARINGAddFileMemberArgs` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBSHARINGAddFileMemberArgs` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBSHARINGAddFileMemberArgs *)instance;

///
/// Deserializes `DBSHARINGAddFileMemberArgs` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBSHARINGAddFileMemberArgs` API object.
///
/// @return An instantiation of the `DBSHARINGAddFileMemberArgs` object.
///
+ (DBSHARINGAddFileMemberArgs *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
