//
//  KuiklyRenderViewControllerDelegator.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/7/9.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "KuiklyRenderViewControllerBaseDelegator.h"

NS_ASSUME_NONNULL_BEGIN

@interface KuiklyRenderViewControllerBaseDelegator (Extension)
/// kuikly页面名称
@property (nonatomic, strong) NSString *pageName;
/// kuikly视图
@property (nullable, nonatomic, weak) UIView * view;

/*
 * @brief 获取kmm工程打包的framework名字，并将获取到的名字传入callback处理
 * @param callback 处理获取到的framework名字的回调函数
 */
- (void)fetchContextCodeWithResultCallback:(KuiklyContextCodeCallback)callback;
/*
 * @brief 创建Kuikly接入模式实例
 * @param contextCode kmm工程打包的framework名字
 */
- (KuiklyBaseContextMode *)createContextMode:(NSString * _Nullable) contextCode;
/*
 * @brief 初始化renderView
 * @param contextCode kmm工程打包的framework名字
 */
- (void)initRenderViewWithContextCode:(NSString *)contextCode;

@end

NS_ASSUME_NONNULL_END

