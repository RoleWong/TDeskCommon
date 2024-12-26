//
//  TIMDefine.h
//  Pods
//
//  Created by cologne on 2023/3/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#ifndef TIMDefine_h
#define TIMDefine_h

#import <ReactiveObjCForTDesk/TDesk_ReactiveObjC.h>
#import <TDeskCore/TDesk_TUIDefine.h>
#import <MasonryForTDesk/Masonry.h>
#import "TDesk_TIMConfig.h"
#import "TDesk_TIMCommonModel.h"
#import "TDesk_TIMRTLUtil.h"

#define kEnableAllRotationOrientationNotification @"kEnableAllRotationOrientationNotification"
#define kDisableAllRotationOrientationNotification @"kDisableAllRotationOrientationNotification"
#define TUIMessageMediaViewDeviceOrientationChangeNotification @"TUIMessageMediaViewDeviceOrientationChangeNotification"

//Provide customers with the ability to modify the default emoji expression size in various input behaviors
#define kTIMDefaultEmojiSize CGSizeMake(23, 23)

#endif /* TIMDefine_h */
