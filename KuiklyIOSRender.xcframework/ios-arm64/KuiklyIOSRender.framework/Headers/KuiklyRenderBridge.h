//
//  KuiklyRenderBridge.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/7/28.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KRLogModule.h"
#import "KRAPNGView.h"
#import "KRPAGView.h"
#import "KRCacheManager.h"
NS_ASSUME_NONNULL_BEGIN

@protocol KuiklyRenderBridgeProtocol;
@protocol KuiklyRenderComponentExpandProtocol;

typedef void (^KRBundleResponse)(NSString *_Nullable script , NSError *_Nullable error);

@interface KuiklyRenderBridge : NSObject

/*
 * @brief 注册图片下载实现
 */
+ (void)registerComponentExpandHandler:(id<KuiklyRenderComponentExpandProtocol>)componentExpandHandler;
/*
 * @brief 注册自定义log实现
 */
+ (void)registerLogHandler:(id<KuiklyLogProtocol>)logHandler;

/*
 * @brief 注册自定义APNGView实现
 * @param creator 创建apngView实现者实例
 */
+ (void)registerAPNGViewCreator:(APNGViewCreator)creator;
/*
 * @brief 自定义注册PAGView实现(默认只要pod 'libpag', ">= 4.3.21"，就无需注册)
 * @param creator 创建pageView实例
 */
+ (void)registerPAGViewCreator:(PAGViewCreator)creator;

/*
 * @brief 注册自定义Cache实现
 */
+ (void)registerCacheHandler:(id<KRCacheProtocol>)cacheHandler;


+ (id<KuiklyRenderComponentExpandProtocol>)componentExpandHandler;

@end



@protocol KuiklyRenderComponentExpandProtocol <NSObject>


/*
 * 自定义实现设置图片
 * @param url 设置的图片url，如果url为nil，则是取消图片设置，需要view.image = nil
 * @return 是否处理该图片设置，返回值为YES，则交给该代理实现，否则sdk内部自己处理
 */
- (BOOL)hr_setImageWithUrl:(NSString *)url forImageView:(UIImageView *)imageView;

/*
 * 自定义实现设置颜值
 * @param value 设置的颜色值
 * @return 完成自定义处理的颜色对象
 */
- (UIColor *)hr_colorWithValue:(NSString *)value;
/*
 * 扩展文本后置处理
 * @param attributedString 源文本对象
 * @param textPostProcessor 后置处理标记（由kotlin侧text组件属性设置textPostProcessor()而来）
 * @return 返回新的文本对象
 */
- (NSMutableAttributedString *)hr_customTextWithAttributedString:(NSAttributedString *)attributedString textPostProcessor:(NSString *)textPostProcessor;
@end

NS_ASSUME_NONNULL_END
