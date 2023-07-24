///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLegalHoldsListHeldRevisionsContinueArg;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `LegalHoldsListHeldRevisionsContinueArg` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLegalHoldsListHeldRevisionsContinueArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The legal hold Id.
@property (nonatomic, readonly, copy) NSString *id_;

/// The cursor idicates where to continue reading file metadata entries for the
/// next API call. When there are no more entries, the cursor will return none.
@property (nonatomic, readonly, copy, nullable) NSString *cursor;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param id_ The legal hold Id.
/// @param cursor The cursor idicates where to continue reading file metadata
/// entries for the next API call. When there are no more entries, the cursor
/// will return none.
///
/// @return An initialized instance.
///
- (instancetype)initWithId_:(NSString *)id_ cursor:(nullable NSString *)cursor;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param id_ The legal hold Id.
///
/// @return An initialized instance.
///
- (instancetype)initWithId_:(NSString *)id_;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `LegalHoldsListHeldRevisionsContinueArg`
/// struct.
///
@interface DBTEAMLegalHoldsListHeldRevisionsContinueArgSerializer : NSObject

///
/// Serializes `DBTEAMLegalHoldsListHeldRevisionsContinueArg` instances.
///
/// @param instance An instance of the
/// `DBTEAMLegalHoldsListHeldRevisionsContinueArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLegalHoldsListHeldRevisionsContinueArg` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLegalHoldsListHeldRevisionsContinueArg *)instance;

///
/// Deserializes `DBTEAMLegalHoldsListHeldRevisionsContinueArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLegalHoldsListHeldRevisionsContinueArg` API object.
///
/// @return An instantiation of the
/// `DBTEAMLegalHoldsListHeldRevisionsContinueArg` object.
///
+ (DBTEAMLegalHoldsListHeldRevisionsContinueArg *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
