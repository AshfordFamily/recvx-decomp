#ifndef _EN22_H_
#define _EN22_H_

#include "types.h"
#include "macros.h"

typedef struct EN22_ATB_WORK
{
    // total size: 0x8
    int frm;            // offset 0x0, size 0x4
    unsigned int act;   // offset 0x4, size 0x4
} EN22_ATB_WORK;

typedef struct EN22_MTN_WORK
{
    // total size: 0x24
    int no;                 // offset 0x0, size 0x4
    EN22_ATB_WORK atb[4];   // offset 0x4, size 0x20
} EN22_MTN_WORK;

typedef struct EN22_POINT2_XZ
{
    // total size: 0x8
    float px;   // offset 0x0, size 0x4
    float pz;   // offset 0x4, size 0x4
} EN22_POINT2_XZ;

typedef struct EN22_WEFF_WORK
{
    // total size: 0xC
    int mtn;    // offset 0x0, size 0x4
    int frm;    // offset 0x4, size 0x4
    int obj;    // offset 0x8, size 0x4
} EN22_WEFF_WORK, EN22_WSP_WORK;

void bhEne22_DmmyBrain(BH_PWORK* epw);
void bhEne22(BH_PWORK* epw);
void bhEne22_MainLoop(BH_PWORK* epw);
int bhEne22_DmgChk(BH_PWORK* epw);
void bhEne22_ChgDmgMode(BH_PWORK* epw);
void bhEne22_DamageAdd(BH_PWORK* epw);
void bhEne22_CollCheck(BH_PWORK* epw);
void bhEne22_CollCheckWall(BH_PWORK* epw);
void bhEne22_Init(BH_PWORK* epw);
void bhEne22_InitType00(BH_PWORK* epw);
void bhEne22_Move(BH_PWORK* epw);
void bhEne22_Nage(BH_PWORK* epw);
void bhEne22_Damage(BH_PWORK* epw);
void bhEne22_Die(BH_PWORK* epw);
void bhEne22_PlyerHitCheck(BH_PWORK* pl, BH_PWORK* epw);
void bhEne22_EneSearch(BH_PWORK* epw);
void bhEne22_Brain(BH_PWORK* epw);
void bhEne22_Brain00(BH_PWORK* epw);
void bhEne22_Brain01(BH_PWORK* epw);
void bhEne22_Brain02(BH_PWORK* epw);
void bhEne22_Brain04(BH_PWORK* epw);
void bhEne22_MVType00(BH_PWORK* epw);
void bhEne22_MV00(BH_PWORK* epw);
void bhEne22_MV01(BH_PWORK* epw);
void bhEne22_MV02(BH_PWORK* epw);
void bhEne22_MV03(BH_PWORK* epw);
void bhEne22_MV04(BH_PWORK* epw);
void bhEne22_MV05(BH_PWORK* epw);
void bhEne22_MV06(BH_PWORK* epw);
void bhEne22_DGType00(BH_PWORK* epw);
void bhEne22_DG00(BH_PWORK* epw);
void bhEne22_DG01(BH_PWORK* epw);
void bhEne22_DG02(BH_PWORK* epw);
void bhEne22_DDType00(BH_PWORK* epw);
void bhEne22_DD00(BH_PWORK* epw);
void bhEne22_DD01(BH_PWORK* epw);
void bhEne22_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne22_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
int bhEne22_SetMtn(BH_PWORK* epw);
void bhEne22_CheckMtnTbl(BH_PWORK* epw, int frm);
void bhEne22_GetTranslateMtn(BH_PWORK* epw, int frm);
void bhEne22_SparkEffect(BH_PWORK* epw, int frm);
unsigned int* bhEne22_GetDengekiColorAddr(NJS_CNK_OBJECT* objp, int no);
void bhEne22_SetWaterEffect(BH_PWORK* epw, int mtn_no, int frm);
int bhEne22_GetAreaNo(float px, float pz);
int bhEne22_AreaCheck(float ene_x, float ene_z, float ply_x, float ply_z);
int bhEne22_SetTrgPos(BH_PWORK* epw);
void bhEne22_SePlay(BH_PWORK* epw, NJS_POINT3* ps, int no);
O_WRK* bhEne22_SetDengekiEffect(BH_PWORK* epw, int obj, NJS_POINT3* ofs, float size);
void bhEne22_SetDengekiEffect2(BH_PWORK* epw);
void bhEne22_SetElectricShockEffect(BH_PWORK* epw, int type);
void bhEne22_SetElectricShockEffect2(BH_PWORK* epw);
O_WRK* bhEne22_SetElectricLightEffect(BH_PWORK* epw);
void bhEne22_SetLight(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int type);
void bhEne22_CtrLight(BH_PWORK* epw);
void bhEne22_ChgDengekiColor(NJS_CNK_OBJECT* objp, int no, unsigned int argb);

#endif
