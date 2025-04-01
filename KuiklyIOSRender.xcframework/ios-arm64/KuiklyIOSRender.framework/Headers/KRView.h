// KRView.h
// KuiklyKotlinProject
//
// Created by tomqiu on 2022/7/13.
// Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief This is a container view component exposed for Kotlin side to call
 */
@interface KRView : UIView<KuiklyRenderViewExportProtocol>

// The touch down callback for the view
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_touchDown;

// The touch up callback for the view
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_touchUp;

// The touch move callback for the view
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_touchMove;

@end

NS_ASSUME_NONNULL_END
