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
	//ʵ����߽����
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		if (this->m_arrBrickUnit[i].m_x - 1 < this->m_gameArea->getOffsetX() + 1)
		{
			return false;
		}
	}

	//����ԭ����ש��
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
	//ʵ���ұ߽����
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		if (this->m_arrBrickUnit[i].m_x + 1 > this->m_gameArea->getOffsetX() + KCOL)
		{
			return false;
		}
	}

	//����ԭ����ש��
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
	//ʵ���±߽����
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		//����ƫ����������Ϸ���������
		if (this->m_arrBrickUnit[i].m_y + 1 >= this->m_gameArea->getOffsetY() + KROW)
		{
			return false;
		}
	}

	//����ԭ����ש��
	eraseBrick();

	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		m_arrBrickUnit[i].m_y++;
	}
	//������ש��
	drawBrick();

	return true;
}
