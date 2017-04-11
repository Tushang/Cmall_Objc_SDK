//
//  TudeSDK.h
//  TudeSDK version 1.0
//
//  Created by Moyun on 2017/3/24.
//
//  Copyright (c) 2017 Cmall. All rights reserved.

#import <UIKit/UIKit.h>

@interface CmallSDK : NSObject

/**
 SDK初始化方法,clientId和clientSecret在Cmall开放平台申请
 
 @param clientId 在开放平台注册应用分配的clientId
 @param clientSecret 在开放平台注册应用分配的clientSecret
 */
+ (void)startWithClientId:(NSString*_Nonnull)clientId
             clientSecret:(NSString*_Nonnull)clientSecret;

/**
 SDK初始化方法,clientId和clientSecret在Cmall开放平台申请
 
 @param clientId 在开放平台注册应用分配的clientId
 @param clientSecret 在开放平台注册应用分配的clientSecret
 @param redirectUri 非必填项，默认：https://www.cmall.com/redirect
 @param nonceString 非必填项，默认：TudeNonce
 */
+ (void)startWithClientId:(NSString*_Nonnull)clientId
             clientSecret:(NSString*_Nonnull)clientSecret
           redirectUri:(NSString*_Nullable)redirectUri
             nonceString:(NSString*_Nullable)nonceString;

/** 设置是否打印log信息, 默认NO(不打印log).
 @param value 设置为YES,会输出log信息可供调试参考,建议在发布的时候改为No
 @return void.
 */
+ (void)setLogEnabled:(BOOL)value;

/**
 设置你的app所用的图片域名前缀prefix。
 例如：
     https://image.cmall.com/imgsrv/hahha/heihei/123456765432.jpg
     prefix为：https://image.cmall.com/imgsrv
 @param prefix 图片域名前缀。默认为官方前缀：https://image.cmall.com/imgsrv
 */
+ (void)setImagePrefix:(NSString*_Nonnull)prefix;

/**
 进入SDK前必须调用该方法，否则将会使用 【测试】 图片体验流程。

 @param imageUrl 图片Url,未加前缀的url将会拼接图片前缀 ImagePrefix
            传入的图片URL必须要有跨域标识.如：
                 Access-Control-Allow-Headers:X-Requested-With
                 Access-Control-Allow-Methods:GET,POST,OPTIONS
                 Access-Control-Allow-Origin:*
 @param imageWidth 图片宽度，非必填
 @param imageHeight 图片高度，非必填
 */
+ (void)setInitImageUrl:(NSString*_Nonnull)imageUrl imageWidth:(CGFloat)imageWidth imageHeight:(CGFloat)imageHeight;

/**
 开启自动套版之旅

 @param curViewController curViewController
 */
+ (void)showAutoListViewControllerWithCurrentViewController:(UIViewController*_Nonnull)curViewController;

/**
 点击【立即购买】操作后获取相关数据
 
 @param callBack uploadImages对应上述给出的例子， modelJson可以在开放平台下单接口里找到相关信息。
         uploadImages：需要你的app上传到你自己服务器的图片数组，有多个，数据格式如下：
             {
                 "preview3dImage":{
                     "image":image
                     "uploadKey":"http://demoimage.tude.com/new/diy/tude_14903486860753456.jpe/png"
                 }
                 "nodes":[
                     {
                         "image":image
                         "uploadKey":"http://demoimage.tude.com/new/diy/tude_14903486860753456.jpe/png"
                     },
                     {
                         "image":image
                         "uploadKey":"http://demoimage.tude.com/new/diy/_tude_DDFTD-YTREW-HGRE-UYTRE/L0/01_tude_.jpe/png"
                     },
                 ]
             }
         modelJson：你下单时需要用的modelJson字段的值，详见开放平台上的下单接口。
         editFace：第三方忽略次字段。
 */
+ (void)setBuyNowCallBack:(void (^_Nullable)(NSDictionary* _Nonnull uploadImages,NSString* _Nonnull modelJson, NSString * _Nullable editFace))callBack;

/**
 可自己定义加载样式，如果未实现该方法，默认使用SDK提供的加载样式

 @param show show
 */
+ (void)showWithUserDefined:(void (^_Nullable) (NSInteger code, NSString * _Nullable infoDes))show;

/**
 自定义关闭加载样式，须和showWithUserDefined成对出现

 @param dismiss dismiss
 */
+ (void)dismissWithUserDefined:(void (^_Nullable) (void))dismiss;

/**
 sdk普通错误回调

 @param callBack 包括：错误码、错误描述 详见TDError.h
 */
+ (void)setNormalErrorCallBack:(void (^_Nullable)(NSInteger code,NSString* _Nullable errorDesc,NSDictionary * _Nullable errInfo))callBack;

/**
 清除缓存
 */
+ (void)cleanCache;

/**
 定制页面 提供第三方添加自定义字体， 
 例如：
     添加Daniel.otf,并把它放在mainBundle下
         NSMutableArray *paths = [NSMutableArray array];
         NSString *fontFilePath = [[NSBundle mainBundle] pathForResource:@"Daniel" ofType:@"otf"];
         [paths addObject:fontFilePath];
         if (paths) {
            [TudeSDK registerFontWithFilePaths:[paths copy]];
         }
 */
+ (void)registerFontWithFilePaths:(NSArray<NSString*>*_Nonnull)paths;


@end
