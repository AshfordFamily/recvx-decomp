#ifndef _EN09_H_
#define _EN09_H_

#include "types.h"
#include "macros.h"

typedef struct CHG_TBL_WORK
{
	signed int mtn_no; // offset 0x0, size 0x4
    signed int type; // offset 0x4, size 0x4
    signed int frm_no; // offset 0x8, size 0x4
    unsigned int h_cnt; // offset 0xC, size 0x4
    unsigned int mode; // offset 0x10, size 0x4
} CHG_TBL_WORK;

typedef struct CHK_TBL_WORK
{
    signed int mtn_no; // offset 0x0, size 0x4
    signed int s_frm; // offset 0x4, size 0x4
    signed int e_frm; // offset 0x8, size 0x4
    CHG_TBL_WORK chg_tbl[4]; // offset 0xC, size 0x50
} CHK_TBL_WORK;

typedef struct ARM_POS
{
    signed int frm; // offset 0x0, size 0x4
    float len; // offset 0x4, size 0x4
} ARM_POS;

void bhEne09_DmmyBrain();
void bhEne09(BH_PWORK* epw);
void bhEne09_MainLoop(BH_PWORK* epw);
void bhEne09_PlayerControl(BH_PWORK* pl, BH_PWORK* epw);
void bhEne09_CalcEnemy(BH_PWORK* epw);
void bhEne09_CollCheck(BH_PWORK* epw);
void bhEne09_CollCheckWall(BH_PWORK* epw);
void bhEne09_CollCheckArm();
void bhEne09_Init(BH_PWORK* epw);
void bhEne09_Move(BH_PWORK* epw);
void bhEne09_Damage(BH_PWORK* epw);
void bhEne09_Nage(BH_PWORK* epw);
void bhEne09_Die(BH_PWORK* epw);
int bhEne09_DmgCheck(BH_PWORK* epw);
void bhEne09_ChgDmgMode(BH_PWORK* epw);
int bhEne09_ExDmgCheck(BH_PWORK* epw);
void bhEne09_DamageAdd(BH_PWORK* epw);
void bhEne09_PlayerLink(BH_PWORK* pl, BH_PWORK* epw);
void bhEne09_MVType00(BH_PWORK* epw);
void bhEne09_MVType09(BH_PWORK* epw);
void bhEne09_MVType10(BH_PWORK* epw);
void bhEne09_EneSearch(BH_PWORK* epw);
void bhEne09_Brain(BH_PWORK* epw);
int bhEne09_OtherEnemyCheck(BH_PWORK* epw, float dist, int ang);
ATR_WORK* bhEne09_GetCloseEnemyAtari(BH_PWORK* epw, unsigned char type, unsigned char id);
int bhEne09_JumpCheck(BH_PWORK* epw, ATR_WORK* hp);
void bhEne09_Brain00(BH_PWORK* epw);
int bhEne09_AttackCheck(BH_PWORK* epw, int mode);
int bhEne09_AramLineCheck(BH_PWORK* epw, NJS_VECTOR* p1, NJS_VECTOR* p2);
void bhEne09_MV00(BH_PWORK* epw);
void bhEne09_MV01(BH_PWORK* epw);
void bhEne09_MV02();
void bhEne09_MV03(BH_PWORK* epw);
void bhEne09_MV04(BH_PWORK* epw);
void bhEne09_MV05(BH_PWORK* epw);
void bhEne09_MV06(BH_PWORK* epw);
void bhEne09_MV07(BH_PWORK* epw);
void bhEne09_MV08(BH_PWORK* epw);
void bhEne09_MV09(BH_PWORK* epw);
void bhEne09_MV10(BH_PWORK* epw);
void bhEne09_MV11(BH_PWORK* epw);
void bhEne09_MV12(BH_PWORK* epw);
void bhEne09_MV13(BH_PWORK* epw);
void bhEne09_MV14(BH_PWORK* epw);
void bhEne09_NGType00(BH_PWORK* epw);
void bhEne09_NG00(BH_PWORK* epw);
void bhEne09_NG01(BH_PWORK* epw);
void bhEne09_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne09_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
int bhEne09_PlyNageCheck(BH_PWORK* epw, BH_PWORK* pl, float h);
void bhEne09_DGType00(BH_PWORK* epw);
void bhEne09_DG00(BH_PWORK* epw);
void bhEne09_DG01(BH_PWORK* epw);
void bhEne09_DG02(BH_PWORK* epw);
void bhEne09_DG03(BH_PWORK* epw);
void bhEne09_DG04(BH_PWORK* epw);
void bhEne09_DG05(BH_PWORK* epw);
void bhEne09_DG06(BH_PWORK* epw);
void bhEne09_DG07(BH_PWORK* epw);
void bhEne09_DG08(BH_PWORK* epw);
void bhEne09_DG09(BH_PWORK* epw);
void bhEne09_DG10(BH_PWORK* epw);
void bhEne09_DDType00(BH_PWORK* epw);
void bhEne09_DD00(BH_PWORK* epw);
int bhEne09_CollChkArm(BH_PWORK* epw, BH_PWORK* trg);
int bhEne09_CollChkArm2(BH_PWORK* epw);
float bhEne09_ChkArmLen2(BH_PWORK* epw);
ATR_WORK* bhEne09_ChkArmLen(BH_PWORK* epw, float* len, NJS_VECTOR* vec);
int bhEne09_ChkDiffAngle(int pang, int dang);
int bhEne09_SetMtn(BH_PWORK* epw);
void bhEne09_MtnTblPlay(BH_PWORK* epw, int frm);
void bhEne09_SePlay(BH_PWORK* epw, int no);
void bhEne09_SetSmokeEffect(BH_PWORK* epw, NJS_VECTOR* ofs, int rot);

#endif
