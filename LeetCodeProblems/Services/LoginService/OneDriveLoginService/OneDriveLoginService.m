//
//  OneDriveLoginService.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 28.07.23.
//

#import "OneDriveLoginService.h"
#import "UserProfileData.h"
#import <UIKit/UIKit.h>
#import <MSAL/MSAL.h>
@interface OneDriveLoginService()
{
    NSString* kAuthority;
    NSString* kClientId;
    NSArray<NSString *> *scopes;
}
@end;

@implementation OneDriveLoginService

@synthesize userData;

-(instancetype) init;
{
    self = [super init];
    if(self) {
        kAuthority  = @"https://login.microsoftonline.com/common";
        kClientId = @"fdacb5ee-77bd-40d8-ba22-c2d48749f92a";
        scopes = @[@"files.readwrite.all"];
    }
    return nil;
}

-(MSALPublicClientApplication*)createClientApplication {
    NSURL* url = [[NSURL alloc] initWithString:kAuthority];
    if(url == nil) {
        NSLog(@"Can't create url from %@",kAuthority);
        return nil;
    }
    NSError * err = nil;
    MSALAADAuthority* authority = [[MSALAADAuthority alloc]initWithURL:url error:&err];
    if(authority == nil) {
        NSLog(@"Can't create authority with error %@",[err localizedDescription]);
        return nil;
    }
    MSALPublicClientApplicationConfig* config = [[MSALPublicClientApplicationConfig alloc] initWithClientId:kClientId redirectUri:nil authority:authority];
    if(config == nil) {
        NSLog(@"Can't configure client with id %@",kClientId);
        return nil;
    }
    MSALPublicClientApplication* application = [[MSALPublicClientApplication alloc] initWithConfiguration:config error:&err];
    if(application == nil) {
        NSLog(@"Can't create application with error %@",[err localizedDescription]);
        return nil;
    }
    return application;
}

-(MSALAccount*) currentAccount {
    if(userData == nil || userData.userID == nil) {
        return nil;
    }
    MSALPublicClientApplication* application = [self createClientApplication];
    if(application == nil) {
        NSLog(@"Can't get application");
        return nil;
    }
    NSError * err = nil;
    MSALAccount* account = [application accountForIdentifier:userData.userID error:&err];
    if(account == nil) {
        NSLog(@"Can't get account with dentifier %@. Error %@",userData.userID, [err localizedDescription]);
        return nil;
    }
    return account;
}

- (BOOL)shareUrl:(nonnull NSURL *)url withKey:(nullable NSString *)key {
    return [MSALPublicClientApplication handleMSALResponse:url
                                             sourceApplication: key];
}

- (void)signIn {
    MSALPublicClientApplication* application = [self createClientApplication];
    if(application == nil) {
        NSLog(@"Can't get application");
    }
    UIViewController* controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    if(controller == nil) {
        NSLog(@"Can't get root controller");
    }
    while (controller.presentedViewController) {
            controller = controller.presentedViewController;
    }
    MSALWebviewParameters *webParameters = [[MSALWebviewParameters alloc] initWithAuthPresentationViewController:controller];
    MSALInteractiveTokenParameters *interactiveParams = [[MSALInteractiveTokenParameters alloc] initWithScopes:scopes webviewParameters:webParameters];
    [application acquireTokenWithParameters:interactiveParams completionBlock:^(MSALResult * _Nullable result, NSError * _Nullable error) {
                if (error != nil)
                {
                    if(result != nil) {
                        NSString *accountIdentifier = result.account.identifier;
                        NSString *accessToken = result.accessToken;
                    } else {
                        NSLog(@"Can't login into application");
                    }
                }
                else
                {
                    NSLog(@"Can't login into application with error %@",[error localizedDescription]);
                }
    }];
}

- (void)signOut {
    MSALAccount* account = [self currentAccount];
    if(account == nil) {
        NSLog(@"Can't get account");
        return;
    }
    MSALPublicClientApplication* application = [self createClientApplication];
    if(application == nil) {
        NSLog(@"Can't get application");
        return;
    }
    UIViewController* controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    if(controller == nil) {
        NSLog(@"Can't get root controller");
        return;
    }
    while (controller.presentedViewController) {
            controller = controller.presentedViewController;
    }
    MSALWebviewParameters *webParameters = [[MSALWebviewParameters alloc] initWithAuthPresentationViewController:controller];
    MSALSignoutParameters* signOutParameters = [[MSALSignoutParameters alloc]initWithWebviewParameters:webParameters];
    [signOutParameters setSignoutFromBrowser:NO];
    [application signoutWithAccount:account signoutParameters:signOutParameters completionBlock:^(BOOL success, NSError * _Nullable error)
    {
        if (success == NO || error != nil)
        {
            // Signout failed
            return;
        }
                
        // Sign out completed successfully
    }];
}

@end
