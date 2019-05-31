#include "CBrickStyle4.h"

CBrickStyle4::CBrickStyle4(CMainGameArea* gameArea) :CBrick(gameArea)
{
	/*
	 *  ***
	 *    *
	 */
	m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
	m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x + 1;
	m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y;
	m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x + 1;
	m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
}

bool CBrickStyle4::rotate()
{
	//²Á³ýÔ­Í¼°¸
	eraseBrick();

	switch (m_status)
	{
	/*
	 * status 0: ***       *
	 *             * --->  * 
	 *                    **
	 */
	case 0:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y - 1;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
		break;
	/*
	 * status 1:  *      *
	 *            * ---> ***
	 *           **
	 */
	case 1:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x + 1;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y - 1;
		break;
	/*
	 * status 2: *        **
	 *           *** ---> *
	 *                    *
	 */
	case 2:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y + 1;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y - 1;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x + 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y - 1;
		break;
	/*
	 * status 3: **      ***
	 *           *  --->   *
	 *           *
	 */
	case 3:
		m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
		m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x + 1;
		m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y;
		m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x + 1;
		m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;
		break;
	default:
		break;
	}

	m_status = (m_status + 1) % 4;

	drawBrick();

	return true;
}
