#include "AGL_Include.h"
#include "AGL_G1_Functions.h"

void Database1_2(short xCoordCheck, short yCoordCheck, char character, unsigned short attribute, string primeCommand, CHAR_INFO *chiBuffer, Inventory &InvItems)
{

	ConsoleOperations Console;

	int i = ((46 * yCoordCheck) + xCoordCheck);	

	Console.SetCursorCoords(0, 60);
	cout << "          ";
	Console.SetCursorCoords(0, 60);
	cout << i;

	if (character == (char)6) // (spade)
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "It's a spade.");
		}
		else if (_stricmp(primeCommand.c_str(), "Use") == 0)
		{
			chiBuffer[i].Attributes = (White);

			chiBuffer[236].Char.AsciiChar = ' ';

			SendGameMessage(HalfRed, "You activate the switch.");
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that.");
		}
	}
	else if (character == (char)20) // ¶
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			switch (i)
			{
			case 234:
				SendGameMessage(HalfRed, "Key 3");
				break;

			case 1067:
				SendGameMessage(HalfRed, "Key 1");
				break;

			case 1416:
				SendGameMessage(HalfRed, "Key 2");
				break;
			}
		}
		else if (_stricmp(primeCommand.c_str(), "Take") == 0)
		{
			switch (i)
			{
			case 234:
				InvItems.S1_L1 = "Key 3";
				InvItems.slot1_ID = 0x05;

				chiBuffer[i].Char.AsciiChar = ' ';

				SendGameMessage(HalfRed, "You took the key.");
				break;

			case 1067:
				InvItems.S1_L1 = "Key 1";
				InvItems.slot1_ID = 0x03;

				chiBuffer[i].Char.AsciiChar = ' ';

				SendGameMessage(HalfRed, "You took the key.");
				break;
				
			case 1416:
				InvItems.S1_L1 = "Key 2";
				InvItems.slot1_ID = 0x04;

				chiBuffer[i].Char.AsciiChar = ' ';

				SendGameMessage(HalfRed, "You took the key.");
				break;
			}
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that.");
		}
	}
	else if (character == (char)232)
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "It's a shield");
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that");
		}
	}
	else if (character == '#')
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			if (attribute == (FullRed))
			{
				SendGameMessage(HalfRed, "It's a locked door.");
			}
			else if (attribute == (FullGreen))
			{
				SendGameMessage(HalfRed, "It's an unlocked door.");
			}
		}
		else if (_stricmp(primeCommand.c_str(), "Open") == 0)
		{
			if (attribute == (FullRed))
			{
				SendGameMessage(HalfRed, "The door is locked, you are unable to open it. ");
			}
			else if (attribute == (FullGreen))
			{			
				chiBuffer[i].Char.AsciiChar = ' ';

				SendGameMessage(HalfRed, "You opened the door.");
			}
		}
		else if (_stricmp(primeCommand.c_str(), "Unlock") == 0)
		{
			if (attribute == (FullRed))
			{
				switch (i)
				{
				case 395:
					if (InvItems.slot1_ID == 0x03)
					{
						InvItems.slot1_ID = 0x00;
						InvItems.S1_L1 = "";

						chiBuffer[i].Attributes = FullGreen;
						SendGameMessage(HalfRed, "Door unlocked.");
					}
					else
					{
						SendGameMessage(HalfRed, "You need the proper key to unlock this door. ");
					}
					break;

				case 1204:
					if (InvItems.slot1_ID == 0x04)
					{
						InvItems.slot1_ID = 0x00;
						InvItems.S1_L1 = "";

						chiBuffer[i].Attributes = FullGreen;
						SendGameMessage(HalfRed, "Door unlocked.");
					}
					else
					{
						SendGameMessage(HalfRed, "You need the proper key to unlock this door. ");
					}
				}
			}
			else if (attribute == (FullGreen))
			{
				SendGameMessage(HalfRed, "The door is already unlocked.");
			}
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that.");
		}
	}
	else if (i == 403 || i == 404)
	{
		short aniRate = 500;
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "It's a control panel. ");
		}
		else if (_stricmp(primeCommand.c_str(), "Use") == 0 && chiBuffer[403].Attributes == (FullPurple))
		{
			SendGameMessage(HalfRed, "The water moves.");

			// Switch change
			chiBuffer[403].Attributes = HalfPurple;
			chiBuffer[404].Attributes = FullPurple;

			/////////////////////
			// Animation Begin //
			/////////////////////

			// Frame One
			Console.SetColorText(DarkGray);
			Console.SetCursorCoords(34, 20);
			cout << (char)177;
			Console.SetCursorCoords(37, 20);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(28, 21);
			cout << (char)178;
			Console.SetCursorCoords(43, 21);
			cout << (char)178;
			
			Sleep(aniRate);

			// Frame Two
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 21);
			cout << (char)177;
			Console.SetCursorCoords(37, 21);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(30, 20);
			cout << (char)178;
			Console.SetCursorCoords(41, 20);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Three
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 22);
			cout << (char)177;
			Console.SetCursorCoords(37, 22);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(29, 20);
			cout << (char)178;
			Console.SetCursorCoords(42, 20);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Four
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 23);
			cout << (char)177;
			Console.SetCursorCoords(37, 23);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(28, 20);
			cout << (char)178;
			Console.SetCursorCoords(43, 20);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Five
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 24);
			cout << (char)177;
			Console.SetCursorCoords(37, 24);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(33, 19);
			cout << (char)178;
			Console.SetCursorCoords(38, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Six
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 25);
			cout << (char)177;
			Console.SetCursorCoords(37, 25);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(32, 19);
			cout << (char)178;
			Console.SetCursorCoords(39, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Seven
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 26);
			cout << (char)177;
			Console.SetCursorCoords(37, 26);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(31, 19);
			cout << (char)178;
			Console.SetCursorCoords(40, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Eight
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(34, 27);
			cout << (char)177;
			Console.SetCursorCoords(37, 27);
			cout << (char)177;

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(30, 19);
			cout << (char)178;
			Console.SetCursorCoords(41, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Nine
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 20);
			cout << ' ';
			Console.SetCursorCoords(36, 20);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(29, 19);
			cout << (char)178;
			Console.SetCursorCoords(42, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Ten
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 21);
			cout << ' ';
			Console.SetCursorCoords(36, 21);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(28, 19);
			cout << (char)178;
			Console.SetCursorCoords(43, 19);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Eleven
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 22);
			cout << ' ';
			Console.SetCursorCoords(36, 22);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(33, 18);
			cout << (char)178;
			Console.SetCursorCoords(38, 18);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Twelve
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 23);
			cout << ' ';
			Console.SetCursorCoords(36, 23);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(32, 18);
			cout << (char)178;
			Console.SetCursorCoords(39, 18);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Twelve
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 24);
			cout << ' ';
			Console.SetCursorCoords(36, 24);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(31, 18);
			cout << (char)178;
			Console.SetCursorCoords(40, 18);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Thirteen
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 25);
			cout << ' ';
			Console.SetCursorCoords(36, 25);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(30, 18);
			cout << (char)178;
			Console.SetCursorCoords(41, 18);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Fourteen
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 26);
			cout << ' ';
			Console.SetCursorCoords(36, 26);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(29, 18);
			cout << (char)178;
			Console.SetCursorCoords(42, 18);
			cout << (char)178;

			Sleep(aniRate);

			// Frame Fifteen
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 27);
			cout << ' ';
			Console.SetCursorCoords(36, 27);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(28, 18);
			cout << (char)178;
			Console.SetCursorCoords(43, 18);
			cout << (char)178;

			Sleep(1000);

			// Frame Sixteen
			Console.SetColor(DarkGray, Black);
			Console.SetCursorCoords(35, 28);
			cout << ' ';
			Console.SetCursorCoords(36, 28);
			cout << ' ';

			Console.SetColor(HalfBlue, FullBlue);
			Console.SetCursorCoords(35, 19);
			cout << (char)178;
			Console.SetCursorCoords(36, 19);
			cout << (char)178;

			///////////////////
			// Animation End //
			///////////////////
			//
			//
			//
			//////////////////////
			// Map Change Begin //
			//////////////////////

			chiBuffer[909].Char.AsciiChar = ' ';
			chiBuffer[910].Char.AsciiChar = ' ';
			chiBuffer[1323].Char.AsciiChar = ' ';
			chiBuffer[1324].Char.AsciiChar = ' ';

			chiBuffer[954].Char.AsciiChar = (char)177;
			chiBuffer[954].Attributes = (DarkGray);
			chiBuffer[957].Char.AsciiChar = (char)177;
			chiBuffer[957].Attributes = (DarkGray);

			chiBuffer[(954 + 46)].Char.AsciiChar = (char)177;
			chiBuffer[(954 + 46)].Attributes = (DarkGray);
			chiBuffer[(957 + 46)].Char.AsciiChar = (char)177;
			chiBuffer[(957 + 46)].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 2))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 2))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 2))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 2))].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 3))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 3))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 3))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 3))].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 4))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 4))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 4))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 4))].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 5))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 5))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 5))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 5))].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 6))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 6))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 6))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 6))].Attributes = (DarkGray);

			chiBuffer[(954 + (46 * 7))].Char.AsciiChar = (char)177;
			chiBuffer[(954 + (46 * 7))].Attributes = (DarkGray);
			chiBuffer[(957 + (46 * 7))].Char.AsciiChar = (char)177;
			chiBuffer[(957 + (46 * 7))].Attributes = (DarkGray);

			chiBuffer[955].Char.AsciiChar = ' ';
			chiBuffer[955].Attributes = (Black);
			chiBuffer[956].Char.AsciiChar = ' ';
			chiBuffer[956].Attributes = (Black);

			chiBuffer[(955 + 46)].Char.AsciiChar = ' ';
			chiBuffer[(955 + 46)].Attributes = (Black);
			chiBuffer[(956 + 46)].Char.AsciiChar = ' ';
			chiBuffer[(956 + 46)].Attributes = (Black);

			chiBuffer[(955 + (46 * 2))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 2))].Attributes = (Black);
			chiBuffer[(956 + (46 * 2))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 2))].Attributes = (Black);

			chiBuffer[(955 + (46 * 3))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 3))].Attributes = (Black);
			chiBuffer[(956 + (46 * 3))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 3))].Attributes = (Black);

			chiBuffer[(955 + (46 * 4))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 4))].Attributes = (Black);
			chiBuffer[(956 + (46 * 4))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 4))].Attributes = (Black);

			chiBuffer[(955 + (46 * 5))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 5))].Attributes = (Black);
			chiBuffer[(956 + (46 * 5))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 5))].Attributes = (Black);

			chiBuffer[(955 + (46 * 6))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 6))].Attributes = (Black);
			chiBuffer[(956 + (46 * 6))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 6))].Attributes = (Black);

			chiBuffer[(955 + (46 * 7))].Char.AsciiChar = ' ';
			chiBuffer[(955 + (46 * 7))].Attributes = (Black);
			chiBuffer[(956 + (46 * 7))].Char.AsciiChar = ' ';
			chiBuffer[(956 + (46 * 7))].Attributes = (Black);

			unsigned short fgColor = HalfBlue;
			unsigned short bgColor = FullBlue;
			bgColor = bgColor * 0x0010;
			unsigned short combinedColor = (fgColor | bgColor);

			chiBuffer[994].Char.AsciiChar = (char)178;
			chiBuffer[994].Attributes = combinedColor;
			chiBuffer[1009].Char.AsciiChar = (char)178;
			chiBuffer[1009].Attributes = combinedColor;

			chiBuffer[950].Char.AsciiChar = (char)178;
			chiBuffer[950].Attributes = combinedColor;
			chiBuffer[961].Char.AsciiChar = (char)178;
			chiBuffer[961].Attributes = combinedColor;

			chiBuffer[949].Char.AsciiChar = (char)178;
			chiBuffer[949].Attributes = combinedColor;
			chiBuffer[962].Char.AsciiChar = (char)178;
			chiBuffer[962].Attributes = combinedColor;

			chiBuffer[948].Char.AsciiChar = (char)178;
			chiBuffer[948].Attributes = combinedColor;
			chiBuffer[963].Char.AsciiChar = (char)178;
			chiBuffer[963].Attributes = combinedColor;

			chiBuffer[907].Char.AsciiChar = (char)178;
			chiBuffer[907].Attributes = combinedColor;
			chiBuffer[912].Char.AsciiChar = (char)178;
			chiBuffer[912].Attributes = combinedColor;

			chiBuffer[906].Char.AsciiChar = (char)178;
			chiBuffer[906].Attributes = combinedColor;
			chiBuffer[913].Char.AsciiChar = (char)178;
			chiBuffer[913].Attributes = combinedColor;

			chiBuffer[905].Char.AsciiChar = (char)178;
			chiBuffer[905].Attributes = combinedColor;
			chiBuffer[914].Char.AsciiChar = (char)178;
			chiBuffer[914].Attributes = combinedColor;

			chiBuffer[904].Char.AsciiChar = (char)178;
			chiBuffer[904].Attributes = combinedColor;
			chiBuffer[915].Char.AsciiChar = (char)178;
			chiBuffer[915].Attributes = combinedColor;

			chiBuffer[903].Char.AsciiChar = (char)178;
			chiBuffer[903].Attributes = combinedColor;
			chiBuffer[916].Char.AsciiChar = (char)178;
			chiBuffer[916].Attributes = combinedColor;

			chiBuffer[902].Char.AsciiChar = (char)178;
			chiBuffer[902].Attributes = combinedColor;
			chiBuffer[917].Char.AsciiChar = (char)178;
			chiBuffer[917].Attributes = combinedColor;

			chiBuffer[861].Char.AsciiChar = (char)178;
			chiBuffer[861].Attributes = combinedColor;
			chiBuffer[866].Char.AsciiChar = (char)178;
			chiBuffer[866].Attributes = combinedColor;

			chiBuffer[860].Char.AsciiChar = (char)178;
			chiBuffer[860].Attributes = combinedColor;
			chiBuffer[867].Char.AsciiChar = (char)178;
			chiBuffer[867].Attributes = combinedColor;

			chiBuffer[859].Char.AsciiChar = (char)178;
			chiBuffer[859].Attributes = combinedColor;
			chiBuffer[868].Char.AsciiChar = (char)178;
			chiBuffer[868].Attributes = combinedColor;

			chiBuffer[858].Char.AsciiChar = (char)178;
			chiBuffer[858].Attributes = combinedColor;
			chiBuffer[869].Char.AsciiChar = (char)178;
			chiBuffer[869].Attributes = combinedColor;

			chiBuffer[857].Char.AsciiChar = (char)178;
			chiBuffer[857].Attributes = combinedColor;
			chiBuffer[870].Char.AsciiChar = (char)178;
			chiBuffer[870].Attributes = combinedColor;

			chiBuffer[856].Char.AsciiChar = (char)178;
			chiBuffer[856].Attributes = combinedColor;
			chiBuffer[871].Char.AsciiChar = (char)178;
			chiBuffer[871].Attributes = combinedColor;
		}
		else if (_stricmp(primeCommand.c_str(), "Use") == 0 && chiBuffer[403].Attributes == (HalfPurple))
		{
			SendGameMessage(HalfRed, "Nothing more happens.");
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that.");
		}
	}
	else if (i == 1450 || i == 1451)
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			if (attribute == (HalfRed))
			{
				SendGameMessage(HalfRed, "It's a locked sliding door");
			}
			else if (attribute == (HalfGreen))
			{
				SendGameMessage(HalfRed, "It's an unlocked sliding door");
			}
		}
		else if (_stricmp(primeCommand.c_str(), "Open") == 0)
		{
			if (attribute == (HalfRed))
			{
				SendGameMessage(HalfRed, "The doors are locked.");
			}
			else if (attribute == (HalfGreen))
			{
				chiBuffer[1450].Char.AsciiChar = ' ';
				chiBuffer[1451].Char.AsciiChar = ' ';

				SendGameMessage(HalfRed, "The doors open.");
			}
		}
		else if (_stricmp(primeCommand.c_str(), "Unlock") == 0)
		{
			if (attribute == (HalfRed))
			{
				if (InvItems.slot1_ID == 0x05)
				{
					InvItems.slot1_ID = 0x00;
					InvItems.S1_L1 = "";

					chiBuffer[1450].Attributes = HalfGreen;
					chiBuffer[1451].Attributes = HalfGreen;
					SendGameMessage(HalfRed, "Door unlocked.");
				}
				else
				{
					SendGameMessage(HalfRed, "You need the proper key to unlock this door. ");
				}
			}
			else if (attribute == (HalfGreen))
			{
				SendGameMessage(HalfRed, "The door is already unlocked");
			}
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that");
		}
	}
	else
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "You find nothing of interest.");
		}
		else if (_stricmp(primeCommand.c_str(), "Open") == 0)
		{
			SendGameMessage(HalfRed, "There's nothing to open.");
		}
	}
}
