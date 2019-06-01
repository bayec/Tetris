#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "CTetrisGame.h"
#include "CBrickStyle1.h"
#include "CBrickStyle2.h"
#include "CBrickStyle3.h"
#include "CBrickStyle4.h"
#include "CBrickStyle5.h"
#include "CBrickStyle6.h"
#include "CBrickStyle7.h"
#include <stdio.h>

CTetrisGame::CTetrisGame()
{
	this->m_layerCount = 0;
	this->m_speed = 600;
	this->m_level = 1;

	this->setGameArea();
}

void CTetrisGame::run()
{
	char key = 0;
	int brickIndex = 0;
	CBrick* brick = createNewBrick(brickIndex);
	brick->drawBrick();

	while (key != 0x1b)
	{
		while (!_kbhit())
		{
			if (!brick->moveDown())
			{
				brick->setGameAreaMatrix();
				delete brick;
				brick = NULL;

				brick = createNewBrick(brickIndex);
				brick->drawBrick();
			}
			Sleep(this->m_speed);
		}

		key = _getch();
		switch (key)
		{
		//变形
		case 'w':
			brick->rotate();
			break;
		//向下
		case 's':
			brick->moveDown();
			break;
		//向左
		case 'a':
			brick->moveLeft();
			break;
		//向右
		case 'd':
			brick->moveRight();
			break;
		default:
			break;
		}
	}
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
