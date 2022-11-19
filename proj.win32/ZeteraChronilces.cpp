#include <iostream>
#include <windows.h>

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	return TRUE;
}

int main()
{
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
    std::cout << "Hello World!\n";

	return 0;
}
