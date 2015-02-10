#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

/*==================*\
||User command input||
\*==================*/
void CommandParser(string&, string&, string&);
void GameCore::Type1::CommandInput(unsigned short textColor, string &primeCommand, string &subCommand)
{
	ConsoleOperations ConOp;

	char tempArray[33];
	int tempInput = 0;
	short counter = 0;
	string tempCommand;
	primeCommand = "";
	subCommand = "";

	ConOp.SetColorText(textColor);
	ConOp.SetCursorCoords(11, 34);
	ConOp.SetDefaultCursorSize();

	for (counter = 0; counter < 33; counter++)
	{
		tempArray[counter] = 0;
	}
	
	counter = 0;
	while (1)
	{
		tempInput = _getch();
		if (tempInput == 0 || tempInput == 224)
		{
			tempInput = _getch();
			continue;
		}

		if (tempInput == 10 || tempInput == 9)
		{
			continue;
		}

		if (tempInput == 13)
		{
			tempCommand = tempArray;
			break;
		}
		
		if (tempInput == 8)
		{
			if (counter == 0)
			{
				continue;
			}
			counter--;
			tempInput = 0;
			ConOp.SetCursorCoords((11 + counter), 34);
			cout << " ";
			ConOp.SetCursorCoords((11 + counter), 34);
			tempArray[counter] = (char)tempInput;
			continue;
		}

		if (counter < 32)
		{
			tempArray[counter] = (char)tempInput;
			cout << tempArray[counter];
			counter++;
		}
	}
	CommandParser(tempCommand, primeCommand, subCommand);
	ConOp.SetCursorCoords(11, 34);
	cout << "                                   ";
}

void CommandParser(string &tempCommand, string &primeCommand, string &subCommand)
{
	string::iterator iterate;

	bool gotComma = false;
	char tempArray[33];
	int counter = 0;
	int i = 0;

	for (i = 0; i < 33; i++)
	{
		tempArray[i] = NULL;
	}

	counter = 0;
	for (iterate = tempCommand.begin(); iterate < tempCommand.end(); iterate++)
	{
		if (*iterate == '$' && *(iterate + 1) == '<')
		{
			iterate++;
		}
		if (*iterate == ',' && !gotComma)
		{
			primeCommand = tempArray;

			for (i = 0; i < counter; i++)
			{
				tempArray[i] = NULL;
			}

			gotComma = true;
			counter = 0;
			if ((iterate + 1) < tempCommand.end())
			{
				iterate++;
			}
			else
			{
				break;
			}

			while (*iterate == ' ' && (iterate + 1) < tempCommand.end())
			{
				iterate++;
			}
		}

		if (iterate != tempCommand.end())
		{
			tempArray[counter] = *iterate;
			counter++;
		}
	}

	if (gotComma)
	{
		subCommand = tempArray;
	}
	else
	{
		primeCommand = tempArray;
	}
}