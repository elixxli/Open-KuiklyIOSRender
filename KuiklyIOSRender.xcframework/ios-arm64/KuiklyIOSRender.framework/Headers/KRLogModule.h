//
//  KRLogModule.h
//  KuiklyIOSRender
//
//  Created by Mac on 2023/6/30.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "KRBaseModule.h"

NS_ASSUME_NONNULL_BEGIN


@protocol KuiklyLogProtocol <NSObject>

@required
/*
 * 是否支持异步打印日志
 * 注：1.对KLog和平台侧日志打印的相对顺序不关注可以返回true，即性能优先
 *    2.无论异步还是同步，KLog接口打印保持相对时序
 */
- (BOOL)asyncLogEnable;

/*
 * @brief 打印info等级类型日志（该方法子线程调用）
 */
- (void)logInfo:(NSString *)message;
/*
 * @brief 打印debug等级类型日志（该方法子线程调用）
 */
- (void)logDebug:(NSString *)message;
/*
 * @brief 打印error等级类型日志（该方法子线程调用）
 */
- (void)logError:(NSString *)message;



@end

@interface KRLogModule : KRBaseModule
/*
 * @brief 注册自定义log实现
 */
+ (void)registerLogHandler:(id<KuiklyLogProtocol>)logHandler;
/*
 * @brief 打印错误信息
 */
+ (void)logError:(NSString *)errorLog;
/*
 * @brief 打印信息
 */
+ (void)logInfo:(NSString *)infoLog;

@end

NS_ASSUME_NONNULL_END
