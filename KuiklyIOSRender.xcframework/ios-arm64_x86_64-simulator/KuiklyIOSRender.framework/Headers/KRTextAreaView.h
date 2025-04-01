//
//  KRTextAreaView.h
//  KuiklyKotlinProject
//
//  Created by tomqiu on 2022/9/21.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"
NS_ASSUME_NONNULL_BEGIN

/*
 * @brief 暴露给Kotlin侧调用的多行输入框组件
 */
@interface KRTextAreaView : UITextView<KuiklyRenderViewExportProtocol>

@end

NS_ASSUME_NONNULL_END
