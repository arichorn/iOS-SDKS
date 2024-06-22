#if !__has_include(<PassKitCore/PKAddPushablePassConfiguration.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKAddPushablePassConfiguration.h
//    PassKit
//
//  Created by Ryan Cook on 12/8/23.
//  Copyright © 2023 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PassKit/PKAddSecureElementPassConfiguration.h>

API_AVAILABLE(ios(18.0)) API_UNAVAILABLE(watchos, tvos)
@interface PKPushablePassMetadata : NSObject

- (null_unspecified instancetype)init NS_UNAVAILABLE;
+ (null_unspecified instancetype)new NS_UNAVAILABLE;

/// credentialIdentifier: A unique identifier for provisioning credential data.
@property (nonatomic, strong, readonly, nonnull) NSString *credentialIdentifier;
/// sharingInstanceIdentifier: A unique identifier that refers to an instance of sharing of credentials to a user's device initiated from another user, device, or web.
@property (nonatomic, strong, readonly, nonnull) NSString *sharingInstanceIdentifier;
/// cardTemplateIdentifier: Identifier referencing a card template registered by developers in web portal - identifies a combination of cardProfileIdentifier, cardConfigurationIdentifier, and cardArtBundleName.
/// Returns empty string if no identifier is set.
@property (nonatomic, strong, readonly, nonnull) NSString *cardTemplateIdentifier;
/// cardConfigurationIdentifier: Identifier referencing a card configuration registered by developers.
/// Returns empty string if no identifier is set.
@property (nonatomic, strong, readonly, nonnull) NSString *cardConfigurationIdentifier;
/// serverEnvironmentIdentifier: Identifier referencing the target server environment Apple Pay servers should reach out to to provision this pass.
/// If not present, the default Apply Pay server environment will be used and an empty string will be returned.
@property (nonatomic, strong, nonnull) NSString *serverEnvironmentIdentifier;

@end

API_AVAILABLE(ios(18.0)) API_UNAVAILABLE(watchos, tvos)
@interface PKAddPushablePassConfiguration : PKAddSecureElementPassConfiguration

- (null_unspecified instancetype)init NS_UNAVAILABLE;
+ (null_unspecified instancetype)new NS_UNAVAILABLE;

@end


#else
#import <TargetConditionals.h>
#import <PassKitCore/PKAddPushablePassConfiguration.h>
#endif