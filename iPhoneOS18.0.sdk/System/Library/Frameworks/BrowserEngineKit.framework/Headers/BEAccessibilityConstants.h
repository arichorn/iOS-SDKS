//
//  BEAccessibilityConstants.h
//
//  Copyright © 2024 Apple Inc. All rights reserved.
//

#import <BrowserEngineKit/BEMacros.h>

#if BROWSERENGINEKIT_HAS_UIKIT

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// Used when the element is an item in a menu.
BROWSERENGINE_EXTERN UIAccessibilityTraits BEAccessibilityTraitMenuItem NS_SWIFT_NAME(BEAccessibilityTraits.menuItem) BROWSERENGINE_ACCESSIBILITY_AVAILABILITY;

// Used when the element should be treated as a button that opens a pop-up.
BROWSERENGINE_EXTERN UIAccessibilityTraits BEAccessibilityTraitPopUpButton NS_SWIFT_NAME(BEAccessibilityTraits.popUpButton) BROWSERENGINE_ACCESSIBILITY_AVAILABILITY;

// Used when the element should be treated as a radio button.
BROWSERENGINE_EXTERN UIAccessibilityTraits BEAccessibilityTraitRadioButton NS_SWIFT_NAME(BEAccessibilityTraits.radioButton) BROWSERENGINE_ACCESSIBILITY_AVAILABILITY;

// Used when the element should be treated as read-only.
BROWSERENGINE_EXTERN UIAccessibilityTraits BEAccessibilityTraitReadOnly NS_SWIFT_NAME(BEAccessibilityTraits.readOnly) BROWSERENGINE_ACCESSIBILITY_AVAILABILITY;

// Used when the element should be treated as visited (e.g. for a link in a webpage).
BROWSERENGINE_EXTERN UIAccessibilityTraits BEAccessibilityTraitVisited NS_SWIFT_NAME(BEAccessibilityTraits.visited) BROWSERENGINE_ACCESSIBILITY_AVAILABILITY;

#ifdef __swift__
// This struct is not available in Objective-C. Its only purpose is to create a namespace for accessibility symbols in Swift.
typedef struct BEAccessibilityTraits { void *_reserved; } BEAccessibilityTraits;
#endif

NS_ASSUME_NONNULL_END

#endif // BROWSERENGINEKIT_HAS_UIKIT
