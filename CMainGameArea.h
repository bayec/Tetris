#ifndef _CMAINGAMEAREA_H_
#define _CMAINGAMEAREA_H_

#define KROW 19
#define KCOL 15

class CMainGameArea
{
public:
	CMainGameArea(int offsetX = 0, int offsetY = 0);
	void drawGameArea();

	int tryAndCutLayer();
	void resetGameArea();

	int getOffsetX() const;
	int getOffsetY() const;

	int getMatrixStatus(int row, int col) const;
	void setMatrixStatus(int row, int col, int status);

private:
	int m_arrAreaMatrix[KROW][KCOL];
	int m_offsetx;
	int m_offsety;
};

#endif