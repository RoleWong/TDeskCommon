//
//  TDeskSystemMessageCell.m
//  UIKit
//
//  Created by annidyfeng on 2019/5/30.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import "TDesk_TUISystemMessageCell.h"
#import <TDeskCommon/TDesk_TIMDefine.h>
#import <TDeskCore/TDesk_NSString+TUIUtil.h>

@interface TDeskSystemMessageCell ()
@property(nonatomic, strong) UILabel *messageLabel;
@property TDeskSystemMessageCellData *systemData;
@end

@implementation TDeskSystemMessageCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        _messageLabel = [[UILabel alloc] init];
        _messageLabel.font = [UIFont systemFontOfSize:13];
        _messageLabel.textColor = [UIColor d_systemGrayColor];
        _messageLabel.textAlignment = NSTextAlignmentCenter;
        _messageLabel.numberOfLines = 1;
        _messageLabel.backgroundColor = [UIColor clearColor];
        _messageLabel.layer.cornerRadius = 3;
        [_messageLabel.layer setMasksToBounds:YES];
        [self.container addSubview:_messageLabel];
        self.backgroundColor = [UIColor clearColor];
        self.contentView.backgroundColor = [UIColor clearColor];
    }
    return self;
}

+ (BOOL)requiresConstraintBasedLayout {
    return YES;
}

// this is Apple's recommended place for adding/updating constraints
- (void)updateConstraints {
    [super updateConstraints];
    
    [self.container mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.center.mas_equalTo(self.contentView);
        make.size.mas_equalTo(self.contentView);
    }];
    [self.messageLabel sizeToFit];
    if(self.messageLabel.superview) {
        [self.messageLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.center.mas_equalTo(self.container);
            make.size.mas_equalTo(self.messageLabel.frame.size);
        }];
    }
}

- (void)fillWithData:(TDeskSystemMessageCellData *)data;
{
    [super fillWithData:data];
    self.systemData = data;
    self.messageLabel.attributedText = data.attributedString;
    self.nameLabel.hidden = YES;
    self.avatarView.hidden = YES;
    self.retryView.hidden = YES;
    [self.indicator stopAnimating];
    // tell constraints they need updating
    [self setNeedsUpdateConstraints];

    // update constraints now so we can animate the change
    [self updateConstraintsIfNeeded];

    [self layoutIfNeeded];
}

- (void)layoutSubviews {
    [super layoutSubviews];
}


#pragma mark - TDeskMessageCellProtocol
+ (CGFloat)getEstimatedHeight:(TDeskMessageCellData *)data {
    return 42.f;
}

+ (CGFloat)getHeight:(TDeskMessageCellData *)data withWidth:(CGFloat)width {
    return [self getContentSize:data].height + kScale375(16);
}

+ (CGSize)getContentSize:(TDeskMessageCellData *)data {
    NSAssert([data isKindOfClass:TDeskSystemMessageCellData.class], @"data must be kind of TDeskSystemMessageCellData");
    TDeskSystemMessageCellData *systemCellData = (TDeskSystemMessageCellData *)data;
    
    static CGSize maxSystemSize;
    if (CGSizeEqualToSize(maxSystemSize, CGSizeZero)) {
        maxSystemSize = CGSizeMake(TSystemMessageCell_Text_Width_Max, MAXFLOAT);
    }
    CGSize size = [systemCellData.attributedString.string textSizeIn:maxSystemSize font:systemCellData.contentFont];
    size.height += 10;
    size.width += 16;
    return size;
}

@end
