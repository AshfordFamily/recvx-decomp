#include "../../../ps2/veronica/prog/en19.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

// ENEMY: Tyrant T-078 

static void (*bhEne19_Mode0[6])(BH_PWORK*) = 
{ 
	bhEne19_Init,
	bhEne19_Move,
	bhEne19_Damage,
	bhEne19_Die,
	NULL,
	bhEne19_Event
};
static void (*bhEne19_BrainType[3])(BH_PWORK*) = 
{ 
	bhEne19_Br00,
	bhEne19_Br01,
	bhEne19_Br02
};
static TY_DMG_MODE(*bhEne19_CheckDmgLvl[3])(BH_PWORK*, FW_WORK*) = 
{ 
	bhEne19_CheckDmgLvl0,
	bhEne19_CheckDmgLvl1,
	bhEne19_CheckDmgLvl2
};

EA_WORK En19ActTbl[50] =
{
    {  1033,  8,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv08  },
    {  1034,  9,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv09  },
    {  2056,  7,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv07  },
    {  2308,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2309,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2310,  5, 56, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2564,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2565,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2566,  5, 22, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2816,  0,  0, 0, 32,  1.0f, 0x00080020, bhEne19_Mv00  },
    {  2827, 10,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv10  },
    {  2832, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    {  3589,  4, 40, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3599, 14,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv14  },
    {  3845,  4,  4, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3854, 13,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv13  },
    {  4100,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4101,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4102,  5, 26, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  4356,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4357,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4358,  5, 58, 0, 10,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  5124,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  5125,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65024,  0,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv00  },
    { 65028,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04a },
    { 65029,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65030,  5,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65280,  0,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv00  },
    { 65281,  1,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv01  },
    { 65282,  2,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv02  },
    { 65283,  3,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv03  },
    { 65284,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    { 65285,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65286,  5,  0, 0, 12,  1.0f, 0x00080020, bhEne19_Mv05  },
    { 65287,  6,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv06  },
    { 65288,  7,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv07  },
    { 65289,  8,  0, 0,  8, 0.95f, 0x00080020, bhEne19_Mv08  },
    { 65290,  9,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv09  },
    { 65291, 10,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv10  },
    { 65292, 11,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv11  },
    { 65293, 12,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv12  },
    { 65294, 13,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv13  },
    { 65295, 14,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv14  },
    { 65296, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    { 65297, 16,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv16  },
    { 65298, 17,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv17  },
    { 65299, 18,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv18  },
    { 65300, 19,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv19  },
    { 65301, 20,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv20  }
};
COMBWEP_WORK En19CombWepTbl[21] =
{
    {   0, {  0,  0,  0 },   0,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  90, { 10,  0,  0 }, 999, 100 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 190, {  8,  6,  4 }, 300,   0 },
    { 500, { 10, 10, 10 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 300, {  8,  6,  2 }, 400, 200 },
    {  56, { 10,  8,  4 },  80,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    {  10, { 10, 10, 10 },  60,   0 },
    {  60, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  40, { 10, 10, 10 },  60,   0 },
    {   0, {  0,  0,  0 },   0,   0 }
};

static const char FlpTbl[26] =
{
    0, 1, 2, 3, 4, 5, 14, 15, 16, 17, 10, 11, 12, 13, 6, 7, 8, 9, 22, 23, 24, 25, 18, 19, 20, 21
};
static const CPCL Ene19CapColTbl[28] =
{
    {   1,  1, 20 },
    {   0, -8,  0 },
    {   1,  2, 10 },
    {   2,  3, 16 },
    {   3,  3, 12 },
    {   0, 15,  0 },
    {  14, 14, 20 },
    {  -6, 18,  8 },
    {   6,  6, 20 },
    {   6, 18,  8 },
    {   4,  5,  9 },
    {   5,  5, 12 },
    {   0,  9,  0 },
    {   7,  8,  9 },
    {   8,  9,  9 },
    {   9,  9, 15 },
    {  14,  0,  0 },
    {  15, 16,  9 },
    {  16, 17,  9 },
    {  17, 17, 15 },
    { -14,  0,  0 },
    {  18, 19, 10 },
    {  19, 20,  8 },
    {  20, 21,  8 },
    {  22, 23, 10 },
    {  23, 24,  8 },
    {  24, 25,  8 },
    {   0,  0,  0 }
};
static const ACT_TBL_WORK En19PlyActTbl[17] = 
{
    { 35, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 30, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg042     },
    { 31, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg043     },
    { 32, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg044     },
    { 33, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg045     },
    { 34, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 35, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 36, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 37, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 38, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 39, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 40, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 41, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 42, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 43, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 44, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 45, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     }
};
static const float En19OvlTbl[3] = 
{
    2.5f, 1.5f, 1.5f    
};
static const int En19HpTbl[4][3] = 
{
    { 500, 700, 900 },
    { 500, 700, 900 },
    { 300, 420, 540 },
    { 900, 900, 900 }
};
static const float En19AtkRng[3][4] = 
{
    { 13.0f, 11.0f, 15.0f, 13.0f },  
    { 11.0f, 15.0f, 13.0f, 17.0f },  
    { 12.0f, 13.0f, 14.0f, 15.0f }   
};
static const PMA_WORK Eff30aPrm1[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 728, 2.0f, 0.98f, 1456, 4.0f, 0.99f       
    },
    {
        2, 0, 1456, 4.0f, 0.99f, 728, 2.0f, 0.98f      
    }
};
static const PMA_WORK Eff30aPrm2[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 8192, 1.0f, 0.9f, 8192, 2.0f, 0.94f      
    },
    {
        2, 0, 8192, 2.0f, 0.94f, 8192, 1.0f, 0.9f      
    }
};

static COMBJOINT_WORK En19CombJointTbl[26] = { 0 };
static PMA_WORK* Eff30aTbl[3] = 
{ 
	Eff30aPrm2,
	Eff30aPrm1,
	Eff30aPrm2
};

// 100% matching!
void bhEne19(BH_PWORK* ewP)
{
    FW_WORK* fwP;   
    int sts;        
    R49_WORK* r49P; 
    EB_WORK* ebP;   
    ML_WORK* mlwP;  

    if (ewP->mode0 != 0)
    {
        fwP = (FW_WORK*)ewP->exp0;
        
        sts = fwP->status;

        if ((ewP->exp2 == NULL) && (!(sys->gm_flg & 0x1)))
        {
            ewP->exp2 = (unsigned char*)-1;

            if ((sts & 0x20000000))
            {
                fwP->cam_clrP = (R0A_WORK*)bhSetRapEff(310, fwP->e0aP, 8)->free4;
            }

            if ((sts & 0x10000000))
            {
                r49P = (R49_WORK*)bhSetRapEff(349, NULL, 0)->free4;
                
                r49P->fnc_prcP = (void*)bhEne19_TyBloodSet;
                
                ebP = (EB_WORK*)r49P->free;
                
                ebP->ewP = ewP;
                ebP->fwP = fwP;
                
                ebP->time = 0;
            }

            if ((sts & 0x80000000))
            {
                mlwP = ewP->mlwP;
                
                fwP->clw0P = bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW0);
                
                bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW1);
                
                fwP->clw2P = bhEne19_SetLeftClaw(mlwP, TY_OBJ_ARM_L2, TY_OBJ_CLAW2);
            }
        }
    }

    bhEne19_Mode0[ewP->mode0](ewP);

    if (ewP->mode0)
    {
        ((FW_WORK*)ewP->exp0)->mode0_bak = ewP->mode0;
    }
}

// 100% matching!
static void bhEne19_Init(BH_PWORK* ewP)
{
    FW_WORK* fwP;           
    float* rngP;            
    NJS_CNK_OBJECT* objP;  
    NJS_POINT3* posP;      

    if (ewP->exp0 == NULL) 
    {
        ewP->exp0 = bhEne_CallocWork(sizeof(FW_WORK), 32);
    } 
    else
    {
        npSetMemory(ewP->exp0, sizeof(FW_WORK), 0);
    }
    
    fwP = (FW_WORK*)ewP->exp0;

    ewP->mode0 = 1;
    ewP->mode1 = 0;
    ewP->mode2 = 0;
    ewP->mode3 = 0;
    
    ewP->exp2 = NULL;

    ewP->ar = 5.0f;
    ewP->ah = 4.0f;
    ewP->aw = 0;
    ewP->ad = 0;
    
    ewP->car = 6.5f;
    ewP->cah = 4.0f;

    ewP->hp = fwP->hp_bak = En19HpTbl[sys->gm_mode][ewP->type];

    ewP->cpcl = Ene19CapColTbl;

    fwP->ovl_rte = En19OvlTbl[ewP->type];

    ewP->mtn_no = 0;
    ewP->frm_no = 0;
    
    ewP->hokan_count = 0;
    ewP->hokan_rate  = 0;
    
    ewP->mtn_add = 0;
    ewP->mtn_md  = 0;
    ewP->mtn_tp  = (unsigned char*)FlpTbl;

    ewP->flg  |=  0x178;
    ewP->flg  &= ~0x2;
    
    ewP->flg2 |= 0x1;
    
    ewP->stflg |= 0x4000;

    ewP->clp_jno[0] = 5;
    ewP->clp_jno[1] = 17;
    ewP->clp_jno[2] = 9;
    ewP->clp_jno[3] = 1;
    ewP->clp_jno[4] = 25;
    ewP->clp_jno[5] = 21;
    ewP->clp_jno[6] = -1;

    ewP->mdflg &= ~0x20;
    
    ewP->lok_jno = 4;

    fwP->ewP = ewP;
    
    fwP->watr_top = 4;
    fwP->watr_rad = 3.0f;
    
    fwP->ct_pinch = 3600;
    
    fwP->e0aP = Eff30aTbl[ewP->type];

    rngP = En19AtkRng[ewP->type];
    
    fwP->atk_rng_a_near = *rngP++;
    fwP->atk_rng_b_near = *rngP++;
	
    fwP->atk_rng_a_far  = *rngP++;
    fwP->atk_rng_b_far  = *rngP++;

    if (!(ewP->flg & 0x800)) 
    {
        ewP->flg |= 0x800;
        
        rySetShadow(ewP, 24, 20, 2, 2.0f, 3.0f);
    }

    posP = fwP->ClwPos;
    objP = &ewP->mlwP->objP[10];
    
	*posP++ = *(NJS_POINT3*)&(  objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;
	*posP++ = *(NJS_POINT3*)&(++objP)->pos;

    if (ewP->type == 0) 
    {
        NJS_CNK_OBJECT* objP; 
        O_WORK* owP;         
        
        owP  = ewP->mlwP->owP;
        objP = ewP->mlwP->objP;

        objP[10].pos[0] = -1.0f; 
        objP[10].pos[1] = objP[10].pos[2] = 0;
        
        objP[11].pos[0] = -1.0f; 
        objP[11].pos[1] = objP[11].pos[2] = 0;
        
        objP[12].pos[0] = -1.0f; 
        objP[12].pos[1] = objP[12].pos[2] = 0;
        
        objP[13].pos[0] = 3.0f; 
        objP[13].pos[1] = objP[13].pos[2] = 0;

        owP[10].flg |= 0x2;
        owP[11].flg |= 0x2;
        owP[12].flg |= 0x2;
        owP[13].flg |= 0x2;

        ewP->ay &= ~0xFF;
    }

    sys->rm_flg &= ~0x1F;

    bhEne19_ActionChange(ewP, fwP, 0);
    
    bhEne_PlyActionInit(ewP, &fwP->ply_act, En19PlyActTbl, 17);

    if (ewP->type == 1) 
    {
        fwP->status |= 0x70000000;
    } 
    else if (ewP->type == 2) 
    {
        fwP->status |= 0xE0000000;
    }
}

// 100% matching!
static void bhEne19_Move(BH_PWORK* ewP) 
{
    FW_WORK* fwP;        
    int* stsP;           
    NJS_CNK_OBJECT* objP; 
    NJS_POINT3 pos;       
    NJS_MATRIX* mtxP;   
    float ah_bak, ar_bak;         

    fwP = (FW_WORK*)ewP->exp0;

    stsP = &fwP->status;

    bhEne19_DmgCheck(ewP, fwP);

    bhEne19_BrainType[ewP->type](ewP);

    bhEne19_ActionMain(ewP, fwP);

    if ((*stsP & 0x20))
    {
        objP = ewP->mlwP->objP;
        
        objP->ang[0] = objP->ang[1] = objP->ang[2] = 0;
        
        objP->pos[0] *= 0.25f;
        objP->pos[2] *= 0.25f;
        
        *stsP &= ~0x20;
    }

    if ((*stsP & 0x8000))
    {
        bhEne19_PositonFix(ewP, fwP);
    }

    bhEne19_SoundSet(ewP, fwP);

    bhEne19_HeadTurn(ewP, fwP, *stsP & 0x4);

    if (ewP->type != 0)
    {
        bhCheckPlayer(ewP);
    }

    bhCheckEnemies(ewP);

    if ((ewP->flg & 0x10))
    {
        bhCheckWall(ewP);
    }

    if ((ewP->flg & 0x40))
    {
        mtxP = &ewP->mlwP->owP->mtx;
        
        pos = *(NJS_POINT3*)&plp->px;

        if (bhEne19_CollisionCircle2Oval(mtxP, ewP->car * fwP->ovl_rte, ewP->car, &pos, plp->car) != 0)
        {
            plp->px = pos.x;
            plp->pz = pos.z;

            ah_bak = plp->ah;
            ar_bak = plp->ar;

            plp->ah = 1.0f;
            
            bhCheckWall(plp);
            
            plp->ah = ah_bak;
            plp->ar = ar_bak;

            PEXP0_F(72) = plp->px;
            PEXP0_F(80) = plp->pz;
        }
    }

    bhEne19_CalcEnemy(ewP, fwP);
    
    bhEne19_PlyMoveMain(plp, fwP);
}

// 100% matching!
static void bhEne19_Damage()
{

}

// 100% matching!
static void bhEne19_Die(BH_PWORK* ewP) 
{
    ewP->flg |= 0x2; 

    ewP->mtn_add = 0; 
}

// 100% matching!
static void bhEne19_Event(BH_PWORK* ewP)
{
    ((FW_WORK*)ewP->exp0)->status &= ~0x4;

    ewP->mlwP->owP[4].flg &= ~0x2;
    ewP->mlwP->owP[5].flg &= ~0x2;

    bhEne_Event(ewP);

    bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);

    bhEne19_CalcEnemy(ewP, (FW_WORK*)ewP->exp0);
}

// 100% matching!
static void bhEne19_Br00(BH_PWORK* ewP)
{
    FW_WORK* fwP;     
    int* stsP, *pstP;         
    int sts;           
    TY_BR_MODE0* br0P; 
    TY_BR_MODE1* br1P; 
    TY_BR_MODE2* br2P; 
    int* wt1P;         
    int rte;           
    int act;          
    int lop;          

    pdGetPeripheral(0);
    
    stsP =       &((FW_WORK*)ewP->exp0)->status;
    pstP = (int*)&((FW_WORK*)ewP->exp0)->ply_act;

    fwP = (FW_WORK*)ewP->exp0;

    if (!(*stsP & 0x400)) 
    {
        fwP->tgt_pos = *(NJS_POINT3*)&plp->px;
        
        *stsP |= 0x1;
    }

    bhEne19_TargetAnalyze(ewP, fwP);

    if ((fwP->dmg_dly >= 3) && (fwP->br_mde1 != TY_BR1_DAMAGE)) 
    {
        fwP->dmg_lvl = fwP->dmg_dly;
        fwP->dmg_dly = 0;
        
        fwP->br_mde1 = TY_BR1_DAMAGE;
        fwP->br_mde2 = TY_BR2_FIRST;
    }

    sts = *stsP;
    
    rte = fwP->mtn_rte;

    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;
    br2P = &fwP->br_mde2;
    
    wt1P = &fwP->br_wait1;

    act = -1;
    
    lop = 0;

    do 
    {
        switch (*br0P) 
        {
        case TY_BR0_NORMAL:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0)
                {
                    (*wt1P)--;
                    
                    act = 0;
                } 
                else if (!(sts & 0x2000000))
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        lop = 1;
                        
                        *br1P = lop;
                        *br2P = TY_BR2_FIRST;
                    }
                } 
                else 
                {
                    *br1P = TY_BR1_ROTATE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        } 
                        else 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10; 
                            }
                            else 
                            { 
                                act = 9; 
                            }
                        }
                    } 
                    else
                    {
                        act = 0;
                    }
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    { 
                        *br1P = TY_BR1_NORMAL; 
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 4;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((((sts & 0x1000000)) || ((sts & 0x1000))) && (((sts & 0x2000000)) || ((sts & 0x1000))))
                    {
                        lop = 1;
                        
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= 65536) || (fwP->tgt_ang < 1820))
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl < 3) 
                    {
                        if (fwP->dmg_lvl < 2) 
                        { 
                            act = 16; 
                        }
                        else 
                        { 
                            act = 17; 
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                        
                        fwP->dmg_lvl = 0;
                    }
                    else 
                    {
                        act = 18;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte)
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->dmg_lvl != 0)
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if (fwP->dmg_lvl >= 5)
                    {
                        if (rte > 39321)
                        {
                            *br0P = TY_BR0_DOWN;
                            *br1P = TY_BR1_DAMAGE;
                            *br2P = TY_BR2_FIRST;
                        }
                    }
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_DOWN;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                        
                        *wt1P = 120;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DOWN:
            ewP->comb_timeout = 0;
            
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0) 
                {
                    (*wt1P)--;
                    
                    if ((!(sts & 0x2000000)) && ((sts & 0x1000)))
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        act = 1;
                    }
                } 
                else 
                {
                    *br1P = TY_BR1_CHANGE;
                    *br2P = TY_BR2_FIRST;
                    
                    lop = 1;
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (((sts & 0x1)) && (!(*pstP & 0x1)))
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 12; 
                            } 
                            else 
                            { 
                                act = 13; 
                            }
                        } 
                        else 
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 13; 
                            } 
                            else 
                            { 
                                act = 12; 
                            }
                        }
                    } 
                    else 
                    {
                        act = 1;
                    }
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    { 
                        *br1P = TY_BR1_NORMAL; 
                    }
                    
                    break;
                }
                            
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl >= 5) 
                    {
                        act = 19;
                        
                        *br2P = TY_BR2_LOOP0;
                    } 
                    else
                    {
                        *br1P = TY_BR1_NORMAL;
                        
                        lop = 1;
                    }
                    
                    fwP->dmg_lvl = 0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_LAY;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_CHANGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 20;
                    
                    *br2P = TY_BR2_LOOP0;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_NORMAL;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_LAY:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                *br0P = TY_BR0_DIE;
                *br1P = TY_BR1_NORMAL;
                
                act = 2;
                
                *br2P = TY_BR2_FIRST;
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DIE:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    ewP->mtn_add = 0;
                    
                    act = 2;
                    
                    ewP->flg |= 0x2;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        }
    } while (lop-- != 0);

    if (act != -1) 
    {
        bhEne19_ActionChange(ewP, fwP, act);
    }
}

// 
// Start address: 0x1f1370
static void bhEne19_Br01(BH_PWORK* ewP)
{
	ATR_WORK* htP;
	int lop;
	int act;
	int rte;
	int* wt1P;
	TY_BR_MODE2* br2P;
	TY_BR_MODE1* br1P;
	TY_BR_MODE0* br0P;
	int sts;
	int* pstP;
	int* stsP;
	FW_WORK* fwP;
	// Line 1174, Address: 0x1f1370, Func Offset: 0
	// Line 1175, Address: 0x1f139c, Func Offset: 0x2c
	// Line 1183, Address: 0x1f13a4, Func Offset: 0x34
	// Line 1177, Address: 0x1f13a8, Func Offset: 0x38
	// Line 1183, Address: 0x1f13ac, Func Offset: 0x3c
	// Line 1184, Address: 0x1f13b8, Func Offset: 0x48
	// Line 1185, Address: 0x1f13d8, Func Offset: 0x68
	// Line 1189, Address: 0x1f13e4, Func Offset: 0x74
	// Line 1193, Address: 0x1f13f0, Func Offset: 0x80
	// Line 1198, Address: 0x1f13f4, Func Offset: 0x84
	// Line 1194, Address: 0x1f13f8, Func Offset: 0x88
	// Line 1196, Address: 0x1f13fc, Func Offset: 0x8c
	// Line 1193, Address: 0x1f1400, Func Offset: 0x90
	// Line 1203, Address: 0x1f1404, Func Offset: 0x94
	// Line 1195, Address: 0x1f1408, Func Offset: 0x98
	// Line 1197, Address: 0x1f140c, Func Offset: 0x9c
	// Line 1199, Address: 0x1f1410, Func Offset: 0xa0
	// Line 1203, Address: 0x1f1414, Func Offset: 0xa4
	// Line 1207, Address: 0x1f1424, Func Offset: 0xb4
	// Line 1209, Address: 0x1f144c, Func Offset: 0xdc
	// Line 1211, Address: 0x1f1464, Func Offset: 0xf4
	// Line 1212, Address: 0x1f1470, Func Offset: 0x100
	// Line 1213, Address: 0x1f1478, Func Offset: 0x108
	// Line 1214, Address: 0x1f1480, Func Offset: 0x110
	// Line 1216, Address: 0x1f1484, Func Offset: 0x114
	// Line 1217, Address: 0x1f148c, Func Offset: 0x11c
	// Line 1218, Address: 0x1f1490, Func Offset: 0x120
	// Line 1219, Address: 0x1f1494, Func Offset: 0x124
	// Line 1220, Address: 0x1f1498, Func Offset: 0x128
	// Line 1227, Address: 0x1f149c, Func Offset: 0x12c
	// Line 1229, Address: 0x1f14b0, Func Offset: 0x140
	// Line 1230, Address: 0x1f14c4, Func Offset: 0x154
	// Line 1231, Address: 0x1f14dc, Func Offset: 0x16c
	// Line 1233, Address: 0x1f1504, Func Offset: 0x194
	// Line 1239, Address: 0x1f151c, Func Offset: 0x1ac
	// Line 1244, Address: 0x1f154c, Func Offset: 0x1dc
	// Line 1245, Address: 0x1f1568, Func Offset: 0x1f8
	// Line 1246, Address: 0x1f1570, Func Offset: 0x200
	// Line 1245, Address: 0x1f1578, Func Offset: 0x208
	// Line 1246, Address: 0x1f157c, Func Offset: 0x20c
	// Line 1251, Address: 0x1f15c0, Func Offset: 0x250
	// Line 1254, Address: 0x1f15e0, Func Offset: 0x270
	// Line 1257, Address: 0x1f1608, Func Offset: 0x298
	// Line 1259, Address: 0x1f1614, Func Offset: 0x2a4
	// Line 1260, Address: 0x1f161c, Func Offset: 0x2ac
	// Line 1261, Address: 0x1f1624, Func Offset: 0x2b4
	// Line 1262, Address: 0x1f162c, Func Offset: 0x2bc
	// Line 1263, Address: 0x1f163c, Func Offset: 0x2cc
	// Line 1265, Address: 0x1f1640, Func Offset: 0x2d0
	// Line 1266, Address: 0x1f1644, Func Offset: 0x2d4
	// Line 1267, Address: 0x1f164c, Func Offset: 0x2dc
	// Line 1268, Address: 0x1f167c, Func Offset: 0x30c
	// Line 1270, Address: 0x1f1680, Func Offset: 0x310
	// Line 1271, Address: 0x1f1684, Func Offset: 0x314
	// Line 1272, Address: 0x1f168c, Func Offset: 0x31c
	// Line 1276, Address: 0x1f1694, Func Offset: 0x324
	// Line 1277, Address: 0x1f169c, Func Offset: 0x32c
	// Line 1278, Address: 0x1f16a4, Func Offset: 0x334
	// Line 1279, Address: 0x1f16ac, Func Offset: 0x33c
	// Line 1281, Address: 0x1f16b4, Func Offset: 0x344
	// Line 1282, Address: 0x1f16b8, Func Offset: 0x348
	// Line 1283, Address: 0x1f16c0, Func Offset: 0x350
	// Line 1287, Address: 0x1f16c4, Func Offset: 0x354
	// Line 1288, Address: 0x1f16cc, Func Offset: 0x35c
	// Line 1290, Address: 0x1f16d0, Func Offset: 0x360
	// Line 1292, Address: 0x1f16d4, Func Offset: 0x364
	// Line 1295, Address: 0x1f16dc, Func Offset: 0x36c
	// Line 1298, Address: 0x1f1708, Func Offset: 0x398
	// Line 1299, Address: 0x1f1720, Func Offset: 0x3b0
	// Line 1300, Address: 0x1f1728, Func Offset: 0x3b8
	// Line 1302, Address: 0x1f1738, Func Offset: 0x3c8
	// Line 1303, Address: 0x1f1740, Func Offset: 0x3d0
	// Line 1306, Address: 0x1f1750, Func Offset: 0x3e0
	// Line 1307, Address: 0x1f1754, Func Offset: 0x3e4
	// Line 1308, Address: 0x1f175c, Func Offset: 0x3ec
	// Line 1311, Address: 0x1f1760, Func Offset: 0x3f0
	// Line 1314, Address: 0x1f1768, Func Offset: 0x3f8
	// Line 1317, Address: 0x1f1778, Func Offset: 0x408
	// Line 1321, Address: 0x1f1780, Func Offset: 0x410
	// Line 1322, Address: 0x1f17a0, Func Offset: 0x430
	// Line 1324, Address: 0x1f17a8, Func Offset: 0x438
	// Line 1325, Address: 0x1f17b0, Func Offset: 0x440
	// Line 1330, Address: 0x1f17c0, Func Offset: 0x450
	// Line 1334, Address: 0x1f17c8, Func Offset: 0x458
	// Line 1337, Address: 0x1f17e8, Func Offset: 0x478
	// Line 1338, Address: 0x1f17f0, Func Offset: 0x480
	// Line 1340, Address: 0x1f1800, Func Offset: 0x490
	// Line 1341, Address: 0x1f1808, Func Offset: 0x498
	// Line 1345, Address: 0x1f1818, Func Offset: 0x4a8
	// Line 1347, Address: 0x1f1820, Func Offset: 0x4b0
	// Line 1350, Address: 0x1f1828, Func Offset: 0x4b8
	// Line 1351, Address: 0x1f1864, Func Offset: 0x4f4
	// Line 1352, Address: 0x1f1874, Func Offset: 0x504
	// Line 1353, Address: 0x1f1878, Func Offset: 0x508
	// Line 1357, Address: 0x1f1890, Func Offset: 0x520
	// Line 1362, Address: 0x1f18a0, Func Offset: 0x530
	// Line 1366, Address: 0x1f18a8, Func Offset: 0x538
	// Line 1371, Address: 0x1f18c8, Func Offset: 0x558
	// Line 1374, Address: 0x1f18d0, Func Offset: 0x560
	// Line 1375, Address: 0x1f18e0, Func Offset: 0x570
	// Line 1377, Address: 0x1f1908, Func Offset: 0x598
	// Line 1381, Address: 0x1f1918, Func Offset: 0x5a8
	// Line 1385, Address: 0x1f191c, Func Offset: 0x5ac
	// Line 1389, Address: 0x1f1924, Func Offset: 0x5b4
	// Line 1394, Address: 0x1f194c, Func Offset: 0x5dc
	// Line 1397, Address: 0x1f1954, Func Offset: 0x5e4
	// Line 1399, Address: 0x1f196c, Func Offset: 0x5fc
	// Line 1405, Address: 0x1f197c, Func Offset: 0x60c
	// Line 1409, Address: 0x1f1984, Func Offset: 0x614
	// Line 1412, Address: 0x1f19b0, Func Offset: 0x640
	// Line 1414, Address: 0x1f19d0, Func Offset: 0x660
	// Line 1413, Address: 0x1f19d4, Func Offset: 0x664
	// Line 1415, Address: 0x1f19d8, Func Offset: 0x668
	// Line 1416, Address: 0x1f19e0, Func Offset: 0x670
	// Line 1417, Address: 0x1f19e8, Func Offset: 0x678
	// Line 1418, Address: 0x1f1a24, Func Offset: 0x6b4
	// Line 1422, Address: 0x1f1a28, Func Offset: 0x6b8
	// Line 1419, Address: 0x1f1a2c, Func Offset: 0x6bc
	// Line 1421, Address: 0x1f1a30, Func Offset: 0x6c0
	// Line 1424, Address: 0x1f1a34, Func Offset: 0x6c4
	// Line 1427, Address: 0x1f1a3c, Func Offset: 0x6cc
	// Line 1429, Address: 0x1f1a4c, Func Offset: 0x6dc
	// Line 1430, Address: 0x1f1a54, Func Offset: 0x6e4
	// Line 1431, Address: 0x1f1a60, Func Offset: 0x6f0
	// Line 1433, Address: 0x1f1a6c, Func Offset: 0x6fc
	// Line 1436, Address: 0x1f1a74, Func Offset: 0x704
	// Line 1437, Address: 0x1f1a84, Func Offset: 0x714
	// Line 1438, Address: 0x1f1a88, Func Offset: 0x718
	// Line 1445, Address: 0x1f1a8c, Func Offset: 0x71c
	// Line 1449, Address: 0x1f1a94, Func Offset: 0x724
	// Line 1452, Address: 0x1f1ad0, Func Offset: 0x760
	// Line 1454, Address: 0x1f1adc, Func Offset: 0x76c
	// Line 1455, Address: 0x1f1ae4, Func Offset: 0x774
	// Line 1456, Address: 0x1f1aec, Func Offset: 0x77c
	// Line 1457, Address: 0x1f1af4, Func Offset: 0x784
	// Line 1458, Address: 0x1f1afc, Func Offset: 0x78c
	// Line 1459, Address: 0x1f1b00, Func Offset: 0x790
	// Line 1461, Address: 0x1f1b04, Func Offset: 0x794
	// Line 1462, Address: 0x1f1b0c, Func Offset: 0x79c
	// Line 1463, Address: 0x1f1b10, Func Offset: 0x7a0
	// Line 1466, Address: 0x1f1b14, Func Offset: 0x7a4
	// Line 1467, Address: 0x1f1b1c, Func Offset: 0x7ac
	// Line 1468, Address: 0x1f1b20, Func Offset: 0x7b0
	// Line 1471, Address: 0x1f1b24, Func Offset: 0x7b4
	// Line 1474, Address: 0x1f1b2c, Func Offset: 0x7bc
	// Line 1477, Address: 0x1f1b50, Func Offset: 0x7e0
	// Line 1478, Address: 0x1f1b68, Func Offset: 0x7f8
	// Line 1479, Address: 0x1f1b70, Func Offset: 0x800
	// Line 1481, Address: 0x1f1b80, Func Offset: 0x810
	// Line 1482, Address: 0x1f1b88, Func Offset: 0x818
	// Line 1485, Address: 0x1f1b98, Func Offset: 0x828
	// Line 1486, Address: 0x1f1b9c, Func Offset: 0x82c
	// Line 1487, Address: 0x1f1ba4, Func Offset: 0x834
	// Line 1490, Address: 0x1f1ba8, Func Offset: 0x838
	// Line 1493, Address: 0x1f1bb0, Func Offset: 0x840
	// Line 1496, Address: 0x1f1bc0, Func Offset: 0x850
	// Line 1500, Address: 0x1f1bc8, Func Offset: 0x858
	// Line 1501, Address: 0x1f1be8, Func Offset: 0x878
	// Line 1503, Address: 0x1f1bf0, Func Offset: 0x880
	// Line 1504, Address: 0x1f1bf8, Func Offset: 0x888
	// Line 1509, Address: 0x1f1c08, Func Offset: 0x898
	// Line 1512, Address: 0x1f1c10, Func Offset: 0x8a0
	// Line 1516, Address: 0x1f1c2c, Func Offset: 0x8bc
	// Line 1517, Address: 0x1f1c30, Func Offset: 0x8c0
	// Line 1520, Address: 0x1f1c38, Func Offset: 0x8c8
	// Line 1523, Address: 0x1f1c48, Func Offset: 0x8d8
	// Line 1527, Address: 0x1f1c4c, Func Offset: 0x8dc
	// Line 1531, Address: 0x1f1c54, Func Offset: 0x8e4
	// Line 1536, Address: 0x1f1c74, Func Offset: 0x904
	// Line 1539, Address: 0x1f1c7c, Func Offset: 0x90c
	// Line 1542, Address: 0x1f1ca0, Func Offset: 0x930
	// Line 1546, Address: 0x1f1ca8, Func Offset: 0x938
	// Line 1549, Address: 0x1f1cc8, Func Offset: 0x958
	// Line 1553, Address: 0x1f1ce0, Func Offset: 0x970
	// Line 1552, Address: 0x1f1ce4, Func Offset: 0x974
	// Line 1553, Address: 0x1f1ce8, Func Offset: 0x978
	// Line 1556, Address: 0x1f1cec, Func Offset: 0x97c
	// Line 1557, Address: 0x1f1cf0, Func Offset: 0x980
	// Line 1559, Address: 0x1f1d00, Func Offset: 0x990
	// Line 1560, Address: 0x1f1d08, Func Offset: 0x998
	// Line 1561, Address: 0x1f1d14, Func Offset: 0x9a4
	// Line 1568, Address: 0x1f1d24, Func Offset: 0x9b4
	// Line 1569, Address: 0x1f1d28, Func Offset: 0x9b8
	// Line 1572, Address: 0x1f1d34, Func Offset: 0x9c4
	// Line 1575, Address: 0x1f1d50, Func Offset: 0x9e0
	// Func End, Address: 0x1f1d80, Func Offset: 0xa10
	scePrintf("bhEne19_Br01 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_Br02(BH_PWORK* ewP)
{
    FW_WORK* fwP;      
    int* stsP, *pstP;         
    unsigned char rut; 
    NJS_POINT3 pos;   
    int sts;         
    TY_BR_MODE0* br0P; 
    TY_BR_MODE1* br1P;
    TY_BR_MODE2* br2P; 
    int* wt1P;         
    int rte;           
    int act;           
    int lop;           

    fwP = (FW_WORK*)ewP->exp0;
    
    stsP = &fwP->status;
    pstP = (int*)&fwP->ply_act;

    if (!(fwP->status & 0x400))
    {
        pos = *(NJS_POINT3*)&ewP->mlwP->owP[1].mtx[12];
        
        pos.y = ewP->py;
        
        njSubVector(&pos, (NJS_VECTOR*)&ewP->mlwP->owP->mtx[8]);

        rut = bhCheckRoute(&pos, (NJS_POINT3*)&plp->px, &((FW_WORK*)ewP->exp0)->tgt_pos);
        
        if (rut == 0xFF) 
        {
            ((FW_WORK*)ewP->exp0)->tgt_pos = *(NJS_POINT3*)&plp->px;
            
            *stsP |= 0x1;
        }
        else if (rut == bhCheckRouteID((NJS_POINT3*)&plp->px)) 
        {
            ((FW_WORK*)ewP->exp0)->tgt_pos = *(NJS_POINT3*)&plp->px;
            
            *stsP |=  0x1;
        } 
        else 
        {
            *stsP &= ~0x1;
        }
    }

    bhEne19_TargetAnalyze(ewP, fwP);

    sts = *stsP;
    
    rte = fwP->mtn_rte;
    
    br0P = &fwP->br_mde0;
    br1P = &fwP->br_mde1;
    br2P = &fwP->br_mde2;
    
    wt1P = &fwP->br_wait1;
    
    act = -1;
    
    lop = 0;

    do 
    {
        switch (*br0P) 
        {
        case TY_BR0_NORMAL:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                if (*wt1P > 0) 
                {
                    act = 0;
                    
                    *wt1P -= 1;
                } 
                else if (!(sts & 0x1000000)) 
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else
                    {
                        if ((((sts & 0x200000)) && (!(sts & 0x400000)) && ((sts & 0x1))) && (!(*pstP & 0x1)) && (!(sts & 0x800))) 
                        {
                            *br1P = TY_BR1_DASH_ATTACK;
                            *br2P = TY_BR2_FIRST;
                            
                            lop = 1;
                        } 
                        else 
                        {
                            *br1P = TY_BR1_WALK;
                            *br2P = TY_BR2_FIRST;
                            
                            lop = 1;
                        }
                    }
                } 
                else if (!(sts & 0x2000000)) 
                {
                    if (((sts & 0x1000)) && ((sts & 0x1))) 
                    {
                        *br1P = TY_BR1_ATTACK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                    else 
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                } 
                else 
                {
                    if ((sts & 0x1))
                    {
                        *br1P = TY_BR1_ROTATE;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    } 
                    else 
                    {
                        *br1P = TY_BR1_WALK;
                        *br2P = TY_BR2_FIRST;
                        
                        lop = 1;
                    }
                }
                
                break;
            case TY_BR1_ATTACK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    if ((!(*pstP & 0x1)) && (!(sts & 0x800))) 
                    {
                        if (!(sts & 0x8)) 
                        {
                            if ((sts & 0x2000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        } 
                        else
                        {
                            if ((sts & 0x4000)) 
                            { 
                                act = 10;
                            }
                            else 
                            { 
                                act = 9;
                            }
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                    } 
                    else 
                    {
                        act = 11;
                        
                        *br2P = TY_BR2_LOOP1;
                    } 
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if ((rte <= 32768) && (((sts & 0x1000000)) || (!(sts & 0x1000)))) 
                    {
                        *wt1P = 20;
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_DASH_ATTACK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    if (!(sts & 0x8)) 
                    {
                        if ((sts & 0x2000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    }
                    else 
                    {
                        if ((sts & 0x4000)) 
                        { 
                            act = 15;
                        }
                        else 
                        { 
                            act = 14;
                        }
                    }
                    
                    fwP->ct_dash = 1;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((rte >= 45875) && (!(*pstP & 0x1)) && ((!(sts & 0x1000000)) && (!(sts & 0x400000))) && (fwP->ct_dash < 3) && ((sts & 0x1)) && (ewP->hp >= 0)) 
                    {
                        fwP->ct_dash++;
                        
                        if (fwP->act_now == 15) 
                        {
                            act = 14;
                        }
                        else
                        {
                            act = 15;
                        }
                    } 
                    else if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                }
                
                break;
            case TY_BR1_WALK:
                switch (*br2P)
                {
                case TY_BR2_FIRST:
                    act = 5;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if ((!(sts & 0x1000000)) && (!(sts & 0x1000))) 
                    {
                        if (((!(sts & 0x200000)) || ((sts & 0x400000))) || ((*pstP & 0x1)))
                        {
                            break;
                        }
                    } 
                    else if ((!(sts & 0x2000000)) && (!(sts & 0x1000))) 
                    {
                        break;
                    }
                    
                    *br1P = TY_BR1_NORMAL;
                    
                    lop = 1;
                    break;
                }
                
                break;
            case TY_BR1_ROTATE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 8;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->tgt_ang < 1820) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    if (fwP->dmg_lvl < 3) 
                    {
                        if (fwP->dmg_lvl <= 1) 
                        {
                            act = 16;
                        }
                        else
                        {
                            act = 17;
                        }
                        
                        *br2P = TY_BR2_LOOP0;
                        
                        fwP->dmg_lvl = 0;
                    }
                    else
                    {
                        ewP->flg &= ~0x60;
                        
                        act = 18;
                        
                        *br2P = TY_BR2_LOOP1;
                    }
                    
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br1P = TY_BR1_NORMAL;
                    } 
                    else if (fwP->dmg_lvl != 0) 
                    {
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                case TY_BR2_LOOP1:
                    if (rte > 39321) 
                    {
                        *br0P = TY_BR0_DOWN;
                        *br1P = TY_BR1_DAMAGE;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DOWN:
            switch (*br1P) 
            {
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 19;
                    
                    *br2P = TY_BR2_LOOP0;
                    
                    fwP->dmg_lvl = 0;
                    break;
                case TY_BR2_LOOP0:
                    if (rte >= fwP->chg_rte) 
                    {
                        *br0P = TY_BR0_DIE;
                        *br1P = TY_BR1_NORMAL;
                        *br2P = TY_BR2_FIRST;
                    }
                    
                    break;
                }
                
                break;
            }
            
            break;
        case TY_BR0_DIE:
            switch (*br1P) 
            {
            case TY_BR1_NORMAL:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    act = 2;
                    
                    ewP->flg |= 0x2;
                    
                    *br2P = TY_BR2_LOOP0;
                    break;
                case TY_BR2_LOOP0:
                    ewP->mtn_add = 0;
                    break;
                }
                
                break;
            case TY_BR1_DAMAGE:
                switch (*br2P) 
                {
                case TY_BR2_FIRST:
                    *br1P = TY_BR1_NORMAL;
                    
                    fwP->dmg_lvl = 0;
                    break;
                }
                
                break;
            }
            
            break;
        }
    } while (lop--);

    if (act != -1) 
    {
        bhEne19_ActionChange(ewP, fwP, act);
    }
}

// 100% matching!
static void bhEne19_Mv00(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv01(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv02(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x4;
    }
}

// 100% matching!
static void bhEne19_Mv03(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv04a(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP |= 0x4;
    }
}

// 100% matching!
static void bhEne19_Mv04b(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv05(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv06(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv07(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP;    
    float pos[3]; 
    int ang[3];   

    stsP = &fwP->status;

    *stsP |= 0x20;  
    
    if (count == 0) 
    {
        *stsP &= ~0x4;
        
        if ((*stsP & 0x2000)) 
        {
            *stsP |= 0x8;
        }
        else if ((*stsP & 0x4000))
        {
            *stsP &= ~0x8;
        }
        
        fwP->pos_tmp[0] = ewP->px;
        fwP->pos_tmp[1] = ewP->py;
        fwP->pos_tmp[2] = ewP->pz;
        
        fwP->ang_tmp[0] = ewP->ax;
        fwP->ang_tmp[1] = ewP->ay;
        fwP->ang_tmp[2] = ewP->az;
        
        njSetMatrix(&fwP->mtx_bak, ewP->mtx);
    }
    
    if ((*stsP & 0x8)) 
    {
        ewP->mtn_md |= 0x2;
    } 
    else 
    {
        ewP->mtn_md &= ~0x2;
    }
    
    bhGetObjMotion(ewP, 0, pos, ang);
    
    ewP->ax = ang[0];
    ewP->ay = fwP->ang_tmp[1] + ang[1];
    ewP->az = ang[2];
    
    njCalcPoint(&fwP->mtx_bak, (NJS_POINT3*)pos, (NJS_POINT3*)pos);
    
    ewP->px += 0.1f * (pos[0] - ewP->px);
    ewP->pz += 0.1f * (pos[2] - ewP->pz);
    
    if (fwP->mtn_rte >= 52428) 
    {
        *stsP |= 0x4;
    }
}

// 100% matching!
static void bhEne19_Mv08(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    int* stsP;       
    NJS_POINT3 dir;   
    NJS_POINT3 pos;  
    NJS_MATRIX* mtxP; 

    stsP = &fwP->status;

    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(*stsP & 0x8)) ? TY_ARM_RIGHT : TY_ARM_LEFT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        fwP->trw_spd = 2.0f;

        if (((!(*stsP & 0x8)) && ((*stsP & 0x40000000))) || (((*stsP & 0x8)) && ((*stsP & 0x80000000)))) 
        {
            mtxP = &plp->mlwP->owP[2].mtx;
            
            pos = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[12];
            
            njAddVector(&pos, (NJS_VECTOR*)&plp->mlwP->owP[2].mtx[12]);
            
            pos.x *= 0.5f;
            pos.y *= 0.5f;
            pos.z *= 0.5f;
            
            dir = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[4];
            
            dir.x *= -1.0f;
            dir.y *= -1.0f;
            dir.z *= -1.0f;
            
            rySetEffBlood(mtxP, &pos, &dir, 0);
            
            fwP->snd_no = 11;
        } 
        else 
        {
            fwP->snd_no = 9;
        }
    }
}

// 100% matching!
static void bhEne19_Mv09(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    int* stsP;       
    NJS_POINT3 dir;   
    NJS_POINT3 pos;  
    NJS_MATRIX* mtxP; 

    stsP = &fwP->status;

    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(*stsP & 0x8)) ? TY_ARM_LEFT : TY_ARM_RIGHT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        fwP->trw_spd = 2.0f;

        if ((((*stsP & 0x8)) && ((*stsP & 0x40000000))) || ((!(*stsP & 0x8)) && ((*stsP & 0x80000000)))) 
        {
            mtxP = &plp->mlwP->owP[2].mtx;
            
            pos = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[12];
            
            njAddVector(&pos, (NJS_VECTOR*)&plp->mlwP->owP[2].mtx[12]);
            
            pos.x *= 0.5f;
            pos.y *= 0.5f;
            pos.z *= 0.5f;
            
            dir = *(NJS_POINT3*)&ewP->mlwP->owP[9].mtx[4];
            
            dir.x *= -1.0f;
            dir.y *= -1.0f;
            dir.z *= -1.0f;
            
            rySetEffBlood(mtxP, &pos, &dir, 0);
            
            fwP->snd_no = 11;
        } 
        else 
        {
            fwP->snd_no = 9;
        }
    }
}

// 100% matching!
static void bhEne19_Mv10(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* flgP, *stsP;        
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;    
    NJS_POINT3 dir;   
	static NJS_POINT3 off = {  2.5f,    0,    0 };
	static NJS_VECTOR vct = { -1.0f,    0,    0 };

    flgP = &fwP->act_flg;
    stsP = &fwP->status;
    
    if (count == 0) 
    {
        *stsP &= ~0x8;
        *flgP |=  0x8;
        
        fwP->trn_spd = 182;
    }
    
    mtx0P = &ewP->mlwP->owP[10].mtx;
    mtx2P = &ewP->mlwP->owP[12].mtx;
    
    if (fwP->act_frm == 50) 
    {
        bhEne19_SetClawPlane(ewP, mtx0P, -0x0F7F7F80, 11, -2.0f, 3.0f);
        bhEne19_SetClawPlane(ewP, mtx2P,          -1, 11, -2.0f, 3.0f);
    }
    
    if (fwP->act_frm == 60)
    {
        njCalcVector(mtx0P, &vct, &dir);
        njCalcPoint(mtx0P,  &off, &pos);
        
        bhSetEffSpark(&pos, &dir, -1, 0x40F08000, 0);
        bhSetEffSpark(&pos, &dir, -1, 0x40F08000, 1);
        bhSetEffSpark(&pos, &dir, -1, 0x40F04000, 0);
        bhSetEffSpark(&pos, &dir, -1, 0x40F04000, 1);
        
        bhSetRapEff(310, &fwP->e0aP[1], 8);
        
        fwP->snd_no = 19;
    }
    
    if (((*stsP & 0x40)) && ((bhEne19_AttackHitCheck(ewP, TY_ARM_RIGHT, 5.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0))) 
    {
        NJS_POINT3 dir;
        NJS_MATRIX* mtxP; 
        
        fwP->trw_spd = 0.5f;
        
        fwP->snd_no = 15;
        
        mtxP = &plp->mlwP->owP[2].mtx;
        
        dir = *(NJS_POINT3*)&(*mtxP)[4];
        
        njSubVector(&dir, (NJS_POINT3*)&(*mtxP)[8]);
        
        rySetEffBlood(mtxP, (NJS_POINT3*)&(*mtxP)[12], &dir, 2);
    }
}

// 100% matching!
static void bhEne19_Mv11(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(fwP->status & 0x8)) ? TY_ARM_RIGHT : TY_ARM_LEFT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 100% matching!
static void bhEne19_Mv12(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(fwP->status & 0x8)) ? TY_ARM_LEFT : TY_ARM_RIGHT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 100% matching!
static void bhEne19_Mv13(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP, *flgP;          
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;     
    NJS_POINT3 dir;     
    TY_OBJ_MODE obj_no;
    TY_ARM_NO arm_no;   
    ATR_WORK* htP;      
	static NJS_POINT3 off = {  3.0f,     0,     0 };
	static NJS_VECTOR vct = { -1.0f, -1.0f, -1.0f };
    
    stsP = &fwP->status;
    flgP = &fwP->act_flg;

    if (count == 0) 
    {
        *flgP |= 0x8;
        
        fwP->trn_spd = 546;
    }

    if ((!(*stsP & 0x8)) || ((*stsP & 0x80000000))) 
    {
        if (!(*stsP & 0x8)) 
        {
            mtx0P = &ewP->mlwP->owP[10].mtx;
            mtx2P = &ewP->mlwP->owP[12].mtx;
        } 
        else 
        {
            mtx0P = fwP->clw0P->mtxP;
            mtx2P = fwP->clw2P->mtxP;
        }

        if (fwP->act_frm == 8)
        {
            bhEne19_SetClawPlane(ewP, mtx0P, -0xF7F7F80, 16, -2.0f, 3.0f);
            bhEne19_SetClawPlane(ewP, mtx2P, -1,         16, -2.0f, 3.0f);
        }

        if ((fwP->act_frm >= 18) && (fwP->act_frm < 19)) 
        {
            njCalcVector(mtx0P, &vct, &dir);
            njCalcPoint(mtx0P,  &off, &pos);
            
            bhSetEffSpark(&pos, &dir, -1, 0x80F02000, 0);
            bhSetEffSpark(&pos, &dir, -1, 0x80F04000, 0);
            bhSetEffSpark(&pos, &dir, -1, 0x80F05000, 0);
        }
    }

    if ((*stsP & 0x40)) 
    {
        if ((*stsP & 0x8)) 
        {
            arm_no = TY_ARM_LEFT;
            obj_no = TY_OBJ_ARM_L2;
        } 
        else 
        {
            arm_no = TY_ARM_RIGHT;
            obj_no = TY_OBJ_ARM_R2;
        }

        if (bhEne19_AttackHitCheck(ewP, arm_no, 3.5f, &fwP->trw_dir) != 0) 
        {
            NJS_POINT3 dir; 
            int dmg;       
            float spd;     
            int ang;       
            
            ang = fwP->trw_dir;

            dir.x = plp->px - (25.0f * njSin(ang));
            dir.y = plp->py;
            dir.z = plp->pz - (25.0f * njCos(ang));

            if ((bhCollisionCheckLine2((NJS_POINT3*)&plp->px, &dir, 0x4000, plp->flr_no) != NULL) && (njDistanceP2P((NJS_POINT3*)&plp->px, &dir) > 10.0f)) 
            {
                dmg = 3;
                
                spd = 2.5f;
            } 
            else 
            {
                dmg = 1;
                
                spd = 2.0f;
            }

            if (bhEne19_PlySetDamage(plp, fwP, dmg) != 0) 
            {
                if ((!(*stsP & 0x8)) || ((*stsP & 0x80000000))) 
                {
                    NJS_POINT3 dir;  
                    NJS_MATRIX* mtxP;
                    NJS_POINT3* posP; 

                    mtxP = &plp->mlwP->owP[2].mtx;
                    posP = (NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[12];

                    dir = *(NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[4];
                    
                    dir.x *= -1.0f; 
                    dir.y *= -1.0f;
                    dir.z *= -1.0f;
                    
                    rySetEffBlood(mtxP, posP, &dir, 1);
                    
                    fwP->snd_no = 11;
                } 
                else 
                {
                    fwP->snd_no = 9;
                }
                
                fwP->trw_spd = spd;
            }
        }
    }
}

// 99.85% matching
static void bhEne19_Mv14(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
    int* stsP, *flgP;          
    NJS_MATRIX* mtx0P, *mtx2P; 
    NJS_POINT3 pos;     
    NJS_POINT3 dir;     
    TY_OBJ_MODE obj_no;
    TY_ARM_NO arm_no;   
    ATR_WORK* htP;      
	static NJS_POINT3 off = {  3.0f,     0,     0 };
	static NJS_VECTOR vct = {  1.0f, -1.0f,  1.0f };
    
    stsP = &fwP->status;
    flgP = &fwP->act_flg;

    if (count == 0) 
    {
        *flgP |= 0x8;
        
        fwP->trn_spd = 546;
    }

    if (((*stsP & 0x8)) || ((*stsP & 0x80000000))) 
    {
        if ((*stsP & 0x8)) 
        {
            mtx0P = &ewP->mlwP->owP[10].mtx;
            mtx2P = &ewP->mlwP->owP[12].mtx;
        } 
        else 
        {
            mtx0P = fwP->clw0P->mtxP;
            mtx2P = fwP->clw2P->mtxP;
        }

        if (fwP->act_frm == 8)
        {
            bhEne19_SetClawPlane(ewP, mtx0P, -0xF7F7F80, 16, -2.0f, 3.0f);
            bhEne19_SetClawPlane(ewP, mtx2P, -1,         16, -2.0f, 3.0f);
        }

        if ((fwP->act_frm >= 16) && (fwP->act_frm < 23)) 
        {
            njCalcVector(mtx0P, &vct, &dir);
            njCalcPoint(mtx0P,  &off, &pos);
            
            if (bhCheckWallType(&pos, 0, 0.1f, 0.1f) != NULL) 
            {
                bhSetEffSpark(&pos, &dir, -1, 0x80F06000, 0);
                bhSetEffSpark(&pos, &dir, -1, 0x80F04000, 0);
                bhSetEffSpark(&pos, &dir, -1, 0x80F02000, 0);
            }
        }
    }

    if ((*stsP & 0x40)) 
    {
        if ((*stsP & 0x8)) 
        {
            arm_no = TY_ARM_RIGHT;
            obj_no = TY_OBJ_ARM_R2;
        } 
        else 
        {
            arm_no = TY_ARM_LEFT;
            obj_no = TY_OBJ_ARM_L2;
        }

        if (bhEne19_AttackHitCheck(ewP, arm_no, 3.5f, &fwP->trw_dir) != 0) 
        {
            NJS_POINT3 dir; 
            int dmg;       
            float spd;     
            int ang;       
            
            ang = fwP->trw_dir;

            dir.x = plp->px - (25.0f * njSin(ang));
            dir.y = plp->py;
            dir.z = plp->pz - (25.0f * njCos(ang));

            if ((bhCollisionCheckLine2((NJS_POINT3*)&plp->px, &dir, 0x4000, plp->flr_no) != NULL) && (njDistanceP2P((NJS_POINT3*)&plp->px, &dir) > 10.0f)) 
            {
                dmg = 3;
                
                spd = 2.5f;
            } 
            else 
            {
                dmg = 1;
                
                spd = 2.0f;
            }

            if (bhEne19_PlySetDamage(plp, fwP, dmg) != 0) 
            {
                if (((*stsP & 0x8)) || ((*stsP & 0x80000000))) 
                {
                    NJS_POINT3 dir;  
                    NJS_MATRIX* mtxP;
                    NJS_POINT3* posP; 

                    mtxP = &plp->mlwP->owP[2].mtx;
                    posP = (NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[12];

                    dir = *(NJS_POINT3*)&ewP->mlwP->owP[obj_no].mtx[4];
                    
                    dir.x *= -1.0f; 
                    dir.y *= -1.0f;
                    dir.z *= -1.0f;
                    
                    rySetEffBlood(mtxP, posP, &dir, 1);
                    
                    fwP->snd_no = 11;
                } 
                else 
                {
                    fwP->snd_no = 9;
                }
                
                fwP->trw_spd = spd;
            }
        }
    }
}

// 100% matching!
static void bhEne19_Mv15(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv16(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv17(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        *stsP |= 0x100;

        if ((*bstP & 0x40000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv18(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg &= ~0x60;

        fwP->status &= ~0x100;
        fwP->status |=  0x200;
    }
}

// 100% matching!
static void bhEne19_Mv19(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x100;
    }
}

// 100% matching!
static void bhEne19_Mv20(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg |= 0x60;
    }

    if (fwP->mtn_rte >= 65536)
    {
        fwP->status &= ~0x200;
        fwP->status |=  0x100;
    }
}

// 93.33% matching
static EA_WORK* bhEne19_ActionSearch(int act_nw, int act_no)
{
	int key;  
	int high, low;  
	int val;   
	int middle; 

    high = 50;
    
    key = ((unsigned char)act_nw << 8) | ((unsigned char)act_no << 0);
    
    low = 0;

    while (TRUE)
    {
        middle = (low + high) / 2;
        
        val = En19ActTbl[middle].label;

        if (key == val)
        {
            break;
        }
        else if (key < val)
        {
            high = middle - 1;
        }
        else if (key > val)
        {
            low  = middle + 1;
        }

        if (high < low)
        {
            return NULL;
        }
    }

    return &En19ActTbl[middle];
}

// 100% matching!
static int bhEne19_ActionChange(BH_PWORK* ewP, FW_WORK* fwP, int act_dst)
{
    EA_WORK* eaP;
    
    if (((eaP = bhEne19_ActionSearch(fwP->act_now, act_dst)) == NULL) && (fwP->act_now != act_dst)) 
    {
        eaP = bhEne19_ActionSearch(-1, act_dst);
    }
    
    if (eaP != NULL) 
    {
        njMemCopy4(&fwP->b_status, &fwP->status, 8);
        
        fwP->b_mtn_md = ewP->mtn_md;
        
        fwP->act_flg = 0;
        
        fwP->prgP = eaP->prgP;
        
        fwP->act_cnt = 0;
        fwP->act_frm = eaP->frm_no;
        
        ewP->mtn_no = eaP->mtn_no;
        ewP->frm_no = eaP->frm_no * 65536;
        
        ewP->hokan_rate  = eaP->hkn_lvl * (65536.0 / 255.0);
        ewP->hokan_count = eaP->hkn_cnt;

        if ((eaP->flag & 0x20000)) 
        {
            ewP->mtn_add = 0;
        } 
        else if ((eaP->flag & 0x40000)) 
        {
            ewP->mtn_add = -65536;
        } 
        else 
        {
            ewP->mtn_add =  65536;
        }

        ewP->mtn_md = (unsigned short)eaP->flag;
        
        fwP->chg_rte = eaP->chg_rte * 65536.0f;
        
        fwP->status &= ~0x38000;

        if ((eaP->flag & 0x80000)) 
        {
            fwP->status |= 0x8000;
        }

        fwP->act_now = act_dst;
        
        return 1;
    }
    
    return 0;
}

// 
// Start address: 0x1f3980
static int bhEne19_ActionMain(BH_PWORK* ewP, FW_WORK* fwP)
{
	short* s16P;
	int ang;
	int mat;
	int* stsP;
	// Line 2812, Address: 0x1f3980, Func Offset: 0
	// Line 2817, Address: 0x1f399c, Func Offset: 0x1c
	// Line 2820, Address: 0x1f39a4, Func Offset: 0x24
	// Line 2821, Address: 0x1f39b0, Func Offset: 0x30
	// Line 2820, Address: 0x1f39b4, Func Offset: 0x34
	// Line 2821, Address: 0x1f39b8, Func Offset: 0x38
	// Line 2822, Address: 0x1f39d4, Func Offset: 0x54
	// Line 2824, Address: 0x1f39f0, Func Offset: 0x70
	// Line 2825, Address: 0x1f39fc, Func Offset: 0x7c
	// Line 2824, Address: 0x1f3a00, Func Offset: 0x80
	// Line 2825, Address: 0x1f3a04, Func Offset: 0x84
	// Line 2826, Address: 0x1f3a20, Func Offset: 0xa0
	// Line 2828, Address: 0x1f3a3c, Func Offset: 0xbc
	// Line 2830, Address: 0x1f3a48, Func Offset: 0xc8
	// Line 2831, Address: 0x1f3a64, Func Offset: 0xe4
	// Line 2833, Address: 0x1f3a74, Func Offset: 0xf4
	// Line 2834, Address: 0x1f3a90, Func Offset: 0x110
	// Line 2839, Address: 0x1f3aa0, Func Offset: 0x120
	// Line 2843, Address: 0x1f3ac8, Func Offset: 0x148
	// Line 2847, Address: 0x1f3ad8, Func Offset: 0x158
	// Line 2849, Address: 0x1f3ae8, Func Offset: 0x168
	// Line 2850, Address: 0x1f3b04, Func Offset: 0x184
	// Line 2861, Address: 0x1f3b20, Func Offset: 0x1a0
	// Line 2862, Address: 0x1f3b40, Func Offset: 0x1c0
	// Line 2867, Address: 0x1f3b50, Func Offset: 0x1d0
	// Line 2865, Address: 0x1f3b5c, Func Offset: 0x1dc
	// Line 2867, Address: 0x1f3b60, Func Offset: 0x1e0
	// Line 2868, Address: 0x1f3b7c, Func Offset: 0x1fc
	// Line 2874, Address: 0x1f3b88, Func Offset: 0x208
	// Line 2876, Address: 0x1f3bbc, Func Offset: 0x23c
	// Line 2874, Address: 0x1f3bc0, Func Offset: 0x240
	// Line 2877, Address: 0x1f3bc4, Func Offset: 0x244
	// Func End, Address: 0x1f3bdc, Func Offset: 0x25c
	scePrintf("bhEne19_ActionMain - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_TargetAnalyze(BH_PWORK* ewP, FW_WORK* fwP)
{    
    int* stsP;        
    float dst;        
    int dlt;          
    int ang;        

    stsP = &fwP->status;

    if (((*stsP & 0x1)) && ((plp->hp < 0) || ((plp->flg & 0x2)))) 
    {
        *stsP |= 0x800;
    }

    dst = njDistanceP2P((NJS_POINT3*)&ewP->px, &fwP->tgt_pos);
    
    fwP->tgt_dst = dst;

    *stsP &= ~0xF00000;

    if (dst >= 10.0f) 
    {
        *stsP |= 0x100000;
    }
    
    if (dst >= 20.0f) 
    {
        *stsP |= 0x200000;
    }
    
    if (dst >= 25.0f) 
    {
        *stsP |= 0x400000;
    }
    
    if (dst >= 17.0f) 
    {
        *stsP |= 0x800000;
    }

    fwP->ply_dst = njDistanceP2P((NJS_POINT3*)&ewP->px, (NJS_POINT3*)&plp->px);

    dlt = plp->ay - ewP->ay;
    
    if ((dlt & 0x8000)) 
    {
        dlt = (65536 - dlt) | 0x80000000;
    }
    
    fwP->dir_dlt = dlt;

    {
    int dlt;         
    NJS_POINT3 pos;   
    NJS_MATRIX* mtxP; 
        
    dlt = (short)((int)(10430.381f * atan2f(ewP->px - fwP->tgt_pos.x, ewP->pz - fwP->tgt_pos.z)) - ewP->ay);
        
    fwP->tgt_ang = ang = abs(dlt);

    *stsP &= ~0xF006000;
        
    if (dlt < 0) 
    {
        fwP->status |= 0x4000;
    } 
    else 
    {
        fwP->status |= 0x2000;
    }

    if (ang >= 5461) 
    {
        *stsP |= 0x1000000;
    }
        
    if (ang >= 16384) 
    {
        *stsP |= 0x2000000;
    }
        
    if (ang >= 21845) 
    {
        *stsP |= 0x4000000;
    }
        
    if (ang >= 27306) 
    {
        *stsP |= 0x8000000;
    }

    mtxP = &ewP->mlwP->owP->mtx;

    pos = fwP->tgt_pos;

    *stsP &= ~0x1000;

    if ((*stsP & 0x2)) 
    {
        if (bhEne19_CollisionCircle2Oval(mtxP, fwP->atk_rng_a_far, fwP->atk_rng_b_far, &pos, 0) != 0) 
        {
            *stsP |=  0x1000;
        } 
        else 
        {
            *stsP &= ~0x2;
        }
    } 
    else 
    {
        if (bhEne19_CollisionCircle2Oval(mtxP, fwP->atk_rng_a_near, fwP->atk_rng_b_near, &pos, 0) != 0) 
        {
            *stsP |= 0x1002;
        }
    }
    }
}

// 100% matching!
static void bhEne19_PositonFix(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_POINT3* vaP; 
    int sts;         
    char** tblP;     
    NJS_VECTOR vct; 
    NJS_POINT3* vzP; 
	static const char FixDatLL[7] = { 0, 1, 22, 23, 24, 25, -1 };
	static const char FixDatLR[7] = { 0, 1, 18, 19, 20, 21, -1 };
	static const char FixDatAL[9] = { 0, 1,  2,  3, 14, 15, 16, 17, -1 };
	static const char FixDatAR[9] = { 0, 1,  2,  3,  6,  7,  8,  9, -1 };
	static char* FixDatTbl[2][4] = 
	{
		{ (char*)FixDatLL, (char*)FixDatLR, (char*)FixDatAL, (char*)FixDatAR },
		{ (char*)FixDatLR, (char*)FixDatLL, (char*)FixDatAR, (char*)FixDatAL } 
	};

    sts = fwP->status;
    
    vaP = &fwP->fix_adj;
    
    if ((sts & 0x30000)) 
    {
        if ((sts & 0x8)) 
        {
            tblP = FixDatTbl[1];
        } 
        else
        {
            tblP = FixDatTbl[0];
        }
        
        if ((!(sts & 0x10000)) && ((sts & 0x20000))) 
        {
            tblP++;
        }
        
        bhCalcFixOffset(ewP, *tblP, NULL, vaP);
    } 
    else 
    {
        if (njScalor2(vaP) > 0.25f) 
        {
            njUnitVector(vaP);
            
            vaP->x *= 0.25f;
            vaP->y *= 0.25f;
            vaP->z *= 0.25f;
        }
        else
        {
            vaP->x *= 0.96f;
            vaP->y *= 0.96f;
            vaP->z *= 0.96f;
        }
    }
    
    vzP = (NJS_POINT3*)&lcmat[0][8];
    
    njUnitRotPortion(lcmat);
    
    njRotateY(lcmat, -ewP->ay);
    
    njCalcVector(lcmat, vaP, &vct);
    
    njTransposeMatrix(lcmat);
    
    njScaleV(lcmat, &vct);
    
    njSubVector((NJS_VECTOR*)&ewP->px, vzP);
    
    vaP = (NJS_POINT3*)&lcmat;
    
    fwP->adj_vx = *vaP;
    fwP->adj_vz = *vzP;
}

// 99.55% matching
static void bhEne19_HeadTurn(BH_PWORK* ewP, FW_WORK* fwP, int mode)
{
    O_WORK* owP;        
    NJS_CNK_OBJECT* objP; 
    NJS_POINT3* posP; // needs use    
    int dlt;              
    int ang;              
    
    owP = ewP->mlwP->owP;    

    if (mode != 0)
    {
        objP = &ewP->mlwP->objP[5];       
        
        ang = objP->ang[1]; 
        
        dlt = (short)(((int)(10430.381f * atan2f(owP[5].mtx[12] - fwP->tgt_pos.x, owP[5].mtx[14] - fwP->tgt_pos.z)) - ewP->ay) - ang);
        
        ang += dlt / 8;

        if ((short)ang < -7281) 
        {
            ang = -7281;
        }
        else if ((short)ang > 7281) 
        {
            ang = 7281;
        }

        objP[0].ang[1] = ang;
        objP[1].ang[1] = 0;         

        owP[4].flg |= 0x2;
        owP[5].flg |= 0x2;
    }
    else
    {
        owP[4].flg &= ~0x2;
        owP[5].flg &= ~0x2;
    }
}

// 100% matching!
static int bhEne19_AttackHitCheck(BH_PWORK* ewP, TY_ARM_NO arm_no, float ar, int* angP) 
{
    int hit;        
    NJS_SPHERE spr; 
    FW_WORK* fwP;   
    int dir;       
	static const TY_OBJ_MODE AtkObj[2][2] =
	{
		{ TY_OBJ_ARM_L1, TY_OBJ_ARM_L2 }, 
    	{ TY_OBJ_ARM_R1, TY_OBJ_ARM_R2 }  
	};
	static const NJS_POINT3 AtkOff[2] = 
	{
		{  1.0f, -1.0f,  1.0f },
   	    {  1.0f,  1.0f,  1.0f }
	};
    
    fwP = (FW_WORK*)ewP->exp0;
    
    arm_no &= 0x1;
    
    spr.r = ar;
    
    hit = 0;

    njCalcPoint(&ewP->mlwP->owP[AtkObj[arm_no][0]].mtx, (NJS_POINT3*)&AtkOff[arm_no], &spr.c);

    if (njCollisionCheckSC(&spr, &plp->watr) != 0) 
    {
        hit = 1;
    } 
    else 
    {
        njCalcPoint(&ewP->mlwP->owP[AtkObj[arm_no][1]].mtx, (NJS_POINT3*)&AtkOff[arm_no], &spr.c);
        
        if (njCollisionCheckSC(&spr, &plp->watr) != 0) 
        {
            hit = 1;
        }
        else
        {
            hit = 0;
        }
    }

    if (hit != 0) 
    {
        dir = (fwP->tgt_ang - 16384) / 4;
        
        if (arm_no == 1) 
        {
            dir = ewP->ay - dir;
        }
        else 
        {
            dir = ewP->ay + dir;
        }
        
        *angP = dir;
        
        hit = 1;
    }
    else 
    {
        hit = 0;
    }

    return hit;
}

// 100% matching!
static void bhEne19_CalcEnemy(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_POINT3* srcP, *dstP;
    O_WORK* owP;
    
    bhCalcModel(ewP);
    
    owP = &ewP->mlwP->owP[fwP->watr_top];
    
    srcP = &ewP->watr.c1;
    dstP = (NJS_POINT3*)&owP->mtx[12];
    
    *srcP = *dstP;
    
    owP = &owP[19 - fwP->watr_top];
    
    srcP = &ewP->watr.c2;
    dstP = (NJS_POINT3*)&owP->mtx[12];
    
    *srcP = *dstP;
    
    ewP->watr.c2.x = (ewP->watr.c2.x + owP[4].mtx[12]) / 2.0f;
    ewP->watr.c2.y = (ewP->watr.c2.y + owP[4].mtx[13]) / 2.0f;
    ewP->watr.c2.z = (ewP->watr.c2.z + owP[4].mtx[14]) / 2.0f;
    
    ewP->watr.r = fwP->watr_rad;
}

// 
// Start address: 0x1f4460
static void bhEne19_DmgCheck(BH_PWORK* ewP, FW_WORK* fwP)
{
	NJS_POINT3 dir;
	int dst;
	int flg;
	int eff_typ;
	DD_WORK* ddP;
	int* stsP;
	static const DD_WORK DmgDat[21] =
	{
		{ { -1, -1, -1 }, { -1, -1, -1 },  0 },
		{ { -1, -1, -1 }, { -1, -1, -1 },  0 },
		{ {  0, -1, -1 }, { 10, -1, -1 }, 14 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  2,  2,  1 }, { -1, -1, -1 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  6,  6,  6 }, { 11, 10,  9 }, 14 },
		{ {  1,  0,  0 }, { -1, -1, -1 },  8 },
		{ {  0,  0,  0 }, { 11, 10,  9 },  8 },
		{ {  8,  8,  8 }, { -1, -1, -1 }, 14 },
		{ {  1,  1, -1 }, { -1, -1, -1 }, 14 },
		{ {  5,  5,  5 }, { -1, -1, -1 }, 14 },
		{ {  3,  3,  3 }, { -1, -1, -1 }, 14 },
		{ {  1,  1, -1 }, { -1, -1, -1 }, 14 },
		{ { 11, 11, 11 }, { -1, -1, -1 }, 14 },
		{ {  7,  7,  1 }, { -1, -1, -1 }, 14 },
		{ { 11, 11, 11 }, { -1, -1, -1 }, 14 }
	};
	// Line 3221, Address: 0x1f4460, Func Offset: 0
	// Line 3250, Address: 0x1f4480, Func Offset: 0x20
	// Line 3251, Address: 0x1f44a4, Func Offset: 0x44
	// Line 3252, Address: 0x1f44b0, Func Offset: 0x50
	// Line 3253, Address: 0x1f44bc, Func Offset: 0x5c
	// Line 3255, Address: 0x1f44c8, Func Offset: 0x68
	// Line 3260, Address: 0x1f44d0, Func Offset: 0x70
	// Line 3263, Address: 0x1f44e0, Func Offset: 0x80
	// Line 3266, Address: 0x1f44ec, Func Offset: 0x8c
	// Line 3268, Address: 0x1f4504, Func Offset: 0xa4
	// Line 3271, Address: 0x1f4508, Func Offset: 0xa8
	// Line 3268, Address: 0x1f450c, Func Offset: 0xac
	// Line 3271, Address: 0x1f4520, Func Offset: 0xc0
	// Line 3272, Address: 0x1f4548, Func Offset: 0xe8
	// Line 3276, Address: 0x1f4564, Func Offset: 0x104
	// Line 3279, Address: 0x1f457c, Func Offset: 0x11c
	// Line 3280, Address: 0x1f4580, Func Offset: 0x120
	// Line 3279, Address: 0x1f458c, Func Offset: 0x12c
	// Line 3280, Address: 0x1f4590, Func Offset: 0x130
	// Line 3283, Address: 0x1f45ac, Func Offset: 0x14c
	// Line 3284, Address: 0x1f45c0, Func Offset: 0x160
	// Line 3285, Address: 0x1f45c4, Func Offset: 0x164
	// Line 3292, Address: 0x1f45c8, Func Offset: 0x168
	// Line 3293, Address: 0x1f45cc, Func Offset: 0x16c
	// Line 3294, Address: 0x1f45e0, Func Offset: 0x180
	// Line 3295, Address: 0x1f45f4, Func Offset: 0x194
	// Line 3297, Address: 0x1f4604, Func Offset: 0x1a4
	// Line 3299, Address: 0x1f462c, Func Offset: 0x1cc
	// Line 3302, Address: 0x1f463c, Func Offset: 0x1dc
	// Line 3305, Address: 0x1f4654, Func Offset: 0x1f4
	// Line 3306, Address: 0x1f4658, Func Offset: 0x1f8
	// Line 3305, Address: 0x1f465c, Func Offset: 0x1fc
	// Line 3306, Address: 0x1f467c, Func Offset: 0x21c
	// Line 3308, Address: 0x1f4688, Func Offset: 0x228
	// Line 3309, Address: 0x1f4694, Func Offset: 0x234
	// Line 3310, Address: 0x1f46a0, Func Offset: 0x240
	// Line 3313, Address: 0x1f46bc, Func Offset: 0x25c
	// Line 3317, Address: 0x1f46d4, Func Offset: 0x274
	// Line 3318, Address: 0x1f46e4, Func Offset: 0x284
	// Line 3320, Address: 0x1f4700, Func Offset: 0x2a0
	// Line 3323, Address: 0x1f4704, Func Offset: 0x2a4
	// Line 3325, Address: 0x1f470c, Func Offset: 0x2ac
	// Line 3326, Address: 0x1f471c, Func Offset: 0x2bc
	// Line 3328, Address: 0x1f4728, Func Offset: 0x2c8
	// Line 3330, Address: 0x1f4730, Func Offset: 0x2d0
	// Line 3336, Address: 0x1f4748, Func Offset: 0x2e8
	// Line 3337, Address: 0x1f475c, Func Offset: 0x2fc
	// Func End, Address: 0x1f477c, Func Offset: 0x31c
	scePrintf("bhEne19_DmgCheck - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4780
static void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, NJS_POINT3* dirP)
{
	//NJS_POINT3 off;
	//EO_WORK* eoP;
	//int i;
	//NJS_MATRIX* mtxP;
	//int i;
	NJS_MATRIX* mtxP;
	NJS_POINT3* posP;
	NJS_POINT3 dir;
	float scl;
	int djnt_no;
	//NJS_POINT3 off;
	//NJS_POINT3 off;
	//EO_WORK* eoP;
	int i;
	NJS_POINT3 vct;
	EO_WORK* eoP;
	NJS_POINT3 off;
	float off_z;
	int* effP;
	static const EO_WORK OffTbl[26] =
	{
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  1.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  5.0f,  5.0f },
		{  0.0f,  0.0f,  6.0f,  3.0f },
		{  0.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f,  0.0f,  4.0f,  4.0f },
		{  1.5f,  0.0f,  3.0f,  3.0f },
		{  1.5f,  0.0f,  3.0f,  3.0f },
		{  1.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  0.0f,  0.0f },
		{  0.0f,  0.0f,  4.0f,  4.0f },
		{ -1.5f,  0.0f,  3.0f,  3.0f },
		{ -1.5f,  0.0f,  3.0f,  3.0f },
		{ -1.0f,  0.0f,  2.0f,  2.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f, -2.0f,  2.0f,  6.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f },
		{  0.0f,  0.0f,  1.0f,  2.0f }
	};
	static const int EffTbl[12][4] = 
	{
		{ 0, 0xFF800000,    4198400,  14 },
		{ 0, 0xFF800000,    4198400,  15 },
		{ 0, 0xFF800000,    4198400,  16 },
		{ 1,          1,          5, 306 },
		{ 1,          0,          1, 305 },
		{ 2,     131072,         32, 298 },
		{ 3,          1,          0,   0 },
		{ 3,          1,          1,   0 },
		{ 3,          1,          2,   0 },
		{ 4,          1, 0x80000000,   0 },
		{ 4,          1, 0x80000001,   0 },
		{ 4,          1, 0x80000002,   0 }
	};
	// Line 3347, Address: 0x1f4780, Func Offset: 0
	// Line 3398, Address: 0x1f479c, Func Offset: 0x1c
	// Line 3347, Address: 0x1f47a4, Func Offset: 0x24
	// Line 3403, Address: 0x1f47a8, Func Offset: 0x28
	// Line 3398, Address: 0x1f47ac, Func Offset: 0x2c
	// Line 3403, Address: 0x1f47c0, Func Offset: 0x40
	// Line 3405, Address: 0x1f4808, Func Offset: 0x88
	// Line 3410, Address: 0x1f484c, Func Offset: 0xcc
	// Line 3412, Address: 0x1f4858, Func Offset: 0xd8
	// Line 3413, Address: 0x1f4898, Func Offset: 0x118
	// Line 3416, Address: 0x1f48b8, Func Offset: 0x138
	// Line 3413, Address: 0x1f48c0, Func Offset: 0x140
	// Line 3416, Address: 0x1f48d4, Func Offset: 0x154
	// Line 3413, Address: 0x1f48d8, Func Offset: 0x158
	// Line 3414, Address: 0x1f48e8, Func Offset: 0x168
	// Line 3416, Address: 0x1f48ec, Func Offset: 0x16c
	// Line 3418, Address: 0x1f4900, Func Offset: 0x180
	// Line 3425, Address: 0x1f4908, Func Offset: 0x188
	// Line 3426, Address: 0x1f4920, Func Offset: 0x1a0
	// Line 3428, Address: 0x1f4928, Func Offset: 0x1a8
	// Line 3429, Address: 0x1f4940, Func Offset: 0x1c0
	// Line 3430, Address: 0x1f4958, Func Offset: 0x1d8
	// Line 3431, Address: 0x1f4988, Func Offset: 0x208
	// Line 3435, Address: 0x1f49b0, Func Offset: 0x230
	// Line 3439, Address: 0x1f49bc, Func Offset: 0x23c
	// Line 3431, Address: 0x1f49c0, Func Offset: 0x240
	// Line 3432, Address: 0x1f49cc, Func Offset: 0x24c
	// Line 3439, Address: 0x1f49d4, Func Offset: 0x254
	// Line 3432, Address: 0x1f49dc, Func Offset: 0x25c
	// Line 3439, Address: 0x1f49e0, Func Offset: 0x260
	// Line 3432, Address: 0x1f49e4, Func Offset: 0x264
	// Line 3433, Address: 0x1f4a04, Func Offset: 0x284
	// Line 3434, Address: 0x1f4a1c, Func Offset: 0x29c
	// Line 3435, Address: 0x1f4a30, Func Offset: 0x2b0
	// Line 3441, Address: 0x1f4a68, Func Offset: 0x2e8
	// Line 3444, Address: 0x1f4a74, Func Offset: 0x2f4
	// Line 3445, Address: 0x1f4ab4, Func Offset: 0x334
	// Line 3448, Address: 0x1f4ad0, Func Offset: 0x350
	// Line 3445, Address: 0x1f4ad8, Func Offset: 0x358
	// Line 3448, Address: 0x1f4adc, Func Offset: 0x35c
	// Line 3445, Address: 0x1f4ae0, Func Offset: 0x360
	// Line 3448, Address: 0x1f4af0, Func Offset: 0x370
	// Line 3445, Address: 0x1f4af8, Func Offset: 0x378
	// Line 3448, Address: 0x1f4afc, Func Offset: 0x37c
	// Line 3445, Address: 0x1f4b08, Func Offset: 0x388
	// Line 3448, Address: 0x1f4b18, Func Offset: 0x398
	// Line 3449, Address: 0x1f4b20, Func Offset: 0x3a0
	// Line 3452, Address: 0x1f4b2c, Func Offset: 0x3ac
	// Line 3458, Address: 0x1f4b34, Func Offset: 0x3b4
	// Line 3460, Address: 0x1f4b40, Func Offset: 0x3c0
	// Line 3457, Address: 0x1f4b44, Func Offset: 0x3c4
	// Line 3460, Address: 0x1f4b48, Func Offset: 0x3c8
	// Line 3458, Address: 0x1f4b50, Func Offset: 0x3d0
	// Line 3460, Address: 0x1f4b54, Func Offset: 0x3d4
	// Line 3458, Address: 0x1f4b64, Func Offset: 0x3e4
	// Line 3460, Address: 0x1f4b68, Func Offset: 0x3e8
	// Line 3461, Address: 0x1f4b74, Func Offset: 0x3f4
	// Line 3462, Address: 0x1f4b80, Func Offset: 0x400
	// Line 3464, Address: 0x1f4b94, Func Offset: 0x414
	// Line 3472, Address: 0x1f4ba0, Func Offset: 0x420
	// Line 3464, Address: 0x1f4ba8, Func Offset: 0x428
	// Line 3465, Address: 0x1f4bb4, Func Offset: 0x434
	// Line 3472, Address: 0x1f4bc0, Func Offset: 0x440
	// Line 3465, Address: 0x1f4bc4, Func Offset: 0x444
	// Line 3466, Address: 0x1f4bd0, Func Offset: 0x450
	// Line 3467, Address: 0x1f4bf8, Func Offset: 0x478
	// Line 3468, Address: 0x1f4c0c, Func Offset: 0x48c
	// Line 3469, Address: 0x1f4c48, Func Offset: 0x4c8
	// Line 3470, Address: 0x1f4c60, Func Offset: 0x4e0
	// Line 3472, Address: 0x1f4c9c, Func Offset: 0x51c
	// Line 3474, Address: 0x1f4cb4, Func Offset: 0x534
	// Line 3483, Address: 0x1f4cbc, Func Offset: 0x53c
	// Line 3484, Address: 0x1f4cc0, Func Offset: 0x540
	// Line 3483, Address: 0x1f4cc4, Func Offset: 0x544
	// Line 3485, Address: 0x1f4ce4, Func Offset: 0x564
	// Line 3487, Address: 0x1f4cf8, Func Offset: 0x578
	// Line 3485, Address: 0x1f4cfc, Func Offset: 0x57c
	// Line 3487, Address: 0x1f4d04, Func Offset: 0x584
	// Line 3488, Address: 0x1f4d0c, Func Offset: 0x58c
	// Line 3489, Address: 0x1f4d20, Func Offset: 0x5a0
	// Line 3491, Address: 0x1f4d2c, Func Offset: 0x5ac
	// Line 3497, Address: 0x1f4d34, Func Offset: 0x5b4
	// Line 3499, Address: 0x1f4d40, Func Offset: 0x5c0
	// Line 3497, Address: 0x1f4d44, Func Offset: 0x5c4
	// Line 3501, Address: 0x1f4d48, Func Offset: 0x5c8
	// Line 3499, Address: 0x1f4d4c, Func Offset: 0x5cc
	// Line 3501, Address: 0x1f4d64, Func Offset: 0x5e4
	// Line 3504, Address: 0x1f4d6c, Func Offset: 0x5ec
	// Line 3505, Address: 0x1f4dac, Func Offset: 0x62c
	// Line 3508, Address: 0x1f4dcc, Func Offset: 0x64c
	// Line 3505, Address: 0x1f4dd4, Func Offset: 0x654
	// Line 3506, Address: 0x1f4df8, Func Offset: 0x678
	// Line 3508, Address: 0x1f4dfc, Func Offset: 0x67c
	// Line 3509, Address: 0x1f4e08, Func Offset: 0x688
	// Line 3513, Address: 0x1f4e14, Func Offset: 0x694
	// Line 3514, Address: 0x1f4e18, Func Offset: 0x698
	// Func End, Address: 0x1f4e3c, Func Offset: 0x6bc
	scePrintf("bhEne19_SetDmgEffect - UNIMPLEMENTED!\n");
}

// 100% matching!
static int bhEne19_CollisionCircle2Oval(NJS_MATRIX* basP, float ra, float rb, NJS_POINT3* posP, float rc)
{
    float dst;      
    NJS_VECTOR vct; 
    NJS_POINT3 dlt;
    float dr;       
	static const NJS_MATRIX UniMtx = 
	{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

    if (basP == NULL) 
    {
        basP = (NJS_MATRIX*)&UniMtx;
    }
    
    vct.x = posP->x - basP[0][12];
    vct.y = 0;
    vct.z = posP->z - basP[0][14];
    
    dst = njScalor2(&vct);
    
    njSetMatrix(lcmat, basP);
    
    njInvertMatrix(lcmat);
    
    njCalcPoint(lcmat, posP, &dlt);
    
    dlt.x /= ra;
    dlt.y  = 0;
    dlt.z /= rb;
    
    njUnitVector(&dlt);
    
    dlt.x *= ra;
    dlt.z *= rb;
    
    dr = (rc * rc) + njScalor2(&dlt);
    
    if (dr > dst) 
    {
        njUnitVector(&dlt);
        
        dr = njSqrt(dr);
        
        posP->x = dlt.x * dr;
        posP->y = dlt.y * dr;
        posP->z = dlt.z * dr; 
        
        njCalcPoint(basP, posP, posP);
        
        return 1;
    }
    
    *posP = dlt;
    
    njCalcPoint(basP, posP, posP);
    
    return 0;
}

// 
// Start address: 0x1f5000
static void bhEne19_TyBloodSet(EB_WORK* ebP)
{
	float* prmP;
	int rnd;
	FW_WORK* fwP;
	BH_PWORK* ewP;
	static const float SetPrm[2][3] = 
	{
		{ 18.0f,  0.5f,  1.0f },
		{  4.0f,  1.0f,  2.0f }
	};
	// Line 3606, Address: 0x1f5000, Func Offset: 0
	// Line 3607, Address: 0x1f5018, Func Offset: 0x18
	// Line 3608, Address: 0x1f501c, Func Offset: 0x1c
	// Line 3616, Address: 0x1f5024, Func Offset: 0x24
	// Line 3617, Address: 0x1f5040, Func Offset: 0x40
	// Line 3618, Address: 0x1f504c, Func Offset: 0x4c
	// Line 3622, Address: 0x1f5088, Func Offset: 0x88
	// Line 3618, Address: 0x1f508c, Func Offset: 0x8c
	// Line 3622, Address: 0x1f5090, Func Offset: 0x90
	// Line 3624, Address: 0x1f50b0, Func Offset: 0xb0
	// Line 3626, Address: 0x1f50c8, Func Offset: 0xc8
	// Line 3631, Address: 0x1f50d0, Func Offset: 0xd0
	// Line 3626, Address: 0x1f50d4, Func Offset: 0xd4
	// Line 3631, Address: 0x1f50d8, Func Offset: 0xd8
	// Line 3626, Address: 0x1f50dc, Func Offset: 0xdc
	// Line 3627, Address: 0x1f50e8, Func Offset: 0xe8
	// Line 3629, Address: 0x1f50f4, Func Offset: 0xf4
	// Line 3627, Address: 0x1f50f8, Func Offset: 0xf8
	// Line 3628, Address: 0x1f5104, Func Offset: 0x104
	// Line 3629, Address: 0x1f5118, Func Offset: 0x118
	// Line 3630, Address: 0x1f5134, Func Offset: 0x134
	// Line 3631, Address: 0x1f5148, Func Offset: 0x148
	// Line 3632, Address: 0x1f515c, Func Offset: 0x15c
	// Line 3633, Address: 0x1f5184, Func Offset: 0x184
	// Line 3632, Address: 0x1f5188, Func Offset: 0x188
	// Line 3633, Address: 0x1f5194, Func Offset: 0x194
	// Line 3634, Address: 0x1f51b8, Func Offset: 0x1b8
	// Line 3635, Address: 0x1f5210, Func Offset: 0x210
	// Line 3636, Address: 0x1f5268, Func Offset: 0x268
	// Line 3638, Address: 0x1f5290, Func Offset: 0x290
	// Line 3636, Address: 0x1f5294, Func Offset: 0x294
	// Line 3638, Address: 0x1f52a8, Func Offset: 0x2a8
	// Line 3636, Address: 0x1f52b0, Func Offset: 0x2b0
	// Line 3638, Address: 0x1f52e4, Func Offset: 0x2e4
	// Line 3639, Address: 0x1f52fc, Func Offset: 0x2fc
	// Line 3640, Address: 0x1f5304, Func Offset: 0x304
	// Line 3642, Address: 0x1f530c, Func Offset: 0x30c
	// Func End, Address: 0x1f5328, Func Offset: 0x328
	scePrintf("bhEne19_TyBloodSet - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_ClawReset(BH_PWORK* ewP, FW_WORK* fwP)
{
    NJS_CNK_OBJECT* objP;
    NJS_POINT3* posP;

    objP = ewP->mlwP->objP;
    posP = fwP->ClwPos;

    *(NJS_POINT3*)objP[10].pos = *posP++;
    *(NJS_POINT3*)objP[11].pos = *posP++;
    *(NJS_POINT3*)objP[12].pos = *posP++;
    *(NJS_POINT3*)objP[13].pos = *posP++;
}

// 
// Start address: 0x1f53a0
static void bhEne19_SoundSet(BH_PWORK* ewP, FW_WORK* fwP)
{
	//int sts;
	int obj_b;
	int obj_a;
	int i;
	int sts;
	int obj;
	int snd_no;
	int SndTbl[20] = 
	{
		    0, 74496,  8961, 16786178, 16851715, 16851716, 74501, 74502, 74503, 74504, 
		74505, 74506, 74507,    74508,    74509,    74510, 74511, 74512, 74513, 74514
	};
	static const NJS_POINT3 WlkOff = {  0.0f, -1.5f,  0.0f };
	static const int EffTbl[15] = {  4, 17, 16, 15, 14, 23, 24,  1, 19, 20,  6,  7,  8,  9,  2 };
	// Line 3670, Address: 0x1f53a0, Func Offset: 0
	// Line 3672, Address: 0x1f53b0, Func Offset: 0x10
	// Line 3670, Address: 0x1f53b4, Func Offset: 0x14
	// Line 3672, Address: 0x1f53bc, Func Offset: 0x1c
	// Line 3695, Address: 0x1f53f0, Func Offset: 0x50
	// Line 3697, Address: 0x1f53f4, Func Offset: 0x54
	// Line 3698, Address: 0x1f53fc, Func Offset: 0x5c
	// Line 3700, Address: 0x1f5424, Func Offset: 0x84
	// Line 3703, Address: 0x1f5428, Func Offset: 0x88
	// Line 3711, Address: 0x1f5464, Func Offset: 0xc4
	// Line 3712, Address: 0x1f5468, Func Offset: 0xc8
	// Line 3714, Address: 0x1f547c, Func Offset: 0xdc
	// Line 3716, Address: 0x1f5494, Func Offset: 0xf4
	// Line 3718, Address: 0x1f54ac, Func Offset: 0x10c
	// Line 3721, Address: 0x1f54b0, Func Offset: 0x110
	// Line 3722, Address: 0x1f54b8, Func Offset: 0x118
	// Line 3723, Address: 0x1f54f4, Func Offset: 0x154
	// Line 3724, Address: 0x1f5500, Func Offset: 0x160
	// Line 3726, Address: 0x1f5504, Func Offset: 0x164
	// Line 3723, Address: 0x1f5508, Func Offset: 0x168
	// Line 3724, Address: 0x1f5514, Func Offset: 0x174
	// Line 3727, Address: 0x1f551c, Func Offset: 0x17c
	// Line 3731, Address: 0x1f5520, Func Offset: 0x180
	// Line 3724, Address: 0x1f552c, Func Offset: 0x18c
	// Line 3725, Address: 0x1f5538, Func Offset: 0x198
	// Line 3726, Address: 0x1f5554, Func Offset: 0x1b4
	// Line 3727, Address: 0x1f5568, Func Offset: 0x1c8
	// Line 3728, Address: 0x1f55a4, Func Offset: 0x204
	// Line 3729, Address: 0x1f55b8, Func Offset: 0x218
	// Line 3730, Address: 0x1f55cc, Func Offset: 0x22c
	// Line 3731, Address: 0x1f55e0, Func Offset: 0x240
	// Line 3734, Address: 0x1f55f8, Func Offset: 0x258
	// Line 3748, Address: 0x1f5600, Func Offset: 0x260
	// Line 3749, Address: 0x1f5610, Func Offset: 0x270
	// Line 3748, Address: 0x1f5614, Func Offset: 0x274
	// Line 3749, Address: 0x1f5620, Func Offset: 0x280
	// Line 3752, Address: 0x1f5628, Func Offset: 0x288
	// Line 3749, Address: 0x1f5634, Func Offset: 0x294
	// Line 3750, Address: 0x1f564c, Func Offset: 0x2ac
	// Line 3752, Address: 0x1f5658, Func Offset: 0x2b8
	// Line 3750, Address: 0x1f5660, Func Offset: 0x2c0
	// Line 3753, Address: 0x1f5694, Func Offset: 0x2f4
	// Line 3755, Address: 0x1f569c, Func Offset: 0x2fc
	// Line 3757, Address: 0x1f56a0, Func Offset: 0x300
	// Line 3753, Address: 0x1f56ac, Func Offset: 0x30c
	// Line 3754, Address: 0x1f56b8, Func Offset: 0x318
	// Line 3755, Address: 0x1f56d4, Func Offset: 0x334
	// Line 3756, Address: 0x1f56e8, Func Offset: 0x348
	// Line 3757, Address: 0x1f5724, Func Offset: 0x384
	// Line 3756, Address: 0x1f5728, Func Offset: 0x388
	// Line 3757, Address: 0x1f5734, Func Offset: 0x394
	// Line 3758, Address: 0x1f5750, Func Offset: 0x3b0
	// Line 3757, Address: 0x1f5758, Func Offset: 0x3b8
	// Line 3758, Address: 0x1f575c, Func Offset: 0x3bc
	// Line 3760, Address: 0x1f5764, Func Offset: 0x3c4
	// Line 3767, Address: 0x1f576c, Func Offset: 0x3cc
	// Line 3765, Address: 0x1f5774, Func Offset: 0x3d4
	// Line 3767, Address: 0x1f5778, Func Offset: 0x3d8
	// Line 3768, Address: 0x1f577c, Func Offset: 0x3dc
	// Line 3767, Address: 0x1f5780, Func Offset: 0x3e0
	// Line 3768, Address: 0x1f578c, Func Offset: 0x3ec
	// Line 3771, Address: 0x1f5794, Func Offset: 0x3f4
	// Line 3774, Address: 0x1f5798, Func Offset: 0x3f8
	// Line 3768, Address: 0x1f579c, Func Offset: 0x3fc
	// Line 3769, Address: 0x1f57a8, Func Offset: 0x408
	// Line 3770, Address: 0x1f57c4, Func Offset: 0x424
	// Line 3771, Address: 0x1f57d8, Func Offset: 0x438
	// Line 3772, Address: 0x1f5814, Func Offset: 0x474
	// Line 3774, Address: 0x1f5824, Func Offset: 0x484
	// Line 3775, Address: 0x1f582c, Func Offset: 0x48c
	// Line 3777, Address: 0x1f5830, Func Offset: 0x490
	// Line 3778, Address: 0x1f5838, Func Offset: 0x498
	// Line 3779, Address: 0x1f583c, Func Offset: 0x49c
	// Line 3782, Address: 0x1f5840, Func Offset: 0x4a0
	// Line 3783, Address: 0x1f5848, Func Offset: 0x4a8
	// Line 3782, Address: 0x1f5850, Func Offset: 0x4b0
	// Line 3783, Address: 0x1f5860, Func Offset: 0x4c0
	// Line 3784, Address: 0x1f5870, Func Offset: 0x4d0
	// Line 3783, Address: 0x1f5878, Func Offset: 0x4d8
	// Line 3784, Address: 0x1f587c, Func Offset: 0x4dc
	// Line 3783, Address: 0x1f5880, Func Offset: 0x4e0
	// Line 3784, Address: 0x1f589c, Func Offset: 0x4fc
	// Line 3783, Address: 0x1f58a0, Func Offset: 0x500
	// Line 3784, Address: 0x1f58ac, Func Offset: 0x50c
	// Line 3785, Address: 0x1f58c0, Func Offset: 0x520
	// Line 3786, Address: 0x1f58c8, Func Offset: 0x528
	// Line 3785, Address: 0x1f58d0, Func Offset: 0x530
	// Line 3786, Address: 0x1f58e0, Func Offset: 0x540
	// Line 3787, Address: 0x1f58f0, Func Offset: 0x550
	// Line 3786, Address: 0x1f58f8, Func Offset: 0x558
	// Line 3787, Address: 0x1f58fc, Func Offset: 0x55c
	// Line 3786, Address: 0x1f5900, Func Offset: 0x560
	// Line 3787, Address: 0x1f591c, Func Offset: 0x57c
	// Line 3786, Address: 0x1f5920, Func Offset: 0x580
	// Line 3787, Address: 0x1f592c, Func Offset: 0x58c
	// Line 3792, Address: 0x1f5940, Func Offset: 0x5a0
	// Func End, Address: 0x1f595c, Func Offset: 0x5bc
	scePrintf("bhEne19_SoundSet - UNIMPLEMENTED!\n");
}

// 100% matching!
static int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP)
{
	unsigned short* atrP;

    atrP = ewP->mnwP[ewP->mtn_no].atrP;
  
    return (atrP != NULL) ? atrP[ewP->frm_no / 65536] : 0;
}

// 100% matching!
static int bhEne19_PlySetDamage(BH_PWORK* plP, FW_WORK* fwP, int dmg_mod)
{
    static const int PlyDmgTbl[4] = { 30, 40, 40, 50 };

    if ((!(fwP->ply_act.p_status & 0x1)) && (!(fwP->status & 0x800)))
    {
        plP->flg |=  0x10004;
        plP->flg &= ~0x40000;
        
        plP->mode0 = 5;
        plP->mode1 = 0;
        plP->mode2 = 0;
        plP->mode3 = 0;
        
        plP->hp -= PlyDmgTbl[dmg_mod];
        
        if ((plP->hp < 0) && (dmg_mod == 0)) 
        {
            dmg_mod = 1;
        }
        
        plP->stflg |= 0x40000;
        plP->stflg |= 0x4000;
        
        fwP->ply_act.p_act_flg =  0;
        fwP->ply_act.p_status  =  1;
        fwP->ply_act.p_act_now = -1;
        
        fwP->ply_mde        = 0;
        fwP->ply_act.p_mode = dmg_mod;
        
        if (((fwP->dir_dlt / 16384) & 0x1)) 
        {
            fwP->ply_act.p_status |= 0x2;
        }
        
        StartVibrationEx(1, 11);
        
        return 1;
    }
    
    return 0;
}

// 
// Start address: 0x1f5ad0
static void bhEne19_PlyMoveMain(BH_PWORK* plP, FW_WORK* fwP)
{
	ATR_WORK* htP;
	int act;
	int* stsP;
	// Line 3880, Address: 0x1f5ad0, Func Offset: 0
	// Line 3887, Address: 0x1f5aec, Func Offset: 0x1c
	// Line 3881, Address: 0x1f5afc, Func Offset: 0x2c
	// Line 3887, Address: 0x1f5b00, Func Offset: 0x30
	// Line 3889, Address: 0x1f5b08, Func Offset: 0x38
	// Line 3890, Address: 0x1f5b14, Func Offset: 0x44
	// Line 3891, Address: 0x1f5b2c, Func Offset: 0x5c
	// Line 3892, Address: 0x1f5b48, Func Offset: 0x78
	// Line 3893, Address: 0x1f5b64, Func Offset: 0x94
	// Line 3897, Address: 0x1f5b7c, Func Offset: 0xac
	// Line 3898, Address: 0x1f5b8c, Func Offset: 0xbc
	// Line 3900, Address: 0x1f5bb8, Func Offset: 0xe8
	// Line 3901, Address: 0x1f5bcc, Func Offset: 0xfc
	// Line 3902, Address: 0x1f5bd0, Func Offset: 0x100
	// Line 3903, Address: 0x1f5bd4, Func Offset: 0x104
	// Line 3907, Address: 0x1f5bdc, Func Offset: 0x10c
	// Line 3908, Address: 0x1f5bf0, Func Offset: 0x120
	// Line 3909, Address: 0x1f5bf4, Func Offset: 0x124
	// Line 3910, Address: 0x1f5bf8, Func Offset: 0x128
	// Line 3913, Address: 0x1f5c00, Func Offset: 0x130
	// Line 3914, Address: 0x1f5c14, Func Offset: 0x144
	// Line 3915, Address: 0x1f5c18, Func Offset: 0x148
	// Line 3916, Address: 0x1f5c1c, Func Offset: 0x14c
	// Line 3919, Address: 0x1f5c24, Func Offset: 0x154
	// Line 3920, Address: 0x1f5c58, Func Offset: 0x188
	// Line 3922, Address: 0x1f5c68, Func Offset: 0x198
	// Line 3923, Address: 0x1f5c78, Func Offset: 0x1a8
	// Line 3924, Address: 0x1f5c88, Func Offset: 0x1b8
	// Line 3925, Address: 0x1f5ca0, Func Offset: 0x1d0
	// Line 3927, Address: 0x1f5ca4, Func Offset: 0x1d4
	// Line 3929, Address: 0x1f5ca8, Func Offset: 0x1d8
	// Line 3930, Address: 0x1f5cb0, Func Offset: 0x1e0
	// Line 3931, Address: 0x1f5cbc, Func Offset: 0x1ec
	// Line 3932, Address: 0x1f5cd0, Func Offset: 0x200
	// Line 3933, Address: 0x1f5cd4, Func Offset: 0x204
	// Line 3935, Address: 0x1f5cdc, Func Offset: 0x20c
	// Line 3936, Address: 0x1f5cf0, Func Offset: 0x220
	// Line 3937, Address: 0x1f5d04, Func Offset: 0x234
	// Line 3938, Address: 0x1f5d08, Func Offset: 0x238
	// Line 3939, Address: 0x1f5d10, Func Offset: 0x240
	// Line 3940, Address: 0x1f5d24, Func Offset: 0x254
	// Line 3943, Address: 0x1f5d28, Func Offset: 0x258
	// Line 3947, Address: 0x1f5d30, Func Offset: 0x260
	// Line 3948, Address: 0x1f5d3c, Func Offset: 0x26c
	// Line 3950, Address: 0x1f5d4c, Func Offset: 0x27c
	// Line 3951, Address: 0x1f5d64, Func Offset: 0x294
	// Line 3953, Address: 0x1f5d68, Func Offset: 0x298
	// Line 3954, Address: 0x1f5d6c, Func Offset: 0x29c
	// Line 3955, Address: 0x1f5d74, Func Offset: 0x2a4
	// Line 3956, Address: 0x1f5d80, Func Offset: 0x2b0
	// Line 3957, Address: 0x1f5d94, Func Offset: 0x2c4
	// Line 3958, Address: 0x1f5d98, Func Offset: 0x2c8
	// Line 3960, Address: 0x1f5da0, Func Offset: 0x2d0
	// Line 3961, Address: 0x1f5db4, Func Offset: 0x2e4
	// Line 3962, Address: 0x1f5dc8, Func Offset: 0x2f8
	// Line 3963, Address: 0x1f5dcc, Func Offset: 0x2fc
	// Line 3964, Address: 0x1f5dd4, Func Offset: 0x304
	// Line 3965, Address: 0x1f5de8, Func Offset: 0x318
	// Line 3975, Address: 0x1f5dec, Func Offset: 0x31c
	// Line 3976, Address: 0x1f5dfc, Func Offset: 0x32c
	// Line 3977, Address: 0x1f5e18, Func Offset: 0x348
	// Line 3980, Address: 0x1f5e24, Func Offset: 0x354
	// Func End, Address: 0x1f5e40, Func Offset: 0x370
	scePrintf("bhEne19_PlyMoveMain - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_PlyDmg042(BH_PWORK* plP, FW_WORK* fwP)
{    
    int dir;   
    float spd; 
    int dlt;  
    int obj;  
	static const int EffTbl[4] = { 20,  9, 16, 13 };

    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0) 
    {
        CallPlayerVoice(1026);
    }
    
    spd = fwP->trw_spd; 
    dir = fwP->trw_dir;
    
    if (spd > 0)
    {
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.075f;
    }
    
    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0)
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 16;
    }
    
    if (fwP->ply_act.p_mtn_rte > 26214) 
    {
        obj = EffTbl[fwP->ply_act.p_act_frm & 0x3];
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[obj].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
}

// 100% matching!
static void bhEne19_PlyDmg043(BH_PWORK* plP, FW_WORK* fwP)
{
    bhEne19_PlyDmg042(plP, fwP);
    
    if ((fwP->ply_act.p_mtn_rte > 26214) && ((fwP->ply_act.p_act_frm & 0x1))) 
    {
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[1].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
}

// 100% matching!
static void bhEne19_PlyDmg044(BH_PWORK* plP, FW_WORK* fwP)
{
    if (fwP->ply_act.p_act_frm < 18)
    {
        plP->flg |=  0xC0000;
    }
    else if (fwP->ply_act.p_act_frm <= 40)
    {
        plP->flg &= ~0x80000;
    }
    else
    {
        plP->flg |=  0xC0000;
    }
	
    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg045(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_act_frm >= 11)
    {
        plP->flg |=  0x40000;
        plP->flg &= ~0x80000;
    }

    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg046_047(BH_PWORK* plP, FW_WORK* fwP)
{
	bhEne19_PlyDmgDie(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg050_051(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1025);
    }

    bhEne19_PlyDmgDie(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg052_053(BH_PWORK* plP, FW_WORK* fwP)
{
    int dir;      
    float spd;    
    ATR_WORK* htP; 
    int i;        
    int dlt;      
    
    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1026);
        
        fwP->bnd_tim = 0;
    }

    dir = fwP->trw_dir;
    
    if (fwP->trw_spd > 0) 
    {
        spd = fwP->trw_spd;
        
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.07f;
    }
    
    if (fwP->bnd_tim == 0) 
    {
        htP = bhCheckWallRefAngle((NJS_POINT3*)&plP->px, 0, plP->ar, plP->ah, &fwP->trw_dir);
        
        if (htP != NULL) 
        {
            static const int EffTbl[4] = {  2,  1, 18, 14 };
            
            fwP->bnd_tim = 1;
                
            fwP->trw_spd *= 0.25f;
                
            sys->ef.flg = 1;
                
            sys->ef.id = 305;
                
            sys->ef.ay = fwP->ewP->ay + 10922;
            sys->ef.ax = 0;
                
            sys->ef.sx = sys->ef.sy = 1.0f;
                
            sys->ef.mdlver = 0;
                
            sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
            
            for (i = 0; (unsigned int)i < 4; i++) 
            {
                *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[EffTbl[i]].mtx[12];
                
                bhSetEffectTb(&sys->ef, NULL, NULL, 0);
            }
            
            if (fwP->ewP->type == 1)
            {
                bhSetRapEff(310, &fwP->e0aP[2], 8);
            }
                
            fwP->snd_no = 9;
        }
    }
    
    if (fwP->ply_act.p_mtn_rte <= 58982) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0) 
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 8;
    }
    
    if (fwP->ply_act.p_act_frm == 18) 
    {
        static const int EffTbl[4] = { 20,  9, 16, 13 };
        int i; 
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        for (i = 0; (unsigned int)i < 4; i++) 
        {
            *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[EffTbl[i]].mtx[12];
            
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        }
    }
}

// 100% matching!
static void bhEne19_PlyDmg117_118(BH_PWORK* plP, FW_WORK* fwP)
{
    int dir;   
    float spd; 
    int dlt;   
    int obj;  
	static const int EffTbl[2] = { 20, 16 };

    plP->flg |= 0x200000;
    
    if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1026);
    }
    
    spd = fwP->trw_spd;
    dir = fwP->trw_dir;
    
    if (spd > 0) 
    {
        plP->px += spd * -njSin(dir);
        plp->pz += spd * -njCos(dir);
        
        fwP->trw_spd -= 0.1f;
    }
    
    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
        dlt = fwP->trw_dir - plP->ay;
        
        if (njCos(dlt) < 0) 
        {
            dlt += 32768;
        }
        
        plP->ay += (short)dlt / 32;
    }
    
    if ((fwP->ply_act.p_mtn_rte < 32768) && ((fwP->ply_act.p_act_frm & 0x1)))
    {
        obj = EffTbl[(fwP->ply_act.p_act_frm & 0x2) / 2];
        
        sys->ef.flg = 1;
        
        sys->ef.id = 305;
        
        sys->ef.ay = fwP->ewP->ay + 10922;
        sys->ef.ax = 0;
        
        sys->ef.sx = sys->ef.sy = 1.0f;
        
        sys->ef.mdlver = 0;
        
        sys->ef.type = fwP->ply_act.p_act_frm & 0x1;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&plP->mlwP->owP[obj].mtx[12];
        
        bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    }
    
    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmgDie(BH_PWORK* plP, FW_WORK* fwP)
{
	PAW_WORK* pawP;

	pawP = &fwP->ply_act;

	if (pawP->p_mtn_rte > 32768)
    {
        if (!(plP->flg & 0x2))
        {
            plP->flg |= 0x2;

            plP->flg   &= ~0x10004;
            plP->stflg &= ~0x10000;

            plP->mode0 = 6;
            plP->mode1 = 0;
            plP->mode2 = 0;
            plP->mode3 = 0;
        }
    }

    if (pawP->p_mtn_rte >= 65536)
    {
        fwP->ply_act.p_status &= ~0x1;

        plP->mtn_add = 0;
    }
}

// 100% matching!
static void bhEne19_PlyDmgRtn(BH_PWORK* plP, FW_WORK* fwP)
{
    if (fwP->ply_act.p_mtn_rte >= 65536)
    {
        plP->mnwP = plP->mnwPb;
        
        plP->flg &= ~0x10004;
        
        plP->stflg &= ~0x10000; 
        plP->stflg &= ~0x4000;
            
        plP->flg &= ~0x4000;
        
        plP->stflg &= ~0x40000;
        
        plP->mode0 = 1;
        plP->mode1 = 0;
        plP->mode2 = 0;
        plP->mode3 = 0;
        
        fwP->ply_act.p_status &= ~0x1;
    }
}

// 100% matching!
static void bhEne19_PlyDmgFal(BH_PWORK* plP, FW_WORK* fwP)
{
    PAW_WORK* pawP; 
    PF_WORK* pfP;  
    int dlt;        
    int dir;       
	float spd;     
	static const PF_WORK PlyFal[3] = 
	{
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.0f, -0.065333336f, 0.0f }, 0.98f, 50.0f, 0                               
		},
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.3f,  0.065333337f, 0.0f }, 0.75f, 50.0f, 1                               
		},
		{
			{ 0.0f, -1.0453334f, 0.0f }, { 0.0f, -0.065333336f, 0.0f }, 0.98f, 25.0f, 0                               
		}
	};
    
    pfP  = &PlyFal[fwP->ewP->type];
    pawP = &fwP->ply_act;

    switch (fwP->ply_mde) 
    {          
    case 0:
        plP->flg |=  0x2;
        plP->flg &= ~0x118;
        
        plP->stflg |= 0x8;
        
        fwP->wnd_spd = pfP->vct_spd;
        
        fwP->ply_mde++;
    case 1:
        if (fwP->tgt_dst > 32.0f)
        {
            plP->flg   &= ~0x10004;
            plP->stflg &= ~0x10000;
            
            plP->mode0 = 6;
            plP->mode1 = 0;
            plP->mode2 = 0;
            plP->mode3 = 0;
            
            fwP->ply_mde++;
        }
    case 2:
        if (pawP->p_mtn_rte <= 49152) 
        {
            dlt = fwP->trw_dir - plP->ay;
            
            if (njCos(dlt) < 0) 
            {
                dlt += 32768;
            }
            
            plP->ay += (short)dlt / 16;
        }
        
        if (pfP->mode != 0) 
        {
            if ((pawP->p_status & 0x2)) 
            {
                plP->ax += 1820;
            } 
            else 
            {
                plP->ax -= 910;
            }
        }
        
        if (fwP->tgt_dst < 500.0f) 
        {
            spd = fwP->trw_spd;
            dir = fwP->trw_dir;
            
            plP->px += spd * -njSin(dir);
            plp->pz += spd * -njCos(dir); 
            
            njAddVector((NJS_VECTOR*)&plP->px, &fwP->wnd_spd);
            
            fwP->trw_spd = spd * pfP->acl_rte;
            
            njAddVector(&fwP->wnd_spd, &pfP->vct_acl);
        } 
        else 
        {
            pawP->p_status &= ~0x1;
            
            plP->ax = 0;
        }
        
        break;
    }
    
    if (pawP->p_mtn_rte >= 65536)
    {
        plP->mtn_add = 0;
    }
}

// 100% matching!
static void bhEne_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num)
{
    pawP->act_tblP = act_tblP;
    
    pawP->tbl_num = tbl_num;
    
    pawP->p_act_now = -1;
    
    pawP->ene_mnwP = ewP->mnwP;
    pawP->p_paramP = ewP->exp0;
}

#pragma divbyzerocheck on

// 100% matching!
static void bhEne_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP)
{
    if ((pawP->p_act_flg & 0x7) == 2)
    {
        pawP->p_act_flg &= ~0x2;
        
        bhEne_PlyActionChange(plP, pawP, pawP->p_act_jmp);
    }
    
    pawP->p_mtn_rte = plP->frm_no / (pawP->p_frm_num - 1);
    
    if (pawP->p_prgP != NULL) 
    {
        pawP->p_prgP(plP, pawP->p_paramP);
    }
    
    pawP->p_act_frm = plP->frm_no / 65536;
    
    if (pawP->p_act_frm == pawP->p_chg_frm) 
    {
        pawP->p_act_flg &= ~0x1;
    }
}

#pragma divbyzerocheck off

// 100% matching!
static int bhEne_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no)
{
    ACT_TBL_WORK* paP;
    
    paP = &pawP->act_tblP[act_no];
    
    if ((!(pawP->p_act_flg & 0x7)) && (pawP->p_act_now != act_no))
    {
        pawP->p_prgP = paP->prgP;
        
        pawP->p_act_now = act_no;
        pawP->p_act_flg = 1;
        
        if (paP->mtn_no != -1)
        {
            plP->mnwP = pawP->ene_mnwP;
            
            plP->mtn_no = paP->mtn_no;
            plP->frm_no = paP->frm_no * 65536;
            
            plP->hokan_count = paP->hkn_cnt;
            plP->hokan_rate  = paP->hkn_lvl * (65536.0 / 255.0);
            
            plP->mtn_add = 65536;
            plP->mtn_md  = (unsigned short)paP->flag;
                
            pawP->p_frm_num = plP->mnwP[paP->mtn_no].frm_num;
            
            pawP->p_act_frm = paP->frm_no;
            pawP->p_act_jmp = paP->act_jmp;
            
            if (pawP->p_act_jmp != -1)
            {
                pawP->p_act_flg |= 0x2;
            }
            
            if (paP->chg_frm != 0xFF) 
            {
                pawP->p_chg_frm = paP->chg_frm;
            } 
            else 
            {
                pawP->p_chg_frm = pawP->p_frm_num - 1;
            }
        }
        
        return 1;
    }
    
    return 0;
}

#pragma divbyzerocheck on

// 100% matching!
static int bhEne_CalcCombRate(BH_PWORK* ewP, COMBWEP_WORK* cwP)
{
	int cmb_lvl;

    cmb_lvl = 0;
    
    cwP += ewP->wpnr_no;

    if (cwP->crit != 0)
    {
        cmb_lvl = (ewP->comb_pnt * 16) / cwP->crit;
    }
    else
    {
        cmb_lvl = 0;
    }

    if ((cmb_lvl & ~0xF))
    {
        cmb_lvl = 15;
    }

    return cmb_lvl;
}

#pragma divbyzerocheck off

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl0(BH_PWORK* ewP, FW_WORK* fwP)
{
	TY_DMG_MODE dmg_lvl; 
    int cmb_lvl;         
    int* flgP;          

	flgP = &fwP->dmg_flg;

    cmb_lvl = bhEne_CalcCombRate(ewP, En19CombWepTbl);
    
    if (ewP->comb_pnt == 0) 
    {
        *flgP &= ~0x6;
    }

    if (ewP->hp < 0)
    {
        dmg_lvl = TY_DMG_LVL4;
    }
    else if ((ewP->comb_flg & 0x1)) 
    {
        dmg_lvl = TY_DMG_LVL2;
    }
    else if ((cmb_lvl >= 12) && (!(*flgP & 0x4)))
    {
		fwP->dmg_flg |= 0x4;

		dmg_lvl = TY_DMG_LVL1;
    }
    else if ((cmb_lvl >= 8) && (!(*flgP & 0x2))) 
    {
		fwP->dmg_flg |= 0x2;

		dmg_lvl = TY_DMG_LVL0;
    }
	else 
	{
		dmg_lvl = TY_DMG_NON;
	}

    return dmg_lvl;
}

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl1(BH_PWORK* ewP, FW_WORK* fwP)
{
	TY_DMG_MODE dmg_lvl;

    bhEne_CalcCombRate(ewP, En19CombWepTbl);

    if ((ewP->hp < 0) && (!(fwP->dmg_flg & 0x20))) 
	{
        fwP->dmg_flg |= 0x20;

        dmg_lvl = TY_DMG_LVL4;
    } 
	else if ((ewP->hp < ((fwP->hp_bak * 50) / 100)) && (!(fwP->dmg_flg & 0x8))) 
	{
        fwP->dmg_flg |= 0x8;

        dmg_lvl = TY_DMG_LVL2;
    } 
	else if ((ewP->comb_flg & 0x1)) 
	{
        dmg_lvl = TY_DMG_LVL0;
    } 
	else 
	{
        dmg_lvl = TY_DMG_NON;
    }

    if ((fwP->ct_pinch == 0) && (!(fwP->dmg_flg & 0x40)))
	{
        fwP->dmg_flg |= 0x40;

        dmg_lvl = TY_DMG_SPECIAL;
    }

    return dmg_lvl;
}

// 100% matching!
static TY_DMG_MODE bhEne19_CheckDmgLvl2(BH_PWORK* ewP, FW_WORK* fwP)
{
    TY_DMG_MODE dmg_lvl; 
    int cmb_lvl;         
    int* flgP;          

    flgP = &fwP->dmg_flg;
    
	cmb_lvl = bhEne_CalcCombRate(ewP, En19CombWepTbl);
    
	if (ewP->comb_pnt == 0) 
	{
        *flgP &= ~0x2;
    }

    if (ewP->hp < 0)
	{
        dmg_lvl = TY_DMG_LVL4;
    }
    else if ((ewP->comb_flg & 0x1)) 
	{
        dmg_lvl = TY_DMG_LVL1;
    }
    else if ((cmb_lvl >= 10) && (!(*flgP & 0x2))) 
	{
        fwP->dmg_flg |= 0x2;

        dmg_lvl = TY_DMG_LVL0;
    }
    else 
	{
        dmg_lvl = TY_DMG_NON;
    }

    return dmg_lvl;
}

// 100% matching!
static R0_WK* bhEne19_SetLeftClaw(ML_WORK* mlwP, TY_OBJ_MODE tgt_bas, TY_OBJ_MODE tgt_obj)
{
	PRM_WRK prm;
	NJS_CNK_OBJECT* objP;

    objP = &mlwP->objP[tgt_obj];

    prm.mtxP = &mlwP->owP[tgt_bas].mtx;
    prm.texP = mlwP->texP;
    prm.mdlP = (NJS_MODEL*)objP->model;

    prm.pos[0] = -objP->pos[0];
    prm.pos[1] =  objP->pos[1];
    prm.pos[2] =  objP->pos[2];

    prm.ang[0] = objP->ang[0];
    prm.ang[1] = 32768 - objP->ang[1];
    prm.ang[2] = -objP->ang[2];

    return (R0_WK*)((bhSetRapEff(312, &prm, 9))->free4);
}

// 100% matching!
static void bhEne19_SetClawPlane(BH_PWORK* ewP, NJS_MATRIX* mtxP, int col, int tim, float src_x, float dst_x)
{
	EFFPRM_WORK Dat307;

	Dat307.src.x = src_x;
    Dat307.src.y = Dat307.src.z = 0;

    Dat307.dst.x = dst_x;
    Dat307.dst.y = Dat307.dst.z = 0;

    Dat307.frm_inc = 0.125f;

    Dat307.tim = tim;

    Dat307.texP = ewP->mlwP->texP;

    Dat307.tex_id = 4;

    Dat307.col = col;

    Dat307.mtxP = mtxP;
	
    bhSetRapEff(307, &Dat307, 12);
}
