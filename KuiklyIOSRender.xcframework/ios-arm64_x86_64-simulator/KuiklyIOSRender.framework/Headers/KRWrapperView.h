//
//  KRWrapperView.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/2/13.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KRWrapperView : UIView

- (instancetype)initWithHostView:(UIView *)hostView;

- (void)moveToSuperview:(UIView *)superView;


@end

NS_ASSUME_NONNULL_END
