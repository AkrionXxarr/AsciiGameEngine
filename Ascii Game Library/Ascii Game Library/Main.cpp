#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

#include "ConsoleOperations.h"
#include "GameCore.h"

void RunGame();

int main()
{
	string testMessage;
	ConsoleOperations Console;

	GameCore::Type1::GetUserInterface(FullBlue, White);
	GameCore::Type1::SendCharacterInfo(0, FullRed, "Testing. $<FullGreen> Some More.");
	GameCore::Type1::SendCharacterInfo(3, HalfGreen, "Line Four Testing.");
	GameCore::Type1::SendCharacterInfo(0, HalfBlue, "Testing.");
	GameCore::Type1::SendCharacterInfo(7, White, "Candy $<FullRed> Cane$<Default>.");
	RunGame();
	Console.SetCursorCoords(11, 34);

	return 0;
}


void RunMap();
void GameMap1();
void GameMap2();
void ClearMap();

void RunGame()
{
	string command1;
	string command2;
	string commandError;

	// Edit Window save setup //
	HANDLE hReadCO = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO chiBuffer[1518]; // [45][31];
	COORD chiBufferSize = {46, 33};
	COORD chiBufferCoord = {1, 2};
	SMALL_RECT srctEditWindow;
	
	srctEditWindow.Top = 2;
	srctEditWindow.Left = 1;
	srctEditWindow.Bottom = 32;
	srctEditWindow.Right = 45;
	///////////////////////////

	GameCore::Type1::SendGameMessage(HalfYellow, "Type '?' or 'Help' at any time for a list of commands\n"
												 "$<HalfRed> There is no 'enter' check to use the command line here."
												 "There will be once you load a map, so you can alternate between game "
												 "and command input.\n"
												 "All inputs are currently $<FullRed> Case Sensitive.");
	while (1)
	{
		GameCore::Type1::CommandInput(FullGreen, command1, command2);

		if (_stricmp(command1.c_str(), "CaseTesting") == 0)
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Case test success");
			continue;
		}

		if (command1 == "?" || command1 == "Help")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Commands: Quit | Load, <map name> | Map List | "
														 "Test, <Test Number> | Test List");
		}
		/*
		else if (command1 == "Load")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Usage: Load <map name>. See 'Map List' for a list of map names");
		}
		*/
		else if (command1 == "Map List")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Map list: Map1, Map2");
		}
		else if (command1 == "Test List")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Test list: One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Eleven, Twelve");
		}
		else if (command1 == "Load")
		{
			if (command2 == "Map1")
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Loading Map1...");
				GameMap1();
				RunMap();
			}
			else if (command2 == "Map2")
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Loading Map2...");
				GameMap2();
				RunMap();
			}
			else if (command2 == "Game")
			{
				RunMap();
			}
			else
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Usage: Load, <map name> || See 'Map List' for a list of map names");
			}
		}
		/*
		else if (command1 == "Load Map1")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Loading Map1...");
			GameMap1();
			RunMap();
		}
		else if (input == "Load Map2")
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "Loading Map2...");
			GameMap2();
			RunMap();
		}
		*/
		else if (command1 == "Test")
		{
			if (command2 == "One")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
														   "=================================================================="
													   	   "======================");
			}
			else if (command2 == "Two")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "This is a very long test string that I am writing so I can fully test"
														   "out my revamped word wrapping function. If I did everything correctly"
														   "This should work out fairly well. But I guess we shall see after I"
														   "compile this and run the compiled program.");
			}
			else if (command2 == "Three")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "Pneumonoultramicroscopicsilicovolcanoconiosis.");
			}
			else if (command2 == "Four")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "|||||||||||||||||||||||||||||||||||||||||||"
														   "Testing.");
			}
			else if (command2 == "Five")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "Testing |||||||||||||||||||||||||||||||||||||||||||||| "
														   "Some more testing. ||||||||||||||||||||||||||||||||||| "
														   "And some final testing.");
			}
			else if (command2 == "Six")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "I am now testing.. \n"
														   "To see if my return function.. \n"
														   "Works at all\n"
														   "Testing.");
			}
			else if (command2 == "Seven")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "==========================================/n"
														   "Testing.");
			}
			else if (command2 == "Eight")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "Here is a backslash n test \n"
														   "Testing.");
			}
			else if (command2 == "Nine")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "Bracket Testing $<Testing>\n"
														   "And some more testing \n"
														   "Space $<Testing>Test");
			}
			else if (command2 == "Ten")
			{
				GameCore::Type1::SendGameMessage(FullRed, "Color change test. $<FullGreen> Does it work? $<HalfPurple> Seems to. "
														  "$<HalfTeal> Well, how about defaulting? $<Default> Does it work? \n"
														  "$<White> It $<LightGray> Totally $<DarkGray> Does$<Default> !!!");
			}
			else if (command2 == "Eleven")
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "You have found a $<HalfPurple> Key$<Default> .");
			}
			else if (command2 == "Twelve")
			{
				GameCore::Type1::SendGameMessage(FullTeal, "Testing a string that is very very long. Longer than any other so far. "
														   "This is in order to push the string well past the length of the whole "
														   "message window. Long long long long string. Make it longer. Michael doesn't "
														   "think I'm typing enough. So I am going to type more because of this fact. "
														   "Message probably isn't nearly long enough, so still I continue to type. "
														   "Hopefully this works out, because this is alot of typing to do in order "
														   "to test out the functionality of stuff. One of these days I'll just copy "
														   "paste a novel into this so I can test it out much more easily. Anyway, now "
														   "I shall see if I have typed enough. \n"
														   "It would seem that yes, indeed I have typed plenty. Now lets try for two times. "
														   "I guess I can talk about how amazingly awesome Hraefn is. Or Siivyra. That works. "
														   "They are both the most awesomist people in the whole world. :D "
														   "Awesome Hrae + Awesome Vy = explosion of awesome. Siivyra is now looking at me "
														   "and reading what I am typing. Eventually she will catch up and say something along "
														   "the lines of 'oh you' .. Or she'll just stay quiet and snicker at me knowing that "
														   "I was most likely correct in my statement in an attempt to make my statement incorrect. "
														   "Alright, perhaps I have typed enough to make it onto a third message box page. "
														   "Lets try it out.");
			}
			else if (command2 == "Thirteen")
			{
				GameCore::Type1::PrintMapTest();
			}
			else if (command2 == "Fourteen")
			{
				ifstream readFile(".\\Maps\\Test Folder\\Map1.dat", ios::binary);
				readFile.read((char*)&chiBuffer, sizeof(chiBuffer));

				WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);
				readFile.close();

			}
			else if (command2 == "Fifteen")
			{
				ofstream makeFile(".\\FolderA\\FolderB\\Testing.txt");
				makeFile.close();
			}
			else
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Usage: Test, <Test Number> || See 'Test List' for a list of test numbers.");
			}
		}
		else if (command1 == "Quit")
		{
			break;
		}
		else
		{
			commandError = "Unknown Command: ";
			GameCore::Type1::SendGameMessage(FullRed, commandError.append(command1));
		}
	}
}


void RunMap()
{
	ConsoleOperations Console;

	short col = 44;
	short row = 4;

	int moveInput;

	string command1;
	string command2;
	string commandError;

	string mapArray[2][2] =
	{
		{"1-1", "1-2"},
		{"1-3", "1-4"}
	};

	string mapName;
	string mapNumber;

	short mapArrayCol = 0;
	short mapArrayRow = 0;

	// Edit Window save setup //
	HANDLE hReadCO = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO chiBuffer[1518]; // [45][31];
	COORD chiBufferSize = {46, 33};
	COORD chiBufferCoord = {1, 2};
	SMALL_RECT srctEditWindow;
	
	srctEditWindow.Top = 2;
	srctEditWindow.Left = 1;
	srctEditWindow.Bottom = 32;
	srctEditWindow.Right = 45;
	///////////////////////////

	mapName = ".\\Maps\\Map_";
	mapNumber = "";
	
	mapNumber = mapArray[mapArrayRow][mapArrayCol];
	mapNumber.append(".dat");
	mapName.append(mapNumber);

	ifstream loadStream(mapName.c_str(), ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

	loadStream.close();
	

	Console.SetColorText(FullPurple);
	Console.SetCursorCoords(col, row);
	cout << "@";

	while (1)
	{
		Console.SetColorText(FullPurple);
		Console.SetCursorSize(1);

		moveInput = _getch();

		if (moveInput == 13)
		{
			GameCore::Type1::CommandInput(FullGreen, command1, command2);

			if (command1 == "")
			{
				Console.SetCursorCoords(col, row);
				continue;
			}
			else if (command1 == "?" || command1 == "Help")
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Commands: Unload Map | Look, <Direction> (Directions are: North, East, South, West)"
															 " | Load, <Menu> | Menu List");
				Console.SetCursorCoords(col, row);
				continue;
			}
			else if (command1 == "Look")
			{
				if (command2 == "North")
				{
					Console.SetCursorCoords(col, row - 1);

					switch (Console.GetCursorChar())
					{
					case ' ':
						GameCore::Type1::SendGameMessage(HalfTeal, "You find nothing of interest.");
						break;
					case '#':
						GameCore::Type1::SendGameMessage(HalfTeal, "It is a door, but it's currently locked.");
						break;
					case 'o':
						GameCore::Type1::SendGameMessage(HalfTeal, "Looks to be a trash bin of some sort.");
						break;
					default:
						GameCore::Type1::SendGameMessage(HalfTeal, "A solid stone wall, there is nothing of interest.");
					}
				}
				else if (command2 == "East")
				{
					Console.SetCursorCoords(col + 1, row);

					switch (Console.GetCursorChar())
					{
					case ' ':
						GameCore::Type1::SendGameMessage(HalfTeal, "You find nothing of interest.");
						break;
					case '#':
						GameCore::Type1::SendGameMessage(HalfTeal, "It is a door, but it's currently locked.");
						break;
					case 'o':
						GameCore::Type1::SendGameMessage(HalfTeal, "Looks to be a trash bin of some sort.");
						break;
					default:
						GameCore::Type1::SendGameMessage(HalfTeal, "A solid stone wall, there is nothing of interest.");
					}
				}
				else if (command2 == "South")
				{
					Console.SetCursorCoords(col, row + 1);

					switch (Console.GetCursorChar())
					{
					case ' ':
						GameCore::Type1::SendGameMessage(HalfTeal, "You find nothing of interest.");
						break;
					case '#':
						GameCore::Type1::SendGameMessage(HalfTeal, "It is a door, but it's currently locked.");
						break;
					case 'o':
						GameCore::Type1::SendGameMessage(HalfTeal, "Looks to be a trash bin of some sort.");
						break;
					default:
						GameCore::Type1::SendGameMessage(HalfTeal, "A solid stone wall, there is nothing of interest.");
					}
				}
				else if (command2 == "West")
				{
					Console.SetCursorCoords(col - 1, row);

					switch (Console.GetCursorChar())
					{
					case ' ':
						GameCore::Type1::SendGameMessage(HalfTeal, "You find nothing of interest.");
						break;
					case '#':
						GameCore::Type1::SendGameMessage(HalfTeal, "It is a door, but it's currently locked.");
						break;
					case 'o':
						GameCore::Type1::SendGameMessage(HalfTeal, "Looks to be a trash bin of some sort.");
						break;
					default:
						GameCore::Type1::SendGameMessage(HalfTeal, "A solid stone wall, there is nothing of interest.");
					}
				}
				else
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Usage: Look, <Direction> (Directions in North, East, South, West)");
				}
				Console.SetCursorCoords(col, row);
				continue;
			}
			else if (command1 == "Menu List")
			{
				GameCore::Type1::SendGameMessage(HalfYellow, "Menu List: Menu1, Menu2, Menu3");
			}
			else if (command1 == "Unload Map")
			{
				ClearMap();
				break;
			}
			else
			{
				commandError = "Unknown Command: ";
				GameCore::Type1::SendGameMessage(FullRed, commandError.append(command1));
				Console.SetCursorCoords(col, row);
				continue;
			}
		}

		Console.SetCursorCoords(col, row);
		cout << " ";
		GameControl::Type1::CharMovement(col, row, moveInput);
		Console.SetCursorCoords(col, row);

		if (row < 2)
		{
			mapName = ".\\Maps\\Map_";
			mapNumber = "";
			mapArrayRow -= 1;

			mapNumber = mapArray[mapArrayRow][mapArrayCol];
			mapNumber.append(".dat");
			mapName.append(mapNumber);

			ifstream loadStream(mapName.c_str(), ios::binary);
			loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

			WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

			loadStream.close();

			row = 32;
			Console.SetCursorCoords(col, row);
			cout << "@";
		}
		else if (col > 45)
		{
			mapName = ".\\Maps\\Map_";
			mapNumber = "";
			mapArrayCol += 1;

			mapNumber = mapArray[mapArrayRow][mapArrayCol];
			mapNumber.append(".dat");
			mapName.append(mapNumber);

			ifstream loadStream(mapName.c_str(), ios::binary);
			loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

			WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

			loadStream.close();

			col = 1;
			Console.SetCursorCoords(col, row);
			cout << "@";
		}
		else if (row > 32)
		{
			mapName = ".\\Maps\\Map_";
			mapNumber = "";
			mapArrayRow += 1;

			mapNumber = mapArray[mapArrayRow][mapArrayCol];
			mapNumber.append(".dat");
			mapName.append(mapNumber);

			ifstream loadStream(mapName.c_str(), ios::binary);
			loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

			WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

			loadStream.close();

			row = 2;
			Console.SetCursorCoords(col, row);
			cout << "@";
		}
		else if (col < 1)
		{
			mapName = ".\\Maps\\Map_";
			mapNumber = "";
			mapArrayCol -= 1;

			mapNumber = mapArray[mapArrayRow][mapArrayCol];
			mapNumber.append(".dat");
			mapName.append(mapNumber);

			ifstream loadStream(mapName.c_str(), ios::binary);
			loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

			WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

			loadStream.close();

			col = 45;
			Console.SetCursorCoords(col, row);
			cout << "@";
		}
		else if (Console.GetCursorChar() != ' ')
		{
			GameControl::Type1::CharMovement(col, row, moveInput);
			Console.SetCursorCoords(col, row);
			cout << "@";
		}
		Console.SetCursorCoords(col, row);
		cout << "@";
	}
}

void GameMap1()
{
	short row = 0;
	short col = 0;
	ConsoleOperations Console;

	Console.SetColorText(HalfRed);

	col = 1;
	row = 2;

	for (col; col < 45; col++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row < 32; row++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (col; col > 1; col--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row > 2; row--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	col = 10;
	row = 10;
	for (col; col < 20; col++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row < 20; row++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (col; col > 10; col--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row > 10; row--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}

	Console.SetCursorCoords(15, 20);
	Console.SetColorText(FullRed);
	cout << "#";

	Console.SetCursorCoords(2, 3);
	Console.SetColorText(DarkGray);
	cout << "o";

	GameCore::Type1::SendGameMessage(HalfYellow, "Map1 loaded.");
}

void GameMap2()
{
	short row = 0;
	short col = 0;
	ConsoleOperations Console;

	Console.SetColorText(HalfRed);

	col = 1;
	row = 2;

	for (col; col < 45; col++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row < 32; row++)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (col; col > 1; col--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
	for (row; row > 2; row--)
	{
		Console.SetCursorCoords(col, row);
		cout << (char)178;
	}
}

void ClearMap()
{
	short col = 1;
	short row = 2;
	int counter = 0;
	ConsoleOperations Console;

	Console.SetCursorCoords(col, row);

	for (counter = 0; counter < 1395; counter++)
	{
		if (counter % 45 == 0 && counter != 0)
		{
			row++;
			Console.SetCursorCoords(col, row);
		}
		cout << " ";
	}

	/*for (row = 2; row < 33; row++)
	{
		for (col = 1; col < 46; col++)
		{
			Console.SetCursorCoords(col, row);
			cout << " ";
		}
	}*/
}