//
//  KRMaskView.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/1/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"
NS_ASSUME_NONNULL_BEGIN
/*
 * 遮罩视图 : 其 alpha 通道用于屏蔽视图内容的视图
 */
@interface KRMaskView : UIView<KuiklyRenderViewExportProtocol>

@end

NS_ASSUME_NONNULL_END
