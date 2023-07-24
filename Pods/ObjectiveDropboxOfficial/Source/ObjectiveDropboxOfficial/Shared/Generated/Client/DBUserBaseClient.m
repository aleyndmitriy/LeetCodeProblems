///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import "DBUserBaseClient.h"
#import "DBACCOUNTUserAuthRoutes.h"
#import "DBAUTHUserAuthRoutes.h"
#import "DBCHECKUserAuthRoutes.h"
#import "DBCONTACTSUserAuthRoutes.h"
#import "DBFILEPROPERTIESUserAuthRoutes.h"
#import "DBFILEREQUESTSUserAuthRoutes.h"
#import "DBFILESUserAuthRoutes.h"
#import "DBOPENIDUserAuthRoutes.h"
#import "DBPAPERUserAuthRoutes.h"
#import "DBSHARINGUserAuthRoutes.h"
#import "DBTransportClientProtocol.h"
#import "DBUSERSUserAuthRoutes.h"

@implementation DBUserBaseClient

- (instancetype)initWithTransportClient:(id<DBTransportClient>)client {
  self = [super init];
  if (self) {
    _transportClient = client;
    _accountRoutes = [[DBACCOUNTUserAuthRoutes alloc] init:client];
    _authRoutes = [[DBAUTHUserAuthRoutes alloc] init:client];
    _checkRoutes = [[DBCHECKUserAuthRoutes alloc] init:client];
    _contactsRoutes = [[DBCONTACTSUserAuthRoutes alloc] init:client];
    _filePropertiesRoutes = [[DBFILEPROPERTIESUserAuthRoutes alloc] init:client];
    _fileRequestsRoutes = [[DBFILEREQUESTSUserAuthRoutes alloc] init:client];
    _filesRoutes = [[DBFILESUserAuthRoutes alloc] init:client];
    _openidRoutes = [[DBOPENIDUserAuthRoutes alloc] init:client];
    _paperRoutes = [[DBPAPERUserAuthRoutes alloc] init:client];
    _sharingRoutes = [[DBSHARINGUserAuthRoutes alloc] init:client];
    _usersRoutes = [[DBUSERSUserAuthRoutes alloc] init:client];
  }
  return self;
}
@end