#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

void GameControl::Type1::CharMovement(short &col, short &row, int &input)
{
	if (input == 0 || input == 224 || input == 327 || input == 335 || input == 332 || input == 330)
	{
		if (input == 224 || input == 0)
		{
			input = _getch();
		}

		switch (input)
		{
		case 72:
		case 80:
		case 77:
		case 75:
			input += 255;
			break;

		case 327:
		case 335:
		case 332:
		case 330:
			break;

		default:
			input = 0;
			break;
		}

		switch (input)
		{
		case 327:
			row--;
			input = 335;
			break;
		case 335:
			row++;
			input = 327;
			break;
		case 332:
			col++;
			input = 330;
			break;
		case 330:
			col--;
			input = 332;
			break;
		}
	}
}