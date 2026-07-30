#ifndef _EFFSUB5_H_
#define _EFFSUB5_H_

#include "types.h"

typedef struct EFF5UV 
{
    // total size: 0x4
    short u; // offset 0x0, size 0x2
    short v; // offset 0x2, size 0x2
} EFF5UV;

typedef struct EFF5UVWH 
{
    // total size: 0x8
    short u; // offset 0x0, size 0x2
    short v; // offset 0x2, size 0x2
    short w; // offset 0x4, size 0x2
    short h; // offset 0x6, size 0x2
} EFF5UVWH;

typedef struct EFF5UVTBL 
{
    // total size: 0x18
    EFF5UV* pTblTop;        // offset 0x0, size 0x4
    int lTblMax;            // offset 0x4, size 0x4
    int lTexID;             // offset 0x8, size 0x4
    int lAniCt;             // offset 0xC, size 0x4
    int lPaletteBankOffset; // offset 0x10, size 0x4
    short w;                // offset 0x14, size 0x2
    short h;                // offset 0x16, size 0x2
} EFF5UVTBL;

typedef struct EFF5UVWHUC 
{
    // total size: 0x4
    unsigned char u; // offset 0x0, size 0x1
    unsigned char v; // offset 0x1, size 0x1
    unsigned char w; // offset 0x2, size 0x1
    unsigned char h; // offset 0x3, size 0x1
} EFF5UVWHUC;

typedef struct EFF5SNOWGRP 
{
    // total size: 0x8
    NJS_POINT3* pPointTop; // offset 0x0, size 0x4
    int lPointMax;         // offset 0x4, size 0x4
} EFF5SNOWGRP;

typedef struct EFF5SNOWRECT 
{
    // total size: 0x160
    unsigned int flg;             // offset 0x0, size 0x4
    unsigned int ulFrame;         // offset 0x4, size 0x4
    NJS_POINT3 AreaCenter;        // offset 0x8, size 0xC
    float fAreaSizeX;             // offset 0x14, size 0x4
    float fAreaSizeY;             // offset 0x18, size 0x4
    float fAreaSizeZ;             // offset 0x1C, size 0x4
    float fAreaMinX;              // offset 0x20, size 0x4
    float fAreaMaxX;              // offset 0x24, size 0x4
    float fAreaMinY;              // offset 0x28, size 0x4
    float fAreaMaxY;              // offset 0x2C, size 0x4
    float fAreaMinZ;              // offset 0x30, size 0x4
    float fAreaMaxZ;              // offset 0x34, size 0x4
    int lSnowTotalMax;            // offset 0x38, size 0x4
    EFF5SNOWGRP SnowGrp[20];      // offset 0x3C, size 0xA0
    int lSnowGrpMax;              // offset 0xDC, size 0x4
    NJS_VECTOR* pSnowVector;      // offset 0xE0, size 0x4
    int lSnowExistPrev;           // offset 0xE4, size 0x4
    int lSnowExistCrnt;           // offset 0xE8, size 0x4
    int lSnowExistNext;           // offset 0xEC, size 0x4
    int lSnowTimerCnt;            // offset 0xF0, size 0x4
    int lSnowTimerMax;            // offset 0xF4, size 0x4
    NJS_TEXLIST* pSnowTexList;    // offset 0xF8, size 0x4
    unsigned int ulSnowTexNum;    // offset 0xFC, size 0x4
    NJS_TEXTURE_VTX SnowModel[4]; // offset 0x100, size 0x60
} EFF5SNOWRECT;

void bhEff200(O_WRK* op);
void bhEff201(O_WRK* op);
void bhEff202(O_WRK* op);
void bhEff203(O_WRK* op);
void bhEff204(O_WRK* op);
void bhEff205(O_WRK* op);
void bhEff206(O_WRK* op);
void bhEff207(O_WRK* op);
void bhEff208(O_WRK* op);
void bhEff209(O_WRK* op);
void bhEff210(O_WRK* op);
void bhEff211(O_WRK* op);
void bhEff212(O_WRK* op);
void bhEff213(O_WRK* op);
void bhEff214(O_WRK* op);
void bhEff215(O_WRK* op);
void bhEff216(O_WRK* op);
void bhEff217(O_WRK* op);
void bhEff218(O_WRK* op);
void bhEff219(O_WRK* op);
void bhEff220(O_WRK* op);
void bhEff221(O_WRK* op);
void bhDrawEff221(O_WRK* op);
void bhEff222(O_WRK* op);
void bhEff223(O_WRK* op);
void bhEff224(O_WRK* op);
void bhEff225(O_WRK* op);
void bhEff226(O_WRK* op);
void bhEff227(O_WRK* op);
void bhEff228(O_WRK* op);
void bhEff229(O_WRK* op);
void bhDrawWeaponEffect2(O_WRK* op);
void bhEff230(O_WRK* op);
void bhEff231(O_WRK* op);
void bhEff232(O_WRK* op);
void bhEff233(O_WRK* op);
void bhEff234(O_WRK* op);
void bhEff235(O_WRK* op);
void bhEff236(O_WRK* op);
void bhDrawEff236(O_WRK* op);
void bhEff237(O_WRK* op);
void bhEff238(O_WRK* op);
void bhEff239(O_WRK* op);
void bhEff240(O_WRK* op);
void bhEff241(O_WRK* op);
void bhEff242(O_WRK* op);
void bhEff243(O_WRK* op);
void bhDrawEff243(O_WRK* op);
void bhEff244(O_WRK* op);
void bhEff245(O_WRK* op);
void bhEff246(O_WRK* op);
void bhEff247(O_WRK* op);
void bhEff248(O_WRK* op);
void bhEff249(O_WRK* op);
EFF5SNOWRECT* CreateEff5SnowRect(int lSnowMax);
void DeleteEff5SnowRect(EFF5SNOWRECT* pSnow);
void ExecEff5SnowRect(EFF5SNOWRECT* pSnow);
void DrawEff5SnowRect(O_WRK* op);
void SetEff5SnowRectAreaCenter(EFF5SNOWRECT* pSnow, float fPointX, float fPointY, float fPointZ);
void SetEff5SnowRectAreaCenterAndSize(EFF5SNOWRECT* pSnow, float fCenterX, float fCenterY, float fCenterZ, float fSizeX, float fSizeY, float fSizeZ);
void SetEff5SnowRectParticleMax(EFF5SNOWRECT* pSnow, int lSnowMax);
void MovEff5SnowRectParticleMax(EFF5SNOWRECT* pSnow, int lSnowMax, int lTimeMax);
void ArrangeEff5SnowRectParticle(EFF5SNOWRECT* pSnow);
void SetEff5SnowRectParticleTexture(EFF5SNOWRECT* pSnow, NJS_TEXLIST* pTexList, unsigned int ulTexNum, float fU0, float fV0, float fU1, float fV1, float fU2, float fV2, float fU3, float fV3);
void SetEff5SnowRectParticleColor(EFF5SNOWRECT* pSnow, unsigned int ulColor0, unsigned int ulColor1, unsigned int ulColor2, unsigned int ulColor3);
void SetEff5SnowRectParticleSize(EFF5SNOWRECT* pSnow, float fWidth, float fHeight);
NJS_VECTOR* GetEff5SnowRectCurrentWindVector(void* unused, NJS_VECTOR* pVector);

#endif
