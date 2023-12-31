///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGUndoOrganizeFolderWithTidyDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `UndoOrganizeFolderWithTidyDetails` struct.
///
/// Removed multi-file organize.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGUndoOrganizeFolderWithTidyDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @return An initialized instance.
///
- (instancetype)initDefault;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `UndoOrganizeFolderWithTidyDetails` struct.
///
@interface DBTEAMLOGUndoOrganizeFolderWithTidyDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGUndoOrganizeFolderWithTidyDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGUndoOrganizeFolderWithTidyDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGUndoOrganizeFolderWithTidyDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGUndoOrganizeFolderWithTidyDetails *)instance;

///
/// Deserializes `DBTEAMLOGUndoOrganizeFolderWithTidyDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGUndoOrganizeFolderWithTidyDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGUndoOrganizeFolderWithTidyDetails`
/// object.
///
+ (DBTEAMLOGUndoOrganizeFolderWithTidyDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
