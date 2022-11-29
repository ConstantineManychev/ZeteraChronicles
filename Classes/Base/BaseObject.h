#ifndef  _BASE_OBJECT_H_
#define  _BASE_OBJECT_H_

#include "Types/DataTypes.h"
#include "iostream"
#include "vector"
#include "map"

namespace cocos2d {

class  BaseObject
{
private:
	sSize3 mSize;
	sVec3 mPosition;
	BaseObject* mParent;
	std::vector<BaseObject*> mChildren;
	std::string mName;
	std::string mValue;

	//std::map<std::string, Action*> mActions;

private:

public:
	virtual void onInit();

	BaseObject();
	~BaseObject();
};

}

#endif // _BASE_OBJECT_H_