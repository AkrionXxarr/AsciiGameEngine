#include "AGL_Include.h"
#include "AGL_G1_Functions.h"

void Database1_1(short xCoordCheck, short yCoordCheck, char character, unsigned short attribute, string primeCommand, CHAR_INFO *chiBuffer, Inventory &InvItems);
void Database1_2(short xCoordCheck, short yCoordCheck, char character, unsigned short attribute, string primeCommand, CHAR_INFO *chiBuffer, Inventory &InvItems);

void MainDatabase(short xCoordCheck, short yCoordCheck, string primeCommand, string mapLoad, string mapArrayE, Inventory &InvItems)
{
	ConsoleOperations Console;

	char character;
	unsigned short attribute;
	int i;

	CHAR_INFO chiBuffer[1518];

	ifstream loadStream(mapLoad.c_str(), ios::binary);

	if (loadStream.fail())
	{
		loadStream.clear();
		loadStream.close();
		return;
	}
	else
	{
		loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

		i = ((46 * yCoordCheck) + xCoordCheck);

		character = chiBuffer[i].Char.AsciiChar;
		attribute = chiBuffer[i].Attributes;
		loadStream.close();
	}

	if (_stricmp(mapArrayE.c_str(), "1-1") == 0)
	{
		Database1_1(xCoordCheck, yCoordCheck, character, attribute, primeCommand, chiBuffer, InvItems);
	}
	else if (_stricmp(mapArrayE.c_str(), "1-2") == 0)
	{
		Database1_2(xCoordCheck, yCoordCheck, character, attribute, primeCommand, chiBuffer, InvItems);
	}

	ofstream saveStream(mapLoad.c_str(), ios::binary);

	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.close();
}