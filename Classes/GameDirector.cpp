#include "GameDirector.h"

GameDirector::GameDirector()
	: mGameAspectRatio(eGameAspectRatio::_UNDEF)
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

}