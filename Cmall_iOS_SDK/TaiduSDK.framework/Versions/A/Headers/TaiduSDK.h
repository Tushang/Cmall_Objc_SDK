//
//  TaiduSDK.h
//  Cmall
//
//  Created by Moyun on 2017/9/7.
//  Copyright © 2017 Taidu. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 态度SDK错误码

 - TDTaiduSDKErrorTypeNotFoundMoudle: 点击态度视图时，无响应。
 - TDTaiduSDKErrorTypeAbsenceSource: 调用态度SDK的编辑预览方法时，缺少资源图。
 - TDTaiduSDKErrorTypeRendingError: 态度视图渲染失败
 - TDTaiduSDKErrorTypeParamsError: 提供给态度视图的参数错误
 - TDTaiduSDKErrorTypeNetworkError: 网络错误
 - TDTaiduSDKErrorTypeInterfaceParamError: 接口响应数据有误
 */
typedef NS_ENUM(NSInteger,TDTaiduSDKErrorType) {
    TDTaiduSDKErrorTypeNotFoundMoudle = 3001,
    TDTaiduSDKErrorTypeAbsenceSource = 3002,
    TDTaiduSDKErrorTypeRendingError = 3003,
    
    TDTaiduSDKErrorTypeParamsError = 3011,
    TDTaiduSDKErrorTypeNetworkError = 3012,
    TDTaiduSDKErrorTypeInterfaceParamError = 3013,
};

/**
 态度 一家专做定制的平台 SDK
 */
@interface TaiduSDK : NSObject

/**
 SDK 版本

 @return NSString 版本号
 */
+ (NSString *_Nullable)td_version;

/**
 注册SDK

 @param appId 应用ID
 @param appSecret 应用秘钥
 */
+ (void)startWithAppId:(NSString *_Nonnull)appId appSecret:(NSString *_Nonnull)appSecret;

/**
 态度 SDK 环境
 
 @param isOnline true是线上环境，false是开发环境。默认false
 */
+ (void)td_setEnvironmentOfOnline:(BOOL)isOnline;



@end
