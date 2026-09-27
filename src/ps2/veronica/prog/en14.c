#include "../../../ps2/veronica/prog/en14.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: Third Form Alexia 

static unsigned char flip_tree[22] = { 0, 1, 2, 3, 4, 5, 6, 9, 10, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };
static char SdwTab[5] = { 1, 6, 11, 12, -1 };
static DMG_REACT DmgReact[21] =
{
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },   
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  1,  0,  0 }, 0 },   
    { {  2,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },
    { {  1,  1,  0 }, {  1,  0,  0 }, 0 },
    { {  2,  1,  0 }, {  1,  1,  1 }, 1 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 2 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 1 },
    { { -1, -1, -1 }, {  1,  0,  0 }, 0 },
    { {  2,  2,  2 }, {  1,  1,  1 }, 0 },
    { {  2,  2,  2 }, {  1,  0,  0 }, 1 },
    { {  2,  2,  2 }, {  1,  1,  1 }, 0 }
};
static COMBWEP_WORK CombWepTbl[21] =
{
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  4, { 1, 0, 0 }, 120, 800 },
    { 20, { 6, 4, 2 },  60,   0 },
    { 20, { 6, 4, 2 },  60,   0 },
    { 20, { 6, 4, 2 },  60,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    { 25, { 5, 3, 1 },  30,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  1, { 1, 1, 1 },  60,   0 },
    { 25, { 5, 4, 2 },  30,   0 },
    {  0, { 0, 0, 0 },  60,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 },
    {  0, { 0, 0, 0 },   0,   0 }
};
static COMBJOINT_WORK CombJointTbl[22] = { 0 };
static BLOOD_TBL BloodTbl[22] =
{
    { 1, {  0.0f,  0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 0, {  0.0f,  2.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 0, {  0.0f,  2.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 0, {  0.0f,  1.0f, -2.0f }, 5.0f, 3.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 2.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 2.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 1, {  0.0f,  0.0f, -1.0f }, 1.0f, 1.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f },
    { 0, {  0.0f, -1.0f,  0.0f }, 1.0f, 2.0f, 1.0f }
};
static CPCL CapColTab[25] = 
{
    {   1,   2,  18 },
    {   2,   3,  18 },
    {   3,   3,  30 },
    {   0,  25,   0 },
    {   3,   3,  20 },
    {  15,  40,   0 },
    {   3,   3,  20 },
    { -15,  40,   0 },
    {   7,   7,  12 },
    {   0,   0,   0 },
    {   8,   8,  12 },
    {   0,   0,   0 },
    {   9,   9,  12 },
    {   0,   0,   0 },
    {  10,  10,  12 },
    {   0,   0,   0 },
    {   3,   4,  12 },
    {   4,   5,   8 },
    {   5,   6,   6 },
    {   6,   6,  15 },
    {   0,  15,   0 },
    {   1,  11,  20 },
    {   1,   1,  30 },
    {   0, -20,   0 },
    {   0,   0,   0 }
};
static P_WORK ShapeTbl_Acid_F[5] = 
{
    {   0,    0.0f },
    {   5, 1000.0f },
    {  12, 1000.0f },
    {  20,    0.0f },
    { 999,    0.0f }
};
static P_WORK ShapeTbl_Acid_S[6] = 
{
    {   0,    0.0f },
    {   6, 1000.0f },
    {  10,  300.0f },
    {  16, 1000.0f },
    {  25,    0.0f },
    { 999,    0.0f }
};
/* unused below */
/*static char joint_tree[1][6];
static P_WORK ShapeTbl_Acid_A[5];*/

void (*bhEne14_Mode0[6])(BH_PWORK*) = 
{
	bhEne14_Init,
	bhEne14_Move,
	bhEne14_Nage,
	bhEne14_Damage,
	bhEne14_Die,
	bhEne_Event
};
void (*bhEne14_BrainType[2])(BH_PWORK*) = 
{
	bhEne14_BR00,
	bhEne14_BR01
};
void (*bhEne14_MoveMode2[12])(BH_PWORK*) = 
{
	bhEne14_MV00,
	bhEne14_MV01,
	bhEne14_MV02,
	bhEne14_MV03,
	bhEne14_MV04,
	bhEne14_MV05,
	bhEne14_MV06,
	bhEne14_MV07,
	bhEne14_MV08,
	bhEne14_MV09,
	bhEne14_MV10,
	bhEne14_MV11
};
void (*bhEne14_NageMode2[1])(BH_PWORK*) = { bhEne14_NG00 };
void (*bhEne14_DamageMode2[2])(BH_PWORK*) = 
{
	bhEne14_DG00,
	bhEne14_DG01
};

// 100% matching!
void bhEne14(BH_PWORK* epw)
{
	int i;
	O_WRK* op;

    bhEne14_Mode0[epw->mode0](epw);
    bhEne14_CallSE(epw);
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (epw->flg & 0x20000)
    {
        bhEne14_TailSwing(epw);
    }
    
    if (epw->flg & 0x10)
    {
        bhEne14_CheckWall(epw);
    }
    
    if (epw->type == 1)
    {
        bhEne14_SetMotion(epw);
    }
    
    bhCalcModel(epw);
    bhEne14_LookPlayaer(epw);
    bhEne_SetWeponAtr(epw, 6, 1, 5.0f);
    
    if (epw->type == 1)
    {
        bhEne14_PlayerControl(epw);
    }
    
    *(O_WRK **)(epw->exp0 + 0x244) = NULL;
    for (i = 0, op = eff; i < 512; i++, op++)
    {
        if ((op->flg & 1) && !(op->stflg & 0x1000000) && (op->id == 130) && (op->type == 4))
        {
            *(O_WRK **)(epw->exp0 + 0x244) = op;
            break;
        }
    }
}

// 100% matching!
void bhEne14_Init(BH_PWORK* epw)
{
	BH_PWORK* ep;
	int i;

    epw->flg |= 0x78;
    epw->flg &= ~6;
    epw->flg2 |= 1;
    epw->ar = 8.0f;
    epw->ah = 25.0f;
    epw->car = 4.0f;
    epw->car = 25.0f;
    epw->hp = 400;
    
    if (epw->type == 0)
    {
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
        epw->mtn_no = 0;
        epw->mtn_md = 0;
        epw->hokan_rate = 65536;
        epw->hokan_count = 0;
        epw->mtn_add = 65536;
        epw->mtn_tp = flip_tree;
        epw->frm_no = 0;
    } 
    else
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 4;
        epw->mode3 = 0;
        epw->mtn_no = 5;
        epw->mtn_md = 0;
        epw->hokan_rate = 65536;
        epw->hokan_count = 0;
        epw->mtn_add = 65536;
        epw->mtn_tp = flip_tree;
        epw->frm_no = 0;
    }
    
    epw->clp_jno[0] = 6;
    epw->clp_jno[1] = 1;
    epw->clp_jno[2] = 7;
    epw->clp_jno[3] = 9;
    epw->clp_jno[4] = 11;
    epw->clp_jno[5] = 15;
    epw->clp_jno[6] = 18;
    epw->clp_jno[7] = 21;
    epw->mdflg &= ~0x20;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(584, 8);
    }
    
    epw->flg &= ~0x80;
    
    if (epw->type == 0)
    {
        for (i = 0, ep = ene; i <= sys->enow; i++, ep++)
        {
            if ((ep->flg & 1) && (ep->id == 13)) 
            {
                epw->lkwkp = (unsigned char*)ep;
                epw->lkono = 0;
                epw->px = ep->px;
                epw->py = ep->py;
                epw->pz = ep->pz;
                epw->ay = ep->ay;
                epw->flg &= ~0x10;
                break;
            }
        }
    }
    
    if (epw->type == 1)
    {
        if (!(epw->flg & 0x800))
        {
            bhSetShadow(SdwTab, (unsigned char*) epw, 2, 6.0f, 6.0f, 4.0f);
            epw->flg |= 0x800;
        }
        epw->stflg &= ~8;
    } 
    else
    {
        epw->stflg |= 8;
    }

    epw->cpcl = CapColTab;
    bhEne14_TailInit(epw);
}


// 100% matching!
void bhEne14_Brain(BH_PWORK* epw)
{
	bhEne14_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne14_BR00()
{
	
}

// 100% matching!
void bhEne14_BR01()
{

}

// 100% matching!
void bhEne14_Move(BH_PWORK* epw) 
{
    bhEne14_MoveMode2[epw->mode2](epw);
    if (epw->mode1 == 1)
    {
        bhEne14_Brain(epw);
    }
    
    if (epw->type == 1)
    {
        if (epw->flg & 4)
        {
            epw->flg &= ~4;
            bhEne14_InitDamage(epw);
        }
    }
}

// 100% matching!
void bhEne14_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_md &= ~2;
        epw->flg |= 0x100000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 18;
        epw->hokan_rate = 45875;
        epw->mode3++;
    }
}

// 100% matching!
void bhEne14_MV01(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 16;
        epw->mtn_no = 1;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->frm_no == 2949120)
        {
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 16;
        }

    }
}

// 100% matching!
void bhEne14_MV02(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int ang; 
    int fno;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        ep = (BH_PWORK*) epw->lkwkp;
        ang = (short)(bhArcTan2(ep->px - plp->px, ep->pz - plp->pz) - ep->ay);
        
        if (ang < -NJM_DEG_ANG(30.0f))
        {
            epw->ct1 = 1;
        } 
        else if (ang > NJM_DEG_ANG(30.0f))
        {
            epw->ct1 = 2;
        }
        else
        {
            epw->ct1 = 0;
        }

        switch (epw->ct1)
        {
        case 0: 
            epw->mtn_no = 2;
            break;
        case 1: 
            epw->mtn_no = 3;
            break;
        case 2:
            epw->mtn_no = 3;
            epw->mtn_md |= 2;
        }
        
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 0.0f;
        epw->mode3++;

    case 1:
        fno = epw->frm_no / 65536;
        switch (epw->ct1) 
        {
            case 0:
                epw->shp_ct = bhEne_GetShapeCnt(ShapeTbl_Acid_F, fno);
                break;
            default:
                epw->shp_ct = bhEne_GetShapeCnt(ShapeTbl_Acid_S, fno);
        }
        
        if (fno >= 7 && fno < 13)
        {
            bhEne14_Acid(epw, 1);            
        }
        
        if (fno == 15)
        {
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 4;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->mdflg &= ~2;
        }

    }
}

// 100% matching!
void bhEne14_MV03()
{

}

// 
// Start address: 0x1de340
void bhEne14_MV04(BH_PWORK* epw)
{
	//float dist;
	NJS_LINE ln;
	NJS_POINT3 cp;
	float spd;
	NJS_VECTOR v;
	NJS_VECTOR vec;
	int ang;
	ATR_WORK* hp;
	float dist;
	// Line 827, Address: 0x1de340, Func Offset: 0
	// Line 830, Address: 0x1de358, Func Offset: 0x18
	// Line 832, Address: 0x1de384, Func Offset: 0x44
	// Line 833, Address: 0x1de38c, Func Offset: 0x4c
	// Line 834, Address: 0x1de390, Func Offset: 0x50
	// Line 832, Address: 0x1de394, Func Offset: 0x54
	// Line 833, Address: 0x1de39c, Func Offset: 0x5c
	// Line 837, Address: 0x1de3a0, Func Offset: 0x60
	// Line 833, Address: 0x1de3a8, Func Offset: 0x68
	// Line 834, Address: 0x1de3b0, Func Offset: 0x70
	// Line 837, Address: 0x1de3b8, Func Offset: 0x78
	// Line 838, Address: 0x1de3c0, Func Offset: 0x80
	// Line 841, Address: 0x1de3c8, Func Offset: 0x88
	// Line 843, Address: 0x1de3d0, Func Offset: 0x90
	// Line 842, Address: 0x1de3d4, Func Offset: 0x94
	// Line 843, Address: 0x1de3d8, Func Offset: 0x98
	// Line 844, Address: 0x1de3dc, Func Offset: 0x9c
	// Line 846, Address: 0x1de3e4, Func Offset: 0xa4
	// Line 849, Address: 0x1de3f0, Func Offset: 0xb0
	// Line 852, Address: 0x1de3f4, Func Offset: 0xb4
	// Line 846, Address: 0x1de3f8, Func Offset: 0xb8
	// Line 849, Address: 0x1de400, Func Offset: 0xc0
	// Line 852, Address: 0x1de404, Func Offset: 0xc4
	// Line 854, Address: 0x1de408, Func Offset: 0xc8
	// Line 862, Address: 0x1de414, Func Offset: 0xd4
	// Line 863, Address: 0x1de42c, Func Offset: 0xec
	// Line 865, Address: 0x1de444, Func Offset: 0x104
	// Line 870, Address: 0x1de460, Func Offset: 0x120
	// Line 865, Address: 0x1de464, Func Offset: 0x124
	// Line 866, Address: 0x1de474, Func Offset: 0x134
	// Line 870, Address: 0x1de490, Func Offset: 0x150
	// Line 871, Address: 0x1de498, Func Offset: 0x158
	// Line 872, Address: 0x1de4a8, Func Offset: 0x168
	// Line 874, Address: 0x1de4b8, Func Offset: 0x178
	// Line 876, Address: 0x1de4fc, Func Offset: 0x1bc
	// Line 877, Address: 0x1de520, Func Offset: 0x1e0
	// Line 878, Address: 0x1de53c, Func Offset: 0x1fc
	// Line 881, Address: 0x1de598, Func Offset: 0x258
	// Line 883, Address: 0x1de5a0, Func Offset: 0x260
	// Line 882, Address: 0x1de5a4, Func Offset: 0x264
	// Line 883, Address: 0x1de5a8, Func Offset: 0x268
	// Line 884, Address: 0x1de5ac, Func Offset: 0x26c
	// Line 886, Address: 0x1de5b4, Func Offset: 0x274
	// Line 887, Address: 0x1de5c0, Func Offset: 0x280
	// Line 888, Address: 0x1de5c8, Func Offset: 0x288
	// Line 891, Address: 0x1de624, Func Offset: 0x2e4
	// Line 893, Address: 0x1de62c, Func Offset: 0x2ec
	// Line 892, Address: 0x1de630, Func Offset: 0x2f0
	// Line 893, Address: 0x1de634, Func Offset: 0x2f4
	// Line 894, Address: 0x1de638, Func Offset: 0x2f8
	// Line 895, Address: 0x1de640, Func Offset: 0x300
	// Line 898, Address: 0x1de64c, Func Offset: 0x30c
	// Line 899, Address: 0x1de66c, Func Offset: 0x32c
	// Line 898, Address: 0x1de670, Func Offset: 0x330
	// Line 899, Address: 0x1de688, Func Offset: 0x348
	// Line 900, Address: 0x1de69c, Func Offset: 0x35c
	// Line 899, Address: 0x1de6a0, Func Offset: 0x360
	// Line 900, Address: 0x1de6a8, Func Offset: 0x368
	// Line 901, Address: 0x1de6c4, Func Offset: 0x384
	// Line 902, Address: 0x1de714, Func Offset: 0x3d4
	// Line 904, Address: 0x1de71c, Func Offset: 0x3dc
	// Line 905, Address: 0x1de73c, Func Offset: 0x3fc
	// Line 904, Address: 0x1de744, Func Offset: 0x404
	// Line 905, Address: 0x1de748, Func Offset: 0x408
	// Line 907, Address: 0x1de76c, Func Offset: 0x42c
	// Line 910, Address: 0x1de7b8, Func Offset: 0x478
	// Line 912, Address: 0x1de7c0, Func Offset: 0x480
	// Line 911, Address: 0x1de7c4, Func Offset: 0x484
	// Line 912, Address: 0x1de7c8, Func Offset: 0x488
	// Line 913, Address: 0x1de7cc, Func Offset: 0x48c
	// Line 915, Address: 0x1de7d4, Func Offset: 0x494
	// Line 917, Address: 0x1de7e0, Func Offset: 0x4a0
	// Line 918, Address: 0x1de800, Func Offset: 0x4c0
	// Line 917, Address: 0x1de804, Func Offset: 0x4c4
	// Line 918, Address: 0x1de81c, Func Offset: 0x4dc
	// Line 919, Address: 0x1de830, Func Offset: 0x4f0
	// Line 918, Address: 0x1de834, Func Offset: 0x4f4
	// Line 919, Address: 0x1de83c, Func Offset: 0x4fc
	// Line 920, Address: 0x1de858, Func Offset: 0x518
	// Line 921, Address: 0x1de8a8, Func Offset: 0x568
	// Line 923, Address: 0x1de8b0, Func Offset: 0x570
	// Line 926, Address: 0x1de8fc, Func Offset: 0x5bc
	// Line 928, Address: 0x1de904, Func Offset: 0x5c4
	// Line 927, Address: 0x1de908, Func Offset: 0x5c8
	// Line 928, Address: 0x1de90c, Func Offset: 0x5cc
	// Line 929, Address: 0x1de910, Func Offset: 0x5d0
	// Line 931, Address: 0x1de914, Func Offset: 0x5d4
	// Line 932, Address: 0x1de934, Func Offset: 0x5f4
	// Line 931, Address: 0x1de938, Func Offset: 0x5f8
	// Line 932, Address: 0x1de950, Func Offset: 0x610
	// Line 933, Address: 0x1de964, Func Offset: 0x624
	// Line 932, Address: 0x1de968, Func Offset: 0x628
	// Line 933, Address: 0x1de970, Func Offset: 0x630
	// Line 934, Address: 0x1de98c, Func Offset: 0x64c
	// Line 945, Address: 0x1de9e0, Func Offset: 0x6a0
	// Line 946, Address: 0x1de9f0, Func Offset: 0x6b0
	// Line 947, Address: 0x1de9f4, Func Offset: 0x6b4
	// Line 948, Address: 0x1dea04, Func Offset: 0x6c4
	// Line 949, Address: 0x1dea08, Func Offset: 0x6c8
	// Line 950, Address: 0x1dea10, Func Offset: 0x6d0
	// Line 953, Address: 0x1dea14, Func Offset: 0x6d4
	// Line 954, Address: 0x1dea1c, Func Offset: 0x6dc
	// Line 961, Address: 0x1dea24, Func Offset: 0x6e4
	// Line 962, Address: 0x1dea34, Func Offset: 0x6f4
	// Line 963, Address: 0x1dea38, Func Offset: 0x6f8
	// Line 961, Address: 0x1dea3c, Func Offset: 0x6fc
	// Line 964, Address: 0x1dea40, Func Offset: 0x700
	// Line 961, Address: 0x1dea44, Func Offset: 0x704
	// Line 962, Address: 0x1dea4c, Func Offset: 0x70c
	// Line 963, Address: 0x1dea60, Func Offset: 0x720
	// Line 964, Address: 0x1dea78, Func Offset: 0x738
	// Line 965, Address: 0x1dea80, Func Offset: 0x740
	// Line 966, Address: 0x1dea9c, Func Offset: 0x75c
	// Line 967, Address: 0x1deaac, Func Offset: 0x76c
	// Line 968, Address: 0x1deabc, Func Offset: 0x77c
	// Line 970, Address: 0x1deacc, Func Offset: 0x78c
	// Line 974, Address: 0x1dead4, Func Offset: 0x794
	// Line 977, Address: 0x1deafc, Func Offset: 0x7bc
	// Line 978, Address: 0x1deb08, Func Offset: 0x7c8
	// Line 980, Address: 0x1deb0c, Func Offset: 0x7cc
	// Line 979, Address: 0x1deb10, Func Offset: 0x7d0
	// Line 980, Address: 0x1deb14, Func Offset: 0x7d4
	// Line 981, Address: 0x1deb18, Func Offset: 0x7d8
	// Line 988, Address: 0x1deb20, Func Offset: 0x7e0
	// Line 989, Address: 0x1deb30, Func Offset: 0x7f0
	// Line 990, Address: 0x1deb3c, Func Offset: 0x7fc
	// Line 991, Address: 0x1deb60, Func Offset: 0x820
	// Line 993, Address: 0x1deb64, Func Offset: 0x824
	// Line 994, Address: 0x1deb6c, Func Offset: 0x82c
	// Line 998, Address: 0x1deb74, Func Offset: 0x834
	// Line 1000, Address: 0x1deb90, Func Offset: 0x850
	// Line 1006, Address: 0x1deba0, Func Offset: 0x860
	// Line 1012, Address: 0x1deba4, Func Offset: 0x864
	// Line 1006, Address: 0x1debb0, Func Offset: 0x870
	// Line 1007, Address: 0x1debb4, Func Offset: 0x874
	// Line 1008, Address: 0x1debc4, Func Offset: 0x884
	// Line 1009, Address: 0x1debd4, Func Offset: 0x894
	// Line 1010, Address: 0x1debe4, Func Offset: 0x8a4
	// Line 1011, Address: 0x1debf4, Func Offset: 0x8b4
	// Line 1012, Address: 0x1dec00, Func Offset: 0x8c0
	// Line 1015, Address: 0x1dec08, Func Offset: 0x8c8
	// Line 1016, Address: 0x1dec24, Func Offset: 0x8e4
	// Line 1017, Address: 0x1dec2c, Func Offset: 0x8ec
	// Line 1018, Address: 0x1dec34, Func Offset: 0x8f4
	// Line 1022, Address: 0x1dec3c, Func Offset: 0x8fc
	// Line 1023, Address: 0x1dec48, Func Offset: 0x908
	// Line 1024, Address: 0x1dec64, Func Offset: 0x924
	// Line 1025, Address: 0x1dec68, Func Offset: 0x928
	// Line 1031, Address: 0x1dec74, Func Offset: 0x934
	// Func End, Address: 0x1dec90, Func Offset: 0x950
}

// 100% matching!
void bhEne14_MV05()
{

}

// 100% matching!
void bhEne14_MV06()
{

}

// 100% matching!
void bhEne14_MV07()
{

}

// 100% matching!
void bhEne14_MV08()
{

}

// 100% matching!
void bhEne14_MV09()
{

}

// 100% matching!
void bhEne14_MV10()
{

}

// 
// Start address: 0x1decf0
void bhEne14_MV11(BH_PWORK* epw)
{
	//float dist;
	NJS_LINE ln;
	NJS_POINT3 cp;
	float spd;
	NJS_VECTOR v;
	NJS_VECTOR vec;
	int ang;
	ATR_WORK* hp;
	float dist;
	// Line 1107, Address: 0x1decf0, Func Offset: 0
	// Line 1110, Address: 0x1ded08, Func Offset: 0x18
	// Line 1112, Address: 0x1ded34, Func Offset: 0x44
	// Line 1113, Address: 0x1ded3c, Func Offset: 0x4c
	// Line 1114, Address: 0x1ded40, Func Offset: 0x50
	// Line 1112, Address: 0x1ded44, Func Offset: 0x54
	// Line 1113, Address: 0x1ded4c, Func Offset: 0x5c
	// Line 1117, Address: 0x1ded50, Func Offset: 0x60
	// Line 1113, Address: 0x1ded58, Func Offset: 0x68
	// Line 1114, Address: 0x1ded60, Func Offset: 0x70
	// Line 1117, Address: 0x1ded68, Func Offset: 0x78
	// Line 1118, Address: 0x1ded70, Func Offset: 0x80
	// Line 1121, Address: 0x1ded78, Func Offset: 0x88
	// Line 1123, Address: 0x1ded80, Func Offset: 0x90
	// Line 1122, Address: 0x1ded84, Func Offset: 0x94
	// Line 1123, Address: 0x1ded88, Func Offset: 0x98
	// Line 1124, Address: 0x1ded8c, Func Offset: 0x9c
	// Line 1126, Address: 0x1ded94, Func Offset: 0xa4
	// Line 1129, Address: 0x1deda8, Func Offset: 0xb8
	// Line 1130, Address: 0x1dedb4, Func Offset: 0xc4
	// Line 1131, Address: 0x1dedb8, Func Offset: 0xc8
	// Line 1132, Address: 0x1dedc0, Func Offset: 0xd0
	// Line 1136, Address: 0x1dedc4, Func Offset: 0xd4
	// Line 1139, Address: 0x1dedd8, Func Offset: 0xe8
	// Line 1141, Address: 0x1dede0, Func Offset: 0xf0
	// Line 1149, Address: 0x1dedec, Func Offset: 0xfc
	// Line 1150, Address: 0x1dee04, Func Offset: 0x114
	// Line 1152, Address: 0x1dee1c, Func Offset: 0x12c
	// Line 1157, Address: 0x1dee38, Func Offset: 0x148
	// Line 1152, Address: 0x1dee3c, Func Offset: 0x14c
	// Line 1153, Address: 0x1dee4c, Func Offset: 0x15c
	// Line 1157, Address: 0x1dee68, Func Offset: 0x178
	// Line 1158, Address: 0x1dee70, Func Offset: 0x180
	// Line 1159, Address: 0x1dee80, Func Offset: 0x190
	// Line 1162, Address: 0x1dee90, Func Offset: 0x1a0
	// Line 1163, Address: 0x1deeb4, Func Offset: 0x1c4
	// Line 1164, Address: 0x1deed0, Func Offset: 0x1e0
	// Line 1165, Address: 0x1def28, Func Offset: 0x238
	// Line 1166, Address: 0x1def30, Func Offset: 0x240
	// Line 1169, Address: 0x1def8c, Func Offset: 0x29c
	// Line 1170, Address: 0x1defac, Func Offset: 0x2bc
	// Line 1169, Address: 0x1defb0, Func Offset: 0x2c0
	// Line 1170, Address: 0x1defc8, Func Offset: 0x2d8
	// Line 1171, Address: 0x1defdc, Func Offset: 0x2ec
	// Line 1170, Address: 0x1defe0, Func Offset: 0x2f0
	// Line 1171, Address: 0x1defe8, Func Offset: 0x2f8
	// Line 1172, Address: 0x1df004, Func Offset: 0x314
	// Line 1177, Address: 0x1df058, Func Offset: 0x368
	// Line 1179, Address: 0x1df060, Func Offset: 0x370
	// Line 1180, Address: 0x1df068, Func Offset: 0x378
	// Line 1187, Address: 0x1df070, Func Offset: 0x380
	// Line 1188, Address: 0x1df080, Func Offset: 0x390
	// Line 1189, Address: 0x1df084, Func Offset: 0x394
	// Line 1187, Address: 0x1df088, Func Offset: 0x398
	// Line 1190, Address: 0x1df08c, Func Offset: 0x39c
	// Line 1187, Address: 0x1df090, Func Offset: 0x3a0
	// Line 1188, Address: 0x1df098, Func Offset: 0x3a8
	// Line 1189, Address: 0x1df0ac, Func Offset: 0x3bc
	// Line 1190, Address: 0x1df0c4, Func Offset: 0x3d4
	// Line 1191, Address: 0x1df0cc, Func Offset: 0x3dc
	// Line 1192, Address: 0x1df0e8, Func Offset: 0x3f8
	// Line 1193, Address: 0x1df0f8, Func Offset: 0x408
	// Line 1194, Address: 0x1df108, Func Offset: 0x418
	// Line 1196, Address: 0x1df118, Func Offset: 0x428
	// Line 1200, Address: 0x1df120, Func Offset: 0x430
	// Line 1203, Address: 0x1df140, Func Offset: 0x450
	// Line 1200, Address: 0x1df144, Func Offset: 0x454
	// Line 1203, Address: 0x1df14c, Func Offset: 0x45c
	// Line 1204, Address: 0x1df158, Func Offset: 0x468
	// Line 1206, Address: 0x1df160, Func Offset: 0x470
	// Line 1207, Address: 0x1df184, Func Offset: 0x494
	// Line 1210, Address: 0x1df18c, Func Offset: 0x49c
	// Line 1211, Address: 0x1df19c, Func Offset: 0x4ac
	// Line 1212, Address: 0x1df1c4, Func Offset: 0x4d4
	// Line 1214, Address: 0x1df1cc, Func Offset: 0x4dc
	// Line 1215, Address: 0x1df1d4, Func Offset: 0x4e4
	// Line 1220, Address: 0x1df1d8, Func Offset: 0x4e8
	// Line 1226, Address: 0x1df1e8, Func Offset: 0x4f8
	// Line 1232, Address: 0x1df1ec, Func Offset: 0x4fc
	// Line 1226, Address: 0x1df1f8, Func Offset: 0x508
	// Line 1227, Address: 0x1df1fc, Func Offset: 0x50c
	// Line 1228, Address: 0x1df20c, Func Offset: 0x51c
	// Line 1229, Address: 0x1df21c, Func Offset: 0x52c
	// Line 1230, Address: 0x1df22c, Func Offset: 0x53c
	// Line 1231, Address: 0x1df23c, Func Offset: 0x54c
	// Line 1232, Address: 0x1df248, Func Offset: 0x558
	// Line 1234, Address: 0x1df250, Func Offset: 0x560
	// Line 1235, Address: 0x1df26c, Func Offset: 0x57c
	// Line 1239, Address: 0x1df270, Func Offset: 0x580
	// Line 1240, Address: 0x1df27c, Func Offset: 0x58c
	// Line 1241, Address: 0x1df288, Func Offset: 0x598
	// Line 1242, Address: 0x1df2a4, Func Offset: 0x5b4
	// Line 1243, Address: 0x1df2a8, Func Offset: 0x5b8
	// Line 1249, Address: 0x1df2b4, Func Offset: 0x5c4
	// Func End, Address: 0x1df2d0, Func Offset: 0x5e0
}

// 100% matching!
void bhEne14_Nage(BH_PWORK* epw)
{
	bhEne14_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne14_NG00()
{

}

// 100% matching!
void bhEne14_Damage(BH_PWORK* epw)
{
	bhEne14_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne14_DG00(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mtn_md &= ~2;
        epw->mode3++;
        
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 8;
        }
    }
}

// 100% matching!
void bhEne14_DG01(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->flg &= ~0x100000;
        EXP0_I(0x240) = 8;
        epw->mtn_no = 22;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mtn_md &= ~2;
        epw->mode3++;
        
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg |= 0x100000;
            EXP0_I(0x240) = 8;
        }
    }
}

// 100% matching!
void bhEne14_Die()
{

}

// 100% matching!
void bhEne14_InitDamage(BH_PWORK* epw)
{
	bhEne14_HitMark(epw);
}

// 
// Start address: 0x1df520
void bhEne14_LookPlayaer(BH_PWORK* epw)
{
	NJS_CNK_OBJECT* objP;
	NJS_MKEY_A_MOD* mkaP;
	int ang;
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR vec;
	NJS_POINT3 view;
	int rz2;
	int rz1;
	int rz;
	int ry;
	int rx;
	float* mat2;
	float* mat;
	// Line 1391, Address: 0x1df520, Func Offset: 0
	// Line 1392, Address: 0x1df544, Func Offset: 0x24
	// Line 1391, Address: 0x1df548, Func Offset: 0x28
	// Line 1392, Address: 0x1df54c, Func Offset: 0x2c
	// Line 1401, Address: 0x1df550, Func Offset: 0x30
	// Line 1393, Address: 0x1df55c, Func Offset: 0x3c
	// Line 1401, Address: 0x1df560, Func Offset: 0x40
	// Line 1402, Address: 0x1df568, Func Offset: 0x48
	// Line 1403, Address: 0x1df574, Func Offset: 0x54
	// Line 1402, Address: 0x1df578, Func Offset: 0x58
	// Line 1403, Address: 0x1df580, Func Offset: 0x60
	// Line 1404, Address: 0x1df590, Func Offset: 0x70
	// Line 1406, Address: 0x1df598, Func Offset: 0x78
	// Line 1408, Address: 0x1df59c, Func Offset: 0x7c
	// Line 1406, Address: 0x1df5a0, Func Offset: 0x80
	// Line 1408, Address: 0x1df5b0, Func Offset: 0x90
	// Line 1411, Address: 0x1df5c0, Func Offset: 0xa0
	// Line 1415, Address: 0x1df5c4, Func Offset: 0xa4
	// Line 1411, Address: 0x1df5c8, Func Offset: 0xa8
	// Line 1412, Address: 0x1df5cc, Func Offset: 0xac
	// Line 1411, Address: 0x1df5d0, Func Offset: 0xb0
	// Line 1415, Address: 0x1df5e4, Func Offset: 0xc4
	// Line 1411, Address: 0x1df5e8, Func Offset: 0xc8
	// Line 1412, Address: 0x1df5ec, Func Offset: 0xcc
	// Line 1415, Address: 0x1df5fc, Func Offset: 0xdc
	// Line 1416, Address: 0x1df604, Func Offset: 0xe4
	// Line 1417, Address: 0x1df610, Func Offset: 0xf0
	// Line 1418, Address: 0x1df630, Func Offset: 0x110
	// Line 1419, Address: 0x1df638, Func Offset: 0x118
	// Line 1420, Address: 0x1df644, Func Offset: 0x124
	// Line 1422, Address: 0x1df65c, Func Offset: 0x13c
	// Line 1424, Address: 0x1df664, Func Offset: 0x144
	// Line 1425, Address: 0x1df670, Func Offset: 0x150
	// Line 1426, Address: 0x1df674, Func Offset: 0x154
	// Line 1424, Address: 0x1df678, Func Offset: 0x158
	// Line 1427, Address: 0x1df680, Func Offset: 0x160
	// Line 1424, Address: 0x1df684, Func Offset: 0x164
	// Line 1425, Address: 0x1df698, Func Offset: 0x178
	// Line 1426, Address: 0x1df6b8, Func Offset: 0x198
	// Line 1427, Address: 0x1df6d4, Func Offset: 0x1b4
	// Line 1430, Address: 0x1df6dc, Func Offset: 0x1bc
	// Line 1431, Address: 0x1df6f0, Func Offset: 0x1d0
	// Line 1432, Address: 0x1df6f8, Func Offset: 0x1d8
	// Line 1435, Address: 0x1df708, Func Offset: 0x1e8
	// Line 1436, Address: 0x1df724, Func Offset: 0x204
	// Line 1435, Address: 0x1df72c, Func Offset: 0x20c
	// Line 1436, Address: 0x1df730, Func Offset: 0x210
	// Line 1437, Address: 0x1df740, Func Offset: 0x220
	// Line 1438, Address: 0x1df750, Func Offset: 0x230
	// Line 1439, Address: 0x1df760, Func Offset: 0x240
	// Line 1440, Address: 0x1df770, Func Offset: 0x250
	// Line 1441, Address: 0x1df780, Func Offset: 0x260
	// Line 1442, Address: 0x1df784, Func Offset: 0x264
	// Line 1443, Address: 0x1df788, Func Offset: 0x268
	// Line 1444, Address: 0x1df790, Func Offset: 0x270
	// Line 1445, Address: 0x1df798, Func Offset: 0x278
	// Line 1446, Address: 0x1df7ac, Func Offset: 0x28c
	// Line 1449, Address: 0x1df7bc, Func Offset: 0x29c
	// Line 1450, Address: 0x1df7c0, Func Offset: 0x2a0
	// Line 1451, Address: 0x1df7c4, Func Offset: 0x2a4
	// Line 1452, Address: 0x1df7c8, Func Offset: 0x2a8
	// Line 1453, Address: 0x1df7dc, Func Offset: 0x2bc
	// Line 1454, Address: 0x1df7e8, Func Offset: 0x2c8
	// Line 1456, Address: 0x1df808, Func Offset: 0x2e8
	// Line 1457, Address: 0x1df814, Func Offset: 0x2f4
	// Line 1460, Address: 0x1df828, Func Offset: 0x308
	// Line 1461, Address: 0x1df844, Func Offset: 0x324
	// Line 1464, Address: 0x1df854, Func Offset: 0x334
	// Line 1466, Address: 0x1df864, Func Offset: 0x344
	// Line 1468, Address: 0x1df87c, Func Offset: 0x35c
	// Line 1469, Address: 0x1df890, Func Offset: 0x370
	// Line 1470, Address: 0x1df898, Func Offset: 0x378
	// Line 1471, Address: 0x1df8a8, Func Offset: 0x388
	// Line 1474, Address: 0x1df8b4, Func Offset: 0x394
	// Line 1475, Address: 0x1df8d0, Func Offset: 0x3b0
	// Line 1478, Address: 0x1df8f0, Func Offset: 0x3d0
	// Line 1479, Address: 0x1df904, Func Offset: 0x3e4
	// Line 1480, Address: 0x1df910, Func Offset: 0x3f0
	// Line 1482, Address: 0x1df944, Func Offset: 0x424
	// Line 1483, Address: 0x1df94c, Func Offset: 0x42c
	// Line 1484, Address: 0x1df95c, Func Offset: 0x43c
	// Line 1485, Address: 0x1df96c, Func Offset: 0x44c
	// Line 1488, Address: 0x1df978, Func Offset: 0x458
	// Line 1489, Address: 0x1df998, Func Offset: 0x478
	// Line 1488, Address: 0x1df99c, Func Offset: 0x47c
	// Line 1489, Address: 0x1df9a0, Func Offset: 0x480
	// Line 1491, Address: 0x1df9a8, Func Offset: 0x488
	// Line 1495, Address: 0x1df9b8, Func Offset: 0x498
	// Line 1496, Address: 0x1df9c4, Func Offset: 0x4a4
	// Line 1495, Address: 0x1df9cc, Func Offset: 0x4ac
	// Line 1496, Address: 0x1df9d0, Func Offset: 0x4b0
	// Line 1497, Address: 0x1df9d8, Func Offset: 0x4b8
	// Line 1501, Address: 0x1df9fc, Func Offset: 0x4dc
	// Line 1509, Address: 0x1dfa00, Func Offset: 0x4e0
	// Line 1501, Address: 0x1dfa04, Func Offset: 0x4e4
	// Line 1504, Address: 0x1dfa08, Func Offset: 0x4e8
	// Line 1505, Address: 0x1dfa0c, Func Offset: 0x4ec
	// Line 1506, Address: 0x1dfa10, Func Offset: 0x4f0
	// Line 1509, Address: 0x1dfa14, Func Offset: 0x4f4
	// Line 1510, Address: 0x1dfa24, Func Offset: 0x504
	// Line 1511, Address: 0x1dfa38, Func Offset: 0x518
	// Line 1513, Address: 0x1dfa48, Func Offset: 0x528
	// Func End, Address: 0x1dfa74, Func Offset: 0x554
}

// 100% matching!
void bhEne14_TailInit(BH_PWORK* epw)
{
    int i;
    O_WORK* p;

    p = &epw->mlwP->owP[11];

    for (i = 0; i < 11; i++, p++) 
    {
        *(float *)(epw->exp0 + 0x138 + i * 0xC) = p->mtx[12];
        *(float *)(epw->exp0 + 0x13C + i * 0xC) = p->mtx[13];
        *(float *)(epw->exp0 + 0x140 + i * 0xC) = p->mtx[14];
        *(int *)(epw->exp0 + 0x30 + i * 0xC) = 0;
        *(int *)(epw->exp0 + 0x34 + i * 0xC) = 0;
        *(int *)(epw->exp0 + 0x38 + i * 0xC) = 0;
        *(float *)(epw->exp0 + 4 + i * 4) = 2.5f;
    }
}

// 
// Start address: 0x1dfb20
void bhEne14_TailSwing(BH_PWORK* epw)
{
	NJS_CNK_OBJECT* objp;
	O_WORK* owp;
	int i;
	NJS_VECTOR v;
	static float g[11] = { 0.5f, 0.5f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
	static float n[11] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	// Line 1569, Address: 0x1dfb20, Func Offset: 0
	// Line 1604, Address: 0x1dfb3c, Func Offset: 0x1c
	// Line 1606, Address: 0x1dfb44, Func Offset: 0x24
	// Line 1607, Address: 0x1dfb4c, Func Offset: 0x2c
	// Line 1610, Address: 0x1dfb50, Func Offset: 0x30
	// Line 1607, Address: 0x1dfb58, Func Offset: 0x38
	// Line 1608, Address: 0x1dfb64, Func Offset: 0x44
	// Line 1609, Address: 0x1dfb74, Func Offset: 0x54
	// Line 1610, Address: 0x1dfb84, Func Offset: 0x64
	// Line 1612, Address: 0x1dfb8c, Func Offset: 0x6c
	// Line 1613, Address: 0x1dfba4, Func Offset: 0x84
	// Line 1612, Address: 0x1dfbac, Func Offset: 0x8c
	// Line 1615, Address: 0x1dfbb0, Func Offset: 0x90
	// Line 1623, Address: 0x1dfbb4, Func Offset: 0x94
	// Line 1615, Address: 0x1dfbb8, Func Offset: 0x98
	// Line 1623, Address: 0x1dfbbc, Func Offset: 0x9c
	// Line 1615, Address: 0x1dfbc0, Func Offset: 0xa0
	// Line 1616, Address: 0x1dfbd8, Func Offset: 0xb8
	// Line 1617, Address: 0x1dfbf8, Func Offset: 0xd8
	// Line 1622, Address: 0x1dfc0c, Func Offset: 0xec
	// Line 1617, Address: 0x1dfc10, Func Offset: 0xf0
	// Line 1620, Address: 0x1dfc1c, Func Offset: 0xfc
	// Line 1621, Address: 0x1dfc40, Func Offset: 0x120
	// Line 1622, Address: 0x1dfc64, Func Offset: 0x144
	// Line 1623, Address: 0x1dfc80, Func Offset: 0x160
	// Line 1622, Address: 0x1dfc84, Func Offset: 0x164
	// Line 1623, Address: 0x1dfc90, Func Offset: 0x170
	// Line 1626, Address: 0x1dfc98, Func Offset: 0x178
	// Line 1631, Address: 0x1dfca0, Func Offset: 0x180
	// Line 1626, Address: 0x1dfca8, Func Offset: 0x188
	// Line 1627, Address: 0x1dfcb4, Func Offset: 0x194
	// Line 1628, Address: 0x1dfcc8, Func Offset: 0x1a8
	// Line 1632, Address: 0x1dfcdc, Func Offset: 0x1bc
	// Line 1633, Address: 0x1dfce0, Func Offset: 0x1c0
	// Line 1634, Address: 0x1dfce4, Func Offset: 0x1c4
	// Line 1635, Address: 0x1dfce8, Func Offset: 0x1c8
	// Line 1632, Address: 0x1dfcec, Func Offset: 0x1cc
	// Line 1633, Address: 0x1dfd00, Func Offset: 0x1e0
	// Line 1634, Address: 0x1dfd18, Func Offset: 0x1f8
	// Line 1635, Address: 0x1dfd2c, Func Offset: 0x20c
	// Line 1636, Address: 0x1dfd34, Func Offset: 0x214
	// Line 1639, Address: 0x1dfd44, Func Offset: 0x224
	// Line 1636, Address: 0x1dfd48, Func Offset: 0x228
	// Line 1639, Address: 0x1dfd54, Func Offset: 0x234
	// Line 1636, Address: 0x1dfd58, Func Offset: 0x238
	// Line 1637, Address: 0x1dfd60, Func Offset: 0x240
	// Line 1638, Address: 0x1dfd7c, Func Offset: 0x25c
	// Line 1639, Address: 0x1dfd98, Func Offset: 0x278
	// Line 1642, Address: 0x1dfda0, Func Offset: 0x280
	// Line 1643, Address: 0x1dfda8, Func Offset: 0x288
	// Line 1646, Address: 0x1dfdac, Func Offset: 0x28c
	// Line 1643, Address: 0x1dfdb4, Func Offset: 0x294
	// Line 1644, Address: 0x1dfdc8, Func Offset: 0x2a8
	// Line 1645, Address: 0x1dfde0, Func Offset: 0x2c0
	// Line 1646, Address: 0x1dfdf8, Func Offset: 0x2d8
	// Line 1649, Address: 0x1dfe00, Func Offset: 0x2e0
	// Line 1651, Address: 0x1dfe04, Func Offset: 0x2e4
	// Line 1649, Address: 0x1dfe08, Func Offset: 0x2e8
	// Line 1650, Address: 0x1dfe0c, Func Offset: 0x2ec
	// Line 1649, Address: 0x1dfe10, Func Offset: 0x2f0
	// Line 1651, Address: 0x1dfe14, Func Offset: 0x2f4
	// Line 1652, Address: 0x1dfe20, Func Offset: 0x300
	// Line 1653, Address: 0x1dfe24, Func Offset: 0x304
	// Line 1654, Address: 0x1dfe2c, Func Offset: 0x30c
	// Line 1655, Address: 0x1dfe34, Func Offset: 0x314
	// Line 1656, Address: 0x1dfe5c, Func Offset: 0x33c
	// Line 1659, Address: 0x1dfe64, Func Offset: 0x344
	// Line 1660, Address: 0x1dfe7c, Func Offset: 0x35c
	// Line 1661, Address: 0x1dfe80, Func Offset: 0x360
	// Line 1664, Address: 0x1dfe98, Func Offset: 0x378
	// Line 1665, Address: 0x1dfeb0, Func Offset: 0x390
	// Line 1666, Address: 0x1dfec8, Func Offset: 0x3a8
	// Line 1667, Address: 0x1dfee0, Func Offset: 0x3c0
	// Line 1669, Address: 0x1dfef8, Func Offset: 0x3d8
	// Line 1670, Address: 0x1dff04, Func Offset: 0x3e4
	// Line 1671, Address: 0x1dff10, Func Offset: 0x3f0
	// Line 1692, Address: 0x1dff20, Func Offset: 0x400
	// Func End, Address: 0x1dff40, Func Offset: 0x420
}

// 100% matching!
int bhEne14_HitMark(BH_PWORK* epw)
{
	int range;
	int i;
	NJS_POINT3 ofp;
	BLOOD_TBL* blp;

    range = 0;
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
    blp = &BloodTbl[epw->djnt_no];
    
    if ((epw->comb_flg & 0x10))
    {
        range = 0;
    }
    
    if ((epw->comb_flg & 0x20))
    {
        range = 1;
    }
    
    if ((epw->comb_flg & 0x40))
    {
        range = 2;
    }
    
    if (DmgReact[epw->wpnr_no].type[range] >= 0)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = (epw->comb_flg & 4) ? blp->ofp.z : -blp->ofp.z;


        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        

        switch (epw->wpnr_no)
        {
        case 10:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, (NJS_POINT3*)&epw->dpx, 1);
            break;
        default:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
            break;
        }
    }
   
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0))
    {
        for (i = 0; i < 4; i++)        
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;

            ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, (0.5f + (0.5f * njRandom())), (int)(40.0f * njRandom()) + 20);
        }         
    }
    
    if (DmgReact[epw->wpnr_no].exef & 2)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;

        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if (epw->type == 1)
    {
        epw->hp -= epw->total_dam;
    }
    
    if (sys->gm_mode != 3) 
    {
        if (epw->hp < 0)
        {
            epw->hp = 0;
        }
        
        if (epw->wpnr_no == 18)
        {
            epw->flg |= 2;
            plp->mnwP = plp->mnwPb;
        }
    } 
    else if (epw->hp < 0)
    {
        epw->flg |= 2;
    }
    
    return epw->total_dam;
}

// 
// Start address: 0x1e0500
void bhEne14_Acid(BH_PWORK* epw, int se)
{
	float t;
	float dt;
	O_WORK* owk;
	int rapid;
	int i;
	int eno;
	// Line 1802, Address: 0x1e0500, Func Offset: 0
	// Line 1822, Address: 0x1e0504, Func Offset: 0x4
	// Line 1802, Address: 0x1e0508, Func Offset: 0x8
	// Line 1810, Address: 0x1e0540, Func Offset: 0x40
	// Line 1811, Address: 0x1e054c, Func Offset: 0x4c
	// Line 1812, Address: 0x1e0550, Func Offset: 0x50
	// Line 1813, Address: 0x1e0554, Func Offset: 0x54
	// Line 1822, Address: 0x1e0558, Func Offset: 0x58
	// Line 1827, Address: 0x1e0560, Func Offset: 0x60
	// Line 1822, Address: 0x1e0570, Func Offset: 0x70
	// Line 1827, Address: 0x1e0574, Func Offset: 0x74
	// Line 1828, Address: 0x1e05b0, Func Offset: 0xb0
	// Line 1829, Address: 0x1e05b8, Func Offset: 0xb8
	// Line 1831, Address: 0x1e05d8, Func Offset: 0xd8
	// Line 1836, Address: 0x1e05e0, Func Offset: 0xe0
	// Line 1837, Address: 0x1e05e4, Func Offset: 0xe4
	// Line 1836, Address: 0x1e05e8, Func Offset: 0xe8
	// Line 1831, Address: 0x1e05f0, Func Offset: 0xf0
	// Line 1832, Address: 0x1e05f4, Func Offset: 0xf4
	// Line 1836, Address: 0x1e05f8, Func Offset: 0xf8
	// Line 1831, Address: 0x1e0600, Func Offset: 0x100
	// Line 1836, Address: 0x1e0604, Func Offset: 0x104
	// Line 1837, Address: 0x1e0608, Func Offset: 0x108
	// Line 1832, Address: 0x1e0610, Func Offset: 0x110
	// Line 1831, Address: 0x1e0614, Func Offset: 0x114
	// Line 1837, Address: 0x1e0618, Func Offset: 0x118
	// Line 1838, Address: 0x1e0624, Func Offset: 0x124
	// Line 1839, Address: 0x1e0638, Func Offset: 0x138
	// Line 1840, Address: 0x1e064c, Func Offset: 0x14c
	// Line 1832, Address: 0x1e0654, Func Offset: 0x154
	// Line 1840, Address: 0x1e0658, Func Offset: 0x158
	// Line 1842, Address: 0x1e0664, Func Offset: 0x164
	// Line 1832, Address: 0x1e0668, Func Offset: 0x168
	// Line 1842, Address: 0x1e0670, Func Offset: 0x170
	// Line 1843, Address: 0x1e0678, Func Offset: 0x178
	// Line 1845, Address: 0x1e068c, Func Offset: 0x18c
	// Line 1846, Address: 0x1e0694, Func Offset: 0x194
	// Line 1850, Address: 0x1e06ac, Func Offset: 0x1ac
	// Line 1851, Address: 0x1e06b8, Func Offset: 0x1b8
	// Line 1852, Address: 0x1e06d4, Func Offset: 0x1d4
	// Line 1851, Address: 0x1e06dc, Func Offset: 0x1dc
	// Line 1855, Address: 0x1e06e0, Func Offset: 0x1e0
	// Line 1851, Address: 0x1e06e4, Func Offset: 0x1e4
	// Line 1852, Address: 0x1e06f4, Func Offset: 0x1f4
	// Line 1855, Address: 0x1e06fc, Func Offset: 0x1fc
	// Line 1851, Address: 0x1e0704, Func Offset: 0x204
	// Line 1852, Address: 0x1e0714, Func Offset: 0x214
	// Line 1853, Address: 0x1e0718, Func Offset: 0x218
	// Line 1854, Address: 0x1e072c, Func Offset: 0x22c
	// Line 1855, Address: 0x1e0740, Func Offset: 0x240
	// Line 1856, Address: 0x1e0758, Func Offset: 0x258
	// Line 1857, Address: 0x1e0764, Func Offset: 0x264
	// Line 1860, Address: 0x1e0788, Func Offset: 0x288
	// Line 1861, Address: 0x1e078c, Func Offset: 0x28c
	// Line 1862, Address: 0x1e0790, Func Offset: 0x290
	// Line 1857, Address: 0x1e0794, Func Offset: 0x294
	// Line 1858, Address: 0x1e079c, Func Offset: 0x29c
	// Line 1865, Address: 0x1e07a0, Func Offset: 0x2a0
	// Line 1858, Address: 0x1e07a4, Func Offset: 0x2a4
	// Line 1859, Address: 0x1e07a8, Func Offset: 0x2a8
	// Line 1860, Address: 0x1e07ac, Func Offset: 0x2ac
	// Line 1861, Address: 0x1e07b0, Func Offset: 0x2b0
	// Line 1865, Address: 0x1e07b4, Func Offset: 0x2b4
	// Line 1866, Address: 0x1e07bc, Func Offset: 0x2bc
	// Line 1867, Address: 0x1e0810, Func Offset: 0x310
	// Line 1868, Address: 0x1e085c, Func Offset: 0x35c
	// Line 1870, Address: 0x1e086c, Func Offset: 0x36c
	// Line 1871, Address: 0x1e087c, Func Offset: 0x37c
	// Line 1870, Address: 0x1e0880, Func Offset: 0x380
	// Line 1871, Address: 0x1e088c, Func Offset: 0x38c
	// Line 1870, Address: 0x1e0890, Func Offset: 0x390
	// Line 1871, Address: 0x1e0894, Func Offset: 0x394
	// Line 1872, Address: 0x1e08a0, Func Offset: 0x3a0
	// Line 1873, Address: 0x1e08b4, Func Offset: 0x3b4
	// Line 1876, Address: 0x1e08c8, Func Offset: 0x3c8
	// Line 1877, Address: 0x1e08cc, Func Offset: 0x3cc
	// Line 1878, Address: 0x1e08d0, Func Offset: 0x3d0
	// Line 1879, Address: 0x1e08e0, Func Offset: 0x3e0
	// Func End, Address: 0x1e0920, Func Offset: 0x420
}

// 
// Start address: 0x1e0920
void bhEne14_SetMotion(BH_PWORK* epw)
{
	// already reversed DWARF order
	NJS_MKEY_A_MOD* mkaP;
	NJS_CNK_OBJECT* objP;
	int i;
	int obj_list[4]   = {  7,  8,  9, 10 };
	int obj_list_f[4] = {  9, 10,  7,  8 };
	// Line 1893, Address: 0x1e0920, Func Offset: 0
	// Line 1889, Address: 0x1e092c, Func Offset: 0xc
	// Line 1893, Address: 0x1e0930, Func Offset: 0x10
	// Line 1899, Address: 0x1e0934, Func Offset: 0x14
	// Line 1893, Address: 0x1e0940, Func Offset: 0x20
	// Line 1899, Address: 0x1e0944, Func Offset: 0x24
	// Line 1908, Address: 0x1e094c, Func Offset: 0x2c
	// Line 1909, Address: 0x1e095c, Func Offset: 0x3c
	// Line 1911, Address: 0x1e0960, Func Offset: 0x40
	// Line 1910, Address: 0x1e0964, Func Offset: 0x44
	// Line 1912, Address: 0x1e0968, Func Offset: 0x48
	// Line 1913, Address: 0x1e096c, Func Offset: 0x4c
	// Line 1912, Address: 0x1e0970, Func Offset: 0x50
	// Line 1911, Address: 0x1e0978, Func Offset: 0x58
	// Line 1910, Address: 0x1e0980, Func Offset: 0x60
	// Line 1911, Address: 0x1e0984, Func Offset: 0x64
	// Line 1918, Address: 0x1e0990, Func Offset: 0x70
	// Line 1911, Address: 0x1e0994, Func Offset: 0x74
	// Line 1912, Address: 0x1e0998, Func Offset: 0x78
	// Line 1913, Address: 0x1e099c, Func Offset: 0x7c
	// Line 1912, Address: 0x1e09a0, Func Offset: 0x80
	// Line 1917, Address: 0x1e09b4, Func Offset: 0x94
	// Line 1913, Address: 0x1e09bc, Func Offset: 0x9c
	// Line 1912, Address: 0x1e09c8, Func Offset: 0xa8
	// Line 1913, Address: 0x1e09d0, Func Offset: 0xb0
	// Line 1915, Address: 0x1e09d4, Func Offset: 0xb4
	// Line 1918, Address: 0x1e09d8, Func Offset: 0xb8
	// Line 1915, Address: 0x1e09dc, Func Offset: 0xbc
	// Line 1916, Address: 0x1e09e0, Func Offset: 0xc0
	// Line 1917, Address: 0x1e09ec, Func Offset: 0xcc
	// Line 1918, Address: 0x1e09f4, Func Offset: 0xd4
	// Line 1919, Address: 0x1e09fc, Func Offset: 0xdc
	// Line 1920, Address: 0x1e0a04, Func Offset: 0xe4
	// Line 1922, Address: 0x1e0a08, Func Offset: 0xe8
	// Line 1921, Address: 0x1e0a0c, Func Offset: 0xec
	// Line 1924, Address: 0x1e0a10, Func Offset: 0xf0
	// Line 1923, Address: 0x1e0a14, Func Offset: 0xf4
	// Line 1929, Address: 0x1e0a1c, Func Offset: 0xfc
	// Line 1922, Address: 0x1e0a20, Func Offset: 0x100
	// Line 1921, Address: 0x1e0a28, Func Offset: 0x108
	// Line 1922, Address: 0x1e0a2c, Func Offset: 0x10c
	// Line 1923, Address: 0x1e0a38, Func Offset: 0x118
	// Line 1922, Address: 0x1e0a3c, Func Offset: 0x11c
	// Line 1924, Address: 0x1e0a40, Func Offset: 0x120
	// Line 1923, Address: 0x1e0a44, Func Offset: 0x124
	// Line 1928, Address: 0x1e0a58, Func Offset: 0x138
	// Line 1924, Address: 0x1e0a5c, Func Offset: 0x13c
	// Line 1923, Address: 0x1e0a68, Func Offset: 0x148
	// Line 1924, Address: 0x1e0a70, Func Offset: 0x150
	// Line 1926, Address: 0x1e0a74, Func Offset: 0x154
	// Line 1929, Address: 0x1e0a78, Func Offset: 0x158
	// Line 1926, Address: 0x1e0a7c, Func Offset: 0x15c
	// Line 1927, Address: 0x1e0a80, Func Offset: 0x160
	// Line 1928, Address: 0x1e0a88, Func Offset: 0x168
	// Line 1929, Address: 0x1e0a8c, Func Offset: 0x16c
	// Line 1930, Address: 0x1e0a94, Func Offset: 0x174
	// Line 1931, Address: 0x1e0a98, Func Offset: 0x178
	// Func End, Address: 0x1e0aa4, Func Offset: 0x184
}

// 100% matching!
void bhEne14_CheckWall(BH_PWORK* epw)
{
    bhEne03_Collision(epw);
    epw->py -= 8.0f;
    bhEne03_Collision(epw);
    epw->py += 8.0f;
    epw->py += 8.0f;
    bhEne03_Collision(epw);
    epw->py -= 8.0f;
}

// 100% matching!
void bhEne14_PlayerControl(BH_PWORK* epw)
{
    if ((plp->mode0 == 4) && !(epw->flg & 2))
    {
        switch (plp->mode2) 
        {
        case 0:
		case 1:
            switch (plp->mode3)
            {
            case 0:
                plp->flg &= ~0x40000;
                plp->flg |= 0x10000;
                plp->flg2 |= 1;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = 71;
                } 
                else
                {
                    plp->mtn_no = 72;
                }
    
                plp->frm_no = 0;
                plp->hokan_count = 3;
                plp->hokan_rate = 32768;
                plp->mtn_add = 65536;
                plp->mode3++;
                bhEne_CallPlayerVoice(2);
                StartVibrationEx(1, 9);
                break;
                
            case 1:
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = epw->mnwP;
                    
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = 31;
                    } 
                    else
                    {
                        plp->mtn_no = 32;
                    }
                    plp->frm_no = 0;
                    plp->hokan_count = 3;
                    plp->hokan_rate = 32768;
                    plp->mtn_add = 65536;
                    plp->mode3++;
                }
                break;
                
            case 2:
                if (plp->frm_no == 0)
                {
                    plp->mnwP = plp->mnwPb;
                    plp->flg &= ~0x10004;
                    plp->flg2 &= ~1;
                    plp->flg |= 8;
                    plp->at_flg = 0;
                    plp->stflg &= ~0x10000;
                    *(int*)&plp->mode0 = 1;    
                } 
            }
        } 
    } 
}

// 100% matching!
void bhEne14_CallSE(BH_PWORK* epw) 
{
    if (epw->mnwP == epw->mnwPb)
    {
        switch (epw->mtn_no)
        {
        case 1:
            if (epw->frm_no == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16851712);
            }
            break;
            
        case 2:
        case 3:
            if (epw->frm_no == 458752)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            break;
            
        case 4:
            if (epw->frm_no == 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8962);
            }
            break;
            
        case 22:
            if (epw->frm_no == 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16786193);
            }
            break;
        }
    }
}
