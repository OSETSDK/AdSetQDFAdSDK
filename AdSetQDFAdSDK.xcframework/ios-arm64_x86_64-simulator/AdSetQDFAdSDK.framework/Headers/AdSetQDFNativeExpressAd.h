//
//  AdSetQDFNativeExpressAd.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDFNativeExpressAd;
@class AdSetQDFNativeExpressAdView;

@protocol AdSetQDFNativeExpressAdDelegate <NSObject>

@optional
/**
 * 拉取原生模板广告成功
 */
- (void)AdSetQDF_nativeExpressAdSuccessToLoad:(AdSetQDFNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof AdSetQDFNativeExpressAdView *> *)views;

/**
 * 拉取原生模板广告失败
 */
- (void)AdSetQDF_nativeExpressAdFailToLoad:(AdSetQDFNativeExpressAd *)nativeExpressAd error:(NSError *)error;

/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)AdSetQDF_nativeExpressAdViewRenderSuccess:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告渲染失败
 */
- (void)AdSetQDF_nativeExpressAdViewRenderFail:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告曝光回调
 */
- (void)AdSetQDF_nativeExpressAdViewExposure:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告点击回调
 */
- (void)AdSetQDF_nativeExpressAdViewClicked:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告被关闭
 */
- (void)AdSetQDF_nativeExpressAdViewClosed:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

/**
 * 点击原生模板广告以后即将弹出全屏广告页
 */
- (void)AdSetQDF_nativeExpressAdViewWillPresentScreen:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;


/**
 * 全屏广告页将要关闭
 */
- (void)AdSetQDF_nativeExpressAdViewWillDismissScreen:(AdSetQDFNativeExpressAdView *)nativeExpressAdView;

@end

@interface AdSetQDFNativeExpressAd : NSObject
/**
 *  委托对象
 */
@property (nonatomic, weak) id<AdSetQDFNativeExpressAdDelegate> delegate;


@property (nonatomic, readonly) NSString *placementId;

/**
 *  构造方法
 *  详解：placementId - 广告位 ID
 *       adSize - 广告展示的宽高
 */

- (instancetype)initWithPlacementId:(NSString *)placementId adSize:(CGSize)size;

/**
 *  拉取广告
 */
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
