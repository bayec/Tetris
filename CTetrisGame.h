#ifndef _CTETRISGAME_H_
#define _CTETRISGAME_H_

#include "CMainGameArea.h"
#include "CInfoBoard.h"
#include "CNextBrickBoard.h"
#include "CBrick.h"

class CTetrisGame
{
public:
	CTetrisGame();
	void run();

private:
	void setGameArea();
	CBrick* createNewBrick(int &brickIndex);

private:
	CMainGameArea* m_gameArea;
	CInfoBoard* m_infoBoard;
	CNextBrickBoard* m_nextBrickBoard;
	int m_speed;
	int m_level;
	int m_layerCount;
};

#endif