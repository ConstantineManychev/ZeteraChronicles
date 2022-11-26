#ifndef  _BASE_OBJECT_H_
#define  _BASE_OBJECT_H_

//#include "Types/DataTypes.h"
#include "iostream"
#include "vector"
#include "map"

//namespace myGame {

	class  BaseObject
	{
	private:
		//sSize3 mSize;
		//sVec3 mPosition;
		BaseObject* mParent;
		std::vector<BaseObject*> mChildren;
		std::string mName;
		std::string mValue;

		//std::map<std::string, Action*> mActions;

	private:

	public:
		void onInit();

		BaseObject();
		~BaseObject();
	};
//}
#endif // _BASE_OBJECT_H_