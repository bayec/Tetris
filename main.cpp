#include "CInfoBoard.h"
#include "CNextBrickBoard.h"
#include "CMainGameArea.h"
#include <stdio.h>
#include "CBrickStyle2.h"

int main()
{
	CBrickStyle2* style = new CBrickStyle2();
	style->drawBrick();

	getchar();
	style->rotate();

	getchar();
	style->rotate();

	getchar();
	style->rotate();

	return 0;
}