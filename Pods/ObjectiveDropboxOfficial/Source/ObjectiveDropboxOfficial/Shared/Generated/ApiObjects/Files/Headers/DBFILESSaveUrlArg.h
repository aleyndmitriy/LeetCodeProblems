///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBFILESSaveUrlArg;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SaveUrlArg` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILESSaveUrlArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The path in Dropbox where the URL will be saved to.
@property (nonatomic, readonly, copy) NSString *path;

/// The URL to be saved.
@property (nonatomic, readonly, copy) NSString *url;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param path The path in Dropbox where the URL will be saved to.
/// @param url The URL to be saved.
///
/// @return An initialized instance.
///
- (instancetype)initWithPath:(NSString *)path url:(NSString *)url;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SaveUrlArg` struct.
///
@interface DBFILESSaveUrlArgSerializer : NSObject

///
/// Serializes `DBFILESSaveUrlArg` instances.
///
/// @param instance An instance of the `DBFILESSaveUrlArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILESSaveUrlArg` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBFILESSaveUrlArg *)instance;

///
/// Deserializes `DBFILESSaveUrlArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILESSaveUrlArg` API object.
///
/// @return An instantiation of the `DBFILESSaveUrlArg` object.
///
+ (DBFILESSaveUrlArg *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END