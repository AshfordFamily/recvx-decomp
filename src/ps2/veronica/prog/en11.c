#include "../../../ps2/veronica/prog/en11.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"

// ENEMY: Spotter 

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*BrainType_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne11_Mode0[6] =
{
    bhEne11_Init,
    bhEne11_Move,
    bhEne11_Nage,
    bhEne11_Damage,
    bhEne11_Die,
    bhEne_Event
};

BrainType_proc bhEne11_BrainType[1] =
{
    bhEne11_BR00
};

MoveMode2_proc bhEne11_MoveMode2[10] =
{
    bhEne11_MV00,
    bhEne11_MV01,
    bhEne11_MV02,
    bhEne11_MV03,
    bhEne11_MV04,
    bhEne11_MV05,
    bhEne11_MV06,
    bhEne11_MV07,
    bhEne11_MV08,
    bhEne11_MV09,
};

// 100% matching!
void bhEne11(BH_PWORK* epw)
{
    unsigned int flg;
    NJS_VECTOR v;
    int ang;

    bhEne11_Mode0[epw->mode0](epw);
    
    if (epw->mnwP != epw->mnwPb)
    {
        epw->az = 0;
        epw->ay = 0;
        epw->ax = 0;
        
        flg = epw->flg;
        epw->flg &= ~0x1000;
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        bhCalcModel(epw);
        
        epw->flg = flg;
        epw->flg |= 0x80000;
        return;
    }
    
    if (epw->flg & 0x80000) 
    {
        epw->mtn_no = 0;
        epw->mtn_add = 0;
        epw->frm_no = 0;
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->flg &= 0xFFF7FFFF;
        
        switch (epw->type)
        {
            case 0:
                ang = bhArcTan2(-EXP0_F(0x28), -EXP0_F(0x20));
                
                v.x = 8.0f * njCos(ang);
                v.z = 8.0f * njSin(ang);
                v.y = -fabsf(plp->py - epw->py);
                    
                break;
            
            case 1:
                v.x = 0.0f;
                v.z = 16.0f;
                v.y = -fabsf(plp->py - epw->py);
                
                break;
            
            case 3:
                v.x = 0.0f;
                v.z = -16.0f;
                v.y = -fabsf(plp->py - epw->py);
                
                break;
            
            case 2:
                v.x = 16.0f;
                v.z = 0.0f;
                v.y = -fabsf(plp->py - epw->py);
                
                break;
            
            case 4:
                v.x = -16.0f;
                v.z = 0.0f;
                v.y = -fabsf(plp->py - epw->py);
        }
        
        bhEne11_CameraSet(epw, (NJS_VECTOR* ) &v, 0);
    }
    
    bhEne11_CollisionWalls(epw);
    njUnitMatrix(epw->mtx);
    njTranslate(epw->mtx, epw->px, epw->py, epw->pz);
    njMultiMatrix(epw->mtx, (NJS_MATRIX *) &EXP0_F(0x0));
    bhCalcModel(epw);
}

// 100% matching!
void bhEne11_Init(BH_PWORK* epw)
{
    int eff_id;

    sys->rm_flg &= ~1;
    epw->flg |= 0x1848;
    epw->flg &= ~6;
    epw->ar = 3.5f;
    epw->ah = 1.5f;
    epw->car = 1.0f;
    epw->cah = 1.0f;
    epw->spd = 0.2f;
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x70, 8);
    }
    
    njUnitMatrix((NJS_MATRIX *) &EXP0_F(0x0));
    
    if (epw->type == 0)
    {
        njRotateY((NJS_MATRIX *) &EXP0_F(0x0), epw->ay);
        njRotateZ((NJS_MATRIX *) &EXP0_F(0x0), 0x8000);
    }
    else 
    {
        njRotateY((NJS_MATRIX *) &EXP0_F(0x0), (epw->type - 1) << 0xE);
        njRotateX((NJS_MATRIX *) &EXP0_F(0x0), 0x4000);
        njRotateY((NJS_MATRIX *) &EXP0_F(0x0), epw->ay);
    }
    
    EXP0_UC(0x56) = 0;
    
    if (*(O_WRK **)(epw->exp0 + 0x60) == NULL)
    {
        sys->ef.id = 0x105;
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
        
        eff_id = bhSetEffectTb(&sys->ef, NULL, (unsigned char *)epw, 0);
        
        if (eff_id >= 0)
        {
            *(O_WRK **)(epw->exp0 + 0x60) = &eff[eff_id];
            (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 0;
            
        }
    }
    else 
    {
        (*(O_WRK **)(epw->exp0 + 0x60))->mode0 = 0;
        (*(O_WRK **)(epw->exp0 + 0x60))->ct2 = 0;
    }
    
    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 4;
    epw->clp_jno[2] = -1;
    
    bhEne11_MoveNearWall(epw);
    
    epw->flg |= 0x80000;
}

// 100% matching!
void bhEne11_Brain(BH_PWORK* epw)
{
    bhEne11_BrainType[0](epw);
}

// 100% matching!
void bhEne11_BR00(BH_PWORK* epw)
{
    if ((*(O_WRK **)(epw->exp0 + 0x60))->ct2 != 0)
    {
        EXP0_UC(0x56) = 1;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        if (!(sys->st_flg & 0x2000))
        {
            sys->rm_flg |= 1;
        }
    } 
    else if ((sys->rm_flg & 1) && ((*(O_WRK **)(epw->exp0 + 0x60))->mode0 == 2)) 
    {
        EXP0_UC(0x56) = 1;
        (*(O_WRK **)(epw->exp0 + 0x60))->ct2 = 1;
    }
}

// 100% matching!
void bhEne11_Move(BH_PWORK* epw) 
{
    if (epw->mode1 == 1) 
    {
        bhEne11_Brain(epw);
    }
    
    bhEne11_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne11_MV00(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x1E;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                    return;
                }
                
                epw->mode2 = 6;
            }
    }
}

// 100% matching!
void bhEne11_MV01(BH_PWORK* epw)
{
    NJS_VECTOR v;
    int ang;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = 0;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            
            epw->ay = bhArcTan2(-EXP0_F(0x28), -EXP0_F(0x20));
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            ang = epw->ay + (epw->ct2 * 0x28F);
            
            v.x = 8.0f * njCos(ang);
            v.z = 8.0f * njSin(ang);
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, (NJS_VECTOR* ) &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                }
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan((int)epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->mode3 += 1;
            epw->spd = 0.2f;
        
            /* fallthrough */
        case 1:
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                }
                else 
                {
                    epw->mode2 = 6;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
            else
            {
                bhEne_SetSEPan((int)epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
    }
}

// 100% matching!
void bhEne11_MV03(BH_PWORK* epw) 
{
    NJS_VECTOR v;

    switch (epw->mode3)
    {
        case 0:
            switch (EXP0_I(0x5C))
            {
                case 0:
                    epw->way = 0;
                    epw->ct0 = 0;
                    break;
                
                case 1:
                    epw->way = -0x222;
                    epw->ct0 = 0x1D;
                    bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12301);
                    break;
                
                case 2:
                    epw->way = 0x38E;
                    epw->ct0 = 0x23;
                    bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12301);
                    break;
                
                case 3:
                    epw->way = 0x222;
                    epw->ct0 = 0x1D;
                    bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x12301);
            }
            
            epw->ct1 = 0x10;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            njRotateY((NJS_MATRIX *) &EXP0_F(0x0), epw->way);
            
            if (epw->ct0-- == 0)
            {
                epw->mode1 = 1;
                epw->mode3 = 0;
                
                if (epw->type == 0) 
                {
                    epw->mode2 = 1;
                }
                else 
                {
                    epw->mode2 = 6;
                }
            }
            
            if (epw->type != 0)
            {
                switch (epw->type & 0xFFFF)
                {
                    case 1:
                        v.x = 0;
                        v.z = 16.0f;
                        break;
                    
                    case 3:
                        v.x = 0;
                        v.z = -16.0f;
                        break;
                    
                    case 2:
                        v.x = 16.0f;
                        v.z = 0;
                        break;
                    
                    case 4:
                        v.x = -16.0f;
                        v.z = 0;
                }
                
                v.y = -fabsf(plp->py - epw->py);
                
                bhEne11_CameraSet(epw, (NJS_VECTOR* ) &v, epw->ct1);
                
                if (epw->ct1 != 0)
                {
                    epw->ct1--;
                }
            }
    }
}

// 100% matching!
void bhEne11_MV04(BH_PWORK* epw) 
{
    NJS_VECTOR v;
    float f;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = EXP0_I(0x5C) * 0x19;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            f = 16.0f + (16.0f * njSin(epw->ct2 * 0x28F));
            
            v.x = -EXP0_F(0x20) * f;
            v.z = -EXP0_F(0x28) * f;
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, (NJS_VECTOR *)&v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                }
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan((int)epw, (NJS_VECTOR *)&epw->px, 0x11300);
            }
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV05(BH_PWORK* epw) 
{
    NJS_VECTOR v;
    float f;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 0x19;
            epw->ct2 = 0;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            f = 16.0f + (16.0f * njSin(epw->ct2 * 0x28F));
            
            v.x = EXP0_F(0x10) * f;
            v.z = EXP0_F(0x18) * f;
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, (NJS_VECTOR* ) &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan((int) epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
            
            break;
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV06(BH_PWORK* epw) 
{
	NJS_VECTOR v;
    int ang;

    switch (epw->mode3)
    {
        case 0:
            epw->ct0 = 0x63;
            epw->ct1 = 8;
            epw->ct2 = 0x19;
            epw->ct3 = 0;
            bhEne11_LightControl(epw, 0);
            epw->spd = 0.2f;
            epw->mode3++;
            
            /* fallthrough */
        case 1:
            ang = (int)(16384.0f + (16384.0f * njCos(epw->ct2 * 0x28F)));
            
            switch (epw->type)
            {
                case 1:
                    v.x = 16.0f * njCos(ang);
                    v.z = 16.0f * njSin(ang);
                    break;
                
                case 3:
                    v.x = 16.0f * njCos(ang);
                    v.z = -16.0f * njSin(ang);
                    break;
                
                case 2:
                    v.x = 16.0f * njSin(ang);
                    v.z = 16.0f * njCos(ang);
                    break;
                
                case 4:
                    v.x = -16.0f * njSin(ang);
                    v.z = 16.0f * njCos(ang);
            }
            
            v.y = -fabsf(plp->py - epw->py);
            
            epw->ct2++;
            
            bhEne11_CameraSet(epw, (NJS_VECTOR* ) &v, epw->ct1);
            
            if (epw->ct1 != 0)
            {
                epw->ct1--;
            }
            
            bhEne11_GoFoward(epw);
            
            if (epw->ct0-- == 0)
            {
                EXP0_I(0x5C) = bhEne11_SelectDir(epw);
                
                if (EXP0_I(0x5C) != 0)
                {
                    bhEne11_LightControl(epw, 1);
                    epw->mode1 = 1;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->ct0 = 0x63;
                }
            }
            
            if (ChechPlayEnemySe(sys->enow, 0x11300) == 0) 
            {
                bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
            else 
            {
                bhEne_SetSEPan((int) epw, (NJS_VECTOR* ) &epw->px, 0x11300);
            }
    }
    
    if (EXP0_UC(0x56) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 7;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne11_MV07(BH_PWORK* epw)
{
    switch(epw->mode3)
    {
        case 0:
            bhEne_CallSE(epw, (NJS_VECTOR* ) &epw->px, 0x2302);
            epw->mode3++;
    }
}

// 100% matching!
void bhEne11_MV08(BH_PWORK* epw) 
{
    switch(epw->mode3)
    {
        case 0:
            epw->mode1 = 0;
            bhEne11_LightControl(epw, 1);
            epw->mode3++;
    }
}

// 100% matching!
void bhEne11_MV09(BH_PWORK* epw)
{
    O_WORK* owk;

    owk = &epw->mlwP->owP[1];
    njSetMatrix((NJS_MATRIX *)&EXP0_F(0x0), (NJS_MATRIX *)owk->mtx);
    
    EXP0_I(0x30) = 0;
    EXP0_I(0x34) = 0;
    EXP0_I(0x38) = 0;
    
    owk = epw->mlwP->owP;
    
    epw->px = owk->mtx[0xC] + (3.0f * EXP0_F(0x10));
    epw->py = owk->mtx[0xD] + (3.0f * EXP0_F(0x14));
    epw->pz = owk->mtx[0xE] + (3.0f * EXP0_F(0x18));
    
    owk = &epw->mlwP->owP[2];
    owk->flg |= 2;
    
    owk = &epw->mlwP->owP[3];
    owk->flg |= 2;
    
    epw->mnwP = epw->mnwPb;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    owk = &epw->mlwP->owP[2];
    owk->flg &= ~2;
    
    owk = &epw->mlwP->owP[3];
    owk->flg &= ~2;
    
    bhEne11_MoveNearWall(epw);
    
    if (epw->type == 0) 
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 4;
        epw->mode3 = 1;
        epw->ct0 = 0x96;
        epw->ct1 = 0x20;
        epw->ct2 = 0;
    } 
    else 
    {
        epw->mode0 = 1;
        epw->mode1 = 1;
        epw->mode2 = 6;
        epw->mode3 = 1;
        epw->ct0 = 0x96;
        epw->ct1 = 0x20;
        epw->ct2 = 0;
    }
    
    epw->flg &= 0xFFF7FFFF;
    epw->spd = 0.2f;
    
    bhEne11_GoFoward(epw);
}

// 100% matching!
void bhEne11_Nage() 
{

}

// 100% matching!
void bhEne11_Damage()
{

}

// 100% matching!
void bhEne11_Die() 
{

}

// 100% matching!
void bhEne11_GoFoward(BH_PWORK* epw) 
{
    epw->px -= EXP0_F(0x20) * epw->spd;
    epw->py -= EXP0_F(0x24) * epw->spd;
    epw->pz -= EXP0_F(0x28) * epw->spd;
}

// 100% matching!
void bhEne11_CollisionWalls(BH_PWORK* epw) 
{
	NJS_VECTOR body = { 0.0f, 3.5f, 0.0f };
    NJS_VECTOR vd;

    njCalcVector((NJS_MATRIX *)&EXP0_F(0x0), &body, &vd);
    
    epw->px += vd.x;
    epw->py += vd.y;
    epw->pz += vd.z;
    
    bhEne03_Collision(epw);
    
    if (EXP0_I(0x58) != 0) 
    {
        bhEne11_CollisionBoxEdge2(epw);
    }
    
    epw->px -= vd.x;
    epw->py -= vd.y;
    epw->pz -= vd.z;
}

// 100% matching!
void bhEne11_CollisionBoxEdge2(BH_PWORK* epw)
{
	NJS_POINT3 v;        // r29+0xE0
    NJS_POINT3 p[4];     // r29+0x80
    NJS_POINT3 p2[4];    // r29+0xB0
    float ar;
    int i;

    ar = 1.0f + epw->ar;
        
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    
    njCalcVector((NJS_MATRIX *)&EXP0_F(0x0), (NJS_VECTOR* ) &v, (NJS_VECTOR* ) &v);
    
    switch (bhEne03_GetWallDir((NJS_VECTOR* ) &v)) 
    {
        case 0:
            p[0].x = epw->px - ar;
            p[0].z = epw->pz - ar;
            
            p[1].x = epw->px - ar;
            p[1].z = epw->pz + ar;
            
            p[2].x = epw->px + ar;
            p[2].z = epw->pz - ar;
            
            p[3].x = epw->px + ar;
            p[3].z = epw->pz + ar;
            
            p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
            
            v.x = 0.0f;
            v.y = -ar;
            v.z = 0.0f;
            
            break;
        
        case 1:
            p[0].x = epw->px - ar;
            p[0].z = epw->pz - ar;
        
            p[1].x = epw->px - ar;
            p[1].z = epw->pz + ar;
        
            p[2].x = epw->px + ar;
            p[2].z = epw->pz - ar;
        
            p[3].x = epw->px + ar;
            p[3].z = epw->pz + ar;
        
            p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
        
            v.x = 0.0f;
            v.y = ar;
            v.z = 0.0f;

            break;
            
        case 4:
            p[0].y = epw->py - ar;
            p[0].z = epw->pz - ar;
        
            p[1].y = epw->py - ar;
            p[1].z = epw->pz + ar;
        
            p[2].y = epw->py + ar;
            p[2].z = epw->pz - ar;
        
            p[3].y = epw->py + ar;
            p[3].z = epw->pz + ar;
        
            p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
        
            v.x = ar;
            v.y = 0.0f;
            v.z = 0.0f;

            break;
        
        case 2:
            p[0].y = epw->py - ar;
            p[0].z = epw->pz - ar;
        
            p[1].y = epw->py - ar;
            p[1].z = epw->pz + ar;
        
            p[2].y = epw->py + ar;
            p[2].z = epw->pz - ar;
        
            p[3].y = epw->py + ar;
            p[3].z = epw->pz + ar;
        
            p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
        
            v.x = -ar;
            v.y = 0.0f;
            v.z = 0.0f;

            break;
            
        case 3:
            p[0].x = epw->px - ar;
            p[0].y = epw->py - ar;
        
            p[1].x = epw->px - ar;
            p[1].y = epw->py + ar;
        
            p[2].x = epw->px + ar;
            p[2].y = epw->py - ar;
        
            p[3].x = epw->px + ar;
            p[3].y = epw->py + ar;
        
            p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
        
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = ar;

            break;
            
        case 5:
            p[0].x = epw->px - ar;
            p[0].y = epw->py - ar;
        
            p[1].x = epw->px - ar;
            p[1].y = epw->py + ar;
        
            p[2].x = epw->px + ar;
            p[2].y = epw->py - ar;
        
            p[3].x = epw->px + ar;
            p[3].y = epw->py + ar;
        
            p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
        
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = -ar;

            break;
            
    }

    for (i = 0; i < 4; i++)
    {
        p2[i].x = v.x + p[i].x;
        p2[i].y = v.y + p[i].y;
        p2[i].z = v.z + p[i].z;

        if (bhCollisionCheckLine(&p[i], &p2[i]) == NULL)
        {
            *(ATR_WORK **)(epw->exp0 + 0x58) = bhEne03_GetWall(epw);

            if (*(ATR_WORK **)(epw->exp0 + 0x58) != NULL)
            {
                bhEne03_CollisionBoxEdge(*(ATR_WORK **)(epw->exp0 + 0x58), (NJS_VECTOR* ) &epw->px, epw->ar);
                break;
            }
        }
    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne11_CameraSet(BH_PWORK* epw, NJS_VECTOR* vec, int hcnt)
{
	NJS_CNK_OBJECT *objP;
    NJS_VECTOR v;
    NJS_VECTOR vb;
    NJS_VECTOR ov;
    float out;
    int ang;
    int ax;
    int ay;

    njSetMatrix(NULL, (NJS_MATRIX *)&EXP0_F(0x0));
    njInvertMatrix(NULL);
    
    njCalcVector(NULL, vec, &v);
    
    njUnitVector(&v);
    
    if (hcnt != 0) 
    {
        objP = &epw->mlwP->objP[2];
        
        vb.x = 0;
        vb.y = 0;
        vb.z = -1.0f;
        
        njUnitMatrix(NULL);
        
        njRotateEx(objP[0].ang, 0);
        njRotateEx(objP[1].ang, 0);
        
        njCalcVector(NULL, &vb, &vb);
        
        out = njOuterProduct(&vb, &v, &ov);
        
        njUnitVector(&ov);
        
        ang = (int)(10430.381f * asinf(out)) / hcnt;
        
        njUnitMatrix(NULL);
        njRotate(NULL, &ov, ang);
        njCalcVector(NULL, &vb, &v);
    }
    
    ax = bhArcTan2(-v.x, -v.z);
    ay = bhArcTan2(v.y, njSqrt(v.x * v.x + v.z * v.z));
    
    if (ay < 0) 
    {
        ay = 0;
    }
    
    objP = epw->mlwP->objP;
    objP[2].ang[1] = ax;
    objP[3].ang[0] = ay;
}

#pragma divbyzerocheck off

/*// 

// 
// Start address: 0x1d4f30
void bhEne11_MoveNearWall(BH_PWORK* epw)
{
	_anon3 pt;
	_anon3 vd;
	_anon3 vec;
	// Line 1237, Address: 0x1d4f30, Func Offset: 0
	// Line 1242, Address: 0x1d4f44, Func Offset: 0x14
	// Line 1241, Address: 0x1d4f48, Func Offset: 0x18
	// Line 1242, Address: 0x1d4f4c, Func Offset: 0x1c
	// Line 1243, Address: 0x1d4f54, Func Offset: 0x24
	// Line 1244, Address: 0x1d4f58, Func Offset: 0x28
	// Line 1245, Address: 0x1d4f68, Func Offset: 0x38
	// Line 1247, Address: 0x1d4f78, Func Offset: 0x48
	// Line 1248, Address: 0x1d4f80, Func Offset: 0x50
	// Line 1249, Address: 0x1d4f88, Func Offset: 0x58
	// Line 1247, Address: 0x1d4f8c, Func Offset: 0x5c
	// Line 1251, Address: 0x1d4f90, Func Offset: 0x60
	// Line 1247, Address: 0x1d4f98, Func Offset: 0x68
	// Line 1248, Address: 0x1d4f9c, Func Offset: 0x6c
	// Line 1249, Address: 0x1d4fa8, Func Offset: 0x78
	// Line 1251, Address: 0x1d4fb4, Func Offset: 0x84
	// Line 1252, Address: 0x1d4fc4, Func Offset: 0x94
	// Line 1253, Address: 0x1d4fd4, Func Offset: 0xa4
	// Line 1254, Address: 0x1d4fe0, Func Offset: 0xb0
	// Line 1255, Address: 0x1d4fec, Func Offset: 0xbc
	// Line 1257, Address: 0x1d4ff8, Func Offset: 0xc8
	// Func End, Address: 0x1d5010, Func Offset: 0xe0
}*/

// 
// Start address: 0x1d5010
void bhEne11_LightControl(BH_PWORK* epw, int flg)
{
	// Line 1269, Address: 0x1d5010, Func Offset: 0
	// Line 1272, Address: 0x1d5044, Func Offset: 0x34
	// Line 1273, Address: 0x1d5048, Func Offset: 0x38
	// Line 1272, Address: 0x1d504c, Func Offset: 0x3c
	// Line 1273, Address: 0x1d5054, Func Offset: 0x44
	// Line 1274, Address: 0x1d505c, Func Offset: 0x4c
	// Line 1277, Address: 0x1d5064, Func Offset: 0x54
	// Line 1278, Address: 0x1d506c, Func Offset: 0x5c
	// Line 1281, Address: 0x1d5074, Func Offset: 0x64
	// Line 1282, Address: 0x1d507c, Func Offset: 0x6c
	// Line 1285, Address: 0x1d5084, Func Offset: 0x74
	// Line 1286, Address: 0x1d508c, Func Offset: 0x7c
	// Line 1285, Address: 0x1d5090, Func Offset: 0x80
	// Line 1286, Address: 0x1d5098, Func Offset: 0x88
	// Line 1287, Address: 0x1d50a4, Func Offset: 0x94
	// Line 1290, Address: 0x1d50b0, Func Offset: 0xa0
	// Func End, Address: 0x1d50b8, Func Offset: 0xa8
	scePrintf("bhEne11_LightControl - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x1d50c0
int bhEne11_SelectDir(BH_PWORK* epw)
{
	unsigned char ang;
	_anon3 pos;
	float h;
	int flg[4];
	int dir;
	int i;
	_anon3 p3;
	_anon3 p2;
	_anon3 p1;
	// Line 1300, Address: 0x1d50c0, Func Offset: 0
	// Line 1306, Address: 0x1d50e8, Func Offset: 0x28
	// Line 1307, Address: 0x1d5104, Func Offset: 0x44
	// Line 1312, Address: 0x1d510c, Func Offset: 0x4c
	// Line 1308, Address: 0x1d5114, Func Offset: 0x54
	// Line 1307, Address: 0x1d5118, Func Offset: 0x58
	// Line 1309, Address: 0x1d511c, Func Offset: 0x5c
	// Line 1313, Address: 0x1d5120, Func Offset: 0x60
	// Line 1307, Address: 0x1d5128, Func Offset: 0x68
	// Line 1314, Address: 0x1d512c, Func Offset: 0x6c
	// Line 1315, Address: 0x1d5130, Func Offset: 0x70
	// Line 1307, Address: 0x1d5134, Func Offset: 0x74
	// Line 1308, Address: 0x1d5138, Func Offset: 0x78
	// Line 1309, Address: 0x1d514c, Func Offset: 0x8c
	// Line 1312, Address: 0x1d5160, Func Offset: 0xa0
	// Line 1313, Address: 0x1d5178, Func Offset: 0xb8
	// Line 1314, Address: 0x1d5190, Func Offset: 0xd0
	// Line 1315, Address: 0x1d519c, Func Offset: 0xdc
	// Line 1314, Address: 0x1d51a0, Func Offset: 0xe0
	// Line 1315, Address: 0x1d51a8, Func Offset: 0xe8
	// Line 1316, Address: 0x1d51b8, Func Offset: 0xf8
	// Line 1319, Address: 0x1d51c8, Func Offset: 0x108
	// Line 1316, Address: 0x1d51cc, Func Offset: 0x10c
	// Line 1319, Address: 0x1d51d0, Func Offset: 0x110
	// Line 1316, Address: 0x1d51d4, Func Offset: 0x114
	// Line 1317, Address: 0x1d51e0, Func Offset: 0x120
	// Line 1318, Address: 0x1d51f8, Func Offset: 0x138
	// Line 1319, Address: 0x1d520c, Func Offset: 0x14c
	// Line 1320, Address: 0x1d521c, Func Offset: 0x15c
	// Line 1321, Address: 0x1d5228, Func Offset: 0x168
	// Line 1320, Address: 0x1d5234, Func Offset: 0x174
	// Line 1321, Address: 0x1d5238, Func Offset: 0x178
	// Line 1330, Address: 0x1d5250, Func Offset: 0x190
	// Line 1333, Address: 0x1d5260, Func Offset: 0x1a0
	// Line 1330, Address: 0x1d5264, Func Offset: 0x1a4
	// Line 1333, Address: 0x1d5268, Func Offset: 0x1a8
	// Line 1330, Address: 0x1d526c, Func Offset: 0x1ac
	// Line 1331, Address: 0x1d5278, Func Offset: 0x1b8
	// Line 1332, Address: 0x1d5290, Func Offset: 0x1d0
	// Line 1333, Address: 0x1d52a4, Func Offset: 0x1e4
	// Line 1334, Address: 0x1d52b4, Func Offset: 0x1f4
	// Line 1337, Address: 0x1d52c4, Func Offset: 0x204
	// Line 1334, Address: 0x1d52c8, Func Offset: 0x208
	// Line 1337, Address: 0x1d52cc, Func Offset: 0x20c
	// Line 1334, Address: 0x1d52d0, Func Offset: 0x210
	// Line 1335, Address: 0x1d52dc, Func Offset: 0x21c
	// Line 1336, Address: 0x1d52f4, Func Offset: 0x234
	// Line 1337, Address: 0x1d5308, Func Offset: 0x248
	// Line 1338, Address: 0x1d5318, Func Offset: 0x258
	// Line 1339, Address: 0x1d5324, Func Offset: 0x264
	// Line 1338, Address: 0x1d5330, Func Offset: 0x270
	// Line 1339, Address: 0x1d5334, Func Offset: 0x274
	// Line 1348, Address: 0x1d534c, Func Offset: 0x28c
	// Line 1351, Address: 0x1d535c, Func Offset: 0x29c
	// Line 1348, Address: 0x1d5360, Func Offset: 0x2a0
	// Line 1351, Address: 0x1d5364, Func Offset: 0x2a4
	// Line 1348, Address: 0x1d5368, Func Offset: 0x2a8
	// Line 1349, Address: 0x1d5374, Func Offset: 0x2b4
	// Line 1350, Address: 0x1d538c, Func Offset: 0x2cc
	// Line 1351, Address: 0x1d53a0, Func Offset: 0x2e0
	// Line 1352, Address: 0x1d53b0, Func Offset: 0x2f0
	// Line 1355, Address: 0x1d53c0, Func Offset: 0x300
	// Line 1352, Address: 0x1d53c4, Func Offset: 0x304
	// Line 1355, Address: 0x1d53c8, Func Offset: 0x308
	// Line 1352, Address: 0x1d53cc, Func Offset: 0x30c
	// Line 1353, Address: 0x1d53d8, Func Offset: 0x318
	// Line 1354, Address: 0x1d53f0, Func Offset: 0x330
	// Line 1355, Address: 0x1d5404, Func Offset: 0x344
	// Line 1356, Address: 0x1d5414, Func Offset: 0x354
	// Line 1357, Address: 0x1d5420, Func Offset: 0x360
	// Line 1356, Address: 0x1d542c, Func Offset: 0x36c
	// Line 1357, Address: 0x1d5430, Func Offset: 0x370
	// Line 1366, Address: 0x1d5448, Func Offset: 0x388
	// Line 1369, Address: 0x1d5458, Func Offset: 0x398
	// Line 1366, Address: 0x1d545c, Func Offset: 0x39c
	// Line 1369, Address: 0x1d5460, Func Offset: 0x3a0
	// Line 1366, Address: 0x1d5464, Func Offset: 0x3a4
	// Line 1367, Address: 0x1d5470, Func Offset: 0x3b0
	// Line 1368, Address: 0x1d5488, Func Offset: 0x3c8
	// Line 1369, Address: 0x1d549c, Func Offset: 0x3dc
	// Line 1370, Address: 0x1d54ac, Func Offset: 0x3ec
	// Line 1373, Address: 0x1d54bc, Func Offset: 0x3fc
	// Line 1370, Address: 0x1d54c0, Func Offset: 0x400
	// Line 1373, Address: 0x1d54c4, Func Offset: 0x404
	// Line 1370, Address: 0x1d54c8, Func Offset: 0x408
	// Line 1371, Address: 0x1d54d4, Func Offset: 0x414
	// Line 1372, Address: 0x1d54ec, Func Offset: 0x42c
	// Line 1373, Address: 0x1d5500, Func Offset: 0x440
	// Line 1374, Address: 0x1d5510, Func Offset: 0x450
	// Line 1375, Address: 0x1d551c, Func Offset: 0x45c
	// Line 1374, Address: 0x1d5528, Func Offset: 0x468
	// Line 1375, Address: 0x1d552c, Func Offset: 0x46c
	// Line 1383, Address: 0x1d5544, Func Offset: 0x484
	// Line 1388, Address: 0x1d55a0, Func Offset: 0x4e0
	// Line 1389, Address: 0x1d55ac, Func Offset: 0x4ec
	// Line 1390, Address: 0x1d55b4, Func Offset: 0x4f4
	// Line 1391, Address: 0x1d55cc, Func Offset: 0x50c
	// Line 1392, Address: 0x1d55e4, Func Offset: 0x524
	// Line 1393, Address: 0x1d55e8, Func Offset: 0x528
	// Line 1394, Address: 0x1d55f0, Func Offset: 0x530
	// Line 1396, Address: 0x1d562c, Func Offset: 0x56c
	// Line 1397, Address: 0x1d5630, Func Offset: 0x570
	// Line 1401, Address: 0x1d5644, Func Offset: 0x584
	// Line 1400, Address: 0x1d5648, Func Offset: 0x588
	// Line 1401, Address: 0x1d564c, Func Offset: 0x58c
	// Line 1404, Address: 0x1d5658, Func Offset: 0x598
	// Func End, Address: 0x1d5684, Func Offset: 0x5c4
}*/

