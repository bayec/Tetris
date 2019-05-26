#ifndef _CBRICKUNIT_H_
#define _CBRICKUNIT_H_

class CBrickUnit
{
public:
	CBrickUnit(char image = '*');
	void drawBrickUnit();
	void eraseBrickUnit();

public:
	int m_x;
	int m_y;
	char m_image;
};

#endif