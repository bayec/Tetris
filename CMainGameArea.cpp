#include <iostream>
#include "CMainGameArea.h"
#include "CTools.h"

using namespace std;

CMainGameArea::CMainGameArea(int offsetX, int offsetY)
{
	m_offsetx = offsetX;
	m_offsety = offsetY;
}

void CMainGameArea::drawGameArea()
{
	for (int i = 0; i < KROW; i++)
	{
		CTools::gotoxy(m_offsetx, m_offsety + i);
		cout << "|";
		for (int j = 0; j < KCOL; j++)
		{
			cout << " ";
		}
		cout << "|";
	}
	CTools::gotoxy(m_offsetx, m_offsety + KROW);
	for (int i = 0; i < KCOL + 2; i++)
	{
		cout << "-";
	}
}

int CMainGameArea::tryAndCutLayer()
{
	return 0;
}

void CMainGameArea::resetGameArea()
{

}

int CMainGameArea::getOffsetX() const
{
	return m_offsetx;
}

int CMainGameArea::getOffsetY() const
{
	return m_offsety;
}

int CMainGameArea::getMatrixStatus(int row, int col) const
{
	return m_arrAreaMatrix[row][col];
}

void CMainGameArea::setMatrixStatus(int row, int col, int status)
{
	m_arrAreaMatrix[row][col] = status;
}
