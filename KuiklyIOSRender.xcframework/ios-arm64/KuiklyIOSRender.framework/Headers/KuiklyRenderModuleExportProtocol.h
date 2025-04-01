//
//  KuiklyRenderModuleExportProtocol.h
//  KuiklyKotlinProject
//
//  Created by tomqiu on 2022/7/7.
//  Copyright © 2022 Tencent. All rights reserved.
//

#ifndef KuiklyRenderModuleExportProtocol_h
#define KuiklyRenderModuleExportProtocol_h
#define KR_SYNC_CALLBACK_KEY @"hr_sync_callback"
NS_ASSUME_NONNULL_BEGIN
@class UIView;
@class KuiklyRenderView;
/*
 * 回调给Kotlin侧的闭包
 * @param result 数据(类型可为NSDictionary, NSArray, NSString, NSNumber, NSData, 注: NSDictionary在Kotlin侧对应为String类型)
 */
typedef void (^KuiklyRenderCallback)(id _Nullable result);
/*
 * @brief 暴露native侧的module组件所需实现的协议
 */
@protocol KuiklyRenderModuleExportProtocol <NSObject>

@optional

/*
 * @brief 当前所在根视图
 */
@property (nonatomic, weak) KuiklyRenderView *hr_rootView;

/*
 * @brief Kotlin侧调用当前module的实例方法出发该回调(多线程调用)
 * @param method 方法名
 * @param params 方法参数 (透传kotlin侧数据, 类型可为NSString, NSArray, NSData, NSNumber)
 * @param callback 方法中的异步回调闭包参数
 * @return 同步返回给kotlin侧的返回值(类型可为NSDictionary, NSString, NSArray, NSData, NSNumber)
 */
- (id _Nullable)hrv_callWithMethod:(NSString * _Nonnull)method
                    params:(id _Nullable)params
                  callback:(KuiklyRenderCallback _Nullable)callback;


@end


NS_ASSUME_NONNULL_END

#endif /* KuiklyRenderModuleExportProtocol_h */
