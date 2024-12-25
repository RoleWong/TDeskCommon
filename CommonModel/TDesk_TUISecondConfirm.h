//
//  TDeskSecondConfirm.h
//  TIMCommon
//
//  Created by xiangzhang on 2023/5/15.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^TDeskSecondConfirmBtnClickCallback)(void);
@interface TDeskSecondConfirmBtnInfo : NSObject
@property(nonatomic, strong) NSString *tile;
@property(nonatomic, copy) TDeskSecondConfirmBtnClickCallback click;
@end

@interface TDeskSecondConfirm : NSObject
+ (void)show:(NSString *)title cancelBtnInfo:(TDeskSecondConfirmBtnInfo *)cancelBtnInfo confirmBtnInfo:(TDeskSecondConfirmBtnInfo *)confirmBtnInfo;
@end

NS_ASSUME_NONNULL_END
