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

DMG_REACT DmgReact[21] =
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
            if (epw->shp_ct = bhEne_GetShapeCnt(HeartBeat, epw->ct0), epw->shp_ct < 1000.0f)
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
            if (epw->shp_ct = bhEne_GetShapeCnt(SpawnAttacker, epw->ct0), epw->shp_ct < 1000.0f)
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

/*

// 
// Start address: 0x1efd80
void bhEne18_Nage()
{
	// Line 1099, Address: 0x1efd80, Func Offset: 0
	// Func End, Address: 0x1efd88, Func Offset: 0x8
}

// 
// Start address: 0x1efd90
void bhEne18_Damage()
{
	// Line 1110, Address: 0x1efd90, Func Offset: 0
	// Func End, Address: 0x1efd98, Func Offset: 0x8
}

// 
// Start address: 0x1efda0
void bhEne18_Die(BH_PWORK* epw)
{
	// Line 1121, Address: 0x1efda0, Func Offset: 0
	// Line 1125, Address: 0x1efda4, Func Offset: 0x4
	// Line 1121, Address: 0x1efda8, Func Offset: 0x8
	// Line 1123, Address: 0x1efdb0, Func Offset: 0x10
	// Line 1124, Address: 0x1efdc0, Func Offset: 0x20
	// Line 1125, Address: 0x1efdc4, Func Offset: 0x24
	// Line 1126, Address: 0x1efdd0, Func Offset: 0x30
	// Line 1127, Address: 0x1efde4, Func Offset: 0x44
	// Func End, Address: 0x1efdec, Func Offset: 0x4c
}

// 
// Start address: 0x1efdf0
int bhEne18_HitMark(BH_PWORK* epw)
{
	_anon3* eop;
	_anon0* blp;
	_anon25 ofp;
	int i;
	int range;
	// Line 1137, Address: 0x1efdf0, Func Offset: 0
	// Line 1144, Address: 0x1efe00, Func Offset: 0x10
	// Line 1137, Address: 0x1efe04, Func Offset: 0x14
	// Line 1144, Address: 0x1efe08, Func Offset: 0x18
	// Line 1137, Address: 0x1efe0c, Func Offset: 0x1c
	// Line 1144, Address: 0x1efe18, Func Offset: 0x28
	// Line 1137, Address: 0x1efe24, Func Offset: 0x34
	// Line 1144, Address: 0x1efe28, Func Offset: 0x38
	// Line 1147, Address: 0x1efe30, Func Offset: 0x40
	// Line 1148, Address: 0x1efe38, Func Offset: 0x48
	// Line 1147, Address: 0x1efe3c, Func Offset: 0x4c
	// Line 1148, Address: 0x1efe50, Func Offset: 0x60
	// Line 1149, Address: 0x1efe54, Func Offset: 0x64
	// Line 1150, Address: 0x1efe64, Func Offset: 0x74
	// Line 1151, Address: 0x1efe74, Func Offset: 0x84
	// Line 1152, Address: 0x1efe9c, Func Offset: 0xac
	// Line 1154, Address: 0x1efee8, Func Offset: 0xf8
	// Line 1155, Address: 0x1efeec, Func Offset: 0xfc
	// Line 1152, Address: 0x1efef0, Func Offset: 0x100
	// Line 1153, Address: 0x1efef4, Func Offset: 0x104
	// Line 1154, Address: 0x1efefc, Func Offset: 0x10c
	// Line 1155, Address: 0x1eff04, Func Offset: 0x114
	// Line 1156, Address: 0x1eff0c, Func Offset: 0x11c
	// Line 1157, Address: 0x1eff4c, Func Offset: 0x15c
	// Line 1158, Address: 0x1eff8c, Func Offset: 0x19c
	// Line 1160, Address: 0x1effcc, Func Offset: 0x1dc
	// Line 1170, Address: 0x1efffc, Func Offset: 0x20c
	// Line 1171, Address: 0x1f002c, Func Offset: 0x23c
	// Line 1173, Address: 0x1f0034, Func Offset: 0x244
	// Line 1178, Address: 0x1f0064, Func Offset: 0x274
	// Line 1179, Address: 0x1f008c, Func Offset: 0x29c
	// Line 1183, Address: 0x1f00a0, Func Offset: 0x2b0
	// Line 1184, Address: 0x1f00e4, Func Offset: 0x2f4
	// Line 1185, Address: 0x1f00e8, Func Offset: 0x2f8
	// Line 1187, Address: 0x1f0134, Func Offset: 0x344
	// Line 1188, Address: 0x1f0138, Func Offset: 0x348
	// Line 1185, Address: 0x1f013c, Func Offset: 0x34c
	// Line 1186, Address: 0x1f0140, Func Offset: 0x350
	// Line 1187, Address: 0x1f0148, Func Offset: 0x358
	// Line 1188, Address: 0x1f0150, Func Offset: 0x360
	// Line 1189, Address: 0x1f0158, Func Offset: 0x368
	// Line 1190, Address: 0x1f0198, Func Offset: 0x3a8
	// Line 1191, Address: 0x1f01d8, Func Offset: 0x3e8
	// Line 1192, Address: 0x1f0214, Func Offset: 0x424
	// Line 1193, Address: 0x1f029c, Func Offset: 0x4ac
	// Line 1194, Address: 0x1f02ac, Func Offset: 0x4bc
	// Line 1196, Address: 0x1f02b0, Func Offset: 0x4c0
	// Line 1197, Address: 0x1f02e4, Func Offset: 0x4f4
	// Line 1199, Address: 0x1f0330, Func Offset: 0x540
	// Line 1197, Address: 0x1f0334, Func Offset: 0x544
	// Line 1198, Address: 0x1f0338, Func Offset: 0x548
	// Line 1200, Address: 0x1f033c, Func Offset: 0x54c
	// Line 1198, Address: 0x1f0340, Func Offset: 0x550
	// Line 1199, Address: 0x1f0344, Func Offset: 0x554
	// Line 1200, Address: 0x1f034c, Func Offset: 0x55c
	// Line 1201, Address: 0x1f0354, Func Offset: 0x564
	// Line 1202, Address: 0x1f0394, Func Offset: 0x5a4
	// Line 1203, Address: 0x1f03d4, Func Offset: 0x5e4
	// Line 1204, Address: 0x1f03f0, Func Offset: 0x600
	// Line 1203, Address: 0x1f03f4, Func Offset: 0x604
	// Line 1204, Address: 0x1f0418, Func Offset: 0x628
	// Line 1207, Address: 0x1f0424, Func Offset: 0x634
	// Line 1208, Address: 0x1f0428, Func Offset: 0x638
	// Func End, Address: 0x1f0450, Func Offset: 0x660
}*/

