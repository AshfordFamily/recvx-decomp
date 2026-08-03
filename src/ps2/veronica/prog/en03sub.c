#include "../../../ps2/veronica/prog/en03sub.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

void (*bhEne03s_Mode0[3])(BH_PWORK*) = {
    bhEne03s_Init,
    bhEne03s_Move,
    bhEne03s_Dummy
};

void (*bhEne03s_MoveMode2[1])(BH_PWORK*) = {
    bhEne03s_MV00
};

// 100% matching!
void bhEne03s(BH_PWORK* epw)
{
    bhEne03s_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne03s_Init(BH_PWORK* epw)
{
    epw->ar = 0.3f;
    epw->ah = 0.3f;
    epw->car = 0.3f;
    epw->cah = 0.3f;
    epw->mode0 = 2;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(0xD4, 0x8);
    }

    EXP0_US(0x0) = 0x0;
}

// 100% matching!
void bhEne03s_Move(BH_PWORK* epw)
{
    bhEne03s_MoveMode2[epw->mode2](epw);

    if (epw->mode0 == 1)
    {
        if ((EXP0_US(0x0) & 0x2) == 0)
        {
            bhEne03s_WallCheck(epw);
        }
        else
        {
            bhEne03s_WallCheck2(epw);
        }
    }
}

// 100% matching!
void bhEne03s_MV00(BH_PWORK* epw)
{
    NJS_POINT3 c;
    NJS_VECTOR v;
    NJS_VECTOR vd;
    NJS_VECTOR ov;
    float out;
    float spd;
    int ang;
    BH_PWORK* ep;

    switch (epw->mode3)
    {
    case 0:
        ep = (BH_PWORK*)epw->lkwkp;
        EXP0_F(0x4) = (*epw->mtx)[12] - ep->px;
        EXP0_F(0x8) = (*epw->mtx)[13] - ep->py;
        EXP0_F(0xC) = (*epw->mtx)[14] - ep->pz;
        njUnitVector((NJS_VECTOR*)&EXP0_F(0x4));

        if (epw->type == 0)
        {
            switch (epw->ct0)
            {
            case 0:
                spd = 0.5f + njRandom();
                EXP0_F(0x4) *= spd;
                EXP0_F(0xC) *= spd;
                EXP0_F(0x8) = 0.5f + (2.0f * njRandom());
                break;

            case 1:
                spd = 0.5f + njRandom();
                EXP0_F(0x4) *= spd;
                EXP0_F(0xC) *= spd;
                EXP0_F(0x8) = 0.0f;
                break;

            case 2:
            case 3:
            case 4:
            case 5:
                spd = 0.5f + njRandom();
                EXP0_F(0x4) *= spd;
                EXP0_F(0xC) *= spd;
                EXP0_F(0x8) *= spd;
            }
        }
        else
        {
            spd = 0.5f + (0.5f * njRandom());
            EXP0_F(0x4) *= spd;
            EXP0_F(0xC) *= spd;
            EXP0_F(0x8) *= spd;
        }

        EXP0_US(0x0) |= 0x1;

        bhEne03s_InitCollision(epw);

        epw->ct0 = 5 + (int)(6.0f * njRandom());
        epw->mode3++;
        break;

    case 1:
        if (EXP0_US(0x0) & 1)
        {
            if (epw->type == 0)
            {
                EXP0_F(0x8) -= 0.2f;
            }
            else
            {
                EXP0_F(0x8) -= 0.2f;
            }

            njAddVector((NJS_VECTOR*)&(*epw->mtx)[12], (NJS_VECTOR*)&EXP0_F(0x4));
            njCalcPoint((NJS_MATRIX*)epw->mtx, (NJS_POINT3*)&EXP0_F(0x88), &c);
            njSubVector((NJS_VECTOR*)&(*epw->mtx)[12], &c);
            njUnitMatrix(NULL);
            njRotate(NULL, (NJS_VECTOR*)&EXP0_F(0xB8), epw->azp);
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->mtx);
            njGetMatrix((NJS_MATRIX*)epw->mtx);
            njAddVector((NJS_VECTOR*)&(*epw->mtx)[12], &c);
        }
        else
        {
            epw->ct3 = 8;
            epw->mode3++;
        }

        if (epw->ct0-- == 0)
        {
            epw->ct0 = 15 + (int)(10.0f * njRandom());
            bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->px, 1, 9, 0);
        }
        break;

    case 2:
        if (epw->ct3)
        {
            v.x = EXP0_F(0x10);
            v.y = EXP0_F(0x18);
            v.z = EXP0_F(0x14);

            njCalcVector((NJS_MATRIX*)epw->mtx, &v, &vd);

            if (vd.y < 0.0f)
            {
                vd.x *= -1.0f;
                vd.y *= -1.0f;
                vd.z *= -1.0f;
            }

            out = njOuterProduct(&vd, (NJS_VECTOR*)&EXP0_F(0x10), &ov);
            njUnitVector(&ov);
            ang = njArcSin(out);
            njSubVector((NJS_VECTOR*)&(*epw->mtx)[12], (NJS_VECTOR*)(epw->exp0 + (12 * EXP0_I(0xC4)) + 0x40));
            njUnitMatrix(NULL);
            njRotate(NULL, &ov, ang / epw->ct3);
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->mtx);
            njGetMatrix((NJS_MATRIX*)epw->mtx);
            njAddVector((NJS_VECTOR*)&(*epw->mtx)[12], (NJS_VECTOR*)(epw->exp0 + (12 * EXP0_I(0xC4)) + 0x40));

            epw->ct3--;
        }
        else
        {
            EXP0_F(0x4) = 0.0f;
            EXP0_F(0x8) = 0.0f;
            EXP0_F(0xC) = 0.0f;
            EXP0_US(0x0) |= 0x2;

            njCalcPoint((NJS_MATRIX*)epw->mtx, (NJS_POINT3*)&EXP0_F(0x88), (NJS_POINT3*)&EXP0_F(0xC8));

            epw->mode3++;
        }

        (*epw->mtx)[13] -= 0.2f;
        break;

    case 3:
        if ((EXP0_US(0x0) & 2) == 0)
        {
            epw->mode0 = 2;
        }
        else
        {
            njAddVector((NJS_VECTOR*)&(*epw->mtx)[12], (NJS_VECTOR*)&EXP0_F(0x4));
            EXP0_F(0x8) -= 0.2f;
        }
    }
}

// 100% matching!
void bhEne03s_Dummy(BH_PWORK* epw)
{
    return;
}

// 100% matching!
void bhEne03s_WallCheck(BH_PWORK* epw)
{
    NJS_VECTOR v;
    NJS_VECTOR n[3];
    int i;
    int flg[3];
    ATR_WORK* hp;
    int flgX;
    int flgY;
    int flgZ;
    int last;
    NJS_POINT3 p[3];

    last = -1;
    flgX = flgY = flgZ = 0;
    epw->px = (*epw->mtx)[12];
    epw->py = (*epw->mtx)[13];
    epw->pz = (*epw->mtx)[14];

    for (i = 2; i >= 0; i--)
    {
        flg[i] = 0;

        njCalcVector((NJS_MATRIX*)epw->mtx, (NJS_POINT3*)(epw->exp0 + (12 * i) + 0x1C), &v);

        epw->px += v.x;
        epw->py += v.y;
        epw->pz += v.z;

        if (EXP0_US(0x0) & 0x1)
        {
            hp = bhCollisionCheckLine((NJS_POINT3*)(epw->exp0 + (12 * i) + 0x64), (NJS_POINT3*)&epw->px);
            if (hp != NULL)
            {
                flg[i] = 1;
                bhGetHitCollisionNormal(&n[i]);
                njUnitVector(&n[i]);

                if (n[i].y < 0.0f)
                {
                    EXP0_F(0x8) = 0.0f;
                }

                if (n[i].y == 0.0f)
                {
                    if (fabsf(n[i].x) > fabsf(n[i].z))
                    {
                        flgX = 1;
                    }
                    else
                    {
                        flgZ = 1;
                    }
                }

                if (n[i].y > 0.99f)
                {
                    flgY = 1;
                    last = i;
                }
            }
        }

        bhEne03_Collision(epw);

        epw->px -= v.x;
        epw->py -= v.y;
        epw->pz -= v.z;
    }

    (*epw->mtx)[12] = epw->px;
    (*epw->mtx)[13] = epw->py;
    (*epw->mtx)[14] = epw->pz;

    if (flgX)
    {
        EXP0_F(0x4) *= -0.3f;
    }

    if (flgY)
    {
        EXP0_F(0x8) *= -0.3f;
    }

    if (flgZ)
    {
        EXP0_F(0xC) *= -0.3f;
    }

    for (i = 0; i < 3; i++)
    {
        *(float*)(epw->exp0 + (12 * i) + 0x64) = *(float*)(epw->exp0 + (12 * i) + 0x40);
        *(float*)(epw->exp0 + (12 * i) + 0x68) = *(float*)(epw->exp0 + (12 * i) + 0x44);
        *(float*)(epw->exp0 + (12 * i) + 0x6C) = *(float*)(epw->exp0 + (12 * i) + 0x48);

        njCalcVector(epw->mtx, (NJS_VECTOR*)(epw->exp0 + (12 * i) + 0x1C), &v);

        *(float*)(epw->exp0 + (12 * i) + 0x40) = epw->px + v.x;
        *(float*)(epw->exp0 + (12 * i) + 0x44) = epw->py + v.y;
        *(float*)(epw->exp0 + (12 * i) + 0x48) = epw->pz + v.z;
    }

    for (i = 0; i < 3; i++)
    {
        if (flg[i])
        {
            p[0].x = (EXP0_F(0x40) + EXP0_F(0x4C) + EXP0_F(0x58)) / 3.0f;
            p[0].y = (EXP0_F(0x44) + EXP0_F(0x50) + EXP0_F(0x5C)) / 3.0f;
            p[0].z = (EXP0_F(0x48) + EXP0_F(0x54) + EXP0_F(0x60)) / 3.0f;

            p[1].x = *(float*)(epw->exp0 + (12 * i) + 0x40);
            p[1].y = *(float*)(epw->exp0 + (12 * i) + 0x44);
            p[1].z = *(float*)(epw->exp0 + (12 * i) + 0x48);

            p[2].x = p[1].x + n[i].x;
            p[2].y = p[1].y + n[i].y;
            p[2].z = p[1].z + n[i].z;

            njGetPlaneNormal(p, (NJS_VECTOR*)&EXP0_F(0xB8));
            njUnitVector((NJS_VECTOR*)&EXP0_F(0xB8));

            epw->azp *= 0.7;
        }
    }

    if ((last >= 0) && (epw->azp < NJM_DEG_ANG(3)))
    {
        EXP0_US(0x0) &= ~0x1;
        EXP0_I(0xC4) = last;
        *(NJS_VECTOR*)&EXP0_F(0x10) = n[last];
        EXP0_F(0x4) = 0.0f;
        EXP0_F(0xC) = 0.0f;
    }
}

// 100% matching!
void bhEne03s_WallCheck2(BH_PWORK* epw)
{
    NJS_VECTOR v;
    NJS_VECTOR n;
    ATR_WORK* hp;

    epw->px = (*epw->mtx)[12];
    epw->py = (*epw->mtx)[13];
    epw->pz = (*epw->mtx)[14];

    njCalcVector(epw->mtx, (NJS_VECTOR*)&EXP0_F(0x88), &v);

    epw->px += v.x;
    epw->py += v.y;
    epw->pz += v.z;

    if (EXP0_US(0x0) & 0x2)
    {
        hp = bhCollisionCheckLine((NJS_POINT3*)&EXP0_F(0xC8), (NJS_POINT3*)&epw->px);
        if (hp != NULL)
        {
            bhGetHitCollisionNormal(&n);
            njUnitVector(&n);
            if (n.y > 0.99f)
            {
                EXP0_US(0x0) &= ~0x2;
            }
        }
    }

    bhEne03_Collision(epw);

    epw->px -= v.x;
    epw->py -= v.y;
    epw->pz -= v.z;

    (*epw->mtx)[12] = epw->px;
    (*epw->mtx)[13] = epw->py;
    (*epw->mtx)[14] = epw->pz;

    njCalcPoint(epw->mtx, (NJS_POINT3*)&EXP0_F(0x88), (NJS_POINT3*)&EXP0_F(0xC8));
}

// 100% matching!
void bhEne03s_InitCollision(BH_PWORK* epw)
{
    O_WORK* owk;
    int i;
    NJS_POINT3 pos;

    owk = (O_WORK*)epw->exp1;

    EXP0_F(0x1C) = 0.0f;
    EXP0_F(0x20) = 0.0f;
    EXP0_F(0x24) = 0.0f;

    EXP0_F(0x40) = owk[0].mtx[12];
    EXP0_F(0x44) = owk[0].mtx[13];
    EXP0_F(0x48) = owk[0].mtx[14];

    pos.x = owk[1].mtx[12];
    pos.y = owk[1].mtx[13];
    pos.z = owk[1].mtx[14];

    pos.x += owk[2].mtx[12];
    pos.y += owk[2].mtx[13];
    pos.z += owk[2].mtx[14];

    EXP0_F(0x4C) = 0.5f * pos.x;
    EXP0_F(0x50) = 0.5f * pos.y;
    EXP0_F(0x54) = 0.5f * pos.z;

    if (epw->type == 0)
    {
        pos.x = (epw->lkono) ? 2.5f : -2.5f;
        pos.y = -1.0f;
        pos.z = 0.0f;
    }
    else
    {
        pos.x = (epw->lkono) ? -5.0f : 5.0f;
        pos.y = -1.0f;
        pos.z = 0.0f;
    }

    njCalcPoint(&owk[2].mtx, &pos, &pos);

    EXP0_F(0x58) = pos.x;
    EXP0_F(0x5C) = pos.y;
    EXP0_F(0x60) = pos.z;

    njSetMatrix(NULL, epw->mtx);
    njInvertMatrix(NULL);
    njCalcPoint(NULL, (NJS_POINT3*)&EXP0_F(0x4C), (NJS_POINT3*)&EXP0_F(0x28));
    njCalcPoint(NULL, (NJS_POINT3*)&EXP0_F(0x58), (NJS_POINT3*)&EXP0_F(0x34));

    EXP0_F(0x88) = EXP0_F(0x8C) = EXP0_F(0x90) = 0.0f;

    njAddVector((NJS_VECTOR*)&EXP0_F(0x88), (NJS_VECTOR*)&EXP0_F(0x28));
    njAddVector((NJS_VECTOR*)&EXP0_F(0x88), (NJS_VECTOR*)&EXP0_F(0x34));

    EXP0_F(0x88) /= 3.0f;
    EXP0_F(0x8C) /= 3.0f;
    EXP0_F(0x90) /= 3.0f;

    for (i = 0; i < 3; i++)
    {
        *(NJS_POINT3*)(epw->exp0 + (12 * i) + 0x64) = *(NJS_POINT3*)(epw->exp0 + (12 * i) + 0x40);

        *(float*)(epw->exp0 + (12 * i) + 0x94) = 0.0f;
        *(float*)(epw->exp0 + (12 * i) + 0x98) = 0.0f;
        *(float*)(epw->exp0 + (12 * i) + 0x9C) = 0.0f;
    }

    njUnitMatrix(NULL);
    njRotateX(NULL, NJM_DEG_ANG(360) * njRandom());
    njRotateZ(NULL, NJM_DEG_ANG(360) * njRandom());

    EXP0_F(0xB8) = 0.0f;
    EXP0_F(0xBC) = 1.0f;
    EXP0_F(0xC0) = 0.0f;

    njCalcVector(NULL, (NJS_VECTOR*)&EXP0_F(0xB8), (NJS_VECTOR*)&EXP0_F(0xB8));

    epw->azp = (65536.0f / 360.0f) * (5.0f + (8.0f * njRandom()));
}
