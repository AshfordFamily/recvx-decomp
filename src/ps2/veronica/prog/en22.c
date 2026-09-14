#include "../../../ps2/veronica/prog/en22.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Albinoid Adult

const char en22_flipTree[43] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    19, 20, 21, 22, 23, 24, 25,
    12, 13, 14, 15, 16, 17, 18,
    34, 35, 36, 37, 38, 39, 40, 41,
    26, 27, 28, 29, 30, 31, 32, 33,
    -1
};

/*char en22_tree[16][4];
_anon46 en22_mtn_tbl[12];*/

WPNDAMAGE_WORK En22_WpnDamageTbl[22] = {
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0},
	{ 0, 4, 3, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 7, 3, 3},
	{ 0, 0, 5, 3, 5},
	{ 0, 4, 7, 3, 3},
	{ 0, 4, 3, 3, 3},
	{ 0, 0, 1, 3, 3},
	{12, 0, 1, 3, 3},
	{ 4, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3},
	{ 0, 0, 1, 3, 3}
};

static COMBWEP_WORK CombWepTbl[21] = {
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 90, {10, 8, 5}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    {160, {10, 8, 5}, 0, 0},
    { 40, {10, 8, 5}, 0, 0},
    { 80, {10, 8, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {160, {10, 8, 5}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0},
    {  0, { 0, 0, 0}, 0, 0}
};

static COMBJOINT_WORK CombJointTbl[42] = {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};

CPCL Ene22CapColTab[27] = {
    {  2,  2, 20},
    {  0,  0, 20},
    {  2,  2, 23},
    {-25,  0, 20},
    {  2,  2, 23},
    { 25,  0, 20},
    {  3,  4, 30},
    {  4,  5, 22},
    {  5,  6, 15},
    {  6,  7, 18},
    {  7,  8, 12},
    {  8,  9, 11},
    {  9, 10, 11},
    { 10, 11, 10},
    { 19, 20, 11},
    { 20, 21,  9},
    { 12, 13, 11},
    { 13, 14,  9},
    { 34, 34, 20},
    {  8,  0,  0},
    { 35, 36,  8},
    { 36, 37,  8},
    { 26, 26, 20},
    { -8,  0,  0},
    { 27, 28,  8},
    { 28, 29,  8},
    {  0,  0,  0}
};

BT_WORK en22prt_blood_tbl[42] = {
    { 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    { 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    { 2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 3, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 4, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 5, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 6, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 7, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 8, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    { 9, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {10, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {11, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {12, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {13, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {14, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {15, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {17, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {18, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {19, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {20, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {21, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {22, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {23, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {24, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {25, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {26, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {27, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {28, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {29, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {30, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {31, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {32, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {33, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {34, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {35, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {36, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {37, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {38, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {39, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {40, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f},
    {41, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f}
};

char En22SdwTab[7] = {
    2, 7, 13, 20, 28, 36, -1
};

/*int en22_hp_tbl[16];
_anon44 ene22_wsp_tbl[57];
_anon41 en22_weff_tbl[14];
_anon37 ply_mtn42b_pos[20];
_anon37 ply_mtn43b_pos[20];
_anon37 ply_mtn44b_pos[50];
_anon37 ply_mtn45b_pos[50];*/

void (*bhEne22_Mode0[6])(BH_PWORK*) = {
    bhEne22_Init,
    bhEne22_Move,
    bhEne22_Nage,
    bhEne22_Damage,
    bhEne22_Die,
    bhEne_Event
};

void (*bhEne22_InitType[1])(BH_PWORK*) = {
    bhEne22_InitType00
};

void (*bhEne22_MoveType[1])(BH_PWORK*) = {
    bhEne22_MVType00
};

void (*bhEne22_BrainMode2[6])(BH_PWORK*) = {
    bhEne22_Brain00,
    bhEne22_Brain01,
    bhEne22_Brain02,
    bhEne22_DmmyBrain,
    bhEne22_Brain04,
    bhEne22_DmmyBrain
};

void (*bhEne22_MoveMode2[7])(BH_PWORK*) = {
    bhEne22_MV00,
    bhEne22_MV01,
    bhEne22_MV02,
    bhEne22_MV03,
    bhEne22_MV04,
    bhEne22_MV05,
    bhEne22_MV06
};

/*void(*bhEne22_NageType)(BH_PWORK*)[1];
void(*bhEne22_NageMode2)(BH_PWORK*)[1];*/

void (*bhEne22_DamageType[1])(BH_PWORK*) = {
    bhEne22_DGType00
};

void (*bhEne22_DamageMode2[3])(BH_PWORK*) = {
    bhEne22_DG00,
    bhEne22_DG01,
    bhEne22_DG02
};

void (*bhEne22_DieType[1])(BH_PWORK*) = {
    bhEne22_DDType00
};

void (*bhEne22_DieMode2[2])(BH_PWORK*) = {
    bhEne22_DD00,
    bhEne22_DD01
};

/*float en22_mogmog[20];*/

// 100% matching!
void bhEne22_DmmyBrain(BH_PWORK* epw)
{
	return;
}

// 100% matching!
void bhEne22(BH_PWORK* epw)
{
    O_WORK* owk;
    int i;

    bhEne22_MainLoop(epw);

    if ((plp->mode0 == 4) || (plp->mode0 == 6))
    {
        if (plp->mode2 == 0)
        {
            bhEne22_PlyDG00(plp, epw);
        }
        else
        {
            bhEne22_PlyDG01(plp, epw);
        }
    }

    if (epw->flg & 0x4)
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        epw->flg &= ~0x4;
    }

    bhEne22_CollCheck(epw);
    bhCalcModel(epw);

    owk = epw->mlwP->owP + 4;
    epw->aox = owk->mtx[12] - epw->px;
    epw->aoz = owk->mtx[14] - epw->pz;

    owk = epw->mlwP->owP + 3;
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = epw->py + 2.0f;
    epw->watr.c1.z = owk->mtx[14];

    owk = epw->mlwP->owP + 9;
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = epw->py + 2.0f;
    epw->watr.c2.z = owk->mtx[14];
    epw->watr.r = 5.5f;

    if (EXP0_I(0xC) > 0)
    {
        EXP0_I(0xC)--;
    }

    if (EXP0_I(0x10) > 0)
    {
        EXP0_I(0x10)--;
    }

    if (EXP0_I(0x14) > 0)
    {
        EXP0_I(0x14)--;
    }

    if (EXP0_I(0x1C) > 0)
    {
        EXP0_I(0x1C)--;
    }

    bhEne22_CtrLight(epw);
}

// 100% matching!
void bhEne22_MainLoop(BH_PWORK* epw)
{
    bhEne22_DmgChk(epw);

    bhEne22_Mode0[epw->mode0](epw);

    bhEne22_SetMtn(epw);
}

// 100% matching!
int bhEne22_DmgChk(BH_PWORK* epw)
{
    int houkou;

    if ((epw->flg & 0x4) && ((epw->flg & 0x2) == 0) && ((EXP0_I(0x8) & 0x20000) == 0))
    {
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        if (epw->total_dam == 0)
        {
            return 1;
        }

        bhEne22_DamageAdd(epw);
        if (epw->mode0 != 1)
        {
            return 1;
        }

        houkou = bhDGCdirCheck3((NJS_VECTOR*)&epw->dvx, epw->ay);
        EXP0_I(0x8) &= ~0x30;
        if (houkou == 0)
        {
            EXP0_I(0x8) |= 0x0;
        }
        else if (houkou == 1)
        {
            EXP0_I(0x8) |= 0x10;
        }
        else if (houkou == 2)
        {
            EXP0_I(0x8) |= 0x20;
        }
        else if (houkou == 3)
        {
            EXP0_I(0x8) |= 0x30;
        }

        bhEne22_ChgDmgMode(epw);

        return 1;
    }

    return 0;
}

// 100% matching!
void bhEne22_ChgDmgMode(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl = En22_WpnDamageTbl;
    int act;

    wp_tbl += epw->wpnr_no;
    act = wp_tbl->nm_act;

    if (epw->hp < 0)
    {
        epw->comb_flg |= 0x1;
        epw->comb_timeout = 0;
        epw->comb_pnt = 0;
    }

    if (epw->comb_flg & 0x1)
    {
        act = wp_tbl->cb_act;
    }

    if (act < 4U)
    {
        if (EXP0_I(0x8) & 0x1000)
        {
            if (((*(O_WRK**)(epw->exp0 + 0x4C))->flg != 0)
                && ((*(O_WRK**)(epw->exp0 + 0x4C))->id == 353)
                && ((BH_PWORK*)(*(O_WRK**)(epw->exp0 + 0x4C))->lkwkp == epw))
            {
                (*(O_WRK**)(epw->exp0 + 0x4C))->mode0 = 4;
            }

            if (EXP0_I(0x8) & 0x80000)
            {
                rom->lgtp[2].flg &= ~0x3;
                EXP0_I(0x8) &= ~0x80000;
            }

            EXP0_I(0x8) &= ~0x1000;
        }

        if (epw->hp < 0)
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        else
        {
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode3 = 0;
            if (EXP0_I(0x8) & 0x100)
            {
                epw->mode2 = 0;
            }
            else
            {
                epw->mode2 = 1;
            }
        }
    }
}

// 100% matching!
void bhEne22_DamageAdd(BH_PWORK* epw)
{
    WPNDAMAGE_WORK* wp_tbl = En22_WpnDamageTbl;
    int* d;
    int i;

    if (epw->hp >= 0)
    {
        epw->hp -= epw->total_dam;
        wp_tbl += epw->comb_wep;

        for (d = epw->dam + 2, i = 2; i < (int)epw->mlwP->obj_num; i++, d++)
        {
            if (*d <= 0) continue;

            epw->djnt_no = i;

            if (wp_tbl->flg & 0x4) continue;

            if ((epw->comb_flg & 0x1) || (epw->hp < 0))
            {
                bhEne_SetBlood(epw, wp_tbl->cb_blood, en22prt_blood_tbl);
            }
            else
            {
                bhEne_SetBlood(epw, wp_tbl->nm_blood, en22prt_blood_tbl);
            }
        }
    }

    if (((wp_tbl->flg & 0x1) || (wp_tbl->flg & 0x2)) && (EXP0_I(0x10) <= 0))
    {
        EXP0_I(0x10) = 10;

        if (wp_tbl->flg & 0x2)
        {
            bhEne_SetDFireEffect(epw, epw->djnt_no, en22prt_blood_tbl, 2);
        }
        else
        {
            bhEne_SetDFireEffect(epw, epw->djnt_no, en22prt_blood_tbl, 1);
        }
    }

    if ((wp_tbl->flg & 0x8) && (EXP0_I(0x10) <= 0))
    {
        EXP0_I(0x10) = 10;

        bhEne_SetSanEffect(epw, epw->djnt_no, en22prt_blood_tbl);
    }
}

// 100% matching!
void bhEne22_CollCheck(BH_PWORK* epw)
{
    if ((epw->flg & 0x2) == 0)
    {
        if ((epw->flg & 0x8) && (EXP0_I(0x8) & 0x40))
        {
            bhCheckPlayer(epw);
        }

        bhEne22_CollCheckWall(epw);
    }
}

// 100% matching!
void bhEne22_CollCheckWall(BH_PWORK* epw)
{
    NJS_POINT3 ps, pd;
    O_WORK* owk;

    if ((sys->st_flg & 0x40) && ((epw->stflg & 0x100000) == 0) && (bhCheckWater((NJS_POINT3*)&epw->px) != NULL))
    {
        epw->stflg |= 0x100000;
    }

    EXP0_ATR(17) = bhCheckWallType((NJS_POINT3*)&epw->px, epw->flg, epw->ar, epw->ah);

    if (((EXP0_I(0x8) & 0xF) == 0x1) && (epw->flg & 0x10))
    {
        ps.x = epw->px + epw->aox;
        ps.z = epw->pz + epw->aoz;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, epw->ar, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 28;
        ps.x = owk->mtx[12];
        ps.z = owk->mtx[14];
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 29;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 36;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 37;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 13;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 14;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 20;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 21;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }
    }
    else if ((EXP0_I(0x8) & 0xF) == 2)
    {
        bhCheckDansa(epw);

        owk = epw->mlwP->owP + 21;
        ps.x = owk->mtx[12];
        ps.z = owk->mtx[14];
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }

        owk = epw->mlwP->owP + 14;
        ps.x = owk->mtx[12] + pd.x;
        ps.z = owk->mtx[14] + pd.z;
        ps.y = epw->py;
        if (bhEne_CollisionCheckWall(epw, &ps, &pd, 2.0f, epw->ah))
        {
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }
    }
}

// 100% matching!
void bhEne22_Init(BH_PWORK* epw)
{
    int i;
    unsigned char* addr;
    int size;

    epw->ar = 7.0f;
    epw->ah = 6.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 7.0f;
    epw->cah = 6.0f;
    epw->stflg = 0;

    if (sys->gm_mode != 2)
    {
        epw->hp = 250;
    }
    else
    {
        epw->hp = 160;
    }

    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }

    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = (unsigned char*)en22_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0xB0, 8);
    }
    else
    {
        if (EXP0_I(0x8) & 0x80000)
        {
            rom->lgtp[2].flg &= ~0x3;
            EXP0_I(0x8) &= ~0x80000;
        }

        addr = epw->exp0;
        size = 0xB0;
        while (size-- != 0)
        {
            *addr = 0;
            addr++;
        }
    }

    EXP0_I(0x8) |= 0x41;
    epw->flg |= 0x78;
    epw->flg &= ~0x2;

    if ((epw->flg & 0x800) == 0)
    {
        addr = (unsigned char*)epw;
        bhSetShadow(En22SdwTab, addr, 4, 4.0f, 4.0f, 8.0f);
        epw->flg |= 0x800;
    }

    epw->clp_jno[0] = -1;
    epw->mdflg |= 0x20;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->lok_jno = 2;
    epw->cpcl = Ene22CapColTab;

    bhEne22_InitType[epw->type](epw);
}

// 100% matching!
void bhEne22_InitType00(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_Move(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos, epos;

    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];

    epos.x = epw->px + epw->aox;
    epos.z = epw->pz + epw->aoz;
    epos.y = epw->py;

    EXP0_F(0x20) = njDistanceP2P(&pos, &epos);

    bhEne22_MoveType[epw->type](epw);

    if ((EXP0_I(0x14) == 0) && (epw->mode2 != 4))
    {
        bhEne22_SetElectricShockEffect(epw, 3);

        EXP0_I(0x14) = rand() % 30 + 60;
        EXP0_I(0x1C) = 15;

        pos.x = 0.0f;
        pos.y = 5.0f;
        pos.z = 0.0f;

        bhEne22_SetLight(epw, 4, &pos, 0);
        bhEne22_SePlay(epw, (NJS_POINT3*)&epw->px, 0x1012302);
    }

    bhEne22_PlyerHitCheck(plp, epw);
}

// 100% matching!
void bhEne22_Nage(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_Damage(BH_PWORK* epw)
{
    bhEne22_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne22_Die(BH_PWORK* epw)
{
    bhEne22_DieType[epw->type](epw);
}

// 100% matching!
void bhEne22_PlyerHitCheck(BH_PWORK* pl, BH_PWORK* epw)
{
    NJS_POINT3 ps;

    if ((EXP0_I(0x1C) > 0)
        && (EXP0_F(0x20) <= 20.0f)
        && (pl->flr_no == epw->flr_no)
        && ((pl->flg & 0x2) == 0)
        && ((pl->flg & 0x4) == 0)
        && ((pl->stflg & 0x80000000) == 0))
    {
        EXP0_I(0x8) |= 0x40000;

        pl->mode0 = 4;
        pl->mode1 = 0;
        pl->mode2 = 0;
        pl->mode3 = 0;
        pl->flg |= 0x4;
        pl->hp -= 30;

        bhEne22_SetElectricShockEffect2(epw);
        bhEne22_SePlay(epw, (NJS_POINT3*)&pl->px, 0x1012302);

        ps.x = plp->px;
        ps.y = 10.0f;
        ps.z = plp->pz;

        bhEne22_SetLight(epw, -1, &ps, 0);

        EXP0_I(0x1C) = 0;
    }

    if ((EXP0_F(0x20) <= 10.0f)
        && (ikou3(epw, (NJS_POINT3*)&plp->px, NJM_DEG_ANG(30.0f)) == 0)
        && (pl->flr_no == epw->flr_no)
        && ((pl->flg & 0x2) == 0)
        && ((pl->flg & 0x4) == 0)
        && ((pl->stflg & 0x80000000) == 0))
    {
        EXP0_I(0x8) |= 0x40000;

        if ((epw->mtn_no == 5) || (epw->mtn_no - 6 < 2))
        {
            pl->mode0 = 4;
            pl->mode1 = 0;
            pl->mode2 = 1;
            pl->mode3 = 0;
        }
        else
        {
            pl->mode0 = 4;
            pl->mode1 = 0;
            pl->mode2 = 0;
            pl->mode3 = 0;
        }

        pl->flg |= 0x4;
        pl->hp -= 30;

        bhEne22_SetElectricShockEffect2(epw);
        bhEne22_SetElectricShockEffect(epw, 1);
        bhEne22_SePlay(epw, (NJS_POINT3*)&pl->px, 0x1012302);

        ps.x = plp->px;
        ps.y = 10.0f;
        ps.z = plp->pz;

        bhEne22_SetLight(epw, -1, &ps, 0);
    }
}

// 100% matching!
void bhEne22_EneSearch(BH_PWORK* epw)
{
    EXP0_UC(0x0) |= 0x80;

    if ((EXP0_UC(0x0) & 0x1F) < 0x4)
    {
        if (bhSearchPlayer(epw, 18204) != -1)
        {
            EXP0_UC(0x0) |= 0x20;
        }

        if ((EXP0_UC(0x0) & 0x1F) == 3)
        {
            if (EXP0_UC(0x0) & 0x20)
            {
                EXP0_UC(0x0) |= 0x40;
            }
            else
            {
                EXP0_UC(0x0) &= ~0x40;
            }

            EXP0_UC(0x0) &= ~0xA0;
        }
    }

    EXP0_UC(0x0)++;

    if ((EXP0_UC(0x0) & 0x1F) > 0xF)
    {
        EXP0_UC(0x0) &= ~0x1F;
    }
}

// 100% matching!
void bhEne22_Brain(BH_PWORK* epw)
{
    if ((EXP0_UC(0x0) & 0x40) == 0)
    {
        bhEne22_EneSearch(epw);
    }

    bhEne22_BrainMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_Brain00(BH_PWORK* epw)
{
    if (epw->mode3 == 0) return;

    if (plp->flr_no == 0)
    {
        if (EXP0_F(0x20) <= 40.0f)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        else if (((plp->stflg & 0x80000000) == 0) && (EXP0_F(0x20) > 40.0f))
        {
            epw->mode1 = 1;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }

        epw->ct0 = rand() % 60 + 120;
    }
    else
    {
        epw->ct0--;

        if (bhEne22_AreaCheck(epw->px, epw->pz, plp->px, plp->pz) || (epw->ct0 < 0) || (EXP0_F(0x20) < 42.0f))
        {
            bhEne22_SetTrgPos(epw);

            if (epw->ct0 < 0)
            {
                if (rand() % 2)
                {
                    epw->mode2 = 1;
                }
                else
                {
                    epw->mode2 = 2;
                }
            }
            else
            {
                epw->mode2 = 2;
            }
            epw->mode1 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne22_Brain01(BH_PWORK* epw)
{
    if (bhEne22_AreaCheck(EXP0_F(0x24), EXP0_F(0x2C), plp->px, plp->pz))
    {
        bhEne22_SetTrgPos(epw);
    }

    if (plp->flr_no == 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne22_Brain02(BH_PWORK* epw)
{
    if (plp->flr_no == 0)
    {
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
    }
    else
    {
        if (bhEne22_AreaCheck(EXP0_F(0x24), EXP0_F(0x2C), plp->px, plp->pz))
        {
            bhEne22_SetTrgPos(epw);
        }
    }
}

// 100% matching!
void bhEne22_Brain04(BH_PWORK* epw)
{
    if (EXP0_F(0x20) < 20.0f)
    {
        EXP0_I(0x8) |= 0x10000;
    }
}

// 100% matching!
void bhEne22_MVType00(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne22_Brain(epw);
    }

    bhEne22_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 7);

        if (EXP0_UC(0x0) & 0x40)
        {
            epw->ct0 = rand() % 60 + 30;
        }
        else
        {
            epw->ct0 = rand() % 60 + 120;
        }

        if (EXP0_I(0x8) & 0x4000)
        {
            EXP0_I(0x8) &= ~0x4000;
            epw->ct0 = rand() % 60 + 90;
            epw->ct1 = 1;
        }
        else
        {
            epw->ct1 = 0;
        }
        epw->ct2 = 0;
        epw->mode1 = 1;
        epw->mode3++;
        break;

    case 1:
        break;
    }

    if ((epw->flg & 0x2000000) && (rand() % 2))
    {
        bhEne22_SePlay(epw, (NJS_POINT3*)&epw->px, 0x1012306);
    }
}

// 100% matching!
void bhEne22_MV01(BH_PWORK* epw)
{
    int hit;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 1, 0, 5);
        epw->way = 384;
        epw->wax = 0;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->spd = 0.0f;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            epw->ct1 = rand() % 30 + 40;
            epw->mode3++;
        }

        epw->spd += 0.02f;
        if (epw->spd >= 0.4f)
        {
            epw->spd = 0.4f;
        }

        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
        bhAddSpeed(epw, 0);
        break;

    case 2:
        if (bhEne_CheckDirWall2(epw, 0, 18.0f) != NULL)
        {
            hit = bhEne_CheckSideWall2(epw, 18.0f, 0);
            if (hit == 0)
            {
                epw->way = (rand() % 2) ? 384 : -384;
            }
            else
            {
                epw->way = hit * 384;
            }

            if (epw->way < 0)
            {
                epw->wax = -256;
            }
            else
            {
                epw->wax = 256;
            }
            EXP0_I(0x8) |= 0x2000;
            bhEne_ChgMtn(epw, 2, 0, 5);
            epw->ct1 = 42;
            epw->mode3++;
        }
        else
        {
            if ((epw->flg & 0x2000000)
                && (((fabsf(EXP0_F(0x24) - epw->px) < 10.0f) && (fabsf(EXP0_F(0x2C) - epw->pz) < 10.0f))
                    || (EXP0_I(0x8) & 0x8000)))
            {
                bhEne_ChgMtn(epw, 4, 0, 5);
                epw->ct1 = 0;
                epw->mode3 = 4;
                EXP0_I(0x8) &= ~0x8000;
            }

            ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
            bhAddSpeed(epw, 0);
        }
        break;

    case 3:
        epw->ay += epw->way;
        bhAddSpeed(epw, -epw->way);
        if (--epw->ct1 < 0)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->mode3 = 2;
        }
        break;

    case 4:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }

        epw->spd -= 0.02f;
        if (epw->spd < 0.0f)
        {
            epw->spd = 0.0f;
        }
        bhAddSpeed(epw, 0);
        break;
    }
}

// 100% matching!
void bhEne22_MV02(BH_PWORK* epw)
{
    ATR_WORK* hp;
    NJS_POINT3 pos;
    int frm;
    int hit;

    switch (epw->mode3)
    {
    case 0:
        epw->way = 768;
        epw->wax = 0;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        epw->ct3 = 0;
        EXP0_I(0x8) |= 0x100;

        if (EXP0_I(0x8) & 0x200)
        {
            bhEne_ChgMtn(epw, 6, 0, 5);
            EXP0_I(0x8) &= ~0x200;
            epw->ct0 = 0;
            epw->spd = 1.2f;
            epw->mode3 = 2;
            return;
        }

        bhEne_ChgMtn(epw, 5, 0, 5);
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
        epw->spd = 0.0f;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 6, 0, 0);
            epw->ct0 = 0;
            epw->ct2 = 300;
            epw->mode3++;
        }

        epw->spd += 0.05f;
        if (epw->spd >= 1.2f)
        {
            epw->spd = 1.2f;
        }

        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 768);
        bhAddSpeed(epw, 0);
        break;

    case 2:
        epw->spd = 1.2f - epw->ct0 * 0.01f;
        epw->ct0++;
        if (epw->spd < 0.8f)
        {
            epw->ct0 = 0;
            epw->spd = 0.8f;
            if (ikou3(epw, (NJS_POINT3*)&plp->px, NJM_DEG_ANG(112.5f)) && (EXP0_F(0x20) > 20.0f))
            {
                epw->mode3 = 6;
                return;
            }
        }

        if (EXP0_I(0x8) & 0x40000)
        {
            EXP0_I(0x8) &= ~0x40000;
            epw->way = (rand() % 2) ? 768 : -768;
            EXP0_I(0x8) |= 0x2000;
            bhEne_ChgMtn(epw, 7, 0, 5);
            if (epw->way > 0)
            {
                epw->mtn_md |= 0x2;
            }
            epw->ct1 = 32;
            epw->mode3 = 4;
            epw->ct2 = 0;
        }
        else
        {
            hp = bhEne_CheckDirWall2(epw, 0, 18.0f);
            if (hp != NULL)
            {
                pos.x = epw->px + 18.0f * -njSin(epw->ay);
                pos.z = epw->pz + 18.0f * -njCos(epw->ay);
                pos.y = epw->py;

                hit = bhEne_CheckSideWall3(epw, &pos, 18.0f, 0);
                if (hit == 0)
                {
                    epw->way = (rand() % 2) ? 768 : -768;
                }
                else
                {
                    epw->way = hit * 768;
                }

                if (epw->way < 0)
                {
                    epw->wax = -1024;
                }
                else
                {
                    epw->wax = 1024;
                }

                EXP0_I(0x8) |= 0x2000;
                bhEne_ChgMtn(epw, 7, 0, 5);
                if (epw->wax > 0)
                {
                    epw->mtn_md |= 0x2;
                }
                epw->ct1 = 21;
                epw->mode3 = 4;
            }
            else
            {
                if ((plp->flr_no == 0) && (EXP0_F(0x20) >= 40.0f))
                {
                    bhEne_ChgMtn(epw, 8, 0, 5);
                    epw->mode3 = 3;
                }
                else
                {
                    if ((fabsf(EXP0_F(0x24) - epw->px) < 5.0f) && (fabsf(EXP0_F(0x2C) - epw->pz) < 5.0f))
                    {
                        bhEne_ChgMtn(epw, 8, 0, 5);
                        epw->mode3 = 3;
                    }

                    ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
                    bhAddSpeed(epw, 0);
                }
            }
        }
        break;

    case 3:
        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) &= ~0x100;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }

        epw->spd -= 0.05f;
        if (epw->spd < 0.0f)
        {
            epw->spd = 0.0f;
        }
        bhAddSpeed(epw, 0);
        break;

    case 4:
        frm = epw->frm_no / 65536;
        if (frm == 20)
        {
            epw->mtn_add = 0;
        }

        if (epw->spd > 0.5f)
        {
            epw->spd -= 0.02f;
            epw->ct0++;
        }
        else
        {
            epw->spd = 0.5f;
        }

        hp = bhEne_CheckDirWall2(epw, 0, 18.0f);
        if ((hp == NULL) && (frm >= 16))
        {
            epw->mtn_add = 65536;
            epw->mode3++;
        }
        else
        {
            epw->ay += epw->way;
        }
        bhAddSpeed(epw, -epw->way);
        break;

    case 5:
        frm = epw->frm_no / 65536;

        epw->spd += 0.05f;
        if (epw->spd >= 1.2f)
        {
            epw->spd = 1.2f;
        }

        epw->ay += epw->way;

        if (frm == 31)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->ct0 = 0;
            epw->mode3 = 2;
            if (epw->mtn_md & 0x2)
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                epw->mtn_md |= 0x2;
            }
        }
        bhAddSpeed(epw, 0);
        break;

    case 6:
        bhEne_ChgMtn(epw, 7, 0, 5);
        epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        epw->ayp = (epw->ayp - epw->ay) & 0xFFFF;
        if (epw->ayp <= NJM_DEG_ANG(180.0f))
        {
            epw->ayp /= 32;
            epw->mtn_md |= 0x2;
        }
        else
        {
            epw->ayp = -(NJM_DEG_ANG(360.0f) - epw->ayp) / 32;
        }
        epw->ct0 = 32;
        epw->mode3++;

    case 7:
        if (epw->spd > 0.5f)
        {
            epw->spd -= 0.02f;
        }
        else
        {
            epw->spd = 0.5f;
        }

        epw->ay += epw->ayp;

        if (--epw->ct0 < 0)
        {
            epw->ct1 = rand() % 30 + 40;
            epw->ct0 = 0;
            epw->mode3 = 2;
            if (epw->mtn_md & 0x2)
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                epw->mtn_md |= 0x2;
            }
        }
        bhAddSpeed(epw, -epw->way);
        break;
    }
}

// 100% matching!
void bhEne22_MV03(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_MV04(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 9, 0, 5);
        epw->ct0 = 30;
        epw->ct1 = 0;
        epw->ct2 = 0;
        EXP0_I(0x5C) = 0;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if (EXP0_I(0x8) & 0x10000)
        {
            EXP0_I(0x8) &= ~0x10000;
            if (frm <= 20)
            {
                EXP0_I(0x8) &= ~0x1000;
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;

                if (((*(O_WRK**)(epw->exp0 + 0x4C))->flg != 0)
                    && ((*(O_WRK**)(epw->exp0 + 0x4C))->id == 353)
                    && ((BH_PWORK*)(*(O_WRK**)(epw->exp0 + 0x4C))->lkwkp == epw))
                {
                    (*(O_WRK**)(epw->exp0 + 0x4C))->mode0 = 4;
                }

                if (EXP0_I(0x8) & 0x80000)
                {
                    rom->lgtp[2].flg &= ~0x3;
                    EXP0_I(0x8) &= ~0x80000;
                }
                break;
            }
        }

        if (epw->ct0 <= 0)
        {
            epw->ct1++;
        }
        else
        {
            epw->ct0--;
        }

        EXP0_F(0x50) = 4.0f * epw->ct1 + 24.0f;

        if ((frm >= 21) && (frm <= 60))
        {
            EXP0_I(0x8) |= 0x20000;

            if ((EXP0_F(0x20) <= EXP0_F(0x50)) && (EXP0_F(0x20) >= EXP0_F(0x50) - 8.0f)
                && ((plp->flg & 0x2) == 0) && ((plp->flg & 0x4) == 0)
                && ((plp->stflg & 0x80000000) == 0))
            {
                plp->flg |= 0x4;
                plp->mode0 = 4;
                plp->mode1 = 0;
                plp->mode2 = 0;
                plp->mode3 = 0;
                plp->hp -= 30;

                bhEne22_SetElectricShockEffect2(epw);
                bhEne22_SePlay(epw, (NJS_POINT3*)&plp->px, 0x1012302);
            }
        }
        else
        {
            EXP0_I(0x8) &= ~0x20000;
        }

        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) &= ~0x1000;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_MV05(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_MV06(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 2, 0, 7);
        epw->ct1 = 0;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 0) && (frm <= 30))
        {
            epw->ay -= NJM_DEG_ANG(3.0f);
        }

        frm = epw->frm_no / 65536;
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) |= 0x200;
            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct3 = 0;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_DGType00(BH_PWORK* epw)
{
    bhEne22_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if ((EXP0_I(0x8) & 0x30) == 0)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x10)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x20)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x30)
        {
            bhEne_ChgMtn(epw, 13, 0, 5);
        }
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x8) |= 0x200;
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        epw->spd = 0.6f;
        ikou(epw, (NJS_POINT3*)&EXP0_F(0x24), 384);
        bhAddSpeed(epw, 0);
    }
}

// 100% matching!
void bhEne22_DG01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if ((EXP0_I(0x8) & 0x30) == 0)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
            if ((rand() % 2) == 0)
            {
                epw->mtn_md |= 0x2;
            }
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x10)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x20)
        {
            bhEne_ChgMtn(epw, 11, 0, 5);
            if ((rand() % 2) == 0)
            {
                epw->mtn_md |= 0x2;
            }
        }
        else if ((EXP0_I(0x8) & 0x30) == 0x30)
        {
            bhEne_ChgMtn(epw, 10, 0, 5);
        }
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne22_DG02(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne22_DDType00(BH_PWORK* epw)
{
    bhEne22_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne22_DD00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (EXP0_I(0x8) & 0x100)
        {
            bhEne_ChgMtn(epw, 20, 0, 5);
        }
        else
        {
            bhEne_ChgMtn(epw, 19, 0, 5);
        }
        epw->spd = 0.8f;
        epw->ct0 = 0;
        epw->mode3++;

    case 1:
        if (epw->mtn_no == 20)
        {
            epw->spd -= 0.01f;
            epw->ct0++;
            if (epw->spd < 0.0f)
            {
                epw->spd = 0.0f;
            }
            bhAddSpeed(epw, 0);
        }

        if (epw->flg & 0x2000000)
        {
            epw->flg |= 0x2;
            epw->flg &= ~0x28;
            bhEne_ChgMtn(epw, 22, 0, 0);
            epw->mode3++;
        }
        break;

    case 2:
        break;
    }
}

/*// 
// Start address: 0x1fdb70
void bhEne22_DD01()
{
	// Line 2554, Address: 0x1fdb70, Func Offset: 0
	// Func End, Address: 0x1fdb78, Func Offset: 0x8
}

// 
// Start address: 0x1fdb80
void bhEne22_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
	NJS_POINT3 dv;
	// Line 2577, Address: 0x1fdb80, Func Offset: 0
	// Line 2581, Address: 0x1fdb90, Func Offset: 0x10
	// Line 2584, Address: 0x1fdbb4, Func Offset: 0x34
	// Line 2585, Address: 0x1fdbc0, Func Offset: 0x40
	// Line 2586, Address: 0x1fdbc4, Func Offset: 0x44
	// Line 2591, Address: 0x1fdbc8, Func Offset: 0x48
	// Line 2584, Address: 0x1fdbcc, Func Offset: 0x4c
	// Line 2585, Address: 0x1fdbd4, Func Offset: 0x54
	// Line 2594, Address: 0x1fdbd8, Func Offset: 0x58
	// Line 2585, Address: 0x1fdbdc, Func Offset: 0x5c
	// Line 2586, Address: 0x1fdbe4, Func Offset: 0x64
	// Line 2589, Address: 0x1fdbf0, Func Offset: 0x70
	// Line 2590, Address: 0x1fdbf4, Func Offset: 0x74
	// Line 2591, Address: 0x1fdbf8, Func Offset: 0x78
	// Line 2592, Address: 0x1fdbfc, Func Offset: 0x7c
	// Line 2593, Address: 0x1fdc00, Func Offset: 0x80
	// Line 2594, Address: 0x1fdc04, Func Offset: 0x84
	// Line 2595, Address: 0x1fdc08, Func Offset: 0x88
	// Line 2597, Address: 0x1fdc0c, Func Offset: 0x8c
	// Line 2598, Address: 0x1fdc1c, Func Offset: 0x9c
	// Line 2599, Address: 0x1fdc2c, Func Offset: 0xac
	// Line 2600, Address: 0x1fdc3c, Func Offset: 0xbc
	// Line 2602, Address: 0x1fdc50, Func Offset: 0xd0
	// Line 2603, Address: 0x1fdc54, Func Offset: 0xd4
	// Line 2606, Address: 0x1fdc5c, Func Offset: 0xdc
	// Line 2610, Address: 0x1fdc64, Func Offset: 0xe4
	// Line 2612, Address: 0x1fdc6c, Func Offset: 0xec
	// Line 2613, Address: 0x1fdc78, Func Offset: 0xf8
	// Line 2614, Address: 0x1fdc80, Func Offset: 0x100
	// Line 2617, Address: 0x1fdc88, Func Offset: 0x108
	// Line 2620, Address: 0x1fdc98, Func Offset: 0x118
	// Line 2621, Address: 0x1fdca4, Func Offset: 0x124
	// Line 2624, Address: 0x1fdcb8, Func Offset: 0x138
	// Line 2627, Address: 0x1fdcc4, Func Offset: 0x144
	// Line 2628, Address: 0x1fdcd0, Func Offset: 0x150
	// Line 2630, Address: 0x1fdcd4, Func Offset: 0x154
	// Line 2627, Address: 0x1fdcd8, Func Offset: 0x158
	// Line 2628, Address: 0x1fdce0, Func Offset: 0x160
	// Line 2631, Address: 0x1fdce4, Func Offset: 0x164
	// Line 2630, Address: 0x1fdcec, Func Offset: 0x16c
	// Line 2635, Address: 0x1fdcf0, Func Offset: 0x170
	// Line 2628, Address: 0x1fdcf4, Func Offset: 0x174
	// Line 2630, Address: 0x1fdcfc, Func Offset: 0x17c
	// Line 2631, Address: 0x1fdd1c, Func Offset: 0x19c
	// Line 2635, Address: 0x1fdd20, Func Offset: 0x1a0
	// Line 2631, Address: 0x1fdd24, Func Offset: 0x1a4
	// Line 2632, Address: 0x1fdd2c, Func Offset: 0x1ac
	// Line 2633, Address: 0x1fdd38, Func Offset: 0x1b8
	// Line 2634, Address: 0x1fdd44, Func Offset: 0x1c4
	// Line 2635, Address: 0x1fdd48, Func Offset: 0x1c8
	// Line 2639, Address: 0x1fdd50, Func Offset: 0x1d0
	// Func End, Address: 0x1fdd64, Func Offset: 0x1e4
}

// 
// Start address: 0x1fdd70
void bhEne22_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
	_anon3 eff_pos;
	int frm;
	int rot;
	NJS_POINT3 dv;
	NJS_POINT3 key;
	O_WORK* owk;
	npobj* obj;
	_anon37* pos_p;
	_anon37* mtn_pos[4];
	// Line 2658, Address: 0x1fdd70, Func Offset: 0
	// Line 2659, Address: 0x1fdd80, Func Offset: 0x10
	// Line 2658, Address: 0x1fdd88, Func Offset: 0x18
	// Line 2659, Address: 0x1fdd90, Func Offset: 0x20
	// Line 2674, Address: 0x1fdda0, Func Offset: 0x30
	// Line 2677, Address: 0x1fddcc, Func Offset: 0x5c
	// Line 2678, Address: 0x1fddd8, Func Offset: 0x68
	// Line 2679, Address: 0x1fdddc, Func Offset: 0x6c
	// Line 2685, Address: 0x1fdde0, Func Offset: 0x70
	// Line 2677, Address: 0x1fdde4, Func Offset: 0x74
	// Line 2678, Address: 0x1fddec, Func Offset: 0x7c
	// Line 2693, Address: 0x1fddf0, Func Offset: 0x80
	// Line 2678, Address: 0x1fddf4, Func Offset: 0x84
	// Line 2679, Address: 0x1fddfc, Func Offset: 0x8c
	// Line 2682, Address: 0x1fde08, Func Offset: 0x98
	// Line 2683, Address: 0x1fde10, Func Offset: 0xa0
	// Line 2684, Address: 0x1fde14, Func Offset: 0xa4
	// Line 2685, Address: 0x1fde18, Func Offset: 0xa8
	// Line 2686, Address: 0x1fde1c, Func Offset: 0xac
	// Line 2687, Address: 0x1fde20, Func Offset: 0xb0
	// Line 2688, Address: 0x1fde24, Func Offset: 0xb4
	// Line 2689, Address: 0x1fde28, Func Offset: 0xb8
	// Line 2691, Address: 0x1fde2c, Func Offset: 0xbc
	// Line 2692, Address: 0x1fde3c, Func Offset: 0xcc
	// Line 2693, Address: 0x1fde4c, Func Offset: 0xdc
	// Line 2694, Address: 0x1fde5c, Func Offset: 0xec
	// Line 2696, Address: 0x1fde70, Func Offset: 0x100
	// Line 2697, Address: 0x1fde78, Func Offset: 0x108
	// Line 2698, Address: 0x1fdea0, Func Offset: 0x130
	// Line 2701, Address: 0x1fdea8, Func Offset: 0x138
	// Line 2702, Address: 0x1fdeb0, Func Offset: 0x140
	// Line 2703, Address: 0x1fded4, Func Offset: 0x164
	// Line 2705, Address: 0x1fdedc, Func Offset: 0x16c
	// Line 2708, Address: 0x1fdee8, Func Offset: 0x178
	// Line 2709, Address: 0x1fdef0, Func Offset: 0x180
	// Line 2710, Address: 0x1fdef8, Func Offset: 0x188
	// Line 2713, Address: 0x1fdf00, Func Offset: 0x190
	// Line 2715, Address: 0x1fdf08, Func Offset: 0x198
	// Line 2717, Address: 0x1fdf14, Func Offset: 0x1a4
	// Line 2718, Address: 0x1fdf1c, Func Offset: 0x1ac
	// Line 2717, Address: 0x1fdf20, Func Offset: 0x1b0
	// Line 2718, Address: 0x1fdf28, Func Offset: 0x1b8
	// Line 2719, Address: 0x1fdf3c, Func Offset: 0x1cc
	// Line 2722, Address: 0x1fdf4c, Func Offset: 0x1dc
	// Line 2726, Address: 0x1fdf64, Func Offset: 0x1f4
	// Line 2729, Address: 0x1fdf80, Func Offset: 0x210
	// Line 2734, Address: 0x1fdf84, Func Offset: 0x214
	// Line 2729, Address: 0x1fdf90, Func Offset: 0x220
	// Line 2734, Address: 0x1fdf94, Func Offset: 0x224
	// Line 2730, Address: 0x1fdf98, Func Offset: 0x228
	// Line 2731, Address: 0x1fdfa0, Func Offset: 0x230
	// Line 2732, Address: 0x1fdfa8, Func Offset: 0x238
	// Line 2733, Address: 0x1fdfb0, Func Offset: 0x240
	// Line 2734, Address: 0x1fdfb8, Func Offset: 0x248
	// Line 2736, Address: 0x1fdfc0, Func Offset: 0x250
	// Line 2740, Address: 0x1fdfe0, Func Offset: 0x270
	// Line 2742, Address: 0x1fdfe8, Func Offset: 0x278
	// Line 2743, Address: 0x1fdff8, Func Offset: 0x288
	// Line 2745, Address: 0x1fe004, Func Offset: 0x294
	// Line 2746, Address: 0x1fe00c, Func Offset: 0x29c
	// Line 2748, Address: 0x1fe014, Func Offset: 0x2a4
	// Line 2751, Address: 0x1fe01c, Func Offset: 0x2ac
	// Line 2755, Address: 0x1fe02c, Func Offset: 0x2bc
	// Line 2759, Address: 0x1fe030, Func Offset: 0x2c0
	// Line 2762, Address: 0x1fe038, Func Offset: 0x2c8
	// Line 2761, Address: 0x1fe040, Func Offset: 0x2d0
	// Line 2755, Address: 0x1fe044, Func Offset: 0x2d4
	// Line 2761, Address: 0x1fe048, Func Offset: 0x2d8
	// Line 2768, Address: 0x1fe04c, Func Offset: 0x2dc
	// Line 2756, Address: 0x1fe050, Func Offset: 0x2e0
	// Line 2759, Address: 0x1fe058, Func Offset: 0x2e8
	// Line 2767, Address: 0x1fe05c, Func Offset: 0x2ec
	// Line 2759, Address: 0x1fe060, Func Offset: 0x2f0
	// Line 2761, Address: 0x1fe068, Func Offset: 0x2f8
	// Line 2762, Address: 0x1fe088, Func Offset: 0x318
	// Line 2767, Address: 0x1fe08c, Func Offset: 0x31c
	// Line 2762, Address: 0x1fe090, Func Offset: 0x320
	// Line 2763, Address: 0x1fe098, Func Offset: 0x328
	// Line 2764, Address: 0x1fe0a4, Func Offset: 0x334
	// Line 2765, Address: 0x1fe0b0, Func Offset: 0x340
	// Line 2766, Address: 0x1fe0b4, Func Offset: 0x344
	// Line 2767, Address: 0x1fe0bc, Func Offset: 0x34c
	// Line 2768, Address: 0x1fe0c4, Func Offset: 0x354
	// Line 2773, Address: 0x1fe0d0, Func Offset: 0x360
	// Line 2775, Address: 0x1fe0ec, Func Offset: 0x37c
	// Line 2776, Address: 0x1fe0f0, Func Offset: 0x380
	// Line 2782, Address: 0x1fe0f4, Func Offset: 0x384
	// Line 2775, Address: 0x1fe0f8, Func Offset: 0x388
	// Line 2776, Address: 0x1fe104, Func Offset: 0x394
	// Line 2778, Address: 0x1fe110, Func Offset: 0x3a0
	// Line 2779, Address: 0x1fe118, Func Offset: 0x3a8
	// Line 2780, Address: 0x1fe11c, Func Offset: 0x3ac
	// Line 2782, Address: 0x1fe120, Func Offset: 0x3b0
	// Line 2783, Address: 0x1fe128, Func Offset: 0x3b8
	// Line 2784, Address: 0x1fe13c, Func Offset: 0x3cc
	// Line 2785, Address: 0x1fe150, Func Offset: 0x3e0
	// Line 2787, Address: 0x1fe160, Func Offset: 0x3f0
	// Func End, Address: 0x1fe178, Func Offset: 0x408
}

// 
// Start address: 0x1fe180
int bhEne22_SetMtn(BH_PWORK* epw)
{
	int ret;
	int frm;
	npobj* obj;
	// Line 2811, Address: 0x1fe180, Func Offset: 0
	// Line 2816, Address: 0x1fe194, Func Offset: 0x14
	// Line 2818, Address: 0x1fe1b0, Func Offset: 0x30
	// Line 2819, Address: 0x1fe1b4, Func Offset: 0x34
	// Line 2821, Address: 0x1fe1cc, Func Offset: 0x4c
	// Line 2822, Address: 0x1fe1d4, Func Offset: 0x54
	// Line 2824, Address: 0x1fe1e8, Func Offset: 0x68
	// Line 2827, Address: 0x1fe1fc, Func Offset: 0x7c
	// Line 2829, Address: 0x1fe214, Func Offset: 0x94
	// Line 2831, Address: 0x1fe218, Func Offset: 0x98
	// Line 2829, Address: 0x1fe220, Func Offset: 0xa0
	// Line 2830, Address: 0x1fe224, Func Offset: 0xa4
	// Line 2831, Address: 0x1fe228, Func Offset: 0xa8
	// Line 2834, Address: 0x1fe230, Func Offset: 0xb0
	// Line 2837, Address: 0x1fe240, Func Offset: 0xc0
	// Line 2839, Address: 0x1fe254, Func Offset: 0xd4
	// Line 2844, Address: 0x1fe264, Func Offset: 0xe4
	// Line 2846, Address: 0x1fe274, Func Offset: 0xf4
	// Line 2856, Address: 0x1fe280, Func Offset: 0x100
	// Line 2858, Address: 0x1fe28c, Func Offset: 0x10c
	// Line 2859, Address: 0x1fe290, Func Offset: 0x110
	// Func End, Address: 0x1fe2a8, Func Offset: 0x128
}

// 
// Start address: 0x1fe2b0
void bhEne22_CheckMtnTbl(BH_PWORK* epw, int frm)
{
	int i;
	_anon46* mtbl;
	// Line 2878, Address: 0x1fe2b0, Func Offset: 0
	// Line 2882, Address: 0x1fe2cc, Func Offset: 0x1c
	// Line 2879, Address: 0x1fe2d8, Func Offset: 0x28
	// Line 2882, Address: 0x1fe2e0, Func Offset: 0x30
	// Line 2887, Address: 0x1fe300, Func Offset: 0x50
	// Line 2889, Address: 0x1fe30c, Func Offset: 0x5c
	// Line 2891, Address: 0x1fe318, Func Offset: 0x68
	// Line 2893, Address: 0x1fe328, Func Offset: 0x78
	// Line 2895, Address: 0x1fe330, Func Offset: 0x80
	// Line 2897, Address: 0x1fe340, Func Offset: 0x90
	// Line 2899, Address: 0x1fe350, Func Offset: 0xa0
	// Line 2900, Address: 0x1fe354, Func Offset: 0xa4
	// Line 2924, Address: 0x1fe368, Func Offset: 0xb8
	// Func End, Address: 0x1fe388, Func Offset: 0xd8
}

// 
// Start address: 0x1fe390
void bhEne22_GetTranslateMtn(BH_PWORK* epw, int frm)
{
	NJS_POINT3 pos;
	_anon25* mkfP;
	// Line 2942, Address: 0x1fe390, Func Offset: 0
	// Line 2945, Address: 0x1fe39c, Func Offset: 0xc
	// Line 2948, Address: 0x1fe3a4, Func Offset: 0x14
	// Line 2945, Address: 0x1fe3ac, Func Offset: 0x1c
	// Line 2948, Address: 0x1fe3d0, Func Offset: 0x40
	// Line 2950, Address: 0x1fe3e8, Func Offset: 0x58
	// Line 2952, Address: 0x1fe3f0, Func Offset: 0x60
	// Line 2954, Address: 0x1fe408, Func Offset: 0x78
	// Line 2955, Address: 0x1fe418, Func Offset: 0x88
	// Line 2956, Address: 0x1fe41c, Func Offset: 0x8c
	// Line 2957, Address: 0x1fe42c, Func Offset: 0x9c
	// Line 2960, Address: 0x1fe434, Func Offset: 0xa4
	// Line 2961, Address: 0x1fe43c, Func Offset: 0xac
	// Line 2962, Address: 0x1fe440, Func Offset: 0xb0
	// Line 2964, Address: 0x1fe444, Func Offset: 0xb4
	// Line 2967, Address: 0x1fe44c, Func Offset: 0xbc
	// Line 2968, Address: 0x1fe460, Func Offset: 0xd0
	// Line 2969, Address: 0x1fe464, Func Offset: 0xd4
	// Line 2973, Address: 0x1fe478, Func Offset: 0xe8
	// Line 2975, Address: 0x1fe488, Func Offset: 0xf8
	// Line 2979, Address: 0x1fe4a0, Func Offset: 0x110
	// Line 2983, Address: 0x1fe4a8, Func Offset: 0x118
	// Line 2979, Address: 0x1fe4ac, Func Offset: 0x11c
	// Line 2980, Address: 0x1fe4b0, Func Offset: 0x120
	// Line 2981, Address: 0x1fe4bc, Func Offset: 0x12c
	// Line 2983, Address: 0x1fe4c4, Func Offset: 0x134
	// Line 2984, Address: 0x1fe4cc, Func Offset: 0x13c
	// Line 2985, Address: 0x1fe4e0, Func Offset: 0x150
	// Line 2986, Address: 0x1fe4f4, Func Offset: 0x164
	// Line 2987, Address: 0x1fe504, Func Offset: 0x174
	// Func End, Address: 0x1fe514, Func Offset: 0x184
}

// 
// Start address: 0x1fe520
void bhEne22_SparkEffect(BH_PWORK* epw, int frm)
{
	int no;
	int j;
	int i;
	unsigned int* argb;
	NJS_POINT3 ps;
	npobj* obj;
	unsigned int* ulpMatAdrTbl[2][40][6];
	unsigned int ene22_eff_col[20];
	// Line 3006, Address: 0x1fe520, Func Offset: 0
	// Line 3034, Address: 0x1fe54c, Func Offset: 0x2c
	// Line 3006, Address: 0x1fe554, Func Offset: 0x34
	// Line 3034, Address: 0x1fe55c, Func Offset: 0x3c
	// Line 3040, Address: 0x1fe56c, Func Offset: 0x4c
	// Line 3043, Address: 0x1fe578, Func Offset: 0x58
	// Line 3045, Address: 0x1fe580, Func Offset: 0x60
	// Line 3046, Address: 0x1fe584, Func Offset: 0x64
	// Line 3047, Address: 0x1fe58c, Func Offset: 0x6c
	// Line 3045, Address: 0x1fe594, Func Offset: 0x74
	// Line 3046, Address: 0x1fe598, Func Offset: 0x78
	// Line 3047, Address: 0x1fe59c, Func Offset: 0x7c
	// Line 3049, Address: 0x1fe5a0, Func Offset: 0x80
	// Line 3050, Address: 0x1fe5ac, Func Offset: 0x8c
	// Line 3051, Address: 0x1fe5bc, Func Offset: 0x9c
	// Line 3053, Address: 0x1fe5cc, Func Offset: 0xac
	// Line 3052, Address: 0x1fe5d4, Func Offset: 0xb4
	// Line 3053, Address: 0x1fe5dc, Func Offset: 0xbc
	// Line 3054, Address: 0x1fe5e4, Func Offset: 0xc4
	// Line 3059, Address: 0x1fe5fc, Func Offset: 0xdc
	// Line 3061, Address: 0x1fe604, Func Offset: 0xe4
	// Line 3062, Address: 0x1fe60c, Func Offset: 0xec
	// Line 3061, Address: 0x1fe610, Func Offset: 0xf0
	// Line 3062, Address: 0x1fe614, Func Offset: 0xf4
	// Line 3064, Address: 0x1fe618, Func Offset: 0xf8
	// Line 3065, Address: 0x1fe620, Func Offset: 0x100
	// Line 3064, Address: 0x1fe628, Func Offset: 0x108
	// Line 3065, Address: 0x1fe62c, Func Offset: 0x10c
	// Line 3066, Address: 0x1fe63c, Func Offset: 0x11c
	// Line 3065, Address: 0x1fe640, Func Offset: 0x120
	// Line 3066, Address: 0x1fe644, Func Offset: 0x124
	// Line 3067, Address: 0x1fe64c, Func Offset: 0x12c
	// Line 3066, Address: 0x1fe654, Func Offset: 0x134
	// Line 3067, Address: 0x1fe658, Func Offset: 0x138
	// Line 3068, Address: 0x1fe660, Func Offset: 0x140
	// Line 3067, Address: 0x1fe668, Func Offset: 0x148
	// Line 3068, Address: 0x1fe66c, Func Offset: 0x14c
	// Line 3072, Address: 0x1fe674, Func Offset: 0x154
	// Line 3073, Address: 0x1fe67c, Func Offset: 0x15c
	// Line 3074, Address: 0x1fe680, Func Offset: 0x160
	// Line 3075, Address: 0x1fe688, Func Offset: 0x168
	// Line 3077, Address: 0x1fe6a4, Func Offset: 0x184
	// Line 3088, Address: 0x1fe6a8, Func Offset: 0x188
	// Line 3092, Address: 0x1fe6b0, Func Offset: 0x190
	// Line 3080, Address: 0x1fe6b8, Func Offset: 0x198
	// Line 3081, Address: 0x1fe6bc, Func Offset: 0x19c
	// Line 3080, Address: 0x1fe6c0, Func Offset: 0x1a0
	// Line 3081, Address: 0x1fe6c4, Func Offset: 0x1a4
	// Line 3083, Address: 0x1fe6c8, Func Offset: 0x1a8
	// Line 3085, Address: 0x1fe6dc, Func Offset: 0x1bc
	// Line 3086, Address: 0x1fe6e0, Func Offset: 0x1c0
	// Line 3088, Address: 0x1fe6ec, Func Offset: 0x1cc
	// Line 3089, Address: 0x1fe6f8, Func Offset: 0x1d8
	// Line 3094, Address: 0x1fe700, Func Offset: 0x1e0
	// Line 3097, Address: 0x1fe708, Func Offset: 0x1e8
	// Line 3098, Address: 0x1fe70c, Func Offset: 0x1ec
	// Line 3100, Address: 0x1fe710, Func Offset: 0x1f0
	// Line 3101, Address: 0x1fe720, Func Offset: 0x200
	// Line 3102, Address: 0x1fe730, Func Offset: 0x210
	// Line 3105, Address: 0x1fe73c, Func Offset: 0x21c
	// Line 3102, Address: 0x1fe740, Func Offset: 0x220
	// Line 3113, Address: 0x1fe74c, Func Offset: 0x22c
	// Line 3108, Address: 0x1fe750, Func Offset: 0x230
	// Line 3109, Address: 0x1fe758, Func Offset: 0x238
	// Line 3108, Address: 0x1fe75c, Func Offset: 0x23c
	// Line 3113, Address: 0x1fe760, Func Offset: 0x240
	// Line 3120, Address: 0x1fe764, Func Offset: 0x244
	// Line 3113, Address: 0x1fe768, Func Offset: 0x248
	// Line 3120, Address: 0x1fe76c, Func Offset: 0x24c
	// Line 3113, Address: 0x1fe770, Func Offset: 0x250
	// Line 3119, Address: 0x1fe774, Func Offset: 0x254
	// Line 3113, Address: 0x1fe778, Func Offset: 0x258
	// Line 3114, Address: 0x1fe788, Func Offset: 0x268
	// Line 3119, Address: 0x1fe790, Func Offset: 0x270
	// Line 3120, Address: 0x1fe794, Func Offset: 0x274
	// Line 3121, Address: 0x1fe79c, Func Offset: 0x27c
	// Line 3124, Address: 0x1fe7ac, Func Offset: 0x28c
	// Line 3130, Address: 0x1fe7b4, Func Offset: 0x294
	// Line 3132, Address: 0x1fe7d4, Func Offset: 0x2b4
	// Line 3134, Address: 0x1fe7f0, Func Offset: 0x2d0
	// Line 3137, Address: 0x1fe7fc, Func Offset: 0x2dc
	// Line 3139, Address: 0x1fe80c, Func Offset: 0x2ec
	// Line 3144, Address: 0x1fe818, Func Offset: 0x2f8
	// Line 3146, Address: 0x1fe828, Func Offset: 0x308
	// Line 3147, Address: 0x1fe834, Func Offset: 0x314
	// Line 3149, Address: 0x1fe84c, Func Offset: 0x32c
	// Line 3151, Address: 0x1fe85c, Func Offset: 0x33c
	// Func End, Address: 0x1fe88c, Func Offset: 0x36c
}

// 
// Start address: 0x1fe890
unsigned int* bhEne22_GetDengekiColorAddr(npobj* objp, int no)
{
	short head;
	int max;
	short* plp;
	int offset;
	// Line 3162, Address: 0x1fe890, Func Offset: 0
	// Line 3161, Address: 0x1fe894, Func Offset: 0x4
	// Line 3162, Address: 0x1fe898, Func Offset: 0x8
	// Line 3171, Address: 0x1fe8a0, Func Offset: 0x10
	// Line 3193, Address: 0x1fe8a4, Func Offset: 0x14
	// Line 3165, Address: 0x1fe8a8, Func Offset: 0x18
	// Line 3166, Address: 0x1fe8b4, Func Offset: 0x24
	// Line 3168, Address: 0x1fe8cc, Func Offset: 0x3c
	// Line 3169, Address: 0x1fe8d4, Func Offset: 0x44
	// Line 3170, Address: 0x1fe8d8, Func Offset: 0x48
	// Line 3171, Address: 0x1fe8e0, Func Offset: 0x50
	// Line 3174, Address: 0x1fe8e8, Func Offset: 0x58
	// Line 3175, Address: 0x1fe8f0, Func Offset: 0x60
	// Line 3178, Address: 0x1fe908, Func Offset: 0x78
	// Line 3181, Address: 0x1fe910, Func Offset: 0x80
	// Line 3183, Address: 0x1fe918, Func Offset: 0x88
	// Line 3185, Address: 0x1fe91c, Func Offset: 0x8c
	// Line 3183, Address: 0x1fe920, Func Offset: 0x90
	// Line 3184, Address: 0x1fe924, Func Offset: 0x94
	// Line 3186, Address: 0x1fe928, Func Offset: 0x98
	// Line 3187, Address: 0x1fe930, Func Offset: 0xa0
	// Line 3190, Address: 0x1fe948, Func Offset: 0xb8
	// Line 3191, Address: 0x1fe950, Func Offset: 0xc0
	// Line 3192, Address: 0x1fe954, Func Offset: 0xc4
	// Line 3193, Address: 0x1fe95c, Func Offset: 0xcc
	// Line 3198, Address: 0x1fe964, Func Offset: 0xd4
	// Func End, Address: 0x1fe96c, Func Offset: 0xdc
}

// 
// Start address: 0x1fe970
void bhEne22_SetWaterEffect(BH_PWORK* epw, int mtn_no, int frm)
{
	int i;
	float size;
	_anon3 eff_pos;
	O_WORK* owk;
	_anon44* eff2;
	_anon41* eff;
	// Line 3217, Address: 0x1fe970, Func Offset: 0
	// Line 3226, Address: 0x1fe98c, Func Offset: 0x1c
	// Line 3228, Address: 0x1fe9a0, Func Offset: 0x30
	// Line 3230, Address: 0x1fe9a4, Func Offset: 0x34
	// Line 3232, Address: 0x1fe9b4, Func Offset: 0x44
	// Line 3234, Address: 0x1fe9c8, Func Offset: 0x58
	// Line 3239, Address: 0x1fe9d0, Func Offset: 0x60
	// Line 3234, Address: 0x1fe9d8, Func Offset: 0x68
	// Line 3239, Address: 0x1fe9e8, Func Offset: 0x78
	// Line 3234, Address: 0x1fe9ec, Func Offset: 0x7c
	// Line 3235, Address: 0x1fe9f0, Func Offset: 0x80
	// Line 3239, Address: 0x1fe9f4, Func Offset: 0x84
	// Line 3235, Address: 0x1fe9f8, Func Offset: 0x88
	// Line 3236, Address: 0x1fe9fc, Func Offset: 0x8c
	// Line 3237, Address: 0x1fea04, Func Offset: 0x94
	// Line 3238, Address: 0x1fea0c, Func Offset: 0x9c
	// Line 3239, Address: 0x1fea14, Func Offset: 0xa4
	// Line 3240, Address: 0x1fea1c, Func Offset: 0xac
	// Line 3241, Address: 0x1fea20, Func Offset: 0xb0
	// Line 3242, Address: 0x1fea24, Func Offset: 0xb4
	// Line 3245, Address: 0x1fea2c, Func Offset: 0xbc
	// Line 3246, Address: 0x1fea34, Func Offset: 0xc4
	// Line 3248, Address: 0x1fea38, Func Offset: 0xc8
	// Line 3250, Address: 0x1fea48, Func Offset: 0xd8
	// Line 3252, Address: 0x1fea5c, Func Offset: 0xec
	// Line 3254, Address: 0x1fea74, Func Offset: 0x104
	// Line 3252, Address: 0x1fea78, Func Offset: 0x108
	// Line 3254, Address: 0x1fea7c, Func Offset: 0x10c
	// Line 3252, Address: 0x1fea84, Func Offset: 0x114
	// Line 3254, Address: 0x1fea94, Func Offset: 0x124
	// Line 3252, Address: 0x1feab0, Func Offset: 0x140
	// Line 3254, Address: 0x1feab4, Func Offset: 0x144
	// Line 3256, Address: 0x1feac0, Func Offset: 0x150
	// Line 3257, Address: 0x1feac4, Func Offset: 0x154
	// Line 3258, Address: 0x1feacc, Func Offset: 0x15c
	// Func End, Address: 0x1feaec, Func Offset: 0x17c
}

// 
// Start address: 0x1feaf0
int bhEne22_GetAreaNo(float px, float pz)
{
	int i;
	_anon10* at;
	_anon10 trg_atari[4];
	// Line 3278, Address: 0x1feaf0, Func Offset: 0
	// Line 3280, Address: 0x1feb04, Func Offset: 0x14
	// Line 3278, Address: 0x1feb08, Func Offset: 0x18
	// Line 3280, Address: 0x1feb0c, Func Offset: 0x1c
	// Line 3289, Address: 0x1feb28, Func Offset: 0x38
	// Line 3280, Address: 0x1feb2c, Func Offset: 0x3c
	// Line 3291, Address: 0x1feb40, Func Offset: 0x50
	// Line 3293, Address: 0x1feb64, Func Offset: 0x74
	// Line 3296, Address: 0x1feb6c, Func Offset: 0x7c
	// Line 3298, Address: 0x1feb7c, Func Offset: 0x8c
	// Line 3299, Address: 0x1feb80, Func Offset: 0x90
	// Func End, Address: 0x1feb9c, Func Offset: 0xac
}

// 
// Start address: 0x1feba0
int bhEne22_AreaCheck(float ene_x, float ene_z, float ply_x, float ply_z)
{
	int ply_at;
	int ene_at;
	// Line 3318, Address: 0x1feba0, Func Offset: 0
	// Line 3321, Address: 0x1febb8, Func Offset: 0x18
	// Line 3322, Address: 0x1febc0, Func Offset: 0x20
	// Line 3324, Address: 0x1febd0, Func Offset: 0x30
	// Line 3327, Address: 0x1febe4, Func Offset: 0x44
	// Func End, Address: 0x1febfc, Func Offset: 0x5c
}

// 
// Start address: 0x1fec00
int bhEne22_SetTrgPos(BH_PWORK* epw)
{
	int i;
	int ply_at;
	int ene_at;
	float dist;
	float near_dist;
	NJS_POINT3 pos;
	NJS_POINT3 epos;
	_anon10* at;
	_anon10 trg_atari[4];
	// Line 3346, Address: 0x1fec00, Func Offset: 0
	// Line 3348, Address: 0x1fec24, Func Offset: 0x24
	// Line 3346, Address: 0x1fec28, Func Offset: 0x28
	// Line 3348, Address: 0x1fec30, Func Offset: 0x30
	// Line 3356, Address: 0x1fec34, Func Offset: 0x34
	// Line 3348, Address: 0x1fec38, Func Offset: 0x38
	// Line 3361, Address: 0x1fec5c, Func Offset: 0x5c
	// Line 3362, Address: 0x1fec70, Func Offset: 0x70
	// Line 3364, Address: 0x1fec88, Func Offset: 0x88
	// Line 3366, Address: 0x1fec9c, Func Offset: 0x9c
	// Line 3371, Address: 0x1feca0, Func Offset: 0xa0
	// Line 3366, Address: 0x1feca4, Func Offset: 0xa4
	// Line 3367, Address: 0x1feca8, Func Offset: 0xa8
	// Line 3368, Address: 0x1fecb0, Func Offset: 0xb0
	// Line 3373, Address: 0x1fecb8, Func Offset: 0xb8
	// Line 3375, Address: 0x1fecc8, Func Offset: 0xc8
	// Line 3377, Address: 0x1fecd8, Func Offset: 0xd8
	// Line 3375, Address: 0x1fecdc, Func Offset: 0xdc
	// Line 3378, Address: 0x1fece0, Func Offset: 0xe0
	// Line 3375, Address: 0x1fece8, Func Offset: 0xe8
	// Line 3376, Address: 0x1fecf0, Func Offset: 0xf0
	// Line 3377, Address: 0x1fecf8, Func Offset: 0xf8
	// Line 3378, Address: 0x1fed0c, Func Offset: 0x10c
	// Line 3379, Address: 0x1fed14, Func Offset: 0x114
	// Line 3384, Address: 0x1fed40, Func Offset: 0x140
	// Line 3382, Address: 0x1fed44, Func Offset: 0x144
	// Line 3381, Address: 0x1fed48, Func Offset: 0x148
	// Line 3386, Address: 0x1fed4c, Func Offset: 0x14c
	// Line 3388, Address: 0x1fed50, Func Offset: 0x150
	// Line 3390, Address: 0x1fed60, Func Offset: 0x160
	// Line 3392, Address: 0x1fed7c, Func Offset: 0x17c
	// Line 3394, Address: 0x1fed80, Func Offset: 0x180
	// Line 3392, Address: 0x1fed84, Func Offset: 0x184
	// Line 3393, Address: 0x1fed88, Func Offset: 0x188
	// Line 3394, Address: 0x1fed8c, Func Offset: 0x18c
	// Line 3397, Address: 0x1fed94, Func Offset: 0x194
	// Line 3453, Address: 0x1fed98, Func Offset: 0x198
	// Func End, Address: 0x1fedc8, Func Offset: 0x1c8
}

// 
// Start address: 0x1fedd0
void bhEne22_SePlay(BH_PWORK* epw, NJS_POINT3* ps, int no)
{
	// Line 3718, Address: 0x1fedd0, Func Offset: 0
	// Line 3719, Address: 0x1fedd8, Func Offset: 0x8
	// Line 3721, Address: 0x1fedec, Func Offset: 0x1c
	// Line 3722, Address: 0x1fee04, Func Offset: 0x34
	// Func End, Address: 0x1fee10, Func Offset: 0x40
}

// 
// Start address: 0x1fee10
_anon0* bhEne22_SetDengekiEffect(BH_PWORK* epw, int obj, NJS_POINT3* ofs, float size)
{
	int eno;
	// Line 3745, Address: 0x1fee10, Func Offset: 0
	// Line 3748, Address: 0x1fee1c, Func Offset: 0xc
	// Line 3749, Address: 0x1fee30, Func Offset: 0x20
	// Line 3748, Address: 0x1fee34, Func Offset: 0x24
	// Line 3749, Address: 0x1fee40, Func Offset: 0x30
	// Line 3756, Address: 0x1fee48, Func Offset: 0x38
	// Line 3749, Address: 0x1fee4c, Func Offset: 0x3c
	// Line 3750, Address: 0x1fee58, Func Offset: 0x48
	// Line 3751, Address: 0x1fee6c, Func Offset: 0x5c
	// Line 3752, Address: 0x1fee80, Func Offset: 0x70
	// Line 3753, Address: 0x1fee94, Func Offset: 0x84
	// Line 3754, Address: 0x1feea8, Func Offset: 0x98
	// Line 3756, Address: 0x1feeb8, Func Offset: 0xa8
	// Line 3758, Address: 0x1feec0, Func Offset: 0xb0
	// Line 3761, Address: 0x1feecc, Func Offset: 0xbc
	// Line 3758, Address: 0x1feed4, Func Offset: 0xc4
	// Line 3759, Address: 0x1feee0, Func Offset: 0xd0
	// Line 3760, Address: 0x1feef8, Func Offset: 0xe8
	// Line 3761, Address: 0x1fef10, Func Offset: 0x100
	// Line 3762, Address: 0x1fef2c, Func Offset: 0x11c
	// Line 3765, Address: 0x1fef34, Func Offset: 0x124
	// Line 3768, Address: 0x1fef3c, Func Offset: 0x12c
	// Line 3765, Address: 0x1fef44, Func Offset: 0x134
	// Line 3766, Address: 0x1fef50, Func Offset: 0x140
	// Line 3767, Address: 0x1fef64, Func Offset: 0x154
	// Line 3768, Address: 0x1fef78, Func Offset: 0x168
	// Line 3770, Address: 0x1fef90, Func Offset: 0x180
	// Line 3772, Address: 0x1fef9c, Func Offset: 0x18c
	// Line 3773, Address: 0x1fefc0, Func Offset: 0x1b0
	// Line 3772, Address: 0x1fefcc, Func Offset: 0x1bc
	// Line 3773, Address: 0x1fefd4, Func Offset: 0x1c4
	// Line 3774, Address: 0x1fefd8, Func Offset: 0x1c8
	// Line 3773, Address: 0x1fefe4, Func Offset: 0x1d4
	// Line 3774, Address: 0x1fefe8, Func Offset: 0x1d8
	// Line 3775, Address: 0x1fefec, Func Offset: 0x1dc
	// Line 3773, Address: 0x1feff4, Func Offset: 0x1e4
	// Line 3774, Address: 0x1feff8, Func Offset: 0x1e8
	// Line 3775, Address: 0x1feffc, Func Offset: 0x1ec
	// Line 3776, Address: 0x1ff004, Func Offset: 0x1f4
	// Line 3777, Address: 0x1ff018, Func Offset: 0x208
	// Line 3779, Address: 0x1ff028, Func Offset: 0x218
	// Line 3780, Address: 0x1ff02c, Func Offset: 0x21c
	// Func End, Address: 0x1ff03c, Func Offset: 0x22c
}

// 
// Start address: 0x1ff040
void bhEne22_SetDengekiEffect2(BH_PWORK* epw)
{
	int ang;
	int i;
	int eno;
	// Line 3798, Address: 0x1ff040, Func Offset: 0
	// Line 3806, Address: 0x1ff058, Func Offset: 0x18
	// Line 3816, Address: 0x1ff060, Func Offset: 0x20
	// Line 3806, Address: 0x1ff064, Func Offset: 0x24
	// Line 3816, Address: 0x1ff068, Func Offset: 0x28
	// Line 3807, Address: 0x1ff06c, Func Offset: 0x2c
	// Line 3806, Address: 0x1ff070, Func Offset: 0x30
	// Line 3807, Address: 0x1ff07c, Func Offset: 0x3c
	// Line 3809, Address: 0x1ff084, Func Offset: 0x44
	// Line 3807, Address: 0x1ff08c, Func Offset: 0x4c
	// Line 3808, Address: 0x1ff098, Func Offset: 0x58
	// Line 3809, Address: 0x1ff0ac, Func Offset: 0x6c
	// Line 3810, Address: 0x1ff0c0, Func Offset: 0x80
	// Line 3811, Address: 0x1ff0d4, Func Offset: 0x94
	// Line 3812, Address: 0x1ff0e8, Func Offset: 0xa8
	// Line 3813, Address: 0x1ff0fc, Func Offset: 0xbc
	// Line 3814, Address: 0x1ff110, Func Offset: 0xd0
	// Line 3815, Address: 0x1ff130, Func Offset: 0xf0
	// Line 3816, Address: 0x1ff150, Func Offset: 0x110
	// Line 3817, Address: 0x1ff16c, Func Offset: 0x12c
	// Line 3819, Address: 0x1ff17c, Func Offset: 0x13c
	// Line 3820, Address: 0x1ff1a0, Func Offset: 0x160
	// Line 3819, Address: 0x1ff1a4, Func Offset: 0x164
	// Line 3822, Address: 0x1ff1a8, Func Offset: 0x168
	// Line 3823, Address: 0x1ff1cc, Func Offset: 0x18c
	// Line 3825, Address: 0x1ff1e8, Func Offset: 0x1a8
	// Line 3827, Address: 0x1ff214, Func Offset: 0x1d4
	// Line 3831, Address: 0x1ff230, Func Offset: 0x1f0
	// Line 3833, Address: 0x1ff234, Func Offset: 0x1f4
	// Line 3827, Address: 0x1ff238, Func Offset: 0x1f8
	// Line 3828, Address: 0x1ff254, Func Offset: 0x214
	// Line 3829, Address: 0x1ff260, Func Offset: 0x220
	// Line 3830, Address: 0x1ff264, Func Offset: 0x224
	// Line 3831, Address: 0x1ff268, Func Offset: 0x228
	// Line 3832, Address: 0x1ff26c, Func Offset: 0x22c
	// Line 3835, Address: 0x1ff270, Func Offset: 0x230
	// Line 3837, Address: 0x1ff280, Func Offset: 0x240
	// Func End, Address: 0x1ff29c, Func Offset: 0x25c
}

// 
// Start address: 0x1ff2a0
void bhEne22_SetElectricShockEffect(BH_PWORK* epw, int type)
{
	int i;
	NJS_POINT3 ps;
	_anon0* op;
	_anon40* eff_tbl;
	_anon40 en22_den_tbl[20];
	// Line 3858, Address: 0x1ff2a0, Func Offset: 0
	// Line 3889, Address: 0x1ff2bc, Func Offset: 0x1c
	// Line 3891, Address: 0x1ff2c4, Func Offset: 0x24
	// Line 3892, Address: 0x1ff2f4, Func Offset: 0x54
	// Line 3893, Address: 0x1ff370, Func Offset: 0xd0
	// Line 3894, Address: 0x1ff378, Func Offset: 0xd8
	// Line 3895, Address: 0x1ff37c, Func Offset: 0xdc
	// Line 3896, Address: 0x1ff3c8, Func Offset: 0x128
	// Line 3897, Address: 0x1ff3d0, Func Offset: 0x130
	// Line 3899, Address: 0x1ff3dc, Func Offset: 0x13c
	// Line 3901, Address: 0x1ff3e4, Func Offset: 0x144
	// Line 3902, Address: 0x1ff414, Func Offset: 0x174
	// Line 3903, Address: 0x1ff490, Func Offset: 0x1f0
	// Line 3904, Address: 0x1ff498, Func Offset: 0x1f8
	// Line 3905, Address: 0x1ff49c, Func Offset: 0x1fc
	// Line 3906, Address: 0x1ff4e8, Func Offset: 0x248
	// Line 3908, Address: 0x1ff4f0, Func Offset: 0x250
	// Line 3909, Address: 0x1ff4f4, Func Offset: 0x254
	// Line 3910, Address: 0x1ff4f8, Func Offset: 0x258
	// Line 3911, Address: 0x1ff508, Func Offset: 0x268
	// Line 3912, Address: 0x1ff510, Func Offset: 0x270
	// Line 3914, Address: 0x1ff51c, Func Offset: 0x27c
	// Line 3916, Address: 0x1ff524, Func Offset: 0x284
	// Line 3918, Address: 0x1ff528, Func Offset: 0x288
	// Line 3920, Address: 0x1ff538, Func Offset: 0x298
	// Line 3921, Address: 0x1ff54c, Func Offset: 0x2ac
	// Line 3923, Address: 0x1ff554, Func Offset: 0x2b4
	// Line 3924, Address: 0x1ff55c, Func Offset: 0x2bc
	// Line 3925, Address: 0x1ff560, Func Offset: 0x2c0
	// Line 3926, Address: 0x1ff564, Func Offset: 0x2c4
	// Line 3930, Address: 0x1ff56c, Func Offset: 0x2cc
	// Line 3932, Address: 0x1ff574, Func Offset: 0x2d4
	// Line 3933, Address: 0x1ff5a4, Func Offset: 0x304
	// Line 3934, Address: 0x1ff620, Func Offset: 0x380
	// Line 3935, Address: 0x1ff628, Func Offset: 0x388
	// Line 3936, Address: 0x1ff62c, Func Offset: 0x38c
	// Line 3937, Address: 0x1ff678, Func Offset: 0x3d8
	// Line 3939, Address: 0x1ff680, Func Offset: 0x3e0
	// Line 3940, Address: 0x1ff684, Func Offset: 0x3e4
	// Line 3941, Address: 0x1ff688, Func Offset: 0x3e8
	// Line 3943, Address: 0x1ff698, Func Offset: 0x3f8
	// Func End, Address: 0x1ff6b8, Func Offset: 0x418
}

// 
// Start address: 0x1ff6c0
void bhEne22_SetElectricShockEffect2(BH_PWORK* epw)
{
	int i;
	NJS_POINT3 ps;
	_anon0* op;
	float ply_ofs[4];
	int obj[4];
	// Line 3963, Address: 0x1ff6c0, Func Offset: 0
	// Line 3964, Address: 0x1ff6d8, Func Offset: 0x18
	// Line 3963, Address: 0x1ff6dc, Func Offset: 0x1c
	// Line 3964, Address: 0x1ff6e0, Func Offset: 0x20
	// Line 3970, Address: 0x1ff6ec, Func Offset: 0x2c
	// Line 3964, Address: 0x1ff6fc, Func Offset: 0x3c
	// Line 3970, Address: 0x1ff700, Func Offset: 0x40
	// Line 3980, Address: 0x1ff704, Func Offset: 0x44
	// Line 3970, Address: 0x1ff70c, Func Offset: 0x4c
	// Line 3982, Address: 0x1ff710, Func Offset: 0x50
	// Line 3983, Address: 0x1ff714, Func Offset: 0x54
	// Line 3984, Address: 0x1ff764, Func Offset: 0xa4
	// Line 3986, Address: 0x1ff7b8, Func Offset: 0xf8
	// Line 3988, Address: 0x1ff7dc, Func Offset: 0x11c
	// Line 3989, Address: 0x1ff7e8, Func Offset: 0x128
	// Line 3990, Address: 0x1ff7ec, Func Offset: 0x12c
	// Line 3991, Address: 0x1ff7f0, Func Offset: 0x130
	// Line 3989, Address: 0x1ff7f8, Func Offset: 0x138
	// Line 3991, Address: 0x1ff800, Func Offset: 0x140
	// Line 3992, Address: 0x1ff808, Func Offset: 0x148
	// Func End, Address: 0x1ff828, Func Offset: 0x168
}

// 
// Start address: 0x1ff830
_anon0* bhEne22_SetElectricLightEffect(BH_PWORK* epw)
{
	int eno;
	NJS_POINT3 ofs;
	// Line 4010, Address: 0x1ff830, Func Offset: 0
	// Line 4011, Address: 0x1ff834, Func Offset: 0x4
	// Line 4010, Address: 0x1ff838, Func Offset: 0x8
	// Line 4011, Address: 0x1ff840, Func Offset: 0x10
	// Line 4014, Address: 0x1ff850, Func Offset: 0x20
	// Line 4011, Address: 0x1ff85c, Func Offset: 0x2c
	// Line 4014, Address: 0x1ff864, Func Offset: 0x34
	// Line 4015, Address: 0x1ff868, Func Offset: 0x38
	// Line 4017, Address: 0x1ff86c, Func Offset: 0x3c
	// Line 4025, Address: 0x1ff870, Func Offset: 0x40
	// Line 4014, Address: 0x1ff878, Func Offset: 0x48
	// Line 4015, Address: 0x1ff884, Func Offset: 0x54
	// Line 4016, Address: 0x1ff898, Func Offset: 0x68
	// Line 4017, Address: 0x1ff8ac, Func Offset: 0x7c
	// Line 4018, Address: 0x1ff8c0, Func Offset: 0x90
	// Line 4019, Address: 0x1ff8d4, Func Offset: 0xa4
	// Line 4020, Address: 0x1ff8e8, Func Offset: 0xb8
	// Line 4022, Address: 0x1ff8fc, Func Offset: 0xcc
	// Line 4023, Address: 0x1ff910, Func Offset: 0xe0
	// Line 4024, Address: 0x1ff924, Func Offset: 0xf4
	// Line 4025, Address: 0x1ff938, Func Offset: 0x108
	// Line 4026, Address: 0x1ff950, Func Offset: 0x120
	// Line 4028, Address: 0x1ff95c, Func Offset: 0x12c
	// Line 4029, Address: 0x1ff980, Func Offset: 0x150
	// Line 4028, Address: 0x1ff98c, Func Offset: 0x15c
	// Line 4029, Address: 0x1ff994, Func Offset: 0x164
	// Line 4030, Address: 0x1ff998, Func Offset: 0x168
	// Line 4029, Address: 0x1ff9a4, Func Offset: 0x174
	// Line 4030, Address: 0x1ff9a8, Func Offset: 0x178
	// Line 4031, Address: 0x1ff9ac, Func Offset: 0x17c
	// Line 4029, Address: 0x1ff9b4, Func Offset: 0x184
	// Line 4031, Address: 0x1ff9b8, Func Offset: 0x188
	// Line 4030, Address: 0x1ff9bc, Func Offset: 0x18c
	// Line 4031, Address: 0x1ff9c0, Func Offset: 0x190
	// Line 4032, Address: 0x1ff9c4, Func Offset: 0x194
	// Line 4034, Address: 0x1ff9d4, Func Offset: 0x1a4
	// Line 4035, Address: 0x1ff9d8, Func Offset: 0x1a8
	// Func End, Address: 0x1ff9e8, Func Offset: 0x1b8
}

// 
// Start address: 0x1ff9f0
void bhEne22_SetLight(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int type)
{
	_anon2* lp;
	// Line 4062, Address: 0x1ff9f0, Func Offset: 0
	// Line 4065, Address: 0x1ff9f4, Func Offset: 0x4
	// Line 4062, Address: 0x1ff9f8, Func Offset: 0x8
	// Line 4065, Address: 0x1ff9fc, Func Offset: 0xc
	// Line 4067, Address: 0x1ffa00, Func Offset: 0x10
	// Line 4068, Address: 0x1ffa04, Func Offset: 0x14
	// Line 4065, Address: 0x1ffa08, Func Offset: 0x18
	// Line 4062, Address: 0x1ffa0c, Func Offset: 0x1c
	// Line 4074, Address: 0x1ffa10, Func Offset: 0x20
	// Line 4075, Address: 0x1ffa14, Func Offset: 0x24
	// Line 4065, Address: 0x1ffa18, Func Offset: 0x28
	// Line 4067, Address: 0x1ffa20, Func Offset: 0x30
	// Line 4068, Address: 0x1ffa24, Func Offset: 0x34
	// Line 4069, Address: 0x1ffa28, Func Offset: 0x38
	// Line 4070, Address: 0x1ffa2c, Func Offset: 0x3c
	// Line 4071, Address: 0x1ffa30, Func Offset: 0x40
	// Line 4072, Address: 0x1ffa34, Func Offset: 0x44
	// Line 4073, Address: 0x1ffa38, Func Offset: 0x48
	// Line 4074, Address: 0x1ffa3c, Func Offset: 0x4c
	// Line 4075, Address: 0x1ffa40, Func Offset: 0x50
	// Line 4078, Address: 0x1ffa44, Func Offset: 0x54
	// Line 4062, Address: 0x1ffa48, Func Offset: 0x58
	// Line 4078, Address: 0x1ffa4c, Func Offset: 0x5c
	// Line 4080, Address: 0x1ffa54, Func Offset: 0x64
	// Line 4081, Address: 0x1ffa58, Func Offset: 0x68
	// Line 4082, Address: 0x1ffa5c, Func Offset: 0x6c
	// Line 4083, Address: 0x1ffa60, Func Offset: 0x70
	// Line 4084, Address: 0x1ffa68, Func Offset: 0x78
	// Line 4085, Address: 0x1ffa70, Func Offset: 0x80
	// Line 4086, Address: 0x1ffa74, Func Offset: 0x84
	// Line 4090, Address: 0x1ffa7c, Func Offset: 0x8c
	// Line 4091, Address: 0x1ffa84, Func Offset: 0x94
	// Line 4092, Address: 0x1ffa8c, Func Offset: 0x9c
	// Line 4093, Address: 0x1ffa90, Func Offset: 0xa0
	// Line 4094, Address: 0x1ffa98, Func Offset: 0xa8
	// Line 4095, Address: 0x1ffaa0, Func Offset: 0xb0
	// Line 4096, Address: 0x1ffaa8, Func Offset: 0xb8
	// Line 4097, Address: 0x1ffaac, Func Offset: 0xbc
	// Line 4098, Address: 0x1ffab0, Func Offset: 0xc0
	// Line 4101, Address: 0x1ffab4, Func Offset: 0xc4
	// Line 4104, Address: 0x1ffabc, Func Offset: 0xcc
	// Line 4107, Address: 0x1ffac4, Func Offset: 0xd4
	// Line 4109, Address: 0x1ffacc, Func Offset: 0xdc
	// Func End, Address: 0x1ffad4, Func Offset: 0xe4
}

// 
// Start address: 0x1ffae0
void bhEne22_CtrLight(BH_PWORK* epw)
{
	float fl;
	_anon2* lp;
	float rgb[3];
	// Line 4126, Address: 0x1ffae0, Func Offset: 0
	// Line 4127, Address: 0x1ffaec, Func Offset: 0xc
	// Line 4126, Address: 0x1ffaf4, Func Offset: 0x14
	// Line 4127, Address: 0x1ffaf8, Func Offset: 0x18
	// Line 4131, Address: 0x1ffb10, Func Offset: 0x30
	// Line 4133, Address: 0x1ffb28, Func Offset: 0x48
	// Line 4134, Address: 0x1ffb34, Func Offset: 0x54
	// Line 4133, Address: 0x1ffb38, Func Offset: 0x58
	// Line 4134, Address: 0x1ffb3c, Func Offset: 0x5c
	// Line 4136, Address: 0x1ffb48, Func Offset: 0x68
	// Line 4137, Address: 0x1ffb54, Func Offset: 0x74
	// Line 4141, Address: 0x1ffb80, Func Offset: 0xa0
	// Line 4140, Address: 0x1ffb84, Func Offset: 0xa4
	// Line 4141, Address: 0x1ffb88, Func Offset: 0xa8
	// Line 4142, Address: 0x1ffb8c, Func Offset: 0xac
	// Line 4143, Address: 0x1ffb94, Func Offset: 0xb4
	// Line 4146, Address: 0x1ffba0, Func Offset: 0xc0
	// Line 4147, Address: 0x1ffba8, Func Offset: 0xc8
	// Line 4148, Address: 0x1ffbb4, Func Offset: 0xd4
	// Line 4149, Address: 0x1ffbc0, Func Offset: 0xe0
	// Line 4150, Address: 0x1ffbcc, Func Offset: 0xec
	// Line 4152, Address: 0x1ffbe4, Func Offset: 0x104
	// Line 4154, Address: 0x1ffbf4, Func Offset: 0x114
	// Line 4155, Address: 0x1ffbfc, Func Offset: 0x11c
	// Line 4154, Address: 0x1ffc04, Func Offset: 0x124
	// Line 4155, Address: 0x1ffc0c, Func Offset: 0x12c
	// Line 4157, Address: 0x1ffc18, Func Offset: 0x138
	// Line 4160, Address: 0x1ffc20, Func Offset: 0x140
	// Line 4162, Address: 0x1ffc28, Func Offset: 0x148
	// Line 4161, Address: 0x1ffc2c, Func Offset: 0x14c
	// Line 4162, Address: 0x1ffc30, Func Offset: 0x150
	// Line 4163, Address: 0x1ffc34, Func Offset: 0x154
	// Line 4166, Address: 0x1ffc40, Func Offset: 0x160
	// Line 4167, Address: 0x1ffc48, Func Offset: 0x168
	// Line 4168, Address: 0x1ffc54, Func Offset: 0x174
	// Line 4169, Address: 0x1ffc60, Func Offset: 0x180
	// Line 4170, Address: 0x1ffc6c, Func Offset: 0x18c
	// Line 4171, Address: 0x1ffc84, Func Offset: 0x1a4
	// Line 4173, Address: 0x1ffc94, Func Offset: 0x1b4
	// Line 4174, Address: 0x1ffc98, Func Offset: 0x1b8
	// Line 4173, Address: 0x1ffc9c, Func Offset: 0x1bc
	// Line 4176, Address: 0x1ffca4, Func Offset: 0x1c4
	// Line 4179, Address: 0x1ffcac, Func Offset: 0x1cc
	// Line 4181, Address: 0x1ffcbc, Func Offset: 0x1dc
	// Line 4182, Address: 0x1ffcc0, Func Offset: 0x1e0
	// Line 4181, Address: 0x1ffcc4, Func Offset: 0x1e4
	// Line 4182, Address: 0x1ffccc, Func Offset: 0x1ec
	// Line 4187, Address: 0x1ffcd0, Func Offset: 0x1f0
	// Line 4188, Address: 0x1ffce0, Func Offset: 0x200
	// Line 4187, Address: 0x1ffce4, Func Offset: 0x204
	// Line 4188, Address: 0x1ffcec, Func Offset: 0x20c
	// Line 4190, Address: 0x1ffd00, Func Offset: 0x220
	// Line 4192, Address: 0x1ffd10, Func Offset: 0x230
	// Line 4193, Address: 0x1ffd14, Func Offset: 0x234
	// Line 4192, Address: 0x1ffd18, Func Offset: 0x238
	// Line 4195, Address: 0x1ffd20, Func Offset: 0x240
	// Line 4198, Address: 0x1ffd28, Func Offset: 0x248
	// Line 4199, Address: 0x1ffd30, Func Offset: 0x250
	// Line 4200, Address: 0x1ffd3c, Func Offset: 0x25c
	// Line 4201, Address: 0x1ffd48, Func Offset: 0x268
	// Line 4202, Address: 0x1ffd54, Func Offset: 0x274
	// Line 4203, Address: 0x1ffd6c, Func Offset: 0x28c
	// Line 4205, Address: 0x1ffd7c, Func Offset: 0x29c
	// Line 4206, Address: 0x1ffd84, Func Offset: 0x2a4
	// Line 4205, Address: 0x1ffd8c, Func Offset: 0x2ac
	// Line 4206, Address: 0x1ffd94, Func Offset: 0x2b4
	// Line 4211, Address: 0x1ffda4, Func Offset: 0x2c4
	// Func End, Address: 0x1ffdb8, Func Offset: 0x2d8
}

// 
// Start address: 0x1ffdc0
void bhEne22_ChgDengekiColor(npobj* objp, int no, unsigned int argb)
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
	short head;
	int max;
	unsigned char* mat;
	short* plp;
	int offset;
	// Line 4230, Address: 0x1ffdc0, Func Offset: 0
	// Line 4224, Address: 0x1ffdc4, Func Offset: 0x4
	// Line 4227, Address: 0x1ffdd4, Func Offset: 0x14
	// Line 4230, Address: 0x1ffdd8, Func Offset: 0x18
	// Line 4225, Address: 0x1ffddc, Func Offset: 0x1c
	// Line 4229, Address: 0x1ffdec, Func Offset: 0x2c
	// Line 4226, Address: 0x1ffdf0, Func Offset: 0x30
	// Line 4239, Address: 0x1ffdfc, Func Offset: 0x3c
	// Line 4282, Address: 0x1ffe00, Func Offset: 0x40
	// Line 4233, Address: 0x1ffe04, Func Offset: 0x44
	// Line 4234, Address: 0x1ffe10, Func Offset: 0x50
	// Line 4236, Address: 0x1ffe28, Func Offset: 0x68
	// Line 4237, Address: 0x1ffe30, Func Offset: 0x70
	// Line 4238, Address: 0x1ffe34, Func Offset: 0x74
	// Line 4239, Address: 0x1ffe3c, Func Offset: 0x7c
	// Line 4242, Address: 0x1ffe44, Func Offset: 0x84
	// Line 4243, Address: 0x1ffe4c, Func Offset: 0x8c
	// Line 4246, Address: 0x1ffe64, Func Offset: 0xa4
	// Line 4249, Address: 0x1ffe6c, Func Offset: 0xac
	// Line 4253, Address: 0x1ffea4, Func Offset: 0xe4
	// Line 4254, Address: 0x1ffea8, Func Offset: 0xe8
	// Line 4255, Address: 0x1ffeac, Func Offset: 0xec
	// Line 4257, Address: 0x1ffeb0, Func Offset: 0xf0
	// Line 4260, Address: 0x1ffeb8, Func Offset: 0xf8
	// Line 4261, Address: 0x1ffebc, Func Offset: 0xfc
	// Line 4262, Address: 0x1ffec0, Func Offset: 0x100
	// Line 4263, Address: 0x1ffec4, Func Offset: 0x104
	// Line 4264, Address: 0x1ffec8, Func Offset: 0x108
	// Line 4265, Address: 0x1ffecc, Func Offset: 0x10c
	// Line 4266, Address: 0x1ffed0, Func Offset: 0x110
	// Line 4267, Address: 0x1ffed4, Func Offset: 0x114
	// Line 4270, Address: 0x1ffed8, Func Offset: 0x118
	// Line 4272, Address: 0x1ffee0, Func Offset: 0x120
	// Line 4274, Address: 0x1ffee4, Func Offset: 0x124
	// Line 4272, Address: 0x1ffee8, Func Offset: 0x128
	// Line 4273, Address: 0x1ffeec, Func Offset: 0x12c
	// Line 4275, Address: 0x1ffef0, Func Offset: 0x130
	// Line 4276, Address: 0x1ffef8, Func Offset: 0x138
	// Line 4279, Address: 0x1fff10, Func Offset: 0x150
	// Line 4280, Address: 0x1fff18, Func Offset: 0x158
	// Line 4281, Address: 0x1fff1c, Func Offset: 0x15c
	// Line 4282, Address: 0x1fff24, Func Offset: 0x164
	// Line 4287, Address: 0x1fff2c, Func Offset: 0x16c
	// Func End, Address: 0x1fff34, Func Offset: 0x174
}*/
