#ifndef  _GAME_DIRECTOR_H_
#define  _GAME_DIRECTOR_H_

#include "windows.h"
#include "Types/DataTypes.h"

//namespace myGame {

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
		sSize mDefaultScreenSize;
		int mAppTime;
		bool isCloseApp;

		HWND mWindowsConsole;
		eGameAspectRatio mGameAspectRatio;
		sSize mGameScreenSize;

	private:
		GameDirector();

		void setDefaultScreenSize(sSize& aSize);
		void setScreenSize(sSize& aSize);
		void setFullScreen(bool aIsFullScreen);

		void CenterWindow(HWND hwnd, HWND hwndCenter);

		void update(float aDelta);

	public:
		void onInit();

		virtual ~GameDirector();

		static GameDirector* getInstance();

		void Draw();

		void run();
	};

#define GD GameDirector::getInstance()

//}
#endif // _GAME_DIRECTOR_H_