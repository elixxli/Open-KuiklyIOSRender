//
//  KRMultiDelegateProxy.h
//
//  Created by tomqiu on 2023/2/15.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
 * 一对多代理转发类
 */
@interface KRMultiDelegateProxy : NSProxy
/* 添加代理 */
- (void)addDelegate:(NSObject *)delegate;
/* 删除代理 */
- (void)removeDelegate:(NSObject *)delegate;

@end
NS_ASSUME_NONNULL_END
