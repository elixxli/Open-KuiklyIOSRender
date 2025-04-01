//
//  NSObject+KR.h
//  iosApp
//
//  Created by tomqiu on 2022/11/30.
//  Copyright © 2022 orgName. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (KR)

- (NSDictionary *)hr_stringToDictionary;
- (NSDictionary *)kr_stringToDictionary;

- (NSArray *)hr_stringToArray;
- (NSArray *)kr_stringToArray;

- (NSString *)kr_urlEncode;

- (id)kr_invokeWithSelector:(SEL)selector args:(id)args;

+ (id)kr_performWithTarget:(id)target selector:(SEL)aSelector  withObjects:(NSArray *)objects;

+ (id)kr_performWithClass:(Class)classTarget selector:(SEL)aSelector  withObjects:(NSArray *)objects;


@end

@interface NSDictionary (KR)

- (NSString *)hr_dictionaryToString;
- (NSString *)kr_dictionaryToString;

@end

@interface NSString (KR)

- (NSString *)kr_appendUrlEncodeWithParam:(NSDictionary *)param;
- (NSString *)kr_md5String;
- (NSString *)kr_base64Encode;
- (NSString *)kr_base64Decode;
- (NSString *)kr_sha256String;

@end

@interface UIView (KR)

+ (UIImage *)kr_safeAsImageWithLayer:(CALayer *)layer bounds:(CGRect)bounds;
- (UIViewController *)kr_viewController;
@end

@interface NSInvocation (KR)

- (void)kr_setArgumentObject:(id)arguementObject atIndex:(NSInteger)idx;

@end

@interface UIImage (KR)

/**
  使用vImage进行高斯模糊
 @param radius 模糊的范围 可以1~99
 @return 返回已经模糊过的图片
 */

- (UIImage *)kr_blurBlurRadius:(CGFloat)radius;

/**
 * 转换为热力图图片
 */
- (UIImage *)kr_applyHeatmapWithGridentRawData:(unsigned char *)gridentRawData gridentImage:(UIImage *)gridentImage;

/**
 * 获取图片像素数组
 */
- (unsigned char *)kr_getRawData;
/**
 * 染色非透明像素为该颜色
 */
- (UIImage *)kr_tintedImageWithColor:(UIColor *)color;
@end


@interface UIApplication (KR)
+ (BOOL)isAppExtension;
@end

NS_ASSUME_NONNULL_END
