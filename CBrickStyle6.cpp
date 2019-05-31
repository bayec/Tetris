#include "CBrickStyle6.h"

CBrickStyle6::CBrickStyle6(CMainGameArea* gameArea) :CBrick(gameArea)
{
	/*
	 *  **
	 *   **
	 */
	m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
	m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x;
	m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
	m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x + 1;
	m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
}

bool CBrickStyle6::rotate()
{
	//������ͼ��
	eraseBrick();

	switch (m_status)
	{
	/*
	 *  status: **  --->   *
	 *			 **       **
	 *                    *
	 */
	case 0:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y - 1;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
		break;
	/*
	 *  status:   *  ---> **
	 *			 **        **
	 *           *         
	 */
	case 1:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x + 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
		break;
	}

	m_status = (m_status + 1) % 2;

	drawBrick();

	return true;
}