//
//  TDeskCommonMediator.m
//  TUIEmojiPlugin
//
//  Created by cologne on 2023/11/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_TIMCommonMediator.h"

@interface TDeskCommonMediator()
@property (nonatomic, strong) NSMutableDictionary *map;
@end

@implementation TDeskCommonMediator

+ (instancetype)share {
    static TDeskCommonMediator *mediator = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        mediator = [TDeskCommonMediator new];
        mediator.map = [NSMutableDictionary new];
    });
    return mediator;
}

- (void)registerService:(Protocol *)service class:(Class)cls {
    if (!service || !cls) return;
    self.map[NSStringFromProtocol(service)] = cls;
}

- (id)getObject:(Protocol *)service {
    if (!service) return nil;
    Class cls = self.map[NSStringFromProtocol(service)];
    id obj = [cls new];
    if ([obj conformsToProtocol:service]) {
        return obj;
    }
    return nil;
}
@end
