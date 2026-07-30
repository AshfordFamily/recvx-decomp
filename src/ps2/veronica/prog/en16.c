#include "../../../ps2/veronica/prog/en16.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/effsub2.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

void(*bhEne16_Mode0[6])(BH_PWORK*) =
{
    bhEne16_Init,
    bhEne16_Move,
    NULL,
    NULL,
    NULL,
    bhEne_Event
};

void(*bhEne16_BrainType[1])(BH_PWORK*) =
{
    bhEne16_BR00
};

void(*bhEne16_MoveMode2[3])(BH_PWORK*) =
{
    bhEne16_MV00,
    bhEne16_MV01,
    bhEne16_MV02
};


// 100% matching!
void bhEne16(BH_PWORK* epw)
{
    bhEne16_Mode0[epw->mode0](epw);
    if (epw->type == 0)
    {
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        if (EXP0_I(0) != 0)
        {
            ((char*)EXP0_I(0))[0xC] = 2;
        }
    }
    bhCalcModel(epw);
}

// 100% matching!
void bhEne16_Init(BH_PWORK* epw)
{
    int eff_id;

    if (epw->type == 0)
    {
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 1;
        epw->mode3 = 0;
    } 
    else
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(104, 8);
        sys->ef.id = 270;
        sys->ef.flg = 1;
        sys->ef.type = 0;
        sys->ef.mdlver = 0;
        sys->ef.px = 0.0f;
        sys->ef.py = 0.0f;
        sys->ef.pz = 0.0f;
        sys->ef.sx = 0.0f;
        sys->ef.sy = 0.0f;
        sys->ef.sz = 0.0f;
        sys->ef.ay = 0;
        eff_id = bhSetEffectTb(&sys->ef, NULL, (unsigned char*)epw, 0);
        if (eff_id >= 0)
        {
            EXP0_I(0) = (int)&eff[eff_id];
            ((char*)EXP0_I(0))[0xC] = 0;
            bhEff_E16_LaserSight((O_WRK*)((char*)EXP0_I(0)));
        }
    }
    epw->mdflg |= 1;
    epw->flg |= 0x8000;
    epw->ct0 = 45;
}

// 100% matching!
void bhEne16_Brain(BH_PWORK* epw)
{
    bhEne16_BrainType[0](epw);
}

// 100% matching!
void bhEne16_BR00(BH_PWORK* epw)
{
    ATR_WORK* hp;
    
    hp = bhCheckFloorEnemy(plp->flr_no, plp->px, plp->pz);
    
    if ((hp != NULL) && ((hp->prm0 == 16)))
    {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
    else
    {
        epw->mode2 = 0;
        return;
    }

}

// 100% matching!
void bhEne16_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne16_Brain(epw);
    }
    bhEne16_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne16_MV00(BH_PWORK* epw)
{
    if (EXP0_I(0) != 0)
    {
        ((char*)EXP0_I(0))[0xC] = 1;
    }
}

// 100% matching!
void bhEne16_MV01(BH_PWORK* epw)
{
    if (EXP0_I(0) != 0)
    {
        ((char*)EXP0_I(0))[0xC] = 2;
    }
}

// 99.92% matching
void bhEne16_MV02(BH_PWORK* epw)
{
    O_WORK* owp; // r2
	int ax; // r2
	int ay; // r16
	float mov; // r29+0xC0
	float spd; // r20
	float spd_now; // r29+0xC0
	NJS_VECTOR v; // r29+0xA0
	NJS_POINT3 pos; // r29+0xB0
	ATR_WORK* hp; // r16   
    GA_WORK gap; // r29+0x50

    // not present in DWARF
    float dx, dy, dz;
    

    switch (epw->mode3) {
    case 0:       
        if ((BH_PWORK*)EXP0_I(0x0) != NULL)
        {
            ((BH_PWORK*)EXP0_I(0x0))->mode0 = 2;
        }
        epw->ct0 = 30;
        epw->ct1 = 7;
        epw->flg |= 0x80000;
        owp = plp->mlwP->owP;
        epw->xn = owp[3].mtx[12] + 20.0f * owp[3].mtx[8];
        epw->yn = owp[3].mtx[13] + 20.0f * owp[3].mtx[9];
        epw->zn = owp[3].mtx[14] + 20.0f * owp[3].mtx[10];
        epw->aox = 0.0f;
        epw->aoy = 0.0f;
        epw->aoz = 0.0f;
        EXP0_I(0x64) = 0;
        epw->mode3++;
        break;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode3++;
        }
        break;
    case 2:
        if (njScalor((NJS_VECTOR*)&epw->aox) < 0.5f)
        {

            if (((BH_PWORK*)EXP0_I(0x0) != NULL) && (((BH_PWORK*)EXP0_I(0x0))->ct0 > 0))
            {
                epw->ct0 = 30;
                epw->mode3++;
            }
        }
        break;
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mode3++;
        }
        break;
    case 4:
        if (epw->ct1 != 0)
        {
            epw->ct1--;
            bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 74497);

            if (((BH_PWORK*)EXP0_I(0x0) != NULL) && ((int)((BH_PWORK*)EXP0_I(0x3D4)) > 0) && !(plp->stflg & 0x30))
            {
                plp->dvx = epw->xn - epw->px;
                plp->dvy = epw->yn - epw->py;
                plp->dvz = epw->zn - epw->pz;

                bhEne_SetBloodEffectBurst(plp, 2, ((BH_PWORK*)EXP0_I(0x0))->ct0, (NJS_POINT3*)&((BH_PWORK*)EXP0_I(0x0))->gpx, 1);
                if (150 < plp->hp)
                {
                    plp->hp -= plp->hp / 2;

                } 
                else if (50 < plp->hp)
                {
                    plp->hp -= plp->hp / 3;
                } 
                else
                {
                    plp->hp = -1;
                }
                if (plp->hp >= 0)
                {
                    plp->flg |= 4;
                    plp->mode0 = 2;
                    plp->mode1 = bhEne_DGDirCheck(plp);
                    plp->mode2 = 1;
                    plp->mode3 = 0;
                } 
                else
                {
                    epw->ct1 = 0;
                }
            } 
            else
            {
                hp = (ATR_WORK*)(BH_PWORK*)EXP0_I(0x2F0); 
                if ((hp != NULL) && (bhCheckWallAttrB89(hp) != 0))
                {
                    v.x = epw->px - epw->xn;
                    v.y = epw->py - epw->yn;
                    v.z = epw->pz - epw->zn;
  
                    pos.x = (*(BH_PWORK**)epw->exp0)->lox;
                    pos.y = (*(BH_PWORK**)epw->exp0)->loy;
                    pos.z = (*(BH_PWORK**)epw->exp0)->loz;
                    bhSetEffGunSpark(&pos, &v, 0xFFF8F8A0U, 0x4CE04010U, WpnTab[13].hiteff - 4);
                    gap.wpn_no = 0xD;
                    gap.ay = bhArcTan2(v.x, v.z);
                    bhSetGunSplash(&gap, &pos, hp->prm0);
                }
            }
            epw->aox += 1.5f * epw->mlwP->owP->mtx[4];
            epw->aoy += 1.5f * epw->mlwP->owP->mtx[5];
            epw->aoz += 1.5f * epw->mlwP->owP->mtx[6];
            epw->dpx = epw->xn;
            epw->dpy = epw->yn;
            epw->dpz = epw->zn;
            epw->flg &= ~0x80000;
            epw->mode3++;
            epw->ct0 = 0;
        }
        break;
    case 5:
        epw->ct0++;
        if (epw->ct0 < 3)
        {
            epw->aox *= 0.7f;
            epw->aoy *= 0.7f;
            epw->aoz *= 0.7f;
        } 
        else if (epw->ct0 == 3)
        {
            epw->xn += 15.0f * epw->mlwP->owP->mtx[4];
            epw->yn += 15.0f * epw->mlwP->owP->mtx[5];
            epw->zn += 15.0f * epw->mlwP->owP->mtx[6];
        } 
        else if (epw->ct0 < 30)
        {
            epw->aox += (epw->dpx - epw->xn) / 32.0f;
            epw->aoy += (epw->dpy - epw->yn) / 32.0f;
            epw->aoz += (epw->dpz - epw->zn) / 32.0f;
            spd = njScalor((NJS_VECTOR*)&epw->aox);
            mov = spd + (0.1f * (0.6f - spd));
            njUnitVector((NJS_VECTOR*)&epw->aox);
            epw->aox *= mov;
            epw->aoy *= mov;
            epw->aoz *= mov;
        } 
        else if (epw->ct1 != 0)
        {
            epw->flg |= 0x80000;
            epw->mode3 = 2;
        } else
        {

            if ((BH_PWORK*)EXP0_I(0x0) != NULL)
            {
                ((BH_PWORK*)EXP0_I(0x0))->mode0 = 1;
            }
            epw->mode3 = 6;
            epw->ct0 = 0x5A;
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
        }
        break;
    case 6:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
        }
        break;
    }
    if (epw->flg & 0x80000)
    {
        owp = plp->mlwP->owP;
        epw->aox += (owp[3].mtx[12] - epw->xn) / 32.0f;
        epw->aoy += ((1.5f + owp[3].mtx[13]) - epw->yn) / 32.0f;
        epw->aoz += (owp[3].mtx[14] - epw->zn) / 32.0f;

        dx = owp[3].mtx[12] - epw->xn;
        dz = owp[3].mtx[14] - epw->zn;
        
        if (njSqrt(dx * dx + dz * dz) < 30.0f) {
            if (plp->hp < 30)
            {
                spd = 0.6f;
            } 
            else if (plp->hp < 120)
            {
                spd = 0.65f;
            } 
            else
            {
                spd = 0.7f;
            }
            mov = njScalor((NJS_VECTOR*)&epw->aox);
            if (mov > spd)
            {
                mov = mov + (0.1f * (spd - mov));
                njUnitVector((NJS_VECTOR*)&epw->aox);
                epw->aox *= mov;
                epw->aoy *= mov;
                epw->aoz *= mov;
            }
        }

        if (((BH_PWORK*)EXP0_I(0x0) != NULL) && (((BH_PWORK*)EXP0_I(0x0))->ct0 > 0))
        {
            epw->aox *= 0.7f;
            epw->aoy *= 0.7f;
            epw->aoz *= 0.7f;
        }
    }
    epw->xn += (epw->aox + (0.3f * njRandom())) - 0.15f;
    epw->yn += (epw->aoy + (0.3f * njRandom())) - 0.15f;
    epw->zn += (epw->aoz + (0.3f * njRandom())) - 0.15f;

    dx = epw->xn - epw->px;
    dy = epw->yn - epw->py;
    dz = epw->zn - epw->pz;
    
    ay = bhArcTan2(-dx, -dz);
    ax = bhArcTan2(dy, njSqrt(dx * dx + dz * dz));
    epw->mlwP->objP->ang[1] = ay;
    epw->mlwP->objP->ang[0] = ax;
}

// 100% matching!
int bhEne16_GetEffNum(BH_PWORK* epw)
{
    return EXP0_I(0x64);
}

// 100% matching!
NJS_POINT3* bhEne16_GetEffPos(BH_PWORK* epw)
{
    return &EXP0_P3(0);
}

// 100% matching!
void bhEne16_AddEffPos(BH_PWORK* epw, NJS_POINT3* pos)
{
    int i;
    
    for (i = EXP0_I(0x64); i > 0; i--)
    {
        EXP0_P3(i) = *(&EXP0_P3(i) - 1);
    }

    EXP0_P3(0) = *pos;

    if (EXP0_I(0x64) < 7)
    {
        EXP0_I(0x64)++;
    }
    
}
