#include "DataManager.h"

using namespace cocos2d;

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