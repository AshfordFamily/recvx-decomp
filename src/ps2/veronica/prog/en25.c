#include "../../../ps2/veronica/prog/en25.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Ceiling Trap

static BP_WORK BloodParam = {
    {0.0f, 0.2f, 0.0f},
    0,
    0.0f,
    0.3f,
    {0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0, 0, 0, 0}
};

void (*bhEne25_Mode0[6])(BH_PWORK*) = {
    bhEne25_Init,
    bhEne25_Move,
    bhEne25_Nage,
    bhEne25_Damage,
    bhEne25_Die,
    bhEne_Event
};

void (*bhEne25_MoveMode2[4])(BH_PWORK*) = {
    bhEne25_MV00,
    bhEne25_MV01,
    bhEne25_MV02,
    bhEne25_MV03
};

// 100% matching!
void bhEne25(BH_PWORK* epw)
{
    bhEne25_Mode0[epw->mode0](epw);

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    bhCalcModel(epw);

    if (EXP0_UC(0x8) == 1)
    {
        bhEne25_PlayerControl(epw);
    }
}

// 100% matching!
void bhEne25_Init(BH_PWORK* epw)
{
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0xC, 0x8);
        EXP0_ATR(0) = &sys->mwalp[sys->mwal_n++];
        EXP0_ATR(0)->flg |= 0x81;
        EXP0_ATR(0)->type = 0;
        EXP0_ATR(0)->flr_no = 0;
        EXP0_ATR(0)->attr = 2;
        EXP0_ATR(0)->prm0 = EXP0_ATR(0)->prm1 = EXP0_ATR(0)->prm2 = EXP0_ATR(0)->prm3 = 0;
    }

    EXP0_ATR(0)->h = 4.0f;
    EXP0_ATR(0)->py = epw->py - -30.0f;
    EXP0_ATR(0)->w = 14.0f;
    EXP0_ATR(0)->d = 14.0f;
    EXP0_ATR(0)->px = epw->px - 7.0f;
    EXP0_ATR(0)->pz = epw->pz - 7.0f;
    epw->flg |= 0x1;
    epw->flg |= 0x8000;
    epw->flg &= ~0x6;
    epw->ar = 0.0f;
    epw->ah = 0.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->hp = 100;
    EXP0_UC(0x0) = 0;
    EXP0_UC(0x1) = 0;
    EXP0_UC(0x8) = 0;
    epw->mtn_no = 0;
    epw->frm_no = 0;
    epw->hokan_count = 0;
    epw->hokan_rate = 0;
    epw->mtn_add = 0;

    if (epw->type == 0)
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }
    else if (epw->type == 1)
    {
        epw->mode0 = 4;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }

    epw->mdflg |= 0x20;
}

// 100% matching!
void bhEne25_Brain(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne25_Move(BH_PWORK* epw)
{
    float tx;
    float tz;
    float bx;
    float bz;

    tx = epw->px - 6.9f;
    tz = epw->pz - 6.9f;
    bx = epw->px + 6.9f;
    bz = epw->pz + 6.9f;

    if ((plp->px > tx) && (plp->pz > tz) && (plp->px < bx) && (plp->pz < bz))
    {
        EXP0_UC(0x0) = 1;
    }
    else
    {
        EXP0_UC(0x0) = 0;
    }

    tx = epw->px - 6.8f;
    tz = epw->pz - 6.8f;
    bx = epw->px + 6.8f;
    bz = epw->pz + 6.8f;

    if ((plp->px > tx) && (plp->pz > tz) && (plp->px < bx) && (plp->pz < bz))
    {
        EXP0_UC(0x1) = 1;
    }
    else
    {
        EXP0_UC(0x1) = 0;
    }

    if (epw->mode1 == 1)
    {
        bhEne25_Brain(epw);
    }

    if (epw->mode0 == 1)
    {
        bhEne25_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne25_MV00(BH_PWORK* epw)
{
    if ((epw->mode1 == 1) && (EXP0_UC(0x0) == 1))
    {
        epw->mode2 = 1;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne25_MV01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 12;
        epw->mode3++;
        // Fallthrough
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0x10000;
            epw->mode3++;
        }
        break;

    case 2:
        EXP0_ATR(0)->py = epw->mlwP->owP->mtx[13];

        if ((EXP0_UC(0x1) == 1) && ((epw->frm_no >> 0x10) == 6) && (EXP0_UC(0x8) == 0))
        {
            if ((sys->gm_flg & 0x40) && (sys->st_flg & 0x800000))
            {
                if ((sys->gm_flg & 0x1000000) == 0)
                {
                    sys->gm_flg &= ~0x40;
                    sys->gm_flg &= ~0x80;
                    sys->gm_flg |= 0x800;
                }

                sys->st_flg &= ~0x800000;
                sys->gm_flg &= ~0x80000;
                sys->pt_flg |= 0x1;
            }

            epw->flg |= 0x2;
            sys->pt_flg &= ~0x1;
            plp->flg &= ~0x18;
            EXP0_UC(0x8) = 1;
            plp->mode0 = 6;
            plp->mode3 = 0;
            plp->hp = -1;
        }

        if ((epw->frm_no >> 0x10) == 9)
        {
            bhEne25_SetEffect(epw);
            StartVibrationEx(1, 0xB);
            CallSystemSe(0, 0x80000202);
        }

        if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            StartVibrationEx(1, 0xB);
            epw->mtn_no = 1;
            epw->frm_no = 0;
            epw->mode3++;
        }
        break;

    case 3:
        if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            epw->ct0 = 15;
            epw->mode3++;
        }
        break;

    case 4:
        if (epw->ct0-- == 0)
        {
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }

}

// 100% matching!
void bhEne25_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;

        CallSystemSe(0, 0x80000203);

        epw->mode3++;
        // Fallthrough
    case 1:
        EXP0_ATR(0)->py = epw->mlwP->owP->mtx[13];

        if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_ATR(0)->py = epw->py - -30.0f;
            epw->mtn_add = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne25_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->hokan_rate = 0;
        epw->mtn_add = 0;
        epw->ct0 = 20;
        epw->mode3++;
        // Fallthrough
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne25_Nage(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne25_Damage(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne25_Die(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne25_SetEffect(BH_PWORK* epw)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        sys->ef.id = 2;
        sys->ef.flg = 0x100001;
        sys->ef.type = 3;
        sys->ef.mdlver = 0;
        sys->ef.flr_no = 0;
        sys->ef.ax = sys->ef.ay = 0;
        sys->ef.sx = 2.0f;
        sys->ef.sy = 2.0f;
        sys->ef.sz = 2.0f;

        sys->ef.px = epw->px - 7.5f + (1.5f * i);
        sys->ef.py = 11.5f;
        sys->ef.pz = epw->pz - 7.5f;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);

        sys->ef.px = epw->px - 7.5f;
        sys->ef.py = 11.5f;
        sys->ef.pz = epw->pz - 7.5f + (1.5f * i);
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);

        sys->ef.px = epw->px + 7.5f - (1.5f * i);
        sys->ef.py = 11.5f;
        sys->ef.pz = epw->pz + 7.5f;
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);

        sys->ef.px = epw->px + 7.5f;
        sys->ef.py = 11.5f;
        sys->ef.pz = epw->pz + 7.5f - (1.5f * i);
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
}

// 100% matching!
void bhEne25_PlayerControl(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    if (plp->mode0 == 6)
    {
        switch (plp->mode3)
        {
        case 0:
            plp->flg &= ~0x40018;
            plp->flg |= 0x10600;
            plp->flg2 |= 0x1;

            pos.x = epw->px + 5.0f;
            pos.y = plp->py;
            pos.z = epw->pz;
            bhEne_BloodPool(epw, &pos, epw->ay, &BloodParam);

            plp->mode3++;
            // Fallthrough
        case 1:
            plp->py = -30.0f;
            plp->mode3++;
            break;

        case 2:
            break;
        }
    }
}
