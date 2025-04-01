//
//  KRAsyncDeallocManager.h
//  iosApp
//
//  Created by tomqiu on 2023/2/14.
//  Copyright © 2023 orgName. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KRAsyncDeallocManager : NSObject


+ (instancetype)shareManager;

- (void)asyncDeallocWithObject:(id _Nullable)deallocObject;


@end

NS_ASSUME_NONNULL_END
