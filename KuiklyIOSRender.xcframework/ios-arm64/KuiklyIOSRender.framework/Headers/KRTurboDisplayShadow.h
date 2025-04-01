//
//  KRTurboDisplayShadow.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/3.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class KRTurboDisplayProp;
@class KRTurboDisplayNodeMethod;
@interface KRTurboDisplayShadow : NSObject<NSCoding>

@property (nonatomic, strong, readonly) NSNumber *tag;
@property (nonatomic, copy, readonly) NSString *viewName;
@property (nonatomic, strong, readonly) NSMutableArray<KRTurboDisplayProp *> *props;
@property (nonatomic, strong, readonly) NSValue *constraintSize;
@property (nonatomic, strong, readonly) NSMutableArray<KRTurboDisplayNodeMethod *> *callMethods;

- (instancetype)initWithTag:(NSNumber *)tag viewName:(NSString *)viewName;

- (void)setPropWithKey:(NSString *)propKey propValue:(id)propValue;

- (void)calculateWithConstraintSize:(CGSize)constraintSize;

- (void)addMethodWithName:(NSString *)name params:(NSString *)params;

- (KRTurboDisplayShadow *)deepCopy;

@end

NS_ASSUME_NONNULL_END
