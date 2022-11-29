#include "AppDelegate.h"
#include "windows.h"
#include "GameDirector.h"

using namespace cocos2d;

AppDelegate::AppDelegate()
{

}
AppDelegate::~AppDelegate()
{

}

void AppDelegate::onInit()
{
	GD->onInit();
}