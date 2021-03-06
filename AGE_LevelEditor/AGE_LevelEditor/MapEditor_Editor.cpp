#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "stdio.h"
using namespace std;

#include "ConsoleOperations.h"
#include "GameCore.h"

void ClearEditWindow();
void Editor()
{
	ConsoleOperations Console;

	bool done = false;
	bool print = true;
	bool erase = false;
	bool contPrint = true;
	bool keyPrint = false;


	int input = 0;


	short asciiVal = 0;
	short col = 0;
	short row = 0;
	short printCellColor = Black;
	short printTextColor = White;


	char *charPtr;
	short *iPtr;


	string asciiChar;
	string currentChar;

	string currentCellColor;
	string currentTextColor;
	string color;
	string colorInsert;

	string printStatus_String;
	string printStatus_Color;
	string printStatus_Status;

	string printMethod_String;
	string printMethod_Color;
	string printMethod_Status;

	string keyPrint_String;
	string keyPrint_Color;
	string keyPrint_Status;

	string fileName;

	string primeCommand;
	string subCommand;
	string unknownCommand;

	string::iterator iterate;


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


	col = 1;
	row = 2;

	// Clear the edit window
	ClearEditWindow();

	// Initialize Current Character
	currentChar = "Current Character: ";
	asciiChar = (char)asciiVal;
	GameCore::Type1::SendCharacterInfo(2, White, currentChar.append(asciiChar));

	// Initialize Current Colors
	GameCore::Type1::SendCharacterInfo(4, White, "- Current Colors -");

	color = "      ";
	for (iterate = color.begin(); iterate < color.end(); iterate++)
	{
		*iterate = (char)254;
	}

	currentTextColor = "> Text: ";
	colorInsert = "$<White>";
	GameCore::Type1::SendCharacterInfo(5, White, currentTextColor.append(colorInsert.append(color)));

	currentCellColor = "> Cell: ";
	colorInsert = "$<Black>";
	GameCore::Type1::SendCharacterInfo(6, White, currentCellColor.append(colorInsert.append(color)));
	

	// Initialize Current Print Status
	printStatus_String = "Print Status: ";
	printStatus_Color = "$<HalfGreen>";
	printStatus_Status = "Print";
	GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append(printStatus_Color.append(printStatus_Status)));

	// Initialize Continuious Print
	printMethod_String = "Print Method: ";
	printMethod_Color = "$<HalfGreen>";
	printMethod_Status = "Cont.";
	GameCore::Type1::SendCharacterInfo(10, White, printMethod_String.append(printMethod_Color.append(printMethod_Status)));

	// Initialize Key Print status
	keyPrint_String = "Key Printing: ";
	keyPrint_Color = "$<HalfRed>";
	keyPrint_Status = "Off";
	GameCore::Type1::SendCharacterInfo(12, White, keyPrint_String.append(keyPrint_Color.append(keyPrint_Status)));

	while (!done)
	{

		Console.SetCursorSize(100);
		Console.SetCursorCoords(col, row);
		Console.SetColor(printTextColor, printCellColor);

		unknownCommand = "Unknown command: ";

		input = _getch();

		// Print / Move / Erase
		if ((input == 49 || input == 50 || input == 51) && !keyPrint)
		{
			printStatus_String = "Print Status: ";

			switch (input)
			{
			case 49:
				print = true;
				erase = false;
				printStatus_Color = "$<HalfGreen>";
				printStatus_Status = "Print";
				GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append(printStatus_Color.append(printStatus_Status)));
				break;

			case 50:
				print = false;
				erase = false;
				printStatus_Color = "$<HalfYellow>";
				printStatus_Status = "Move";
				GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append(printStatus_Color.append(printStatus_Status)));
				break;

			case 51:
				print = false;
				erase = true;
				printStatus_Color = "$<HalfRed>";
				printStatus_Status = "Erase";
				GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append(printStatus_Color.append(printStatus_Status)));
				break;
			}
			continue;
		}
		
		// Continuious print / Single print
		if (input == 9 && !keyPrint)
		{
			printMethod_String = "Print Method: ";
			if (!contPrint)
			{
				contPrint = true;
				printMethod_Color = "$<HalfGreen>";
				printMethod_Status = "Cont.";
				GameCore::Type1::SendCharacterInfo(10, White, printMethod_String.append(printMethod_Color.append(printMethod_Status)));
			}
			else
			{
				contPrint = false;
				printMethod_Color = "$<HalfYellow>";
				printMethod_Status = "Single";
				GameCore::Type1::SendCharacterInfo(10, White, printMethod_String.append(printMethod_Color.append(printMethod_Status)));
			}
			continue;
		}

		// User hit Enter
		if (input == 13)
		{
			GameCore::Type1::SendGameMessage(HalfYellow, "");
			GameCore::Type1::CommandInput(HalfYellow, primeCommand, subCommand);

			if (primeCommand == "")
			{
				continue;
			}
			// Character change command
			else if (_stricmp(primeCommand.c_str(), "Char") == 0)
			{
				if (subCommand == "")
				{
					continue;
				}
				else if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Enter the ascii value for the character you wish to use. "
																 "See an Ascii table for a list of character values. "
																 "You may also enter $<HG>.Char$<Dflt>, and any keyboard character. \n \n"
																 "Usage 1: $<HG>Char$<Dflt>, $<HG><Ascii Number>$<Dflt> \n"
																 "Usage 2: $<HG>.Char$<Dflt>, $<HG><Keyboard Char>$<Dflt> \n \n"
																 "Example 1: $<HG>Char$<Dflt>, $<HG>64$<Dflt> \n"
																 "Result: $<HG>@$<Dflt> \n \n"
																 "Example 2: $<HG>.Char$<Dflt>, $<HG>@$<Dflt> \n"
																 "Result: $<HG>@$<Dflt> \n \n"
																 " \n \n \n ");
					continue;
				}

				charPtr = new char[subCommand.size()];
				iPtr = new short;

				*iPtr = 0;
				for (iterate = subCommand.begin(); iterate < subCommand.end(); iterate++)
				{
					charPtr[*iPtr] = *iterate;
					*iPtr += 1;
				}

				asciiVal = atoi(charPtr);

				currentChar = "Current Character: ";
				asciiChar = (char)asciiVal;
				GameCore::Type1::SendCharacterInfo(2, White, currentChar.append(asciiChar));

				delete [] charPtr;
				charPtr = NULL;
				delete iPtr;
				iPtr = NULL;
			}
			else if (_stricmp(primeCommand.c_str(), ".Char") == 0)
			{
				if (subCommand == "")
				{
					continue;
				}
				iterate = subCommand.begin();
				asciiVal = (short)*iterate;

				currentChar = "Current Character: ";
				asciiChar = (char)asciiVal;
				GameCore::Type1::SendCharacterInfo(2, White, currentChar.append(asciiChar));
			}
			// Text Color change command
			else if (_stricmp(primeCommand.c_str(), "ColorText") == 0)
			{
				if      (_stricmp(subCommand.c_str(), "Black"     ) == 0) {printTextColor = Black;      colorInsert = "$<Black>";     }
				else if (_stricmp(subCommand.c_str(), "DarkGray"  ) == 0) {printTextColor = DarkGray;   colorInsert = "$<DarkGray>";  }
				else if (_stricmp(subCommand.c_str(), "HalfBlue"  ) == 0) {printTextColor = HalfBlue;   colorInsert = "$<HalfBlue>";  }
				else if (_stricmp(subCommand.c_str(), "FullBlue"  ) == 0) {printTextColor = FullBlue;   colorInsert = "$<FullBlue>";  }
				else if (_stricmp(subCommand.c_str(), "HalfGreen" ) == 0) {printTextColor = HalfGreen;  colorInsert = "$<HalfGreen>"; }
				else if (_stricmp(subCommand.c_str(), "FullGreen" ) == 0) {printTextColor = FullGreen;  colorInsert = "$<FullGreen>"; }
				else if (_stricmp(subCommand.c_str(), "HalfRed"   ) == 0) {printTextColor = HalfRed;    colorInsert = "$<HalfRed>";   }
				else if (_stricmp(subCommand.c_str(), "FullRed"   ) == 0) {printTextColor = FullRed;    colorInsert = "$<FullRed>";   }
				else if (_stricmp(subCommand.c_str(), "HalfTeal"  ) == 0) {printTextColor = HalfTeal;   colorInsert = "$<HalfTeal>";  }
				else if (_stricmp(subCommand.c_str(), "FullTeal"  ) == 0) {printTextColor = FullTeal;   colorInsert = "$<FullTeal>";  }
				else if (_stricmp(subCommand.c_str(), "HalfPurple") == 0) {printTextColor = HalfPurple; colorInsert = "$<HalfPurple>";}
				else if (_stricmp(subCommand.c_str(), "FullPurple") == 0) {printTextColor = FullPurple; colorInsert = "$<FullPurple>";}
				else if (_stricmp(subCommand.c_str(), "HalfYellow") == 0) {printTextColor = HalfYellow; colorInsert = "$<HalfYellow>";}
				else if (_stricmp(subCommand.c_str(), "FullYellow") == 0) {printTextColor = FullYellow; colorInsert = "$<FullYellow>";}
				else if (_stricmp(subCommand.c_str(), "LightGray" ) == 0) {printTextColor = LightGray;  colorInsert = "$<LightGray>"; }
				else if (_stricmp(subCommand.c_str(), "White"     ) == 0) {printTextColor = White;      colorInsert = "$<White>";     }

				else if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Enter the color you wish to use for the text. "
																 "Enter $<HG>ColorText$<Dflt>, $<HG>List $<Dflt> for "
																 "a list of valid colors. \n \n"
																 "Usage: $<HG>ColorText$<Dflt>, $<HG><Color>$<Dflt>. \n \n"
																 "Example: $<HG>ColorText$<Dflt>, $<HG>HalfRed$<Dflt>. \n"
																 " \n \n \n \n \n \n \n ");
					continue;
				}
				else if (_stricmp(subCommand.c_str(), "List") == 0)
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Color Commands: \n"
																 "------------------------ \n"
																 "Black      | DarkGray \n"
																 "HalfBlue   | FullBlue \n"
																 "HalfGreen  | FullGreen \n"
																 "HalfRed    | FullRed \n"
																 "HalfTeal   | FullTeal \n"
																 "HalfPurple | FullPurple \n"
																 "HalfYellow | FullYellow \n"
																 "LightGray  | White \n"
																 "------------------------ \n \n"
																 " \n \n ");
					continue;
				}
				else if (subCommand == "")
				{
					continue;
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));

					continue;
				}

				currentTextColor = "> Text: ";
				GameCore::Type1::SendCharacterInfo(5, White, currentTextColor.append(colorInsert.append(color)));
			}
			// Cell Color change command
			else if (_stricmp(primeCommand.c_str(), "ColorCell") == 0)
			{
				if      (_stricmp(subCommand.c_str(), "Black"     ) == 0) {printCellColor = Black;      colorInsert = "$<Black>";     }
				else if (_stricmp(subCommand.c_str(), "DarkGray"  ) == 0) {printCellColor = DarkGray;   colorInsert = "$<DarkGray>";  }
				else if (_stricmp(subCommand.c_str(), "HalfBlue"  ) == 0) {printCellColor = HalfBlue;   colorInsert = "$<HalfBlue>";  }
				else if (_stricmp(subCommand.c_str(), "FullBlue"  ) == 0) {printCellColor = FullBlue;   colorInsert = "$<FullBlue>";  }
				else if (_stricmp(subCommand.c_str(), "HalfGreen" ) == 0) {printCellColor = HalfGreen;  colorInsert = "$<HalfGreen>"; }
				else if (_stricmp(subCommand.c_str(), "FullGreen" ) == 0) {printCellColor = FullGreen;  colorInsert = "$<FullGreen>"; }
				else if (_stricmp(subCommand.c_str(), "HalfRed"   ) == 0) {printCellColor = HalfRed;    colorInsert = "$<HalfRed>";   }
				else if (_stricmp(subCommand.c_str(), "FullRed"   ) == 0) {printCellColor = FullRed;    colorInsert = "$<FullRed>";   }
				else if (_stricmp(subCommand.c_str(), "HalfTeal"  ) == 0) {printCellColor = HalfTeal;   colorInsert = "$<HalfTeal>";  }
				else if (_stricmp(subCommand.c_str(), "FullTeal"  ) == 0) {printCellColor = FullTeal;   colorInsert = "$<FullTeal>";  }
				else if (_stricmp(subCommand.c_str(), "HalfPurple") == 0) {printCellColor = HalfPurple; colorInsert = "$<HalfPurple>";}
				else if (_stricmp(subCommand.c_str(), "FullPurple") == 0) {printCellColor = FullPurple; colorInsert = "$<FullPurple>";}
				else if (_stricmp(subCommand.c_str(), "HalfYellow") == 0) {printCellColor = HalfYellow; colorInsert = "$<HalfYellow>";}
				else if (_stricmp(subCommand.c_str(), "FullYellow") == 0) {printCellColor = FullYellow; colorInsert = "$<FullYellow>";}
				else if (_stricmp(subCommand.c_str(), "LightGray" ) == 0) {printCellColor = LightGray;  colorInsert = "$<LightGray>"; }
				else if (_stricmp(subCommand.c_str(), "White"     ) == 0) {printCellColor = White;      colorInsert = "$<White>";     }

				else if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Enter the color you wish to use for the cell. "
																 "Enter $<HG>ColorCell$<Dflt>, $<HG>List $<Dflt> for "
																 "a list of valid colors. \n \n"
																 "Usage: $<HG>ColorCell$<Dflt>, $<HG><Color>$<Dflt>. \n \n"
																 "Example: $<HG>ColorCell$<Dflt>, $<HG>HalfRed$<Dflt>. \n"
																 " \n \n \n \n \n \n \n ");
					continue;
				}
				else if (_stricmp(subCommand.c_str(), "List") == 0)
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Colors commands: \n"
																 "------------------------ \n"
																 "Black      | DarkGray \n"
																 "HalfBlue   | FullBlue \n"
																 "HalfGreen  | FullGreen \n"
																 "HalfRed    | FullRed \n"
																 "HalfTeal   | FullTeal \n"
																 "HalfPurple | FullPurple \n"
																 "HalfYellow | FullYellow \n"
																 "LightGray  | White \n"
																 "------------------------ \n \n"
																 " \n \n ");
					continue;
				}
				else if (subCommand == "")
				{
					continue;
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));

					continue;
				}

				currentCellColor = "> Cell: ";
				GameCore::Type1::SendCharacterInfo(6, White, currentCellColor.append(colorInsert.append(color)));
			}
			// Clear edit window command
			else if (_stricmp(primeCommand.c_str(), "Clear") == 0)
			{
				if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Use this command to clear the entire edit window, "
																 "you will be prompted for confirmation. \n"
																 " \n \n \n \n \n \n \n \n \n \n \n \n \n ");
					continue;
				}
				else if (subCommand == "")
				{
					GameCore::Type1::SendGameMessage(FullRed, "Are you sure you wish to clear the edit screen? Y/N");
					while (1)
					{
						GameCore::Type1::CommandInput(HalfYellow, primeCommand, subCommand);

						if (_stricmp(primeCommand.c_str(), "Y") == 0)
						{
							ClearEditWindow();
							break;
						}
						else if (_stricmp(primeCommand.c_str(), "N") == 0)
						{
							break;
						}
					}
					GameCore::Type1::SendGameMessage(FullTeal, "");
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));

					continue;
				}
			}
			// Help command
			else if (_stricmp(primeCommand.c_str(), "Help") == 0)
			{
				if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Now you're just being silly. \n"
																 " \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");
					continue;
				}
				else if (subCommand == "")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Type $<HG>? $<Dflt> after a command found in the menu "
															 "to learn more about said command. \n \n"
														     "Usage: $<HG><Command>$<Dflt>, $<HG>? $<Dflt> \n \n"
														     "Example: $<HG>Save$<Dflt>, $<HG>? $<Dflt> \n"
														     " \n \n \n \n \n \n \n \n \n \n \n ");
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));

					continue;
				}
			}
			// Key bindings
			else if (_stricmp(primeCommand.c_str(), "KeyCommands") == 0)
			{
				if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Shows a list of keyboard commands."
																 " \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");

					continue;
				}
				else if (subCommand == "")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Keyboard commands: \n"
															 "---------------------- \n"
															 "| Key  | Function    | \n"
															 "---------------------- \n"
															 "| 1    | Print       | \n"
															 "| 2    | Move        | \n"
															 "| 3    | Erase       | \n"
															 "| Tab  | Cont/Single | \n"
															 "| \x18\x1A\x19\x1B | Move Cursor | \n"
															 "---------------------- \n"
															 " \n \n \n \n \n ");
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));

					continue;
				}
			}
			// Keyboard print command
			else if (_stricmp(primeCommand.c_str(), "KeyPrinting") == 0)
			{
				if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Use this command to toggle $<HT>Key Printing $<Dflt> on and off. "
																 "When $<HT>Key Printing $<Dflt> is on, you are able to type with your "
																 "keyboard directly onto the window. This turns $<HT>Print Status $<Dflt> "
																 "and $<HT>Print Method $<Dflt> off. Turning $<HT>Key Printing $<Dflt> "
																 "off will reset $<HT>Print Status $<Dflt> and $<HT>Print Method $<Dflt>"
																 "to their previous settings. $<HG>KeyPrinting $<Dflt> doesn't take any commands "
																 "beyond $<HG>?$<Dflt>. "
																 " \n \n \n \n \n \n ");
				}
				else if (!keyPrint && subCommand == "")
				{
					keyPrint = true;

					keyPrint_String = "Key Printing: ";
					keyPrint_Color = "$<HalfGreen>";
					keyPrint_Status = "On";
					GameCore::Type1::SendCharacterInfo(12, White, keyPrint_String.append(keyPrint_Color.append(keyPrint_Status)));

					printStatus_String = "Print Status: ";
					printMethod_String = "Print Method: ";
					GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append("$<FullRed> Off"));
					GameCore::Type1::SendCharacterInfo(10, White, printMethod_String.append("$<FullRed> Off"));
				}
				else if (keyPrint && subCommand == "")
				{
					keyPrint = false;

					keyPrint_String = "Key Printing: ";
					keyPrint_Color = "$<HalfRed>";
					keyPrint_Status = "Off";
					GameCore::Type1::SendCharacterInfo(12, White, keyPrint_String.append(keyPrint_Color.append(keyPrint_Status)));

					printStatus_String = "Print Status: ";
					printMethod_String = "Print Method: ";

					if (_stricmp(printStatus_Color.c_str(), "$<HalfGreen>Print") == 0)
					{
						printStatus_Color = "$<HalfGreen>";
					}
					else if (_stricmp(printStatus_Color.c_str(), "$<HalfYellow>Move") == 0)
					{
						printStatus_Color = "$<HalfYellow>";
					}
					else if (_stricmp(printStatus_Color.c_str(), "$<HalfRed>Erase") == 0)
					{
						printStatus_Color = "$<HalfRed>";
					}

					if (_stricmp(printMethod_Color.c_str(), "$<HalfGreen>Cont.") == 0)
					{
						printMethod_Color = "$<HalfGreen>";
					}
					else if (_stricmp(printMethod_Color.c_str(), "$<HalfYellow>Single") == 0)
					{
						printMethod_Color = "$<HalfYellow>";
					}

					GameCore::Type1::SendCharacterInfo(8, White, printStatus_String.append(printStatus_Color.append(printStatus_Status)));
					GameCore::Type1::SendCharacterInfo(10, White, printMethod_String.append(printMethod_Color.append(printMethod_Status)));
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));
				}

				continue;
			}
			// Save command
			else if (_stricmp(primeCommand.c_str(), "Save") == 0)
			{
				if (subCommand == "")
				{
					continue;
				}
				else if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Use this command to save your work to $<HT>[%LocalDir%\\Maps\\]$<Dflt>. "
																 "Case will be taken into account for the name, "
																 "you will be prompted with an overwrite check if name exists. "
																 "$<HR>Do not $<Dflt> add a file extension to the name. \n \n"
																 "Usage: $<HG>Save$<Dflt>, $<HG><Map Name>$<Dflt> \n \n"
																 "Example: $<HG>Save$<Dflt>, $<HG>ExampleMap$<Dflt> \n"
																 "Result: ExampleMap.dat saved to $<HT>[%LocalDir%\\Maps\\]$<Dflt>"
																 " \n \n \n \n \n \n \n \n \n ");
					continue;
				}
				else
				{
					bool saveMap = true;

					fileName = ".\\Maps\\";
					fileName.append(subCommand.append(".dat"));

					ReadConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);

					ifstream checkSave(fileName.c_str(), ios::binary);

					if (checkSave.is_open())
					{
						GameCore::Type1::SendGameMessage(FullRed, "File exists, overwrite? Y/N");
						while (1)
						{
							GameCore::Type1::CommandInput(HalfYellow, primeCommand, subCommand);

							if (_stricmp(primeCommand.c_str(), "Y") == 0)
							{
								break;
							}
							else if (_stricmp(primeCommand.c_str(), "N") == 0)
							{
								saveMap = false;
								break;
							}
						}
						GameCore::Type1::SendGameMessage(FullRed, "");
					}

					if (saveMap)
					{
						ofstream saveStream(fileName.c_str(), ios::binary);
						if (saveStream.fail())
						{
							saveStream.clear();
							GameCore::Type1::SendGameMessage(FullRed, fileName.insert(0, "Could not save "));
						}
						else
						{
							saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));
							GameCore::Type1::SendGameMessage(FullRed, fileName.append(" saved."));
						}
						saveStream.close();

					}

					continue;
				}
			}
			// Load command
			else if (_stricmp(primeCommand.c_str(), "Load") == 0)
			{
				if (subCommand == "")
				{
					continue;
				}
				else if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Use this command to load your work from $<HT>[%LocalDir%\\Maps\\]$<Dflt>. "
																 "You will be prompted with a check before loading. "
																 "$<HR>Do not $<Dflt> add a file extension to the name. \n \n"
																 "Usage: $<HG>Load$<Dflt>, $<HG><Map Name>$<Dflt> \n \n"
																 "Example: $<HG>Load$<Dflt>, $<HG>ExampleMap$<Dflt> \n"
																 "Result: ExampleMap.dat loaded from $<HT>[%LocalDir%\\Maps\\]$<Dflt>"
																 " \n \n \n \n \n \n \n \n \n ");
					continue;
				}
				else
				{
					bool loadMap = true;

					fileName = ".\\Maps\\";
					fileName.append(subCommand.append(".dat"));

					ifstream loadStream(fileName.c_str(), ios::binary);

					if (!loadStream.is_open())
					{
						GameCore::Type1::SendGameMessage(FullRed, "File not found."
									  " \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");

						loadStream.close();
						continue;
					}

					GameCore::Type1::SendGameMessage(FullRed, "Unsaved progress will be lost, are you sure? Y/N");
					while (1)
					{
						GameCore::Type1::CommandInput(HalfYellow, primeCommand, subCommand);

						if (_stricmp(primeCommand.c_str(), "Y") == 0)
						{
							break;
						}
						else if (_stricmp(primeCommand.c_str(), "N") == 0)
						{
							loadMap = false;
							break;
						}
					}
					GameCore::Type1::SendGameMessage(FullRed, "");

					if (loadMap)
					{
						if (loadStream.fail())
						{
							loadStream.clear();
							GameCore::Type1::SendGameMessage(FullRed, fileName.insert(0, "Could not load "));
						}
						else
						{
							loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

							WriteConsoleOutput(hReadCO, chiBuffer, chiBufferSize, chiBufferCoord, &srctEditWindow);
							GameCore::Type1::SendGameMessage(FullRed, fileName.append(" loaded."));
						}
					}

					loadStream.close();
					continue;
				}
			}
			// Quit command
			else if (_stricmp(primeCommand.c_str(), "Quit") == 0)
			{
				if (subCommand == "?")
				{
					GameCore::Type1::SendGameMessage(HalfYellow, "Quits the program."
																 " \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");
					continue;
				}
				else if (subCommand == "")
				{
					done = true;
				}
				else
				{
					GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(subCommand));
					continue;
				}
			}
			else
			{
				GameCore::Type1::SendGameMessage(FullRed, unknownCommand.append(primeCommand));
			}
			continue;
		}

		GameControl::Type1::CharMovement(col, row, input);

		if (col < 1 || col > 45 || row < 2 || row > 32)
		{
			GameControl::Type1::CharMovement(col, row, input);
		}

		if (keyPrint && (input > 32 && input < 127))
		{
			cout << (char)input;
			if (col < 45)
			{
				col++;
			}
		}
		else if (keyPrint && input == 32)
		{
			if (col < 45)
			{
				col++;
			}
			cout << " ";
		}
		else if (keyPrint && input == 8)
		{
			if (col > 1)
			{
				col--;
				Console.SetCursorCoords(col, row);
			}
			Console.SetColorCell(Black);
			cout << " ";
		}

		// Print Status: Print
		if (print && !keyPrint)
		{
			// Print Method: Cont.
			if (contPrint)
			{
				cout << (char)asciiVal;
			}
			// Print Method: Single
			else 
			{
				if (input == 32)
				{
					cout << (char)asciiVal;
				}
			}
		}
		// Print Status: Erase
		else if (!print && erase && !keyPrint)
		{
			// Print Method: Cont.
			if (contPrint)
			{
				Console.SetColorCell(Black);
				cout << " ";
			}
			// Print Method: Single
			else
			{
				if (input == 32)
				{
					Console.SetColorCell(Black);
					cout << " ";
				}
			}
		}
	}
}

void ClearEditWindow()
{
	ConsoleOperations Console;

	short row = 2;
	short col = 1;

	Console.SetCursorCoords(1, row);
	Console.SetColorCell(Black);
	for (row = 2; row < 34; row++)
	{
		for (col = 1; col < 46; col++)
		{
			cout << " ";
		}
		Console.SetCursorCoords(1, row);
	}
}

