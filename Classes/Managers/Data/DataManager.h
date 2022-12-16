#ifndef  _DATA_MANAGER_H_
#define  _DATA_MANAGER_H_

#include "cocos2d.h"
#include "BCommon.h"

NS_CC_BEGIN
class  DataManager
{
private:
	std::string mProjectName;
	BValue mProjectSettings;
	BValueMap mMainConfigs;

private:
	DataManager();

public:
	void onInit();

	virtual ~DataManager();

	static DataManager* getInstance();

	void loadMainConfig();
};

#define DM DataManager::getInstance()
NS_CC_END

#endif // _DATA_MANAGER_H_