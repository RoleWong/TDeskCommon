//
//  TDeskRTLUtil.h
//  TIMCommon
//
//  Created by cologne on 2023/7/21.
//  Copyright © 2023 Tencent. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TDeskRTLUtil : NSObject

@end

@interface UIView (TUIRTL)
- (void)resetFrameToFitRTL;

@end

@interface UIImage (TUIRTL)

- (UIImage *_Nonnull)checkOverturn;
- (UIImage *)rtl_imageFlippedForRightToLeftLayoutDirection;
@end

typedef NS_ENUM(NSUInteger, TDeskTextRTLAlignment) {
    TUITextRTLAlignmentUndefine,
    TUITextRTLAlignmentLeading,
    TUITextRTLAlignmentTrailing,
    TUITextRTLAlignmentCenter,
};
@interface UILabel (TUIRTL)
@property (nonatomic, assign) TDeskTextRTLAlignment rtlAlignment;
@end

@interface NSMutableAttributedString (TUIRTL)
@property (nonatomic, assign) TDeskTextRTLAlignment rtlAlignment;
@end

BOOL isRTLString(NSString *string);
NSString * rtlString(NSString *string);
NSAttributedString *rtlAttributeString(NSAttributedString *attributeString ,NSTextAlignment textAlignment );
UIEdgeInsets rtlEdgeInsetsWithInsets(UIEdgeInsets insets);

@interface TDeskCollectionRTLFitFlowLayout : UICollectionViewFlowLayout

@end
NS_ASSUME_NONNULL_END
