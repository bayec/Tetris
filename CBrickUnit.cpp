#include <iostream>
#include "CBrickUnit.h"
#include "CTools.h"

using namespace std;

CBrickUnit::CBrickUnit(char image)
{
	m_image = image;
	m_x = 0;
	m_y = 0;
}

void CBrickUnit::drawBrickUnit()
{
	CTools::gotoxy(m_x, m_y);
	cout << m_image;
}

void CBrickUnit::eraseBrickUnit()
{
	CTools::gotoxy(m_x, m_y);
	cout << " ";
}
