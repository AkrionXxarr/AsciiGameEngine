#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

					       /*===================*\
|*=========================|| Message box print ||=========================*|
|*=========================**===================**=========================*|
|| ** Prints a message to the message box, complete with word wrapping. ** ||
||																		   ||
||						      -- Word Wrap --							   ||
|| Word wrapping is done by counting the characters in a word,			   ||
|| resetting the counter for each time the iterator returns a space.	   ||
||																		   ||
|| - The word wrapping function must account for:						   ||
|| * Are we at the end of the line? If so; New Line.					   ||
|| * Are we in the middle of a word, and at the end of the line?		   ||
||   If so; erase the reminents of the word, New Line, print again		   ||
||   from the beginning of the word.									   ||
|| * Is the word as long as the line, or, are we starting a new word?	   ||
||   If so; charCounter mod 43 == 0. New Line and continue printing.	   ||
|| * Is the word longer than half the line? If so; do not erase and		   ||
||   re-print. Instead, New Line and continue printing.					   ||
||																		   ||
\*=========================================================================*/

unsigned short StringColorCheck(unsigned short, string);

void GameCore::Type1::SendGameMessage(unsigned short textColor, string message)
{
	// Message box home coords are: //
	// Row 38, Column 2             //
	// MEssage box dimensions are:  //
	// 43 cells across, 15 down     //
	ConsoleOperations ConOp;
	string::iterator iterate;

	string::iterator itBase;
	string::iterator itPtr;

	string colorChange;

	unsigned short cellCounter = 0;
	unsigned short charCounter = 0;

	unsigned short totalCounter = 0;
	unsigned short lineCounter = 0;

	unsigned short testCounter = 0;
	unsigned short counter = 0;

	short col = 2;
	short row = 38;

	ConOp.SetColorText(textColor);
	ConOp.SetCursorCoords(col, row);
	ConOp.SetCursorSize(1);

	// Clear the entire message box //
	for (cellCounter = 0; cellCounter < 645; cellCounter++)
	{
		if (cellCounter % 43 == 0 && cellCounter != 0)
		{
			row++;
			ConOp.SetCursorCoords(col, row);
		}
		cout << " ";
	}

	// Reset back to 'home' //
	cellCounter = 0;
	row = 38;
	ConOp.SetCursorCoords(col, row);

	counter = 0;
	//iterate = message.begin();

	bool lineReturn = false;
	while (1)
	{	
		iterate = message.begin();
		iterate += totalCounter;
		while (iterate < message.end() && lineCounter < 43)
		{
			if (*iterate == '\n')
			{
				iterate++;
				totalCounter++;
				lineReturn = true;
				break;
			}
			else if (*iterate == '$' && *(iterate + 1) == '<')
			{
				iterate++;
				totalCounter++;
				while (*iterate != '>')
				{
					iterate++;
					totalCounter++;
				}
			}

			iterate++;
			lineCounter++;
			totalCounter++;
		}

		if (lineReturn)
		{
			lineCounter = 0;
			lineReturn = false;
			continue;
		}

		if (iterate == message.end())
		{
			break;
		}

		itPtr = iterate;

		while (*itPtr != ' ' && counter < 43)
		{
			itPtr--;
			totalCounter--;
			counter++;
		}
		if (counter == 43)
		{
			itPtr = iterate;
		}
		else
		{
			itPtr++;
			totalCounter++;
		}
		message.insert(itPtr, 1, '\n');
		totalCounter++;
		counter = 0;
		lineCounter = 0;
	}

	unsigned short rowCounter = 0;
	short clearRow = 38;
	int input = 0;

	// Begin printing the provided message into the message box //
	for (iterate = message.begin(); iterate < message.end(); iterate++)
	{
		// Check for "\n" and return to the next line if the case is true //
		if (*iterate == '\n')
		{
			iterate++;
			cellCounter = 0;
			row++;
			rowCounter++;
			ConOp.SetCursorCoords(col, row);
		}


		if (rowCounter == 14)
		{
			ConOp.SetCursorCoords(20, row);
			cout << "<Enter>";
			while (1)
			{
				if (_kbhit())
				{
					input = _getch();
					while (_kbhit())
					{
						input = _getch();
						if (input == 13)
						{
							break;
						}
					}
					if (input == 13)
					{
						break;
					}
				}

				ConOp.SetCursorCoords(18, row);
				cout << (char)25;
				ConOp.SetCursorCoords(28, row);
				cout << (char)25;

				Sleep(500);
				if (_kbhit())
				{
					input = _getch();
					while (_kbhit())
					{
						input = _getch();
						if (input == 13)
						{
							break;
						}
					}
					if (input == 13)
					{
						break;
					}
				}
				
				ConOp.SetCursorCoords(18, row);
				cout << " ";
				ConOp.SetCursorCoords(28, row);
				cout << " ";
				Sleep(500);
			}

			ConOp.SetCursorCoords(col, clearRow);
			for (cellCounter = 0; cellCounter < 645; cellCounter++)
			{
				if (cellCounter % 43 == 0 && cellCounter != 0)
				{
					clearRow++;
					ConOp.SetCursorCoords(col, clearRow);
				}
				cout << " ";
			}
			input = 0;
			rowCounter = 0;
			clearRow = 38;
			row = 38;
			ConOp.SetCursorCoords(col, row);
		}

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

unsigned short StringColorCheck(unsigned short Default, string Color)
{
	if		(Color == "<Default>"    || Color == "<Dflt>"){ return Default;    }
	else if (Color == "<Black>"      || Color == "<Blk>" ){ return Black;      }
	else if (Color == "<DarkGray>"   || Color == "<DG>"  ){ return DarkGray;   }
	else if (Color == "<HalfBlue>"   || Color == "<HB>"  ){ return HalfBlue;   }
	else if (Color == "<FullBlue>"   || Color == "<FB>"  ){ return FullBlue;   }
	else if (Color == "<HalfGreen>"  || Color == "<HG>"  ){ return HalfGreen;  }
	else if (Color == "<FullGreen>"  || Color == "<FG>"  ){ return FullGreen;  }
	else if (Color == "<HalfRed>"    || Color == "<HR>"  ){ return HalfRed;    }
	else if (Color == "<FullRed>"    || Color == "<FR>"  ){ return FullRed;    }
	else if (Color == "<HalfTeal>"   || Color == "<HT>"  ){ return HalfTeal;   }
	else if (Color == "<FullTeal>"   || Color == "<FT>"  ){ return FullTeal;   }
	else if (Color == "<HalfPurple>" || Color == "<HP>"  ){ return HalfPurple; }
	else if (Color == "<FullPurple>" || Color == "<FP>"  ){ return FullPurple; }
	else if (Color == "<HalfYellow>" || Color == "<HY>"  ){ return HalfYellow; }
	else if (Color == "<FullYellow>" || Color == "<FY>"  ){ return FullYellow; }
	else if (Color == "<LightGray>"  || Color == "<LG>"  ){ return LightGray;  }
	else if (Color == "<White>"      || Color == "<Wht>" ){ return White;      }
	else    /*---------------------------------------> */ { return 0;          }
}