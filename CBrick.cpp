#include "CBrick.h"

CBrick::CBrick()
{
	m_status = 0;
	m_arrBrickUnit[1].m_x = 5;
	m_arrBrickUnit[1].m_y = 3;
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
