//
//  KuiklyContextParam.h
//  KuiklyIOSRender
//
//  Created by luoyibu on 2023/7/4.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KuiklyRenderContextProtocol.h"

NS_ASSUME_NONNULL_BEGIN

extern const KuiklyContextMode KuiklyContextMode_Framework;

@class KuiklyContextParam;

// Kuikly接入模式
@interface KuiklyBaseContextMode : NSObject

@property (nonatomic, assign) KuiklyContextMode modeId;

// 创建Framework接入模式实例，modeId为KuiklyContextMode_Framework
- (instancetype)initFrameworkMode;

// 获取资源文件的URL，用于加载图片等资源
- (NSURL *)urlForFileName:(NSString *)fileName extension:(NSString *)fileExtension;

// 创建Kuikly执行环境的实现者
- (id<KuiklyRenderContextProtocol>)createContextHandlerWithContextCode:(NSString *)contextCode
                                                          contextParam:(KuiklyContextParam *)contextParam;

@end

@interface KuiklyContextParam : NSObject

// pageName 页面名 （对应的值为kotlin侧页面注解 @Page("xxxx")中的xxx名）
@property (nonatomic, copy, readonly) NSString *pageName;

// contextMode context产物模式
@property (nonatomic, strong) KuiklyBaseContextMode *contextMode;

/*
 * @brief 初始化context相关参数
 * @param pageName 页面名 （对应的值为kotlin侧页面注解 @Page("xxxx")中的xxx名，区分大小写）
 */
+ (instancetype)newWithPageName:(NSString *)pageName;

@end

NS_ASSUME_NONNULL_END
