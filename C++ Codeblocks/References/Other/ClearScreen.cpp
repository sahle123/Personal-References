/*
*	Courtesy of Duoas from C++ forums.
*	Date: Jan. 8th, 2013
*
*		This is an efficient and proper method as to how to clear
*	the screen of the MSDOS console. Note that this will only work
*	for WINDOWS.
*
*	This function will basically set every cell in the buffer to
* 	' ' which is an empty space and then place the cursor back to
*	(0,0) which is the top left of the console.
*
*	For POSIX systems (like Mac OSX, Linux, etc..) read this article
* 	for instructions to setup a proper clear screen function.
*		http://www.cplusplus.com/articles/4z1805o
*	
*/

#include <windows.h> // <-- Necessary Preprocessor directive

void ClearScreen()
{
	// Local variables 
	HANDLE					   hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD					   count;
	DWORD					   cellCount;
	COORD					   homeCoords = {0, 0};
	
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if(hStdOut == INVALID_HANDLE_VALUE)
		return;
	/* Get the number of cells in the current buffer */
	if(!GetConsoleScreenBufferInfo(hStdOut, &csbi))	
		return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;
	
	/* Fill the entire buffer with spaces */
	// Note the syntax looks funny here, but it actually normal.
	if(!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count)) return;
		
	/* Fill the entire buffer with the current colors and atributes*/
	if(!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;
	
	/* Move the cursor back to home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}