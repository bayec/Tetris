#ifndef _CBRICKSTYLE4_H_
#define _CBRICKSTYLE4_H_

#include "CBrick.h"

/*
 *  ***
 *    *
 */

class CBrickStyle4 : public CBrick
{
public:
	CBrickStyle4(CMainGameArea* gameArea);

	virtual bool rotate();

private:
};

#endif