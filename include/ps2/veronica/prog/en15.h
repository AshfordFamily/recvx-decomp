#ifndef _EN15_H_
#define _EN15_H_

#include "types.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "macros.h"

typedef union _ATTACK_COL 
{
    NJS_CAPSULE cap; // offset 0x0, size 0x1C
    NJS_BOX box;     // offset 0x0, size 0x60
} ATTACK_COL; 

typedef struct _ATTACK_COL_TBL 
{
    // total size: 0x24
    int* obj_no;      // offset 0x0, size 0x4
    int start_frm;    // offset 0x4, size 0x4
    int end_frm;      // offset 0x8, size 0x4
    int damage;       // offset 0xC, size 0x4
    int impact_ang;   // offset 0x10, size 0x4
    float spd;        // offset 0x14, size 0x4
    float volume;     // offset 0x18, size 0x4
    int sp_start_frm; // offset 0x1C, size 0x4
    int sp_end_frm;   // offset 0x20, size 0x4
} ATTACK_COL_TBL;

typedef struct _MTN_RELAY 
{
    // total size: 0x8
    short old_mtn_no;  // offset 0x0, size 0x2
    short next_mtn_no; // offset 0x2, size 0x2
    short from;        // offset 0x4, size 0x2
    short to;          // offset 0x6, size 0x2
} MTN_RELAY;

typedef struct _UVINFO 
{
    // total size: 0xC
    short u;     // offset 0x0, size 0x2
    short v;     // offset 0x2, size 0x2
    short sx;    // offset 0x4, size 0x2
    short sy;    // offset 0x6, size 0x2
    short frm;   // offset 0x8, size 0x2
    short scale; // offset 0xA, size 0x2
} UVINFO;

typedef struct MTN_SE_TBL 
{
    // total size: 0xC
    unsigned int mtn_no; // offset 0x0, size 0x4
    unsigned int frm;    // offset 0x4, size 0x4
    int seno;            // offset 0x8, size 0x4
} MTN_SE_TBL;

typedef struct _WPNDG_TBL 
{
    // total size: 0x3
    char dmg_type;   // offset 0x0, size 0x1
    char blood_type; // offset 0x1, size 0x1
    char mince_type; // offset 0x2, size 0x1
} WPNDG_TBL;

typedef struct _COMBO_EFF 
{
    // total size: 0x6
    char dmg_type[3];   // offset 0x0, size 0x3
    char blood_type[3]; // offset 0x3, size 0x3
} COMBO_EFF;

typedef struct _LEGLOCK_LIST 
{
    // total size: 0x2
    char start; // offset 0x0, size 0x1
    char end;   // offset 0x1, size 0x1
} LEGLOCK_LIST;

typedef struct _LEGLOCK_TAB 
{
    // total size: 0x8
    char mtn_no;        // offset 0x0, size 0x1
    char default_lr;    // offset 0x1, size 0x1
    LEGLOCK_LIST* list; // offset 0x4, size 0x4
} LEGLOCK_TAB;

/* unused */
typedef struct _JOINT_PARE
{
    // total size: 0x2
    char cur;    // offset 0x0, size 0x1
    char parent; // offset 0x1, size 0x1
} JOINT_PARE;

typedef struct _MTN_RELAY_RELAY 
{
    // total size: 0x8
    short old_mtn_no;  // offset 0x0, size 0x2
    short next_mtn_no; // offset 0x2, size 0x2
    MTN_RELAY* relay;  // offset 0x4, size 0x4
} MTN_RELAY_RELAY;

typedef struct _EFF_INFO 
{
    // total size: 0x8
    int texid;     // offset 0x0, size 0x4
    UVINFO* uvtbl; // offset 0x4, size 0x4
} EFF_INFO;

static int target_direction(BH_PWORK* epw);
static float target_distance(BH_PWORK* epw);
static int GetLocalEneNo(BH_PWORK* epw);
static void SetMtnSE(BH_PWORK* epw);
void bhEne15(BH_PWORK* epw);
static void Init(BH_PWORK* epw);
static void Move(BH_PWORK* epw);
static void Stand(BH_PWORK* epw);
static void __attack(BH_PWORK* epw);
static void CloseTurn(BH_PWORK* epw);
static void Chase(BH_PWORK* epw);
static void __goalAng(BH_PWORK* epw, NJS_VECTOR* vec, NJS_POINT3* ans);
static int _goalAng(BH_PWORK* epw);
static int _goalAng2(BH_PWORK* epw);
static void KeepFar(BH_PWORK* epw);
static void Attack(BH_PWORK* epw);
static void Throw(BH_PWORK* epw);
static void Damage(BH_PWORK* epw);
static void Die(BH_PWORK* epw);
static int NearestCapsule(BH_PWORK* epw, NJS_POINT3* pos, NJS_CAPSULE* dest, short* jnt);
static void CheckDamage(BH_PWORK* epw);
static int GetRelay(BH_PWORK* epw, MTN_RELAY** ret);
static void SetMtn(BH_PWORK* epw);
static void ReqMtn(BH_PWORK* epw, unsigned int mtn_no);
static void SetPlyMtn(unsigned int mtn_no);
static int VacumeToPoint(BH_PWORK* pw, NJS_POINT3* pos);
static void LockLeg(BH_PWORK* epw);
int bhEne15_AttackPlayerCC(NJS_CAPSULE* cap, NJS_VECTOR* attack_v, int damage);
int bhEne15_AttackPlayerBC(NJS_BOX* box, NJS_VECTOR* attack_v, int damage);
int bhEne15_AttackPlayerSS(NJS_SPHERE* spr, NJS_VECTOR* attack_v, int damage);
static void SetSmoke(NJS_POINT3* pos, float arg1);
static void SpecialAttack(BH_PWORK* epw, NJS_VECTOR* splash_v);
static void _bhEne_SetPoison(BH_PWORK* epw, NJS_POINT3* ofp, short ry);
static void _bhEne_SetPoison2(O_WRK* op, int type, NJS_POINT3* ofp);
void bhEne_SetPoison(BH_PWORK* epw, BT_WORK* bt);
static void PoisonAttack(O_WRK* op);
static void AddWindForce(O_WRK* op, float reg);
void bhEff_E15_Poison(O_WRK* op);
void bhEne15_RotChar(BH_PWORK* pw, int goal, int add_ang);
static int AbleToFall(BH_PWORK* pp);
static int _DrivePlayer(BH_PWORK* epw);
static void DrivePlayer(BH_PWORK* epw);
static void FallingPlayer(BH_PWORK* epw);
static void SlidePlayer(BH_PWORK* epw);
static void StandupPlayer(BH_PWORK* epw);
static void HoldPlayer(BH_PWORK* epw);
static void FlyingPlayer(BH_PWORK* epw);
static void FallDiePlayer(BH_PWORK* epw);
static void DiePlayer(BH_PWORK* epw);
static void ChangeAmbient(short* plist, unsigned char add);
static void SetMince(BH_PWORK* epw, int type, int num);
static void CoreInit(BH_PWORK* epw);
static void CoreMove(BH_PWORK* epw);
static void CoreDie(BH_PWORK* epw);
void bhEne53(BH_PWORK* epw);

#endif
