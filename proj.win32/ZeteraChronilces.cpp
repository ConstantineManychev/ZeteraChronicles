#include "..\Classes\AppDelegate.h"

//namespace myGame {

	/*BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
	{
		return TRUE;
	}*/

	int main()
	{
		//SetConsoleCtrlHandler(CtrlHandler, TRUE);
		AppDelegate app;
		app.onInit();

		return 0;
	}

//}
