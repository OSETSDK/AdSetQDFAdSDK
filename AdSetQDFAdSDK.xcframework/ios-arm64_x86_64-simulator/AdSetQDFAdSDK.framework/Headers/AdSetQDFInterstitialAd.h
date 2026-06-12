//
//  AdSetQDFInterstitialAd.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdSetQDFAdSDK/AdSetQDFProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDFInterstitialAd;
@protocol AdSetQDFInterstitialAdDelegate <NSObject>
@optional

/// 插屏广告加载成功
- (void)AdSetQDF_interstitialAdLoadSuccess:(AdSetQDFInterstitialAd *)interstitialAd;

/// 插屏广告加载失败
- (void)AdSetQDF_interstitialAdLoadFail:(AdSetQDFInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏广告曝光
- (void)AdSetQDF_interstitialAdDidShow:(AdSetQDFInterstitialAd *)interstitialAd;

/// 插屏广告点击
- (void)AdSetQDF_interstitialAdDidClick:(AdSetQDFInterstitialAd *)interstitialAd;

/// 插屏广告关闭
- (void)AdSetQDF_interstitialAdDidClose:(AdSetQDFInterstitialAd *)interstitialAd;

/// 点击插屏广告以后即将弹出全屏广告页
- (void)AdSetQDF_interstitialAdWillPresentFullScreenModal:(AdSetQDFInterstitialAd *)interstitialAd;

/// 全屏广告页将要关闭
- (void)AdSetQDF_interstitialAdWillDismissFullScreenModal:(AdSetQDFInterstitialAd *)interstitialAd;

@end

@interface AdSetQDFInterstitialAd : NSObject<AdSetQDFProtocol>

/**
 *  委托对象
 */
@property (nonatomic, weak) id<AdSetQDFInterstitialAdDelegate> delegate;

@property (nonatomic, readonly) NSString *placementId;

/**
 *  构造方法
 *  详解：placementId - 广告位 ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 *  广告发起请求方法
 *  详解：[必选]发起拉取广告请求
 */
- (void)loadAdData;

/**
 *  广告展示方法
 *  详解：[必选]发起展示广告请求, 必须传入用于显示插播广告的UIViewController
 */

- (void)showFromViewController:(UIViewController *)viewController;

/**
 返回广告的eCPM，单位：分

 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;


@end

NS_ASSUME_NONNULL_END
