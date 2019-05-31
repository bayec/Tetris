#ifndef _CBRICKSTYLE2_H_
#define _CBRICKSTYLE2_H_

#include "CBrick.h"

/*
 *  ****
 */

class CBrickStyle2 : public CBrick
{
public:
	CBrickStyle2(CMainGameArea* gameArea);

	virtual bool rotate();

private:
};

#endif