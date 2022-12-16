#include "HelperUtils.h"
#include "base/ccUTF8.h"
#include "GCSWrapper.h"
#include "Managers/Players/PlayerProfile.h"
#include "Managers/Data/DataManager.h"


#include "codecvt"

_USEB

#if ( CC_TARGET_PLATFORM != CC_PLATFORM_IOS )

std::string HelperUtils::stringToUpper(const std::string &aStr, const unsigned aStartIndex, const unsigned aEndIndex, const std::string& aLoc)
{
	std::string result = aStr;

	if ( aStartIndex < aEndIndex && aStr.size() >= aEndIndex )
	{
		std::wstring wstr;
		std::wstring wstrUpper;

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv;
		wstr = conv.from_bytes( result );
		wstrUpper = wstr;

		if (aLoc == "ru_RU")
		{
			for (unsigned i = 0u; i < wstrUpper.size(); i++)
			{
				wchar_t letter = wstrUpper[i];
				if (letter >= 1072 && letter <= 1103 )
				{
					wstrUpper[i] = letter - 32;
				}
				else if (letter == 1105)
				{
					wstrUpper[i] = 1025;
				}
			}
		}
		else
		{
			auto locale = std::locale("");
			auto& facet = std::use_facet<std::ctype<wchar_t>>(locale);
			facet.toupper(&wstrUpper[0], &wstrUpper[0] + wstrUpper.size());
		}
		/*
		if( aLoc == "pt_PT" )
		{
			for ( auto i = 0; i < wstr.size(); i++ )
			{
				char32_t letter = wstr[i];
				if (letter >= 224 && letter <= 246 )
				{
					wstr[i] = letter - 32;
				}
			}
		}
		*/

		wstr.erase( aStartIndex, aEndIndex );
		wstr.insert(aStartIndex, wstrUpper.substr(aStartIndex, aEndIndex));

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv8;
        result = conv8.to_bytes( wstr );
	}

	return result;
}

std::string HelperUtils::stringToLower(const std::string &aStr, const unsigned aStartIndex, const unsigned aEndIndex)
{
	std::string result = aStr;

	if (aStartIndex < aEndIndex && aStr.size() >= aEndIndex)
	{
		std::wstring wstr;
		std::wstring wstrLower;

		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv;
		wstr = conv.from_bytes(result);
		wstrLower = wstr;


		auto locale = std::locale("");
		auto& facet = std::use_facet<std::ctype<wchar_t>>(locale);
		facet.tolower(&wstrLower[0], &wstrLower[0] + wstrLower.size());

		wstr.erase(aStartIndex, aEndIndex);
		wstr.insert(aStartIndex, wstrLower.substr(aStartIndex, aEndIndex));

		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv8;
		result = conv8.to_bytes(wstr);
	}

	return result;
}

#endif

std::string HelperUtils::stringReplaceAll(const std::string& aStr, const std::string & aWhat, const std::string & aWith)
{
	auto result = aStr;

	for (size_t pos = 0; (pos = result.find(aWhat, pos)) != std::string::npos; pos += aWith.length())
	{
		result.replace(pos, aWhat.length(), aWith);
	}

	return result;
}

std::string HelperUtils::getStringWithoutSpaces(const std::string &aStr)
{
    std::string resString = aStr;
    std::u16string strUTF16;
    StringUtils::UTF8ToUTF16(resString, strUTF16);

    std::u16string spaces = { 32, 160, 8199, 8239, 8288 };

    int posBegin = 0;
    while (static_cast<std::size_t>(posBegin) < strUTF16.size() && spaces.find(strUTF16[posBegin]) != std::u16string::npos)
    {
        ++posBegin;
    }

    int posEnd = static_cast<int>(strUTF16.size() - 1);
    while (posEnd > -1 && spaces.find(strUTF16[posEnd]) != std::u16string::npos)
    {
        --posEnd;
    }

    if (posBegin <= posEnd)
    {
        strUTF16 = strUTF16.substr(posBegin, posEnd - posBegin + 1);
    }
    else
    {
        strUTF16.clear();
    }

    resString.clear();
    StringUtils::UTF16ToUTF8(strUTF16, resString);

    return resString;
}
std::string HelperUtils::getSupportPageURL()
{
	std::string url = GCSWrapper::getInstance()->getSupportURL();

	BValue progress;

	int coins = PLAYER->getCurrency(eCurrencyType::CASH);
	int gems = PLAYER->getCurrency(eCurrencyType::CRYSTALS);
	int level = PLAYER->getLevel();
	int exp = PLAYER->getExperience();
	int maxExp = 0;

	const auto nextLevelInfo = DM->getLevelInfoByNumber(level + 1);
	if (nextLevelInfo)
	{
		maxExp = nextLevelInfo->requiredExperience;
	}

	progress.initWithFormat("level=%d+Xp(%d+of+%d),+Coins+%d,+Gems+%d", level, exp, maxExp, coins, gems);

	std::string toAppend = "&" + progress.getString();

	url.append(toAppend);

	bool needToDeleteSpaces = true;

	while (needToDeleteSpaces)
	{
		auto pos = url.find(" ");

		if (pos == std::string::npos)
		{
			needToDeleteSpaces = false;
		}
		else
		{
			url.replace(pos, 1, "%20");
}
	}

	int pos = url.find("https");

	if (pos == std::string::npos)
	{
		pos = url.find("http");

		if (pos != std::string::npos)
		{
			url.replace(pos, 4, "https");
		}
	}

	return url;
}

std::string HelperUtils::getShareFilePath(eImageFormat aImageFormate)
{
	std::string imageType = aImageFormate == eImageFormat::WEBP ? ".webp" : ".png";

	std::string fileName;
	std::string filePath = getDLCFolderPath();
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	fileName = "share_" + PLAYER->getShortPlayerUniqueID() + imageType;
	filePath = getShareContentFolderPath();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	fileName = "DLC/share_" + PLAYER->getShortPlayerUniqueID() + imageType;
#else
	fileName = "DLC\\share_" + PLAYER->getShortPlayerUniqueID() + imageType;
#endif

	std::string fullPath = filePath + fileName;
	return fullPath;
}

std::string HelperUtils::getShareContentFolderPath()
{
	std::string path = FileUtils::getInstance()->getWritablePath();
	return path;
}

std::string HelperUtils::getDLCFolderPath()
{
   std::string path;
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    path = FileUtils::getInstance()->getDocumentsWritablePath();
#else
    path = GCSWrapper::getInstance()->getManager()->GetUtils()->GetPathToRootFolder();
#endif
    return path;
}

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )

void HelperUtils::checkDeeplinkIntentData()
{
	JniMethodInfo methodInfo;
	if (!JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AppActivity", "checkDeeplinkIntentData", "()V"))
	{
		log("HelperUtils::checkDeeplinkIntentData %s %d ERROR to get method info", __FILE__, __LINE__);
	}
	else
	{
		log("HelperUtils::checkDeeplinkIntentData call success");

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}

void HelperUtils::shareObject(eShareDataType aType, const std::string& aText, const std::string& aImgUri)
{
	JniMethodInfo methodInfo;
	if (!JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AppActivity", "shareObject", "(ILjava/lang/String;Ljava/lang/String;)V"))
	{
		log("HelperUtils::shareObject %s %d ERROR to get method info", __FILE__, __LINE__);
	}
	else
	{
		log("HelperUtils::shareObject call success");

		jstring dataText = methodInfo.env->NewStringUTF(aText.c_str());
		jstring dataUri = methodInfo.env->NewStringUTF(aImgUri.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, static_cast<int>(aType), dataText, dataUri);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}

#endif

int HelperUtils::getTagFromSetName(const std::string& aName)
{
	int result = 0;

	auto index = aName.find_first_of("_");
	if (index > 0)
	{
		auto tagStr = aName.substr(index + 1);
		result = std::stoi(tagStr);
	}

	return result;
}
