//
//  KRBlurView.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/3/22.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"
NS_ASSUME_NONNULL_BEGIN


@interface KRBlurView : UIVisualEffectView<KuiklyRenderViewExportProtocol>

/// css attr 高斯模糊模糊半径 默认为10
@property (nonatomic, strong) NSNumber *css_blurRadius;

@end

NS_ASSUME_NONNULL_END
