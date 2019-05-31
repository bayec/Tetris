#include <time.h>
#include <stdlib.h>
#include "CTetrisGame.h"
#include "CBrickStyle1.h"
#include "CBrickStyle2.h"
#include "CBrickStyle3.h"
#include "CBrickStyle4.h"
#include "CBrickStyle5.h"
#include "CBrickStyle6.h"
#include "CBrickStyle7.h"

CTetrisGame::CTetrisGame()
{
	this->m_layerCount = 0;
	this->m_speed = 500;
	this->m_level = 1;

	this->setGameArea();
}

void CTetrisGame::run()
{
	int brickIndex = 0;
	CBrick* brick = createNewBrick(brickIndex);
	brick->drawBrick();
}

void CTetrisGame::setGameArea()
{
	this->m_gameArea = new CMainGameArea(50, 0);
	this->m_gameArea->drawGameArea();

	this->m_infoBoard = new CInfoBoard(15, 13);
	this->m_infoBoard->drawInfoBoard(8, 0);

	this->m_nextBrickBoard = new CNextBrickBoard(15, 4);
	this->m_nextBrickBoard->drawNextBrickBoard(0);
}

CBrick* CTetrisGame::createNewBrick(int& brickIndex)
{
	srand((unsigned int)time(NULL));
	brickIndex = rand() % 7;

	switch (brickIndex)
	{
	case 0:
		return new CBrickStyle1(m_gameArea);
	case 1:
		return new CBrickStyle2(m_gameArea);
	case 2:
		return new CBrickStyle3(m_gameArea);
	case 3:
		return new CBrickStyle4(m_gameArea);
	case 4:
		return new CBrickStyle5(m_gameArea);
	case 5:
		return new CBrickStyle6(m_gameArea);
	case 6:
		return new CBrickStyle7(m_gameArea);
	default:
		break;
	}

	return NULL;
}
