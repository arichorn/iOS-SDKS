/*
    Copyright (C) 2024 Apple Inc. All Rights Reserved.
*/

#pragma once

#ifndef ACCESSORY_SETUP_KIT_INDIRECT_INCLUDES
#error "Please #import <AccessorySetupKit/AccessorySetupKit.h> instead of this file directly."
#endif

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

AS_EXTERN
API_AVAILABLE( ios( 18.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
NS_SWIFT_SENDABLE 
@interface ASAccessorySettings : NSObject

/*!
    @property    SSID
    @abstract    Hotspot identifier which clients can use to connect to accessory's hotspot.
*/
@property (readwrite, copy, nullable, nonatomic) NSString *SSID;

@end

NS_ASSUME_NONNULL_END
