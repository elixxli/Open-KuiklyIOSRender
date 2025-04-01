//
//  KuiklyRenderThreadManager.h
//
//  Created by tomqiu on 2023/2/3.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define KR_ASSERT_CONTEXT_HTREAD assert([KuiklyRenderThreadManager isContextQueue])

@interface KuiklyRenderThreadManager : NSObject

/*
 * 指定Context线程执行闭包
 * @param block 任务闭包
 */
+ (void)performOnContextQueueWithBlock:(dispatch_block_t)block;

/*
 * 指定Context线程执行闭包
 * @param block 任务闭包
 * @param sync 是否同步执行
 */
+ (void)performOnContextQueueWithBlock:(dispatch_block_t)block sync:(BOOL)sync;
/*
 * 如果是在context线程的话，立即在context线程执行，否则next runloop执行
 */
+ (void)performOnContextQueueImmediatelyWithBlock:(dispatch_block_t)block;

/*
 * 主线程执行任务
 */
+ (void)performOnMainQueueWithTask:(dispatch_block_t)task sync:(BOOL)sync;
/*
 * 指定Log线程执行闭包
 * @param block 任务闭包
 */
+ (void)performOnLogQueueWithBlock:(dispatch_block_t)block;

/*
 * Context线程
 */
+ (dispatch_queue_t)contextQueue;
/*
 * 当前所处线程是否为context线程
 */
+ (BOOL)isContextQueue;
/*
 * TDFModule线程执行
 * @param moduleName TDFModule名字
 * @param task 执行的闭包
 * @return 是否执行成功
 */
+ (BOOL)performOnModuleQueueWithTDFModuleName:(NSString *)moduleName task:(dispatch_block_t)task;
/*
 * 断言当前线程必须为ContextQueue
 */
+ (void)assertContextQueue;

/*
 * 延时在主线程执行
 * @param task 主线程上执行的闭包任务
 * @param delay 延时时间，单位为ms
 */
+ (void)performOnMainQueueWithTask:(dispatch_block_t)task delay:(CGFloat)delay;

/*
 * 延时在context线程执行
 * @param task context线程延时执行的闭包任务
 * @param delay 延时时间，单位为s
 */
+ (void)performOnContextQueueWithTask:(dispatch_block_t)task delay:(CGFloat)delay;
@end

NS_ASSUME_NONNULL_END
