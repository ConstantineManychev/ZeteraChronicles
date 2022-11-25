#include "AppDelegate.h"
#include <windows.h>

AppDelegate::AppDelegate()
	: mDefaultScreenSize ()
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

}

void AppDelegate::setDefaultScreenSize()
{
	auto defaultScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	auto defaultScreenHeigh = GetSystemMetrics(SM_CYSCREEN);

	mDefaultScreenSize.width = defaultScreenWidth;
	mDefaultScreenSize.height = defaultScreenHeigh;
}