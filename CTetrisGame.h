#ifndef _CTETRISGAME_H_
#define _CTETRISGAME_H_

#include "CMainGameArea.h"
#include "CInfoBoard.h"
#include "CNextBrickBoard.h"

class CTetrisGame
{
public:
	CTetrisGame();
	void run();

private:
	CMainGameArea* m_gameArea;
	CInfoBoard* m_infoBoard;
	CNextBrickBoard* m_nextBrickBoard;
	int m_speed;
	int m_level;
	int m_layerCount;
};

#endif