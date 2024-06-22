//
//  PhoneticEmbedderEnums.h
//  Speech
//
//  Created by Festus Ojo on 1/19/24.
//  Copyright © 2024 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

__attribute__ ((deprecated ("Use PhoneticEmbedder.InputFormat instead.")))
typedef NS_ENUM(NSInteger, PhoneticEncoderType) {
    PhoneticEncoderTypeGrapheme = 0,
    PhoneticEncoderTypePhoneme = 1,
} API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18), visionos(2.0));

__attribute__ ((deprecated ("Use PhoneticEmbedder.LoadingOption instead.")))
typedef NS_ENUM(NSInteger, PhoneticEmbedderInitFlag) {
    PhoneticEmbedderInitFlagAll = 0,
    PhoneticEmbedderInitFlagEmbedder = 1,
} API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18), visionos(2.0));
