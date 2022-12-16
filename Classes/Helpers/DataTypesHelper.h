#ifndef DataTypesHelper_H
#define DataTypesHelper_H

#include "Types/DataTypes.h"
#include "MinigameChoiseTypes.h"
#include "Types/LeaderboardTypes.h"
#include "Types/LootBoxesTypes.h"
#include "Types/VotingTypes.h"
#include "Managers/GameDirector.h"
#include "Types/AchievementTypes.h"
#include "Types/QuestEventTypes.h"
#include "Types/DataTypesFilters.h"
#include "Types/DesignerLooksTypes.h"
#include "DailyRewardsTypes.h"
#include "BCommon.h"//TODO: NEED FOR JSON

_BSTART

class DataTypesHelper
{
	DataTypesHelper();
	virtual ~DataTypesHelper();

	enum class eAchieveSaveKey
	{
		UNDEFINED = -1,
		UNIQUE_ID = 0,
		QUEST_STATE = 1,
		ACHIEVEMENT_ITERATION,
		REQUIRED_DAYS_COUNT,
		CURRENT_DAYS_COUNT,
		NEW_DAY_START_TIME,
		CURRENT_PROGRESS_COUNT,
		REQUIRED_PROGRESS_COUNT,
		SPECIAL_CHECK_MODULES
	};

	enum class eQuestSaveKey
	{
		UNDEFINED = -1,
		UNIQUE_ID = 0,
		QUEST_STATE,
		CURRENT_EVENTS_COUNT
	};

	static const int mAchieveMaxFields = static_cast< int >( eAchieveSaveKey::SPECIAL_CHECK_MODULES ) + 1;
	static const int mQuestMaxFields = static_cast< int >( eQuestSaveKey::CURRENT_EVENTS_COUNT ) + 1;

public:

	/* eAnimAreaType */
	static eAnimAreaType getAnimAreaTypeFromStr(const std::string& aStr);
	static std::string getStrFromAnimAreaType(eAnimAreaType aType);

	/* eLookType */
	static eLookType getLookTypeFromStr(const std::string& aStr);
	static std::string getStrFromLookType(eLookType aType);

	/*eLookCategory*/
	static eLookCategory getLookCategoryFromStr(const std::string& aStr);
	static std::string getStrFromLookCategory(eLookCategory aType);

	/* eLookFilterColor */
	static eLookFilterColor getLookFilterColorFromStr(const std::string& aStr);
	static std::string getStrFromLookFilterColor(eLookFilterColor aLookFilterColor);

	/* eLookFilterFabric */
	static eLookFilterFabric getLookFilterFabricFromStr(const std::string& aStr);
	static std::string getStrFromLookFilterFabric(eLookFilterFabric aLookFilterFabric);

	/* eLookFilterStyle */
	static eLookFilterStyle getLookFilterStyleFromStr(const std::string& aStr);
	static std::string getStrFromLookFilterStyle(eLookFilterStyle aLookFilterPattern);

	/* eLookFilterPattern */
	static eLookFilterPattern getLookFilterPatternFromStr(const std::string& aStr);
	static std::string getStrFromLookFilterPattern(eLookFilterPattern aLookFilterPattern);
    
    /* eLookFilterCollection */
	static eLookFilterCollection getLookFilterCollectionFromStr(const std::string& aStr);
	static std::string getStrFromLookFilterCollection(eLookFilterCollection aLookFilterPattern);

    /* eLookFilterCollection */
    static eLookFilterQuest getLookFilterQuestFromStr(const std::string& aStr);
    static std::string getStrFromLookFilterQuest(eLookFilterQuest aLookFilterPattern);

	/* eCurrencyType */
	static eCurrencyType getCurrencyTypeFromStr(const std::string& aStr);
	static std::string getStrFromCurrencyType(eCurrencyType aCurrencyType);
	static eCurrencyType getCurrencyTypeFromRewardType(eRewardType aRewardType);

	/* eCharFacePart */
	static eCharFacePart getCharFacePartFromStr(const std::string& aStr);
	static std::string getStrFromCharFacePart(eCharFacePart aFacePart);

	/* eCharColorizedPart */
	static eCharColorizedPart getCharColorizedPartFromStr(const std::string& aStr);
	static std::string getStrFromCharColorizedPart(eCharColorizedPart aColorPart);

    /* eBrandIconColorizedPart */
    static eBrandIconColorizedPart getIconColorizedPartFromStr(const std::string& aStr);

	/* eLookCustomFilterDress */
	static eLookCustomFilterDress getLookCustomFilterDressFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterDress(eLookCustomFilterDress aCustomFilter);

	/* eLookCustomFilterBottom */
	static eLookCustomFilterBottom getLookCustomFilterBottomFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterBottom(eLookCustomFilterBottom aCustomFilter);

	/* eLookCustomFilterShoes */
	static eLookCustomFilterShoes getLookCustomFilterShoesFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterShoes(eLookCustomFilterShoes aCustomFilter);

	/* eLookCustomFilterAccessories */
	static eLookCustomFilterAccessories getLookCustomFilterAccessoriesFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterAccessories(eLookCustomFilterAccessories aCustomFilter);

	/* eLookCustomFilterTopA */
	static eLookCustomFilterTopA getLookCustomFilterTopAFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterTopA(eLookCustomFilterTopA aCustomFilter);

	/* eLookCustomFilterTopB */
	static eLookCustomFilterTopB getLookCustomFilterTopBFromStr(const std::string& aStr);
	static std::string getStrFromLookCustomFilterTopB(eLookCustomFilterTopB aCustomFilter);

	/*eEventDifficulty*/
	static eEventDifficulty getEventDifficultyFromStr(const std::string& aStr);
	static std::string getStringFromEventDifficulty(eEventDifficulty aEventDifficulty);

	/*eRewardType*/
	static eRewardType getEventRewardTypeFromString(const std::string& aStr);
	static std::string getStringFromEvetRewardType(eRewardType aRewardType);
	static eRewardType getRewardTypeFromCurrencyType(eCurrencyType aCurrencyType);

	/*eDailyRewardsPoolType*/
	static void getStringFromDailyRewardsPoolType(eDailyRewardsPoolType aType, std::string& aResult);
	static eDailyRewardsPoolType getDailyRewardPoolTypeFromString(const std::string& aType);

	/*eEventType*/
	static eEventType getEventTypeFromStr(const std::string& aStr);
	static std::string getStrFromEventType(eEventType aEventType);

	/*eEventVisibility*/
	static eEventVisibility getEventVisibilityFromStr(const std::string& aStr);
	static std::string getStrFromEventVisibility(eEventVisibility aEventVisibility);

	static std::vector< int > getLookCustomFilterValuesVec(eLookType aLookType);
	/* eLookType */
	static std::string getStrFromLookCustomFilter(eLookType aLookType, int aCustomFilter);
	static int getLookCustomFilterFromStr(eLookType aLookType, const std::string& aStr);

	static eBonusType getBonusTypeFromStr(const std::string& aStr);
	static std::string getStrFromBonusType(eBonusType aEventType);

	static std::string getStrFromAspectRatioSkin(eGameAspectRatio aGameAspectRatio);

	static std::string getStrFromTrackIndex(eTrackIndex aTrackIndex);
	static eTrackIndex getTrackIndexFromString(std::string aTrackName);

    static std::string getStrIDFromBanReasonType(eItemBanReasonType aReasonType);
	static std::string getStrIDFromBanReasonHeaderType(eItemBanReasonType aReasonType);
	static std::string getStrIDFromBanReasonBodyType(eItemBanReasonType aReasonType);

	static BValue convertCharStyleToBValue(const sCharStyleInfo& aCharStyleRaw);

	static void serializeBValueToEventInfo(sEventInfo& aEvInfo, const BValue& aCharStyleRaw);

	static sEventRequirementInfo serializeBValueToEventRequirementInfo(const BValue& aEvReqRaw);
	static void serializeEventRequirementInfoToBValue(const sEventRequirementInfo* aEeqRaw, BValueMap& aInfo);

	static sEventRewardInfo serializeBValueToEventRewardInfo(const BValue& aEvRewardRaw);

	static sVotingLookInfo serializeBValueToVotingLookInfo(const BValue& aLookInfoRaw);

	static eMinigameCharacterType getMinigameCharaterTypeFromStr(const std::string& aStr);
	static std::string getStringFromMinigameCharacterType(eMinigameCharacterType aType);

	static eLeaderboardRank getLeaderboardRankFormStr(const std::string& aStr);
	static std::string getStringFromLeaderboardRank(eLeaderboardRank aRank);

	static eLootBoxPoolType getLootBoxPoolTypeFromStr(const std::string& aStr);
	static std::string getStrFromLootBoxPoolType(eLootBoxPoolType);

	static unsigned getIntFromCustomFilterString(const std::string& aRawStr);

	static sLeaderboardSeasonInfo getLeaderboardSeasonInfoFromBValue(const BValue& aRawValue);

	static BValue serializePlayerStyleToBValue(const sPlayerStyleInfo& aRawValue);

	static eLocationType getLocationTypeFromString(const std::string& str);

	static std::string getRegularSeasonTitle(int aMonth, int aYear, int aWeek);

	static std::string getStrFromEffectType(eEffectType currencyType);
	static eEffectType getEffectTypeFromStr(const std::string& str);

	// form rapidjson value
	static void parseEventRequirementInfoFromRapidjsonValue(sEventRequirementInfo& aEvReqInfo, const rapidjson::Value& aRapidjsonValue);
	static void parseEventInfoFromJsonValue(sEventInfo& aEvInfoo, const rapidjson::Value& aRapidjsonValue);
	static sEventRequirementInfo parseEventRequirementInfoFromJsonValue(const rapidjson::Value& aRapidjsonValue);


	static std::string decodeLink( const std::string & aSrc );
	static sDeepLinkInfo parseDeepLinkInfoFromString(const std::string& aData);

	static void parsePlayerInfoFromBValue(const BValue& aRawValue, sPlayerInfo& aInfo);
	static void parsePlayerStyleInfoFromBValue(const BValue & aRawValue, sPlayerStyleInfo& aInfo);
	static bool parseCharStyleInfoFromNetwork(const BValue & aCharStyleRaw , sCharStyleInfo& aInfo);
	static void parseCharStyleInfoFromConfig(const BValue & aCharStyleRaw, sCharStyleInfo& aInfo);
	static void parseEventRewardInfo(const BValue& aEvRewardRaw, sEventRewardInfo& aInfo);
	static void parseEventRewardInfo(const rapidjson::Value& aEvRewardRaw , sEventRewardInfo& aInfo);
    static void parsePlayerInfoFromCDNFollowInfo(const BValue & aRawValue, sPlayerInfo& aInfo);

	static void parseEventDifficultyInfo(const rapidjson::Value& aJsonValue, sEventDifficultyInfo& aInfo);

	static float getBonusStarsCountForLook(const sPlayerStyleInfo *const aInfo);

	static std::vector< std::string > getArchetypeVectorFromArchetype( const std::string& aArchetype );

	// CDN REFRAC
	static bool isItemArchetypeCorrect(const std::string& aCondition, const sArchetype* aArhetypeInfo);

	//Achievements save
	static BValueMap getBValueMapFromStringSaveAchievement( const std::string& aSave );
	static std::string getStringFromBValueAchievement( const BValueMap& aMap );
	static eAchievementId getAchievementEnumFromString( const std::string& aAchievementId );
	static std::string getAchievementIdFromEnum( eAchievementId aId );
	static eAchieveSaveKey getAchieveSaveKeyByString( const std::string& aKey );
	static std::string getStringByAchieveSaveKey( eAchieveSaveKey aKey );

	static BValueMap getBValueMapFromStringSaveQuest( const std::string& aSave );
	static std::string getStringFromBValueQuest( const BValueMap& aMap );
	static eQuestId getQuestEnumFromString( const std::string& aQuestId );
	static std::string getQuestIdFromEnum( eQuestId aId );
	static eQuestSaveKey getQuestSaveKeyFromString( const std::string& aQuestSaveId );
	static std::string getStringFromQuestSaveKey( eQuestSaveKey aQuestSaveKey );

	// requirement
	static sEventFormatedRequirementInfo formateRequirementInfo(sEventRequirementInfo* aReqInfo);

	static void initMetaFromParams(sLookMetaData* aMeta, const BValueMap& aParams);
};

_BEND

#endif
