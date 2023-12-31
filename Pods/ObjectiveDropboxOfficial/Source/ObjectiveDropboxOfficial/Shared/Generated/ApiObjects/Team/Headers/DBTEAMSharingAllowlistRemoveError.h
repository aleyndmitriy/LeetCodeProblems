///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMSharingAllowlistRemoveError;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharingAllowlistRemoveError` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMSharingAllowlistRemoveError : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMSharingAllowlistRemoveErrorTag` enum type represents the possible
/// tag states with which the `DBTEAMSharingAllowlistRemoveError` union can
/// exist.
typedef NS_CLOSED_ENUM(NSInteger, DBTEAMSharingAllowlistRemoveErrorTag){
    /// One of provided values is not valid.
    DBTEAMSharingAllowlistRemoveErrorMalformedEntry,

    /// One or more provided values do not exist.
    DBTEAMSharingAllowlistRemoveErrorEntriesDoNotExist,

    /// Neither single domain nor email provided.
    DBTEAMSharingAllowlistRemoveErrorNoEntriesProvided,

    /// Too many entries provided within one call.
    DBTEAMSharingAllowlistRemoveErrorTooManyEntriesProvided,

    /// Unknown error.
    DBTEAMSharingAllowlistRemoveErrorUnknownError,

    /// (no description).
    DBTEAMSharingAllowlistRemoveErrorOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMSharingAllowlistRemoveErrorTag tag;

/// One of provided values is not valid. @note Ensure the `isMalformedEntry`
/// method returns true before accessing, otherwise a runtime exception will be
/// raised.
@property (nonatomic, readonly, copy) NSString *malformedEntry;

/// One or more provided values do not exist. @note Ensure the
/// `isEntriesDoNotExist` method returns true before accessing, otherwise a
/// runtime exception will be raised.
@property (nonatomic, readonly, copy) NSString *entriesDoNotExist;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "malformed_entry".
///
/// Description of the "malformed_entry" tag state: One of provided values is
/// not valid.
///
/// @param malformedEntry One of provided values is not valid.
///
/// @return An initialized instance.
///
- (instancetype)initWithMalformedEntry:(NSString *)malformedEntry;

///
/// Initializes union class with tag state of "entries_do_not_exist".
///
/// Description of the "entries_do_not_exist" tag state: One or more provided
/// values do not exist.
///
/// @param entriesDoNotExist One or more provided values do not exist.
///
/// @return An initialized instance.
///
- (instancetype)initWithEntriesDoNotExist:(NSString *)entriesDoNotExist;

///
/// Initializes union class with tag state of "no_entries_provided".
///
/// Description of the "no_entries_provided" tag state: Neither single domain
/// nor email provided.
///
/// @return An initialized instance.
///
- (instancetype)initWithNoEntriesProvided;

///
/// Initializes union class with tag state of "too_many_entries_provided".
///
/// Description of the "too_many_entries_provided" tag state: Too many entries
/// provided within one call.
///
/// @return An initialized instance.
///
- (instancetype)initWithTooManyEntriesProvided;

///
/// Initializes union class with tag state of "unknown_error".
///
/// Description of the "unknown_error" tag state: Unknown error.
///
/// @return An initialized instance.
///
- (instancetype)initWithUnknownError;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "malformed_entry".
///
/// @note Call this method and ensure it returns true before accessing the
/// `malformedEntry` property, otherwise a runtime exception will be thrown.
///
/// @return Whether the union's current tag state has value "malformed_entry".
///
- (BOOL)isMalformedEntry;

///
/// Retrieves whether the union's current tag state has value
/// "entries_do_not_exist".
///
/// @note Call this method and ensure it returns true before accessing the
/// `entriesDoNotExist` property, otherwise a runtime exception will be thrown.
///
/// @return Whether the union's current tag state has value
/// "entries_do_not_exist".
///
- (BOOL)isEntriesDoNotExist;

///
/// Retrieves whether the union's current tag state has value
/// "no_entries_provided".
///
/// @return Whether the union's current tag state has value
/// "no_entries_provided".
///
- (BOOL)isNoEntriesProvided;

///
/// Retrieves whether the union's current tag state has value
/// "too_many_entries_provided".
///
/// @return Whether the union's current tag state has value
/// "too_many_entries_provided".
///
- (BOOL)isTooManyEntriesProvided;

///
/// Retrieves whether the union's current tag state has value "unknown_error".
///
/// @return Whether the union's current tag state has value "unknown_error".
///
- (BOOL)isUnknownError;

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
/// The serialization class for the `DBTEAMSharingAllowlistRemoveError` union.
///
@interface DBTEAMSharingAllowlistRemoveErrorSerializer : NSObject

///
/// Serializes `DBTEAMSharingAllowlistRemoveError` instances.
///
/// @param instance An instance of the `DBTEAMSharingAllowlistRemoveError` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMSharingAllowlistRemoveError` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMSharingAllowlistRemoveError *)instance;

///
/// Deserializes `DBTEAMSharingAllowlistRemoveError` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMSharingAllowlistRemoveError` API object.
///
/// @return An instantiation of the `DBTEAMSharingAllowlistRemoveError` object.
///
+ (DBTEAMSharingAllowlistRemoveError *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
