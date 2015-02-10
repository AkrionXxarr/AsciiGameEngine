#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "GameCore.h"
#include "ConsoleOperations.h"

/*====================*\
||User Interface print||
\*====================*/
void GameCore::Type1::GetUserInterface(unsigned short borderColor, unsigned short titleColor)
{
	int x = 0;
	int y = 0;
	int counter = 0;
	ConsoleOperations ConOp;
	ConOp.SetScreenSize(Max, 60);
	ConOp.SetColorText(borderColor);
	//////
	//
	// First row
	cout << (char)201;
	while (counter <= 44)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)187;
	cout << (char)201;
	counter = 0;

	while (counter <= 24)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)187;
	counter = 0;
	//////
	//
	// Second row
	y = 1;
	ConOp.SetCursorCoords(0, y);
	cout << (char)204;
	while (counter < 15)
	{
		cout << (char)205;
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << " ";
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)185;
	cout << (char)204;
	counter = 0;

	while (counter < 5)
	{
		cout << (char)205;
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << " ";
		counter++;
	}
	counter = 0;
	while (counter < 5)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)185;
	counter = 0;


	y = 2;
	while (counter < 31)
	{
		ConOp.SetCursorCoords(0, y);
		cout << (char)186;
		ConOp.SetCursorCoords(46, y);
		cout << (char)186;
		ConOp.SetCursorCoords(47, y);
		cout << (char)186;
		ConOp.SetCursorCoords(73, y);
		cout << (char)186;

		counter++;
		y++;
	}
	counter = 0;
	ConOp.SetCursorCoords(0, y);


	
	cout << (char)204;
	while (counter <= 44)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)185;
	cout << (char)186;
	counter = 0;

	while (counter <= 24)
	{
		cout << " ";
		counter++;
	}
	cout << (char)186;
	counter = 0;
	y++;



	ConOp.SetCursorCoords(0, y);
	cout << (char)186;
	ConOp.SetCursorCoords(46, y);
	cout << (char)186;
	ConOp.SetCursorCoords(47, y);
	cout << (char)186;
	ConOp.SetCursorCoords(73, y);
	cout << (char)186;
	counter = 0;
	y++;
	ConOp.SetCursorCoords(0, y);



	cout << (char)200;
	while (counter <= 44)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)188;
	cout << (char)200;
	counter = 0;
	while (counter <= 24)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)188;
	counter = 0;
	y++;
	ConOp.SetCursorCoords(0, y);


	cout << (char)201;
	while (counter <= 44)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)187;
	cout << (char)201;
	counter = 0;

	while (counter <= 24)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)187;
	counter = 0;
	y++;
	ConOp.SetCursorCoords(0, y);



	cout << (char)204;
	while (counter < 15)
	{
		cout << (char)205;
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << " ";
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)185;
	cout << (char)204;
	counter = 0;

	while (counter < 5)
	{
		cout << (char)205;
		counter++;
	}
	counter = 0;
	while (counter < 15)
	{
		cout << " ";
		counter++;
	}
	counter = 0;
	while (counter < 5)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)185;
	counter = 0;
	y++;



	while (counter < 15)
	{
		ConOp.SetCursorCoords(0, y);
		cout << (char)186;
		ConOp.SetCursorCoords(46, y);
		cout << (char)186;
		ConOp.SetCursorCoords(47, y);
		cout << (char)186;
		ConOp.SetCursorCoords(73, y);
		cout << (char)186;

		counter++;
		y++;
	}
	counter = 0;
	ConOp.SetCursorCoords(0, y);

	cout << (char)200;
	while (counter <= 44)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)188;
	cout << (char)200;
	counter = 0;
	while (counter <= 24)
	{
		cout << (char)205;
		counter++;
	}
	cout << (char)188;
	counter = 0;
	y++;

	//////////////////
	//Title printing//
	//////////////////

	ConOp.SetColorText(titleColor);
	ConOp.SetCursorCoords(18, 1);
	cout << "Edit Window";
	ConOp.SetCursorCoords(56, 1);
	cout << "Edit Menu";
	ConOp.SetCursorCoords(17, 37);
	cout << "Edit Messages";
	ConOp.SetCursorCoords(56, 37);
	cout << "Edit Info";
	ConOp.SetCursorCoords(2, 34);
	cout << "Command: ";
}