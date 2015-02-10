#include <iostream>
#include <conio.h>
using namespace std;

#include "ConsoleOperations.h"
#include "GameCore.h"

void Editor();

int main()
{
	// Total dimensions:
	// 45 cells wide by 31 cells high
	ConsoleOperations Console;
	Console.ClearScreen();
	GameCore::Type1::GetUserInterface(DarkGray, HalfRed);
	CreateDirectory(".\\Maps", NULL);

	GameCore::Type1::MenuItems commandList;
	
	commandList.MenuTitle = "Command List";

	commandList.Item1_0 = "Char";
	commandList.Item1_1 = "Clear";
	commandList.Item1_2 = "ColorCell";
	commandList.Item1_3 = "ColorText";
	commandList.Item1_4 = "Help";
	commandList.Item2_0 = "KeyCommands";
	commandList.Item2_1 = "KeyPrinting";
	commandList.Item2_2 = "Save";
	commandList.Item2_3 = "Load";
	commandList.Item2_4 = "Quit";

	GameCore::Type1::SetMenu(10, HalfRed, commandList);

	GameCore::Type1::SendGameMessage(HalfYellow, "Press $<HG><enter> $<Dflt> at any time to use the command line. "
												 "You can find a list of commands in the Edit Menu. "
												 "Commands are not case sensitive. Use the cursor keys "
												 "$<HG>(\x18\x1A\x19\x1B) $<Dflt> to move the cursor through the map edit window."
												 " \n \n \n \n \n \n \n \n \n \n \n \n ");


	Editor();

	return 0;
}

