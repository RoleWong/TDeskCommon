//
//  TDeskRelationUserModel.m
//  TIMCommon
//
//  Created by wyl on 2023/12/5.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_TUIRelationUserModel.h"
#import <TDeskCommon/TDesk_TIMDefine.h>

@implementation TDeskRelationUserModel

- (NSString *)getDisplayName {
    if (IS_NOT_EMPTY_NSSTRING(self.nameCard)) {
        return self.nameCard;
    } else if (IS_NOT_EMPTY_NSSTRING(self.friendRemark)) {
        return self.friendRemark;
    } else if (IS_NOT_EMPTY_NSSTRING(self.nickName)) {
        return self.nickName;
    } else {
        return self.userID;
    }
    return @"";
}
@end
