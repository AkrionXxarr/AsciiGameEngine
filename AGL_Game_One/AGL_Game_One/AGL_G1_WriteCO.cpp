#include "AGL_Include.h"

void WriteCO(string fileName)
{
	// Game Window setup //
	HANDLE hReadCO = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO chiBuffer[1518]; // [46][33];
	COORD chiBufferSize = {46, 33};
	COORD chiBufferCoord = {1, 2};
	SMALL_RECT srctEditWindow;
	
	srctEditWindow.Top = 2;
	srctEditWindow.Left = 1;
	srctEditWindow.Bottom = 32;
	srctEditWindow.Right = 45;
	///////////////////////////

	ifstream loadStream(fileName.c_str(), ios::binary);

	if (loadStream.fail())
	{
		loadStream.clear();

		SendGameMessage(FullRed, "File not found.");
	}
	else
	{
		loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

		WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);
	}

	loadStream.close();
}