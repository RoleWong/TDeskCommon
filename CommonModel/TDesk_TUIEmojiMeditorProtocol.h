//
//  TDeskEmojiMeditorProtocol.h
//  TUIEmojiPlugin
//
//  Created by wyl on 2023/11/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TDesk_TIMDefine.h"
#import "TDesk_TIMCommonModel.h"
@class V2TIMMessage;
@class TDeskFaceGroup;

NS_ASSUME_NONNULL_BEGIN

@protocol TDeskEmojiMeditorProtocol <NSObject>
- (void)updateEmojiGroups;
- (id)getFaceGroup;
- (void)appendFaceGroup:(TDeskFaceGroup *)faceGroup;
- (id)getChatPopDetailGroups;
- (id)getChatContextEmojiDetailGroups;
- (id)getChatPopMenuRecentQueue;
- (void)updateRecentMenuQueue:(NSString *)faceName;
@end

NS_ASSUME_NONNULL_END
