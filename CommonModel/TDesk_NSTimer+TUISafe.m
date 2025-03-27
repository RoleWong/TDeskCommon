//
//  NSTimer+TUISafe.m
//  TDeskCore
//
//  Created by wyl on 2022/7/5.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_NSTimer+TUISafe.h"

@implementation NSTimer (TUISafe)
+ (NSTimer *)tdesk_scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats block:(void (^)(NSTimer *timer))block {
    return [self scheduledTimerWithTimeInterval:interval target:self selector:@selector(tdesk_callBlock:) userInfo:[block copy] repeats:repeats];
}

+ (void)tdesk_callBlock:(NSTimer *)timer {
    void (^block)(NSTimer *timer) = timer.userInfo;
    !block ?: block(timer);
}

@end
