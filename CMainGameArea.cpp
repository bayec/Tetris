#include <iostream>
#include "CMainGameArea.h"
#include "CTools.h"

using namespace std;

CMainGameArea::CMainGameArea(int offsetX, int offsetY)
{
	m_offsetx = offsetX;
	m_offsety = offsetY;
}

void CMainGameArea::cutLayer(int row)
{
	int i = row;
	while (i > 0)
	{
		for (int j = 0; j < KCOL; j++)
		{
			this->m_arrAreaMatrix[i][j] = this->m_arrAreaMatrix[i - 1][j];
		}
		i--;
	}
}

void CMainGameArea::drawMatrix()
{
	for (int i = 0; i < KROW; i++)
	{
		CTools::gotoxy(m_offsetx + 1, m_offsety + i);
		for (int j = 0; j < KCOL; j++)
		{
			if (this->m_arrAreaMatrix[i][j] == 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
	}
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
	int cutLayers = 0;
	for (int i = 0; i < KROW; i++)
	{
		int unitCount = 0;
		for (int j = 0; j < KCOL; j++)
		{
			unitCount += this->m_arrAreaMatrix[i][j];
		}

		if (unitCount == KCOL)
		{
			//可以消层
			cutLayer(i);

			cutLayers++;

			//消层完后刷新游戏区域
			drawMatrix();
		}
	}

	return cutLayers;
}

void CMainGameArea::resetGameArea()
{
	for (int i = 0; i < KROW; i++)
	{
		for (int j = 0; j < KCOL; j++)
		{
			m_arrAreaMatrix[i][j] = 0;
		}
	}

	this->drawMatrix();
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
