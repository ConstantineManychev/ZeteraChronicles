#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

NS_CC_BEGIN
class  AppDelegate : private cocos2d::Application
{
private:

public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initGLContextAttrs();

	virtual bool applicationDidFinishLaunching();

	virtual void applicationDidEnterBackground();

	virtual void applicationWillEnterForeground();
};
NS_CC_END
#endif // _APP_DELEGATE_H_