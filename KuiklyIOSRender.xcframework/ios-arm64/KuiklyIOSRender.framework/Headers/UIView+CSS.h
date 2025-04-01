//
//  UIView+CSS.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/7/18.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+CSSDebug.h"
#import "KuiklyRenderViewExportProtocol.h"

#define KR_SCROLL_INDEX  @"scrollIndex"

#define KR_TURBO_DISPLAY_AUTO_UPDATE_ENABLE  @"turboDisplayAutoUpdateEnable"

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CSS)

@property (nonatomic, strong, nullable) NSNumber *css_visibility;
@property (nonatomic, strong, nullable) NSNumber *css_opacity;
@property (nonatomic, strong, nullable) NSNumber *css_overflow;
@property (nonatomic, strong, nullable) NSString *css_backgroundColor;
@property (nonatomic, strong, nullable) NSNumber *css_touchEnable;
@property (nonatomic, strong, nullable) NSString *css_transform;
@property (nonatomic, strong, nullable) NSString *css_backgroundImage;
@property (nonatomic, strong, nullable) NSString *css_boxShadow;
@property (nonatomic, strong, nullable) NSString *css_borderRadius;
@property (nonatomic, strong, nullable) NSString *css_border;
@property (nonatomic, strong, nullable) NSString *css_animation;
@property (nonatomic, strong, nullable) NSValue *css_frame;
@property (nonatomic, strong, nullable) NSNumber *css_zIndex;
@property (nonatomic, strong, nullable) NSString *css_accessibility;
@property (nonatomic, strong, nullable) NSString *css_accessibilityRole;
@property (nonatomic, strong, nullable) NSNumber *css_wrapperBoxShadowView;
@property (nonatomic, strong, nullable) NSNumber *css_autoDarkEnable;
@property (nonatomic, strong, nullable) NSNumber *css_scrollIndex;
@property (nonatomic, strong, nullable) NSNumber *css_turboDisplayAutoUpdateEnable;
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_click;
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_doubleClick;
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_longPress;
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_pan;
@property (nonatomic, strong, nullable) KuiklyRenderCallback css_animationCompletion;
/// 在列表中是否可以允许滑动
@property (nonatomic, assign) BOOL kr_canCancelInScrollView;

+ (NSString *_Nullable)css_string:(id)value;
+ (BOOL)css_bool:(id)value;
+ (UIColor *)css_color:(id)value;

- (BOOL)css_setPropWithKey:(NSString *)key value:(id)value;

- (void)css_reset;

- (void)css_onClickTapWithSender:(UIGestureRecognizer *)sender;
- (void)css_onDoubleClickWithSender:(UIGestureRecognizer *)sender;
- (void)css_onLongPressWithSender:(UILongPressGestureRecognizer *)sender;
@end

// ***  CSSGrientLayer  ** //
@interface CSSGradientLayer : CAGradientLayer

- (instancetype)initWithLayer:(id _Nullable)layer cssGradient:(NSString *)cssGradient;

@end

@interface CSSBoxShadow : NSObject

@property(nonatomic, assign) CGFloat offsetX;
@property(nonatomic, assign) CGFloat offsetY;
@property(nonatomic, assign) CGFloat shadowRadius;
@property(nonatomic, strong) UIColor *shadowColor;

- (instancetype)initWithCSSBoxShadow:(NSString *)boxShadow;

@end


@interface KRBoxShadowView : UIView

- (instancetype)initWithContentView:(UIView *)contentView;

@end




NS_ASSUME_NONNULL_END
