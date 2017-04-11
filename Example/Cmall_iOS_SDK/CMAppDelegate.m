//
//  CMAppDelegate.m
//  Cmall_iOS_SDK
//
//  Created by momo605654602@gmail.com on 04/10/2017.
//  Copyright (c) 2017 momo605654602@gmail.com. All rights reserved.
//

#import "CMAppDelegate.h"
#import <CmallSDK/CmallSDK.h>

@implementation CMAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [CmallSDK startWithClientId:@"d83fcd1f-2ad8-41b5-981d-3342548c768e" clientSecret:@"0927150e-64fd-4191-85c2-b9b5c34d5a17"];
    
    // 开启SDK的日志打印
    [CmallSDK setLogEnabled:true];
    
    // 添加SDK内部定制界面的自定义字体方式
    NSArray *filePaths = @[@"BrushScriptStd.ttf",@"Daniel.otf"];
    NSMutableArray *paths = [NSMutableArray arrayWithCapacity:filePaths.count];
    for (NSString *filePath in filePaths) {
        NSString *fontFilePath = [[NSBundle mainBundle] pathForResource:filePath ofType:nil];
        [paths addObject:fontFilePath];
    }
    if (paths) {
        [CmallSDK registerFontWithFilePaths:[paths copy]];
    }
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
