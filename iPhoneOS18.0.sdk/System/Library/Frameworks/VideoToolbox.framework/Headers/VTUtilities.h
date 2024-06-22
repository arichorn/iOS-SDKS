/*
	File:  VTUtilities.h
 
	Framework:  VideoToolbox
 
	Copyright © 2013-2014 Apple Inc. All rights reserved.
 
*/

#ifndef VTUTILITIES_H
#define VTUTILITIES_H

#include <VideoToolbox/VTBase.h>
#include <CoreVideo/CoreVideo.h>
#include <CoreGraphics/CoreGraphics.h>
#include <CoreMedia/CMBase.h>
#include <CoreMedia/CMFormatDescription.h>

#if defined(__cplusplus)
extern "C"
{
#endif
    
#pragma pack(push, 4)

/*!
	@function VTCreateCGImageFromCVPixelBuffer
	@abstract Creates a CGImage using the provided CVPixelBuffer
	@param	pixelBuffer
		The pixelBuffer to be used as the image data source for the CGImage.
	@param	options
		no options currently.  pass NULL.
	@param	imageOut
		pointer to an address to receive the newly created CGImage.
	@discussion
		This routine creates a CGImage representation of the image data contained in
		the provided CVPixelBuffer.
		The source CVPixelBuffer may be retained for the lifetime of the CGImage.  Changes
		to the CVPixelBuffer after making this call (other than releasing it) will have 
		undefined results.
		Not all CVPixelBuffer pixel formats will support conversion into a CGImage compatible
		pixel format.
*/
VT_EXPORT OSStatus 
VTCreateCGImageFromCVPixelBuffer(
	CM_NONNULL CVPixelBufferRef			pixelBuffer,
	CM_NULLABLE CFDictionaryRef			options,
	CM_RETURNS_RETAINED_PARAMETER CM_NULLABLE CGImageRef * CM_NONNULL imageOut ) API_AVAILABLE(macos(10.11), ios(9.0), tvos(10.2), visionos(1.0)) API_UNAVAILABLE(watchos);


/*!
	@function	VTRegisterSupplementalVideoDecoderIfAvailable
	@abstract	Requests that a video decoder, if available, be registered for the specified CMVideoCodecType
	@param	codecType
		The CMVideoCodecType corresponding the format being requested
	@discussion
		This call will find and register a video decoder for the provided CMVideoCodecType if
		such a decoder is available on the system but not registered by default.
*/
VT_EXPORT void VTRegisterSupplementalVideoDecoderIfAvailable( CMVideoCodecType codecType ) API_AVAILABLE(macos(11.0)) API_UNAVAILABLE(ios, watchos, tvos, visionos);

/*!
	@function		VTCopyVideoDecoderExtensionProperties
	@abstract		Returns information about the Media Extension video decoder required to decode the specified format.
	@discussion		If a Media Extension video decoder will be used to decode the specified format, this function will return information about the Media Extension that will be used.
	@param			formatDesc
		The format description for the video format for which information is being requested.
	@param			mediaExtensionPropertiesOut
		If a Media Extension video decoder will be used to decode the specified format, this pointer will return a dictionary with a set of properties describing the extension video decoder.
	@result			If the function succeeds and a Media Extension video decoder will be used to decode this format, the return value will be noErr. If the function succeeds but a Media Extension video decoder will not be used to decode this format, the return value will be kVTCouldNotFindExtensionErr. Otherwise, the return value will be an error code describing the failure.
*/
VT_EXPORT OSStatus VTCopyVideoDecoderExtensionProperties( CMFormatDescriptionRef CM_NONNULL formatDesc, CM_RETURNS_RETAINED_PARAMETER CM_NULLABLE CFDictionaryRef * CM_NONNULL mediaExtensionPropertiesOut ) API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

/*!
	@typedef		VTDecoderExtensionPropertiesKey
	@abstract		A key in a Media Extension video decoder properties dictionary.
*/
typedef CFStringRef VTDecoderExtensionPropertiesKey CF_TYPED_ENUM API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

CM_ASSUME_NONNULL_BEGIN

/*!
	@constant		kVTDecoderExtensionProperties_ExtensionNameKey
	@abstract		A CFDictionary key for the localized video decoder extension name.
	@discussion		This key points to a CFStringRef value with the localized video decoder extension name.
*/
VT_EXPORT VTDecoderExtensionPropertiesKey const kVTDecoderExtensionProperties_ExtensionNameKey API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

/*!
	@constant		kVTDecoderExtensionProperties_ContainingBundleNameKey
	@abstract		A CFDictionary key for the extension host application localized name.
	@discussion		This key points to a CFStringRef value with the localized name of the application hosting the video decoder extension.
*/
VT_EXPORT VTDecoderExtensionPropertiesKey const kVTDecoderExtensionProperties_ContainingBundleNameKey API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

/*!
	@constant		kVTDecoderExtensionProperties_ExtensionURLKey
	@abstract		A CFDictionary key for the URL of the video decoder extension.
	@discussion 	This key points to a CFURLRef value with the URL for the video decoder extension.
*/
VT_EXPORT VTDecoderExtensionPropertiesKey const kVTDecoderExtensionProperties_ExtensionURLKey API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

/*!
	@constant		kVTDecoderExtensionProperties_ContainingBundleURLKey
	@abstract		A CFDictionary key for the URL of the extension host application.
	@discussion		This key points to a CFURLRef value with the URL of the extension host application.
*/
VT_EXPORT VTDecoderExtensionPropertiesKey const kVTDecoderExtensionProperties_ContainingBundleURLKey API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos, watchos, visionos);

CM_ASSUME_NONNULL_END

#pragma pack(pop)

#if defined(__cplusplus)
}
#endif

#endif // VTUTILITIES_H
