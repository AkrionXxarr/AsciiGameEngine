#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

unsigned short StringColorCheck(unsigned short, string);

void GameCore::Type1::SendCharacterInfo(unsigned short lineNumber, unsigned short textColor, string message)
{
	// Character box home coords are:   //
	// Row 38, Column 49                //
	// Character box dimensions are:    //
	// 23 cells across, 15 down         //

	ConsoleOperations ConOp;
	string::iterator iterate;

	string colorChange;

	ConOp.SetColorText(textColor);

	ConOp.SetCursorCoords(49, (38 + lineNumber));
	cout << "                       ";
	ConOp.SetCursorCoords(49, (38 + lineNumber));
	for (iterate = message.begin(); iterate < message.end(); iterate++)
	{
		if (*iterate == '$' && *(iterate + 1) == '<')
		{
			colorChange.clear();
			iterate++;
			while (*iterate != '>')
			{
				colorChange.append(1, *iterate);
				iterate++;
			}
			colorChange.append(1, *iterate);

			if (*(iterate + 1) == ' ')
			{
				iterate++;
			}

			ConOp.SetColorText(StringColorCheck(textColor, colorChange));

			continue;
		}
		cout << *iterate;
	}
}