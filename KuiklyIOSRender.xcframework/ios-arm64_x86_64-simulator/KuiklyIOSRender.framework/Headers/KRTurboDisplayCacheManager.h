//
//  KRTurboDisplayCacheManager.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/12/3.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KRTurboDisplayNode;
@class KRTurboDisplayCacheData;
/*
 * @brief TurboDisplay首屏渲染指令二进制文件缓存管理
 */

@interface KRTurboDisplayCacheManager : NSObject

+ (instancetype)sharedInstance;
/*
 * @brief 缓存node
 */
- (void)cacheWithViewNode:(KRTurboDisplayNode *)viewNode cacheKey:(NSString *)key;
/*
 * @brief 获取缓存node（注：获取之后内部自动删除，避免缓存文件有问题时一直处于问题）
 */
- (KRTurboDisplayCacheData *)nodeWithCachKey:(NSString *)cacheKey;

- (void)removeCacheWithKey:(NSString *)cacheKey;

/*
 * @brief 返回对应缓存Key
 */
- (NSString *)cacheKeyWithTurboDisplayKey:(NSString *)turboDisplayKey pageName:(NSString *)pageName;

/*
 * @brief 删除所有TurboDisplay缓存文件
 */
- (void)removeAllTurboDisplayCacheFiles;
/*
 * @brief 是否存在该缓存key的节点
 */
- (BOOL)hasNodeWithCacheKey:(NSString *)cacheKey;
/*
 * @brief 缓存Node节点的NSData二进制数据，用于回写
 */
- (void)cacheWithViewNodeData:(NSData *)nodeData cacheKey:(NSString *)cacheKey;

@end

@interface KRTurboDisplayCacheData : NSObject

@property (nonatomic, strong, nullable) KRTurboDisplayNode *turboDisplayNode;
@property (nonatomic, strong, nullable) NSData *turboDisplayNodeData;

@end

NS_ASSUME_NONNULL_END
