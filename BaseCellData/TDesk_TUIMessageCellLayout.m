//
//  TDeskMessageCellLayout.m
//  TXIMSDK_TUIKit_iOS
//
//  Created by annidyfeng on 2019/5/21.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_TUIMessageCellLayout.h"
#import <TDeskCommon/TDesk_TIMDefine.h>

@implementation TDeskMessageCellLayout

- (instancetype)init:(BOOL)isIncomming {
    self = [super init];
    if (self) {
        self.avatarSize = CGSizeMake(40, 40);
        if (isIncomming) {
            self.avatarInsets = (UIEdgeInsets){
                .left = 8,
                .top = 3,
                .bottom = 1,
            };
            self.messageInsets = (UIEdgeInsets){
                .top = 3,
                .bottom = 17,
                .left = 8,
            };
        } else {
            self.avatarInsets = (UIEdgeInsets){
                .right = 8,
                .top = 3,
                .bottom = 1,
            };
            self.messageInsets = (UIEdgeInsets){
                .top = 3,
                .bottom = 17,
                .right = 8,
            };
        }
    }
    return self;
}

static TDeskMessageCellLayout *gIncommingMessageLayout;

+ (TDeskMessageCellLayout *)incommingMessageLayout {
    if (!gIncommingMessageLayout) {
        gIncommingMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
    }
    return gIncommingMessageLayout;
}

static TDeskMessageCellLayout *gOutgoingMessageLayout;

+ (TDeskMessageCellLayout *)outgoingMessageLayout {
    if (!gOutgoingMessageLayout) {
        gOutgoingMessageLayout = [[TDeskMessageCellLayout alloc] init:NO];
    }
    return gOutgoingMessageLayout;
}

#pragma Text CellLayout

static TDeskMessageCellLayout *gIncommingTextMessageLayout;

+ (TDeskMessageCellLayout *)incommingTextMessageLayout {
    if (!gIncommingTextMessageLayout) {
        gIncommingTextMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
        gIncommingTextMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 10.5, .bottom = 10.5, .left = 16, .right = 16};
    }
    return gIncommingTextMessageLayout;
}

static TDeskMessageCellLayout *gOutgingTextMessageLayout;

+ (TDeskMessageCellLayout *)outgoingTextMessageLayout {
    if (!gOutgingTextMessageLayout) {
        gOutgingTextMessageLayout = [[TDeskMessageCellLayout alloc] init:NO];
        gOutgingTextMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 10.5, .bottom = 10.5, .left = 16, .right = 16};
    }
    return gOutgingTextMessageLayout;
}

#pragma Voice CellLayout

static TDeskMessageCellLayout *gIncommingVoiceMessageLayout;

+ (TDeskMessageCellLayout *)incommingVoiceMessageLayout {
    if (!gIncommingVoiceMessageLayout) {
        gIncommingVoiceMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
        gIncommingVoiceMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 12, .bottom = 12, .left = 16, .right = 16};
    }
    return gIncommingVoiceMessageLayout;
}

static TDeskMessageCellLayout *gOutgingVoiceMessageLayout;

+ (TDeskMessageCellLayout *)outgoingVoiceMessageLayout {
    if (!gOutgingVoiceMessageLayout) {
        gOutgingVoiceMessageLayout = [[TDeskMessageCellLayout alloc] init:NO];
        gOutgingVoiceMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 14, .bottom = 20, .left = 22, .right = 20};
    }
    return gOutgingVoiceMessageLayout;
}

#pragma System CellLayout

static TDeskMessageCellLayout *gSystemMessageLayout;

+ (TDeskMessageCellLayout *)systemMessageLayout {
    if (!gSystemMessageLayout) {
        gSystemMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
        gSystemMessageLayout.messageInsets = (UIEdgeInsets){.top = 5, .bottom = 5};
    }
    return gSystemMessageLayout;
}

#pragma Image CellLayout

static TDeskMessageCellLayout *gIncommingImageMessageLayout;
+ (TDeskMessageCellLayout *)incommingImageMessageLayout {
    if (!gIncommingImageMessageLayout) {
        gIncommingImageMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
        gIncommingImageMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 0, .bottom = 0, .left = 0 ,.right = 0};
    }
    return gIncommingImageMessageLayout;
}

static TDeskMessageCellLayout *gOutgoingImageMessageLayout;
+ (TDeskMessageCellLayout *)outgoingImageMessageLayout {
    if (!gOutgoingImageMessageLayout) {
        gOutgoingImageMessageLayout = [[TDeskMessageCellLayout alloc] init:NO];
        gOutgoingImageMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 0, .bottom = 0, .left = 0 ,.right = 0};
    }
    return gOutgoingImageMessageLayout;
}

#pragma Video CellLayout
static TDeskMessageCellLayout *gIncommingVideoMessageLayout;

+ (TDeskMessageCellLayout *)incommingVideoMessageLayout {
    if (!gIncommingVideoMessageLayout) {
        gIncommingVideoMessageLayout = [[TDeskMessageCellLayout alloc] init:YES];
        gIncommingVideoMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 0, .bottom = 0, .left = 0 ,.right = 0};
    }
    return gIncommingVideoMessageLayout;
}

static TDeskMessageCellLayout *gOutgoingVideoMessageLayout;

+ (TDeskMessageCellLayout *)outgoingVideoMessageLayout {
    if (!gOutgoingVideoMessageLayout) {
        gOutgoingVideoMessageLayout = [[TDeskMessageCellLayout alloc] init:NO];
        gOutgoingVideoMessageLayout.bubbleInsets = (UIEdgeInsets){.top = 0, .bottom = 0, .left = 0 ,.right = 0};
    }
    return gOutgoingVideoMessageLayout;
}

@end
