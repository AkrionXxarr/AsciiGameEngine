#include <windows.h>
#include "ConsoleOperations.h"
#include "ConsoleOperationsImp.h"

/*============================*\
||Constructors and Destructors||
\*============================*/
ConsoleOperations::ConsoleOperations()
{
	ConOpImp = new ConsoleOperationsImp;
}

ConsoleOperations::~ConsoleOperations()
{
	delete ConOpImp;
}

/*======================*\
||Clear Screen Functions||
\*======================*/

void ConsoleOperations::ClearScreen()
{
	ConOpImp->ClearScreen();
}

void ConsoleOperations::ClearScreen(unsigned short bgColor)
{
	ConOpImp->ClearScreen(bgColor);
}



/*====================*\
||Defaulting functions||
\*====================*/

void ConsoleOperations::SetDefaultColor()
{
	ConOpImp->SetDefaultColor();
}

void ConsoleOperations::SetDefaultCursorSize()
{
	ConOpImp->SetDefaultCursorSize();
}

void ConsoleOperations::SetDefaultScreenSize()
{
	ConOpImp->SetDefaultScreenSize();
}



/*=======================*\
||Console Color functions||
\*=======================*/

// --Get Color functions-- //
unsigned short ConsoleOperations::GetColorCell()
{
	return ConOpImp->GetColorCell();
}

unsigned short ConsoleOperations::GetColorText()
{
	return ConOpImp->GetColorText();
}

// --Return Color functions-- //
void ConsoleOperations::RetrieveColors(unsigned short &fgColor, unsigned short &bgColor)
{
	ConOpImp->RetrieveColors(fgColor, bgColor);
}



// --Set Color functions-- //
void ConsoleOperations::SetColor(unsigned short fgColor, unsigned short bgColor)
{
	bgColor = bgColor * 0x0010;
	ConOpImp->SetColor(fgColor, bgColor);
}

void ConsoleOperations::SetColorCell(unsigned short bgColor)
{
	bgColor = bgColor * 0x0010;
	ConOpImp->SetColorCell(bgColor);
}

void ConsoleOperations::SetColorText(unsigned short fgColor)
{
	ConOpImp->SetColorText(fgColor);
}



/*========================*\
||Console Cursor functions||
\*========================*/

// --Get Cursor functions-- //
char ConsoleOperations::GetCursorChar()
{
	return ConOpImp->GetCursorChar();
}

short ConsoleOperations::GetCursorSize()
{
	return ConOpImp->GetCursorSize();
}

// --Return Cursor functions-- //
void ConsoleOperations::RetrieveCursorCoords(short &x, short &y)
{
	ConOpImp->RetrieveCursorCoords(x, y);
}



// --Set Cursor functions-- //
void ConsoleOperations::SetCursorCoords(short x, short y)
{
	ConOpImp->SetCursorCoords(x, y);
}

void ConsoleOperations::SetCursorHome()
{
	ConOpImp->SetCursorHome();
}

void ConsoleOperations::SetCursorSize(short size)
{
	ConOpImp->SetCursorSize(size);
}

/*========================*\
||Console Screen functions||
\*========================*/

// --Return Screen functions-- //
void ConsoleOperations::RetrieveScreenSize(short &xLength, short &yLength)
{
	ConOpImp->RetrieveScreenSize(xLength, yLength);
}



// --Set Screen functions-- //
void ConsoleOperations::SetScreenSize(short xLength, short yLength)
{
	ConOpImp->SetScreenSize(xLength, yLength);
}
