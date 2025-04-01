//
//  KRWeakObject.h
//
//  Created by tomqiu on 2023/2/10.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KRWeakObject : NSObject

@property (nonatomic, weak, readonly) id weakObject;

- (instancetype)initWithObject:(id)object;



@end

NS_ASSUME_NONNULL_END
