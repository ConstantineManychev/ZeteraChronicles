#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
private:
	void updateWindow(cocos2d::GLView* aGLView);

public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initGLContextAttrs();

	virtual bool applicationDidFinishLaunching();

	virtual void applicationDidEnterBackground();

	virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_