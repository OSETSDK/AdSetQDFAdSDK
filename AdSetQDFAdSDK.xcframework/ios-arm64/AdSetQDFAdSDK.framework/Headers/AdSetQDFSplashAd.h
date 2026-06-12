//
//  AdSetQDFSplashAd.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/16.
//

#import <UIKit/UIKit.h>
#import <AdSetQDFAdSDK/AdSetQDFProtocol.h>

@class AdSetQDFSplashAd;
@protocol AdSetQDFSplashAdDelegate <NSObject>

@optional
- (void)AdSetQDF_splashAdDidLoad:(AdSetQDFSplashAd *)splashAd;
/**
 *  开屏广告展示失败
 */
- (void)AdSetQDF_splashAdFailToPresent:(AdSetQDFSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告成功展示
 */
- (void)AdSetQDF_splashAdSuccessPresentScreen:(AdSetQDFSplashAd *)splashAd;
/**
 *  开屏广告曝光回调
 */
- (void)AdSetQDF_splashAdExposured:(AdSetQDFSplashAd *)splashAd;

/**
 *  开屏广告将要关闭回调
 */
- (void)AdSetQDF_splashAdWillClosed:(AdSetQDFSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)AdSetQDF_splashAdClosed:(AdSetQDFSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)AdSetQDF_splashAdClicked:(AdSetQDFSplashAd *)splashAd;

/**
 * 开屏广告剩余时间回调
 */
- (void)AdSetQDF_splashAdLifeTime:(NSUInteger)time;

/**
 *  开屏广告点击以后即将弹出全屏广告页
 */
- (void)AdSetQDF_splashAdWillPresentFullScreenModal:(AdSetQDFSplashAd *)splashAd;

/**
 *  点击以后全屏广告页将要关闭
 */
- (void)AdSetQDF_splashAdWillDismissFullScreenModal:(AdSetQDFSplashAd *)splashAd;

@end

@interface AdSetQDFSplashAd : NSObject<AdSetQDFProtocol>
/**
 *  委托对象
 */
@property (weak, nonatomic) id<AdSetQDFSplashAdDelegate> delegate;

@property (weak, nonatomic) UIViewController *viewController;

/// buttomView  底部视图 可为空
@property(strong, nonatomic) UIView *bottomView;

/**
 *  构造方法
 *  @param placementId - 广告位 ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

@property (nonatomic, readonly) NSString *placementId;

/**
 *  发起拉取广告请求，只拉取不展示
 *  详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调splashAdFailToPresent方法
 */
- (void)loadAd;

/**
 * 返回广告是否可展示
 * 对于并行请求，在调用showAdInWindow前时需判断下
 * @return 当广告已经加载完成&&未曝光&&未过期时，为YES，否则为NO
 */
- (BOOL)isAdValid;

/**
 *  展示广告
 *  详解：广告展示成功时会回调splashAdSuccessPresentScreen方法，展示失败时会回调splashAdFailToPresent方法
 */
- (void)showAdInWindow:(UIWindow *)window;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

// 是否在关闭落地页时候同时关闭广告
@property (nonatomic, assign) BOOL closeAdWhenCloseLandPage;

@end
