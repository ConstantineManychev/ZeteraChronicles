#include "GameDirector.h"
#include "AppDelegate.h"
#include "Types/DataTypes.h"


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
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	mWindowsConsole = GetConsoleWindow();
#endif

	sSize defaultScreenSize;
	defaultScreenSize.width = GetSystemMetrics(SM_CXSCREEN);
	defaultScreenSize.height = GetSystemMetrics(SM_CYSCREEN);

	AD->setDefaultScreenSize(defaultScreenSize);

	setScreenSize(defaultScreenSize);
	setFullScreen(true);
}

void GameDirector::setScreenSize(sSize& aSize)
{
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	//MoveWindow(mWindowsConsole, 0, 0, aSize.width, aSize.height, TRUE);
	//SetWindowPos(mWindowsConsole, NULL, 0, 0, aSize.width, aSize.height, SWP_NOZORDER);
	//CenterWindow(mWindowsConsole);
#endif
}

void GameDirector::setFullScreen(bool aIsFullScreen)
{
#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32)
	if (aIsFullScreen)
	{
		//system("mode 650");
		//SetConsoleDisplayMode(mWindowsConsole, CONSOLE_FULLSCREEN_MODE, 0);
		SendMessage(mWindowsConsole, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	}
	else
	{
		//SetConsoleDisplayMode(mWindowsConsole, CONSOLE_WINDOWED_MODE, 0);
		ShowWindow(mWindowsConsole, SW_MAXIMIZE);
		//SendMessage(mWindowsConsole, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	}
#endif
}

void GameDirector::Draw()
{

}

void GameDirector::CenterWindow(HWND hwnd, HWND hwndCenter)
{
	// Determine owner window to center against.
	DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
	if (hwndCenter == NULL)
	{
		if (dwStyle & WS_CHILD)
			hwndCenter = GetParent(hwnd);
		else
			hwndCenter = GetWindow(hwnd, GW_OWNER);
	}

	// Get coordinates of the window relative to its parent.
	RECT rcDlg;
	GetWindowRect(hwnd, &rcDlg);
	RECT rcArea;
	RECT rcCenter;
	HWND hwndParent;
	if ((dwStyle & WS_CHILD) == 0)
	{
		// Don't center against invisible or minimized windows.
		if (hwndCenter != NULL)
		{
			DWORD dwStyleCenter = GetWindowLong(hwndCenter, GWL_STYLE);
			if (!(dwStyleCenter & WS_VISIBLE) || (dwStyleCenter & WS_MINIMIZE))
				hwndCenter = NULL;
		}

		// Center within screen coordinates.
		SystemParametersInfo(SPI_GETWORKAREA, NULL, &rcArea, NULL);
		if (hwndCenter == NULL)
			rcCenter = rcArea;
		else
			GetWindowRect(hwndCenter, &rcCenter);
	}
	else
	{
		// Center within parent client coordinates.
		hwndParent = GetParent(hwnd);
		GetClientRect(hwndParent, &rcArea);
		GetClientRect(hwndCenter, &rcCenter);
		MapWindowPoints(hwndCenter, hwndParent, (POINT*)&rcCenter, 2);
	}

	int nDlgWidth = rcDlg.right - rcDlg.left;
	int nDlgHeight = rcDlg.bottom - rcDlg.top;

	// Find dialog's upper left based on rcCenter.
	int xLeft = (rcCenter.left + rcCenter.right) / 2 - nDlgWidth / 2;
	int yTop = (rcCenter.top + rcCenter.bottom) / 2 - nDlgHeight / 2;

	// If the dialog is outside the screen, move it inside.
	if (xLeft < rcArea.left)
		xLeft = rcArea.left;
	else if (xLeft + nDlgWidth > rcArea.right)
		xLeft = rcArea.right - nDlgWidth;

	if (yTop < rcArea.top)
		yTop = rcArea.top;
	else if (yTop + nDlgHeight > rcArea.bottom)
		yTop = rcArea.bottom - nDlgHeight;

	// Map screen coordinates to child coordinates.
	SetWindowPos(hwnd, NULL, xLeft, yTop, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}