//
//  KRComponentDefine.h
//  KuiklyProject
//
//  Created by tomqiu on 2022/7/18.
//  Copyright © 2023 Tencent. All rights reserved.
//
// #import "KRComponentDefine.h"
#ifndef KRComponentDefine_h
#define KRComponentDefine_h

#import "UIView+CSS.h"

// Kuikly属性声明宏
#define KUIKLY_PROP(name) css_##name

#define KUIKLY_SET_PROP(key, method) \
if ([propKey isEqualToString:@#key]) { \
    self.key = [KuiklyConvert method:propValue]; \
    return; \
}

#define KUIKLY_SET_CSS_PROP(key, method) \
if ([propKey isEqualToString:@#key]) { \
    self.key = [UIView method:propValue]; \
}

// 设置通用样式
#define KUIKLY_SET_CSS_COMMON_PROP  \
if ([self css_setPropWithKey:propKey value:propValue]) { \
    return ; \
}

// 重置通用样式
#define KUIKLY_RESET_CSS_COMMON_PROP  [self css_reset];

#define KRC_PARAM_KEY @"param"
#define KRC_CALLBACK_KEY @"callback"
// 设置CSS_Method
#define KUIKLY_CALL_CSS_METHOD  \
SEL selector = NSSelectorFromString( [NSString stringWithFormat:@"css_%@:", method] ); \
if ([self respondsToSelector:selector]) { \
    IMP imp = [self methodForSelector:selector]; \
    void (*func)(id, SEL, id) = (void *)imp; \
    NSMutableDictionary *args = [@{} mutableCopy]; \
    if (params) { args[KRC_PARAM_KEY] = params; } \
    if (callback) { args[KRC_CALLBACK_KEY] = callback; } \
    func(self, selector, args); \
}

#define KR_STRONG_SELF_RETURN_IF_NIL \
if (!weakSelf) { \
    return; \
} \
__strong typeof(&*weakSelf) strongSelf = weakSelf; \

#define KR_WEAK_SELF __weak typeof(&*self) weakSelf = self;


#define KR_STRONG_SELF_RETURN_NIL \
if (!weakSelf) { \
    return nil; \
} \
__strong typeof(&*weakSelf) strongSelf = weakSelf; \

#endif /* KRComponentDefine_h */
