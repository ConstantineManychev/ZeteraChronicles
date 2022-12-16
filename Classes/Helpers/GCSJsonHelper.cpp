#include "GCSJsonHelper.h"

_USEB

void GCSJsonHelper::convertGCSJsonToBValue(const GCS::JSON& aJson, BValue& aValue)
{
    if (aJson.is_string())
    {
        aValue = aJson.get<std::string>();
    }
    else if (aJson.is_number_integer())
    {
        aValue = aJson.get<int>();
    }
    else if (aJson.is_number_float())
    {
        aValue = aJson.get<float>();
    }
    else if (aJson.is_boolean())
    {
        aValue = aJson.get<bool>();
    }
    else if (aJson.is_object())
    {
        aValue.clearWithType(BValue::Type::MAP);
        BValueMap& valueMap = aValue.getValueMap();

        for (auto jsonIt = aJson.begin(); jsonIt != aJson.end(); jsonIt++)
        {
            if (!jsonIt.value().empty())
            {
                BValue& fillValue = valueMap[jsonIt.key()];
                convertGCSJsonToBValue(jsonIt.value(), fillValue);
            }
        }
    }
    else if (aJson.is_array())
    {
        aValue.clearWithType(BValue::Type::VECTOR);
        BValueVector& valueVec = aValue.getValueVector();
        int jsonSize = aJson.size();
        valueVec.resize(jsonSize);
        int i = 0;
        for (auto jsonIt = aJson.begin(); jsonIt != aJson.end(), i < jsonSize; jsonIt++, i++)
        {
            convertGCSJsonToBValue(jsonIt.value(), valueVec[i]);
        }
    }
}

void GCSJsonHelper::parseResponseData(BValueMap& aRespParams, const GCS::JSON& aRespData)
{
    for (auto cmdDataIt = aRespData.begin(); cmdDataIt != aRespData.end(); cmdDataIt++)
    {
        auto& valueParams = aRespParams[cmdDataIt.key()];
        convertGCSJsonToBValue(cmdDataIt.value(), valueParams);
    }
}

void GCSJsonHelper::convertMapToGCSJson(GCS::JSON& aData, const BValueMap& aValueMap)
{
    BValue::Type valueType;
    for (const auto& paramPair : aValueMap)
    {
        valueType = paramPair.second.getType();

        switch (valueType)
        {
        case BValue::Type::INTEGER:
            aData[paramPair.first] = paramPair.second.getInt();
            break;
        case BValue::Type::STRING:
            aData[paramPair.first] = paramPair.second.getString();
            break;
        case BValue::Type::BOOLEAN:
            aData[paramPair.first] = paramPair.second.getBool();
            break;
        case BValue::Type::FLOAT:
            aData[paramPair.first] = paramPair.second.getFloat();
            break;
        case BValue::Type::MAP:
            convertMapToGCSJson(aData[paramPair.first], paramPair.second.getValueMap());
            break;
        case BValue::Type::VECTOR:
            convertFromBValueVectorToJsonVector(aData[paramPair.first], paramPair.second.getValueVector());
            break;
        default:
            break;
        }
    }
}

void GCSJsonHelper::convertFromBValueVectorToJsonVector(GCS::JSON::value_type& aObj, const BValueVector& aVector)
{
    for (auto& value : aVector)
    {
        switch (value.getType())
        {
        case BValue::Type::INTEGER:
            aObj.push_back(value.getInt());
            break;
        case BValue::Type::STRING:
            aObj.push_back(value.getString());
            break;
        case BValue::Type::BOOLEAN:
            aObj.push_back(value.getBool());
            break;
        case BValue::Type::FLOAT:
            aObj.push_back(value.getFloat());
            break;
        case BValue::Type::COLOR4F:
            aObj.push_back(value.getString());
            break;
        case BValue::Type::MAP:
        {
            GCS::JSON::value_type obj;
            convertMapToGCSJson(obj, value.getValueMap());
            aObj.push_back(obj);
        }
        break;
        case BValue::Type::VECTOR:
        {
            GCS::JSON::value_type obj;
            convertFromBValueVectorToJsonVector(obj, value.getValueVector());
            aObj.push_back(obj);
        }
        break;
        }
    }
}