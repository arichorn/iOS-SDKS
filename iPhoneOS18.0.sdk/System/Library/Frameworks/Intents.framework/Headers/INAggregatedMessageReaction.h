//
//  INAggregatedMessageReaction.h
//  Intents
//
//  Copyright (c) 2016-2024 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Intents/INMessageReactionType.h>

@class INPerson;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(18.0), watchos(11.0))
API_UNAVAILABLE(macos, tvos)
@interface INAggregatedMessageReaction : NSObject <NSCopying, NSSecureCoding>

- (instancetype)initWithReactionType:(INMessageReactionType)reactionType
                               emoji:(nullable NSString *)emoji
                             senders:(nullable NSArray<INPerson *> *)senders
                       reactionCount:(nullable NSNumber *)reactionCount NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

@property (readonly, assign, NS_NONATOMIC_IOSONLY) INMessageReactionType reactionType;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *emoji;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSArray<INPerson *> *senders;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *reactionCount NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
