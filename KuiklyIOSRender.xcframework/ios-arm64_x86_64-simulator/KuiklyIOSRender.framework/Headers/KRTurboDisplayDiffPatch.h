//
//  KRTurboDisplayDiffPatch.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/3.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRTurboDisplayNode.h"
#import "KuiklyRenderLayerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface KRTurboDisplayDiffPatch : NSObject
/**
 * @brief diff 两棵树进行差量更新到渲染器
 */
+ (void)diffPatchToRenderingWithRenderLayer:(id<KuiklyRenderLayerProtocol>)renderLayer
                                oldNodeTree:(KRTurboDisplayNode * _Nullable)oldNodeTree
                                newNodeTree:(KRTurboDisplayNode *)newNodeTree;

/**
 * @brief 保留目标树结构，仅更新目标树属性信息
 * @param targetNodeTree 被更新的目标树
 * @param fromNodeTree 更新的来源树
 * @return 是否有发生更新
 */
+ (BOOL)onlyUpdateWithTargetNodeTree:(KRTurboDisplayNode *)targetNodeTree fromNodeTree:(KRTurboDisplayNode *)fromNodeTree;

@end

NS_ASSUME_NONNULL_END
