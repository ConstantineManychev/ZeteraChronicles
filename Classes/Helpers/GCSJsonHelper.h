#ifndef _GCSJSONHELPER_H_
#define _GCSJSONHELPER_H_

#include "BCommonDefines.h"
#include "GCSWrapper.h"
#include "BValue.h"

_BSTART

class GCSJsonHelper
{
public:
    static void convertGCSJsonToBValue(const GCS::JSON& aJson, BValue& aValue);
    static void parseResponseData(BValueMap& aRespParams, const GCS::JSON& aRespData);

    static void convertMapToGCSJson(GCS::JSON& aJson, const BValueMap& aValueMap);
    static void convertFromBValueVectorToJsonVector(GCS::JSON::value_type& aObj, const BValueVector& aVector);
};

_BEND

#endif // _GCSJSONHELPER_H_

