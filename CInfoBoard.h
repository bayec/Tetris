#ifndef _CINFOBOARD_H_
#define _CINFOBOARD_H_

class CInfoBoard
{
public:
	CInfoBoard(int offsetX, int offsetY);
	void drawInfoBoard(int needLayers, int curLayers);

private:
	int m_offsetX;
	int m_offsetY;
};

#endif