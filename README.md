# RCBMWorkKit

[![CI Status](https://img.shields.io/travis/gongjiahao/RCBMWorkKit.svg?style=flat)](https://travis-ci.org/gongjiahao/RCBMWorkKit)
[![Version](https://img.shields.io/cocoapods/v/RCBMWorkKit.svg?style=flat)](https://cocoapods.org/pods/RCBMWorkKit)
[![License](https://img.shields.io/cocoapods/l/RCBMWorkKit.svg?style=flat)](https://cocoapods.org/pods/RCBMWorkKit)
[![Platform](https://img.shields.io/cocoapods/p/RCBMWorkKit.svg?style=flat)](https://cocoapods.org/pods/RCBMWorkKit)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

RCBMWorkKit is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'RCBMWorkKit', '~> 0.1.0'
```

## How to Use

1. 从应用管理后台获取应用的三要素,初始化参数;sm2PublicKey与服务器部署相关

```Objective-C
//引入头文件
#import <RCBMWorkKit/RCBMWorkKitConfig.h>

// 在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中或者项目中初始化三方SDK方法中

 /**
 * 准备初始化必须参数
 * @param dataApplicationKey  应用id 即 appid
 * @param dataAuthorizationKey 应用授权key 即 Basic Base64.encode(appKey:appSecret)
 * @param sm2PublicKey 公钥key
 */
    [RCBMWorkKitConfig prepareWorkKitParms:KdataApplicationKey anddataAuthorization:KdataAuthorizationKey andsm2PublicKey:Ksm2PublicKey];

```
📢: 这里需要特别注意,如果server端 提供参数接口,则需要在其接口的成功回调中调用:实现`prepareWorkParmByServer:`代理方法
```Objective-C
//在 APPDelegate中 遵守 <RCBMPrepareWorkParmsDelegate> 协议
// 在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中或者项目中初始化三方SDK方法中
// 工作台 设置代理
[RCBMWorkKitConfig setPrepareWorkParmsDelegate:self];
#pragma RCBMPrepareWorkParmsDelegate Method
- (void)prepareWorkParmByServer:(void (^)(BOOL isSuccess))callBack{
/*
这里请求接口处理
//FIXME: 接口API 接口成功则进行正常初始化后
*/
[RCBMWorkKitConfig prepareWorkKitParms:KdataApplicationKey anddataAuthorization:KdataAuthorizationKey andsm2PublicKey:Ksm2PublicKey];
//    [RCBMWorkKitConfig prepareWorkKitParmsAppID:KAppId appKey:KAppKey appSecret:KAppSecret andsm2PublicKey:Ksm2PublicKey];
//开启打印网络交互日志
[RCBMWorkKitConfig enableNetLog:YES];
}
```

2. 是否打印网络交互日志(可选)

`[RCBMWorkKitConfig enableNetLog:YES]`

3. 登录成功回调后,调用宏信授权,token交换,数据同步

```Objective-C
/**
* 前置授权
* @param username  用户名
* @param password  加密后的密文
* @param serverHost  工作台server服务地址,
* @param callBack  成功或失败回调
*/
[RCBMWorkKitConfig prepardWorkKitAuthorization:username andPwd:pwd serverHost:serverAddress_hx callBack:^(BOOL isSuccess) {
	if( isSuccess){
		//TODO: 授权成功,进行其他初始化化的逻辑

   } else{
		//TODO: 授权失败
		[RCBMWorkKitConfig retryWorkAuthorization:^(BOOL isSuccess) {
			if(isSuccess){
			//TODO: 重新授权成功
			...
		    }else{
			//TODO: 重新授权失败
			...
			}
		}];
   }
}];


```

4. 进行 工作台列表页的嵌入 入口,路由或者初始化根据项目调整

```Objective-C
/// 返回初始化 工作台VC
/// @param isTabBarImpot  是否是tabbar 接入
    UIViewController *homeVC = [RCBMWorkKitConfig genWorkBenchHomeVC:NO];
```

5. 宏信授权的信息清理,在登出时,调用即可
`[RCBMWorkKitConfig clearHXUserAuthInfo]`




## Author

asunrong, gongjiahao@rongcloud.cn

## License

RCBMWorkKit is available under the MIT license. See the LICENSE file for more info.
