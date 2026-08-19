#include "../../../ps2/veronica/prog/en18.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/main.h"

// ENEMY: Alexia's Tentacle 

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

static DMG_REACT DmgReact[21] =
{
    { {0, 1, 0}, {0, 0, 0}, 0 },
    { {0, 1, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {1, 1, 0}, {0, 0, 0}, 0 },
    { {1, 1, 0}, {0, 0, 0}, 0 },
    { {1, 1, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {1, 1, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {1, 1, 0}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 1 },
    { {-1, -1, -1}, {0, 0, 0}, 2 },
    { {-1, -1, -1}, {0, 0, 0}, 1 },
    { {-1, -1, -1}, {0, 0, 0}, 0 },
    { {1, 1, 1}, {0, 0, 0}, 0 },
    { {0, 0, 0}, {0, 0, 0}, 1 },
    { {1, 1, 1}, {0, 0, 0}, 1 }
};

static COMBWEP_WORK CombWepTbl[21] =
{
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 4, {1, 0, 0}, 30, 0 },
    { 10, {4, 3, 1}, 20, 0 },
    { 10, {4, 3, 1}, 20, 0 },
    { 10, {4, 3, 1}, 10, 0 },
    { 0, {0, 0, 0}, 25, 0 },
    { 0, {0, 0, 0}, 25, 0 },
    { 25, {5, 3, 1}, 5, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 10, 0 },
    { 0, {0, 0, 0}, 30, 0 },
    { 25, {5, 4, 2}, 10, 0 },
    { 0, {0, 0, 0}, 60, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 }
};

static COMBJOINT_WORK CombJointTbl[14] =
{
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 },
    { 0, -60 }
};

ENE18_EO ENE18_EO_00[1] =
{
    { { 0.0f, 0.0f, -8.0f }, 0.0f, 0.0f, 0.0f }
};

ENE18_EO ENE18_EO_04[7] =
{
    { { 0.0f, 0.0f, -9.0f }, 5.0f, 2.0f, 1.0f },
    { { 0.0f, 4.5f, -4.5f }, 4.0f, 4.0f, 2.0f },
    { { 0.0f, 6.0f, -6.0f }, 4.0f, 1.0f, 2.0f },
    { { -6.6f, 0.0f, -5.8f }, 1.0f, 3.0f, 1.0f },
    { { -6.0f, 3.5f, -3.5f }, 2.0f, 4.0f, 2.0f },
    { { 6.6f, 0.0f, -5.8f }, 1.0f, 3.0f, 1.0f },
    { { 6.0f, 3.5f, -3.5f }, 2.0f, 4.0f, 2.0f }
};

ENE18_EO ENE18_EO_05[5] =
{
    { { -1.6f, 6.3f, -5.9f }, 4.0f, 1.0f, 5.0f },
    { { -0.4f, 6.3f, -1.6f }, 4.0f, 1.0f, 5.0f },
    { { -4.0f, 2.4f, 3.0f }, 4.0f, 3.0f, 5.0f },
    { { -4.5f, 0.0f, -4.9f }, 2.0f, 4.0f, 5.0f },
    { { 3.4f, 3.0f, -6.1f }, 2.0f, 4.0f, 5.0f }
};

ENE18_EO ENE18_EO_06[7] =
{
    { { -1.3f, 5.0f, -3.9f }, 4.0f, 1.0f, 5.0f },
    { { 0.0f, 6.5f, 0.4f }, 4.0f, 1.0f, 5.0f },
    { { 1.5f, 7.1f, 5.0f }, 4.0f, 1.0f, 5.0f },
    { { -3.6f, 0.0f, 0.6f }, 2.0f, 4.0f, 4.0f },
    { { -4.6f, 0.0f, 4.6f }, 2.0f, 4.0f, 4.0f },
    { { 1.5f, 0.0f, -5.8f }, 2.0f, 4.0f, 4.0f },
    { { 4.2f, 0.0f, -1.0f }, 2.0f, 4.0f, 4.0f }
};

ENE18_EO ENE18_EO_07[6] =
{
    { { 2.6f, 7.1f, 7.2f }, 4.0f, 2.0f, 3.0f },
    { { 1.0f, 4.9f, 3.2f }, 4.0f, 2.0f, 3.0f },
    { { 0.0f, 3.6f, 0.0f }, 3.0f, 1.0f, 3.0f },
    { { -0.4f, 1.1f, -3.7f }, 2.0f, 1.0f, 3.0f },
    { { 2.8f, 2.1f, 2.5f }, 1.0f, 2.0f, 1.0f },
    { { 0.9f, 2.1f, 4.9f }, 1.0f, 2.0f, 1.0f }
};

ENE18_EO ENE18_EO_08[5] =
{
    { { 1.6f, 6.3f, -5.9f }, 4.0f, 1.0f, 5.0f },
    { { 0.4f, 6.3f, -1.6f }, 4.0f, 1.0f, 5.0f },
    { { 4.0f, 2.4f, 3.0f }, 4.0f, 3.0f, 5.0f },
    { { 4.5f, 0.0f, -4.9f }, 2.0f, 4.0f, 5.0f },
    { { -3.4f, 3.0f, -6.1f }, 2.0f, 4.0f, 5.0f }
};

ENE18_EO ENE18_EO_09[7] =
{
    { { 1.3f, 5.0f, -3.9f }, 4.0f, 1.0f, 5.0f },
    { { -0.0f, 6.5f, 0.4f }, 4.0f, 1.0f, 5.0f },
    { { -1.5f, 7.1f, 5.0f }, 4.0f, 1.0f, 5.0f },
    { { 3.6f, 0.0f, 0.6f }, 2.0f, 4.0f, 4.0f },
    { { 4.6f, 0.0f, 4.6f }, 2.0f, 4.0f, 4.0f },
    { { -1.5f, 0.0f, -5.8f }, 2.0f, 4.0f, 4.0f },
    { { -4.2f, 0.0f, -1.0f }, 2.0f, 4.0f, 4.0f }
};

ENE18_EO ENE18_EO_10[6] =
{
    { { -2.6f, 7.1f, 7.2f }, 4.0f, 2.0f, 3.0f },
    { { -1.0f, 4.9f, 3.2f }, 4.0f, 2.0f, 3.0f },
    { { -0.0f, 3.6f, 0.0f }, 3.0f, 1.0f, 3.0f },
    { { 0.4f, 1.1f, -3.7f }, 2.0f, 1.0f, 3.0f },
    { { -2.8f, 2.1f, 2.5f }, 1.0f, 2.0f, 1.0f },
    { { -0.9f, 2.1f, 4.9f }, 1.0f, 2.0f, 1.0f }
};

ENE18_EO ENE18_EO_11[5] =
{
    { { -0.5f, -1.0f, -0.5f }, 4.0f, 4.0f, 4.0f },
    { { -1.5f, 2.0f, 0.0f }, 4.0f, 4.0f, 4.0f },
    { { -0.5f, -1.0f, 5.5f }, 4.0f, 4.0f, 4.0f },
    { { 3.0f, 3.0f, 7.0f }, 4.0f, 4.0f, 4.0f },
    { { 4.0f, 3.5f, 1.5f }, 4.0f, 4.0f, 4.0f }
};

ENE18_EO ENE18_EO_12[8] =
{
    { { 0.0f, 4.0f, 3.3f }, 3.0f, 1.0f, 4.0f },
    { { 0.0f, 5.0f, 7.5f }, 3.0f, 1.0f, 5.0f },
    { { -3.3f, 0.0f, 4.2f }, 2.0f, 2.0f, 5.0f },
    { { -2.6f, 2.8f, 9.3f }, 2.0f, 2.0f, 5.0f },
    { { -5.0f, 1.4f, 4.0f }, 2.0f, 2.0f, 2.0f },
    { { 3.3f, 0.0f, 4.2f }, 2.0f, 2.0f, 5.0f },
    { { 2.6f, 2.8f, 9.3f }, 2.0f, 2.0f, 5.0f },
    { { 5.0f, 1.4f, 4.0f }, 2.0f, 2.0f, 2.0f }
};

ENE18_EO ENE18_EO_13[5] =
{
    { { 0.5f, -1.0f, -0.5f }, 4.0f, 4.0f, 4.0f },
    { { 1.5f, 2.0f, 0.0f }, 4.0f, 4.0f, 4.0f },
    { { 0.5f, -1.0f, 5.5f }, 4.0f, 4.0f, 4.0f },
    { { -3.0f, 3.0f, 7.0f }, 4.0f, 4.0f, 4.0f },
    { { -4.0f, 3.5f, 1.5f }, 4.0f, 4.0f, 4.0f }
};

static ENE18_BLOOD_TBL BloodTbl[14] =
{
    { 1, ENE18_EO_00, 1 },
    { 0, ENE18_EO_04, 7 },
    { 0, ENE18_EO_00, 1 },
    { 0, ENE18_EO_00, 1 },
    { 0, ENE18_EO_04, 7 },
    { 0, ENE18_EO_05, 5 },
    { 0, ENE18_EO_06, 7 },
    { 1, ENE18_EO_07, 6 },
    { 0, ENE18_EO_08, 5 },
    { 0, ENE18_EO_09, 7 },
    { 1, ENE18_EO_10, 6 },
    { 0, ENE18_EO_11, 5 },
    { 0, ENE18_EO_12, 8 },
    { 0, ENE18_EO_13, 5 }
};

static CPCL CapColTab[31] =
{
    { 0, 4, 80 },
    { 0, 5, 60 },
    { 0, 8, 60 },
    { 8, 5, 55 },
    { 5, 6, 55 },
    { 6, 7, 30 },
    { 8, 9, 55 },
    { 9, 10, 30 },
    { 11, 11, 65 },
    { 25, -20, 25 },
    { 12, 12, 65 },
    { 0, -20, 40 },
    { 13, 13, 65 },
    { -25, -20, 25 },
    { 10, 10, 20 },
    { 5, 0, -40 },
    { 7, 7, 20 },
    { -5, 0, -40 },
    { 4, 4, 30 },
    { 40, 90, 0 },
    { 4, 4, 30 },
    { 70, 50, 0 },
    { 4, 4, 30 },
    { 90, 0, 0 },
    { 4, 4, 30 },
    { -40, 90, 0 },
    { 4, 4, 30 },
    { -70, 50, 0 },
    { 4, 4, 30 },
    { -90, 0, 0 },
    { 0, 0, 0 }
};

static P_WORK HeartBeat[13] =
{
    { 0, 0.0f },
    { 10, 900.0f },
    { 15, 1000.0f },
    { 17, 900.0f },
    { 30, 800.0f },
    { 40, 1900.0f },
    { 45, 2000.0f },
    { 47, 1800.0f },
    { 50, 1600.0f },
    { 80, 1000.0f },
    { 90, 500.0f },
    { 120, 0.0f },
    { 999, 0.0f }
};

static P_WORK SpawnAttacker[15] =
{
    { 0, 0.0f },
    { 5, 600.0f },
    { 10, 800.0f },
    { 20, 1000.0f },
    { 25, 1000.0f },
    { 30, 1100.0f },
    { 32, 1800.0f },
    { 25, 2000.0f },
    { 43, 2100.0f },
    { 50, 2140.0f },
    { 56, 2300.0f },
    { 63, 2700.0f },
    { 70, 2950.0f },
    { 75, 3000.0f },
    { 999, 3000.0f }
};

static P_WORK Tentacle[11] =
{
    { 0, 0.0f },
    { 5, 300.0f },
    { 10, 500.0f },
    { 15, 1000.0f },
    { 25, 1000.0f },
    { 30, 1100.0f },
    { 32, 1800.0f },
    { 35, 2000.0f },
    { 115, 2000.0f },
    { 140, 3000.0f },
    { 999, 3000.0f }
};

static P_WORK Tentacle2[11] =
{
    { 0, 0.0f },
    { 5, 300.0f },
    { 10, 500.0f },
    { 15, 1000.0f },
    { 25, 1000.0f },
    { 30, 1100.0f },
    { 32, 1800.0f },
    { 35, 2000.0f },
    { 95, 2000.0f },
    { 114, 3000.0f },
    { 999, 3000.0f }
};

static P_WORK Tentacle3[11] =
{
    { 0, 0.0f },
    { 5, 300.0f },
    { 10, 500.0f },
    { 15, 1000.0f },
    { 25, 1000.0f },
    { 30, 1100.0f },
    { 32, 1800.0f },
    { 35, 2000.0f },
    { 120, 2000.0f },
    { 145, 3000.0f },
    { 999, 3000.0f }
};

static P_WORK Tentacle4[11] =
{
    { 0, 0.0f },
    { 5, 300.0f },
    { 10, 500.0f },
    { 15, 1000.0f },
    { 25, 1000.0f },
    { 30, 1100.0f },
    { 32, 1800.0f },
    { 35, 2000.0f },
    { 100, 2000.0f },
    { 120, 3000.0f },
    { 999, 3000.0f }
};

Mode0_proc bhEne18_Mode0[6] =
{
    bhEne18_Init,
    bhEne18_Move,
    bhEne18_Nage,
    bhEne18_Damage,
    bhEne18_Die,
    bhEne_Event
};

MoveMode2_proc bhEne18_MoveMode2[6] =
{
    bhEne18_MV00,
    bhEne18_MV01,
    bhEne18_MV02,
    bhEne18_MV03,
    bhEne18_MV04,
    bhEne18_MV05
};

// 100% matching!
void bhEne18(BH_PWORK* epw)
{
    bhEne18_Mode0[epw->mode0](epw);
    
    if (((BH_PWORK *)epw->lkwkp)->stflg & 0x01000000) 
    {
        epw->stflg |= 0x01000000;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
    }
    
    bhCalcModel(epw);
}

// 100% matching!
void bhEne18_Init(BH_PWORK* epw) 
{
	BH_PWORK *ep;
    NJS_VECTOR vec;
    int InitAction[10] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int temp;    // NOT from DWARF

    ep = (BH_PWORK *)epw->lkwkp;
    
    if (!(ep->flg & 1) || (ep->id != 0xD)) 
    {
        epw->flg = 0;
        return;
    }
    
    epw->flg |= 0x8000;
    epw->flg &= ~6;
    
    epw->mdflg |= 0x20;
    
    epw->ar = 5.0f;
    epw->ah = 1.0f;
    epw->car = 3.0f;
    epw->mode0 = 1;
    epw->mode1 = 0;
    
    epw->mode2 = InitAction[epw->type];
    
    epw->mode3 = 0;
    epw->hokan_rate = 0x10000;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_md = 0;
    epw->mtn_add = 0x10000;
    epw->frm_no = 0;
    
    if ((-rand() / -2.1474836e9f) > 0.5f) 
    {
        temp = 1;
    }
    else
    {
        temp = -1;
    }
    
    epw->ct1 = temp;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0x18, 8);
        
        *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4) = epw->mlwP->objP;
        *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8) = epw->mlwP[1].objP;
        *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC) = epw->mlwP[2].objP;
        
        *(ATR_WORK **)(epw->exp0 + 0x14) = &sys->mwalp[sys->mwal_n];
        
        sys->mwal_n++;
        
        (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->type = 3;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->w = 0.0f;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->h = 0.0f;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->d = 0.0f;
        (*(ATR_WORK **)(epw->exp0 + 0x14))->attr = 0;
    }

    if (epw->type < 4) return;
    
    epw->flg |= 0x28;
    epw->mdflg |= 1;
    
    ep = (BH_PWORK *)epw->lkwkp;
    
    switch (epw->type)
    {
        case 4:
            epw->watr.c1.x = ep->px;
            epw->watr.c1.y = 18.0f + ep->py;
            epw->watr.c1.z = ep->pz;
            
            epw->watr.c2.x = ep->px;
            epw->watr.c2.y = 5.0f + ep->py;
            epw->watr.c2.z = ep->pz;
            
            epw->watr.r = 11.0f;
            epw->cpcl = CapColTab;
            
            break;
        
        case 5:
            vec.x = -5.0f;
            vec.y = 10.0f;
            vec.z = -0.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c1.x = ep->px + vec.x;
            epw->watr.c1.y = ep->py + vec.y;
            epw->watr.c1.z = ep->pz + vec.z;
            
            vec.x = -15.0f;
            vec.y = 2.0f;
            vec.z = -30.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c2.x = ep->px + vec.x;
            epw->watr.c2.y = ep->py + vec.y;
            epw->watr.c2.z = ep->pz + vec.z;
            
            epw->watr.r = 4.0f;
            
            epw->flg2 |= 0x10;
            
            break;
        
        case 6:
            vec.x = 5.0f;
            vec.y = 10.0f;
            vec.z = 0.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c1.x = ep->px + vec.x;
            epw->watr.c1.y = ep->py + vec.y;
            epw->watr.c1.z = ep->pz + vec.z;
            
            vec.x = 15.0f;
            vec.y = 2.0f;
            vec.z = -30.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c2.x = ep->px + vec.x;
            epw->watr.c2.y = ep->py + vec.y;
            epw->watr.c2.z = ep->pz + vec.z;
            
            epw->watr.r = 4.0f;
            
            epw->flg2 |= 0x10;

            break;
        
        case 7:
            vec.x = 0.0f;
            vec.y = 5.0f;
            vec.z = -10.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c1.x = ep->px + vec.x;
            epw->watr.c1.y = ep->py + vec.y;
            epw->watr.c1.z = ep->pz + vec.z;
            
            vec.x = 0.0f;
            vec.y = 0.0f;
            vec.z = -20.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c2.x = ep->px + vec.x;
            epw->watr.c2.y = ep->py + vec.y;
            epw->watr.c2.z = ep->pz + vec.z;
            
            epw->watr.r = 6.0f;
            
            epw->flg2 |= 0x10;

            break;
        
        case 8:
            vec.x = -10.0f;
            vec.y = 5.0f;
            vec.z = -5.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c1.x = ep->px + vec.x;
            epw->watr.c1.y = ep->py + vec.y;
            epw->watr.c1.z = ep->pz + vec.z;
            
            vec.x = -18.0f;
            vec.y = 0.0f;
            vec.z = -9.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c2.x = ep->px + vec.x;
            epw->watr.c2.y = ep->py + vec.y;
            epw->watr.c2.z = ep->pz + vec.z;
            
            epw->watr.r = 6.0f;
            
            epw->flg2 |= 0x10;

            break;
        
        case 9:
            vec.x = 10.0f;
            vec.y = 5.0f;
            vec.z = -5.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c1.x = ep->px + vec.x;
            epw->watr.c1.y = ep->py + vec.y;
            epw->watr.c1.z = ep->pz + vec.z;
            
            vec.x = 18.0f;
            vec.y = 0.0f;
            vec.z = -9.0f;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &vec, &vec);
            
            epw->watr.c2.x = ep->px + vec.x;
            epw->watr.c2.y = ep->py + vec.y;
            epw->watr.c2.z = ep->pz + vec.z;
            
            epw->watr.r = 6.0f;
            
            epw->flg2 |= 0x10;

            break;
    }
}

// 100% matching!
void bhEne18_Move(BH_PWORK* epw)
{
    bhEne18_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne18_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
        case 0:
            epw->mlwP->objP = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
        
            epw->shp_ct = 0.0f;
            epw->mdflg &= ~2;
            epw->mode3++;
            
            break;
    }
}

// 100% matching!
void bhEne18_MV01(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            epw->mdflg |= 2;
            epw->ct0 = 0;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            epw->shp_ct = bhEne_GetShapeCnt(SpawnAttacker, epw->ct0);
            
            if (epw->shp_ct < 1000.0f)
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
            } 
            else 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct -= 1000.0f;
            }
            
            epw->ct0++;
            
            if (epw->ct0 > 120) 
            {
                epw->ct0 = 0;
            }
            
            break;
    }
}

// 100% matching!
void bhEne18_MV02(BH_PWORK* epw) 
{
    NJS_POINT3 pos[3] = 
    {
        { 0.0f, 0.0f, -20.0f }, 
        { -18.0f, 0.0f, -10.0f }, 
        { 18.0f, 0.0f, -10.0f } 
    };
    BH_PWORK *ep;

    switch (epw->mode3)
    {
        case 0:
            epw->mdflg |= 2;
            epw->ct0 = 0;
            epw->ct1 = bhEne13_GetHatchNo((BH_PWORK *)epw->lkwkp);
            
            ep = (BH_PWORK *)epw->lkwkp;
            
            (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 1;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &pos[epw->ct1], (NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px));
            njAddVector((NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px), (NJS_VECTOR *)&ep->px);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            epw->shp_ct = bhEne_GetShapeCnt(SpawnAttacker, epw->ct0);
            
            if (epw->shp_ct < 1000.0f)
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            
            else if (epw->shp_ct < 2000.0f) 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct -= 1000.0f;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = 10.0f;
            }
            else 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct = 3000.0f - epw->shp_ct;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            
            epw->ct0++;
            
            if (epw->ct0 == 30) 
            {
                bhEne13_PutAttacker((BH_PWORK *)epw->lkwkp, epw->ct1);
            }
            
            if (epw->ct0 > 75) 
            {
                epw->mdflg &= ~2;
                epw->shp_ct = 0.0f;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
            }
            
            break;
    }
}

// 100% matching!
void bhEne18_MV03() 
{

}

// 100% matching!
void bhEne18_MV04(BH_PWORK* epw) 
{
    NJS_POINT3 pos[3] = 
    {
        { 0.0f, 0.0f, -20.0f }, 
        { -18.0f, 0.0f, -10.0f }, 
        { 18.0f, 0.0f, -10.0f } 
    };
    BH_PWORK *ep;

    switch (epw->mode3)
    {
        case 0:
            epw->mdflg |= 2;
            epw->ct0 = 0;
            
            epw->ct1 = bhEne13_GetHatchNo((BH_PWORK *)epw->lkwkp);
            epw->ct2 = bhEne13_GetTentaNo((BH_PWORK *)epw->lkwkp);
            
            ep = (BH_PWORK *)epw->lkwkp;
            
            (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 1;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &pos[epw->ct1], (NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px));
            njAddVector((NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px), (NJS_VECTOR *)&ep->px);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->type == 1) 
            {
                epw->shp_ct = bhEne_GetShapeCnt(Tentacle3, epw->ct0);
            }
            else 
            {
                epw->shp_ct = bhEne_GetShapeCnt(Tentacle, epw->ct0);
            }
            
            if (epw->shp_ct < 1000.0f) 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            else if (epw->shp_ct < 2000.0f) 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct -= 1000.0f;
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = 10.0f;
            }
            else 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct = 3000.0f - epw->shp_ct;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            
            epw->ct0++;
            
            if (epw->ct0 == 30) 
            {
                bhEne13_Tentacle((BH_PWORK *)epw->lkwkp, epw->ct2);
            }
            
            if (epw->ct0 > 145) 
            {
                epw->mdflg &= ~2;
                epw->shp_ct = 0.0f;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
            }
            
            break;
    }
}

// 100% matching!
void bhEne18_MV05(BH_PWORK* epw) 
{
    NJS_POINT3 pos[3] = 
    {
        { 0.0f, 0.0f, -20.0f }, 
        { -18.0f, 0.0f, -10.0f }, 
        { 18.0f, 0.0f, -10.0f } 
    };
    BH_PWORK *ep;

    switch (epw->mode3)
    {
        case 0:
            epw->mdflg |= 2;
            epw->ct0 = 0;
            
            epw->ct1 = bhEne13_GetHatchNo((BH_PWORK *)epw->lkwkp);
            epw->ct2 = bhEne13_GetTentaNo((BH_PWORK *)epw->lkwkp);
            
            ep = (BH_PWORK *)epw->lkwkp;
            
            (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 1;
            
            njUnitMatrix(NULL);
            njRotateY(NULL, ep->ay);
            njCalcVector(NULL, &pos[epw->ct1], (NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px));
            njAddVector((NJS_VECTOR *)&((*(ATR_WORK **)(epw->exp0 + 0x14))->px), (NJS_VECTOR *)&ep->px);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->type == 1) 
            {
                epw->shp_ct = bhEne_GetShapeCnt(Tentacle4, epw->ct0);
            }
            else 
            {
                epw->shp_ct = bhEne_GetShapeCnt(Tentacle2, epw->ct0);
            }
            
            if (epw->shp_ct < 1000.0f) 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            else if (epw->shp_ct < 2000.0f) 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x8);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct -= 1000.0f;
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = 10.0f;
            }
            else 
            {
                epw->obj_a = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
                epw->obj_b = *(NJS_CNK_OBJECT **)(epw->exp0 + 0xC);
                
                epw->shp_ct = 3000.0f - epw->shp_ct;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->w = (10.0f * epw->shp_ct) / 1000.0f;
            }
            
            epw->ct0++;
            
            if (epw->ct0 == 30) 
            {
                bhEne13_Tentacle((BH_PWORK *)epw->lkwkp, epw->ct2);
            }
            
            if (epw->ct0 > 122) 
            {
                epw->mdflg &= ~2;
                epw->shp_ct = 0.0f;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
            }
            
            break;
    }
}

// 100% matching!
void bhEne18_Nage()
{

}

// 100% matching!
void bhEne18_Damage()
{

}

// 100% matching!
void bhEne18_Die(BH_PWORK* epw)
{
    epw->flg |= 2;
    
    epw->mlwP->objP = *(NJS_CNK_OBJECT **)(epw->exp0 + 0x4);
    
    epw->shp_ct = 0.0f;
    epw->mdflg &= ~2;
    
    if (*(ATR_WORK **)(epw->exp0 + 0x14) != NULL) 
    {
        (*(ATR_WORK **)(epw->exp0 + 0x14))->flg = 0;
    }
}

// 100% matching!
int bhEne18_HitMark(BH_PWORK* epw)
{
	int range;
    int i;
    NJS_POINT3 ofp;
    ENE18_BLOOD_TBL *blp;
    ENE18_EO *eop;

    range = 0;
    
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
    
    blp = &BloodTbl[epw->djnt_no];
    
    if (epw->comb_flg & 0x10) 
    {
        range = 0;
    }
    
    if (epw->comb_flg & 0x20) 
    {
        range = 1;
    }
    
    if (epw->comb_flg & 0x40) 
    {
        range = 2;
    }
    
    if (DmgReact[epw->wpnr_no].type[range] >= 0) 
    {
        eop = &blp->effoff[(int)(blp->num * (-rand() / -2.1474836e9f))];
        
        ofp.x = eop->ofp.x;
        ofp.y = eop->ofp.y;
        ofp.z = eop->ofp.z;
        
        ofp.x += (eop->rx * (-rand() / -2.1474836e9f)) - (eop->rx / 2.0f);
        ofp.y += (eop->ry * (-rand() / -2.1474836e9f)) - (eop->ry / 2.0f);
        ofp.z += (eop->rz * (-rand() / -2.1474836e9f)) - (eop->rz / 2.0f);
        
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
                bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, (NJS_POINT3 *)&epw->dpx, 1);
                break;

            default:
                bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
                break;
        }
        
        if (DmgReact[epw->wpnr_no].bloodstain[range]) 
        {
            bhEne_SetBloodstain(epw, 0, epw->djnt_no, &ofp);
        }
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0) && (epw->flg2 & 4)) 
    {
        for (i = 0; i < 4; i++)
        {
            eop = &blp->effoff[(int)(blp->num * (-rand() / -2.1474836e9f))];
            
            ofp.x = eop->ofp.x;
            ofp.y = eop->ofp.y;
            ofp.z = eop->ofp.z;
            
            ofp.x += (eop->rx * (-rand() / -2.1474836e9f)) - (eop->rx / 2.0f);
            ofp.y += (eop->ry * (-rand() / -2.1474836e9f)) - (eop->ry / 2.0f);
            ofp.z += (eop->rz * (-rand() / -2.1474836e9f)) - (eop->rz / 2.0f);
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2.1474836e9f)), (int)(40.0f * (-rand() / -2.1474836e9f)) + 20);
        } 
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 2) && (blp->flg == 0)) 
    {
        eop = &blp->effoff[(int)(blp->num * (-rand() / -2.1474836e9f))];
        
        ofp.x = eop->ofp.x;
        ofp.y = eop->ofp.y;
        ofp.z = eop->ofp.z;
        
        ofp.x += (eop->rx * (-rand() / -2.1474836e9f)) - (eop->rx / 2.0f);
        ofp.y += (eop->ry * (-rand() / -2.1474836e9f)) - (eop->ry / 2.0f);
        ofp.z += (eop->rz * (-rand() / -2.1474836e9f)) - (eop->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    return epw->total_dam;
}
