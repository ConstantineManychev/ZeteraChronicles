#include "AppDelegate.h"
#include "windows.h"
#include "GameDirector.h"

AppDelegate::AppDelegate()
	: mAppTime (0)
{

}
AppDelegate::~AppDelegate()
{

}

AppDelegate* AppDelegate::getInstance()
{
	static AppDelegate instance;

	return &instance;
}

void AppDelegate::onInit()
{
	GD->onInit();
}

void AppDelegate::run()
{
	update(0.0f);
}

void AppDelegate::update(float aDelta)
{
	if (isCloseApp)
	{

	}
}

void AppDelegate::setDefaultScreenSize(sSize& aSize)
{
	mDefaultScreenSize = aSize;
}