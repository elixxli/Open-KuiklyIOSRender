//
//  KRRichTextView.h
//  iosApp
//
//  Created by tomqiu on 2022/7/27.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "KRLabel.h"
#import "KuiklyRenderViewExportProtocol.h"

NS_ASSUME_NONNULL_BEGIN
extern NSString *const KuiklyIndexAttributeName;
@interface KRRichTextView : KRLabel<KuiklyRenderViewExportProtocol>

@end

@interface KRRichTextShadow : NSObject<KuiklyRenderShadowProtocol>

@property (nonatomic, strong) NSMutableAttributedString *attributedString;
@property (nonatomic, assign) bool strokeAndFill;

- (NSAttributedString *)buildAttributedString;


@end

@interface KRRichTextAttachment : NSTextAttachment

@property (nonatomic , assign) CGFloat offsetY ;
@property (nonatomic , assign) NSUInteger charIndex ;

@end

NS_ASSUME_NONNULL_END
