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
	//擦除原来的砖块
	eraseBrick();

	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].m_y++;
	}
	drawBrick();

	return true;
}
