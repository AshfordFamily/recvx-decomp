#ifndef _EN18_H_
#define _EN18_H_

#include "types.h"
#include "macros.h"

typedef struct ENE18_EO
{
    // total size: 0xC
    NJS_POINT3 ofp; // offset 0x0, size 0xC
    float rx; // offset 0xC, size 0x4
    float ry; // offset 0x10, size 0x4
    float rz; // offset 0x14, size 0x4
} ENE18_EO;

typedef struct ENE18_BLOOD_TBL {
    // total size: 0xC
    signed int flg; // offset 0x0, size 0x4
    ENE18_EO *effoff; // offset 0x4, size 0x4
    signed int num; // offset 0x8, size 0x4
} ENE18_BLOOD_TBL;

void bhEne18(BH_PWORK* epw);
void bhEne18_Init(BH_PWORK* epw);
void bhEne18_Move(BH_PWORK* epw);
void bhEne18_MV00(BH_PWORK* epw);
void bhEne18_MV01(BH_PWORK* epw);
void bhEne18_MV02(BH_PWORK* epw);
void bhEne18_MV03();
void bhEne18_MV04(BH_PWORK* epw);
void bhEne18_MV05(BH_PWORK* epw);
void bhEne18_Nage();
void bhEne18_Damage();
void bhEne18_Die(BH_PWORK* epw);
int bhEne18_HitMark(BH_PWORK* epw);

#endif
