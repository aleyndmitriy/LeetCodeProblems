//
//  DropBoxLoginService.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.07.23.
//
#import <ObjectiveDropboxOfficial/ObjectiveDropboxOfficial.h>
#import <UIKit/UIKit.h>
#import "DropBoxLoginService.h"
#import "UserProfileData.h"
@interface DropBoxLoginService()
{
    NSArray<NSString *> *scopes;
}
@end;

@implementation DropBoxLoginService

@synthesize userData;

-(instancetype) init;
{
    self = [super init];
    if(self) {
        scopes = @[@"account_info.read", @"sharing.write", @"sharing.read", @"files.content.write", @"files.content.read"];
        return self;
    }
    return nil;
}

- (BOOL)shareUrl:(nonnull NSURL *)url withKey:(nullable NSString *)key {
    DBOAuthCompletion completion = ^(DBOAuthResult *authResult) {
        if (authResult != nil) {
          if ([authResult isSuccess]) {
            NSLog(@"\n\nSuccess! User is logged into Dropbox.\n\n");
          } else if ([authResult isCancel]) {
            NSLog(@"\n\nAuthorization flow was manually canceled by user!\n\n");
          } else if ([authResult isError]) {
            NSLog(@"\n\nError: %@\n\n", authResult);
          }
        }
      };
    return [DBClientsManager handleRedirectURL:url completion:completion];
}

- (void)signIn {
    DBScopeRequest *scopeRequest = [[DBScopeRequest alloc] initWithScopeType:DBScopeTypeUser
                                                                        scopes:scopes
                                                          includeGrantedScopes:NO];
    UIViewController* controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    if(controller == nil) {
        NSLog(@"Can't get root controller");
        return;
    }
    while (controller.presentedViewController) {
            controller = controller.presentedViewController;
    }
    NSDictionary<UIApplicationOpenURLOptionsKey,id> * dict = [NSDictionary dictionary];
    [DBClientsManager authorizeFromControllerV2:[UIApplication sharedApplication] controller:controller loadingStatusDelegate:nil openURL:^(NSURL * _Nonnull url) {
        [[UIApplication sharedApplication] openURL:url options:dict completionHandler:nil];
    } scopeRequest:scopeRequest];
}

- (void)signOut {
    [DBClientsManager unlinkAndResetClients];
}



@end
