#ifndef _COMMONEVENTSHELPER_H_
#define _COMMONEVENTSHELPER_H_

#include "BCommonDefines.h"
#include "BValue.h"

_BSTART

class CommonEventsHelper
{
public:
    static BValueMap getStringMap(const std::string& aStringValue, int aOrderReq = 1);
	static BValueMap getStringsMap(const std::vector<std::string>& aVectorString, int aOrderReq = 1);
	static BValueMap getStringMapWithError(const std::string& aStringValue, int aError );

	static BValueMap getStringsMapWithError(const std::vector<std::string>& aStringValue, int aError);

    static std::string getStringData(const BValueMap& aRepEventParams);
	static int getDataError(const BValueMap& aRepEventParams);

	static std::tuple<std::string, int> getStringMapWithForceVal(const BValueMap& aRepEventParams);
	static std::tuple<std::vector<std::string>, int> getStringsMapWithForceVal(const BValueMap& aRepEventParams);
};

_BEND

#endif //_COMMONEVENTSHELPER_H_

