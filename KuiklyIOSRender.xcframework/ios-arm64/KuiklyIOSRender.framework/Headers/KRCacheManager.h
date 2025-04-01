//
//  KRCacheManager.h
//  KuiklyIOSRender
//
//  Created by 邱良雄 on 2024/6/2.
//  Copyright © 2024 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KRCacheProtocol <NSObject>

@optional

/*
 * 指定Kuikly sdk内所有缓存的根缓存路径，默认为系统Cache/kuikly作为目录
 */
- (NSString * _Nonnull)kr_rootCachePath;



@end

NS_ASSUME_NONNULL_BEGIN

@interface KRCacheManager : NSObject

/*
 * @brief 注册Cache的自定义实现
 */
+ (void)registerCacheHandler:(id<KRCacheProtocol>)cacheHandler;

+ (instancetype)sharedInstance;
/*
 * 根据文件夹名返回对应缓存全路径
 * @param folderName 文件夹名词，即返回rootCachePath/folderName, 如果该参数为空，则返回rootCachePath
 */
- (NSString *)cachePathWithFolderName:(NSString * _Nullable)folderName;


@end

NS_ASSUME_NONNULL_END
