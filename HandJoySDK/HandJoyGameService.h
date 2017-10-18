//
//  HandJoyGameService.h
//  iOSKKUUSDKdemo
//
//  Created by janr on 2017/4/1.
//  Copyright © 2017年 cs039. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol HandJoyGameSDKCallBack <NSObject>

/*
 * Callback after weChatLogin
 */
- (void) didWeChatLoginSuccess:(NSDictionary*) userLoginResult;

/*
 * Callback after weChatShare
 */
- (void) didWeChatShareSuccess:(NSDictionary*) userShareResult;

/*
 * Callback after nickNameLogin
 */
- (void) didNickNameLoginSuccess:(NSDictionary*) userLoginResult;
/*
 * Callback after APPPurchaseSucceed
 */
- (void) didPurchaseSuccess:(NSDictionary*) userPurchaseResult;

/*
 * Callback after APPPurchaseFail
 */
- (void) didPurchaseFail:(NSDictionary*) userPurchaseResult;
@end



@interface HandJoyGameService : NSObject
@property (nonatomic, strong) NSString *gameid;
@property (nonatomic, strong) NSString *channelid;


/**
 打开其他app的回调
 */
+ (BOOL)handleOpenURL:(NSURL *)url;

//单例
+ (instancetype)shareInstance;

/**
 查看微信是否安装
 */
+ (BOOL)isWeiXinInstall;

/*! @brief 激活并初始化SDK。
 *
 * @param gameID  HandJoy平台给游戏分配的游戏ID
 */
//- (void)activateFusionSDKWithGameID:(NSString *)gameID
//                       andChannelID:(NSString *)channelID
//                              AppID:(NSString *)appID
//                       AppSecretKey:(NSString *)appSecretKey
//                           delegate:(id<HandJoyGameSDKCallBack>)delegate;
- (void)activateFusionSDKWithGameID:(NSString *)gameID
                       andChannelID:(NSString *)channelID
                              AppID:(NSString *)appID
                           delegate:(id<HandJoyGameSDKCallBack>)delegate;

//游客登陆
- (void)visitorLogin;

//微信登陆
- (void)wechatLogin;

//微信分享到对话
- (void)wechatShareToSessionWithTitle:(NSString *)title
                          Description:(NSString *)description
                             ImageURL:(NSString *)imageURL
                           WebpageUrl:(NSString *)webpageUrl;


//微信分享到朋友圈
- (void)wechatShareToTimelineShareWithTitle:(NSString *)title
                                Description:(NSString *)description
                                   ImageURL:(NSString *)imageURL
                                 WebpageUrl:(NSString *)webpageUrl;



/*! @brief 融合充值接口
 *
 * @param pay_money     商品价格
 * @param pay_num       商品数量
 * @param account_name  账号名称
 * @param role_id       游戏角色id
 * @param role_name     游戏角色名称
 * @param role_level    游戏角色等级
 * @param server_id     商品数量
 * @param channel_tag   下单金额
 * @param goods_id      商品id
 * @param goods_name    商品名称
 * @param goods_desc    商品数量
 * @param cp_order_id   下单金额
 * @param cp_notify_url 商品名称
 * @param cp_ext        商品数量
 */
- (void)payFusionSDKPay_money:(NSString *)pay_money
                andLogin_uuid:(NSString *)login_uuid
                   andPay_num:(NSInteger )pay_num
                   andAccount:(NSString *)account_name
                    andRoleId:(NSString *)role_id
                  andRoleName:(NSString *)role_name
                 andRoleLevel:(NSString *)role_level
                  andServerId:(NSString *)server_id
               andChannel_tag:(NSString *)channel_tag
                  andGoods_Id:(NSString *)goods_id
                andGoods_name:(NSString *)goods_name
                andGoods_desc:(NSString *)goods_desc
                   andOrderId:(NSString *)cp_order_id
                       andURL:(NSString *)cp_notify_url
                       andExt:(NSString *)cp_ext;

@end
