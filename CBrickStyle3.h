#ifndef _CBRICKSTYLE3_H_
#define _CBRICKSTYLE3_H_

#include "CBrick.h"

/*
 *  ***
 *   *
 */

class CBrickStyle3 : public CBrick
{
public:
	CBrickStyle3(CMainGameArea* gameArea);

	virtual bool rotate();

private:
};

#endif
