#include "..\Classes\AppDelegate.h"

//namespace myGame {

	/*BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
	{
		return TRUE;
	}*/

	int main()
	{
		//SetConsoleCtrlHandler(CtrlHandler, TRUE);
		AD->onInit();
		AD->run();

		return 0;
	}

//}
