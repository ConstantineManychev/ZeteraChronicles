#ifndef MetricHelper_H
#define MetricHelper_H

#include "BValue.h"
#include <string>
#include "Managers/SaleSystem/SaleSystem.h"
#include "Managers/Metrics/MetricsSystemEvents.h"

_BSTART

class MetricHelper
{

	static std::string getItemSubTypeStringByLookType(eLookType type);
	static std::string getItemTypeStringByLookType(eLookType type);

public:

	static BValueMap getEventItemBuyMetricParamsMap(const sLookMetaData* aLookMeta);

	static void sendSalePopupOpenMetric(const std::string& aScreenId);
	static void sendSaleBundleBuyMetric(const sSale* aSale, int aAmount);
	static void sendSaleItemBuyMetric(const sSale* aSale, const std::string& aItemId, int aCount);
	static void sendSaleItemsBuyMetric(const sSale* aSale, const std::vector< std::string >& aItemsId, int aCount);

	static std::string getResourceIDByCurrencyType(const eCurrencyType& aCurrencyType);
	static std::string getItemIDForMetric(const std::string& aItemID);
	static std::string getViewIDByCurrentEvent();

	static void sendUGCItemEventMetric(const std::string& aItemId, MetricsSystemEvents::eUGCItemEvent aEvent, const BValueMap& aParams = BValueMap());
	static void sendCollectionMetric(const std::string& aCollectionId, bool aIsAdded);

	static void sendUGCWeeklyRatingMetric();
	static void sendUGCSpecificButtonPress(const std::string& aScreenType, const std::string& aScreenId, std::string aButtonId);
};

_BEND

#endif
