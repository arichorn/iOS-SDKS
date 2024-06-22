//
//  PKToolPickerCustomItemConfiguration.h
//  PencilKit
//
//  Copyright © 2024 Apple Inc. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@class PKToolPickerCustomItem;
@class UIColor;
@class UIImage;
@class UIViewController;

NS_ASSUME_NONNULL_BEGIN

/// A configuration that specifies the appearance and behavior of a item and its contents.
NS_REFINED_FOR_SWIFT
API_AVAILABLE(ios(18.0), visionos(2.0))
@interface PKToolPickerCustomItemConfiguration : NSObject <NSCopying>

/// Create a new eraser tool item with a width.
/// @param identifier The identifier for the tool item.
/// @param name The name for the tool item.
- (instancetype)initWithIdentifier:(NSString *)identifier name:(NSString *)name;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// A string that identifies the item in the picker.
/// For example, com.example.myapp.toolpicker.pencil.
/// If multiple items with the same identifier are used to create the picker, only the first instance is used.
@property (nonatomic, copy) NSString *identifier;

/// A short string suitable for presentation to users as the name of the tool.
@property (nonatomic, copy) NSString *name;

/// A block to provide an image representing the given tool item.
/// Return an image at least 150 points tall to avoid the bottom of the item showing during animations.
@property (nonatomic, copy, nullable) UIImage * _Nonnull (^imageProvider)(PKToolPickerCustomItem *);

/// A block to provide a view controller above the system controls in the tool attributes popover.
@property (nonatomic, copy, nullable) UIViewController * _Nonnull (^viewControllerProvider)(PKToolPickerCustomItem *);

/// Default width for the tool.
/// Default value is 0.
@property (nonatomic, assign) CGFloat defaultWidth;

/// A dictionary representing the UI options for choosing width variants, with each element containing its width value paired with its corresponding image.
/// A dictionary with fewer than 2 elements means no selection UI is available for users to adjust the width value.
/// A dictionary with 2 or more elements means that users can adjust the width value using the selection UI.
/// Provide square images with a size of at least 32pts by 32pts.
@property (nonatomic, copy) NSDictionary<NSNumber *, UIImage *> *widthVariants;

/// Default color for the tool.
/// Default value is black.
@property (nonatomic, strong) UIColor *defaultColor;

/// Present color selection UI to the user.
/// Default value is NO.
@property (nonatomic, assign) BOOL allowsColorSelection;

@end

NS_ASSUME_NONNULL_END
