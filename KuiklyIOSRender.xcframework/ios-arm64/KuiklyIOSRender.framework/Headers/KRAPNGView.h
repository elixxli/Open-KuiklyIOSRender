//
//  KRAPNGView.h
//  KuiklyIOSRender
//  Copyright © 2023 Tencent. All rights reserved.
//  Created by Mac on 2023/7/19.
//

#import <UIKit/UIKit.h>
#import "KuiklyRenderViewExportProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol APNGImageViewProtocol;

/// APNG组件动画播放回调
@protocol APNGViewPlayDelegate <NSObject>

@optional

/// 播放结束接口
/// - Parameter apngImageView: apngView视图
/// - Parameter loopCount: 已播放次数
- (void)apngImageView:(id<APNGImageViewProtocol> _Nonnull)apngImageView playEndLoop:(NSUInteger)loopCount;


@end

@protocol APNGImageViewProtocol <NSObject>

/// apngView动画播放代理
@property (nonatomic, weak, nullable) id<APNGViewPlayDelegate> delegate;

/// 播放次数，0表示无限循环，如果不设置，则会使用从apng图解析出来的count
@property (nonatomic, assign) NSInteger playCount;

/// 设置图片路径（优先实现该setFilePath）
/// @param filePath 图片路径
/// @param completion 图片解析完成后回调，返回第一帧图片内容
- (void)setFilePath:(NSString *_Nullable)filePath withCompletion:(void (^_Nullable)(UIImage * _Nullable image))completion;
/// 设置图片路径
/// @param filePath 图片路径
- (void)setFilePath:(NSString *_Nullable)filePath ;


/// 开始播放动画（第一次播放调用该接口，从第一帧开始）
- (void)startAPNGAnimating;

/// 停止播放动画
- (void)stopAPNGAnimating;

@optional
/// 动画播放停止时暂时最后一帧动画
@property (nonatomic, assign) BOOL showLastImgaeWhenPause;


@end

typedef id<APNGImageViewProtocol> _Nonnull (^APNGViewCreator)(CGRect frame);
@interface KRAPNGView : UIView<KuiklyRenderViewExportProtocol>
/*
 * @brief 注册自定义APNGView实现
 * @param creator 创建apngView实现者实例
 */
+ (void)registerAPNGViewCreator:(APNGViewCreator)creator;

// 预下载cdn apng资源并缓存
+ (void)preDownloadIfNeedWithCDNUrl:(NSString *)cdnUrl;
+ (BOOL)isCdnUrl:(NSString *)url;
@end

NS_ASSUME_NONNULL_END
