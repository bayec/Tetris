#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include "CTetrisGame.h"
#include "CTools.h"
#include "CBrickStyle1.h"
#include "CBrickStyle2.h"
#include "CBrickStyle3.h"
#include "CBrickStyle4.h"
#include "CBrickStyle5.h"
#include "CBrickStyle6.h"
#include "CBrickStyle7.h"

using namespace std;

CTetrisGame::CTetrisGame()
{
	this->m_layerCount = 0;
	this->m_speed = 300;
	this->m_level = 1;
	this->m_nextBrickIndex = -1;

	this->setGameArea();
}

void CTetrisGame::run()
{
	bool pauseFlag = false;
	char key = 0;
	int brickIndex = 0;
	CBrick* brick = createNewBrick(brickIndex);
	brick->drawBrick();
	this->m_nextBrickBoard->drawNextBrickBoard(this->m_nextBrickIndex);

	while (key != 0x1b)
	{
		while (!_kbhit() && !pauseFlag)
		{
			if (!brick->moveDown())
			{
				//ש���䶨֮�󽫱�־λ���õ�������
				brick->setGameAreaMatrix();
				delete brick;
				brick = NULL;

				//ש���䶨�����Ƿ�����
				this->m_layerCount += this->m_gameArea->tryAndCutLayer();

				//������Ƿ���أ�ˢ��
				if (this->m_layerCount >= this->m_level * KLAYERS_PRE_LEVEL)
				{
					//�ؿ�����1
					this->m_level++;

					//�������Ϸ����
					//this->m_gameArea->resetGameArea();
				}

				//��⵱ǰ����Ƿ������Ϸ����
				if (this->m_gameArea->gameOver())
				{
					system("cls");
					CTools::gotoxy(40, 10);
					cout << "Game Over!!!" << endl;
					return;
				}

				//ˢ����Ϣ���
				this->m_infoBoard->drawInfoBoard(this->m_level * KLAYERS_PRE_LEVEL, this->m_layerCount);

				//������һ��ש
				brick = createNewBrick(brickIndex);
				brick->drawBrick();

				//ˢ����һ��שԤ�����
				this->m_nextBrickBoard->drawNextBrickBoard(this->m_nextBrickIndex);
			}
			Sleep(this->m_speed);
		}

		key = _getch();
		switch (key)
		{
		//����
		case 'w':
			brick->rotate();
			break;
		//����
		case 's':
			brick->moveDown();
			break;
		//����
		case 'a':
			brick->moveLeft();
			break;
		//����
		case 'd':
			brick->moveRight();
			break;
		//��ͣ���߻ָ�
		case ' ':
			pauseFlag = !pauseFlag;
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
	this->m_infoBoard->drawInfoBoard(this->m_level * KLAYERS_PRE_LEVEL, this->m_layerCount);

	this->m_nextBrickBoard = new CNextBrickBoard(15, 4);
	this->m_nextBrickBoard->drawNextBrickBoard(0);
}

CBrick* CTetrisGame::createNewBrick(int& brickIndex)
{
	srand((unsigned int)time(NULL));
	if (this->m_nextBrickIndex == -1)
	{
		//��Ϸ�տ�ʼ
		brickIndex = rand() % 7;

		this->m_nextBrickIndex = rand() % 7;
	}
	else
	{
		//��ǰש���䶨��������һ��ש
		brickIndex = this->m_nextBrickIndex;
		this->m_nextBrickIndex = rand() % 7;
	}

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
