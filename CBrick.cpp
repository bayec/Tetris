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

		//��߽�ש����ײ
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX() - 1;
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
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

		//�ұ߽�ש����ײ
		int x = this->m_arrBrickUnit[i].m_x - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
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

		//�±߽�ש����ײ
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY() + 1;
		if (this->m_gameArea->getMatrixStatus(y, x) == 1)
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

void CBrick::setGameAreaMatrix()
{
	for (int i = 0; i < KBRICK_UINT_COUNT; i++)
	{
		int x = this->m_arrBrickUnit[i].m_x - 1 - m_gameArea->getOffsetX();
		int y = this->m_arrBrickUnit[i].m_y - m_gameArea->getOffsetY();
		this->m_gameArea->setMatrixStatus(y, x, 1);
	}
}
