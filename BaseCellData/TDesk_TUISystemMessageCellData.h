
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.
/**
 * This file declares the TDeskSystemMessageCellData class.
 * This class inherits from TDeskMessageCellData and is used to store a series of data and information required by the system message unit.
 */
#import "TDesk_TUIMessageCellData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TDeskSystemMessageType) {
    TUISystemMessageTypeUnknown = 0,
    TUISystemMessageTypeDate = 1,
};

/**
 * 【Module name】TDeskSystemMessageCellData
 * 【Function description】The datasource of system message unit.
 */
@interface TDeskSystemMessageCellData : TDeskMessageCellData

/**
 *  The content of system message, such as "You recalled a message.".
 */
@property(nonatomic, strong) NSString *content;

/**
 *  The flag of whether supporting re-edit.
 */
@property(nonatomic, assign) BOOL supportReEdit;

/**
 *  Mutable string
 *  The recalled message can be re-edited within 2 minutes, which is displayed here based on attributedString.
 */
@property(nonatomic, strong, nullable) NSMutableAttributedString *attributedString;

/**
 *  The font of label which displays the system message content.
 */
@property(nonatomic, strong, nullable) UIFont *contentFont;

/**
 *  The color of label which displays the system message content.
 */
@property(nonatomic, strong, nullable) UIColor *contentColor;

/**
 * The type of system message type, default is TUISystemMessageTypeUnknown
 */
@property(nonatomic, assign) TDeskSystemMessageType type;

@property(nonatomic, strong) NSArray<NSString *> *replacedUserIDList;

@end

NS_ASSUME_NONNULL_END
