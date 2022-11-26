#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "Types/DataTypes.h"

//namespace myGame {

	class  AppDelegate
	{
	private:
		sSize mDefaultScreenSize;

	private:
		void setDefaultScreenSize();

	public:
		void onInit();

		AppDelegate();
		virtual ~AppDelegate();

		static AppDelegate* getInstance();
	};

#define DM AppDelegate::getInstance()

//}

#endif // _APP_DELEGATE_H_