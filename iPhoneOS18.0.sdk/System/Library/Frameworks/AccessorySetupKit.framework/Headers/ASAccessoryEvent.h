/*
    Copyright (C) 2024 Apple Inc. All Rights Reserved.
*/

#ifndef ACCESSORY_SETUP_KIT_INDIRECT_INCLUDES
#error "Please #import <AccessorySetupKit/AccessorySetupKit.h> instead of this file directly."
#endif

#pragma once

#import <AccessorySetupKit/ASCommon.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

@class ASAccessory;

//===========================================================================================================================
/// Type of event.
typedef NS_ENUM( NSInteger, ASAccessoryEventType )
{
    ASAccessoryEventTypeUnknown NS_SWIFT_NAME(unknown)                              = 0,    // Unknown event. Placeholder for initializing event types.
    ASAccessoryEventTypeActivated NS_SWIFT_NAME(activated)                          = 10,   // [ASAccessoryEvent] Instance activate completed.
    ASAccessoryEventTypeInvalidated NS_SWIFT_NAME(invalidated)                      = 11,   // [ASAccessoryEvent] Instance invalidated.
    ASAccessoryEventTypeMigrationComplete NS_SWIFT_NAME(migrationComplete)          = 20,   // [ASAccessoryEvent] Accessories migration complete.
    ASAccessoryEventTypeAccessoryAdded NS_SWIFT_NAME(accessoryAdded)                = 30,   // [ASAccessoryEvent] Accessory added.
    ASAccessoryEventTypeAccessoryRemoved NS_SWIFT_NAME(accessoryRemoved)            = 31,   // [ASAccessoryEvent] Accessory removed from system.
    ASAccessoryEventTypeAccessoryChanged NS_SWIFT_NAME(accessoryChanged)            = 32,   // [ASAccessoryEvent] Accessory properties changed.
    ASAccessoryEventTypePickerDidPresent NS_SWIFT_NAME(pickerDidPresent)            = 42,   // [ASAccessoryEvent] Picker did present.
    ASAccessoryEventTypePickerDidDismiss NS_SWIFT_NAME(pickerDidDismiss)            = 45,   // [ASAccessoryEvent] Picker did dismiss.
};

//===========================================================================================================================
/// Event for status and other updates.
AS_EXTERN
API_AVAILABLE( ios( 18.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
@interface ASAccessoryEvent : NSObject

/// Type of event. Type may indicate the subclass of ASAccessoryEvent to provide additional properties.
@property (readonly, assign, nonatomic) ASAccessoryEventType eventType;

/// Accessory found, lost or changed.
@property (readonly, copy, nullable, nonatomic) ASAccessory *accessory;

/// Any error for event type.
@property (readonly, copy, nullable, nonatomic) NSError *error;

- (instancetype) init NS_UNAVAILABLE;
- (instancetype) new NS_UNAVAILABLE;

@end

#ifdef __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
