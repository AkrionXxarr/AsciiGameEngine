#include "AGL_Include.h"
#include "AGL_G1_Functions.h"


bool DirectionCheck(short X, short Y, short &xCoordCheck, short &yCoordCheck, string subCommand);
bool PlayCommandCheck(string primeCommand);
void MainMenu();

void RunGame()
{
	ConsoleOperations Console;

	int input = 0;

	Inventory InvItems;

	short mapArrayRow = 0;
	short mapArrayCol = 0;

	short X = 0;
	short Y = 0;
	short xCoordCheck = 0;
	short yCoordCheck = 0;

	string primeCommand;
	string subCommand;

	string mapArray[3][3] =
	{
		{"1-1", "1-2", "1-5"},
		{"1-6", "1-3", "1-4"},
		{"1-7", "1-8", "1-9"}
	};

	string mapDir;
	string mapExt;
	string mapName;
	string mapLoad;

	// File path setup //
	mapDir = ".\\Maps\\Map_";
	mapExt = ".dat";
	mapName = mapArray[mapArrayRow][mapArrayCol];
	mapLoad = mapDir.append(mapName.append(mapExt));
	// --------------- //

	// InvItems ID initialization //
	InvItems.slot1_ID = 0x00;
	InvItems.slot2_ID = 0x00;
	InvItems.slot3_ID = 0x00;
	InvItems.slot4_ID = 0x00;
	InvItems.slot5_ID = 0x00;
	InvItems.slot6_ID = 0x00;
	InvItems.slot7_ID = 0x00;
	InvItems.slot8_ID = 0x00;
	InvItems.slot9_ID = 0x00;
	InvItems.slot10_ID = 0x00;
	InvItems.slot11_ID = 0x00;
	InvItems.slot12_ID = 0x00;
	// --------------------------- //

	WriteCO(mapLoad);
	MainMenu();

	X = 23;
	Y = 16;
	xCoordCheck = X;
	yCoordCheck = Y;

	Console.SetCursorCoords(X, Y);
	Console.SetCursorSize(1);
	Console.SetColorText(HalfPurple);
	cout << "@";

	while (1)
	{
		input = _getch();

		if (input == 13)
		{
			CommandInput(FullGreen, primeCommand, subCommand);

			if (PlayCommandCheck(primeCommand))
			{
				if (DirectionCheck(X, Y, xCoordCheck, yCoordCheck, subCommand))
				{
					MainDatabase(xCoordCheck, yCoordCheck, primeCommand, mapLoad, mapArray[mapArrayRow][mapArrayCol], InvItems);
					WriteCO(mapLoad);
				}
			}
			else if (_stricmp(primeCommand.c_str(), "Redraw") == 0)
			{
				if (subCommand == "test1")
				{
					WriteCO(mapLoad);
				}
				else if (subCommand == "test2")
				{
					WriteCO(".\\Maps\\Reference Maps\\RefMap_1-1.dat");
					WriteCO(mapLoad);
					
				}
			}
			else if (_stricmp(primeCommand.c_str(), "Inventory") == 0 || _stricmp(primeCommand.c_str(), "Inv") == 0)
			{
				GetInventory(InvItems);
				SendGameMessage(HalfRed, "Inventory opened."
										 " \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");
				WriteCO(mapLoad);
			}
			else if (_stricmp(primeCommand.c_str(), "Example") == 0)
			{
				SendGameMessage(FullGreen, "Example text showing off $<HalfRed> The workings of the message box "
										   "using this engine. $<FullBlue> It can change colors mid-text via use of these brackets. "
										   "$<Default> And easily return to its original color.");
			}

			Console.SetCursorSize(1);
			Console.SetColorText(HalfPurple);
			Console.SetCursorCoords(X, Y);
			cout << "@";

			continue;
		}

		Console.SetCursorCoords(X, Y);
		cout << " ";

		GameControl::Type1::CharMovement(X, Y, input);
		Console.SetCursorCoords(X, Y);

		if (X > 45 || Y > 32 || X < 1 || Y < 2)
		{
			if (X > 45)
			{
				X = 1;
				mapArrayCol++;
			}
			else if (Y > 32)
			{
				Y = 2;
				mapArrayRow++;
			}
			else if (X < 1)
			{
				X = 45;
				mapArrayCol--;
			}
			else if (Y < 2)
			{
				Y = 32;
				mapArrayRow--;
			}

			mapDir = ".\\Maps\\Map_";
			mapExt = ".dat";
			mapName = mapArray[mapArrayRow][mapArrayCol];
			mapLoad = mapDir.append(mapName.append(mapExt));

			WriteCO(mapLoad);
			Console.SetCursorCoords(X, Y);
			cout << "@";
		}
		else if (Console.GetCursorChar() == ' ')
		{
			cout << "@";
		}
		else
		{
			GameControl::Type1::CharMovement(X, Y, input);
			Console.SetCursorCoords(X, Y);
			cout << "@";
		}
	}
}

bool DirectionCheck(short X, short Y, short &xCheck, short &yCheck, string subCommand)
{
	if (_stricmp(subCommand.c_str(), "North") == 0 || _stricmp(subCommand.c_str(), "N") == 0)
	{
		yCheck = Y - 1;
		xCheck = X;
		return true;
	}
	else if (_stricmp(subCommand.c_str(), "East") == 0 || _stricmp(subCommand.c_str(), "E") == 0)
	{
		yCheck = Y;
		xCheck = X + 1;
		return true;
	}
	else if (_stricmp(subCommand.c_str(), "South") == 0 || _stricmp(subCommand.c_str(), "S") == 0)
	{
		yCheck = Y + 1;
		xCheck = X;
		return true;
	}
	else if (_stricmp(subCommand.c_str(), "West") == 0 || _stricmp(subCommand.c_str(), "W") == 0)
	{
		yCheck = Y;
		xCheck = X - 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayCommandCheck(string primeCommand)
{
	if (_stricmp(primeCommand.c_str(), "Look") == 0)
	{
		return true;
	}
	else if (_stricmp(primeCommand.c_str(), "Open") == 0)
	{
		return true;
	}
	else if (_stricmp(primeCommand.c_str(), "Take") == 0)
	{
		return true;
	}
	else if (_stricmp(primeCommand.c_str(), "Unlock") == 0)
	{
		return true;
	}
	else if (_stricmp(primeCommand.c_str(), "Use") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MainMenu()
{
	MenuItems MainMenu;

	MainMenu.MenuTitle = "Game Commands";

	MainMenu.Item1_0 = "Look";
	MainMenu.Item1_1 = "Open";
	MainMenu.Item1_2 = "Take";
	MainMenu.Item1_3 = "Unlock";
	MainMenu.Item1_4 = "Use";

	MainMenu.Item2_0 = "(Inv)entory";

	MainMenu.Item2_1 = "Hello";
	MainMenu.Item2_2 = "World";

	GameCore::Type1::SetMenu(8, White, MainMenu);
}

