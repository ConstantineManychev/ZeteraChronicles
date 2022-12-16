#ifndef _LiveOpsDataHelper_H_
#define _LiveOpsDataHelper_H_

#include "BCommon.h"// TODO : NEED FOR JSON
#include "Types/LiveOpsDataTypes.h"

_BSTART

class LiveOpsDataHelper
{
	LiveOpsDataHelper();
	virtual  ~LiveOpsDataHelper();


public:

	static void parseLiveOpsDailyReward(const rapidjson::Value& aData, sLiveOpsDailyReward& aInfo);
	static void parseLiveOpsRewardInfo(const rapidjson::Value& aData, sLiveOpsRewardInfo& aInfo);
	static void parseLiveOpsRewardInfo(const BValue& aData, sLiveOpsRewardInfo& aInfo);
	static void parseLiveOpsRankInfo(const rapidjson::Value& aData, sLiveOpsRankInfo& aInfo);
	static void parseMarathonTokenDailyReward(const rapidjson::Value& aData, sMarathonTokenDailyReward & aInfo);

	static eMarathonTokenActionRewardType getActionRewardByString(const std::string& aStr);
	static std::string getStringByActionRewardType(eMarathonTokenActionRewardType aType);
};

_BEND

#endif