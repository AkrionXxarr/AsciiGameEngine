#include "AGL_Include.h"
#include "AGL_G1_Functions.h"

int main()
{
	string introFile;
	string clearFile;

	// 2 dimensional array to 1 dimensional:
	// index = width * row + col;

	introFile = ".\\Other\\AGL_Game_One_Intro.dat";
	clearFile = ".\\Other\\ClearScreen.dat";

	GetUserInterface(DarkGray, HalfGreen);
	MapCopy();
	
	WriteCO(introFile);

	SendGameMessage(HalfRed, "        ..Press enter to continue.. \n"
		                       " \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");

	WriteCO(clearFile);
	RunGame();

	return 0;
}