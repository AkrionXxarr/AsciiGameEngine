#include "AGL_Include.h"

void MapCopy()
{
	CHAR_INFO chiBuffer[1518]; // [46][33];


	ifstream loadStream;
	ofstream saveStream;

	// Map_1-1
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-1.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-1.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-2
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-2.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-2.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-3
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-3.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-3.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-4
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-4.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-4.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-5
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-5.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-5.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-6
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-6.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-6.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-7
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-7.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-7.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-8
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-8.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-8.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();

	// Map_1-9
	loadStream.open(".\\Maps\\Reference Maps\\RefMap_1-9.dat", ios::binary);
	loadStream.read((char*)&chiBuffer, sizeof(chiBuffer));

	saveStream.open(".\\Maps\\Map_1-9.dat", ios::binary);
	saveStream.write((char*)&chiBuffer, sizeof(chiBuffer));

	loadStream.close();
	saveStream.close();
}