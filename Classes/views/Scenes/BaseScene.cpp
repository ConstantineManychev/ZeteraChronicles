#include "BaseScene.h"
//#include "BGameManager.h"
#include "Managers/GameDirector.h"


BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
}

/*void BaseScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event, const std::vector<cocos2d::EventKeyboard::KeyCode>& pressedKeys)
{
	Parent::onKeyPressed(keyCode, event, pressedKeys);

	if (!pressedKeys.empty() && (

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
		std::find(pressedKeys.begin(), pressedKeys.end(), cocos2d::EventKeyboard::KeyCode::KEY_HYPER) != pressedKeys.end()
#else
		std::find(pressedKeys.begin(), pressedKeys.end(), cocos2d::EventKeyboard::KeyCode::KEY_LEFT_CTRL) != pressedKeys.end()
		|| std::find(pressedKeys.begin(), pressedKeys.end(), cocos2d::EventKeyboard::KeyCode::KEY_CTRL) != pressedKeys.end()

		|| std::find(pressedKeys.begin(), pressedKeys.end(), cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_CTRL) != pressedKeys.end()
#endif
		))
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_1)
		{
			BValueMap params;
			params["screen_id"] = static_cast<int>( eScreenId::HOME );

			auto sm = BGM->getSceneManager();
			sm->openScene( "world_map", params);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_2)
		{
			auto sm = BGM->getSceneManager();
			sm->openScene("al_editor");

		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_3)
		{
			auto sm = BGM->getSceneManager();
			sm->openScene("test");

		}
	}
}

void BaseScene::update( float delta )
{
    Parent::update(delta);

	auto eventSystem = EVENTS_SYSTEM;

	if (eventSystem)
	{
		eventSystem->update(delta);
	}

    GCSWrapper::getInstance()->update(delta);
}*/
