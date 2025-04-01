//
//  KRRouterModule.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/4/16.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "KRBaseModule.h"

NS_ASSUME_NONNULL_BEGIN
@protocol KRRouterProtocol;
@interface KRRouterModule : KRBaseModule

+ (void)registerRouterHandler:(id<KRRouterProtocol>)routerHandler;

@end

@protocol KRRouterProtocol <NSObject>

@required
/*
 * @brief 打开kuikly页面
 * @param pageName kuikly页面名，为@Page注解名
 * @param pageData 页面的传参，数据类型为jsonObject，key&value为字符串/Number等基础数据类型
 * @param controller 当前页面所在controller
 */
- (void)openPageWithName:(NSString *)pageName
                pageData:(NSDictionary * _Nullable)pageData
              controller:(UIViewController *)controller;
/*
 * @brief 关闭当前页
 * @param controller 需要关闭的controller
 */
- (void)closePage:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
