#include "AppDelegate.h"
#include "windows.h"
#include "GameDirector.h"

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