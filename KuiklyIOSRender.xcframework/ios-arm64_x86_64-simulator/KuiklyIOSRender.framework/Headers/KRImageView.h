//
//  KRImageView.h
//  KuiklyKotlinProject
//
//  Created by tomqiu on 2022/7/18.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKIt/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"

NS_ASSUME_NONNULL_BEGIN
/*
 * @brief 暴露给Kotlin侧调用的Image组件
 */
@interface KRImageView : UIImageView<KuiklyRenderViewExportProtocol>


@end



NS_ASSUME_NONNULL_END
