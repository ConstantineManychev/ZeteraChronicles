#include "LiveOpsDataHelper.h"
#include "BGameManager.h"
#include "Helpers/DataTypesHelper.h"
#include "Managers/Data/DataManager.h"

_USEB

LiveOpsDataHelper::LiveOpsDataHelper()
{
}

LiveOpsDataHelper::~LiveOpsDataHelper()
{
}

void LiveOpsDataHelper::parseLiveOpsDailyReward(const rapidjson::Value& aData, sLiveOpsDailyReward & aInfo)
{
	if (aData.IsObject())
	{
		auto infoIt = aData.FindMember("id");
		if (infoIt != aData.MemberEnd())
		{
			aInfo.id = infoIt->value.GetString();
		}

		infoIt = aData.FindMember("reward");
		if (infoIt != aData.MemberEnd())
		{
			auto& rewardValue = infoIt->value;
			if (rewardValue.IsObject())
			{
				DataTypesHelper::parseEventRewardInfo(rewardValue, aInfo.reward);
				
				auto rewardIt = rewardValue.FindMember("item_type");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.typeItem = DataTypesHelper::getEventRewardTypeFromString(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("price_min");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.priceMin = atoi(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("price_max");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.priceMax = atoi(rewardIt->value.GetString());
				}
			}
		}
	}
}

void LiveOpsDataHelper::parseMarathonTokenDailyReward(const rapidjson::Value& aData, sMarathonTokenDailyReward & aInfo)
{
	if (aData.IsObject())
	{
		auto infoIt = aData.FindMember("id");
		if (infoIt != aData.MemberEnd())
		{
			aInfo.id = infoIt->value.GetString();
		}

		infoIt = aData.FindMember("reward");
		if (infoIt != aData.MemberEnd())
		{
			auto& rewardValue = infoIt->value;
			if (rewardValue.IsObject())
			{
				auto rewardIt = rewardValue.FindMember("reward_type");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.rewType = DataTypesHelper::getEventRewardTypeFromString(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("item_type");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.currencyType = DataTypesHelper::getCurrencyTypeFromStr(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("tokens_count");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.needTokens = rewardIt->value.GetInt();
				}

				rewardIt = rewardValue.FindMember("reward_amount");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.rewardAmount = rewardIt->value.GetInt();
				}

				rewardIt = rewardValue.FindMember("price_min");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.priceMin = atoi(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("price_max");
				if (rewardIt != rewardValue.MemberEnd())
				{
					aInfo.priceMax = atoi(rewardIt->value.GetString());
				}

				rewardIt = rewardValue.FindMember("reward_look_id");
				if (rewardIt != rewardValue.MemberEnd())
				{
                    aInfo.lookId = DM->getLookIDByOldID(rewardIt->value.GetString()); // TODO : REMOVE CONVERTATION TO SAVE ID
				}
			}
		}
	}
}

void LiveOpsDataHelper::parseLiveOpsRewardInfo(const rapidjson::Value & aData, sLiveOpsRewardInfo & aInfo)
{
	if (aData.IsObject())
	{
		if (aData.HasMember("reward_type"))
		{
			std::string rwdStrType = aData["reward_type"].GetString();
			if (rwdStrType == "cash")
			{
				aInfo.rewardType = eRewardType::CASH;
			}
			else if (rwdStrType == "crystals")
			{
				aInfo.rewardType = eRewardType::CRYSTALS;
			}
		}

		if (aData.HasMember("reward_amount"))
		{
			int amount = aData["reward_amount"].GetInt();
			aInfo.rewardsAmount = amount;
		}

		if (aData.HasMember("reward_look_id"))
		{
			aInfo.rewardType = eRewardType::ITEM;
            aInfo.rewardLookId = DM->getLookIDByOldID(aData["reward_look_id"].GetString()); // TODO : REMOVE CONVERTATION TO SAVE ID
		}
	}
}

void LiveOpsDataHelper::parseLiveOpsRewardInfo(const BValue & aData, sLiveOpsRewardInfo & aInfo)
{
	if (aData.checkType(BValue::Type::MAP))
	{
		auto& data = aData.getValueMap();
		sLiveOpsRewardInfo infoReward;

		auto rewardParamIt = data.find("reward_type");
		if (rewardParamIt != data.end())
		{
			std::string rwdStrType = rewardParamIt->second.getString();
			if (rwdStrType == "cash")
			{
				aInfo.rewardType = eRewardType::CASH;
			}
			else if (rwdStrType == "crystals")
			{
				aInfo.rewardType = eRewardType::CRYSTALS;
			}

			rewardParamIt = data.find("reward_amount");
			if (rewardParamIt != data.end())
			{
				int amount = rewardParamIt->second.getInt();
				aInfo.rewardsAmount = amount;
			}

			rewardParamIt = data.find("reward_look_id");
			if (rewardParamIt != data.end())
			{
				aInfo.rewardType = eRewardType::ITEM;
                aInfo.rewardLookId = DM->getLookIDByOldID(rewardParamIt->second.getString()); // TODO : REMOVE CONVERTATION TO SAVE ID
			}
		}
	}
}

void LiveOpsDataHelper::parseLiveOpsRankInfo(const rapidjson::Value & aData, sLiveOpsRankInfo & aInfo)
{
	if (aData.IsObject())
	{
		auto infoIt = aData.FindMember("id");
		if (infoIt != aData.MemberEnd())
		{
			aInfo.id = infoIt->value.GetString();
		}

		infoIt = aData.FindMember("places_count");
		if (infoIt != aData.MemberEnd())
		{
			aInfo.placesCount = infoIt->value.GetInt();
		}

		infoIt = aData.FindMember("reward");
		if (infoIt != aData.MemberEnd())
		{
			auto rewardsVec = infoIt->value.GetArray();
			auto rewardsSize = rewardsVec.Size();
			aInfo.rewards.resize(rewardsSize);

			int j = 0;
			for (auto& rewardIt : rewardsVec)
			{
				if (rewardIt.IsObject())
				{
					parseLiveOpsRewardInfo(rewardIt, aInfo.rewards[j]);
					++j;
				}
			}
		}

		infoIt = aData.FindMember("vis_leader");
		if (infoIt != aData.MemberEnd())
		{
			aInfo.isVisibleInLeaderboard = infoIt->value.GetBool();
		}
	}
}

eMarathonTokenActionRewardType LiveOpsDataHelper::getActionRewardByString(const std::string & aStr)
{
	eMarathonTokenActionRewardType rew = eMarathonTokenActionRewardType::NONE;

	if (aStr == "daily_challenge")
	{
		rew = eMarathonTokenActionRewardType::DAILY_CHALLENGE;
	}
	else if (aStr == "daily_deal")
	{
		rew = eMarathonTokenActionRewardType::DAILY_DEAL;
	}
	else if (aStr == "event_result")
	{
		rew = eMarathonTokenActionRewardType::EVENT_RESULT;
	}
	else if (aStr == "event_submit")
	{
		rew = eMarathonTokenActionRewardType::EVENT_SUBMIT;
	}
	else if (aStr == "item_buy")
	{
		rew = eMarathonTokenActionRewardType::ITEM_BUY;
	}
	else if (aStr == "vote")
	{
		rew = eMarathonTokenActionRewardType::VOTING;
	}
	else if (aStr == "lootbox")
	{
		rew = eMarathonTokenActionRewardType::LOOTBOX;
	}
	return rew;
}

std::string LiveOpsDataHelper::getStringByActionRewardType(eMarathonTokenActionRewardType aType)
{
	std::string rew;

	if (aType == eMarathonTokenActionRewardType::DAILY_CHALLENGE)
	{
		rew = "daily_challenge";
	}
	else if (aType == eMarathonTokenActionRewardType::DAILY_DEAL)
	{
		rew = "daily_deal";
	}
	else if (aType == eMarathonTokenActionRewardType::EVENT_RESULT)
	{
		rew = "event_result";
	}
	else if (aType == eMarathonTokenActionRewardType::EVENT_SUBMIT)
	{
		rew = "event_submit";
	}
	else if (aType == eMarathonTokenActionRewardType::ITEM_BUY)
	{
		rew = "item_buy";
	}
	else if (aType == eMarathonTokenActionRewardType::VOTING)
	{
		rew = "vote";
	}
	else if (aType == eMarathonTokenActionRewardType::LOOTBOX)
	{
		rew = "lootbox";
	}
	return rew;
}