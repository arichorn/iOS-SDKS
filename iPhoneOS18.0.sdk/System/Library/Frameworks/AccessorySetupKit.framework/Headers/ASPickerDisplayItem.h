/*
    Copyright (C) 2024 Apple Inc. All Rights Reserved.
*/

#pragma once

#ifndef ACCESSORY_SETUP_KIT_INDIRECT_INCLUDES
#error "Please #import <AccessorySetupKit/AccessorySetupKit.h> instead of this file directly."
#endif

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ASDiscoveryDescriptor;

AS_EXTERN
API_AVAILABLE( ios( 18.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
NS_SWIFT_SENDABLE
@interface ASPickerDisplayItem : NSObject

/// NOTE:-  `name` and `image` is ignored if display item matched with an already authorized accessory for another app

/// Ask user to rename accessory.
@property (readwrite, assign, nonatomic) BOOL allowsRename;

/// Accessory rename option. `allowsRename` needs to be allowed to update options.
@property (readwrite, assign, nonatomic) ASAccessoryRenameOptions renameOptions;

/// Accessory's display name on picker as title.
@property (readonly, copy, nonatomic) NSString *name;

/// Accessory's product image.
@property (readonly, copy, nonatomic) UIImage *productImage;

/// Accessory discovery parameters.
@property (readonly, copy, nonatomic) ASDiscoveryDescriptor *descriptor;

- (instancetype)initWithName:(NSString *) name productImage:(UIImage *) productImage
        descriptor:(ASDiscoveryDescriptor *) descriptor NS_DESIGNATED_INITIALIZER;

- (instancetype) init NS_UNAVAILABLE;
- (instancetype) new NS_UNAVAILABLE;

@end

// MARK: -
//===========================================================================================================================

AS_EXTERN
API_AVAILABLE( ios( 18.0 ) ) API_UNAVAILABLE(macos, macCatalyst, watchos, tvos, visionos)
NS_SWIFT_SENDABLE
@interface ASMigrationDisplayItem : ASPickerDisplayItem

@property (readwrite, copy, nullable, nonatomic) NSUUID *peripheralIdentifier;

@property (readwrite, copy, nullable, nonatomic) NSString *hotspotSSID;

@end

NS_ASSUME_NONNULL_END
