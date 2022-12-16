#ifndef __HELPER_UTILS_H__
#define __HELPER_UTILS_H__

#include "BCommonDefines.h"
#include "platform/CCPlatformConfig.h"
#include "Types/DataTypes.h"
#include "string"

_BSTART

enum class eShareDataType
{
    IMAGE = 0,
    TEXT
};

class HelperUtils
{
public:

    static std::string getStringWithoutSpaces(const std::string &aStr);

    static std::string stringToUpper(const std::string &aStr, const unsigned aStartIndex, const unsigned aEndIndex , const std::string& aLoc = "");
	static std::string stringToLower(const std::string &aStr, const unsigned aStartIndex, const unsigned aEndIndex);

	static std::string stringReplaceAll(const std::string& aStr, const std::string& aWhat, const std::string& aWith = "");

	static std::string getSupportPageURL();

    static std::string getDLCFolderPath();

    static std::string getShareContentFolderPath();

    static std::string getShareFilePath(eImageFormat aImageFormate = eImageFormat::WEBP);

#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_IOS )
    static void shareObject(eShareDataType aType, const std::string& aText, const std::string& aImgUri = "");
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	static void checkDeeplinkIntentData();
    static void shareObject(eShareDataType aType, const std::string& aText, const std::string& aImgUri = "");
#endif
	static int getTagFromSetName(const std::string& aName);
};

_BEND


#endif    // end of __HELPER_UTILS_H__
