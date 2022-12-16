#ifndef  _GAME_DIRECTOR_H_
#define  _GAME_DIRECTOR_H_

#include "cocos2d.h"
#include "Types/DataTypes.h"

NS_CC_BEGIN
enum class eGameAspectRatio
{
	_UNDEF = 0,
	_4X3,
	_16X9,
	_19_5X9,
	_14_4X9,
	_18X9,

	_21X9,
	_32X9
};

class EncryptionFileManager;

class  GameDirector
{
private:
	EncryptionFileManager* mEncryptionFileManager;


	cocos2d::GLView* mGLView;
	cocos2d::Size mScreenSize;
	bool mIsFullScreen;
	int mAppTime;

	//HWND mWindowsConsole;
	eGameAspectRatio mGameAspectRatio;
	cocos2d::Size mGameScreenSize;

private:
	GameDirector();

	void setScreenSize(cocos2d::Size& aSize);

	void GameDirector::updateWindowSize();

public:
	void onInit();

	virtual ~GameDirector();

	static GameDirector* getInstance();

	cocos2d::Size getScreenSize();
	void openScene();

	EncryptionFileManager* getEncryptionFileManager();
};

#define GD GameDirector::getInstance()

#define EFM GD->getEncryptionFileManager()

NS_CC_END
#endif // _GAME_DIRECTOR_H_