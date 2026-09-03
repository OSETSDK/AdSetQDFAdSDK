//
//  AdSetQDFRewardVideoAd.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/21.
//

#import <UIKit/UIKit.h>
#import <AdSetQDFAdSDK/AdSetQDFAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDFRewardVideoAd;
@protocol AdSetQDFRewardVideoAdDelegate <NSObject>
@optional

/**
 广告数据加载成功回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdDidLoad:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdVideoDidLoad:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页即将展示回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdWillVisible:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频广告曝光回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdDidExposed:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdDidClose:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdDidClicked:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)AdSetQDF_rewardVideoAd:(AdSetQDFRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/**
 视频广告播放达到激励条件回调

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 @param info 包含此次广告行为的一些信息
 */
- (void)AdSetQDF_rewardVideoAdDidRewardEffective:(AdSetQDFRewardVideoAd *)rewardedVideoAd info:(NSDictionary *)info;

/**
 视频广告视频播放完成

 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 */
- (void)AdSetQDF_rewardVideoAdDidPlayFinish:(AdSetQDFRewardVideoAd *)rewardedVideoAd;

/**
 视频广告播放失败
 
 @param rewardedVideoAd AdSetQDFRewardVideoAd 实例
 @param error 具体错误信息
 
 */
- (void)AdSetQDF_rewardVideoAd:(AdSetQDFRewardVideoAd *)rewardedVideoAd didPlayFailWithError:(NSError *)error;

@end

@interface AdSetQDFRewardVideoAd : NSObject<AdSetQDFAdProtocol>
/**
 构造方法
 
 @param placementId - 广告位 ID
 @return AdSetQDFRewardVideoAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

@property (nonatomic, weak) id <AdSetQDFRewardVideoAdDelegate> delegate;

@property (readonly, nonatomic) NSString *placementId;

/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告已经曝光过
 *  c.广告过期
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

/**
 加载广告方法
 */
- (void)loadAd;
/**
 展示广告方法

 @param rootViewController 用于 present 激励视频 VC
 @return 是否展示成功
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
