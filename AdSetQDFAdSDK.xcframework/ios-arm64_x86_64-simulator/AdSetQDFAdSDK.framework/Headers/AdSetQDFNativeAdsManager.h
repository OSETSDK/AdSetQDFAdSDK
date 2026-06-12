//
//  AdSetQDFNativeAdsManager.h
//  AdSetQDFAdSDK
//
//  Created by AustinYang on 2025/7/24.
//

#import <Foundation/Foundation.h>
#import <AdSetQDFAdSDK/AdSetQDFNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDFNativeAdsManager;
@protocol AdSetQDFNativeAdsManagerDelegate <NSObject>

- (void)AdSetQDF_nativeAdsManagerSuccessToLoad:(AdSetQDFNativeAdsManager *)adsManager nativeAds:(NSArray<AdSetQDFNativeAd *> *_Nullable)nativeAdDataArray;

- (void)AdSetQDF_nativeAdsManager:(AdSetQDFNativeAdsManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@interface AdSetQDFNativeAdsManager : NSObject
/**
 构造方法

 @param placementId 广告位ID
 @return CXNativeAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *_Nullable)placementId;

@property (nonatomic, weak) id<AdSetQDFNativeAdsManagerDelegate> delegate;

/**
 加载广告
 */
- (void)loadAdWithAd;
/**
 广告位Id
 */
@property (nonatomic, readonly) NSString *placementId;

@end

NS_ASSUME_NONNULL_END
