#ifndef _EN02_H_
#define _EN02_H_

#include "types.h"

typedef struct EN02_WE_WORK 
{
    // total size: 0x14
    unsigned int frm_no; // offset 0x0, size 0x4
    float ofx;           // offset 0x4, size 0x4
    float ofy;           // offset 0x8, size 0x4
    float ofz;           // offset 0xC, size 0x4
    unsigned int size;   // offset 0x10, size 0x4
} EN02_WE_WORK;

typedef struct EN02_SANDEFFECTTBL_WORK 
{
    // total size: 0xC
    int mtn_no;       // offset 0x0, size 0x4
    EN02_WE_WORK* we; // offset 0x4, size 0x4
    unsigned int num; // offset 0x8, size 0x4
} EN02_SANDEFFECTTBL_WORK;

void bhEne02(BH_PWORK* epw);
void bhEne02_Init(BH_PWORK* epw);
void bhEne02_Brain(BH_PWORK* epw);
void bhEne02_BR00(BH_PWORK* epw);
void bhEne02_Move(BH_PWORK* epw);
void bhEne02_MV00(BH_PWORK* epw);
void bhEne02_MV02(BH_PWORK* epw);
void bhEne02_MV03(BH_PWORK* epw);
void bhEne02_MV04(BH_PWORK* epw);
void bhEne02_MV05(BH_PWORK* epw);
void bhEne02_Nage();
void bhEne02_Damage(BH_PWORK* epw);
void bhEne02_DG00();
void bhEne02_DG01(BH_PWORK* epw);
void bhEne02_Die(BH_PWORK* epw);
void bhEne02_DD00(BH_PWORK* epw);
void bhEne02_DD01(BH_PWORK* epw);
void bhEne02_SetSandEffect(BH_PWORK* epw, NJS_POINT3* pos, int type);
void bhEne02_SetSandEffectEV(int eno, int type1, int type2);
void bhEne02_SetSandEffectMain(int type0, NJS_POINT3* pos, int type);
void bhEne02_SetSandSpr(int type0, NJS_POINT3* pos, int type, int flip, float size, int ang);
void bhEne02_SandEffect(BH_PWORK* epw);
void bhEne02_SandEffectP(BH_PWORK* epw);
void bhEne02_PlayerControl(BH_PWORK* epw);
void bhEne02_DamageInit(BH_PWORK* epw);
void bhEne02_SetSandParticle(NJS_POINT3* pos, int type);
void bhEne02_CheckWall(BH_PWORK* epw);
void bhEne02_CameraControl(BH_PWORK* epw);
void bhEne02_WarpCheck(BH_PWORK* epw);
void bhEne02_FallingRock(BH_PWORK* epw);
void bhEne02_CallSE(BH_PWORK* epw);
void bhEne02_HitMark(BH_PWORK* epw);

#endif
