#include "CBrickStyle1.h"

CBrickStyle1::CBrickStyle1()
{
	m_arrBrickUnit[0].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[0].m_y = m_arrBrickUnit[1].m_y;
	m_arrBrickUnit[2].m_x = m_arrBrickUnit[1].m_x - 1;
	m_arrBrickUnit[2].m_y = m_arrBrickUnit[1].m_y + 1;
	m_arrBrickUnit[3].m_x = m_arrBrickUnit[1].m_x;
	m_arrBrickUnit[3].m_y = m_arrBrickUnit[1].m_y + 1;

}

bool CBrickStyle1::rotate()
{
	return true;
}
