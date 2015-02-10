#ifndef _CONSOLE_OPERATIONS_IMP_H
#define _CONSOLE_OPERATIONS_IMP_H

//// Implementation ////
class ConsoleOperationsImp
{
public:
	// Constructors and Destructors//
	ConsoleOperationsImp();

	// Clear Screen functions//
	void ClearScreen();
	void ClearScreen(unsigned short);

	// Defaulting functions //
	void SetDefaultColor();
	void SetDefaultCursorSize();
	void SetDefaultScreenSize();



	///////////////////////////
	// === Get functions === //
	///////////////////////////

	// Get Color functions  //
	unsigned short GetColorCell();
	unsigned short GetColorText();

	// Get Cursor functions //
	char GetCursorChar();
	short GetCursorSize();



	//////////////////////////////
	// === Return functions === //
	//////////////////////////////

	// Color functions --
	void RetrieveColors(unsigned short&, unsigned short&);

	// Cursor functions --
	void RetrieveCursorCoords(short&, short&);

	// Screen functions --
	void RetrieveScreenSize(short&, short&);



	///////////////////////////
	// === Set functions === //
	///////////////////////////

	// Set Color functions //
	void SetColor(unsigned short, unsigned short);
	void SetColorCell(unsigned short);
	void SetColorText(unsigned short);

	// Set Cursor functions //
	void SetCursorCoords(short, short);
	void SetCursorHome();
	void SetCursorSize(short);

	// Set Screen functions //
	void SetScreenSize(short, short);

private:
	// Color storage //
	unsigned short fgColorStore;
	unsigned short bgColorStore;


	// Cursor storage //
	short cursorCoordX;
	short cursorCoordY;
	short cursorSize;


	// Screen storage //
	short xScreen;
	short yScreen;

	short xScreenDefault;
	short yScreenDefault;

	short xScreenStore;
	short yScreenStore;

	short xScreenMax;
	short yScreenMax;

	// Set Screen //
	void GetBuffer();
};

#endif