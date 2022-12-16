#include "Helpers/MetricHelper.h"
#include "Managers/Data/DataManager.h"
#include "Types/DataTypes.h"
#include "Managers/GameDirector.h"
#include "Helpers/MetricTransformHelper.h"
#include "Managers/Shop/ShopManager.h"
#include "Managers/Shop/StoreManager.h"
#include "Managers/ItemSystem/ItemSystem.h"
#include "Managers/Presets/PresetsManager.h"

#include "Managers/Players/PlayerProfile.h"

#include "Managers/LiveOps/LiveOpsSystem.h"
#include "Managers/LiveOps/EventSets/LiveOpsEventSetsController.h"
#include "Managers/LiveOps/RunwayDuel/LiveOpsRunwayDuelController.h"
#include "Managers/LiveOps/Journey/LiveOpsJourneyController.h"
#include "Managers/DesignerLooks/DesignerLooksManager.h"
#include "Helpers/DataTypesHelper.h"

_USEB

BValueMap MetricHelper::getEventItemBuyMetricParamsMap(const sLookMetaData* aLookMeta)
{
	BValueMap result;

	result["location_id"] = MTHelper->getLocationName(PLAYER->getCurrentLocation());

	if (aLookMeta)
	{
		auto itemPriceInfo = ISYSTEM->getItemPriceInfo(aLookMeta);
		result["amount"] = -1 * itemPriceInfo.finalPrice;
	}

	auto eventSetsInfo = EVENT_SETS->getCurrentEventInfo();
	if (eventSetsInfo && PLAYER->getCurrentEvent() == eventSetsInfo->eventUniqueID)
	{
		result["event_id"] = eventSetsInfo->eventUniqueID;
		result["sub_event"] = static_cast<int>(MetricsSystemEvents::eMetricsSystemEvent::EVENT_SETS_ITEM_BUY);
		
		if (aLookMeta)
		{
			result["modifier"] = aLookMeta->currencyType == eCurrencyType::CASH ? "ITEM" : "PREMIUM";
			result["action"] = "BUY";
		}
	}
	else if (PLAYER->getCurrentEvent() == RUNWAY_DUEL->getDressingRoomEventId())
	{
		result["paste_id_formatted"] = true;

		result["modifier"] = "%s|" + MetricHelper::getResourceIDByCurrencyType(aLookMeta->currencyType);
		result["sub_event"] = static_cast<int>(MetricsSystemEvents::eMetricsSystemEvent::DUEL_ITEM_BUY);
	}

	return result;
}

void MetricHelper::sendSalePopupOpenMetric(const std::string& aScreenId)
{
	if (!aScreenId.empty())
	{
		BValueMap revParams;
		revParams["screen_type"] = "POPUP";
		revParams["screen_id"] = aScreenId;

		EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::SALE_POPUP_OPEN, revParams);
	}
}

void MetricHelper::sendSaleBundleBuyMetric(const sSale* aSale, int aAmount)
{
	if (aSale && aAmount)
	{
		BValueMap revParams;
		revParams["source_type"] = "DIRECT" + (!aSale->offerId.empty() ? "|" + aSale->offerId : "");
		revParams["screen_type"] = "POPUP" + (!aSale->screenId.empty() ? "|" + aSale->screenId : "");
		revParams["resource_id"] = "DIAMONDS";
		revParams["amount"] = -aAmount;

		EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::SALE_BUNDLE_BUY, revParams);
	}
}

void MetricHelper::sendSaleItemsBuyMetric(const sSale* aSale, const std::vector< std::string >& aItemsId, int aCount)
{
	if (!aItemsId.empty())
	{
		for (const std::string& itemId : aItemsId)
		{
			sendSaleItemBuyMetric(aSale, itemId, aCount);
		}
	}
}

std::string MetricHelper::getResourceIDByCurrencyType(const eCurrencyType & aCurrencyType)
{
	std::string result;

	switch (aCurrencyType)
	{
	case eCurrencyType::CASH:
		result = "CASH";
		break;
	case eCurrencyType::CRYSTALS:
		result = "DIAMONDS";
		break;
	case eCurrencyType::TICKET:
		result = "TICKET";
		break;
	};

	return result;
}

std::string MetricHelper::getItemIDForMetric(const std::string & aItemID)
{
	std::string result;

	const bool isItemFace = (PRESETS_MNG->getPremiumFaceInfo(aItemID) != nullptr);
	auto metaData = DM->getUnlockedLookMetaData(aItemID);
	if (metaData)
	{
		auto lookCategory = ISYSTEM->getLookCategoryByLookType(metaData->lookType);
		if (lookCategory == eLookCategory::HAIRSTYLE)
		{
			result = "HAIRSTYLE|" + aItemID;
		}
		else if (lookCategory == eLookCategory::MAKEUP_EYES)
		{
			result = "MAKEUP|EYELINER|" + aItemID;
		}
		else if (lookCategory == eLookCategory::MAKEUP_LIPS)
		{
			result = "MAKEUP|LIPSTICK|" + aItemID;
		}
		else if (lookCategory == eLookCategory::CONSUMABLE)
		{
			result = "CONSUMABLE|";

			const auto& lookType = metaData->lookType;
			if (lookType == eLookType::FACE_GLITTER)
			{
				result += "GLITTER|";
			}
			else if (lookType == eLookType::PERFUME)
			{
				result += "PERFUME|";
			}

			result += aItemID;
		}
		else
		{
			result = "CLOTH|";

			if (lookCategory == eLookCategory::DRESS)
			{
				result += "DRESS|";
			}
			else if (lookCategory == eLookCategory::TOP_A)
			{
				result += "TOP|";
			}
			else if (lookCategory == eLookCategory::TOP_B)
			{
				result += "OUTERWEAR|";
			}
			else if (lookCategory == eLookCategory::BOTTOM)
			{
				result += "BOTTOM|";
			}
			else if (lookCategory == eLookCategory::SHOES)
			{
				result += "SHOES|";
			}
			else if (lookCategory == eLookCategory::ACCESSORIES)
			{
				result += "ACCESSORY|";
			}

			result += MTHelper->getItemIDByLookMeta(metaData);
		}
	}
	else if (isItemFace)
	{
		result = "PREMIUMFACE|" + aItemID;
	}
	else
	{
		result = "FACESLOT|" + aItemID;
	}

	return result;
}

std::string MetricHelper::getViewIDByCurrentEvent()
{
	std::string result = "dressing_room";

	auto eventSetsInfo = EVENT_SETS->getCurrentEventInfo();
	if (eventSetsInfo && PLAYER->getCurrentEvent() == eventSetsInfo->eventUniqueID)
	{
		result = "event_sets";
	}
	else if (PLAYER->getCurrentEvent() == RUNWAY_DUEL->getDressingRoomEventId())
	{
		result = "runway_duel";
	}
	else if (PLAYER->getCurrentEvent() == JOURNEY->getDressingRoomEventId())
	{
		result = "journey";
	}

	return result;
}

void MetricHelper::sendSaleItemBuyMetric(const sSale* aSale, const std::string& aItemId, int aCount)
{
	if (aSale)
	{
		std::string resources = "";
		auto itemMeta = DM->getLookMetaData(aItemId);

		BValueMap revParams;
		revParams["source_type"] = "DIRECT" + (!aSale->offerId.empty() ? "|" + aSale->offerId : "");
		revParams["screen_type"] = "POPUP" + (!aSale->screenId.empty() ? "|" + aSale->screenId : "");

		if (aSale->id != "FACES_BUNDLE"
			&& itemMeta && itemMeta->isLoaded)
		{
			resources = resources + getItemTypeStringByLookType(itemMeta->lookType);
			resources = resources + "|" + getItemSubTypeStringByLookType(itemMeta->lookType) + "|";
		}
		else
		{
			if (aItemId == "ANY")
			{
				resources = resources + "PREMIUMFACE||";
			}
			else
			{
				resources = resources + "FACESLOT||";
			}
		}

		resources = resources + aItemId;

		revParams["resources"] = resources;
		revParams["count"] = aCount;


		EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::SALE_ITEM_BUY, revParams);
	}
}

std::string MetricHelper::getItemSubTypeStringByLookType(eLookType type)
{
	std::string result = "";

	switch (type)
	{
	case eLookType::MAKEUP_EYES:
		result = "EYELINER";
		break;
	case eLookType::MAKEUP_LIPS:
		result = "LIPSTICK";
		break;
	case eLookType::PERFUME:
		result = "PERFUME";
		break;
	case eLookType::FACE_GLITTER:
		result = "GLITTER";
		break;
	default:
		result = "";
		break;
	}

	return result;
}

std::string MetricHelper::getItemTypeStringByLookType(eLookType type)
{
	std::string result = "";

	switch (type)
	{
	case eLookType::HAIRSTYLE:
		result = "HAIRSTYLE";
		break;
	case eLookType::MAKEUP_EYES:
	case eLookType::MAKEUP_LIPS:
		result = "MAKEUP";
		break;
	case eLookType::PERFUME:
	case eLookType::FACE_GLITTER:
		result = "CONSUMABLE";
		break;
	default:
		result = "UNDEFINED";
		break;
	}


	return result;
}

void MetricHelper::sendCollectionMetric(const std::string& aCollectionName, bool aIsAdded)
{
	auto dlm = dynamic_cast<DesignerLooksManager*>(DESIGNER_LOOKS_MANAGER);

	if (dlm)
	{
		auto collectionID = PLAYER->getDesignerCollectionIdAsStringByName(aCollectionName);

		if (collectionID != "NON_COLLECTION" && !collectionID.empty())
		{
			auto publishedAmount = dlm->getPublishedItemsAmountByCollectionID(collectionID);

			int collectionUnlockThreashold =  DM->getMainConfigValueByID("collection_unlock_threshold").getInt();

			BValueMap revParams;
			revParams["collectionid"] = collectionID;

			if (publishedAmount == collectionUnlockThreashold && aIsAdded)
			{
				EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::UGC_COLLECTON_CREATE, revParams);
			}
			else if (publishedAmount == collectionUnlockThreashold - 1 && !aIsAdded)
			{
				EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::UGC_COLLECTON_DELETE, revParams);
			}
		}
	}
}

void MetricHelper::sendUGCItemEventMetric(const std::string& aItemId, MetricsSystemEvents::eUGCItemEvent aEvent, const BValueMap& aParams)
{
	auto metaData = const_cast<sLookMetaData*>(DM->getLookMetaData(aItemId));

	if (metaData)
	{
		if (!metaData->isLoaded)
		{
			DataTypesHelper::initMetaFromParams(metaData, aParams);
		}

		BValueMap revParams;
		revParams["itemid"] = MTHelper->getUGCItemIDByLookMeta(metaData);

		MetricsSystemEvents::eMetricsSystemEvent metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UNDEFINED;

		if (aEvent == MetricsSystemEvents::eUGCItemEvent::IMPORT)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_IMPORT;
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::PUBLISH)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_PUBLISH;
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::UNPUBLISH)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_UNPUBLISH;
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::SELL)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_SELL;
			
			auto paramIt = aParams.find("count");
			if (paramIt != aParams.end() && paramIt->second.checkType(BValue::Type::INTEGER))
			{
				revParams["item_id_qty"] = MTHelper->getItemIDByLookMeta(metaData) + "|" + std::to_string(paramIt->second.getInt());
			}

			paramIt = aParams.find("amount");
			if (paramIt != aParams.end() && paramIt->second.checkType(BValue::Type::INTEGER))
			{
				revParams["amount"] = std::to_string(paramIt->second.getInt());
			}
			
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::REPORTED)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_REPORTED;
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::REMOVED)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_REMOVED;
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::REFUND)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_REFUND;
			
			auto paramIt = aParams.find("count");
			if (paramIt != aParams.end() && paramIt->second.checkType(BValue::Type::INTEGER))
			{
				revParams["count"] = std::to_string(std::abs(paramIt->second.getInt()));
			}
		}
		else if (aEvent == MetricsSystemEvents::eUGCItemEvent::BANNED)
		{
			metricEvent = MetricsSystemEvents::eMetricsSystemEvent::UGC_ITEM_BANNED;
		}

		if (metricEvent != MetricsSystemEvents::eMetricsSystemEvent::UNDEFINED)
		{
			EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, metricEvent, revParams);
		}
	}
}

void MetricHelper::sendUGCWeeklyRatingMetric()
{
	BValueMap params;
	params["leaderboard_id"] = "DESIGNERSWEEKLY";
	params["leaderboard_position"] = std::to_string(PLAYER->getDesignerWeeklyRank());

	auto playerInfo = PLAYER->getPlayerInfo();
	if (playerInfo)
	{
		params["rating"] = playerInfo->desWeeklyRating;
	}

	EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::UGC_WEEKLY_RATING, params);
}

void MetricHelper::sendUGCSpecificButtonPress(const std::string& aScreenType, const std::string& aScreenId, std::string aButtonId) 
{
	std::transform(aButtonId.begin(), aButtonId.end(), aButtonId.begin(), toupper);
	aButtonId.erase(std::remove(aButtonId.begin(), aButtonId.end(), '_'), aButtonId.end());

	BValueMap metricParams;
	metricParams["screen_type"] = aScreenType;
	metricParams["screenid"] = aScreenId;
	metricParams["button_id"] = aButtonId;
	EVENTS_SYSTEM->notifySystem(MetricsSystemEvents::EVENT_TYPE, MetricsSystemEvents::eMetricsSystemEvent::SPECIFIC_BUTTON_PRESS, metricParams);
}