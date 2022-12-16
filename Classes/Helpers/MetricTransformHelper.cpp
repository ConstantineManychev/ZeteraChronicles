#include "Helpers/MetricTransformHelper.h"
#include "BJsonHelper.h"
#include "Types/DataTypesFilters.h"
#include "Helpers/DataTypesHelper.h"
#include "Helpers/SceneHelper.h"
#include "Managers/GameDirector.h"
#include "Managers/LiveOps/LiveOpsSystem.h"
#include "Managers/LiveOps/Holiday/LiveOpsHolidayController.h"
#include "Managers/Quest/Component/QuestsUIDataInterface.h"
#include "Managers/Quest/Component/BaseQuest.h"
#include "Managers/Quest/Component/BaseAchievement.h"
#include "Managers/Data/DataManager.h"

_USEB


MetricTransformHelper::MetricTransformHelper()
: mConfigLoaded( false )
{

}

MetricTransformHelper::~MetricTransformHelper()
{

}

MetricTransformHelper* MetricTransformHelper::getInstance()
{
	static MetricTransformHelper instance;
	return &instance;
}

void MetricTransformHelper::loadMetricTransformationsConfig()
{
	if( !mConfigLoaded )
	{
		std::string data = FileUtils::getInstance()->getStringFromFile( "data/metric_transformations.json" );

		rapidjson::Document document;
		document.Parse<0>( data.c_str() );

		if( !document.HasParseError() && document.IsObject() )
		{
			BValue transormationMapsValue;
			BJsonHelper::parseBValueFromJsonValue( document, transormationMapsValue );

			if( transormationMapsValue.checkType( BValue::Type::MAP ) )
			{
				auto& transormationMaps = transormationMapsValue.getValueMap();
				
				auto findIter = transormationMaps.find( "transform_location_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseLocationIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_item_type" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseItemTypeMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_item_collection" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseItemCollectionMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_quest_complexity" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseQuestComplexityMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_quest_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseQuestIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_achievement_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseAchievementIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_tutorial_scenario_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseTutorialScenarioIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find("transform_badges_id");

				if (findIter != transormationMaps.end() && findIter->second.checkType(BValue::Type::MAP))
				{
					parseBadgesIDMap(findIter->second.getValueMap());
				}

				findIter = transormationMaps.find( "transform_face_choose_part_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseFaceChoosePartIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_face_buy_item_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseFaceBuyPartIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_banner_offer_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseBannerOfferIDMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_face_section_id" );

				if( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseFaceSectionMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find( "transform_not_enough_currency_screen_id" );

				if ( findIter != transormationMaps.end() && findIter->second.checkType( BValue::Type::MAP ) )
				{
					parseNotEnoughCurrencyScreenSectionMap( findIter->second.getValueMap() );
				}

				findIter = transormationMaps.find("transform_holiday_offer_id");

				if (findIter != transormationMaps.end() && findIter->second.checkType(BValue::Type::MAP))
				{
					parseHolidayOfferIdMap(findIter->second.getValueMap());
				}

				mConfigLoaded = true;
			}
		}
	}
}

void MetricTransformHelper::parseLocationIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mLocationTransformMap[ pair.first ] = pair.second.getString();
	}
}

void MetricTransformHelper::parseItemTypeMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mItemTypeTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseItemCollectionMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mItemCollectionTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseQuestComplexityMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mQuestComplexityTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseQuestIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mQuestIDTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseAchievementIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mAchievementIDTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseTutorialScenarioIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mTutorialScenarioIDTransformMap[ pair.first ] = pair.second.getString();
	}
}

void MetricTransformHelper::parseFaceChoosePartIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mFaceChoosePartIDTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseFaceBuyPartIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mFaceBuyPartIDTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseBannerOfferIDMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mBannerOfferIDTransformMap[ pair.first ] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseFaceSectionMap( const BValueMap& aMap )
{
	for( const auto& pair : aMap )
	{
		mFaceSectionTransformMap[ pair.first ] = pair.second.getString();
	}
}

void MetricTransformHelper::parseNotEnoughCurrencyScreenSectionMap( const BValueMap & aMap )
{
	for ( const auto& pair : aMap )
	{
		mNotEnoughCurrencyScreenSectionTransformMap[ pair.first ] = pair.second.getString();
	}
}

void MetricTransformHelper::parseBadgesIDMap(const BValueMap & aMap)
{
	for (const auto& pair : aMap)
	{
		mBadgesIdMap[pair.first] = pair.second.getInt();
	}
}

void MetricTransformHelper::parseHolidayOfferIdMap(const BValueMap & aMap)
{
	for (const auto& pair : aMap)
	{
		mHolidayOfferIdTransformMap[pair.first] = pair.second.getString();
	}
}

std::string MetricTransformHelper::getLocationName( const std::string& aLocationID )
{
	std::string retVal;

	auto findIter = mLocationTransformMap.find( aLocationID );

	if( findIter != mLocationTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getIntHashFromString( const std::string& aStringToHash )
{
	int retVal = 0;

	if( isNumber( aStringToHash ) )
	{
		retVal = atoi( aStringToHash.c_str() );
	}
	else
	{
		const char *first = aStringToHash.c_str();
		int count = aStringToHash.size();
		retVal = 2166136261U;
		const int primeFNV = 16777619U;

		for( int next = 0; next < count; ++next )
		{	// fold in another byte
			retVal ^= ( int )first[ next ];
			retVal *= primeFNV;
		}
	}

	return retVal;
}

std::string MetricTransformHelper::getItemIDByLookMeta(const sLookMetaData* aLookInfo)
{
	std::string retVal;

	if (aLookInfo)
	{
		if (isClothes(aLookInfo->lookType))
		{
			BValue str;

			const int& typeID = getTypeID(aLookInfo->lookType, aLookInfo->lfilterCustom);

			std::string collectionID;
			auto isUgc = aLookInfo->lookID.find("UGC") != std::string::npos;
			if (isUgc)
			{
				collectionID = DM->getMainConfigValueByID("ugc_collection_id").getString();
			}
			else
			{
				collectionID = std::to_string(getCollectionID(aLookInfo->lookSet));
			}

			const std::string& mark = aLookInfo->mark;

			str.initWithFormat("%d-%s-%s", typeID, collectionID.c_str(), mark.c_str());

			retVal = str.getString();
		}
		else
		{
			retVal = aLookInfo->lookID;
		}
	}

	return retVal;
}

std::string MetricTransformHelper::getUGCItemIDByLookMeta(const sLookMetaData* aLookInfo)
{
	std::string retVal;

	if (aLookInfo)
	{
		BValue str;

		const int& typeID = getTypeID(aLookInfo->lookType, aLookInfo->lfilterCustom);
		const std::string& collectionID = DM->getMainConfigValueByID("ugc_collection_id").getString();
		int prefixLength = DM->getMainConfigValueByID("ugc_itemid_prefix_length").getInt();
		const std::string& mark = !aLookInfo->mark.empty() 
			? aLookInfo->mark 
			: (aLookInfo->lookID.empty() 
				? "" 
				: aLookInfo->lookID.substr( prefixLength, aLookInfo->lookID.length() - prefixLength));

		str.initWithFormat("%d-%s-%s", typeID, collectionID.c_str(), mark.c_str());

		retVal = str.getString();
	}

	return retVal;
}

int MetricTransformHelper::getDailyQuestID( const QuestsUIDataInterface* aQuestInfo )
{
	int retVal = 0;

	const BaseQuest* challengeInfo = dynamic_cast< const BaseQuest* >( aQuestInfo );
	
	if( challengeInfo )
	{
		const auto questID = challengeInfo->getTitleId();
		const auto complexityEnum = challengeInfo->getQuestComplexity();
		std::string complexityStr;

		if( complexityEnum == eQuestComplexity::UNDEFINED )
		{
			complexityStr = "UNDEFINED";
		}
		else if( complexityEnum == eQuestComplexity::EASY )
		{
			complexityStr = "EASY";
		}
		else if( complexityEnum == eQuestComplexity::MEDIUM )
		{
			complexityStr = "MEDIUM";
		}
		else if( complexityEnum == eQuestComplexity::HARD )
		{
			complexityStr = "HARD";
		}

		const auto findComplexityIter = mQuestComplexityTransformMap.find( complexityStr );

		if( findComplexityIter != mQuestComplexityTransformMap.end())
		{
			retVal = findComplexityIter->second * 100;
		}

		const auto findIDIter = mQuestIDTransformMap.find( questID );

		if( findIDIter != mQuestIDTransformMap.end() )
		{
			retVal += findIDIter->second;
		}
	}

	return retVal;
}

int MetricTransformHelper::getAchievementID( const QuestsUIDataInterface* aQuestInfo )
{
	int retVal = 0;

	const BaseAchievement* achievementInfo = dynamic_cast< const BaseAchievement* >( aQuestInfo );

	if( achievementInfo )
	{
		const auto achievID = achievementInfo->getUniqueID();
		const auto iterNumber = achievementInfo->getCurrentIterationNumber() + 1;
		
		retVal = iterNumber * 100;

		const auto findIDIter = mAchievementIDTransformMap.find( achievID );

		if( findIDIter != mAchievementIDTransformMap.end() )
		{
			retVal += findIDIter->second;
		}
	}

	return retVal;
}

std::string MetricTransformHelper::getTutorialScenarioID( const std::string aScenarioName )
{
	std::string retVal;
	
	auto findIter = mTutorialScenarioIDTransformMap.find( aScenarioName );

	if( findIter != mTutorialScenarioIDTransformMap.end() )
	{
		retVal = findIter->second;
	}
	
	return retVal;
}

int MetricTransformHelper::getFaceID( const sCharCustomizeInfo& aCharCustomizeInfo )
{
	int retVal = 0;

	auto findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.skin_id );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal = 100000 * findIter->second;
	}

	findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.faceParts.at( eCharFacePart::JAW ) );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal += 10000 * findIter->second;
	}

	findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.faceParts.at( eCharFacePart::NOSE ) );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal += 1000 * findIter->second;
	}

	findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.faceParts.at( eCharFacePart::EYES ) );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal += 100 * findIter->second;
	}
	
	findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.faceParts.at( eCharFacePart::BROWS ) );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal += 10 * findIter->second;
	}

	findIter = mFaceChoosePartIDTransformMap.find( aCharCustomizeInfo.faceParts.at( eCharFacePart::LIPS ) );

	if( findIter != mFaceChoosePartIDTransformMap.end() )
	{
		retVal += findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getBuyingFacePartID( const std::string& aItemID )
{
	int retVal = 0;

	auto findIter = mFaceBuyPartIDTransformMap.find( aItemID );

	if( findIter != mFaceBuyPartIDTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getBunnerOfferID( const std::string& aBunnerTitleID )
{
	int retVal = 0;

	auto findIter = mBannerOfferIDTransformMap.find( aBunnerTitleID );

	if( findIter != mBannerOfferIDTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getBadgesID(const std::string & aBadgesID)
{
	int retVal = 0;

	auto findIter = mBadgesIdMap.find(aBadgesID);

	if (findIter != mBadgesIdMap.end())
	{
		retVal = findIter->second;
	}

	return retVal;
}

std::string MetricTransformHelper::getSectionName( const std::string& aGroupID )
{
	std::string retVal;

	auto findIter = mFaceSectionTransformMap.find( aGroupID );

	if( findIter != mFaceSectionTransformMap.end() )
	{
		retVal = findIter->second;
	}
	
	return retVal;
}

std::string MetricTransformHelper::getSubsectionName( const std::string& aGroupID )
{
	std::string retVal;

	auto findIter = mFaceSectionTransformMap.find( aGroupID + "_SUB" );

	if( findIter != mFaceSectionTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

std::string MetricTransformHelper::getNotEnoughCurrencyScreenId( const std::string & aReportingViewId )
{
	std::string retVal;

	auto findIter = mNotEnoughCurrencyScreenSectionTransformMap.find( aReportingViewId );

	if ( findIter != mNotEnoughCurrencyScreenSectionTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

std::string MetricTransformHelper::getCurrentHolidayName()
{
	std::string result;
	const auto& holidayId = HOLIDAY->getHolidayID();

	auto findIt = mHolidayOfferIdTransformMap.find(holidayId);
	if (findIt != mHolidayOfferIdTransformMap.end())
	{
		result = findIt->second;
	}
	else
	{
		result = holidayId;
	}

	auto tm = SceneHelper::getGameDate();
	result += std::to_string(tm.tm_year);

	return result;
}

int MetricTransformHelper::getTypeID( eLookType aType, unsigned aCustomIndex )
{
	int retVal = 100;

	int enumIndex = getEnumIndexFromCustomIndex(aCustomIndex);
	std::string itemTypeName;

	switch(aType)
	{
		case eLookType::DRESS:
		{
			eLookCustomFilterDress dressEnum = static_cast< eLookCustomFilterDress >( enumIndex );
			itemTypeName = DataTypesHelper::getStrFromLookCustomFilterDress( dressEnum );
			break;
		}
		case eLookType::TOP_A:
		case eLookType::TOP_A_TUCKED:
		{
			eLookCustomFilterTopA topEnum = static_cast< eLookCustomFilterTopA >( enumIndex );
			itemTypeName = DataTypesHelper::getStrFromLookCustomFilterTopA( topEnum );
			break;
		}
		case eLookType::BOTTOM:
		{
			eLookCustomFilterBottom bottomEnum = static_cast< eLookCustomFilterBottom >( enumIndex );
			itemTypeName = DataTypesHelper::getStrFromLookCustomFilterBottom( bottomEnum );
			break;
		}
		case eLookType::TOP_B:
		{
			eLookCustomFilterTopB outerwearEnum = static_cast< eLookCustomFilterTopB >( enumIndex );
			itemTypeName = DataTypesHelper::getStrFromLookCustomFilterTopB( outerwearEnum );
			break;
		}
		case eLookType::SHOES:
		case eLookType::BOOTS:
		{
			eLookCustomFilterShoes shoesEnum = static_cast< eLookCustomFilterShoes >( enumIndex );
			itemTypeName = DataTypesHelper::getStrFromLookCustomFilterShoes( shoesEnum );
			break;
		}
		case eLookType::ACC_BACKPACKS:
		case eLookType::ACC_HANDBAGS:
		{
			itemTypeName = "BAG";
			break;
		}
		case eLookType::ACC_JEWELRY:
		{
			itemTypeName = "JEWELRY";
			break;
		}
		case eLookType::ACC_GLASSES:
		{
			itemTypeName = "GLASSES";
			break;
		}
		case eLookType::ACC_SCARVES:
		{
			itemTypeName = "SCARF";
			break;
		}
		case eLookType::ACC_HATS:
		{
			itemTypeName = "HAT";
			break;
		}
		case eLookType::ACC_BELTS:
		{
			itemTypeName = "BELT";
			break;
		}
		case eLookType::ACC_GLOVES:
		{
			itemTypeName = "GLOVES";
			break;
		}
		case eLookType::ACC_STOCKINGS:
		{
			itemTypeName = "STOCKINGS";
			break;
		}
		case eLookType::PERFUME:
		{
			itemTypeName = "PERFUME";
			break;
		}
		case eLookType::FACE_GLITTER:
		{
			itemTypeName = "GLITTERS";
			break;
		}
	}

	const auto findIter = mItemTypeTransformMap.find( itemTypeName );
	if( findIter != mItemTypeTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getCollectionID(const std::string& aLookSet )
{
	int retVal = 0;

	auto findIter = mItemCollectionTransformMap.find(aLookSet);
	if( findIter != mItemCollectionTransformMap.end() )
	{
		retVal = findIter->second;
	}

	return retVal;
}

int MetricTransformHelper::getEnumIndexFromCustomIndex( int aCustomIndex )
{
	int retVal = 0;

	if( aCustomIndex <= 0 )
	{
		retVal = 0;
	}
	else
	{
		while( aCustomIndex > 1 )
		{
			if( aCustomIndex % 2 == 1 )
			{
				retVal = 0;
				break;
			}

			aCustomIndex >>= 1;
			retVal++;
		}
	}

	return retVal;
}

bool MetricTransformHelper::isNumber( const std::string& aString )
{
	bool retVal = false;

	std::string::const_iterator iter = aString.begin();

	while( iter != aString.end()
		   && ( isdigit( *iter )
				|| ( iter == aString.begin()
					 && *iter == '-' ) ) )
	{
		++iter;
	}

	if( !aString.empty() && iter == aString.end() )
	{
		retVal = true;
	}

	return retVal;
}

bool MetricTransformHelper::isClothes(eLookType aType)
{
	bool result = true;

	switch (aType)
	{
	case eLookType::PERFUME:
	case eLookType::FACE_GLITTER:
	case eLookType::MAKEUP_EYES:
	case eLookType::MAKEUP_LIPS:
	case eLookType::CUSTOMIZATION:
	case eLookType::HAIRSTYLE:
		result = false;
		break;
	}

	return result;
}
