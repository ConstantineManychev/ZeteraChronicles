#ifndef  _GAME_DIRECTOR_H_
#define  _GAME_DIRECTOR_H_

#include "windows.h"
#include "cocos2d.h"
#include "Types/DataTypes.h"

namespace cocos2d {

enum class eGameAspectRatio
{
	_UNDEF = 0,
	_4X3,
	_16X9,
	_19_5X9,
	_14_4X9,
	_18X9
};

class  GameDirector
{
private:
	Size mDefaultScreenSize;
	int mAppTime;
	bool isCloseApp;

	HWND mWindowsConsole;
	eGameAspectRatio mGameAspectRatio;
	Size mGameScreenSize;

private:
	GameDirector();

	void setDefaultScreenSize(Size& aSize);
	void setScreenSize(Size& aSize);
	void setFullScreen(bool aIsFullScreen);

	void update(float aDelta);

public:
	void onInit();

	virtual ~GameDirector();

	static GameDirector* getInstance();

	void Draw();

	void run();
};

#define GD GameDirector::getInstance()

}
#endif // _GAME_DIRECTOR_H_