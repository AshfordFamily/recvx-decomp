#ifndef _EN01_H_
#define _EN01_H_

#include "types.h"
#include "macros.h"

typedef struct EN01_PERSONAL_TYPE
{
	// total size: 0x14
    float adist; // offset 0x0, size 0x4
    float ndist; // offset 0x4, size 0x4
    int ang;     // offset 0x8, size 0x4
    int add_hp;  // offset 0xC, size 0x4
    int add_atk; // offset 0x10, size 0x4
} EN01_PERSONAL_TYPE;

typedef struct EN01_CHG_WORK
{
    // total size: 0x24
    unsigned int mode;          // offset 0x0, size 0x4
    unsigned int clr_flg;       // offset 0x4, size 0x4
    unsigned int set_flg;       // offset 0x8, size 0x4
    int mtn_no1;                // offset 0xC, size 0x4
    int mtn_no2;                // offset 0x10, size 0x4
    int type;                   // offset 0x14, size 0x4
    int frm_no;                 // offset 0x18, size 0x4
    unsigned int hokan_count;   // offset 0x1C, size 0x4
    int mtn_add;                // offset 0x20, size 0x4
} EN01_CHG_WORK;

typedef struct EN01_CHK_WORK
{
    // total size: 0x54
    int mtn_no;                 // offset 0x0, size 0x4
    int sfrm;                   // offset 0x4, size 0x4
    int efrm;                   // offset 0x8, size 0x4
    EN01_CHG_WORK chg_tbl[2];   // offset 0xC, size 0x48
} EN01_CHK_WORK;

typedef struct EN01_EFF_WORK 
{
    // total size: 0xC
    short frm;  // offset 0x0, size 0x2
    char size;  // offset 0x2, size 0x1
    char obj;   // offset 0x3, size 0x1
    float px;   // offset 0x4, size 0x4
    float pz;   // offset 0x8, size 0x4
} EN01_EFF_WORK; 
     
typedef struct EN01_WATER_WORK 
{
    // total size: 0x28
    int mtn_no;             // offset 0x0, size 0x4
    EN01_EFF_WORK eff[3];   // offset 0x4, size 0x24
} EN01_WATER_WORK;

typedef struct EN01_FIRE_WORK
{
    // total size: 0x18
    int obj;        // offset 0x0, size 0x4
    float size;     // offset 0x4, size 0x4
    float len;      // offset 0x8, size 0x4
	NJS_POINT3 ofs; // offset 0xC, size 0xC
} EN01_FIRE_WORK;

typedef struct EN01_FMTN_WORK
{
    // total size: 0xC
	int type;   // offset 0x0, size 0x4
	int s_frm;  // offset 0x4, size 0x4
	int e_frm;  // offset 0x8, size 0x4
} EN01_FMTN_WORK;

typedef struct EN01_ATB_WORK
{
    // total size: 0x8
	int frm;            // offset 0x0, size 0x4
	unsigned int act;   // offset 0x4, size 0x4
} EN01_ATB_WORK;

typedef struct EN01_MTN_WORK
{
    // total size: 0x28
	int no;                 // offset 0x0, size 0x4
	EN01_FMTN_WORK fmtn[3]; // offset 0x4, size 0x24
} EN01_MTN_WORK;

typedef struct EN01_MTN2_WORK
{
    // total size: 0x24
	int no;                 // offset 0x0, size 0x4
	EN01_ATB_WORK atb[4];   // offset 0x4, size 0x20
} EN01_MTN2_WORK;

typedef struct EN01_KAMI_WORK
{
    // total size: 0xC
    int mtn_no;     // offset 0x0, size 0x4
    short frm[4];   // offset 0x4, size 0x8
} EN01_KAMI_WORK;

typedef struct EN01_FLYINGCAP_WORK
{
    // total size: 0x14
    int angY;     // offset 0x0, size 0x4
    int angZ;     // offset 0x4, size 0x4
    int rspd;     // offset 0x8, size 0x4
    float v;      // offset 0xC, size 0x4
    float point;  // offset 0x10, size 0x4
} EN01_FLYINGCAP_WORK;

void bhEne01_DmgCheckTypeDmmy();
void bhEne01(BH_PWORK* epw);
void bhEne01_MainLoop(BH_PWORK* epw);
void bhEne01_Init(BH_PWORK* epw);
BH_PWORK* bhEne01_SetLinkEnemy(BH_PWORK* epw, int lkono, short id);
void bhEne01_Move(BH_PWORK* epw);
void bhEne01_Nage(BH_PWORK* epw);
void bhEne01_Damage(BH_PWORK* epw);
void bhEne01_Die(BH_PWORK* epw);
void bhEne01_PlayerControl(BH_PWORK* pl, BH_PWORK* epw);
void bhEne01_SearchNeck(BH_PWORK* epw);
void bhEne01_PlayerLink(BH_PWORK* ply, BH_PWORK* epw);
void bhEne01_CalcEnemy(BH_PWORK* epw);
void bhEne01_DmgCheck(BH_PWORK* epw);
void bhEne01_SetBlood(BH_PWORK* epw, int hp);
void bhEne01_DmgCheckType00(BH_PWORK* epw);
int bhEne01_CheckExpHead(BH_PWORK* epw);
void bhEne01_DmgCheckType02(BH_PWORK* epw);
void bhEne01_DamageAdd(BH_PWORK* epw);
void bhEne01_PartsDamageCheck(BH_PWORK* epw);
int bhEne01_DmgModeJumpCheck(BH_PWORK* epw);
void bhEne01_CollCheck(BH_PWORK* epw);
void bhEne01_CollCheckPush(BH_PWORK* epw, BH_PWORK* top_epw);
int bhEne01_EnemyHitChk(BH_PWORK* epw, BH_PWORK* tepw, int rng);
void bhEne01_CollCheckWall(BH_PWORK* epw);
void bhEne01_InitType00(BH_PWORK* epw);
void bhEne01_InitType02(BH_PWORK* epw);
void bhEne01_InitType06(BH_PWORK* epw);
void bhEne01_InitType10(BH_PWORK* epw);
void bhEne01_InitType11(BH_PWORK* epw);
void bhEne01_InitType15(BH_PWORK* epw);
void bhEne01_EneSearch(BH_PWORK* epw);
void bhEne01_Brain00(BH_PWORK* epw);
void bhEne01_Brain02(BH_PWORK* epw);
int bhEne01_ActionModeCheck(BH_PWORK* epw);
void bhEne01_MVType00(BH_PWORK* epw);
void bhEne01_MVType02(BH_PWORK* epw);
void bhEne01_MV00(BH_PWORK* epw);
void bhEne01_MV01(BH_PWORK* epw);
void bhEne01_MV02(BH_PWORK* epw);
void bhEne01_MV03(BH_PWORK* epw);
void bhEne01_MV04(BH_PWORK* epw);
void bhEne01_MV05(BH_PWORK* epw);
void bhEne01_MV06(BH_PWORK* epw);
void bhEne01_MV07(BH_PWORK* epw);
void bhEne01_MV08(BH_PWORK* epw);
void bhEne01_MV09(BH_PWORK* epw);
void bhEne01_MV10(BH_PWORK* epw);
void bhEne01_MV11(BH_PWORK* epw);
void bhEne01_MV12(BH_PWORK* epw);
void bhEne01_MV14(BH_PWORK* epw);
void bhEne01_MV15(BH_PWORK* epw);
void bhEne01_MV16(BH_PWORK* epw);
void bhEne01_NGType00(BH_PWORK* epw);
void bhEne01_NG00(BH_PWORK* epw);
void bhEne01_NG01(BH_PWORK* epw);
void bhEne01_NG02(BH_PWORK* epw);
void bhEne01_PlyDG00(BH_PWORK* pl, BH_PWORK* epw);
void bhEne01_PlyDG01(BH_PWORK* pl, BH_PWORK* epw);
void bhEne01_EnemyPushChk(BH_PWORK* epw, int mode);
void bhEne01_DGType00(BH_PWORK* epw);
void bhEne01_DGType02(BH_PWORK* epw);
void bhEne01_DG00(BH_PWORK* epw);
void bhEne01_DG01(BH_PWORK* epw);
void bhEne01_DG02(BH_PWORK* epw);
void bhEne01_DG03(BH_PWORK* epw);
void bhEne01_DG04(BH_PWORK* epw);
void bhEne01_DG05(BH_PWORK* epw);
void bhEne01_DG06(BH_PWORK* epw);
void bhEne01_DG07(BH_PWORK* epw);
void bhEne01_DG08(BH_PWORK* epw);
void bhEne01_DG09(BH_PWORK* epw);
void bhEne01_DG10(BH_PWORK* epw);
void bhEne01_DG11(BH_PWORK* epw);
void bhEne01_DG14(BH_PWORK* epw);
void bhEne01_DG15(BH_PWORK* epw);
void bhEne01_DG16(BH_PWORK* epw);
void bhEne01_DDType00(BH_PWORK* epw);
void bhEne01_DDType02(BH_PWORK* epw);
void bhEne01_DD00(BH_PWORK* epw);
void bhEne01_DD01(BH_PWORK* epw);
void bhEne01_DD02(BH_PWORK* epw);
void bhEne01_DD03(BH_PWORK* epw);
void bhEne01_ChgWalkMtn(BH_PWORK* epw);
int bhEne01_SetMtn(BH_PWORK* epw);
void bhEne01_CheckMtnTbl(BH_PWORK* epw, int frm);
void bhEne01_KamiEffect(BH_PWORK* epw, int frm);
void bhEne01_WaterEffect(BH_PWORK* epw, int frm);
void bhEne01_NeckBloodEffect(BH_PWORK* epw, int type);
void bhEne01_NeckBloodEffect2(BH_PWORK* epw, int type);
void bhEne01_ExpHeadEffect(BH_PWORK* epw, int unused); // different from DWARF
void bhEne01_ExpHeadEffect2(BH_PWORK* epw, int type);
void bhEne01_NikuhenEffect(BH_PWORK* epw, NJS_POINT3* ps, int n);
void bhEne01_ExpLegEffect(BH_PWORK* epw, int lnk_obj);
void bhEne01_ExpWormEffect(BH_PWORK* epw);
void bhEne01_PoisonEffect(BH_PWORK* epw, int num);
void bhEne01_LinkFireEffect(BH_PWORK* epw, int type);
int bhEne01_ChgTextID(BH_PWORK* epw, int tex_id);
void bhEne01_SePlay(BH_PWORK* epw, NJS_POINT3* pos, int no);
void bhEne01_GetWalkMotion(BH_PWORK* epw);
int bhEne01_FastCheck(BH_PWORK* epw);
int bhEne01_CmnFlgCheck(BH_PWORK* epw);
int bhEne01_FastWalkCheck(BH_PWORK* epw);
int bhEne01_ZulzulCheck(BH_PWORK* epw, int ang, float len, NJS_POINT3* get_pos, int* wang);
int bhEne01_GakeotiCheck(BH_PWORK* epw);
int bhEne01_DansaCheck(BH_PWORK* epw, int ang, float ofs_z);
int bhEne01_PoisonCheck(BH_PWORK* epw);
int bhEne01_EatCheck(BH_PWORK* epw, int rng, float dist, int mode);
int bhEne01_WormCheck(BH_PWORK* epw);
int bhEne01_KaidanCheck(BH_PWORK* epw);
int bhEne01_CutLeg(BH_PWORK* epw);
void bhEne01_CutHead(BH_PWORK* epw, int unused); // different from DWARF
void bhEne01_FlyingCap(BH_PWORK* epw, int tbl_no);

extern NJS_POINT2_XZ cl_mtn01_xz[60];
extern NJS_POINT2_XZ cl_mtn02_xz[60];
extern NJS_POINT2_XZ cl_mtn04_xz[50];
extern NJS_POINT2_XZ cl_mtn05_xz[50];
extern NJS_POINT2_XZ ch_mtn01_xz[60];
extern NJS_POINT2_XZ ch_mtn02_xz[60];
extern NJS_POINT2_XZ ch_mtn04_xz[50];
extern NJS_POINT2_XZ ch_mtn05_xz[50];
extern NJS_POINT2_XZ st_mtn01_xz[60];
extern NJS_POINT2_XZ st_mtn02_xz[60];
extern NJS_POINT2_XZ st_mtn04_xz[50];
extern NJS_POINT2_XZ st_mtn05_xz[50];
extern const float en01_kamikami[71];
extern const float en01_kamikami2[70];
extern const float en01_mogmog[40];
extern BP_WORK en01_BldTbl;
extern BP_WORK en01_BldTbl2;
extern int kaidan_ang[4];
extern int En01_PlyMtn_OffsetTbl[4];

#endif
