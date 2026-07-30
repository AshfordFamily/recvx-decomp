#ifndef _EFFSUB1_H_
#define _EFFSUB1_H_

#include "types.h"

typedef struct ER_WORK 
{
    // total size: 0x10
    float px; // offset 0x0, size 0x4
    float py; // offset 0x4, size 0x4
    float pz; // offset 0x8, size 0x4
    short ax; // offset 0xC, size 0x2
    short ay; // offset 0xE, size 0x2
} ER_WORK;

typedef struct EXP_EFF025_WORK 
{
    // total size: 0x20
    unsigned short flg; // offset 0x0, size 0x2
    short ct;           // offset 0x2, size 0x2
    float scl;          // offset 0x4, size 0x4
    float px;           // offset 0x8, size 0x4
    float py;           // offset 0xC, size 0x4
    float pz;           // offset 0x10, size 0x4
    float xn;           // offset 0x14, size 0x4
    float yn;           // offset 0x18, size 0x4
    float zn;           // offset 0x1C, size 0x4
} EXP_EFF025_WORK;

typedef struct EXP_DRAW022_WORK
{
    // total size: 0x10
    unsigned short flg; // offset 0x0, size 0x2
    short ct;           // offset 0x2, size 0x2
    float px;           // offset 0x4, size 0x4
    float py;           // offset 0x8, size 0x4
    float pz;           // offset 0xC, size 0x4
} EXP_DRAW022_WORK;

void bhEffDmy(O_WRK* op);
void bhEffFil(O_WRK* op);
void bhEffBG(O_WRK* op);
void bhEff2D(O_WRK* op);
void bhEff000(O_WRK* op);
void bhEff001(O_WRK* op);
void bhEff002(O_WRK* op);
void bhDrawWeaponEffect(O_WRK* op);
void bhEff003(O_WRK* op);
void bhEff004();
void bhEff005(O_WRK* op);
void bhEff006(O_WRK* op);
void bhEff007(O_WRK* op);
void bhEff008(O_WRK* op);
void bhEff009(O_WRK* op);
void bhEff010(O_WRK* op);
void bhEff011(O_WRK* op);
void bhEff012(O_WRK* op);
void bhEff013(O_WRK* op);
void bhEff014(O_WRK* op);
void bhEff015(O_WRK* op);
void bhEff016(O_WRK* op);
void bhEff017(O_WRK* op);
void bhEff018(O_WRK* op);
void bhEff019(O_WRK* op);
void bhDraw021();
void bhEff021(O_WRK* op);
void bhDraw022(O_WRK* op);
void bhEff022(O_WRK* op);
void bhEff023(O_WRK* op);
void bhDraw024(O_WRK* op);
void bhEff024(O_WRK* op);
void bhDraw025(O_WRK* op);
void bhEff025(O_WRK* op);
void bhEff026(O_WRK* op);
void bhDraw027(O_WRK* op);
void bhEff027(O_WRK* op);
void bhEff028();
void bhEff029(O_WRK* op);
void bhEff100(O_WRK* op);
void bhEff101(O_WRK* op);
void bhEff102(O_WRK* op);
void bhEff103(O_WRK* op);
void bhEff104(O_WRK* op);
void bhEff105(O_WRK* op);
void bhEff106(O_WRK* op);
void bhDraw107(O_WRK* op);
void bhEff107(O_WRK* op);
void bhEff108(O_WRK* op);
void bhEff109(O_WRK* op);
void bhEff110(O_WRK* op);
void bhEff111(O_WRK* op);
void bhEff112(O_WRK* op);
void bhEff113(O_WRK* op);
void bhDraw114(O_WRK* op);
void bhEff114(O_WRK* op);
void bhEff115(O_WRK* op);
void bhEff116(O_WRK* op);
void bhEff117(O_WRK* op);
void bhEff118(O_WRK* op);
void bhEff119(O_WRK* op);
void bhEff120(O_WRK* op);
void bhEff121(O_WRK* op);
void bhEff122(O_WRK* op);
void bhEff123(O_WRK* op);
void bhEff124(O_WRK* op);
void bhEff125(O_WRK* op);
void bhEff126(O_WRK* op);
void bhEff127(O_WRK* op);
void bhEff128(O_WRK* op);
void bhEff129();
void bhEff130(O_WRK* op);
void bhEff131(O_WRK* op);
void bhEff132(O_WRK* op);

#endif
