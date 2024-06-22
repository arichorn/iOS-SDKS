// Copyright © 2024 Apple Inc. All rights reserved.

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(15.0), ios(18.0), visionos(2.0)) API_UNAVAILABLE(tvos, watchos)
NS_REFINED_FOR_SWIFT
@interface ASAuthorizationPublicKeyCredentialPRFRegistrationInput: NSObject

+ (instancetype)checkForSupport;

@property (nonatomic, readonly) BOOL shouldCheckForSupport;

@end

NS_ASSUME_NONNULL_END
