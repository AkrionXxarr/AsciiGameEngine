#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

void GameCore::Type1::PrintMapTest()
{
	ConsoleOperations ConOp;
	unsigned short mapTestArray[2][10][10];

	int x, y, z;

	for (z = 0; z < 2; z++)
	{
		for (x = 0; x < 10; x++)
		{
			for (y = 0; y < 10; y++)
			{
				if (z == 0)
				{
					mapTestArray[z][x][y] = 219;
				}
				else if (z == 1 && (x % 2) == 0 && (y % 2) == 0)
				{
					mapTestArray[z][x][y] = White;
				}
				else if (z == 1 && (x % 2) != 0 && (y % 2) != 0)
				{
					mapTestArray[z][x][y] = White;
				}
				else
				{
					mapTestArray[z][x][y] = FullRed;
				}
			}
		}
	}

	ConOp.SetCursorCoords(1, 2);

	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			ConOp.SetColorText(mapTestArray[1][x][y]);
			cout << (char)mapTestArray[0][x][y];
		}
		ConOp.SetCursorCoords(1, ((y + 1) + 2));
	}

}