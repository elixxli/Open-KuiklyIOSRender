//
//  KRTurboDisplayNodeMethod.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/2.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRComponentDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    KRTurboDisplayNodeMethodTypeView,
    KRTurboDisplayNodeMethodTypeModule
} KRTurboDisplayNodeMethodType;

@interface KRTurboDisplayNodeMethod : NSObject<NSCoding>

@property (nonatomic, assign) KRTurboDisplayNodeMethodType type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *method;
@property (nonatomic, copy) NSString *params;
@property (nonatomic, copy) KuiklyRenderCallback callback;

- (KRTurboDisplayNodeMethod *)deepCopy;

@end

NS_ASSUME_NONNULL_END
