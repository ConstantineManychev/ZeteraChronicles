#include "Helpers/TimeHelper.h"
#include "BValue.h"
#include "BGameManager.h"

_USEB

std::string TimeHelper::getStringTimeInSimpleFormat(long aTargetTime, int borderDay)
{
    std::string result = "";

    auto timeInSpecialFormat = TimeHelper::getMapTimeInSpecialFormat(aTargetTime);

    auto days = timeInSpecialFormat[eTimeFormatType::DAYS];
    auto hours = timeInSpecialFormat[eTimeFormatType::HOURS];
    auto minutes = timeInSpecialFormat[eTimeFormatType::MINUTES];
    auto seconds = timeInSpecialFormat[eTimeFormatType::SECONDS];

    BValue timeStr;

    bool isBorderDay = false;

    if (days <= borderDay)
    {
        result = TimeHelper::getStringTimeInSpecialFormat(aTargetTime);
        isBorderDay = true;
    }

    if (!isBorderDay || borderDay == -1)
    {
        if (days)
        {
			timeStr.initWithFormat("%02d%s %02d%s", days, GET_STRING("TT_DAY").c_str(), hours, GET_STRING("TT_HOUR").c_str());
        }
        else if (hours)
        {
            timeStr.initWithFormat("%02d%s %02d%s", hours, GET_STRING("TT_HOUR").c_str(), minutes, GET_STRING("TT_MINUTE").c_str());
        }
        else
        {
            timeStr.initWithFormat("%02d%s %02d%s", minutes, GET_STRING("TT_MINUTE").c_str(), seconds, GET_STRING("TT_SECOND").c_str());
        }

        result = timeStr.getString();
    }

    return result;
}

std::string TimeHelper::getStringTimeInSpecialFormat(long aTargetTime)
{
    auto timeInSpecialFormat = TimeHelper::getMapTimeInSpecialFormat(aTargetTime);

    auto days = timeInSpecialFormat[eTimeFormatType::DAYS];
    auto hours = timeInSpecialFormat[eTimeFormatType::HOURS];
    auto minutes = timeInSpecialFormat[eTimeFormatType::MINUTES];
    auto seconds = timeInSpecialFormat[eTimeFormatType::SECONDS];

    BValue timeStr;

    if (days)
    {
        timeStr.initWithFormat("%d%s %02d:%02d:%02d", days, GET_STRING("TT_DAY").c_str(), hours, minutes, seconds);
    }
    else
    {
        timeStr.initWithFormat("%02d:%02d:%02d", hours, minutes, seconds);
    }

    return timeStr.getString();
}

std::map<eTimeFormatType, int> TimeHelper::getMapTimeInSpecialFormat(long aTargetTime)
{
    std::map< eTimeFormatType, int > result;
    result[eTimeFormatType::DAYS] = 0;
    result[eTimeFormatType::HOURS] = 0;
    result[eTimeFormatType::MINUTES] = 0;
    result[eTimeFormatType::SECONDS] = 0;

    if (aTargetTime > 0)
    {
        const unsigned long secondsInMinute = TH_SECONDS_IN_MINUTE;
        const unsigned long secondsInHour = TH_SECONDS_IN_HOUR;
        const unsigned long secondsInDay = TH_SECONDS_IN_DAY;

        auto remainingDays = aTargetTime / secondsInDay;
        aTargetTime -= remainingDays * secondsInDay;

        auto remainingHours = aTargetTime / secondsInHour;
        aTargetTime -= remainingHours * secondsInHour;

        auto remainingMinutes = aTargetTime / secondsInMinute;
        aTargetTime -= remainingMinutes * secondsInMinute;

        auto remainingSeconds = aTargetTime;

        result[eTimeFormatType::DAYS] = static_cast<int>(remainingDays);
        result[eTimeFormatType::HOURS] = static_cast<int>(remainingHours);
        result[eTimeFormatType::MINUTES] = static_cast<int>(remainingMinutes);
        result[eTimeFormatType::SECONDS] = static_cast<int>(remainingSeconds);
    }

    return result;
}