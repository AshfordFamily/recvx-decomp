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

int En09_PlyMtn_OffsetTbl[4] =
{
    0x00000064,
    0x0000006E,
    0x00000078,
    0x0000006E
};

float en09_mtn23[35] =
{
    0,
    0.8460479975,
    0.9654740095,
    0.8990900517,
    0.7489609718,
    0.6820127964,
    0.6796393394,
    0.7418408394,
    0.8686180115,
    0.9701399803,
    1.013323784,
    1.071469307,
    1.144568443,
    1.232629776,
    1.335645676,
    0.2317342758,
    0.207318306,
    0.1867198944,
    0.1699371338,
    0.1569738388,
    0.1478261948,
    0.142496109,
    0.1409835815,
    0.1288032532,
    0.1071634293,
    0.09115505219,
    0.08077430725,
    0.07602500916,
    0.07888698578,
    0.08192253113,
    0.07942676544,
    0.07140254974,
    0.05784797668,
    0.03876399994,
    0.01414966583
};

/*
_anon1 en09_mtn_tbl[28];
_anon6 en09_mtn_tbl2[24];
_anon6 en09_mtn_tbl3[5];
_anon40 en09_BldTbl;
_anon40 en09_BldTbl2;
_anon20 en09_lkmtab;
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

// 100% matching!
void bhEne09_ChgDmgMode(BH_PWORK* epw)
{
	WPNDAMAGE_WORK* wp_tbl = En09_WpnDamageTbl;
    int act;

    wp_tbl += epw->wpnr_no;
    act = wp_tbl->nm_act;
    
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

// 99.98% matching!
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
            
            obj = epw->mlwP->objP + 7;
            
            obj[0].pos[0]  = EXP0_F(0x0);
            obj[1].pos[0]  = EXP0_F(0x4);
            obj[2].pos[0]  = EXP0_F(0x8);
            obj[3].pos[0] = EXP0_F(0xC);
            
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
            
            obj = epw->mlwP->objP + 7;
            
            obj[0].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[1].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[2].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[3].pos[0] += EXP0_F(0x74) / 4.0f;
            
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
                
                obj = epw->mlwP->objP + 7;
                
                obj[0].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[1].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 4.0f;
                obj[3].pos[0] -= EXP0_F(0x74) / 4.0f;
                
                EXP0_F(0x74) -= nn;
                
                obj[0].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[1].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[2].pos[0] += EXP0_F(0x74) / 4.0f;
                obj[3].pos[0] += EXP0_F(0x74) / 4.0f;
                
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
                
                obj = epw->mlwP->objP + 7;
                
                EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
                EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
                EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
                EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
                
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
                obj = epw->mlwP->objP + 7;
                
                obj[0].pos[0] -= EXP0_F(0x6C) / epw->ct1;
                obj[1].pos[0] -= EXP0_F(0x70) / epw->ct1;
                obj[2].pos[0] -= EXP0_F(0x74) / epw->ct1;
                obj[3].pos[0] -= EXP0_F(0x78) / epw->ct1;
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
                
                EXP0_F(0x5C) = ((EXP0_F(0x60) - 0.143332f) - epw->py) / 12.0f;
                
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

// 100% matching!
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
            
            obj = epw->mlwP->objP + 7;
            
            obj[0].pos[0]  = EXP0_F(0x0);
            obj[1].pos[0]  = EXP0_F(0x4);
            obj[2].pos[0]  = EXP0_F(0x8);
            obj[3].pos[0] = EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            owk = plp->mlwP->owP;
            
            rot = ikou3(epw, (NJS_VECTOR*)&owk->mtx[0xC], epw->way);
            
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
            
            EXP0_F(0x74) = 10.0f - (1.2f * epw->ct1);
            
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
            
            obj = epw->mlwP->objP + 7;
            
            obj[0].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[1].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[2].pos[0] += EXP0_F(0x74) / 4.0f;
            obj[3].pos[0] += EXP0_F(0x74) / 4.0f;
            
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
                obj = epw->mlwP->objP + 7;
                
                EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
                EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
                EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
                EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
                
                epw->ct1 = 8;
                epw->ct0 = 0;
                epw->mode3++;
            }
            
            bhEne09_CollChkArm2(epw);
            
            break;
        
        case 4:
            if (epw->ct1 > epw->ct0)
            {
                obj = epw->mlwP->objP + 7;
                
                obj[0].pos[0] -= EXP0_F(0x6C) / epw->ct1;
                obj[1].pos[0] -= EXP0_F(0x70) / epw->ct1;
                obj[2].pos[0] -= EXP0_F(0x74) / epw->ct1;
                obj[3].pos[0] -= EXP0_F(0x78) / epw->ct1;
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

// 100% matching!
void bhEne09_PlyDG00(BH_PWORK* pl, BH_PWORK* epw) 
{
	static NJS_POINT3 ply_ofs_pos[8] =
    {
        {  0.0102239996f, 0.000000000f, -20.71177101f },
        { -0.0102260001f, 0.000000000f, -20.71356964f },
        {  0.0102239996f, 0.000000000f, -20.50097275f },
        { -0.0102260001f, 0.000000000f, -20.31103706f },
        {  0.0102239996f, 0.000000000f, -20.71177101f },
        { -0.0102260001f, 0.000000000f, -20.71356964f },
        {  0.0102239996f, 0.000000000f, -20.50097275f },
        { -0.0102260001f, 0.000000000f, -20.31103706f },
    };
    O_WORK *owk;
    NJS_POINT3 pd;
    NJS_POINT3 ps;
    int frm;
    int id;
    int i;
    
    switch (pl->mode3)
    {
        case 0:
            pl->flg &= 0xFFFBFFFF;
            pl->flg |= 0x10000;
            pl->mode3++;
            
            *(int *)(plp->exp1 + 0x0) |= 0x1E0;
            
            *(int *)(plp->exp1 + 0x0) &= ~4;
            
            if (EXP0_I(0x18) & 0x400) 
            {
                id = sys->ply_id * 2;
                
                epw->wax = -0x8000;
                
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id];
            } 
            else 
            {
                id = (sys->ply_id * 2) + 1;
                
                epw->wax = 0;
                
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 1;
            }
            
            EXP0_F(0x38) = ply_ofs_pos[id].x;
            EXP0_F(0x3C) = ply_ofs_pos[id].y;
            EXP0_F(0x40) = ply_ofs_pos[id].z;
            
            pl->ay = (epw->ay + epw->wax) & 0xFFFF;
            pl->mnwP = epw->mnwP;
            pl->frm_no = 0x30000;
            pl->hokan_count = 0;
            pl->hokan_rate = 0xC000;
            pl->mtn_add = 0x10000;
            pl->mtn_md = 0;
            pl->ct0 = 0;
            pl->ct1 = 0;
            
            EXP0_I(0x18) |= 0x200000;
            
            bhEne_PlayerSePlay(epw, 0x402);
            
            owk = plp->mlwP->owP;
            
            ps.x = owk[1].mtx[12];
            ps.z = owk[1].mtx[14];
            ps.y = 1.0f + epw->py;
            
            for (i = 0; i < 6; i++)
            {
                bhEne09_SetSmokeEffect(epw, &ps, epw->ay + NJM_DEG_ANG(247.5f) + (i * NJM_DEG_ANG(45.0f)));
            } 
        
            /* fallthrough */
        case 1:
            frm = pl->frm_no >> 0x10;
            
            if (frm != 0x1B)
            {
                if (frm == 0x47)
                {
                    bhEne_PlayerSePlay(epw, 0x402);
                }
                else if ((frm == 0x69) || (frm == 0x72))
                {
                    bhEne09_SePlay(epw, 0x230D);
                }
            }
            
            if (frm == 0x46) 
            {
                ps.x = 0;
                ps.y = 0.5f;
                ps.z = 0;
            
                plp->djnt_no = 5;
                
                bhSetEffParticle(plp, plp->djnt_no, &ps, &pd, 0xffffffffff5f0000, 0xc);
                bhSetEffParticle(plp, plp->djnt_no, &ps, &pd, 0xffffffffff5f0000, 0xc);
                bhSetEffParticle(plp, plp->djnt_no, &ps, &pd, 0xffffffffff5f0000, 0xc);
                
                sys->ef.flg = 1;
                sys->ef.px = 0.0f;
                sys->ef.py = 0.0f;
                sys->ef.pz = 0.0f;
                sys->ef.sx = 2.0f;
                sys->ef.sy = 2.0f;
                sys->ef.sz = 0.0f;
                sys->ef.ay = 0;
                sys->ef.mdlver = 0;
                sys->ef.id = 5;
                sys->ef.type = 2;
                
                ps.x = 0;
                ps.y = 0.5f;
                ps.z = 0;
                
                bhSetEffectTb(&sys->ef, &ps, (unsigned char *)plp, plp->djnt_no);
            }
            
            if ((pl->frm_no >> 0x10) == 0x3C)
            {
                pl->flg |= 2;
            }
            
            if ((pl->frm_no >> 0x10) == (pl->mnwP[pl->mtn_no].frm_num - 1)) 
            {
                pl->mtn_add = 0;
                
                EXP0_I(0x18) &= 0xFFDFFFFF;
                EXP0_I(0x18) &= 0xFFBFFFFF;
                
                pl->mode3++;
                pl->ct0 = 1;
                pl->ct1 = 0x73;
            }
            
            break;
        
        case 2:
            if (--pl->ct0 < 0)
            {
                sys->pad_on &= ~0xF;
                pl->flg &= 0xFFFEFFFF;
                pl->stflg &= 0xFFFEFFFF;
                pl->at_flg = 0;
                pl->stflg |= 0x40000;
                pl->flg &= ~4;
                pl->hp = -1;
                
                EXP0_I(0x18) &= 0xFFBFFFFF;
            }
    }
}

// 100% matching!
void bhEne09_PlyDG01(BH_PWORK* pl, BH_PWORK* epw) 
{
    static NJS_POINT3 ply_ofs_pos[8] =
    {
        { 0.6000000238f, 0.000000000f, 0.4000000060f },
        { 0.0000000000f, 0.000000000f, 0.0000000000f },
        { 0.6999999881f, 0.000000000f, 0.0000000000f },
        { 0.0000000000f, 0.000000000f, 0.0000000000f },
        { 0.6000000238f, 0.000000000f, 0.4000000060f },
        { 0.0000000000f, 0.000000000f, 0.0000000000f },
        { 0.6999999881f, 0.000000000f, 0.0000000000f },
        { 0.0000000000f, 0.000000000f, 0.0000000000f },
    };
    O_WORK *owk;
    NJS_POINT3 ps;
    int frm;
    int id;
    int i;

    switch (pl->mode3)
    {
        case 0:
            pl->flg &= 0xFFFBFFFF;
            pl->flg |= 0x10000;
            pl->mode3++;
            
            *(int *)(plp->exp1 + 0x0) |= 0x1E0;
            *(int *)(plp->exp1 + 0x0) &= ~4;
            
            if (EXP0_I(0x18) & 0x400) 
            {
                id = sys->ply_id * 2;
                
                epw->wax = -0x8000;
                
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 4;
            } 
            else 
            {
                id = (sys->ply_id * 2) + 1;
                
                epw->wax = 0;
                
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 5;
            }
            
            EXP0_F(0x38) = ply_ofs_pos[id].x;
            EXP0_F(0x3C) = ply_ofs_pos[id].y;
            EXP0_F(0x40) = ply_ofs_pos[id].z;
            
            pl->ay = (epw->ay + epw->wax) & 0xFFFF;
            pl->mnwP = epw->mnwP;
            pl->frm_no = 0x20000;
            pl->hokan_count = 0;
            pl->hokan_rate = 0xC000;
            pl->mtn_add = 0x10000;
            pl->mtn_md = 0;
            pl->ct0 = 0;
            pl->ct1 = 0;
            pl->flg2 |= 1;
            
            EXP0_I(0x18) |= 0x800000;
            
            bhEne_PlayerSePlay(epw, 0x402);
            
            owk = plp->mlwP->owP;
            
            ps.x = owk[1].mtx[12];
            ps.z = owk[1].mtx[14];
            ps.y = 1.0f + epw->py;
            
            for (i = 0; i < 6; i++)
            {
                bhEne09_SetSmokeEffect(epw, &ps, epw->ay + NJM_DEG_ANG(247.5f) + (i * NJM_DEG_ANG(45.0f)));
            } 
            
            break;

        case 1:
            break;
        
        case 2:
            if (EXP0_I(0x18) & 0x400) 
            {
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 6;
            } 
            else 
            {
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 7;
            }
            
            pl->frm_no = 0;
            pl->hokan_count = 0;
            pl->mode3++;
            
            break;
        
        case 3:
            if ((pl->frm_no >> 0x10) >= 0x14)
            {
                EXP0_I(0x18) &= 0xFF7FFFFF;
            }
            
            if ((pl->frm_no >> 0x10) == 0) 
            {
                sys->pad_on &= ~0xF;
                pl->flg &= 0xFFFEFFFB;
                pl->flg2 &= ~1;
                pl->flg |= 8;
                pl->stflg &= 0xFFFEFFFF;
                pl->at_flg = 0;
                pl->mnwP = pl->mnwPb;
                
                EXP0_I(0x18) &= 0xFBBFFFFF;
                
                *(int *)&pl->mode0 = 1;
            }
            
            break;
        
        case 4:
            if (EXP0_I(0x18) & 0x400) 
            {
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 8;
            } 
            else 
            {
                pl->mtn_no = En09_PlyMtn_OffsetTbl[sys->ply_id] + 9;
            }
            
            pl->frm_no = 0;
            pl->hokan_count = 0;
            pl->flg |= 0x40000;
            pl->stflg |= 0x40000;
            
            EXP0_I(0x18) &= 0xFF7FFFFF;
            
            bhEne_PlayerSePlay(epw, 0x401);
            
            pl->hp = -1;
            pl->mode3++;
        
            /* fallthrough */
        case 5:
            frm = pl->frm_no >> 0x10;
            
            if (pl->mtn_no == (En09_PlyMtn_OffsetTbl[sys->ply_id] + 8)) 
            {
                if (frm < 5) 
                {
                    pl->flg |= 0x80000;
                }
                else 
                {
                    pl->flg &= 0xFFF7FFFF;
                }
            } 
            else 
            {
                pl->flg &= 0xFFF7FFFF;
            }
            
            if (pl->mtn_no == (En09_PlyMtn_OffsetTbl[sys->ply_id] + 8))
            {
                if ((frm == 0x2F) || (frm == 0x33))
                {
                    bhEne09_SePlay(epw, 0x230D);
                }
            }
            else if ((frm == 0x1E) || (frm == 0x33))
            {
                bhEne09_SePlay(epw, 0x230D);
            }
            
            if ((pl->frm_no >> 0x10) == (pl->mnwP[pl->mtn_no].frm_num - 1)) 
            {
                pl->mtn_add = 0;
                pl->flg |= 2;
                pl->flg2 &= ~1;
            }
    }
}

// 99.94% matching!
int bhEne09_PlyNageCheck(BH_PWORK* epw, BH_PWORK* pl, float h) 
{   
	ATR_WORK *hp;
    ATR_WORK *hp2;
    NJS_SPHERE at;
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    int rot;

    pos.x = epw->px;
    pos.y = epw->py + h;
    pos.z = epw->pz;
    
    pos2.x = pl->px;
    pos2.y = epw->py + h;
    pos2.z = pl->pz;
    
    if (!(plp->flg & 2)) 
    {
        if (!(plp->flg & 4) && !(plp->stflg & 0x80000000) && (plp->hp >= 0)) 
        {
            bhEne_CalcPartsPos(epw, lcmat, &at.c, en09_tree[2], 10, 1);
            
            at.r = 2.0f;
            
            if (npCollisionCheckSC(&at, &plp->watr) != 0) 
            {
                hp = bhCollisionCheckLine(&pos, &pos2);
                
                at.c.y = plp->py;
                
                hp2 = bhCheckWallType(&at.c, 0, 0.5f + plp->ar, plp->ah);
                
                if ((hp == NULL) && (hp2 == NULL)) 
                {
                    return 1;
                }
                
                plp->djnt_no = 2;
                
                plp->dpx = at.c.x;
                plp->dpy = at.c.y;
                plp->dpz = at.c.z;
                
                bhEne_HitCheckParts(plp, &at.c);
                
                plp->flg |= 4;
                plp->mode0 = 2;
                plp->mode2 = 1;
                plp->mode3 = 0;
                plp->hp -= 0xA;
                
                rot = (NitenDir_ck(plp->px, plp->pz, epw->px, epw->pz) - plp->ay) & 0xFFFF;
                
                if ((rot <= 0x4000) || (rot > 0xC000)) 
                {
                    plp->mode1 = 0;
                }
                else 
                {
                    plp->mode1 = 1;
                }
                
                bhEne09_SePlay(epw, 0x12307);
                bhEne_SetVibration(1);
                
                return 2;
            }
        }
    }
    
    return 0;
}

// 100% matching!
void bhEne09_DGType00(BH_PWORK* epw)
{
    bhEne09_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne09_DG00(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;
    int mtn_no;

    switch (epw->mode3) 
    {
        case 0:
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            epw->way = 0x16C;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg2 &= ~1;
            
            if (EXP0_I(0x18) & 0x200) 
            {
                if (EXP0_I(0x18) & 0x8000) 
                {
                    mtn_no = 0x43;
                }
                else
                {
                    mtn_no = 0x25;
                }
            }
            else 
            {
                if (EXP0_I(0x18) & 0x8000)
                {
                    mtn_no = 0x42;
                }
                else
                {
                    mtn_no = 0x24;
                }
            }
            
            bhEne_ChgMtn(epw, mtn_no, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            if ((epw->frm_no >> 0x10) == 5) 
            {
                EXP0_I(0x18) &= 0xFFFF7FFF;
                
                if ((epw->flr_no == plp->flr_no) && (EXP0_F(0x28) > 15.0f) && ikou3(epw, (NJS_VECTOR *)&plp->px, 0x6000))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 8;
                    epw->mode3 = 0;
                }
                else
                {
                    epw->mode0 = 1;
                    epw->mode1 = 1;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                }
            }
            
            obj = epw->mlwP->objP + 7;
            
            if (epw->ct0 < 6) 
            {
                obj[0].pos[0] -= EXP0_F(0x6C) / 6.0f;
                obj[1].pos[0] -= EXP0_F(0x70) / 6.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 6.0f;
                obj[3].pos[0] -= EXP0_F(0x78) / 6.0f;
            }
            else 
            {
                obj[0].pos[0] = EXP0_F(0x0);
                obj[1].pos[0] = EXP0_F(0x4);
                obj[2].pos[0] = EXP0_F(0x8);
                obj[3].pos[0] = EXP0_F(0xC);
            }
            
            epw->ct0++;
    }
}

// 100% matching!
void bhEne09_DG01(BH_PWORK* epw)
{
    NJS_CNK_OBJECT *obj;
    int mtn_no;

    switch (epw->mode3) 
    {
        case 0:
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            epw->way = 0x16C;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg2 &= ~1;
            
            if (EXP0_I(0x18) & 0x200) 
            {
                if (EXP0_I(0x18) & 0x8000) 
                {
                    mtn_no = 0x41;
                }
                else
                {
                    mtn_no = 0x23;
                }
            }
            else 
            {
                if (EXP0_I(0x18) & 0x8000)
                {
                    mtn_no = 0x40;
                }
                else
                {
                    mtn_no = 0x22;
                }
            }
            
            bhEne_ChgMtn(epw, mtn_no, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            mtn_no = epw->mtn_no;
            
            if ((((mtn_no == 0x23) || (mtn_no == 0x41)) && ((epw->frm_no >> 0x10) == 9)) 
                || ((epw->frm_no >> 0x10) == (epw->mnwP[mtn_no].frm_num - 1))) 
            {
                EXP0_I(0x18) &= 0xFFFF7FFF;
                
                if ((epw->flr_no == plp->flr_no) && (EXP0_F(0x28) > 15.0f) && ikou3(epw, (NJS_VECTOR *)&plp->px, 0x6000))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 8;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 1;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                }
                
                
            }
            
            obj = epw->mlwP->objP + 7;
            
            if (epw->ct0 < 6) 
            {
                obj[0].pos[0] -= EXP0_F(0x6C) / 6.0f;
                obj[1].pos[0] -= EXP0_F(0x70) / 6.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 6.0f;
                obj[3].pos[0] -= EXP0_F(0x78) / 6.0f;
            }
            else 
            {
                obj[0].pos[0] = EXP0_F(0x0);
                obj[1].pos[0] = EXP0_F(0x4);
                obj[2].pos[0] = EXP0_F(0x8);
                obj[3].pos[0] = EXP0_F(0xC);
            }
            
            epw->ct0++;
    }
}

// 100% matching!
void bhEne09_DG02(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;
    int mtn_no;

    switch (epw->mode3) 
    {
        case 0:
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            epw->way = 0x16C;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg2 &= ~1;
            
            if (EXP0_I(0x18) & 0x200) 
            {
                if (EXP0_I(0x18) & 0x8000) 
                {
                    mtn_no = 0x3F;
                }
                else
                {
                    mtn_no = 0x21;
                }
            }
            else 
            {
                if (EXP0_I(0x18) & 0x8000)
                {
                    mtn_no = 0x3E;
                }
                else
                {
                    mtn_no = 0x20;
                }
            }
            
            bhEne_ChgMtn(epw, mtn_no, 0, 5);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            
            epw->flg |= 0x40000;
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            mtn_no = epw->mtn_no;
                
            if (
                (((mtn_no == 0x21) || (mtn_no == 0x3F)) && ((epw->frm_no >> 0x10) >= 0x1A))
                ||
                (((mtn_no == 0x20) || (mtn_no == 0x3E)) && ((epw->frm_no >> 0x10) == 0x16))
            )
            {
                EXP0_I(0x18) &= 0xFFFF7FFF;
                        
                if ((epw->flr_no == plp->flr_no) && (EXP0_F(0x28) > 15.0f) && ikou3(epw, (NJS_VECTOR *)&plp->px, 0x6000))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 8;
                    epw->mode3 = 0;
                } 
                else 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 1;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                }
            }
            
            obj = epw->mlwP->objP + 7;
            
            if (epw->ct0 < 6) 
            {
                obj[0].pos[0] -= EXP0_F(0x6C) / 6.0f;
                obj[1].pos[0] -= EXP0_F(0x70) / 6.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 6.0f;
                obj[3].pos[0] -= EXP0_F(0x78) / 6.0f;
            }
            else 
            {
                obj[0].pos[0] = EXP0_F(0x0);
                obj[1].pos[0] = EXP0_F(0x4);
                obj[2].pos[0] = EXP0_F(0x8);
                obj[3].pos[0] = EXP0_F(0xC);
            }
            
            epw->ct0++;
    }
}

// 100% matching!
void bhEne09_DG03(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;
    NJS_POINT3 pos;
    int ang;
    int frm;
    
    switch (epw->mode3) 
    {
        case 0:
            EXP0_I(0x18) &= ~0xF;
            EXP0_I(0x18) |= 3;
            EXP0_I(0x18) &= ~0x30;
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg &= ~0x100;
            epw->flg2 &= ~1;
            epw->flg &= ~0x20;
            
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            if (EXP0_I(0x18) & 0x8000) 
            {
                bhEne_ChgMtn(epw, 0x3D, 0, 0xA);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
            } 
            else 
            {
                bhEne_ChgMtn(epw, 0x17, 0, 0xA);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
            }
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->ayp = (int)(10430.381f * atan2f(epw->dvx, epw->dvz));
            
            frm = epw->frm_no >> 0x10;
            
            epw->ct0 = 0;
            epw->mode3++;
            
            break;
        
        case 1:
            frm = epw->frm_no >> 0x10;
            
            if (frm < 0xA) 
            {
                ang = (epw->ayp - epw->ay) & 0xFFFF;
                
                if (ang > 0x8000) 
                {
                    ang = ((ang - 0x8000) - 0x8000);
                }
                else
                {
                    ang = ang;
                }
                
                epw->ay += ang >> 1;
            }
            
            if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
            {
                epw->mtn_add = 0;
                
                if (epw->hokan_count == 0) 
                {
                    EXP0_I(0x18) &= 0xFFFF3F7F;
                    EXP0_I(0x18) &= ~0xF;
                    EXP0_I(0x18) |= 1;
                    
                    if (epw->hp < 0) 
                    {
                        epw->mode0 = 4;
                        epw->mode1 = 0;
                        epw->mode2 = 0;
                        epw->mode3 = 0;
                    }
                    else 
                    {
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        epw->mode2 = 3;
                        epw->mode3 = 0;
                        
                        EXP0_I(0x18) |= 0x2040;
                    }
                }
            } 
            else 
            {
                obj = epw->mlwP->objP + 7;
            
                if (epw->ct0 < 6) 
                {
                    obj[0].pos[0] -= EXP0_F(0x6C) / 6.0f;
                    obj[1].pos[0] -= EXP0_F(0x70) / 6.0f;
                    obj[2].pos[0] -= EXP0_F(0x74) / 6.0f;
                    obj[3].pos[0] -= EXP0_F(0x78) / 6.0f;
                }
                else 
                {
                    obj[0].pos[0] = EXP0_F(0x0);
                    obj[1].pos[0] = EXP0_F(0x4);
                    obj[2].pos[0] = EXP0_F(0x8);
                    obj[3].pos[0] = EXP0_F(0xC);
                }
                
                if (epw->ct0 < 5)
                {
                    epw->ay += epw->ayp / 5;
                }
                
                epw->ct0++;
            }
            break;
    }
    
    njUnitMatrix(NULL);
    njTranslate(NULL, epw->px, epw->py, epw->pz);
    njRotateY(NULL, epw->ay);
    
    pos.y = 0;
    pos.x = 0;
    pos.z = en09_mtn23[frm];
    
    njCalcPoint(NULL, &pos, (NJS_VECTOR *)&epw->px);
}

// 100% matching!
void bhEne09_DG04(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;

    switch (epw->mode3)
    {
        case 0:
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg &= ~0x100;
            epw->flg2 &= ~1;
            
            EXP0_I(0x18) &= ~0x30;
            
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            if (EXP0_I(0x18) & 0x8000) 
            {
                bhEne_ChgMtn(epw, 0x3C, 0, 5);
                
                EXP0_I(0x18) &= 0x1FFFFFFF;
                
                epw->flg |= 0x40000;
            } 
            else 
            {
                bhEne_ChgMtn(epw, 0x35, 0, 5);
                
                EXP0_I(0x18) &= 0x7FFFFFFF;
                EXP0_I(0x18) &= 0xDFFFFFFF;
                EXP0_I(0x18) |= 0x40000000;
            }
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->ct0 = 0;
            epw->mode3++;
            
            break;
        
        case 1:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                
                if (epw->hokan_count == 0) 
                {
                    EXP0_I(0x18) &= 0xFFFF3F7F;
                    EXP0_I(0x18) &= ~0xF;
                    EXP0_I(0x18) |= 1;
                    
                    if (epw->hp < 0)
                    {
                        epw->mode0 = 4;
                        epw->mode1 = 0;
                        epw->mode2 = 0;
                        epw->mode3 = 0;
                    }
                    else
                    {
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        epw->mode2 = 3;
                        epw->mode3 = 0;
                        
                        EXP0_I(0x18) |= 0x2040;
                    }
                }
            } 
            else 
            {
                if ((epw->frm_no >> 0x10) == 0x18) 
                {
                    EXP0_I(0x18) &= ~0xF;
                    EXP0_I(0x18) |= 3;
                }
                
                obj = epw->mlwP->objP + 7;
                
                if (epw->ct0 < 6) 
                {
                    obj[0].pos[0] -= EXP0_F(0x6C) / 6.0f;
                    obj[1].pos[0] -= EXP0_F(0x70) / 6.0f;
                    obj[2].pos[0] -= EXP0_F(0x74) / 6.0f;
                    obj[3].pos[0] -= EXP0_F(0x78) / 6.0f;
                }
                else 
                {
                    obj[0].pos[0] = EXP0_F(0x0);
                    obj[1].pos[0] = EXP0_F(0x4);
                    obj[2].pos[0] = EXP0_F(0x8);
                    obj[3].pos[0] = EXP0_F(0xC);
                }
                
                epw->ct0++;
            }
    }
}

// 100% matching!
void bhEne09_DG05(BH_PWORK* epw) 
{
	NJS_CNK_OBJECT *obj;
    ATR_WORK *hp;
    float len;
    int frm;

    switch (epw->mode3) 
    {
        case 0:
            epw->flg2 |= 1;
            
            EXP0_I(0x18) &= ~0x30;
            EXP0_I(0x18) &= ~0xF;
            EXP0_I(0x18) |= 2;
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg &= ~0x100;
            
            frm = epw->frm_no >> 0x10;

            if ((epw->mtn_no == 9) && (frm < 6)) 
            {
                EXP0_I(0x18) |= 0x200;
            }
            else if ((epw->mtn_no == 0xc) && (5 < frm)) 
            {
                EXP0_I(0x18) &= ~0x200;
            }
            
            bhEne_ChgMtn(epw, 0x17, 0, 8);
            
            EXP0_I(0x18) &= 0x7FFFFFFF;
            EXP0_I(0x18) &= 0xBFFFFFFF;
            EXP0_I(0x18) |= 0x20000000;
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            EXP0_F(0x58) = 0.0f;
            
            hp = *(ATR_WORK **)(epw->exp0 + 0x54);
            
            if (hp->type == 0) 
            {
                epw->axp = (unsigned short)epw->axp;
            
                if ((0x2000 < epw->axp) && (0x5FFF >= epw->axp))
                {
                    if (EXP0_I(0x18) & 0x200) 
                    {
                        len = -1.0f * ((12.0f + (hp->px + hp->w)) - epw->px);
                    } 
                    else 
                    {
                        len = -1.0f * ((hp->px - 9.0f) - epw->px);
                    }
                }
                else if ((0x6000 < epw->axp) && (0x9FFF >= epw->axp))
                {
                    if (EXP0_I(0x18) & 0x200) 
                    {
                        len = (hp->pz - 12.0f) - epw->pz;
                    }
                    else 
                    {
                        len = (9.0f + (hp->pz + hp->d)) - epw->pz;
                    }
                }
                else if ((0xA000 < epw->axp) && (0xDFFF >= epw->axp)) 
                {
                    if (EXP0_I(0x18) & 0x200) 
                    {
                        len = (hp->px - 12.0f) - epw->px;
                    }
                    else 
                    {
                        len = (9.0f + (hp->px + hp->w)) - epw->px;
                    }
                }
                else 
                {
                    if (EXP0_I(0x18) & 0x200) 
                    {
                        len = -1.0f * ((12.0f + (hp->pz + hp->d)) - epw->pz);
                    }
                    else 
                    {
                        len = -1.0f * ((hp->pz - 9.0f) - epw->pz);
                    }
                }
                
                EXP0_F(0x58) = ((len / 15.0f) / njCos(0x2000));
            }
            
            epw->ct0 = 0;
            epw->mode3++;
            
            break;
        
        case 1:
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                
                epw->py = 0.001f + rom->grand[epw->flr_no + 2];
                
                epw->flg |= 0x100;
                epw->flg2 &= ~1;
                
                EXP0_I(0x18) &= ~0xF;
                EXP0_I(0x18) |= 1;
                EXP0_I(0x18) &= 0xFFFF3F7F;
                
                if (epw->hp < 0) 
                {
                    epw->mode0 = 4;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                }
                else
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) |= 0x2040;
                }
            }
            else
            {
                obj = epw->mlwP->objP + 7;
            
                if (epw->ct0 < 5) 
                {
                    obj[0].pos[0] -= EXP0_F(0x6C) / 5.0f;
                    obj[1].pos[0] -= EXP0_F(0x70) / 5.0f;
                    obj[2].pos[0] -= EXP0_F(0x74) / 5.0f;
                    obj[3].pos[0] -= EXP0_F(0x78) / 5.0f;
                }
                else 
                {
                    obj[0].pos[0] = EXP0_F(0x0);
                    obj[1].pos[0] = EXP0_F(0x4);
                    obj[2].pos[0] = EXP0_F(0x8);
                    obj[3].pos[0] = EXP0_F(0xC);
                }
                
                if (epw->ct0 < 0xF) 
                {
                    len = njCos(0x2000);
                    epw->spd = EXP0_F(0x58) * len;
                    
                    bhAddSpeed(epw, 0);
                }
                
                epw->py += fabsf(EXP0_F(0x58)) * njSin(0x2000) - epw->ct0 * 0.23f;
                
                if (!(rom->grand[epw->flr_no + 2] <= epw->py)) 
                {
                    epw->py = 0.001f + rom->grand[epw->flr_no + 2];
                }
                
                epw->ct0++;
            }
            
    }
}

// 100% matching!
void bhEne09_DG06(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;

    switch (epw->mode3)
    {
        case 0:
            EXP0_I(0x18) &= ~0x30;
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg &= ~0x100;
            epw->flg2 &= ~1;
            
            bhEne_ChgMtn(epw, 0x3D, 0, 8);
            
            EXP0_I(0x18) &= 0x7FFFFFFF;
            EXP0_I(0x18) &= 0xBFFFFFFF;
            EXP0_I(0x18) |= 0x20000000;
            
            EXP0_F(0x58) = 1.0f;
            
            epw->ct0 = 0;
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->mode3++;
        
            /* fallthrough */
        case 1:
            epw->py += fabsf(EXP0_F(0x58)) * njSin(0x2000) - epw->ct0 * 0.23f;
                
            if (!(rom->grand[epw->flr_no + 2] <= epw->py)) 
            {
                epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            }
            else
            {
                float f = njCos(0x2000);
                epw->spd = EXP0_F(0x58) * f;
                
                bhAddSpeed(epw, 0x8000);
            }
            
            obj = epw->mlwP->objP + 7;
            
            if (epw->ct0 < 5) 
            {
                obj[0].pos[0] -= EXP0_F(0x6C) / 5.0f;
                obj[1].pos[0] -= EXP0_F(0x70) / 5.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 5.0f;
                obj[3].pos[0] -= EXP0_F(0x78) / 5.0f;
            }
            else 
            {
                obj[0].pos[0] = EXP0_F(0x0);
                obj[1].pos[0] = EXP0_F(0x4);
                obj[2].pos[0] = EXP0_F(0x8);
                obj[3].pos[0] = EXP0_F(0xC);
            }
            
            epw->ct0++;
            
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                epw->flg |= 0x100;
                
                EXP0_I(0x18) &= 0xFFFE3F7F;
                
                if (epw->hp < 0) 
                {
                    epw->mode0 = 4;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                }
                else
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) |= 0x2040;
                }
            }
    }
}

// 100% matching!
void bhEne09_DG07(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT *obj;

    switch (epw->mode3)
    {
        case 0:
            EXP0_I(0x18) &= ~0x30;
            EXP0_I(0x18) &= ~0x180;
            
            epw->flg |= 0x100;
            epw->flg2 &= ~1;
            
            bhEne_ChgMtn(epw, 0x19, 0, 8);
            
            EXP0_I(0x18) &= 0x1FFFFFFF;
            epw->ct0 = 0;
            
            EXP0_I(0x18) &= 0xFFFE3F7F;
            
            epw->py = 0.001f + rom->grand[epw->flr_no + 2];
            
            obj = epw->mlwP->objP + 7;
            
            EXP0_F(0x6C) = obj[0].pos[0] - EXP0_F(0x0);
            EXP0_F(0x70) = obj[1].pos[0] - EXP0_F(0x4);
            EXP0_F(0x74) = obj[2].pos[0] - EXP0_F(0x8);
            EXP0_F(0x78) = obj[3].pos[0] - EXP0_F(0xC);
            
            epw->mode3++;
            
            /* fallthrough */
        case 1:
            obj = epw->mlwP->objP + 7;
                
            if (epw->ct0 < 5) 
            {
                obj[0].pos[0] -= EXP0_F(0x6C) / 5.0f;
                obj[1].pos[0] -= EXP0_F(0x70) / 5.0f;
                obj[2].pos[0] -= EXP0_F(0x74) / 5.0f;
                obj[3].pos[0] -= EXP0_F(0x78) / 5.0f;
            }
            else 
            {
                obj[0].pos[0] = EXP0_F(0x0);
                obj[1].pos[0] = EXP0_F(0x4);
                obj[2].pos[0] = EXP0_F(0x8);
                obj[3].pos[0] = EXP0_F(0xC);
            }
            
            epw->ct0++;
            
            if ((epw->frm_no >> 0x10) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
            {
                epw->mtn_add = 0;
                epw->flg |= 0x100;
                
                EXP0_I(0x18) &= 0xFFFE3F7F;
                
                if (epw->hp < 0)
                {
                    epw->mode0 = 4;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                }
                else
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 3;
                    epw->mode3 = 0;
                    
                    EXP0_I(0x18) |= 0x2040;
                }
            }
    }
}

/*

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

