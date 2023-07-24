///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBSHARINGRelinquishFolderMembershipError;
@class DBSHARINGSharedFolderAccessError;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `RelinquishFolderMembershipError` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBSHARINGRelinquishFolderMembershipError : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBSHARINGRelinquishFolderMembershipErrorTag` enum type represents the
/// possible tag states with which the
/// `DBSHARINGRelinquishFolderMembershipError` union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBSHARINGRelinquishFolderMembershipErrorTag){
    /// (no description).
    DBSHARINGRelinquishFolderMembershipErrorAccessError,

    /// The current user is the owner of the shared folder. Owners cannot
    /// relinquish membership to their own folders. Try unsharing or
    /// transferring ownership first.
    DBSHARINGRelinquishFolderMembershipErrorFolderOwner,

    /// The shared folder is currently mounted.  Unmount the shared folder
    /// before relinquishing membership.
    DBSHARINGRelinquishFolderMembershipErrorMounted,

    /// The current user has access to the shared folder via a group.  You can't
    /// relinquish membership to folders shared via groups.
    DBSHARINGRelinquishFolderMembershipErrorGroupAccess,

    /// This action cannot be performed on a team shared folder.
    DBSHARINGRelinquishFolderMembershipErrorTeamFolder,

    /// The current user does not have permission to perform this action.
    DBSHARINGRelinquishFolderMembershipErrorNoPermission,

    /// The current user only has inherited access to the shared folder.  You
    /// can't relinquish inherited membership to folders.
    DBSHARINGRelinquishFolderMembershipErrorNoExplicitAccess,

    /// (no description).
    DBSHARINGRelinquishFolderMembershipErrorOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBSHARINGRelinquishFolderMembershipErrorTag tag;

/// (no description). @note Ensure the `isAccessError` method returns true
/// before accessing, otherwise a runtime exception will be raised.
@property (nonatomic, readonly) DBSHARINGSharedFolderAccessError *accessError;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "access_error".
///
/// @param accessError (no description).
///
/// @return An initialized instance.
///
- (instancetype)initWithAccessError:(DBSHARINGSharedFolderAccessError *)accessError;

///
/// Initializes union class with tag state of "folder_owner".
///
/// Description of the "folder_owner" tag state: The current user is the owner
/// of the shared folder. Owners cannot relinquish membership to their own
/// folders. Try unsharing or transferring ownership first.
///
/// @return An initialized instance.
///
- (instancetype)initWithFolderOwner;

///
/// Initializes union class with tag state of "mounted".
///
/// Description of the "mounted" tag state: The shared folder is currently
/// mounted.  Unmount the shared folder before relinquishing membership.
///
/// @return An initialized instance.
///
- (instancetype)initWithMounted;

///
/// Initializes union class with tag state of "group_access".
///
/// Description of the "group_access" tag state: The current user has access to
/// the shared folder via a group.  You can't relinquish membership to folders
/// shared via groups.
///
/// @return An initialized instance.
///
- (instancetype)initWithGroupAccess;

///
/// Initializes union class with tag state of "team_folder".
///
/// Description of the "team_folder" tag state: This action cannot be performed
/// on a team shared folder.
///
/// @return An initialized instance.
///
- (instancetype)initWithTeamFolder;

///
/// Initializes union class with tag state of "no_permission".
///
/// Description of the "no_permission" tag state: The current user does not have
/// permission to perform this action.
///
/// @return An initialized instance.
///
- (instancetype)initWithNoPermission;

///
/// Initializes union class with tag state of "no_explicit_access".
///
/// Description of the "no_explicit_access" tag state: The current user only has
/// inherited access to the shared folder.  You can't relinquish inherited
/// membership to folders.
///
/// @return An initialized instance.
///
- (instancetype)initWithNoExplicitAccess;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "access_error".
///
/// @note Call this method and ensure it returns true before accessing the
/// `accessError` property, otherwise a runtime exception will be thrown.
///
/// @return Whether the union's current tag state has value "access_error".
///
- (BOOL)isAccessError;

///
/// Retrieves whether the union's current tag state has value "folder_owner".
///
/// @return Whether the union's current tag state has value "folder_owner".
///
- (BOOL)isFolderOwner;

///
/// Retrieves whether the union's current tag state has value "mounted".
///
/// @return Whether the union's current tag state has value "mounted".
///
- (BOOL)isMounted;

///
/// Retrieves whether the union's current tag state has value "group_access".
///
/// @return Whether the union's current tag state has value "group_access".
///
- (BOOL)isGroupAccess;

///
/// Retrieves whether the union's current tag state has value "team_folder".
///
/// @return Whether the union's current tag state has value "team_folder".
///
- (BOOL)isTeamFolder;

///
/// Retrieves whether the union's current tag state has value "no_permission".
///
/// @return Whether the union's current tag state has value "no_permission".
///
- (BOOL)isNoPermission;

///
/// Retrieves whether the union's current tag state has value
/// "no_explicit_access".
///
/// @return Whether the union's current tag state has value
/// "no_explicit_access".
///
- (BOOL)isNoExplicitAccess;

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
/// The serialization class for the `DBSHARINGRelinquishFolderMembershipError`
/// union.
///
@interface DBSHARINGRelinquishFolderMembershipErrorSerializer : NSObject

///
/// Serializes `DBSHARINGRelinquishFolderMembershipError` instances.
///
/// @param instance An instance of the
/// `DBSHARINGRelinquishFolderMembershipError` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBSHARINGRelinquishFolderMembershipError` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBSHARINGRelinquishFolderMembershipError *)instance;

///
/// Deserializes `DBSHARINGRelinquishFolderMembershipError` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBSHARINGRelinquishFolderMembershipError` API object.
///
/// @return An instantiation of the `DBSHARINGRelinquishFolderMembershipError`
/// object.
///
+ (DBSHARINGRelinquishFolderMembershipError *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
