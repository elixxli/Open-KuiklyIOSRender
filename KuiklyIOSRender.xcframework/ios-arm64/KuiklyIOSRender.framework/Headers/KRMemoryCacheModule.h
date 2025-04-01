//
//  KRMemoryCacheModule.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/7/31.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KuiklyRenderModuleExportProtocol.h"
#import "KRBaseModule.h"

NS_ASSUME_NONNULL_BEGIN

@interface KRMemoryCacheModule : KRBaseModule

- (id)memoryObjectForKey:(NSString *)key;
- (void)setMemoryObjectWithKey:(NSString *)key value:(id)value;
- (UIImage*)imageWithKey:(NSString*)key;
@end

NS_ASSUME_NONNULL_END
