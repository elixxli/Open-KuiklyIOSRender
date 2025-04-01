//
//  KuiklyClientSideRenderLayerHanlder.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/2.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KuiklyRenderLayerProtocol.h"
NS_ASSUME_NONNULL_BEGIN
@class KuiklyRenderUIScheduler;
@class KuiklyRenderCore;

/**
 * @brief TurboDisply直出渲染模式实现器
 */
@interface KuiklyTurboDisplayRenderLayerHandler : NSObject<KuiklyRenderLayerProtocol>
/** ui调度器 */
@property (nonatomic, weak) KuiklyRenderUIScheduler *uiScheduler;

- (instancetype)initWithRootView:(UIView *)rootView contextParam:(KuiklyContextParam *)contextParam turboDisplayKey:(NSString *)turboDisplayKey;


@end

NS_ASSUME_NONNULL_END
