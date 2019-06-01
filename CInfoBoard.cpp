#include <iostream>
#include "CInfoBoard.h"
#include "CTools.h"

using namespace std;

CInfoBoard::CInfoBoard(int offsetX, int offsetY)
{
	m_offsetX = offsetX;
	m_offsetY = offsetY;
}

void CInfoBoard::drawInfoBoard(int needLayers, int curLayers)
{
	CTools::gotoxy(m_offsetX, m_offsetY);
	cout << "-----------------------------";
	CTools::gotoxy(m_offsetX, m_offsetY + 1);
	cout << "          NEED: " << needLayers << "      ";
	CTools::gotoxy(m_offsetX, m_offsetY + 2);
	cout << "          NOW : " << curLayers << "      ";
	CTools::gotoxy(m_offsetX, m_offsetY + 3);
	cout << "-----------------------------";
}