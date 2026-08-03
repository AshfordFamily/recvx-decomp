#ifndef _EN03SUB_H_
#define _EN03SUB_H_

#include "types.h"
#include "macros.h"

void bhEne03s(BH_PWORK* epw);
void bhEne03s_Init(BH_PWORK* epw);
void bhEne03s_Move(BH_PWORK* epw);
void bhEne03s_MV00(BH_PWORK* epw);
void bhEne03s_Dummy(BH_PWORK* epw);
void bhEne03s_WallCheck(BH_PWORK* epw);
void bhEne03s_WallCheck2(BH_PWORK* epw);
void bhEne03s_InitCollision(BH_PWORK* epw);

#endif
