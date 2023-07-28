//
//  AppDelegate.m
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 31.03.23.
//

#import "AppDelegate.h"

#import "LoginViewModuleInitializer.h"
#import "LoginViewController.h"
NSString* appIdYandexClientId = @"fe3f41ba6aff4b8180ea470cc43f9805";
NSString* appIdDropBoxClientId = @"0x1vbxaklvuouqb";
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc]initWithFrame:[[UIScreen mainScreen]bounds]];
    UINavigationController* navController = [[UINavigationController alloc]init];
    self.window.rootViewController = navController;
   // CFURLRef ref = CFCopyHomeDirectoryURL();
    @try {
        LoginViewController* controller = [LoginViewModuleInitializer createLoginViewController];
        NSError* initError = nil;
        [YXLSdk.shared activateWithAppId:appIdYandexClientId error:&initError];
        NSLog(@"Error\nName-> %@\nDescription-> %@", [initError localizedRecoverySuggestion],
                [initError localizedDescription]);
        [DBClientsManager setupWithAppKey:appIdDropBoxClientId];
        [navController pushViewController:controller animated:YES];
        } @catch (NSException *exception) {
            NSLog(@"EXCEPTION\nName-> %@\nDescription-> %@", [exception name],
                    [exception description]);
        } @finally {
            return YES;
        }
}

-(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler
{
    [YXLSdk.shared processUserActivity:userActivity];
    return YES;
}

-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    NSString* key = options[UIApplicationOpenURLOptionsSourceApplicationKey];
    if([YXLSdk.shared handleOpenURL:url sourceApplication:key]) {
        NSLog(@"This URL is handled by Yandex");
    }
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
    if([DBClientsManager handleRedirectURL:url completion:completion]) {
        NSLog(@"This URL is handled by DropBox");
    }
    return YES;
}
#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options  API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)){
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions  API_AVAILABLE(ios(13.0)){
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
