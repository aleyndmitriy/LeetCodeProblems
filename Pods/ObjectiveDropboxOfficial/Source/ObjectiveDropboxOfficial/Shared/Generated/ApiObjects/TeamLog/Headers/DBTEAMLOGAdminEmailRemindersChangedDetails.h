///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGAdminEmailRemindersChangedDetails;
@class DBTEAMLOGAdminEmailRemindersPolicy;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `AdminEmailRemindersChangedDetails` struct.
///
/// Changed admin reminder settings for requests to join the team.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGAdminEmailRemindersChangedDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// To.
@property (nonatomic, readonly) DBTEAMLOGAdminEmailRemindersPolicy *dNewValue;

/// From.
@property (nonatomic, readonly) DBTEAMLOGAdminEmailRemindersPolicy *previousValue;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param dNewValue To.
/// @param previousValue From.
///
/// @return An initialized instance.
///
- (instancetype)initWithDNewValue:(DBTEAMLOGAdminEmailRemindersPolicy *)dNewValue
                    previousValue:(DBTEAMLOGAdminEmailRemindersPolicy *)previousValue;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `AdminEmailRemindersChangedDetails` struct.
///
@interface DBTEAMLOGAdminEmailRemindersChangedDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGAdminEmailRemindersChangedDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGAdminEmailRemindersChangedDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGAdminEmailRemindersChangedDetails` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBTEAMLOGAdminEmailRemindersChangedDetails *)instance;

///
/// Deserializes `DBTEAMLOGAdminEmailRemindersChangedDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGAdminEmailRemindersChangedDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGAdminEmailRemindersChangedDetails`
/// object.
///
+ (DBTEAMLOGAdminEmailRemindersChangedDetails *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
