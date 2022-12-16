/*#ifndef IngameCache_h
#define IngameCache_h

#include "cocos2d.h"
#include "BCommonDefines.h"
#include "Types/DataTypes.h"
#include <set>

NS_CC_BEGIN

struct sBGDNodeInfo;

class IngameCache 
{
    const std::string mViewCacheFileName;
	
    std::map< eMainSubfilterType, std::set<unsigned>> mMainAppliedSubfilters;
    std::map< eLookCategory, std::set<unsigned>> mDeployedCategoryAppliedSubfilters;

    std::map< std::string, BValueMap> mCurrentEventRequeirent;
    
	std::map< std::string, std::vector< std::string > > mViewResourcesIdMap;

    sEventFormatedRequirementInfo mActiveEventRequirement;

	sCharStyleInfo mInspectedCharStyleInfo;
	
	std::vector< std::string > mLocationsByOrderOnMap;

    std::pair<std::string, std::vector<eMainSubfilterType>> mReportedItemID;

    std::string mShopDesignerID;

	std::string mTopSellingDesignerItem;

	std::string mHighResolutionResourcesPath;

    std::string mCurrentOpenView;

    eLookCategory mDeployedLookCategory;

    eSubfilteSortType mSortType;

    eSubfilterType mSubfilterType;

    bool mIsSubFilterPanelVisible;
    bool mIsShowRepotedItem;
    bool mIsDeviceStorageFullMessageShown;
        
    int mMapScrollCurrentLocation;
	bool mIsPlayerCollection;

	void parseViewResourcesId( const std::string& aViewID );
	void parseNodeChildsResourcesId( const std::string& aParentViewId, const sBGDNodeInfo& aInfo );
	void addNodeResIdToCache( const std::string& aViewId, const std::string& aResID );

public:
    IngameCache();
    virtual ~IngameCache();
    
    std::map< eMainSubfilterType, std::set<unsigned>>& getMainAppliedSubfilters( );
    void setMainAppliedSubfilters( std::map< eMainSubfilterType, std::set<unsigned>>& aFilters );
    
    std::map< eLookCategory, std::set<unsigned>>& getDeployedCategoryAppliedSubfilters( );
    void setDeployedCategoryAppliedSubfilters( std::map< eLookCategory, std::set<unsigned>>& aFilters );  
    
    eLookCategory getDeployedLookCategory();
    void setDeployedLookCategory (eLookCategory aLookCategory);

    eSubfilteSortType getAppliedSubfilterSort();
    void setAppliedSubfilterSort(eSubfilteSortType aSubfilteSortType);

    eSubfilterType getSubfilteType();
    void setSubfilterType(eSubfilterType aType);

    int getMapScrollCurrentLocation();
    void setMapScrollCurrentLocation(int aLocation);
    
    bool getSubFilterPanelVisible();
    void setSubFilterPanelVisible(bool aVisible);

    void setActvieEventRequirement(sEventFormatedRequirementInfo& mRequirementInfo);
    sEventFormatedRequirementInfo getEventRequiredInfo();

    void resetDressingRoomState();

	const std::vector< std::string >& getLocationsByOrderOnMap();
	void setLocationsByOrderOnMap( const std::vector< std::string >& aLocations);

	const std::string& getHighResolutionResPath();
	void setHighResolutionResPath(const std::string& aPath);

	void setInspectedCharStyleInfo( const sCharStyleInfo& aStyleInfo );
	const sCharStyleInfo& getInspectedCharStyleInfo();

	void setupViewResourcesCache();

	void createViewResourcesCache();
	void saveViewResourcesCache();
	bool loadViewResourcesCache();
    
    void setDeviceStorageMessageShown(bool aFlag);
    bool isDeviceStorageMessageShown();
    
	std::vector< std::string > getResourcesVecForScene( const std::string& aSceneId, const BValue& aSceneParams );

    void setOpenedCurrentView(const std::string& aViewId);
    const std::string& getOpenedCurrentView();

    bool isShowReportedItem();
    void setShowRepotedItem(bool aIsShow);
    void setReportedItems(std::string aItemId, std::vector<eMainSubfilterType> aReportedFilters);
    std::pair<std::string, std::vector<eMainSubfilterType>> getReportedItem();

    const std::string & getShopDesignerID();
    void setShopDesignerID(const std::string & aDesignerID);
    void clearShopDesignerID();

	void setTopSellingDesignerItem(const std::string& aItemID);
	const std::string& getTopSellingDesignerItem()const;
	void clearTopSellingDesignerItem();

	void setPlayerCollectionSelected(bool aIsSelected);
	bool isPlayerCollectionSelected();
};

NS_CC_END

#endif /* IngameCache_h */
