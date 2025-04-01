//
//  KRTurboDisplayProp.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/2.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRComponentDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    KRTurboDisplayPropTypeAttr,
    KRTurboDisplayPropTypeEvent,
    KRTurboDisplayPropTypeFrame,
    KRTurboDisplayPropTypeShadow,
    KRTurboDisplayPropTypeInsert
} KRTurboDisplayPropType;

@interface KRTurboDisplayProp : NSObject<NSCoding>

@property (nonatomic, strong ) NSString *propKey;
@property (nonatomic, strong) id propValue;
@property (nonatomic, assign ) KRTurboDisplayPropType propType;

- (instancetype)initWithType:(KRTurboDisplayPropType)type propKey:(NSString *)propKey propValue:(id)propValue;

- (void)lazyEventIfNeed;

- (void)performLazyEventToCallback:(KuiklyRenderCallback)callback;

- (KRTurboDisplayProp *)deepCopy;
@end

NS_ASSUME_NONNULL_END
