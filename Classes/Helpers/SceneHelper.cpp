#include "SceneHelper.h"
#include "Managers/Players/PlayerProfile.h"
#include "Managers/Debug/DebugManager.h"
#include "Managers/Data/DataManager.h"
#include "Helpers/DataHelper.h"
#include "Helpers/HelperUtils.h"
#include "BGameManager.h"
#include "Views/Effects/BasePostProcess.h"
#include "Misc/TimeCounter.h"
#include "Managers/Server/DlcManager.h"
#include "BTCacheWrapper.h"
#include "BGDHelper.h"
#include "Views/Custom/Character/CharacterView.h"
#include "Managers/Social/SocialManager.h"
#include "Managers/GameDirector.h"
#include "Managers/UI/ScreensManager.h"
#include "Views/SimpleViews/Map/Controllers/NavigationPanelView.h"
#include "Views/SimpleViews/DesignerView/DesignerView.h"
#include "Views/ViewFactory.h"
#include "BJsonHelper.h"
#include "Helpers/DataTypesHelper.h"
#include "Helpers/NodeHelper.h"
#include "Managers/GameDirector.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "webp/include/android/encode.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "webp/include/ios/encode.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "webp/include/win32/encode.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "webp/include/mac/encode.h"
#endif




_USEB

BValueVector SceneHelper::mTestingLogs;

unsigned long SceneHelper::getCurrentTime()
{
    time_t timep;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    time(&timep);
#else
    timeval now;
    gettimeofday(&now, NULL);
    timep = now.tv_sec;
#endif

    return timep;
}

uint64_t SceneHelper::getCurrentTimeInMilliseconds()
{
    time_t timep;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    timep = clock() * 1000 / CLOCKS_PER_SEC;
#else
    timeval now;
    gettimeofday(&now, NULL);

    timep = (now.tv_sec * (uint64_t)1000) + (now.tv_usec / 1000);
#endif

    return timep;
}


void SceneHelper::updateRemainingTimeToTarget(Label* aTimeLabel, long aTargetTime, const std::string& aScheduleTag, std::function< void() > aFunc )
{
    auto remainingTimeMap = getRemainingTimeToTargetInSpecialFormat(aTargetTime);

    auto remainingDays = remainingTimeMap[eTimeFormatType::DAYS];
    auto remainingHours = remainingTimeMap[eTimeFormatType::HOURS];
    auto remainingMinutes = remainingTimeMap[eTimeFormatType::MINUTES];
    auto remainingSeconds = remainingTimeMap[eTimeFormatType::SECONDS];

    if (remainingDays || remainingHours || remainingMinutes || remainingSeconds)
    {
        BValue remainingTimeStr;

        if (remainingDays)
        {
            remainingTimeStr.initWithFormat("%dd %02d:%02d:%02d", remainingDays, remainingHours, remainingMinutes, remainingSeconds);
        }
        else
        {
            remainingTimeStr.initWithFormat("%02d:%02d:%02d", remainingHours, remainingMinutes, remainingSeconds);
        }

        if (aTimeLabel)
        {
            aTimeLabel->setString(remainingTimeStr.getString());
        }
    }
    else
    {
        if (aTimeLabel)
        {
            aTimeLabel->setVisible(false);
            aTimeLabel->unschedule(aScheduleTag);

            if( aFunc )
            {
                aFunc();
            }
        }
    }
}

unsigned long SceneHelper::convertStringToULong(const std::string& aConvertedString)
{
    unsigned long result = 0;

    result = std::strtoul(aConvertedString.c_str(), nullptr, 0);

    return result;
}

// TODO: while working on blur logic implementation always check for potential memory leaks by creating/deleting 
// of BasePostProccess objects. 

Node* SceneHelper::createBlurredTexture( const std::string& aTextureResID, Size& aBluredTextureSize, Vec2& aBluredTexturePos, float aBlurStrength )
{
    Node* result = nullptr;

    auto fragmentFilePath = GET_RESOURCE_PATH("BLUR_EFFECT_FRAG");
    auto verticesFilePath = GET_RESOURCE_PATH("BLUR_EFFECT_VERT");

    auto bluredTexture = Sprite::create( GET_RESOURCE_PATH( aTextureResID ) );

    auto blurXPostProcessLayer = BasePostProcess::create( verticesFilePath, fragmentFilePath, aBluredTextureSize );
    auto blurYPostProcessLayer = BasePostProcess::create( verticesFilePath, fragmentFilePath, aBluredTextureSize );

    if ( blurXPostProcessLayer && blurYPostProcessLayer && bluredTexture )
    {
        bluredTexture->setContentSize(aBluredTextureSize);
        bluredTexture->setAnchorPoint(Vec2::ZERO);
        bluredTexture->setPosition(Vec2::ZERO);
        
        blurYPostProcessLayer->setContentSize( aBluredTextureSize );

        auto blurProcessXState = blurXPostProcessLayer->getGLProgramState();

        if ( blurProcessXState )
        { 
            blurProcessXState->setUniformVec2( "u_blurOffset", Vec2( aBlurStrength / aBluredTextureSize.width, aBlurStrength / aBluredTextureSize.height ) );
        }

        bluredTexture->setVisible(true);
        blurXPostProcessLayer->draw( bluredTexture );
        bluredTexture->setVisible(false);

        auto blurProcessYState = blurYPostProcessLayer->getGLProgramState();

        if ( blurProcessYState )
        { 
            blurProcessYState->setUniformVec2( "u_blurOffset", Vec2( aBlurStrength / aBluredTextureSize.width, -aBlurStrength / aBluredTextureSize.height ) );
        }

        blurXPostProcessLayer->setVisible( true );
        blurYPostProcessLayer->draw( blurXPostProcessLayer );
        blurXPostProcessLayer->setVisible( false );

        result = blurYPostProcessLayer;
    }

    return result;
}

void SceneHelper::switchMainScreenBack(const std::string& aCalledFrom, BValueMap aParams)
{
	auto navigationPanel = SCREENS_MNG->getNavigationPanelView();
	if (navigationPanel)
	{
		auto btnType = eButtonType::BTN_MAP;

		if (aCalledFrom == "LEADERBOARDS_VIEW")
		{
			btnType = eButtonType::BTN_LEADEDRS;
		}
		else if (aCalledFrom == "GLOBAL_LEADERBOARDS_VIEW")
		{
			btnType = eButtonType::BTN_CHAT;
			aParams["first_tab"] = "none";
		}
		else if (aCalledFrom == "VOTING_VIEW"
			|| aCalledFrom == "INSPECT_LOOK_VIEW")
		{
			btnType = eButtonType::BTN_VOTING;
		}

		navigationPanel->switchScreensManually(btnType, aParams);
	}
}

unsigned long SceneHelper::getGameTime()
{
    return  GCSWrapper::getInstance()->getServerTimeStamp();
}

std::tm SceneHelper::getGameDate()
{ 
	auto timeStamp = GCSWrapper::getInstance()->getServerTimeStamp();
	std::tm now = *std::localtime(&timeStamp);
	now.tm_year += 1900;
	return now;
}

std::map< eTimeFormatType, int > SceneHelper::getRemainingTimeToTargetInSpecialFormat( unsigned long aTargetTime )
{
    std::map< eTimeFormatType, int > result;
    result[eTimeFormatType::DAYS] = 0;
    result[eTimeFormatType::HOURS] = 0;
    result[eTimeFormatType::MINUTES] = 0;
    result[eTimeFormatType::SECONDS] = 0;

    unsigned long currentTime = SceneHelper::getGameTime();

    if ( aTargetTime > currentTime)
    {
        auto remainingTime = aTargetTime - currentTime;

        const unsigned long secondsInMinute = SECONDS_IN_MINUTE;
        const unsigned long secondsInHour = SECONDS_IN_HOUR;
        const unsigned long secondsInDay = SECONDS_IN_DAY;

        auto remainingDays = remainingTime / secondsInDay;
        remainingTime -= remainingDays * secondsInDay;

        auto remainingHours = remainingTime / secondsInHour;
        remainingTime -= remainingHours * secondsInHour;

        auto remainingMinutes = remainingTime / secondsInMinute;
        remainingTime -= remainingMinutes * secondsInMinute;

        auto remainingSeconds = remainingTime; 

        result[eTimeFormatType::DAYS] = static_cast< int >(remainingDays);
        result[eTimeFormatType::HOURS] = static_cast< int >(remainingHours);
        result[eTimeFormatType::MINUTES] = static_cast< int >(remainingMinutes);
        result[eTimeFormatType::SECONDS] = static_cast< int >(remainingSeconds);
    }

    return result;
}

std::map<eTimeFormatType, int> SceneHelper::getTimeInSpecialFormat( long aTargetTime )
{
    std::map< eTimeFormatType, int > result;
    result[ eTimeFormatType::DAYS ] = 0;
    result[ eTimeFormatType::HOURS ] = 0;
    result[ eTimeFormatType::MINUTES ] = 0;
    result[ eTimeFormatType::SECONDS ] = 0;

    if ( aTargetTime > 0 )
    {
        const unsigned long secondsInMinute = SECONDS_IN_MINUTE;
        const unsigned long secondsInHour = SECONDS_IN_HOUR;
        const unsigned long secondsInDay = SECONDS_IN_DAY;

        auto remainingDays = aTargetTime / secondsInDay;
        aTargetTime -= remainingDays * secondsInDay;

        auto remainingHours = aTargetTime / secondsInHour;
        aTargetTime -= remainingHours * secondsInHour;

        auto remainingMinutes = aTargetTime / secondsInMinute;
        aTargetTime -= remainingMinutes * secondsInMinute;

        auto remainingSeconds = aTargetTime;

        result[ eTimeFormatType::DAYS ] = static_cast< int >( remainingDays );
        result[ eTimeFormatType::HOURS ] = static_cast< int >( remainingHours );
        result[ eTimeFormatType::MINUTES ] = static_cast< int >( remainingMinutes );
        result[ eTimeFormatType::SECONDS ] = static_cast< int >( remainingSeconds );
    }

    return result;
}

void SceneHelper::setTimeToLabelInSpecialFormat( Label* aTimeLabel, long aTargetTime )
{
    if ( aTimeLabel )
    {
        auto timeInSpecialFormat = getTimeInSpecialFormat( aTargetTime );

        auto days = timeInSpecialFormat[ eTimeFormatType::DAYS ];
        auto hours = timeInSpecialFormat[ eTimeFormatType::HOURS ];
        auto minutes = timeInSpecialFormat[ eTimeFormatType::MINUTES ];
        auto seconds = timeInSpecialFormat[ eTimeFormatType::SECONDS ];

        BValue timeStr;

		if ( days )
		{
			timeStr.initWithFormat( "%d%s %02d:%02d:%02d", days, GET_STRING("TT_DAY").c_str(), hours, minutes, seconds );
		}
		else
		{
			timeStr.initWithFormat( "%02d:%02d:%02d", hours, minutes, seconds );
		}

        if ( aTimeLabel )
        {
            aTimeLabel->setString( timeStr.getString() );
        }
    }
}

void SceneHelper::setTimeToLabeInSpecialMarathonFormat(Label * aTimeLabel, long aTargetTime)
{
    if (aTimeLabel)
    {
        auto timeInSpecialFormat = SceneHelper::getTimeInSpecialFormat(aTargetTime);

        auto days = timeInSpecialFormat[eTimeFormatType::DAYS];
        auto hours = timeInSpecialFormat[eTimeFormatType::HOURS];
        auto minutes = timeInSpecialFormat[eTimeFormatType::MINUTES];
        auto seconds = timeInSpecialFormat[eTimeFormatType::SECONDS];

        BValue timeStr;

		if (days <= 9)
		{
			setTimeToLabelInSpecialFormat(aTimeLabel, aTargetTime);
		}
		else
		{
			if (days)
			{
				timeStr.initWithFormat("%02d%s %02d%s", days,GET_STRING("TT_DAY").c_str(), hours, GET_STRING("TT_HOUR").c_str());
			}
			else if (hours)
			{
				timeStr.initWithFormat("%02d%s %02d%s", hours, GET_STRING("TT_HOUR").c_str(), minutes, GET_STRING("TT_MINUTE").c_str());
			}
			else
			{
				timeStr.initWithFormat("%02d%s %02d%s", minutes, GET_STRING("TT_MINUTE").c_str(), seconds, GET_STRING("TT_SECOND").c_str());
			}

            aTimeLabel->setString(timeStr.getString());
        }
    }
}

void SceneHelper::setTimeToLabelInSpecialMarathonFormatHM(std::string stringID, Label * aTimeLabel, long aTargetTime)
{
    if (aTimeLabel)
    {
        auto timeInSpecialFormat = SceneHelper::getTimeInSpecialFormat(aTargetTime);

        auto hours = timeInSpecialFormat[eTimeFormatType::HOURS];
        auto minutes = timeInSpecialFormat[eTimeFormatType::MINUTES];

        BValue timeStr;
        BValue resultString;

		timeStr.initWithFormat("%02d%s %02d%s", hours, GET_STRING("TT_HOUR").c_str(), minutes, GET_STRING("TT_MINUTE").c_str());

        std::string currentString = GET_STRING(stringID);

        resultString.initWithFormat(currentString.c_str(), timeStr.getString().c_str());
        
        aTimeLabel->setString(resultString.getString());
    }
}

void SceneHelper::setTimeToLabelInSimpleFormat(Label * aTimeLabel, long aTargetTime, int borderDay)
{
    if (aTimeLabel)
    {
        auto timeInSpecialFormat = SceneHelper::getTimeInSpecialFormat(aTargetTime);

        auto days = timeInSpecialFormat[eTimeFormatType::DAYS];
        auto hours = timeInSpecialFormat[eTimeFormatType::HOURS];
        auto minutes = timeInSpecialFormat[eTimeFormatType::MINUTES];
        auto seconds = timeInSpecialFormat[eTimeFormatType::SECONDS];

        BValue timeStr;

        bool isBorderDay = false;

		if (days <= borderDay)
		{
		
			if (days)
			{
				timeStr.initWithFormat("%d%s %02d:%02d", days, GET_STRING("TT_DAY").c_str(), hours, minutes);
			}
			else
			{
				timeStr.initWithFormat("%02d:%02d:%02d", hours, minutes, seconds);
			}

            if (aTimeLabel)
            {
                aTimeLabel->setString(timeStr.getString());
            }
            
            isBorderDay = true;
        }

		if (!isBorderDay || borderDay == -1)
		{
			if (days)
			{
				timeStr.initWithFormat("%02d%s %02d%s", days, GET_STRING("TT_DAY").c_str(), hours, GET_STRING("TT_HOUR").c_str());
			}
			else if (hours)
			{
				timeStr.initWithFormat("%02d%s %02d%s", hours, GET_STRING("TT_HOUR").c_str(), minutes, GET_STRING("TT_MINUTE").c_str());
			}
			else
			{
				timeStr.initWithFormat("%02d%s %02d%s", minutes, GET_STRING("TT_MINUTE").c_str(), seconds, GET_STRING("TT_SECOND").c_str());
			}

            aTimeLabel->setString(timeStr.getString());
        }
    }
}

std::string SceneHelper::getStrFromAppDelegateResolution( eAppDelegateResolution aAppDelegateResolution )
{
    std::string result;

    switch ( aAppDelegateResolution )
    {
    case eAppDelegateResolution::RES_1536_2048:
        result = "res_1536_2048";
        break;
    case eAppDelegateResolution::RES_2048_3330:
        result = "res_2048_3330";
        break;
    case eAppDelegateResolution::RES_2048_3330_M:
        result = "res_2048_3330";
        break;
    case eAppDelegateResolution::RES_750_1334:
        result = "res_750_1334";
        break;
    }

    return result;
}

tm * SceneHelper::getTimeStructByTimeInSeconds( time_t aTime )
{
    struct tm *spTime;
    spTime = localtime( &aTime );
    spTime->tm_year = spTime->tm_year + 1900;
    spTime->tm_mon += 1;

    return spTime;
}

time_t SceneHelper::getMidnightTimeForDayByTimeInSeconds( time_t aTime )
{
    time_t result = 0;

    tm timeStruct = *( SceneHelper::getTimeStructByTimeInSeconds( aTime ) );
    tm midnightTime = timeStruct;

    midnightTime.tm_mday += 1;
    midnightTime.tm_hour = 0;
    midnightTime.tm_min = 0;
    midnightTime.tm_sec = 0;

    midnightTime.tm_year -= 1900;
    midnightTime.tm_mon -= 1;

    result = mktime( &midnightTime );

    return result;
}

time_t SceneHelper::calculateMidnightTime(time_t aTime)
{
    time_t result = 0;

    tm* timeInTM = localtime(&aTime);

    if (timeInTM)
    {
        timeInTM->tm_sec = 0;
        timeInTM->tm_min = 0;
        timeInTM->tm_hour = 0;

        result = mktime(timeInTM);
    }

    return result;
}

void SceneHelper::setImageFromTexturePack(Node* aNode, const std::string& aTexturePack, const std::string& aTextureId, bool aIsScaleToFrameSize)
{
    BTCWrapper->loadTexturePackFile(GET_RESOURCE_PATH(aTexturePack));
    auto& resParams = GET_RESOURCE_PARAMS(aTexturePack);
    if (resParams.checkType(BValue::Type::MAP))
    {
        auto& resMap = resParams.getValueMap();
        auto resIt = resMap.find(aTextureId);
        if (resIt != resMap.end() && resIt->second.checkType(BValue::Type::STRING))
        {
            setImage(aNode, resIt->second.getString(), aIsScaleToFrameSize);
        }
    }
    else
    {
        setImage(aNode, aTextureId, aIsScaleToFrameSize);
    }
}

void SceneHelper::setImageFromTexturePackAndScale(Node* aNode, Node* aBox, const std::string& aTexturePack, const std::string& aTextureId)
{
    Node container;
    container.setContentSize(aBox->getContentSize());
    SceneHelper::setImageFromTexturePack(aNode, aTexturePack, aTextureId);
    NodeHelper::scaleDownNodeToContainerSize(aNode, &container);
}

void SceneHelper::setImage(Node * aNode, const std::string & aPath, bool aIsScaleToFrameSize)
{
    auto image = dynamic_cast<ui::ImageView*>( aNode );
    auto spr = dynamic_cast<Sprite*>( aNode );

    std::string frameName = aPath.substr(aPath.find_last_of("/") + 1);
    auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
    if ( !frame )
    {
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(aPath);
    }

	if (aIsScaleToFrameSize && aNode && frame)
	{
		auto size = frame->getRect().size;
		aNode->setContentSize(size);
	}

    if ( frame )
    {
        if ( spr )
        {
            spr->setSpriteFrame(frame);
        }
        else if ( image )
        {
            image->loadTexture(frame);
        }
    }
    else
    {
        if ( spr )
        {
            spr->setTexture(aPath);
        }
        else if ( image )
        {
            image->loadTexture(aPath);
        }
    }
}

void SceneHelper::loadTextureAsync(const std::string & aPath, std::function<void(std::string)> aFunc)
{
    auto textureCache = Director::getInstance()->getTextureCache();

    std::string fileName = aPath.substr(0, aPath.find_last_of(".")) + ".plist";

    if ( FileUtils::getInstance()->isFileExist(aPath) )
    {
        std::string texturePath = aPath;
        size_t startPos = texturePath.find_last_of(".");
        texturePath = texturePath.erase(startPos);
        texturePath.append(".webp");

        if ( !FileUtils::getInstance()->isFileExist(texturePath) )
        {
            startPos = texturePath.find_last_of(".");
            texturePath = texturePath.erase(startPos);
            texturePath.append(".png");
        }

        auto texture = textureCache->getTextureForKey( texturePath );
        if ( texture )
        {
            BTCWrapper->loadTexturePackFile(fileName);
            aFunc(aPath);
        }
        else
        {
            textureCache->addImageAsync(texturePath, [fileName, aPath, aFunc](Texture2D* aTexture) {
                BTCWrapper->loadTexturePackFile(fileName);
                aFunc(aPath);
                });
        }
    }
    else
    {
        auto textureCache = Director::getInstance()->getTextureCache();

        auto texture = textureCache->getTextureForKey(aPath);
        if ( texture )
        {
            aFunc(aPath);
        }
        else
        {
            textureCache->addImageAsync(aPath, [aPath, aFunc](Texture2D* aTexture) {
                aFunc(aPath);
                });
        }
    }
}

void SceneHelper::loadTextureAsyncCDN(const std::string& aPath, std::function<void(std::string)> aFunc)
{
	if (aFunc)
	{
		auto textureCache = Director::getInstance()->getTextureCache();

		auto texture = textureCache->getTextureForKey(aPath);
		if (texture)
		{
			aFunc(aPath);
		}
		else if (FileUtils::getInstance()->isFileExist(aPath))
		{
			textureCache->addImageAsync(aPath, [aPath, aFunc](Texture2D* aTexture) {
				aFunc(aPath);
				});
		}
	}
}
void SceneHelper::launchAllActionTracks(Node * aTarget)
{
    if ( aTarget )
    {
        for ( auto& child : aTarget->getChildren() )
        {
            auto tracksModule = BGDHelper::getModuleActionTracks(child);

            if ( tracksModule )
            {
                auto tracksMap = tracksModule->getActionsTracksMap();

                for ( auto& trackPair : tracksMap )
                {
                    BGD->playActionTrack(child, trackPair.first);
                }
            }
        }
    }
}

void SceneHelper::stopAllActionTracks(Node * aTarget)
{
    if ( aTarget )
    {
        for ( auto& child : aTarget->getChildren() )
        {
            auto tracksModule = BGDHelper::getModuleActionTracks(child);

            if ( tracksModule )
            {
                auto tracksMap = tracksModule->getActionsTracksMap();

                for ( auto& trackPair : tracksMap )
                {
                    BGD->stopActionTrack(child, trackPair.first);
                }
            }
        }
    }
}

void SceneHelper::addLog(const BValue& aLog)
{
    mTestingLogs.push_back(aLog);
}

void SceneHelper::clearLogs()
{
    mTestingLogs.clear();
}

void SceneHelper::saveLogs()
{
    flushLogs(mTestingLogs);
}

void SceneHelper::flushLogs(const BValue& aLog, std::string  aNameFile )
{
	std::string path; 

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	path = FileUtils::getInstance()->getDocumentsWritablePath();
#else
	path = FileUtils::getInstance()->getWritablePath();
#endif

	//std::string path = FileUtils::getInstance()->getDocumentsWritablePath() + aNameFile + ".json";
	path.append(aNameFile);
	path.append(".json");

	rapidjson::Document doc;
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
	doc.SetObject();

    BJsonHelper::saveBValueToJsonValue(doc, aLog, allocator);
    rapidjson::StringBuffer strbuf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(strbuf);
    doc.Accept(writer);

    std::string dir;
    auto findIt = path.find_last_of("/");
    if (findIt != std::string::npos)
    {
        dir = path.substr(0, findIt+1);
    }

    if (!dir.empty() && !FileUtils::getInstance()->isDirectoryExist(dir))
    {
        FileUtils::getInstance()->createDirectory(dir);
    }

    FileUtils::getInstance()->writeStringToFile(strbuf.GetString(), path);

}

void SceneHelper::clearLogs( std::string aNameFile )
{
	std::string path;

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	path = FileUtils::getInstance()->getDocumentsWritablePath();
#else
	path = FileUtils::getInstance()->getWritablePath();
#endif

	//std::string path = FileUtils::getInstance()->getDocumentsWritablePath() + aNameFile + ".json";
	path.append(aNameFile);
	path.append(".json");


	FileUtils::getInstance()->removeFile( path );
}

Texture2D* SceneHelper::transformAvatarAnimationToSprite(const std::string& aClipping, const std::string aAvatar, Node* aPanel)
{
    Texture2D* result = nullptr;
    if (aPanel)
    {
        auto avatarClipping = aPanel->getChildByName(aClipping);
        auto panelOpacity = aPanel->getOpacity();
        auto isCascadOpacity = aPanel->isCascadeOpacityEnabled();
        aPanel->setOpacity(255);
        aPanel->setCascadeOpacityEnabled(false);
        if (avatarClipping)
        {
            float avatarScale = 0.0f;

            auto avatar = dynamic_cast<CharacterView*>(avatarClipping->getChildByName(aAvatar));
            if (avatar)
            {
                avatarScale = avatar->getScale();
                avatar->updateAnimationSpine();
            }
            auto anchorPoint = avatarClipping->getAnchorPoint();
            auto pos = avatarClipping->getPosition();
            avatarClipping->setVisible(true);
            avatarClipping->setScale(1.0f / avatarScale);
            avatarClipping->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            avatarClipping->setPosition(Vec2::ZERO);

            auto size = avatarClipping->getContentSize() * avatarClipping->getScale();    
            auto rendTexture = RenderTexture::create(size.width /* (1.0f + avatarScale)*/,
                size.height /* (1.0f + avatarScale)*/,
                Texture2D::PixelFormat::RGBA8888,
                GL_DEPTH24_STENCIL8);
            rendTexture->retain();

            rendTexture->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);

            avatarClipping->visit();
            rendTexture->end();
            Director::getInstance()->getRenderer()->render();
            result = rendTexture->getSprite()->getTexture();
            auto renderedAvatar = dynamic_cast<Sprite*>(aPanel->getChildByName("rendered_avatar"));
            if (renderedAvatar)
            {
                renderedAvatar->setTexture(result);
            }
            else
            {
                renderedAvatar = Sprite::createWithTexture(result);
                renderedAvatar->getTexture()->setAntiAliasTexParameters();
                aPanel->addChild(renderedAvatar, avatarClipping->getLocalZOrder());
                renderedAvatar->setPosition(pos);
                renderedAvatar->setFlippedY(true);
                renderedAvatar->setName("rendered_avatar");
                renderedAvatar->setCascadeOpacityEnabled(avatar->isCascadeOpacityEnabled());
            }

            if (renderedAvatar && renderedAvatar->getScale() != avatarScale)
            {
                renderedAvatar->setScale(avatarScale);
            }

            avatarClipping->setVisible(false);
            avatarClipping->setScale(1.0f);
            avatarClipping->setAnchorPoint(anchorPoint);

            avatarClipping->setPosition(pos);

            rendTexture->release();
        }

        aPanel->setOpacity(panelOpacity);
        aPanel->setCascadeOpacityEnabled(isCascadOpacity);
    }

    return result;
}

RenderTexture* SceneHelper::renderTextureFromNode(Node * aSource, bool aForcedRender)
{
    RenderTexture* renderTexture = nullptr;
    if (aSource)
    {
        auto panelOpacity = aSource->getOpacity();
        auto isCascadOpacity = aSource->isCascadeOpacityEnabled();
        aSource->setOpacity(255);
        aSource->setCascadeOpacityEnabled(false);

        auto size = aSource->getContentSize() * aSource->getScale();
        renderTexture = RenderTexture::create(size.width * 1.0f ,
                                                 size.height * 1.0f,
                                                 Texture2D::PixelFormat::RGBA8888,
                                                 GL_DEPTH24_STENCIL8);
        renderTexture->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
        aSource->visit();
        renderTexture->end();

        if (aForcedRender)
        {
            Director::getInstance()->getRenderer()->render();
        }
        aSource->setOpacity(panelOpacity);
        aSource->setCascadeOpacityEnabled(isCascadOpacity);
    }

    return renderTexture;
}

bool SceneHelper::saveRenderTextureAsWebp(RenderTexture * aRenderTexture, const std::string & aFullPath, float aQuality, std::function<void()> aSaveCallback)
{
    bool ret = false;

    if (aRenderTexture)
    {
        Director::getInstance()->getRenderer()->render();

        auto img = aRenderTexture->newImage();
        if (img) {
            unsigned char* textureData = img->getData();
            size_t textureDataSize = img->getDataLen();

            int height = img->getHeight();
            unsigned char* writeData;
            size_t writeDataSize = WebPEncodeRGBA(
                textureData,
                img->getWidth(),
                height,
                textureDataSize / height,
                aQuality,
                &writeData
            );

            Data data;
            data.fastSet(writeData, writeDataSize);
            ret = FileUtils::getInstance()->writeDataToFile(data, aFullPath);

            if (aSaveCallback)
            {
                aSaveCallback();
            }
        }
    }

    return ret;
}

bool SceneHelper::saveSharePictureToFile(const sLookMetaData& aItemMetaData, eImageFormat aImageFormate, std::function<void()> aSaveCallback)
{
    bool ret = false;

    BGDView* bgdViewChar = BGDView::create("CHARACTER", "skin_1");
    CharacterView* charView = dynamic_cast<CharacterView*>(bgdViewChar);

    std::string skinID = "skin_dark";
    std::string curArchetype;
    sCharStyleInfo characterStyle;
    characterStyle.customizeInfo = PLAYER->getFullPlayerAvatarStyle().customizeInfo;

    auto itemResData = DM->getLookResourcesData(aItemMetaData.lookID);
    if (itemResData && itemResData->isLoaded)
    {
        curArchetype = itemResData->archetypeInfo.archetype;
    }

	auto colors = DataHelper::rightShift(aItemMetaData.lfilterColor);
    if (colors.size() == 1)
    {
        if (static_cast<eLookFilterColor>(*colors.begin()) == eLookFilterColor::BLACK)
        {
            skinID = "skin_light";
        }
    }

    characterStyle.looks.insert(std::make_pair(aItemMetaData.lookType, aItemMetaData.lookID));

    if (charView)
    {
        Size newSize = charView->getContentSize();
        auto topLimit = 0.0f;
        auto botLimit = 0.0f;

        auto limits = DM->getArchetypeCropY(curArchetype);
        if (limits.size() == 2)
        {
            auto iter = limits.find("cropHeight");
            if (iter != limits.end())
            {
                topLimit = limits["cropHeight"];
            }

            iter = limits.find("charPosition");
            if (iter != limits.end())
            {
                botLimit = limits["charPosition"];
            }
        }

        float xShift = 0;
        auto background = charView->getChildByName("background");
        if (background)
        {
            auto bgWidth = background->getContentSize().width;
            if (newSize.width > bgWidth)
            {
                xShift = newSize.width - bgWidth;
                newSize.width = bgWidth;
            }
        }

        auto imgOffset = newSize.width * 0.05f;
        auto height = newSize.height - newSize.height * topLimit;
        auto posY = newSize.height * 0.05f - newSize.height * botLimit;
        auto uPosY = fabs(posY);
        if (uPosY > fabs(newSize.height - height))
        {
            height -= uPosY;
        }
        charView->setContentSize(Size(newSize.width - imgOffset, height));
        charView->setPositionY(posY);
        charView->setPositionX(charView->getPositionX() - imgOffset - xShift / 2.0f);

        charView->resumeAnimTrack();
        charView->playAnimTrack("idle_a", true);
        charView->pauseAnimTrack();
        charView->makeDemoModel();
        characterStyle.customizeInfo.isHairEndsEnabled = false;
        characterStyle.customizeInfo.skin_id = skinID;

        auto skinClr = DM->getSkinColorsParamsByID(skinID);
        if (skinClr["r"].isDouble() && skinClr["g"].isDouble() && skinClr["b"].isDouble())
        {
            auto r = skinClr["r"].getFloat();
            auto g = skinClr["g"].getFloat();
            auto b = skinClr["b"].getFloat();
            auto& parts = characterStyle.customizeInfo.colorParts;
            for (auto& part : parts)
            {
                part.second = Color4F(r, g, b, 1.0f);
            }
        }

        charView->applyCharStyle(characterStyle, false);

        RenderTexture* rendTexture = renderTextureFromNode(charView);
        if (rendTexture)
        {
            std::string fullPath = HelperUtils::getShareFilePath(aImageFormate);

            if (aImageFormate == eImageFormat::WEBP)
            {
                ret = saveRenderTextureAsWebp(rendTexture, fullPath, 100.0f, aSaveCallback);
            }
            else if (aImageFormate == eImageFormat::PNG)
            {
                ret = saveRenderTextureAsPNG(rendTexture, fullPath, aSaveCallback);
            }
        }
    }

    return ret;
}

bool SceneHelper::savePlayerAvatarToFile(Node* aCharacter)
{
    bool result = false;
    
    CharacterView* charView = dynamic_cast<CharacterView*>(aCharacter);
    auto avatarSettings = DM->getMainConfigValueByID("avatar_settings");
    Size dim = Size(0.0f, 0.0f);
    auto scale = 0.0f;
    auto skinID = GD->getDefSkinIDForAspectRatio();

    // abort if not all look resources are loaded
    bool allItemsLoaded = true;
    const sCharStyleInfo & fullAvatarStyle = PLAYER->getProfileAvatarFull();
    for (auto look : fullAvatarStyle.looks)
    {
        auto lookResData = DM->getLookResourcesData(look.second);
        if (!lookResData || !lookResData->isLoaded)
        {
            allItemsLoaded = false;
            break;
        }
    }

    if (avatarSettings.isMap())
    {
        auto settingsMap = avatarSettings.getValueMap();
        auto endIt = settingsMap.end();

        auto setIt = settingsMap.find("avatar_dimension");
        if(setIt != endIt && setIt->second.isMap())
        {
            auto dimMap = setIt->second.getValueMap();
            auto endDim = dimMap.end();

            setIt = dimMap.find("width");
            if (setIt != endDim && setIt->second.isDouble())
            {
                dim.width = setIt->second.getDouble();
            }

            setIt = dimMap.find("height");
            if (setIt != endDim && setIt->second.isDouble())
            {
                dim.height = setIt->second.getDouble();
            }
        }
        
        setIt = settingsMap.find("avatar_scale");
        if(setIt != endIt && setIt->second.isMap())
        {
            auto scaleMap = setIt->second.getValueMap();
            setIt = scaleMap.find(skinID);
            if (setIt != scaleMap.end() && setIt->second.isDouble())
            {
                scale = setIt->second.getDouble();
            }
        }
    }

    if (charView && allItemsLoaded)
    {
        Size newSize = charView->getContentSize();


        RenderTexture* rendTexture = renderTextureFromNode(charView);

        if (rendTexture)
        {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
            std::string fileName = "DLC\\avatar_" + PLAYER->getShortPlayerUniqueID() + ".webp";
#else
            std::string fileName = "DLC/avatar_" + PLAYER->getShortPlayerUniqueID() + ".webp";
#endif
            std::string fullPath = HelperUtils::getDLCFolderPath() + fileName;

            result = saveRenderTextureAsWebp(rendTexture, fullPath, dim, scale);
#ifdef USES_AWS_CLIENT
            DLC_MNG->uploadPlayerAvatarToS3(fileName);
#endif
        }
    }

    return result;
}

bool SceneHelper::saveRenderTextureAsWebp(RenderTexture * aRenderTexture, const std::string & aFullPath, const Size & aSize, const float aScale, float aQuality)
{
    bool ret = false;

    if (aRenderTexture && aSize.width > 0 && aSize.height > 0)
    {
        // render aRenderTexture
        Director::getInstance()->getRenderer()->render();

        Texture2D* textureCopy = new Texture2D;
        textureCopy->initWithImage(aRenderTexture->newImage());

        auto curSize = textureCopy->getContentSize();
        Sprite* sprite = Sprite::createWithTexture(textureCopy);
        sprite->setContentSize(curSize * aScale);
        sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

        RenderTexture* rendTextureResized = RenderTexture::create(aSize.width, aSize.height);
        rendTextureResized->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
        sprite->visit();
        rendTextureResized->end();

        // render rendTextureResized
        Director::getInstance()->getRenderer()->render();

        auto img = rendTextureResized->newImage();
        if (img)
        {
            unsigned char* textureData = img->getData();
            if (textureData)
            {
                size_t textureDataSize = img->getDataLen();

                int height = img->getHeight();
                unsigned char* writeData;
                size_t writeDataSize = WebPEncodeRGBA(
                    textureData,
                    img->getWidth(),
                    height,
                    textureDataSize / height,
                    aQuality,
                    &writeData
                );

                Data data;
                data.fastSet(writeData, writeDataSize);
                ret = FileUtils::getInstance()->writeDataToFile(data, aFullPath);
            }
        }
    }

    return ret;
}

bool SceneHelper::saveRenderTextureAsPNG(RenderTexture* aRenderTexture, const std::string& aFullPath, std::function<void()> aSaveCallback)
{
    bool ret = false;

    if (aRenderTexture)
    {
        DM->saveImageToFIle(aRenderTexture, aFullPath, Image::Format::PNG, true, aSaveCallback);
    }

    return ret;
}

void SceneHelper::useFBIconInsteadAvatar(Node* aPanel, const std::string& aClipping, const std::string aAvatar, const std::string aFbId, bool aIsUseIcon,const std::string& aKey)
{
    if (aPanel)
    {
        auto clipping = aPanel->getChildByName(aClipping);
        if (clipping)
        {
            if (aIsUseIcon)
            {
                auto avatar = clipping->getChildByName(aAvatar);
                auto iconFbDef = clipping->getChildByName("icon_fb_def");
                auto isUseIcon = false;

                if (useFBIcon(clipping, aFbId, aKey))
                {
                    isUseIcon = true;
                }


                if ( iconFbDef)
                {
                    iconFbDef->setVisible(!isUseIcon);
                }


                if (avatar)
                {
                    avatar->setVisible( !iconFbDef && !isUseIcon);
                }

                auto renderedAvatar = aPanel->getChildByName("rendered_avatar");
                if (renderedAvatar)
                {
                    renderedAvatar->setVisible(false);
                }

                clipping->setVisible( true );

            }
            else
            {
                auto fbIcon = clipping->getChildByName("icon_fb");
                if (fbIcon)
                {
                    fbIcon->removeFromParent();
                }


                auto iconFbDef = clipping->getChildByName("icon_fb_def");
                if (iconFbDef)
                {
                    iconFbDef->setVisible(false);
                }

                auto renderedAvatar = aPanel->getChildByName("rendered_avatar");
                if (renderedAvatar)
                {
                    renderedAvatar->setVisible(true);
                    clipping->setVisible(false);
                }

                auto avatar = clipping->getChildByName(aAvatar);
                if (avatar)
                {
                    avatar->setVisible(true);
                }
            }
        }
    }
}
bool SceneHelper::useFBIcon(Node* aPanel, const std::string& aFBId,const std::string& aKey)
{
    bool result = false;
    auto imagePath = SOCIAL_MNG->getFBIconPathByUserId(aFBId,aKey);
    if (aPanel && !imagePath.empty())
    {
        result = true;
        auto renderedAvatar = dynamic_cast<Sprite*>(aPanel->getChildByName("icon_fb"));
        if (renderedAvatar)
        {
            renderedAvatar->setTexture(imagePath);
        }
        else
        {
			BValueMap params;
			params["path"] = imagePath;
			params["name"] = "icon_fb";
			params["pos"] = aPanel->getContentSize() / 2.0f;
            params["anchor"] = Vec2::ANCHOR_BOTTOM_LEFT;
			params["order"] = 100;

			renderedAvatar = SceneHelper::createSpriteWithParams(params, aPanel);
        }

        NodeHelper::scaleDownNodeToContainerSize( renderedAvatar, aPanel, true);
    }

    return result;
}
Texture2D* SceneHelper::updateAvatarPlayer(Node* aPanel, const std::string& aClipping, const std::string aAvatar, const std::string aFbId, bool aIsFBIcon,const std::string& aKey)
{
    Texture2D* result = nullptr;
    if (aPanel)
    {
        if (!aFbId.empty() && aIsFBIcon)
        {
            useFBIconInsteadAvatar(aPanel, aClipping, aAvatar,aFbId, aIsFBIcon,aKey);
        }
        else
        {
            useFBIconInsteadAvatar(aPanel, aClipping, aAvatar, aFbId, false);
            result = transformAvatarAnimationToSprite(aClipping, aAvatar, aPanel);
        }
    }

    return result;
}


Node* SceneHelper::createTemplate(const std::vector<std::string>& aPaths, const std::string& aName, Node* aParent)
{
    Node* result = nullptr;

    auto info = getTemplateInfo(aPaths, aName);
    result = createNodeFromTemplateInfo(info, aParent);

    return result;
}

Node* SceneHelper::createTemplate(const std::string& aPaths, const std::string& aName, Node* aParent)
{
    Node* result = nullptr;

    auto info = getTemplateInfo(aPaths, aName);
    result = createNodeFromTemplateInfo(info,aParent);

    return result;
}

sBGDNodeInfo SceneHelper::getTemplateInfo(const std::vector<std::string>& aPaths, const std::string& aName)
{
    sBGDNodeInfo result;

    auto nodeInfo = BGD->getNodeInfo(aPaths, aName, GD->getDefSkinIDForAspectRatio());
    if (nodeInfo)
    {
        result = *nodeInfo;
        result.params[static_cast<int> (eNodeType::NODE)][static_cast<int>(eNodeParam::AUTOCREATE)] = true;
    }

    return result;
}

sBGDNodeInfo SceneHelper::getTemplateInfo(const std::string& aPaths, const std::string& aName)
{
    sBGDNodeInfo result;

    auto nodeInfo = BGD->getNodeInfo(aPaths, aName, GD->getDefSkinIDForAspectRatio());
    if (nodeInfo)
    {
        result = *nodeInfo;
        result.params[static_cast<int> (eNodeType::NODE)][static_cast<int>(eNodeParam::AUTOCREATE)] = true;
    }

    return result;
}

Node* SceneHelper::createNodeFromTemplateInfo(const sBGDNodeInfo& aInfo, Node* aParent)
{
    Node* result = nullptr;
    if (aInfo.typeID != eNodeType::UNDEFINED)
    {
        auto viewFactory = GD->getViewFactory();

        if (viewFactory)
        {
            std::vector< std::string > parentsNamesVec;
            result = viewFactory->createNode(parentsNamesVec, aInfo, GD->getDefSkinIDForAspectRatio(), aParent);
        }
    }

    return result;
}

std::string SceneHelper::constructItemName( const std::string& aItemId )
{
    std::string result;

    std::string color;
    std::string fabric;
    std::string type;
    std::string style;

	auto lookInfo = DM->getUnlockedLookMetaData( aItemId );

    if ( lookInfo )
    {
        std::string idTemplate = "TT_FILTERS_%s_BTN_%s";

        if ( lookInfo->lfilterColor )
        {
            int filter = static_cast< int >( log2( lookInfo->lfilterColor ) );

            color = DataTypesHelper::getStrFromLookFilterColor( static_cast< eLookFilterColor >( filter ) );

            BValue ID;
            ID.initWithFormat( idTemplate.c_str(), "COLOR", color.c_str() );

            color = GET_STRING( ID.getString().c_str() );
        }

        if ( lookInfo->lfilterStyle )
        {
            int filter = static_cast< int >( log2( lookInfo->lfilterStyle ) );

            style = DataTypesHelper::getStrFromLookFilterStyle( static_cast< eLookFilterStyle >( filter ) );

            BValue ID;
            ID.initWithFormat( idTemplate.c_str(), "STYLE", style.c_str() );

            style = GET_STRING( ID.getString().c_str() );
        }

        if ( lookInfo->lfilterFabric )
        {
            int filter = static_cast< int >( log2( lookInfo->lfilterFabric ) );

            fabric = DataTypesHelper::getStrFromLookFilterFabric( static_cast< eLookFilterFabric >( filter ) );

            BValue ID;
            ID.initWithFormat( idTemplate.c_str(), "FABRIC", fabric.c_str() );

            fabric = GET_STRING( ID.getString().c_str() );
        }

        if ( lookInfo->lfilterCustom )
        {
            type = DataHelper::getItemNameFromCustomFilter( lookInfo->lookType, lookInfo->lfilterCustom, false );
        }

        result = color + " " + fabric + " " + type;
    }

    return result;
}

void SceneHelper::setPlayerPosWithSpecialCheck(Label * aLabel, std::string aPlayerPos, Node* aBorderNode) {
    if (aLabel) {
        int playerPos = BValue(aPlayerPos).getInt();

        if (playerPos > MAX_PLAYER_POS) {
            aPlayerPos = "10" + GET_STRING("TT_THOUSAND") + "+";
        } else {
            if (aBorderNode != nullptr) {
                NodeHelper::scaleDownNodeIfCropping(aLabel, aBorderNode);
            }
        }

        aLabel->setString(aPlayerPos);
    }
}

std::string SceneHelper::getSaveIdFromItemID(const std::string& aItemId)
{
    std::string result = "";

	auto lookInfo = DM->getUnlockedLookMetaData(aItemId);
	if (lookInfo)
	{
		result = lookInfo->lookID;
	}

    return result;
}

void SceneHelper::loadBrandIconToSlot(Sprite* aBrandCell, const std::string& aTexturePack, const std::string& aTextureId)
{
    if (aBrandCell)
    {
        Size cellSize = aBrandCell->getContentSize();

        auto cache = SpriteFrameCache::getInstance();
        auto frame = cache->getSpriteFrameByName(aTextureId);
        if (frame)
        {
            aBrandCell->setSpriteFrame(frame);
        }
        else
        {
            BTCWrapper->loadTexturePackFile(GET_RESOURCE_PATH(aTexturePack));
            frame = cache->getSpriteFrameByName(aTextureId);
            if (frame)
            {
                aBrandCell->setSpriteFrame(frame);
            }
            else
            {
                std::string framePath = GET_RESOURCE_PATH(aTextureId);
                if (framePath.empty())
                {
                    const auto& resPath = GET_RESOURCE_PARAMS(aTexturePack);
                    if (resPath.isMap())
                    {
                        const auto& map = resPath.getValueMap();

                        auto findIt = map.find(aTextureId);
                        if (findIt != map.end())
                        {
                            framePath = findIt->second.getString();
                        }
                    }
                }

                frame = cache->getSpriteFrameByName(framePath);
                if (frame)
                {
                    aBrandCell->setSpriteFrame(frame);
                }
                else
                {
                    aBrandCell->setTexture(framePath);
                }
            }
        }

        aBrandCell->setContentSize(cellSize);
    }
}

bool SceneHelper::isCircleNodeContainsCoord(Node * aCircleNode, Vec2 aCoord)
{
    bool result = false;

    if (aCircleNode)
    {
        Size nodeSize = aCircleNode->getContentSize();
        bool isCircle = fabs(nodeSize.width - nodeSize.height) < FLT_EPSILON;
        if (isCircle)
        {
            float radius = nodeSize.width / 2.0f;
            Vec2 center = aCircleNode->getPosition();
            float legX = center.x - aCoord.x;
            float legY = center.y - aCoord.y;
            float hipotenuse = sqrt( legX * legX + legY * legY );

            result = radius > hipotenuse;
        }
    }

    return result;
}

bool SceneHelper::setNordcurrentIDAvatar(Sprite* aAvatarNode, const std::string& aAvatarData, bool aIsNewUpdate)
{
    bool res = false;

	if (aAvatarNode && !aAvatarData.empty())
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		std::string fileName = "DLC\\ncid_avatar.jpg";
#else
		std::string fileName = "DLC/ncid_avatar.jpg";
#endif
		bool isImageExist = false;
		std::string fullPath = HelperUtils::getDLCFolderPath() + fileName;
		if (aIsNewUpdate || !FileUtils::getInstance()->isFileExist(fullPath))
		{
			isImageExist = SceneHelper::createImageFromDataAndSaveToFile(aAvatarData, fullPath);
		}
		else
        {
		    isImageExist = true;
        }

		auto parent = aAvatarNode->getParent();
		if (parent && isImageExist)
		{
            auto avatarProfile = parent->getChildByName("avatar_profile");
            if (avatarProfile)
            {
                parent->removeChild(avatarProfile, true);
            }
            
            auto director = Director::getInstance();
            if (director)
            {
                director->getTextureCache()->removeTextureForKey(fullPath);
            }
            
			BValueMap params;
			params["path"] = fullPath;
			params["name"] = "avatar_profile";
			params["pos"] = aAvatarNode->getPosition();
			params["order"] = aAvatarNode->getLocalZOrder();
			
			Sprite* newNode = SceneHelper::createSpriteWithParams(params, parent);
			if (newNode)
			{
				NodeHelper::scaleDownNodeToContainerSize(newNode, aAvatarNode);
				res = true;
			}
            
		}
	}

    return res;
}

Sprite* SceneHelper::createSpriteWithParams(BValueMap& aParams, Node* aParent)
{
	Sprite* res = nullptr;
	
	auto findIt = aParams.find("path");
	if (findIt != aParams.end() && findIt->second.isString())
	{
		res = Sprite::create(findIt->second.getString());
	}

	if (res)
	{
		res->getTexture()->setAntiAliasTexParameters();
		res->setStretchEnabled(true);

		findIt = aParams.find("pos");
		if (findIt != aParams.end() && findIt->second.isVec2())
		{
			res->setPosition(findIt->second.getVec2());
		}

		findIt = aParams.find("anchor");
		if (findIt != aParams.end() && findIt->second.isVec2())
		{
			res->setAnchorPoint(findIt->second.getVec2());
		}

		findIt = aParams.find("name");
		if (findIt != aParams.end() && findIt->second.isString())
		{
			res->setName(findIt->second.getString());
		}

		findIt = aParams.find("order");
		if (findIt != aParams.end() && findIt->second.isInteger())
		{
			res->setLocalZOrder(findIt->second.getInt());
		}

		if (aParent)
		{
			aParent->addChild(res);
		}
	}

	return res;
}

bool SceneHelper::createImageFromDataAndSaveToFile(const std::string& aAvatarData, const std::string& aFilePath)
{
	bool res = false;

	if (!aAvatarData.empty() && !aFilePath.empty())
	{
		std::size_t newStartIndx = aAvatarData.find_first_of(",");
		std::string baseData = aAvatarData.substr(newStartIndx + 1);

		unsigned char* buff;
		auto length = base64Decode(reinterpret_cast<const unsigned char*>(baseData.c_str()), baseData.length(), &buff);
		if (buff && length > 0)
		{
			auto image = new Image();
			res = image->initWithImageData(buff, length);
			if (res)
			{
				res = image->saveToFile(aFilePath);
			}
			free(buff);
		}
	}

	return res;
}
