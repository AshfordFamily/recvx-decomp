#include "../../../ps2/veronica/prog/en13sub.h"
#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne13B_Mode0[6] =
{
    bhEne13B_Init,
    bhEne13B_Move,
    bhEne13B_Nage,
    bhEne13B_Damage,
    bhEne13B_Die,
    bhEne_Event
};

MoveMode2_proc bhEne13B_MoveMode2[2] =
{
    bhEne13B_MV00,
    bhEne13B_MV01
};
/*(*bhEne13B_BrainType)(BH_PWORK*)[1]; - unused*/

// 100% matching!
void bhEne13B(BH_PWORK* epw)
{
	int i;
    O_WORK* owk;

    bhEne13B_Mode0[epw->mode0](epw);

    if ((((BH_PWORK*)epw->lkwkp)->stflg & 0x1000000))
    {
        int i;

        epw->stflg |= 0x1000000;

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }
    }

	owk = epw->mlwP->owP;

    for (i = 0; i < epw->mlwP->obj_num; i++, owk++)
    {
        *EXP0_P3(i) = *(NJS_POINT3*)&owk->mtx[12];
    }

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    bhEne13B_SetHittab(epw);
}

// 100% matching!
void bhEne13B_Init(BH_PWORK* epw)
{
	int i;

    epw->flg |= 0x8018;
    epw->flg &= ~0x6;

    epw->flg2 |= 0x1;
    epw->flg2 |= 0x10;

    epw->mdflg |= 0x20;

    epw->ar = 5.0f;
    epw->ah = 1.0f;

    epw->car = 3.0f;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;

    epw->mtn_no  = 4;
    epw->mtn_md  = 0;
    epw->mtn_add = 0;

    epw->frm_no = 0;

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(520, 8);

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i) = &sys->mwalp[sys->mwal_n];

            sys->mwal_n++;

            EXP0_ATR(i)->flg = 0;

            EXP0_ATR(i)->type = 3;

            EXP0_ATR(i)->w = 2.0f;
            EXP0_ATR(i)->h = 1.0f;
            EXP0_ATR(i)->d = 0;

            EXP0_ATR(i)->attr = 0;

            EXP0_ATR(i)->px = epw->mlwP->owP->mtx[12];
            EXP0_ATR(i)->py = epw->mlwP->owP->mtx[13];
            EXP0_ATR(i)->pz = epw->mlwP->owP->mtx[14];
        }
    }
}

// 100% matching!
void bhEne13B_Move(BH_PWORK* epw)
{
	bhEne13B_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne13B_MV00()
{

}

// 100% matching!
void bhEne13B_MV01(BH_PWORK* epw)
{
	int mtn_no[6] = { 6, 4, 8, 7, 5, 9 };
    O_WORK* owk;
    int i, j;
    int num;
    BH_PWORK** ep;
    NJS_POINT3 p1;
	float x, y, z; // not from DWARF

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn_no[epw->type];
        epw->frm_no = 0;

        epw->mtn_add = 65536;

        epw->hokan_count = 0;

        epw->ct0 = 1;

        epw->flg &= ~0x80000;

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74507);

        epw->mode3++;
        break;
    case 1:
        if (((epw->mtn_no == 5) && (epw->frm_no == 3276800)) || ((epw->mtn_no == 7) && (epw->frm_no == 3801088)) || ((epw->mtn_no == 9) && (epw->frm_no == 3276800)))
        {
            bhEne13_SetCamera((BH_PWORK*)epw->lkwkp, 3.2f);

            bhEne_CallSE(epw, (NJS_POINT3*)&epw->mlwP->owP[18].mtx[12], 74512);
        }

        if (((epw->mtn_no == 4) && (epw->frm_no == 1507328)) || ((epw->mtn_no == 6) && (epw->frm_no == 1507328)) || ((epw->mtn_no == 8) && (epw->frm_no == 1507328)))
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->mlwP->owP[18].mtx[12], 74511);
        }

        switch (epw->mtn_no)
        {
        case 4:
            if (epw->frm_no >= 3538944)
            {
                epw->flg |= 0x80000;
				
                epw->ct0 = 0;
            }

            break;
        case 6:
            if (epw->frm_no >= 2883584)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            break;
        case 8:
            if (epw->frm_no >= 3538944)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            break;
        case 5:
            if (epw->frm_no == 851968)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            if (epw->frm_no == 3080192)
            {
                epw->flg &= ~0x80000;

                epw->ct0 = 2;
            }

            if (epw->frm_no == 3473408)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            break;
        case 7:
            if (epw->frm_no == 1245184)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            if (epw->frm_no == 3604480)
            {
                epw->flg &= ~0x80000;

                epw->ct0 = 2;
            }

            if (epw->frm_no == 3932160)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            break;
        case 9:
            if (epw->frm_no == 851968)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            if (epw->frm_no == 3080192)
            {
                epw->flg &= ~0x80000;

                epw->ct0 = 2;
            }

            if (epw->frm_no == 3473408)
            {
                epw->flg |= 0x80000;

                epw->ct0 = 0;
            }

            break;
        }

        if (epw->ct0 != 0)
        {
			owk = &epw->mlwP->owP[epw->mlwP->obj_num] - 1;

            for (i = epw->mlwP->obj_num - 1; i > 0; i--, owk--)
            {
                if ((epw->ct0 != 0) && ((plp->mode0 != 3) && (plp->mode0 != 4) && (plp->mode0 != 6)) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&owk->mtx[12], 4.0f)))
                {
                    p1.x = epw->mlwP->owP->mtx[12];
                    p1.y = epw->mlwP->owP->mtx[13];
                    p1.z = epw->mlwP->owP->mtx[14];

					x = epw->mlwP->owP[i].mtx[12];
					y = epw->mlwP->owP[i].mtx[13];
					z = epw->mlwP->owP[i].mtx[14];

					plp->dvx = EXP0_P3(i)->x - x;
					plp->dvy = EXP0_P3(i)->y - y;
					plp->dvz = EXP0_P3(i)->z - z;

                    if ((njDistanceP2P(&p1, (NJS_POINT3*)&plp->px) < 15.0f) || (njScalor((NJS_VECTOR*)&plp->dvx) < 5.0f))
                    {
                        plp->dvx = p1.x - plp->px;
                        plp->dvy = p1.y - plp->py;
                        plp->dvz = p1.z - plp->pz;
                    }

                    if (epw->ct0 == 1)
                    {
                        plp->hp -= 25;
                    }
                    else
                    {
                        plp->hp -= 60;
                    }

                    if (plp->hp < 0)
                    {
                        plp->flg   |= 0x10004;
                        plp->stflg |= 0x50000;

                        plp->mode0 = 6;
                        plp->mode1 = 0;

                        if (bhEne_DGDirCheck(plp) != 0)
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);

                            plp->mode2 = 1;
                        }
                        else
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);

                            plp->mode2 = 0;
                        }

                        plp->mode3 = 0;
                    }
                    else
                    {
                        plp->flg   |= 0x10004;
                        plp->stflg |= 0x10000;

                        plp->mode0 = 4;
                        plp->mode1 = 0;

                        if (bhEne_DGDirCheck(plp) != 0)
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);

                            plp->mode2 = 1;
                        }
                        else
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);

                            plp->mode2 = 0;
                        }

                        plp->mode3 = 0;
                    }

                    bhEne13_PlayerControl((BH_PWORK*)epw->lkwkp);

                    epw->ct0 = 0;
                }

                ep = bhEne13_GetChild((BH_PWORK*)epw->lkwkp, &num);

                for (j = 0; j < num; j++, ep++)
                {
                    if ((((*ep)->flg & 0x20)) && (bhEne_AttackHitCheck(*ep, (NJS_POINT3*)&owk->mtx[12], 4.0f)))
                    {
						(*ep)->flg |= 0x4;
						
						(*ep)->dam[0] = 100;
                    }
                }
            }
        }

        if (epw->frm_no == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 0;

            epw->mtn_add = 0;

            epw->mode3 = 0;
        }

        break;
    }
}

// 100% matching!
void bhEne13B_Nage()
{

}

// 100% matching!
void bhEne13B_Damage()
{

}

// 100% matching!
void bhEne13B_Die(BH_PWORK* epw)
{
	int i;

    epw->stflg |= 0x1000000;
    epw->flg   |= 0x2;

    for (i = 0; i < epw->mlwP->obj_num; i++)
    {
        EXP0_ATR(i)->flg = 0;
    }

    epw->flg &= ~0x80000;
}

// 100% matching!
void bhEne13B_SetHittab(BH_PWORK* epw)
{
	int i;
    O_WORK* owk;

    if ((epw->flg & 0x80000))
    {
        EXP0_I(516)++;

        if (EXP0_I(516) > 15)
        {
            EXP0_I(516) = 15;
        }

        owk = epw->mlwP->owP;

        for (i = 0; i < EXP0_I(516); i++, owk++)
        {
            EXP0_ATR(i)->flg = 1;

            EXP0_ATR(i)->px = owk->mtx[12];
            EXP0_ATR(i)->py = owk->mtx[13];
            EXP0_ATR(i)->pz = owk->mtx[14];
        }
    }
    else
    {
        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }

        EXP0_I(516) = 0;
    }
}
