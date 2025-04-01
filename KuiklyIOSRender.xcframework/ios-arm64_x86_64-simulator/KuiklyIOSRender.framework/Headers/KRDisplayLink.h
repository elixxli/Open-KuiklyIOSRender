//
//  KRDisplayLink.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/10/29.
//  Copyright © 2023 Tencent. All rights reserved.
//

// KRDisplayLink.h
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef void (^DisplayLinkCallback)(CFTimeInterval timestamp);

@interface KRDisplayLink : NSObject

- (void)startWithCallback:(DisplayLinkCallback)callback;
- (void)stop;
- (void)pause:(BOOL)pause;

@end
