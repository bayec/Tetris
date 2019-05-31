#include "CBrickStyle7.h"

CBrickStyle7::CBrickStyle7(CMainGameArea* gameArea) :CBrick(gameArea)
{
	/*
	 *   **
	 *  **
	 */
	m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
	m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 2;
	m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
	m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
}

bool CBrickStyle7::rotate()
{
	//²Á³ý¾ÉÍ¼°¸
	eraseBrick();

	switch (m_status)
	{
	/*
	 *  status:  ** ---> *
	 *			**       **
	 *                    *
	 */
	case 0:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y - 1;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y - 2;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y - 1;
		break;
	/*
	 *  status: *  --->  **
	 *			**      **
	 *           *
	 */
	case 1:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 2;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
		break;
	}

	m_status = (m_status + 1) % 2;

	drawBrick();

	return true;
}