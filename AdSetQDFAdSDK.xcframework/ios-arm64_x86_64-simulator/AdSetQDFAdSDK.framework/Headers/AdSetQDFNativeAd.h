//
//  AdSetQDFNativeAd.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/24.
//

#import <Foundation/Foundation.h>
#import <AdSetQDFAdSDK/AdSetQDFNativeAdDataObject.h>
#import <AdSetQDFAdSDK/AdSetQDFProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDFNativeAd;
@protocol AdSetQDFNativeAdDelegate <NSObject>
@optional
/**
 广告曝光回调

 @param nativeAd AdSetQDFNativeAd 实例
 */
- (void)AdSetQDF_nativeAdViewExposure:(AdSetQDFNativeAd *)nativeAd;

/**
 广告点击回调

 @param nativeAd AdSetQDFNativeAd 实例
 */
- (void)AdSetQDF_nativeAdViewClicked:(AdSetQDFNativeAd *)nativeAd;

/**
 *  点击以后即将弹出全屏广告页
 */
- (void)AdSetQDF_nativeAdWillPresentFullScreenModal:(AdSetQDFNativeAd *)nativeAd;

/**
 *  点击以后全屏广告页将要关闭
 */
- (void)AdSetQDF_nativeAdWillDismissFullScreenModal:(AdSetQDFNativeAd *)nativeAd;

@end

@interface AdSetQDFNativeAd : NSObject<AdSetQDFProtocol>

/**
 Ad material.
 */
@property (nonatomic, strong, readonly, nullable) AdSetQDFNativeAdDataObject *dataObject;

/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <AdSetQDFNativeAdDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<AdSetQDFNativeAdDelegate> delegate;

/**
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

@property (strong, nonatomic, readonly) __kindof UIView *videoView;

/**
 @warning 需要注意的是 该方法需要避免重复多次调用的情况
 @warning 当广告不需要展示并且销毁的时候，需要调用 -[AdSetQDFNativeAd unregisterView]方法，即registerContainer方法需要与unregisterView方法成对调用
 
 @param containerView 承载广告的容器，必传
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 */
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *)clickableViews;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 AdSetQDFNativeAd 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterView 方法，
 将广告对象与 AdSetQDFNativeAd 解绑，具体可参考示例 demo 的 NativeAdListCell 类
 */
- (void)unregisterView;

/**
 广告logo
 */
@property (nonatomic, readonly) UIView * _Nonnull adLogoView;

@end

NS_ASSUME_NONNULL_END
