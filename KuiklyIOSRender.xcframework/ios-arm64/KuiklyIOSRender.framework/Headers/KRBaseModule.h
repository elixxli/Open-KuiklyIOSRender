//
//  KRBaseModule.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/10/25.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KuiklyRenderModuleExportProtocol.h"
#import <UIKit/UIKit.h>
#import "NSObject+KR.h"
#import "KuiklyRenderView.h"
#import <TDFCommon/TDFBaseModule.h>
NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString *const KR_PARAM_KEY;
UIKIT_EXTERN NSString *const KR_CALLBACK_KEY;

@interface KRBaseModule : TDFBaseModule<KuiklyRenderModuleExportProtocol>

/*
 * @brief 获取kotlin侧tag(nativeRef)对应的Native View实例（仅支持在主线程调用）.
 * @param tag view对应的索引
 * @return view实例
 */
- (UIView * _Nullable)viewWithTag:(NSNumber *)tag;

@end

NS_ASSUME_NONNULL_END
