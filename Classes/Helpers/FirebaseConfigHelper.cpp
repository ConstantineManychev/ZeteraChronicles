#include "FirebaseConfigHelper.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "../firebase_cpp_sdk/include/firebase/remote_config.h"
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include "Managers/Metrics/External/Firebase/cpp/frameworks/ios/universal/firebase.framework/Headers/remote_config.h"
#endif

#include "../../gcs/GCSWrapper.h"
#include "../../butils/src/core/BCommonDefines.h"
#include "Managers/Debug/DebugManager.h"
#include "Managers/Players/PlayerProfile.h"


_USEB

FirebaseConfigHelper::FirebaseConfigHelper()
    : mCacheRefresh( 24 * 60 * 60 )
    , mCheatCacheRefresh( 2 * 60 )
{

}

FirebaseConfigHelper::~FirebaseConfigHelper()
{

}

auto* FirebaseConfigHelper::getRemoteConfigInstance()
{
    return firebase::remote_config::RemoteConfig::GetInstance(firebase::App::GetInstance());
}

FirebaseConfigHelper* FirebaseConfigHelper::getInstance()
{
    static FirebaseConfigHelper instance;
    return &instance;
}

void FirebaseConfigHelper::init()
{
    auto* remoteConfig = getRemoteConfigInstance();
    remoteConfig->EnsureInitialized();

    auto configSettings = firebase::remote_config::ConfigSettings();
    configSettings.fetch_timeout_in_milliseconds = DEBUG->isCheatsEnable() ? mCheatCacheRefresh : mCacheRefresh;
    remoteConfig->SetConfigSettings(configSettings);

    auto playerID = PLAYER->getPlayerUniqueID();
    const bool forced = playerID != mCurrentPlayerID;
    mCurrentPlayerID = playerID;

    const auto refresh = DEBUG->isCheatsEnable() ? mCheatCacheRefresh : mCacheRefresh;

    remoteConfig->Fetch(forced ? 0 : refresh).OnCompletion( [remoteConfig, this](auto result) {
        if (mCurrentPlayerID == PLAYER->getPlayerUniqueID())
        {
            remoteConfig->Activate();

            BValueMap tags;
            for (auto& key : remoteConfig->GetKeysByPrefix("gcs_tag_"))
            {
                tags[key] = remoteConfig->GetString(key.c_str());
            }

            BValueMap params;
            params["gcs_tags"] = tags;
            PLAYER->addSaveOperation(eSaveOperationType::UPDATE_FIREBASE_TAGS, params);
        }
    });
}
