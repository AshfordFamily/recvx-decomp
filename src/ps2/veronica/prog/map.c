#include "../../../ps2/veronica/prog/map.h"
#include "../../../ps2/veronica/prog/binfunc.h"
#include "../../../ps2/veronica/prog/event.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSprite.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

static map_wrk MapWrk;

static map_wrk* mwP = &MapWrk;

const NJS_ARGB MapPal[32] = 
{
    { 1.0f, 0.7f, 0.7f, 0.7f }, { 1.0f, 0.1f, 0.2f, 0.4f }, { 1.0f, 0.4f, 0.1f, 0.2f }, { 0.5f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 0.6f, 0.1f, 0.5f }, { 0.3f, 0.2f, 0.2f, 0.8f }, { 1.0f, 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.4f, 0.8f },
    { 1.0f, 0.8f, 0.0f, 0.4f }, { 0.8f, 1.0f, 0.5f, 0.0f }, { 1.0f, 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.8f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f, 0.8f }, { 1.0f, 0.0f, 0.8f, 0.8f }, { 1.0f, 0.8f, 0.8f, 0.0f },
    { 1.0f, 0.0f, 0.8f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.8f, 0.6f, 0.4f, 0.0f },
    { 1.0f, 0.8f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.8f, 0.0f }, { 1.0f, 0.0f, 0.0f, 0.8f }, { 1.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 0.5f, 0.1f, 0.1f }, { 1.0f, 0.5f, 0.3f, 0.3f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.8f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f, 0.8f }, { 1.0f, 0.0f, 0.8f, 0.8f }, { 1.0f, 0.8f, 0.8f, 0.0f }
};
const NJS_COLOR MapCol[3] = 
{
    { 0xFF000800 }, { 0xFF003000 }, { 0xC0A0A0A0 }
};
const ID_WORK ItmDat[22] = 
{
    { 59, 96 },  { 86, 96 },  { 84, 97 },  { 56, 98 },  { 51, 99 },  { 67, 100 }, { 68, 101 }, { 33, 102 },  { 73, 103 }, { 62, 104 }, 
	{ 93, 105 }, { 76, 106 }, { 75, 107 }, { 89, 108 }, { 90, 109 }, { 81, 110 }, { 92, 111 }, { 105, 112 }, { 66, 113 }, { 44, 114 },
    { 46, 115 }, { 108, 116 }
};
const unsigned short CncDatA[81] = 
{
    65284, 1, 65285, 256, 416, 65325, 40960, 40961, 41121, 65347, 41376, 41232, 41233, 41234, 65287, 4113, 65288, 4368, 4370, 4513, 4400, 
	4401, 4402, 65289, 4625, 65294, 12337, 65295, 12592, 12594, 12560, 12561, 12562, 12706, 65296, 12849, 65345, 41520, 41521, 41522, 
	41504, 41505, 41506, 41507, 65290, 8225, 8354, 8256, 8257, 65291, 8480, 8482, 65292, 8737, 8739, 65293, 8994, 65297, 16449, 16416,
    16417, 16418, 16419, 16464, 65298, 16704, 65299, 20544, 20545, 20576, 20577, 20578, 65300, 24673, 65301, 24928, 24930, 24912, 65302, 
	25185, 65535
};
const unsigned short CncDatB[49] = 
{
    65303, 28785, 65304, 29040, 29042, 65294, 29297, 29299, 65295, 29554, 29556, 29568, 29569, 65296, 29811, 65297, 32897, 32880, 32881, 
	32882, 32883, 32884, 32912, 32913, 32914, 32915, 32916, 32917, 65298, 33152, 65305, 37009, 65306, 37264, 37266, 65307, 37521, 37523, 
	65308, 37778, 37780, 65300, 38035, 38037, 65301, 38292, 38272, 38273, 65535
};

// 98.45% matching
void bhInitMap(enum_2 set_mod)
{
    NJS_TEXLIST* texP;

    njClipZ(-2.0f, -20000.0f);
    
    njSetAspect(1.174f, 1.0f);
    njSetBackColor(0, 0, 0);
    
    npSetMemory((unsigned char*)mwP, sizeof(map_wrk), 0);
    
    mwP->status |= (1 << set_mod) & 7;
    
    mwP->mem_bakP = sys->memp;
    
    mwP->vew_mtxP = (NJS_MATRIX*)mwP->Vew_Mtx;
    mwP->rom_mtxP = (NJS_MATRIX*)mwP->Rom_Mtx;
    
    mwP->cur_mtxP = &mwP->rom_mtxP[1];
    mwP->tmp_mtxP = &mwP->rom_mtxP[2];
    
    mwP->ply_stg = sys->stg_no;
    mwP->ply_rom = sys->rom_no + (sys->stg_no * 100);
    
    mwP->vew_max.y = 600.0f;
    mwP->vew_min.y = 600.0f;
    
    mwP->dst_zom = 600.0f;
    mwP->vew_zom = 600.0f;
    
    mwP->vew_ang[0] = -16384;
    
    mwP->bck_depth = -1600.0f;
    
    mwP->bck_p0.x = 0;
    mwP->bck_p0.y = 0;
    
    mwP->bck_p1.x = 640.0f;
    mwP->bck_p1.y = 480.0f;
    
    mwP->ar = mwP->ag = mwP->ab = 0;
    mwP->pr = mwP->pg = mwP->pb = 0.6f;
    
    mwP->pitch = -16384;
    
    mwP->yaw = 0;
    
    mwP->map_scale = 0.001f;
    
    if ((mwP->status & 0x2)) 
    {
        mwP->bnk_mde = sys->mp_prm[0];
        mwP->bnk_stg = sys->mp_prm[1];
        mwP->bnk_flr = sys->mp_prm[2];
        mwP->bnk_rom = sys->mp_prm[3] + (mwP->bnk_stg * 100);
    }
    
    if (!(mwP->status & 0x4)) 
    {
        mwP->rom_texP = rom->mdl.texP;
        
        if (mwP->rom_texP != NULL) 
        {
            sys->memp = (unsigned char*)(((int)sys->memp + 31) & ~0x1F);
            
            mwP->rom_bakP = sys->memp;
            
            sys->memp = (unsigned char*)bhCopyTexmem2Mainmem(mwP->rom_texP, (char*)sys->memp);
            
            bhGarbageTexture(NULL, 0);
            
            Ps2ClearOT();
            
            if (sys->fade_an > 0) 
            {
                bhDrawScreenFade();
            }
        }
    }
    
    texP = (NJS_TEXLIST*)bhGetFreeMemory(8, 4);
    
    texP->textures  = (NJS_TEXNAME*)bhGetFreeMemory(12, 4);
    texP->nbTexture = 1;
    
    mwP->map_texP = texP;
    
    texP = (NJS_TEXLIST*)bhGetFreeMemory(8, 4);
    
    texP->textures  = (NJS_TEXNAME*)bhGetFreeMemory(12, 4);
    texP->nbTexture = 1;
    
    mwP->stg_texP = texP;
    
    MapFuncInit(24);
    
    njCnkSetEasyMultiLight(1);
    
    MapCnvStatus2Flag();
    
    mwP->prti_no = sys->dor_partid;
    
    if (!(mwP->status & 0x4)) 
    {
        CallSystemSe(0, 3);
    }
}

// 100% matching! 
void bhSetMap()
{

}

// 100% matching!
void bhExitMap()
{
    njClipZ(GameNear, GameFar);
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y);
    
    if ((mwP->status & 0x8)) 
    {
        njReleaseTexture(mwP->map_texP);
    }
    
    if ((mwP->status & 0x10)) 
    {
        njReleaseTexture(mwP->stg_texP);
    }
    
    bhGarbageTexture(NULL, 0);
    
    if (mwP->rom_texP != NULL) 
    {
        bhCopyMainmem2Texmem(mwP->rom_texP);
    }
    
    bhReleaseFreeMemory(mwP->mem_bakP);
    
    sys->gm_flg &= ~0x80000;
}

// 100% matching!
static int bhReadMapData(char* namP)
{
    int code;
	int status;

    code = 0;
    
    switch (mwP->fil_mode)
    {
    case 0:
        if (mwP->map_bufP != NULL) 
        {
            bhReleaseFreeMemory(mwP->map_bufP);
        }
        
        mwP->map_bufP = bhGetFreeMemory(GetInsideFileSize(mwP->prti_no, (unsigned int)namP), 32);
        
        if (RequestReadInsideFile(mwP->prti_no, (unsigned int)namP, mwP->map_bufP) == 0) 
        {
            mwP->fil_mode = 2;
            break;
        }
        else 
        {
            mwP->fil_mode = 1;
        }
    case 1:
        code = -1;
        break;
    case 2:
        status = GetReadFileStatus(mwP);
        
        if (status == -1) 
        {
            code = -1;
        }
        else if (status == 0) 
        {
            code = 1;
        }
        
        break;
    }
    
    return code;
}

// 99.41% matching
static void MapCnvStatus2Flag()
{
	int id;
    unsigned int* itm_basP;
    ID_WORK* datP;
    int chk;
    int itm;
    unsigned int* itmP;

    id = sys->ply_id;
    
    if (id > 2)
    {
        if (id == 3) 
        {
            id = 2;
        }
        else if (id == 4) 
        {
            id = 0;
        }
        else 
        {
            id = 0;
        }
    }
    
    bhFlagSet(8, 1,      1);
    bhFlagSet(8, 2,      1);
    bhFlagSet(8, 3,      1);
    bhFlagSet(8, id + 1, 0);
   
    itm_basP = &sys->itm[sys->ply_id * 16];
    
    chk = 22; 
    
    datP = ItmDat;
    
    for (; chk > 0; chk--, datP++)
    {
        bhFlagSet(9, datP->flg_no, 1);
    }

    chk = 22;
    
    datP = ItmDat;

    for (; chk > 0; chk--, datP++)
    {
        for (itmP = itm_basP, id = 0; id < 16; id++, itmP++)
        {
            itm = (*itmP >> 16) & 0xFF;
            
            if ((unsigned int)itm == datP->itm_no)
            {
                bhFlagSet(9, datP->flg_no, 0);
                break;
            }
        }
    }
}

// 99.82% matching
int bhControlMap()
{
    int bol;         
    NJS_SCREEN scrn; 
    int next;        
    int* pacP;        
    ML_WORK* mlwP;    
    int i;            
    unsigned int tmp; 

    bol = 1;
    
    switch (mwP->map_mode) 
    {
    case MP_MOD_FIRST:
        bhSetScreenFade(sys->fade_pbk, 8.0f);
        
        MapFuncAlloc(FsubBackDraw, 0);
        MapFuncAlloc((void*)FsubZoomScreen, 0);
        
        MapEntryTask(FtskMapWait, MP_MOD_IDX_READ, 0);
        
        mwP->map_mode = MP_MOD_WAIT;
        
        MapCncInit(11, 6);
        
        if (GetGameMode() == 1) 
        {
            MapCncConnect(CncDatA);
        } 
        else 
        {
            MapCncConnect(CncDatB);
        }
        
        break;
    case MP_MOD_IDX_READ:
        njClipZ(-2.0f, -20000.0f);
        
        njSetAspect(1.174f, 1.0f);
        njSetBackColor(0x00000000, 0x00000000, 0x00000000); 
        
        scrn.dist = 500.0f;
        
        scrn.w = 640.0f;
        scrn.h = 480.0f;
        
        scrn.cx = 320.0f;
        scrn.cy = 240.0f;
        
        njSetScreen(&scrn);
        
        MapEntryTask(FtskMapRead, MP_MOD_IDX_ANALYZE, sys->ply_id);
        
        mwP->map_mode = MP_MOD_WAIT;
        break;
    case MP_MOD_IDX_ANALYZE:
        pacP = mwP->map_bufP;
        
        if (*pacP++ == 0x4341504D)
        {
            mlwP = mwP->MrkMdl;
            
            pacP = (int*)((int)pacP + *pacP);
            
            next = *pacP++;
            
            while ((*pacP & 0xFFFFFF) == 0x4C444D) 
            {
                bhMlbBinRealize(pacP, mlwP);
                
                pacP = (int*)((int)pacP + next);
                
                next = *pacP++;
                
                mlwP++; 
            }
            
            mwP->status |= 0x8;
            
            bhSetMemPvpTexture(mwP->map_texP, (unsigned char*)pacP, 0);
            
            if (next != -1) 
            {
                pacP = (int*)((int)pacP + next); 
                
                next = *pacP++;
            }
            
            for (i = 0; i < 10; i++) 
            {
                mwP->mes_bufPP[i] = (unsigned int*)pacP;
                
                if (next != -1) 
                {
                    pacP = (int*)((int)pacP + next); 
                    
                    next = *pacP++;
                }
            }
            
            mwP->map_bufP = pacP;
            
            tmp = MapGetFloorNo(mwP->map_bufP, mwP->ply_rom, plp->py);
            
            mwP->map_no  = tmp / 65536;
            mwP->ply_flr = tmp & 0xFFFF;
            
            MapEntrySprite(MP_SET_SILHOUETTE, 0);
            
            MapFuncAlloc((void*)FsubCompass, 0);
            MapFuncAlloc((void*)FsubModeMessage, 0);
        }
        
        if ((mwP->status & 0x2)) 
        {
            mwP->stg_no = mwP->bnk_stg;
            mwP->rom_no = mwP->bnk_rom;
            mwP->flr_no = mwP->bnk_flr;
        } 
        else 
        {
            mwP->stg_no = mwP->map_no;
            mwP->rom_no = mwP->ply_rom;
            mwP->flr_no = mwP->ply_flr;
        }
    case MP_MOD_MAP_READ:
        mwP->status &= ~0x40;
        mwP->status &= ~0x100;
        
        mwP->map_flr = mwP->flr_no;
        
        if ((mwP->status & 0x10)) 
        {
            mwP->status &= ~0x10;
            
            njReleaseTexture(mwP->stg_texP);
            
            bhGarbageTexture(NULL, 0);
        }
        
        MapEntryTask(FtskMapRead, MP_MOD_DAT_SET, (mwP->map_flr + (mwP->stg_no * 6)) + 5);
        
        mwP->map_mode = MP_MOD_WAIT;
        break;
    case MP_MOD_DAT_SET:
    {
        int next;  
        int* pacP; 
        
        pacP = mwP->map_bufP; 
        
        if (*pacP++ == 0x4341504D)
        {
            pacP = (int*)((int)pacP + *pacP);
            
            next = *pacP++;
            
            mwP->map_cdeP = (short*)pacP;
            
            if (next != -1) 
            {
                pacP = (int*)((int)pacP + next);
                
                next = *pacP++;
                
                bhMlbBinRealize(pacP, &mwP->map_mdl);
                
                MapPurgeTree(&mwP->map_mdl);
                
                mwP->map_objP = mwP->map_mdl.objP;
                
                if (next != -1) 
                {
                    mwP->status |= 0x10;
                    
                    bhSetMemPvpTexture(mwP->stg_texP, (unsigned char*)(((int)pacP + next) + 4), 0); 
                }
            }
            
            MapFuncAlloc(FsubMapDraw, 0);
            
            MapTagInit(64);
            
            mwP->map_mode = MP_MOD_VEW_NORMAL;
        } 
        else 
        {
            mwP->map_mode = MP_MOD_WAIT_NOMAP;
        }
        
        break;
    }
    case MP_MOD_VEW_NORMAL:
        MapEntryTask(FtskMapNormal, MP_MOD_VEW_ZOOM, 0);
        
        mwP->map_mode = MP_MOD_WAIT_NORMAL;
        break;
    case MP_MOD_VEW_ZOOM:
        MapEntryTask(FtskMapZoom, MP_MOD_VEW_NORMAL, 0);
        
        mwP->map_mode = MP_MOD_WAIT_ZOOM;
        break;
    case MP_MOD_WAIT_NOMAP:
        MapDrawMessage(mwP->ply_rom, 160.0f, 220.0f);
    case MP_MOD_WAIT_NORMAL:
    case MP_MOD_WAIT_ZOOM:
    {
        NJS_POINT3* dstP, *srcP; 

        srcP = &mwP->vew_pos;
        dstP = &mwP->dst_pos;
            
        srcP->x      += 0.5f * (dstP->x      - srcP->x);
        mwP->vew_zom += 0.5f * (mwP->dst_zom - mwP->vew_zom);
        srcP->z      += 0.5f * (dstP->z      - srcP->z);
        
        if ((mwP->pad_ps & 0x3000)) 
        {
            CallSystemSe(0, 0);
            
            bhSetScreenFade(0xFF000000, 8.0f);
            
            mwP->map_mode = MP_MOD_WAIT;
            
            MapEntryTask(FtskMapExit, MP_MOD_EXIT, 0);
            
            mwP->status |= 0x400;
        }
        
        break;
    }
    case MP_MOD_EXIT:
        bol = 0;
        break;
    }
    
    mwP->time++;
    
    MapPadMain();
    MapViewMain();
    MapLightMain();
    MapPaletteMain();
    
    MapFuncExec();
    
    return bol;
}

// 100% matching!
static void MapPadMain()
{
    if ((mwP->status & 0x400)) 
    {
        mwP->pad_ps = 0;
        
        mwP->pad_ax = mwP->pad_ay = 0;
        mwP->pad_al = mwP->pad_ar = 0;
        return;
    }
    
    mwP->pad_ps = sys->pad_ps;
    
    mwP->pad_al = sys->pad_al;
    mwP->pad_ar = sys->pad_ar;
    
    if ((sys->pad_ax > 40.0f) || (sys->pad_ax < -40.0f))
    {
        mwP->pad_ax = sys->pad_ax;
    }
    else 
    {
        mwP->pad_ax = 0;
    }
    
    if ((sys->pad_ay > 40.0f) || (sys->pad_ay < -40.0f))
    {
        mwP->pad_ay = sys->pad_ay;
    }
    else
    {
        mwP->pad_ay = 0;
    }
}

// 100% matching!
static void MapViewMain()
{
    NJS_MATRIX* mtxP;

    mtxP = mwP->vew_mtxP;
    
    njUnitMatrix(mtxP);
    
    njRotateX(mtxP, 32768);
    
    njTranslate(mtxP, 0, 0, -mwP->vew_zom);
    
    njRotateZ(mtxP, -mwP->vew_ang[2]);
    njRotateX(mtxP, -mwP->vew_ang[0]);
    njRotateY(mtxP, -mwP->vew_ang[1]);
    
    njTranslate(mtxP, -mwP->vew_pos.x, -mwP->vew_pos.y, -mwP->vew_pos.z);
}

// 99.61% matching
static void MapLightMain()
{
	int pitch, yaw;
    float scl;

    njCnkSetEasyMultiLightSwitch(1, 1);
    njCnkSetEasyMultiAmbient(mwP->ar, mwP->ag, mwP->ab);
    
    mwP->lgt_scale = mwP->map_scale;
    
    yaw   = mwP->yaw;
    pitch = mwP->pitch;
    
    scl = 1.0f / mwP->map_scale;
    
    njCnkSetEasyMultiLightVector(-njSin(yaw) * njCos(pitch), njSin(pitch), -njCos(yaw) * njCos(pitch));
    njCnkSetEasyMultiLightColor(1, mwP->pr * scl, mwP->pg * scl, mwP->pb * scl);
    
    njPushMatrix(mwP->vew_mtxP);
    
    njCnkSetEasyMultiLightMatrices();
    
    njPopMatrixEx();
}

// 100% matching!
static void MapPaletteMain()
{
    NJS_ARGB* srcP, *dstP;
    int i;

    njMemCopy4(mwP->MapPal, MapPal, 64);
    njMemCopy4(mwP->MapCol, MapCol, 3);
    
    srcP = &MapPal[16];
    dstP = &mwP->MapPal[16];
    
    for (i = 4; i > 0; i--, srcP++, dstP++) 
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 1024);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
    
    for (i = 4; i > 0; i--, srcP++, dstP++)
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 2048);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
    
    for (i = 4; i > 0; i--, srcP++, dstP++)
    {
        float rate;
        
        rate = 2.0f + njSin((mwP->time + (i * 4)) * 4096);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    }
    
    for (i = 4; i > 0; i--, srcP++, dstP++) 
    {
        float rate;

        rate = 2.0f + njSin(mwP->time * 4096);
        rate = 0.3333f * rate;
        
        dstP->a = srcP->a * rate;
        dstP->r = srcP->r * rate;
        dstP->g = srcP->g * rate;
        dstP->b = srcP->b * rate;
    } 
}

#pragma divbyzerocheck on 

// 100% matching!
static void MapCodeProcess()
{
    short* ocP;         
    int* stsP;          
    NJS_CNK_OBJECT* objP;
    int mode;             
    unsigned char typ;   // needs use  
    //unsigned char typ; // needs use
    float scl;     
    float x, y, z;    // not from DWARF
    float xx, yy, zz; // not from DWARF
	static const int SndTbl[1] = { 0x80000247 };
    
    ocP  = mwP->map_cdeP;
    stsP = &mwP->status;
    
    njControl3D(0x810);
    
    njSetConstantAttr(-1, 0x800);
    
    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    njScale(NULL, 1.0f, mwP->lgt_scale, 1.0f);
    
    while ((mode = *ocP) != 2) 
    {
        ocP++;
        
        switch (mode & 0xFFF) 
        {
        case 3:
            objP = mwP->map_objP + *ocP++;
            
            mwP->cur_objP = objP;
            
            njPushMatrixEx();
            
            njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
            njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);
            
            njGetMatrix(mwP->cur_mtxP);
            
            njPopMatrixEx();
            break;
        case 4:
            mode = *ocP++;
            
            njPushMatrix(mwP->vew_mtxP);
            njMultiMatrix(NULL, mwP->cur_mtxP);
            
            if (mwP->cur_objP->model != NULL) 
            {
                if (((mwP->status & 0x200)) && (mwP->chk_rom == mwP->bnk_tag_rom))
                {
                    if ((mode == 1) || (mode == 2) || (mode == 24)) 
                    {
                        mode = mwP->bnk_tag_pal;
                    }
                    else if ((mode == 7) || (mode == 8) || (mode == 25)) 
                    {
                        mode = mwP->bnk_tag_pal_wal;
                    } 
                }
                
                njSetConstantMaterial(&mwP->MapPal[mode]);
                
                njCnkEasyMultiDrawModel(mwP->cur_objP->model);
            }
            
            njPopMatrixEx();
            break;
        case 5:
        {
            int mrk_no;       
            NJS_POINT3 pos;    
                
            mrk_no = ocP[0];
            
            pos.x = ocP[1] / 32.0f;
            pos.y = ocP[2] / 32.0f;
            
            scl = ocP[3];
            
            ocP += 4;
            
            pos.z = scl / 32.0f;
            
            MapDrawMarker(mrk_no, &pos, -1);
            break;
        }
        case 7:
        {
            int ax, ay, az;           
            
            ax = ocP[0];
            ay = ocP[1];
            az = ocP[2];
            
            ocP += 3;
            
            njRotateXYZ(mwP->cur_mtxP, ax, ay, az);
            break;
        }
        case 6:
        {
            float tx, ty, tz;            
            
            tx = ocP[0] / 32.0f;
            ty = ocP[1] / 32.0f;
            tz = ocP[2] / 32.0f;
            
            ocP += 3;
            
            njTranslate(mwP->cur_mtxP, tx, ty, tz);
            break;
        }
        case 11:
        {
            int ck_rom;         
            
            ck_rom = *ocP++;
            
            if ((mwP->ply_flr == mwP->map_flr) && (mwP->rom_no == ck_rom))
            {
                MapBoolSet(1, mode & 0xF000);
            }  
            else 
            {
                MapBoolSet(0, mode & 0xF000);
            }
            
            mwP->chk_rom = ck_rom;
            break;
        }
        case 12:
            MapBoolSet(bhFlagCk(*ocP++, *ocP++, 0), mode & 0xF000);
            break;
        case 13:
            x = ocP[0] / 32.0f;
            y = ocP[1] / 32.0f;
            z = ocP[2] / 32.0f;
            
            xx = ocP[3] / 32.0f;
            yy = ocP[4] / 32.0f;
            zz = ocP[5] / 32.0f;
            
            ocP += 6;
            
            if (((x <= plp->px) && (plp->px <= xx)) && ((y <= plp->py) && (plp->py <= yy)) && ((z <= plp->pz) && (plp->pz <= zz))) 
            {
                MapBoolSet(1, mode & 0xF000);
            }
            else
            {
                MapBoolSet(0, mode & 0xF000);
            }
            
            break;
        case 8:
            if (mwP->cde_bol == 0)
            {
                ocP++;
            } 
            else 
            {
                ocP = &mwP->map_cdeP[*ocP];
            }
            
            break;
        case 9:
            if (mwP->cde_bol != 0)
            {
                ocP++;
            } 
            else
            {
                ocP = &mwP->map_cdeP[*ocP];
            }
            
            break;
        case 10:
            ocP = &mwP->map_cdeP[*ocP];
            break;
        case 14:
            MapBoolSet(bhFlagSet(*ocP++, *ocP++, 0), mode & 0xF000);
            break;
        case 15:
            if (!(*stsP & 0x40))
            {
                *stsP |= 0x40;
                
                mwP->vew_pos.x = 10.0f * (ocP[0] / 32.0f);
                mwP->vew_pos.y = 10.0f * (ocP[1] / 32.0f);
                mwP->vew_pos.z = 10.0f * (ocP[2] / 32.0f);
                mwP->vew_zom   = 10.0f * (ocP[3] / 32.0f);
                
                ocP += 4;
                
                mwP->vew_min.y = 0.3333f * mwP->vew_zom;
                mwP->vew_max.y = 1.5f    * mwP->vew_zom;
                
                MapViewMain();
                
                scl = 1.0f;
                scl = (scl * mwP->vew_mtxP[0][14]) / _nj_screen_.dist;
                
                mwP->vew_min.x = mwP->vew_pos.x - (320.0f * scl);
                mwP->vew_max.x = mwP->vew_pos.x + (320.0f * scl);
                
                mwP->vew_min.z = mwP->vew_pos.z - (240.0f * scl);
                mwP->vew_max.z = mwP->vew_pos.z + (240.0f * scl);
                
                mwP->vew_pos_bak = mwP->vew_pos;
                mwP->vew_zom_bak = mwP->vew_zom;
            } 
            else
            {
                ocP += 4;
            }
            
            break;
        case 16:
        {
            int rom_no;         
            NJS_POINT3 pos;     
                
            if (!(*stsP & 0x100))
            {
                rom_no = ocP[0];
                
                pos.x = ocP[1] / 32.0f;
                pos.y = ocP[2] / 32.0f;
                
                scl = ocP[3];
                
                ocP += 4;
                
                pos.z = scl / 32.0f;
                
                MapTagEntry(mwP->cur_mtxP, rom_no, &pos);
            } 
            else 
            {
                ocP += 4;
            }
            
            break;
        }
        case 17:
        {
            int mrk_no, pal_no;        
            NJS_POINT3 pos;     
                
            mrk_no = ocP[0];
            pal_no = ocP[1];
            
            pos.x = ocP[2] / 32.0f;
            pos.y = ocP[3] / 32.0f;
            
            scl = ocP[4];
            
            ocP += 5;
            
            pos.z = scl / 32.0f;
            
            MapDrawMarker(mrk_no, &pos, pal_no);
            break;
        }
        case 18:
        {
            int snd_no; 
            int bnk_tim, off_tim; 
            
            snd_no = ocP[0];
            
            bnk_tim = ocP[1];
            off_tim = ocP[2];
            
            ocP += 3;
            
            if (((off_tim + mwP->time) % bnk_tim) == 0)
            {
                CallSystemSe(0, SndTbl[snd_no]);
            }
            
            break;
        }
        case 0:
        case 1:
        case 2:
            break;
        } 
    }
                    
    njPopMatrixEx();
    
    njControl3D(0);
}

#pragma divbyzerocheck off

// 100% matching!
static void MapBoolSet(int bol, int mod) 
{
    switch (mod) 
    {                                 
    case 0:
        mwP->cde_bol = bol;
        break;
    case 0x4000:
        mwP->cde_bol &= bol;
        break;
    case 0x8000:
        mwP->cde_bol |= bol;
        break;
    }
}

// 100% matching!
static void MapDrawMarker(int mrk_no, NJS_POINT3* posP, int pal_no)
{
	MA_WORK* maP;
	static MA_WORK MrkAtr[6] = 
    {
        { 0, 3.0f, 24.0f, 16 }, { 1, 3.0f, 20.0f, 28 }, { 1, 3.0f, 16.0f, 13 },
        { 1, 3.0f, 12.0f, 14 }, { 3, 1.0f, 12.0f, 30 }, { 2, 2.0f,  8.0f, 31 }
    };

    switch (mrk_no)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        maP = &MrkAtr[mrk_no];
        
        if (pal_no == -1) 
        {
            pal_no = maP->pal_no;
        }
        
        njSetConstantMaterial(&mwP->MapPal[pal_no]);
        
        njPushMatrix(mwP->vew_mtxP);
        
        njMultiMatrix(NULL, mwP->cur_mtxP);
        
        if (mrk_no == 0) 
        {
            if (mwP->ply_flr == mwP->map_flr)
            {
                njTranslate(NULL, plp->px, plp->py + maP->offset, plp->pz);
                njRotateXYZ(NULL, plp->ax, plp->ay, plp->az);
                
                njScale(NULL, maP->scale, 1.0f, maP->scale);
                
                njCnkEasyMultiDrawObject(mwP->MrkMdl[maP->mrk_no].objP);
            }
        } 
        else 
        {
            njTranslate(NULL, posP->x, posP->y + maP->offset, posP->z);
            
            njScale(NULL, maP->scale, 1.0f, maP->scale);
            
            njCnkEasyMultiDrawObject(mwP->MrkMdl[maP->mrk_no].objP);
        }
        
        njPopMatrixEx();
        break;
    case 6:
        posP->z -= 1.0f;
        
        MapDrawSprite(posP, -1, MP_SPR_TITLE);
        break;
    }
}

// 100% matching!
static void MapDrawBackground(float depth, NJS_POINT2* p0P, NJS_POINT2* p1P)
{
    NJS_POINT2 p0, p1;
    float dst;     
    
    MapDrawFill(p0P, p1P, depth, mwP->MapCol[0].color);
    
    p0.x = ceilf(-16.0f + p0P->x);
    p0.y = ceilf(p0P->y);
    
    p1.x = floorf(p1P->x);
    p1.y = p0.y;
    
    dst = floorf(p1P->y);
    
    while (p0.y <= dst) 
    {
        MapDrawLine(&p0, &p1, 20.0f + depth, mwP->MapCol[1].color);
        
        p0.y += 32.0f;
        p1.y += 32.0f;
    }
    
    p0.x = ceilf(-16.0f + p0P->x);
    p0.y = ceilf(p0P->y);
    
    p1.x = p0.x;
    p1.y = floorf(p1P->y);
    
    dst = floorf(p1P->x);
    
    while (p0.x <= dst)
    {
        MapDrawLine(&p0, &p1, 20.0f + depth, mwP->MapCol[1].color);
        
        p0.x += 32.0f;
        p1.x += 32.0f;
    }
}

// 97.04% matching
static void MapDrawSprite(NJS_POINT3* posP, int col, mp_spr spr_no)
{
    NJS_SPRITE* sprP;
	NJS_ARGB* mtrP;
	static const NJS_TEXANIM TexAnm[18] = 
    {
        {  40,  56, 20, 26,   0,   0,  80, 112, 0, 0 },
        {  32,  16, 16,  8, 192,   0, 256,  32, 0, 0 },
        {  32,  16, 15,  8, 256,  32, 192,   0, 0, 0 },
        {  16,  32,  8, 15, 160,   0, 192,  64, 0, 0 },
        {  16,  32,  8, 16, 192,  64, 160,   0, 0, 0 },
        {  24,  24, 12, 12, 208,  80, 256, 128, 0, 0 },
        {  24,  24, 12, 12, 208, 128, 256, 176, 0, 0 },
        {  24,  24, 12, 12, 208,  32, 256,  80, 0, 0 },
        {  88,  32, 41, 16,   0, 128, 176, 192, 0, 0 },
        {  88,  16,  0,  8,   0, 192, 176, 224, 0, 0 },
        {  40,  16,  0,  8,  96,  64, 176,  96, 0, 0 },
        {  40,  16,  0,  8,  96,  96, 176, 128, 0, 0 },
        { 104,  16,  0,  8,   0, 224, 208, 256, 0, 0 },
        {  16,  16,  7,  7, 224, 224, 256, 256, 0, 0 },
        {  24,  16,  0, 16,  96,   0, 144,  32, 0, 0 },
        {  24,  16,  0, 16,  96,   0, 144,  32, 0, 0 },
        {  24,  16, 24,  0,  96,  32, 144,  64, 0, 0 },
        { 128, 128,  0,  0,   0,   0, 256, 256, 0, 0 }
    };

    sprP = &mwP->map_spr;
    mtrP = &mwP->map_mtr;
    
    sprP->ang = 0;
    
    sprP->sx = 1.0f;
    sprP->sy = 1.0f;
    
    sprP->p.x = posP->x;
    sprP->p.y = posP->y;
    
    sprP->tanim = (NJS_TEXANIM*)&TexAnm[spr_no];
    
    if (spr_no < 17) 
    {
        sprP->tlist = mwP->map_texP;
    } 
    else 
    {
        sprP->tlist = mwP->stg_texP;
    }
    
    mtrP->b = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->g = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->r = (float)(col & 0xFF) * (1.0 / 255.0);
    col >>= 8;
    
    mtrP->a = (float)(col & 0xFF) * (1.0 / 255.0);
    
    njSetConstantMaterial(mtrP);
    
    njDrawSprite2D(sprP, 0, posP->z, 0x22);
}

// 100% matching!
static int MapGetFloorNo(void* datP, int rom_no, float pos_y)
{
    int high;  
    float key;  
    int low;    
    FT_WRK* ftP; 
    int middle;  

    low  = 0;
    high = ((short*)datP)[3] - 1;
    
    key = 100.0f * rom_no;
    
    ftP = (FT_WRK*)((int)datP + ((short*)datP)[2]);
    
    do 
    {
        middle = (low + high) / 2;
        
        if ((key + pos_y) <= ftP[middle].label) 
        {
            high = middle;
        }
        else
        {
            low = middle;
        }
    } while ((high - low) != 1);
    
    if (ftP[high].label < (100.0f * rom_no)) 
    {
        return -1;
    }
    
    return (ftP[high].map_no << 16) | ftP[high].flr_no;
}

// 100% matching!
static void MapPurgeTree(ML_WORK* mlwP)
{
    NJS_CNK_OBJECT* objP; 
    NJS_MATRIX* mtxP;    
    int obj_num;         
    
    objP = mlwP->objP;
    mtxP = lcmat;
    
    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    for (obj_num = mlwP->obj_num; obj_num > 0; obj_num--, objP++) 
    {
        if (objP->sibling != NULL)
        {
            njPushMatrixEx();
        }
        
        njTranslate(NULL, objP->pos[0], objP->pos[1], objP->pos[2]);
        njRotateXYZ(NULL, objP->ang[0], objP->ang[1], objP->ang[2]);
        
        njGetMatrix(mtxP);
        
        objP->ang[0] = 10430.381f * atan2f(mtxP[0][6], mtxP[0][10]);
        objP->ang[1] = 10430.381f * asinf(-mtxP[0][2]);
        objP->ang[2] = 10430.381f * atan2f(mtxP[0][1], mtxP[0][0]);
        
        objP->pos[0] = mtxP[0][12];
        objP->pos[1] = mtxP[0][13];
        objP->pos[2] = mtxP[0][14];
        
        if (objP->child == NULL) 
        {
            njPopMatrixEx();
        }
        
        objP->child   = NULL;
        objP->sibling = NULL;
    } 
    
    njPopMatrixEx();
}

// 100% matching! 
static void MapFuncInit(int func_num) 
{
    func_wrk_typ* fwP; 

    fwP = mwP->busy_funcP = (func_wrk_typ*)bhGetFreeMemory((func_num + 2) * 64, 4);
    
    fwP->nextP = fwP->prevP = fwP;
    
    mwP->free_funcP = ++fwP;
    
    fwP->nextP = fwP->prevP = fwP;
    
    fwP++; 
    
    for ( ; func_num > 0; func_num--, fwP++) 
    {
        MapFuncIns(mwP->free_funcP, fwP);
    }
}

// 100% matching!
static func_wrk_typ* MapFuncAlloc(int(*funcP)(func_wrk_typ*), int param0) 
{
    func_wrk_typ* fwP;
    
    fwP = mwP->free_funcP->nextP;
    
    MapFuncDel(fwP);
    MapFuncIns(mwP->busy_funcP, fwP);
    
    fwP->funcP = funcP;
    
    fwP->mode = 0;
    
    fwP->param0 = param0;
    fwP->param1 = 0;
    fwP->param2 = 0;
    
    fwP->FreeWrk[0] = fwP->FreeWrk[1] = fwP->FreeWrk[2] = fwP->FreeWrk[3] = 0;
    fwP->FreeWrk[4] = fwP->FreeWrk[5] = fwP->FreeWrk[6] = fwP->FreeWrk[7] = 0;
    
    fwP->FreeWrk[8] = 0;
    
    return fwP;
}

// 100% matching!
static void MapFuncFree(func_wrk_typ* fwP) 
{
    MapFuncDel(fwP);
    MapFuncIns(mwP->free_funcP, fwP);
}

// 100% matching!
static void MapFuncDel(func_wrk_typ* fwP)
{
    fwP->prevP->nextP = fwP->nextP;
	fwP->nextP->prevP = fwP->prevP;
}

// 100% matching!
static func_wrk_typ* MapFuncIns(func_wrk_typ* bsP, func_wrk_typ* fwP)
{
    fwP->nextP = bsP->nextP;
    fwP->prevP = bsP;
    
    bsP->nextP->prevP = fwP;
    bsP->nextP        = fwP;
}

// 100% matching!
static void MapFuncExec() 
{
    func_wrk_typ* fwP, *nxP;

    for (nxP = mwP->busy_funcP->nextP; nxP != mwP->busy_funcP; nxP = fwP) 
    {
        fwP = nxP->nextP;
        
        if (nxP->funcP != NULL) 
        {
            nxP->funcP(nxP);
        }
    }
}

// 100% matching!
static int FsubMapDraw(func_wrk_typ* fwP)
{
    tag_wrk_typ* curP; // not from DWARF

    if (mwP->map_mode == MP_MOD_MAP_READ) 
    {
        mwP->map_objP = NULL;
        mwP->map_cdeP = NULL;
        
        MapFuncFree(fwP);
    } 
    else if ((mwP->map_objP != NULL) && (mwP->map_cdeP != NULL)) 
    {
        MapCodeProcess();
        
        if (!(mwP->status & 0x100)) 
        {
            mwP->status |= 0x100;
            
            curP = MapTagConnect(mwP->rom_no);
            
            mwP->cur_tagP = curP;
            
            if (curP == NULL) 
            {
                mwP->cur_tagP = MapTagCenter();
            }
        }
    }
    
    return 1;
}

// 100% matching!
static int FsubBackDraw() 
{
    MapDrawBackground(mwP->bck_depth, &mwP->bck_p0, &mwP->bck_p1);
    
    return 1;
}

// 100% matching!
static void MapEntrySprite(mp_set set_no, int mode)
{
    func_wrk_typ* fwP;
    SS_WORK* ssP;
    FSD_WORK* fsdP;
	static const SS_WORK SprSet[11] = 
    {
        { MP_SPR_SILHOUETTE,  (void*)FsprSilhouetteDraw, 1535, 0xFF004000, { 585.0f,  66.0f, -8.0f } },
        { MP_SPR_ARROW_UP,    (void*)FsprArrowDraw,      128,  0xFF008000, { 320.0f,  40.0f, -6.0f } },
        { MP_SPR_ARROW_DOWN,  (void*)FsprArrowDraw,      128,  0xFF008000, { 320.0f, 443.0f, -6.0f } },
        { MP_SPR_ARROW_LEFT,  (void*)FsprArrowDraw,      128,  0xFF008000, {  32.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_RIGHT, (void*)FsprArrowDraw,      128,  0xFF008000, { 610.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_UP,    (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 320.0f,  40.0f, -6.0f } },
        { MP_SPR_ARROW_DOWN,  (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 320.0f, 443.0f, -6.0f } },
        { MP_SPR_ARROW_LEFT,  (void*)FsprArrowDraw2,     256,  0xFF4050A0, {  32.0f, 240.0f, -6.0f } },
        { MP_SPR_ARROW_RIGHT, (void*)FsprArrowDraw2,     256,  0xFF4050A0, { 610.0f, 240.0f, -6.0f } },
        { MP_SPR_LR_ZOOM,     (void*)FsprSpriteDraw,     256,  0xFFFFFFFF, { 320.0f,  80.0f, -8.0f } },
        { MP_SPR_TITLE,       (void*)FsprSpriteDraw,     1120, 0xFFFFFFFF, {  64.0f,  32.0f, -8.0f } }
    };
    
    ssP = &SprSet[set_no];
    fwP = MapFuncAlloc(ssP->funcP, 0);
    
    if (fwP != NULL) 
    {
        fwP->param0 = (int)&mwP->map_mode;
        fwP->param1 = ssP->act_bit;
        fwP->param2 = ssP->spr_no;
        
        fwP->FreeWrk[0]                = ssP->spr_col;
        *(NJS_POINT3*)&fwP->FreeWrk[1] = *(NJS_POINT3*)&ssP->spr_pos;
        fwP->FreeWrk[4]                = mode;
    }
}

// 100% matching!
static int FsprSpriteDraw(FS_WORK* fsP) 
{
    FSD_WORK* fsdP;
    
    fsdP = (FSD_WORK*)&fsP->spr_dsp;

    if (!(fsP->spr_dsp.act_bit & (1 << *(fsP->spr_dsp.act_mdeP)))) 
    {
        MapFuncFree((func_wrk_typ*)fsP);
    } 
    else if (fsP->mode == 0) 
    {
        MapDrawSprite(&fsdP->spr_pos, fsdP->spr_col, fsdP->spr_no);
    }
    
    return 1;
}

// 100% matching!
static int FsprSilhouetteDraw(FS_WORK* fsP)
{
    FSD_WORK* fsdP; 
    FSC_WORK* fscP; 
    int bol;       
    int col_bak;    
 
    fsdP = &fsP->spr_dsp;
    fscP = &fsP->spr_cnt;
    
    bol = 1; 
    
    switch (fscP->spr_mde) 
    {                          
    case 0:
        col_bak = fsdP->spr_col;
        
        fscP->count++;
        
        if (++fscP->count >= 0xFF) 
        {
            fscP->count   = 0xFF;
            fscP->spr_mde = 1;
        }
        
        fsdP->spr_col = (fsdP->spr_col & 0xFFFFFF) | (fscP->count << 24);
        
        bol = FsprSpriteDraw(fsP);
        
        fsdP->spr_col = col_bak;
        break;
    case 1:
        bol = FsprSpriteDraw(fsP);
        break;
    }

    return bol; 
}

// 
// Start address: 0x2b49d0
static int FsprArrowDraw(FS_WORK* fsP)
{
	int flr_top;
	cnc_wrk_typ* srcP;
	cnc_wrk_typ* dstP;
	mp_no cn_d;
	mp_no cn_s;
	int* prmP;
	int p_prs;
	map_nxt* mnP;
	NJS_POINT3 bak;
	int count;
	FSC_WORK* fscP;
	FSD_WORK* fsdP;
	// Line 2161, Address: 0x2b49d0, Func Offset: 0
	// Line 2167, Address: 0x2b49ec, Func Offset: 0x1c
	// Line 2170, Address: 0x2b49f0, Func Offset: 0x20
	// Line 2172, Address: 0x2b4a04, Func Offset: 0x34
	// Line 2170, Address: 0x2b4a08, Func Offset: 0x38
	// Line 2172, Address: 0x2b4a14, Func Offset: 0x44
	// Line 2162, Address: 0x2b4a18, Func Offset: 0x48
	// Line 2172, Address: 0x2b4a1c, Func Offset: 0x4c
	// Line 2173, Address: 0x2b4a4c, Func Offset: 0x7c
	// Line 2174, Address: 0x2b4a78, Func Offset: 0xa8
	// Line 2175, Address: 0x2b4aa4, Func Offset: 0xd4
	// Line 2176, Address: 0x2b4ad0, Func Offset: 0x100
	// Line 2179, Address: 0x2b4af4, Func Offset: 0x124
	// Line 2180, Address: 0x2b4b04, Func Offset: 0x134
	// Line 2181, Address: 0x2b4b10, Func Offset: 0x140
	// Line 2183, Address: 0x2b4b18, Func Offset: 0x148
	// Line 2185, Address: 0x2b4b28, Func Offset: 0x158
	// Line 2183, Address: 0x2b4b2c, Func Offset: 0x15c
	// Line 2185, Address: 0x2b4b38, Func Offset: 0x168
	// Line 2186, Address: 0x2b4b3c, Func Offset: 0x16c
	// Line 2190, Address: 0x2b4b58, Func Offset: 0x188
	// Line 2192, Address: 0x2b4b70, Func Offset: 0x1a0
	// Line 2196, Address: 0x2b4b74, Func Offset: 0x1a4
	// Line 2193, Address: 0x2b4b78, Func Offset: 0x1a8
	// Line 2196, Address: 0x2b4b7c, Func Offset: 0x1ac
	// Line 2197, Address: 0x2b4bb0, Func Offset: 0x1e0
	// Line 2198, Address: 0x2b4bc4, Func Offset: 0x1f4
	// Line 2199, Address: 0x2b4bd8, Func Offset: 0x208
	// Line 2200, Address: 0x2b4bec, Func Offset: 0x21c
	// Line 2203, Address: 0x2b4bfc, Func Offset: 0x22c
	// Line 2204, Address: 0x2b4c04, Func Offset: 0x234
	// Line 2214, Address: 0x2b4c10, Func Offset: 0x240
	// Line 2216, Address: 0x2b4c30, Func Offset: 0x260
	// Line 2217, Address: 0x2b4c44, Func Offset: 0x274
	// Line 2216, Address: 0x2b4c48, Func Offset: 0x278
	// Line 2217, Address: 0x2b4c4c, Func Offset: 0x27c
	// Line 2218, Address: 0x2b4c54, Func Offset: 0x284
	// Line 2219, Address: 0x2b4c5c, Func Offset: 0x28c
	// Line 2217, Address: 0x2b4c60, Func Offset: 0x290
	// Line 2221, Address: 0x2b4c64, Func Offset: 0x294
	// Line 2218, Address: 0x2b4c6c, Func Offset: 0x29c
	// Line 2219, Address: 0x2b4c70, Func Offset: 0x2a0
	// Line 2218, Address: 0x2b4c78, Func Offset: 0x2a8
	// Line 2221, Address: 0x2b4c80, Func Offset: 0x2b0
	// Line 2222, Address: 0x2b4c94, Func Offset: 0x2c4
	// Line 2223, Address: 0x2b4c9c, Func Offset: 0x2cc
	// Line 2224, Address: 0x2b4cac, Func Offset: 0x2dc
	// Line 2229, Address: 0x2b4cb8, Func Offset: 0x2e8
	// Line 2231, Address: 0x2b4cc4, Func Offset: 0x2f4
	// Line 2230, Address: 0x2b4cc8, Func Offset: 0x2f8
	// Line 2229, Address: 0x2b4ccc, Func Offset: 0x2fc
	// Line 2230, Address: 0x2b4cd0, Func Offset: 0x300
	// Line 2231, Address: 0x2b4cd8, Func Offset: 0x308
	// Line 2230, Address: 0x2b4cdc, Func Offset: 0x30c
	// Line 2231, Address: 0x2b4ce0, Func Offset: 0x310
	// Line 2236, Address: 0x2b4ce8, Func Offset: 0x318
	// Line 2235, Address: 0x2b4d00, Func Offset: 0x330
	// Line 2236, Address: 0x2b4d04, Func Offset: 0x334
	// Func End, Address: 0x2b4d0c, Func Offset: 0x33c
	scePrintf("FsprArrowDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b4d10
static int FsprArrowDraw2(FS_WORK* fsP)
{
	NJS_POINT3 bak;
	int tab;
	int count;
	tag_wrk_typ* twP;
	FSC_WORK* fscP;
	FSD_WORK* fsdP;
	// Line 2246, Address: 0x2b4d10, Func Offset: 0
	// Line 2249, Address: 0x2b4d30, Func Offset: 0x20
	// Line 2252, Address: 0x2b4d3c, Func Offset: 0x2c
	// Line 2256, Address: 0x2b4d40, Func Offset: 0x30
	// Line 2249, Address: 0x2b4d4c, Func Offset: 0x3c
	// Line 2256, Address: 0x2b4d50, Func Offset: 0x40
	// Line 2247, Address: 0x2b4d54, Func Offset: 0x44
	// Line 2256, Address: 0x2b4d58, Func Offset: 0x48
	// Line 2257, Address: 0x2b4d64, Func Offset: 0x54
	// Line 2258, Address: 0x2b4d9c, Func Offset: 0x8c
	// Line 2259, Address: 0x2b4dcc, Func Offset: 0xbc
	// Line 2260, Address: 0x2b4dfc, Func Offset: 0xec
	// Line 2261, Address: 0x2b4e2c, Func Offset: 0x11c
	// Line 2263, Address: 0x2b4e54, Func Offset: 0x144
	// Line 2264, Address: 0x2b4e64, Func Offset: 0x154
	// Line 2266, Address: 0x2b4e6c, Func Offset: 0x15c
	// Line 2264, Address: 0x2b4e74, Func Offset: 0x164
	// Line 2266, Address: 0x2b4e78, Func Offset: 0x168
	// Line 2268, Address: 0x2b4e94, Func Offset: 0x184
	// Line 2269, Address: 0x2b4e9c, Func Offset: 0x18c
	// Line 2271, Address: 0x2b4eac, Func Offset: 0x19c
	// Line 2269, Address: 0x2b4eb0, Func Offset: 0x1a0
	// Line 2271, Address: 0x2b4ebc, Func Offset: 0x1ac
	// Line 2272, Address: 0x2b4ec0, Func Offset: 0x1b0
	// Line 2276, Address: 0x2b4edc, Func Offset: 0x1cc
	// Line 2275, Address: 0x2b4ef8, Func Offset: 0x1e8
	// Line 2276, Address: 0x2b4efc, Func Offset: 0x1ec
	// Func End, Address: 0x2b4f04, Func Offset: 0x1f4
	scePrintf("FsprArrowDraw2 - UNIMPLEMENTED!\n");
}

// 100% matching!
static FT_WORK* MapEntryTask(int(*tskP)(FTS_WORK*), mp_mod chg_mde, int param0) 
{
    func_wrk_typ* fwP;
    FT_WORK* ftP;

    fwP = MapFuncAlloc((void*)FsubTaskMain, 0);
    ftP = NULL;
    
    if (fwP != NULL) 
    {
        fwP->param0 = (int)&mwP->map_mode;
        fwP->param1 = chg_mde; 
        fwP->param2 = (int)tskP;
        
        fwP->FreeWrk[0] = param0;

        ftP = (FT_WORK*)fwP;
        
        return ftP;
    }
    
    return ftP;
}

// 100% matching!
static int FsubTaskMain(FT_WORK* ftP) 
{
    if (ftP->tskP(&ftP->tsk_sub) == 0) 
    {
        *ftP->map_mdeP = ftP->chg_mde;
        
        MapFuncFree((func_wrk_typ*)ftP);
    }
    
    return 1;
}

// 100% matching!
static int FtskMapWait()
{
    int bol;

    bol = 1;
    
    if (!(sys->st_flg & 0x8)) 
    {
        bol = 0;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapExit() 
{
    int bol;

    bol = 1;
    
    if (!(sys->cb_flg & 0x2)) 
    {
        bol = 0;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapRead(FTS_WORK* ftsP) 
{
    int bol;

    bol = 1;
    
    switch (ftsP->param3) 
    {                          
    case 0:
        mwP->fil_mode = 0;
        
        ftsP->param3++;
    case 1:
        if (bhReadMapData((char*)ftsP->param0) != 0) 
        {
            bol = 0;
        }
        
        break;
    }
    
    return bol;
}

// 100% matching!
static int FtskMapNormal(FTS_WORK* ftsP)
{
    int bol;   
    map_nxt* mnP; 
    
    bol = 1;
    
    switch (ftsP->param3) 
    {                              
    case 0:
        CallSystemSe(0, 5);
        
        mwP->dst_pos = mwP->vew_pos_bak;
        mwP->dst_zom = mwP->vew_zom_bak;
        
        mnP = MapCheckNextMap(&mwP->map_nxt);
        
        if (mnP->map_up != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_UP, 0);
        }
        
        if (mnP->map_down != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_DOWN, 1);
        }
        
        if (mnP->map_left != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_LEFT, 2);
        }
        
        if (mnP->map_right != -1) 
        {
            MapEntrySprite(MP_SET_ARROW_RIGHT, 3);
        }
        
        ftsP->param3++;
        break;
    case 1:
        if (mwP->map_mode == MP_MOD_MAP_READ) 
        {
            MapFuncFree((func_wrk_typ*)&ftsP[-1]);
        } 
        else if (((mwP->pad_ps & 0x100)) && (mwP->cur_tagP != NULL)) 
        {
            bol = 0;
        }
        
        break;
    }
    
    return bol;
}

// 
// Start address: 0x2b5220
static int FtskMapZoom(FTS_WORK* ftsP)
{
	int tag;
	tag_wrk_typ* twP;
	unsigned int p_prs;
	FG_WORK* fgP;
	//tag_wrk_typ* twP;
	int bol;
	// Line 2483, Address: 0x2b5220, Func Offset: 0
	// Line 2486, Address: 0x2b5230, Func Offset: 0x10
	// Line 2484, Address: 0x2b5234, Func Offset: 0x14
	// Line 2486, Address: 0x2b5238, Func Offset: 0x18
	// Line 2489, Address: 0x2b5250, Func Offset: 0x30
	// Line 2493, Address: 0x2b525c, Func Offset: 0x3c
	// Line 2498, Address: 0x2b5264, Func Offset: 0x44
	// Line 2496, Address: 0x2b526c, Func Offset: 0x4c
	// Line 2505, Address: 0x2b5270, Func Offset: 0x50
	// Line 2493, Address: 0x2b5274, Func Offset: 0x54
	// Line 2494, Address: 0x2b5278, Func Offset: 0x58
	// Line 2505, Address: 0x2b527c, Func Offset: 0x5c
	// Line 2497, Address: 0x2b5280, Func Offset: 0x60
	// Line 2493, Address: 0x2b5284, Func Offset: 0x64
	// Line 2494, Address: 0x2b5288, Func Offset: 0x68
	// Line 2505, Address: 0x2b528c, Func Offset: 0x6c
	// Line 2494, Address: 0x2b5290, Func Offset: 0x70
	// Line 2495, Address: 0x2b5294, Func Offset: 0x74
	// Line 2494, Address: 0x2b5298, Func Offset: 0x78
	// Line 2495, Address: 0x2b52a0, Func Offset: 0x80
	// Line 2496, Address: 0x2b52a8, Func Offset: 0x88
	// Line 2495, Address: 0x2b52ac, Func Offset: 0x8c
	// Line 2496, Address: 0x2b52b0, Func Offset: 0x90
	// Line 2497, Address: 0x2b52b8, Func Offset: 0x98
	// Line 2498, Address: 0x2b52c4, Func Offset: 0xa4
	// Line 2500, Address: 0x2b52d0, Func Offset: 0xb0
	// Line 2498, Address: 0x2b52d4, Func Offset: 0xb4
	// Line 2500, Address: 0x2b52dc, Func Offset: 0xbc
	// Line 2501, Address: 0x2b52e4, Func Offset: 0xc4
	// Line 2500, Address: 0x2b52e8, Func Offset: 0xc8
	// Line 2501, Address: 0x2b52ec, Func Offset: 0xcc
	// Line 2502, Address: 0x2b52f4, Func Offset: 0xd4
	// Line 2501, Address: 0x2b52f8, Func Offset: 0xd8
	// Line 2502, Address: 0x2b52fc, Func Offset: 0xdc
	// Line 2505, Address: 0x2b5304, Func Offset: 0xe4
	// Line 2506, Address: 0x2b530c, Func Offset: 0xec
	// Line 2507, Address: 0x2b531c, Func Offset: 0xfc
	// Line 2508, Address: 0x2b5328, Func Offset: 0x108
	// Line 2509, Address: 0x2b5334, Func Offset: 0x114
	// Line 2510, Address: 0x2b5340, Func Offset: 0x120
	// Line 2511, Address: 0x2b534c, Func Offset: 0x12c
	// Line 2518, Address: 0x2b5358, Func Offset: 0x138
	// Line 2519, Address: 0x2b5368, Func Offset: 0x148
	// Line 2520, Address: 0x2b5370, Func Offset: 0x150
	// Line 2521, Address: 0x2b5378, Func Offset: 0x158
	// Line 2524, Address: 0x2b5380, Func Offset: 0x160
	// Line 2525, Address: 0x2b5384, Func Offset: 0x164
	// Line 2529, Address: 0x2b538c, Func Offset: 0x16c
	// Line 2531, Address: 0x2b5394, Func Offset: 0x174
	// Line 2533, Address: 0x2b53a4, Func Offset: 0x184
	// Line 2534, Address: 0x2b53ac, Func Offset: 0x18c
	// Line 2535, Address: 0x2b53b4, Func Offset: 0x194
	// Line 2536, Address: 0x2b53c0, Func Offset: 0x1a0
	// Line 2537, Address: 0x2b53c8, Func Offset: 0x1a8
	// Line 2536, Address: 0x2b53cc, Func Offset: 0x1ac
	// Line 2538, Address: 0x2b53d0, Func Offset: 0x1b0
	// Line 2541, Address: 0x2b53d8, Func Offset: 0x1b8
	// Line 2544, Address: 0x2b53e0, Func Offset: 0x1c0
	// Line 2545, Address: 0x2b53f4, Func Offset: 0x1d4
	// Line 2546, Address: 0x2b5408, Func Offset: 0x1e8
	// Line 2547, Address: 0x2b541c, Func Offset: 0x1fc
	// Line 2549, Address: 0x2b542c, Func Offset: 0x20c
	// Line 2550, Address: 0x2b5438, Func Offset: 0x218
	// Line 2551, Address: 0x2b544c, Func Offset: 0x22c
	// Line 2553, Address: 0x2b5450, Func Offset: 0x230
	// Line 2558, Address: 0x2b545c, Func Offset: 0x23c
	// Line 2554, Address: 0x2b5464, Func Offset: 0x244
	// Line 2553, Address: 0x2b5468, Func Offset: 0x248
	// Line 2554, Address: 0x2b546c, Func Offset: 0x24c
	// Line 2555, Address: 0x2b5474, Func Offset: 0x254
	// Line 2554, Address: 0x2b5478, Func Offset: 0x258
	// Line 2555, Address: 0x2b547c, Func Offset: 0x25c
	// Line 2556, Address: 0x2b5484, Func Offset: 0x264
	// Line 2555, Address: 0x2b5488, Func Offset: 0x268
	// Line 2556, Address: 0x2b548c, Func Offset: 0x26c
	// Line 2558, Address: 0x2b5494, Func Offset: 0x274
	// Line 2565, Address: 0x2b549c, Func Offset: 0x27c
	// Line 2567, Address: 0x2b54b0, Func Offset: 0x290
	// Line 2565, Address: 0x2b54b4, Func Offset: 0x294
	// Line 2566, Address: 0x2b54bc, Func Offset: 0x29c
	// Line 2565, Address: 0x2b54c0, Func Offset: 0x2a0
	// Line 2566, Address: 0x2b54cc, Func Offset: 0x2ac
	// Line 2567, Address: 0x2b54d8, Func Offset: 0x2b8
	// Line 2566, Address: 0x2b54dc, Func Offset: 0x2bc
	// Line 2567, Address: 0x2b54e8, Func Offset: 0x2c8
	// Line 2568, Address: 0x2b5514, Func Offset: 0x2f4
	// Line 2592, Address: 0x2b5548, Func Offset: 0x328
	// Line 2593, Address: 0x2b554c, Func Offset: 0x32c
	// Func End, Address: 0x2b5560, Func Offset: 0x340
	scePrintf("FtskMapZoom - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b5560
static int FsubGaugeDrawZ(FG_WORK* fgP)
{
	float size;
	float tmp;
	float dsp;
	float pos;
	int cnt;
	NJS_POINT2 pnt[2];
	NJS_COLOR col[2];
	float scl;
	NJS_POINT2COL p2c;
	// Line 2712, Address: 0x2b5560, Func Offset: 0
	// Line 2719, Address: 0x2b558c, Func Offset: 0x2c
	// Line 2728, Address: 0x2b559c, Func Offset: 0x3c
	// Line 2736, Address: 0x2b55a0, Func Offset: 0x40
	// Line 2719, Address: 0x2b55a4, Func Offset: 0x44
	// Line 2729, Address: 0x2b55b0, Func Offset: 0x50
	// Line 2736, Address: 0x2b55b4, Func Offset: 0x54
	// Line 2730, Address: 0x2b55b8, Func Offset: 0x58
	// Line 2719, Address: 0x2b55bc, Func Offset: 0x5c
	// Line 2727, Address: 0x2b55c4, Func Offset: 0x64
	// Line 2719, Address: 0x2b55c8, Func Offset: 0x68
	// Line 2727, Address: 0x2b55cc, Func Offset: 0x6c
	// Line 2728, Address: 0x2b55d0, Func Offset: 0x70
	// Line 2729, Address: 0x2b55d8, Func Offset: 0x78
	// Line 2730, Address: 0x2b55e0, Func Offset: 0x80
	// Line 2738, Address: 0x2b55e8, Func Offset: 0x88
	// Line 2719, Address: 0x2b55ec, Func Offset: 0x8c
	// Line 2736, Address: 0x2b55f0, Func Offset: 0x90
	// Line 2719, Address: 0x2b55f4, Func Offset: 0x94
	// Line 2738, Address: 0x2b55f8, Func Offset: 0x98
	// Line 2736, Address: 0x2b5600, Func Offset: 0xa0
	// Line 2740, Address: 0x2b5608, Func Offset: 0xa8
	// Line 2741, Address: 0x2b5624, Func Offset: 0xc4
	// Line 2740, Address: 0x2b5628, Func Offset: 0xc8
	// Line 2741, Address: 0x2b5630, Func Offset: 0xd0
	// Line 2742, Address: 0x2b5644, Func Offset: 0xe4
	// Line 2743, Address: 0x2b5668, Func Offset: 0x108
	// Line 2742, Address: 0x2b5674, Func Offset: 0x114
	// Line 2743, Address: 0x2b5678, Func Offset: 0x118
	// Line 2744, Address: 0x2b5688, Func Offset: 0x128
	// Line 2746, Address: 0x2b5698, Func Offset: 0x138
	// Line 2744, Address: 0x2b569c, Func Offset: 0x13c
	// Line 2746, Address: 0x2b56a0, Func Offset: 0x140
	// Line 2744, Address: 0x2b56a8, Func Offset: 0x148
	// Line 2745, Address: 0x2b56ac, Func Offset: 0x14c
	// Line 2746, Address: 0x2b56b4, Func Offset: 0x154
	// Line 2747, Address: 0x2b56c4, Func Offset: 0x164
	// Line 2748, Address: 0x2b56c8, Func Offset: 0x168
	// Line 2747, Address: 0x2b56d4, Func Offset: 0x174
	// Line 2748, Address: 0x2b56d8, Func Offset: 0x178
	// Line 2749, Address: 0x2b56ec, Func Offset: 0x18c
	// Line 2748, Address: 0x2b56f0, Func Offset: 0x190
	// Line 2749, Address: 0x2b56f4, Func Offset: 0x194
	// Line 2748, Address: 0x2b5700, Func Offset: 0x1a0
	// Line 2749, Address: 0x2b5704, Func Offset: 0x1a4
	// Line 2752, Address: 0x2b5710, Func Offset: 0x1b0
	// Line 2754, Address: 0x2b5744, Func Offset: 0x1e4
	// Line 2755, Address: 0x2b5764, Func Offset: 0x204
	// Line 2756, Address: 0x2b576c, Func Offset: 0x20c
	// Line 2757, Address: 0x2b5770, Func Offset: 0x210
	// Line 2758, Address: 0x2b5778, Func Offset: 0x218
	// Line 2759, Address: 0x2b5790, Func Offset: 0x230
	// Line 2764, Address: 0x2b57b8, Func Offset: 0x258
	// Line 2767, Address: 0x2b57d4, Func Offset: 0x274
	// Line 2768, Address: 0x2b5800, Func Offset: 0x2a0
	// Line 2769, Address: 0x2b5830, Func Offset: 0x2d0
	// Line 2772, Address: 0x2b5838, Func Offset: 0x2d8
	// Line 2775, Address: 0x2b584c, Func Offset: 0x2ec
	// Line 2772, Address: 0x2b5850, Func Offset: 0x2f0
	// Line 2775, Address: 0x2b5854, Func Offset: 0x2f4
	// Line 2772, Address: 0x2b585c, Func Offset: 0x2fc
	// Line 2773, Address: 0x2b5864, Func Offset: 0x304
	// Line 2774, Address: 0x2b586c, Func Offset: 0x30c
	// Line 2775, Address: 0x2b5878, Func Offset: 0x318
	// Line 2776, Address: 0x2b5888, Func Offset: 0x328
	// Line 2783, Address: 0x2b58b8, Func Offset: 0x358
	// Line 2782, Address: 0x2b58e0, Func Offset: 0x380
	// Line 2783, Address: 0x2b58e4, Func Offset: 0x384
	// Func End, Address: 0x2b58ec, Func Offset: 0x38c
	scePrintf("FsubGaugeDrawZ - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b58f0
static int FsubGaugeDrawX(FG_WORK* fgP)
{
	float size;
	float tmp;
	float dsp;
	float pos;
	int cnt;
	NJS_POINT2 pnt[2];
	NJS_COLOR col[2];
	float scl;
	NJS_POINT2COL p2c;
	// Line 2793, Address: 0x2b58f0, Func Offset: 0
	// Line 2800, Address: 0x2b591c, Func Offset: 0x2c
	// Line 2810, Address: 0x2b592c, Func Offset: 0x3c
	// Line 2801, Address: 0x2b5930, Func Offset: 0x40
	// Line 2800, Address: 0x2b5934, Func Offset: 0x44
	// Line 2801, Address: 0x2b5940, Func Offset: 0x50
	// Line 2811, Address: 0x2b5948, Func Offset: 0x58
	// Line 2800, Address: 0x2b594c, Func Offset: 0x5c
	// Line 2812, Address: 0x2b5950, Func Offset: 0x60
	// Line 2809, Address: 0x2b5954, Func Offset: 0x64
	// Line 2800, Address: 0x2b595c, Func Offset: 0x6c
	// Line 2809, Address: 0x2b5960, Func Offset: 0x70
	// Line 2810, Address: 0x2b5964, Func Offset: 0x74
	// Line 2811, Address: 0x2b596c, Func Offset: 0x7c
	// Line 2812, Address: 0x2b5974, Func Offset: 0x84
	// Line 2818, Address: 0x2b597c, Func Offset: 0x8c
	// Line 2820, Address: 0x2b5980, Func Offset: 0x90
	// Line 2800, Address: 0x2b598c, Func Offset: 0x9c
	// Line 2821, Address: 0x2b5994, Func Offset: 0xa4
	// Line 2800, Address: 0x2b5998, Func Offset: 0xa8
	// Line 2821, Address: 0x2b59a0, Func Offset: 0xb0
	// Line 2822, Address: 0x2b59b8, Func Offset: 0xc8
	// Line 2821, Address: 0x2b59bc, Func Offset: 0xcc
	// Line 2822, Address: 0x2b59c4, Func Offset: 0xd4
	// Line 2823, Address: 0x2b59dc, Func Offset: 0xec
	// Line 2824, Address: 0x2b5a00, Func Offset: 0x110
	// Line 2823, Address: 0x2b5a0c, Func Offset: 0x11c
	// Line 2824, Address: 0x2b5a10, Func Offset: 0x120
	// Line 2825, Address: 0x2b5a20, Func Offset: 0x130
	// Line 2827, Address: 0x2b5a40, Func Offset: 0x150
	// Line 2825, Address: 0x2b5a44, Func Offset: 0x154
	// Line 2827, Address: 0x2b5a48, Func Offset: 0x158
	// Line 2825, Address: 0x2b5a50, Func Offset: 0x160
	// Line 2826, Address: 0x2b5a54, Func Offset: 0x164
	// Line 2827, Address: 0x2b5a5c, Func Offset: 0x16c
	// Line 2828, Address: 0x2b5a6c, Func Offset: 0x17c
	// Line 2829, Address: 0x2b5a70, Func Offset: 0x180
	// Line 2828, Address: 0x2b5a7c, Func Offset: 0x18c
	// Line 2829, Address: 0x2b5a80, Func Offset: 0x190
	// Line 2830, Address: 0x2b5a94, Func Offset: 0x1a4
	// Line 2829, Address: 0x2b5a98, Func Offset: 0x1a8
	// Line 2830, Address: 0x2b5a9c, Func Offset: 0x1ac
	// Line 2829, Address: 0x2b5aa4, Func Offset: 0x1b4
	// Line 2830, Address: 0x2b5aa8, Func Offset: 0x1b8
	// Line 2833, Address: 0x2b5ab8, Func Offset: 0x1c8
	// Line 2835, Address: 0x2b5aec, Func Offset: 0x1fc
	// Line 2836, Address: 0x2b5b0c, Func Offset: 0x21c
	// Line 2837, Address: 0x2b5b14, Func Offset: 0x224
	// Line 2838, Address: 0x2b5b18, Func Offset: 0x228
	// Line 2839, Address: 0x2b5b20, Func Offset: 0x230
	// Line 2840, Address: 0x2b5b38, Func Offset: 0x248
	// Line 2844, Address: 0x2b5b60, Func Offset: 0x270
	// Line 2847, Address: 0x2b5b7c, Func Offset: 0x28c
	// Line 2848, Address: 0x2b5ba8, Func Offset: 0x2b8
	// Line 2849, Address: 0x2b5bd8, Func Offset: 0x2e8
	// Line 2852, Address: 0x2b5be0, Func Offset: 0x2f0
	// Line 2855, Address: 0x2b5bf4, Func Offset: 0x304
	// Line 2852, Address: 0x2b5bf8, Func Offset: 0x308
	// Line 2855, Address: 0x2b5bfc, Func Offset: 0x30c
	// Line 2852, Address: 0x2b5c04, Func Offset: 0x314
	// Line 2853, Address: 0x2b5c0c, Func Offset: 0x31c
	// Line 2854, Address: 0x2b5c18, Func Offset: 0x328
	// Line 2855, Address: 0x2b5c20, Func Offset: 0x330
	// Line 2856, Address: 0x2b5c30, Func Offset: 0x340
	// Line 2863, Address: 0x2b5c60, Func Offset: 0x370
	// Line 2862, Address: 0x2b5c88, Func Offset: 0x398
	// Line 2863, Address: 0x2b5c8c, Func Offset: 0x39c
	// Func End, Address: 0x2b5c94, Func Offset: 0x3a4
	scePrintf("FsubGaugeDrawX - UNIMPLEMENTED!\n");
}

// 86.86% matching
static int FsubGaugeDraw(FG_WORK* fgP)
{
    float scl_y;   
    NJS_POINT3 p0; 
    
    FsubGaugeDrawZ(fgP);
    FsubGaugeDrawX(fgP);
    
    scl_y = (_nj_screen_.dist * (5.0f / mwP->vew_mtxP[0][14])) / 5.0f;
    
    p0.x = 2.0f + fgP->gge_pos.x;
    p0.y = 8.0f + (fgP->gge_pos.y - (100.0f * scl_y));
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_10M_L);
    
    p0.x = fgP->gge_pos.x - 2.0f;
    p0.y = 1.0f + fgP->gge_pos.y;
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_0M);
    
    p0.x = (fgP->gge_pos.x + (100.0f * (1.174f * scl_y))) - 8.0f;
    p0.y = fgP->gge_pos.y - 2.0f;
    p0.z = fgP->gge_pos.z;
    
    MapDrawSprite(&p0, -1, MP_SPR_10M_D);
    
    if (mwP->map_mode != MP_MOD_WAIT_ZOOM)
    {
        MapFuncFree((func_wrk_typ*)fgP);
    }
    
    return 1;
}

// 100% matching!
static void MapTagInit(int tag_num)
{
    mwP->tag_num = 0;
    mwP->tag_wrkP = (tag_wrk_typ*)bhGetFreeMemory(tag_num * 32, 4);
}

// 100% matching!
static void MapTagEntry(NJS_MATRIX* basP, int rom_no, NJS_POINT3* posP)
{
    tag_wrk_typ* twP;

    twP = &mwP->tag_wrkP[mwP->tag_num++];
    
    twP->rom_no = rom_no;   
    
    if (basP != NULL) 
    {
        njCalcPoint(basP, posP, &twP->pos);
    }
    else 
    {
        twP->pos = *posP;
    } 
}

// 
// Start address: 0x2b5ef0
static tag_wrk_typ* MapTagConnect(int rom_no)
{
	int dir;
	float d;
	tag_wrk_typ* twP;
	float dst[4];
	int i;
	tag_wrk_typ* basP;
	tag_wrk_typ* rtnP;
	int num;
	// Line 2959, Address: 0x2b5ef0, Func Offset: 0
	// Line 2962, Address: 0x2b5f14, Func Offset: 0x24
	// Line 2964, Address: 0x2b5f20, Func Offset: 0x30
	// Line 2962, Address: 0x2b5f24, Func Offset: 0x34
	// Line 2964, Address: 0x2b5f28, Func Offset: 0x38
	// Line 2968, Address: 0x2b5f30, Func Offset: 0x40
	// Line 2971, Address: 0x2b5f38, Func Offset: 0x48
	// Line 2968, Address: 0x2b5f40, Func Offset: 0x50
	// Line 2973, Address: 0x2b5f44, Func Offset: 0x54
	// Line 2971, Address: 0x2b5f48, Func Offset: 0x58
	// Line 2972, Address: 0x2b5f58, Func Offset: 0x68
	// Line 2973, Address: 0x2b5f68, Func Offset: 0x78
	// Line 2974, Address: 0x2b5f78, Func Offset: 0x88
	// Line 2978, Address: 0x2b5f80, Func Offset: 0x90
	// Line 2979, Address: 0x2b5f88, Func Offset: 0x98
	// Line 2978, Address: 0x2b5f90, Func Offset: 0xa0
	// Line 2979, Address: 0x2b5f94, Func Offset: 0xa4
	// Line 2980, Address: 0x2b5f98, Func Offset: 0xa8
	// Line 2982, Address: 0x2b5f9c, Func Offset: 0xac
	// Line 2983, Address: 0x2b5fc4, Func Offset: 0xd4
	// Line 2984, Address: 0x2b5fe4, Func Offset: 0xf4
	// Line 2985, Address: 0x2b5fe8, Func Offset: 0xf8
	// Line 2988, Address: 0x2b5ff0, Func Offset: 0x100
	// Line 2990, Address: 0x2b6000, Func Offset: 0x110
	// Line 2991, Address: 0x2b6010, Func Offset: 0x120
	// Line 2993, Address: 0x2b6020, Func Offset: 0x130
	// Line 2994, Address: 0x2b6024, Func Offset: 0x134
	// Func End, Address: 0x2b604c, Func Offset: 0x15c
	scePrintf("MapTagConnect - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b6050
static tag_wrk_typ* MapTagCenter()
{
	float d;
	tag_wrk_typ* rtnP;
	tag_wrk_typ* twP;
	float dst;
	int num;
	//tag_wrk_typ* twP;
	float f_num;
	//int num;
	// Line 3013, Address: 0x2b6050, Func Offset: 0
	// Line 3007, Address: 0x2b605c, Func Offset: 0xc
	// Line 3013, Address: 0x2b6060, Func Offset: 0x10
	// Line 3007, Address: 0x2b6064, Func Offset: 0x14
	// Line 3013, Address: 0x2b6068, Func Offset: 0x18
	// Line 3017, Address: 0x2b606c, Func Offset: 0x1c
	// Line 3013, Address: 0x2b6070, Func Offset: 0x20
	// Line 3017, Address: 0x2b6074, Func Offset: 0x24
	// Line 3013, Address: 0x2b6078, Func Offset: 0x28
	// Line 3019, Address: 0x2b607c, Func Offset: 0x2c
	// Line 3013, Address: 0x2b6080, Func Offset: 0x30
	// Line 3019, Address: 0x2b608c, Func Offset: 0x3c
	// Line 3020, Address: 0x2b6094, Func Offset: 0x44
	// Line 3022, Address: 0x2b6098, Func Offset: 0x48
	// Line 3023, Address: 0x2b609c, Func Offset: 0x4c
	// Line 3020, Address: 0x2b60a0, Func Offset: 0x50
	// Line 3023, Address: 0x2b60a4, Func Offset: 0x54
	// Line 3024, Address: 0x2b60b0, Func Offset: 0x60
	// Line 3032, Address: 0x2b60b4, Func Offset: 0x64
	// Line 3026, Address: 0x2b60bc, Func Offset: 0x6c
	// Line 3032, Address: 0x2b60c0, Func Offset: 0x70
	// Line 3036, Address: 0x2b60c4, Func Offset: 0x74
	// Line 3040, Address: 0x2b60cc, Func Offset: 0x7c
	// Line 3042, Address: 0x2b60d0, Func Offset: 0x80
	// Line 3040, Address: 0x2b60d4, Func Offset: 0x84
	// Line 3042, Address: 0x2b60d8, Func Offset: 0x88
	// Line 3043, Address: 0x2b60dc, Func Offset: 0x8c
	// Line 3045, Address: 0x2b60e4, Func Offset: 0x94
	// Line 3046, Address: 0x2b60f4, Func Offset: 0xa4
	// Line 3047, Address: 0x2b60f8, Func Offset: 0xa8
	// Line 3048, Address: 0x2b60fc, Func Offset: 0xac
	// Line 3049, Address: 0x2b6100, Func Offset: 0xb0
	// Line 3053, Address: 0x2b6110, Func Offset: 0xc0
	// Func End, Address: 0x2b6118, Func Offset: 0xc8
	scePrintf("MapTagCenter - UNIMPLEMENTED!\n");
}

// 100% matching!
static void MapDrawLine2(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal) 
{
    static NJS_POINT2 pnt[2];
    static NJS_COLOR col[2];
    static NJS_POINT2COL p2c = { pnt, col, NULL, 1 };

    pnt[0].x = srcP->x;
    pnt[0].y = srcP->y;

    pnt[1].x = dstP->x;
    pnt[1].y = dstP->y;

    col[0].color = col[1].color = pal;

    njDrawLine2D(&p2c, p2c.num, pri, 0x40);
}

// 100% matching!
static void MapDrawLine(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal)
{ 
    static NJS_POINT2 pnt[2];
    static NJS_COLOR col[2];
    static NJS_POINT2COL p2c = { pnt, col, NULL, 1 };

    pnt[0].x = 0.5f + floorf(srcP->x);
    pnt[0].y = 0.5f + floorf(srcP->y);
    
    pnt[1].x = 0.5f + floorf(dstP->x);
    pnt[1].y = 0.5f + floorf(dstP->y);
    
    col[0].color = col[1].color = pal;

    njDrawLine2D(&p2c, p2c.num, pri, 0);
}

// 100% matching!
static void MapDrawFill(NJS_POINT2* srcP, NJS_POINT2* dstP, float pri, int pal) 
{
    static NJS_POINT2 pnt[4];
    
    pnt[0].x = srcP->x;
    pnt[0].y = srcP->y;

    pnt[1].x = dstP->x;
    pnt[1].y = srcP->y;
    
    pnt[2].x = dstP->x;
    pnt[2].y = dstP->y;
    
    pnt[3].x = srcP->x;
    pnt[3].y = dstP->y;
    
    MapDrawPolyFill(pnt, pri, pal);
}

// 100% matching!
static void MapDrawPolyFill(NJS_POINT2* pnt, float pri, int pal) 
{
    static NJS_COLOR col[4];
    static NJS_POINT2COL p2c = { NULL, col, NULL, 4 };

    p2c.p = pnt;
    
    col[0].color = col[1].color = col[2].color = col[3].color = pal;
    
    njDrawPolygon2D(&p2c, p2c.num, pri, 0x60);
}

// 100% matching!
static void MapDrawMessage(int rom, float x, float y) // parameters not present on DWARF
{

}

// 
// Start address: 0x2b6320
static int FsubZoomCursor(FZ_WORK* fzP)
{
	NJS_POINT2 dst_pos2[4];
	NJS_POINT2 dst_pos1[4];
	NJS_POINT2 dst_pos0[4];
	// Line 3165, Address: 0x2b6320, Func Offset: 0
	// Line 3182, Address: 0x2b6330, Func Offset: 0x10
	// Line 3186, Address: 0x2b635c, Func Offset: 0x3c
	// Line 3185, Address: 0x2b6364, Func Offset: 0x44
	// Line 3186, Address: 0x2b6368, Func Offset: 0x48
	// Line 3187, Address: 0x2b6370, Func Offset: 0x50
	// Line 3186, Address: 0x2b6378, Func Offset: 0x58
	// Line 3187, Address: 0x2b6380, Func Offset: 0x60
	// Line 3188, Address: 0x2b6388, Func Offset: 0x68
	// Line 3189, Address: 0x2b6390, Func Offset: 0x70
	// Line 3187, Address: 0x2b6394, Func Offset: 0x74
	// Line 3188, Address: 0x2b639c, Func Offset: 0x7c
	// Line 3189, Address: 0x2b63a4, Func Offset: 0x84
	// Line 3190, Address: 0x2b63a8, Func Offset: 0x88
	// Line 3188, Address: 0x2b63b0, Func Offset: 0x90
	// Line 3189, Address: 0x2b63b8, Func Offset: 0x98
	// Line 3190, Address: 0x2b63c8, Func Offset: 0xa8
	// Line 3191, Address: 0x2b63cc, Func Offset: 0xac
	// Line 3195, Address: 0x2b63d8, Func Offset: 0xb8
	// Line 3197, Address: 0x2b63e4, Func Offset: 0xc4
	// Line 3198, Address: 0x2b640c, Func Offset: 0xec
	// Line 3200, Address: 0x2b641c, Func Offset: 0xfc
	// Line 3201, Address: 0x2b6434, Func Offset: 0x114
	// Line 3202, Address: 0x2b6440, Func Offset: 0x120
	// Line 3203, Address: 0x2b6448, Func Offset: 0x128
	// Line 3205, Address: 0x2b644c, Func Offset: 0x12c
	// Line 3208, Address: 0x2b6454, Func Offset: 0x134
	// Line 3209, Address: 0x2b6460, Func Offset: 0x140
	// Line 3210, Address: 0x2b6468, Func Offset: 0x148
	// Line 3216, Address: 0x2b6478, Func Offset: 0x158
	// Line 3217, Address: 0x2b64a8, Func Offset: 0x188
	// Line 3228, Address: 0x2b64d8, Func Offset: 0x1b8
	// Line 3229, Address: 0x2b64fc, Func Offset: 0x1dc
	// Line 3228, Address: 0x2b6508, Func Offset: 0x1e8
	// Line 3229, Address: 0x2b6510, Func Offset: 0x1f0
	// Line 3230, Address: 0x2b652c, Func Offset: 0x20c
	// Line 3229, Address: 0x2b6538, Func Offset: 0x218
	// Line 3230, Address: 0x2b6540, Func Offset: 0x220
	// Line 3231, Address: 0x2b655c, Func Offset: 0x23c
	// Line 3230, Address: 0x2b6568, Func Offset: 0x248
	// Line 3231, Address: 0x2b6570, Func Offset: 0x250
	// Line 3232, Address: 0x2b658c, Func Offset: 0x26c
	// Line 3231, Address: 0x2b6598, Func Offset: 0x278
	// Line 3232, Address: 0x2b65a0, Func Offset: 0x280
	// Line 3233, Address: 0x2b65bc, Func Offset: 0x29c
	// Line 3232, Address: 0x2b65c8, Func Offset: 0x2a8
	// Line 3233, Address: 0x2b65d0, Func Offset: 0x2b0
	// Line 3234, Address: 0x2b65ec, Func Offset: 0x2cc
	// Line 3233, Address: 0x2b65f8, Func Offset: 0x2d8
	// Line 3234, Address: 0x2b6600, Func Offset: 0x2e0
	// Line 3235, Address: 0x2b661c, Func Offset: 0x2fc
	// Line 3234, Address: 0x2b6628, Func Offset: 0x308
	// Line 3235, Address: 0x2b6630, Func Offset: 0x310
	// Line 3239, Address: 0x2b664c, Func Offset: 0x32c
	// Line 3235, Address: 0x2b6650, Func Offset: 0x330
	// Line 3240, Address: 0x2b6658, Func Offset: 0x338
	// Func End, Address: 0x2b666c, Func Offset: 0x34c
	scePrintf("FsubZoomCursor - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b6670
static int FsubZoomInfomation(FI_WORK* fiP)
{
	NJS_POINT3 pos;
	NJS_POINT3 set_pos;
	// Line 3250, Address: 0x2b6670, Func Offset: 0
	// Line 3257, Address: 0x2b6680, Func Offset: 0x10
	// Line 3260, Address: 0x2b66a0, Func Offset: 0x30
	// Line 3265, Address: 0x2b66b4, Func Offset: 0x44
	// Line 3260, Address: 0x2b66b8, Func Offset: 0x48
	// Line 3265, Address: 0x2b66bc, Func Offset: 0x4c
	// Line 3260, Address: 0x2b66c0, Func Offset: 0x50
	// Line 3266, Address: 0x2b66c4, Func Offset: 0x54
	// Line 3260, Address: 0x2b66c8, Func Offset: 0x58
	// Line 3266, Address: 0x2b66cc, Func Offset: 0x5c
	// Line 3265, Address: 0x2b66d0, Func Offset: 0x60
	// Line 3266, Address: 0x2b66d4, Func Offset: 0x64
	// Line 3268, Address: 0x2b66d8, Func Offset: 0x68
	// Line 3269, Address: 0x2b66dc, Func Offset: 0x6c
	// Line 3273, Address: 0x2b66e8, Func Offset: 0x78
	// Line 3277, Address: 0x2b66f4, Func Offset: 0x84
	// Line 3279, Address: 0x2b6708, Func Offset: 0x98
	// Line 3280, Address: 0x2b6714, Func Offset: 0xa4
	// Line 3281, Address: 0x2b6718, Func Offset: 0xa8
	// Line 3279, Address: 0x2b671c, Func Offset: 0xac
	// Line 3283, Address: 0x2b6720, Func Offset: 0xb0
	// Line 3279, Address: 0x2b6728, Func Offset: 0xb8
	// Line 3280, Address: 0x2b672c, Func Offset: 0xbc
	// Line 3281, Address: 0x2b6730, Func Offset: 0xc0
	// Line 3280, Address: 0x2b6738, Func Offset: 0xc8
	// Line 3281, Address: 0x2b6740, Func Offset: 0xd0
	// Line 3283, Address: 0x2b6744, Func Offset: 0xd4
	// Line 3281, Address: 0x2b6748, Func Offset: 0xd8
	// Line 3283, Address: 0x2b674c, Func Offset: 0xdc
	// Line 3284, Address: 0x2b6768, Func Offset: 0xf8
	// Line 3285, Address: 0x2b6774, Func Offset: 0x104
	// Line 3284, Address: 0x2b677c, Func Offset: 0x10c
	// Line 3285, Address: 0x2b6780, Func Offset: 0x110
	// Line 3286, Address: 0x2b678c, Func Offset: 0x11c
	// Line 3289, Address: 0x2b6798, Func Offset: 0x128
	// Line 3286, Address: 0x2b67a0, Func Offset: 0x130
	// Line 3288, Address: 0x2b67a8, Func Offset: 0x138
	// Line 3289, Address: 0x2b67ac, Func Offset: 0x13c
	// Line 3288, Address: 0x2b67b0, Func Offset: 0x140
	// Line 3289, Address: 0x2b67b4, Func Offset: 0x144
	// Line 3290, Address: 0x2b67d0, Func Offset: 0x160
	// Line 3291, Address: 0x2b67dc, Func Offset: 0x16c
	// Line 3290, Address: 0x2b67e4, Func Offset: 0x174
	// Line 3291, Address: 0x2b67e8, Func Offset: 0x178
	// Line 3292, Address: 0x2b67f4, Func Offset: 0x184
	// Line 3295, Address: 0x2b6800, Func Offset: 0x190
	// Line 3292, Address: 0x2b6808, Func Offset: 0x198
	// Line 3294, Address: 0x2b6810, Func Offset: 0x1a0
	// Line 3295, Address: 0x2b6814, Func Offset: 0x1a4
	// Line 3294, Address: 0x2b6818, Func Offset: 0x1a8
	// Line 3295, Address: 0x2b681c, Func Offset: 0x1ac
	// Line 3296, Address: 0x2b6838, Func Offset: 0x1c8
	// Line 3299, Address: 0x2b6844, Func Offset: 0x1d4
	// Line 3296, Address: 0x2b684c, Func Offset: 0x1dc
	// Line 3299, Address: 0x2b6850, Func Offset: 0x1e0
	// Line 3300, Address: 0x2b685c, Func Offset: 0x1ec
	// Line 3302, Address: 0x2b6868, Func Offset: 0x1f8
	// Line 3300, Address: 0x2b6870, Func Offset: 0x200
	// Line 3302, Address: 0x2b6874, Func Offset: 0x204
	// Line 3304, Address: 0x2b6880, Func Offset: 0x210
	// Line 3306, Address: 0x2b6890, Func Offset: 0x220
	// Line 3307, Address: 0x2b68a8, Func Offset: 0x238
	// Line 3313, Address: 0x2b68b0, Func Offset: 0x240
	// Line 3312, Address: 0x2b68bc, Func Offset: 0x24c
	// Line 3313, Address: 0x2b68c0, Func Offset: 0x250
	// Func End, Address: 0x2b68c8, Func Offset: 0x258
	scePrintf("FsubZoomInfomation - UNIMPLEMENTED!\n");
}

// 100% matching!
static NJS_COLOR MapCnvArgb2Color(NJS_ARGB* argbP)
{
    NJS_COLOR col;
    
    col.argb.a = 255.0f * argbP->a;
    col.argb.r = 255.0f * argbP->r;
    col.argb.g = 255.0f * argbP->g;
    col.argb.b = 255.0f * argbP->b;

    return col;
}

// 
// Start address: 0x2b6970
static int FsubZoomScreen(FS_WRK* fsP)
{
	int tmp;
	int ang;
	NJS_POINT2 pnt[4];
	NJS_POINT2 ScrOut[2];
	NJS_POINT2 ScrIn[2];
	// Line 3343, Address: 0x2b6970, Func Offset: 0
	// Line 3353, Address: 0x2b6984, Func Offset: 0x14
	// Line 3356, Address: 0x2b69a4, Func Offset: 0x34
	// Line 3358, Address: 0x2b69b4, Func Offset: 0x44
	// Line 3357, Address: 0x2b69b8, Func Offset: 0x48
	// Line 3356, Address: 0x2b69c0, Func Offset: 0x50
	// Line 3357, Address: 0x2b69c8, Func Offset: 0x58
	// Line 3359, Address: 0x2b69d0, Func Offset: 0x60
	// Line 3357, Address: 0x2b69d4, Func Offset: 0x64
	// Line 3358, Address: 0x2b69dc, Func Offset: 0x6c
	// Line 3359, Address: 0x2b69e0, Func Offset: 0x70
	// Line 3360, Address: 0x2b69e4, Func Offset: 0x74
	// Line 3364, Address: 0x2b69f0, Func Offset: 0x80
	// Line 3365, Address: 0x2b6a00, Func Offset: 0x90
	// Line 3364, Address: 0x2b6a04, Func Offset: 0x94
	// Line 3365, Address: 0x2b6a18, Func Offset: 0xa8
	// Line 3364, Address: 0x2b6a20, Func Offset: 0xb0
	// Line 3365, Address: 0x2b6a28, Func Offset: 0xb8
	// Line 3366, Address: 0x2b6a30, Func Offset: 0xc0
	// Line 3365, Address: 0x2b6a40, Func Offset: 0xd0
	// Line 3367, Address: 0x2b6a50, Func Offset: 0xe0
	// Line 3365, Address: 0x2b6a60, Func Offset: 0xf0
	// Line 3368, Address: 0x2b6a64, Func Offset: 0xf4
	// Line 3365, Address: 0x2b6a6c, Func Offset: 0xfc
	// Line 3366, Address: 0x2b6a70, Func Offset: 0x100
	// Line 3368, Address: 0x2b6a78, Func Offset: 0x108
	// Line 3366, Address: 0x2b6a7c, Func Offset: 0x10c
	// Line 3368, Address: 0x2b6a80, Func Offset: 0x110
	// Line 3366, Address: 0x2b6a88, Func Offset: 0x118
	// Line 3367, Address: 0x2b6a98, Func Offset: 0x128
	// Line 3368, Address: 0x2b6ab0, Func Offset: 0x140
	// Line 3369, Address: 0x2b6ab8, Func Offset: 0x148
	// Line 3373, Address: 0x2b6ad8, Func Offset: 0x168
	// Line 3376, Address: 0x2b6adc, Func Offset: 0x16c
	// Line 3377, Address: 0x2b6af0, Func Offset: 0x180
	// Line 3376, Address: 0x2b6af4, Func Offset: 0x184
	// Line 3377, Address: 0x2b6b04, Func Offset: 0x194
	// Line 3378, Address: 0x2b6b2c, Func Offset: 0x1bc
	// Line 3379, Address: 0x2b6b34, Func Offset: 0x1c4
	// Line 3380, Address: 0x2b6b48, Func Offset: 0x1d8
	// Line 3379, Address: 0x2b6b4c, Func Offset: 0x1dc
	// Line 3380, Address: 0x2b6b5c, Func Offset: 0x1ec
	// Line 3381, Address: 0x2b6b68, Func Offset: 0x1f8
	// Line 3380, Address: 0x2b6b70, Func Offset: 0x200
	// Line 3381, Address: 0x2b6b74, Func Offset: 0x204
	// Line 3380, Address: 0x2b6b7c, Func Offset: 0x20c
	// Line 3381, Address: 0x2b6b80, Func Offset: 0x210
	// Line 3380, Address: 0x2b6b8c, Func Offset: 0x21c
	// Line 3381, Address: 0x2b6b94, Func Offset: 0x224
	// Line 3380, Address: 0x2b6b98, Func Offset: 0x228
	// Line 3381, Address: 0x2b6ba0, Func Offset: 0x230
	// Line 3383, Address: 0x2b6ba8, Func Offset: 0x238
	// Line 3384, Address: 0x2b6bb8, Func Offset: 0x248
	// Line 3385, Address: 0x2b6be8, Func Offset: 0x278
	// Line 3387, Address: 0x2b6c00, Func Offset: 0x290
	// Line 3391, Address: 0x2b6c18, Func Offset: 0x2a8
	// Line 3393, Address: 0x2b6c2c, Func Offset: 0x2bc
	// Line 3396, Address: 0x2b6c4c, Func Offset: 0x2dc
	// Line 3399, Address: 0x2b6c54, Func Offset: 0x2e4
	// Line 3395, Address: 0x2b6c5c, Func Offset: 0x2ec
	// Line 3399, Address: 0x2b6c64, Func Offset: 0x2f4
	// Line 3397, Address: 0x2b6c68, Func Offset: 0x2f8
	// Line 3399, Address: 0x2b6c70, Func Offset: 0x300
	// Line 3395, Address: 0x2b6c74, Func Offset: 0x304
	// Line 3399, Address: 0x2b6c78, Func Offset: 0x308
	// Line 3398, Address: 0x2b6c7c, Func Offset: 0x30c
	// Line 3395, Address: 0x2b6c84, Func Offset: 0x314
	// Line 3396, Address: 0x2b6c94, Func Offset: 0x324
	// Line 3397, Address: 0x2b6ca4, Func Offset: 0x334
	// Line 3398, Address: 0x2b6cb4, Func Offset: 0x344
	// Line 3399, Address: 0x2b6cc0, Func Offset: 0x350
	// Line 3404, Address: 0x2b6cc8, Func Offset: 0x358
	// Line 3401, Address: 0x2b6cd0, Func Offset: 0x360
	// Line 3405, Address: 0x2b6cd4, Func Offset: 0x364
	// Line 3401, Address: 0x2b6ce4, Func Offset: 0x374
	// Line 3402, Address: 0x2b6cf4, Func Offset: 0x384
	// Line 3405, Address: 0x2b6cfc, Func Offset: 0x38c
	// Line 3402, Address: 0x2b6d00, Func Offset: 0x390
	// Line 3403, Address: 0x2b6d0c, Func Offset: 0x39c
	// Line 3404, Address: 0x2b6d20, Func Offset: 0x3b0
	// Line 3405, Address: 0x2b6d2c, Func Offset: 0x3bc
	// Line 3406, Address: 0x2b6d34, Func Offset: 0x3c4
	// Line 3408, Address: 0x2b6d58, Func Offset: 0x3e8
	// Line 3412, Address: 0x2b6d60, Func Offset: 0x3f0
	// Line 3411, Address: 0x2b6d74, Func Offset: 0x404
	// Line 3408, Address: 0x2b6d7c, Func Offset: 0x40c
	// Line 3409, Address: 0x2b6d8c, Func Offset: 0x41c
	// Line 3410, Address: 0x2b6da0, Func Offset: 0x430
	// Line 3411, Address: 0x2b6db4, Func Offset: 0x444
	// Line 3412, Address: 0x2b6dc0, Func Offset: 0x450
	// Line 3414, Address: 0x2b6dc8, Func Offset: 0x458
	// Line 3413, Address: 0x2b6dd0, Func Offset: 0x460
	// Line 3414, Address: 0x2b6dd4, Func Offset: 0x464
	// Line 3413, Address: 0x2b6de4, Func Offset: 0x474
	// Line 3414, Address: 0x2b6de8, Func Offset: 0x478
	// Line 3413, Address: 0x2b6dec, Func Offset: 0x47c
	// Line 3414, Address: 0x2b6df0, Func Offset: 0x480
	// Line 3417, Address: 0x2b6df8, Func Offset: 0x488
	// Line 3420, Address: 0x2b6e00, Func Offset: 0x490
	// Line 3419, Address: 0x2b6e08, Func Offset: 0x498
	// Line 3420, Address: 0x2b6e0c, Func Offset: 0x49c
	// Line 3417, Address: 0x2b6e14, Func Offset: 0x4a4
	// Line 3418, Address: 0x2b6e1c, Func Offset: 0x4ac
	// Line 3420, Address: 0x2b6e24, Func Offset: 0x4b4
	// Line 3418, Address: 0x2b6e30, Func Offset: 0x4c0
	// Line 3419, Address: 0x2b6e34, Func Offset: 0x4c4
	// Line 3420, Address: 0x2b6e40, Func Offset: 0x4d0
	// Line 3422, Address: 0x2b6e4c, Func Offset: 0x4dc
	// Line 3423, Address: 0x2b6e50, Func Offset: 0x4e0
	// Line 3422, Address: 0x2b6e54, Func Offset: 0x4e4
	// Line 3423, Address: 0x2b6e58, Func Offset: 0x4e8
	// Line 3421, Address: 0x2b6e5c, Func Offset: 0x4ec
	// Line 3423, Address: 0x2b6e60, Func Offset: 0x4f0
	// Line 3421, Address: 0x2b6e6c, Func Offset: 0x4fc
	// Line 3423, Address: 0x2b6e70, Func Offset: 0x500
	// Line 3421, Address: 0x2b6e74, Func Offset: 0x504
	// Line 3422, Address: 0x2b6e78, Func Offset: 0x508
	// Line 3423, Address: 0x2b6e7c, Func Offset: 0x50c
	// Line 3422, Address: 0x2b6e80, Func Offset: 0x510
	// Line 3423, Address: 0x2b6e84, Func Offset: 0x514
	// Line 3425, Address: 0x2b6e8c, Func Offset: 0x51c
	// Line 3426, Address: 0x2b6ea0, Func Offset: 0x530
	// Line 3428, Address: 0x2b6ea8, Func Offset: 0x538
	// Line 3426, Address: 0x2b6eb8, Func Offset: 0x548
	// Line 3428, Address: 0x2b6ec0, Func Offset: 0x550
	// Line 3427, Address: 0x2b6ec8, Func Offset: 0x558
	// Line 3428, Address: 0x2b6ecc, Func Offset: 0x55c
	// Line 3427, Address: 0x2b6ed0, Func Offset: 0x560
	// Line 3428, Address: 0x2b6ed4, Func Offset: 0x564
	// Line 3430, Address: 0x2b6ee0, Func Offset: 0x570
	// Line 3431, Address: 0x2b6ee4, Func Offset: 0x574
	// Line 3430, Address: 0x2b6ee8, Func Offset: 0x578
	// Line 3431, Address: 0x2b6eec, Func Offset: 0x57c
	// Line 3429, Address: 0x2b6ef0, Func Offset: 0x580
	// Line 3431, Address: 0x2b6ef4, Func Offset: 0x584
	// Line 3429, Address: 0x2b6f00, Func Offset: 0x590
	// Line 3431, Address: 0x2b6f04, Func Offset: 0x594
	// Line 3429, Address: 0x2b6f08, Func Offset: 0x598
	// Line 3430, Address: 0x2b6f0c, Func Offset: 0x59c
	// Line 3431, Address: 0x2b6f10, Func Offset: 0x5a0
	// Line 3430, Address: 0x2b6f14, Func Offset: 0x5a4
	// Line 3431, Address: 0x2b6f18, Func Offset: 0x5a8
	// Line 3437, Address: 0x2b6f20, Func Offset: 0x5b0
	// Line 3436, Address: 0x2b6f30, Func Offset: 0x5c0
	// Line 3437, Address: 0x2b6f34, Func Offset: 0x5c4
	// Func End, Address: 0x2b6f3c, Func Offset: 0x5cc
	scePrintf("FsubZoomScreen - UNIMPLEMENTED!\n");
}

// 100% matching!
static int FsubCompass(FC_WORK* fcP)
{
    static const NJS_POLYGON_VTX CmpArw[4] = 
    {
        {   0.0f, -30.0f, 0.0f, 0x6000C000 }, { -12.0f, -22.0f, 0.0f, 0x6000C000 },
        {  12.0f, -22.0f, 0.0f, 0x6000C000 }, {   0.0f,  30.0f, 0.0f, 0x6000C000 }
    }; 
    
    switch (fcP->mode) 
    {               
    case 0:
        fcP->pos.x = 585.0f;
        fcP->pos.y = 62.0f;
        fcP->pos.z = -4.0f;
        
        fcP->scl_y = fabsf(-4.0f) / _nj_screen_.dist;
        fcP->scl_x = fcP->scl_y / 1.174f;
        
        fcP->pos.x = (fcP->pos.x - 320.0f) * fcP->scl_x;
        fcP->pos.y = (240.0f - fcP->pos.y) * fcP->scl_y;
        
        fcP->ang = 0;
        
        fcP->mode++;
    case 1:
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateX(NULL, 32768);
        
        njTranslateEx(&fcP->pos);
        
        njScale(NULL, fcP->scl_y, fcP->scl_y, fcP->scl_y);
        
        njRotateY(NULL, fcP->ang += 1456); // the second parameter here is written in an unusual form
        
        njDrawPolygon3DEx(CmpArw, 4, 1);
        
        njPopMatrixEx();
        break;
    }
    
    return 1;
}

// 100% matching!
static int FsubModeMessage(FM_WORK* fmP)
{
    int typ;
    MD_WORK* mdP;
	static const MD_WORK NmlMes[2] = 
    {
        { { 464.0f, 441.0f, -7.0f }, 5 },
        { { 480.0f, 441.0f, -7.0f }, 9 }
    };
    
    typ = sys->keytype;
    
    if (typ > 2)
    {
        typ = 0;
    }
    
    switch (fmP->mode) 
    {
    case 0:
        fmP->mdP = NmlMes;
        mdP      = fmP->mdP;
        
        if (mdP != NULL)
        {
            MapDrawSprite(&mdP[0].pos, -1, mdP[0].spr + typ);
            MapDrawSprite(&mdP[1].pos, -1, mdP[1].spr);
        }
        
        break;
    }
    
    return 1;
}

// 100% matching!
static void MapCncInit(int map_num, int flr_num)
{
    int map_no, flr_no;
	cnc_wrk_typ* cwP;
	
    mwP->cnc_map = map_num;
    mwP->cnc_flr = flr_num;
    
    map_num *= flr_num;
    
    mwP->cnc_wrkP = (cnc_wrk_typ*)bhGetFreeMemory(map_num * 28, 4);
    
    for (map_no = 0; map_no < map_num; map_no++)
    {
        for (flr_no = 0; flr_no < flr_num; flr_no++) 
        {
            cwP = MapCncGet(map_no, flr_no);
            
            cwP->map_no = map_no;
            cwP->flr_no = flr_no;
            
            cwP->status = 0;
        } 
    } 
}

// 100% matching!
static cnc_wrk_typ* MapCncGet(int map_no, int flr_no)
{
    map_no *= mwP->cnc_flr;
    map_no += flr_no;
    
    return &mwP->cnc_wrkP[map_no];
}

// 68.79% matching
static void MapCnc(mp_no dst, mp_no src, int status)
{
	// modified order of local variables in regards to DWARF
    cnc_wrk_typ* srcP, *dstP; 
    int dst_map;       
	int src_flr, src_map;     
	int dst_flr;     
	static const int AdjMapA[3] = { 64, 128, 832 };
    
    dst_flr = dst / 16;
    dst_map = dst & 0xF;

    src_flr = src / 16;
    src_map = src & 0xF;
    
    dstP = MapCncGet(dst_flr, dst_map);
    srcP = MapCncGet(src_flr, src_map);
    
    dst_flr *= 256;
    src_flr *= 256;
    
    if (src_flr == 2560) 
	{
        src_flr = AdjMapA[src_map];
    }

    if (dst_flr == 2560) 
	{
        dst_flr = AdjMapA[dst_map];
    }

    if (src_flr == 512) 
	{
        src_flr = 896;
    }

    if (dst_flr == 512) 
	{
        dst_flr = 896;
    }

    if (dst_flr == src_flr) 
	{
        if (dst_map < src_map) 
		{
            srcP->flr_prevP = dstP;
        } 
		else if (dst_map > src_map) 
		{
            srcP->flr_nextP = dstP;
        }
    } 
	else if (dst_flr < src_flr) 
	{
        srcP->map_prevP = dstP;
    }
	else 
	{
        srcP->map_nextP = dstP;
    }

    dstP->status = status;
}

// 81.59% matching (matches on NGC)
static void MapCncConnect(const unsigned short* datP) 
{
    int sts;          
    int dat_u;  
    int dat_l;        
    unsigned short dat; 

    sts = 0;

    while (TRUE)
    {
        dat = *datP++;
        
        dat_l = dat >> 8;
        dat_u = (unsigned char)dat;
        
        if (dat_l == 255) 
        {
            if (dat_u == 255)
            { 
                break;
            }

            if (bhFlagCk(8, dat_u, 0) != 0)
            {
                sts = 1;
            } 
            else
            {
                sts = 0;
            }
        } 
        else 
        {
            MapCnc(dat_l, dat_u, sts);
        }
    }
}

// 92.80% matching (matches on NGC)
static map_nxt* MapCheckNextMap(map_nxt* mnP)
{
    cnc_wrk_typ* curP, *cwP;

    curP = MapCncGet(mwP->stg_no, mwP->flr_no);
    
    for (cwP = curP->flr_nextP; cwP != NULL; cwP = cwP->flr_nextP)
    {
        if (cwP->status != 0)
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_up = -1;
    }
    else 
    {
        mnP->map_up = cwP->map_no;
        mnP->flr_up = cwP->flr_no;
    }

    for (cwP = curP->flr_prevP; cwP != NULL; cwP = cwP->flr_prevP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_down = -1;
    } 
    else 
    {
        mnP->map_down = cwP->map_no;
        mnP->flr_down = cwP->flr_no;
    }

    for (cwP = curP->map_prevP; cwP != NULL; cwP = cwP->map_prevP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL) 
    {
        mnP->map_left = -1;
    } 
    else
    {
        mnP->map_left = cwP->map_no;
        mnP->flr_left = cwP->flr_no;
    }
    
    for (cwP = curP->map_nextP; cwP != NULL; cwP = cwP->map_nextP)
    {
        if (cwP->status != 0) 
        {
            break;
        }
    }
    
    if (cwP == NULL)
    {
        mnP->map_right = -1;
    } 
    else 
    {
        mnP->map_right = cwP->map_no;
        mnP->flr_right = cwP->flr_no;
    }

    return mnP;
}

// 100% matching!
static int GetGameMode()
{
    if (sys->stg_no >= 7) 
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
