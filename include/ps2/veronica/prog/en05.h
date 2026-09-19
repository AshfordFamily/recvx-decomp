#ifndef _EN05_H_
#define _EN05_H_

#include "types.h"
#include "macros.h"

// total size: 0x10
typedef struct EN05_WE_WORK 
{
    // Members
    unsigned int frm_no; // offset 0x0, size 0x4
    float ofx; // offset 0x4, size 0x4
    float ofz; // offset 0x8, size 0x4
    unsigned int size; // offset 0xC, size 0x4
} EN05_WE_WORK;

// total size: 0xC
typedef struct EN05_WATER_EFFECT_WORK
{
    // Members
    signed int mtn_no; // offset 0x0, size 0x4
    EN05_WE_WORK* we; // offset 0x4, size 0x4
    unsigned int num; // offset 0x8, size 0x4
} EN05_WATER_EFFECT_WORK;

// total size: 0x1C
typedef struct EN05_SWITCH_WORK
{
    // Members
    signed short kmno; // offset 0x0, size 0x2
    signed short fno0; // offset 0x2, size 0x2
    signed short fno1; // offset 0x4, size 0x2
    signed short mno; // offset 0x6, size 0x2
    signed short fno; // offset 0x8, size 0x2
    signed int hrate; // offset 0xC, size 0x4
    unsigned int hcnt; // offset 0x10, size 0x4
    unsigned char mode2; // offset 0x14, size 0x1
    unsigned char mode3; // offset 0x15, size 0x1
    signed int ct0; // offset 0x18, size 0x4
} EN05_SWITCH_WORK;

void bhEne05(BH_PWORK* epw);
void bhEne05_Init(BH_PWORK* epw);
void bhEne05_Brain(BH_PWORK* epw);
void bhEne05_BR00(BH_PWORK* epw);
void bhEne05_BR01();
void bhEne05_BR02(BH_PWORK* epw);
void bhEne05_Move(BH_PWORK* epw);
void bhEne05_MV00(BH_PWORK* epw);
void bhEne05_MV01(BH_PWORK* epw);
void bhEne05_MV02(BH_PWORK* epw);
void bhEne05_MV03(BH_PWORK* epw);
void bhEne05_MV04();
void bhEne05_MV05(BH_PWORK* epw);
void bhEne05_MV06(BH_PWORK* epw);
void bhEne05_MV07(BH_PWORK* epw);
void bhEne05_MV08(BH_PWORK* epw);
void bhEne05_MV09(BH_PWORK* epw);
void bhEne05_MV10(BH_PWORK* epw);
void bhEne05_MV11(BH_PWORK* epw);
void bhEne05_MV12(BH_PWORK* epw);
void bhEne05_MV13(BH_PWORK* epw);
void bhEne05_MV14(BH_PWORK* epw);
void bhEne05_MV15(BH_PWORK* epw);
void bhEne05_MV16(BH_PWORK* epw);
void bhEne05_MV17(BH_PWORK* epw);
void bhEne05_Nage();
void bhEne05_Damage(BH_PWORK* epw);
void bhEne05_DG00(BH_PWORK* epw);
void bhEne05_DG01();
void bhEne05_DG02(BH_PWORK* epw);
void bhEne05_DG03(BH_PWORK* epw);
void bhEne05_DG04(BH_PWORK* epw);
void bhEne05_DG05(BH_PWORK* epw);
void bhEne05_DG06(BH_PWORK* epw);
void bhEne05_DG07(BH_PWORK* epw);
void bhEne05_DG08(BH_PWORK* epw);
void bhEne05_DG09(BH_PWORK* epw);
void bhEne05_DG10(BH_PWORK* epw);
void bhEne05_DG11(BH_PWORK* epw);
void bhEne05_DG12(BH_PWORK* epw);
void bhEne05_DG13(BH_PWORK* epw);
void bhEne05_ChainDamage(BH_PWORK* epw);
void bhEne05_Die(BH_PWORK* epw);
void bhEne05_DD00(BH_PWORK* epw);
void bhEne05_DD01(BH_PWORK* epw);
void bhEne05_DD02(BH_PWORK* epw);
void bhEne05_DD03(BH_PWORK* epw);
void bhEne05_DD04(BH_PWORK* epw);
void bhEne05_DD05(BH_PWORK* epw);
void bhEne05_DD06(BH_PWORK* epw);
void bhEne05_DD07(BH_PWORK* epw);
void bhEne05_DD08(BH_PWORK* epw);
void bhEne05_SearchPlayer(BH_PWORK* epw);
void bhEne05_MotionPause(BH_PWORK* epw, char* parts);
void bhEne05_SetMotionFlg(BH_PWORK* epw, unsigned int flg, unsigned char mode);
void bhEne05_FixedLegPos(BH_PWORK* epw);
void bhEne05_CheckWall(BH_PWORK* epw);
int bhEne05_CheckLeaningWall(BH_PWORK* epw, int flg);
void bhEne05_FloorCollision(BH_PWORK* epw);
void bhEne05_SetWeponAtr(BH_PWORK* epw);
void bhEne05_InitDamage(BH_PWORK* epw);
void bhEne05_WaterEffect(BH_PWORK* epw);
void bhEne05_PlayerControl(BH_PWORK* epw);
int bhEne05_CheckJump(BH_PWORK* epw);
int bhEne05_CheckBackAttack(BH_PWORK* epw);
int bhEne05_CheckHikkaki(BH_PWORK* epw);
int bhEne05_CheckPlyRoute(BH_PWORK* epw);
void bhEne05_HitMark(BH_PWORK* epw);
void bhEne05_DustEffect(BH_PWORK* epw, int unk);
void bhEne05_CallSE(BH_PWORK* epw);

#endif
