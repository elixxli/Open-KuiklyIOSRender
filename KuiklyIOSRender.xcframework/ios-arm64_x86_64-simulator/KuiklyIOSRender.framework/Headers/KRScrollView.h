//
//  KRScrollView.h
//  KuiklyKotlinProject
//
//  Created by tomqiu on 2022/7/18.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"
NS_ASSUME_NONNULL_BEGIN

/*
 * @brief 暴露给Kotlin侧调用的Scoller组件
 */
@interface KRScrollView : UIScrollView<KuiklyRenderViewExportProtocol, UIScrollViewDelegate>

@property (nonatomic, assign) BOOL autoAdjustContentOffsetDisable ;
/*
 * 添加滚动监听
 */
- (void)addScrollViewDelegate:(id<UIScrollViewDelegate>)scrollViewDelegate;
/*
 * 删除滚动监听
 */
- (void)removeScrollViewDelegate:(id<UIScrollViewDelegate>)scrollViewDelegate;

@end

@protocol KRScrollContentViewDelegate <NSObject>
@optional
- (void)contentViewDidInsertSubview;

@end

@interface KRScrollContentView : UIView<KuiklyRenderViewExportProtocol>
/*
 * 添加滚动监听
 */
- (void)addScrollContentViewDelegate:(id<KRScrollContentViewDelegate>)scrollContentViewDelegate;
/*
 * 删除滚动监听
 */
- (void)removeScrollContentViewDelegate:(id<KRScrollContentViewDelegate>)scrollContentViewDelegate;
@end



NS_ASSUME_NONNULL_END
