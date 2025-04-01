//
//  KRTurboDisplayModule.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/3.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRBaseModule.h"
NS_ASSUME_NONNULL_BEGIN
/** 设置当前UI作为TurboDisplay首屏通知 */
extern NSString *const kSetCurrentUIAsFirstScreenForNextLaunchNotificationName;
/** 关闭TurboDisplay模式通知 */
extern NSString *const kCloseTurboDisplayNotificationName;

/*
 * @brief TurboDisplay首屏直出渲染模式（通过直接执行二进制产物渲染生成首屏，避免业务代码执行后再生成的首屏等待耗时）
 */
@interface KRTurboDisplayModule : KRBaseModule
/// 首屏使用了TurboDisplay
@property (nonatomic, assign) BOOL firstScreenTurboDisplay;

@end

NS_ASSUME_NONNULL_END
