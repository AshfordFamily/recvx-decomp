#include "../../../ps2/veronica/prog/en01sub.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/weapon.h"
#include "../../../ps2/veronica/prog/zonzon.h"

void (*bhEne01Parent_Mode0[2])(BH_PWORK*) =
{
	bhEne01Parent_Init,
	bhEne01Parent_Move
};
void (*bhEne01Arm_Mode0[4])(BH_PWORK*) =
{
	bhEne01Arm_Init,
	bhEne01Arm_Move,
	NULL,
	bhEne01Arm_Damage
};
void (*bhEne01Arm_DamageMode[2])(BH_PWORK*) =
{
	bhEne01Arm_DG00,
	bhEne01Arm_DG01
};
void (*bhEne01Leg_Mode0[4])(BH_PWORK*) =
{
	bhEne01Leg_Init,
	bhEne01Leg_Move,
	NULL,
	bhEne01Leg_Damage
};
void (*bhEne01Leg_DamageMode[1])(BH_PWORK*) =
{
	bhEne01Leg_DG00
};
void (*bhEne01Head_Mode0[4])(BH_PWORK*) =
{
	bhEne01Head_Init,
	bhEne01Head_Move,
	NULL,
	bhEne01Head_Damage
};
void (*bhEne01Head_DamageMode[1])(BH_PWORK*) =
{
	bhEne01Head_DG00
};
void (*bhEne01Cap_Mode0[4])(BH_PWORK*) = 
{
	bhEne01Cap_Init,
	bhEne01Cap_Move,
	NULL,
	bhEne01Cap_Damage
};
void (*bhEne01Cap_DamageMode[2])(BH_PWORK*) =
{
	bhEne01Cap_DG00,
	bhEne01Cap_DG01
};
void (*bhEne01Worm_Mode0[4])(BH_PWORK*) = 
{
	bhEne01Worm_Init,
	bhEne01Worm_Move,
	NULL,
	NULL
};
void (*bhEne01Worm_MoveMode[3])(BH_PWORK*) =
{
	bhEne01Worm_MV00,
	bhEne01Worm_MV01,
	bhEne01Worm_MV02
};
void (*bhEne01Bom_Mode0[2])(BH_PWORK*) = 
{
	bhEne01Bom_Init,
	bhEne01Bom_Move
};
void (*bhEne01Scope_Mode0[2])(BH_PWORK*) =
{
	bhEne01Scope_Init,
	bhEne01Scope_Move
};

// 100% matching!
void bhEne01Parent(BH_PWORK* epw)
{
	bhEne01Parent_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Parent_Init(BH_PWORK* epw)
{
	epw->stflg = 0;

    epw->flg |= 0x8000;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Parent_Move()
{
	bhEne01Parent_NearestCheck();
	bhEne01Parent_NoKaidanCheck();
}

// 100% matching!
void bhEne01Parent_NearestCheck() 
{
    BH_PWORK* ep, *epp;  
    float dist;    
    int i;         
    
    ep  = ene;
    epp = NULL;
    
    dist = 0;

    for (i = 0; i < sys->ewk_n; i++, ep++) 
    {
        if (((ep->id == 1) && ((ep->flg & 0x1)) && (ep->type != 10)) && (ep->exp0 != NULL) && ((!(ep->stflg & 0x1000000)) && ((!(ep->flg & 0x2)) && (!(ep->flg & 0x80))))) 
        {
            EP_EXP0_I(68) &= ~0x2;
            
            if ((dist > EP_EXP0_F(84)) || (epp == NULL)) 
            {
                dist = EP_EXP0_F(84);
                
                epp = ep;
            }
        }
    }

    if (epp != NULL) 
    {
        ep = epp; 
        
        EP_EXP0_I(68) |= 0x2;
    }
}

// 100% matching!
void bhEne01Parent_NoKaidanCheck() 
{
    static STG_WORK ene_stg_tbl[2] = 
	{
		{  0, 6, 2, 2 },
		{ -1, 0, 0, 0 }
	};
    STG_WORK* stg_p;    
    BH_PWORK* ep_p[10]; 
    BH_PWORK* ep;       
    int i;              
    int n, no;             

    ep = ene;
    
    stg_p = ene_stg_tbl;

    for (i = 0; i < 0xFF; i++, stg_p++) 
    {
        if (stg_p->stg_no == -1) 
        {
            return;
        }
        
        if ((sys->stg_no == stg_p->stg_no) || (sys->rom_no == stg_p->rom_no)) 
        {
            break;
        }
    }

    i = 0;
    n = 0;

    for (no = 0; i < sys->ewk_n; i++, ep++) 
    {
        if (((ep->id == 1) && ((ep->flg & 0x1)) && (ep->type != 10)) && (ep->exp0 != NULL) && ((!(ep->stflg & 0x1000000)) && ((!(ep->flg & 0x2)) && (!(ep->flg & 0x80)))))
        {
            ep->flg &= ~0x200000;
            
            if (ep->flr_no == stg_p->flr_no) 
            {
                n++;
            } 
            else 
            {
                ep_p[no++] = ep; 
            }
        }
    }

    if (n >= stg_p->ene_max)
    {
        for (i = 0; i < no; i++) 
        {
            ep_p[i]->flg |= 0x200000;
        }
    }
}

// 100% matching!
void bhEne01Arm(BH_PWORK* epw)
{
	bhEne01Arm_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Arm_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 2;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0; 
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Arm_Move(BH_PWORK* epw)
{
	bhEne01Arm_MV00();
}

// 100% matching!
void bhEne01Arm_MV00()
{

}

// 100% matching!
void bhEne01Arm_Damage(BH_PWORK* epw)
{
	bhEne01Arm_DamageMode[epw->mode2](epw);
}

// 100% matching!
void bhEne01Arm_DG00(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;         
    BH_PWORK* epp;      
    NJS_POINT3 ps, pd;      
    int i;              

    epp = (BH_PWORK*)epw->lkwkp;
    
    obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
    
    owk = (O_WORK*)EXP0_I(4);

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 0;
        
        epw->mode3++;
    case 1:
        if ((epw->ct0 % 8) == 0) 
        {
            pd.x = 0;
            pd.y = 0;
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
            
            epp->djnt_no = epw->ct3;
            bhEne_SetBlood2(epp, 1, (NJS_POINT3*)&epw->xn, 0);
        }

        owk->mtx[12] += epw->dvx / 10.0f;
        owk->mtx[13] -= 0.1f * epw->ct0;
        owk->mtx[14] += epw->dvz / 10.0f;

        for (i = 0; i < (EXP0_I(8) - 1); i++) 
        {
            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
            
            owk++;
            obj++;
        }

        epw->ct0++;

        owk = (O_WORK*)EXP0_I(4) + (EXP0_I(8) - 1);

        ps.x = epw->py;
        ps.y = 0;
        ps.z = 0;
        
        njCalcPoint(&owk->mtx, &ps, &pd);

        if (pd.y < rom->grand[epw->flr_no + 2]) 
        {
            njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &owk->mtx);
            
            njTranslate((NJS_MATRIX*)&epw->exp0[48], epw->py, 0, 0);
            
            EXP0_F(100) = rom->grand[epw->flr_no + 2];
            
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        owk = (O_WORK*)EXP0_I(4) + (EXP0_I(8) - 1);
        
        EXP0_F(100) += 0.2f - (0.08f * epw->ct0);
        
        epw->ct0++;
        
        if (EXP0_F(100) < rom->grand[epw->flr_no + 2]) 
        {
            EXP0_F(100) = rom->grand[epw->flr_no + 2];
        }

        njRotateZ((NJS_MATRIX*)&epw->exp0[48], epw->az);
        njRotateZ(&owk[0].mtx,                 epw->az);
        
        epw->az += epw->ay;

        ps.x = -epw->py;
        ps.y = 0;
        ps.z = 0;
        
        njCalcPoint((NJS_MATRIX*)&epw->exp0[48], &ps, &pd);

        owk[0].mtx[12] = pd.x;
        owk[0].mtx[14] = pd.z;
        owk[0].mtx[13] = pd.y;

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + (EXP0_I(8) - 1);

        for (i = 0; i < (EXP0_I(8) - 1); i++) 
        {
            njSetMatrix(&owk[-1].mtx, &owk[0].mtx);
            
            njRotateXYZ(&owk[-1].mtx, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
            njTranslate(&owk[-1].mtx, -obj->pos[0], -obj->pos[1], -obj->pos[2]);
            
            owk--;
            obj--;
        }

        if (((O_WORK*)EXP0_I(4))[1].mtx[13] < (rom->grand[epw->flr_no + 2] + 1.0f)) 
        {
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        if (owk[0].mtx[13] > -4.0f) 
        {
            owk[0].mtx[13] -= 500.0f;
            
            owk->flg |= 0x100;
            
            epw->ct0++;

            for (i = 0; i < (EXP0_I(8) - 1); i++) 
            {
                njSetMatrix(&owk[1].mtx, &owk[0].mtx);
                
                njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
                njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
                
                owk++;
                obj++;
            }
            
            epw->mode3++;
        }
        
        break;
    case 4:
        break;
    }
}

// 100% matching!
void bhEne01Arm_DG01(BH_PWORK* epw)
{
    BH_PWORK* epp;       
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;        
    NJS_POINT3 pd;      
    int i;               

    epp = (BH_PWORK*)epw->lkwkp;  

    switch (epw->mode3) 
    {
    case 0:
        owk = &plp->mlwP->owP[11];
        
        njSetMatrix(&lcmat[0], &owk->mtx);
        
        njInvertMatrix(&lcmat[0]);
        
        njSetMatrix(&lcmat[1], &((O_WORK*)EXP0_I(4))[2].mtx);
        
        njMultiMatrix(&lcmat[0], &lcmat[1]);
        
        njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &lcmat[0]);

        obj = epw->mlwP->objP;
        
        epw->xn = obj[12].pos[0];
        epw->yn = obj[12].pos[1];
        epw->zn = obj[12].pos[2];

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + (EXP0_I(8) - 1);
        
        obj->ang[0] = obj->ang[1] = obj->ang[2] = 0;

        epw->ct0 = 0;
        epw->ct3 = 0;
        
        epw->mode3++;
    case 1:
        if ((epw->ct3 % 8) == 0) 
        {
            pd.x = 0; 
            pd.y = 0; 
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
            
            epp->djnt_no = 9;
            bhEne_SetBlood2(epp, 1, (NJS_POINT3*)&epw->xn, 0);
        }

        owk = &plp->mlwP->owP[11];
        
        njSetMatrix(&lcmat[0], &owk->mtx);
        
        njTranslate(&lcmat[0], -1.0f, 0.5f, 0);

        owk = (O_WORK*)EXP0_I(4) + (EXP0_I(8) - 1);
        
        njSetMatrix(&owk[0].mtx, &lcmat[0]);
        
        epw->ct0++;

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        if (obj->ang[1] <= 32768) 
        {
            obj->ang[1] += epw->ct0 * 64;
        } 
        else 
        {
            epw->ct0 = 0;
            
            epw->mode3++;
        }

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + (EXP0_I(8) - 1);
        
        for (i = 0; i < (EXP0_I(8) - 1); owk--, obj--, i++)
        {
            njSetMatrix(&owk[-1].mtx, &owk[0].mtx);
            
            njRotateXYZ(&owk[-1].mtx, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
            njTranslate(&owk[-1].mtx, -obj->pos[0], -obj->pos[1], -obj->pos[2]);
        }
        
        break;
    case 2:
        if ((epw->ct3 % 8) == 0) 
        {
            pd.x = 0; 
            pd.y = 0; 
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
            
            epp->djnt_no = 9;
            bhEne_SetBlood2(epp, 1, (NJS_POINT3*)&epw->xn, 0);
        }

        owk = (O_WORK*)EXP0_I(4);
        
        owk[0].mtx[13] -= 0.1f * epw->ct0;
        
        if (owk[0].mtx[13] < (0.5f + rom->grand[epw->flr_no + 2])) 
        {
            owk[0].mtx[13] = 0.5f + rom->grand[epw->flr_no + 2];
            
            epw->ct0 = 0;
            
            epw->mode3++;
        }

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        for (i = 0; i < (EXP0_I(8) - 1); owk++, obj++, i++) 
        {
            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
        }
        
        epw->ct0++;
        break;
    case 3:
        owk = (O_WORK*)EXP0_I(4);
        
        owk[0].mtx[13] += 0.2f - (0.08f * epw->ct0);
        
        if (owk[0].mtx[13] < (0.5f + rom->grand[epw->flr_no + 2])) 
        {
            owk[0].mtx[13] = 0.5f + rom->grand[epw->flr_no + 2];
        }
        
        epw->ct0++;

        njSetMatrix(&lcmat[0], &owk[0].mtx);
        
        njRotateY(&lcmat[0], epw->ct0 * -256);

        ((NJS_CNK_OBJECT*)EXP0_I(0))[1].ang[1] += epw->ct0 * -192;

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        for (i = 0; i < (EXP0_I(8) - 1); obj++, i++) 
        {
            njSetMatrix(&lcmat[i + 1], &lcmat[i]);
            
            njTranslate(&lcmat[i + 1], obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&lcmat[i + 1], obj->ang[0], obj->ang[1], obj->ang[2]);
        }

        if (lcmat[1][13] < (0.5f + rom->grand[epw->flr_no + 2])) 
        {
            ((NJS_CNK_OBJECT*)EXP0_I(0))[1].ang[1] += (epw->ct0 - 1) * 256;
            
            epw->mode3++;
            
            epw->ct0 = 8;
        } 
        else
        {
            njSetMatrix(&owk[0].mtx, &lcmat[0]);
            njSetMatrix(&owk[1].mtx, &lcmat[1]);
            njSetMatrix(&owk[2].mtx, &lcmat[2]);
        }
        
        break;
    case 4:
        owk = (O_WORK*)EXP0_I(4);
        
        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        obj->ang[1] += epw->ct0 * 256;
        
        epw->ct0++;
        
        njSetMatrix(lcmat, &owk->mtx);

        for (i = 0; i < (EXP0_I(8) - 1); obj++, i++) 
        {
            njSetMatrix(&lcmat[i + 1], &lcmat[i]);
            
            njTranslate(&lcmat[i + 1], obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&lcmat[i + 1], obj->ang[0], obj->ang[1], obj->ang[2]);
        }

        if (lcmat[2][13] < (1.0f + rom->grand[epw->flr_no + 2])) 
        {
            ((NJS_CNK_OBJECT*)EXP0_I(0))[1].ang[1] -= (epw->ct0 - 1) * 256;
            
            epw->mode3++;
            
            epw->ct0 = 0;
        } 
        else
        {
            njSetMatrix(&owk[0].mtx, &lcmat[0]);
            njSetMatrix(&owk[1].mtx, &lcmat[1]);
            njSetMatrix(&owk[2].mtx, &lcmat[2]);
        }
        
        break;
    case 5:
        owk = (O_WORK*)EXP0_I(4);
        
        owk->mtx[13] += 0.2f - (0.1f * epw->ct0);

        if (owk->mtx[13] < 0.5f) 
        {
            owk->mtx[13] -= 500.0f;
            
            owk->flg |= 0x100;
            
            epw->mode3++;
        }
        
        epw->ct0++;

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        for (i = 0; i < (EXP0_I(8) - 1); owk++, obj++, i++) 
        {
            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
        }
        
        break;
    case 6:
        break;
    }

    if (epw->mode3 != 6) 
    {
        epw->ct3++;
    }
}

// 100% matching!
void bhEne01Leg(BH_PWORK* epw)
{
	bhEne01Leg_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Leg_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 2;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Leg_Move(BH_PWORK* epw)
{
	bhEne01Leg_MV00();
}

// 100% matching!
void bhEne01Leg_MV00()
{

}

// 100% matching!
void bhEne01Leg_Damage(BH_PWORK* epw)
{
	bhEne01Leg_DamageMode[epw->mode2](epw);
}

// 99.89% matching
void bhEne01Leg_DG00(BH_PWORK* epw)
{
    ATR_WORK* hp;        
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;        
    BH_PWORK* epp;    
    NJS_POINT3 pd;      

    epp = (BH_PWORK*)epw->lkwkp;

    switch (epw->mode3) 
    {
    case 0:
        epw->ct0 = 0;
        
        obj = (NJS_CNK_OBJECT*)EXP0_I(0);
        
        obj[0].ang[0] = obj[0].ang[1] = obj[0].ang[2] = 0;
        obj[1].ang[0] = obj[1].ang[1] = obj[1].ang[2] = 0;

        owk = (O_WORK*)EXP0_I(4) + 1;
        
        njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &owk->mtx);
        
        njTranslate((NJS_MATRIX*)&epw->exp0[48], 0, -1.0f, -2.2f);

        epw->mode3++;
    case 1:
        if ((epw->ct0 % 8) == 0) 
        {
            pd.x = 0;
            pd.y = 0;
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
        }
        
        epw->ct0++;

        owk = (O_WORK*)EXP0_I(4);
        
        pd.x = owk[0].mtx[12];
        pd.y = owk[0].mtx[13] - 1.0f;
        pd.z = owk[0].mtx[14];
        
        hp = bhCheckWallType(&pd, epw->flg, 1.0f, 1.0f);

        if ((hp == NULL) || ((hp != NULL) && (hp->type != 7)))
        {
            owk = (O_WORK*)EXP0_I(4) + 1;
            
            njRotateXYZ((NJS_MATRIX*)&epw->exp0[48], 0, 0, epw->ax);
            njRotateXYZ(&owk[0].mtx,                 0, 0, epw->ax);
            
            epw->ax += epw->wax;
        }

        owk = (O_WORK*)EXP0_I(4);
        
        if (((hp != NULL) && (hp->type == 7)) || (owk[1].mtx[13] > owk[0].mtx[13]))
        {
            owk->mtx[13] += -100.0f;
            
            obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;

            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);

            epw->mode3++;
            break;
        }

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        owk = (O_WORK*)EXP0_I(4) + 1;

        njSetMatrix(&owk[-1].mtx, &owk[0].mtx);
        
        njRotateXYZ(&owk[-1].mtx, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
        njTranslate(&owk[-1].mtx, -obj->pos[0], -obj->pos[1], -obj->pos[2]);
        break;
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Head(BH_PWORK* epw)
{
	bhEne01Head_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Head_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(32, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 0;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Head_Move(BH_PWORK* epw)
{
	bhEne01Head_MV00();
}

// 100% matching!
void bhEne01Head_MV00()
{
	
}

// 100% matching!
void bhEne01Head_Damage(BH_PWORK* epw)
{
	bhEne01Head_DamageMode[epw->mode2](epw);
}

// 99.97% matching
void bhEne01Head_DG00(BH_PWORK* epw) 
{
    ATR_WORK* hp;   
    BH_PWORK* ep;  
    O_WORK* owk;  
    NJS_POINT3 ps, pd; 
    NJS_POINT3 dv, dv2;  
    int i;      
    int tex_id; // not from DWARF

    ep = (BH_PWORK*)epw->lkwkp;
    
    owk = (O_WORK*)EXP0_I(4);

    switch (epw->mode3) 
    {
    case 0:
        epw->px = 2.0f;
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        
        epw->ax = 4096;
        epw->az = 7424;
        
        epw->mode3++;
    case 1:
        if ((epw->ct0++ % 4) == 0)
        {
            ps.x = 0;
            ps.y = 0;
            ps.z = 0;
            
            ep->djnt_no = 11;
            
            ps.y = 1.0f;

            dv2.x = 0;
            dv2.y = 0;
            dv2.z = 0;
            
            tex_id = bhEne01_ChgTextID(ep, 6);
            
            bhEne_SetBlood3(ep, 11, &ps, &dv2, 1, tex_id, 2, 0);

            njUnitMatrix(NULL);
            
            njRotateX(NULL, -13312);

            dv2.x = 0;
            dv2.y = 0;
            dv2.z = -1.0f;
            
            njCalcVector(NULL, &dv2, &dv);

            njUnitMatrix(NULL);
            
            for (i = 0; i < 4; i++) 
            {
                njCalcVector(NULL, &dv, &dv2);
                
                tex_id = bhEne01_ChgTextID(ep, 6);
                
                bhEne_SetBlood3(ep, 11, &ps, &dv2, 1, tex_id, 5, i);
                
                njRotateY(NULL, 16384);
            }
        }

        ps.x =  epw->px * njCos(epw->az);
        ps.y = (epw->px * njSin(epw->az)) - (0.2f * epw->ct1);
        
        epw->ct1++;

        njRotateX(&owk->mtx, epw->ax);         
        
        owk->mtx[12] -= ps.x * njSin(epw->ay);
        owk->mtx[13] += ps.y;
        owk->mtx[14] -= ps.x * njCos(epw->ay);

        pd.x = owk->mtx[12];
        pd.y = owk->mtx[13] - 1.0;
        pd.z = owk->mtx[14];

        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL))
        {
            epw->stflg |= 0x100000;
            
            bhEne01_SePlay(ep, (NJS_POINT3*)&owk->mtx[12], 4871);
            
            bhSetWaterSplash2(epw, (NJS_POINT3*)&owk->mtx[12], 1, 1.1f, 1.1f, 1.1f);
        }

        if ((hp = bhCheckWallRefAngle(&pd, 0, 1.5f, 2.0f, &epw->ay)) != NULL)
        {
            owk->mtx[12] = pd.x;
            owk->mtx[14] = pd.z;
            
            bhEne01_SePlay(ep, (NJS_POINT3*)&owk->mtx[12], 4870);

            if (epw->ct2 < 2) 
            {
                if (hp->type == 7) 
                {
                    owk->mtx[13] = 1.0 + pd.y;

                    ps.x = 0.7 * (epw->px * njCos(epw->az));
                    ps.y = 0.6 * (epw->px * njSin(epw->az));

                    epw->px = njSqrt((ps.x * ps.x) + (ps.y * ps.y));
                    
                    epw->az = 10430.381f * acosf(ps.x / epw->px);
                    
                    epw->ct1 = 0;
                    
                    epw->ax /= 2;
                }
                
                epw->ct2++;
            } 
            else
            {
                owk->mtx[13] -= 500.0f;
                
                owk->flg |= 0x100;
                
                epw->mode3++;
            }

            if (owk->mtx[13] < -10.0f) 
            {
                epw->mode3++;
            }
        }
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Cap(BH_PWORK* epw) 
{
    if ((((O_WRK*)epw->lkwkp)->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
	else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    bhEne01Cap_Mode0[epw->mode0](epw);
    
    bhCalcModel(epw);
}

// 100% matching!
void bhEne01Cap_Init(BH_PWORK* epw)
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    if (!(epw->flg & 0x80)) 
    {
        epw->flg |= 0x80;
        
        epw->px = 0;
        epw->py = 0;
        epw->pz = 0;
        
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 0;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Cap_Move(BH_PWORK* epw)
{
	bhEne01Cap_MV00();
}

// 100% matching!
void bhEne01Cap_MV00()
{

}

// 100% matching!
void bhEne01Cap_Damage(BH_PWORK* epw)
{
	bhEne01Cap_DamageMode[epw->mode2](epw);
}

// 99.91% matching
void bhEne01Cap_DG00(BH_PWORK* epw) 
{
    NJS_POINT3 p[3] = 
	{
		{ 0.0f, -1.200000048f, -1.350000024f },
		{ 0.0f,          0.0f,          0.0f },
		{ 0.0f, -1.200000048f,          1.0f }
	};
    NJS_POINT3 pp[3]; 
    ATR_WORK* hp;    
    O_WORK* owk;     
    float heavy;    
    float wk0, wk1;        
    int ay;          
    int i;            

    switch (epw->mode3)
    {
    case 0:
        owk = epw->mlwP->owP;
        
        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL)) 
        {
            epw->stflg |= 0x100000;
        }
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        
        epw->mode3++;
    case 1:
        owk = epw->mlwP->owP;
        
        wk0 =  epw->dpx * njCos(epw->waz);
        wk1 = (epw->dpx * njSin(epw->waz)) - (0.08f * epw->ct1);

        owk->mtx[12] -= wk0 * njSin(epw->way);
        owk->mtx[13] += wk1;
        owk->mtx[14] -= wk0 * njCos(epw->way);
        
        epw->ct1++;

        for (i = 0; i < 3; i++)
        {
            njCalcPoint(&owk->mtx, &p[i], &pp[i]);
        }

        heavy = pp[epw->waxp].y;

        if ((heavy > pp[0].y) || (heavy > pp[1].y) || (heavy > pp[2].y)) 
        {
            njRotateX(&owk->mtx, epw->wax);
        }

        njTranslate(&owk->mtx, 0, -0.6f, 0);

        pp[0].x = owk->mtx[12];
        pp[0].y = owk->mtx[13] - 0.6f;
        pp[0].z = owk->mtx[14];
        
        ay = epw->way;

        if (bhCheckWallRefAngle(pp, 0x400, 1.0f, 1.2f, &ay) != NULL) 
        {
            if ((owk->mtx[13] - 0.6f) != pp[0].y)
            {
                if (epw->ct0 == 0)
                {
                    wk0 = (epw->dpx * njCos(epw->waz)) * 0.4;
                    wk1 = (epw->dpx * njSin(epw->waz)) * 0.6;
                    
                    epw->dpx = njSqrt((wk0 * wk0) + (wk1 * wk1));
                    
                    epw->waz = 10430.381f * acosf(wk0 / epw->dpx);
                    
                    epw->ct1 = 0;
                    epw->ct0++;
                } 
                else 
                {
                    epw->mode3++;
                }
            }
            
            owk->mtx[12] = pp[0].x;
            owk->mtx[13] = pp[0].y + 0.6f;
            owk->mtx[14] = pp[0].z;
        }

        njTranslate(&owk->mtx, 0, 0.6f, 0);

        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL)) 
        {
            epw->stflg |= 0x100000;
            
            bhSetWaterSplash2(epw, (NJS_POINT3*)&owk->mtx[12], 1, 1.1f, 1.1f, 1.1f);
        }
        
        break;
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Cap_DG01(BH_PWORK* epw) 
{
    ATR_WORK* hp;  
    O_WORK* owk;  
    NJS_POINT3 ps, pd; 
    int ay;        
    float grand_h;

    switch (epw->mode3) 
    {
    case 0:
        epw->dpx = 0.16f;
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        
        epw->wax = 4096;
        epw->waz = 12288;
        
        epw->ax = 32768;
        
        njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &epw->mlwP->owP[0].mtx);

        njTranslate((NJS_MATRIX*)&epw->exp0[48], 0.0f, -1.2f, -1.35f);
        
        epw->waz = 0;
        
        epw->mode3++;
    case 1:
        owk = epw->mlwP->owP;
        
        if (owk->mtx[13] > EXP0_F(100)) 
        {
            njRotateX((NJS_MATRIX*)&epw->exp0[48], -1536);
            njRotateX(&owk->mtx,                   -1536);
        }
        else 
        {
            epw->ct0 = 0;
            
            epw->mode3++;
            break;
        }
        
        ay = epw->ay;
        
        if ((hp = bhCheckWallRefAngle(&pd, 1024, 2.0f, 2.0f, &ay)) != NULL) 
        {
            if ((hp->type == 0) && (hp->type == 2) && (hp->type == 4)) 
            {
                EXP0_F(96)  = pd.x;
                EXP0_F(104) = pd.z;
            } 
            else if (hp->type == 6)
            {
                njRotateX((NJS_MATRIX*)&epw->exp0[48], -1536);
                njRotateX(&owk->mtx,                   -1536);
            }
        }
        
        ps.x = 0;
        ps.y = 1.2f;
        ps.z = 1.35f;
        
        njCalcPoint((NJS_MATRIX*)&epw->exp0[48], &ps, &pd);
        
        owk->mtx[12] = pd.x;
        owk->mtx[14] = pd.z;
        
        grand_h = bhGetGroundPosition((NJS_POINT3*)&owk->mtx[12]);
        
        owk->mtx[13] = pd.y;
        
        if (owk->mtx[13] < (grand_h + 0.2)) 
        {
            owk->mtx[13] = grand_h + 0.4;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (++epw->ct0 > 3) 
        {
            epw->mode3++;
            
            epw->ct0 = 0;
            break;
        }
        
        njRotateX(&epw->mlwP->owP->mtx, -1536);
        break;
    case 3:
        break;
    }
}

// 100% matching!
void bhEne01Worm(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj;

    bhEne01Worm_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (epw->mtn_no == 159) 
    {
        obj = epw->mlwP->objP;
        
        obj->pos[0] = 0;
        obj->pos[2] = 0;
    }
    
    if (!(epw->mdflg & 0x4)) 
    {
        bhCalcModel(epw);
    }
}

// 100% matching!
void bhEne01Worm_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |=  0x8000;
    epw->flg &= ~0x100000;
    
    epw->hokan_rate  = 0;
    epw->hokan_count = 0;
    
    epw->frm_no = 0;
    
    epw->mtn_add = 65536;
    epw->mtn_no  = 168;
    epw->mtn_tp  = NULL;
    epw->mtn_md  = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    if (!(epw->flg & 0x80))
    {
        epw->flg   |= 0x80;
        epw->mdflg |= 0x1;
        
        epw->px = 0;
        epw->py = 0;
        epw->pz = 0;
        
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
    } 
    else if (epw->lkwkp != epw->exp1) 
    {
        epw->mdflg |= 0x1;
        
        epw->lkwkp = epw->exp1;
        
        epw->lox = 0;
        epw->loy = 1.0f;
        epw->loz = 0;
    }
    
    epw->flg &= ~0x2;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Worm_Move(BH_PWORK* epw)
{
	bhEne01Worm_MoveMode[epw->mode2](epw);
}

// 100% matching!
void bhEne01Worm_MV00()
{

}

// 100% matching!
void bhEne01Worm_MV01(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;         
    NJS_POINT3 pos;      

    switch (epw->mode3) 
    {                                     
    case 0:                                                 
        epw->flg   &= ~0x80;
        epw->mdflg &= ~0x1;
        
        if (epw->mode1 == 0) 
        {
            bhEne_ChgMtn(epw, 154, 0, 0);
        } 
        else if (epw->mode1 == 1) 
        {
            bhEne_ChgMtn(epw, 155, 0, 0);
        } 
        else if (epw->mode1 == 2) 
        {
            bhEne_ChgMtn(epw, 156, 0, 0);
        } 
        else 
        {
            bhEne_ChgMtn(epw, 157, 0, 0);
        }
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 74560);
        
        epw->mode3++;
    case 1:                                                 
        ikou(epw, (NJS_POINT3*)&plp->px, 1024);
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            owk = epw->mlwP->owP;
            
            epw->px = owk->mtx[12];
            epw->py = owk->mtx[13];
            epw->pz = owk->mtx[14];
            
            bhEne_ChgMtn(epw, 158, 0, 0);
            
            epw->spd = 3.0f;
            
            bhAddSpeed(epw, 0);
            
            epw->mode3++;
        }
        
        break;
    case 2:                                                 
        pos.x = epw->px;
        pos.y = plp->py;
        pos.z = epw->pz;
        
        if (njDistanceP2P((NJS_POINT3*)&plp->px, &pos) < 5.0f) 
        {
            bhEne_ChgMtn(epw, 159, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkwkp = (unsigned char*)plp;
            epw->lkono = 0;
            
            epw->lox = 0;
            epw->loy = 0;
            epw->loz = 1.870168f;
            
            epw->ax = 0;
            epw->ay = 0;
            epw->az = 0;
            
            epw->mode3++;
            
            plp->mtn_no = 42;
            plp->frm_no = 0;
            
            plp->hokan_count = 5;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            
            plp->flg &= ~0x40000;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            break;
        }
        
        ikou(epw, (NJS_POINT3*)&plp->px, 1024);
        
        epw->spd = 3.0f;
        
        bhAddSpeed(epw, 0);
        break;
    case 3:                                                 
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16851777);
            
            epw->mdflg &= ~0x4;
            epw->flg   &= ~0x80;
            
            pos.x = 0;
            pos.y = 0;
            pos.z = 1.599416f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&epw->px);
            
            epw->ay = plp->ay;
            
            bhEne_ChgMtn(epw, 167, 0, 0);
            
            epw->mode3++;
            
            plp->flg |= 0x4;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 0;
            plp->hokan_rate  = 52428;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 20;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
        }
        
        break;
    case 4:
        if ((epw->frm_no / 65536) == 19) 
        {
            pos.x =  0;
            pos.y = -0.8f;
            pos.z =  0;
            
            epw->djnt_no = 1;
            
            bhEne_SetBlood2(epw, 6, &pos, plp->ay + 32768);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16786242);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 168, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ay = 0;
            
            pos.x =  0.06567f;
            pos.y =  0;
            pos.z = -3.911583f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&plp->px);
            
            PEXP0_F(72) = plp->px;
            PEXP0_F(80) = plp->pz;
            
            obj = plp->mlwP->objP;
            
            obj->pos[0] = obj->pos[2] = 0;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
            
            plp->hp -= 10;
            
            if (plp->hp <= 0) 
            {
                plp->hp = 1;
            }
            
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne01Worm_MV02(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    int frm;

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 90;
        epw->ct1 = 0;
        epw->ct2 = 60;
        
        epw->mode3++;
    case 1:
        epw->ct2 -= bhEne_LeverCheck();
        
        if (((epw->ct1 >= 4) || (epw->ct2 < 0)) && ((((!(plp->flg & 0x4)) && (!(plp->flg & 0x2))) && (!(plp->stflg & 0x80000000))) && (plp->hp >= 0)))
        {
            epw->mdflg &= ~0x4;
            epw->flg   &= ~0x80;
            
            bhEne_ChgMtn(epw, 164, 0, 0);
            
            pos.x = pos.y = 0;
            pos.z = 1.599416f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&epw->px);
            
            epw->ay = plp->ay;
            
            plp->flg |=  0x4;
            plp->flg &= ~0x40000;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 0;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 22;
            
            epw->mode3 = 3;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            break;
        }
        
        if ((--epw->ct0 < 0) && (((((!(plp->flg & 0x4)) && (!(plp->flg & 0x2))) && (!(plp->stflg & 0x80000000))) && (plp->hp >= 0))))
        {
            bhEne_ChgMtn(epw, 163, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0.0f;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ay = 0;
            
            epw->mode3++;
            
            plp->flg |=  0x4;
            plp->flg &= ~0x40000;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 5;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 21;
            
            plp->hp -= 10;
            
            if (plp->hp <= 0)
            {
                plp->hp = 1;
            }
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
        }
        
        break;
    case 2:
        if ((epw->frm_no / 65536) == 1) 
        {
            pos.x = 0;
            pos.y = -0.8f;
            pos.z = 0;
            
            epw->djnt_no = 1;

            bhEne_SetBlood2(epw, 6, &pos, plp->ay + 32768);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16786242);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 168, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ct0 = 90;
            
            epw->mode3 = 1;
            
            epw->ay = 0;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
            
            epw->ct1++;
        }
        
        break;
    case 3:
        frm = epw->frm_no / 65536;
        
        if (frm == 36)
        {
            epw->lkwkp = epw->exp1;
            
            bhEne01_ExpWormEffect(epw);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 9027);
        }
        
        if (frm == 40)
        {
            epw->mdflg |= 0x1;
        }
        
        if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            
            epw->flg |=  0x2;
            epw->flg &= ~0x100000;
            
            epw->mode3++;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
        }
        
        break;
    case 4:
        break;
    }
}

// 100% matching!
void bhEne01Bom(BH_PWORK* epw)
{
    BH_PWORK* ep;
    O_WORK* owk;
    NJS_POINT3 pos;
   
    ep = (BH_PWORK*)epw->lkwkp;
    
    if ((ep->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
    else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    if ((ep->flg & 0x2)) 
    {
        epw->flg &= ~0x20;
    }
    
    bhEne01Bom_Mode0[epw->mode0](epw);
    
    if ((epw->flg & 0x4)) 
    {
        epw->flg &= ~0x4;
    }
    
    bhCalcModel(epw);
    
    owk = epw->mlwP->owP;
    
    pos.x = 0;
    pos.y = 1.0f;
    pos.z = 0;
    
    njCalcPoint(&owk->mtx, &pos, (NJS_POINT3*)&epw->watr.c1);
    
    pos.y = -1.0f;
    
    njCalcPoint(&owk->mtx, &pos, (NJS_POINT3*)&epw->watr.c2);
    
    epw->watr.r = 2.0f;
}

CPCL Ene01BomCapColTab[3] = 
{
	{ 0, 0, 14 },
	{ 0, 0, 0  },
	{ 0, 0, 0  }
};

// 100% matching!
void bhEne01Bom_Init(BH_PWORK* epw) 
{
    BH_PWORK* ep;
    int i;
    
    ep = (BH_PWORK*)epw->lkwkp;
    
    epw->ar = 3.0f;
    epw->ah = 3.0f;
    
    epw->aw = 0;
    epw->ad = 0;
    
    epw->car = 3.0f;
    epw->cah = 3.0f;
    
    epw->stflg = 0;
    
    epw->hp = 1;
    
    for (i = 0; i < 64; i++) 
    {
        epw->dam[i] = 0;
    } 
    
    epw->flg |= 0x8020;
    
    epw->cpcl = Ene01BomCapColTab;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    if (ep->type == 13) 
    {
        epw->mdflg &= ~0x1;
    }
    else 
    {
        epw->mdflg |= 0x1;
        
        epw->flg &= ~0x20;
    }
}

// 100% matching!
void bhEne01Bom_Move(BH_PWORK* epw)
{
    BH_PWORK* ep = (BH_PWORK*)epw->lkwkp;
    NJS_POINT3 pos = { 0.0f, 0.0f, 2.0f }, pos2;
    
    switch (epw->mode3)
    {                             
    case 0:
        if (((epw->flg & 0x4)) && (((epw->wpnr_no != 2) && (epw->wpnr_no != 10)) && ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4)))))
        {
			njCalcPoint(&epw->mlwP->owP->mtx, &pos, &pos2);
			
			if (pos2.y < rom->grand[epw->flr_no + 2]) 
			{
				pos2.y = 1.0f + rom->grand[epw->flr_no + 2];
			}
			
			bhSetExplosion(&pos2);
			
			bhEne01_SePlay(ep, &pos2, 4936);
			
			epw->mdflg |= 0x1;
			
			epw->flg &= ~0x20;
			
			epw->mode3++;
        }
    case 1:
        break;
    }
}

// 100% matching!
void bhEne01Scope(BH_PWORK* epw) 
{
    if ((((O_WRK*)epw->lkwkp)->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
    else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    bhEne01Scope_Mode0[epw->mode0](epw);
    
    bhCalcModel(epw);
    
    bhEne01Scope_Effect(epw); 
}

// 100% matching!
void bhEne01Scope_Init(BH_PWORK* epw)
{
    if (((O_WRK*)epw->lkwkp)->type == 14) 
    {
        epw->mdflg &= ~0x1;
    } 
    else 
    {
        epw->mdflg |=  0x1;
    }
    
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Scope_Move()
{
	
}

// 100% matching!
void bhEne01Scope_Effect(BH_PWORK* epw) 
{
	static NJS_POINT3 scope_ofs[2] = 
	{
		{  0.3f, -0.5f, -1.1f },
		{ -0.3f, -0.5f, -1.1f }
	};
    BH_PWORK* ep;
    int i;
    int eno;
    
    ep = (BH_PWORK*)epw->lkwkp;
    
    if (((epw->mdflg & 0x1)) || ((ep->flg & 0x2))) 
    {
        return;
    }
    
    sys->ef.id   = 355;
    sys->ef.type = 0;
    
    sys->ef.flg = 1;
    
    sys->ef.sx = 0.18f;
    sys->ef.sy = 0.18f;
    sys->ef.sz = 0.18f;
    
    sys->ef.mdlver = 0;
    
    for (i = 0; i < 2; i++) 
    {
        njCalcPoint(epw->mtx, &scope_ofs[i], (NJS_POINT3*)&sys->ef.px);
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if ((eno != -1) || (eno < 512)) 
        {
            eff[eno].ax = 10430.381f * atan2f(epw->mtx[0][6], epw->mtx[0][10]);
            eff[eno].ay = 10430.381f * asinf(-epw->mtx[0][2]);
            eff[eno].az = 10430.381f * atan2f(epw->mtx[0][1], epw->mtx[0][0]);
            
            eff[eno].ct3 = 0;
            
            eff[eno].exp0 = (unsigned char*)ep;
        }
    }
}
