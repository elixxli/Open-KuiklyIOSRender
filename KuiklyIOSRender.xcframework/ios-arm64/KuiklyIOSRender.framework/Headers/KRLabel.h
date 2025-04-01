//
//  KRLabel.h
//
//  Created by tomqiu on 2022/12/21.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>


NS_ASSUME_NONNULL_BEGIN
@class KRTextRender;


extern NSString *const KRHighlightAttributeKey;
extern NSString *const KRBGAttributeKey;


@interface KRLabel : UILabel

@property (nonatomic, strong, nullable) KRTextRender *textRender;
@property (nonatomic, assign) BOOL displaysAsynchronously;

/**
 * 获取富文本的对应尺寸大小
 * note：任意线程都可以调用该方法，一般用于 子线程 执行
 */
+ (CGSize)sizeThatFits:(CGSize)size attributedString:(NSAttributedString *)attString numberOfLines:(NSUInteger)lines lineBreakMode:(NSLineBreakMode)mode;
+ (CGSize)sizeThatFits:(CGSize)size attributedString:(NSAttributedString *)attString numberOfLines:(NSUInteger)lines lineBreakMode:(NSLineBreakMode)mode lineBreakMarin:(CGFloat)marin;

@end



//------KRLayoutManager类分割线-----

@interface KRLayoutManager : NSLayoutManager

@property (nonatomic, assign) NSRange highlightRange;


@end




//---------KRTextRender类分割线------------
@interface KRTextRender : NSObject

@property (nonatomic, strong, nullable) NSTextStorage *textStorage;
@property (nonatomic, strong, readonly) KRLayoutManager * layoutManager;
@property (nonatomic, strong, readonly) NSTextContainer *textContainer;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGFloat lineFragmentPadding;
@property (nonatomic, assign) NSLineBreakMode lineBreakMode;
@property (nonatomic, assign) NSUInteger maximumNumberOfLines;
@property (nonatomic, assign, readonly) CGRect textBound;
@property (nonatomic, assign) BOOL isBreakLine;//是否被截断

@property (nonatomic, assign) CGFloat lineBreakMargin;//截断边距
// initialize
- (instancetype)initWithAttributedText:(NSAttributedString *)attributedText;
- (instancetype)initWithTextStorage:(NSTextStorage *)textStorage;

@property (nonatomic, strong, readonly, nullable) NSArray<NSTextAttachment *> *attachmentViews;
@property (nonatomic, strong, readonly, nullable) NSSet<NSTextAttachment *> *attachmentViewSet;

- (NSRange)visibleGlyphRange ;
- (NSRange)visibleCharacterRange ;
- (CGRect)boundingRectForCharacterRange:(NSRange)characterRange;
- (CGRect)boundingRectForGlyphRange:(NSRange)glyphRange ;
- (CGSize)textSizeWithRenderWidth:(CGFloat)renderWidth;
- (NSInteger)characterIndexForPoint:(CGPoint)point;

/**
 draw text at point
 */
- (void)drawTextAtPoint:(CGPoint)point isCanceled:(BOOL (^__nullable)(void))isCanceled;

@end





// ------- 类分割线--------

@interface NSAttributedString(MIJAsync)
@property(nullable, nonatomic, strong) KRTextRender * hr_textRender;
@property(nonatomic, assign) CGSize hr_size;
@end


typedef NS_ENUM(NSUInteger, KRAttachmentAlignment) {
    KRAttachmentAlignmentBaseline,
    KRAttachmentAlignmentCenter,
    KRAttachmentAlignmentBottom
};
// ------- 类分割线--------
@interface KRTextAttachment : NSTextAttachment

@property (nonatomic, strong, nullable) UIView *view;
@property (nonatomic,assign) CGSize size;
@property (nonatomic,assign) CGFloat baseline;
@property (nonatomic,assign) KRAttachmentAlignment verticalAlignment;

@end
// ------- 类分割线--------
@interface KRTextAttachment (Display)
@property (nonatomic, assign, readonly) NSRange range;
@property (nonatomic, assign, readonly) CGPoint position;
- (void)setFrame:(CGRect)frame;
- (void)addToSuperView:(UIView *)superView;
- (void)removeFromSuperView:(UIView *)superView;
@end
// ------- 类分割线--------
@interface NSAttributedString (KRTextAttachment)
@property(nonatomic, assign) BOOL hr_hasAttachmentViews;
- (NSArray<KRTextAttachment *> *)hr_viewAttachments;

@end

NS_ASSUME_NONNULL_END



