#include "../../../ps2/veronica/prog/en24.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/eneset.h"

float DeadRate[19] = 
{
    0.0f, 
    0.0f, 
    1.0f, 
    1.0f,
    1.0f,
    1.0f,
    1.0f, 
    1.0f, 
    0.3f, 
    1.0f, 
    0.0f, 
    0.3f, 
    1.0f, 
    1.0f, 
    1.0f, 
    1.0f, 
    1.0f, 
    1.0f, 
    1.0f  
};

CPCL CapColTab[3] =
{
    { 0, 0, 5 },
    { 0, 2, 0 },
    { 0, 0, 0 }
};

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*BrainType_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne24_Mode0[7] =
{
    bhEne24_Init,
    bhEne24_Move,
    bhEne24_Nage,
    bhEne24_Damage,
    bhEne24_Die,
    bhEne_Event,
    bhEne24_Dummy
};

BrainType_proc bhEne24_BrainType[1] =
{
    bhEne24_BR00
};

MoveMode2_proc bhEne24_MoveMode2[6] = 
{
    bhEne24_MV00,
    bhEne24_MV01, 
    bhEne24_MV02,
    bhEne24_MV03,
    bhEne24_MV04, 
    bhEne24_MV05
};

// 100% matching!
void bhEne24(BH_PWORK* epw)
{
    BH_PWORK* ep;
    
    if (epw->mode0 != 6)
    {
        bhEne24_Mode0[epw->mode0](epw);
        bhEne24_CollisionLine(epw);
        if (epw->flg & 0x10)
        {
            bhEne24_CollisionWalls(epw);
        }
        bhCalcModel(epw);
        
        epw->watr.c1.x = epw->px;
        epw->watr.c1.y = epw->py;
        epw->watr.c1.z = epw->pz;
        
        epw->watr.c2.x = epw->px;
        epw->watr.c2.y = epw->py;
        epw->watr.c2.z = 1.0f + epw->pz;
        
        epw->watr.r = 2.0f;
        
        ep = (BH_PWORK*)epw->lkwkp;
        if (ep != NULL && epw->flg & 0x80000)
        {
            if (3 < epw->frm_no)
            {
                epw->frm_no = 0;
            }
            epw->mlwP = &ep->mdl[epw->frm_no + 2];
            epw->frm_no++;
        }
    }
}

// 100% matching!
void bhEne24_Init(BH_PWORK* epw)
{
    epw->flg |= 0x8010;
    epw->flg &= ~0x26;
    
    epw->mdflg |= 5;
    
    epw->ar = 1.2f;
    epw->ah = 1.2f;
    
    epw->car = 1.2f;
    epw->cah = 1.2f;
    
    epw->hp = 2;
    
    epw->flg2 |= 0x10;
    
    epw->mode0 = 6;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(72, 8);
    }
    EXP0_UC(0x20) = 0;
    EXP0_I(0) = 1148829696;
    EXP0_I(0x4) = 0;
    EXP0_I(0x8) = 0;
    EXP0_I(0xC) = 0;
    EXP0_I(0x10) = 0;
    
    epw->clp_jno[0] = 0;
    epw->clp_jno[1] = -1;
    
    epw->mdflg &= ~0x20;
    
    epw->cpcl = CapColTab;
    
    EXP0_I(0x24) =(int)(30.0f * njRandom()) + 30;
}

// 100% matching!
void bhEne24_Brain(BH_PWORK* epw)
{
    bhEne24_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne24_BR00(BH_PWORK* epw)
{
    EXP0_F(0) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);
    
    if (bhSearchPlayer(epw, 10922) == -1)
    {
        EXP0_UC(0x20) = 0;
    } 
    else
    {
        EXP0_UC(0x20) = 1;
    }
    
    if ((plp->stflg & 0x80000000) || (plp->flg & 0x4) || (epw->flg & 0x4))
    {
        return;
    }

    if (EXP0_I(0x24))
    {
        EXP0_I(0x24)--;
        return;
    }

    if (EXP0_UC(0x20) == 0)
    {
        return;
    }

    if (EXP0_F(0) >= 5.0F)
    {
        return;
    }

    epw->mode1 = 0;
    epw->mode2 = 4;
    epw->mode3 = 0;

    EXP0_I(0x24) = (int)(30.0F * njRandom()) + 30;
}

// 100% matching!
void bhEne24_Move(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    
    if (epw->mode1 == 1)
    {
        bhEne24_Brain(epw);
    }
    
    if ((plp->mode0 == 1) && (epw->flg & 0x20) && bhEne24_DeadCheck(epw))
    {
        epw->flg |= 2;
    }
    
    if (epw->flg & 4)
    {
        epw->flg &= ~4;
        if (epw->hp > 0)
        {
            if (njRandom() < DeadRate[epw->wpnr_no])
            {
                epw->flg |= 2;
            }
            epw->hp -= 1;
        } 
        else
        {
            epw->flg |= 2;
        }
    }
    
    if (epw->flg & 2)
    {
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74497);
        
        epw->dvx = 0.0f;
        epw->dvy = 1.0f;
        epw->dvz = 0.0f;
        
        pos.x = epw->px;
        pos.y = 1.0f + epw->py;
        pos.z = epw->pz;
        
        bhEne_SetBloodEffect4(&pos, (NJS_POINT3*)&epw->dvx, 1, 0, 0);
        
        sys->ef.id = 303;
        sys->ef.flg = 1;
        sys->ef.type = 1;
        
        sys->ef.px = epw->px;
        sys->ef.py = epw->py;
        sys->ef.pz = epw->pz;
        
        sys->ef.sx = 2.0f;
        sys->ef.sy = 2.0f;
        sys->ef.sz = 2.0f;
        
        sys->ef.ax = 0;
        sys->ef.ay = epw->ay;
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        epw->mdflg |= 1;
        
        epw->mode0 = 4;
        epw->mode2 = 0;
        epw->mode3 = 0;
        return;
    }
    bhEne24_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne24_MV00(void)
{

}

// 100% matching!
void bhEne24_MV01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x80000;
        epw->flg |= 0x20;
        epw->ct0 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = (njRandom() > 0.5f) ? 2 : 3;
            epw->mode3 = 0;
        }

    }
}

// 100% matching!
void bhEne24_MV02(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    { 
    case 0:
        epw->ct0 = (int)(30.0f * njRandom()) + 60;
        
        epw->ct1 = (njRandom() < 0.5f) ? -1 : 1;
        
        epw->ct2 = (int)(20.0f + (20.0f * njRandom()) - (20.0f * njRandom()));
        
        epw->spd = 0.3f;
        
        epw->flg |= 0x80000;
        
        epw->way = (njRandom() > 0.5f) ? 273 : -273;
        
        epw->flg |= 0x20;
        epw->mode3++;

    case 1:
        bhAddSpeed(epw, 0);
        
        if (EXP0_UC(0x20) == 1) 
        {
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 455);
        }
        
        pos.x = epw->px - (5.0f * njSin(epw->ay));
        pos.y = epw->py;
        pos.z = epw->pz - (5.0f * njCos(epw->ay));
        
        if (bhCheckWallType(&pos, 0, 1.0f, 1.0f))
        {
            epw->ay += epw->way;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        
        if ((epw->py > bhGetGroundPosition((NJS_POINT3*)&epw->px)))
        {
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }

    }
    epw->ct2--;
    if (epw->ct2 < 0)
    {
        bhEne_CallSE(epw, (NJS_POINT3*) &epw->px, 74496);
        epw->ct2 = (int)(40.0f + (40.0f * njRandom()));
    }
}

// 100% matching!
void bhEne24_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->way = (njRandom() > 0.5f) ? 273 : -273;
        
        epw->ct0 = (int)(45.0f * njRandom()) + 15;
        
        epw->flg |= 0x80000;
        
        epw->mode3++;

    case 1:
        epw->ay += epw->way;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne24_MV04(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->flg |= 0x100000;
        
        EXP0_F(0x14) = 0.6f * -njSin(epw->ay);
        EXP0_F(0x18) = 2.5f;
        EXP0_F(0x1C) = 0.6f * -njCos(epw->ay);
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x20;
        
        epw->mode3++;

    case 1:
        if (epw->flg & 0x100000)
        {
            epw->px += EXP0_F(0x14);
            epw->py += EXP0_F(0x18);
            epw->pz += EXP0_F(0x1C);
            EXP0_F(0x18) -= 0.33f;
            
            if (!(plp->flg & 4))
            {
                if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000) && (plp->hp >= 0) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&epw->px, 2.0f)))
                {
                    plp->flg |= 0x10004;
                    plp->stflg |= 0x10000;
                    
                    plp->hp -= 1;
                    if (plp->hp < 0)
                    {
                        plp->hp = 0;
                    }
                    plp->mode0 = 2;
                    plp->mode1 = 0;
                    plp->mode2 = 0;
                    plp->mode3 = 0;
                    
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
                    bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&EXP0_UC(0x14), 0, 9, 1);
                    EXP0_F(0x14) *= -1.0f;
                    EXP0_F(0x1C) *= -1.0f;
                    epw->ay += 32768;
                    break;
                }
            }
        } 
        else
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->flg |= 0x20;
        }
    }
}

// 100% matching!
void bhEne24_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x100000;
        epw->flg &= ~0x80000;
        epw->flg &= ~0x20;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x100000)
        {
            epw->px += epw->xn;
            epw->py += epw->yn;
            epw->pz += epw->zn;
            epw->yn -= 0.33f;
            break;
        }
        epw->flg |= 0x20;
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne24_Nage(void)
{

}

// 100% matching!
void bhEne24_Damage(void)
{

}

// 100% matching!
void bhEne24_Die(void)
{

}

// 100% matching!
void bhEne24_Dummy(void)
{

}

// 100% matching!
void bhEne24_CollisionWalls(BH_PWORK* epw)
{
    epw->py += epw->ar;
    bhEne03_Collision(epw);
    epw->py -= epw->ar;
}

// 100% matching!
void bhEne24_CollisionLine(BH_PWORK* epw)
{
    ATR_WORK* hp;
	NJS_POINT3 n;
    
    if ((epw->flg & 0x100000) && (hp = bhCollisionCheckLine((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px), hp != NULL))
    {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        if (n.y > 0.99f)
        {
            epw->flg &= ~0x100000;
        }
    }
}

// 100% matching!
int bhEne24_DeadCheck(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_VECTOR vec;
    int ang;
    int w;
    float mov;
    O_WORK* owk;
    int i;
    int joint[2] = { 17, 21 };

    for (i = 0; i < 2; i++)
    {
        owk = &plp->mlwP->owP[joint[i]];

        pos.x = owk->mtx[12];
        pos.y = owk->mtx[13];
        pos.z = owk->mtx[14];

        vec.x = EXP0_P3_X(i) - pos.x;
        vec.y = EXP0_P3_Y(i) - pos.y;
        vec.z = EXP0_P3_Z(i) - pos.z;  

        mov = njScalor(&vec);

        w = bhArcTan2(owk->mtx[8], owk->mtx[10]);
        
        ang = (short)(w - EXP0_ANG(i));
        if (ang < 0)
        {
            ang = -ang;
        }
        
        EXP0_P3_X(i) = pos.x;
        EXP0_P3_Y(i) = pos.y;
        EXP0_P3_Z(i) = pos.z;
        
        EXP0_ANG(i) = w;

        if ((mov > 0.05f || 182 < ang) && (njDistanceP2P((NJS_POINT3*)&epw->px, &pos) < 2.0f))
        {
            return 1;            
        }
    }
    return 0;
}
