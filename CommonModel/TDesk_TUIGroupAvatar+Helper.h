//
//  TDeskGroupAvatar+Helper.h
//  TIMCommon
//
//  Created by wyl on 2023/4/27.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <TDeskCore/TDesk_TUIDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface TDeskGroupAvatar (Helper)

+ (UIImage *)getNormalGroupCacheAvatar:(NSString *)groupID groupType:(NSString *)groupType;

+ (void)configAvatarByParam:(NSDictionary *)param targetView:(UIImageView *)targetView;

@end

NS_ASSUME_NONNULL_END
