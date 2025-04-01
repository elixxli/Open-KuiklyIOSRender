//   
//  UIView+CSSDebug.h
//  KuiklyProject
//   
//  Created by jakchen on 2023/3/9
//  Copyright © 2023 Tencent. All rights reserved.
//  

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CSSDebug)

/// 调试类名
@property (nonatomic, strong, nullable) NSString *css_debugName;

@end

NS_ASSUME_NONNULL_END
