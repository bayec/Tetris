#include "CInfoBoard.h"
#include "CNextBrickBoard.h"
#include "CMainGameArea.h"

int main()
{
	//CInfoBoard* board = new CInfoBoard(20, 10);
	//board->drawInfoBoard(8, 6);

	//CNextBrickBoard* board = new CNextBrickBoard(20, 10);
	//board->drawNextBrickBoard(6);

	CMainGameArea* area = new CMainGameArea(20, 5);
	area->drawGameArea();

	return 0;
}