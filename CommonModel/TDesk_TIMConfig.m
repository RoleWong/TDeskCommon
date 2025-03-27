//
//  TDeskIMConfig.m
//  Pods
//
//  Created by cologne on 2023/3/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_TIMConfig.h"
#import "TDesk_TIMCommonMediator.h"
#import "TDesk_TUIEmojiMeditorProtocol.h"
#define kTUIKitFirstInitAppStyleID @"Classic";  // Classic / Minimalist

typedef NS_OPTIONS(NSInteger, emojiFaceType) {
    emojiFaceTypeKeyBoard = 1 << 0,
    emojiFaceTypePopDetail = 1 << 1,
};

@interface TDeskIMConfig ()

@end

@implementation TDeskIMConfig

+ (void)load {
    TDeskRegisterThemeResourcePath(TDeskCommonThemePath, TUIThemeModuleTIMCommon);
}

- (id)init {
    self = [super init];
    if (self) {
        self.enableMessageBubble = YES;
    }
    return self;
}

+ (id)defaultConfig {
    static dispatch_once_t onceToken;
    static TDeskIMConfig *config;
    dispatch_once(&onceToken, ^{
      config = [[TDeskIMConfig alloc] init];
    });
    return config;
}

- (NSArray<TDeskFaceGroup *> *)faceGroups {
    id<TDeskEmojiMeditorProtocol> service = [[TDeskCommonMediator share] getObject:@protocol(TDeskEmojiMeditorProtocol)];
    return [service getFaceGroup];
}

- (NSArray<TDeskFaceGroup *> *)chatPopDetailGroups {
    id<TDeskEmojiMeditorProtocol> service = [[TDeskCommonMediator share] getObject:@protocol(TDeskEmojiMeditorProtocol)];
    return [service getChatPopDetailGroups];
}

+ (NSString *)getCurrentStyleSelectID {
    NSString *styleID = [[NSUserDefaults standardUserDefaults] objectForKey:@"StyleSelectkey"];
    if (IS_NOT_EMPTY_NSSTRING(styleID)) {
        return styleID;
    } else {
        // First Init
        NSString *initStyleID = kTUIKitFirstInitAppStyleID;
        [[NSUserDefaults standardUserDefaults] setValue:initStyleID forKey:@"StyleSelectkey"];
        [NSUserDefaults.standardUserDefaults synchronize];
        return initStyleID;
    }
}

+ (BOOL)isClassicEntrance {
    NSString *styleID = [self.class getCurrentStyleSelectID];
    if ([styleID isKindOfClass:NSString.class]) {
        if (styleID.length > 0) {
            if ([styleID isEqualToString:@"Classic"]) {
                return YES;
            }
        }
    }
    return NO;
}
@end
