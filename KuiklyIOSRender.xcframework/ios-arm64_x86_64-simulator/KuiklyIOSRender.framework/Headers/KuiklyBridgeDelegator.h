//
//  KuiklyBridgeDelegator.h
//  KuiklyIOSRender
//
//  Created by luoyibu on 2023/9/5.
//

#import <Foundation/Foundation.h>
#import <TDFCommon/TDFModuleProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class KuiklyRenderView;

@interface KuiklyBridgeDelegator : NSObject <TDFBridgeDelegate>

- (instancetype)initWithRootView:(UIView *)rootView;

@end

NS_ASSUME_NONNULL_END
