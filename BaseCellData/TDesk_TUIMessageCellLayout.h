
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.

#import <Foundation/Foundation.h>
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

/**
 *【Module Name】TDeskMessageCellLayout
 *【Function description】The layout of message unit
 * - UI layouts for implementing various message units (text, voice, video, images, emoticons, etc.).
 * - When you want to adjust the interface layout in TUIKit, you can modify the corresponding properties in this layout.
 */
@interface TDeskMessageCellLayout : NSObject

/**
 * The insets of message
 */
@property(nonatomic, assign) UIEdgeInsets messageInsets;

/**
 * The insets of bubble content.
 */
@property(nonatomic, assign) UIEdgeInsets bubbleInsets;

/**
 * The insets of avatar
 */
@property(nonatomic, assign) UIEdgeInsets avatarInsets;

/**
 * The size of avatar
 */
@property(nonatomic, assign) CGSize avatarSize;

/////////////////////////////////////////////////////////////////////////////////
//                      Text Message Layout
/////////////////////////////////////////////////////////////////////////////////

/**
 *  Getting text message (receive) layout
 */
+ (TDeskMessageCellLayout *)incommingTextMessageLayout;

/**
 *  Getting text message (send) layout
 */
+ (TDeskMessageCellLayout *)outgoingTextMessageLayout;

/////////////////////////////////////////////////////////////////////////////////
//                      Voice Message Layout
/////////////////////////////////////////////////////////////////////////////////
/**
 *  Getting voice message (receive) layout
 */
+ (TDeskMessageCellLayout *)incommingVoiceMessageLayout;

/**
 *  Getting voice message (send) layout
 */
+ (TDeskMessageCellLayout *)outgoingVoiceMessageLayout;

/////////////////////////////////////////////////////////////////////////////////
//                      System Message Layout
/////////////////////////////////////////////////////////////////////////////////
/**
 *  Getting system message layout
 */
+ (TDeskMessageCellLayout *)systemMessageLayout;

/////////////////////////////////////////////////////////////////////////////////
//                      Image Message Layout
/////////////////////////////////////////////////////////////////////////////////

/**
 *  Getting Image message layout
 */
+ (TDeskMessageCellLayout *)incommingImageMessageLayout;
+ (TDeskMessageCellLayout *)outgoingImageMessageLayout;

/////////////////////////////////////////////////////////////////////////////////
//                      Video Message Layout
/////////////////////////////////////////////////////////////////////////////////

/**
 *  Getting video message layout
 */
+ (TDeskMessageCellLayout *)incommingVideoMessageLayout;
+ (TDeskMessageCellLayout *)outgoingVideoMessageLayout;



/////////////////////////////////////////////////////////////////////////////////
//                     Other Message Layout
/////////////////////////////////////////////////////////////////////////////////
/**
 *  Getting receive message layout
 */
+ (TDeskMessageCellLayout *)incommingMessageLayout;

/**
 *  Getting send message layout
 */
+ (TDeskMessageCellLayout *)outgoingMessageLayout;

@end

NS_ASSUME_NONNULL_END
