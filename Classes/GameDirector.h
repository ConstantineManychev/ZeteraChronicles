#ifndef  _GAME_DIRECTOR_H_
#define  _GAME_DIRECTOR_H_

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
		eGameAspectRatio mGameAspectRatio;
		sSize mGameScreenSize;

	private:
		GameDirector();

	public:
		void onInit();

		virtual ~GameDirector();

		static GameDirector* getInstance();
	};

#define DM GameDirector::getInstance()

//}
#endif // _GAME_DIRECTOR_H_