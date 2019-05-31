#ifndef _CBRICKSTYLE1_H_
#define _CBRICKSTYLE1_H_

#include "CBrick.h"

/*
 *  **
 *  **
 */

class CBrickStyle1: public CBrick
{
public:
	CBrickStyle1(CMainGameArea* gameArea);

	virtual bool rotate();

private:
};

#endif

