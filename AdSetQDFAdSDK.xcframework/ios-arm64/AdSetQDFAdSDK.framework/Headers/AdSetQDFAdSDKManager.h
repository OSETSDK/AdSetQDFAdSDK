//
//  AdSetQDFAdSDKManager.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdSetQDFAdSDKManager : NSObject

/**
 * 启动SDK
 * @param appId - 开发者平台注册得到的appId
 * @param secretKey - 媒体密钥
 * @param handler - 启动成功|失败的结果回调
 * @note 请先调用initWithAppId:mediaId:secretKey接口，再调用startWithCompletionHandler接口。
 */
+ (void)startWithAppId: (NSString *)appId
             secretKey: (NSString *)secretKey
     completionHandler: (void(^)(BOOL success, NSError * _Nullable error))handler;

/**
 SDK版本号
 */
+ (NSString *)sdkVersion;


/**
 设置IDFA，请传原始值，不需要加密
 */
+ (void)setIdfa:(NSString *)idfa;

/**
 设置经纬度，请传入CLLocationManager获取的经纬度
 @param latitude 纬度
 @param longitude 经度
 */
+ (void)setLatitude:(NSString *)latitude longitude:(NSString *)longitude;

@end

NS_ASSUME_NONNULL_END
