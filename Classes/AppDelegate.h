#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

namespace cocos2d {

class  AppDelegate
{
private:

private:

public:
	void onInit();

	AppDelegate();
	virtual ~AppDelegate();
};

#define AD AppDelegate::getInstance()

}

#endif // _APP_DELEGATE_H_