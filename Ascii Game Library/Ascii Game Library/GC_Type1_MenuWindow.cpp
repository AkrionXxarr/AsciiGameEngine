#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

/*=================*\
|| Game Menu print ||
\*=================*/
void GameCore::Type1::SetMenu(int items, unsigned short menuColor, GameCore::Type1::MenuItems Menu)
{
	ConsoleOperations ConOp;
	ConOp.SetColorText(menuColor);

	int counter = 0;
	int titleLength = 0;

	items = (items * 2) - 1;
	titleLength = (Menu.MenuTitle.length() + 3);

	//////////////
	//Clear menu//
	//////////////
	for (counter = 0; counter < 33; counter++)
	{
		ConOp.SetCursorCoords(50, (2 + counter));
		for (int tempCounter = 0; tempCounter < 20; tempCounter++)
		{
			cout << " ";
		}
	}


	//////////////
	//Print menu//
	//////////////

	ConOp.SetCursorCoords(50, 2);
	cout << (char)218;
	for (counter = 0; counter < titleLength; counter++)
	{
		cout << (char)196;
	}
	ConOp.SetCursorCoords(50, 3);
	cout << (char)179;
	ConOp.SetCursorCoords(50, 4);
	cout << (char)195;
	for (counter = 0; counter < titleLength; counter++)
	{
		cout << (char)196;
	}
	ConOp.SetCursorCoords((50 + titleLength), 2);
	cout << (char)191;
	ConOp.SetCursorCoords((50 + titleLength), 3);
	cout << (char)179;
	ConOp.SetCursorCoords((50 + titleLength), 4);
	cout << (char)217;


	for (counter = 0; counter < items; counter++)
	{
		ConOp.SetCursorCoords(50, (5 + counter));
		if (counter % 2 != 0 && counter != 0)
		{
			cout << (char)195;
		}
		else
		{
			cout << (char)179;
		}
	}
	ConOp.SetCursorCoords(50, (5 + counter));
	cout << (char)192;

	ConOp.SetCursorCoords(52, 3);
	cout << Menu.MenuTitle;

	ConOp.SetCursorCoords(52, 6);
	cout << Menu.Item1_0;
	ConOp.SetCursorCoords(52, 8);
	cout << Menu.Item1_1;
	ConOp.SetCursorCoords(52, 10);
	cout << Menu.Item1_2;
	ConOp.SetCursorCoords(52, 12);
	cout << Menu.Item1_3;
	ConOp.SetCursorCoords(52, 14);
	cout << Menu.Item1_4;

	ConOp.SetCursorCoords(52, 16);
	cout << Menu.Item2_0;
	ConOp.SetCursorCoords(52, 18);
	cout << Menu.Item2_1;
	ConOp.SetCursorCoords(52, 20);
	cout << Menu.Item2_2;
	ConOp.SetCursorCoords(52, 22);
	cout << Menu.Item2_3;
	ConOp.SetCursorCoords(52, 24);
	cout << Menu.Item2_4;

	ConOp.SetCursorCoords(52, 26);
	cout << Menu.Item3_0;
	ConOp.SetCursorCoords(52, 28);
	cout << Menu.Item3_1;
	ConOp.SetCursorCoords(52, 30);
	cout << Menu.Item3_2;
	ConOp.SetCursorCoords(52, 32);
	cout << Menu.Item3_3;
	ConOp.SetCursorCoords(52, 34);
	cout << Menu.Item3_4;

}