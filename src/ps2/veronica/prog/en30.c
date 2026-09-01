#include "../../../ps2/veronica/prog/en30.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/macros.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: Alexia's Baby 

static int ENE30_HITPOINT[16] = {5, 5, 5, 5, 5, 5, 5, 5, 15, 15, 15, 15, 15, 15, 20, 20};
static char SdwTab[3] = {0x1, 0x4, 0xFF};
static CPCL CapColTab[3] =
{
    { 0, 0, 16},
    { 0, 5, 0},
    { 0, 0, 0},
};

void(*bhEne30_Mode0[6])(BH_PWORK*) = {
    bhEne30_Init,
    bhEne30_Move, 
    bhEne30_Nage,
    bhEne30_Damage,
    bhEne30_Die,
    bhEne_Event,
};

void(*bhEne30_BrainType[1])(BH_PWORK*) = {
    bhEne30_BR00,
};

void(*bhEne30_MoveMode2[8])(BH_PWORK*) = {
    bhEne30_MV00,
    bhEne30_MV01,
    bhEne30_MV02,
    bhEne30_MV03,
    bhEne30_MV04,
    bhEne30_MV05,
    bhEne30_MV06,
    bhEne30_MV07,
};

void(*bhEne30_DamageMode2[2])(BH_PWORK*) = {
    bhEne30_DG00,
    bhEne30_DG01,
};

void(*bhEne30_DeadMode2[2])(BH_PWORK*) = {
    bhEne30_DD00,
    bhEne30_DD01,
};

// 100% matching!
void bhEne30(BH_PWORK* epw) 
{
    float wy;

    bhEne30_Mode0[epw->mode0](epw);

    if (((BH_PWORK*)epw->lkwkp)->stflg & 0x01000000) {
        epw->stflg |= 0x01000000;
    }
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (!(epw->flg & 0x80000)) {
        bhCheckPlayer(epw);
        bhCheckEnemies(epw);
    }
    
    if (!(epw->flg & 0x80000)) {
        bhEne30_CheckEnemies(epw);
    }
    
    if (epw->flg & 0x10) {
        bhEne30_CollisionLine(epw);
        wy = epw->py;
        epw->py = wy + epw->ar;
        bhEne03_Collision(epw);
        epw->py -= epw->ar;
        if (!(epw->flg & 0x200000)) {
            epw->py = wy;
        }
    }
    
    bhCalcModel(epw);
    bhEne_SetWeponAtr(epw, 0, 3, 3.0f);
}

// 100% matching!
void bhEne30_Init(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* obj;
    NJS_CNK_OBJECT* pObj;
    int i;

    epw->flg &= ~0x78;
    epw->flg &= ~6;
    epw->flg &= ~0x180000;

    epw->flg2 &= ~1; 
    epw->flg2 |= 0x10; 

    epw->mdflg |= 1;

    epw->ar  = 3.0f;
    epw->ah  = 1.0f;
    epw->car = 2.0f;
    epw->cah = 1.0f;

    epw->mlwP = &epw->mdl[0];
    epw->mdl_no = 0;

    epw->mdflg &= ~2; 

    epw->hp = ENE30_HITPOINT[(int)(16.0f * ((float)-rand() / -2147483648.0f))];

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;
    epw->mtn_no      = 0;
    epw->mtn_md      = 0;
    epw->mtn_add     = 65536;
    epw->frm_no      = 0;

    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 7;
    epw->clp_jno[2] = 9;
    epw->clp_jno[3] = 11;
    epw->clp_jno[4] = 13;
    epw->clp_jno[5] = 15;
    epw->clp_jno[6] = -1;

    epw->mdflg &= ~0x20;

    if (epw->exp0 == NULL) {
        epw->exp0 = bhEne_CallocWork(252, 8);
        pObj = epw->mdl[1].objP;
        
        for(i = 0; i < epw->mdl[1].obj_num; i++, pObj++) {
            ((float*)(epw->exp0))[3*i+0]= pObj->pos[0];
            ((float*)(epw->exp0))[3*i+1]= pObj->pos[1];
            ((float*)(epw->exp0))[3*i+2]= pObj->pos[2];
        }
    }

    obj = &epw->mlwP->objP[5];
    for(i = 5; i <= 15; i++, obj++) {
        obj->pos[1] = 0.0f;
    }

    epw->mdl[0].objP[1].evalflags  &= ~8;
    epw->mdl[0].objP[16].evalflags &= ~8;
    epw->mdl[1].objP[1].evalflags  &= ~8;
    epw->mdl[1].objP[16].evalflags &= ~8;

    if (!(epw->flg & 0x800)) {
        bhSetShadow(SdwTab, (unsigned char*)epw, 16, 4.0f, 5.0f, 6.0f);
        epw->flg |= 0x800;
    }

    epw->stflg &= ~8;
    epw->cpcl = CapColTab;

    EXP0_I(240) = (int)(20.0f * ((float)-rand() / -2147483648.0f)) + 20;

    epw->obj_a = epw->mdl[0].objP;
    epw->obj_b = epw->mdl[1].objP;

    epw->mdflg &= ~2;
    epw->shp_ct = 0;
}

// 100% matching!
void bhEne30_Brain(BH_PWORK* epw) 
{
    bhEne30_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne30_BR00(BH_PWORK* epw) 
{
    EXP0_F(244) = njSqrt((epw->px - plp->px) * (epw->px - plp->px) + (epw->pz - plp->pz) * (epw->pz - plp->pz));
    if(((int*)epw->exp0)[60]) {
        ((int*)epw->exp0)[60] -= 1;
    }

    if (EXP0_I(240) != 0) {
        return;
    }
    
    if ((float) -rand() / -2147483648.0f > 0.3f
        && EXP0_F(244) < 15.0f
        && bhEne_CheckDirTarget(epw, plp->px, plp->pz, 5461) ) {
        epw->mode1 = 0;
        epw->mode2 = 7;
        epw->mode3 = 0;
        EXP0_I(240) = (int)(20.0f * ((float) -rand() / -2147483648.0f)) + 20;
    } else if (EXP0_F(244) < 15.0f) {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        EXP0_I(240) = (int)(20.0f * ((float) -rand() / -2147483648.0f)) + 20;
        return;
    }
}

// 100% matching!
void bhEne30_Move(BH_PWORK* epw) 
{

    if (epw->mode1 != 0) {
        bhEne30_Brain(epw);
    }
    
    bhEne30_MoveMode2[epw->mode2](epw);
    
    if (epw->flg & 4) {
        epw->flg &= ~4;
        bhEne30_DamageInit(epw);
    }
}

// 100% matching!
void bhEne30_MV00() 
{

}

// 100% matching!
void bhEne30_MV01(BH_PWORK* epw) 
{
	NJS_POINT3 pos;
	ATR_WORK* hp;
	NJS_POINT3 vec;
	int i;
	BH_PWORK* ep;
	float dist;
	float wdist;
    int ang;

    switch (epw->mode3) {                             
    case 0:
        epw->flg &= ~0x80000;
        epw->flg2 &= ~1;
        epw->flg |= 0x100000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->axp = 0;
        epw->ct0 = 45;
        epw->ct1 = 0;
        epw->ayp = epw->ay;
        epw->mode3 += 1;
        /* fallthrough */
    case 1:
        ep = ene;
        wdist = 100.0f;
        for(i = 0; i < sys->ewk_n; i++, ep++) {
            if (ep != epw) {
                if ((ep->flg & 1) && (ep->id == 30) && (ep->flg & 0x100000)) {
                    {
                        float px = epw->px - ep->px;
                        float pz = epw->pz - ep->pz;
                        dist = njSqrt((px * px) + (pz * pz));
                    }
                    if (!(wdist <= dist)) {
                        ang = (short) ((bhArcTan2(epw->px - ep->px, epw->pz - ep->pz) - epw->ay));
                        if ((ang < 16384) && (ang > -16384)) {
                            wdist = dist;
                            if (epw->ct1 == 0) {
                                if (ang < 0) {
                                    epw->ct1 = 1;
                                } else {
                                    epw->ct1 = -1;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (wdist < 10.0f) {
            epw->ayp = epw->ayp + (epw->ct1 * 1092);
        } else if ((bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) & 0xFF) != 0xFF) {
            epw->ay =  epw->ayp;
            epw->ayp = epw->ayp + bhEne_DirTarget(epw, pos.x, pos.z, 2184);
        } else {
            pos.x = epw->px - (7.0f * njSin(epw->ay));
            pos.y = epw->py;
            pos.z = epw->pz - (7.0f * njCos(epw->ay));
            if ((hp = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos)) != 0) {
                if (epw->ct1 == 0) {
                    bhGetHitCollisionNormal(&vec);
                    njUnitVector(&vec);
                    njUnitMatrix(NULL);
                    njRotateY(NULL, -epw->ay);
                    njCalcVector(NULL, &vec, &vec);
                    
                    if  (vec.x < 0.0f) {
                        epw->ayp += 1092;
                        epw->ct1 = 1;
                    } else {
                        epw->ayp -= 1092;
                        epw->ct1 = -1;
                    }
                }
                
                epw->ayp = epw->ayp + (epw->ct1 * 1092);
            } else {
                epw->ay = epw->ayp;
                epw->ayp = epw->ayp + bhEne_DirTarget(epw, plp->px, plp->pz, 2184);
            }
        }
        
        epw->axp += 910;
        epw->ay = (epw->ayp + (int)(910.0f * njSin(epw->axp)));
        epw->spd = (0.5f + fabsf(0.5f * njSin(epw->axp * 2)));
        
        bhAddSpeed(epw, 0);
        if (epw->ct0 != 0) {
            epw->ct0--;
            return;
        }
        
        epw->mode1 = 1;
        epw->ct0 = 150;
        epw->ct1 = 0;
        break;
    }
}

// 100% matching!
void bhEne30_MV02(BH_PWORK* epw)
{
    int i;
    NJS_POINT3 v;
    NJS_POINT3 pos;
    float size;
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x80000;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 0.0f;

        for (i = 0; i < 8; i++) {
            pos.x = (epw->px + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            pos.y = epw->py + (2.0f * ((float) -rand() / -2.1474836e9f));
            pos.z = (epw->pz + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            size = 0.1f + (0.2f * ((float) -rand() / -2.1474836e9f));
            v.x = 0.1f;
            v.z = 0.1f;
            v.y = 0.5f + (0.7f * ((float) -rand() / -2.1474836e9f));
            njUnitMatrix(NULL);
            njRotateY(NULL, (int)(65536.0f * ((float) -rand() / -2.1474836e9f)));
            njCalcVector(NULL, &v, &v);
            bhEne30_SetFluidEffect(&pos, &v, 0, size);
        }

        for(i = 0; i < 4; i++) {
            pos.x = (epw->px + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            pos.y = epw->py + (2.0f * ((float) -rand() / -2.1474836e9f));
            pos.z = (epw->pz + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            size = 0.1f + (0.2f * ((float) -rand() / -2.1474836e9f));
            v.x = 0.2f;
            v.z = 0.2f;
            v.y = 0.4f + (0.7f * ((float) -rand() / -2.1474836e9f));
            njUnitMatrix(NULL);
            njRotateY(NULL, (int)(65536.0f * ((float) -rand() / -2.1474836e9f)));
            njCalcVector(NULL, &v, &v);
            bhEne30_SetFluidEffect(&pos, &v, 1, size);
        }

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230B);
        epw->mode3 += 1;
        /* fallthrough */
        
    case 1:
        epw->shp_ct += 300.0f;
        if (!(epw->shp_ct < 1000.0f)) {
            epw->shp_ct = 1000.0f;
            epw->mlwP = &epw->mdl[1];
            epw->mdflg &= ~2;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        
        {
            int i;
            for (i = 5; i <= 15; i++, objA++, objB++) {
                objA->pos[1] = objB->pos[1] = (epw->shp_ct * (*(float*)(epw->exp0 + i * 0xC + 4))) / 1000.0f;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne30_MV03(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;
    int i;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x80000;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 45875;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 1000.0f;
        epw->mode3 += 1;

    case 1:
        epw->shp_ct -= 35.0f;
        if (epw->shp_ct < 0.0f) {
            epw->shp_ct = 0.0f;
            epw->mlwP = epw->mdl;
            epw->mdflg &= ~2;
            epw->flg &= ~0x80000;
            epw->flg2 &= ~1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        
        for (i = 5; i <= 15; i++) {
            objA->pos[1] = objB->pos[1] = (epw->shp_ct * (*(float*)(epw->exp0 + i * 0xC + 4))) / 1000.0f;
            objA++;
            objB++;
        }
        
        break;
    }
}

// 100% matching!
void bhEne30_MV04(BH_PWORK* epw) 
{
    int mtn[3] = {2, 5, 6};
    
    switch (epw->mode3) {
        case 0:
            break;
        default:
            return;
    } 
    
    epw->flg |= 0x80000;
    epw->mtn_no = mtn[(((int)(3.0f * ((float) -rand() / -2.1474836e9f))))];
    epw->frm_no = 0;
    epw->hokan_count = 8;
    epw->hokan_rate = 45875;
    epw->mode3 += 1;
}

// 100% matching!
void bhEne30_MV05(BH_PWORK* epw) 
{
	int mtn[3] = {8, 7, 8};
	NJS_POINT3 pos;
	int i;
    O_WORK* owk;

    switch (epw->mode3) {                           
    case 0:
        epw->flg |=  0x80000;
        
        if (EXP0_F(244) < 30.0f) {
            epw->ct1 = (int)(3.0f * ((float) -rand() / -2.1474836e9f));
        } else if (EXP0_F(244) < 70.0f) {
            epw->ct1 = (int)(2.0f * ((float) -rand() / -2.1474836e9f));
        } else {
            epw->ct1 = 0;
        }
        
        epw->mtn_no = mtn[epw->ct1];
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 26214;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num  - 2;
        epw->ct1  = 1;
        epw->mode3 += 1;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230C);
        break;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mode2 = 3;
            epw->mode3  = 0;
        }
        break;
    }
    
    if ((epw->ct1 != 0) && !(plp->flg & 4) && !(plp->stflg & 0x30)) {
            for(i = 8; i <= 15; i++) {
                
            owk = &epw->mlwP->owP[i];
            pos.x = owk->mtx[12];
            pos.y = owk->mtx[13];
            pos.z = owk->mtx[14];
            
            if (bhEne_AttackHitCheck(plp, &pos, 3.0f)) {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230D);
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
                plp->hp -= 5;
                
                if (plp->hp < 0) {
                    plp->hp = 0;
                }
                
                bhEne_SetBloodEffect5(plp, 0xA, 1);
                plp->mode0 = 2;
                plp->mode2 = 0;
                plp->mode3 = 0;
                
                if (abs((short)(epw->ay - plp->ay)) > 16384) {
                    plp->mode1 = 0;
                } else {
                    plp->mode1 = 1;
                }
                
                epw->ct1 = 0;
                return;
            }
        }
    }
}


// 99.95% matching!
void bhEne30_MV06(BH_PWORK* epw) 
{

    int i;
    NJS_POINT3 v;
    NJS_POINT3 pos;
    float spd;
    float size;

    switch (epw->mode3) {
    case 0:
        epw->flg &=  ~0x80000;
        epw->flg2 &= ~1;
        epw->flg |= 0x100000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->spd = 1.0f;
        epw->ct0 = 0;
        epw->ax = 0;
        epw->mdflg &= ~1;
        epw->flg |= 0x68;
        epw->mode3 += 1;
        /* fallthrough */

    case 1:
        bhAddSpeed(epw, 0);
        if (epw->ct0 < 10) {
            v.x = -njSin(epw->ay);
            v.y = 0.0f;
            v.z = -njCos(epw->ay);
            for (i = 0; i < 6; i++) {
                pos.x = (epw->px + (2.0f * (-rand() / -2.1474836e9f))) - 1.0f;
                pos.y = epw->py + (2.0f * (-rand() / -2.1474836e9f));
                pos.z = (epw->pz + (2.0f * (-rand() / -2.1474836e9f))) - 1.0f;
                size = 0.3f + (0.4f * (-rand() / -2.1474836e9f));
                spd = 0.4f + (0.4f * (-rand() / -2.1474836e9f));
                v.x *= spd;
                v.z *= spd;
                v.y = 0.3f + (0.2f * (-rand() / -2.1474836e9f));
                njUnitMatrix(NULL);
                njRotateY(NULL, (int)((21845.0f * (-rand() / -2.1474836e9f)) - 10922.0f));
                njCalcVector(NULL, &v, &v);
                bhEne30_SetFluidEffect(&pos, &v, 0, size);
            }

            for (i = 0; i < 3; i++) {
                pos.x = (epw->px + (2.0f * (-rand() / -2.1474836e9f))) - 1.0f;
                pos.y = epw->py + (2.0f * (-rand() / -2.1474836e9f));
                pos.z = (epw->pz + (2.0f * (-rand() / -2.1474836e9f))) - 1.0f;
                size = 0.3f + (0.4f * (-rand() / -2.1474836e9f));
                spd = 0.4f + (0.4f * (-rand() / -2.1474836e9f));
                v.x *= spd;
                v.z *= spd;
                v.y = 0.3f + (0.2f * (-rand() / -2.1474836e9f));
                njUnitMatrix(NULL);
                njRotateY(NULL, (int)((21845.0f * (-rand() / -2.1474836e9f)) - 10922.0f));
                njCalcVector(NULL, &v, &v);
                bhEne30_SetFluidEffect(&pos, &v, 1, size);
            }
        }

        if (epw->ct0++ >= 10) {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->flg |= 0x10;
            ((int*)epw->exp0)[60] = 0;
        }

        break;
    }
}


// 100% matching!
void bhEne30_MV07(BH_PWORK* epw) 
{
    float dist;
    
    switch (epw->mode3) {                             
    case 0:
        epw->flg &= ~0x80000;
        epw->flg2 &= ~1;
        epw->flg &= ~0x60;
        epw->flg |= 0x200000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->mtn_add = 0;
        epw->hokan_count = 0;
        epw->ct0 = 100;
        dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
        epw->xn =  ((dist * -njSin(epw->ay)) / 10.0f);
        epw->zn =  ((dist * -njCos(epw->ay)) / 10.0f);
        epw->yn = 3.0f;
        epw->mode3 += 1;
        
    case 1:
        if (epw->flg & 0x200000) {
            epw->px += epw->xn;
            epw->py += epw->yn;
            epw->pz += epw->zn;
            

            epw->yn -= 0.4f;
            if (!(epw->yn <= 0.0f)) {
                {
                    int temp;
                    temp = ((short)((16384 - epw->ax)));
                    epw->ax += (temp / 4);
                }
            } else {
                epw->ax = epw->ax - (epw->ax / 4);
            }
            
            if (!(plp->flg & 4) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&epw->px, 2))) {
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
                plp->hp -= 5;
                
                if (plp->hp < 0) {
                    plp->hp = 0;
                }
                
                plp->mode0 = 2;
                plp->mode1 = 0;
                plp->mode2 = 0;
                plp->mode3 = 0;
                
                bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->xn, 0, 10, 1);
                
                epw->xn *= -0.6f;
                epw->zn *= -0.6f;
                epw->yn = 0.5f;
                
            }
        } else {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->flg |= 0x60;
            epw->mtn_add = 0x10000;
            epw->ax = 0;
            epw->py = 24.0f;
        }
        
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne30_Nage(BH_PWORK* epw)
{
}

// 100% matching!
void bhEne30_Damage(BH_PWORK* epw) 
{
    bhEne30_DamageMode2[epw->mode2](epw);
}


// 100% matching!
void bhEne30_DG00(BH_PWORK* epw) 
{

    switch (epw->mode3) {                             
    case 0:
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 26214;
        epw->mtn_add = 131072;
        epw->ct0 = 10;
        epw->mode3 += 1;
        break;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mtn_add = 65536;
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne30_DG01(BH_PWORK* epw) 
{
    switch (epw->mode3) {                              
    case 0:
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 26214;
        epw->mtn_add = 65536;
        epw->mode3 += 1;
        break;
        
    case 1:
        if (epw->frm_no == 0) {
            epw->mtn_add = 65536;
            epw->mode0= 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne30_Die(BH_PWORK* epw) 
{
    bhEne30_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne30_DD00(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;
    int i;
    O_WORK* owk;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x8002;
        epw->flg &= ~0x28;
        epw->flg &= ~0x100000;
        epw->stflg |= 8; 
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 26214;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mlwP->objP[1].evalflags |= 8;
        epw->mlwP->objP[16].evalflags |= 8;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230E);
        epw->mode3++;
        /* fallthrough */
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mtn_add = 0;
        }

        epw->shp_ct -= 15.0f;
        if (epw->shp_ct < 200.0f) {
            epw->shp_ct = 0.0f;
            epw->mode3++;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        for(i = 5; i <= 15; i++, objA++, objB++) {
            objA->pos[1] = objB->pos[1] = (epw->shp_ct * *(float*)(epw->exp0 + i * 0xC + 4)) / 1000.0f;
        }

        if (epw->ct1-- == 0) {
            owk = epw->mlwP->owP;
            epw->dvx = owk[7].mtx[12];
            epw->dvy = owk[7].mtx[13];
            epw->dvz = owk[7].mtx[14];
            owk = epw->mlwP->owP;
            njSubVector((NJS_VECTOR*)&epw->dvx, (NJS_VECTOR*)&owk[6].mtx[12]);
            bhEne_SetBloodEffectBurst(epw, 0, 7, NULL, 0);
            epw->ct1 = (int)(8.0f * ((float)-rand() / -2147483648.0f)) + 0x10;
        }
        break;

    case 2:
        epw->mdflg |= 1;
        bhEne_SetBloodEffectBurst(epw, 3, 7, NULL, 0);
        epw->ct0 = 60;
        epw->mode3++;
        /* fallthrough */
        
    case 3:
        
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne30_DD01(BH_PWORK* epw) 
{
    switch (epw->mode3) {                         
    case 0:
        epw->flg |= 0x8002;
        epw->flg &= ~0x28;
        epw->flg &= ~0x100000;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230E);
        epw->stflg |= 8; 
        epw->mdflg |= 1;
        epw->ct0 = 60;
        epw->mode3 += 1;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }
        return;
    }
}

// 100% matching!
void bhEne30_CheckEnemies(BH_PWORK* epw) 
{
    int i;
    float dx;
    float dz;
    float len;
    BH_PWORK* ep;

    ep = ene;
    for (i = 0; i < sys->ewk_n; i++, ep++) {
        if ((ep->flg & 1) && (ep->flg & 8) && (ep->id == 30) && (ep->flg & 0x80000)) {
            dx = epw->px - ep->px;
            dz = epw->pz - ep->pz;
            

            len = njSqrt((dx * dx) + (dz * dz));

            if (len != 0.0f) {
                if (len < (epw->car + ep->car)) {
                    epw->px = ep->px + (dx * (epw->car + ep->car)) / len;
                    epw->pz = ep->pz + (dz * (epw->car + ep->car)) / len;
                }
            }
        }
    }
}

// 100% matching!
void bhEne30_DamageInit(BH_PWORK* epw) 
{
	int i;
	int dam;
    NJS_POINT3 ofp;

    dam = 0;
    for(i = 0; i < epw->mlwP->obj_num; i++) {
        if (epw->dam[i] != 0) {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }
    
    if (dam != 0) {
        epw->hp =  (epw->hp - dam);
        bhEne_SetBloodEffectBurst(epw, 2, 1, NULL, 0);
        
        if ((epw->hp < 0) || (i = epw->flg & 0x80000, (i != 0))) {
            ofp.x = 0.0f;
            ofp.y = 1.0f;
            ofp.z = 0.0f;
            epw->dvz = 0;
            epw->dvx = 0;
            epw->dvy = -1.0f;
            
            bhEne_SetBloodstain(epw, 2, 5, &ofp);
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            bhEne_SetMinceEffect(epw, 0x102, 3);
            bhEne_SetMinceEffect(epw, 0x103, 2);
            
            if (epw->flg & 0x80000) {
                epw->mode2 = 0;
                return;
            }
            
            epw->mode2 = 1;
            return;
        }
        
        if (!(epw->flg & 0x200000)) {
            if (i != 0) {
                epw->mode2 = 0;
            } else {
                epw->mode2= 1;
            }
            
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne30_CollisionLine(BH_PWORK* epw) 
{
    NJS_POINT3 n;
    ATR_WORK* hp;
    
    if (((hp = bhCollisionCheckLine((NJS_POINT3*)&epw->pxb,  (NJS_POINT3*)&epw->px)) != NULL) && (epw->flg & 0x200000)) {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        if (!(n.y < 0.99f)) {
            epw->flg &= ~0x200000;
        }
    }
}

// 100% matching!
void bhEne30_SetFluidEffect(NJS_POINT3* pos, NJS_POINT3* vec, int type, float size) 
{
    int eno;

    sys->ef.id = 267;
    sys->ef.flg = 1;
    sys->ef.type = type;
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = size;
    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    if (eno != -1) {
        eff[eno].xn = vec->x;
        eff[eno].yn = vec->y;
        eff[eno].zn = vec->z;
    }
}

