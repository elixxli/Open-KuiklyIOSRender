//
//  KRSnapshotModule.h
//  KuiklyIOSRender
//
//  Created by tomqiu on 2023/4/2.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "KRBaseModule.h"

NS_ASSUME_NONNULL_BEGIN
/*
 * @brief 页面快照模块，用于下次打开pager的首屏未出现时以快照作为首屏过渡，实现首屏无任何白屏体验
 */
@interface KRSnapshotModule : KRBaseModule
/*
 * @brief 获取页面快照
 * @param snapshotKey 同kotlin侧设置snapshotPager方法传入的key
 * @return 返回对应的快照图片
 */
+ (UIImage *)snapshotPagerWithSnapshotKey:(NSString *)snapshotKey;

@end

NS_ASSUME_NONNULL_END
