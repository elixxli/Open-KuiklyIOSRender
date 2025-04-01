//
//  KuiklyRenderFrameworkContextHandler.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/2/19.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KuiklyRenderContextProtocol.h"
NS_ASSUME_NONNULL_BEGIN
/**
 * @brief framework执行环境的实现者
 */
@interface KuiklyRenderFrameworkContextHandler : NSObject<KuiklyRenderContextProtocol>

/*
 * @brief 对应contextCode是否framework模式
 */
+ (BOOL)isFrameworkWithContextCode:(NSString *)contextCode;
/*
 * @brief 判断PageName是否存在于当前Framework中
 * @param pageName 对应Kotin测@Page注解名字
 * @param frameworkName 编译出来的framework名字
 * @return 是否存在该页面
 */
+ (BOOL)isPageExistWithPageName:(NSString *)pageName frameworkName:(NSString *)frameworkName;
/*
 * @brief 根据framework名获取Kotlin/Native入口类
 */
+ (Class _Nullable)entryClassWithFrameworkName:(NSString *)frameworkName;

@end

NS_ASSUME_NONNULL_END
