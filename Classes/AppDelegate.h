#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "Types/DataTypes.h"

#define CC_PLATFORM_UNKNOWN            0
#define CC_PLATFORM_IOS                1
#define CC_PLATFORM_ANDROID            2
#define CC_PLATFORM_WIN32              3
#define CC_PLATFORM_MARMALADE          4
#define CC_PLATFORM_LINUX              5
#define CC_PLATFORM_BADA               6
#define CC_PLATFORM_BLACKBERRY         7
#define CC_PLATFORM_MAC                8
#define CC_PLATFORM_NACL               9
#define CC_PLATFORM_EMSCRIPTEN        10
#define CC_PLATFORM_TIZEN             11
#define CC_PLATFORM_QT5               12
#define CC_PLATFORM_WINRT             13

#define CC_TARGET_PLATFORM             CC_PLATFORM_UNKNOWN

// Apple: Mac and iOS
#if defined(__APPLE__) && !defined(ANDROID) // exclude android for binding generator.
//#include <TargetConditionals.h>
//#if TARGET_OS_IPHONE // TARGET_OS_IPHONE includes TARGET_OS_IOS TARGET_OS_TV and TARGET_OS_WATCH. see TargetConditionals.h
//#undef  CC_TARGET_PLATFORM
//#define CC_TARGET_PLATFORM         CC_PLATFORM_IOS
//#elif TARGET_OS_MAC
#undef  CC_TARGET_PLATFORM
#define CC_TARGET_PLATFORM         CC_PLATFORM_MAC
//#endif
#endif

// android
#if defined(ANDROID)
#undef  CC_TARGET_PLATFORM
#define CC_TARGET_PLATFORM         CC_PLATFORM_ANDROID
#endif

// win32
#if defined(_WIN32) && defined(_WINDOWS)
#undef  CC_TARGET_PLATFORM
#define CC_TARGET_PLATFORM         CC_PLATFORM_WIN32
#endif

// linux
#if defined(LINUX) && !defined(__APPLE__)
#undef  CC_TARGET_PLATFORM
#define CC_TARGET_PLATFORM         CC_PLATFORM_LINUX
#endif

//namespace myGame {

	class  AppDelegate
	{
	private:
		sSize mDefaultScreenSize;
		int mAppTime;
		bool isCloseApp;

	private:
		void update(float aDelta);

	public:
		void onInit();

		AppDelegate();
		virtual ~AppDelegate();

		static AppDelegate* getInstance();

		void run();

		void setDefaultScreenSize(sSize& aSize);
	};

#define AD AppDelegate::getInstance()

//}

#endif // _APP_DELEGATE_H_