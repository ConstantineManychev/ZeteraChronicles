/*#include "IngameCache.h"
#include "BGameManager.h"
#include "Managers/Data/DataManager.h" 

USING_NS_CC;

IngameCache::IngameCache()
: mDeployedLookCategory (eLookCategory::UNDEFINED)
, mIsSubFilterPanelVisible(false)
, mMapScrollCurrentLocation(0)
, mViewCacheFileName( "view_cache" )
, mReportedItemID(std::make_pair("", eMainSubfilterType::NONE))
, mIsShowRepotedItem(false)
, mSortType(eSubfilteSortType::NONE)
, mSubfilterType(eSubfilterType::NONE), mIsDeviceStorageFullMessageShown(false)
, mIsPlayerCollection(false)
{

}

IngameCache::~IngameCache()
{
    
}

std::map< eMainSubfilterType, std::set<unsigned>>& IngameCache::getMainAppliedSubfilters( )
{
    return mMainAppliedSubfilters;
}

void IngameCache::setMainAppliedSubfilters( std::map< eMainSubfilterType, std::set<unsigned>>& aFilters )
{
    mMainAppliedSubfilters = aFilters;
}

std::map< eLookCategory, std::set<unsigned>>& IngameCache::getDeployedCategoryAppliedSubfilters( )
{
    return mDeployedCategoryAppliedSubfilters;
}

void IngameCache::setDeployedCategoryAppliedSubfilters( std::map< eLookCategory, std::set<unsigned>>& aFilters )
{
	mDeployedCategoryAppliedSubfilters = aFilters;
}

eLookCategory IngameCache::getDeployedLookCategory()
{
    return mDeployedLookCategory;
}

void IngameCache::setDeployedLookCategory (eLookCategory aLookCategory)
{
    mDeployedLookCategory = aLookCategory;
}

eSubfilteSortType IngameCache::getAppliedSubfilterSort()
{
	return mSortType;
}

void IngameCache::setAppliedSubfilterSort(eSubfilteSortType aSubfilteSortType)
{
	mSortType = aSubfilteSortType;
}

eSubfilterType IngameCache::getSubfilteType()
{
	return mSubfilterType;
}

void IngameCache::setSubfilterType(eSubfilterType aType)
{
	mSubfilterType = aType;
}

int IngameCache::getMapScrollCurrentLocation()
{
    return mMapScrollCurrentLocation;
}

void IngameCache::setMapScrollCurrentLocation(int aLocation)
{
	mMapScrollCurrentLocation = aLocation;
}

bool IngameCache::getSubFilterPanelVisible()
{
    return mIsSubFilterPanelVisible;
}

void IngameCache::setSubFilterPanelVisible(bool aVisible)
{
    mIsSubFilterPanelVisible = aVisible;
}

void IngameCache::setActvieEventRequirement(sEventFormatedRequirementInfo& mRequirementInfo)
{
	mActiveEventRequirement = mRequirementInfo;
}

sEventFormatedRequirementInfo IngameCache::getEventRequiredInfo()
{
	return mActiveEventRequirement;
}

void IngameCache::resetDressingRoomState()
{
    mMainAppliedSubfilters.clear();
	mDeployedCategoryAppliedSubfilters.clear();
	mSortType = eSubfilteSortType::NONE;
    mDeployedLookCategory = eLookCategory::UNDEFINED;
    mIsSubFilterPanelVisible = false;
}

const std::vector< std::string >& IngameCache::getLocationsByOrderOnMap()
{
	return mLocationsByOrderOnMap;
}

void IngameCache::setLocationsByOrderOnMap( const std::vector< std::string >& aLocations )
{
	mLocationsByOrderOnMap = aLocations;
}

const std::string& IngameCache::getHighResolutionResPath()
{
	return mHighResolutionResourcesPath;
}

void IngameCache::setHighResolutionResPath(const std::string& aPath)
{
	mHighResolutionResourcesPath = aPath;
}

void IngameCache::setInspectedCharStyleInfo( const sCharStyleInfo& aStyleInfo )
{
	mInspectedCharStyleInfo = aStyleInfo;
}

const sCharStyleInfo& IngameCache::getInspectedCharStyleInfo()
{
	return mInspectedCharStyleInfo;
}

void IngameCache::setupViewResourcesCache()
{
	if ( !loadViewResourcesCache() )
	{
		createViewResourcesCache();
		saveViewResourcesCache();
	}
}

void IngameCache::createViewResourcesCache()
{
	auto preloadedScenesVal = DM->getMainConfigValueByID( "preloaded_views_for_scenes" );

	if ( preloadedScenesVal.checkType( BValue::Type::MAP ) )
	{
		const auto& preloadedScenesMap = preloadedScenesVal.getValueMap();

		for( auto& preloadedScenePair : preloadedScenesMap )
		{
			for( auto& preloadedViewId : preloadedScenePair.second.getValueVector() )
			{
				parseViewResourcesId( preloadedViewId.getString() );
			}
		}
	}
}

bool IngameCache::loadViewResourcesCache()
{
	bool result = false;

	std::string content = FileUtils::getInstance()->getStringFromFile( FileUtils::getInstance()->getWritablePath() + mViewCacheFileName );

	rapidjson::Document document;

	document.Parse< 0 >( content.c_str() );
	
	mViewResourcesIdMap.clear();

	if ( !document.HasParseError() )
	{	
		result = true;

		for ( auto viewObjIt = document.MemberBegin(); viewObjIt != document.MemberEnd(); ++viewObjIt )
		{
			std::string viewObjName = ( *viewObjIt ).name.GetString();
			rapidjson::Value& viewResArray = ( *viewObjIt ).value;

			if ( viewResArray.IsArray() )
			{
				auto& viewResVec = mViewResourcesIdMap[ viewObjName ];

				for ( unsigned i = 0u; i < viewResArray.Size(); i++ )
				{
					std::string resID = viewResArray[ i ].GetString();
					viewResVec.push_back( resID );
				}
			}
		}
	}

	return result;
}

void IngameCache::saveViewResourcesCache()
{
	rapidjson::Document resDoc;
	rapidjson::Document::AllocatorType& res_allocator = resDoc.GetAllocator();
	resDoc.SetObject();

	rapidjson::Value viewMapValue( rapidjson::kObjectType );

	for ( auto viewResInfoMap : mViewResourcesIdMap )
	{
		std::string viewID = viewResInfoMap.first;
		rapidjson::Value viewResArrayValue( rapidjson::kArrayType );

		for ( auto resID : viewResInfoMap.second )
		{
			rapidjson::Value resIDValue( rapidjson::kStringType );
			resIDValue.SetString( resID.c_str(), resID.size(), res_allocator );
			viewResArrayValue.PushBack( resIDValue, res_allocator );
		}

		rapidjson::Value viewIDValue( rapidjson::kStringType );
		viewIDValue.SetString( viewID.c_str(), viewID.size(), res_allocator );

		resDoc.AddMember( viewIDValue, viewResArrayValue, res_allocator );
	}

	rapidjson::StringBuffer resStrbuf;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> resWriter( resStrbuf );
	resDoc.Accept( resWriter );

	std::string resPath = FileUtils::getInstance()->getWritablePath();
	if ( !resPath.empty() && resPath[ resPath.size() - 1 ] != '/' )
	{
		resPath += "/";
	}

	FileUtils::getInstance()->writeStringToFile( resStrbuf.GetString(), resPath + mViewCacheFileName );
}

void IngameCache::parseViewResourcesId( const std::string& aViewID )
{
	auto viewInfo = BGD->getViewInfo( aViewID );

	if ( viewInfo )
	{
		for( auto viewChild : viewInfo->children.nodes )
		{
			if ( viewChild.second.typeID == eNodeType::BGDVIEW )
			{
				const auto& childViewId = viewChild.second.creationInfo.getValueMap()[ "view_id" ].getString();

				parseViewResourcesId( childViewId );

				auto& childViewResVec = mViewResourcesIdMap[ childViewId ];

				auto& parentViewResVec = mViewResourcesIdMap[ viewInfo->name ];

				for (auto& aResID : childViewResVec)
				{
					if (std::find(parentViewResVec.begin(), parentViewResVec.end(), aResID) == parentViewResVec.end())
					{
						parentViewResVec.push_back(aResID);
					}
				}
			}
			else
			{
				parseNodeChildsResourcesId( viewInfo->name, viewChild.second );

				addNodeResIdToCache( viewInfo->name, viewChild.first );
			}
		}
	}
}

void IngameCache::parseNodeChildsResourcesId( const std::string& aParentViewId, const sBGDNodeInfo& aInfo )
{
	if (aInfo.typeID == eNodeType::BGDVIEW)
	{
		const BValueMap& creationInfoMap = aInfo.creationInfo.getValueMap();

		auto creationInfoIt = creationInfoMap.find("view_id");

		if (creationInfoIt != creationInfoMap.end())
		{
			const auto& childViewId = creationInfoIt->second.getString();

			parseViewResourcesId(childViewId);

			auto& childViewResVec = mViewResourcesIdMap[childViewId];

			auto& parentViewResVec = mViewResourcesIdMap[aParentViewId];

			for (auto& aResID : childViewResVec)
			{
				if (std::find(parentViewResVec.begin(), parentViewResVec.end(), aResID) == parentViewResVec.end())
				{
					parentViewResVec.push_back(aResID);
				}
			}
		}
	}
	else if (aInfo.creationInfo.checkType(BValue::Type::MAP))
	{
		std::vector < std::string > childResIds;

		auto creationInfoMap = aInfo.creationInfo.getValueMap();

		for (auto& creationParamVal : creationInfoMap)
		{
			if (creationParamVal.second.checkType(BValue::Type::MAP))
			{
				auto creationParamMap = creationParamVal.second.getValueMap();

				auto resIdIt = creationParamMap.find("res_id");

				if (resIdIt != creationParamMap.end())
				{
					childResIds.push_back(resIdIt->second.getString());
				}
			}
		}

		for (auto& resId : childResIds)
		{
			addNodeResIdToCache(aParentViewId, resId);
		}
	}

	for ( auto viewChild : aInfo.children.nodes )
	{
		parseNodeChildsResourcesId( aParentViewId, viewChild.second );
	}
}

void IngameCache::addNodeResIdToCache( const std::string& aViewId, const std::string& aResID )
{
	auto resInfo = BGM->getResourceManager()->getResInfo( aResID );

	if ( resInfo )
	{
		if ( resInfo->type == eResourceType::TEXTURE_PACK
		  || resInfo->type == eResourceType::TEXTURE
		  || resInfo->type == eResourceType::SPINE_ATLAS
		   )
		{
			auto& resVec = mViewResourcesIdMap[ aViewId ];

			if ( std::find( resVec.begin(), resVec.end(), aResID ) == resVec.end() )
			{
				resVec.push_back( aResID );
			}
		}
	}
}

std::vector< std::string > IngameCache::getResourcesVecForScene( const std::string& aSceneId, const BValue& aSceneParams )
{
	std::vector< std::string > result;

	auto preloadedViewsVal = DM->getMainConfigValueByID( "preloaded_views_for_scenes" );

	if ( preloadedViewsVal.checkType( BValue::Type::MAP ) )
	{
		const auto& preloadedViewsMap = preloadedViewsVal.getValueMap();

		auto loadedSceneIt = preloadedViewsMap.find( aSceneId );
		
		if ( loadedSceneIt != preloadedViewsMap.end() ) 
		{
			for ( auto& viewId : loadedSceneIt->second.getValueVector() )
			{
				auto viewResurcesVec = mViewResourcesIdMap[ viewId.getString() ];

				result.insert( result.end(), viewResurcesVec.begin(), viewResurcesVec.end() );
			}	
		}
	}

	return result;
}

void IngameCache::setDeviceStorageMessageShown(bool aFlag)
{
    mIsDeviceStorageFullMessageShown = aFlag;
}

bool IngameCache::isDeviceStorageMessageShown()
{
    return mIsDeviceStorageFullMessageShown;
}

void IngameCache::setOpenedCurrentView(const std::string& aViewId)
{
	mCurrentOpenView = aViewId;
}

const std::string& IngameCache::getOpenedCurrentView()
{
	return mCurrentOpenView;
}

bool IngameCache::isShowReportedItem()
{
	return mIsShowRepotedItem;
}

void IngameCache::setShowRepotedItem(bool aIsShow)
{
	mIsShowRepotedItem = aIsShow;
}

void IngameCache::setReportedItems(std::string aItemId, std::vector<eMainSubfilterType> aReportedFilters)
{
	mReportedItemID = std::make_pair(aItemId, aReportedFilters);
}

std::pair<std::string, std::vector<eMainSubfilterType>> IngameCache::getReportedItem()
{
	return mReportedItemID;
}

const std::string & IngameCache::getShopDesignerID()
{
    return mShopDesignerID;
}

void IngameCache::setShopDesignerID(const std::string & aDesignerID)
{
    mShopDesignerID = aDesignerID;
}

void IngameCache::clearShopDesignerID()
{
    mShopDesignerID.clear();
}

void IngameCache::setTopSellingDesignerItem(const std::string & aItemID)
{
	mTopSellingDesignerItem = aItemID;
}

const std::string & IngameCache::getTopSellingDesignerItem() const
{
	return mTopSellingDesignerItem;
}

void IngameCache::clearTopSellingDesignerItem()
{
	mTopSellingDesignerItem.clear();
}

void IngameCache::setPlayerCollectionSelected(bool aIsSelected)
{
	mIsPlayerCollection = aIsSelected;
}

bool IngameCache::isPlayerCollectionSelected()
{
	return mIsPlayerCollection;
}*/