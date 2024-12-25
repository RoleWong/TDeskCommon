//
//  NSString+TUIEmoji.h
//  TUIChat
//
//  Created by harvy on 2021/11/15.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TDesk_TIMDefine.h"
NS_ASSUME_NONNULL_BEGIN

#define kSplitStringResultKey @"result"
#define kSplitStringTextKey @"text"
#define kSplitStringTextIndexKey @"textIndex"

@interface NSString (TUIEmoji)

/**
 * Localize the emoji text in the current text and get the localized text
 * eg: The original text was @"你好, [大哭]"
 *    - If it is currently in English, this method converts the text to @"Hello,[Cry]"
 *    - If the current is Chinese, this method converts the text to @"你好,[大哭]"
 */
- (NSString *)getLocalizableStringWithFaceContent;

/**
 * Internationalize the emoji text in the current text and get the internationalized text. The internationalized text of the emoji is Chinese
 */
- (NSString *)getInternationalStringWithfaceContent;

/**
 *
 * Get the formatted emoticon text (after the image and text are mixed) The emoticon is stored in the NSTextAttachment object and cannot carry parameters
 */
- (NSMutableAttributedString *)getFormatEmojiStringWithFont:(UIFont *)textFont
                                             emojiLocations:(nullable NSMutableArray<NSDictionary<NSValue *, NSAttributedString *> *> *)emojiLocations;

/**
 *
 * Get the formatted emoji (after the image and text are mixed together) The emoji is stored in the TUIEmojiTextAttachment object, which can carry parameters.
 * For example: the original text is @"Hello,[cry]", then this method turns the text into @"Hello,😭"
 */
- (NSMutableAttributedString *)getAdvancedFormatEmojiStringWithFont:(UIFont *)textFont
                                                          textColor:(UIColor *)textColor
                                                     emojiLocations:(nullable NSMutableArray<NSDictionary<NSValue *, NSAttributedString *> *> *)emojiLocations;

- (NSString *)getEmojiImagePath;

- (UIImage *)getEmojiImage;

/**
 * Split string using both emoji and @user. For instance,
 * Origin string is @"hello[Grin]world, @user1 see you!", and users is @[@"user1"];
 * Return value is:
 * @{
 *    kSplitStringResultKey:    @[@"hello", @"[Grin]", @"world, ", @"user1 ", @"see you!"],
 *    kSplitStringTextKey:      @[@"hello", @"world, ", @"see you!"],
 *    kSplitStringTextIndexKey: @[@0, @2, @4]
 * }
 * kSplitStringResultKey's value contains all elements after spliting.
 * kSplitStringTextKey'value contains all text elements in the split result, excluding emojis and @user infos.
 * kSplitStringTextIndexKey'value contains the location of text in split result.
 */
- (NSDictionary *)splitTextByEmojiAndAtUsers:(NSArray *_Nullable)users;

/**
 * Replace the element in array, whose index is in index with the corresponding value in replaceDict.
 * For instance,
 * array is         @[@"hello", @"[Grin]", @"world, ", @"user1 ", @"see you!"]
 * index is         @[@0, @2, @4]
 * replaceDict is   @{@"hello":@"你好", @"world":@"世界", @"see you!":@"再见!"}
 * Return value is  @"你好[Grin]世界, @user1 再见!"
 */
+ (NSString *)replacedStringWithArray:(NSArray *)array index:(NSArray *)index replaceDict:(NSDictionary *)replaceDict;

@end

@interface NSAttributedString (EmojiExtension)

/**
 *   @"你好,😭""  ->  @"你好,[大哭]"
 *   @"Hello,😭"  ->  @"Hello,[Cry]"
 */
- (NSString *)tui_getPlainString;

@end

NS_ASSUME_NONNULL_END
