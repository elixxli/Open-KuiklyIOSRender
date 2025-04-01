//
//  KRTurboDisplayNode.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/2.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRTurboDisplayNodeMethod.h"
#import "KRTurboDisplayProp.h"

#define FRAME_KEY  @"frame"
#define SHADOW_KEY  @"shadow"
#define INSERT_KEY  @"insert"

NS_ASSUME_NONNULL_BEGIN

@protocol KuiklyRenderShadowProtocol;
@class KRTurboDisplayShadow;
@interface KRTurboDisplayNode : NSObject<NSCoding>

@property (nonatomic, strong) NSNumber *tag;
@property (nonatomic, strong) NSString *viewName;
@property (nonatomic, strong, nullable) NSNumber *parentTag;
@property (nonatomic, strong) NSMutableArray<KRTurboDisplayNode *> *children;
@property (nonatomic, strong, readonly) NSMutableArray<KRTurboDisplayProp *> *props;
@property (nonatomic, strong, readonly) NSMutableArray<KRTurboDisplayNodeMethod *> *callMethods;
@property (nonatomic, strong) id renderShadow; // 真实shadow，内存字段，不参与序列化
@property (nonatomic, strong) NSNumber* scrollIndex; // computed property
@property (nonatomic, assign) CGRect renderFrame; // computed property
@property (nonatomic, assign) BOOL addViewMethodDisable;


- (instancetype)initWithTag:(NSNumber *)tag viewName:(NSString *)viewName;

- (void)insertSubNode:(KRTurboDisplayNode *)subNode index:(NSInteger)index;

- (void)removeFromParentNode:(KRTurboDisplayNode *)parentNode;

- (void)addViewMethodWithMethod:(NSString *)method
                         params:(NSString * _Nullable)params
                       callback:(KuiklyRenderCallback _Nullable)callback;

- (void)addModuleMethodWithModuleName:(NSString *)moduelName
                               method:(NSString *)method
                               params:(NSString * _Nullable)params
                             callback:(KuiklyRenderCallback _Nullable)callback;

- (void)setPropWithKey:(NSString *)propKey propValue:(id)propValue;

- (void)setFrame:(CGRect)frame;

- (void)setShadow:(KRTurboDisplayShadow *)shadow;

- (void)setPropWithKey:(NSString *)propKey propValue:(id)propValue propType:(KRTurboDisplayPropType)type;

- (KRTurboDisplayProp *)propWithKey:(NSString *)key;

- (BOOL)hasChild;

- (KRTurboDisplayNode *)deepCopy;

@end

NS_ASSUME_NONNULL_END
