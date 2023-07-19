//
//  UserProfileData.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 13.04.23.
//

#import "UserProfileData.h"
#import "Utils.h"

@implementation UserProfileData

-(instancetype)initWithToken:(NSString* _Nonnull)token
{
    if(self = [super init]) {
        _accessToken = [token copy];
    }
    return self;
}

+(BOOL)supportsSecureCoding {
      return YES;
}
    
-(BOOL) isEqual:(id)object
{
    if(self == object) {
        return YES;
    }
    if([self class] != [object class]) {
        return NO;
    }
    UserProfileData* otherData = (UserProfileData*)object;
    if([_accessToken isEqualToString:otherData.accessToken]==NO) {
        return NO;
    }
    if(_serviceType != otherData.serviceType) {
        return NO;
    }
    
    if(_userID != nil && otherData.userID != nil && [_userID isEqualToString:otherData.userID]==NO){
        return NO;
    }
    if(_givenName != nil && otherData.givenName && [_givenName isEqualToString:otherData.givenName]==NO) {
        return NO;
    }
    if(_phone != nil && otherData.phone != nil && [_phone isEqualToString:otherData.phone]==NO) {
        return NO;
    }
    if(_email != nil && otherData.email != nil && [_email isEqualToString:otherData.email]==NO) {
        return NO;
    }
    if(_name != nil && otherData.name != nil && [_name isEqualToString:otherData.name]==NO) {
        return NO;
    }
    if(_familyName != nil && otherData.familyName != nil && [_familyName isEqualToString:otherData.familyName]==NO) {
        return NO;
    }
    return YES;
}

-(NSUInteger) hash {
    return [_accessToken hash];
}

- (nonnull instancetype)copyWithZone:(nullable NSZone *)zone {
    UserProfileData* userData = [[UserProfileData alloc]initWithToken:[_accessToken copy]];
    if(_userID != nil){
        userData->_userID = [_userID copy];
    }
    if(_givenName != nil){
        userData->_givenName = [_givenName copy];
    }
    if(_phone != nil){
        userData->_phone = [_phone copy];
    }
    if(_email != nil){
        userData->_email = [_email copy];
    }
    if(_name != nil){
        userData->_name = [_name copy];
    }
    if(_familyName != nil){
        userData->_familyName = [_familyName copy];
    }
    userData->_serviceType = _serviceType;
    return userData;
    
}

- (void)encodeWithCoder:(nonnull NSCoder *)coder {
    if(_userID != nil) {
        [coder encodeObject:_userID forKey:@"userID"];
    }
    if(_givenName != nil) {
        [coder encodeObject:_givenName forKey:@"givenName"];
    }
    if(_phone != nil) {
        [coder encodeObject:_phone forKey:@"phone"];
    }
    if(_email != nil) {
        [coder encodeObject:_email forKey:@"email"];
    }
    if(_name != nil) {
        [coder encodeObject:_name forKey:@"name"];
    }
    if(_familyName != nil) {
        [coder encodeObject:_familyName forKey:@"familyName"];
    }
    [coder encodeInteger:_serviceType forKey:@"serviceType"];
    [coder encodeObject:_accessToken forKey:@"accessToken"];
}

- (nullable instancetype)initWithCoder:(nonnull NSCoder *)coder {
    NSString* accessToken = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"accessToken"]);
    if(accessToken == nil) {
        return nil;
    }
    UserProfileData* userData = [[UserProfileData alloc] initWithToken:accessToken];
    userData.userID = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"userID"]);
    userData.givenName = convertToString([coder decodeObjectForKey:@"givenName"]);
    userData.phone = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"phone"]);
    userData.email = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"email"]);
    userData.name = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"name"]);
    userData.familyName = convertToString([coder decodeObjectOfClass:[NSString class] forKey:@"familyName"]);
    userData.serviceType = [coder decodeIntegerForKey:@"serviceType"];
    return userData;
}
    
@end
