//
//  AdSetQDFAdProtocol.h
//  CXAdSDKDemo
//
//  Created by AustinYang on 2026/6/17.
//

#import <Foundation/Foundation.h>

// 最高失败价格 - 竟胜后传入其它失败里面的最高失败价格
#define kHighestFailurePrice @"highestFailurePrice"

// 竞价失败后使用 - 竟胜的最高价格
#define kHighestWinPrice @"highestWinPrice"

// 竞价失败原因
#define kBindingFailureReason @"bindingFailureReason"

/// 竞价失败枚举
typedef NS_ENUM(NSInteger, AdSetQDFBiddingLoseReason) {
    // 未知原因失败
    AdSetQDFBiddingLoseReasonUnkonwn = 0,
    // 竞价过低
    AdSetQDFBiddingLoseReasonBidTooLow = 100,
    // 响应超时
    AdSetQDFBiddingLoseReasonResponseTimeout = 200,
};



@protocol AdSetQDFAdProtocol <NSObject>

@optional

/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用  -----------  请注意竟胜和竟败均使用一价
 *
 *  @param winPrice 竞胜价格
 *
 */
- (void)sendWinNotificationWithWinPrice:(NSInteger)winPrice;

/**
 *  竞败之后或未参竞调用
 *
 *  @pararm lossPrice 竟胜价格
 *  lossReason ：竞败原因
 */
- (void)sendLossNotificationWithLossPrice:(NSInteger)lossPrice lossReason:(AdSetQDFBiddingLoseReason)lossReason;


/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用 - 请使用上面API：sendWinNotificationWithWinPrice:
 *
 *  @param winInfo 竞胜信息 字典类型，支持的key为以下，注：key是个宏，在AdSetQDFAdProtocol.h中有定义，可以参考demo中的使用方法

 *  kHighestFailurePrice：最高失败出价，值类型为NSString  *
 *
 */
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;

/**
 *  竞败之后或未参竞调用 - 请使用上面API：sendLossNotificationWithLossPrice:lossReason:
 *
 *  @pararm lossInfo 竞败信息，字典类型，注：key是个宏，在AdSetQDFAdProtocol.h中有定义
 *  kHighestWinPrice ：竞胜价格 (单位: 分)，值类型为NSString *，选填
 *  kBindingFailureReason ：广告竞败原因，竞败原因参考枚举AdSetQDFBiddingLoseReason中的定义，值类型为NSNumber *，必填
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end
