#ifndef _EN19_H_
#define _EN19_H_

#include "types.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef enum TY_OBJ_MODE
{
    TY_OBJ_NULL   = 0,
    TY_OBJ_WAIST  = 1,
    TY_OBJ_BODY   = 2,
    TY_OBJ_BODYU  = 3,
    TY_OBJ_NECK   = 4,
    TY_OBJ_HEAD   = 5,
    TY_OBJ_BODYR  = 6,
    TY_OBJ_ARM_R0 = 7,
    TY_OBJ_ARM_R1 = 8,
    TY_OBJ_ARM_R2 = 9,
    TY_OBJ_CLAW0  = 10,
    TY_OBJ_CLAW1  = 11,
    TY_OBJ_CLAW2  = 12,
    TY_OBJ_ELBOW  = 13,
    TY_OBJ_BODYL  = 14,
    TY_OBJ_ARM_L0 = 15,
    TY_OBJ_ARM_L1 = 16,
    TY_OBJ_ARM_L2 = 17,
    TY_OBJ_LEG_R0 = 18,
    TY_OBJ_LEG_R1 = 19,
    TY_OBJ_LEG_R2 = 20,
    TY_OBJ_LEG_R3 = 21,
    TY_OBJ_LEG_L0 = 22,
    TY_OBJ_LEG_L1 = 23,
    TY_OBJ_LEG_L2 = 24,
    TY_OBJ_LEG_L3 = 25,
    TY_OBJ_NUM    = 26
} TY_OBJ_MODE;

typedef enum TY_DMG_MODE 
{
    TY_DMG_NON     = 0,
    TY_DMG_LVL0    = 1,
    TY_DMG_LVL1    = 2,
    TY_DMG_LVL2    = 3,
    TY_DMG_LVL3    = 4,
    TY_DMG_LVL4    = 5,
    TY_DMG_SPECIAL = 6
} TY_DMG_MODE;

typedef enum TY_ARM_NO
{
    TY_ARM_LEFT  = 0,
    TY_ARM_RIGHT = 1
} TY_ARM_NO;

typedef enum TY_BR_MODE0 
{
    TY_BR0_NORMAL = 0,
    TY_BR0_DOWN   = 1,
    TY_BR0_LAY    = 2,
    TY_BR0_DIE    = 3,
    TY_BR0_PINCH  = 4
} TY_BR_MODE0; 

typedef enum TY_BR_MODE1
{
    TY_BR1_NORMAL      = 0,
    TY_BR1_WALK        = 1,
    TY_BR1_ROTATE      = 2,
    TY_BR1_ATTACK      = 3,
    TY_BR1_DASH_ATTACK = 4,
    TY_BR1_WAIT        = 5,
    TY_BR1_DAMAGE      = 6,
    TY_BR1_CHANGE      = 7
} TY_BR_MODE1; 

typedef enum TY_BR_MODE2 
{
    TY_BR2_FIRST = 0,
    TY_BR2_LOOP0 = 1,
    TY_BR2_LOOP1 = 2,
    TY_BR2_LOOP2 = 3
} TY_BR_MODE2; 

typedef struct _en19_freework 
{
    // total size: 0x0
    int pad; // this isn't an actual field, but it gets rid of a compiling error about an empty struct
} en19_freework;

typedef enum TY_PRG_MODE0 
{
    TY_PRG_INIT    = 0,
    TY_PRG_MOVE    = 1,
    TY_PRG_DAMAGE  = 2,
    TY_PRG_DIE     = 3,
    TY_PRG_UNKKOWN = 4,
    TY_PRG_EVENT   = 5
} TY_PRG_MODE0;

typedef struct ACT_TBL_WORK
{
    // total size: 0x10
    short mtn_no;          // offset 0x0, size 0x2
    short frm_no;          // offset 0x2, size 0x2
    unsigned char hkn_lvl; // offset 0x4, size 0x1
    unsigned char hkn_cnt; // offset 0x5, size 0x1
    unsigned char chg_frm; // offset 0x6, size 0x1
    char act_jmp;          // offset 0x7, size 0x1
    int flag;              // offset 0x8, size 0x4
    void* prgP;            // offset 0xC, size 0x4
} ACT_TBL_WORK;

typedef struct PAW_WORK 
{
    // total size: 0x38
    int p_status;                     // offset 0x0, size 0x4
    int p_mode;                       // offset 0x4, size 0x4
    int p_act_flg;                    // offset 0x8, size 0x4
    void (*p_prgP)(BH_PWORK*, void*); // offset 0xC, size 0x4
    void* p_paramP;                   // offset 0x10, size 0x4
    int p_act_frm;                    // offset 0x14, size 0x4
    int p_chg_frm;                    // offset 0x18, size 0x4
    int p_mtn_rte;                    // offset 0x1C, size 0x4
    int p_act_jmp;                    // offset 0x20, size 0x4
    int p_frm_num;                    // offset 0x24, size 0x4
    int p_act_now;                    // offset 0x28, size 0x4
    MN_WORK* ene_mnwP;                // offset 0x2C, size 0x4
    ACT_TBL_WORK* act_tblP;           // offset 0x30, size 0x4
    int tbl_num;                      // offset 0x34, size 0x4
} PAW_WORK;

typedef struct FW_WORK 
{
    // total size: 0x204
    NJS_MATRIX mtx_bak;                             // offset 0x0, size 0x40
    int status;                                     // offset 0x40, size 0x4
    int act_flg;                                    // offset 0x44, size 0x4
    void (*prgP)(BH_PWORK*, en19_freework*, int);   // offset 0x48, size 0x4
    int act_frm;                                    // offset 0x4C, size 0x4
    int act_now;                                    // offset 0x50, size 0x4
    int mtn_rte;                                    // offset 0x54, size 0x4
    int chg_rte;                                    // offset 0x58, size 0x4
    int act_cnt;                                    // offset 0x5C, size 0x4
    int b_status;                                   // offset 0x60, size 0x4
    int b_act_flg;                                  // offset 0x64, size 0x4
    void (*b_prgP)(BH_PWORK*, en19_freework*, int); // offset 0x68, size 0x4
    int b_act_frm;                                  // offset 0x6C, size 0x4
    int b_act_now;                                  // offset 0x70, size 0x4
    int b_mtn_rte;                                  // offset 0x74, size 0x4
    int b_chg_rte;                                  // offset 0x78, size 0x4
    int b_act_cnt;                                  // offset 0x7C, size 0x4
    int b_mtn_md;                                   // offset 0x80, size 0x4
    int dummy;                                      // offset 0x84, size 0x4
    PAW_WORK ply_act;                               // offset 0x88, size 0x38
    BH_PWORK* ewP;                                  // offset 0xC0, size 0x4
    TY_BR_MODE0 br_mde0;                            // offset 0xC4, size 0x4
    TY_BR_MODE1 br_mde1;                            // offset 0xC8, size 0x4
    TY_BR_MODE2 br_mde2;                            // offset 0xCC, size 0x4
    int br_wait1;                                   // offset 0xD0, size 0x4
    int ct_dash;                                    // offset 0xD4, size 0x4
    int ct_pinch;                                   // offset 0xD8, size 0x4
    NJS_POINT3 ClwPos[4];                           // offset 0xDC, size 0x30
    NJS_POINT3 fix_adj;                             // offset 0x10C, size 0xC
    NJS_POINT3 adj_vx;                              // offset 0x118, size 0xC
    NJS_POINT3 adj_vz;                              // offset 0x124, size 0xC
    NJS_POINT3 tgt_pos;                             // offset 0x130, size 0xC
    float ply_dst;                                  // offset 0x13C, size 0x4
    float tgt_dst;                                  // offset 0x140, size 0x4
    int tgt_ang;                                    // offset 0x144, size 0x4
    int trn_spd;                                    // offset 0x148, size 0x4
    int dir_dlt;                                    // offset 0x14C, size 0x4
    int trw_dir;                                    // offset 0x150, size 0x4
    float trw_spd;                                  // offset 0x154, size 0x4
    int ply_mde;                                    // offset 0x158, size 0x4
    NJS_POINT3 wnd_spd;                             // offset 0x15C, size 0xC
    int dmg_obj;                                    // offset 0x168, size 0x4
    int dmg_cnt;                                    // offset 0x16C, size 0x4
    int dwn_cnt;                                    // offset 0x170, size 0x4
    int bnd_tim;                                    // offset 0x174, size 0x4
    int hp_bak;                                     // offset 0x178, size 0x4
    int watr_top;                                   // offset 0x17C, size 0x4
    float watr_rad;                                 // offset 0x180, size 0x4
    int snd_no;                                     // offset 0x184, size 0x4
    float ovl_rte;                                  // offset 0x188, size 0x4
    float atk_rng_a_near;                           // offset 0x18C, size 0x4
    float atk_rng_b_near;                           // offset 0x190, size 0x4
    float atk_rng_a_far;                            // offset 0x194, size 0x4
    float atk_rng_b_far;                            // offset 0x198, size 0x4
    int dmg_flg;                                    // offset 0x19C, size 0x4
    TY_DMG_MODE dmg_lvl;                            // offset 0x1A0, size 0x4
    int cmb_lvl;                                    // offset 0x1A4, size 0x4
    int dmg_dly;                                    // offset 0x1A8, size 0x4
    float pos_tmp[3];                               // offset 0x1AC, size 0xC
    int ang_tmp[3];                                 // offset 0x1B8, size 0xC
    NJS_VECTOR vct_tmp;                             // offset 0x1C4, size 0xC
    int cnt_tmp;                                    // offset 0x1D0, size 0x4
    PMA_WORK* e0aP;                                 // offset 0x1D4, size 0x4
    int eff_tim;                                    // offset 0x1D8, size 0x4
    R0_WK* clw0P;                                   // offset 0x1DC, size 0x4
    R0_WK* clw2P;                                   // offset 0x1E0, size 0x4
    TY_PRG_MODE0 mode0_bak;                         // offset 0x1E4, size 0x4
    R0A_WORK* cam_clrP;                             // offset 0x1E8, size 0x4
    TY_BR_MODE0 br_mde0_bak;                        // offset 0x1EC, size 0x4
    TY_BR_MODE1 br_mde1_bak;                        // offset 0x1F0, size 0x4
    TY_BR_MODE2 br_mde2_bak;                        // offset 0x1F4, size 0x4
    int comb_flg;                                   // offset 0x1F8, size 0x4
    unsigned int Dummy[2];                          // offset 0x1FC, size 0x8
} FW_WORK;

typedef struct EA_WORK 
{
    // total size: 0x14
    int label;             // offset 0x0, size 0x4
    unsigned char mtn_no;  // offset 0x4, size 0x1
    unsigned char frm_no;  // offset 0x5, size 0x1
    unsigned char hkn_lvl; // offset 0x6, size 0x1
    unsigned char hkn_cnt; // offset 0x7, size 0x1
    float chg_rte;         // offset 0x8, size 0x4
    int flag;              // offset 0xC, size 0x4
    void* prgP;            // offset 0x10, size 0x4
} EA_WORK;

typedef struct EB_WORK 
{
    // total size: 0xC
    BH_PWORK* ewP; // offset 0x0, size 0x4
    FW_WORK* fwP;  // offset 0x4, size 0x4
    int time;      // offset 0x8, size 0x4
} EB_WORK;

typedef struct PF_WORK
{
    // total size: 0x24
    NJS_VECTOR vct_spd; // offset 0x0, size 0xC
    NJS_VECTOR vct_acl; // offset 0xC, size 0xC
    float acl_rte;      // offset 0x18, size 0x4
    float die_dst;      // offset 0x1C, size 0x4
    int mode;           // offset 0x20, size 0x4
} PF_WORK;

typedef struct EO_WORK
{
    // total size: 0x10
    float off_x; // offset 0x0, size 0x4
    float off_y; // offset 0x4, size 0x4
    float rnd_x; // offset 0x8, size 0x4
    float rnd_y; // offset 0xC, size 0x4
} EO_WORK;

typedef struct DD_WORK
{
    // total size: 0x1C
    int eff_nml[3]; // offset 0x0, size 0xC
    int eff_cmb[3]; // offset 0xC, size 0xC
    int dmg_cdn;    // offset 0x18, size 0x4
} DD_WORK;

void bhEne19(BH_PWORK* ewP);
static void bhEne19_Init(BH_PWORK* ewP);
static void bhEne19_Move(BH_PWORK* ewP);
static void bhEne19_Damage();
static void bhEne19_Die(BH_PWORK* ewP);
static void bhEne19_Event(BH_PWORK* ewP);
static void bhEne19_Br00(BH_PWORK* ewP);
static void bhEne19_Br01(BH_PWORK* ewP);
static void bhEne19_Br02(BH_PWORK* ewP);
static void bhEne19_Mv00(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv01(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv02(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv03(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv04a(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv04b(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv05(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv06(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv07(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv08(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv09(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv10(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv11(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv12(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv13(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv14(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv15(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv16(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv17(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv18(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv19(BH_PWORK* ewP, FW_WORK* fwP, int count);
static void bhEne19_Mv20(BH_PWORK* ewP, FW_WORK* fwP, int count);
static EA_WORK* bhEne19_ActionSearch(int act_nw, int act_no);
static int bhEne19_ActionChange(BH_PWORK* ewP, FW_WORK* fwP, int act_dst);
static int bhEne19_ActionMain(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_TargetAnalyze(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_PositonFix(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_HeadTurn(BH_PWORK* ewP, FW_WORK* fwP, int mode);
static int bhEne19_AttackHitCheck(BH_PWORK* ewP, TY_ARM_NO arm_no, float ar, int* angP);
static void bhEne19_CalcEnemy(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_DmgCheck(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, NJS_POINT3* dirP);
static int bhEne19_CollisionCircle2Oval(NJS_MATRIX* basP, float ra, float rb, NJS_POINT3* posP, float rc);
static void bhEne19_TyBloodSet(EB_WORK* ebP);
static void bhEne19_ClawReset(BH_PWORK* ewP, FW_WORK* fwP);
static void bhEne19_SoundSet(BH_PWORK* ewP, FW_WORK* fwP);
static int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP);
static int bhEne19_PlySetDamage(BH_PWORK* plP, FW_WORK* fwP, int dmg_mod);
static void bhEne19_PlyMoveMain(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg042(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg043(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg044(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg045(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg046_047(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg050_051(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg052_053(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmg117_118(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmgDie(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmgRtn(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne19_PlyDmgFal(BH_PWORK* plP, FW_WORK* fwP);
static void bhEne_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num);
static void bhEne_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP);
static int bhEne_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no);
static int bhEne_CalcCombRate(BH_PWORK* ewP, COMBWEP_WORK* cwP);
static TY_DMG_MODE bhEne19_CheckDmgLvl0(BH_PWORK* ewP, FW_WORK* fwP);
static TY_DMG_MODE bhEne19_CheckDmgLvl1(BH_PWORK* ewP, FW_WORK* fwP);
static TY_DMG_MODE bhEne19_CheckDmgLvl2(BH_PWORK* ewP, FW_WORK* fwP);
static R0_WK* bhEne19_SetLeftClaw(ML_WORK* mlwP, TY_OBJ_MODE tgt_bas, TY_OBJ_MODE tgt_obj);
static void bhEne19_SetClawPlane(BH_PWORK* ewP, NJS_MATRIX* mtxP, int col, int tim, float src_x, float dst_x);

#endif
