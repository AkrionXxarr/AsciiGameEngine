#ifndef _GAMECORE_
#define _GAMECORE_
#include <string>
using namespace std;

namespace GameCore
{
	namespace Type1
	{
		__declspec(dllexport) void CommandInput(unsigned short color, string& primeCommand, string& subCommand);

		__declspec(dllexport) void GetUserInterface(unsigned short borderColor, unsigned short titleColor);

		__declspec(dllexport) void PrintMapTest();

		__declspec(dllexport) void SendCharacterInfo(unsigned short lineNumber, unsigned short textColor, string message);

		__declspec(dllexport) void SendGameMessage(unsigned short textColor, string message);

		__declspec(dllexport) void SetMenu(int itemCount, unsigned short menuColor, struct MenuItems);
		struct __declspec(dllexport) MenuItems
		{
			string MenuTitle;

			// First five
			string Item1_0;
			string Item1_1;
			string Item1_2;
			string Item1_3;
			string Item1_4;

			// Second five
			string Item2_0;
			string Item2_1;
			string Item2_2;
			string Item2_3;
			string Item2_4;

			// Third five
			string Item3_0;
			string Item3_1;
			string Item3_2;
			string Item3_3;
			string Item3_4;
		};
	}
}

namespace GameControl
{
	namespace Type1
	{
		__declspec(dllexport) void CharMovement(short& X, short& Y, int& input);
	}
}

#endif