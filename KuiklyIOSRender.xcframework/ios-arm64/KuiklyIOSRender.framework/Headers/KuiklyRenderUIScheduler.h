//
//  KuiklyRenderUIScheduler.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/2/3.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol KuiklyRenderUISchedulerDelegate;
/**
 * @brief KuiklyRenderCore UI线程调度器
 */
@interface KuiklyRenderUIScheduler : NSObject
/** 执行主线程任务中 */
@property (nonatomic, assign, readonly) BOOL performingMainQueueTask;
/*
 * @brief KuiklyRenderUIScheduler初始化方法
 * @param delegate KuiklyRenderUISchedulerDelegate代理
 */
- (instancetype)initWithDelegate:(id<KuiklyRenderUISchedulerDelegate>)delegate;

/*
 * @brief 添加任务到主线程执行（下一个runloop统一批量执行）
 * @param task 任务闭包
 */
- (void)addTaskToMainQueueWithTask:(dispatch_block_t)task;
/*
 * @brief 立即执行待同步的主线程任务
 */
- (void)performSyncMainQueueTasksBlockIfNeed;

/*
 * @brief 执行任务当首屏完成时(优化首屏性能压力)
 * @param task 任务闭包
 */
- (void)performWhenViewDidLoadWithTask:(dispatch_block_t)task;
/*
 * @brief 标记首屏已经已经加载完成
 */
- (void)markViewDidLoad;


@end

@protocol KuiklyRenderUISchedulerDelegate<NSObject>

/**
 * @brief  UI任务将要执行前回调
 * @param scheduler KuiklyRenderUIScheduler
 */
- (void)willPerformUITasksWithScheduler:(KuiklyRenderUIScheduler*)scheduler;

@end

NS_ASSUME_NONNULL_END

