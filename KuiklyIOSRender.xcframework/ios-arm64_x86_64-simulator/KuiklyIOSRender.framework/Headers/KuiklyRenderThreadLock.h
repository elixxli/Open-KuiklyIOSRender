//
//  KuiklyRenderThreadLock.h
//  KuiklyProject
//
//  Created by tomqiu on 2023/2/3.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KuiklyRenderThreadLock : NSObject

/*
 * 线程安全
 */
- (void)threadSafeInBlock:(dispatch_block_t)block;

@end

NS_ASSUME_NONNULL_END
