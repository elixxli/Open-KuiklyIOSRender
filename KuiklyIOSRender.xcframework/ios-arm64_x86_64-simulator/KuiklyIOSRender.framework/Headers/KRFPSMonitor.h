//
//  KRFPSMonitor.h
//  KuiklyIOSRender
//
//  Created by luoyibu on 2023/7/11.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, KRFPSThead) {
    KRFPSThead_Main = 1,
    KRFPSThead_Kotlin = 2,
};


@interface KRFPSMonitor : NSObject

/// 当前fps，每秒更新
@property (nonatomic, assign, readonly) NSUInteger curFPS;
/// 平均fps
@property (nonatomic, assign, readonly) NSUInteger avgFPS;
/// 最大fps
@property (nonatomic, assign, readonly) NSUInteger maxFPS;
/// 最低fps
@property (nonatomic, assign, readonly) NSUInteger minFPS;

- (instancetype)initWithThread:(KRFPSThead)thread pageName:(NSString *)pageName;

- (void)onTick:(NSTimeInterval)timestamp;

- (void)endMonitor;

@end

NS_ASSUME_NONNULL_END
