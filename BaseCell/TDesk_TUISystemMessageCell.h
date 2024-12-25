
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.
/**
 *
 *  This file declares the TDeskSystemMessageCell class, which is responsible for displaying system messages.
 *  The system message unit is responsible for displaying special messages from the system. Such messages are usually white on a gray background and centered.
 */
#import "TDesk_TUIMessageCell.h"
#import "TDesk_TUISystemMessageCellData.h"

/**
 * 【Module name】 TDeskSystemMessageCell
 * 【Function description】System message unit
 *  - It is used to display the system messages. Common system messages include: recall-message, group-member-change-message, group-created and
 * group-diss-message, etc.
 *  - System messages are typically used to display notifications from apps that are sent by the system, not from any user.
 */
@interface TDeskSystemMessageCell : TDeskMessageCell

/**
 *
 *  The label of display system message content, such as "You recalled a message.".
 */
@property(readonly) UILabel *messageLabel;

@property(readonly) TDeskSystemMessageCellData *systemData;

- (void)fillWithData:(TDeskSystemMessageCellData *)data;
@end
