#include "AGL_Include.h"
#include "AGL_G1_Functions.h"

void GetInventory(Inventory InvItems)
{
	// - Home Coords -
	// Box 1: (4, 8)  | Box 2:  (14, 8) |  Box 3:  (24, 8)  | Box 4:  (34, 8)
	// Box 5: (4, 15) | Box 6:  (14, 15) | Box 7:  (24, 15) | Box 8:  (34, 15)
	// Box 9: (4, 22) | Box 10: (14, 22) | Box 11: (24, 22) | Box 12: (34, 22)

	ConsoleOperations Console;
	Console.SetColor(Black, HalfRed);
	WriteCO(".\\Other\\AGL_Game_One_Inventory.dat");
	


	/////////////
	// Top Row //
	/////////////

	// Slot One //
	Console.SetCursorCoords(4, 8);
	cout << InvItems.S1_L1;
	Console.SetCursorCoords(4, 9);
	cout << InvItems.S1_L2;
	Console.SetCursorCoords(4, 10);
	cout << InvItems.S1_L3;
	Console.SetCursorCoords(4, 11);
	cout << InvItems.S1_L4;

	// Slot Two //
	Console.SetCursorCoords(14, 8);
	cout << InvItems.S2_L1;
	Console.SetCursorCoords(14, 9);
	cout << InvItems.S2_L2;
	Console.SetCursorCoords(14, 10);
	cout << InvItems.S2_L3;
	Console.SetCursorCoords(14, 11);
	cout << InvItems.S2_L4;

	// Slot Three //
	Console.SetCursorCoords(24, 8);
	cout << InvItems.S3_L1;
	Console.SetCursorCoords(24, 9);
	cout << InvItems.S3_L2;
	Console.SetCursorCoords(24, 10);
	cout << InvItems.S3_L3;
	Console.SetCursorCoords(24, 11);
	cout << InvItems.S3_L4;

	// Slot Four //
	Console.SetCursorCoords(34, 8);
	cout << InvItems.S4_L1;
	Console.SetCursorCoords(34, 9);
	cout << InvItems.S4_L2;
	Console.SetCursorCoords(34, 10);
	cout << InvItems.S4_L3;
	Console.SetCursorCoords(34, 11);
	cout << InvItems.S4_L4;



	//////////////
	//Middle Row//
	//////////////

	// Slot Five //
	Console.SetCursorCoords(4, 15);
	cout << InvItems.S5_L1;
	Console.SetCursorCoords(4, 16);
	cout << InvItems.S5_L2;
	Console.SetCursorCoords(4, 17);
	cout << InvItems.S5_L3;
	Console.SetCursorCoords(4, 18);
	cout << InvItems.S5_L4;

	// Slot Six //
	Console.SetCursorCoords(14, 15);
	cout << InvItems.S6_L1;
	Console.SetCursorCoords(14, 16);
	cout << InvItems.S6_L2;
	Console.SetCursorCoords(14, 17);
	cout << InvItems.S6_L3;
	Console.SetCursorCoords(14, 18);
	cout << InvItems.S6_L4;

	// Slot Seven //
	Console.SetCursorCoords(24, 15);
	cout << InvItems.S7_L1;
	Console.SetCursorCoords(24, 16);
	cout << InvItems.S7_L2;
	Console.SetCursorCoords(24, 17);
	cout << InvItems.S7_L3;
	Console.SetCursorCoords(24, 18);
	cout << InvItems.S7_L4;

	// Slot Eight //
	Console.SetCursorCoords(34, 15);
	cout << InvItems.S8_L1;
	Console.SetCursorCoords(34, 16);
	cout << InvItems.S8_L2;
	Console.SetCursorCoords(34, 17);
	cout << InvItems.S8_L3;
	Console.SetCursorCoords(34, 18);
	cout << InvItems.S8_L4;



	//////////////
	//Bottom Row//
	//////////////

	// Slot Nine //
	Console.SetCursorCoords(4, 22);
	cout << InvItems.S9_L1;
	Console.SetCursorCoords(4, 23);
	cout << InvItems.S9_L2;
	Console.SetCursorCoords(4, 24);
	cout << InvItems.S9_L3;
	Console.SetCursorCoords(4, 25);
	cout << InvItems.S9_L4;

	// Slot Ten //
	Console.SetCursorCoords(14, 22);
	cout << InvItems.S10_L1;
	Console.SetCursorCoords(14, 23);
	cout << InvItems.S10_L2;
	Console.SetCursorCoords(14, 24);
	cout << InvItems.S10_L3;
	Console.SetCursorCoords(14, 25);
	cout << InvItems.S10_L4;

	// Slot Eleven //
	Console.SetCursorCoords(24, 22);
	cout << InvItems.S11_L1;
	Console.SetCursorCoords(24, 23);
	cout << InvItems.S11_L2;
	Console.SetCursorCoords(24, 24);
	cout << InvItems.S11_L3;
	Console.SetCursorCoords(24, 25);
	cout << InvItems.S11_L4;

	// Slot Twelve //
	Console.SetCursorCoords(34, 22);
	cout << InvItems.S12_L1;
	Console.SetCursorCoords(34, 23);
	cout << InvItems.S12_L2;
	Console.SetCursorCoords(34, 24);
	cout << InvItems.S12_L3;
	Console.SetCursorCoords(34, 25);
	cout << InvItems.S12_L4;

	
}