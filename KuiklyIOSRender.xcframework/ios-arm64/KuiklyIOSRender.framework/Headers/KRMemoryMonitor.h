//
//  KRMemoryMonitor.h
//  KuiklyIOSRender
//
//  Created by luoyibu on 2023/7/12.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 内存监控，每10秒打点一次
@interface KRMemoryMonitor : NSObject

/// 页面的平均内存增量数据: 页面可见期间的平均内存 - 页面进入前的内存， 单位：字节
@property (nonatomic, readonly) int64_t avgIncrementMemory;

/// 页面的峰值增量数据: 页面可见期间的内存峰值 - 页面进入前的内存， 单位：字节
@property (nonatomic, readonly) int64_t peakIncrementMemory;

/// 页面的内存峰值: 页面可见期间的内存峰值， 单位：字节
@property (nonatomic, readonly) int64_t appPeakMemory;

/// 页面的平均内存: 页面可见期间的平均内存， 单位：字节
@property (nonatomic, readonly) int64_t appAvgMemory;

- (instancetype)initWithPageName:(NSString *)pageName;

- (void)startMonitor;

- (void)endMonitor;

@end

NS_ASSUME_NONNULL_END
