///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

/// Arguments, results, and errors for the `SeenState` namespace.

#import "DBSEENSTATEPlatformType.h"
#import "DBStoneSerializers.h"
#import "DBStoneValidators.h"

#pragma mark - API Object

@implementation DBSEENSTATEPlatformType

#pragma mark - Constructors

- (instancetype)initWithWeb {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeWeb;
  }
  return self;
}

- (instancetype)initWithDesktop {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeDesktop;
  }
  return self;
}

- (instancetype)initWithMobileIos {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeMobileIos;
  }
  return self;
}

- (instancetype)initWithMobileAndroid {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeMobileAndroid;
  }
  return self;
}

- (instancetype)initWithApi {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeApi;
  }
  return self;
}

- (instancetype)initWithUnknown {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeUnknown;
  }
  return self;
}

- (instancetype)initWithMobile {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeMobile;
  }
  return self;
}

- (instancetype)initWithOther {
  self = [super init];
  if (self) {
    _tag = DBSEENSTATEPlatformTypeOther;
  }
  return self;
}

#pragma mark - Instance field accessors

#pragma mark - Tag state methods

- (BOOL)isWeb {
  return _tag == DBSEENSTATEPlatformTypeWeb;
}

- (BOOL)isDesktop {
  return _tag == DBSEENSTATEPlatformTypeDesktop;
}

- (BOOL)isMobileIos {
  return _tag == DBSEENSTATEPlatformTypeMobileIos;
}

- (BOOL)isMobileAndroid {
  return _tag == DBSEENSTATEPlatformTypeMobileAndroid;
}

- (BOOL)isApi {
  return _tag == DBSEENSTATEPlatformTypeApi;
}

- (BOOL)isUnknown {
  return _tag == DBSEENSTATEPlatformTypeUnknown;
}

- (BOOL)isMobile {
  return _tag == DBSEENSTATEPlatformTypeMobile;
}

- (BOOL)isOther {
  return _tag == DBSEENSTATEPlatformTypeOther;
}

- (NSString *)tagName {
  switch (_tag) {
  case DBSEENSTATEPlatformTypeWeb:
    return @"DBSEENSTATEPlatformTypeWeb";
  case DBSEENSTATEPlatformTypeDesktop:
    return @"DBSEENSTATEPlatformTypeDesktop";
  case DBSEENSTATEPlatformTypeMobileIos:
    return @"DBSEENSTATEPlatformTypeMobileIos";
  case DBSEENSTATEPlatformTypeMobileAndroid:
    return @"DBSEENSTATEPlatformTypeMobileAndroid";
  case DBSEENSTATEPlatformTypeApi:
    return @"DBSEENSTATEPlatformTypeApi";
  case DBSEENSTATEPlatformTypeUnknown:
    return @"DBSEENSTATEPlatformTypeUnknown";
  case DBSEENSTATEPlatformTypeMobile:
    return @"DBSEENSTATEPlatformTypeMobile";
  case DBSEENSTATEPlatformTypeOther:
    return @"DBSEENSTATEPlatformTypeOther";
  }

  @throw([NSException exceptionWithName:@"InvalidTag" reason:@"Tag has an unknown value." userInfo:nil]);
}

#pragma mark - Serialization methods

+ (nullable NSDictionary<NSString *, id> *)serialize:(id)instance {
  return [DBSEENSTATEPlatformTypeSerializer serialize:instance];
}

+ (id)deserialize:(NSDictionary<NSString *, id> *)dict {
  return [DBSEENSTATEPlatformTypeSerializer deserialize:dict];
}

#pragma mark - Debug Description method

- (NSString *)debugDescription {
  return [[DBSEENSTATEPlatformTypeSerializer serialize:self] description];
}

#pragma mark - Copyable method

- (instancetype)copyWithZone:(NSZone *)zone {
#pragma unused(zone)
  /// object is immutable
  return self;
}

#pragma mark - Hash method

- (NSUInteger)hash {
  NSUInteger prime = 31;
  NSUInteger result = 1;

  switch (_tag) {
  case DBSEENSTATEPlatformTypeWeb:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeDesktop:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeMobileIos:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeMobileAndroid:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeApi:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeUnknown:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeMobile:
    result = prime * result + [[self tagName] hash];
    break;
  case DBSEENSTATEPlatformTypeOther:
    result = prime * result + [[self tagName] hash];
    break;
  }

  return prime * result;
}

#pragma mark - Equality method

- (BOOL)isEqual:(id)other {
  if (other == self) {
    return YES;
  }
  if (!other || ![other isKindOfClass:[self class]]) {
    return NO;
  }
  return [self isEqualToPlatformType:other];
}

- (BOOL)isEqualToPlatformType:(DBSEENSTATEPlatformType *)aPlatformType {
  if (self == aPlatformType) {
    return YES;
  }
  if (self.tag != aPlatformType.tag) {
    return NO;
  }
  switch (_tag) {
  case DBSEENSTATEPlatformTypeWeb:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeDesktop:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeMobileIos:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeMobileAndroid:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeApi:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeUnknown:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeMobile:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  case DBSEENSTATEPlatformTypeOther:
    return [[self tagName] isEqual:[aPlatformType tagName]];
  }
  return YES;
}

@end

#pragma mark - Serializer Object

@implementation DBSEENSTATEPlatformTypeSerializer

+ (NSDictionary<NSString *, id> *)serialize:(DBSEENSTATEPlatformType *)valueObj {
  NSMutableDictionary *jsonDict = [[NSMutableDictionary alloc] init];

  if ([valueObj isWeb]) {
    jsonDict[@".tag"] = @"web";
  } else if ([valueObj isDesktop]) {
    jsonDict[@".tag"] = @"desktop";
  } else if ([valueObj isMobileIos]) {
    jsonDict[@".tag"] = @"mobile_ios";
  } else if ([valueObj isMobileAndroid]) {
    jsonDict[@".tag"] = @"mobile_android";
  } else if ([valueObj isApi]) {
    jsonDict[@".tag"] = @"api";
  } else if ([valueObj isUnknown]) {
    jsonDict[@".tag"] = @"unknown";
  } else if ([valueObj isMobile]) {
    jsonDict[@".tag"] = @"mobile";
  } else if ([valueObj isOther]) {
    jsonDict[@".tag"] = @"other";
  } else {
    jsonDict[@".tag"] = @"other";
  }

  return [jsonDict count] > 0 ? jsonDict : nil;
}

+ (DBSEENSTATEPlatformType *)deserialize:(NSDictionary<NSString *, id> *)valueDict {
  NSString *tag = valueDict[@".tag"];

  if ([tag isEqualToString:@"web"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithWeb];
  } else if ([tag isEqualToString:@"desktop"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithDesktop];
  } else if ([tag isEqualToString:@"mobile_ios"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithMobileIos];
  } else if ([tag isEqualToString:@"mobile_android"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithMobileAndroid];
  } else if ([tag isEqualToString:@"api"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithApi];
  } else if ([tag isEqualToString:@"unknown"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithUnknown];
  } else if ([tag isEqualToString:@"mobile"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithMobile];
  } else if ([tag isEqualToString:@"other"]) {
    return [[DBSEENSTATEPlatformType alloc] initWithOther];
  } else {
    return [[DBSEENSTATEPlatformType alloc] initWithOther];
  }
}

@end
