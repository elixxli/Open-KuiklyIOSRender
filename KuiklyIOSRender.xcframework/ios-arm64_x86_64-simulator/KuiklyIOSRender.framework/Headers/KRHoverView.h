//
//  KRHoverView.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/2/10.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"
NS_ASSUME_NONNULL_BEGIN

/*
 * @brief 用于列表下的自动悬停（列表滚动可自动悬浮置顶）视图组件
 */
@interface KRHoverView : UIView<KuiklyRenderViewExportProtocol>

@end

NS_ASSUME_NONNULL_END
