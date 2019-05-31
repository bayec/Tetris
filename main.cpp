#include "CInfoBoard.h"
#include "CNextBrickBoard.h"
#include "CMainGameArea.h"
#include <stdio.h>
#include "CBrickStyle7.h"
#include "CTetrisGame.h"

int main()
{
	CTetrisGame* game = new CTetrisGame();
	game->run();

	return 0;
}