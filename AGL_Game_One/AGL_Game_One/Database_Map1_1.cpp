#include "AGL_Include.h"
#include "AGL_G1_Functions.h"

void Database1_1(short xCoordCheck, short yCoordCheck, char character, unsigned short attribute, string primeCommand, CHAR_INFO *chiBuffer, Inventory &InvItems)
{

	ConsoleOperations Console;

	int i = ((46 * yCoordCheck) + xCoordCheck);	

	Console.SetCursorCoords(0, 60);
	cout << "          ";
	Console.SetCursorCoords(0, 60);
	cout << i;

	if (character == (char)20) // ¶
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "A small key rests on the floor.");
		}
		else if (_stricmp(primeCommand.c_str(), "Take") == 0)
		{
			switch (i)
			{
			case 907:
				InvItems.S1_L1 = "A small";
				InvItems.S1_L2 = "Room Key";
				InvItems.slot1_ID = 0x01;

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
	else if (character == 'o')
	{
		switch (i)
		{
		case 825:
			if (InvItems.slot1_ID != 0x02 && (chiBuffer[569].Char.AsciiChar == '#' && chiBuffer[569].Attributes == (FullRed)))
			{
				if (_stricmp(primeCommand.c_str(), "Look") == 0)
				{
					SendGameMessage(HalfRed, "A trash bin sits tucked behind a couch, inside are a few scraps of paper "
											 "underneath of which the glint of a metal object can be seen.");
				}
				else if (_stricmp(primeCommand.c_str(), "Take") == 0)
				{
					InvItems.S1_L1 = "A heavy";
					InvItems.S1_L2 = "Door Key";
					InvItems.slot1_ID = 0x02;

					SendGameMessage(HalfRed, "You reach in and remove the metal object from the trash bin, "
											 "it's a heavy metal key.");
				}
				else
				{
					SendGameMessage(HalfRed, "You can't do that.");
				}
			}
			else
			{
				if (_stricmp(primeCommand.c_str(), "Look") == 0)
				{
					SendGameMessage(HalfRed, "A trash bin sits tucked behind a couch, inside are a few scraps of paper. ");
				}
				else if (_stricmp(primeCommand.c_str(), "Take") == 0)
				{
					SendGameMessage(HalfRed, "There's nothing else to take.");
				}
				else
				{
					SendGameMessage(HalfRed, "You can't do that.");
				}
			}
				break;
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
				case 569:
					if (InvItems.slot1_ID == 0x02)
					{
						InvItems.slot1_ID = 0x00;
						InvItems.S1_L1 = "";
						InvItems.S1_L2 = "";

						chiBuffer[i].Attributes = FullGreen;
						SendGameMessage(HalfRed, "Door unlocked.");
					}
					else
					{
						SendGameMessage(HalfRed, "You need the proper key to unlock this door. ");
					}
					break;
				case 721:
					if (InvItems.slot1_ID == 0x01)
					{
						InvItems.slot1_ID = 0x00;
						InvItems.S1_L1 = "";
						InvItems.S1_L2 = "";

						chiBuffer[i].Attributes = FullGreen;
						SendGameMessage(HalfRed, "Door unlocked.");
					}
					else
					{
						SendGameMessage(HalfRed, "You need the proper key to unlock this door. ");
					}
					break;
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
	else if (i == 655 || i == 834)
	{
		if (_stricmp(primeCommand.c_str(), "Look") == 0)
		{
			SendGameMessage(HalfRed, "It's a control panel for operating the door. ");
		}
		else if (_stricmp(primeCommand.c_str(), "Use") == 0 && chiBuffer[650].Attributes == (HalfRed))
		{
			chiBuffer[650].Attributes = (HalfGreen);
			chiBuffer[839].Attributes = (HalfGreen);

			chiBuffer[743].Char.AsciiChar = ' ';
			chiBuffer[744].Char.AsciiChar = ' ';
			chiBuffer[745].Char.AsciiChar = ' ';
			chiBuffer[746].Char.AsciiChar = ' ';

			SendGameMessage(HalfRed, "You hear an electric motor kick into action and the door opens.");
		}
		else if (_stricmp(primeCommand.c_str(), "Use") == 0 && chiBuffer[650].Attributes == (HalfGreen))
		{
			chiBuffer[650].Attributes = (HalfRed);
			chiBuffer[839].Attributes = (HalfRed);

			chiBuffer[743].Char.AsciiChar = (char)196;
			chiBuffer[744].Char.AsciiChar = (char)196;
			chiBuffer[745].Char.AsciiChar = (char)196;
			chiBuffer[746].Char.AsciiChar = (char)196;

			SendGameMessage(HalfRed, "You hear an electric motor kick into action and the door closes.");
		}
		else
		{
			SendGameMessage(HalfRed, "You can't do that.");
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