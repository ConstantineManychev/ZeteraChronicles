#include "DataManager.h"


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