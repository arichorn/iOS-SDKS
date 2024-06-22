//
//  MLModelAsset.h
//  CoreML
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//
#import <CoreML/MLModelDescription.h>

NS_ASSUME_NONNULL_BEGIN

/// A compiled model asset.
///
/// `MLModelAsset` is an abstraction of a compiled model, which can be:
///
///  - `.mlmodelc` bundle on the file system
///  - In-memory model specification
///
/// It provides the unified interface to query the model description and to instantiate `MLModel`.
///
/// ```swift
/// // Creates an object.
/// let modelAsset = MLModelAsset(url: modelURL)
///
/// // Query the model description
/// let description = try await modelAsset.modelDescription
///
/// // Query the list of functions in the model asset.
/// let functionNames = try await modelAsset.functionNames
///
/// // Query the model description of a specific function.
/// let descriptionOfMyFunction = try await modelAsset.modelDescription(of: "MyFunction")
///
/// // Instantiate `MLModel` for "MyFunction".
/// let modelConfiguration = MLModelConfiguration()
/// modelConfiguration.functionName = "MyFunction"
/// let model = try await MLModel.load(asset: modelAsset, configuration: modelConfiguration)
/// ```
ML_EXPORT
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
@interface MLModelAsset : NSObject

/// Construct an optimized model asset from the contents of specification data.
///
/// - Parameters:
///   - specificationData: Contents of .mlmodel as a data blob.
///   - error: When the model asset creation fails error is populated with the reason for failure.
+ (nullable instancetype)modelAssetWithSpecificationData:(NSData *)specificationData
                                                   error:(NSError * _Nullable __autoreleasing *)error API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0)) API_UNAVAILABLE(watchos) NS_SWIFT_NAME(init(specification:));

/// Constructs a ModelAsset from a compiled model URL.
///
/// - Parameters:
///   - compiledModelURL: Location on the disk where the model asset is present.
///   - error: Errors if the model asset is not loadable.
///
/// - Returns: a model asset or nil if there is an error.
+ (nullable instancetype)modelAssetWithURL:(NSURL *)compiledModelURL
                                     error:(NSError **)error API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18.0));

/// The default model descripton.
///
/// Use this method to get the description of the model such as the feature descriptions, the model author, and other metadata.
///
/// For the multi-function model asset, this method vends the description for the default function. Use `modelDescription(for:)` to get the model description of other functions.
///
/// ```swift
/// let modelAsset = try MLModelAsset(url: modelURL)
/// let modelDescription = try await modelAsset.modelDescription()
/// print(modelDescription)
/// ```
- (void)modelDescriptionWithCompletionHandler:(void (^)(MLModelDescription * _Nullable modelDescription, NSError * _Nullable error))handler API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18.0)) NS_SWIFT_ASYNC_NAME(getter:modelDescription());

/// The model descripton for a specified function.
///
/// Use this method to get the description of the model such as the feature descriptions, the model author, and other metadata.
///
/// ```swift
/// let modelAsset = try MLModelAsset(url: modelURL)
/// let modelDescription = try await modelAsset.modelDescription(of: "my_function")
/// print(modelDescription)
/// ```
- (void)modelDescriptionOfFunctionNamed:(NSString *)functionName
                      completionHandler:(void (^)(MLModelDescription * _Nullable modelDescription, NSError * _Nullable error))handler API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18.0)) NS_SWIFT_ASYNC_NAME(modelDescription(of:));

/// The list of function names in the model asset.
///
/// Some model types (e.g. ML Program) supports multiple functions. Use this method to query the function names.
///
/// The method vends the empty array when the model doesn't use the multi-function configuration.
///
/// ```swift
/// let modelAsset = try MLModelAsset(url: modelURL)
/// let functionNames = try await modelAsset.functionNames
/// print(functionNames) // For example, ["my_function1", "my_function2"];
/// ```
- (void)functionNamesWithCompletionHandler:(void (^)(NSArray<NSString *> * _Nullable functionNames, NSError * _Nullable error))handler API_UNAVAILABLE(macos, ios, watchos, tvos) NS_SWIFT_ASYNC_NAME(getter:functionNames());

// cannot construct MLModelAsset without model specification data.
- (instancetype)init NS_UNAVAILABLE;

// cannot construct MLModelAsset without model specification data.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
