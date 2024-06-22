//
//  CLServiceSession.h
//  CoreLocation
//
//  Created by Siraj Abidi on 04/11/24.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLAvailability.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos)
typedef NS_ENUM(NSInteger, CLServiceSessionAuthorizationRequirement) {
	CLServiceSessionAuthorizationRequirementNone = 0,
	CLServiceSessionAuthorizationRequirementWhenInUse,
#if TARGET_OS_IOS || TARGET_OS_WATCH
	CLServiceSessionAuthorizationRequirementAlways,
#endif
} NS_REFINED_FOR_SWIFT;

API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos) NS_REFINED_FOR_SWIFT
@interface CLServiceSessionDiagnostic : NSObject
/*
 *  authorizationDenied
 *
 *  Discussion:
 *      True if the session will be suspended while the app has been denied
 *      location authorization.
 *
 */
@property (nonatomic, readonly) BOOL authorizationDenied;

/*
 *  authorizationDeniedGlobally
 *
 *  Discussion:
 *      True if the session will be suspended while the user has disabled Location
 *      Services system-wide.
 *
 */
@property (nonatomic, readonly) BOOL authorizationDeniedGlobally;

/*
 *  authorizationRestricted
 *
 *  Discussion:
 *      True if session will be suspended while the app lacks authorization,
 *      and authorization changes are prevented by parental restrictions,
 *      MDM configuration, or other factors.
 *
 */
 @property (nonatomic, readonly) BOOL authorizationRestricted;

/*
 *  insufficientlyInUse
 *
 *  Discussion:
 *      True if the session will be suspended while the app is not sufficiently
 *      in-use.
 *
 */
@property (nonatomic, readonly) BOOL insufficientlyInUse;

/*
 *  serviceSessionRequired
 *
 *  Discussion:
 *      True if LocationServices are disabled because the app has adopted CLRequireExplicitServiceSession
 *      info.plist key but no CLServiceSession requiring authorization is outstanding yet.
 *
 */
@property (nonatomic, readonly) BOOL serviceSessionRequired;

/*
 *  fullAccuracyDenied
 *
 *  Discussion:
 *      True if a session requiring FullAccuracy has been denied full accuracy due to user decision.
 *
 */
@property (nonatomic, readonly) BOOL fullAccuracyDenied;

/*
*  alwaysAuthorizationDenied
*
*  Discussion:
*      True if a session requiring Always authorization has been denied Always due to user decision.
*
*/
@property (nonatomic, readonly) BOOL alwaysAuthorizationDenied;

/*
 *  authorizationRequestInProgress
 *
 *  Discussion:
 *      True if the system is requesting authorization from the user on behalf of the app, but no response has been received yet.
 *
 */
@property (nonatomic, readonly) BOOL authorizationRequestInProgress;

@end

CL_EXTERN
API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos) NS_REFINED_FOR_SWIFT
@interface CLServiceSession : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


/* sessionRequiringAuthorization:
 *  Discussion:
 *      TODO - rdar://123570432
 *
 */
+ (CLServiceSession *)sessionRequiringAuthorization:(CLServiceSessionAuthorizationRequirement)authorizationRequirement API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos);

/* sessionRequiringAuthorization:queue:handler:
 *  Discussion:
 *      TODO - rdar://123570432
 */
+ (CLServiceSession *)sessionRequiringAuthorization:(CLServiceSessionAuthorizationRequirement)authorizationRequirement
											  queue:(dispatch_queue_t)queue
											handler:(void(^)(CLServiceSessionDiagnostic *diagnostic))handler API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos);


/* sessionRequiringAuthorization:accuracy:
 *  Discussion:
 *      TODO - rdar://123570432
 *
 */
+ (CLServiceSession *)sessionRequiringAuthorization:(CLServiceSessionAuthorizationRequirement)authorizationRequirement
							 fullAccuracyPurposeKey:(nonnull NSString *)purposeKey API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos);



/* sessionRequiringAuthorization:accuracy:queue:handler:
 *  Discussion:
 *      TODO - rdar://123570432
 *
 */
+ (CLServiceSession *)sessionRequiringAuthorization:(CLServiceSessionAuthorizationRequirement)authorizationRequirement
							 fullAccuracyPurposeKey:(nonnull NSString *)purposeKey
											  queue:(dispatch_queue_t)queue
											handler:(void(^)(CLServiceSessionDiagnostic *diagnostic))handler API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos);


/*
 *  invalidate
 *
 *  Discussion:
 *      Ends the session immediately. Once the session is
 *      invalidated it cannot become active again.
 */
- (void)invalidate API_AVAILABLE(ios(18.0), watchos(11.0), tvos(18.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(2.0)
#endif
) API_UNAVAILABLE(macos);

@end

NS_ASSUME_NONNULL_END
