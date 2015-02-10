#include <windows.h>
#include "ConsoleOperationsImp.h"

/*============================*\
||Constructors and Destructors||
\*============================*/

ConsoleOperationsImp::ConsoleOperationsImp()
{
	// Color storage //
	fgColorStore = (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	bgColorStore = 0;

	// Cursor storage //
	cursorCoordX = 0;
	cursorCoordY = 0;
	cursorSize = 25;

	// Screen storage //
	xScreen = 0;
	yScreen = 0;

	xScreenDefault = 0;
	yScreenDefault = 0;

	xScreenStore = 0;
	yScreenStore = 0;

	xScreenMax = 0;
	yScreenMax = 0;

	GetBuffer();
}

/*======================*\
||Clear Screen Functions||
\*======================*/

void ConsoleOperationsImp::ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };


	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;


	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
	hStdOut,
	(TCHAR) ' ',
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
	hStdOut,
	csbi.wAttributes,
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}

void ConsoleOperationsImp::ClearScreen(unsigned short bgColor)
{	
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };


	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;


	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
	hStdOut,
	(TCHAR) ' ',
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
	hStdOut,
	csbi.wAttributes,
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}



/*====================*\
||Defaulting functions||
\*====================*/

void ConsoleOperationsImp::SetDefaultColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void ConsoleOperationsImp::SetDefaultCursorSize()
{
	CONSOLE_CURSOR_INFO *cursePtr;
	CONSOLE_CURSOR_INFO conCurse;

	cursePtr = &conCurse;

	conCurse.bVisible = true;
	conCurse.dwSize = 25;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), cursePtr);
}

void ConsoleOperationsImp::SetDefaultScreenSize()
{
	SMALL_RECT DisplayArea = {0, 0, 0, 0};

	DisplayArea.Right = xScreenDefault;
	DisplayArea.Bottom = yScreenDefault;

	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &DisplayArea);
}



/*=======================*\
||Console color functions||
\*=======================*/

// --Get Color functions-- //
unsigned short ConsoleOperationsImp::GetColorCell()
{
	return bgColorStore;
}

unsigned short ConsoleOperationsImp::GetColorText()
{
	return fgColorStore;
}

// --Return Color functions-- //
void ConsoleOperationsImp::RetrieveColors(unsigned short &fgColor, unsigned short &bgColor)
{
	fgColor = fgColorStore;
	bgColor = bgColorStore;
}

// --Set Color functions-- //
void ConsoleOperationsImp::SetColor(unsigned short fgColor, unsigned short bgColor)
{
	unsigned short combinedColor;
	combinedColor = (fgColor | bgColor);

	fgColorStore = fgColor;
	bgColorStore = bgColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), combinedColor);
}

void ConsoleOperationsImp::SetColorCell(unsigned short bgColor)
{
	bgColorStore = bgColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor);
}

void ConsoleOperationsImp::SetColorText(unsigned short fgColor)
{
	fgColorStore = fgColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fgColor);
}



/*========================*\
||Console cursor functions||
\*========================*/

// --Get Cursor functions-- //
char ConsoleOperationsImp::GetCursorChar()
{
	char c = '\0';
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hCsbi = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hCsbi != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hCsbi, &csbi))
	{
		DWORD read = 0;
		if (!ReadConsoleOutputCharacterA(hCsbi, &c, 1, csbi.dwCursorPosition, &read) || read != 1)
		{
			c = '\0';
		}
	}
	return c;
}

short ConsoleOperationsImp::GetCursorSize()
{
	return cursorSize;
}

// --Return Cursor functions-- //
void ConsoleOperationsImp::RetrieveCursorCoords(short &x, short&y)
{
	x = cursorCoordX;
	y = cursorCoordY;
}

// --Set Cursor functions-- //
void ConsoleOperationsImp::SetCursorCoords(short x, short y)
{
	cursorCoordX = x;
	cursorCoordY = y;
	COORD coord = {x, y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleOperationsImp::SetCursorHome()
{
	cursorCoordX = 0;
	cursorCoordY = 0;
	COORD coord = {0, 0};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleOperationsImp::SetCursorSize(short size)
{
	cursorSize = size;

	CONSOLE_CURSOR_INFO *cursePtr;
	CONSOLE_CURSOR_INFO conCurse;

	cursePtr = &conCurse;
	conCurse.dwSize = size;
	conCurse.bVisible = true;

	if (size == 1)
	{
		conCurse.bVisible = false;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), cursePtr);
}



/*========================*\
||Console screen functions||
\*========================*/

// --Get Screen functions-- //
void ConsoleOperationsImp::GetBuffer()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	GetConsoleScreenBufferInfo(hOut, &csbi);

	xScreenDefault = csbi.srWindow.Right;
	yScreenDefault = csbi.srWindow.Bottom;
	xScreenMax = (csbi.dwMaximumWindowSize.X - 1);
	yScreenMax = (csbi.dwMaximumWindowSize.Y - 1);
}	

// --Return Screen cuntions-- //
void ConsoleOperationsImp::RetrieveScreenSize(short &xLength, short &yLength)
{
	xLength = xScreenStore;
	yLength = yScreenStore;
}

// --Set Screen functions-- //
void ConsoleOperationsImp::SetScreenSize(short xLength, short yLength)
{
	xScreen = xLength;
	yScreen = yLength;

	if (xLength == 0)
	{
		xScreen = xScreenMax;
	}
	if (yLength == 0)
	{
		yScreen = yScreenMax;
	}

	HANDLE hOut;
	SMALL_RECT DisplayArea = {0, 0, 0, 0};

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if(xScreen > xScreenMax)
	{
		xScreen = xScreenDefault;
	}
	else if(yScreen > yScreenMax)
	{
		yScreen = yScreenDefault;
	}
	
	xScreenStore = xScreen;
	yScreenStore = yScreen;

	DisplayArea.Right = xScreen;
	DisplayArea.Bottom = yScreen;
	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}
