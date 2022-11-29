#include "GameDirector.h"
#include "AppDelegate.h"
#include "Types/DataTypes.h"

using namespace cocos2d;

GameDirector::GameDirector()
	: mGameAspectRatio(eGameAspectRatio::_UNDEF)
	, mAppTime(0)
{

}

GameDirector::~GameDirector()
{

}

GameDirector* GameDirector::getInstance()
{
	static GameDirector instance;

	return &instance;
}

void GameDirector::onInit()
{
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	mWindowsConsole = GetConsoleWindow();
#endif

	Size defaultScreenSize;
	defaultScreenSize.width = GetSystemMetrics(SM_CXSCREEN);
	defaultScreenSize.height = GetSystemMetrics(SM_CYSCREEN);

	setDefaultScreenSize(defaultScreenSize);

	setScreenSize(defaultScreenSize);
	setFullScreen(true);
}



void GameDirector::setDefaultScreenSize(Size& aSize)
{
	mDefaultScreenSize = aSize;
}

void GameDirector::setScreenSize(Size& aSize)
{
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	//MoveWindow(mWindowsConsole, 0, 0, aSize.width, aSize.height, TRUE);
	//SetWindowPos(mWindowsConsole, NULL, 0, 0, aSize.width, aSize.height, SWP_NOZORDER);
	//CenterWindow(mWindowsConsole);
#endif
}

void GameDirector::setFullScreen(bool aIsFullScreen)
{
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	if (aIsFullScreen)
	{
		//system("mode 650");
		//SetConsoleDisplayMode(mWindowsConsole, CONSOLE_FULLSCREEN_MODE, 0);
		SendMessage(mWindowsConsole, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	}
	else
	{
		//SetConsoleDisplayMode(mWindowsConsole, CONSOLE_WINDOWED_MODE, 0);
		ShowWindow(mWindowsConsole, SW_MAXIMIZE);
		//SendMessage(mWindowsConsole, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	}
#endif
}

void GameDirector::Draw()
{

}

void GameDirector::run()
{
	update(0.0f);
}

void GameDirector::update(float aDelta)
{
	if (isCloseApp)
	{

	}
}