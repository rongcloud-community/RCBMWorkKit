//
//  RCBMPrepareWorkParmsDelegate.h
//  RCBMWorkKit
//
//  Created by dev on 2022/8/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RCBMPrepareWorkParmsDelegate <NSObject>
/// 通过server获取工作台初始化参数
/// @param callBack 获取参数回调
- (void)prepareWorkParmByServer:(void (^)(BOOL isSuccess))callBack;
@end

NS_ASSUME_NONNULL_END
