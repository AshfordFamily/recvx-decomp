#include "../../../ps2/veronica/prog/en15.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/pwksub.h"

//#include <string.h>

// ENEMY: Nosferatu 

#pragma optimization_level 4

static char dbgout_buf[256];
static char poison_attack_wait;
static char poison_eff_wait;

static WPNDG_TBL WpnDamageTbl[21] = 
{
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 0, 2, 2 },  
    { 2, 2, 2 },  
    { 0, 0, 0 },  
    { 0, 0, 0 },  
    { 2, 1, 1 },  
    { 0, 0, 0 },  
    { 2, 1, 2 },  
    { 0, 1, 1 },  
    { 2, 0, 1 },  
    { 2, 0, 0 },  
    { 2, 0, 0 },  
    { 1, 0, 0 },  
    { 1, 0, 0 },  
    { 2, 2, 2 },  
    { 0, 0, 0 },  
    { 2, 2, 2 }  
};
static COMBWEP_WORK CombWepTbl[21] = 
{
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  40, { 10,  0,  0 }, 30, 0 },
    {  70, { 10,  8,  0 }, 60, 0 },
    {  70, { 10,  8,  0 }, 60, 0 },
    {  40, { 10,  8,  0 }, 30, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  70, { 10,  8,  0 }, 30, 0 },
    { 160, { 10,  8,  0 }, 40, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  80, { 10,  8,  0 }, 70, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  60, { 10,  8,  0 }, 60, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
	{   0, {  0,  0,  0 },  0, 0 }
};
static COMBJOINT_WORK CombJointTbl[24] = { 0 };
static COMBO_EFF Combo_Eff[21] = 
{
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 1, 0, 0 }, {  1,  0, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } },  
    { { 0, 0, 0 }, { -1, -1, -1 } }  
};
static char SdwTab[3]= { 20, 23, -1 };
static BT_WORK prt_blood_tbl[24]= 
{
    {  0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    {  1, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  2, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  3, 0.0f, 2.0f, 1.8f, 2.0f, 5.0f, 1.0f, 5.0f },
    {  4, 0.0f, 2.0f, 1.8f, 2.0f, 3.0f, 1.0f, 3.0f },
    {  5, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  6, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  7, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    {  8, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    {  9, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 10, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 11, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 12, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 13, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 14, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 15, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 4.0f },
    { 16, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 17, 0.0f, 2.0f, 1.8f, 2.0f, 2.0f, 1.0f, 3.0f },
    { 18, 0.0f, 0.0f, 1.8f, 2.0f, 4.0f, 1.0f, 4.0f },
    { 19, 0.0f, 2.0f, 1.0f, 1.0f, 4.0f, 1.0f, 4.0f },
    { 20, 0.0f, 2.0f, 1.0f, 1.0f, 3.0f, 1.0f, 3.0f },
    { 21, 0.0f, 0.0f, 1.8f, 2.0f, 4.0f, 1.0f, 4.0f },
    { 22, 0.0f, 2.0f, 1.0f, 1.0f, 4.0f, 1.0f, 4.0f },
    { 23, 0.0f, 2.0f, 1.0f, 1.0f, 3.0f, 1.0f, 3.0f }
};
static char rfoot_joint_tree[6] = { 0, 1, 18, 19, 20, -1 };
static char lfoot_joint_tree[6] = { 0, 1, 21, 22, 23, -1 };
static LEGLOCK_LIST lrl_walk[2] = 
{
    { 40, 74 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_a1[2] = 
{
    { 64, 93 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_a2[2] = 
{
    { 25, 47 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_fldmg[2] = 
{
    { 18, 58 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_bldmg[2] = 
{
    { 27, 92 },
    { -1, -1 }
};
static LEGLOCK_LIST lrl_crdmg[2] = 
{
    { 25, 118 },
    { -1,  -1 }
};
static LEGLOCK_LIST lrl_dummy[1] = 
{
    { -1, -1 }
};
static LEGLOCK_TAB leglock_tab[11] = 
{
    {  1,  1, lrl_walk  },
    {  2,  1, lrl_a1    },
    {  3,  0, lrl_a2    },
    {  6,  0, lrl_dummy },
    {  7,  1, lrl_dummy },
    {  8,  1, lrl_fldmg },
    {  9,  1, lrl_bldmg },
    { 10,  0, lrl_crdmg },
    { 12,  0, lrl_dummy },
    { 13,  1, lrl_dummy },
    { -1, -1, NULL      }
};
static int attack1_col_joint[5] = { 7, 8, 9, 10, -1 };
static int attack2_col_joint[4] = { 8, 9, 10, -1 };
static int attack3_col_joint[6] = { 6, 7, 8, 9, 10, -1 };
static ATTACK_COL_TBL attack_col_tab[3] =
{
    { attack1_col_joint, 31, 56, 50, 8192, 6.05f, 4.3f, 41, 52 },
    { attack2_col_joint, 29, 40, 50, 5461,  4.0f, 3.3f,  0,  0 },
    { attack3_col_joint, 24, 32, 30, 7281,  4.5f, 5.0f, 24, 30 }
};
static CPCL CapColTab[23] = 
{
    {   3,   3,   4 },
    {   0,  12,  -8 },
    {   4,   4,  12 },
    {   0,   9,  -2 },
    {   3,   3,  10 },
    {  18,  14,   6 },
    {   3,   3,  10 },
    {  18,   5,   7 },
    {   3,   3,  10 },
    {  18,  -4,   8 },
    {   3,   3,  10 },
    { -18,  14,   6 },
    {   3,   3,  10 },
    { -18,   5,   7 },
    {   3,   3,  10 },
    { -18,  -4,   8 },
    {   4,   3,  12 },
    {   3,   2,  15 },
    {  18,  19,  10 },
    {  19,  20,  10 },
    {  21,  22,  10 },
    {  22,  23,  10 },
    {   0,   0,   0 }
};
static unsigned char flip_tree[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
static void (*Mode_func[6])(BH_PWORK*) = 
{
	Init,
	Move,
	Throw,
	Damage,
	Die,
	bhEne_Event
};
static void (*Move_func[5])(BH_PWORK*) = 
{
	Stand,
	CloseTurn,
	KeepFar,
	Chase,
	Attack
};
static void (*Ply_func[8])(BH_PWORK*) = 
{
	DrivePlayer,
	SlidePlayer,
	StandupPlayer,
	FallingPlayer,
	FallDiePlayer,
	HoldPlayer,
	FlyingPlayer,
	DiePlayer
};
/* unused below */
/*static JOINT_PARE jointTree[11];
static char joint_tree_buf[12];*/

// 99.80% matching
static int target_direction(BH_PWORK* epw)
{
    float ans;

    ans = 0.005493164f * (NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz) - epw->ay);
    if (ans > 180.0f) {
        ans = ans + -360.0f;
    }
    else if (ans <= -180.0f)
    {
        ans = ans + 360.0f;
    }
    return (182.04445f * ans);
}

// 100% matching!
static float target_distance(BH_PWORK* epw)
{
    NJS_POINT3 epos;
    O_WORK* owk;

    owk = epw->mlwP->owP;
    epos.x = owk[1].mtx[12];
    epos.y = 0;
    epos.z = owk[1].mtx[14];
    
    return njDistanceP2P((NJS_POINT3*)&plp->px, &epos);
}

// 100% matching!
static int GetLocalEneNo(BH_PWORK* epw)
{
    int i;

    for (i = 0; i < 128; i++) 
    {
        if (&ene[i] == epw) 
        {
            return i;
        }
    }
    
    sprintf(dbgout_buf, "GetLocalEneNo : Not Found Enemy Object!!\n");
    
    write(1, dbgout_buf, sizeof(dbgout_buf));
    
    return -1;
}

// 
// Start address: 0x1e1040
static void SetMtnSE(BH_PWORK* epw)
{
	int i;
	static MTN_SE_TBL mtn_se_tbl[30] = 
	{
		{   1,  38,    74496 },
		{   1,  74,    74496 },
		{   2,  33,    74498 },
		{   2,  11,    74496 },
		{   2,  57,    74496 },
		{   2,  96,    74496 },
		{   3,  32,    74500 },
		{   3,  15,    74496 },
		{   3,  47,    74496 },
		{   3,  66,    74496 },
		{   4,  24,    74498 },
		{   4,  20,    74496 },
		{   4,  20,    74496 },
		{   6,   1, 16851722 },
		{   7,   1, 16851722 },
		{   8,   9, 16851723 },
		{   8,  12,    74496 },
		{   8,  47,    74496 },
		{   9,  13, 16851723 },
		{   9,  26,    74496 },
		{   9,  58,    74496 },
		{  10,  33, 16851724 },
		{  10,  26,    74496 },
		{  10,  49,    74496 },
		{  10,  92,    74496 },
		{  11,   8, 16851725 },
		{  11,  91,     8974 },
		{  11, 150,     8974 },
		{  12,  21,    74496 },
		{  -1,   0,        0 }
	};
	// Line 1246, Address: 0x1e1040, Func Offset: 0
	// Line 1282, Address: 0x1e1058, Func Offset: 0x18
	// Line 1283, Address: 0x1e1068, Func Offset: 0x28
	// Line 1285, Address: 0x1e1088, Func Offset: 0x48
	// Line 1286, Address: 0x1e10b8, Func Offset: 0x78
	// Line 1288, Address: 0x1e10c4, Func Offset: 0x84
	// Line 1289, Address: 0x1e10d4, Func Offset: 0x94
	// Func End, Address: 0x1e10e8, Func Offset: 0xa8
	scePrintf("SetMtnSE - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e10f0
void bhEne15(BH_PWORK* epw)
{
	O_WORK* owk;
	// Line 1351, Address: 0x1e10f0, Func Offset: 0
	// Line 1352, Address: 0x1e10fc, Func Offset: 0xc
	// Line 1353, Address: 0x1e1118, Func Offset: 0x28
	// Line 1355, Address: 0x1e1134, Func Offset: 0x44
	// Line 1356, Address: 0x1e1140, Func Offset: 0x50
	// Line 1361, Address: 0x1e1160, Func Offset: 0x70
	// Line 1362, Address: 0x1e116c, Func Offset: 0x7c
	// Line 1363, Address: 0x1e117c, Func Offset: 0x8c
	// Line 1364, Address: 0x1e119c, Func Offset: 0xac
	// Line 1365, Address: 0x1e11b0, Func Offset: 0xc0
	// Line 1371, Address: 0x1e11b8, Func Offset: 0xc8
	// Line 1372, Address: 0x1e11c8, Func Offset: 0xd8
	// Line 1376, Address: 0x1e11d8, Func Offset: 0xe8
	// Line 1378, Address: 0x1e11e0, Func Offset: 0xf0
	// Line 1379, Address: 0x1e11e8, Func Offset: 0xf8
	// Line 1380, Address: 0x1e11f0, Func Offset: 0x100
	// Line 1381, Address: 0x1e11f8, Func Offset: 0x108
	// Line 1383, Address: 0x1e1200, Func Offset: 0x110
	// Line 1384, Address: 0x1e120c, Func Offset: 0x11c
	// Line 1388, Address: 0x1e122c, Func Offset: 0x13c
	// Line 1390, Address: 0x1e1230, Func Offset: 0x140
	// Line 1394, Address: 0x1e1238, Func Offset: 0x148
	// Line 1388, Address: 0x1e123c, Func Offset: 0x14c
	// Line 1389, Address: 0x1e1240, Func Offset: 0x150
	// Line 1390, Address: 0x1e1258, Func Offset: 0x168
	// Line 1392, Address: 0x1e1264, Func Offset: 0x174
	// Line 1394, Address: 0x1e1284, Func Offset: 0x194
	// Line 1395, Address: 0x1e1294, Func Offset: 0x1a4
	// Line 1396, Address: 0x1e12a0, Func Offset: 0x1b0
	// Line 1395, Address: 0x1e12a4, Func Offset: 0x1b4
	// Line 1396, Address: 0x1e12c4, Func Offset: 0x1d4
	// Line 1399, Address: 0x1e12c8, Func Offset: 0x1d8
	// Line 1400, Address: 0x1e12dc, Func Offset: 0x1ec
	// Line 1401, Address: 0x1e12e4, Func Offset: 0x1f4
	// Line 1400, Address: 0x1e12e8, Func Offset: 0x1f8
	// Line 1401, Address: 0x1e12ec, Func Offset: 0x1fc
	// Line 1400, Address: 0x1e12f0, Func Offset: 0x200
	// Line 1401, Address: 0x1e12fc, Func Offset: 0x20c
	// Line 1404, Address: 0x1e1314, Func Offset: 0x224
	// Func End, Address: 0x1e1324, Func Offset: 0x234
	scePrintf("bhEne15 - UNIMPLEMENTED!\n");
}

// 99.86% matching
static void Init(BH_PWORK* epw) 
{   
    int i;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhGetFreeMemory(100, 32);
        if (epw->exp0 == NULL)
        {
            sprintf(dbgout_buf, "Can't Get WorkMemory!\n");
            write(1, dbgout_buf, sizeof(dbgout_buf));
        }
    }
    
    if (epw->exp0 != NULL)
    {
        EXP0_S(0x58) = -1;
        EXP0_S(0x5C) = 0;
    }
    
    epw->flg |= 0x178;
    epw->flg &= ~6;
    epw->mdflg &= ~4;
    EXP0_S(0x5A) = 0;
    bhCrFlg(sys->ev_flg, 57);
    epw->aox = epw->aoy = epw->aoz = 0.0f;
    
    epw->ar = 3.8f;
    epw->ah = 20.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 2.5f;
    epw->cah = 20.0f;
    epw->cpcl = CapColTab;
    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }
    
    if (sys->gm_mode == 2)
    {
        epw->hp = 360;
    } 
    else
    {
        epw->hp = 600;
    }
    
    bhEne_InitDamage(epw);
    epw->ct1 = 0;
    epw->ct2 = 0;
    epw->ct0 = 0;
    epw->mlwP->objP = epw->mbp[0];
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[0];
    epw->mdflg &= ~2;
    epw->shp_ct = 0.0f;
    if (!(epw->flg & 0x800))
    {
        float sxz = 5.0f; // Not from DWARF
        bhSetShadow(SdwTab, (unsigned char*)epw, 1, 6.0f, sxz, (float)sxz);
        epw->flg |= 0x800;
    }
    
    epw->clp_jno[0] = 4;
    epw->clp_jno[1] = 20;
    epw->clp_jno[2] = 23;
    epw->clp_jno[3] = -1;
    epw->mdflg |= 0x20;
    epw->lok_jno = 4;
    epw->mtn_md = 0;
    epw->mtn_no = -1;
    epw->mtn_tp = flip_tree;
    epw->mtn_add = 65536;
    epw->ct2 = 0;
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->way = 0;
    ReqMtn(epw, 0);
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 65536;
    epw->mtn_no = EXP0_S(0x58);
    
    if (bhSetMotion(epw, 0, epw->mtn_md, epw->mtn_tp) != 0)
    {
        epw->flg |= 0x2000000;
    } else {
        epw->flg &= ~0x2000000;
    }

    EXP0_S(0x58) = -1;
}

// 100% matching!
static void Move(BH_PWORK* epw)
{
    Move_func[epw->mode1](epw);

    if (epw->ct2 != 0)
    {
        epw->ct2--;
    }

    if (epw->ct0 != 0)
    {
        epw->ct0--;
    }
    
    if (epw->ct1 != 0)
    {
        epw->ct1--;
    }
}

// 100% matching!
static void Stand(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
    
    if (35.0f <  target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 3;
        epw->way = 145;
        ReqMtn(epw, 1);
        return;
    }
    
    if (25.0f < target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
        return;
    }
    
    if (target_direction(epw) >= -NJM_DEG_ANG(10.0f))
    {
        if ((target_direction(epw) < NJM_DEG_ANG(10.0f)) && (7.0f > target_distance(epw))) 
        {
            if (plp->flg & 2) 
            {
                epw->ct2 = 30;
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->way = 0;
                ReqMtn(epw, 0);
                return;
            }
            else 
            {
                epw->mode2 = 0;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->way = 1456;
                ReqMtn(epw, 5);
                return;
            }            
        }
    }

    epw->ct2 = 30;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->way = 1456;
    ReqMtn(epw, 1);
}

// 
// Start address: 0x1e1840
static void __attack(BH_PWORK* epw)
{
	int ang;
	// Line 1681, Address: 0x1e1840, Func Offset: 0
	// Line 1683, Address: 0x1e1850, Func Offset: 0x10
	// Line 1684, Address: 0x1e1884, Func Offset: 0x44
	// Line 1685, Address: 0x1e188c, Func Offset: 0x4c
	// Line 1689, Address: 0x1e1920, Func Offset: 0xe0
	// Line 1690, Address: 0x1e1994, Func Offset: 0x154
	// Line 1694, Address: 0x1e1a30, Func Offset: 0x1f0
	// Line 1695, Address: 0x1e1aa4, Func Offset: 0x264
	// Line 1698, Address: 0x1e1b0c, Func Offset: 0x2cc
	// Line 1699, Address: 0x1e1b80, Func Offset: 0x340
	// Line 1702, Address: 0x1e1be8, Func Offset: 0x3a8
	// Line 1703, Address: 0x1e1c58, Func Offset: 0x418
	// Line 1706, Address: 0x1e1cdc, Func Offset: 0x49c
	// Line 1707, Address: 0x1e1d48, Func Offset: 0x508
	// Line 1709, Address: 0x1e1d8c, Func Offset: 0x54c
	// Line 1710, Address: 0x1e1e04, Func Offset: 0x5c4
	// Line 1712, Address: 0x1e1e64, Func Offset: 0x624
	// Line 1714, Address: 0x1e1ed8, Func Offset: 0x698
	// Func End, Address: 0x1e1eec, Func Offset: 0x6ac
	scePrintf("__attack - UNIMPLEMENTED!\n");
}

// 100% matching!
static void CloseTurn(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px,  epw->way);
    
    if (16.0f < target_distance(epw))
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
        return;
    }
    
    if (target_direction(epw) >= -NJM_DEG_ANG(10.0f))
    {
        if ((target_direction(epw) < NJM_DEG_ANG(10.0f)) && (7.0f > target_distance(epw)))
        {
            if (plp->flg & 2)
            {
                epw->ct2 = 30;
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->way = 0;
                ReqMtn(epw, 0);
            } 
            else
            {
                epw->mode2 = 0;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->way = 1456;
                ReqMtn(epw, 5);
            }
            return;
        }
    }

    if (9.0f < target_distance(epw))
    {
        __attack(epw);
    }
}

// 100% matching!
static void Chase(BH_PWORK* epw)
{
    ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
    
    if (25.0f > target_distance(epw)) 
    {
        epw->mode0 = 1;
        epw->mode1 = 2;
        epw->way = 327;
        ReqMtn(epw, 1);
    }
    else
    {
        __attack(epw);       
    }
}

// 100% matching!
static void __goalAng(BH_PWORK* epw, NJS_VECTOR* vec, NJS_VECTOR* ans)
{
    NJS_VECTOR v = { 0.0f, 1.0f, 0.0f };

    *vec = *(NJS_POINT3*)&plp->px;

    njSubVector(vec, (NJS_VECTOR*)&epw->px);
    njOuterProduct(vec, &v, ans);
}

// 100% matching!
static int _goalAng(BH_PWORK* epw)
{
    NJS_POINT3 vec;
    NJS_POINT3 ans;

    __goalAng(epw, &vec, &ans);   
    return njArcTan2(ans.x, ans.z);
}

// 100% matching!
static int _goalAng2(BH_PWORK* epw)
{
    NJS_POINT3 vec;
    NJS_POINT3 ans;

    __goalAng(epw, &vec, &ans);   
    njAddVector(&ans, &vec);
    return njArcTan2(ans.x, ans.z);
}

// 100% matching!
static void KeepFar(BH_PWORK* epw)
{
    if (9.0f > target_distance(epw)) 
    {
        epw->ct2 = 30;
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->way = 1456;
        ReqMtn(epw, 1);
    } 
    else
    {
        if (16.0f > target_distance(epw))
        {
            bhEne15_RotChar(epw, _goalAng2(epw), epw->way);
        } 
        else
        {
            bhEne15_RotChar(epw, _goalAng(epw), epw->way);
        }
        
        if (35.0f < target_distance(epw))
        {
            epw->mode0 = 1;
            epw->mode1 = 3;
            epw->way = 145;
            ReqMtn(epw, 1);
        }
        else
        {
            __attack(epw);
        }        
    }    
}

// 100% matching!
static void Attack(BH_PWORK* epw) 
{    
    int i;                                                 
    NJS_VECTOR attack_v;                                
    ATTACK_COL col;                                        

    if (epw->ct3 != 0) 
    {
        epw->ct3--;
    }

    if ((epw->mtn_no >= 2) && (epw->mtn_no < 5)) 
    {
        ikou(epw, (NJS_POINT3*)&plp->px, epw->way);
        
        if ((epw->frm_no / 65536) == 20) 
        {
            epw->way = 0;
        }
        
        if (((attack_col_tab[MTN_NO_CHECK(epw)].start_frm <= (epw->frm_no / 65536)) && ((epw->frm_no / 65536) < attack_col_tab[MTN_NO_CHECK(epw)].end_frm)) && (!(EXP0_S(90) & 0x1)))
        {
            for (i = 0; attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] != -1; i++) 
            {
                if (MTN_NO_CHECK(epw) == 1)
                {
                    NJS_POINT3 _p; 
                    
                    col.cap.r = attack_col_tab[MTN_NO_CHECK(epw)].volume;
                    
                    _p.x = 0;
                    _p.y = 0;
                    _p.z = 0;
                    
                    njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, &col.cap.c1);
                    
                    if (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] != -1) 
                    {
                        NJS_POINT3 _p; 

                        _p.x = 0;
                        _p.y = 0;
                        _p.z = 0;
                        
                        njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1]].mtx, &_p, &col.cap.c2);
                    } 
                    else 
                    {
                        NJS_POINT3 _p = { 0, 8.0f, 0 }; 
                        
                        njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &col.cap.c2);
                    }
                } 
                else
                {
					static char left_idx[4] = { 0, 4, 5, 1 }, right_idx[4] = { 3, 7, 6, 2 }; 
                    float vane_width; 
                    char* f_idx, *b_idx;      

                    vane_width = 2.0f;
                    
                    if (MTN_NO_CHECK(epw) == 0)
                    {
                        b_idx = left_idx;
                        f_idx = right_idx;
                    } 
                    else
                    {
                        vane_width *= -1.0f;
                        
                        b_idx = right_idx;
                        f_idx = left_idx;
                    }

                    col.box.v[b_idx[0]] = col.box.v[b_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 5));
                    
                    col.box.v[b_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    col.box.v[b_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    
                    {
                        NJS_POINT3 _p; 
                        
                        _p.x = vane_width;
                        _p.y = 0;
                        _p.z = 0;
                        
                        njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, &col.box.v[b_idx[3]]);
                    }
                    
                    col.box.v[b_idx[2]] = col.box.v[b_idx[3]];
                    
                    col.box.v[b_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    col.box.v[b_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                    if (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] != -1)
                    {
                        col.box.v[f_idx[0]] = col.box.v[f_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1] - 5));
                        
                        col.box.v[f_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                        {
                            NJS_POINT3 _p; 
                            
                            _p.x = vane_width;
                            _p.y = 0;
                            _p.z = 0;
                            
                            njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i + 1]].mtx, &_p, &col.box.v[f_idx[3]]);
                        }

                        col.box.v[f_idx[2]] = col.box.v[f_idx[3]];
                        
                        col.box.v[f_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    } 
                    else 
                    {
                        
                        col.box.v[f_idx[0]] = col.box.v[f_idx[1]] = *((NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 4));

                        col.box.v[f_idx[0]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[1]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;

                        {
                            NJS_POINT3 _p = { 0, 9.8f, 0 }; 
                            
                            _p.x = vane_width;
                            
                            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &col.box.v[f_idx[3]]);
                        }

                        col.box.v[f_idx[2]] = col.box.v[f_idx[3]];
                        
                        col.box.v[f_idx[3]].y += attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                        col.box.v[f_idx[2]].y -= attack_col_tab[MTN_NO_CHECK(epw)].volume / 2.0f;
                    }
                }

                if (MTN_NO_CHECK(epw) == 1) 
                {
                    NJS_MATRIX mat;                   
                    NJS_VECTOR vec = { 0, 0, -1.0f }; 
                    
                    njUnitMatrix(&mat);
                    
                    njRotateY(&mat, epw->ay);
                    njCalcVector(&mat, &vec, &attack_v);
                } 
                else
                {
                    NJS_VECTOR vec0, vec1; 

                    vec0 = col.box.v[1];
                    vec1 = col.box.v[2];
                    
                    njSubVector(&vec1, &vec0);
                    
                    vec0.x = 0;
                    vec0.y = 1.0f;
                    vec0.z = 0;
                    
                    njOuterProduct(&vec0, &vec1, &attack_v);
                }
                    
                njUnitVector(&attack_v);
                
                attack_v.x *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                attack_v.y *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                attack_v.z *= attack_col_tab[MTN_NO_CHECK(epw)].spd;
                
                {
                    NJS_MATRIX mat;                 
                    NJS_VECTOR vec = { 0, 1.0f, 0 };
                    NJS_POINT3 axis;                 

                    njOuterProduct(&attack_v, &vec, &axis);
                    
                    njUnitVector(&axis);
                    
                    vec = attack_v; 
                    
                    njUnitMatrix(&mat);
                    
                    njRotate(&mat, &axis, attack_col_tab[MTN_NO_CHECK(epw)].impact_ang);
                    njCalcVector(&mat, &vec, &attack_v);
                }
                
                if (((MTN_NO_CHECK(epw) == 1) ? bhEne15_AttackPlayerCC(&col.cap, &attack_v, attack_col_tab[MTN_NO_CHECK(epw)].damage) : bhEne15_AttackPlayerBC(&col.box, &attack_v, attack_col_tab[MTN_NO_CHECK(epw)].damage)) != 0)
                {
                    bhEne_SetBloodEffect(plp, 1, -1);  
                    
                    RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->dpx, (MTN_NO_CHECK(epw) == 1) ? 0x12305 : 0x12303);
                    
                    StartVibrationEx(1, 11);
                    
                    plp->flg &= ~0x110;
                    
                    if (bhDGCdirCheck((NJS_VECTOR*)&plp->dvx, plp->ay) != 0) 
                    {
                        plp->day += 32768;
                        
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 0;
                        
                        plp->spd = 0;
                        
                        SetPlyMtn(14);
                        
                        plp->mode0 = 5;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    } 
                    else
                    {
                        plp->mnwP = epw->mnwP;
                        
                        EXP0_S(90) |= 0x1;
                        
                        epw->mode3 = 0;
                        
                        plp->spd = 0;
                        
                        SetPlyMtn(15);
                        
                        plp->mode0 = 5;
                        plp->mode1 = 0;
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        
                        plp->flg |=  0x10004;
                        plp->flg &= ~0x40000;
                        
                        plp->stflg |= 0x50000;
                    }
                    
                    break;
                }
            }
        }

        if (((attack_col_tab[MTN_NO_CHECK(epw)].sp_start_frm <= (epw->frm_no / 65536)) && ((epw->frm_no / 65536) < attack_col_tab[MTN_NO_CHECK(epw)].sp_end_frm)) && (epw->mode2 == 1))
        {
            NJS_VECTOR splash_v;            
            NJS_POINT3 _p = { 0, 9.8f, 0 }; 
            
            _p.x = 0; 
            
            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &splash_v);
            njSubVector(&splash_v, (NJS_VECTOR*)epw->exp0 + 6);
            
            SpecialAttack(epw, &splash_v);
        }

        if (MTN_NO_CHECK(epw) != 1) 
        {
            NJS_POINT3 _p; 
            
            for (i = 0; attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] != -1; i++) 
            {
                _p.x = 0;
                _p.y = 0;
                _p.z = 0;
                
                njCalcPoint(&epw->mlwP->owP[attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i]].mtx, &_p, (NJS_POINT3*)epw->exp0 + (attack_col_tab[MTN_NO_CHECK(epw)].obj_no[i] - 5));
            }
            
            {
                NJS_POINT3 _p = { 0, 9.8f, 0 };
                
                _p.x = 0; 
                
                njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, (NJS_POINT3*)epw->exp0 + 6);
            }
        }

        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            epw->ct0 = (rand() % 150) + 30;
            
            epw->mode0 = 1;
            epw->mode1 = 3;
            
            epw->way = 145;
            
            ReqMtn(epw, 1);
        }
    }
}

// 
// Start address: 0x1e3b90
static void Throw(BH_PWORK* epw)
{
	NJS_VECTOR vec;
	NJS_VECTOR attack_v;
	NJS_MATRIX mat; // NJS_MATRIX*?
	NJS_POINT3 _p  = {     0,  8.0f,     0 };
	NJS_POINT3 pos = {     0,     0, -1.0f };
	// Line 1976, Address: 0x1e3b90, Func Offset: 0
	// Line 1977, Address: 0x1e3ba0, Func Offset: 0x10
	// Line 1978, Address: 0x1e3bd0, Func Offset: 0x40
	// Line 1979, Address: 0x1e3be0, Func Offset: 0x50
	// Line 1980, Address: 0x1e3bec, Func Offset: 0x5c
	// Line 1981, Address: 0x1e3c18, Func Offset: 0x88
	// Line 1983, Address: 0x1e3c20, Func Offset: 0x90
	// Line 1988, Address: 0x1e3ca8, Func Offset: 0x118
	// Line 1989, Address: 0x1e3cc8, Func Offset: 0x138
	// Line 1991, Address: 0x1e3cd0, Func Offset: 0x140
	// Line 1994, Address: 0x1e3ce4, Func Offset: 0x154
	// Line 1997, Address: 0x1e3d5c, Func Offset: 0x1cc
	// Line 1998, Address: 0x1e3efc, Func Offset: 0x36c
	// Line 1999, Address: 0x1e3f18, Func Offset: 0x388
	// Line 2002, Address: 0x1e3f24, Func Offset: 0x394
	// Line 2003, Address: 0x1e3f30, Func Offset: 0x3a0
	// Line 2005, Address: 0x1e3f38, Func Offset: 0x3a8
	// Line 2006, Address: 0x1e3f40, Func Offset: 0x3b0
	// Line 2007, Address: 0x1e3f44, Func Offset: 0x3b4
	// Line 2012, Address: 0x1e3f4c, Func Offset: 0x3bc
	// Line 2015, Address: 0x1e3f60, Func Offset: 0x3d0
	// Line 2016, Address: 0x1e3f90, Func Offset: 0x400
	// Line 2017, Address: 0x1e3fb0, Func Offset: 0x420
	// Line 2019, Address: 0x1e3fc4, Func Offset: 0x434
	// Line 2020, Address: 0x1e3fe4, Func Offset: 0x454
	// Line 2022, Address: 0x1e4020, Func Offset: 0x490
	// Line 2034, Address: 0x1e4034, Func Offset: 0x4a4
	// Line 2035, Address: 0x1e404c, Func Offset: 0x4bc
	// Line 2036, Address: 0x1e406c, Func Offset: 0x4dc
	// Line 2037, Address: 0x1e407c, Func Offset: 0x4ec
	// Line 2039, Address: 0x1e4084, Func Offset: 0x4f4
	// Line 2041, Address: 0x1e4090, Func Offset: 0x500
	// Line 2040, Address: 0x1e4094, Func Offset: 0x504
	// Line 2039, Address: 0x1e4098, Func Offset: 0x508
	// Line 2040, Address: 0x1e40a0, Func Offset: 0x510
	// Line 2041, Address: 0x1e40ac, Func Offset: 0x51c
	// Line 2042, Address: 0x1e40b8, Func Offset: 0x528
	// Line 2043, Address: 0x1e40e4, Func Offset: 0x554
	// Line 2044, Address: 0x1e410c, Func Offset: 0x57c
	// Line 2045, Address: 0x1e4110, Func Offset: 0x580
	// Line 2043, Address: 0x1e4114, Func Offset: 0x584
	// Line 2044, Address: 0x1e4118, Func Offset: 0x588
	// Line 2045, Address: 0x1e4134, Func Offset: 0x5a4
	// Line 2046, Address: 0x1e4158, Func Offset: 0x5c8
	// Line 2048, Address: 0x1e41d0, Func Offset: 0x640
	// Line 2051, Address: 0x1e41dc, Func Offset: 0x64c
	// Line 2052, Address: 0x1e420c, Func Offset: 0x67c
	// Line 2055, Address: 0x1e4250, Func Offset: 0x6c0
	// Func End, Address: 0x1e4264, Func Offset: 0x6d4
	scePrintf("Throw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e4270
static void Damage(BH_PWORK* epw)
{
	// Line 2071, Address: 0x1e4270, Func Offset: 0
	// Line 2072, Address: 0x1e4280, Func Offset: 0x10
	// Line 2073, Address: 0x1e429c, Func Offset: 0x2c
	// Line 2074, Address: 0x1e42bc, Func Offset: 0x4c
	// Line 2076, Address: 0x1e42cc, Func Offset: 0x5c
	// Line 2079, Address: 0x1e4314, Func Offset: 0xa4
	// Line 2082, Address: 0x1e4328, Func Offset: 0xb8
	// Line 2083, Address: 0x1e4358, Func Offset: 0xe8
	// Line 2084, Address: 0x1e4378, Func Offset: 0x108
	// Line 2087, Address: 0x1e4380, Func Offset: 0x110
	// Func End, Address: 0x1e4390, Func Offset: 0x120
	scePrintf("Damage - UNIMPLEMENTED!\n");
}

// 100% matching!
static void Die(BH_PWORK* epw)
{
    NJS_VECTOR vec;

    if (epw->mtn_no == 11)
    {
        vec = *(NJS_VECTOR*)&epw->px;
        njSubVector(&vec, (NJS_VECTOR*)&epw->mlwP->owP[4].mtx[12]);
        vec.y = 0.0f;
        if (njScalor(&vec) > 3.8f)
        {
            epw->ar = njScalor(&vec);
        } 
        else 
        {
            epw->ar = 3.8f;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg &= ~0x40;
            epw->flg |= 2;
            epw->mtn_add = 0;
            if ((epw->mode1 == 0) && (sys->gm_flg & 0x40))
            {
                sys->gm_flg &= ~0x40;
                if (!(sys->gm_flg & 0x1000000))
                {
                    sys->gm_flg &= ~0x80;
                }
                
                sys->gm_flg |= 0x800;
                
                if (sys->st_flg & 0x800000) 
                {
                    sys->st_flg &= ~0x800000;
                    sys->gm_flg &= ~0x80000;
                    sys->pt_flg |= 1;
                }
            }
        }
    }
}

// 
// Start address: 0x1e4560
static int NearestCapsule(BH_PWORK* epw, NJS_POINT3* pos, NJS_CAPSULE* dest, short* jnt)
{
	NJS_POINT3 p;
	short _jnt;
	float dis;
	NJS_CAPSULE cap;
	CPCL* ctab;
	int notop;
	float topdis;
	short topjnt;
	NJS_CAPSULE top;
	// Line 2140, Address: 0x1e4560, Func Offset: 0
	// Line 2145, Address: 0x1e4590, Func Offset: 0x30
	// Line 2144, Address: 0x1e4594, Func Offset: 0x34
	// Line 2145, Address: 0x1e4598, Func Offset: 0x38
	// Line 2146, Address: 0x1e45a8, Func Offset: 0x48
	// Line 2150, Address: 0x1e45b0, Func Offset: 0x50
	// Line 2152, Address: 0x1e45b8, Func Offset: 0x58
	// Line 2151, Address: 0x1e45c0, Func Offset: 0x60
	// Line 2152, Address: 0x1e45c4, Func Offset: 0x64
	// Line 2154, Address: 0x1e45d0, Func Offset: 0x70
	// Line 2152, Address: 0x1e45dc, Func Offset: 0x7c
	// Line 2151, Address: 0x1e45f0, Func Offset: 0x90
	// Line 2152, Address: 0x1e45f4, Func Offset: 0x94
	// Line 2153, Address: 0x1e4600, Func Offset: 0xa0
	// Line 2154, Address: 0x1e4634, Func Offset: 0xd4
	// Line 2155, Address: 0x1e4640, Func Offset: 0xe0
	// Line 2157, Address: 0x1e4648, Func Offset: 0xe8
	// Line 2156, Address: 0x1e4654, Func Offset: 0xf4
	// Line 2157, Address: 0x1e4658, Func Offset: 0xf8
	// Line 2158, Address: 0x1e4660, Func Offset: 0x100
	// Line 2157, Address: 0x1e466c, Func Offset: 0x10c
	// Line 2163, Address: 0x1e4680, Func Offset: 0x120
	// Line 2156, Address: 0x1e4684, Func Offset: 0x124
	// Line 2157, Address: 0x1e4688, Func Offset: 0x128
	// Line 2158, Address: 0x1e4694, Func Offset: 0x134
	// Line 2159, Address: 0x1e469c, Func Offset: 0x13c
	// Line 2158, Address: 0x1e46a0, Func Offset: 0x140
	// Line 2160, Address: 0x1e46a8, Func Offset: 0x148
	// Line 2161, Address: 0x1e46c0, Func Offset: 0x160
	// Line 2162, Address: 0x1e46d8, Func Offset: 0x178
	// Line 2163, Address: 0x1e46e4, Func Offset: 0x184
	// Line 2164, Address: 0x1e46ec, Func Offset: 0x18c
	// Line 2168, Address: 0x1e4708, Func Offset: 0x1a8
	// Line 2170, Address: 0x1e4714, Func Offset: 0x1b4
	// Line 2168, Address: 0x1e4718, Func Offset: 0x1b8
	// Line 2169, Address: 0x1e471c, Func Offset: 0x1bc
	// Line 2168, Address: 0x1e4724, Func Offset: 0x1c4
	// Line 2171, Address: 0x1e4728, Func Offset: 0x1c8
	// Line 2170, Address: 0x1e4730, Func Offset: 0x1d0
	// Line 2169, Address: 0x1e4734, Func Offset: 0x1d4
	// Line 2170, Address: 0x1e4738, Func Offset: 0x1d8
	// Line 2168, Address: 0x1e473c, Func Offset: 0x1dc
	// Line 2169, Address: 0x1e4744, Func Offset: 0x1e4
	// Line 2170, Address: 0x1e4748, Func Offset: 0x1e8
	// Line 2169, Address: 0x1e474c, Func Offset: 0x1ec
	// Line 2170, Address: 0x1e4750, Func Offset: 0x1f0
	// Line 2171, Address: 0x1e4758, Func Offset: 0x1f8
	// Line 2173, Address: 0x1e4760, Func Offset: 0x200
	// Line 2174, Address: 0x1e4768, Func Offset: 0x208
	// Line 2175, Address: 0x1e4794, Func Offset: 0x234
	// Line 2176, Address: 0x1e47ac, Func Offset: 0x24c
	// Line 2178, Address: 0x1e47d8, Func Offset: 0x278
	// Line 2179, Address: 0x1e47dc, Func Offset: 0x27c
	// Line 2180, Address: 0x1e4808, Func Offset: 0x2a8
	// Line 2181, Address: 0x1e481c, Func Offset: 0x2bc
	// Line 2180, Address: 0x1e4824, Func Offset: 0x2c4
	// Line 2182, Address: 0x1e4850, Func Offset: 0x2f0
	// Func End, Address: 0x1e4884, Func Offset: 0x324
	scePrintf("NearestCapsule - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e4890
static void CheckDamage(BH_PWORK* epw)
{
	short jnt;
	NJS_CAPSULE cap;
	NJS_POINT3 ofp;
	NJS_POINT3 pos;
	NJS_POINT3 ofs;
	int is_core_damage;
	// Line 2347, Address: 0x1e4890, Func Offset: 0
	// Line 2348, Address: 0x1e48a0, Func Offset: 0x10
	// Line 2358, Address: 0x1e48b0, Func Offset: 0x20
	// Line 2361, Address: 0x1e48c8, Func Offset: 0x38
	// Line 2363, Address: 0x1e48e8, Func Offset: 0x58
	// Line 2366, Address: 0x1e48fc, Func Offset: 0x6c
	// Line 2364, Address: 0x1e4900, Func Offset: 0x70
	// Line 2363, Address: 0x1e4908, Func Offset: 0x78
	// Line 2366, Address: 0x1e490c, Func Offset: 0x7c
	// Line 2363, Address: 0x1e4910, Func Offset: 0x80
	// Line 2365, Address: 0x1e4914, Func Offset: 0x84
	// Line 2364, Address: 0x1e491c, Func Offset: 0x8c
	// Line 2363, Address: 0x1e4920, Func Offset: 0x90
	// Line 2364, Address: 0x1e4924, Func Offset: 0x94
	// Line 2363, Address: 0x1e4928, Func Offset: 0x98
	// Line 2365, Address: 0x1e492c, Func Offset: 0x9c
	// Line 2364, Address: 0x1e4930, Func Offset: 0xa0
	// Line 2365, Address: 0x1e4934, Func Offset: 0xa4
	// Line 2364, Address: 0x1e4938, Func Offset: 0xa8
	// Line 2365, Address: 0x1e493c, Func Offset: 0xac
	// Line 2366, Address: 0x1e4940, Func Offset: 0xb0
	// Line 2367, Address: 0x1e4950, Func Offset: 0xc0
	// Line 2368, Address: 0x1e495c, Func Offset: 0xcc
	// Line 2369, Address: 0x1e49a0, Func Offset: 0x110
	// Line 2370, Address: 0x1e49a4, Func Offset: 0x114
	// Line 2369, Address: 0x1e49a8, Func Offset: 0x118
	// Line 2373, Address: 0x1e49b8, Func Offset: 0x128
	// Line 2374, Address: 0x1e49e4, Func Offset: 0x154
	// Line 2375, Address: 0x1e49e8, Func Offset: 0x158
	// Line 2374, Address: 0x1e49ec, Func Offset: 0x15c
	// Line 2380, Address: 0x1e49f8, Func Offset: 0x168
	// Line 2384, Address: 0x1e4a04, Func Offset: 0x174
	// Line 2385, Address: 0x1e4a0c, Func Offset: 0x17c
	// Line 2391, Address: 0x1e4a18, Func Offset: 0x188
	// Line 2393, Address: 0x1e4a28, Func Offset: 0x198
	// Line 2395, Address: 0x1e4a30, Func Offset: 0x1a0
	// Line 2396, Address: 0x1e4a50, Func Offset: 0x1c0
	// Line 2398, Address: 0x1e4ab0, Func Offset: 0x220
	// Line 2399, Address: 0x1e4ae4, Func Offset: 0x254
	// Line 2401, Address: 0x1e4b10, Func Offset: 0x280
	// Line 2405, Address: 0x1e4b1c, Func Offset: 0x28c
	// Line 2406, Address: 0x1e4b3c, Func Offset: 0x2ac
	// Line 2410, Address: 0x1e4b4c, Func Offset: 0x2bc
	// Line 2416, Address: 0x1e4be4, Func Offset: 0x354
	// Line 2417, Address: 0x1e4bf8, Func Offset: 0x368
	// Line 2418, Address: 0x1e4c08, Func Offset: 0x378
	// Line 2419, Address: 0x1e4c30, Func Offset: 0x3a0
	// Line 2423, Address: 0x1e4c4c, Func Offset: 0x3bc
	// Line 2425, Address: 0x1e4c58, Func Offset: 0x3c8
	// Line 2426, Address: 0x1e4c60, Func Offset: 0x3d0
	// Line 2427, Address: 0x1e4c80, Func Offset: 0x3f0
	// Line 2428, Address: 0x1e4c98, Func Offset: 0x408
	// Line 2430, Address: 0x1e4d00, Func Offset: 0x470
	// Line 2431, Address: 0x1e4d30, Func Offset: 0x4a0
	// Line 2432, Address: 0x1e4d4c, Func Offset: 0x4bc
	// Line 2435, Address: 0x1e4d54, Func Offset: 0x4c4
	// Line 2436, Address: 0x1e4d84, Func Offset: 0x4f4
	// Line 2439, Address: 0x1e4da0, Func Offset: 0x510
	// Line 2443, Address: 0x1e4e00, Func Offset: 0x570
	// Line 2445, Address: 0x1e4e38, Func Offset: 0x5a8
	// Line 2446, Address: 0x1e4ea0, Func Offset: 0x610
	// Line 2447, Address: 0x1e4ef4, Func Offset: 0x664
	// Line 2450, Address: 0x1e4efc, Func Offset: 0x66c
	// Line 2451, Address: 0x1e4f68, Func Offset: 0x6d8
	// Line 2455, Address: 0x1e4fc0, Func Offset: 0x730
	// Line 2457, Address: 0x1e4fd8, Func Offset: 0x748
	// Line 2458, Address: 0x1e4ff0, Func Offset: 0x760
	// Line 2459, Address: 0x1e4ff8, Func Offset: 0x768
	// Line 2460, Address: 0x1e4ffc, Func Offset: 0x76c
	// Line 2459, Address: 0x1e5004, Func Offset: 0x774
	// Line 2460, Address: 0x1e500c, Func Offset: 0x77c
	// Line 2462, Address: 0x1e5018, Func Offset: 0x788
	// Line 2463, Address: 0x1e5034, Func Offset: 0x7a4
	// Line 2464, Address: 0x1e503c, Func Offset: 0x7ac
	// Line 2463, Address: 0x1e5044, Func Offset: 0x7b4
	// Line 2464, Address: 0x1e504c, Func Offset: 0x7bc
	// Line 2465, Address: 0x1e5074, Func Offset: 0x7e4
	// Line 2466, Address: 0x1e507c, Func Offset: 0x7ec
	// Line 2465, Address: 0x1e5080, Func Offset: 0x7f0
	// Line 2466, Address: 0x1e5084, Func Offset: 0x7f4
	// Line 2465, Address: 0x1e5088, Func Offset: 0x7f8
	// Line 2466, Address: 0x1e5090, Func Offset: 0x800
	// Line 2467, Address: 0x1e50a8, Func Offset: 0x818
	// Line 2468, Address: 0x1e50b4, Func Offset: 0x824
	// Line 2467, Address: 0x1e50c0, Func Offset: 0x830
	// Line 2468, Address: 0x1e50c8, Func Offset: 0x838
	// Line 2469, Address: 0x1e50d0, Func Offset: 0x840
	// Line 2468, Address: 0x1e50d4, Func Offset: 0x844
	// Line 2469, Address: 0x1e50dc, Func Offset: 0x84c
	// Line 2472, Address: 0x1e50e8, Func Offset: 0x858
	// Line 2473, Address: 0x1e5108, Func Offset: 0x878
	// Line 2474, Address: 0x1e5110, Func Offset: 0x880
	// Line 2477, Address: 0x1e512c, Func Offset: 0x89c
	// Line 2478, Address: 0x1e5134, Func Offset: 0x8a4
	// Line 2477, Address: 0x1e5138, Func Offset: 0x8a8
	// Line 2478, Address: 0x1e513c, Func Offset: 0x8ac
	// Line 2484, Address: 0x1e5144, Func Offset: 0x8b4
	// Func End, Address: 0x1e5158, Func Offset: 0x8c8
	scePrintf("CheckDamage - UNIMPLEMENTED!\n");
}

static MTN_RELAY mtn_relay[21] = 
{
    {  1,  2, 55,  0 },
    {  1,  3, 55,  0 },
    {  1,  4, 55,  0 },
    {  2,  1, -1,  0 },
    {  3,  1, -1,  0 },
    {  4,  1, -1, 23 },
    {  1,  5, 55,  0 },
    {  1,  6, 55,  0 },
    {  1,  7, 29,  0 },
    {  6,  1, -1, 31 },
    {  7,  1, -1, 38 },
    {  8,  1, -1, 23 },
    {  9,  1, -1,  0 },
    { 10,  1, -1, 64 },
    {  1, 12, 55,  0 },
    { 12,  0, -1,  0 },
    {  0, 13,  1,  0 },
    { 13,  1, -1, 23 },
    {  5,  0, -1,  0 },
    {  5,  1,  0, 56 },
    { -1,  0,  0,  0 }
};
static MTN_RELAY_RELAY mtn_relay_relay[4] = 
{
    {  1,  0, &mtn_relay[14] },
    {  0,  1, &mtn_relay[16] },
    {  5,  1, &mtn_relay[18] },
    { -1,  0, NULL           }
};

// 
// Start address: 0x1e5160
static int GetRelay(BH_PWORK* epw, MTN_RELAY** ret)
{
	int found;
	int i;
	// Line 2540, Address: 0x1e5168, Func Offset: 0x8
	// Line 2538, Address: 0x1e516c, Func Offset: 0xc
	// Line 2537, Address: 0x1e5170, Func Offset: 0x10
	// Line 2540, Address: 0x1e5174, Func Offset: 0x14
	// Line 2541, Address: 0x1e517c, Func Offset: 0x1c
	// Line 2544, Address: 0x1e519c, Func Offset: 0x3c
	// Line 2547, Address: 0x1e51e0, Func Offset: 0x80
	// Line 2548, Address: 0x1e51f4, Func Offset: 0x94
	// Line 2551, Address: 0x1e51fc, Func Offset: 0x9c
	// Line 2554, Address: 0x1e5204, Func Offset: 0xa4
	// Line 2556, Address: 0x1e521c, Func Offset: 0xbc
	// Line 2557, Address: 0x1e5228, Func Offset: 0xc8
	// Line 2560, Address: 0x1e5248, Func Offset: 0xe8
	// Line 2563, Address: 0x1e5290, Func Offset: 0x130
	// Line 2564, Address: 0x1e52a4, Func Offset: 0x144
	// Line 2567, Address: 0x1e52b0, Func Offset: 0x150
	// Line 2569, Address: 0x1e52b4, Func Offset: 0x154
	// Line 2567, Address: 0x1e52b8, Func Offset: 0x158
	// Line 2570, Address: 0x1e52bc, Func Offset: 0x15c
	// Line 2572, Address: 0x1e52cc, Func Offset: 0x16c
	// Func End, Address: 0x1e52d4, Func Offset: 0x174
	scePrintf("GetRelay - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e52e0
static void SetMtn(BH_PWORK* epw)
{
	MTN_RELAY* relay;
	// Line 2574, Address: 0x1e52e0, Func Offset: 0
	// Line 2575, Address: 0x1e52ec, Func Offset: 0xc
	// Line 2577, Address: 0x1e5300, Func Offset: 0x20
	// Line 2578, Address: 0x1e5310, Func Offset: 0x30
	// Line 2580, Address: 0x1e531c, Func Offset: 0x3c
	// Line 2581, Address: 0x1e5320, Func Offset: 0x40
	// Line 2582, Address: 0x1e5328, Func Offset: 0x48
	// Line 2583, Address: 0x1e5350, Func Offset: 0x70
	// Line 2584, Address: 0x1e5358, Func Offset: 0x78
	// Line 2586, Address: 0x1e535c, Func Offset: 0x7c
	// Line 2584, Address: 0x1e5360, Func Offset: 0x80
	// Line 2586, Address: 0x1e5368, Func Offset: 0x88
	// Line 2587, Address: 0x1e5380, Func Offset: 0xa0
	// Line 2589, Address: 0x1e5394, Func Offset: 0xb4
	// Line 2590, Address: 0x1e53a8, Func Offset: 0xc8
	// Line 2591, Address: 0x1e53c0, Func Offset: 0xe0
	// Line 2593, Address: 0x1e53c8, Func Offset: 0xe8
	// Line 2595, Address: 0x1e53dc, Func Offset: 0xfc
	// Line 2596, Address: 0x1e53e0, Func Offset: 0x100
	// Line 2597, Address: 0x1e53e4, Func Offset: 0x104
	// Line 2598, Address: 0x1e53e8, Func Offset: 0x108
	// Line 2599, Address: 0x1e53f0, Func Offset: 0x110
	// Line 2601, Address: 0x1e53fc, Func Offset: 0x11c
	// Line 2602, Address: 0x1e5414, Func Offset: 0x134
	// Line 2604, Address: 0x1e5428, Func Offset: 0x148
	// Line 2605, Address: 0x1e543c, Func Offset: 0x15c
	// Line 2606, Address: 0x1e5444, Func Offset: 0x164
	// Line 2609, Address: 0x1e544c, Func Offset: 0x16c
	// Line 2610, Address: 0x1e5460, Func Offset: 0x180
	// Func End, Address: 0x1e5470, Func Offset: 0x190
	scePrintf("SetMtn - UNIMPLEMENTED!\n");
}

// 100% matching!
static void ReqMtn(BH_PWORK* epw, unsigned int mtn_no)
{
    EXP0_S(0x58) = mtn_no;
}

// 100% matching!
static void SetPlyMtn(unsigned int mtn_no)
{
    plp->hokan_rate = 13107;
    plp->hokan_count = 10;
    plp->frm_no = 0;
    plp->mtn_add = 65536;
    plp->mtn_no = mtn_no;
    
    if (bhSetMotion(plp, 0, plp->mtn_md, plp->mtn_tp) != 0)
    {
        plp->flg |= 0x2000000;
    } 
    else
    {
        plp->flg &= ~0x2000000;
    }

    if (plp->mtn_no == 26)
    {
        plp->py -= 10.6722f;
    }
    
    if (plp->mtn_no == 25)
    {
        plp->py -= 10.7582f;
    }
}

// 100% matching!
static int VacumeToPoint(BH_PWORK* pw, NJS_VECTOR* pos)
{
    NJS_VECTOR v;
    
    v = *pos;
    
    njSubVector(&v, (NJS_VECTOR*)&pw->px);
    if (njScalor(&v) > pw->spd)
    {
        njUnitVector(&v);
        v.x *= pw->spd;
        v.y *= pw->spd;
        v.z *= pw->spd;
        njAddVector((NJS_VECTOR*)&pw->px, &v);
        return 0;
    }
    
    *(NJS_POINT3*)&pw->px = *pos;

    return 1;
}

// 
// Start address: 0x1e5680
static void LockLeg(BH_PWORK* epw)
{
	char lock_leg;
	int j;
	int i;
	// Line 2680, Address: 0x1e5680, Func Offset: 0
	// Line 2682, Address: 0x1e568c, Func Offset: 0xc
	// Line 2680, Address: 0x1e5690, Func Offset: 0x10
	// Line 2682, Address: 0x1e5694, Func Offset: 0x14
	// Line 2683, Address: 0x1e569c, Func Offset: 0x1c
	// Line 2684, Address: 0x1e56a8, Func Offset: 0x28
	// Line 2685, Address: 0x1e56bc, Func Offset: 0x3c
	// Line 2686, Address: 0x1e56dc, Func Offset: 0x5c
	// Line 2688, Address: 0x1e56fc, Func Offset: 0x7c
	// Line 2690, Address: 0x1e570c, Func Offset: 0x8c
	// Line 2691, Address: 0x1e5714, Func Offset: 0x94
	// Line 2694, Address: 0x1e571c, Func Offset: 0x9c
	// Line 2695, Address: 0x1e5750, Func Offset: 0xd0
	// Line 2696, Address: 0x1e5760, Func Offset: 0xe0
	// Line 2697, Address: 0x1e576c, Func Offset: 0xec
	// Line 2698, Address: 0x1e5774, Func Offset: 0xf4
	// Line 2700, Address: 0x1e5780, Func Offset: 0x100
	// Line 2702, Address: 0x1e578c, Func Offset: 0x10c
	// Line 2703, Address: 0x1e57c0, Func Offset: 0x140
	// Func End, Address: 0x1e57cc, Func Offset: 0x14c
	scePrintf("LockLeg - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e57d0
int bhEne15_AttackPlayerCC(NJS_CAPSULE* cap, NJS_VECTOR* attack_v, int damage)
{
	NJS_POINT3 tar_p;
	float distance;
	NJS_POINT3 hit_p;
	float latest;
	int kno;
	int j;
	// Line 2718, Address: 0x1e57d0, Func Offset: 0
	// Line 2720, Address: 0x1e57fc, Func Offset: 0x2c
	// Line 2724, Address: 0x1e5820, Func Offset: 0x50
	// Line 2725, Address: 0x1e5830, Func Offset: 0x60
	// Line 2726, Address: 0x1e5834, Func Offset: 0x64
	// Line 2724, Address: 0x1e5838, Func Offset: 0x68
	// Line 2727, Address: 0x1e583c, Func Offset: 0x6c
	// Line 2724, Address: 0x1e5844, Func Offset: 0x74
	// Line 2725, Address: 0x1e584c, Func Offset: 0x7c
	// Line 2726, Address: 0x1e5860, Func Offset: 0x90
	// Line 2727, Address: 0x1e5878, Func Offset: 0xa8
	// Line 2730, Address: 0x1e5880, Func Offset: 0xb0
	// Line 2731, Address: 0x1e5890, Func Offset: 0xc0
	// Line 2732, Address: 0x1e58a4, Func Offset: 0xd4
	// Line 2733, Address: 0x1e58b4, Func Offset: 0xe4
	// Line 2734, Address: 0x1e58bc, Func Offset: 0xec
	// Line 2736, Address: 0x1e58cc, Func Offset: 0xfc
	// Line 2738, Address: 0x1e58f0, Func Offset: 0x120
	// Line 2737, Address: 0x1e58f4, Func Offset: 0x124
	// Line 2738, Address: 0x1e58f8, Func Offset: 0x128
	// Line 2740, Address: 0x1e58fc, Func Offset: 0x12c
	// Line 2742, Address: 0x1e5920, Func Offset: 0x150
	// Line 2743, Address: 0x1e594c, Func Offset: 0x17c
	// Line 2747, Address: 0x1e5974, Func Offset: 0x1a4
	// Line 2743, Address: 0x1e5978, Func Offset: 0x1a8
	// Line 2744, Address: 0x1e597c, Func Offset: 0x1ac
	// Line 2752, Address: 0x1e5988, Func Offset: 0x1b8
	// Line 2744, Address: 0x1e598c, Func Offset: 0x1bc
	// Line 2745, Address: 0x1e59ac, Func Offset: 0x1dc
	// Line 2744, Address: 0x1e59b0, Func Offset: 0x1e0
	// Line 2745, Address: 0x1e59b4, Func Offset: 0x1e4
	// Line 2746, Address: 0x1e59bc, Func Offset: 0x1ec
	// Line 2747, Address: 0x1e59e8, Func Offset: 0x218
	// Line 2746, Address: 0x1e59ec, Func Offset: 0x21c
	// Line 2747, Address: 0x1e59f0, Func Offset: 0x220
	// Line 2749, Address: 0x1e59fc, Func Offset: 0x22c
	// Line 2751, Address: 0x1e5a08, Func Offset: 0x238
	// Line 2749, Address: 0x1e5a0c, Func Offset: 0x23c
	// Line 2751, Address: 0x1e5a14, Func Offset: 0x244
	// Line 2752, Address: 0x1e5a20, Func Offset: 0x250
	// Line 2754, Address: 0x1e5a28, Func Offset: 0x258
	// Line 2755, Address: 0x1e5a2c, Func Offset: 0x25c
	// Func End, Address: 0x1e5a5c, Func Offset: 0x28c
	scePrintf("bhEne15_AttackPlayerCC - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e5a60
int bhEne15_AttackPlayerBC(NJS_BOX* box, NJS_VECTOR* attack_v, int damage)
{
	NJS_POINT3 tar_p;
	float distance;
	NJS_POINT3 hit_p;
	float latest;
	int kno;
	int j;
	// Line 2757, Address: 0x1e5a60, Func Offset: 0
	// Line 2759, Address: 0x1e5a8c, Func Offset: 0x2c
	// Line 2764, Address: 0x1e5ab0, Func Offset: 0x50
	// Line 2765, Address: 0x1e5ac8, Func Offset: 0x68
	// Line 2764, Address: 0x1e5acc, Func Offset: 0x6c
	// Line 2766, Address: 0x1e5ad0, Func Offset: 0x70
	// Line 2767, Address: 0x1e5ad4, Func Offset: 0x74
	// Line 2764, Address: 0x1e5ad8, Func Offset: 0x78
	// Line 2765, Address: 0x1e5aec, Func Offset: 0x8c
	// Line 2766, Address: 0x1e5b10, Func Offset: 0xb0
	// Line 2767, Address: 0x1e5b38, Func Offset: 0xd8
	// Line 2770, Address: 0x1e5b40, Func Offset: 0xe0
	// Line 2771, Address: 0x1e5b50, Func Offset: 0xf0
	// Line 2772, Address: 0x1e5b64, Func Offset: 0x104
	// Line 2773, Address: 0x1e5b74, Func Offset: 0x114
	// Line 2774, Address: 0x1e5b7c, Func Offset: 0x11c
	// Line 2776, Address: 0x1e5b8c, Func Offset: 0x12c
	// Line 2778, Address: 0x1e5bb0, Func Offset: 0x150
	// Line 2777, Address: 0x1e5bb4, Func Offset: 0x154
	// Line 2778, Address: 0x1e5bb8, Func Offset: 0x158
	// Line 2780, Address: 0x1e5bbc, Func Offset: 0x15c
	// Line 2782, Address: 0x1e5be0, Func Offset: 0x180
	// Line 2783, Address: 0x1e5c0c, Func Offset: 0x1ac
	// Line 2787, Address: 0x1e5c34, Func Offset: 0x1d4
	// Line 2783, Address: 0x1e5c38, Func Offset: 0x1d8
	// Line 2784, Address: 0x1e5c3c, Func Offset: 0x1dc
	// Line 2792, Address: 0x1e5c48, Func Offset: 0x1e8
	// Line 2784, Address: 0x1e5c4c, Func Offset: 0x1ec
	// Line 2785, Address: 0x1e5c6c, Func Offset: 0x20c
	// Line 2784, Address: 0x1e5c70, Func Offset: 0x210
	// Line 2785, Address: 0x1e5c74, Func Offset: 0x214
	// Line 2786, Address: 0x1e5c7c, Func Offset: 0x21c
	// Line 2787, Address: 0x1e5ca8, Func Offset: 0x248
	// Line 2786, Address: 0x1e5cac, Func Offset: 0x24c
	// Line 2787, Address: 0x1e5cb0, Func Offset: 0x250
	// Line 2789, Address: 0x1e5cbc, Func Offset: 0x25c
	// Line 2791, Address: 0x1e5cc8, Func Offset: 0x268
	// Line 2789, Address: 0x1e5ccc, Func Offset: 0x26c
	// Line 2791, Address: 0x1e5cd4, Func Offset: 0x274
	// Line 2792, Address: 0x1e5ce0, Func Offset: 0x280
	// Line 2794, Address: 0x1e5ce8, Func Offset: 0x288
	// Line 2795, Address: 0x1e5cec, Func Offset: 0x28c
	// Func End, Address: 0x1e5d1c, Func Offset: 0x2bc
	scePrintf("bhEne15_AttackPlayerBC - UNIMPLEMENTED!\n");
}

// 100% matching!
int bhEne15_AttackPlayerSS(NJS_SPHERE* spr, NJS_VECTOR* attack_v, int damage)
{
    NJS_SPHERE plcol;
    
    plcol.c.x = plp->mlwP->owP[5].mtx[12];
    plcol.c.y = plp->mlwP->owP[5].mtx[13];
    plcol.c.z = plp->mlwP->owP[5].mtx[14];
    plcol.r = 2.0f;

    if (njCollisionCheckSS(&plcol, spr) != 0)
    {
        plp->dax = NJM_RAD_ANG(atan2f(attack_v->y, attack_v->z));
        plp->day = NJM_RAD_ANG(atan2f(attack_v->x, attack_v->z));
        *(NJS_POINT3*)&plp->dvx = *attack_v;
        plp->djnt_no = 5;
        *(NJS_POINT3*)&plp->dpx = spr->c;
        
        plp->dam[5] = damage;
        plp->hp -= damage;
        plp->flg |= 4;
        return 1;
    }
    
    return 0;
}

// 100% matching!
static void SetSmoke(NJS_POINT3* pos)
{
    sys->ef.id = 257;
    sys->ef.flg = 1;
    sys->ef.type = 0;
    
    *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&pos->x;
    
    sys->ef.sz = 0.5f;
    sys->ef.sy = 0.5f;
    sys->ef.sx = 0.5f;
    
    bhSetEffectTb(&sys->ef, NULL, NULL, 0);
}

static UVINFO uvinfo1_1[5] = 
{
    {  0,  0, 24, 24,  3, 20 },
    {  0, 24, 24, 24,  2, 20 },
    {  0, 48, 24, 24,  5, 20 },
    {  0, 24, 24, 24,  3, 20 },
    { -1,  0,  0,  0,  0,  0 }
};
static UVINFO uvinfo1_2[16] = 
{
    {  24,   0,  16,  16,   1,  10 },
    {  40,   0,  24,  24,   2,  10 },
    {  64,   0,  32,  32,   2,  10 },
    {  96,   0,  40,  40,   2,  10 },
    { 136,   0,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 120,  48,  56,  56,   3,  10 },
    { 176,  48,  56,  56,   4,  10 },
    {   0,  88,  56,  56,   5,  10 },
    {  56,  88,  56,  56,   5,  10 },
    { 112, 104,  56,  56,   5,  10 },
    { 168, 104,  56,  56,   5,  10 },
    { 168, 160,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo1_3[23] = 
{
    {  24,   0,  16,  16,   1,  10 },
    {  40,   0,  24,  24,   2,  10 },
    {  64,   0,  32,  32,   2,  10 },
    {  96,   0,  40,  40,   2,  10 },
    { 136,   0,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    {  24,  40,  48,  48,   2,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 184,   0,  48,  48,   2,  10 },
    {  24,  40,  48,  48,   2,  10 },
    {  72,  40,  48,  48,   3,  10 },
    { 120,  48,  56,  56,   3,  10 },
    { 176,  48,  56,  56,   4,  10 },
    {   0,  88,  56,  56,   5,  10 },
    {  56,  88,  56,  56,   5,  10 },
    { 112, 104,  56,  56,   5,  10 },
    { 168, 104,  56,  56,   5,  10 },
    { 168, 160,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo2_1[30] = 
{
    {   0,   0,  16,  16,   1,  10 },
    {  16,   0,  16,  16,   1,  11 },
    {  32,   0,  24,  24,   1,  12 },
    {  56,   0,  24,  24,   1,  13 },
    {  80,   0,  24,  24,   1,  14 },
    {   0,  16,  32,  32,   1,  15 },
    {  80,   0,  24,  24,   1,  16 },
    {  56,   0,  24,  24,   1,  17 },
    {  32,   0,  24,  24,   1,  18 },
    {  56,   0,  24,  24,   1,  19 },
    {  80,   0,  24,  24,   1,  20 },
    {   0,  16,  32,  32,   1,  21 },
    {  80,   0,  24,  24,   1,  22 },
    {  56,   0,  24,  24,   1,  23 },
    {  32,   0,  24,  24,   1,  24 },
    {  56,   0,  24,  24,   1,  25 },
    {  80,   0,  24,  24,   1,  26 },
    {   0,  16,  32,  32,   1,  27 },
    {   0,  48,  32,  32,   1,  28 },
    {   0,  80,  32,  32,   1,  29 },
    {   0, 112,  32,  32,   1,  30 },
    {   0, 144,  32,  32,   1,  31 },
    {  32,  24,  40,  40,   1,  32 },
    {  72,  24,  40,  40,   1,  33 },
    {  32,  64,  40,  40,   1,  34 },
    {  72,  64,  40,  40,   1,  35 },
    {  32, 104,  40,  40,   1,  36 },
    {  72, 104,  40,  40,   1,  37 },
    {  32, 144,  40,  40,   1,  38 },
    {  -1,   0,   0,   0,   0,   0 }
};
static UVINFO uvinfo2_2[16] = 
{
    { 104,   0,  16,  16,   1,  10 },
    { 112,  16,  24,  24,   2,  10 },
    { 136,   0,  32,  32,   2,  10 },
    { 168,   0,  40,  40,   2,  10 },
    { 208,   0,  48,  48,   2,  10 },
    { 112,  40,  48,  48,   2,  10 },
    { 160,  40,  48,  48,   2,  10 },
    { 208,  48,  48,  48,   3,  10 },
    { 112,  88,  56,  56,   3,  10 },
    {  72, 144,  56,  56,   4,  10 },
    { 128, 144,  56,  56,   5,  10 },
    { 184, 144,  56,  56,   5,  10 },
    {   0, 200,  56,  56,   5,  10 },
    {  56, 200,  56,  56,   5,  10 },
    { 112, 200,  56,  56,   5,  10 },
    {  -1,   0,   0,   0,   0,   0 }
};
static EFF_INFO eff_info[5] = 
{
    { 7, uvinfo2_2 },
    { 6, uvinfo1_2 },
    { 6, uvinfo1_3 },
    { 7, uvinfo2_1 },
    { 6, uvinfo1_1 }
};

// 100% matching!
static void SpecialAttack(BH_PWORK* epw, NJS_VECTOR* splash_v)
{
	int eno;

    if (epw->ct3 == 0)
    {
        sys->ef.flg = 1;
        {
            NJS_POINT3 _p = { 0.0f, 8.0f, 0.0f };
            njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, (NJS_POINT3*)&sys->ef.px);
        }

        sys->ef.ay = 0;
        sys->ef.mdlver = 0;
        sys->ef.id = 397;
        sys->ef.type = 4;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            eff[eno].txp[0] = epw->mlwP->texP;
            eff[eno].tex_id = eff_info[sys->ef.type].texid;
            eff[eno].mode3 = 0;
            eff[eno].exp0 = (unsigned char*)epw;            
            *(NJS_POINT3*)&eff[eno].xn = *splash_v;        
        }
    }
}

// 100% matching!
static void _bhEne_SetPoison(BH_PWORK* epw, NJS_VECTOR* ofp, short ry)
{
    int eno;

    sys->ef.id = 397;
    sys->ef.type = 1;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry;
    sys->ef.ax = 0;
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].xn = eff[eno].yn = eff[eno].zn = 0.0f;
    }

    sys->ef.id = 397;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry - NJM_DEG_ANG(90.0f);
    sys->ef.ax = 0;
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].mode3 = 0;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].tv[0].x = 2.0f;
        eff[eno].tv[0].y = -1.0f;
        eff[eno].tv[1].x = 0.0f;
        eff[eno].tv[1].y = -1.0f;
        eff[eno].tv[2].x = 2.0f;
        eff[eno].tv[2].y = 1.0f;
        eff[eno].tv[3].x = 0.0f;
        eff[eno].tv[3].y = 1.0f;
    }

    sys->ef.id = 397;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.px = sys->ef.py = sys->ef.pz = 0.0f;
    sys->ef.sx = sys->ef.sy = 1.0f;
    sys->ef.sz = 0.0f;
    sys->ef.ay = ry - NJM_DEG_ANG(90.0f);
    sys->ef.ax = NJM_DEG_ANG(90.0f);
    sys->ef.mdlver = 0;
    eno = bhSetEffectTb(&sys->ef, ofp, (unsigned char*)epw, epw->djnt_no);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = eff_info[sys->ef.type].texid;
        eff[eno].exp0 = (unsigned char*)epw;
        eff[eno].tv[0].x = 2.0f;
        eff[eno].tv[0].y = -1.0f;
        eff[eno].tv[1].x = 0.0f;
        eff[eno].tv[1].y = -1.0f;
        eff[eno].tv[2].x = 2.0f;
        eff[eno].tv[2].y = 1.0f;
        eff[eno].tv[3].x = 0.0f;
        eff[eno].tv[3].y = 1.0f;
    }
}

// 100% matching!
static void _bhEne_SetPoison2(O_WRK* op, int type, NJS_VECTOR* ofp)
{
	int eno;

    sys->ef.id = 397;
    sys->ef.type = type;
    sys->ef.flg = 1;

    *(NJS_VECTOR*)&sys->ef.px = *(NJS_VECTOR*)&op->px;

    njAddVector((NJS_VECTOR*)&sys->ef.px, ofp);
       
    sys->ef.sx = sys->ef.sy = 2.0f;
    
    sys->ef.sz = 0.0f;

    if (type == 2)
    {
        sys->ef.ax = NJM_DEG_ANG(90.0f);
        sys->ef.ay = 0;
    }
    else
    {
        sys->ef.ay = 0;
        sys->ef.ax = 0;
    }

    sys->ef.mdlver = 0;

    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    if (eno != -1)
    {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = op->txp[0];
        eff[eno].tex_id = eff_info[type].texid;
        eff[eno].exp0 = op->exp0;
        *(NJS_VECTOR*)&eff[eno].xn = *(NJS_VECTOR*)&op->xn;
    }
}

// 100% matching!
void bhEne_SetPoison(BH_PWORK* epw, BT_WORK* bt) 
{
	O_WORK* owk; 
	NJS_POINT3 ofp; 
	NJS_POINT3 ps;
	int fhit;

    // not present in DWARF
    BT_WORK* btp;
    
    fhit = 0;
    if (poison_eff_wait == 0)
    {
        poison_eff_wait = 15;
        owk = &epw->mlwP->owP[epw->djnt_no];
        if ((bt == NULL) || (epw->wpnr_no == 13) || (epw->wpnr_no == 10))
        {
            ps.x = epw->dpx - owk->mtx[12];
            ps.y = epw->dpy - owk->mtx[13];
            ps.z = epw->dpz - owk->mtx[14];
            njSetMatrix(lcmat, &owk->mtx);
            njInvertMatrix(lcmat);
            njCalcVector(lcmat, &ps, &ofp);
        } 
        else 
        {
            if (bhDGCdirCheck2((NJS_VECTOR*)&epw->dvx, owk) == 0)
            {
                fhit = 1;
            }
            
            btp = &bt[epw->djnt_no];

            ofp.x = btp->x + (btp->xlen - (2.0f * btp->xlen * njRandom()));
            ofp.y = btp->y + (btp->ylen - (2.0f * btp->ylen * njRandom()));
            
            if (fhit != 0)
            {
                ofp.z = -btp->z;
            }
            else
            {
                ofp.z = btp->z;
            }
            epw->djnt_no = btp->lnk_obj;
        }
        _bhEne_SetPoison(epw, (NJS_VECTOR*)&ofp, plp->way);
    }
}

// 100% matching!
static void PoisonAttack(O_WRK* op)
{
    NJS_SPHERE col;
    NJS_VECTOR attack_v;

    if (poison_attack_wait != 0)
    {
        return;
    }
        
    if ((op->type == 1) || (op->type == 2))
    {
        return;
    }
        
    col.c = *(NJS_POINT3*)&op->px; 
    col.r = 3.0f;

    attack_v = *(NJS_POINT3*)&plp->px; 

    njSubVector(&attack_v, &col.c);

    if (*(short*)(*(unsigned char**)(op->exp0 + 0x2F0) + 0x5A) & 1)
    {
        return;
    }

    if (bhEne15_AttackPlayerSS(&col, &attack_v, 3) == 0)
    {
        return;
    }
        
    if ((plp->mode0 != 1) && (plp->mode0 != 0))
    {
        plp->hp += 3;
    } 
    else
    {
        if (*(short *)(*(int *)(op->exp0 + 0x2F0) + 0x5C) > 5)
        {
            if (njRandom() < 0.6)
            {
                plp->stflg |= 0x200000;
            }  
        }
        else
        {
            (*(short *)(*(int *)(op->exp0 + 0x2F0) + 0x5C))++;
        }

        plp->flg |= 4;

        if (plp->hp < 0)
        {
            plp->hp = 0;
        }
            
        plp->mode0 = 2;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
    }

    poison_attack_wait = 20;
}

// 100% matching!
static void AddWindForce(O_WRK* op, float reg)
{
    NJS_VECTOR vec1;
	NJS_VECTOR vec2;

    vec1.x = reg * sys->winds * -njSin(sys->windr);
    vec1.y = 0.0f;
    vec1.z = reg * sys->winds * -njCos(sys->windr);
    
    vec2.x = reg * sys->windsb * -njSin(sys->windrb);
    vec2.y = 0.0f;
    vec2.z = reg * sys->windsb * -njCos(sys->windrb);
    
    njSubVector(&vec1, &vec2);
    njAddVector((NJS_VECTOR*)&op->xn, &vec1);
    njAddVector((NJS_VECTOR*)&op->px, (NJS_VECTOR*)&op->xn);
}

// 
// Start address: 0x1e6f80
void bhEff_E15_Poison(O_WRK* op)
{
	//NJS_POINT3 pos;
	//NJS_POINT3 pos;
	NJS_POINT3 pos;
	UVINFO* uvp;
	// Line 3271, Address: 0x1e6f80, Func Offset: 0
	// Line 3272, Address: 0x1e6f90, Func Offset: 0x10
	// Line 3274, Address: 0x1e6fc4, Func Offset: 0x44
	// Line 3275, Address: 0x1e6fc8, Func Offset: 0x48
	// Line 3276, Address: 0x1e6fcc, Func Offset: 0x4c
	// Line 3277, Address: 0x1e6fd0, Func Offset: 0x50
	// Line 3279, Address: 0x1e6fd4, Func Offset: 0x54
	// Line 3280, Address: 0x1e6fdc, Func Offset: 0x5c
	// Line 3281, Address: 0x1e6fe4, Func Offset: 0x64
	// Line 3284, Address: 0x1e7000, Func Offset: 0x80
	// Line 3286, Address: 0x1e7014, Func Offset: 0x94
	// Line 3287, Address: 0x1e7024, Func Offset: 0xa4
	// Line 3290, Address: 0x1e7028, Func Offset: 0xa8
	// Line 3287, Address: 0x1e702c, Func Offset: 0xac
	// Line 3288, Address: 0x1e7034, Func Offset: 0xb4
	// Line 3289, Address: 0x1e7044, Func Offset: 0xc4
	// Line 3290, Address: 0x1e7050, Func Offset: 0xd0
	// Line 3292, Address: 0x1e7064, Func Offset: 0xe4
	// Line 3293, Address: 0x1e7068, Func Offset: 0xe8
	// Line 3295, Address: 0x1e7080, Func Offset: 0x100
	// Line 3296, Address: 0x1e709c, Func Offset: 0x11c
	// Line 3297, Address: 0x1e70a8, Func Offset: 0x128
	// Line 3302, Address: 0x1e70ac, Func Offset: 0x12c
	// Line 3305, Address: 0x1e70c4, Func Offset: 0x144
	// Line 3308, Address: 0x1e70cc, Func Offset: 0x14c
	// Line 3310, Address: 0x1e70ec, Func Offset: 0x16c
	// Line 3311, Address: 0x1e70fc, Func Offset: 0x17c
	// Line 3310, Address: 0x1e7100, Func Offset: 0x180
	// Line 3311, Address: 0x1e7104, Func Offset: 0x184
	// Line 3310, Address: 0x1e7108, Func Offset: 0x188
	// Line 3311, Address: 0x1e710c, Func Offset: 0x18c
	// Line 3312, Address: 0x1e7120, Func Offset: 0x1a0
	// Line 3313, Address: 0x1e712c, Func Offset: 0x1ac
	// Line 3315, Address: 0x1e7138, Func Offset: 0x1b8
	// Line 3316, Address: 0x1e7164, Func Offset: 0x1e4
	// Line 3317, Address: 0x1e71cc, Func Offset: 0x24c
	// Line 3318, Address: 0x1e7234, Func Offset: 0x2b4
	// Line 3319, Address: 0x1e7298, Func Offset: 0x318
	// Line 3318, Address: 0x1e72a8, Func Offset: 0x328
	// Line 3319, Address: 0x1e72ac, Func Offset: 0x32c
	// Line 3320, Address: 0x1e72b4, Func Offset: 0x334
	// Line 3325, Address: 0x1e72dc, Func Offset: 0x35c
	// Line 3327, Address: 0x1e7308, Func Offset: 0x388
	// Line 3330, Address: 0x1e73d8, Func Offset: 0x458
	// Line 3331, Address: 0x1e740c, Func Offset: 0x48c
	// Line 3332, Address: 0x1e7440, Func Offset: 0x4c0
	// Line 3333, Address: 0x1e7458, Func Offset: 0x4d8
	// Line 3332, Address: 0x1e745c, Func Offset: 0x4dc
	// Line 3333, Address: 0x1e7460, Func Offset: 0x4e0
	// Line 3332, Address: 0x1e7464, Func Offset: 0x4e4
	// Line 3333, Address: 0x1e7474, Func Offset: 0x4f4
	// Line 3332, Address: 0x1e747c, Func Offset: 0x4fc
	// Line 3333, Address: 0x1e7484, Func Offset: 0x504
	// Line 3335, Address: 0x1e74b4, Func Offset: 0x534
	// Line 3333, Address: 0x1e74b8, Func Offset: 0x538
	// Line 3334, Address: 0x1e74c0, Func Offset: 0x540
	// Line 3335, Address: 0x1e74c4, Func Offset: 0x544
	// Line 3336, Address: 0x1e74f0, Func Offset: 0x570
	// Line 3335, Address: 0x1e74f4, Func Offset: 0x574
	// Line 3336, Address: 0x1e7500, Func Offset: 0x580
	// Line 3335, Address: 0x1e750c, Func Offset: 0x58c
	// Line 3336, Address: 0x1e7514, Func Offset: 0x594
	// Line 3338, Address: 0x1e751c, Func Offset: 0x59c
	// Line 3339, Address: 0x1e7528, Func Offset: 0x5a8
	// Line 3341, Address: 0x1e7538, Func Offset: 0x5b8
	// Line 3343, Address: 0x1e7540, Func Offset: 0x5c0
	// Line 3346, Address: 0x1e7610, Func Offset: 0x690
	// Line 3347, Address: 0x1e7644, Func Offset: 0x6c4
	// Line 3348, Address: 0x1e7678, Func Offset: 0x6f8
	// Line 3349, Address: 0x1e7690, Func Offset: 0x710
	// Line 3348, Address: 0x1e7694, Func Offset: 0x714
	// Line 3349, Address: 0x1e7698, Func Offset: 0x718
	// Line 3348, Address: 0x1e769c, Func Offset: 0x71c
	// Line 3349, Address: 0x1e76ac, Func Offset: 0x72c
	// Line 3348, Address: 0x1e76b4, Func Offset: 0x734
	// Line 3349, Address: 0x1e76bc, Func Offset: 0x73c
	// Line 3350, Address: 0x1e76e0, Func Offset: 0x760
	// Line 3349, Address: 0x1e76e4, Func Offset: 0x764
	// Line 3350, Address: 0x1e76f0, Func Offset: 0x770
	// Line 3349, Address: 0x1e76f4, Func Offset: 0x774
	// Line 3351, Address: 0x1e76f8, Func Offset: 0x778
	// Line 3349, Address: 0x1e76fc, Func Offset: 0x77c
	// Line 3350, Address: 0x1e7704, Func Offset: 0x784
	// Line 3351, Address: 0x1e7708, Func Offset: 0x788
	// Line 3352, Address: 0x1e7734, Func Offset: 0x7b4
	// Line 3351, Address: 0x1e7738, Func Offset: 0x7b8
	// Line 3352, Address: 0x1e7744, Func Offset: 0x7c4
	// Line 3351, Address: 0x1e7750, Func Offset: 0x7d0
	// Line 3352, Address: 0x1e7758, Func Offset: 0x7d8
	// Line 3367, Address: 0x1e7760, Func Offset: 0x7e0
	// Line 3368, Address: 0x1e776c, Func Offset: 0x7ec
	// Line 3370, Address: 0x1e777c, Func Offset: 0x7fc
	// Line 3374, Address: 0x1e7784, Func Offset: 0x804
	// Line 3377, Address: 0x1e779c, Func Offset: 0x81c
	// Line 3378, Address: 0x1e77a0, Func Offset: 0x820
	// Line 3379, Address: 0x1e77b0, Func Offset: 0x830
	// Line 3378, Address: 0x1e77b8, Func Offset: 0x838
	// Line 3379, Address: 0x1e77bc, Func Offset: 0x83c
	// Line 3380, Address: 0x1e77c8, Func Offset: 0x848
	// Line 3387, Address: 0x1e77d0, Func Offset: 0x850
	// Line 3397, Address: 0x1e77dc, Func Offset: 0x85c
	// Line 3399, Address: 0x1e77e4, Func Offset: 0x864
	// Line 3387, Address: 0x1e77e8, Func Offset: 0x868
	// Line 3388, Address: 0x1e7810, Func Offset: 0x890
	// Line 3389, Address: 0x1e783c, Func Offset: 0x8bc
	// Line 3390, Address: 0x1e7874, Func Offset: 0x8f4
	// Line 3391, Address: 0x1e787c, Func Offset: 0x8fc
	// Line 3392, Address: 0x1e7884, Func Offset: 0x904
	// Line 3393, Address: 0x1e78bc, Func Offset: 0x93c
	// Line 3394, Address: 0x1e78c4, Func Offset: 0x944
	// Line 3397, Address: 0x1e78cc, Func Offset: 0x94c
	// Line 3399, Address: 0x1e7900, Func Offset: 0x980
	// Line 3400, Address: 0x1e791c, Func Offset: 0x99c
	// Line 3401, Address: 0x1e7930, Func Offset: 0x9b0
	// Line 3405, Address: 0x1e7954, Func Offset: 0x9d4
	// Line 3406, Address: 0x1e7960, Func Offset: 0x9e0
	// Line 3407, Address: 0x1e7994, Func Offset: 0xa14
	// Line 3408, Address: 0x1e799c, Func Offset: 0xa1c
	// Line 3409, Address: 0x1e79c0, Func Offset: 0xa40
	// Line 3410, Address: 0x1e79cc, Func Offset: 0xa4c
	// Line 3411, Address: 0x1e79d4, Func Offset: 0xa54
	// Line 3412, Address: 0x1e79dc, Func Offset: 0xa5c
	// Line 3413, Address: 0x1e79e4, Func Offset: 0xa64
	// Line 3417, Address: 0x1e79e8, Func Offset: 0xa68
	// Line 3422, Address: 0x1e79f0, Func Offset: 0xa70
	// Line 3423, Address: 0x1e7a00, Func Offset: 0xa80
	// Line 3424, Address: 0x1e7a04, Func Offset: 0xa84
	// Line 3425, Address: 0x1e7a0c, Func Offset: 0xa8c
	// Line 3428, Address: 0x1e7a14, Func Offset: 0xa94
	// Line 3429, Address: 0x1e7a3c, Func Offset: 0xabc
	// Line 3430, Address: 0x1e7a58, Func Offset: 0xad8
	// Line 3431, Address: 0x1e7a74, Func Offset: 0xaf4
	// Line 3437, Address: 0x1e7a90, Func Offset: 0xb10
	// Func End, Address: 0x1e7aa4, Func Offset: 0xb24
	scePrintf("bhEff_E15_Poison - UNIMPLEMENTED!\n");
}

// 99.06% matching
void bhEne15_RotChar(BH_PWORK* pw, int goal, int add_ang)
{
    int rot;

    if (!(pw->flg & 0x80))
    {
        if (add_ang & 0x80000000)
        {
            add_ang = -add_ang;
            goal = (unsigned short)(goal + NJM_DEG_ANG(180.0f));
        }
        
        rot = (unsigned short)(add_ang + (goal - pw->ay));
        
        if (rot < (add_ang + add_ang)) 
        {
            pw->ay = goal;
            return;
        }
        
        pw->ay = pw->ay - add_ang;
        if (rot <= NJM_DEG_ANG(180.0f))
        {
            pw->ay += (add_ang + add_ang);
        }
    }
}

// 100% matching!
static int AbleToFall(BH_PWORK* pp)
{
    O_WORK* owk;

    owk = &pp->mlwP->owP[1];

    if (((owk->mtx[12] <= rom->posp[1].px) || (owk->mtx[12] >= rom->posp[4].px))
      || (owk->mtx[14] <= rom->posp[2].pz) || (owk->mtx[14] >= rom->posp[3].pz))
        return 1;

    return 0;
}

// 
// Start address: 0x1e7bc0
static int _DrivePlayer()
{
	float FP;
	float FP1;
	float FP0;
	float ofs;
	int ans;
	// Line 3518, Address: 0x1e7bc0, Func Offset: 0
	// Line 3521, Address: 0x1e7bd8, Func Offset: 0x18
	// Line 3519, Address: 0x1e7be0, Func Offset: 0x20
	// Line 3521, Address: 0x1e7be4, Func Offset: 0x24
	// Line 3522, Address: 0x1e7bec, Func Offset: 0x2c
	// Line 3521, Address: 0x1e7bf4, Func Offset: 0x34
	// Line 3522, Address: 0x1e7bfc, Func Offset: 0x3c
	// Line 3523, Address: 0x1e7c04, Func Offset: 0x44
	// Line 3525, Address: 0x1e7c28, Func Offset: 0x68
	// Line 3527, Address: 0x1e7c38, Func Offset: 0x78
	// Line 3529, Address: 0x1e7c40, Func Offset: 0x80
	// Line 3530, Address: 0x1e7c7c, Func Offset: 0xbc
	// Line 3531, Address: 0x1e7cbc, Func Offset: 0xfc
	// Line 3532, Address: 0x1e7cc0, Func Offset: 0x100
	// Line 3533, Address: 0x1e7ccc, Func Offset: 0x10c
	// Line 3532, Address: 0x1e7cd4, Func Offset: 0x114
	// Line 3533, Address: 0x1e7cd8, Func Offset: 0x118
	// Line 3532, Address: 0x1e7cdc, Func Offset: 0x11c
	// Line 3533, Address: 0x1e7ce4, Func Offset: 0x124
	// Line 3534, Address: 0x1e7ce8, Func Offset: 0x128
	// Line 3532, Address: 0x1e7cf0, Func Offset: 0x130
	// Line 3533, Address: 0x1e7cfc, Func Offset: 0x13c
	// Line 3534, Address: 0x1e7d00, Func Offset: 0x140
	// Line 3535, Address: 0x1e7d04, Func Offset: 0x144
	// Line 3533, Address: 0x1e7d08, Func Offset: 0x148
	// Line 3534, Address: 0x1e7d0c, Func Offset: 0x14c
	// Line 3533, Address: 0x1e7d10, Func Offset: 0x150
	// Line 3535, Address: 0x1e7d14, Func Offset: 0x154
	// Line 3533, Address: 0x1e7d18, Func Offset: 0x158
	// Line 3534, Address: 0x1e7d24, Func Offset: 0x164
	// Line 3535, Address: 0x1e7d2c, Func Offset: 0x16c
	// Line 3534, Address: 0x1e7d30, Func Offset: 0x170
	// Line 3535, Address: 0x1e7d38, Func Offset: 0x178
	// Line 3537, Address: 0x1e7d48, Func Offset: 0x188
	// Line 3538, Address: 0x1e7d78, Func Offset: 0x1b8
	// Line 3539, Address: 0x1e7d90, Func Offset: 0x1d0
	// Line 3540, Address: 0x1e7da8, Func Offset: 0x1e8
	// Line 3539, Address: 0x1e7dac, Func Offset: 0x1ec
	// Line 3540, Address: 0x1e7db0, Func Offset: 0x1f0
	// Line 3543, Address: 0x1e7dd4, Func Offset: 0x214
	// Line 3545, Address: 0x1e7dec, Func Offset: 0x22c
	// Line 3547, Address: 0x1e7df0, Func Offset: 0x230
	// Line 3548, Address: 0x1e7df8, Func Offset: 0x238
	// Line 3550, Address: 0x1e7e14, Func Offset: 0x254
	// Line 3554, Address: 0x1e7e28, Func Offset: 0x268
	// Line 3550, Address: 0x1e7e2c, Func Offset: 0x26c
	// Line 3551, Address: 0x1e7e30, Func Offset: 0x270
	// Line 3550, Address: 0x1e7e34, Func Offset: 0x274
	// Line 3551, Address: 0x1e7e3c, Func Offset: 0x27c
	// Line 3552, Address: 0x1e7e44, Func Offset: 0x284
	// Line 3551, Address: 0x1e7e48, Func Offset: 0x288
	// Line 3552, Address: 0x1e7e50, Func Offset: 0x290
	// Line 3555, Address: 0x1e7e60, Func Offset: 0x2a0
	// Func End, Address: 0x1e7e7c, Func Offset: 0x2bc
	scePrintf("_DrivePlayer - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1e7e80
static void DrivePlayer(BH_PWORK* epw)
{
	int _mtnno;
	// Line 3558, Address: 0x1e7e80, Func Offset: 0
	// Line 3560, Address: 0x1e7e94, Func Offset: 0x14
	// Line 3561, Address: 0x1e7ea8, Func Offset: 0x28
	// Line 3563, Address: 0x1e7edc, Func Offset: 0x5c
	// Line 3564, Address: 0x1e7f00, Func Offset: 0x80
	// Line 3565, Address: 0x1e7f20, Func Offset: 0xa0
	// Line 3566, Address: 0x1e8040, Func Offset: 0x1c0
	// Line 3569, Address: 0x1e8048, Func Offset: 0x1c8
	// Line 3570, Address: 0x1e806c, Func Offset: 0x1ec
	// Line 3572, Address: 0x1e808c, Func Offset: 0x20c
	// Line 3573, Address: 0x1e80a4, Func Offset: 0x224
	// Line 3574, Address: 0x1e80b8, Func Offset: 0x238
	// Line 3575, Address: 0x1e80c0, Func Offset: 0x240
	// Line 3576, Address: 0x1e80cc, Func Offset: 0x24c
	// Line 3578, Address: 0x1e80dc, Func Offset: 0x25c
	// Line 3581, Address: 0x1e80e4, Func Offset: 0x264
	// Line 3582, Address: 0x1e8108, Func Offset: 0x288
	// Line 3584, Address: 0x1e8128, Func Offset: 0x2a8
	// Line 3587, Address: 0x1e813c, Func Offset: 0x2bc
	// Line 3588, Address: 0x1e8150, Func Offset: 0x2d0
	// Line 3589, Address: 0x1e8158, Func Offset: 0x2d8
	// Line 3590, Address: 0x1e8164, Func Offset: 0x2e4
	// Line 3592, Address: 0x1e8178, Func Offset: 0x2f8
	// Line 3595, Address: 0x1e81a0, Func Offset: 0x320
	// Line 3596, Address: 0x1e81e0, Func Offset: 0x360
	// Line 3598, Address: 0x1e81e4, Func Offset: 0x364
	// Func End, Address: 0x1e81f8, Func Offset: 0x378
	scePrintf("DrivePlayer - UNIMPLEMENTED!\n");
}

// 100% matching!
static void FallingPlayer(BH_PWORK* epw)
{
    bhEne15_RotChar(plp, plp->day, NJM_DEG_ANG(90.0f));
    njAddVector((NJS_VECTOR*)&plp->px, (NJS_VECTOR*)&plp->dvx);
    plp->dvy -= 1.3f;
    plp->dvx *= 0.9f;
    plp->dvy *= 0.9f;
    plp->dvz *= 0.9f;
    
    if (plp->py < -90.0f)
    {
        plp->hp = -1;
        plp->mnwP = epw->mnwP;
        EXP0_S(0x5A) |= 1;
        epw->mode3 = 4;
        plp->spd = plp->spd;
        SetPlyMtn(plp->mtn_no);
        plp->mode0 = 6;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        plp->flg |= 0x10004;
        plp->flg &= ~0x40000;
        plp->stflg |= 0x50000;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        plp->mtn_add = 0;
    }
}

// 
// Start address: 0x1e83f0
static void SlidePlayer(BH_PWORK* epw)
{
	//int _mtnno;
	NJS_POINT3 delta;
	int _mtnno;
	// Line 3628, Address: 0x1e83f0, Func Offset: 0
	// Line 3629, Address: 0x1e8404, Func Offset: 0x14
	// Line 3630, Address: 0x1e8418, Func Offset: 0x28
	// Line 3631, Address: 0x1e853c, Func Offset: 0x14c
	// Line 3633, Address: 0x1e8544, Func Offset: 0x154
	// Line 3634, Address: 0x1e8558, Func Offset: 0x168
	// Line 3635, Address: 0x1e8568, Func Offset: 0x178
	// Line 3636, Address: 0x1e85a8, Func Offset: 0x1b8
	// Line 3638, Address: 0x1e85ac, Func Offset: 0x1bc
	// Line 3639, Address: 0x1e864c, Func Offset: 0x25c
	// Line 3642, Address: 0x1e8660, Func Offset: 0x270
	// Line 3639, Address: 0x1e8664, Func Offset: 0x274
	// Line 3642, Address: 0x1e8668, Func Offset: 0x278
	// Line 3639, Address: 0x1e866c, Func Offset: 0x27c
	// Line 3642, Address: 0x1e8674, Func Offset: 0x284
	// Line 3643, Address: 0x1e8684, Func Offset: 0x294
	// Line 3642, Address: 0x1e8688, Func Offset: 0x298
	// Line 3643, Address: 0x1e8690, Func Offset: 0x2a0
	// Line 3644, Address: 0x1e8698, Func Offset: 0x2a8
	// Line 3645, Address: 0x1e86c0, Func Offset: 0x2d0
	// Line 3646, Address: 0x1e86cc, Func Offset: 0x2dc
	// Line 3648, Address: 0x1e888c, Func Offset: 0x49c
	// Line 3649, Address: 0x1e88b8, Func Offset: 0x4c8
	// Line 3652, Address: 0x1e88cc, Func Offset: 0x4dc
	// Func End, Address: 0x1e88e0, Func Offset: 0x4f0
	scePrintf("SlidePlayer - UNIMPLEMENTED!\n");
}

// 100% matching!
static void StandupPlayer(BH_PWORK* epw)
{
    if ((plp->mtn_no == 17) || (plp->mtn_no == 16))
    {
        plp->flg |= 0xC0000;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        if (plp->mtn_no == 22)
        {
            SetPlyMtn(23);
        }
        else if (plp->mtn_no == 20)
        {
            SetPlyMtn(24);
        } 
        else
        {
            plp->mnwP = plp->mnwPb;
            plp->mode0 = 1;
            plp->mode3 = 0;
            plp->mode2 = 0;
            plp->mode1 = 0;
            plp->flg &= ~0x310004;
            plp->flg |= 0x118;
            plp->stflg &= ~0x50480;
            plp->spd = 0.0f;
            EXP0_S(0x5A) &= ~1;
        }
    }
}

// 100% matching!
static void HoldPlayer(BH_PWORK* epw)
{	
    NJS_VECTOR _v;

    if (plp->mtn_no == 19)
    {
        ikou(plp, (NJS_POINT3*)&epw->px, 8192);
    } 
    else
    {        
        _v = *(NJS_VECTOR*)&plp->px;

        njSubVector(&_v, (NJS_VECTOR*)&epw->px);
        njAddVector(&_v, (NJS_VECTOR*)&plp->px);
        
        ikou(plp, &_v, 8192);
    }
    
    {
        NJS_VECTOR _v;
        NJS_POINT3 pos; 
	    O_WORK* owk;
        
        _v.x = -njSin(epw->ay);
        _v.y = 0;
        _v.z = -njCos(epw->ay);
        
        njUnitVector(&_v);
        
        _v.x *= 2.0f;
        _v.z *= 2.0f;
        
        owk = epw->mlwP->owP;
        pos.x = owk[1].mtx[12];
        pos.y = 0.0f;
        pos.z = owk[1].mtx[14];
        
        njAddVector(&_v, &pos);
        VacumeToPoint(plp, &_v);
    }
}

// 100% matching!
static void FlyingPlayer(BH_PWORK* epw)
{
	NJS_POINT3 pos1;
    NJS_POINT3 pos2;
	NJS_POINT3 pos3;    	    
	O_WORK* owk;
    NJS_POINT3 _p = { 0.0f, 8.0f, 0.0f };

    njCalcPoint(&epw->mlwP->owP[10].mtx, &_p, &pos1);
    
    owk = plp->mlwP->owP;
    pos2.x = owk[1].mtx[12];
    pos2.y = owk[1].mtx[13];
    pos2.z = owk[1].mtx[14];
    
    pos3 = *(NJS_POINT3*)&plp->px;
    
    njSubVector(&pos3, &pos2);
    njAddVector(&pos1, &pos3);
    
    *(NJS_POINT3*)&plp->px = pos1;
}

// 100% matching!
static void FallDiePlayer(BH_PWORK* epw)
{
    switch (plp->mode1)
    {
    case 0:
        plp->mnwP = plp->mnwPb;
        plp->flg &= ~0x310004;
        plp->flg &= ~0x118;
        plp->stflg &= ~0x10480;
        plp->stflg |= 8;
        plp->spd = 0.0f;
        plp->mode1++;
        break;
        
    case 1:
        CallPlayerVoice(1025);
        StartVibrationEx(1, 11);
        plp->mode1++;
        break;
        
    case 2:
        EXP0_S(0x5A) &= ~1;
        plp->flg |= 2;
        sys->ts_flg |= 0x4000;
        break;
        
    }
}

// 100% matching!
static void DiePlayer(BH_PWORK* epw)
{
    if (plp->mode1 == 0)
    {
        CallPlayerVoice(1025);
        plp->mode1++;
    }
    
    if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
    {
        EXP0_S(0x5A) &= ~1;
        plp->flg |= 2;
        plp->mtn_add = 0;
        sys->ts_flg |= 0x4000;
    }
}

// 100% matching!
static void ChangeAmbient(short* plist, unsigned char add)
{
    while (*plist != 0xFF)
    {
        switch (*(unsigned char *)plist)
        {
        case 18:
            *((unsigned char *)plist + 5) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 19:
            *((unsigned char *)plist + 9) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 22:
            *((unsigned char *)plist + 5) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 23:
            *((unsigned char *)plist + 9) = add;
            plist++;
            plist += *plist;
            plist++;
            break;
            
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:            
        case 5:
            plist++;
            break;
            
        case 8:
        case 9:
            plist += 2;
            break;
            
        default:
            plist++;
            plist += *plist;
            plist++;
            break;
            
        }
    }
}

// 99.93% matching
static void SetMince(BH_PWORK* epw, int type, int num)
{
    int i;
	int eno;

    sys->ef.id = 250;
    sys->ef.flg = 1;
    sys->ef.type = type;
    
    *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&epw->dpx;
    
    sys->ef.sx = sys->ef.sy = 0.1f + (0.3f * njRandom());
    sys->ef.sz = 0.0f;
    sys->ef.mdlver = 0;
    
    for (i = 0; i < num; i++)
    {
        sys->ef.ay = ((bhArcTan2(epw->dvx, epw->dvz) + (21845.0f * njRandom())) - 10922.0f);
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            eff[eno].txp[0] = epw->txp[0];
            eff[eno].tex_id = 1;
            *(NJS_POINT3*)&eff[eno].xn = *(NJS_POINT3*)&epw->dvx;
        }
    }
}

// 100% matching!
static void CoreInit(BH_PWORK* epw) 
{
    epw->flg &= ~0x178;
    epw->flg &= ~6;
    epw->mdflg |= 4;
    epw->aoz = 0.0f;
    epw->aoy = 0.0f;
    epw->aox = 0.0f;
    epw->loz = 0.0f;
    epw->loy = 0.0f;
    epw->lox = 0.0f;
    epw->mdflg |= 2;
    epw->shp_ct = 0.0f;
    epw->mtn_md = 0;
    epw->mtn_no = 0;
    epw->mtn_tp = NULL;
    epw->mtn_add = 0;
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 0;
    ChangeAmbient(epw->mbp[0]->child->model->plist, 178);
    ChangeAmbient(epw->mbp[1]->child->model->plist, 178);
    ChangeAmbient(epw->mbp[2]->child->model->plist, 178);
    epw->mlwP->objP = epw->mbp[0];
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];
    epw->shp_ct = 0.0f;
    epw->mode0++;
    epw->mode1 = 0;
}

// 100% matching!
static void CoreMove(BH_PWORK* epw)
{
    if (!(epw->mdflg & 1) && (epw->mdflg & 2))
    {
        switch (epw->mode1)
        {
        case 0:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 1;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[2];
                epw->ct0 = 0;
                break;
            }
            epw->shp_ct += 400.0f;
            break;
            
        case 1:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 2;
                epw->ct0 = 0;
                break;
            }
            epw->shp_ct += 166.67f;
            break;
            
        case 2:
            if (epw->ct0++ == 3) {
                epw->mode1 = 3;
                epw->obj_a = epw->mbp[2];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                break;
            }
            break;
            
        case 3:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 4;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[0];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += 166.67f;
            break;
            
        case 4:
            if (1000.0f < epw->shp_ct) 
            {
                epw->mode1 = 0;
                epw->obj_a = epw->mbp[0];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += 150.0f;
            break;
            
        }
    }
}

// 100% matching!
static void CoreDie(BH_PWORK* epw)
{
    int i;

    switch (epw->mode2)
    {
    case 1:
        if (epw->mode3 == 0) 
        {
            epw->ct1 = 0;
            epw->mode3++;
        }

        switch (epw->mode1)
        { 
        case 0:
            if (1000.0f < epw->shp_ct)
            {
                epw->mode1 = 1;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[2];
                break;
            }
            epw->shp_ct += (400.0f / (epw->ct1 + 2));
            break;
            
        case 1:
            if (1000.0f < epw->shp_ct)
            {
                epw->ct0 = 0;
                epw->ct1++;

                if (epw->ct1 < 5)
                {
                    epw->mode1 = 2;
                    break;
                }
                
                epw->mode1 = 5;

                break;
            }
            epw->shp_ct += (166.67f / (epw->ct1 + 2));
            break;
            
        case 2:
            if (epw->ct0++ == 3)
            {
                epw->mode1 = 3;
                epw->obj_a = epw->mbp[2];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
            }
            break;
            
        case 3:
            if (1000.f < epw->shp_ct)
            {
                epw->mode1 = 4;
                epw->obj_a = epw->mbp[1];
                epw->obj_b = epw->mbp[0];
                epw->shp_ct = 0.0f;
                break;
            }
            epw->shp_ct += (166.67f / (epw->ct1 + 2));
            break;
            
        case 4:
            if (1000.f < epw->shp_ct)
            {
                epw->obj_a = epw->mbp[0];
                epw->obj_b = epw->mbp[1];
                epw->shp_ct = 0.0f;
                epw->mode1 = 0;
                break;
            }
            epw->shp_ct += (150.0f / (epw->ct1 + 2));
            break;
        }
        break;
    case 2:
        if (!(epw->mdflg & 1))
        {
            if (epw->mode3 == 0)
            {
                epw->ct2 = 178;
                if (epw->mode1 < 5)
                {
                    epw->mode1 = 0;
                }
                epw->mode3++;
            }
            ChangeAmbient(epw->obj_a->child->model->plist, epw->ct2);
            ChangeAmbient(epw->obj_b->child->model->plist, epw->ct2);

            if (0 < epw->ct2 - 4)
            {
                epw->ct2 -= 4;
            }
            else
            {
                epw->ct2 = 0;
            }

            switch (epw->mode1)
            {
            case 0:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 1;
                    epw->obj_a = epw->mbp[1];
                    epw->obj_b = epw->mbp[2];
                    epw->ct0 = 0;
                    break;
                }
                epw->shp_ct += 400.0f;
                break;
                
            case 1:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 2;
                    epw->ct0 = 0;
                    break;
                }
                epw->shp_ct += 166.67f;
                break;
                
            case 2:
                if (epw->ct2 == 0)
                {
                    epw->mode1 = 5;
                }
                break;
                
            case 3:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 4;
                    epw->obj_a = epw->mbp[1];
                    epw->obj_b = epw->mbp[0];
                    epw->shp_ct = 0.0f;
                    break;
                }
                epw->shp_ct += 166.67f;
                break;
                
            case 4:
                if (1000.f < epw->shp_ct)
                {
                    epw->mode1 = 0;
                    epw->obj_a = epw->mbp[0];
                    epw->obj_b = epw->mbp[1];
                    epw->shp_ct = 0.0f;
                    break;
                }
                epw->shp_ct += 150.0f;
                break;
                
            case 5:
                epw->mdflg |= 1;
                epw->id = 15;
                epw->djnt_no = 1;
                *(NJS_POINT3*)&epw->dpx = *(NJS_POINT3*)&epw->mlwP->owP[epw->djnt_no].mtx[12];
                epw->dvx = 2.0f * njSin(epw->ay);
                epw->dvz = 2.0f * njCos(epw->ay);
                epw->dvy = 0.0f;
                SetMince(epw, 2, 32);
                bhEne_SetBloodEffect5(epw, 2, 2);
                for (i = 0; i < 5; i++)
                {
                    epw->dpx += (njRandom() - 0.5) * 5.0f;
                    epw->dpy += (njRandom() - 0.5) * 5.0f;
                    epw->dpz += (njRandom() - 0.5) * 5.0f;
                    bhEne_SetBloodEffect5(epw, 0, 2);
                }
                epw->id = 53;
                RequestEnemySe(GetLocalEneNo(epw), (NJS_POINT3*)&epw->px, 2147484170);
                epw->mode1 = 6;
                break;
            }
        }
        break;
    }
}

// 100% matching!
void bhEne53(BH_PWORK* epw)
{
    switch (epw->mode0)
    {
    case 0:
        CoreInit(epw);

    case 1:
        CoreMove(epw);
        break;
		
    case 3:
        CoreDie(epw);
        break;

    case 5:
        bhEne_Event(epw);
        break;
    }
}
