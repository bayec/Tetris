#include <Windows.h>
#include "CTools.h"

void CTools::gotoxy(int x, int y)
{
	COORD coor;
	coor.X = x;
	coor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}