#ifndef _TIMEHELPER_H_
#define _TIMEHELPER_H_

#include "BCommonDefines.h"
#include <string>
#include <map>
#include "Types/DataTypes.h"

_BSTART

#define TH_SECONDS_IN_WEEK 604800
#define TH_SECONDS_IN_DAY 86400
#define TH_SECONDS_IN_HOUR 3600
#define TH_SECONDS_IN_MINUTE 60

class TimeHelper
{
public:
    static std::string getStringTimeInSimpleFormat(long aTargetTime, int borderDay = -1);
    static std::string getStringTimeInSpecialFormat(long aTargetTime);
    static std::map<eTimeFormatType, int> getMapTimeInSpecialFormat(long aTargetTime);
};

_BEND

#endif // _TIMEHELPER_H_
