#ifndef MetricTransformHelper_H
#define MetricTransformHelper_H

#include "BCommonDefines.h"
#include "Types/DataTypes.h"

_BSTART

class QuestsUIDataInterface;

class MetricTransformHelper
{
	bool mConfigLoaded;

	std::map< std::string, int > mItemTypeTransformMap;
	std::map< std::string, int > mItemCollectionTransformMap;
	std::map< std::string, int > mQuestComplexityTransformMap;
	std::map< std::string, int > mQuestIDTransformMap;
	std::map< std::string, int > mAchievementIDTransformMap;
	std::map< std::string, int > mFaceChoosePartIDTransformMap;
	std::map< std::string, int > mFaceBuyPartIDTransformMap;
	std::map< std::string, int > mBannerOfferIDTransformMap;
	std::map< std::string, int > mBadgesIdMap;
	std::map< std::string, std::string > mLocationTransformMap;
	std::map< std::string, std::string > mTutorialScenarioIDTransformMap;
	std::map< std::string, std::string > mFaceSectionTransformMap;
	std::map< std::string, std::string > mNotEnoughCurrencyScreenSectionTransformMap;
	std::map< std::string, std::string > mHolidayOfferIdTransformMap;

	MetricTransformHelper();

	void parseLocationIDMap( const BValueMap& aMap );
	void parseItemTypeMap( const BValueMap& aMap );
	void parseItemCollectionMap( const BValueMap& aMap );
	void parseQuestComplexityMap( const BValueMap& aMap );
	void parseQuestIDMap( const BValueMap& aMap );
	void parseAchievementIDMap( const BValueMap& aMap );
	void parseTutorialScenarioIDMap( const BValueMap& aMap );
	void parseFaceChoosePartIDMap( const BValueMap& aMap );
	void parseFaceBuyPartIDMap( const BValueMap& aMap );
	void parseBannerOfferIDMap( const BValueMap& aMap );
	void parseFaceSectionMap( const BValueMap& aMap );
	void parseNotEnoughCurrencyScreenSectionMap( const BValueMap& aMap );
	void parseBadgesIDMap(const BValueMap& aMap);
	void parseHolidayOfferIdMap(const BValueMap& aMap);

	int getTypeID( eLookType aType, unsigned aCustomIndex );
	int getCollectionID(const std::string& aLookSet );
	int getEnumIndexFromCustomIndex( int aCustomIndex );

	bool isNumber( const std::string& aString );
	bool isClothes(eLookType aType);

public:
	virtual ~MetricTransformHelper();

	static MetricTransformHelper* getInstance();

	void loadMetricTransformationsConfig();

	std::string getLocationName( const std::string& alocationID );

	int getIntHashFromString( const std::string& aStringToHash );
	std::string getItemIDByLookMeta( const sLookMetaData* aLookInfo );
	std::string getUGCItemIDByLookMeta(const sLookMetaData* aLookInfo);
	int getDailyQuestID( const QuestsUIDataInterface* aQuestInfo );
	int getAchievementID( const QuestsUIDataInterface* aQuestInfo );
	int getFaceID( const sCharCustomizeInfo& aCharCustomizeInfo );
	int getBuyingFacePartID( const std::string& aItemID );
	int getBunnerOfferID( const std::string& aBunnerTitleID );
	int getBadgesID(const std::string& aBadgesID);
	std::string getTutorialScenarioID( const std::string aScenarioName );
	std::string getSectionName( const std::string& aGroupID );
	std::string getSubsectionName( const std::string& aGroupID );	
	std::string getNotEnoughCurrencyScreenId( const std::string& aReportingViewId );
	std::string getCurrentHolidayName();
};

#define MTHelper MetricTransformHelper::getInstance()

_BEND

#endif
