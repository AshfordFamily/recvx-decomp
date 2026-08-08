#include "../../../ps2/veronica/prog/en09.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/main.h"

// ENEMY: Bandersnatch 

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveType_proc)(BH_PWORK*);
typedef void (*DamageType_proc)(BH_PWORK*);
typedef void (*NageType_proc)(BH_PWORK*);
typedef void (*DieType_proc)(BH_PWORK*);
typedef void (*BrainMode2_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);
typedef void (*NageMode2_proc)(BH_PWORK*);
typedef void (*DamageMode2_proc)(BH_PWORK*);
typedef void (*DieMode2_proc)(BH_PWORK*);

Mode0_proc bhEne09_Mode0[6] =
{
    bhEne09_Init,
    bhEne09_Move,
    bhEne09_Nage,
    bhEne09_Damage,
    bhEne09_Die,
    bhEne_Event
};

MoveType_proc bhEne09_MoveType[11] =
{
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType00,
    bhEne09_MVType09,
    bhEne09_MVType10
};

DamageType_proc bhEne09_DamageType[1] =
{
    bhEne09_DGType00
};

NageType_proc bhEne09_NageType[1] =
{
    bhEne09_NGType00
};

DieType_proc bhEne09_DieType[1] =
{
    bhEne09_DDType00
};

BrainMode2_proc bhEne09_BrainMode2[12] =
{
    bhEne09_Brain00,
    bhEne09_Brain00,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain,
    bhEne09_DmmyBrain
};

MoveMode2_proc bhEne09_MoveMode2[15] =
{
    bhEne09_MV00,
    bhEne09_MV01,
    bhEne09_MV02,
    bhEne09_MV03,
    bhEne09_MV04,
    bhEne09_MV05,
    bhEne09_MV06,
    bhEne09_MV07,
    bhEne09_MV08,
    bhEne09_MV09,
    bhEne09_MV10,
    bhEne09_MV11,
    bhEne09_MV12,
    bhEne09_MV13,
    bhEne09_MV14
};

NageMode2_proc bhEne09_NageMode2[2] =
{
    bhEne09_NG00,
    bhEne09_NG01
};

DamageMode2_proc bhEne09_DamageMode2[11] =
{
    bhEne09_DG00,
    bhEne09_DG01,
    bhEne09_DG02,
    bhEne09_DG03,
    bhEne09_DG04,
    bhEne09_DG05,
    bhEne09_DG06,
    bhEne09_DG07,
    bhEne09_DG08,
    bhEne09_DG09,
    bhEne09_DG10
};

DieMode2_proc bhEne09_DieMode2[1] =
{
    bhEne09_DD00
};

char en09_tree[4][16] =
{
    { 0x00, 0x01, 0x15, 0x16, 0x17, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x01, 0x12, 0x13, 0x14, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x01, 0x02, 0x03, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0D, 0xFF, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
};

static COMBJOINT_WORK CombJointTbl[24] = { 0 };

static COMBWEP_WORK CombWepTbl[21] =
{
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 5,   { 0, 0, 0 }, 120, 5 },
    { 5,   { 0, 0, 0 }, 60,  0 },
    { 5,   { 0, 0, 0 }, 60,  0 },
    { 5,   { 0, 0, 0 }, 60,  0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 5,   { 0, 0, 0 }, 60,  0 },
    { 180, { 0, 0, 0 }, 30,  0 },
    { 5,   { 0, 0, 0 }, 0,   0 },
    { 5,   { 0, 0, 0 }, 60,  0 },
    { 4,   { 0, 0, 0 }, 60,  0 },
    { 100, { 0, 0, 0 }, 30,  0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
    { 0,   { 0, 0, 0 }, 0,   0 },
};

WPNDAMAGE_WORK En09_WpnDamageTbl[22] = 
{
    { 0x00, 0, 0, 0, 0 },
    { 0x00, 0, 0, 0, 0 },
    { 0x0A, 4, 3, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 2, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x02, 2, 9, 3, 9 },
    { 0x0A, 4, 7, 3, 3 },
    { 0x02, 2, 3, 3, 3 },
    { 0x12, 2, 1, 3, 3 },
    { 0xC2, 2, 1, 3, 3 },
    { 0x52, 2, 1, 3, 3 },
    { 0x02, 2, 1, 3, 3 },
    { 0x60, 2, 1, 3, 3 },
    { 0x12, 2, 1, 3, 3 },
    { 0x60, 2, 1, 3, 3 },
    { 0x0A, 2, 1, 3, 3 },
};

BT_WORK en09prt_blood_tbl[24] = 
{
    {  0, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    {  1, 0.0f, -1.0f, 1.8f, 1.0f, 1.0f, 2.5f, 0.8f },
    {  2, 0.0f,  1.0f, 2.0f, 1.0f, 1.0f, 2.5f, 0.8f },
    {  3, 0.0f,  2.0f, 2.0f, 1.0f, 1.0f, 2.5f, 0.8f },
    {  4, 0.0f,  1.0f, 1.0f, 0.5f, 0.5f, 2.0f, 0.8f },
    {  5, 0.0f,  0.0f, 1.2f, 0.0f, 0.5f, 1.0f, 1.0f },
    {  6, 0.0f,  0.0f, 2.0f, 1.0f, 0.5f, 2.5f, 0.8f },
    {  7, 0.0f,  0.8f, 0.5f, 0.5f, 0.0f, 2.0f, 0.8f },
    {  8, 0.0f,  0.8f, 0.5f, 0.5f, 0.0f, 2.0f, 0.5f },
    {  9, 0.0f,  1.0f, 0.5f, 0.5f, 0.0f, 2.0f, 0.5f },
    { 10, 0.0f,  0.8f, 0.5f, 0.5f, 0.0f, 2.0f, 0.5f },
    { 11, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 12, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 13, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 14, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 15, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 16, 0.0f,  0.0f, 0.5f, 0.2f, 0.5f, 1.0f, 0.0f },
    { 17, 0.0f,  0.0f, 1.2f, 0.5f, 0.0f, 1.0f, 1.0f },
    { 18, 0.0f, -2.0f, 1.0f, 0.2f, 1.0f, 2.0f, 0.8f },
    { 19, 0.0f, -1.0f, 1.0f, 0.2f, 1.0f, 1.5f, 0.5f },
    { 20, 0.0f,  0.0f, 1.0f, 0.2f, 0.5f, 1.5f, 0.5f },
    { 21, 0.0f, -1.0f, 1.0f, 0.2f, 1.0f, 2.0f, 0.8f },
    { 22, 0.0f, -2.0f, 1.0f, 0.2f, 1.0f, 2.5f, 0.5f },
    { 23, 0.0f,  0.0f, 1.0f, 0.2f, 0.5f, 1.5f, 0.5f },
};

char En09SdwTab[6] =
{
    0x04, 0x0E, 0x11, 0x14, 0x17, 0xFF
};

CPCL Ene09CapColTab[19] = 
{
    {  1,  2, 16 },
    {  3,  3, 22 },
    {  0,  8,  0 },
    {  5,  5, 22 },
    { -12, 20,  0 },
    { 17, 17, 22 },
    { 20, 23,  0 },
    {  4,  4, 12 },
    {  0, 11, -2 },
    { 10, 14, 11 },
    {  6,  7, 14 },
    {  7,  8, 10 },
    {  8,  9, 10 },
    {  9, 10, 10 },
    { 18, 19,  7 },
    { 19, 20,  6 },
    { 21, 22, 10 },
    { 22, 23,  6 },
    {  0,  0,  0 },
};

int en09_hp_tbl[2][16] = 
{
    { 105, 105, 105, 120, 120, 120, 120, 135, 135, 135, 135, 135, 150, 150, 150, 150 },
    {  75,  75,  75,  90,  90,  90,  90, 105, 105, 105, 105, 105, 120, 120, 120, 120 },
};

CHK_TBL_WORK mtn_chg_tbl[17] =
{
    { 22, 0, 39,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 23, 0, 34,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 25, 0, 24,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 53, 0, 57,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 60, 0, 39,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 61, 0, 34,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 39, 0, 43,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 56, 0, 39,
        {
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0x000A0003 },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
            { -1, 0, 0, 0u, 0xFFFFFFFF },
        }
    },
    { 43, 28, 69,
        {
            { -1, 0, 0, 0u, 0x00080003 },
            { -1, 0, 0, 0u, 0x00080003 },
            { -1, 0, 0, 0u, 0x00080003 },
            { -1, 0, 0, 0u, 0x00080003 },
        }
    },
    { 43, 70, 90,
        {
            { -1, 0, 0, 0u, 0x00030003 },
            { -1, 0, 0, 0u, 0x00040003 },
            { -1, 0, 0, 0u, 0x00030003 },
            { -1, 0, 0, 0u, 0x00040003 },
        }
    },
    { 44, 0, 30,
        {
            { -1, 0, 0, 0u, 0x00030003 },
            { -1, 0, 0, 0u, 0x00040003 },
            { -1, 0, 0, 0u, 0x00030003 },
            { -1, 0, 0, 0u, 0x00040003 },
        }
    },
    { 44, 31, 65,
        {
            { -1, 0, 0, 0u, 0x00090003 },
            { -1, 0, 0, 0u, 0x00090003 },
            { -1, 0, 0, 0u, 0x00090003 },
            { -1, 0, 0, 0u, 0x00090003 },
        }
    },
    { 54, 0, 60,
        {
            { 53, 1, 2883584, 10u, 0x020A0003 },
            { 53, 1, 2883584, 10u, 0x020A0003 },
            { 53, 1, 2883584, 10u, 0x01040003 },
            { 53, 1, 2883584, 10u, 0x01040003 },
        }
    },
    { 54, 61, 79,
        {
            { 53, 1, 1441792, 10u, 0x01040003 },
            { 53, 1, 1441792, 10u, 0x01040003 },
            { 53, 1, 1441792, 10u, 0x01040003 },
            { 53, 1, 1441792, 10u, 0x01040003 },
        }
    },
    { 29, 0, 39,
        {
            { 23, 1, 1310720, 10u, 0x020A0003 },
            { 23, 1, 1310720, 10u, 0x020A0003 },
            { 23, 1, 1310720, 10u, 0x01030003 },
            { 23, 1, 1310720, 10u, 0x01030003 },
        }
    },
    { 29, 40, 59,
        {
            { 23, 1, 327680, 10u, 0x01030003 },
            { 22, 0, 327680, 10u, 0x01040003 },
            { 23, 1, 327680, 10u, 0x01030003 },
            { 22, 0, 327680, 10u, 0x01040003 },
        }
    },
    { -1, 0, 0,
        {
            { 0, 0, 0, 0u, 0x00000000 },
            { 0, 0, 0, 0u, 0x00000000 },
            { 0, 0, 0, 0u, 0x00000000 },
            { 0, 0, 0, 0u, 0x00000000 },
        }
    },
};

ARM_POS arm4_pos[92] =
{
    { 0, 3.330214023590088f },
    { 1, 3.3285319805145264f },
    { 2, 3.3288979530334473f },
    { 3, 3.3273448944091797f },
    { 4, 3.326885938644409f },
    { 5, 3.3254499435424805f },
    { 6, 3.329685926437378f },
    { 7, 3.33132004737854f },
    { 8, 3.3315799236297607f },
    { 9, 3.331861972808838f },
    { 10, 3.3314459323883057f },
    { 11, 5.661480903625488f },
    { 12, 7.821333885192871f },
    { 13, 10.887284278869629f },
    { 14, 12.708694458007812f },
    { 15, 12.775318145751953f },
    { 16, 9.384824752807617f },
    { 17, 9.222817420959473f },
    { 18, 9.616060256958008f },
    { 19, 9.069976806640625f },
    { 20, 9.030425071716309f },
    { 21, 9.211437225341797f },
    { 22, 9.237797737121582f },
    { 23, 9.077678680419922f },
    { 24, 8.3761568069458f },
    { 25, 7.658078193664551f },
    { 26, 6.9855170249938965f },
    { 27, 6.246860980987549f },
    { 28, 5.591980934143066f },
    { 29, 4.987664222717285f },
    { 30, 4.412007808685303f },
    { 31, 3.9406731128692627f },
    { 32, 3.7108380794525146f },
    { 33, 3.3435380458831787f },
    { 34, 3.4984679222106934f },
    { 35, 3.5089690685272217f },
    { 36, 3.3773579597473145f },
    { 37, 3.448512077331543f },
    { 38, 3.6010539531707764f },
    { 39, 3.4351658821105957f },
    { 40, 3.373631000518799f },
    { 41, 3.315938949584961f },
    { 42, 2.9275169372558594f },
    { 43, 3.1966440677642822f },
    { 44, 3.3013219833374023f },
    { 45, 3.3259880542755127f },
    { 46, 3.3374850749969482f },
    { 47, 3.3418240547180176f },
    { 48, 3.344641923904419f },
    { 49, 3.345781087875366f },
    { 50, 3.348068952560425f },
    { 51, 3.3501811027526855f },
    { 52, 3.350830078125f },
    { 53, 3.344942092895508f },
    { 54, 3.3343029022216797f },
    { 55, 3.3356359004974365f },
    { 56, 3.3477590084075928f },
    { 57, 3.3597071170806885f },
    { 58, 3.3543519973754883f },
    { 59, 3.33583402633667f },
    { 60, 3.3247249126434326f },
    { 61, 3.3214869499206543f },
    { 62, 3.3134748935699463f },
    { 63, 3.3084518909454346f },
    { 64, 3.30674409866333f },
    { 65, 3.3077850341796875f },
    { 66, 3.307435989379883f },
    { 67, 3.3039169311523438f },
    { 68, 3.3000130653381348f },
    { 69, 3.3007700443267822f },
    { 70, 3.3011300563812256f },
    { 71, 3.3050589561462402f },
    { 72, 3.314694881439209f },
    { 73, 3.307651996612549f },
    { 74, 3.303618907928467f },
    { 75, 3.304003953933716f },
    { 76, 3.3057758808135986f },
    { 77, 3.307692050933838f },
    { 78, 3.311460018157959f },
    { 79, 3.3122119903564453f },
    { 80, 3.3142950534820557f },
    { 81, 3.316282033920288f },
    { 82, 3.3205130100250244f },
    { 83, 3.3222739696502686f },
    { 84, 3.325237989425659f },
    { 85, 3.3267428874969482f },
    { 86, 3.3276100158691406f },
    { 87, 3.3277640342712402f },
    { 88, 3.3269150257110596f },
    { 89, 3.327332019805908f },
    { 90, 3.326478958129883f },
    { -1, 0.0f },
};

ARM_POS arm4_pos2[67] =
{
    { 0, 3.3304150104522705f },
    { 1, 3.3281750679016113f },
    { 2, 3.3257288932800293f },
    { 3, 3.3228020668029785f },
    { 4, 3.3172481060028076f },
    { 5, 3.313291072845459f },
    { 6, 3.322521924972534f },
    { 7, 3.333894968032837f },
    { 8, 3.3278119564056396f },
    { 9, 3.3363139629364014f },
    { 10, 3.3661410808563232f },
    { 11, 3.538316011428833f },
    { 12, 3.7945759296417236f },
    { 13, 5.828187942504883f },
    { 14, 7.164752006530762f },
    { 15, 7.129210948944092f },
    { 16, 5.681756019592285f },
    { 17, 5.750618934631348f },
    { 18, 5.815890789031982f },
    { 19, 5.88588285446167f },
    { 20, 5.838542938232422f },
    { 21, 5.753118991851807f },
    { 22, 5.472600936889648f },
    { 23, 4.1639580726623535f },
    { 24, 3.7393789291381836f },
    { 25, 3.263000965118408f },
    { 26, 3.010317087173462f },
    { 27, 2.559079885482788f },
    { 28, 2.7073869705200195f },
    { 29, 3.374871015548706f },
    { 30, 3.3669939041137695f },
    { 31, 3.3669419288635254f },
    { 32, 3.38474702835083f },
    { 33, 3.3895459175109863f },
    { 34, 3.384922981262207f },
    { 35, 3.318751096725464f },
    { 36, 3.3052749633789062f },
    { 37, 3.341733932495117f },
    { 38, 3.349622964859009f },
    { 39, 3.3379650115966797f },
    { 40, 3.3210129737854004f },
    { 41, 3.2968170642852783f },
    { 42, 3.2965660095214844f },
    { 43, 3.297795057296753f },
    { 44, 3.2877180576324463f },
    { 45, 3.2752270698547363f },
    { 46, 3.2768659591674805f },
    { 47, 3.304769992828369f },
    { 48, 3.304020881652832f },
    { 49, 3.2983579635620117f },
    { 50, 3.2994349002838135f },
    { 51, 3.301455020904541f },
    { 52, 3.306067943572998f },
    { 53, 3.3106300830841064f },
    { 54, 3.3175549507141113f },
    { 55, 3.3199400901794434f },
    { 56, 3.325040102005005f },
    { 57, 3.3283770084381104f },
    { 58, 3.3271889686584473f },
    { 59, 3.3289051055908203f },
    { 60, 3.327683925628662f },
    { 61, 3.3276939392089844f },
    { 62, 3.326749086380005f },
    { 63, 3.325943946838379f },
    { 64, 3.326085090637207f },
    { 65, 3.326111078262329f },
    { -1, 0.0f },
};

/*
int En09_PlyMtn_OffsetTbl[4];
_anon1 en09_mtn_tbl[28];
_anon6 en09_mtn_tbl2[24];
_anon6 en09_mtn_tbl3[5];
_anon40 en09_BldTbl;
_anon40 en09_BldTbl2;
_anon20 en09_lkmtab;
float en09_mtn23[35];
_anon39 arm4_pos3[143];
_anon39 arm4_pos4[128];
_anon39 arm4_pos5[654];
_anon39 arm4_pos6[185];
float en09_mogmog[40];
*/

// 100% matching!
void bhEne09_DmmyBrain(void) 
{

}

// 100% matching!
void bhEne09(BH_PWORK* epw) 
{
	BH_PWORK* ep;
    int i;

    bhEne09_DmgCheck(epw);
    bhEne09_MainLoop(epw);
    
    if (epw->flg & 4) 
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        
        epw->flg &= ~4;
    }
    
    if (EXP0_I(0x14) > 0)
    {
        EXP0_I(0x14)--;
    }
    
    bhEne09_CollCheck(epw);
    bhEne09_CalcEnemy(epw);
    bhEne09_PlayerLink(plp, epw);
     
    if (EXP0_I(0x18) & 0x8000)
    {
        if (!(plp->flg & 4) && !(plp->stflg & 0x80000000)) 
        {
            bhEne09_CollChkArm(epw, plp);
        }
        
        ep = ene;
        for (i = 0; i < sys->ewk_n; i++, ep++)
        {
            if (ep != epw)
            {
                if ((ep->id != 0) && (ep->id != 0x3D))
                {
                    if (!(ep->flg & 2) && !(ep->flg2 & 1) && (ep->flg & 1)) 
                    {
                        bhEne09_CollChkArm(epw, ep);
                    }
                }
            }
        }
    }
    
    if (EXP0_I(0x1C) > 0)
    {
        EXP0_I(0x1C)--;
    }
    
    if (EXP0_I(0x20) > 0)
    {
        EXP0_I(0x20)--;
    }
}

// 100% matching!
void bhEne09_MainLoop(BH_PWORK* epw)
{
    bhEne09_Mode0[epw->mode0](epw);
    
    bhEne09_PlayerControl(plp, epw);
    
    if (!(EXP0_I(0x18) & 0x800)) 
    {
        bhEne09_SetMtn(epw);
    }
}

// 100% matching!
void bhEne09_PlayerControl(BH_PWORK* pl, BH_PWORK* epw) 
{
    if ((EXP0_I(0x18) & 0x400000) && (((pl->mode0 == 4)) || (pl->mode0 == 6))) 
    {
        if (pl->mode2 == 0) 
        {
            bhEne09_PlyDG00(plp, epw);
        }
        else
        {
            bhEne09_PlyDG01(plp, epw);
        }
    }
}

// 100% matching!
void bhEne09_CalcEnemy(BH_PWORK* epw) 
{
    O_WORK* owk;
    NJS_VECTOR ps;
    NJS_VECTOR pd;

    bhCalcModel(epw);

    epw->cah = epw->ah = epw->mlwP->owP[4].mtx[13] - epw->py;
    
    owk = epw->mlwP->owP;
    ps.x = 2.0f;
    ps.y = 0;
    ps.z = 0;
    
    njCalcPoint((NJS_MATRIX *)owk->mtx, &ps, &pd);
    
    epw->aox = pd.x - epw->px;
    epw->aoz = pd.z - epw->pz;
    
    owk = epw->mlwP->owP;
    epw->watr.c1.x = owk[4].mtx[12];
    epw->watr.c1.y = owk[4].mtx[13];
    epw->watr.c1.z = owk[4].mtx[14];
    
    owk = epw->mlwP->owP;
    epw->watr.c2.x = owk[20].mtx[12];
    epw->watr.c2.y = owk[20].mtx[13];
    epw->watr.c2.z = owk[20].mtx[14];
    
    owk = epw->mlwP->owP;
    epw->watr.c2.x = (epw->watr.c2.x + owk[23].mtx[12]) / 2.0f;
    epw->watr.c2.y = (epw->watr.c2.y + owk[23].mtx[13]) / 2.0f;
    epw->watr.c2.z = (epw->watr.c2.z + owk[23].mtx[14]) / 2.0f;
    
    epw->watr.r = 2.5f;
}

// 100% matching!
void bhEne09_CollCheck(BH_PWORK* epw) 
{
    if (!(epw->flg & 2)) 
    {
        if (!(EXP0_I(0x18) & 0x10)) 
        {
            bhCheckPlayer(epw);
        }
        
        if (!(EXP0_I(0x18) & 0x20)) 
        {
            bhCheckEnemies(epw);
        }
    }
    
    bhEne09_CollCheckWall(epw);
}

// 99.9% matching!
void bhEne09_CollCheckWall(BH_PWORK* epw) 
{
	ATR_WORK *hp;
    NJS_VECTOR ps;
    NJS_VECTOR ops;
    NJS_VECTOR pd;
    O_WORK *owk;

    if (!(EXP0_I(0x18) & 0x80) && (epw->flg & 0x10)) 
    {
        epw->stflg &= ~1;
        
        ps.x = epw->px + epw->aox;
        ps.y = epw->py + epw->aoy;
        ps.z = epw->pz + epw->aoz;
        
        hp = bhCheckWallType(&ps, epw->flg, epw->ar, epw->ah);
        *(ATR_WORK **)(epw->exp0 + 0x50) = hp;

        if ((EXP0_I(0x18) & 0xF) == 1)
        {
            ps.x = epw->px + epw->aox;
            ps.y = epw->py + epw->aoy;
            ps.z = epw->pz + epw->aoz;
            
            ops.x = epw->pxb + epw->aox;
            ops.y = epw->pyb + epw->aoy;
            ops.z = epw->pzb + epw->aoz;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne09_CollCheckArm(epw);
        }
        else if ((EXP0_I(0x18) & 0xF) == 2)
        {
            ps.x = epw->px + epw->aox;
            ps.y = epw->py + epw->aoy;
            ps.z = epw->pz + epw->aoz;
            
            ops.x = epw->pxb + epw->aox;
            ops.y = epw->pyb + epw->aoy;
            ops.z = epw->pzb + epw->aoz;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne_CalcPartsPos(epw, lcmat, &pd, en09_tree[0], 5, 1);
            bhEne_CalcPartsPos(epw, lcmat, &ps, en09_tree[1], 5, 1);
            
            ps.x = (pd.x + ps.x) / 2.0f;
            ps.y = (pd.y + ps.y) / 2.0f;
            ps.z = (pd.z + ps.z) / 2.0f;
            
            owk = epw->mlwP->owP;
            ops.x = owk[23].mtx[12];
            ops.y = owk[23].mtx[13];
            ops.z = owk[23].mtx[14];
            
            owk = epw->mlwP->owP;
            ops.x = (ops.x + owk[20].mtx[12]) / 2.0f;
            ops.y = (ops.y + owk[20].mtx[13]) / 2.0f;
            ops.z = (ops.z + owk[20].mtx[14]) / 2.0f;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 2.0f, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne09_CollCheckArm(epw);
        }
        else if ((EXP0_I(0x18) & 0xF) == 3)
        {
            ps.x = epw->px + epw->aox;
            ps.y = epw->py + epw->aoy;
            ps.z = epw->pz + epw->aoz;
            
            ops.x = epw->pxb + epw->aox;
            ops.y = epw->pyb + epw->aoy;
            ops.z = epw->pzb + epw->aoz;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne_CalcPartsPos(epw, lcmat, &ps, en09_tree[3], 5, 1);
            
            ps.y = epw->py;
            
            owk = epw->mlwP->owP;
            ops.x = owk[4].mtx[12];
            ops.y = epw->pxb;
            ops.z = owk[4].mtx[14];
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 2.0f, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne09_CollCheckArm(epw);
        }
        else if ((EXP0_I(0x18) & 0xF) == 6)
        {
            bhEne_CalcPartsPos(epw, lcmat, &ps, en09_tree[2], 2, 1);
                
            owk = epw->mlwP->owP;
            ops.x = owk[1].mtx[12];
            ops.y = owk[1].mtx[13];
            ops.z = owk[1].mtx[14];
            
            ps.x += epw->aox;
            ps.y += epw->aoy;
            ps.z += epw->aoz;
            
            ops.x += epw->aox;
            ops.y += epw->aoy;
            ops.z += epw->aoz;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 4.0f, epw->ah);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
            
            bhEne09_CollCheckArm(epw);
        }
    }
}

// 100% matching!
void bhEne09_CollCheckArm(void)
{

}

// 99.92% matching!
void bhEne09_Init(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT* obj;
    int i;
    float save_pos[4];
    unsigned char* addr;
    int size;
    O_WORK* owk;

    epw->ar = 5.0f;
    epw->ah = 18.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 4.0f;
    epw->cah = 18.0f;
    epw->stflg = 0;
    epw->aoz = 0.0f;
    epw->aoy = 0.0f;
    epw->aox = 0.0f;
    
    if (sys->gm_mode != 2) 
    {
        epw->hp = en09_hp_tbl[0][rand() % 16];
    }
    else 
    {
        epw->hp = en09_hp_tbl[1][rand() % 16];
    }

    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }

    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 1;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = NULL;
    epw->mtn_md = 0x20;

    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(0x7C, 8);

        obj = epw->mlwP->objP;
        EXP0_F(0x0) = obj[7].pos[0];
        EXP0_F(0x4) = obj[8].pos[0];
        EXP0_F(0x8) = obj[9].pos[0];
        EXP0_F(0xC) = obj[10].pos[0];
    }
    else 
    {
        int i;  // Fixes regswaps

        if (EXP0_I(0x18) & 0x01000000)
        {
            owk = plp->mlwP->owP;
            owk[4].flg &= ~3;
            owk[5].flg &= ~2;
        }

        for (i = 0; i < 4; i++)
        {
            save_pos[i] = EXP0_F(4*i);
        }

        addr = epw->exp0;
        i = 0x7C;
        while (i-- != 0)
        {
            *addr++ = 0;
        }

        for (i = 0; i < 4; i++)
        {
            EXP0_F(4*i) = save_pos[i];
        }

        obj = epw->mlwP->objP;
        obj[7].pos[0] = EXP0_F(0x0);
        obj[8].pos[0] = EXP0_F(0x4);
        obj[9].pos[0] = EXP0_F(0x8);
        obj[10].pos[0] = EXP0_F(0xC);
    }

    EXP0_I(0x18) &= ~0xF;
    EXP0_I(0x18) |= 1;

    epw->flg |= 0x178;
    epw->flg &= ~2;
    epw->mlwP->objP = epw->mbp[0];
    epw->mdflg = 0;
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];
    epw->cpcl = Ene09CapColTab;

    if (!(epw->flg & 0x800)) 
    {
        bhSetShadow(En09SdwTab, (unsigned char *)epw, 1, 5.0f, 4.0f, 4.0f);
        epw->flg |= 0x800;
    }

    epw->mdflg &= ~0x400;

    npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFFB2B2B2U);

    epw->clp_jno[0] = 4;
    epw->clp_jno[1] = 0x11;
    epw->clp_jno[2] = 0xF;
    epw->clp_jno[3] = 7;
    epw->clp_jno[4] = 8;
    epw->clp_jno[5] = 9;
    epw->clp_jno[6] = 0x14;
    epw->clp_jno[7] = 0x17;
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->lok_jno = 4;

    bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);  // int cast fixes load order

    bhEne09_CalcEnemy(epw);
}

// 100% matching!
void bhEne09_Move(BH_PWORK* epw)
{
    bhEne09_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne09_Damage(BH_PWORK* epw)
{
    bhEne09_DamageType[0](epw);
}

// 100% matching!
void bhEne09_Nage(BH_PWORK* epw)
{
    bhEne09_NageType[0](epw);
}

// 100% matching!
void bhEne09_Die(BH_PWORK* epw)
{
    bhEne09_DieType[0](epw);
}

// 98.79% matching!
int bhEne09_DmgCheck(BH_PWORK* epw)
{
    int flg;

    flg = 0;
    
    if ((epw->flg & 4) && !(epw->flg & 2))
    {
        flg = 1;
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if (epw->total_dam == 0) 
            return flg;
        
        else if (!(EXP0_I(0x18) & 0x40)
            || (epw->flr_no > plp->flr_no)
            || ((WpnTab[epw->wpnr_no].flg & 0x20) != 0)
            || (WpnTab[epw->wpnr_no].flg & 0x20000000)
            || !(plp->at_flg & 2))
        {
            bhEne09_DamageAdd(epw);
            
            if (epw->mode0 >= 3) 
            {
                bhEne09_SePlay(epw, 0x0100230E);
                flg = 1;
                return flg;
            }
            else
            {
                epw->flg |= 0x40;
            
                EXP0_I(0x18) &= 0xEFFFFFFF;
                
                EXP0_I(0x18) |= 0x08000000;
                
                if (epw->comb_flg & 4) 
                {
                    EXP0_I(0x18) |= 0x200;
                }
                else 
                {
                    EXP0_I(0x18) &= ~0x200;
                }
                
                bhEne09_ChgDmgMode(epw);
                
                if (EXP0_I(0x18) & 0x04000000)
                {
                    EXP0_I(0x18) &= 0xFB1FFFFF;
                    
                    *(int *)plp->exp1 |= 4;
                    
                    sys->pad_on &= ~0xF;
                    plp->flg &= 0xFFFEFFFF;
                    plp->flg |= 8;
                    plp->stflg &= 0xFFFAFFFF;
                    plp->at_flg = 0;
                    plp->mnwP = plp->mnwPb;
                    
                    if (plp->flg2 & 0x200) 
                    {
                        plp->mode0 = 2;
                        plp->mode2 = 1;
                        plp->mode3 = 0;
                        
                        if (bhDGCdirCheck((NJS_VECTOR *)&plp->dvx, plp->ay) == 0) 
                        {
                            plp->mode1 = 0;
                        }
                        else 
                        {
                            plp->mode1 = 1;
                        }
                        
                        plp->flg |= 4;
                    }
                    else 
                    {
                        *((int*)&plp->mode0) = 1;
                        plp->flg &= ~4;
                    }
                }
            }
        }
        
    }

    return flg;
}

// 97.5% matching!
void bhEne09_ChgDmgMode(BH_PWORK* epw)
{
	WPNDAMAGE_WORK *wp_tbl = &En09_WpnDamageTbl[epw->wpnr_no];
    int act = wp_tbl->nm_act;
    
    if ((wp_tbl->flg & 2) && (epw->comb_flg & 1)) 
    {
        if (!(EXP0_I(0x18) & 0x2000) 
            && !(EXP0_I(0x18) & 0x4000) 
            && !(EXP0_I(0x18) & 0x10000) 
            && !(EXP0_I(0x18) & 0x80000) 
            && !(EXP0_I(0x18) & 0x40000) 
            && (epw->hp > 0) 
            && ((rand() % 10) == 0)) 
        {
            act = 2;
            epw->comb_flg &= ~1;
            bhEne09_SePlay(epw, 0x0100230F);
        }
    }
    
    if ((epw->hp < 0) 
        || (!(wp_tbl->flg & 8) 
            && (((EXP0_I(0x18) & 0x2000)) 
                || (EXP0_I(0x18) & 0x4000) 
                || (EXP0_I(0x18) & 0x10000)
                || (EXP0_I(0x18) & 0x80000)
                || (EXP0_I(0x18) & 0x40000))))
    {
        epw->comb_flg |= 1;
        epw->comb_timeout = 0;
        epw->comb_pnt = 0;
    }
    
    if (epw->comb_flg & 1) 
    {
        if (bhEne09_ExDmgCheck(epw) != 0) 
        {
            return;
        }
        else
        {
            bhEne09_SePlay(epw, 0x0100230F);
            act = wp_tbl->cb_act;
        }
    } 
    else 
    {
        bhEne09_SePlay(epw, 0x0100230E);
    }

    if (act == 0)
    {
        if (!(EXP0_I(0x18) & 0x100000))
        {
            EXP0_I(0x18) |= 0x100000;
            epw->ct3 = 0;
        }
    } 
    else if (act == 5)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;
    }
    else if (act == 1)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 1;
        epw->mode3 = 0;
    }
    else if (act == 2)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
    else if (act == 3)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        
        if (epw->comb_flg & 4) 
        {
            if (wp_tbl->flg & 4) 
            {
                epw->mode2 = ((rand() % 3) == 0) ? 4 : 3;
            }
            else
            {
                epw->mode2 = 3;
            }
        }
        else
        {
            epw->mode2 = 4;
        }
    }
}

// 100% matching!
int bhEne09_ExDmgCheck(BH_PWORK* epw)
{
	CHG_TBL_WORK* chg_tbl;
    CHK_TBL_WORK* chk_tbl;
    int frm;
    int hit;
    int i;

    frm = epw->frm_no >> 0x10;
    hit = 0;
    chk_tbl = mtn_chg_tbl;
    i = 0;
    while (1)
    {
        if (chk_tbl->mtn_no == -1) break;

        if ((chk_tbl->mtn_no == epw->mtn_no)
            && (frm >= chk_tbl->s_frm)
            && (frm <= chk_tbl->e_frm))
        {
            if (epw->hp < 0)
            {
                if (EXP0_I(0x18) & 0x200) 
                {
                    chg_tbl = &chk_tbl->chg_tbl[0];
                }
                else
                {
                    chg_tbl = &chk_tbl->chg_tbl[1];
                }
            }
            else 
            {
                if (EXP0_I(0x18) & 0x200) 
                {
                    chg_tbl = &chk_tbl->chg_tbl[2];
                }
                else
                {
                    chg_tbl = &chk_tbl->chg_tbl[3];
                }
            }

            if (chg_tbl->mtn_no != -1)
            {
                if (chg_tbl->type == 0) 
                {
                    bhEne_ChgMtn(epw, chg_tbl->mtn_no, chg_tbl->frm_no, chg_tbl->h_cnt);

                    EXP0_I(0x18) &= 0x1fffffff;
                }
                else 
                {
                    bhEne_ChgMtn(epw, chg_tbl->mtn_no, chg_tbl->frm_no, chg_tbl->h_cnt);

                    EXP0_I(0x18) &= 0x7fffffff;
                    EXP0_I(0x18) &= 0xDFFFFFFF;
                    EXP0_I(0x18) |= 0x40000000;
                }
            }

            if (chg_tbl->mode != -1) 
            {
                *(int*)&epw->mode0 = chg_tbl->mode;
                epw->ayp = epw->ay;
            }
            hit = 1;
            break;
        }

        chk_tbl++;
        i++;
    }

    if (EXP0_I(0x18) & 0x4000) 
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 5;
        epw->mode3 = 0;
        return 1;
    }

    if (EXP0_I(0x18) & 0x10000) 
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;

        if (EXP0_I(0x18) & 0x200) 
        {
            epw->mode2 = 6;
        }
        else
        {
            epw->mode2 = 7;
        }

        hit = 1;
        epw->ayp = epw->ay;
    }

    return hit;
}

// 100% matching!
void bhEne09_DamageAdd(BH_PWORK* epw) 
{
    WPNDAMAGE_WORK *wp_tbl = En09_WpnDamageTbl;
    NJS_POINT3 ofp = { 0.0, 0.0, 0.0 };
    int *d;
    int obj_no;
    int i;

    if (epw->hp >= 0)
    {
        d = &epw->dam[1];
        epw->hp = epw->hp - epw->total_dam;
        wp_tbl = &wp_tbl[epw->comb_wep];
        
        for (i = 1; i < (int)epw->mlwP->obj_num; i++, d++)
        {
            if (*d > 0) 
            {
                epw->djnt_no = i;
                
                if (!(wp_tbl->flg & 0x40)) 
                {
                    if ((epw->comb_flg & 1) || epw->hp < 0)
                    {
                        EXP0_I(0x1C) = 0xA;
                        
                        if (epw->djnt_no < 0x12)
                        {
                            ofp.y = 1.0f;
                            obj_no = 3;
                        }
                        else 
                        {
                            ofp.y = -2.0f;
                            obj_no = 1;
                        }
                        if (wp_tbl->cb_blood == 9) 
                        {
                            if (epw->comb_flg & 0x40) 
                            {
                                bhEne_SetBlood4(epw, obj_no, &ofp, 9, 3);
                            }
                            else 
                            {
                                bhEne_SetBlood4(epw, obj_no, &ofp, 9, 1);
                            }
                            
                            bhEne_SetBlood2(epw, 9U, &ofp, plp->way);
                        }
                        else 
                        {
                            bhEne_SetBlood4(epw, obj_no, &ofp, 9, 0);
                        }
                    } 
                    else 
                    {
                        if (wp_tbl->nm_blood == 9) 
                        {
                            bhEne_SetBlood2(epw, 9U, &ofp, plp->way);
                            
                            if (epw->djnt_no < 0x12) 
                            {
                                ofp.y = 1.0f;
                                obj_no = 3;
                            }
                            else 
                            {
                                ofp.y = -2.0f;
                                obj_no = 1;
                            }
                            
                            if (epw->comb_flg & 0x40) 
                            {
                                bhEne_SetBlood4(epw, obj_no, &ofp, 9, 3);
                            }
                            else 
                            {
                                bhEne_SetBlood4(epw, obj_no, &ofp, 9, 0);
                            }
                        }
                        
                        else if (wp_tbl->nm_blood == 7) 
                        {
                            bhEne_SetBlood(epw, wp_tbl->nm_blood & 0xFF, en09prt_blood_tbl);
                        }
                        else 
                        {
                            bhEne_SetBlood(epw, wp_tbl->nm_blood & 0xFF, en09prt_blood_tbl);
                        }
                    }
                }
            }
        }
    }
    
    if ((wp_tbl->flg & 0x10) || (wp_tbl->flg & 0x20)) 
    {
        if (EXP0_I(0x20) <= 0) 
        {
            EXP0_I(0x20) = 0xA;
            
            if (wp_tbl->flg & 0x20) 
            {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en09prt_blood_tbl, 2);
                
                if (epw->hp < 0) 
                {
                    epw->mdflg |= 0x400;
                    npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF000000U);
                }
            }
            else 
            {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en09prt_blood_tbl, 1);
            }
        }
    }
    
    if (wp_tbl->flg & 0x80) 
    {
        if (EXP0_I(0x20) <= 0) 
        {
            EXP0_I(0x20) = 0xA;
            bhEne_SetSanEffect(epw, epw->djnt_no, en09prt_blood_tbl);
        }
    }
}

// 100% matching!
void bhEne09_PlayerLink(BH_PWORK* pl, BH_PWORK* epw) 
{
    char ply_tree[7] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0xFF };
    NJS_POINT3 ps;
    NJS_POINT3 pd;

    if (EXP0_I(0x18) & 0x200000) 
    {
        njUnitMatrix(NULL);
        njTranslate(NULL, epw->px, epw->py, epw->pz);
        njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
        njCalcPoint(NULL, (NJS_VECTOR* ) &EXP0_F(0x38), &pd);
        
        pl->px = pd.x;
        pl->pz = pd.z;
        
        pl->ay = (epw->ay + epw->wax) & 0xFFFF;
    }
    else if (EXP0_I(0x18) & 0x800000) 
    {
        njCalcPoint((NJS_MATRIX *)&epw->mlwP->owP[13].mtx, (NJS_VECTOR* ) &EXP0_F(0x38), &pd);
        
        bhSetMotion(pl, 0, pl->mtn_md, pl->mtn_tp);
        
        bhEne_CalcPartsPos(pl, lcmat, &ps, ply_tree, 6, 1);
        
        ps.x = pl->px - ps.x;
        ps.z = pl->pz - ps.z;
        
        pl->px = pd.x + ps.x;
        pl->pz = pd.z + ps.z;
        
        pl->ay = (epw->ay + epw->wax) & 0xFFFF;
    }
}

// 100% matching!
void bhEne09_MVType00(BH_PWORK* epw) 
{
    EXP0_F(0x28) = njDistanceP2P((NJS_VECTOR* ) &plp->px, (NJS_VECTOR* ) &epw->px);
    
    if (epw->mode1 == 1) 
    {
        bhEne09_Brain(epw);
    }
    
    if (epw->mode0 == 1) 
    {
        bhEne09_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne09_MVType09(BH_PWORK* epw) 
{
    EXP0_F(0x28) = njDistanceP2P((NJS_VECTOR *)&plp->px, (NJS_VECTOR *)&epw->px);
    EXP0_F(0x2C) = epw->px;
    EXP0_F(0x34) = epw->pz;
    
    epw->mode1 = 0;
    epw->mode2 = 0xA;
    epw->mode3 = 0;
    
    bhEne09_MV10(epw);
}

// 100% matching!
void bhEne09_MVType10(BH_PWORK* epw) 
{
    EXP0_F(0x28) = njDistanceP2P((NJS_VECTOR *)&plp->px, (NJS_VECTOR *)&epw->px);
    
    if (epw->mode2 == 3) 
    {
        bhEne09_MV03(epw);
    }
    else
    {
        bhEne09_MV00(epw);
    }
}

// 100% matching!
void bhEne09_EneSearch(BH_PWORK* epw) 
{
    if ((EXP0_UC(0x10) & 0x1F) < 0x1F) 
    {
        if (bhSearchPlayer(epw, 0x471C) != -1)
        {
            EXP0_UC(0x10) |= 0x20;
        }
        
        if (EXP0_UC(0x10) & 0x20) 
        {
            EXP0_UC(0x10) |= 0x40;
            EXP0_UC(0x10) &= 0xDF;
        } 
        else if ((EXP0_UC(0x10) & 0x1F) == 0x1E) 
        {
            EXP0_UC(0x10) &= 0xBF;
        }
    }
    
    EXP0_UC(0x10)++;
    
    if ((EXP0_UC(0x10) & 0x1F) >= 0x1F) 
    {
        EXP0_UC(0x10) &= 0xE0;
    }
    
    if (EXP0_UC(0x10) & 0x40) 
    {
        EXP0_I(0x18) |= 0x1000;
        EXP0_C(0x11)= 0xFU;
    }
        
    else if (EXP0_I(0x18) & 0x1000) 
    {
        unsigned char temp = EXP0_C(0x11) - 1;
        EXP0_C(0x11) = temp;
        
        if ((temp & 0xFF) < 0) 
        {
            EXP0_I(0x18) &= ~0x1000;
        }
    }
}

// 100% matching!
void bhEne09_Brain(BH_PWORK* epw)
{
	ATR_WORK *hp;
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    unsigned char rid;

    bhEne09_EneSearch(epw);
    
    if ((epw->flr_no == plp->flr_no) && !(plp->stflg & 0x10)) 
    {
        if (EXP0_I(0x18) & 0x1000)
        {
            rid = bhCheckRoute((NJS_VECTOR *)&epw->px, (NJS_VECTOR *)&plp->px, &pos) & 0xFF;
            
            if (rid != 0xFF)
            {
                EXP0_F(0x2C) = pos.x;
                EXP0_F(0x34) = pos.z;
            }
            else 
            {
                EXP0_F(0x2C) = plp->px;
                EXP0_F(0x34) = plp->pz;
            }
            
            if ((epw->mode2 == 1) || (epw->mode2 == 0))
            {
                if ((rid & 0xFF) != 0xFF)
                {
                    if ((ikou3(epw, (NJS_VECTOR *)&EXP0_F(0x2C), 0x2000) == 0)
                        && (bhEne_EnemyAtariCheck((NJS_VECTOR *)&epw->px, epw->flr_no, epw->id, 5U) != NULL)) 
                    {
                        pos.x = epw->px;
                        pos.z = epw->pz;
                        
                        pos2.x = epw->px - ((3.0f + epw->ar) * njSin(epw->ay));
                        pos2.z = epw->pz - ((3.0f + epw->ar) * njCos(epw->ay));
                        
                        pos2.y = pos.y = epw->py;
                        
                        if ((hp = bhCollisionCheckLine(&pos, &pos2)) != NULL)
                        {
                            bhGetHitCollisionNormal(&pos);
                            
                            *(ATR_WORK **)(epw->exp0 + 0x54) = hp;
                            
                            if (hp->type == 0) 
                            {
                                if (!(hp->h <= 0.0f) && (hp->h <= 8.0f)) 
                                {
                                    epw->axp = epw->ayp = (int)(10430.381f * atan2f(pos.x, pos.z));
                                    
                                    epw->ayp = bhEne09_ChkDiffAngle(epw->ay, epw->ayp);
                                    
                                    epw->mode1 = 0;
                                    epw->mode2 = 4;
                                    epw->mode3 = 0;
                                }
                            }
                        }
                    }
                }
                
                if (((rid & 0xFF) != 0xFF) 
                    && !(EXP0_F(0x28) <= 30.0f)
                    && (ikou3(epw, (NJS_VECTOR *)&plp->px, 0xE38) == 0)
                    && (bhEne_EnemyAtariCheck((NJS_VECTOR* ) &epw->px, epw->flr_no, epw->id, 4U) == NULL) 
                    && (bhEne09_OtherEnemyCheck(epw, 50.0f, 0xAAA) == 0))
                {
                    hp = bhEne09_ChkArmLen(epw, (float *)&EXP0_F(0x6C), &pos);
                    
                    if ((hp != NULL)
                        && !(hp->attr & 8)
                        && (hp->h == 0.0f) 
                        && (hp->type == 0)
                        && (bhEne_AngleCheck(&pos, epw->ay, 0x800) != 0)) 
                    {
                        epw->mode1 = 0;
                        epw->mode2 = 5;
                        epw->mode3 = 0;
                    }
                }
            }
        }
        
        EXP0_I(0x18) &= 0xFDFFFFFF;
    } 
    else 
    {
        if (!(EXP0_I(0x18) & 0x02000000))
        {
            if (plp->stflg & 0x10) 
            {
                if (plp->mode0 == 1) 
                {
                    unsigned char temp;
                    if (plp->mode2 == 0xE) 
                    {
                        temp = 2;
                    }
                    else
                    {
                        temp = 3;
                    }
                    
                    hp = bhEne09_GetCloseEnemyAtari(epw, temp, 0xFFU);
                    
                    *(ATR_WORK **)(epw->exp0 + 0x54) = hp;
                    
                    if (hp != NULL)
                    {
                        EXP0_I(0x18) |= 0x02000000;
                    }
                }
            }
            else 
            {
                if (epw->flr_no < plp->flr_no) 
                {
                    rid = 2;
                }
                else
                {
                    rid = 3;
                }
                
                hp = bhEne_EnemyAtariCheck((NJS_VECTOR *)&plp->px, plp->flr_no, epw->id, rid);
                
                if (hp != NULL) 
                {
                    hp = bhEne09_GetCloseEnemyAtari(epw, hp->prm1, hp->prm3);
                    
                    *(ATR_WORK **)(epw->exp0 + 0x54) = hp;
                    
                    if (hp != NULL)
                    {
                        EXP0_I(0x18) |= 0x02000000;
                    }
                }
            }
        }
        
        if (EXP0_I(0x18) & 0x02000000)
        {
            if ((bhCheckRoute((NJS_VECTOR *)&epw->px, (NJS_VECTOR *)&EXP0_F(0x44), &pos) & 0xFF) != 0xFF) 
            {
                EXP0_F(0x2C) = pos.x;
                EXP0_F(0x34) = pos.z;
            }
            else 
            {
                EXP0_F(0x2C) = EXP0_F(0x44);
                EXP0_F(0x34) = EXP0_F(0x4C);
            }
            
            if (bhEne09_JumpCheck(epw, *(ATR_WORK **)(epw->exp0 + 0x54)) != 0) 
            {
                EXP0_I(0x18) &= 0xFDFFFFFF;
            }
        } 
        else 
        {
            EXP0_F(0x2C) = plp->px;
            EXP0_F(0x34) = plp->pz;
        }
    }
    
    bhEne09_BrainMode2[epw->mode2](epw);
}

// 100% matching!
int bhEne09_OtherEnemyCheck(BH_PWORK* epw, float dist, int ang)
{
	BH_PWORK* ep;
    int i;
    
    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (ep != epw) 
        {
            if (!(ep->flg & 2)
                && (ep->flg & 1)
                && (ikou3(epw, (NJS_VECTOR *)&ep->px, ang) == 0)
                && (njDistanceP2P((NJS_VECTOR *)&ep->px, (NJS_VECTOR *)&epw->px) < dist)) 
            {
                return 1;
            }
        }
    }

    return 0;
}

// 100% matching!
ATR_WORK* bhEne09_GetCloseEnemyAtari(BH_PWORK* epw, unsigned char type, unsigned char id)
{
	unsigned char TypeTbl[2] = { 00, 01 };
    short i;
    ATR_WORK *fp;
    ATR_WORK *near_fp;
    NJS_POINT3 pos;
    float near_dist;
    float dist;
    int flr_n;

    // NOT from DWARF
    float px;
    float pz;

    near_dist = 0.0f;
    
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n) 
        {
            fp = &rom->flrp[i];
        }
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if (fp->flg & 1) 
        {
            if ((fp->type == 2) 
                && (fp->flr_no == epw->flr_no)
                && (fp->prm0 == epw->id)
                && (fp->prm1 == TypeTbl[type - 2]) 
                && (fp->prm3 != (id & 0xFF))
                && ((pos.x = fp->px + (fp->w / 2.0f), 
                     pos.y = fp->py, pos.z = fp->pz + (fp->d / 2.0f), 
                     dist = njDistanceP2P(&pos, (NJS_VECTOR *)&epw->px),
                     (near_dist > dist))
                    || (near_dist == 0.0f)))
            {
                pz = pos.z;
                px = pos.x;
                
                near_dist = dist;
                near_fp = fp;
            }
        }
    }
    
    if (!(near_dist <= 0.0f)) 
    {
        EXP0_F(0x44) = px;
        EXP0_F(0x4C) = pz;
        
        return near_fp;
    }
    
    return NULL;
}

// 100% matching!
int bhEne09_JumpCheck(BH_PWORK* epw, ATR_WORK* hp)
{
    int jump_ang[4] =
    {
        0x00000000,
        0x0000C000,
        0x00008000,
        0x00004000
    };
    ATR_WORK *fp;
    NJS_POINT3 pd;
    NJS_LINE l1;
    float len;
    int i;
    int flr_n;

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n) 
        {
            fp = &rom->flrp[i];
        }
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 1) && (fp->type == 2)) 
        {
            if ((fp->px <= epw->px) && !((fp->px + fp->w) < epw->px)) 
            {
                if ((fp->pz <= epw->pz) 
                    && !((fp->pz + fp->d) < epw->pz)
                    && (fp->flr_no == epw->flr_no)
                    && (fp == hp)) 
                {
                    switch (hp->prm2) 
                    {
                        case 0:
                        case 2:
                            l1.px = hp->px;
                            l1.pz = hp->pz + (hp->d / 2.0f);
                            l1.py = hp->py;
                            
                            l1.vx = hp->w;
                            l1.vy = 0;
                            l1.vz = 0.0f;
                            break;
                        
                        case 1:
                        case 3:
                            l1.px = hp->px + (hp->w / 2.0f);
                            l1.pz = hp->pz;
                            l1.py = hp->py;
                            
                            l1.vx = 0.0f;
                            l1.vy = 0;
                            l1.vz = hp->d;
                    }
                    
                    if (njDistanceP2L((NJS_VECTOR *)&epw->px, &l1, &pd) < 2.0f)
                    {
                        if (hp->prm1 == 0)
                        {
                            if (!(plp->py <= epw->py)
                                && (plp->mode0 == 1)
                                && (plp->mode2 == 0xF)) 
                            {
                                return 0;
                            }
                            
                            epw->mode1 = 0;
                            epw->mode2 = 0xA;
                            epw->mode3 = 0;
                            
                            EXP0_F(0x2C) = pd.x;
                            EXP0_F(0x34) = pd.z;
                            EXP0_F(0x30) = epw->py;
                            
                            epw->ayp = bhEne09_ChkDiffAngle(epw->ay, jump_ang[hp->prm2]);
                            
                            return 1;
                        }
                        
                        if (hp->prm1 == 1) 
                        {
                            if ((plp->py < epw->py)
                                && (plp->mode0 == 1)
                                && (plp->mode2 == 0xE))
                            {
                                return 0;
                            }
                            
                            epw->mode1 = 0;
                            epw->mode2 = 0xB;
                            epw->mode3 = 0;
                            
                            EXP0_F(0x2C) = pd.x;
                            EXP0_F(0x34) = pd.z;
                            EXP0_F(0x30) = epw->py;
                            
                            epw->ayp = bhEne09_ChkDiffAngle(epw->ay, jump_ang[hp->prm2]);
                            
                            return 1;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

// 100% matching!
void bhEne09_Brain00(BH_PWORK* epw)
{
    if (((plp->flg & 2) || (plp->flg & 4) || (plp->stflg & 0x80000000))
        && (EXP0_F(0x28) < 17.0f) 
        && (ikou3(epw, (NJS_VECTOR* ) &plp->px, 0x3000) == 0))
    {
        epw->mode1 = 0;
        epw->mode2 = 9;
        epw->mode3 = 0;
        return;
    }
    
    if (!(plp->flg & 2)
        && !(plp->flg & 4) 
        && !(plp->stflg & 0x80000000)
        && (EXP0_I(0x14) <= 0))
    {
        if (bhEne09_AttackCheck(epw, 0) != 0) 
        {
            epw->mode1 = 0;
            epw->mode2 = 0xD;
            epw->mode3 = 0;
            return;
        }
        
        if (bhEne09_AttackCheck(epw, 1) != 0) 
        {
            epw->mode1 = 0;
            epw->mode2 = 0xC;
            epw->mode3 = 0;
            return;
        }
        
        if (bhEne09_AttackCheck(epw, 2) != 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 7;
            epw->mode3 = 0;
            return;
        }
        
        if (bhEne09_AttackCheck(epw, 3) != 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 6;
            epw->mode3 = 0;
            return;
        }
    }
    
    if ((epw->flr_no == plp->flr_no) && (ikou3(epw, (NJS_VECTOR* ) &plp->px, 0x5800) != 0)) 
    {
        if ((epw->flg & 4) || (EXP0_F(0x28) < 15.0f))
        {
            epw->mode1 = 0;
            epw->mode2 = 8;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
int bhEne09_AttackCheck(BH_PWORK* epw, int mode) 
{
	O_WORK *owk;
    ATR_WORK *hp;
    NJS_POINT3 ps1; 
    NJS_POINT3 ps2;
    float dist2;
    float h;

    // NOT from DWARF
    int temp, temp2;

    ps1.x = epw->px;
    ps1.y = epw->py;
    ps1.z = epw->pz;
    
    ps2.x = plp->px;
    ps2.y = plp->py;
    ps2.z = plp->pz;
    
    hp = bhCollisionCheckLine(&ps1, &ps2);
    
    ps1.x = plp->px;
    ps1.y = epw->py;
    ps1.z = plp->pz;
    
    ps2.x = epw->px;
    ps2.y = epw->py;
    ps2.z = epw->pz;
    
    dist2 = njDistanceP2P(&ps1, &ps2);
    
    switch (mode)
    {
        case 0:
            h = EXP0_F(0x28);
            
            if (!(h <= 17.0f)
                && (h < 20.0f) 
                && (hp == NULL)
                && (epw->hp < 0x4B)
                && (plp->hp < 0x50)
                && (epw->flr_no == plp->flr_no)
                && (ikou3(epw, (NJS_VECTOR *)&plp->px, 0x2000) == 0))
            {
                return 1;
            }
            
            break;
        
        case 1:
            h = EXP0_F(0x28);
            
            if (!(h <= 17.0f)
                && (h < 20.0f)
                && (hp == NULL) 
                && (epw->flr_no == plp->flr_no) 
                && (ikou3(epw, (NJS_VECTOR *)&plp->px, 0x2000) == 0)) 
            {
                return 1;
            }
            
            break;
        
        case 2:
            if ((dist2 < 13.0f) 
                && (ikou3(epw, (NJS_VECTOR *)&plp->px, 0x3000) == 0)) 
            {
                owk = epw->mlwP->owP;
                
                ps1.x = epw->px;
                ps1.z = epw->pz;
                ps1.y = owk[4].mtx[13];
                
                ps2.x = plp->px;
                ps2.y = plp->py + (owk[4].mtx[13] - epw->py);
                ps2.z = plp->pz;
                
                if (bhCollisionCheckLine(&ps1, &ps2) == NULL) 
                {
                    return 1;
                }
            }
            
            break;
        
        case 3:
            if (((plp->stflg & 0x400) && (rand() % 8) == 1) || ((rand() % 32) == 1))
            {
                h = plp->py - epw->py;
                
                if (!(h < 0.0f) 
                    && (h <= 10.0f)
                    && !(dist2 <= 14.0f) 
                    && (dist2 < 50.0f))
                {
                    owk = epw->mlwP->owP;
                    
                    ps1.x = epw->px;
                    ps1.z = epw->pz;
                    
                    ps2.x = plp->px;
                    ps2.z = plp->pz;
                    
                    ps2.y = ps1.y = owk[6].mtx[13];
                    
                    if ((bhCollisionCheckLine(&ps1, &ps2) == NULL) 
                        && (bhEne09_AramLineCheck(epw, &ps1, &ps2) == 0)) 
                    {
                        return 1;
                    }
                }
            }
    }

    return 0;
}

// 99.84% matching!
int bhEne09_AramLineCheck(BH_PWORK* epw, NJS_VECTOR* p1, NJS_VECTOR* p2) 
{
	BH_PWORK* ep;
    NJS_SPHERE at;
    int i;
    int j;
    int max;

    // NOT from DWARF
    float px;
    float pz;

    px = (p2->x - p1->x) / 10.0f;
    pz = (p2->z - p1->z) / 10.0f;

    at.c.x = p1->x;
    at.c.y = p1->y;
    at.c.z = p1->z;
    
    at.r = 3.0f;
    
    max = sys->ewk_n;

    for (i = 0; i < 10; i++)
    {
        if (bhCheckWallType(&at.c, epw->flg, 2.0f, 2.0f) != NULL) 
        {
            return 1;
        }
        
        ep = ene;
        
        for (j = 0; j < max; j++, ep++)
        {
            if (ep != epw) 
            {
                if (!(ep->flg & 2) 
                    && (ep->flg & 1)
                    && (npCollisionCheckSC(&at, &ep->watr) != 0)) 
                {
                    return 1;
                }
            }
        }
        
        at.c.x += px;
        at.c.z += pz;
    }

    return 0;
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne09_MV00(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* obj;

    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 1, 0, 0xF);

            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->frm_no = (rand() % epw->mnwP[epw->mtn_no].frm_num) << 0x10;
            
            epw->ct0 = (rand() % 128) + 200;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0]  = EXP0_F(0x0);
            obj[8].pos[0]  = EXP0_F(0x4);
            obj[9].pos[0]  = EXP0_F(0x8);
            obj[10].pos[0] = EXP0_F(0xC);
            
            if (epw->type == 0xA)
            {
                epw->mode1 = 0;
            }
            else 
            {
                epw->mode1 = 1;
            }
            
            epw->mode3 += 1;
        
            /* fallthrough */
        case 1:
            epw->ct0 -= 1;
            
            if (((bhSearchPlayer(epw, 0x471C) != -1) 
                 || (epw->flg & 4) 
                 || (epw->ct0 <= 0)) 
                && (epw->type != 0xA)) 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne09_MV01(BH_PWORK* epw)
{
    int hit;

    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 0, 0, 0xF);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (EXP0_I(0x18) & 0x1000)
            {
                ikou(epw, (NJS_VECTOR *)&EXP0_I(0x2C), 0x16C);
                return;
            }
            
            if (bhEne_CheckDirWall2(epw, 0, 6.0f) != NULL) 
            {
                hit = bhEne_CheckSideWall(epw, 6.0f, 0);
                
                if (hit == 0) 
                {
                    epw->way = (rand() % 2) ? 0x16C : -0x16C;
                } 
                else 
                {
                    epw->way = hit * 0x16C;
                }
                
                epw->mode3++;
            }
            
            break;
        case 2:
            if (bhEne_CheckDirWall2(epw, 0, 6.0f) == NULL) 
            {
                epw->mode3 = 1;
                return;
            }
            
            epw->ay += epw->way;
    }
}

// 100% matching!
void bhEne09_MV02() 
{

}

// 100% matching!
void bhEne09_MV03(BH_PWORK* epw) 
{
    int temp;    // NOT from DWARF
    
    switch (epw->mode3)
    {
        case 0:
            if (epw->mtn_no == 0x35) 
            {
                bhEne_ChgMtn(epw, 0x38, 0, 0);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
            }
            else 
            {
                bhEne_ChgMtn(epw, 0x27, 0, 0);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
            }
            
            epw->ct0 = (rand() % 60) + 0x1E;
            
            EXP0_I(0x18) &= ~0xF;
            EXP0_I(0x18) |= 1;
            EXP0_I(0x18) |= 0x10;
            EXP0_I(0x18) |= 0x2000;
            
            epw->flg |= 0x20;
            epw->flg2 |= 1;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            temp = epw->ct0 - 1;
            epw->ct0 = temp;
            if ((temp < 0) || (EXP0_I(0x18) & 0x08000000))
            {
                if (epw->mtn_no == 0x27)
                {
                    bhEne_ChgMtn(epw, 0x1D, 0, 0);
                    
                    EXP0_I(0x18) &= 0x1FFFFFFF;
                }
                else 
                {
                    bhEne_ChgMtn(epw, 0x36, 0, 0);
                    
                    EXP0_I(0x18) &= 0x1FFFFFFF;
                }
                
                EXP0_I(0x18) &= 0xF7FFFFFF;
                
                epw->flg |= 0x40000;
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if (((epw->mtn_no == 0x1D) && ((epw->frm_no >> 0x10) == 0x32)) ||
                ((epw->mtn_no == 0x36) && ((epw->frm_no >> 0x10) == 0x41)))
            {
                EXP0_I(0x18) &= ~0x40;
            }
            
            if (((epw->mtn_no == 0x1D) && ((epw->frm_no >> 0x10) == 0x38)) ||
                ((epw->mtn_no == 0x36) && ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))))
            {
                epw->flg2 &= ~1;
            
                EXP0_I(0x18) &= ~0x10;
                EXP0_I(0x18) &= ~0x2000;
            
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
            break;
    }
}

// 100% matching!
void bhEne09_MV04(BH_PWORK* epw)
{
	NJS_CNK_OBJECT* obj;
    float len;
    ATR_WORK *hp;
    unsigned int frm;

    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 6, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->way = 0x16C;
            epw->ct0 = 0;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0]  = EXP0_F(0x0);
            obj[8].pos[0]  = EXP0_F(0x4);
            obj[9].pos[0]  = EXP0_F(0x8);
            obj[10].pos[0] = EXP0_F(0xC);
            
            EXP0_F(0x6C) = bhEne09_ChkArmLen2(epw);
            EXP0_I(0x18) |= 0x8000;
            EXP0_I(0x18) |= 0x30;
            EXP0_F(0x60) = epw->py;
            
            epw->flg2 |= 1;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            frm = epw->frm_no >> 0x10;
            
            if (frm < 5) 
            {
                epw->ay += epw->ayp / 5;
            }
            else if (frm >= 0xF) 
            {
                if (frm < 0x13) 
                {
                    obj = epw->mlwP->objP;
                    
                    obj[7].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[8].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[9].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[10].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                }
            }
            
            if (frm == 0x12) 
            {
                epw->frm_no = 0;
                epw->mtn_no = 0x15;
                epw->mode3++;
            }

            break;
        
        case 2:
            if (epw->flg & 0x02000000)
            {
                epw->frm_no = 0;
                epw->mtn_no = 9;
                
                EXP0_I(0x18) |= 0x80;
                EXP0_I(0x18) |= 0x4000;
                
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[8].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[9].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[10].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                
                epw->mode3++;
            }
            
            break;
        
        case 3:
            if (!(epw->flg & 0x02000000))
            {
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[8].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[9].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[10].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                
                return;
            }
            
            epw->frm_no = 0;
            epw->mtn_no = 0xC;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= 0xFFFF7FFF;

            hp = (ATR_WORK *)*(int *)(epw->exp0 + 0x54);

            epw->axp = (unsigned short)epw->axp;
            
            if ((0x2000 < epw->axp) && (0x5FFF >= epw->axp))
            {
                len = -1.0f * ((hp->px - 9.0f) - epw->px);
            }
            else if ((0x6000 < epw->axp) && (0x9FFF >= epw->axp))
            {
                len = (9.0f + (hp->pz + hp->d)) - epw->pz;
            }
            else if ((0xA000 < epw->axp) && (0xDFFF >= epw->axp)) 
            {
                len = (9.0f + (hp->px + hp->w)) - epw->px;
            }
            else 
            {
                len = -1.0f * ((hp->pz - 9.0f) - epw->pz);
            }
            
            epw->spd = len / epw->mnwP[epw->mtn_no].frm_num;
            
            epw->mode3++;
        
            break;
        
        case 4:
            epw->py += -0.15f * epw->ct0;
            
            if (!((EXP0_F(0x60) - 0.414835f) <= epw->py)) 
            {
                epw->py = EXP0_F(0x60) - 0.4f;
            }
            
            bhAddSpeed(epw, 0);
            
            epw->ct0++;
            
            if (epw->flg & 0x02000000) 
            {
                EXP0_I(0x18) &= ~0x80;
                EXP0_I(0x18) &= ~0x4000;
                EXP0_I(0x18) &= ~0x30;
                
                epw->flg2 &= ~1;
                epw->mtn_no = 0x34;
                epw->frm_no = 0;
                epw->ct0 = 0;
                
                epw->py = EXP0_F(0x60);
                
                epw->mode3++;
            }
            
            break;
        
        case 5:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

#pragma divbyzerocheck on

// 99.58% matching!
void bhEne09_MV05(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT* obj;
    O_WORK* owk;
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    NJS_POINT3 pos3;
    NJS_POINT3 v1;
	int frm;
    int frm_max;
    float nn;

    switch (epw->mode3) 
    {
        case 0:
            bhEne_ChgMtn(epw, 7, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->flg2 |= 1;
            epw->way = 0x5B0;
            epw->ct0 = 0;
            
            EXP0_I(0x18) |= 0x8000;
            EXP0_I(0x18) |= 0x30;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0]  = EXP0_F(0x0);
            obj[8].pos[0]  = EXP0_F(0x4);
            obj[9].pos[0]  = EXP0_F(0x8);
            obj[10].pos[0] = EXP0_F(0xC);
            
            bhEne09_ChkArmLen(epw, (float *)&EXP0_F(0x6C), &v1);
            
            EXP0_F(0x6C) -= 3.0f;
            EXP0_F(0x70) = 0.0f;
            EXP0_F(0x74) = 0.0f;
            
            epw->ct0 = 1;
            epw->ct1 = 0;
            
            EXP0_F(0x60) = epw->py;
            
            epw->axp = epw->ayp = (int)(10430.381f * atan2f(v1.x, v1.z));
            
            epw->ayp = bhEne09_ChkDiffAngle(epw->ay, epw->ayp);
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 3)) 
            {
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
            }
            
            EXP0_F(0x74) = 10.0f - (1.2f * epw->ct1);
            
            if (EXP0_F(0x74) < 0.0f)
            {
                EXP0_F(0x74) = 0.1f;
            }
            
            EXP0_F(0x70) += EXP0_F(0x74);
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[8].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[9].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[10].pos[0] += EXP0_F(0x74) / 4.0f;
            
            epw->ct1++;
            
            owk = epw->mlwP->owP;
            
            pos.x = owk[13].mtx[12];
            pos.y = owk[13].mtx[13];
            pos.z = owk[13].mtx[14];
            
            bhEne_CalcPartsPos(epw, lcmat, &pos2, en09_tree[2], 0xB, 1);
            
            pos3.x = pos2.x;
            pos3.y = pos2.y;
            pos3.z = pos2.z;
            
            if (bhCollisionCheckLine(&pos, &pos3) != NULL) 
            {
                pos2.x -= pos3.x;
                pos2.y -= pos3.y;
                pos2.z -= pos3.z;
                
                nn = njScalor(&pos2);
                
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[8].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[9].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[10].pos[0] -= EXP0_F(0x74) / 4.0f;
                
                EXP0_F(0x74) -= nn;
                
                obj[7].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[8].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[9].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[10].pos[0] += EXP0_F(0x74) / 4.0f;
                
                epw->mtn_no = 0x13;
                epw->frm_no = 0;
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
            
            break;
        
        case 3:
            if (epw->flg & 0x02000000)
            {
                epw->mtn_no = 0xA;
                epw->frm_no = 0;
                epw->mtn_add = 0x10000;
                
                EXP0_I(0x18) |= 0x10080;
                
                epw->flg &= ~0x100;
                
                obj = epw->mlwP->objP;
                
                EXP0_F(0x6C) = obj[7].pos[0] - EXP0_F(0x0);
                EXP0_F(0x70) = obj[8].pos[0] - EXP0_F(0x4);
                EXP0_F(0x74) = obj[9].pos[0] - EXP0_F(0x8);
                EXP0_F(0x78) = obj[10].pos[0] - EXP0_F(0xC);
                
                epw->ct1 = 6;
                epw->ct0 = 0;
                epw->mode3++;
            }
            
            break;
        
        case 4:
            frm = epw->frm_no >> 0x10;
            
            frm_max = epw->mnwP[epw->mtn_no].frm_num;
            
            epw->ay += epw->ayp / epw->ct1;
            
            if (((frm_max - 1) == frm) && (epw->mtn_no == 0xA))
            {
                epw->mtn_add = 0;
            }
            
            if (epw->ct0 < epw->ct1)
            {
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= EXP0_F(0x6C) / epw->ct1;
                obj[8].pos[0] -= EXP0_F(0x70) / epw->ct1;
                obj[9].pos[0] -= EXP0_F(0x74) / epw->ct1;
                obj[10].pos[0] -= EXP0_F(0x78) / epw->ct1;
            }
                    
            epw->ct0++;
            
            if ((epw->ct0 >= epw->ct1) && ((frm_max - 1) == frm)) 
            {
                epw->mtn_no = 0xE;
                epw->frm_no = 0;
                epw->hokan_count = 0;
                epw->hokan_rate = 0xCCCC;
                epw->mtn_add = 0x10000;
                epw->flg |= 0x100;
                
                EXP0_I(0x18) &= 0xFFFF7FFF;
                
                epw->mode3++;
            }
            
            break;
        
        case 5:
            if (((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) && (EXP0_I(0x18) & 0x20000)) 
            {
                epw->mode0 = 3;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
            }
            
            if (epw->flg & 0x02000000) 
            {
                epw->mtn_no = 0xF;
                epw->frm_no = 0;
                epw->hokan_count = 0;
                epw->hokan_rate = 0xCCCC;
                epw->mtn_add = 0x10000;
                
                epw->py = EXP0_F(0x60);
                
                epw->ct0 = 0;
                
                owk = epw->mlwP->owP;
                
                epw->px = owk->mtx[0xC];
                epw->py = owk->mtx[0xD];
                epw->pz = owk->mtx[0xE];
                
                EXP0_F(0x5C) = (((EXP0_F(0x60) - 0.143332f) - epw->py) / 12.0f);
                
                epw->spd = 0.3f;
                epw->py += EXP0_F(0x5C);
                epw->mode3++;
            }
            
            break;
        
        case 6:
            frm = epw->frm_no >> 0x10;
            
            if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->flg |= 0x100;
                epw->py = EXP0_F(0x60);
                
                EXP0_I(0x18) &= ~0x30;
                
                epw->flg2 &= ~1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
            else if (frm < 0xC) 
            {
                EXP0_F(0x58) = 1.0f;
                
                nn = njCos(0x3000);
                epw->spd = EXP0_F(0x58) * nn;
                
                bhAddSpeed(epw, 0x8000);
                
                epw->py += (fabsf(EXP0_F(0x58)) * njSin(0x3000)) - (epw->ct0 * 0.15f);
                
                nn = EXP0_F(0x60) - 0.143332f;
                
                if (epw->py < nn)
                {
                    epw->py = nn;
                }
                
                ikou(epw, (NJS_VECTOR *)&plp->px, epw->way);
                
                epw->ct0++;
                epw->spd = 0.3f;
                
                epw->py = epw->py + EXP0_F(0x5C);
            }
            else 
            {
                EXP0_I(0x18) &= ~0x80;
                EXP0_I(0x18) &= 0xFFFEFFFF;
                epw->py = EXP0_F(0x60);
            }

            break;
        
        case 7:
            break;
    }
}

#pragma divbyzerocheck off

// 98.97% matching!
void bhEne09_MV06(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT* obj;
    O_WORK* owk;
    int rot;

    switch(epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 0x10, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->way = 0x71C;
            epw->ct0 = 0;
            epw->ct2 = 0;
            
            EXP0_I(0x18) |= 0x8000;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0]  = EXP0_F(0x0);
            obj[8].pos[0]  = EXP0_F(0x4);
            obj[9].pos[0]  = EXP0_F(0x8);
            obj[10].pos[0] = EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            owk = plp->mlwP->owP;
            
            rot = ikou3(epw, (NJS_VECTOR *)&owk->mtx[0xC], epw->way);
            
            if (rot == 0) 
            {
                epw->ay = NitenDir_ck(epw->px, epw->pz, owk->mtx[0xC], owk->mtx[0xE]);
            }
            else 
            {
                epw->ay += rot;
            }
            
            if ((epw->frm_no >> 0x10) == 0x10) 
            {
                EXP0_F(0x6C) = 30.0f;
                EXP0_F(0x6C) = EXP0_F(0x28) - 15.0f;
                
                if (EXP0_F(0x6C) < 0.0f) 
                {
                    EXP0_F(0x6C) = 0.0f;
                }
                
                EXP0_F(0x70) = 0.0f;
                EXP0_F(0x74) = 0.0f;
                
                epw->ct0 = 0;
                epw->ct1 = 0;
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if ((epw->frm_no >> 0x10) == 0x13) 
            {
                epw->mtn_add = 0;
            }
            
            EXP0_F(0x74) = (10.0f - (1.2f * epw->ct1));
            
            if (EXP0_F(0x74) < 0.0f) 
            {
                EXP0_F(0x74) = 0.1f;
            }
            
            EXP0_F(0x70) += EXP0_F(0x74);
            
            if (EXP0_F(0x6C) < EXP0_F(0x70)) 
            {
                EXP0_F(0x74) = EXP0_F(0x6C) - (EXP0_F(0x70) - EXP0_F(0x74));
                epw->mtn_add = 0x10000;
                epw->mode3++;
                
                break;
            }
            
            epw->ct1++;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[8].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[9].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[10].pos[0] += EXP0_F(0x74) / 4.0f;
                
            if ((0x12 < (epw->frm_no >> 0x10)) && (bhEne09_CollChkArm2(epw) != 0)) 
            {
                bhEne09_SePlay(epw, 0x12307);
                
                obj[0].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[1].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[3].pos[0] -= EXP0_F(0x74) / 4.0f;
                    
                epw->mtn_add = 0x10000;
                epw->mode3++;
            }
            
            break;
        
        case 3:
            if ((epw->frm_no >> 0x10) == 0x19) 
            {
                obj = epw->mlwP->objP;
                
                EXP0_F(0x6C) = obj[7].pos[0] - EXP0_F(0x0);
                EXP0_F(0x70) = obj[8].pos[0] - EXP0_F(0x4);
                EXP0_F(0x74) = obj[9].pos[0] - EXP0_F(0x8);
                EXP0_F(0x78) = obj[10].pos[0] - EXP0_F(0xC);
                
                epw->ct1 = 8;
                epw->ct0 = 0;
                epw->mode3++;
            }
            
            bhEne09_CollChkArm2(epw);
            
            break;
        
        case 4:
            if (epw->ct1 > epw->ct0)
            {
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= EXP0_F(0x6C) / epw->ct1;
                obj[8].pos[0] -= EXP0_F(0x70) / epw->ct1;
                obj[9].pos[0] -= EXP0_F(0x74) / epw->ct1;
                obj[10].pos[0] -= EXP0_F(0x78) / epw->ct1;
            }
            
            epw->ct0++;
            
            rot = epw->frm_no >> 0x10;
            
            if (rot == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->flg |= 0x100;
                
                EXP0_I(0x14) = ((rand() % 15) + 0xA);
                
                EXP0_I(0x18) &= 0xFFFF7FFF;
                
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 99.96% matching!
void bhEne09_MV07(BH_PWORK* epw) 
{
	NJS_SPHERE at;    // r29+0x30
    int rot;
    int frm;

    switch (epw->mode3) 
    {
        case 0:
            rot = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz) - epw->ay;
            
            if ((0x8000 < (rot & 0xFFFF) ) && (0xE7FF >= (rot & 0xFFFF)))
            {
                bhEne_ChgMtn(epw, 0x31, 0, 8);
                EXP0_I(0x18) &= 0x1FFFFFFF;
            }
            else 
            {
                bhEne_ChgMtn(epw, 0x2D, 0, 8);
                EXP0_I(0x18) &= 0x1FFFFFFF;
            }

            if ((rot & 0xFFFF) < 0x8001)
            {
                epw->ayp = ((rot & 0xFFFF) / 5);
            }
            else 
            {
                epw->ayp = (-(0x10000 - (rot & 0xFFFF)) / 5);
            }
            
            epw->flg |= 0x40000;
            epw->way = 0x600;
            epw->ct0 = 5;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (--epw->ct0 >= 0) 
            {
                epw->ay += epw->ayp;
            }
            
            frm = epw->frm_no >> 0x10;
            
            bhEne_CalcPartsPos(epw, lcmat, &at.c, en09_tree[2], 10, 1);
            
            if ((epw->mtn_no == 0x2D && frm >= 0xA && frm < 0x10) ||
                (epw->mtn_no == 0x31 && 0xC < frm && 0x10 >= frm))
            {
                at.r = 3.0f;
                
                if ((npCollisionCheckSC((NJS_SPHERE* ) &at, &plp->watr) != 0) && !(plp->flg & 4) && !(plp->stflg & 0x80000000)) 
                {
                    plp->djnt_no = 2;
                    
                    plp->dpx = at.c.x;
                    plp->dpy = at.c.y;
                    plp->dpz = at.c.z;
                    
                    bhEne_HitCheckParts(plp, &at.c);
                    
                    plp->flg |= 4;
                    plp->mode0 = 2;
                    plp->mode2 = 1;
                    plp->mode3 = 0;
                    plp->hp -= 0x14;
                    
                    rot = (plp->ay - epw->ay) & 0xFFFF;
                    
                    if (epw->mtn_no == 0x2D) 
                    {
                        if (0x2000 < rot && rot < 0xA000) 
                        {
                            plp->mode1 = 0;
                        } 
                        else 
                        {
                            plp->mode1 = 1;
                        }
                    } 
                    else 
                    {
                        if (rot < 0x8000) 
                        {
                            plp->mode1 = 1;
                        } 
                        else 
                        {
                            plp->mode1 = 0;
                        }
                    }
                    
                    bhEne_SetVibration(1);
                    bhEne09_SePlay(epw, 0x12307);
                }
            }
            
            frm = epw->frm_no >> 0x10;
            
            if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
            {
                EXP0_I(0x18) &= ~0x100;
                EXP0_I(0x14) = ((rand() % 15) + 0xA);
                
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne09_MV08(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 0, 0, 8);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg &= 0xFFFBFFFF;
            epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
            epw->ayp = (epw->ayp - epw->ay) & 0xFFFF;
            
            if (epw->ayp < 0x8001) 
            {
                epw->ayp /= 12;
            }
            else 
            {
                epw->ayp = (-(0x10000 - epw->ayp) / 12);
            }
            
            epw->ct0 = 0xC;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            epw->ay += epw->ayp;
            
            if (--epw->ct0 < 0)
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
    }
}

// 100% matching!
void bhEne09_MV09(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 1, 0, 0xA);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
            epw->ayp = (epw->ayp - epw->ay) & 0xFFFF;
            
            if (epw->ayp > 0x8000)
            {
                epw->ayp = (epw->ayp - 0x8000) - 0x8000;
            }
            
            epw->ct0 = 0xA;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (--epw->ct0 >= 0)
            {
                epw->ay += (epw->ayp / 10);
            }
            
            if (!(plp->flg & 4)) 
            {
                if (bhEne09_AttackCheck(epw, 1)) 
                {
                    epw->mode1 = 0;
                    epw->mode2 = 0xC;
                    epw->mode3 = 0;
                }
                else 
                {
                    epw->mode1 = 1;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                }
            }
    }
}

// 100% matching!
void bhEne09_MV10(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT *obj;
    int frm;

    switch (epw->mode3)
    {
        case 0:
            if (epw->type == 9) 
            {
                epw->type = 0;
            }
            
            bhEne_ChgMtn(epw, 0x2B, 0, 5);
            
            EXP0_I(0x18) &= 0xBFFFFFFF;
            EXP0_I(0x18) &= 0xDFFFFFFF;
            EXP0_I(0x18) |= 0x80000000;
            
            epw->way = 0x16C;
            epw->ct0 = 0;
            epw->flg2 |= 1;
            
            EXP0_I(0x18) |= 0x80;
            EXP0_I(0x18) |= 0x30;
            EXP0_I(0x18) |= 0x40000;
            EXP0_I(0x18) |= 0x8000;
            epw->px = EXP0_F(0x2C);
            epw->pz = EXP0_F(0x34);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->flg & 0x02000000)
            {
                bhEne_ChgMtn(epw, 1, 0, 0xA);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
                
                epw->mtn_md |= 0x100;
                
                epw->py = rom->grand[epw->flr_no + 2];
                
                epw->flg2 &= ~1;
                
                EXP0_I(0x18) &= ~0x80;
                EXP0_I(0x18) &= 0xFFFBFFFF;
                EXP0_I(0x18) &= ~0x30;
                
                epw->ct0 = 0xA;
                epw->mode3++;
                return;
            }
            
            frm = epw->frm_no >> 0x10;
            
            if (frm < 5)
            {
                epw->ay += epw->ayp / 5;
            }
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0] += (arm4_pos[frm].len - obj[10].pos[0]) / 4.0f;
            obj[8].pos[0] += (arm4_pos[frm].len - obj[10].pos[0]) / 4.0f;
            obj[9].pos[0] += (arm4_pos[frm].len - obj[10].pos[0]) / 4.0f;
            obj[10].pos[0] += (arm4_pos[frm].len - obj[10].pos[0]) / 4.0f;
            
            if (frm == 0x45)
            {
                epw->flr_no = bhCheckFloorNum(epw->py);
                EXP0_I(0x18) &= 0xFFFF7FFF;
            }
        
            break;
        
        case 2:
            if (--epw->ct0 < 0) 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
                epw->mtn_md &= ~0x100;
            }
    }
}

// 100% matching!
void bhEne09_MV11(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;
    int frm;

    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 0x2C, 0, 5);
            
            EXP0_I(0x18) &= 0xBFFFFFFF;
            EXP0_I(0x18) &= 0xDFFFFFFF;
            EXP0_I(0x18) |= 0x80000000;

            epw->flg2 |= 1;
            epw->way = 0x16C;
            epw->ct0 = 0;

            EXP0_I(0x18) |= 0x30;
            EXP0_I(0x18) |= 0x80;
            EXP0_I(0x18) |= 0x80000;
            
            epw->px = EXP0_F(0x2C);
            epw->pz = EXP0_F(0x34);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if (epw->flg & 0x02000000)
            {
                bhEne_ChgMtn(epw, 1, 0, 0xA);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
                
                epw->mtn_md |= 0x100;

                epw->flg2 &= ~1;
                epw->mode3++;
                
                epw->py = rom->grand[epw->flr_no + 2];
                
                EXP0_I(0x18) &= ~0x30;
                EXP0_I(0x18) &= ~0x80;
                EXP0_I(0x18) &= 0xFFF7FFFF;
                
                epw->ct0 = 0xA;
                return;
            }
            
            frm = epw->frm_no >> 0x10;
            
            if (frm < 5)
            {
                epw->ay += epw->ayp / 5;
            }
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0] += (arm4_pos2[frm].len - obj[10].pos[0]) / 4.0f;
            obj[8].pos[0] += (arm4_pos2[frm].len - obj[10].pos[0]) / 4.0f;
            obj[9].pos[0] += (arm4_pos2[frm].len - obj[10].pos[0]) / 4.0f;
            obj[10].pos[0] += (arm4_pos2[frm].len - obj[10].pos[0]) / 4.0f;

            if (frm == 30)
            {
                EXP0_I(0x18) &= 0xFFFF7FFF;
            }
            else if (frm == 45)
            {
                epw->flr_no = bhCheckFloorNum(epw->py);
            }
            
            break;
        
        case 2:
            if (--epw->ct0 < 0) 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
                epw->mtn_md &= ~0x100;
            }
    }
}

// 100% matching!
void bhEne09_MV12(BH_PWORK* epw)
{
	BH_PWORK* pl;
    O_WORK* owk;
    int rot;
    int frm;

    pl = plp;
    
    switch (epw->mode3) 
    {
        case 0:
            frm = epw->frm_no >> 0x10;
            
            if (epw->mtn_no == 0)
            {
                if ((frm < 0x14) || (frm > 0x31))
                {
                    EXP0_I(0x18) |= 0x10000000;
                }
            }
            
            bhEne_ChgMtn(epw, 0x39, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            
            epw->ay = NitenDir_ck(epw->px, epw->pz, pl->px, pl->pz);
            
            EXP0_I(0x18) |= 0x100;
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            frm = epw->frm_no >> 0x10;
            
            if (frm > 9)
            {
                EXP0_I(0x18) &= 0xEFFFFFFF;
            }
            
            if ((frm < 0x10) != 0) 
            {
                owk = pl->mlwP->owP;
                
                rot = ikou3(epw, (NJS_VECTOR *)&owk->mtx[0xC], 0x71C);
                
                if (rot == 0) 
                {
                    epw->ay = NitenDir_ck(epw->px, epw->pz, owk->mtx[0xC], owk->mtx[0xE]);
                }
                else 
                {
                    epw->ay += rot;
                }
            }
            
            if (frm == 0xF) 
            {
                if (bhEne09_PlyNageCheck(epw, plp, 0.0f) == 1) 
                {
                    pl->mode0 = 4;
                    pl->mode1 = 0;
                    pl->mode2 = 1;
                    pl->mode3 = 0;
                    pl->flg |= 0x10004;
                    pl->hp -= 0x1E;
                    
                    if (pl->hp < 0) 
                    {
                        pl->stflg |= 0x40000;
                    }
                    
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) |= 0x04400000;
                    
                    epw->flg2 |= 1;
                    
                    if (bhCdirCheck(plp->ay, epw->ay) == 0) 
                    {
                        EXP0_I(0x18) |= 0x400;
                        return;
                    }
                    
                    EXP0_I(0x18) &= ~0x400;
                }
                else 
                {
                    bhEne_ChgMtn(epw, 0x45, 0, 0);
                    
                    EXP0_I(0x18) &= 0x1FFFFFFF;
                    
                    epw->flg |= 0x40000;
                    epw->mode3++;
                }
            }
                
            break;
                
        case 2:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1))
            {
                epw->mtn_add = 0;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                EXP0_I(0x18) &= ~0x100;
            }
    }
}

// 100% matching!
void bhEne09_MV13(BH_PWORK* epw) 
{
    BH_PWORK* pl;
    O_WORK* owk;
    int rot;
    int frm;

    pl = plp;
    
    switch (epw->mode3) 
    {
        case 0:
            bhEne_ChgMtn(epw, 0x32, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->ay = NitenDir_ck(epw->px, epw->pz, pl->px, pl->pz);
            
            epw->flg &= ~0x40;
            
            EXP0_I(0x18) |= 0x100;
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            frm = epw->frm_no >> 0x10;
            
            if (frm < 0x11) 
            {
                owk = pl->mlwP->owP;
                
                rot = ikou3(epw, (NJS_VECTOR* ) &owk->mtx[0xC], 0x71C);
                
                if (rot == 0) 
                {
                    epw->ay = NitenDir_ck(epw->px, epw->pz, owk->mtx[0xC], owk->mtx[0xE]);
                }
                else 
                {
                    epw->ay += rot;
                }
            }
            
            if (frm == 0x10) 
            {
                if (bhEne09_PlyNageCheck(epw, pl, 15.0f) == 1) 
                {
                    pl->mode0 = 6;
                    pl->mode1 = 0;
                    pl->mode2 = 0;
                    pl->mode3 = 0;
                    pl->flg &= ~0x10;
                    pl->flg |= 0x10004;
                    
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) |= 0x04400000;
                    
                    epw->flg2 |= 1;
                    
                    if (bhCdirCheck(plp->ay, epw->ay) == 0) 
                    {
                        EXP0_I(0x18) |= 0x400;
                        
                        return;
                    }
                    
                    EXP0_I(0x18) &= ~0x400;
                } 
                else 
                {
                    bhEne_ChgMtn(epw, 0x33, 0, 0);

                    EXP0_I(0x18) &= 0x1FFFFFFF;
                    
                    epw->flg |= 0x40;
                    epw->mode3 = 2;
                }
            }
            
            break;
        
        case 2:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                EXP0_I(0x18) &= ~0x100;
            }
    }
}

// 100% matching!
void bhEne09_MV14(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj;
    unsigned int frm;

    switch (epw->mode3)
    {
        case 0:
            bhEne_ChgMtn(epw, 6, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            epw->way = 0x16C;
            epw->ct0 = 0;
            
            obj = epw->mlwP->objP;
            
            obj[7].pos[0]  = EXP0_F(0x0);
            obj[8].pos[0]  = EXP0_F(0x4);
            obj[9].pos[0]  = EXP0_F(0x8);
            obj[10].pos[0] = EXP0_F(0xC);
            
            EXP0_F(0x6C) = 13.0f;
            EXP0_I(0x18) |= 0x8000;
            EXP0_I(0x18) |= 0x30;
            EXP0_F(0x60) = epw->py;
            
            epw->flg2 |= 1;
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            frm = epw->frm_no >> 0x10;
            
            if (frm < 5) 
            {
                epw->ay += epw->ayp / 5;
            }
            else if (frm >= 0xFU) 
            {
                if (frm < 0x13U) 
                {
                    obj = epw->mlwP->objP;
                    
                    obj[7].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[8].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[9].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                    obj[10].pos[0] += (EXP0_F(0x6C) / 4.0f) / 4.0f;
                }
            }
            
            if (frm == 0x12) 
            {
                epw->frm_no = 0;
                epw->mtn_no = 0x15;
                epw->mode3++;
            }
            
            break;
        
        case 2:
            if (epw->flg & 0x02000000) 
            {
                epw->frm_no = 0;
                epw->mtn_no = 9;
                epw->flg &= ~0x100;
                epw->aoy = 2.0f;
                
                EXP0_I(0x18) |= 0x4000;
                
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[8].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[9].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[10].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                
                epw->mode3++;
            }
            
            break;
        
        case 3:
            if (!(epw->flg & 0x02000000)) 
            {
                obj = epw->mlwP->objP;
                
                obj[7].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[8].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[9].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                obj[10].pos[0] -= (EXP0_F(0x6C) / 4.0f) / 7.0f;
                return;
            }
            
            epw->frm_no = 0;
            epw->mtn_no = 0xC;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= 0xFFFF7FFF;
            
            epw->spd = 1.4f;
            epw->mode3++;
            
            break;
        
        case 4:
            epw->py += -0.15f * epw->ct0;
            
            if (!((EXP0_F(0x60) - 0.414835f) <= epw->py)) 
            {
                epw->py = EXP0_F(0x60) - 0.4f;
            }
            
            bhAddSpeed(epw, 0);
            
            epw->ct0++;
            
            if (epw->flg & 0x02000000) 
            {
                EXP0_I(0x18) &= ~0x80;
                EXP0_I(0x18) &= ~0x4000;
                EXP0_I(0x18) &= ~0x30;
                
                epw->flg2 &= ~1;
                epw->flg |= 0x100;
                epw->aoy = 0.0f;
                epw->mtn_no = 0x34;
                epw->frm_no = 0;
                epw->ct0 = 0;
                
                epw->py = EXP0_F(0x60);
                
                epw->mode3++;
            }
            
            break;
        
        case 5:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
            break;
    }
}

// 100% matching!
void bhEne09_NGType00(BH_PWORK* epw) 
{
    if (epw->mode3 == 0) 
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0) 
        {
            EXP0_I(0x18) |= 0x400;
        }
        else 
        {
            EXP0_I(0x18) &= ~0x400;
        }
    }
    
    bhEne09_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne09_NG00(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
        case 0:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                EXP0_I(0x18) &= ~0x100;
                EXP0_I(0x18) &= 0xFFDFFFFF;
                EXP0_I(0x18) &= 0xFFBFFFFF;
                
                epw->flg |= 0x20;
                epw->flg2 &= ~1;
                epw->mode3 += 1;
            }
        
            /* fallthrough */
        case 1:
            break;
    }
}

// 100% matching!
void bhEne09_NG01(BH_PWORK* epw)
{   
    BH_PWORK* pl;

    pl = plp;
    
    switch (epw->mode3) 
    {
        case 0:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                if (pl->hp < 0) 
                {
                    bhEne_ChgMtn(epw, 0x3B, 0, 0);
                    
                    EXP0_I(0x18) &= 0x1FFFFFFF;
                    
                    epw->flg |= 0x40000;
                    pl->mode0 = 6;

                    pl->mode3 = 4;
                }
                else 
                {
                    bhEne_ChgMtn(epw, 0x3A, 0, 0);
                    
                    EXP0_I(0x18) &= 0x1FFFFFFF;
                    
                    epw->flg |= 0x40000;

                    pl->mode3 = 2;
                }
                
                epw->flg |= 0x20;
                epw->flg2 &= ~1;
                epw->mode3++;
            }

            break;
                
        case 1:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                if (pl->hp < 0) 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) &= ~0x100;
                }
                else 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) &= ~0x100;
                }
            }
    }
}

/*

// 
// Start address: 0x1cd560
void bhEne09_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
	int i;
	int id;
	int frm;
	_anon25 ps;
	_anon25 pd;
	_anon24* owk;
	_anon25 ply_ofs_pos[8];
	// Line 4605, Address: 0x1cd560, Func Offset: 0
	// Line 4623, Address: 0x1cd57c, Func Offset: 0x1c
	// Line 4626, Address: 0x1cd5a8, Func Offset: 0x48
	// Line 4627, Address: 0x1cd5b4, Func Offset: 0x54
	// Line 4631, Address: 0x1cd5b8, Func Offset: 0x58
	// Line 4635, Address: 0x1cd5bc, Func Offset: 0x5c
	// Line 4626, Address: 0x1cd5c0, Func Offset: 0x60
	// Line 4627, Address: 0x1cd5c8, Func Offset: 0x68
	// Line 4628, Address: 0x1cd5d4, Func Offset: 0x74
	// Line 4631, Address: 0x1cd5e0, Func Offset: 0x80
	// Line 4635, Address: 0x1cd5e8, Func Offset: 0x88
	// Line 4631, Address: 0x1cd5ec, Func Offset: 0x8c
	// Line 4635, Address: 0x1cd5f8, Func Offset: 0x98
	// Line 4638, Address: 0x1cd60c, Func Offset: 0xac
	// Line 4640, Address: 0x1cd620, Func Offset: 0xc0
	// Line 4642, Address: 0x1cd628, Func Offset: 0xc8
	// Line 4641, Address: 0x1cd62c, Func Offset: 0xcc
	// Line 4642, Address: 0x1cd630, Func Offset: 0xd0
	// Line 4640, Address: 0x1cd634, Func Offset: 0xd4
	// Line 4642, Address: 0x1cd638, Func Offset: 0xd8
	// Line 4641, Address: 0x1cd63c, Func Offset: 0xdc
	// Line 4642, Address: 0x1cd640, Func Offset: 0xe0
	// Line 4640, Address: 0x1cd644, Func Offset: 0xe4
	// Line 4642, Address: 0x1cd648, Func Offset: 0xe8
	// Line 4643, Address: 0x1cd658, Func Offset: 0xf8
	// Line 4646, Address: 0x1cd660, Func Offset: 0x100
	// Line 4648, Address: 0x1cd668, Func Offset: 0x108
	// Line 4646, Address: 0x1cd670, Func Offset: 0x110
	// Line 4648, Address: 0x1cd674, Func Offset: 0x114
	// Line 4646, Address: 0x1cd678, Func Offset: 0x118
	// Line 4647, Address: 0x1cd680, Func Offset: 0x120
	// Line 4648, Address: 0x1cd684, Func Offset: 0x124
	// Line 4651, Address: 0x1cd6a0, Func Offset: 0x140
	// Line 4658, Address: 0x1cd6c0, Func Offset: 0x160
	// Line 4660, Address: 0x1cd6c4, Func Offset: 0x164
	// Line 4652, Address: 0x1cd6c8, Func Offset: 0x168
	// Line 4651, Address: 0x1cd6d4, Func Offset: 0x174
	// Line 4652, Address: 0x1cd6d8, Func Offset: 0x178
	// Line 4653, Address: 0x1cd6e0, Func Offset: 0x180
	// Line 4652, Address: 0x1cd6e8, Func Offset: 0x188
	// Line 4653, Address: 0x1cd6ec, Func Offset: 0x18c
	// Line 4661, Address: 0x1cd6f8, Func Offset: 0x198
	// Line 4670, Address: 0x1cd6fc, Func Offset: 0x19c
	// Line 4653, Address: 0x1cd700, Func Offset: 0x1a0
	// Line 4654, Address: 0x1cd704, Func Offset: 0x1a4
	// Line 4667, Address: 0x1cd70c, Func Offset: 0x1ac
	// Line 4670, Address: 0x1cd710, Func Offset: 0x1b0
	// Line 4654, Address: 0x1cd714, Func Offset: 0x1b4
	// Line 4657, Address: 0x1cd720, Func Offset: 0x1c0
	// Line 4658, Address: 0x1cd728, Func Offset: 0x1c8
	// Line 4659, Address: 0x1cd72c, Func Offset: 0x1cc
	// Line 4660, Address: 0x1cd730, Func Offset: 0x1d0
	// Line 4661, Address: 0x1cd734, Func Offset: 0x1d4
	// Line 4662, Address: 0x1cd738, Func Offset: 0x1d8
	// Line 4663, Address: 0x1cd73c, Func Offset: 0x1dc
	// Line 4664, Address: 0x1cd740, Func Offset: 0x1e0
	// Line 4667, Address: 0x1cd744, Func Offset: 0x1e4
	// Line 4670, Address: 0x1cd750, Func Offset: 0x1f0
	// Line 4673, Address: 0x1cd758, Func Offset: 0x1f8
	// Line 4676, Address: 0x1cd760, Func Offset: 0x200
	// Line 4677, Address: 0x1cd768, Func Offset: 0x208
	// Line 4673, Address: 0x1cd770, Func Offset: 0x210
	// Line 4674, Address: 0x1cd778, Func Offset: 0x218
	// Line 4675, Address: 0x1cd780, Func Offset: 0x220
	// Line 4676, Address: 0x1cd788, Func Offset: 0x228
	// Line 4679, Address: 0x1cd794, Func Offset: 0x234
	// Line 4680, Address: 0x1cd7b0, Func Offset: 0x250
	// Line 4684, Address: 0x1cd7c0, Func Offset: 0x260
	// Line 4685, Address: 0x1cd7c4, Func Offset: 0x264
	// Line 4684, Address: 0x1cd7c8, Func Offset: 0x268
	// Line 4685, Address: 0x1cd7cc, Func Offset: 0x26c
	// Line 4690, Address: 0x1cd7d4, Func Offset: 0x274
	// Line 4693, Address: 0x1cd7e0, Func Offset: 0x280
	// Line 4694, Address: 0x1cd7ec, Func Offset: 0x28c
	// Line 4695, Address: 0x1cd7f4, Func Offset: 0x294
	// Line 4698, Address: 0x1cd80c, Func Offset: 0x2ac
	// Line 4701, Address: 0x1cd818, Func Offset: 0x2b8
	// Line 4704, Address: 0x1cd824, Func Offset: 0x2c4
	// Line 4703, Address: 0x1cd828, Func Offset: 0x2c8
	// Line 4704, Address: 0x1cd82c, Func Offset: 0x2cc
	// Line 4705, Address: 0x1cd830, Func Offset: 0x2d0
	// Line 4704, Address: 0x1cd834, Func Offset: 0x2d4
	// Line 4705, Address: 0x1cd838, Func Offset: 0x2d8
	// Line 4706, Address: 0x1cd83c, Func Offset: 0x2dc
	// Line 4708, Address: 0x1cd848, Func Offset: 0x2e8
	// Line 4706, Address: 0x1cd850, Func Offset: 0x2f0
	// Line 4708, Address: 0x1cd854, Func Offset: 0x2f4
	// Line 4709, Address: 0x1cd86c, Func Offset: 0x30c
	// Line 4710, Address: 0x1cd88c, Func Offset: 0x32c
	// Line 4712, Address: 0x1cd8ac, Func Offset: 0x34c
	// Line 4716, Address: 0x1cd8b8, Func Offset: 0x358
	// Line 4721, Address: 0x1cd8bc, Func Offset: 0x35c
	// Line 4712, Address: 0x1cd8c0, Func Offset: 0x360
	// Line 4713, Address: 0x1cd8cc, Func Offset: 0x36c
	// Line 4722, Address: 0x1cd8d4, Func Offset: 0x374
	// Line 4726, Address: 0x1cd8d8, Func Offset: 0x378
	// Line 4728, Address: 0x1cd8dc, Func Offset: 0x37c
	// Line 4713, Address: 0x1cd8e0, Func Offset: 0x380
	// Line 4714, Address: 0x1cd8ec, Func Offset: 0x38c
	// Line 4715, Address: 0x1cd900, Func Offset: 0x3a0
	// Line 4716, Address: 0x1cd914, Func Offset: 0x3b4
	// Line 4717, Address: 0x1cd928, Func Offset: 0x3c8
	// Line 4718, Address: 0x1cd93c, Func Offset: 0x3dc
	// Line 4719, Address: 0x1cd950, Func Offset: 0x3f0
	// Line 4720, Address: 0x1cd964, Func Offset: 0x404
	// Line 4721, Address: 0x1cd978, Func Offset: 0x418
	// Line 4722, Address: 0x1cd98c, Func Offset: 0x42c
	// Line 4725, Address: 0x1cd9a0, Func Offset: 0x440
	// Line 4726, Address: 0x1cd9a4, Func Offset: 0x444
	// Line 4727, Address: 0x1cd9a8, Func Offset: 0x448
	// Line 4728, Address: 0x1cd9ac, Func Offset: 0x44c
	// Line 4743, Address: 0x1cd9d0, Func Offset: 0x470
	// Line 4745, Address: 0x1cd9e4, Func Offset: 0x484
	// Line 4748, Address: 0x1cd9f0, Func Offset: 0x490
	// Line 4750, Address: 0x1cda20, Func Offset: 0x4c0
	// Line 4753, Address: 0x1cda24, Func Offset: 0x4c4
	// Line 4754, Address: 0x1cda30, Func Offset: 0x4d0
	// Line 4756, Address: 0x1cda38, Func Offset: 0x4d8
	// Line 4753, Address: 0x1cda3c, Func Offset: 0x4dc
	// Line 4757, Address: 0x1cda40, Func Offset: 0x4e0
	// Line 4753, Address: 0x1cda44, Func Offset: 0x4e4
	// Line 4754, Address: 0x1cda4c, Func Offset: 0x4ec
	// Line 4755, Address: 0x1cda5c, Func Offset: 0x4fc
	// Line 4756, Address: 0x1cda68, Func Offset: 0x508
	// Line 4759, Address: 0x1cda6c, Func Offset: 0x50c
	// Line 4762, Address: 0x1cda74, Func Offset: 0x514
	// Line 4765, Address: 0x1cda84, Func Offset: 0x524
	// Line 4766, Address: 0x1cda8c, Func Offset: 0x52c
	// Line 4776, Address: 0x1cda94, Func Offset: 0x534
	// Line 4765, Address: 0x1cda98, Func Offset: 0x538
	// Line 4771, Address: 0x1cdaa8, Func Offset: 0x548
	// Line 4773, Address: 0x1cdaac, Func Offset: 0x54c
	// Line 4774, Address: 0x1cdab0, Func Offset: 0x550
	// Line 4765, Address: 0x1cdab4, Func Offset: 0x554
	// Line 4766, Address: 0x1cdac4, Func Offset: 0x564
	// Line 4776, Address: 0x1cdac8, Func Offset: 0x568
	// Line 4766, Address: 0x1cdacc, Func Offset: 0x56c
	// Line 4767, Address: 0x1cdad4, Func Offset: 0x574
	// Line 4768, Address: 0x1cdae0, Func Offset: 0x580
	// Line 4771, Address: 0x1cdae4, Func Offset: 0x584
	// Line 4773, Address: 0x1cdaf0, Func Offset: 0x590
	// Line 4774, Address: 0x1cdafc, Func Offset: 0x59c
	// Line 4776, Address: 0x1cdb00, Func Offset: 0x5a0
	// Line 4780, Address: 0x1cdb10, Func Offset: 0x5b0
	// Func End, Address: 0x1cdb2c, Func Offset: 0x5cc
}

// 
// Start address: 0x1cdb30
void bhEne09_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
	int i;
	int id;
	int frm;
	_anon25 ps;
	_anon24* owk;
	_anon25 ply_ofs_pos[8];
	// Line 5072, Address: 0x1cdb30, Func Offset: 0
	// Line 5087, Address: 0x1cdb44, Func Offset: 0x14
	// Line 5090, Address: 0x1cdb74, Func Offset: 0x44
	// Line 5091, Address: 0x1cdb80, Func Offset: 0x50
	// Line 5095, Address: 0x1cdb84, Func Offset: 0x54
	// Line 5099, Address: 0x1cdb88, Func Offset: 0x58
	// Line 5090, Address: 0x1cdb8c, Func Offset: 0x5c
	// Line 5091, Address: 0x1cdb94, Func Offset: 0x64
	// Line 5092, Address: 0x1cdba0, Func Offset: 0x70
	// Line 5095, Address: 0x1cdbac, Func Offset: 0x7c
	// Line 5099, Address: 0x1cdbb4, Func Offset: 0x84
	// Line 5095, Address: 0x1cdbb8, Func Offset: 0x88
	// Line 5099, Address: 0x1cdbc4, Func Offset: 0x94
	// Line 5102, Address: 0x1cdbd8, Func Offset: 0xa8
	// Line 5104, Address: 0x1cdbec, Func Offset: 0xbc
	// Line 5106, Address: 0x1cdbf4, Func Offset: 0xc4
	// Line 5105, Address: 0x1cdbf8, Func Offset: 0xc8
	// Line 5106, Address: 0x1cdbfc, Func Offset: 0xcc
	// Line 5104, Address: 0x1cdc00, Func Offset: 0xd0
	// Line 5106, Address: 0x1cdc04, Func Offset: 0xd4
	// Line 5105, Address: 0x1cdc08, Func Offset: 0xd8
	// Line 5106, Address: 0x1cdc0c, Func Offset: 0xdc
	// Line 5104, Address: 0x1cdc10, Func Offset: 0xe0
	// Line 5106, Address: 0x1cdc14, Func Offset: 0xe4
	// Line 5107, Address: 0x1cdc28, Func Offset: 0xf8
	// Line 5110, Address: 0x1cdc30, Func Offset: 0x100
	// Line 5112, Address: 0x1cdc38, Func Offset: 0x108
	// Line 5110, Address: 0x1cdc40, Func Offset: 0x110
	// Line 5112, Address: 0x1cdc44, Func Offset: 0x114
	// Line 5110, Address: 0x1cdc48, Func Offset: 0x118
	// Line 5111, Address: 0x1cdc50, Func Offset: 0x120
	// Line 5112, Address: 0x1cdc54, Func Offset: 0x124
	// Line 5115, Address: 0x1cdc70, Func Offset: 0x140
	// Line 5123, Address: 0x1cdc90, Func Offset: 0x160
	// Line 5125, Address: 0x1cdc94, Func Offset: 0x164
	// Line 5116, Address: 0x1cdc98, Func Offset: 0x168
	// Line 5115, Address: 0x1cdca4, Func Offset: 0x174
	// Line 5116, Address: 0x1cdca8, Func Offset: 0x178
	// Line 5117, Address: 0x1cdcb0, Func Offset: 0x180
	// Line 5116, Address: 0x1cdcb8, Func Offset: 0x188
	// Line 5117, Address: 0x1cdcbc, Func Offset: 0x18c
	// Line 5126, Address: 0x1cdcc8, Func Offset: 0x198
	// Line 5136, Address: 0x1cdccc, Func Offset: 0x19c
	// Line 5117, Address: 0x1cdcd0, Func Offset: 0x1a0
	// Line 5119, Address: 0x1cdcd4, Func Offset: 0x1a4
	// Line 5133, Address: 0x1cdcdc, Func Offset: 0x1ac
	// Line 5136, Address: 0x1cdce0, Func Offset: 0x1b0
	// Line 5119, Address: 0x1cdce4, Func Offset: 0x1b4
	// Line 5122, Address: 0x1cdcf0, Func Offset: 0x1c0
	// Line 5123, Address: 0x1cdcf8, Func Offset: 0x1c8
	// Line 5124, Address: 0x1cdcfc, Func Offset: 0x1cc
	// Line 5125, Address: 0x1cdd00, Func Offset: 0x1d0
	// Line 5126, Address: 0x1cdd04, Func Offset: 0x1d4
	// Line 5127, Address: 0x1cdd08, Func Offset: 0x1d8
	// Line 5128, Address: 0x1cdd0c, Func Offset: 0x1dc
	// Line 5129, Address: 0x1cdd10, Func Offset: 0x1e0
	// Line 5130, Address: 0x1cdd14, Func Offset: 0x1e4
	// Line 5133, Address: 0x1cdd20, Func Offset: 0x1f0
	// Line 5136, Address: 0x1cdd2c, Func Offset: 0x1fc
	// Line 5139, Address: 0x1cdd34, Func Offset: 0x204
	// Line 5142, Address: 0x1cdd3c, Func Offset: 0x20c
	// Line 5143, Address: 0x1cdd44, Func Offset: 0x214
	// Line 5139, Address: 0x1cdd4c, Func Offset: 0x21c
	// Line 5140, Address: 0x1cdd54, Func Offset: 0x224
	// Line 5141, Address: 0x1cdd5c, Func Offset: 0x22c
	// Line 5142, Address: 0x1cdd64, Func Offset: 0x234
	// Line 5145, Address: 0x1cdd70, Func Offset: 0x240
	// Line 5146, Address: 0x1cdd8c, Func Offset: 0x25c
	// Line 5150, Address: 0x1cdd9c, Func Offset: 0x26c
	// Line 5154, Address: 0x1cdda4, Func Offset: 0x274
	// Line 5155, Address: 0x1cddb8, Func Offset: 0x288
	// Line 5157, Address: 0x1cdde4, Func Offset: 0x2b4
	// Line 5159, Address: 0x1cde0c, Func Offset: 0x2dc
	// Line 5160, Address: 0x1cde10, Func Offset: 0x2e0
	// Line 5161, Address: 0x1cde14, Func Offset: 0x2e4
	// Line 5162, Address: 0x1cde1c, Func Offset: 0x2ec
	// Line 5165, Address: 0x1cde24, Func Offset: 0x2f4
	// Line 5167, Address: 0x1cde38, Func Offset: 0x308
	// Line 5171, Address: 0x1cde50, Func Offset: 0x320
	// Line 5174, Address: 0x1cde60, Func Offset: 0x330
	// Line 5175, Address: 0x1cde68, Func Offset: 0x338
	// Line 5174, Address: 0x1cde6c, Func Offset: 0x33c
	// Line 5175, Address: 0x1cde70, Func Offset: 0x340
	// Line 5178, Address: 0x1cde74, Func Offset: 0x344
	// Line 5174, Address: 0x1cde78, Func Offset: 0x348
	// Line 5182, Address: 0x1cde84, Func Offset: 0x354
	// Line 5176, Address: 0x1cde8c, Func Offset: 0x35c
	// Line 5184, Address: 0x1cde90, Func Offset: 0x360
	// Line 5174, Address: 0x1cde94, Func Offset: 0x364
	// Line 5175, Address: 0x1cdea4, Func Offset: 0x374
	// Line 5176, Address: 0x1cdeb0, Func Offset: 0x380
	// Line 5177, Address: 0x1cdebc, Func Offset: 0x38c
	// Line 5178, Address: 0x1cdec8, Func Offset: 0x398
	// Line 5179, Address: 0x1cded4, Func Offset: 0x3a4
	// Line 5180, Address: 0x1cded8, Func Offset: 0x3a8
	// Line 5182, Address: 0x1cdee0, Func Offset: 0x3b0
	// Line 5186, Address: 0x1cdef0, Func Offset: 0x3c0
	// Line 5189, Address: 0x1cdef8, Func Offset: 0x3c8
	// Line 5190, Address: 0x1cdf0c, Func Offset: 0x3dc
	// Line 5192, Address: 0x1cdf38, Func Offset: 0x408
	// Line 5193, Address: 0x1cdf60, Func Offset: 0x430
	// Line 5194, Address: 0x1cdf64, Func Offset: 0x434
	// Line 5196, Address: 0x1cdf68, Func Offset: 0x438
	// Line 5200, Address: 0x1cdf70, Func Offset: 0x440
	// Line 5203, Address: 0x1cdf78, Func Offset: 0x448
	// Line 5196, Address: 0x1cdf7c, Func Offset: 0x44c
	// Line 5199, Address: 0x1cdf84, Func Offset: 0x454
	// Line 5203, Address: 0x1cdf88, Func Offset: 0x458
	// Line 5199, Address: 0x1cdf8c, Func Offset: 0x45c
	// Line 5200, Address: 0x1cdf94, Func Offset: 0x464
	// Line 5203, Address: 0x1cdfa0, Func Offset: 0x470
	// Line 5204, Address: 0x1cdfa8, Func Offset: 0x478
	// Line 5205, Address: 0x1cdfb0, Func Offset: 0x480
	// Line 5210, Address: 0x1cdfbc, Func Offset: 0x48c
	// Line 5208, Address: 0x1cdfcc, Func Offset: 0x49c
	// Line 5210, Address: 0x1cdfd0, Func Offset: 0x4a0
	// Line 5212, Address: 0x1cdff0, Func Offset: 0x4c0
	// Line 5214, Address: 0x1cdffc, Func Offset: 0x4cc
	// Line 5215, Address: 0x1ce008, Func Offset: 0x4d8
	// Line 5218, Address: 0x1ce010, Func Offset: 0x4e0
	// Line 5220, Address: 0x1ce020, Func Offset: 0x4f0
	// Line 5223, Address: 0x1ce028, Func Offset: 0x4f8
	// Line 5226, Address: 0x1ce03c, Func Offset: 0x50c
	// Line 5228, Address: 0x1ce06c, Func Offset: 0x53c
	// Line 5229, Address: 0x1ce090, Func Offset: 0x560
	// Line 5232, Address: 0x1ce098, Func Offset: 0x568
	// Line 5235, Address: 0x1ce0bc, Func Offset: 0x58c
	// Line 5238, Address: 0x1ce0ec, Func Offset: 0x5bc
	// Line 5240, Address: 0x1ce0f0, Func Offset: 0x5c0
	// Line 5241, Address: 0x1ce0f4, Func Offset: 0x5c4
	// Line 5240, Address: 0x1ce0f8, Func Offset: 0x5c8
	// Line 5241, Address: 0x1ce100, Func Offset: 0x5d0
	// Line 5245, Address: 0x1ce10c, Func Offset: 0x5dc
	// Func End, Address: 0x1ce124, Func Offset: 0x5f4
}

// 
// Start address: 0x1ce130
int bhEne09_PlyNageCheck(BH_PWORK* epw, BH_PWORK* pl, float h)
{
	int rot;
	_anon25 pos2;
	_anon25 pos;
	_anon50 at;
	_anon4* hp2;
	_anon4* hp;
	// Line 5267, Address: 0x1ce130, Func Offset: 0
	// Line 5273, Address: 0x1ce144, Func Offset: 0x14
	// Line 5281, Address: 0x1ce148, Func Offset: 0x18
	// Line 5273, Address: 0x1ce150, Func Offset: 0x20
	// Line 5274, Address: 0x1ce154, Func Offset: 0x24
	// Line 5275, Address: 0x1ce160, Func Offset: 0x30
	// Line 5276, Address: 0x1ce168, Func Offset: 0x38
	// Line 5277, Address: 0x1ce170, Func Offset: 0x40
	// Line 5278, Address: 0x1ce17c, Func Offset: 0x4c
	// Line 5281, Address: 0x1ce184, Func Offset: 0x54
	// Line 5286, Address: 0x1ce1c0, Func Offset: 0x90
	// Line 5287, Address: 0x1ce1e0, Func Offset: 0xb0
	// Line 5289, Address: 0x1ce1e8, Func Offset: 0xb8
	// Line 5291, Address: 0x1ce204, Func Offset: 0xd4
	// Line 5292, Address: 0x1ce210, Func Offset: 0xe0
	// Line 5291, Address: 0x1ce218, Func Offset: 0xe8
	// Line 5293, Address: 0x1ce21c, Func Offset: 0xec
	// Line 5292, Address: 0x1ce220, Func Offset: 0xf0
	// Line 5293, Address: 0x1ce224, Func Offset: 0xf4
	// Line 5292, Address: 0x1ce22c, Func Offset: 0xfc
	// Line 5293, Address: 0x1ce230, Func Offset: 0x100
	// Line 5292, Address: 0x1ce234, Func Offset: 0x104
	// Line 5293, Address: 0x1ce238, Func Offset: 0x108
	// Line 5300, Address: 0x1ce248, Func Offset: 0x118
	// Line 5302, Address: 0x1ce258, Func Offset: 0x128
	// Line 5307, Address: 0x1ce260, Func Offset: 0x130
	// Line 5308, Address: 0x1ce270, Func Offset: 0x140
	// Line 5309, Address: 0x1ce27c, Func Offset: 0x14c
	// Line 5308, Address: 0x1ce280, Func Offset: 0x150
	// Line 5309, Address: 0x1ce284, Func Offset: 0x154
	// Line 5310, Address: 0x1ce28c, Func Offset: 0x15c
	// Line 5309, Address: 0x1ce290, Func Offset: 0x160
	// Line 5310, Address: 0x1ce294, Func Offset: 0x164
	// Line 5311, Address: 0x1ce29c, Func Offset: 0x16c
	// Line 5310, Address: 0x1ce2a0, Func Offset: 0x170
	// Line 5311, Address: 0x1ce2a4, Func Offset: 0x174
	// Line 5315, Address: 0x1ce2b0, Func Offset: 0x180
	// Line 5316, Address: 0x1ce2b8, Func Offset: 0x188
	// Line 5317, Address: 0x1ce2bc, Func Offset: 0x18c
	// Line 5315, Address: 0x1ce2c0, Func Offset: 0x190
	// Line 5316, Address: 0x1ce2c4, Func Offset: 0x194
	// Line 5315, Address: 0x1ce2c8, Func Offset: 0x198
	// Line 5316, Address: 0x1ce2d0, Func Offset: 0x1a0
	// Line 5317, Address: 0x1ce2d8, Func Offset: 0x1a8
	// Line 5318, Address: 0x1ce2e4, Func Offset: 0x1b4
	// Line 5319, Address: 0x1ce2f0, Func Offset: 0x1c0
	// Line 5321, Address: 0x1ce2fc, Func Offset: 0x1cc
	// Line 5319, Address: 0x1ce300, Func Offset: 0x1d0
	// Line 5321, Address: 0x1ce308, Func Offset: 0x1d8
	// Line 5322, Address: 0x1ce320, Func Offset: 0x1f0
	// Line 5323, Address: 0x1ce334, Func Offset: 0x204
	// Line 5324, Address: 0x1ce350, Func Offset: 0x220
	// Line 5326, Address: 0x1ce358, Func Offset: 0x228
	// Line 5329, Address: 0x1ce360, Func Offset: 0x230
	// Line 5332, Address: 0x1ce370, Func Offset: 0x240
	// Line 5333, Address: 0x1ce378, Func Offset: 0x248
	// Line 5338, Address: 0x1ce380, Func Offset: 0x250
	// Line 5339, Address: 0x1ce384, Func Offset: 0x254
	// Func End, Address: 0x1ce39c, Func Offset: 0x26c
}

// 
// Start address: 0x1ce3a0
void bhEne09_DGType00(BH_PWORK* epw)
{
	// Line 5359, Address: 0x1ce3a0, Func Offset: 0
	// Func End, Address: 0x1ce3c0, Func Offset: 0x20
}

// 
// Start address: 0x1ce3c0
void bhEne09_DG00(BH_PWORK* epw)
{
	int mtn_no;
	npobj* obj;
	// Line 5381, Address: 0x1ce3c0, Func Offset: 0
	// Line 5386, Address: 0x1ce3d0, Func Offset: 0x10
	// Line 5392, Address: 0x1ce3f0, Func Offset: 0x30
	// Line 5394, Address: 0x1ce408, Func Offset: 0x48
	// Line 5392, Address: 0x1ce40c, Func Offset: 0x4c
	// Line 5396, Address: 0x1ce418, Func Offset: 0x58
	// Line 5392, Address: 0x1ce41c, Func Offset: 0x5c
	// Line 5397, Address: 0x1ce420, Func Offset: 0x60
	// Line 5392, Address: 0x1ce424, Func Offset: 0x64
	// Line 5394, Address: 0x1ce428, Func Offset: 0x68
	// Line 5395, Address: 0x1ce42c, Func Offset: 0x6c
	// Line 5396, Address: 0x1ce430, Func Offset: 0x70
	// Line 5397, Address: 0x1ce440, Func Offset: 0x80
	// Line 5399, Address: 0x1ce44c, Func Offset: 0x8c
	// Line 5402, Address: 0x1ce460, Func Offset: 0xa0
	// Line 5403, Address: 0x1ce46c, Func Offset: 0xac
	// Line 5405, Address: 0x1ce474, Func Offset: 0xb4
	// Line 5406, Address: 0x1ce478, Func Offset: 0xb8
	// Line 5410, Address: 0x1ce480, Func Offset: 0xc0
	// Line 5411, Address: 0x1ce48c, Func Offset: 0xcc
	// Line 5413, Address: 0x1ce494, Func Offset: 0xd4
	// Line 5415, Address: 0x1ce498, Func Offset: 0xd8
	// Line 5416, Address: 0x1ce4ac, Func Offset: 0xec
	// Line 5415, Address: 0x1ce4b0, Func Offset: 0xf0
	// Line 5416, Address: 0x1ce4c0, Func Offset: 0x100
	// Line 5419, Address: 0x1ce4cc, Func Offset: 0x10c
	// Line 5420, Address: 0x1ce4d0, Func Offset: 0x110
	// Line 5419, Address: 0x1ce4d4, Func Offset: 0x114
	// Line 5420, Address: 0x1ce4d8, Func Offset: 0x118
	// Line 5421, Address: 0x1ce4e8, Func Offset: 0x128
	// Line 5422, Address: 0x1ce4fc, Func Offset: 0x13c
	// Line 5423, Address: 0x1ce510, Func Offset: 0x150
	// Line 5424, Address: 0x1ce524, Func Offset: 0x164
	// Line 5428, Address: 0x1ce530, Func Offset: 0x170
	// Line 5430, Address: 0x1ce544, Func Offset: 0x184
	// Line 5432, Address: 0x1ce550, Func Offset: 0x190
	// Line 5430, Address: 0x1ce554, Func Offset: 0x194
	// Line 5432, Address: 0x1ce560, Func Offset: 0x1a0
	// Line 5436, Address: 0x1ce5ac, Func Offset: 0x1ec
	// Line 5438, Address: 0x1ce5b4, Func Offset: 0x1f4
	// Line 5437, Address: 0x1ce5b8, Func Offset: 0x1f8
	// Line 5438, Address: 0x1ce5bc, Func Offset: 0x1fc
	// Line 5440, Address: 0x1ce5c0, Func Offset: 0x200
	// Line 5443, Address: 0x1ce5c8, Func Offset: 0x208
	// Line 5444, Address: 0x1ce5d0, Func Offset: 0x210
	// Line 5445, Address: 0x1ce5d4, Func Offset: 0x214
	// Line 5446, Address: 0x1ce5d8, Func Offset: 0x218
	// Line 5451, Address: 0x1ce5dc, Func Offset: 0x21c
	// Line 5452, Address: 0x1ce5e0, Func Offset: 0x220
	// Line 5451, Address: 0x1ce5e4, Func Offset: 0x224
	// Line 5452, Address: 0x1ce5e8, Func Offset: 0x228
	// Line 5454, Address: 0x1ce5f4, Func Offset: 0x234
	// Line 5455, Address: 0x1ce614, Func Offset: 0x254
	// Line 5456, Address: 0x1ce62c, Func Offset: 0x26c
	// Line 5457, Address: 0x1ce644, Func Offset: 0x284
	// Line 5458, Address: 0x1ce65c, Func Offset: 0x29c
	// Line 5461, Address: 0x1ce664, Func Offset: 0x2a4
	// Line 5462, Address: 0x1ce670, Func Offset: 0x2b0
	// Line 5463, Address: 0x1ce67c, Func Offset: 0x2bc
	// Line 5464, Address: 0x1ce688, Func Offset: 0x2c8
	// Line 5466, Address: 0x1ce694, Func Offset: 0x2d4
	// Line 5469, Address: 0x1ce6a0, Func Offset: 0x2e0
	// Func End, Address: 0x1ce6b0, Func Offset: 0x2f0
}

// 
// Start address: 0x1ce6b0
void bhEne09_DG01(BH_PWORK* epw)
{
	int mtn_no;
	npobj* obj;
	// Line 5489, Address: 0x1ce6b0, Func Offset: 0
	// Line 5494, Address: 0x1ce6c0, Func Offset: 0x10
	// Line 5500, Address: 0x1ce6e0, Func Offset: 0x30
	// Line 5502, Address: 0x1ce6f8, Func Offset: 0x48
	// Line 5500, Address: 0x1ce6fc, Func Offset: 0x4c
	// Line 5504, Address: 0x1ce708, Func Offset: 0x58
	// Line 5500, Address: 0x1ce70c, Func Offset: 0x5c
	// Line 5505, Address: 0x1ce710, Func Offset: 0x60
	// Line 5500, Address: 0x1ce714, Func Offset: 0x64
	// Line 5502, Address: 0x1ce718, Func Offset: 0x68
	// Line 5503, Address: 0x1ce71c, Func Offset: 0x6c
	// Line 5504, Address: 0x1ce720, Func Offset: 0x70
	// Line 5505, Address: 0x1ce730, Func Offset: 0x80
	// Line 5507, Address: 0x1ce73c, Func Offset: 0x8c
	// Line 5510, Address: 0x1ce750, Func Offset: 0xa0
	// Line 5511, Address: 0x1ce75c, Func Offset: 0xac
	// Line 5513, Address: 0x1ce764, Func Offset: 0xb4
	// Line 5514, Address: 0x1ce768, Func Offset: 0xb8
	// Line 5518, Address: 0x1ce770, Func Offset: 0xc0
	// Line 5519, Address: 0x1ce77c, Func Offset: 0xcc
	// Line 5521, Address: 0x1ce784, Func Offset: 0xd4
	// Line 5523, Address: 0x1ce788, Func Offset: 0xd8
	// Line 5524, Address: 0x1ce79c, Func Offset: 0xec
	// Line 5523, Address: 0x1ce7a0, Func Offset: 0xf0
	// Line 5524, Address: 0x1ce7b0, Func Offset: 0x100
	// Line 5527, Address: 0x1ce7bc, Func Offset: 0x10c
	// Line 5528, Address: 0x1ce7c0, Func Offset: 0x110
	// Line 5527, Address: 0x1ce7c4, Func Offset: 0x114
	// Line 5528, Address: 0x1ce7c8, Func Offset: 0x118
	// Line 5529, Address: 0x1ce7d8, Func Offset: 0x128
	// Line 5530, Address: 0x1ce7ec, Func Offset: 0x13c
	// Line 5531, Address: 0x1ce800, Func Offset: 0x150
	// Line 5532, Address: 0x1ce814, Func Offset: 0x164
	// Line 5535, Address: 0x1ce820, Func Offset: 0x170
	// Line 5539, Address: 0x1ce87c, Func Offset: 0x1cc
	// Line 5540, Address: 0x1ce888, Func Offset: 0x1d8
	// Line 5539, Address: 0x1ce88c, Func Offset: 0x1dc
	// Line 5540, Address: 0x1ce898, Func Offset: 0x1e8
	// Line 5544, Address: 0x1ce8e4, Func Offset: 0x234
	// Line 5546, Address: 0x1ce8ec, Func Offset: 0x23c
	// Line 5545, Address: 0x1ce8f0, Func Offset: 0x240
	// Line 5546, Address: 0x1ce8f4, Func Offset: 0x244
	// Line 5548, Address: 0x1ce8f8, Func Offset: 0x248
	// Line 5551, Address: 0x1ce900, Func Offset: 0x250
	// Line 5552, Address: 0x1ce908, Func Offset: 0x258
	// Line 5553, Address: 0x1ce90c, Func Offset: 0x25c
	// Line 5554, Address: 0x1ce910, Func Offset: 0x260
	// Line 5558, Address: 0x1ce914, Func Offset: 0x264
	// Line 5559, Address: 0x1ce918, Func Offset: 0x268
	// Line 5558, Address: 0x1ce91c, Func Offset: 0x26c
	// Line 5559, Address: 0x1ce920, Func Offset: 0x270
	// Line 5561, Address: 0x1ce92c, Func Offset: 0x27c
	// Line 5562, Address: 0x1ce94c, Func Offset: 0x29c
	// Line 5563, Address: 0x1ce964, Func Offset: 0x2b4
	// Line 5564, Address: 0x1ce97c, Func Offset: 0x2cc
	// Line 5565, Address: 0x1ce994, Func Offset: 0x2e4
	// Line 5568, Address: 0x1ce99c, Func Offset: 0x2ec
	// Line 5569, Address: 0x1ce9a8, Func Offset: 0x2f8
	// Line 5570, Address: 0x1ce9b4, Func Offset: 0x304
	// Line 5571, Address: 0x1ce9c0, Func Offset: 0x310
	// Line 5573, Address: 0x1ce9cc, Func Offset: 0x31c
	// Line 5576, Address: 0x1ce9d8, Func Offset: 0x328
	// Func End, Address: 0x1ce9e8, Func Offset: 0x338
}

// 
// Start address: 0x1ce9f0
void bhEne09_DG02(BH_PWORK* epw)
{
	int mtn_no;
	npobj* obj;
	// Line 5597, Address: 0x1ce9f0, Func Offset: 0
	// Line 5602, Address: 0x1cea00, Func Offset: 0x10
	// Line 5608, Address: 0x1cea20, Func Offset: 0x30
	// Line 5610, Address: 0x1cea38, Func Offset: 0x48
	// Line 5608, Address: 0x1cea3c, Func Offset: 0x4c
	// Line 5612, Address: 0x1cea48, Func Offset: 0x58
	// Line 5608, Address: 0x1cea4c, Func Offset: 0x5c
	// Line 5613, Address: 0x1cea50, Func Offset: 0x60
	// Line 5608, Address: 0x1cea54, Func Offset: 0x64
	// Line 5610, Address: 0x1cea58, Func Offset: 0x68
	// Line 5611, Address: 0x1cea5c, Func Offset: 0x6c
	// Line 5612, Address: 0x1cea60, Func Offset: 0x70
	// Line 5613, Address: 0x1cea70, Func Offset: 0x80
	// Line 5615, Address: 0x1cea7c, Func Offset: 0x8c
	// Line 5618, Address: 0x1cea90, Func Offset: 0xa0
	// Line 5619, Address: 0x1cea9c, Func Offset: 0xac
	// Line 5621, Address: 0x1ceaa4, Func Offset: 0xb4
	// Line 5622, Address: 0x1ceaa8, Func Offset: 0xb8
	// Line 5626, Address: 0x1ceab0, Func Offset: 0xc0
	// Line 5627, Address: 0x1ceabc, Func Offset: 0xcc
	// Line 5629, Address: 0x1ceac4, Func Offset: 0xd4
	// Line 5631, Address: 0x1ceac8, Func Offset: 0xd8
	// Line 5632, Address: 0x1ceadc, Func Offset: 0xec
	// Line 5631, Address: 0x1ceae0, Func Offset: 0xf0
	// Line 5632, Address: 0x1ceaf0, Func Offset: 0x100
	// Line 5635, Address: 0x1ceafc, Func Offset: 0x10c
	// Line 5636, Address: 0x1ceb00, Func Offset: 0x110
	// Line 5635, Address: 0x1ceb04, Func Offset: 0x114
	// Line 5636, Address: 0x1ceb08, Func Offset: 0x118
	// Line 5637, Address: 0x1ceb18, Func Offset: 0x128
	// Line 5638, Address: 0x1ceb2c, Func Offset: 0x13c
	// Line 5639, Address: 0x1ceb40, Func Offset: 0x150
	// Line 5640, Address: 0x1ceb54, Func Offset: 0x164
	// Line 5644, Address: 0x1ceb60, Func Offset: 0x170
	// Line 5649, Address: 0x1cebbc, Func Offset: 0x1cc
	// Line 5650, Address: 0x1cebc8, Func Offset: 0x1d8
	// Line 5649, Address: 0x1cebcc, Func Offset: 0x1dc
	// Line 5650, Address: 0x1cebd8, Func Offset: 0x1e8
	// Line 5654, Address: 0x1cec24, Func Offset: 0x234
	// Line 5656, Address: 0x1cec2c, Func Offset: 0x23c
	// Line 5655, Address: 0x1cec30, Func Offset: 0x240
	// Line 5656, Address: 0x1cec34, Func Offset: 0x244
	// Line 5658, Address: 0x1cec38, Func Offset: 0x248
	// Line 5661, Address: 0x1cec40, Func Offset: 0x250
	// Line 5662, Address: 0x1cec48, Func Offset: 0x258
	// Line 5663, Address: 0x1cec4c, Func Offset: 0x25c
	// Line 5664, Address: 0x1cec50, Func Offset: 0x260
	// Line 5668, Address: 0x1cec54, Func Offset: 0x264
	// Line 5669, Address: 0x1cec58, Func Offset: 0x268
	// Line 5668, Address: 0x1cec5c, Func Offset: 0x26c
	// Line 5669, Address: 0x1cec60, Func Offset: 0x270
	// Line 5671, Address: 0x1cec6c, Func Offset: 0x27c
	// Line 5672, Address: 0x1cec8c, Func Offset: 0x29c
	// Line 5673, Address: 0x1ceca4, Func Offset: 0x2b4
	// Line 5674, Address: 0x1cecbc, Func Offset: 0x2cc
	// Line 5675, Address: 0x1cecd4, Func Offset: 0x2e4
	// Line 5678, Address: 0x1cecdc, Func Offset: 0x2ec
	// Line 5679, Address: 0x1cece8, Func Offset: 0x2f8
	// Line 5680, Address: 0x1cecf4, Func Offset: 0x304
	// Line 5681, Address: 0x1ced00, Func Offset: 0x310
	// Line 5683, Address: 0x1ced0c, Func Offset: 0x31c
	// Line 5686, Address: 0x1ced18, Func Offset: 0x328
	// Func End, Address: 0x1ced28, Func Offset: 0x338
}

// 
// Start address: 0x1ced30
void bhEne09_DG03(BH_PWORK* epw)
{
	int frm;
	int ang;
	_anon25 pos;
	npobj* obj;
	// Line 5707, Address: 0x1ced30, Func Offset: 0
	// Line 5714, Address: 0x1ced40, Func Offset: 0x10
	// Line 5718, Address: 0x1ced60, Func Offset: 0x30
	// Line 5722, Address: 0x1ced68, Func Offset: 0x38
	// Line 5723, Address: 0x1ced6c, Func Offset: 0x3c
	// Line 5718, Address: 0x1ced70, Func Offset: 0x40
	// Line 5724, Address: 0x1ced74, Func Offset: 0x44
	// Line 5725, Address: 0x1ced78, Func Offset: 0x48
	// Line 5728, Address: 0x1ced7c, Func Offset: 0x4c
	// Line 5718, Address: 0x1ced80, Func Offset: 0x50
	// Line 5719, Address: 0x1ced88, Func Offset: 0x58
	// Line 5733, Address: 0x1ced8c, Func Offset: 0x5c
	// Line 5719, Address: 0x1ced9c, Func Offset: 0x6c
	// Line 5722, Address: 0x1ceda8, Func Offset: 0x78
	// Line 5723, Address: 0x1cedb8, Func Offset: 0x88
	// Line 5724, Address: 0x1cedc8, Func Offset: 0x98
	// Line 5725, Address: 0x1cedd4, Func Offset: 0xa4
	// Line 5728, Address: 0x1cede0, Func Offset: 0xb0
	// Line 5733, Address: 0x1cedec, Func Offset: 0xbc
	// Line 5736, Address: 0x1cee08, Func Offset: 0xd8
	// Line 5738, Address: 0x1cee1c, Func Offset: 0xec
	// Line 5739, Address: 0x1cee3c, Func Offset: 0x10c
	// Line 5742, Address: 0x1cee44, Func Offset: 0x114
	// Line 5747, Address: 0x1cee68, Func Offset: 0x138
	// Line 5748, Address: 0x1cee6c, Func Offset: 0x13c
	// Line 5747, Address: 0x1cee70, Func Offset: 0x140
	// Line 5748, Address: 0x1cee74, Func Offset: 0x144
	// Line 5749, Address: 0x1cee84, Func Offset: 0x154
	// Line 5750, Address: 0x1cee98, Func Offset: 0x168
	// Line 5751, Address: 0x1ceeac, Func Offset: 0x17c
	// Line 5754, Address: 0x1ceec0, Func Offset: 0x190
	// Line 5755, Address: 0x1ceee4, Func Offset: 0x1b4
	// Line 5757, Address: 0x1ceeec, Func Offset: 0x1bc
	// Line 5758, Address: 0x1ceef0, Func Offset: 0x1c0
	// Line 5759, Address: 0x1ceef8, Func Offset: 0x1c8
	// Line 5762, Address: 0x1cef00, Func Offset: 0x1d0
	// Line 5763, Address: 0x1cef08, Func Offset: 0x1d8
	// Line 5765, Address: 0x1cef14, Func Offset: 0x1e4
	// Line 5766, Address: 0x1cef1c, Func Offset: 0x1ec
	// Line 5765, Address: 0x1cef20, Func Offset: 0x1f0
	// Line 5766, Address: 0x1cef28, Func Offset: 0x1f8
	// Line 5767, Address: 0x1cef3c, Func Offset: 0x20c
	// Line 5770, Address: 0x1cef4c, Func Offset: 0x21c
	// Line 5772, Address: 0x1cef74, Func Offset: 0x244
	// Line 5774, Address: 0x1cef78, Func Offset: 0x248
	// Line 5777, Address: 0x1cef84, Func Offset: 0x254
	// Line 5778, Address: 0x1cef90, Func Offset: 0x260
	// Line 5777, Address: 0x1cef94, Func Offset: 0x264
	// Line 5778, Address: 0x1cefa0, Func Offset: 0x270
	// Line 5779, Address: 0x1cefb0, Func Offset: 0x280
	// Line 5782, Address: 0x1cefc0, Func Offset: 0x290
	// Line 5784, Address: 0x1cefcc, Func Offset: 0x29c
	// Line 5785, Address: 0x1cefd4, Func Offset: 0x2a4
	// Line 5786, Address: 0x1cefd8, Func Offset: 0x2a8
	// Line 5788, Address: 0x1cefdc, Func Offset: 0x2ac
	// Line 5791, Address: 0x1cefe4, Func Offset: 0x2b4
	// Line 5793, Address: 0x1cefec, Func Offset: 0x2bc
	// Line 5792, Address: 0x1ceff0, Func Offset: 0x2c0
	// Line 5793, Address: 0x1ceff4, Func Offset: 0x2c4
	// Line 5794, Address: 0x1ceff8, Func Offset: 0x2c8
	// Line 5795, Address: 0x1ceffc, Func Offset: 0x2cc
	// Line 5798, Address: 0x1cf008, Func Offset: 0x2d8
	// Line 5801, Address: 0x1cf010, Func Offset: 0x2e0
	// Line 5802, Address: 0x1cf014, Func Offset: 0x2e4
	// Line 5801, Address: 0x1cf018, Func Offset: 0x2e8
	// Line 5802, Address: 0x1cf01c, Func Offset: 0x2ec
	// Line 5804, Address: 0x1cf028, Func Offset: 0x2f8
	// Line 5805, Address: 0x1cf048, Func Offset: 0x318
	// Line 5806, Address: 0x1cf060, Func Offset: 0x330
	// Line 5807, Address: 0x1cf078, Func Offset: 0x348
	// Line 5808, Address: 0x1cf090, Func Offset: 0x360
	// Line 5811, Address: 0x1cf098, Func Offset: 0x368
	// Line 5812, Address: 0x1cf0a4, Func Offset: 0x374
	// Line 5813, Address: 0x1cf0b0, Func Offset: 0x380
	// Line 5814, Address: 0x1cf0bc, Func Offset: 0x38c
	// Line 5816, Address: 0x1cf0c8, Func Offset: 0x398
	// Line 5818, Address: 0x1cf0d8, Func Offset: 0x3a8
	// Line 5820, Address: 0x1cf10c, Func Offset: 0x3dc
	// Line 5827, Address: 0x1cf118, Func Offset: 0x3e8
	// Line 5828, Address: 0x1cf124, Func Offset: 0x3f4
	// Line 5829, Address: 0x1cf138, Func Offset: 0x408
	// Line 5831, Address: 0x1cf144, Func Offset: 0x414
	// Line 5830, Address: 0x1cf150, Func Offset: 0x420
	// Line 5831, Address: 0x1cf154, Func Offset: 0x424
	// Line 5830, Address: 0x1cf158, Func Offset: 0x428
	// Line 5831, Address: 0x1cf15c, Func Offset: 0x42c
	// Line 5832, Address: 0x1cf160, Func Offset: 0x430
	// Line 5833, Address: 0x1cf174, Func Offset: 0x444
	// Func End, Address: 0x1cf188, Func Offset: 0x458
}

// 
// Start address: 0x1cf190
void bhEne09_DG04(BH_PWORK* epw)
{
	npobj* obj;
	// Line 5853, Address: 0x1cf190, Func Offset: 0
	// Line 5862, Address: 0x1cf19c, Func Offset: 0xc
	// Line 5866, Address: 0x1cf1bc, Func Offset: 0x2c
	// Line 5877, Address: 0x1cf1c0, Func Offset: 0x30
	// Line 5866, Address: 0x1cf1c8, Func Offset: 0x38
	// Line 5877, Address: 0x1cf1cc, Func Offset: 0x3c
	// Line 5867, Address: 0x1cf1d0, Func Offset: 0x40
	// Line 5866, Address: 0x1cf1d4, Func Offset: 0x44
	// Line 5868, Address: 0x1cf1d8, Func Offset: 0x48
	// Line 5871, Address: 0x1cf1dc, Func Offset: 0x4c
	// Line 5877, Address: 0x1cf1e0, Func Offset: 0x50
	// Line 5866, Address: 0x1cf1e4, Func Offset: 0x54
	// Line 5867, Address: 0x1cf1ec, Func Offset: 0x5c
	// Line 5868, Address: 0x1cf1f8, Func Offset: 0x68
	// Line 5871, Address: 0x1cf204, Func Offset: 0x74
	// Line 5877, Address: 0x1cf214, Func Offset: 0x84
	// Line 5880, Address: 0x1cf230, Func Offset: 0xa0
	// Line 5883, Address: 0x1cf244, Func Offset: 0xb4
	// Line 5884, Address: 0x1cf258, Func Offset: 0xc8
	// Line 5883, Address: 0x1cf25c, Func Offset: 0xcc
	// Line 5884, Address: 0x1cf26c, Func Offset: 0xdc
	// Line 5885, Address: 0x1cf274, Func Offset: 0xe4
	// Line 5888, Address: 0x1cf27c, Func Offset: 0xec
	// Line 5892, Address: 0x1cf2cc, Func Offset: 0x13c
	// Line 5893, Address: 0x1cf2d0, Func Offset: 0x140
	// Line 5892, Address: 0x1cf2d4, Func Offset: 0x144
	// Line 5893, Address: 0x1cf2d8, Func Offset: 0x148
	// Line 5894, Address: 0x1cf2e8, Func Offset: 0x158
	// Line 5895, Address: 0x1cf2fc, Func Offset: 0x16c
	// Line 5896, Address: 0x1cf310, Func Offset: 0x180
	// Line 5898, Address: 0x1cf324, Func Offset: 0x194
	// Line 5899, Address: 0x1cf328, Func Offset: 0x198
	// Line 5900, Address: 0x1cf330, Func Offset: 0x1a0
	// Line 5903, Address: 0x1cf338, Func Offset: 0x1a8
	// Line 5905, Address: 0x1cf368, Func Offset: 0x1d8
	// Line 5907, Address: 0x1cf36c, Func Offset: 0x1dc
	// Line 5910, Address: 0x1cf378, Func Offset: 0x1e8
	// Line 5911, Address: 0x1cf384, Func Offset: 0x1f4
	// Line 5910, Address: 0x1cf388, Func Offset: 0x1f8
	// Line 5911, Address: 0x1cf394, Func Offset: 0x204
	// Line 5912, Address: 0x1cf3a4, Func Offset: 0x214
	// Line 5915, Address: 0x1cf3b4, Func Offset: 0x224
	// Line 5917, Address: 0x1cf3c0, Func Offset: 0x230
	// Line 5918, Address: 0x1cf3c8, Func Offset: 0x238
	// Line 5919, Address: 0x1cf3cc, Func Offset: 0x23c
	// Line 5921, Address: 0x1cf3d0, Func Offset: 0x240
	// Line 5924, Address: 0x1cf3d8, Func Offset: 0x248
	// Line 5926, Address: 0x1cf3dc, Func Offset: 0x24c
	// Line 5925, Address: 0x1cf3e0, Func Offset: 0x250
	// Line 5926, Address: 0x1cf3e4, Func Offset: 0x254
	// Line 5927, Address: 0x1cf3e8, Func Offset: 0x258
	// Line 5928, Address: 0x1cf3ec, Func Offset: 0x25c
	// Line 5931, Address: 0x1cf3f8, Func Offset: 0x268
	// Line 5934, Address: 0x1cf400, Func Offset: 0x270
	// Line 5937, Address: 0x1cf40c, Func Offset: 0x27c
	// Line 5938, Address: 0x1cf420, Func Offset: 0x290
	// Line 5941, Address: 0x1cf430, Func Offset: 0x2a0
	// Line 5942, Address: 0x1cf434, Func Offset: 0x2a4
	// Line 5941, Address: 0x1cf438, Func Offset: 0x2a8
	// Line 5942, Address: 0x1cf43c, Func Offset: 0x2ac
	// Line 5944, Address: 0x1cf448, Func Offset: 0x2b8
	// Line 5945, Address: 0x1cf468, Func Offset: 0x2d8
	// Line 5946, Address: 0x1cf480, Func Offset: 0x2f0
	// Line 5947, Address: 0x1cf498, Func Offset: 0x308
	// Line 5948, Address: 0x1cf4b0, Func Offset: 0x320
	// Line 5951, Address: 0x1cf4b8, Func Offset: 0x328
	// Line 5952, Address: 0x1cf4c4, Func Offset: 0x334
	// Line 5953, Address: 0x1cf4d0, Func Offset: 0x340
	// Line 5954, Address: 0x1cf4dc, Func Offset: 0x34c
	// Line 5956, Address: 0x1cf4e8, Func Offset: 0x358
	// Line 5960, Address: 0x1cf4f4, Func Offset: 0x364
	// Func End, Address: 0x1cf504, Func Offset: 0x374
}

// 
// Start address: 0x1cf510
void bhEne09_DG05(BH_PWORK* epw)
{
	int frm;
	float len;
	_anon4* hp;
	npobj* obj;
	// Line 5980, Address: 0x1cf510, Func Offset: 0
	// Line 5988, Address: 0x1cf524, Func Offset: 0x14
	// Line 5993, Address: 0x1cf544, Func Offset: 0x34
	// Line 5996, Address: 0x1cf548, Func Offset: 0x38
	// Line 5997, Address: 0x1cf54c, Func Offset: 0x3c
	// Line 6000, Address: 0x1cf550, Func Offset: 0x40
	// Line 5993, Address: 0x1cf554, Func Offset: 0x44
	// Line 5996, Address: 0x1cf55c, Func Offset: 0x4c
	// Line 6001, Address: 0x1cf560, Func Offset: 0x50
	// Line 6006, Address: 0x1cf564, Func Offset: 0x54
	// Line 5996, Address: 0x1cf568, Func Offset: 0x58
	// Line 5997, Address: 0x1cf574, Func Offset: 0x64
	// Line 5998, Address: 0x1cf584, Func Offset: 0x74
	// Line 6000, Address: 0x1cf594, Func Offset: 0x84
	// Line 6001, Address: 0x1cf5a4, Func Offset: 0x94
	// Line 6003, Address: 0x1cf5b0, Func Offset: 0xa0
	// Line 6006, Address: 0x1cf5b4, Func Offset: 0xa4
	// Line 6009, Address: 0x1cf5cc, Func Offset: 0xbc
	// Line 6010, Address: 0x1cf5d8, Func Offset: 0xc8
	// Line 6012, Address: 0x1cf5e0, Func Offset: 0xd0
	// Line 6015, Address: 0x1cf5f8, Func Offset: 0xe8
	// Line 6018, Address: 0x1cf60c, Func Offset: 0xfc
	// Line 6021, Address: 0x1cf660, Func Offset: 0x150
	// Line 6022, Address: 0x1cf664, Func Offset: 0x154
	// Line 6021, Address: 0x1cf668, Func Offset: 0x158
	// Line 6022, Address: 0x1cf66c, Func Offset: 0x15c
	// Line 6023, Address: 0x1cf67c, Func Offset: 0x16c
	// Line 6024, Address: 0x1cf690, Func Offset: 0x180
	// Line 6025, Address: 0x1cf6a4, Func Offset: 0x194
	// Line 6027, Address: 0x1cf6b8, Func Offset: 0x1a8
	// Line 6028, Address: 0x1cf6c0, Func Offset: 0x1b0
	// Line 6029, Address: 0x1cf6c8, Func Offset: 0x1b8
	// Line 6032, Address: 0x1cf6d4, Func Offset: 0x1c4
	// Line 6033, Address: 0x1cf6dc, Func Offset: 0x1cc
	// Line 6035, Address: 0x1cf6f8, Func Offset: 0x1e8
	// Line 6038, Address: 0x1cf70c, Func Offset: 0x1fc
	// Line 6039, Address: 0x1cf734, Func Offset: 0x224
	// Line 6043, Address: 0x1cf73c, Func Offset: 0x22c
	// Line 6045, Address: 0x1cf75c, Func Offset: 0x24c
	// Line 6046, Address: 0x1cf764, Func Offset: 0x254
	// Line 6048, Address: 0x1cf780, Func Offset: 0x270
	// Line 6051, Address: 0x1cf794, Func Offset: 0x284
	// Line 6052, Address: 0x1cf7a8, Func Offset: 0x298
	// Line 6056, Address: 0x1cf7b0, Func Offset: 0x2a0
	// Line 6058, Address: 0x1cf7cc, Func Offset: 0x2bc
	// Line 6059, Address: 0x1cf7d4, Func Offset: 0x2c4
	// Line 6061, Address: 0x1cf7f4, Func Offset: 0x2e4
	// Line 6064, Address: 0x1cf808, Func Offset: 0x2f8
	// Line 6065, Address: 0x1cf81c, Func Offset: 0x30c
	// Line 6069, Address: 0x1cf824, Func Offset: 0x314
	// Line 6071, Address: 0x1cf840, Func Offset: 0x330
	// Line 6074, Address: 0x1cf848, Func Offset: 0x338
	// Line 6077, Address: 0x1cf85c, Func Offset: 0x34c
	// Line 6078, Address: 0x1cf884, Func Offset: 0x374
	// Line 6082, Address: 0x1cf88c, Func Offset: 0x37c
	// Line 6085, Address: 0x1cf8b0, Func Offset: 0x3a0
	// Line 6087, Address: 0x1cf8d4, Func Offset: 0x3c4
	// Line 6088, Address: 0x1cf8d8, Func Offset: 0x3c8
	// Line 6089, Address: 0x1cf8e0, Func Offset: 0x3d0
	// Line 6092, Address: 0x1cf8e8, Func Offset: 0x3d8
	// Line 6094, Address: 0x1cf918, Func Offset: 0x408
	// Line 6098, Address: 0x1cf91c, Func Offset: 0x40c
	// Line 6103, Address: 0x1cf934, Func Offset: 0x424
	// Line 6098, Address: 0x1cf938, Func Offset: 0x428
	// Line 6104, Address: 0x1cf944, Func Offset: 0x434
	// Line 6098, Address: 0x1cf948, Func Offset: 0x438
	// Line 6106, Address: 0x1cf94c, Func Offset: 0x43c
	// Line 6098, Address: 0x1cf954, Func Offset: 0x444
	// Line 6102, Address: 0x1cf958, Func Offset: 0x448
	// Line 6103, Address: 0x1cf964, Func Offset: 0x454
	// Line 6104, Address: 0x1cf970, Func Offset: 0x460
	// Line 6105, Address: 0x1cf980, Func Offset: 0x470
	// Line 6106, Address: 0x1cf990, Func Offset: 0x480
	// Line 6109, Address: 0x1cf9a0, Func Offset: 0x490
	// Line 6111, Address: 0x1cf9ac, Func Offset: 0x49c
	// Line 6112, Address: 0x1cf9b4, Func Offset: 0x4a4
	// Line 6113, Address: 0x1cf9b8, Func Offset: 0x4a8
	// Line 6115, Address: 0x1cf9bc, Func Offset: 0x4ac
	// Line 6118, Address: 0x1cf9c4, Func Offset: 0x4b4
	// Line 6120, Address: 0x1cf9c8, Func Offset: 0x4b8
	// Line 6119, Address: 0x1cf9cc, Func Offset: 0x4bc
	// Line 6120, Address: 0x1cf9d0, Func Offset: 0x4c0
	// Line 6121, Address: 0x1cf9d4, Func Offset: 0x4c4
	// Line 6122, Address: 0x1cf9d8, Func Offset: 0x4c8
	// Line 6124, Address: 0x1cf9e4, Func Offset: 0x4d4
	// Line 6127, Address: 0x1cf9ec, Func Offset: 0x4dc
	// Line 6128, Address: 0x1cf9f0, Func Offset: 0x4e0
	// Line 6127, Address: 0x1cf9f4, Func Offset: 0x4e4
	// Line 6128, Address: 0x1cf9f8, Func Offset: 0x4e8
	// Line 6130, Address: 0x1cfa04, Func Offset: 0x4f4
	// Line 6131, Address: 0x1cfa24, Func Offset: 0x514
	// Line 6132, Address: 0x1cfa3c, Func Offset: 0x52c
	// Line 6133, Address: 0x1cfa54, Func Offset: 0x544
	// Line 6134, Address: 0x1cfa6c, Func Offset: 0x55c
	// Line 6137, Address: 0x1cfa74, Func Offset: 0x564
	// Line 6138, Address: 0x1cfa80, Func Offset: 0x570
	// Line 6139, Address: 0x1cfa8c, Func Offset: 0x57c
	// Line 6140, Address: 0x1cfa98, Func Offset: 0x588
	// Line 6143, Address: 0x1cfaa4, Func Offset: 0x594
	// Line 6145, Address: 0x1cfab4, Func Offset: 0x5a4
	// Line 6146, Address: 0x1cfac0, Func Offset: 0x5b0
	// Line 6145, Address: 0x1cfac8, Func Offset: 0x5b8
	// Line 6146, Address: 0x1cfad0, Func Offset: 0x5c0
	// Line 6149, Address: 0x1cfad8, Func Offset: 0x5c8
	// Line 6150, Address: 0x1cfb0c, Func Offset: 0x5fc
	// Line 6149, Address: 0x1cfb10, Func Offset: 0x600
	// Line 6150, Address: 0x1cfb1c, Func Offset: 0x60c
	// Line 6155, Address: 0x1cfb44, Func Offset: 0x634
	// Line 6159, Address: 0x1cfb5c, Func Offset: 0x64c
	// Line 6163, Address: 0x1cfb68, Func Offset: 0x658
	// Func End, Address: 0x1cfb7c, Func Offset: 0x66c
}

// 
// Start address: 0x1cfb80
void bhEne09_DG06(BH_PWORK* epw)
{
	npobj* obj;
	// Line 6182, Address: 0x1cfb80, Func Offset: 0
	// Line 6185, Address: 0x1cfb90, Func Offset: 0x10
	// Line 6189, Address: 0x1cfbb0, Func Offset: 0x30
	// Line 6190, Address: 0x1cfbb8, Func Offset: 0x38
	// Line 6191, Address: 0x1cfbbc, Func Offset: 0x3c
	// Line 6189, Address: 0x1cfbc0, Func Offset: 0x40
	// Line 6193, Address: 0x1cfbc4, Func Offset: 0x44
	// Line 6195, Address: 0x1cfbc8, Func Offset: 0x48
	// Line 6189, Address: 0x1cfbd0, Func Offset: 0x50
	// Line 6190, Address: 0x1cfbd8, Func Offset: 0x58
	// Line 6195, Address: 0x1cfbdc, Func Offset: 0x5c
	// Line 6190, Address: 0x1cfbe0, Func Offset: 0x60
	// Line 6191, Address: 0x1cfbec, Func Offset: 0x6c
	// Line 6193, Address: 0x1cfbf8, Func Offset: 0x78
	// Line 6195, Address: 0x1cfc00, Func Offset: 0x80
	// Line 6196, Address: 0x1cfc18, Func Offset: 0x98
	// Line 6195, Address: 0x1cfc1c, Func Offset: 0x9c
	// Line 6196, Address: 0x1cfc4c, Func Offset: 0xcc
	// Line 6197, Address: 0x1cfc54, Func Offset: 0xd4
	// Line 6200, Address: 0x1cfc58, Func Offset: 0xd8
	// Line 6201, Address: 0x1cfc5c, Func Offset: 0xdc
	// Line 6200, Address: 0x1cfc60, Func Offset: 0xe0
	// Line 6201, Address: 0x1cfc64, Func Offset: 0xe4
	// Line 6202, Address: 0x1cfc74, Func Offset: 0xf4
	// Line 6203, Address: 0x1cfc88, Func Offset: 0x108
	// Line 6204, Address: 0x1cfc9c, Func Offset: 0x11c
	// Line 6205, Address: 0x1cfcb0, Func Offset: 0x130
	// Line 6208, Address: 0x1cfcbc, Func Offset: 0x13c
	// Line 6209, Address: 0x1cfcf0, Func Offset: 0x170
	// Line 6208, Address: 0x1cfcf4, Func Offset: 0x174
	// Line 6209, Address: 0x1cfd00, Func Offset: 0x180
	// Line 6214, Address: 0x1cfd28, Func Offset: 0x1a8
	// Line 6216, Address: 0x1cfd3c, Func Offset: 0x1bc
	// Line 6219, Address: 0x1cfd44, Func Offset: 0x1c4
	// Line 6220, Address: 0x1cfd54, Func Offset: 0x1d4
	// Line 6219, Address: 0x1cfd5c, Func Offset: 0x1dc
	// Line 6220, Address: 0x1cfd64, Func Offset: 0x1e4
	// Line 6223, Address: 0x1cfd6c, Func Offset: 0x1ec
	// Line 6224, Address: 0x1cfd70, Func Offset: 0x1f0
	// Line 6223, Address: 0x1cfd74, Func Offset: 0x1f4
	// Line 6224, Address: 0x1cfd78, Func Offset: 0x1f8
	// Line 6226, Address: 0x1cfd84, Func Offset: 0x204
	// Line 6227, Address: 0x1cfda4, Func Offset: 0x224
	// Line 6228, Address: 0x1cfdbc, Func Offset: 0x23c
	// Line 6229, Address: 0x1cfdd4, Func Offset: 0x254
	// Line 6230, Address: 0x1cfdec, Func Offset: 0x26c
	// Line 6233, Address: 0x1cfdf4, Func Offset: 0x274
	// Line 6234, Address: 0x1cfe00, Func Offset: 0x280
	// Line 6235, Address: 0x1cfe0c, Func Offset: 0x28c
	// Line 6236, Address: 0x1cfe18, Func Offset: 0x298
	// Line 6238, Address: 0x1cfe24, Func Offset: 0x2a4
	// Line 6240, Address: 0x1cfe30, Func Offset: 0x2b0
	// Line 6242, Address: 0x1cfe60, Func Offset: 0x2e0
	// Line 6243, Address: 0x1cfe64, Func Offset: 0x2e4
	// Line 6246, Address: 0x1cfe68, Func Offset: 0x2e8
	// Line 6243, Address: 0x1cfe70, Func Offset: 0x2f0
	// Line 6246, Address: 0x1cfe78, Func Offset: 0x2f8
	// Line 6248, Address: 0x1cfe88, Func Offset: 0x308
	// Line 6250, Address: 0x1cfe94, Func Offset: 0x314
	// Line 6251, Address: 0x1cfe9c, Func Offset: 0x31c
	// Line 6252, Address: 0x1cfea0, Func Offset: 0x320
	// Line 6254, Address: 0x1cfea4, Func Offset: 0x324
	// Line 6257, Address: 0x1cfeac, Func Offset: 0x32c
	// Line 6259, Address: 0x1cfeb4, Func Offset: 0x334
	// Line 6258, Address: 0x1cfeb8, Func Offset: 0x338
	// Line 6259, Address: 0x1cfebc, Func Offset: 0x33c
	// Line 6260, Address: 0x1cfec0, Func Offset: 0x340
	// Line 6261, Address: 0x1cfec4, Func Offset: 0x344
	// Line 6267, Address: 0x1cfed4, Func Offset: 0x354
	// Func End, Address: 0x1cfee8, Func Offset: 0x368
}

// 
// Start address: 0x1cfef0
void bhEne09_DG07(BH_PWORK* epw)
{
	npobj* obj;
	// Line 6287, Address: 0x1cfef0, Func Offset: 0
	// Line 6291, Address: 0x1cfefc, Func Offset: 0xc
	// Line 6295, Address: 0x1cff1c, Func Offset: 0x2c
	// Line 6296, Address: 0x1cff24, Func Offset: 0x34
	// Line 6299, Address: 0x1cff28, Func Offset: 0x38
	// Line 6295, Address: 0x1cff2c, Func Offset: 0x3c
	// Line 6301, Address: 0x1cff30, Func Offset: 0x40
	// Line 6295, Address: 0x1cff3c, Func Offset: 0x4c
	// Line 6296, Address: 0x1cff44, Func Offset: 0x54
	// Line 6298, Address: 0x1cff54, Func Offset: 0x64
	// Line 6299, Address: 0x1cff60, Func Offset: 0x70
	// Line 6301, Address: 0x1cff68, Func Offset: 0x78
	// Line 6307, Address: 0x1cff70, Func Offset: 0x80
	// Line 6311, Address: 0x1cff78, Func Offset: 0x88
	// Line 6301, Address: 0x1cff80, Func Offset: 0x90
	// Line 6311, Address: 0x1cff84, Func Offset: 0x94
	// Line 6301, Address: 0x1cff8c, Func Offset: 0x9c
	// Line 6302, Address: 0x1cff9c, Func Offset: 0xac
	// Line 6307, Address: 0x1cffa0, Func Offset: 0xb0
	// Line 6311, Address: 0x1cffb0, Func Offset: 0xc0
	// Line 6315, Address: 0x1cffcc, Func Offset: 0xdc
	// Line 6316, Address: 0x1cffd0, Func Offset: 0xe0
	// Line 6315, Address: 0x1cffd4, Func Offset: 0xe4
	// Line 6316, Address: 0x1cffd8, Func Offset: 0xe8
	// Line 6317, Address: 0x1cffe8, Func Offset: 0xf8
	// Line 6318, Address: 0x1cfffc, Func Offset: 0x10c
	// Line 6319, Address: 0x1d0010, Func Offset: 0x120
	// Line 6320, Address: 0x1d0024, Func Offset: 0x134
	// Line 6340, Address: 0x1d0030, Func Offset: 0x140
	// Line 6341, Address: 0x1d0034, Func Offset: 0x144
	// Line 6340, Address: 0x1d0038, Func Offset: 0x148
	// Line 6341, Address: 0x1d003c, Func Offset: 0x14c
	// Line 6343, Address: 0x1d0048, Func Offset: 0x158
	// Line 6344, Address: 0x1d0068, Func Offset: 0x178
	// Line 6345, Address: 0x1d0080, Func Offset: 0x190
	// Line 6346, Address: 0x1d0098, Func Offset: 0x1a8
	// Line 6347, Address: 0x1d00b0, Func Offset: 0x1c0
	// Line 6350, Address: 0x1d00b8, Func Offset: 0x1c8
	// Line 6351, Address: 0x1d00c4, Func Offset: 0x1d4
	// Line 6352, Address: 0x1d00d0, Func Offset: 0x1e0
	// Line 6353, Address: 0x1d00dc, Func Offset: 0x1ec
	// Line 6355, Address: 0x1d00e8, Func Offset: 0x1f8
	// Line 6357, Address: 0x1d00f4, Func Offset: 0x204
	// Line 6359, Address: 0x1d0124, Func Offset: 0x234
	// Line 6360, Address: 0x1d0128, Func Offset: 0x238
	// Line 6363, Address: 0x1d012c, Func Offset: 0x23c
	// Line 6360, Address: 0x1d0134, Func Offset: 0x244
	// Line 6363, Address: 0x1d013c, Func Offset: 0x24c
	// Line 6366, Address: 0x1d014c, Func Offset: 0x25c
	// Line 6368, Address: 0x1d0158, Func Offset: 0x268
	// Line 6369, Address: 0x1d0160, Func Offset: 0x270
	// Line 6370, Address: 0x1d0164, Func Offset: 0x274
	// Line 6372, Address: 0x1d0168, Func Offset: 0x278
	// Line 6375, Address: 0x1d0170, Func Offset: 0x280
	// Line 6377, Address: 0x1d0178, Func Offset: 0x288
	// Line 6376, Address: 0x1d017c, Func Offset: 0x28c
	// Line 6377, Address: 0x1d0180, Func Offset: 0x290
	// Line 6378, Address: 0x1d0184, Func Offset: 0x294
	// Line 6379, Address: 0x1d0188, Func Offset: 0x298
	// Line 6385, Address: 0x1d0198, Func Offset: 0x2a8
	// Func End, Address: 0x1d01a8, Func Offset: 0x2b8
}

// 
// Start address: 0x1d01b0
void bhEne09_DG08(BH_PWORK* epw)
{
	npobj* obj;
	// Line 6407, Address: 0x1d01b0, Func Offset: 0
	// Line 6410, Address: 0x1d01c0, Func Offset: 0x10
	// Line 6415, Address: 0x1d01e0, Func Offset: 0x30
	// Line 6419, Address: 0x1d01e4, Func Offset: 0x34
	// Line 6418, Address: 0x1d01ec, Func Offset: 0x3c
	// Line 6420, Address: 0x1d01f0, Func Offset: 0x40
	// Line 6415, Address: 0x1d01f4, Func Offset: 0x44
	// Line 6418, Address: 0x1d01fc, Func Offset: 0x4c
	// Line 6421, Address: 0x1d0200, Func Offset: 0x50
	// Line 6424, Address: 0x1d0204, Func Offset: 0x54
	// Line 6427, Address: 0x1d0208, Func Offset: 0x58
	// Line 6418, Address: 0x1d020c, Func Offset: 0x5c
	// Line 6427, Address: 0x1d0210, Func Offset: 0x60
	// Line 6418, Address: 0x1d0218, Func Offset: 0x68
	// Line 6419, Address: 0x1d0220, Func Offset: 0x70
	// Line 6420, Address: 0x1d0230, Func Offset: 0x80
	// Line 6421, Address: 0x1d0240, Func Offset: 0x90
	// Line 6424, Address: 0x1d024c, Func Offset: 0x9c
	// Line 6425, Address: 0x1d025c, Func Offset: 0xac
	// Line 6427, Address: 0x1d0268, Func Offset: 0xb8
	// Line 6428, Address: 0x1d0280, Func Offset: 0xd0
	// Line 6427, Address: 0x1d0284, Func Offset: 0xd4
	// Line 6428, Address: 0x1d02b4, Func Offset: 0x104
	// Line 6429, Address: 0x1d02bc, Func Offset: 0x10c
	// Line 6432, Address: 0x1d02c0, Func Offset: 0x110
	// Line 6433, Address: 0x1d02c4, Func Offset: 0x114
	// Line 6432, Address: 0x1d02c8, Func Offset: 0x118
	// Line 6433, Address: 0x1d02cc, Func Offset: 0x11c
	// Line 6434, Address: 0x1d02dc, Func Offset: 0x12c
	// Line 6435, Address: 0x1d02f0, Func Offset: 0x140
	// Line 6436, Address: 0x1d0304, Func Offset: 0x154
	// Line 6437, Address: 0x1d0318, Func Offset: 0x168
	// Line 6440, Address: 0x1d0324, Func Offset: 0x174
	// Line 6442, Address: 0x1d0358, Func Offset: 0x1a8
	// Line 6440, Address: 0x1d035c, Func Offset: 0x1ac
	// Line 6442, Address: 0x1d0368, Func Offset: 0x1b8
	// Line 6447, Address: 0x1d0390, Func Offset: 0x1e0
	// Line 6449, Address: 0x1d03a4, Func Offset: 0x1f4
	// Line 6452, Address: 0x1d03ac, Func Offset: 0x1fc
	// Line 6453, Address: 0x1d03bc, Func Offset: 0x20c
	// Line 6452, Address: 0x1d03c4, Func Offset: 0x214
	// Line 6453, Address: 0x1d03cc, Func Offset: 0x21c
	// Line 6456, Address: 0x1d03d4, Func Offset: 0x224
	// Line 6457, Address: 0x1d03d8, Func Offset: 0x228
	// Line 6456, Address: 0x1d03dc, Func Offset: 0x22c
	// Line 6457, Address: 0x1d03e0, Func Offset: 0x230
	// Line 6459, Address: 0x1d03ec, Func Offset: 0x23c
	// Line 6460, Address: 0x1d040c, Func Offset: 0x25c
	// Line 6461, Address: 0x1d0424, Func Offset: 0x274
	// Line 6462, Address: 0x1d043c, Func Offset: 0x28c
	// Line 6463, Address: 0x1d0454, Func Offset: 0x2a4
	// Line 6466, Address: 0x1d045c, Func Offset: 0x2ac
	// Line 6467, Address: 0x1d0468, Func Offset: 0x2b8
	// Line 6468, Address: 0x1d0474, Func Offset: 0x2c4
	// Line 6469, Address: 0x1d0480, Func Offset: 0x2d0
	// Line 6471, Address: 0x1d048c, Func Offset: 0x2dc
	// Line 6473, Address: 0x1d0498, Func Offset: 0x2e8
	// Line 6475, Address: 0x1d04c8, Func Offset: 0x318
	// Line 6478, Address: 0x1d04cc, Func Offset: 0x31c
	// Line 6482, Address: 0x1d04d0, Func Offset: 0x320
	// Line 6478, Address: 0x1d04d8, Func Offset: 0x328
	// Line 6484, Address: 0x1d04dc, Func Offset: 0x32c
	// Line 6478, Address: 0x1d04e0, Func Offset: 0x330
	// Line 6479, Address: 0x1d04ec, Func Offset: 0x33c
	// Line 6482, Address: 0x1d04fc, Func Offset: 0x34c
	// Line 6483, Address: 0x1d050c, Func Offset: 0x35c
	// Line 6484, Address: 0x1d0518, Func Offset: 0x368
	// Line 6487, Address: 0x1d0524, Func Offset: 0x374
	// Line 6489, Address: 0x1d0530, Func Offset: 0x380
	// Line 6490, Address: 0x1d0538, Func Offset: 0x388
	// Line 6491, Address: 0x1d053c, Func Offset: 0x38c
	// Line 6493, Address: 0x1d0540, Func Offset: 0x390
	// Line 6496, Address: 0x1d0548, Func Offset: 0x398
	// Line 6498, Address: 0x1d0550, Func Offset: 0x3a0
	// Line 6497, Address: 0x1d0554, Func Offset: 0x3a4
	// Line 6498, Address: 0x1d0558, Func Offset: 0x3a8
	// Line 6499, Address: 0x1d055c, Func Offset: 0x3ac
	// Line 6500, Address: 0x1d0560, Func Offset: 0x3b0
	// Line 6506, Address: 0x1d0570, Func Offset: 0x3c0
	// Func End, Address: 0x1d0584, Func Offset: 0x3d4
}

// 
// Start address: 0x1d0590
void bhEne09_DG09(BH_PWORK* epw)
{
	float flr_y;
	npobj* obj;
	// Line 6527, Address: 0x1d0590, Func Offset: 0
	// Line 6531, Address: 0x1d05a0, Func Offset: 0x10
	// Line 6536, Address: 0x1d05c0, Func Offset: 0x30
	// Line 6539, Address: 0x1d05c4, Func Offset: 0x34
	// Line 6540, Address: 0x1d05c8, Func Offset: 0x38
	// Line 6541, Address: 0x1d05cc, Func Offset: 0x3c
	// Line 6536, Address: 0x1d05d0, Func Offset: 0x40
	// Line 6539, Address: 0x1d05d8, Func Offset: 0x48
	// Line 6543, Address: 0x1d05dc, Func Offset: 0x4c
	// Line 6545, Address: 0x1d05e0, Func Offset: 0x50
	// Line 6539, Address: 0x1d05e8, Func Offset: 0x58
	// Line 6545, Address: 0x1d05ec, Func Offset: 0x5c
	// Line 6539, Address: 0x1d05f0, Func Offset: 0x60
	// Line 6540, Address: 0x1d05f8, Func Offset: 0x68
	// Line 6541, Address: 0x1d0604, Func Offset: 0x74
	// Line 6542, Address: 0x1d0614, Func Offset: 0x84
	// Line 6543, Address: 0x1d0624, Func Offset: 0x94
	// Line 6545, Address: 0x1d0630, Func Offset: 0xa0
	// Line 6547, Address: 0x1d0648, Func Offset: 0xb8
	// Line 6545, Address: 0x1d064c, Func Offset: 0xbc
	// Line 6547, Address: 0x1d0678, Func Offset: 0xe8
	// Line 6548, Address: 0x1d0680, Func Offset: 0xf0
	// Line 6550, Address: 0x1d068c, Func Offset: 0xfc
	// Line 6551, Address: 0x1d069c, Func Offset: 0x10c
	// Line 6554, Address: 0x1d06a0, Func Offset: 0x110
	// Line 6555, Address: 0x1d06a4, Func Offset: 0x114
	// Line 6554, Address: 0x1d06a8, Func Offset: 0x118
	// Line 6555, Address: 0x1d06ac, Func Offset: 0x11c
	// Line 6556, Address: 0x1d06bc, Func Offset: 0x12c
	// Line 6557, Address: 0x1d06d0, Func Offset: 0x140
	// Line 6558, Address: 0x1d06e4, Func Offset: 0x154
	// Line 6559, Address: 0x1d06f8, Func Offset: 0x168
	// Line 6562, Address: 0x1d0704, Func Offset: 0x174
	// Line 6564, Address: 0x1d0738, Func Offset: 0x1a8
	// Line 6562, Address: 0x1d073c, Func Offset: 0x1ac
	// Line 6564, Address: 0x1d0748, Func Offset: 0x1b8
	// Line 6569, Address: 0x1d0770, Func Offset: 0x1e0
	// Line 6571, Address: 0x1d0784, Func Offset: 0x1f4
	// Line 6574, Address: 0x1d078c, Func Offset: 0x1fc
	// Line 6578, Address: 0x1d07a8, Func Offset: 0x218
	// Line 6579, Address: 0x1d07ac, Func Offset: 0x21c
	// Line 6578, Address: 0x1d07b0, Func Offset: 0x220
	// Line 6579, Address: 0x1d07b4, Func Offset: 0x224
	// Line 6581, Address: 0x1d07c0, Func Offset: 0x230
	// Line 6582, Address: 0x1d07e0, Func Offset: 0x250
	// Line 6583, Address: 0x1d07f8, Func Offset: 0x268
	// Line 6584, Address: 0x1d0810, Func Offset: 0x280
	// Line 6585, Address: 0x1d0828, Func Offset: 0x298
	// Line 6588, Address: 0x1d0830, Func Offset: 0x2a0
	// Line 6589, Address: 0x1d083c, Func Offset: 0x2ac
	// Line 6590, Address: 0x1d0848, Func Offset: 0x2b8
	// Line 6591, Address: 0x1d0854, Func Offset: 0x2c4
	// Line 6593, Address: 0x1d0860, Func Offset: 0x2d0
	// Line 6595, Address: 0x1d086c, Func Offset: 0x2dc
	// Line 6597, Address: 0x1d089c, Func Offset: 0x30c
	// Line 6600, Address: 0x1d08a0, Func Offset: 0x310
	// Line 6606, Address: 0x1d08a4, Func Offset: 0x314
	// Line 6600, Address: 0x1d08a8, Func Offset: 0x318
	// Line 6603, Address: 0x1d08ac, Func Offset: 0x31c
	// Line 6600, Address: 0x1d08b0, Func Offset: 0x320
	// Line 6606, Address: 0x1d08b4, Func Offset: 0x324
	// Line 6600, Address: 0x1d08b8, Func Offset: 0x328
	// Line 6601, Address: 0x1d08c0, Func Offset: 0x330
	// Line 6602, Address: 0x1d08d0, Func Offset: 0x340
	// Line 6603, Address: 0x1d08dc, Func Offset: 0x34c
	// Line 6606, Address: 0x1d08e8, Func Offset: 0x358
	// Line 6609, Address: 0x1d08f8, Func Offset: 0x368
	// Line 6611, Address: 0x1d0904, Func Offset: 0x374
	// Line 6612, Address: 0x1d090c, Func Offset: 0x37c
	// Line 6613, Address: 0x1d0910, Func Offset: 0x380
	// Line 6615, Address: 0x1d0914, Func Offset: 0x384
	// Line 6618, Address: 0x1d091c, Func Offset: 0x38c
	// Line 6620, Address: 0x1d0924, Func Offset: 0x394
	// Line 6619, Address: 0x1d0928, Func Offset: 0x398
	// Line 6620, Address: 0x1d092c, Func Offset: 0x39c
	// Line 6621, Address: 0x1d0930, Func Offset: 0x3a0
	// Line 6622, Address: 0x1d0934, Func Offset: 0x3a4
	// Line 6628, Address: 0x1d0944, Func Offset: 0x3b4
	// Func End, Address: 0x1d0958, Func Offset: 0x3c8
}

// 
// Start address: 0x1d0960
void bhEne09_DG10(BH_PWORK* epw)
{
	// Line 6649, Address: 0x1d0960, Func Offset: 0
	// Line 6652, Address: 0x1d096c, Func Offset: 0xc
	// Line 6655, Address: 0x1d0998, Func Offset: 0x38
	// Line 6657, Address: 0x1d09a8, Func Offset: 0x48
	// Line 6658, Address: 0x1d09c8, Func Offset: 0x68
	// Line 6659, Address: 0x1d09d0, Func Offset: 0x70
	// Line 6661, Address: 0x1d09dc, Func Offset: 0x7c
	// Line 6662, Address: 0x1d09fc, Func Offset: 0x9c
	// Line 6663, Address: 0x1d0a04, Func Offset: 0xa4
	// Line 6665, Address: 0x1d0a10, Func Offset: 0xb0
	// Line 6666, Address: 0x1d0a30, Func Offset: 0xd0
	// Line 6667, Address: 0x1d0a38, Func Offset: 0xd8
	// Line 6669, Address: 0x1d0a44, Func Offset: 0xe4
	// Line 6671, Address: 0x1d0a68, Func Offset: 0x108
	// Line 6674, Address: 0x1d0a74, Func Offset: 0x114
	// Line 6677, Address: 0x1d0aa4, Func Offset: 0x144
	// Line 6676, Address: 0x1d0aa8, Func Offset: 0x148
	// Line 6677, Address: 0x1d0aac, Func Offset: 0x14c
	// Line 6678, Address: 0x1d0ab0, Func Offset: 0x150
	// Line 6679, Address: 0x1d0ab4, Func Offset: 0x154
	// Line 6680, Address: 0x1d0ab8, Func Offset: 0x158
	// Line 6683, Address: 0x1d0abc, Func Offset: 0x15c
	// Line 6684, Address: 0x1d0ac8, Func Offset: 0x168
	// Line 6683, Address: 0x1d0acc, Func Offset: 0x16c
	// Line 6684, Address: 0x1d0ad8, Func Offset: 0x178
	// Line 6685, Address: 0x1d0ae8, Func Offset: 0x188
	// Line 6687, Address: 0x1d0af4, Func Offset: 0x194
	// Line 6690, Address: 0x1d0afc, Func Offset: 0x19c
	// Line 6692, Address: 0x1d0b2c, Func Offset: 0x1cc
	// Line 6697, Address: 0x1d0b30, Func Offset: 0x1d0
	// Func End, Address: 0x1d0b40, Func Offset: 0x1e0
}

// 
// Start address: 0x1d0b40
void bhEne09_DDType00(BH_PWORK* epw)
{
	// Line 6715, Address: 0x1d0b40, Func Offset: 0
	// Func End, Address: 0x1d0b60, Func Offset: 0x20
}

// 
// Start address: 0x1d0b60
void bhEne09_DD00(BH_PWORK* epw)
{
	// Line 6736, Address: 0x1d0b60, Func Offset: 0
	// Line 6737, Address: 0x1d0b6c, Func Offset: 0xc
	// Line 6740, Address: 0x1d0ba4, Func Offset: 0x44
	// Line 6742, Address: 0x1d0bc0, Func Offset: 0x60
	// Line 6743, Address: 0x1d0be4, Func Offset: 0x84
	// Line 6746, Address: 0x1d0bec, Func Offset: 0x8c
	// Line 6748, Address: 0x1d0c10, Func Offset: 0xb0
	// Line 6749, Address: 0x1d0c14, Func Offset: 0xb4
	// Line 6750, Address: 0x1d0c18, Func Offset: 0xb8
	// Line 6753, Address: 0x1d0c1c, Func Offset: 0xbc
	// Line 6749, Address: 0x1d0c20, Func Offset: 0xc0
	// Line 6750, Address: 0x1d0c28, Func Offset: 0xc8
	// Line 6754, Address: 0x1d0c34, Func Offset: 0xd4
	// Line 6755, Address: 0x1d0c44, Func Offset: 0xe4
	// Line 6754, Address: 0x1d0c54, Func Offset: 0xf4
	// Line 6755, Address: 0x1d0c60, Func Offset: 0x100
	// Line 6756, Address: 0x1d0c6c, Func Offset: 0x10c
	// Line 6759, Address: 0x1d0c78, Func Offset: 0x118
	// Line 6761, Address: 0x1d0c88, Func Offset: 0x128
	// Line 6762, Address: 0x1d0c90, Func Offset: 0x130
	// Line 6764, Address: 0x1d0c98, Func Offset: 0x138
	// Line 6767, Address: 0x1d0ca0, Func Offset: 0x140
	// Line 6769, Address: 0x1d0cd0, Func Offset: 0x170
	// Line 6771, Address: 0x1d0cd4, Func Offset: 0x174
	// Line 6773, Address: 0x1d0ce4, Func Offset: 0x184
	// Line 6774, Address: 0x1d0d00, Func Offset: 0x1a0
	// Line 6773, Address: 0x1d0d04, Func Offset: 0x1a4
	// Line 6775, Address: 0x1d0d0c, Func Offset: 0x1ac
	// Line 6779, Address: 0x1d0d14, Func Offset: 0x1b4
	// Line 6787, Address: 0x1d0d20, Func Offset: 0x1c0
	// Func End, Address: 0x1d0d30, Func Offset: 0x1d0
}

// 
// Start address: 0x1d0d30
int bhEne09_CollChkArm(BH_PWORK* epw, BH_PWORK* trg)
{
	int i;
	float len;
	int r;
	_anon25 pd;
	_anon46 l1;
	_anon51 cp;
	_anon50 sp;
	_anon24* owk;
	// Line 6847, Address: 0x1d0d30, Func Offset: 0
	// Line 6858, Address: 0x1d0d5c, Func Offset: 0x2c
	// Line 6861, Address: 0x1d0d60, Func Offset: 0x30
	// Line 6865, Address: 0x1d0d6c, Func Offset: 0x3c
	// Line 6858, Address: 0x1d0d70, Func Offset: 0x40
	// Line 6859, Address: 0x1d0d74, Func Offset: 0x44
	// Line 6860, Address: 0x1d0d7c, Func Offset: 0x4c
	// Line 6861, Address: 0x1d0d84, Func Offset: 0x54
	// Line 6864, Address: 0x1d0d8c, Func Offset: 0x5c
	// Line 6867, Address: 0x1d0d98, Func Offset: 0x68
	// Line 6868, Address: 0x1d0d9c, Func Offset: 0x6c
	// Line 6869, Address: 0x1d0da0, Func Offset: 0x70
	// Line 6870, Address: 0x1d0da4, Func Offset: 0x74
	// Line 6867, Address: 0x1d0da8, Func Offset: 0x78
	// Line 6868, Address: 0x1d0dac, Func Offset: 0x7c
	// Line 6872, Address: 0x1d0db0, Func Offset: 0x80
	// Line 6873, Address: 0x1d0db8, Func Offset: 0x88
	// Line 6868, Address: 0x1d0dbc, Func Offset: 0x8c
	// Line 6869, Address: 0x1d0dc0, Func Offset: 0x90
	// Line 6873, Address: 0x1d0dc4, Func Offset: 0x94
	// Line 6869, Address: 0x1d0dc8, Func Offset: 0x98
	// Line 6870, Address: 0x1d0dcc, Func Offset: 0x9c
	// Line 6871, Address: 0x1d0dd4, Func Offset: 0xa4
	// Line 6873, Address: 0x1d0de0, Func Offset: 0xb0
	// Line 6875, Address: 0x1d0df4, Func Offset: 0xc4
	// Line 6882, Address: 0x1d0df8, Func Offset: 0xc8
	// Line 6875, Address: 0x1d0e04, Func Offset: 0xd4
	// Line 6876, Address: 0x1d0e08, Func Offset: 0xd8
	// Line 6877, Address: 0x1d0e10, Func Offset: 0xe0
	// Line 6878, Address: 0x1d0e1c, Func Offset: 0xec
	// Line 6880, Address: 0x1d0e28, Func Offset: 0xf8
	// Line 6882, Address: 0x1d0e30, Func Offset: 0x100
	// Line 6883, Address: 0x1d0e38, Func Offset: 0x108
	// Line 6885, Address: 0x1d0e54, Func Offset: 0x124
	// Line 6886, Address: 0x1d0e8c, Func Offset: 0x15c
	// Line 6887, Address: 0x1d0ea0, Func Offset: 0x170
	// Line 6886, Address: 0x1d0ea4, Func Offset: 0x174
	// Line 6887, Address: 0x1d0eb0, Func Offset: 0x180
	// Line 6889, Address: 0x1d0ed4, Func Offset: 0x1a4
	// Line 6892, Address: 0x1d0ee0, Func Offset: 0x1b0
	// Line 6902, Address: 0x1d0ef0, Func Offset: 0x1c0
	// Line 6903, Address: 0x1d0ef4, Func Offset: 0x1c4
	// Func End, Address: 0x1d0f24, Func Offset: 0x1f4
}

// 
// Start address: 0x1d0f30
int bhEne09_CollChkArm2(BH_PWORK* epw)
{
	int rot;
	int i;
	_anon24* owk;
	BH_PWORK* ep;
	_anon50 at2;
	_anon50 at;
	// Line 6925, Address: 0x1d0f30, Func Offset: 0
	// Line 6934, Address: 0x1d0f3c, Func Offset: 0xc
	// Line 6925, Address: 0x1d0f40, Func Offset: 0x10
	// Line 6934, Address: 0x1d0f44, Func Offset: 0x14
	// Line 6925, Address: 0x1d0f48, Func Offset: 0x18
	// Line 6934, Address: 0x1d0f50, Func Offset: 0x20
	// Line 6925, Address: 0x1d0f54, Func Offset: 0x24
	// Line 6934, Address: 0x1d0f5c, Func Offset: 0x2c
	// Line 6935, Address: 0x1d0f78, Func Offset: 0x48
	// Line 6936, Address: 0x1d0f80, Func Offset: 0x50
	// Line 6938, Address: 0x1d0f84, Func Offset: 0x54
	// Line 6942, Address: 0x1d0f88, Func Offset: 0x58
	// Line 6940, Address: 0x1d0f90, Func Offset: 0x60
	// Line 6941, Address: 0x1d0f94, Func Offset: 0x64
	// Line 6938, Address: 0x1d0f98, Func Offset: 0x68
	// Line 6947, Address: 0x1d0f9c, Func Offset: 0x6c
	// Line 6939, Address: 0x1d0fa0, Func Offset: 0x70
	// Line 6940, Address: 0x1d0fa8, Func Offset: 0x78
	// Line 6941, Address: 0x1d0fb0, Func Offset: 0x80
	// Line 6942, Address: 0x1d0fb8, Func Offset: 0x88
	// Line 6943, Address: 0x1d0fc0, Func Offset: 0x90
	// Line 6944, Address: 0x1d0fc8, Func Offset: 0x98
	// Line 6942, Address: 0x1d0fd0, Func Offset: 0xa0
	// Line 6943, Address: 0x1d0fd4, Func Offset: 0xa4
	// Line 6944, Address: 0x1d0fd8, Func Offset: 0xa8
	// Line 6942, Address: 0x1d0fdc, Func Offset: 0xac
	// Line 6943, Address: 0x1d0fe0, Func Offset: 0xb0
	// Line 6944, Address: 0x1d0fe4, Func Offset: 0xb4
	// Line 6949, Address: 0x1d0fe8, Func Offset: 0xb8
	// Line 6951, Address: 0x1d1004, Func Offset: 0xd4
	// Line 6955, Address: 0x1d1030, Func Offset: 0x100
	// Line 6956, Address: 0x1d1038, Func Offset: 0x108
	// Line 6957, Address: 0x1d1044, Func Offset: 0x114
	// Line 6956, Address: 0x1d1048, Func Offset: 0x118
	// Line 6957, Address: 0x1d104c, Func Offset: 0x11c
	// Line 6958, Address: 0x1d1054, Func Offset: 0x124
	// Line 6957, Address: 0x1d1058, Func Offset: 0x128
	// Line 6958, Address: 0x1d105c, Func Offset: 0x12c
	// Line 6959, Address: 0x1d1064, Func Offset: 0x134
	// Line 6958, Address: 0x1d1068, Func Offset: 0x138
	// Line 6959, Address: 0x1d106c, Func Offset: 0x13c
	// Line 6963, Address: 0x1d1078, Func Offset: 0x148
	// Line 6964, Address: 0x1d1080, Func Offset: 0x150
	// Line 6963, Address: 0x1d1084, Func Offset: 0x154
	// Line 6964, Address: 0x1d1088, Func Offset: 0x158
	// Line 6963, Address: 0x1d108c, Func Offset: 0x15c
	// Line 6964, Address: 0x1d1094, Func Offset: 0x164
	// Line 6965, Address: 0x1d109c, Func Offset: 0x16c
	// Line 6966, Address: 0x1d10a8, Func Offset: 0x178
	// Line 6967, Address: 0x1d10b4, Func Offset: 0x184
	// Line 6969, Address: 0x1d10c0, Func Offset: 0x190
	// Line 6967, Address: 0x1d10c4, Func Offset: 0x194
	// Line 6969, Address: 0x1d10cc, Func Offset: 0x19c
	// Line 6970, Address: 0x1d10e4, Func Offset: 0x1b4
	// Line 6971, Address: 0x1d10f8, Func Offset: 0x1c8
	// Line 6972, Address: 0x1d1114, Func Offset: 0x1e4
	// Line 6974, Address: 0x1d111c, Func Offset: 0x1ec
	// Line 6977, Address: 0x1d1124, Func Offset: 0x1f4
	// Line 6980, Address: 0x1d1134, Func Offset: 0x204
	// Line 6982, Address: 0x1d113c, Func Offset: 0x20c
	// Line 6984, Address: 0x1d1148, Func Offset: 0x218
	// Line 6987, Address: 0x1d114c, Func Offset: 0x21c
	// Line 6984, Address: 0x1d1154, Func Offset: 0x224
	// Line 6985, Address: 0x1d115c, Func Offset: 0x22c
	// Line 6986, Address: 0x1d1168, Func Offset: 0x238
	// Line 6987, Address: 0x1d1170, Func Offset: 0x240
	// Line 6990, Address: 0x1d1178, Func Offset: 0x248
	// Line 6992, Address: 0x1d1188, Func Offset: 0x258
	// Line 6996, Address: 0x1d11ac, Func Offset: 0x27c
	// Line 6998, Address: 0x1d11c0, Func Offset: 0x290
	// Line 7001, Address: 0x1d11c8, Func Offset: 0x298
	// Line 7008, Address: 0x1d11f0, Func Offset: 0x2c0
	// Line 7011, Address: 0x1d1214, Func Offset: 0x2e4
	// Func End, Address: 0x1d123c, Func Offset: 0x30c
}

// 
// Start address: 0x1d1240
float bhEne09_ChkArmLen2(BH_PWORK* epw)
{
	int s_mtn_add;
	unsigned int s_hokan_count;
	int s_hokan_rate;
	int s_frm_no;
	unsigned int s_mtn_no;
	int s_ang[3][24];
	int i;
	npobj* obj;
	float tmp2;
	float tmp;
	_anon25 pos2;
	_anon25 pos;
	// Line 7063, Address: 0x1d1240, Func Offset: 0
	// Line 7078, Address: 0x1d1284, Func Offset: 0x44
	// Line 7079, Address: 0x1d1288, Func Offset: 0x48
	// Line 7080, Address: 0x1d128c, Func Offset: 0x4c
	// Line 7081, Address: 0x1d1290, Func Offset: 0x50
	// Line 7082, Address: 0x1d1294, Func Offset: 0x54
	// Line 7084, Address: 0x1d1298, Func Offset: 0x58
	// Line 7089, Address: 0x1d12a0, Func Offset: 0x60
	// Line 7084, Address: 0x1d12ac, Func Offset: 0x6c
	// Line 7085, Address: 0x1d12b0, Func Offset: 0x70
	// Line 7086, Address: 0x1d12b4, Func Offset: 0x74
	// Line 7087, Address: 0x1d12b8, Func Offset: 0x78
	// Line 7091, Address: 0x1d12c0, Func Offset: 0x80
	// Line 7095, Address: 0x1d12c4, Func Offset: 0x84
	// Line 7091, Address: 0x1d12cc, Func Offset: 0x8c
	// Line 7092, Address: 0x1d12d0, Func Offset: 0x90
	// Line 7093, Address: 0x1d12d8, Func Offset: 0x98
	// Line 7094, Address: 0x1d12e0, Func Offset: 0xa0
	// Line 7095, Address: 0x1d12e4, Func Offset: 0xa4
	// Line 7099, Address: 0x1d12ec, Func Offset: 0xac
	// Line 7098, Address: 0x1d12f0, Func Offset: 0xb0
	// Line 7099, Address: 0x1d12f4, Func Offset: 0xb4
	// Line 7100, Address: 0x1d12f8, Func Offset: 0xb8
	// Line 7101, Address: 0x1d12fc, Func Offset: 0xbc
	// Line 7102, Address: 0x1d1300, Func Offset: 0xc0
	// Line 7104, Address: 0x1d1304, Func Offset: 0xc4
	// Line 7106, Address: 0x1d1318, Func Offset: 0xd8
	// Line 7108, Address: 0x1d133c, Func Offset: 0xfc
	// Line 7109, Address: 0x1d1350, Func Offset: 0x110
	// Line 7112, Address: 0x1d1374, Func Offset: 0x134
	// Line 7113, Address: 0x1d137c, Func Offset: 0x13c
	// Line 7114, Address: 0x1d1384, Func Offset: 0x144
	// Line 7112, Address: 0x1d1388, Func Offset: 0x148
	// Line 7116, Address: 0x1d138c, Func Offset: 0x14c
	// Line 7112, Address: 0x1d1390, Func Offset: 0x150
	// Line 7113, Address: 0x1d1394, Func Offset: 0x154
	// Line 7114, Address: 0x1d139c, Func Offset: 0x15c
	// Line 7113, Address: 0x1d13a0, Func Offset: 0x160
	// Line 7114, Address: 0x1d13a8, Func Offset: 0x168
	// Line 7116, Address: 0x1d13b8, Func Offset: 0x178
	// Line 7117, Address: 0x1d13e8, Func Offset: 0x1a8
	// Line 7126, Address: 0x1d13f0, Func Offset: 0x1b0
	// Line 7118, Address: 0x1d13f4, Func Offset: 0x1b4
	// Line 7122, Address: 0x1d13f8, Func Offset: 0x1b8
	// Line 7126, Address: 0x1d13fc, Func Offset: 0x1bc
	// Line 7117, Address: 0x1d1400, Func Offset: 0x1c0
	// Line 7118, Address: 0x1d1404, Func Offset: 0x1c4
	// Line 7119, Address: 0x1d1410, Func Offset: 0x1d0
	// Line 7120, Address: 0x1d1420, Func Offset: 0x1e0
	// Line 7122, Address: 0x1d1424, Func Offset: 0x1e4
	// Line 7123, Address: 0x1d142c, Func Offset: 0x1ec
	// Line 7124, Address: 0x1d1438, Func Offset: 0x1f8
	// Line 7126, Address: 0x1d1440, Func Offset: 0x200
	// Line 7127, Address: 0x1d1448, Func Offset: 0x208
	// Line 7129, Address: 0x1d145c, Func Offset: 0x21c
	// Line 7130, Address: 0x1d1464, Func Offset: 0x224
	// Line 7148, Address: 0x1d1468, Func Offset: 0x228
	// Line 7130, Address: 0x1d146c, Func Offset: 0x22c
	// Line 7129, Address: 0x1d1474, Func Offset: 0x234
	// Line 7130, Address: 0x1d1478, Func Offset: 0x238
	// Line 7131, Address: 0x1d147c, Func Offset: 0x23c
	// Line 7133, Address: 0x1d148c, Func Offset: 0x24c
	// Line 7137, Address: 0x1d14a8, Func Offset: 0x268
	// Line 7138, Address: 0x1d14ac, Func Offset: 0x26c
	// Line 7139, Address: 0x1d14b0, Func Offset: 0x270
	// Line 7140, Address: 0x1d14b4, Func Offset: 0x274
	// Line 7141, Address: 0x1d14b8, Func Offset: 0x278
	// Line 7143, Address: 0x1d14bc, Func Offset: 0x27c
	// Line 7133, Address: 0x1d14c0, Func Offset: 0x280
	// Line 7143, Address: 0x1d14c8, Func Offset: 0x288
	// Line 7133, Address: 0x1d14cc, Func Offset: 0x28c
	// Line 7144, Address: 0x1d14d0, Func Offset: 0x290
	// Line 7145, Address: 0x1d14d4, Func Offset: 0x294
	// Line 7146, Address: 0x1d14d8, Func Offset: 0x298
	// Line 7150, Address: 0x1d14dc, Func Offset: 0x29c
	// Line 7154, Address: 0x1d14e0, Func Offset: 0x2a0
	// Line 7150, Address: 0x1d14e8, Func Offset: 0x2a8
	// Line 7151, Address: 0x1d14ec, Func Offset: 0x2ac
	// Line 7152, Address: 0x1d14f4, Func Offset: 0x2b4
	// Line 7153, Address: 0x1d14fc, Func Offset: 0x2bc
	// Line 7154, Address: 0x1d1500, Func Offset: 0x2c0
	// Line 7158, Address: 0x1d1508, Func Offset: 0x2c8
	// Func End, Address: 0x1d1550, Func Offset: 0x310
}

// 
// Start address: 0x1d1550
_anon4* bhEne09_ChkArmLen(BH_PWORK* epw, float* len, _anon25* vec)
{
	int s_mtn_add;
	unsigned int s_hokan_count;
	int s_hokan_rate;
	int s_frm_no;
	unsigned int s_mtn_no;
	int s_ang[3][24];
	int i;
	_anon4* hp2;
	_anon4* hp;
	npobj* obj;
	float tmp;
	_anon25 pos4;
	_anon25 pos3;
	_anon25 pos2;
	_anon25 pos;
	// Line 7163, Address: 0x1d1550, Func Offset: 0
	// Line 7181, Address: 0x1d159c, Func Offset: 0x4c
	// Line 7183, Address: 0x1d15a4, Func Offset: 0x54
	// Line 7185, Address: 0x1d15a8, Func Offset: 0x58
	// Line 7198, Address: 0x1d15ac, Func Offset: 0x5c
	// Line 7181, Address: 0x1d15b0, Func Offset: 0x60
	// Line 7182, Address: 0x1d15b4, Func Offset: 0x64
	// Line 7184, Address: 0x1d15c8, Func Offset: 0x78
	// Line 7187, Address: 0x1d15d0, Func Offset: 0x80
	// Line 7198, Address: 0x1d15d8, Func Offset: 0x88
	// Line 7188, Address: 0x1d15dc, Func Offset: 0x8c
	// Line 7189, Address: 0x1d15e0, Func Offset: 0x90
	// Line 7190, Address: 0x1d15e4, Func Offset: 0x94
	// Line 7191, Address: 0x1d15e8, Func Offset: 0x98
	// Line 7194, Address: 0x1d15ec, Func Offset: 0x9c
	// Line 7195, Address: 0x1d15f0, Func Offset: 0xa0
	// Line 7196, Address: 0x1d15f4, Func Offset: 0xa4
	// Line 7200, Address: 0x1d15fc, Func Offset: 0xac
	// Line 7204, Address: 0x1d1600, Func Offset: 0xb0
	// Line 7200, Address: 0x1d1608, Func Offset: 0xb8
	// Line 7201, Address: 0x1d160c, Func Offset: 0xbc
	// Line 7202, Address: 0x1d1614, Func Offset: 0xc4
	// Line 7203, Address: 0x1d161c, Func Offset: 0xcc
	// Line 7204, Address: 0x1d1620, Func Offset: 0xd0
	// Line 7206, Address: 0x1d1628, Func Offset: 0xd8
	// Line 7207, Address: 0x1d1630, Func Offset: 0xe0
	// Line 7208, Address: 0x1d1638, Func Offset: 0xe8
	// Line 7209, Address: 0x1d163c, Func Offset: 0xec
	// Line 7210, Address: 0x1d1640, Func Offset: 0xf0
	// Line 7212, Address: 0x1d1644, Func Offset: 0xf4
	// Line 7214, Address: 0x1d1658, Func Offset: 0x108
	// Line 7217, Address: 0x1d167c, Func Offset: 0x12c
	// Line 7223, Address: 0x1d1680, Func Offset: 0x130
	// Line 7218, Address: 0x1d168c, Func Offset: 0x13c
	// Line 7217, Address: 0x1d1690, Func Offset: 0x140
	// Line 7223, Address: 0x1d1694, Func Offset: 0x144
	// Line 7218, Address: 0x1d16a0, Func Offset: 0x150
	// Line 7219, Address: 0x1d16a4, Func Offset: 0x154
	// Line 7220, Address: 0x1d16a8, Func Offset: 0x158
	// Line 7221, Address: 0x1d16ac, Func Offset: 0x15c
	// Line 7223, Address: 0x1d16b0, Func Offset: 0x160
	// Line 7227, Address: 0x1d16bc, Func Offset: 0x16c
	// Line 7229, Address: 0x1d16d0, Func Offset: 0x180
	// Line 7232, Address: 0x1d16d8, Func Offset: 0x188
	// Line 7236, Address: 0x1d16e0, Func Offset: 0x190
	// Line 7240, Address: 0x1d16e8, Func Offset: 0x198
	// Line 7238, Address: 0x1d16f0, Func Offset: 0x1a0
	// Line 7241, Address: 0x1d16f4, Func Offset: 0x1a4
	// Line 7236, Address: 0x1d16f8, Func Offset: 0x1a8
	// Line 7241, Address: 0x1d16fc, Func Offset: 0x1ac
	// Line 7245, Address: 0x1d1700, Func Offset: 0x1b0
	// Line 7236, Address: 0x1d1704, Func Offset: 0x1b4
	// Line 7237, Address: 0x1d1708, Func Offset: 0x1b8
	// Line 7238, Address: 0x1d1710, Func Offset: 0x1c0
	// Line 7240, Address: 0x1d1720, Func Offset: 0x1d0
	// Line 7241, Address: 0x1d1734, Func Offset: 0x1e4
	// Line 7242, Address: 0x1d173c, Func Offset: 0x1ec
	// Line 7241, Address: 0x1d1740, Func Offset: 0x1f0
	// Line 7242, Address: 0x1d174c, Func Offset: 0x1fc
	// Line 7248, Address: 0x1d1750, Func Offset: 0x200
	// Line 7250, Address: 0x1d176c, Func Offset: 0x21c
	// Line 7253, Address: 0x1d1774, Func Offset: 0x224
	// Line 7257, Address: 0x1d177c, Func Offset: 0x22c
	// Line 7259, Address: 0x1d1784, Func Offset: 0x234
	// Line 7257, Address: 0x1d178c, Func Offset: 0x23c
	// Line 7258, Address: 0x1d1794, Func Offset: 0x244
	// Line 7259, Address: 0x1d17a0, Func Offset: 0x250
	// Line 7262, Address: 0x1d17a8, Func Offset: 0x258
	// Line 7265, Address: 0x1d17b0, Func Offset: 0x260
	// Line 7266, Address: 0x1d17b8, Func Offset: 0x268
	// Line 7269, Address: 0x1d17c4, Func Offset: 0x274
	// Line 7265, Address: 0x1d17c8, Func Offset: 0x278
	// Line 7266, Address: 0x1d17cc, Func Offset: 0x27c
	// Line 7265, Address: 0x1d17d0, Func Offset: 0x280
	// Line 7266, Address: 0x1d17d4, Func Offset: 0x284
	// Line 7267, Address: 0x1d17d8, Func Offset: 0x288
	// Line 7269, Address: 0x1d17e8, Func Offset: 0x298
	// Line 7270, Address: 0x1d17f4, Func Offset: 0x2a4
	// Line 7272, Address: 0x1d1810, Func Offset: 0x2c0
	// Line 7277, Address: 0x1d1814, Func Offset: 0x2c4
	// Line 7310, Address: 0x1d1818, Func Offset: 0x2c8
	// Line 7277, Address: 0x1d181c, Func Offset: 0x2cc
	// Line 7278, Address: 0x1d1820, Func Offset: 0x2d0
	// Line 7279, Address: 0x1d1824, Func Offset: 0x2d4
	// Line 7280, Address: 0x1d1828, Func Offset: 0x2d8
	// Line 7281, Address: 0x1d182c, Func Offset: 0x2dc
	// Line 7299, Address: 0x1d1830, Func Offset: 0x2e0
	// Line 7300, Address: 0x1d1838, Func Offset: 0x2e8
	// Line 7302, Address: 0x1d1840, Func Offset: 0x2f0
	// Line 7301, Address: 0x1d1844, Func Offset: 0x2f4
	// Line 7302, Address: 0x1d1848, Func Offset: 0x2f8
	// Line 7303, Address: 0x1d184c, Func Offset: 0x2fc
	// Line 7305, Address: 0x1d1850, Func Offset: 0x300
	// Line 7306, Address: 0x1d1858, Func Offset: 0x308
	// Line 7307, Address: 0x1d185c, Func Offset: 0x30c
	// Line 7308, Address: 0x1d1860, Func Offset: 0x310
	// Line 7312, Address: 0x1d1864, Func Offset: 0x314
	// Line 7316, Address: 0x1d1868, Func Offset: 0x318
	// Line 7312, Address: 0x1d1870, Func Offset: 0x320
	// Line 7313, Address: 0x1d1874, Func Offset: 0x324
	// Line 7314, Address: 0x1d187c, Func Offset: 0x32c
	// Line 7315, Address: 0x1d1884, Func Offset: 0x334
	// Line 7316, Address: 0x1d1888, Func Offset: 0x338
	// Line 7318, Address: 0x1d1890, Func Offset: 0x340
	// Line 7326, Address: 0x1d1894, Func Offset: 0x344
	// Line 7318, Address: 0x1d1898, Func Offset: 0x348
	// Line 7319, Address: 0x1d189c, Func Offset: 0x34c
	// Line 7320, Address: 0x1d18a0, Func Offset: 0x350
	// Line 7321, Address: 0x1d18a4, Func Offset: 0x354
	// Line 7322, Address: 0x1d18a8, Func Offset: 0x358
	// Line 7325, Address: 0x1d18ac, Func Offset: 0x35c
	// Line 7327, Address: 0x1d18b0, Func Offset: 0x360
	// Func End, Address: 0x1d1900, Func Offset: 0x3b0
}

// 
// Start address: 0x1d1900
int bhEne09_ChkDiffAngle(int pang, int dang)
{
	int ang;
	// Line 7414, Address: 0x1d1900, Func Offset: 0
	// Line 7415, Address: 0x1d1908, Func Offset: 0x8
	// Line 7418, Address: 0x1d1920, Func Offset: 0x20
	// Func End, Address: 0x1d1928, Func Offset: 0x28
}

// 
// Start address: 0x1d1930
int bhEne09_SetMtn(BH_PWORK* epw)
{
	float arm_len;
	_anon39* arm;
	int frm;
	int ret;
	npobj* obj;
	int rot_tbl2[4];
	int rot_tbl[4];
	// Line 7441, Address: 0x1d1930, Func Offset: 0
	// Line 7442, Address: 0x1d1940, Func Offset: 0x10
	// Line 7441, Address: 0x1d1944, Func Offset: 0x14
	// Line 7442, Address: 0x1d1948, Func Offset: 0x18
	// Line 7441, Address: 0x1d194c, Func Offset: 0x1c
	// Line 7442, Address: 0x1d1950, Func Offset: 0x20
	// Line 7443, Address: 0x1d1958, Func Offset: 0x28
	// Line 7442, Address: 0x1d1968, Func Offset: 0x38
	// Line 7443, Address: 0x1d196c, Func Offset: 0x3c
	// Line 7451, Address: 0x1d1974, Func Offset: 0x44
	// Line 7453, Address: 0x1d1978, Func Offset: 0x48
	// Line 7456, Address: 0x1d1990, Func Offset: 0x60
	// Line 7457, Address: 0x1d1998, Func Offset: 0x68
	// Line 7459, Address: 0x1d19ac, Func Offset: 0x7c
	// Line 7465, Address: 0x1d19c0, Func Offset: 0x90
	// Line 7473, Address: 0x1d1a00, Func Offset: 0xd0
	// Line 7475, Address: 0x1d1a04, Func Offset: 0xd4
	// Line 7473, Address: 0x1d1a08, Func Offset: 0xd8
	// Line 7475, Address: 0x1d1a0c, Func Offset: 0xdc
	// Line 7476, Address: 0x1d1a14, Func Offset: 0xe4
	// Line 7477, Address: 0x1d1a20, Func Offset: 0xf0
	// Line 7478, Address: 0x1d1a2c, Func Offset: 0xfc
	// Line 7479, Address: 0x1d1a38, Func Offset: 0x108
	// Line 7480, Address: 0x1d1a44, Func Offset: 0x114
	// Line 7482, Address: 0x1d1a50, Func Offset: 0x120
	// Line 7484, Address: 0x1d1a54, Func Offset: 0x124
	// Line 7487, Address: 0x1d1a5c, Func Offset: 0x12c
	// Line 7488, Address: 0x1d1a68, Func Offset: 0x138
	// Line 7489, Address: 0x1d1a6c, Func Offset: 0x13c
	// Line 7490, Address: 0x1d1a80, Func Offset: 0x150
	// Line 7492, Address: 0x1d1a88, Func Offset: 0x158
	// Line 7493, Address: 0x1d1a94, Func Offset: 0x164
	// Line 7494, Address: 0x1d1aa0, Func Offset: 0x170
	// Line 7495, Address: 0x1d1aac, Func Offset: 0x17c
	// Line 7496, Address: 0x1d1ab4, Func Offset: 0x184
	// Line 7499, Address: 0x1d1abc, Func Offset: 0x18c
	// Line 7500, Address: 0x1d1adc, Func Offset: 0x1ac
	// Line 7501, Address: 0x1d1af4, Func Offset: 0x1c4
	// Line 7502, Address: 0x1d1b0c, Func Offset: 0x1dc
	// Line 7507, Address: 0x1d1b20, Func Offset: 0x1f0
	// Line 7509, Address: 0x1d1b38, Func Offset: 0x208
	// Line 7511, Address: 0x1d1b3c, Func Offset: 0x20c
	// Line 7509, Address: 0x1d1b48, Func Offset: 0x218
	// Line 7510, Address: 0x1d1b4c, Func Offset: 0x21c
	// Line 7511, Address: 0x1d1b54, Func Offset: 0x224
	// Line 7512, Address: 0x1d1b5c, Func Offset: 0x22c
	// Line 7513, Address: 0x1d1b64, Func Offset: 0x234
	// Line 7515, Address: 0x1d1b74, Func Offset: 0x244
	// Line 7517, Address: 0x1d1b78, Func Offset: 0x248
	// Line 7515, Address: 0x1d1b84, Func Offset: 0x254
	// Line 7516, Address: 0x1d1b88, Func Offset: 0x258
	// Line 7517, Address: 0x1d1b8c, Func Offset: 0x25c
	// Line 7518, Address: 0x1d1b94, Func Offset: 0x264
	// Line 7519, Address: 0x1d1b9c, Func Offset: 0x26c
	// Line 7521, Address: 0x1d1bac, Func Offset: 0x27c
	// Line 7522, Address: 0x1d1bb4, Func Offset: 0x284
	// Line 7525, Address: 0x1d1bbc, Func Offset: 0x28c
	// Line 7526, Address: 0x1d1bc0, Func Offset: 0x290
	// Line 7525, Address: 0x1d1bcc, Func Offset: 0x29c
	// Line 7526, Address: 0x1d1bd4, Func Offset: 0x2a4
	// Line 7528, Address: 0x1d1bd8, Func Offset: 0x2a8
	// Line 7526, Address: 0x1d1bdc, Func Offset: 0x2ac
	// Line 7528, Address: 0x1d1c0c, Func Offset: 0x2dc
	// Line 7531, Address: 0x1d1c20, Func Offset: 0x2f0
	// Line 7533, Address: 0x1d1c2c, Func Offset: 0x2fc
	// Line 7535, Address: 0x1d1c30, Func Offset: 0x300
	// Line 7533, Address: 0x1d1c34, Func Offset: 0x304
	// Line 7534, Address: 0x1d1c38, Func Offset: 0x308
	// Line 7535, Address: 0x1d1c48, Func Offset: 0x318
	// Line 7536, Address: 0x1d1c54, Func Offset: 0x324
	// Line 7540, Address: 0x1d1c64, Func Offset: 0x334
	// Line 7542, Address: 0x1d1c74, Func Offset: 0x344
	// Line 7543, Address: 0x1d1c78, Func Offset: 0x348
	// Line 7542, Address: 0x1d1c7c, Func Offset: 0x34c
	// Line 7543, Address: 0x1d1c80, Func Offset: 0x350
	// Line 7544, Address: 0x1d1cac, Func Offset: 0x37c
	// Line 7546, Address: 0x1d1cc4, Func Offset: 0x394
	// Line 7547, Address: 0x1d1cd4, Func Offset: 0x3a4
	// Line 7548, Address: 0x1d1cd8, Func Offset: 0x3a8
	// Line 7549, Address: 0x1d1ce0, Func Offset: 0x3b0
	// Line 7551, Address: 0x1d1cec, Func Offset: 0x3bc
	// Line 7553, Address: 0x1d1d04, Func Offset: 0x3d4
	// Line 7561, Address: 0x1d1d10, Func Offset: 0x3e0
	// Line 7563, Address: 0x1d1d20, Func Offset: 0x3f0
	// Line 7566, Address: 0x1d1d3c, Func Offset: 0x40c
	// Line 7577, Address: 0x1d1d48, Func Offset: 0x418
	// Line 7579, Address: 0x1d1d54, Func Offset: 0x424
	// Line 7580, Address: 0x1d1d58, Func Offset: 0x428
	// Func End, Address: 0x1d1d74, Func Offset: 0x444
}

// 
// Start address: 0x1d1d80
void bhEne09_MtnTblPlay(BH_PWORK* epw, int frm)
{
	int i;
	_anon25 vec2;
	_anon25 vec;
	_anon6* mtbl3;
	_anon6* mtbl2;
	_anon1* mtbl;
	// Line 7586, Address: 0x1d1d80, Func Offset: 0
	// Line 7587, Address: 0x1d1da0, Func Offset: 0x20
	// Line 7588, Address: 0x1d1da8, Func Offset: 0x28
	// Line 7589, Address: 0x1d1db0, Func Offset: 0x30
	// Line 7591, Address: 0x1d1db8, Func Offset: 0x38
	// Line 7595, Address: 0x1d1dd4, Func Offset: 0x54
	// Line 7591, Address: 0x1d1dd8, Func Offset: 0x58
	// Line 7595, Address: 0x1d1de0, Func Offset: 0x60
	// Line 7598, Address: 0x1d1dfc, Func Offset: 0x7c
	// Line 7600, Address: 0x1d1e10, Func Offset: 0x90
	// Line 7602, Address: 0x1d1e18, Func Offset: 0x98
	// Line 7604, Address: 0x1d1e24, Func Offset: 0xa4
	// Line 7606, Address: 0x1d1e30, Func Offset: 0xb0
	// Line 7610, Address: 0x1d1e60, Func Offset: 0xe0
	// Line 7613, Address: 0x1d1eb4, Func Offset: 0x134
	// Line 7614, Address: 0x1d1eb8, Func Offset: 0x138
	// Line 7615, Address: 0x1d1ebc, Func Offset: 0x13c
	// Line 7616, Address: 0x1d1ec4, Func Offset: 0x144
	// Line 7617, Address: 0x1d1ec8, Func Offset: 0x148
	// Line 7619, Address: 0x1d1ee0, Func Offset: 0x160
	// Line 7620, Address: 0x1d1ef8, Func Offset: 0x178
	// Line 7623, Address: 0x1d1f00, Func Offset: 0x180
	// Line 7625, Address: 0x1d1f18, Func Offset: 0x198
	// Line 7626, Address: 0x1d1f28, Func Offset: 0x1a8
	// Line 7627, Address: 0x1d1f34, Func Offset: 0x1b4
	// Line 7630, Address: 0x1d1f3c, Func Offset: 0x1bc
	// Line 7631, Address: 0x1d1f40, Func Offset: 0x1c0
	// Line 7632, Address: 0x1d1f44, Func Offset: 0x1c4
	// Line 7633, Address: 0x1d1f4c, Func Offset: 0x1cc
	// Line 7634, Address: 0x1d1f50, Func Offset: 0x1d0
	// Line 7636, Address: 0x1d1f68, Func Offset: 0x1e8
	// Line 7637, Address: 0x1d1f80, Func Offset: 0x200
	// Line 7640, Address: 0x1d1f88, Func Offset: 0x208
	// Line 7642, Address: 0x1d1fa0, Func Offset: 0x220
	// Line 7643, Address: 0x1d1fb0, Func Offset: 0x230
	// Line 7644, Address: 0x1d1fbc, Func Offset: 0x23c
	// Line 7647, Address: 0x1d1fc4, Func Offset: 0x244
	// Line 7648, Address: 0x1d1fdc, Func Offset: 0x25c
	// Line 7649, Address: 0x1d1fec, Func Offset: 0x26c
	// Line 7650, Address: 0x1d1ffc, Func Offset: 0x27c
	// Line 7653, Address: 0x1d2008, Func Offset: 0x288
	// Line 7655, Address: 0x1d2010, Func Offset: 0x290
	// Line 7657, Address: 0x1d2020, Func Offset: 0x2a0
	// Line 7658, Address: 0x1d2024, Func Offset: 0x2a4
	// Line 7663, Address: 0x1d2038, Func Offset: 0x2b8
	// Line 7665, Address: 0x1d2040, Func Offset: 0x2c0
	// Line 7667, Address: 0x1d204c, Func Offset: 0x2cc
	// Line 7669, Address: 0x1d2058, Func Offset: 0x2d8
	// Line 7671, Address: 0x1d2068, Func Offset: 0x2e8
	// Line 7673, Address: 0x1d2070, Func Offset: 0x2f0
	// Line 7674, Address: 0x1d207c, Func Offset: 0x2fc
	// Line 7675, Address: 0x1d2080, Func Offset: 0x300
	// Line 7677, Address: 0x1d2090, Func Offset: 0x310
	// Line 7678, Address: 0x1d2094, Func Offset: 0x314
	// Line 7681, Address: 0x1d20a8, Func Offset: 0x328
	// Line 7683, Address: 0x1d20b8, Func Offset: 0x338
	// Line 7685, Address: 0x1d20c0, Func Offset: 0x340
	// Line 7687, Address: 0x1d20cc, Func Offset: 0x34c
	// Line 7689, Address: 0x1d20d8, Func Offset: 0x358
	// Line 7691, Address: 0x1d20e8, Func Offset: 0x368
	// Line 7693, Address: 0x1d20f0, Func Offset: 0x370
	// Line 7695, Address: 0x1d20f8, Func Offset: 0x378
	// Line 7697, Address: 0x1d2108, Func Offset: 0x388
	// Line 7698, Address: 0x1d210c, Func Offset: 0x38c
	// Line 7700, Address: 0x1d2120, Func Offset: 0x3a0
	// Func End, Address: 0x1d2144, Func Offset: 0x3c4
}

// 
// Start address: 0x1d2150
void bhEne09_SePlay(BH_PWORK* epw, int no)
{
	// Line 7720, Address: 0x1d2150, Func Offset: 0
	// Line 7721, Address: 0x1d215c, Func Offset: 0xc
	// Line 7723, Address: 0x1d2170, Func Offset: 0x20
	// Line 7724, Address: 0x1d218c, Func Offset: 0x3c
	// Func End, Address: 0x1d2198, Func Offset: 0x48
}

// 
// Start address: 0x1d21a0
void bhEne09_SetSmokeEffect(BH_PWORK* epw, _anon25* ofs, int rot)
{
	int i;
	int eno;
	float en09_eff_tbl[4];
	// Line 7746, Address: 0x1d21a0, Func Offset: 0
	// Line 7751, Address: 0x1d21b8, Func Offset: 0x18
	// Line 7752, Address: 0x1d21c8, Func Offset: 0x28
	// Line 7751, Address: 0x1d21cc, Func Offset: 0x2c
	// Line 7752, Address: 0x1d21d8, Func Offset: 0x38
	// Line 7754, Address: 0x1d21e0, Func Offset: 0x40
	// Line 7763, Address: 0x1d21e8, Func Offset: 0x48
	// Line 7752, Address: 0x1d21ec, Func Offset: 0x4c
	// Line 7753, Address: 0x1d21f8, Func Offset: 0x58
	// Line 7754, Address: 0x1d220c, Func Offset: 0x6c
	// Line 7755, Address: 0x1d2220, Func Offset: 0x80
	// Line 7756, Address: 0x1d2234, Func Offset: 0x94
	// Line 7757, Address: 0x1d2248, Func Offset: 0xa8
	// Line 7758, Address: 0x1d225c, Func Offset: 0xbc
	// Line 7759, Address: 0x1d2270, Func Offset: 0xd0
	// Line 7761, Address: 0x1d2284, Func Offset: 0xe4
	// Line 7765, Address: 0x1d229c, Func Offset: 0xfc
	// Line 7766, Address: 0x1d22f0, Func Offset: 0x150
	// Line 7768, Address: 0x1d2318, Func Offset: 0x178
	// Line 7766, Address: 0x1d231c, Func Offset: 0x17c
	// Line 7768, Address: 0x1d2334, Func Offset: 0x194
	// Line 7766, Address: 0x1d233c, Func Offset: 0x19c
	// Line 7768, Address: 0x1d2354, Func Offset: 0x1b4
	// Line 7769, Address: 0x1d236c, Func Offset: 0x1cc
	// Line 7771, Address: 0x1d2378, Func Offset: 0x1d8
	// Line 7773, Address: 0x1d239c, Func Offset: 0x1fc
	// Line 7771, Address: 0x1d23a0, Func Offset: 0x200
	// Line 7772, Address: 0x1d23a8, Func Offset: 0x208
	// Line 7774, Address: 0x1d23b4, Func Offset: 0x214
	// Line 7775, Address: 0x1d23e8, Func Offset: 0x248
	// Line 7774, Address: 0x1d23ec, Func Offset: 0x24c
	// Line 7775, Address: 0x1d23f8, Func Offset: 0x258
	// Line 7776, Address: 0x1d2400, Func Offset: 0x260
	// Line 7777, Address: 0x1d240c, Func Offset: 0x26c
	// Line 7779, Address: 0x1d2410, Func Offset: 0x270
	// Line 7780, Address: 0x1d2420, Func Offset: 0x280
	// Func End, Address: 0x1d243c, Func Offset: 0x29c
}*/

