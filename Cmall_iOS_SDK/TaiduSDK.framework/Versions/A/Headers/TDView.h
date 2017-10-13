//
//  TDView.h
//  Cmall
//
//  Created by Moyun on 2017/9/11.
//  Copyright © 2017 Taidu. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 态度 协议
 */
@protocol TDViewProtocol <NSObject>

/**
 点击态度视图，进行数据交互
 
 @param view 态度视图
 @param name 响应区域的唯一标识
 @param info 响应区域的初始信息，信息格式请咨询【态度SDK】开发人员。
 */
- (void)sdkView:(UIView*_Nonnull)view didClickMoudleWithName:(NSString*_Nonnull)name info:(NSDictionary*_Nonnull)info;

@optional

/**
 态度 SDK view 开始加载
 
 @param view 视图
 */
- (void)sdkViewDidStartLoad:(UIView*_Nonnull)view;

/**
 态度 SDK view 加载完成
 
 @param view 视图
 */
- (void)sdkViewDidFinishLoad:(UIView*_Nonnull)view;

/**
 态度 SDK view 加载失败
 
 @param view 视图
 @param error 错误信息，详见错误码
 */
- (void)sdkView:(UIView*_Nonnull)view didFailLoadWithError:(NSError*_Nonnull)error;


@end

FOUNDATION_EXTERN NSString * _Nonnull const kTDViewPreviewImageKey;
FOUNDATION_EXTERN NSString * _Nonnull const kTDViewThumbImageSuffixKey;

@interface TDView : UIView

@property (weak,  nonatomic) id <TDViewProtocol> _Nullable delegate;

- (instancetype  _Nonnull)initWithSkuniCode:(NSString *_Nonnull)skuniCode;

- (void)switchSkuWithSKUNicode:(NSString *_Nullable)skuniCode;

/**
 态度 编辑完成后，对模型贴图
 
 @param name 点击时获取的name
 @param image 编辑页截图
 @param modelJson 模型数据
 */
- (void)td_editFinishedWithName:(NSString*_Nonnull)name sourceImage:(UIImage*_Nonnull)image modelJson:(NSDictionary *_Nonnull)modelJson;

/**
 态度 SDK 提供正面截图，你可能需要上传的该图片，并应用于订单后者购物车列表里。
 请将此图片上传后，应用在 https://open.cmall.com/pages/openorder.html#data_orderpayback 中的【二、订单创建API】的参数【orderImage】键对应的值。
 
 @return NSDictionary 图片字典,其格式为{kTDViewPreviewImageKey:image}
 */
- (NSDictionary*_Nonnull)td_willUploadImages;

/**
 态度 SDK 提供下单参数中的 【tepComInfo】 键对应的值，使用时，请转成字符串。
 下单接口请参考：https://open.cmall.com/pages/openorder.html#data_orderpayback 中的【一、订单验证API】和【二、订单创建API】
 
 @param imageInfos 上传的图片的信息，其格式为{name:imageUrl,...},其中缩略图的key = name + kTDViewThumbImageSuffixKey,例如name = @"AABBCC" ,则 key = @"AABBCC%@",kTDViewThumbImageSuffixKey。原图的key = name 。
 @discuss 注意，这个地方的参数的key值必须严格按照规则写，否则会影响订单。
 @return NSDictionary 下单参数
 */
- (NSDictionary*_Nonnull)td_orderPramasWithUploadedImageInfos:(NSDictionary*_Nonnull)imageInfos;

/**
 态度 SDK 视图重新加载
 */
- (void)td_reload;

@end
