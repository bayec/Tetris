#include "CBrick.h"

CBrick::CBrick(CMainGameArea* gameArea)
{
	m_status = 0;
	this->m_gameArea = gameArea;
	this->m_arrBrickUnit[1].m_x = m_gameArea->getOffsetX() + KCOL / 2 + 1;
	this->m_arrBrickUnit[1].m_y = m_gameArea->getOffsetY() + 1;
}

CBrick::~CBrick()
{

}

void CBrick::eraseBrick() 
{
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].eraseBrickUnit();
	}
}

void CBrick::drawBrick()
{
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].drawBrickUnit();
	}
}

bool CBrick::moveLeft()
{
	//实现左边界控制
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		if (this->m_arrBrickUnit[i].m_x - 1 < this->m_gameArea->getOffsetX() + 1)
		{
			return false;
		}

		//左边界砖块碰撞
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX() - 1;
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
		{
			return false;
		}
	}

	//擦除原来的砖块
	eraseBrick();

	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].m_x--;
	}
	drawBrick();

	return true;
}

bool CBrick::moveRight()
{
	//实现右边界控制
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		if (this->m_arrBrickUnit[i].m_x + 1 > this->m_gameArea->getOffsetX() + KCOL)
		{
			return false;
		}

		//右边界砖块碰撞
		int x = this->m_arrBrickUnit[i].m_x - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
		{
			return false;
		}
	}

	//擦除原来的砖块
	eraseBrick();

	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].m_x++;
	}
	drawBrick();

	return true;
}

bool CBrick::moveDown()
{
	//实现下边界控制
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		//纵向偏移量加上游戏区域的行数
		if (this->m_arrBrickUnit[i].m_y + 1 >= this->m_gameArea->getOffsetY() + KROW)
		{
			return false;
		}

		//下边界砖块碰撞
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY() + 1;
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
		{
			return false;
		}
	}

	//擦除原来的砖块
	eraseBrick();

	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].m_y++;
	}
	//绘制新砖块
	drawBrick();

	return true;
}

void CBrick::setGameAreaMatrix()
{
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		this->m_gameArea->setMatrixStatus(y, x, 1);
	}
}
