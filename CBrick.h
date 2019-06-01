#ifndef _CBRICK_H_
#define _CBRICK_H_

#include "CBrickUnit.h"
#include "CMainGameArea.h"

#define KBRICK_UINT_COUNT 4

class CBrick
{
public:
	CBrick(CMainGameArea* gameArea);
	virtual ~CBrick();
	virtual bool rotate() = 0;
	void eraseBrick();
	void drawBrick();
	bool moveLeft();
	bool moveRight();
	bool moveDown();

	void setGameAreaMatrix();

protected:
	CBrickUnit m_arrBrickUnit[KBRICK_UINT_COUNT];
	int m_status;
	CMainGameArea* m_gameArea;
};

#endif