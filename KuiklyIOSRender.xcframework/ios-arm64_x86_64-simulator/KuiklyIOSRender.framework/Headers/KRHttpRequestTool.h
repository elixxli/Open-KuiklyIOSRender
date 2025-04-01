//
//  KRHttpRequestTool.h
//  Kuikly
//
//  Created by tomqiu on 2019/3/14.
//  Copyright © 2019年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^KRHttpResponse)(NSDictionary * _Nullable result , NSError * _Nullable error);
typedef void (^KRKotlinHttpResponse)(NSString * _Nullable result , NSURLResponse * _Nullable response, NSError * _Nullable error);
typedef void (^KRHttpFileResponse)(NSString * _Nullable path , NSError * _Nullable error);
@interface KRHttpRequestTool : NSObject

+ (void)downloadWithUrl:(NSString * )url param:(NSDictionary * _Nullable)param sotrePath:(NSString * )path responseBlock:(KRHttpFileResponse)response;
+ (void)requestWithMethod:(NSString *)method url:(NSString *)url param:(NSDictionary *)param headers:(NSDictionary *)headerDics timeout:(float)timeout cookie:(NSString * _Nullable)cookie responseBlock:(KRKotlinHttpResponse)response;



@end


@interface KRHttpRequestUtil : NSObject


+ (NSURLSessionDataTask *)requestWithURLRequest:(NSURLRequest *)request completionHandler:(void (^)(NSDictionary * _Nullable json, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
+ (void)downloadWithUrl:(NSString * )url responseBlock:(KRHttpFileResponse)response;
+ (void)requestContentLengthWithUrl:(NSString *)url completionHandler:(void (^)(long long contentLength, NSError * _Nullable error))completionHandler;
+ (NSURLSessionDataTask *)kotlinRequestWithURLRequest:(NSURLRequest *)request completionHandler:(void (^)(NSString * _Nullable json, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
@end

NS_ASSUME_NONNULL_END
