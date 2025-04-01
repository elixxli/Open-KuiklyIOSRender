//
//  KuiklyCoreDefine.h
//  Pods
//
//  Created by luoyibu on 2023/8/8.
//  Copyright © 2023 Tencent. All rights reserved.
//
#pragma once

#ifndef KuiklyErrorDefine_h
#define KuiklyErrorDefine_h

static NSString * const KuiklyLoadErrorDomain = @"KuiklyLoadErrorDomain";

typedef NS_ENUM(NSInteger, KuiklyLoadErrorCode) {
    KuiklyLoadError_fetchContextCode = 10,
    KuiklyLoadError_fatalException = 11,
};

#endif  /* KuiklyErrorDefine_h */
