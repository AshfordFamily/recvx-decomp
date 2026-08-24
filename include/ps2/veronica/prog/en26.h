#ifndef _EN26_H_
#define _EN26_H_

#include "types.h"
#include "macros.h"

typedef struct EN26_WPNDAMAGE_WORK
{
    // total size: 0x1C
    int flg;        // offset 0x0, size 0x4
    int nm_act;     // offset 0x4, size 0x4
    int nm_blood;   // offset 0x8, size 0x4
    int cb_act;     // offset 0xC, size 0x4
    int cb_blood;   // offset 0x10, size 0x4
    int dw_act;     // offset 0x14, size 0x4
    int dw_blood;   // offset 0x18, size 0x4
} EN26_WPNDAMAGE_WORK;

typedef struct EN26_FIRE_WORK
{
    // total size: 0x18
    int obj;        // offset 0x0, size 0x4
    float size;     // offset 0x4, size 0x4
    float len;      // offset 0x8, size 0x4
	NJS_POINT3 ofs; // offset 0xC, size 0xC
} EN26_FIRE_WORK;

typedef struct EN26_KAMI_WORK
{
    // total size: 0xC
    int mtn_no;     // offset 0x0, size 0x4
    short frm[4];   // offset 0x4, size 0x8
} EN26_KAMI_WORK;

typedef struct EN26_FMTN_WORK
{
    // total size: 0xC
	int type;   // offset 0x0, size 0x4
	int s_frm;  // offset 0x4, size 0x4
	int e_frm;  // offset 0x8, size 0x4
} EN26_FMTN_WORK;

typedef struct EN26_ATB_WORK
{
    // total size: 0x8
	int frm;            // offset 0x0, size 0x4
	unsigned int act;   // offset 0x4, size 0x4
} EN26_ATB_WORK;

typedef struct EN26_MTN_WORK
{
    // total size: 0x28
	int no;                 // offset 0x0, size 0x4
	EN26_FMTN_WORK fmtn[3]; // offset 0x4, size 0x24
} EN26_MTN_WORK;

typedef struct EN26_MTN2_WORK
{
    // total size: 0x24
	int no;                 // offset 0x0, size 0x4
	EN26_ATB_WORK atb[4];   // offset 0x4, size 0x20
} EN26_MTN2_WORK;

void bhEne26(BH_PWORK* epw);
void bhEne26_DmgCheck(BH_PWORK* epw);
void bhEne26_DamageAdd(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl);
void bhEne26_LinkFireEffect(BH_PWORK* epw, int type);
void bhEne26_DmgCheckType00(BH_PWORK* epw,  EN26_WPNDAMAGE_WORK* wp_tbl);
int bhEne26_CheckExpHead(BH_PWORK* epw);
void bhEne26_SetBlood(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl);
void bhEne26_MainLoop(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_PlayerControl(BH_PWORK* epw, BH_PWORK* pl);
int bhEne26_SetMtn(BH_PWORK* epw);
void bhEne26_CheckMtnTbl(BH_PWORK* epw, int frm);
void bhEne26_SearchNeck(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_CollCheck(BH_PWORK* epw);
void bhEne26_CollCheckWall(BH_PWORK* epw);
void bhEne26_PlayerLink(BH_PWORK* epw, BH_PWORK* pl);
void bhEne26_CalcEnemy(BH_PWORK* epw);
void bhEne26_Init(BH_PWORK* epw);
void bhEne26_Move(BH_PWORK* epw);
void bhEne26_MVType(BH_PWORK* epw);
void bhEne26_EneSearch(BH_PWORK* epw);
void bhEne26_Brain00(BH_PWORK* epw);
int bhEne26_ActionModeCheck(BH_PWORK* epw);
void bhEne26_MV00(BH_PWORK* epw);
void bhEne26_MV01(BH_PWORK* epw);
void bhEne26_MV02(BH_PWORK* epw);
void bhEne26_MV03(BH_PWORK* epw);
void bhEne26_MV05(BH_PWORK* epw);
void bhEne26_MV06(BH_PWORK* epw);
void bhEne26_MV07(BH_PWORK* epw);
void bhEne26_MV16(BH_PWORK* epw);
void bhEne26_Nage(BH_PWORK* epw);
void bhEne26_NGType(BH_PWORK* epw);
void bhEne26_NG00(BH_PWORK* epw);
void bhEne26_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne26_Damage(BH_PWORK* epw);
void bhEne26_DGType(BH_PWORK* epw);
void bhEne26_DG00();
void bhEne26_DG01();
void bhEne26_DG02(BH_PWORK* epw);
void bhEne26_DG03(BH_PWORK* epw);
void bhEne26_DG04(BH_PWORK* epw);
void bhEne26_DG15(BH_PWORK* epw);
void bhEne26_Die(BH_PWORK* epw);
void bhEne26_DDType(BH_PWORK* epw);
void bhEne26_DD00(BH_PWORK* epw);
int bhEne26_EatCheck(BH_PWORK* epw, int rng, float dist, int mode);
void bhEne26_ExpHeadEffect(BH_PWORK* epw, int unused); // different from DWARF
void bhEne26_NeckBloodEffect(BH_PWORK* epw, int type);
void bhEne26_KamiEffect(BH_PWORK* epw, int frm);
void bhEne26_SePlay(BH_PWORK* epw, int no);

#endif
