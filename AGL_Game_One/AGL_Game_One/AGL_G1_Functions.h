#ifndef _AGL_GAME_ONE_FUNCTIONS_H
#define _AGL_GAME_ONE_FUNCTIONS_H
#include "AGL_Include.h"

void WriteCO(string fileName);

void GetInventory(struct Inventory);

void MapCopy();

void RunGame();

void MainDatabase(short xCoordCheck, short yCoordCheck, string primeCommand, string mapLoad, string mapArrayE, Inventory &InvItems);

struct Inventory
{
	// S = Slot, L = Line.
	// S1_L1 = Slot 1, Line 1

	string S1_L1;
	string S1_L2;
	string S1_L3;
	string S1_L4;
	int slot1_ID;

	string S2_L1;
	string S2_L2;
	string S2_L3;
	string S2_L4;
	int slot2_ID;

	string S3_L1;
	string S3_L2;
	string S3_L3;
	string S3_L4;
	int slot3_ID;

	string S4_L1;
	string S4_L2;
	string S4_L3;
	string S4_L4;
	int slot4_ID;

	string S5_L1;
	string S5_L2;
	string S5_L3;
	string S5_L4;
	int slot5_ID;

	string S6_L1;
	string S6_L2;
	string S6_L3;
	string S6_L4;
	int slot6_ID;

	string S7_L1;
	string S7_L2;
	string S7_L3;
	string S7_L4;
	int slot7_ID;

	string S8_L1;
	string S8_L2;
	string S8_L3;
	string S8_L4;
	int slot8_ID;

	string S9_L1;
	string S9_L2;
	string S9_L3;
	string S9_L4;
	int slot9_ID;

	string S10_L1;
	string S10_L2;
	string S10_L3;
	string S10_L4;
	int slot10_ID;

	string S11_L1;
	string S11_L2;
	string S11_L3;
	string S11_L4;
	int slot11_ID;

	string S12_L1;
	string S12_L2;
	string S12_L3;
	string S12_L4;
	int slot12_ID;
};

#endif