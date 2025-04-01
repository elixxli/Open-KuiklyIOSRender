//
//  KRPerformanceManager.h
//  KuiklyIOSRender
//
//  Created by luoyibu on 2023/7/6.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRPerformanceDataProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(int, KRPageState) {
    KRPageState_viewDidLoad = 1 << 0,
    KRPageState_viewDidAppear = 1 << 1,
    KRPageState_appActive = 1 << 2,
};

@interface KRPerformanceManager : NSObject <KRPerformanceDataProtocol>

@property (nonatomic, assign) KRPageState pageState;
@property (nonatomic, assign) KRMonitorType monitorType;

/// key stage, value timespam（单位毫秒）
@property (nonatomic, readonly) NSDictionary<NSNumber *, NSNumber *> *stageStartTimes;
/// key stage, value durations（单位毫秒）
@property (nonatomic, readonly) NSDictionary<NSNumber *, NSNumber *> *stageDurations;

- (instancetype)initWithPageName:(NSString *)pageName;

/// 打点记时
- (void)startStage:(KRLoadStage)stage;
- (void)endStage:(KRLoadStage)stage;

- (void)startMonitor;
- (void)endMonitor;

- (void)mergeKotlinCreatePageTime:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
