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
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 80, 50 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}