#ifndef _CBRICK_H_
#define _CBRICK_H_

#include "CBrickUnit.h"

#define KBRICK_UINT_COUNT 4

class CBrick
{
public:
	CBrick();
	virtual ~CBrick();
	virtual bool rotate() = 0;
	void eraseBrick();
	void drawBrick();
	bool moveLeft();
	bool moveRight();
	bool moveDown();

public:
	CBrickUnit m_arrBrickUnit[KBRICK_UINT_COUNT];
	int m_status;
};

#endif