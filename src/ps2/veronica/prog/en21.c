#include "../../../ps2/veronica/prog/en21.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Albinoid Infant

static BP_WORK BloodParam = {
    {0.0f, 0.1f, 0.0f},
    0,
    0.0f,
    0.1f,
    {0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0, 0, 0, 0}
};

static char En21SdwTab[2] = {1, -1};

static CPCL CapColTab[9] = {
    { 1,  4, 10},
    { 2,  2,  8},
    {-1,  2,  3},
    { 3,  3,  8},
    { 1,  2,  3},
    { 5, 10,  5},
    {10, 12,  5},
    {12, 14,  4},
    { 0,  0,  0}
};

static float En21SpdAddTbl[19] = {
    -0.2f, -0.25f, -0.25f, -0.2f,
    -0.15f, -0.1f, -0.0f, -0.1f,
    -0.15f, -0.2f, -0.25f, -0.25f,
    -0.2f, -0.15f, -0.1f, -0.0f,
    -0.0f, -0.1f, -0.15f
};

static unsigned char En21SparkTbl[15] = {
    0x11, 0x15, 0x10, 0x14, 0x0F,
    0x13, 0x0E, 0x12, 0x01, 0x02,
    0x03, 0x06, 0x0A, 0x04, 0x05
};

void (*bhEne21_Mode0[6])(BH_PWORK*) = {
    bhEne21_Init,
    bhEne21_Move,
    bhEne21_Nage,
    bhEne21_Damage,
    bhEne21_Die,
    bhEne_Event
};

// Unused (present in DWARF)
// void (*bhEne21_BrainType[1])(BH_PWORK*);

void (*bhEne21_MoveMode2[9])(BH_PWORK*) = {
    bhEne21_MV00,
    bhEne21_MV01,
    bhEne21_MV02,
    bhEne21_MV03,
    bhEne21_MV04,
    bhEne21_MV05,
    bhEne21_MV06,
    bhEne21_MV07,
    bhEne21_MV08,
};

void (*bhEne21_NageMode2[1])(BH_PWORK*) = {
    bhEne21_NG00
};

// void (*bhEne21_DamageMode2[1])(BH_PWORK*);

void (*bhEne21_DieMode2[1])(BH_PWORK*) = {
    bhEne21_DD00
};

// 100% matching!
void bhEne21(BH_PWORK* epw)
{
    O_WORK* owk;
    int i;

    bhEne21_Mode0[epw->mode0](epw);

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    if ((epw->mode0 == 5) && (epw->type == 2) && (rand() % 3 == 0))
    {
        bhEne21_SetMarkEff(epw);
    }

    if (epw->flg & 4)
    {
        for (i = 0; i < 0x40; i++)
        {
            epw->dam[i] = 0;
        }

        epw->flg = epw->flg & ~0x4;
    }

    if ((epw->flg & 8) && (epw->mode0 != 5))
    {
        if (epw->flg & 0x10)
        {
            bhCheckWall(epw);
        }

        if (epw->flg & 0x40)
        {
            bhCheckPlayer(epw);
        }

        bhEne_CheckEnemiesBall(epw);
    }

    bhCalcModel(epw);

    if (epw->flg & 0x20)
    {
        owk = epw->mlwP->owP + 1;
        epw->watr.c1.x = owk->mtx[12];
        epw->watr.c1.y = owk->mtx[13];
        epw->watr.c1.z = owk->mtx[14];

        owk = epw->mlwP->owP + 6;
        epw->watr.c2.x = owk->mtx[12];
        epw->watr.c2.y = owk->mtx[13];
        epw->watr.c2.z = owk->mtx[14];
        epw->watr.r = 1.2f;
    }

    if (EXP0_UC(0x17) == 1)
    {
        bhEne21_PlayerControl(epw);
    }

    if (EXP0_UC(0x15) != 0)
    {
        EXP0_UC(0x15) -= 1;
    }
}

// 100% matching!
void bhEne21_Init(BH_PWORK* epw)
{
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0x18, 8);
    }

    if (epw->type == 1)
    {
        epw->flg |= 0x8000;
        epw->flg &= ~0x178;
        epw->stflg |= 0x8;
        epw->flg2 &= ~0x1;
        epw->flg &= ~0x6;
        epw->ar = 0.0f;
        epw->ah = 0.0f;
        epw->car = 0.0f;
        epw->cah = 0.0f;
        epw->hp = 80;

        EXP0_UC(0x14) = 0;
        EXP0_F(0x0) = 999.0f;
        EXP0_I(0x4) = 0;
        EXP0_I(0x8) = 0;
        EXP0_I(0xC) = 0;
        EXP0_I(0x10) = 0;
        EXP0_UC(0x15) = 0;
        EXP0_UC(0x16) = 4;
        EXP0_UC(0x17) = 0;

        epw->mtn_no = 7;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->hokan_rate = 0;
        epw->mtn_add = 0;
        epw->mtn_md = 0;
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
    else
    {
        epw->flg |= 0x178;
        epw->flg2 |= 0x40;
        epw->stflg &= ~0x8;
        epw->flg &= ~0x8006;
        epw->ar = 4.0f;
        epw->ah = 1.0f;
        epw->aox = 0.0f;
        epw->aoy = 0.0f;
        epw->aoz = 0.8f;
        epw->car = 2.0f;
        epw->cah = 1.0f;

        if (sys->gm_mode == 0)
        {
            epw->hp = 80;
        }
        else
        {
            epw->hp = 50;
        }

        EXP0_UC(0x14) = 0;
        EXP0_F(0x0) = 999.0f;
        EXP0_I(0x4) = 0;
        EXP0_I(0x8) = 0;
        EXP0_I(0xC) = 0;
        EXP0_I(0x10) = 0;
        EXP0_UC(0x15) = 0;
        EXP0_UC(0x16) = 4;
        EXP0_UC(0x17) = 0;

        epw->lok_jno = 4;
        epw->mtn_no = 7;
        epw->frm_no = rand() % 19;
        epw->hokan_count = 0;
        epw->hokan_rate = 0x10000;
        epw->mtn_add = 0x10000;
        epw->mtn_md = 0;
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 1;
        epw->mode3 = 0;
        epw->cpcl = (CPCL*)CapColTab;
        epw->clp_jno[0] = 0;
        epw->clp_jno[1] = -1;
        epw->mdflg &= ~0x20;

        if (epw->flg & 0x800)
        {
            return;
        }

        bhSetShadow(En21SdwTab, (unsigned char*)epw, 4, 3.0f, 1.0f, 4.0f);
        epw->flg |= 0x800;
    }
}

// 100% matching!
void bhEne21_SearchPlayer(BH_PWORK* epw)
{
    int ang;
    float dx;
    float dz;

    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0x0) = njSqrt(dx * dx + dz * dz);
    EXP0_F(0x8) = plp->px;
    EXP0_F(0xC) = plp->py;
    EXP0_F(0x10) = plp->pz;

    ang = 10430.381f * atan2f(dx, dz);
    EXP0_I(0x4) = (short)(ang - epw->ay);
    ang = abs(EXP0_I(0x4));
    if (ang < NJM_DEG_ANG(100.0f))
    {
        EXP0_UC(0x14) = 1;
    }
    else
    {
        EXP0_UC(0x14) = 0;
    }
}

// 100% matching!
void bhEne21_Brain(BH_PWORK* epw)
{
    bhEne21_BR00(epw);
}

// 100% matching!
void bhEne21_BR00(BH_PWORK* epw)
{
    if ((plp->stflg & 0x80000000) || (plp->flg & 2) || (plp->flg & 4) || (epw->flg & 4))
    {
        return;
    }

    bhEne21_SearchPlayer(epw);

    if ((EXP0_UC(0x14) != 0) && (EXP0_UC(0x15) == 0) && (EXP0_F(0x0) < 5.5f))
    {
        if (abs(EXP0_I(0x4)) < NJM_DEG_ANG(5.0f))
        {
            epw->mode0 = 2;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            bhEne21_Nage(epw);
        }
        else if (EXP0_I(0x4) > 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }
        else
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne21_Brain(epw);
    }
    
    if (((epw->flg & 4) != 0) && ((epw->flg & 2) == 0))
    {
        bhEne21_Damage(epw);
    }
    
    if (epw->mode0 == 1)
    {
        bhEne21_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne21_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }

        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.05f;
        epw->mode3++;
        // Fallthrough
        case 1:
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 8) {
            bhEne21_SetSparkEff(epw, 1, 3, epw->frm_no >> 0x10);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12301);
        }

        if (epw->ct0-- == 0) {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV01(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    unsigned int rnd;

    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }

        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.5f;
        epw->mode3++;
        // Fallthrough
        case 1:
        epw->spd = 0.5f;
        epw->spd += En21SpdAddTbl[epw->frm_no >> 0x10];
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if ((rand() % 3) == 0)
        {
            bhEne21_SetMarkEff(epw);
        }

        if (EXP0_UC(0x14) != 0)
        {
            if (bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) != 0xFF)
            {
                EXP0_F(0x8) = pos.x;
                EXP0_F(0x10) = pos.z;
            }
            else
            {
                EXP0_F(0x8) = plp->px;
                EXP0_F(0x10) = plp->pz;
            }
            epw->ay += bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), NJM_DEG_ANG(4.0f));
        }
        else
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = (rand() % 2) ? 3 : 2;
            epw->mode3 = 0;
            return;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            rnd = rand() % 10;
            if (rnd == 0)
            {
                epw->mode2 = 0;
            }
            else if (rnd == 1)
            {
                epw->mode2 = 3;
            }
            else if (rnd == 2)
            {
                epw->mode2 = 2;
            }
            else
            {
                epw->mode2 = 1;
            }
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }
        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.5f;
        epw->mode3++;
        // Fallthrough
        case 1:
        epw->ay -= NJM_DEG_ANG(4.0f);
        epw->spd = 0.5f;
        epw->spd += En21SpdAddTbl[epw->frm_no >> 0x10];
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (rand() % 3 == 0)
        {
            bhEne21_SetMarkEff(epw);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }
        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.5f;
        epw->mode3++;
        // Fallthrough
        case 1:
        epw->ay += NJM_DEG_ANG(4.0f);
        epw->spd = 0.5f;
        epw->spd += En21SpdAddTbl[epw->frm_no >> 0x10];
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (rand() % 3 == 0)
        {
            bhEne21_SetMarkEff(epw);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }
        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.05f;
        epw->mode3++;
        // Fallthrough
        case 1:
        epw->ay -= NJM_DEG_ANG(7.0f);
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
        if (epw->mtn_no != 7)
        {
            epw->mtn_no = 7;
            epw->frm_no = rand() % 19;
            epw->hokan_count = 3;
            epw->hokan_rate = 0x8000;
        }
        epw->ct0 = rand() % 10 + 10;
        epw->spd = 0.05f;
        epw->mode3++;
        // Fallthrough
        case 1:
        epw->ay += NJM_DEG_ANG(7.0f);
        bhAddSpeed(epw, 0);

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV06(BH_PWORK* epw)
{
    unsigned char wall;

    switch (epw->mode3)
    {
        case 0:
        wall = bhEne21_AllWayWallCheck(epw, 3.0f);
        if ((wall & 8) == 0)
        {
            epw->mtn_no = (rand() % 2) ? 2 : 1;
            epw->mode3 = 2;
        }
        else
        {
            epw->mode3 = 1;

            if (((wall & 2) == 0) && ((wall & 4) == 0))
            {
                epw->mtn_no = (rand() % 2) ? 2 : 1;
            }
            else if ((wall & 2) == 0)
            {
                epw->mtn_no = 1;
            }
            else if ((wall & 4) == 0)
            {
                epw->mtn_no = 2;
            }
            else
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
                break;
            }
        }
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->frm_no = 0;
        epw->hokan_count = 3;
        epw->hokan_rate = 0x8000;
        break;

        case 1:
        if (epw->mtn_no == 1)
        {
            epw->ay -= NJM_DEG_ANG(90.0f) / epw->mnwP[epw->mtn_no].frm_num;
        }
        else
        {
            epw->ay += NJM_DEG_ANG(90.0f) / epw->mnwP[epw->mtn_no].frm_num;
        }

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        break;

        case 2:
        if (epw->mtn_no == 1)
        {
            epw->ay -= NJM_DEG_ANG(180.0f) / epw->mnwP[epw->mtn_no].frm_num;
        }
        else
        {
            epw->ay += NJM_DEG_ANG(180.0f) / epw->mnwP[epw->mtn_no].frm_num;
        }

        if (epw->ct0 == 17)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12300);
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne21_MV07(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne21_MV08(BH_PWORK* epw)
{
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne21_Nage(BH_PWORK* epw)
{
    bhEne21_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne21_NG00(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int i;

    epw->ct0++;

    switch (epw->mode3)
    {
    case 0:
        EXP0_UC(0x17) = 1;
        plp->flg |= 0x10004;
        plp->stflg |= 0x10000;
        plp->mode0 = 4;
        plp->mode1 = 0;
        if (abs((short)(epw->ay - plp->ay)) < NJM_DEG_ANG(90.0f))
        {
            plp->mode2 = 1;
            plp->ayp = epw->ay;
        }
        else
        {
            plp->mode2 = 0;
            plp->ayp = (short)(epw->ay + NJM_DEG_ANG(180.0f));
        }
        plp->mode3 = 0;
        epw->mtn_no = 7;
        epw->frm_no = 0;
        epw->hokan_count = 3;
        epw->hokan_rate = 0x8000;
        epw->ct0 = 0;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12301);
        epw->mode3++;
        // Fallthrough
    case 1:
        if (((epw->frm_no >> 0x10) % 2) == 0)
        {
            bhEne21_SetSparkEff(epw, 1, 1, epw->ct0);
        }

        if (epw->ct0 == 4)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x12301);
            plp->hp -= 9;
            if (plp->hp < 0) {
                epw->mode3 = 3;
                break;
            }
            plp->mode0 = 4;
            plp->mode1 = 1;
            plp->mode3 = 0;
            plp->djnt_no = 4;
            plp->way = epw->ay;
            plp->dpx = epw->mlwP->owP->mtx[12];
            plp->dpy = epw->mlwP->owP->mtx[13];
            plp->dpz = epw->mlwP->owP->mtx[14];
            bhEne_CallPlayerVoice(0x402);
            StartVibrationEx(1, 10);
        }

        if (epw->ct0 == 15) {
            epw->mode3++;
        }
        break;

    case 2:
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 6;
        epw->mode3 = 0;

        ep = ene;
        for (i = 0; i < sys->ewk_n; i++, ep++)
        {
            if ((ep->flg & 1) && (ep->id == 21))
            {
                ep->exp0[0x15] = 35;
            }
        }
        plp->mode0 = 4;
        plp->mode1 = 2;
        plp->mode2 = 0;
        plp->mode3 = 0;
        break;

    case 3:
        epw->ct0 = 0;
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
        break;
    }
}

// 100% matching!
void bhEne21_Damage(BH_PWORK* epw)
{
    unsigned int i;
    unsigned int dam;
    NJS_POINT3 pos;

    for (i = 0, dam = 0; i < epw->mnwP->obj_num; i++)
    {
        if (epw->dam[i] != 0)
        {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }

    if (dam != 0)
    {
        pos.x = 0.0f;
        pos.y = 0.4f;
        pos.z = 0.0f;
        bhEne_SetBloodEffect2(epw, 0, 4, &pos);
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x2302);
    }

    if (epw->hp < dam)
    {
        epw->mode0 = 4;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }
    else
    {
        epw->hp -= dam;
        epw->spd = 0.7f;
    }
}

// 100% matching!
void bhEne21_Die(BH_PWORK* epw)
{
    bhEne21_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne21_DD00(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int i;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x8;
        epw->mtn_no = EXP0_UC(0x16);
        epw->frm_no = 0;
        epw->hokan_count = 3;
        epw->hokan_rate = 0x8000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        ep = ene;
        EXP0_UC(0x16)++;
        if (EXP0_UC(0x16) > 6)
        {
            EXP0_UC(0x16) = 4;
        }
        for (i = 0; i < sys->ewk_n; i++, ep++)
        {
            if ((ep->flg & 1) && (ep->id == 21))
            {
                ep->exp0[0x16] = EXP0_UC(0x16);
            }
        }
        epw->mode3++;
        // Fallthrough
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            epw->mode3++;
        }
        break;

    case 2:
        epw->hp = -1;
        epw->flg |= 0x2;
    }
}

// 100% matching!
void bhEne21_PlayerControl(BH_PWORK* epw)
{
    switch (plp->mode1)
    {
    case 0:
        if (plp->mode3 != 0) break;

        plp->flg &= ~0x40000;
        plp->flg |= 0x10004;
        plp->flg2 |= 0x1;
        plp->stflg |= 0x10000;
        if (plp->hp < 30)
        {
            plp->mtn_no = 0x2C;
        }
        else if (plp->hp < 120)
        {
            plp->mtn_no = 0x2B;
        }
        else
        {
            plp->mtn_no = 0x2A;
        }
        plp->frm_no = 0;
        plp->hokan_count = 5;
        plp->hokan_rate = 0x8000;
        plp->mode3++;
        break;

    case 1:
        switch (plp->mode3)
        {
        case 0:
            if (plp->mode2 == 0)
            {
                plp->mtn_no = 0x4A;
            }
            else
            {
                plp->mtn_no = 0x49;
            }
            plp->frm_no = 0;
            plp->hokan_count = 3;
            plp->hokan_rate = 0x8000;
            plp->ct0 = plp->mnwP[plp->mtn_no].frm_num;
            plp->ct1 = plp->mnwP[plp->mtn_no].frm_num - 3;
            plp->mode3++;
            // Fallthrough
        case 1:
            if (plp->ct1 > 0)
            {
                plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
            }

            if (plp->ct0-- == 0)
            {
                if (plp->hp < 30)
                {
                    plp->mtn_no = 0x2C;
                }
                else if (plp->hp < 120)
                {
                    plp->mtn_no = 0x2B;
                }
                else
                {
                    plp->mtn_no = 0x2A;
                }
                plp->frm_no = 0;
                plp->hokan_count = 4;
                plp->hokan_rate = 0x8000;
                plp->mode3++;
            }
        }
        break;

    case 2:
        plp->flg &= ~0x10004;
        plp->flg2 &= ~0x1;
        plp->flg |= 0x8;
        plp->stflg &= ~0x10000;
        plp->at_flg = 0;
        plp->mode0 = 1;
        EXP0_UC(0x17) = 0;
    }
}

// 100% matching!
unsigned char bhEne21_AllWayWallCheck(BH_PWORK* epw, float dist)
{
    NJS_POINT3 pos;
    int ang;
    unsigned char ret;
    float i;

    ret = 0;
    ang = (unsigned short)epw->ay;
    for (i = 1.0f; i <= dist; i = i + 2.0f)
    {
        pos.x = epw->px - i * njSin(ang);
        pos.z = epw->pz - i * njCos(ang);
        pos.y = epw->py;
        if (bhCheckWallType(&pos, epw->flg, epw->ar, epw->ah) != NULL)
        {
            ret |= 0x1;
            break;
        }
    }

    ang = (unsigned short)(epw->ay - NJM_DEG_ANG(90.0f));
    for (i = 1.0f; i <= dist; i = i + 2.0f)
    {
        pos.x = epw->px - i * njSin(ang);
        pos.z = epw->pz - i * njCos(ang);
        pos.y = epw->py;
        if (bhCheckWallType(&pos, epw->flg, epw->ar, epw->ah) != NULL)
        {
            ret |= 0x2;
            break;
        }
    }

    ang = (unsigned short)(epw->ay + NJM_DEG_ANG(90.0f));
    for (i = 1.0f; i <= dist; i = i + 2.0f)
    {
        pos.x = epw->px - i * njSin(ang);
        pos.z = epw->pz - i * njCos(ang);
        pos.y = epw->py;
        if (bhCheckWallType(&pos, epw->flg, epw->ar, epw->ah) != NULL)
        {
            ret |= 0x4;
            break;
        }
    }

    ang = (unsigned short)(epw->ay + NJM_DEG_ANG(180.0f));
    for (i = 1.0f; i <= dist; i = i + 2.0f)
    {
        pos.x = epw->px - i * njSin(ang);
        pos.z = epw->pz - i * njCos(ang);
        pos.y = epw->py;
        if (bhCheckWallType(&pos, epw->flg, epw->ar, epw->ah) != NULL)
        {
            ret |= 0x8;
            break;
        }
    }

    return ret;
}

// 100% matching!
void bhEne21_SetSparkEff(BH_PWORK* epw, int num, int flg, unsigned int ofy)
{
    int eno;
    int i;
    O_WORK* owk;

    for (i = 0; i < num; i++)
    {
        sys->ef.id = 399;
        sys->ef.flg = 1;
        sys->ef.type = flg;
        sys->ef.sx = 1.0f;
        sys->ef.sy = 1.0f;
        sys->ef.sz = 1.0f;

        switch (flg)
        {
        case 0:
            sys->ef.px = epw->px - 0.5f;
            sys->ef.py = epw->py + 0.7f;
            sys->ef.pz = epw->pz - 0.5f;
            sys->ef.ay = epw->ay;
            break;

        case 1:
        {
            float mtx12;
            float mtx13;
            float mtx14;
            float tmp;

            owk = plp->mlwP->owP + En21SparkTbl[ofy];
            mtx12 = mtx12 = owk->mtx[12];
            mtx13 = mtx13 = owk->mtx[13];
            mtx14 = mtx14 = owk->mtx[14];

            tmp = ((rand() % 2) ? 0.2f : -0.2f);
            sys->ef.px = mtx12 + (tmp * (rand() % 3));
            tmp = ((rand() % 2) ? 0.1f : -0.1f);
            sys->ef.pz = mtx14 + (tmp * (rand() % 3));
            tmp = ((rand() % 2) ? 0.1f : -0.1f);
            sys->ef.py = mtx13 + (tmp * (rand() % 3));
            break;
        }

        case 2:
        {
            float tmp;

            tmp = ((rand() % 2) ? 0.5f : -0.5f);
            sys->ef.px = plp->px + (tmp * ((rand() % 6) + 1));
            tmp = ((rand() % 2) ? 0.4f : -0.4f);
            sys->ef.pz = plp->pz + (tmp * ((rand() % 5) + 1));
            sys->ef.py = plp->py + (3.0f * ((rand() % 5) + 1));
            break;
        }

        case 3:
        {
            float mtx12;
            float mtx13;
            float mtx14;

            owk = &epw->mlwP->owP[1];
            mtx12 = owk->mtx[12];
            mtx13 = owk->mtx[13] + 0.7f;
            mtx14 = owk->mtx[14];

            sys->ef.px = mtx12;
            sys->ef.pz = mtx14;
            sys->ef.py = mtx13;
            sys->ef.ay = epw->ay + NJM_DEG_ANG(180.0f);
        }
        }

        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            eff[eno].stflg |= 0x20;
            eff[eno].txp[0] = epw->mlwP->texP;
            eff[eno].tex_id = 5;
        }
    }
}

// 100% matching!
void bhEff_E21_Spark(O_WRK* op)
{
    static EN21UV uvinfo0[9] = {
        { 80, 160, 40, 40},
        {120, 160, 40, 40},
        {160, 160, 40, 40},
        {200, 160, 40, 40},
        { 80, 200, 40, 40},
        {120, 200, 40, 40},
        {160, 200, 40, 40},
        {200, 200, 40, 40},
        { -1,   0,  0,  0}
    };
    static EN21UV uvinfo1[8] = {
        {  0,   0, 80, 80},
        { 80,   0, 80, 80},
        {160,   0, 80, 80},
        {  0,  80, 80, 80},
        { 80,  80, 80, 80},
        {160,  80, 80, 80},
        {  0, 160, 80, 80},
        { -1,   0,  0,  0}
    };
    static EN21UV uvinfo2[9] = {
        { 80, 160, 40, 40},
        {120, 160, 40, 40},
        {160, 160, 40, 40},
        {200, 160, 40, 40},
        { 80, 200, 40, 40},
        {120, 200, 40, 40},
        {160, 200, 40, 40},
        {200, 200, 40, 40},
        { -1,   0,  0,  0}
    };
    static EN21UV uvinfo3[9] = {
        { 80, 160, 40, 40},
        {120, 160, 40, 40},
        {160, 160, 40, 40},
        {200, 160, 40, 40},
        { 80, 200, 40, 40},
        {120, 200, 40, 40},
        {160, 200, 40, 40},
        {200, 200, 40, 40},
        { -1,   0,  0,  0}
    };
    static EN21UV* uvtble[4] = {
        uvinfo0,
        uvinfo1,
        uvinfo2,
        uvinfo3
    };
    static char flm_tbl[4] = {
        10, 3, 2, 3
    };
    static char pat_tbl[4] = {
        8, 7, 8, 8
    };

    EN21UV* uvp;

    switch (op->mode0)
    {
    case 0:
        op->bl_src = 8;
        op->bl_dst = 10;
        op->ct0 = 0;
        op->ct1 = pat_tbl[op->type];
        op->ct2 = flm_tbl[op->type];
        op->flg |= 0x180000;
        op->stflg |= 0x20;
        op->sxb = op->sx;
        op->syb = op->sy;
        op->yn = op->py;
        op->mode0 = 1;
        // Fallthrough
    case 1:
        op->ct2--;
        if (op->ct2 < 0)
        {
            op->flg = 0;
            break;
        }
        else
        {
            uvp = &uvtble[op->type][rand() % op->ct1];
        }

        switch (op->type)
        {
        case 0:
            op->px = op->px - njSin((unsigned short)op->ay) * 0.4f;
            op->pz = op->pz - njCos((unsigned short)op->ay) * 0.4f;
            break;

        case 1:
            op->py += 0.2f;
            break;

        case 2:
            break;

        case 3:
            op->px = op->px - njSin((unsigned short)op->ay) * 0.7f;
            op->pz = op->pz - njCos((unsigned short)op->ay) * 0.7f;
        }

        op->tv[0].col = 0xFFA0A0FF;
        op->tv[1].col = 0xFFA0A0FF;
        op->tv[2].col = 0xFFA0A0FF;
        op->tv[3].col = 0xFFA0A0FF;
        op->tv[0].u = uvp->u / 256.0f;
        op->tv[0].v = uvp->v / 256.0f;
        op->tv[1].u = (uvp->u + uvp->sx - 1) / 256.0f;
        op->tv[1].v = op->tv[0].v;
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = (uvp->v + uvp->sy - 1) / 256.0f;
        op->tv[3].u = op->tv[1].u;
        op->tv[3].v = op->tv[2].v;
        op->sx = (op->sxb * uvp->sx) / 32.0f;
        op->sy = (op->syb * uvp->sy) / 32.0f;

        if (sys->ef_trsn < 512) {
            sys->ef_trs[sys->ef_trsn] = op;
            sys->ef_trsn++;
        }
    }
}

// 100% matching!
void bhEne21_SetMarkEff(BH_PWORK* epw)
{
    int eno;

    sys->ef.id = 396;
    sys->ef.flg = 1;
    sys->ef.type = 0;
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    sys->ef.px = epw->mlwP->owP->mtx[12];
    sys->ef.py = epw->mlwP->owP->mtx[13] + 0.1f;
    sys->ef.pz = epw->mlwP->owP->mtx[14];
    sys->ef.ay = epw->ay;
    sys->ef.ax = NJM_DEG_ANG(90.0f);

    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    if (eno != -1) {
        eff[eno].stflg |= 0x20;
        eff[eno].txp[0] = epw->mlwP->texP;
        eff[eno].tex_id = 6;
    }
}

// 100% matching!
void bhEff_E21_Mark(O_WRK* op)
{
    static EN21UV uvinfo0[12] = {
        {  0,   0, 55, 55},
        { 55,   0, 55, 55},
        {110,   0, 55, 55},
        {165,   0, 55, 55},
        {  0,  55, 55, 55},
        { 55,  55, 55, 55},
        {110,  55, 55, 55},
        {165,  55, 55, 55},
        {  0, 110, 55, 55},
        { 55, 110, 55, 55},
        {110, 110, 55, 55},
        { -1,   0,  0,  0}
    };
    EN21UV* uvp;

    switch (op->mode0)
    {
    case 0:
        op->bl_src = 11;
        op->bl_dst = 3;
        op->ct0 = 0;
        op->ct1 = 33;
        op->ct2 = 0;
        op->flg |= 0x80000;
        op->stflg |= 0x20;
        op->sxb = op->sx;
        op->syb = op->sy;
        op->mode0 = 1;
        // Fallthrough
    case 1:
        op->ct1--;
        if (op->ct1 < 0)
        {
            op->flg = 0;
            break;
        }

        if ((op->ct1 % 3) == 0)
        {
            op->ct2++;
        }

        uvp = &uvinfo0[op->ct2];

        op->tv[0].col = 0x40808080;
        op->tv[1].col = 0x40808080;
        op->tv[2].col = 0x40808080;
        op->tv[3].col = 0x40808080;
        op->tv[0].u = uvp->u / 256.0f;
        op->tv[0].v = uvp->v / 256.0f;
        op->tv[1].u = (uvp->u + uvp->sx - 1) / 256.0f;
        op->tv[1].v = op->tv[0].v;
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = (uvp->v + uvp->sy - 1) / 256.0f;
        op->tv[3].u = op->tv[1].u;
        op->tv[3].v = op->tv[2].v;
        op->sx = (op->sxb * uvp->sx) / 32.0f;
        op->sy = (op->syb * uvp->sy) / 32.0f;

        if (sys->ef_trsn < 512) {
            sys->ef_trs[sys->ef_trsn] = op;
            sys->ef_trsn++;
        }
    }
}
