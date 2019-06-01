#ifndef _CNEXTBRICKBOARD_H_
#define _CNEXTBRICKBOARD_H_

class CNextBrickBoard
{
public:
	CNextBrickBoard(int offsetX, int offsetY);
	void drawNextBrickBoard(int brickIndex);

private:
	void eraseBoard();

private:
	int m_offsetX;
	int m_offsetY;
};

#endif