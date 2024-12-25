//
//  TIMCommonModel.h
//  TIMCommon
//
//  Created by cologne on 2023/3/14.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TDeskCore/TDesk_TUICommonModel.h>
#import "TDesk_TIMDefine.h"

NS_ASSUME_NONNULL_BEGIN
////////////////////////////////////////////////////////////////////////////////
//
//                           TUIPopView
//
/////////////////////////////////////////////////////////////////////////////////
@class TUIPopView;
@protocol TUIPopViewDelegate <NSObject>
- (void)popView:(TUIPopView *)popView didSelectRowAtIndex:(NSInteger)index;
@end

@interface TUIPopView : UIView
@property(nonatomic, strong) UITableView *tableView;
@property(nonatomic, assign) CGPoint arrowPoint;
@property(nonatomic, weak) id<TUIPopViewDelegate> delegate;
- (void)setData:(NSMutableArray *)data;
- (void)showInWindow:(UIWindow *)window;
@end

@interface TUIPopCellData : NSObject
@property(nonatomic, strong) UIImage *image;
@property(nonatomic, strong) NSString *title;
@end

@interface TUIPopCell : UITableViewCell
@property(nonatomic, strong) UIImageView *image;
@property(nonatomic, strong) UILabel *title;
+ (CGFloat)getHeight;
- (void)setData:(TUIPopCellData *)data;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TUIModifyView
//
/////////////////////////////////////////////////////////////////////////////////
@class TUIModifyView;
@protocol TUIModifyViewDelegate <NSObject>
- (void)modifyView:(TUIModifyView *)modifyView didModiyContent:(NSString *)content;
@end

@interface TUIModifyViewData : NSObject
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *content;
@property(nonatomic, strong) NSString *desc;
@property(nonatomic, assign) BOOL enableNull;
@end

@interface TUIModifyView : UIView
@property(nonatomic, strong) UIView *container;
@property(nonatomic, strong) UILabel *title;
@property(nonatomic, strong) UITextField *content;
@property(nonatomic, strong) UILabel *descLabel;
@property(nonatomic, strong) UIButton *confirm;
@property(nonatomic, strong) UIView *hLine;
@property(nonatomic, weak) id<TUIModifyViewDelegate> delegate;
- (void)setData:(TUIModifyViewData *)data;
- (void)showInWindow:(UIWindow *)window;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TUINaviBarIndicatorView
//
/////////////////////////////////////////////////////////////////////////////////
@interface TUINaviBarIndicatorView : UIView

@property(nonatomic, strong) UIActivityIndicatorView *indicator;

@property(nonatomic, strong) UILabel *label;

@property(nonatomic, assign) CGFloat maxLabelLength;

- (void)setTitle:(NSString *)title;

- (void)startAnimating;

- (void)stopAnimating;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TUICommonCell & data
//
/////////////////////////////////////////////////////////////////////////////////

@interface TDeskCommonCellData : NSObject
@property(strong) NSString *reuseId;
@property(nonatomic, assign) SEL cselector;
@property(nonatomic, strong) NSDictionary *ext;
- (CGFloat)heightOfWidth:(CGFloat)width;
- (CGFloat)estimatedHeight;
@end

@interface TDeskCommonTableViewCell : UITableViewCell

@property(readonly) TDeskCommonCellData *data;
@property UIColor *colorWhenTouched;
@property BOOL changeColorWhenTouched;

- (void)fillWithData:(TDeskCommonCellData *)data;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TDeskCommonTextCell & data
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskCommonTextCellData : TDeskCommonCellData

@property NSString *key;
@property NSString *value;
@property BOOL showAccessory;
@property UIColor *keyColor;
@property UIColor *valueColor;
@property BOOL enableMultiLineValue;

@property(nonatomic, assign) UIEdgeInsets keyEdgeInsets;

@end

@interface TDeskCommonTextCell : TDeskCommonTableViewCell
@property UILabel *keyLabel;
@property UILabel *valueLabel;
@property(readonly) TDeskCommonTextCellData *textData;

- (void)fillWithData:(TDeskCommonTextCellData *)data;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TDeskCommonSwitchCell & data
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskCommonSwitchCellData : TDeskCommonCellData

@property NSString *title;
@property NSString *desc;
@property(getter=isOn) BOOL on;
@property CGFloat margin;
@property SEL cswitchSelector;

@property(nonatomic, assign) BOOL displaySeparatorLine;

@property(nonatomic, assign) BOOL disableChecked;

@end

@interface TDeskCommonSwitchCell : TDeskCommonTableViewCell
@property UILabel *titleLabel;  // main title label
@property UILabel *descLabel;   // detail title label below the main title label, used for explaining details
@property UISwitch *switcher;

@property(readonly) TDeskCommonSwitchCellData *switchData;

- (void)fillWithData:(TDeskCommonSwitchCellData *)data;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TDeskButtonCell & data
//
/////////////////////////////////////////////////////////////////////////////////
typedef enum : NSUInteger {
    ButtonGreen,
    ButtonWhite,
    ButtonRedText,
    ButtonBule,
} TDeskButtonStyle;

@interface TDeskButtonCellData : TDeskCommonCellData
@property(nonatomic, strong) NSString *title;
@property SEL cbuttonSelector;
@property TDeskButtonStyle style;
@property(nonatomic, strong) UIColor *textColor;
@property(nonatomic, assign) BOOL hideSeparatorLine;
@end

@interface TDeskButtonCell : TDeskCommonTableViewCell
@property(nonatomic, strong) UIButton *button;
@property TDeskButtonCellData *buttonData;

- (void)fillWithData:(TDeskButtonCellData *)data;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskGroupPendencyCell & data
//
/////////////////////////////////////////////////////////////////////////////////
#define TUIGroupPendencyCellData_onPendencyChanged @"TUIGroupPendencyCellData_onPendencyChanged"

@interface TDeskGroupPendencyCellData : TDeskCommonCellData

@property(nonatomic, strong) NSString *groupId;

@property(nonatomic, strong) NSString *fromUser;

@property(nonatomic, strong) NSString *toUser;

@property(readonly) V2TIMGroupApplication *pendencyItem;

@property NSURL *avatarUrl;

@property NSString *title;

/**
 *  The joining group introduction of the requester. Such as "Xiao Ming applied to join the group".
 */
@property NSString *requestMsg;

/**
 *  Agree or Not
 *  YES: Agree;  NO: Indicates that the current request was not granted, but does not mean that the request has been denied.
 */
@property BOOL isAccepted;

/**
 *
 *  Refuse or Not
 *  YES: Refuse; NO: Indicates that the current request is not denied, but does not mean that the request has been granted.
 */
@property BOOL isRejectd;
@property SEL cbuttonSelector;

- (instancetype)initWithPendency:(V2TIMGroupApplication *)args;

- (void)accept;
- (void)reject;

@end

@interface TDeskGroupPendencyCell : TDeskCommonTableViewCell

@property UIImageView *avatarView;

@property UILabel *titleLabel;

@property UILabel *addWordingLabel;

@property UIButton *agreeButton;

@property TDeskGroupPendencyCellData *pendencyData;

- (void)fillWithData:(TDeskGroupPendencyCellData *)pendencyData;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskFaceCell & data
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 【Module name】 TDeskFaceCellData
 * 【Function description]】The name and local storage path of the stored emoticon.
 */
@interface TDeskFaceCellData : NSObject

/**
 * The name of emoticon
 */
@property(nonatomic, strong) NSString *name;

/**
 * The localized name of the emoticon (the attribute used for internationalization, if it is empty or the length is 0, the name is displayed by default)
 */
@property(nonatomic, copy) NSString *localizableName;

/**
 * The storage path of the emoticon cached locally.
 */
@property(nonatomic, strong) NSString *path;
@end

/**
 * 【Module name】TDeskFaceCell
 * 【Function description】 Store the image of the emoticon, and initialize the Cell according to TDeskFaceCellData.
 *  In the emoticon view, TDeskFaceCell is the unit displayed on the interface.
 */
@interface TDeskFaceCell : UICollectionViewCell

/**
 *  The image view for displaying emoticon
 */
@property(nonatomic, strong) UIImageView *face;
@property(nonatomic, strong) UIImage *staicImage;
@property(nonatomic, strong) UIImage *gifImage;
@property(nonatomic, copy) void(^longPressCallback)(UILongPressGestureRecognizer *recognizer);
- (void)setData:(TDeskFaceCellData *)data;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskFaceGroup
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 【Module name】 TDeskFaceGroup
 * 【Function description】 It is used to realize the grouping of emoticon, which is convenient for users to browse and select under different emoticon themes.
 *  This class stores the index of each emoticon group, so that FaceView can locate each emoticon group.
 *  At the same time, this class stores the path of all emoticon pictures in an emoticon group, and provides data such as the number of lines, the number of
 * emoticons in each line, etc., to locate specific emoticons
 */
@interface TDeskFaceGroup : NSObject

/**
 *  Index of emoticons group, begining with zero.
 */
@property(nonatomic, assign) int groupIndex;

/**
 *  The resource path of the entire expression group
 */
@property(nonatomic, strong) NSString *groupPath;

/**
 *  The number of lines of emoticons in the emoticon group
 */
@property(nonatomic, assign) int rowCount;

/**
 *  The number of emoticons contained in each line
 */
@property(nonatomic, assign) int itemCountPerRow;

@property(nonatomic, strong) NSMutableArray *faces;

@property(nonatomic, strong) NSDictionary *facesMap;

/**
 *  The flag of indicating whether to display the delete button
 *  When set to YES, FaceView will display a "delete" icon in the lower right corner of the emoticon view. Clicking the icon can delete the entered emoticon
 * directly without evoking the keyboard.
 */
@property(nonatomic, assign) BOOL needBackDelete;

/**
 *  The path to the cover image of the emoticon group
 */
@property(nonatomic, strong) NSString *menuPath;

@property(nonatomic, strong) TDeskFaceGroup *recentGroup;

@property(nonatomic, assign) BOOL isNeedAddInInputBar;

@property(nonatomic, copy) NSString *groupName;

@end

@interface TUIEmojiTextAttachment : NSTextAttachment

@property(nonatomic, strong) TDeskFaceCellData *faceCellData;

@property(nonatomic, copy) NSString *emojiTag;

@property(nonatomic, assign) CGSize emojiSize;  // For emoji image size

@end

/////////////////////////////////////////////////////////////////////////////////
//
// TDeskUnReadView
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskUnReadView : UIView

/**
 * The label of displaying unread message count
 */
@property(nonatomic, strong) UILabel *unReadLabel;

/**
 * Set the unread message count
 */
- (void)setNum:(NSInteger)num;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskConversationPin
//
/////////////////////////////////////////////////////////////////////////////////
extern NSString *kTopConversationListChangedNotification;

@interface TDeskConversationPin : NSObject

+ (instancetype)sharedInstance;

/**
 * 
 * Getting the list of pinned conversations
 */
- (NSArray *)topConversationList;

/**
 * 
 * Pin the conversation
 */
- (void)addTopConversation:(NSString *)conv callback:(void (^__nullable)(BOOL success, NSString *__nullable errorMessage))callback;
/**
 * 
 * Remove pinned conversations
 */
- (void)removeTopConversation:(NSString *)conv callback:(void (^__nullable)(BOOL success, NSString *__nullable errorMessage))callback;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskCommonContactSelectCellData
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskCommonContactSelectCellData : TDeskCommonCellData

@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSURL *avatarUrl;
@property(nonatomic, strong) UIImage *avatarImage;

@property(nonatomic, getter=isSelected) BOOL selected;
@property(nonatomic, getter=isEnabled) BOOL enabled;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskCommonContactListPickerCell
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskCommonContactListPickerCell : UICollectionViewCell

@property UIImageView *avatar;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskContactListPickerOnCancel
//
/////////////////////////////////////////////////////////////////////////////////
typedef void (^TDeskContactListPickerOnCancel)(TDeskCommonContactSelectCellData *data);

@interface TDeskContactListPicker : UIControl

@property(nonatomic, strong, readonly) UIButton *accessoryBtn;
@property(nonatomic, strong) NSArray<TDeskCommonContactSelectCellData *> *selectArray;
@property(nonatomic, copy) TDeskContactListPickerOnCancel onCancel;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskProfileCardCell & vc
//
/////////////////////////////////////////////////////////////////////////////////
@class TDeskProfileCardCell;
@protocol TDeskProfileCardDelegate <NSObject>
- (void)didTapOnAvatar:(TDeskProfileCardCell *)cell;
@end

@interface TDeskProfileCardCellData : TDeskCommonCellData
@property(nonatomic, strong) UIImage *avatarImage;
@property(nonatomic, strong) NSURL *avatarUrl;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, strong) NSString *signature;
@property(nonatomic, strong) UIImage *genderIconImage;
@property(nonatomic, strong) NSString *genderString;
@property BOOL showAccessory;
@property BOOL showSignature;
@end

@interface TDeskProfileCardCell : TDeskCommonTableViewCell
@property(nonatomic, strong) UIImageView *avatar;
@property(nonatomic, strong) UILabel *name;
@property(nonatomic, strong) UILabel *identifier;
@property(nonatomic, strong) UILabel *signature;
@property(nonatomic, strong) UIImageView *genderIcon;
@property(nonatomic, strong) TDeskProfileCardCellData *cardData;
@property(nonatomic, weak) id<TDeskProfileCardDelegate> delegate;
- (void)fillWithData:(TDeskProfileCardCellData *)data;
@end

@interface TDeskAvatarViewController : UIViewController

@property(nonatomic, strong) TDeskProfileCardCellData *avatarData;

@end

typedef NS_ENUM(NSUInteger, TDeskSelectAvatarType) {
    TUISelectAvatarTypeUserAvatar,
    TUISelectAvatarTypeGroupAvatar,
    TUISelectAvatarTypeCover,
    TUISelectAvatarTypeConversationBackGroundCover,
};

@interface TDeskSelectAvatarCardItem : NSObject
@property(nonatomic, strong) NSString *posterUrlStr;
@property(nonatomic, assign) BOOL isSelect;
@property(nonatomic, copy) NSString *fullUrlStr;
@property(nonatomic, assign) BOOL isDefaultBackgroundItem;
@property(nonatomic, assign) BOOL isGroupGridAvatar;
@property(nonatomic, copy) NSString *createGroupType;
@property(nonatomic, strong) UIImage *cacheGroupGridAvatarImage;
@end

@interface TDeskSelectAvatarController : UIViewController
@property(nonatomic, copy) void (^selectCallBack)(NSString *urlStr);
@property(nonatomic, assign) TDeskSelectAvatarType selectAvatarType;
@property(nonatomic, copy) NSString *profilFaceURL;
@property(nonatomic, strong) UIImage *cacheGroupGridAvatarImage;
@property(nonatomic, copy) NSString *createGroupType;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskCommonAvatarCell & Data
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskCommonAvatarCellData : TDeskCommonCellData
;
@property(nonatomic, strong) NSString *key;
@property(nonatomic, strong) NSString *value;
@property BOOL showAccessory;
@property(nonatomic, strong) UIImage *avatarImage;
@property(nonatomic, strong) NSURL *avatarUrl;

@end

@interface TDeskCommonAvatarCell : TDeskCommonTableViewCell
@property UILabel *keyLabel;
@property UILabel *valueLabel;
@property UIImageView *avatar;
@property(readonly) TDeskCommonAvatarCellData *avatarData;

- (void)fillWithData:(TDeskCommonAvatarCellData *)avatarData;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskConversationGroupItem
//
/////////////////////////////////////////////////////////////////////////////////
extern NSUInteger kConversationMarkStarType;
@interface TDeskConversationGroupItem : NSObject
@property(nonatomic, strong) NSString *groupName;
@property(nonatomic, assign) NSInteger unreadCount;
@property(nonatomic, assign) NSInteger groupIndex;
@property(nonatomic, assign) BOOL isShow;
@property(nonatomic, strong) UIButton *groupBtn;
@end


@interface TDeskSendMessageAppendParams : NSObject
@property (nonatomic, assign) BOOL isSendPushInfo;
@property (nonatomic, assign) BOOL isOnlineUserOnly;
@property (nonatomic, assign) V2TIMMessagePriority priority;
+ (instancetype)defaultConfig;
@end
NS_ASSUME_NONNULL_END
