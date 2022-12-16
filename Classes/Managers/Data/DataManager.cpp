#include "DataManager.h"

#include "BJsonHelper.h"

#include "external/json/document.h"
#include "external/json/reader.h"
#include "external/json/stringbuffer.h"
#include "external/json/prettywriter.h"

#include "Managers/GameDirector.h"

USING_NS_CC;

DataManager::DataManager()
{

}
DataManager::~DataManager()
{

}

DataManager* DataManager::getInstance()
{
	static DataManager instance;

	return &instance;
}

void DataManager::onInit()
{

}

void DataManager::loadMainConfig()
{
	//	std::string content = FileUtils::getInstance()->getStringFromFile( "data/main_config.json" );
	std::string content = EFM->getFileString("data/main_config.json");

	rapidjson::Document doc;
	doc.Parse<0>(content.c_str());
	if (!doc.HasParseError())
	{
		for (auto it = doc.MemberBegin(); it != doc.MemberEnd(); ++it)
		{
			std::string key = it->name.GetString();
			BJsonHelper::parseBValueFromJsonValue(it->value, mMainConfigs[key]);
		}
	}
	else
	{
		log("DataManager::loadDressToFile error parse file = data/main_config.json");
	}
}