//
//  RCBMWorkKitConfig.h
//  RCBMWorkKit
//
//  Created by dev on 2022/8/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN


@interface RCBMWorkKitConfig : NSObject


typedef void (^HXAuthCallBack)(BOOL isSuccess);


/// 准备初始化应用必须参数
/// @param appId 应用ID
/// @param appKey appKey
/// @param appSecret appSecret
/// @param sm2PublicKey 服务公钥
+ (void)prepareWorkKitParmsAppID:(NSString *)appId
                     appKey:(NSString *)appKey
                  appSecret:(NSString *)appSecret
            andsm2PublicKey:(NSString *)sm2PublicKey;



///  生成 dataApplicationKey  即 Basic Base64.encode(appKey:appSecret)
/// @param appKey appKey
/// @param appSecret appSecret
+ (NSString *)genDataAuthKeyByappKey:(NSString *)appKey
                           appSecret:(NSString *)appSecret;

/**
 * 准备初始化必须参数
 * @param dataApplicationKey  应用id 即 appid
 * @param dataAuthorizationKey 应用授权key 即 Basic Base64.encode(appKey:appSecret)
 * @param sm2PublicKey 公钥key
 */
+ (void)prepareWorkKitParms:(NSString *)dataApplicationKey
       anddataAuthorization:(NSString * )dataAuthorizationKey
            andsm2PublicKey:(NSString *)sm2PublicKey;


/**
 * 前置授权
 * @param username  用户名
 * @param password  加密后的密文
 * @param serverHost  工作台server服务地址
 * @param callBack  成功或失败回调
 */
+(void)prepardWorkKitAuthorization:(NSString *) username
                            andPwd:(NSString *) password
                        serverHost:(NSString *)serverHost
                          callBack:(HXAuthCallBack)callBack;


/// 清理宏信授权用户信息 app壳工程loginoout时候需调用
+ (void)clearHXUserAuthInfo;

/// token 失效后 重新授权宏信
/// @param callBack 授权宏信完成回调
+(void)retryWorkAuthorization:(HXAuthCallBack)callBack ;

///  开启打印打印
/// @param canLog  是否开启打印
+(void)enableNetLog:(BOOL)canLog ;



/// 返回初始化 工作台VC
/// @param isTabBarImpot  是否是tabbar 接入
+(UIViewController *)genWorkBenchHomeVC:(BOOL)isTabBarImpot;
@end

NS_ASSUME_NONNULL_END
