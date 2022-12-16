#include "GameDirector.h"
#include "AppDelegate.h"
#include "base/CCDirector.h"
#include "Types/DataTypes.h"
#include "Views/Scenes/HelloWorldScene.h"

USING_NS_CC;

#define CREATE_MANAGER(aObject, aClass)           if (aObject == nullptr) { aObject = new  aClass(); }
#define CREATE_MANAGER_WITH_INIT(aObject, aClass)           if (aObject == nullptr) { aObject = new  aClass(); aObject->init(); } 

GameDirector::GameDirector()
	: mGLView(nullptr)
	, mGameAspectRatio(eGameAspectRatio::_UNDEF)
	, mAppTime(0)
	, mIsFullScreen(true)
	, mScreenSize(Size(1024, 768))
	, mEncryptionFileManager(nullptr)
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
	auto director = Director::getInstance();
	auto mGLView = director->getOpenGLView();

	updateWindowSize();

}



void GameDirector::setScreenSize(Size& aSize)
{
	mScreenSize = aSize;
}

Size GameDirector::getScreenSize()
{
	return mScreenSize;
}

void GameDirector::updateWindowSize()
{
	auto director = Director::getInstance();
	if (director)
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		if (mIsFullScreen)
		{
			mGLView = GLViewImpl::createWithFullScreen("ZeteraChronicle");
		}
		else
		{
			auto designResolutionSize = GD->getScreenSize();
			mGLView = GLViewImpl::createWithRect("ZeteraChronicle", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
		}
#else
		aGLView = GLViewImpl::create("ZeteraChronicle");
#endif
	}

	director->setOpenGLView(mGLView);

	director->setDisplayStats(true);

	director->setAnimationInterval(1.0f / 60);

	if (!mIsFullScreen)
	{
		auto designResolutionSize = GD->getScreenSize();
		mGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
		auto frameSize = mGLView->getFrameSize();

		/*if (frameSize.height > mediumResolutionSize.height)
		{
			director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
		}
		else if (frameSize.height > smallResolutionSize.height)
		{
			director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
		}
		else
		{
			director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
		}*/
	}
}

void GameDirector::openScene()
{
	auto director = Director::getInstance();

	auto scene = HelloWorld::createScene();

	director->runWithScene(scene);
}



EncryptionFileManager* GameDirector::getEncryptionFileManager()
{
	CREATE_MANAGER(mEncryptionFileManager, EncryptionFileManager);
	return mEncryptionFileManager;
}