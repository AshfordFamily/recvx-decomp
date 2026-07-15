#ifndef _HITCHKL_H_
#define _HITCHKL_H_

#include "types.h"

ATR_WORK* bhCollisionCheckLine(NJS_POINT3* p1, NJS_POINT3* p2);
ATR_WORK* bhCollisionCheckLine2(NJS_POINT3* p1, NJS_POINT3* p2, unsigned int flg, char flr_no);
ATR_WORK* bhCollisionCheckLine3(NJS_POINT3* p1, NJS_POINT3* p2, unsigned int flg, char flr_no);
int bhCollisionCheckLineMain(ATR_WORK* hp, NJS_VECTOR* vec, NJS_POINT3* p1, NJS_POINT3* p2);
int bhCollisionCheckL2PL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* area, int num);
int bhInOutCheck(NJS_POINT3* p, NJS_POINT3* area, NJS_POINT3* normal, int num);
int bhCollisionCheckL2MDL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_CNK_MODEL* mdl, NJS_MATRIX* mtx);
int bhCollisionCheckL2XZPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float w, float d, int flg);
int bhCollisionCheckL2XYPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float w, float h, int flg);
int bhCollisionCheckL2YZPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float h, float d, int flg);
void bhGetHitCollisionNormal(NJS_POINT3* n);

#endif
