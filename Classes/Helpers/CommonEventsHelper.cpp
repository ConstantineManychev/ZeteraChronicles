#include "Helpers/CommonEventsHelper.h"

_USEB

constexpr char* STR_VAL = "str_val";
constexpr char* STR_VALS = "str_vals";
constexpr char* ERR_VAL = "err_val";
constexpr char* ORDER_REQ = "order_req";

BValueMap CommonEventsHelper::getStringMap(const std::string& aStringValue, int aOrderReq)
{
    BValueMap result;
	BValueVector strings;
	strings.push_back(aStringValue);
	result[STR_VALS] = strings;
	result[ORDER_REQ] = aOrderReq;
    return result;
}

BValueMap CommonEventsHelper::getStringsMap(const std::vector<std::string>& aVectorString, int aOrderReq)
{
	BValueMap result;
	BValueVector strings; 

	for (auto str : aVectorString)
	{
		strings.push_back(str);
	}

	result[STR_VALS] = strings;
	result[ORDER_REQ] = aOrderReq;
	return result;
}

BValueMap CommonEventsHelper::getStringMapWithError(const std::string& aStringValue, int aError)
{
	BValueMap result;
	BValueVector strings;
	strings.push_back(aStringValue);
	result[STR_VALS] = strings;
	result[ERR_VAL] = aError;
	return result;
}

BValueMap CommonEventsHelper::getStringsMapWithError(const std::vector<std::string>& aStringValue, int aError)
{
	BValueMap result;
	BValueVector strings;
	for (auto str : aStringValue)
	{
		strings.push_back(str);
	}
	result[STR_VALS] = strings;
	result[ERR_VAL] = aError;
	return result;

}

std::string CommonEventsHelper::getStringData(const BValueMap& aRepEventParams)
{
    std::string strVal{ "" };

    auto dataIt = aRepEventParams.find(STR_VAL);
    if (dataIt != aRepEventParams.end() && dataIt->second.isString())
    {
        strVal = dataIt->second.getString();
    }

    return strVal;
}

int CommonEventsHelper::getDataError(const BValueMap& aRepEventParams)
{
	int errVal = -1;

	auto dataIt = aRepEventParams.find(ERR_VAL);
	if (dataIt != aRepEventParams.end() && dataIt->second.isInteger())
	{
		errVal = dataIt->second.getInt();
	}

	return errVal;
}

std::tuple<std::string, int> CommonEventsHelper::getStringMapWithForceVal(const BValueMap& aRepEventParams)
{
	std::string strVal{ "" };
	int orderReq{ 0 };

	auto dataIt = aRepEventParams.find(STR_VAL);
	if (dataIt != aRepEventParams.end() && dataIt->second.isString())
	{
		strVal = dataIt->second.getString();
	}

	dataIt = aRepEventParams.find(ORDER_REQ);
	if (dataIt != aRepEventParams.end() && dataIt->second.isInteger())
	{
		orderReq = dataIt->second.getInt();
	}

	return std::make_tuple(strVal, orderReq);
}

std::tuple<std::vector<std::string>, int> CommonEventsHelper::getStringsMapWithForceVal(const BValueMap& aRepEventParams)
{
    std::vector<std::string> strVal;
    int orderReq{ 0 };

    auto dataIt = aRepEventParams.find(STR_VALS);
    if (dataIt != aRepEventParams.end() && dataIt->second.isVector())
    {
		auto& vecVals = dataIt->second.getValueVector();
		for(auto str : vecVals)
		{
			strVal.push_back(str.getString());
		}
    }

    dataIt = aRepEventParams.find(ORDER_REQ);
    if (dataIt != aRepEventParams.end() && dataIt->second.isInteger())
    {
        orderReq = dataIt->second.getInt();
    }

    return std::make_tuple(strVal, orderReq);
}
