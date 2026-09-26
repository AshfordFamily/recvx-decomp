#include "../../../ps2/veronica/prog/en17.h"
#include "../../../ps2/veronica/prog/en17sub.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/eneset.h"

// ENEMY: Monster Steve 

char En17_SdwTab[7] = { 2, 5, 15, 20, 9, 13, 255 };
WPNDAMAGE_WORK En17_WpnDamageTbl[22] = 
{
    {  0,  0,  0,  0,  0 },
    {  0,  0,  0,  0,  0 },
    {  0,  4,  3,  3,  3 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  2, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4, 10,  3, 10 },
    {  0,  4,  7,  3,  7 },
    {  0,  2,  5,  3,  5 },
    {  0,  4, 10,  3, 10 },
    {  0,  2,  3,  3,  3 },
    {  0,  2, 10,  3, 10 },
    { 12,  2,  1,  3,  3 },
    {  5,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 },
    {  6,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 },
    {  6,  2,  1,  3,  3 },
    {  0,  2,  1,  3,  3 }
};

static COMBWEP_WORK CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 }, 0, 0 },
    {  0, {  0,  0,  0 }, 0, 0 },
    { 60, { 10,  0,  0 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, {  4,  4,  4 }, 0, 0 },
    { 60, { 20, 20, 20 }, 0, 0 },
    { 60, { 20, 10, 10 }, 0, 0 },
    { 60, { 60, 60, 30 }, 0, 0 },
    { 60, {  8,  8,  8 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60,  0 }, 0, 0 },
    { 60, { 60, 60,  0 }, 0, 0 },
    { 60, { 60, 60, 20 }, 0, 0 },
    { 60, { 10, 10,  0 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 },
    { 60, { 60, 60, 60 }, 0, 0 }
};
static COMBJOINT_WORK CombJointTbl[24] = { 0 };

CPCL Ene17CapColTab[25] = 
{
    {   1,   2,  20 },
    {   3,   3,  25 },
    {   0,  10,   0 },
    {   3,   3,  30 },
    {   0,  40,  16 },
    {   6,   6,  23 },
    { -30,  24,   0 },
    {  10,  10,  23 },
    {  30,  24,   0 },
    {   4,   5,   8 },
    {   5,   5,  13 },
    {   0,  10,  -5 },
    {   7,   8,  10 },
    {   8,   9,   7 },
    {  11,  12,  10 },
    {  12,  13,   7 },
    {  14,  15,  14 },
    {  15,  16,  10 },
    {  16,  17,   7 },
    {  17,  18,  10 },
    {  19,  20,  14 },
    {  20,  21,  10 },
    {  21,  22,   7 },
    {  22,  23,  10 },
    {   0,   0,   0 }
};
BT_WORK en17prt_blood_tbl[24] = 
{
    {  0,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f },
    {  1,  0.0f, -1.0f,  1.0f,  1.5f,  1.0f,  3.0f,  1.0f },
    {  2,  0.0f,  1.0f,  1.5f,  1.0f,  0.5f,  2.0f,  1.0f },
    {  3,  0.0f,  2.5f,  2.5f,  1.0f,  1.0f,  3.0f,  1.0f },
    {  4,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  4.0f,  1.0f },
    {  5,  0.0f,  1.0f,  2.0f,  0.5f,  0.5f,  2.0f,  0.5f },
    {  6,  0.3f,  0.0f,  2.0f,  0.0f,  0.5f,  2.0f,  1.0f },
    {  7,  0.0f,  0.0f,  1.5f,  0.5f,  0.5f,  4.0f,  0.5f },
    {  8,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  4.0f,  1.0f },
    {  9,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  3.0f,  0.5f },
    { 10, -0.3f,  0.0f,  2.0f,  0.0f,  0.5f,  2.0f,  1.0f },
    { 11,  0.0f,  0.0f,  1.5f,  0.5f,  0.5f,  4.0f,  0.5f },
    { 12,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  4.0f,  1.0f },
    { 13,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  3.0f,  0.5f },
    { 14,  0.0f, -3.0f,  1.5f,  0.5f,  1.5f,  5.0f,  1.0f },
    { 15,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  3.0f,  1.0f },
    { 16,  0.0f, -1.0f,  0.5f,  0.5f,  1.0f,  3.0f,  1.0f },
    { 17,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  2.0f,  1.0f },
    { 18,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  4.0f,  1.0f },
    { 19,  0.0f, -3.0f,  1.5f,  0.5f,  1.5f,  5.0f,  1.0f },
    { 20,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  3.0f,  1.0f },
    { 21,  0.0f, -1.0f,  0.5f,  0.5f,  1.0f,  3.0f,  1.0f },
    { 22,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  2.0f,  1.0f },
    { 23,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  4.0f,  1.0f }
};
MTBL_WRK en17_mtn_tbl[10] = 
{
    {  3, { {  1, 0,  11 }, {  0, 12, 24 }, {  1,  25,  35 }, {  0,  36,  49 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 15, { {  1, 0,  44 }, {  0, 48, 96 }, {  1, 100, 140 }, {  0, 144, 195 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  6, { {  0, 0,  45 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  1, { {  0, 0,  29 }, {  1, 30, 59 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  2, { {  0, 0,  59 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    {  5, { {  0, 0,  79 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 16, { {  2, 0, 319 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 11, { {  0, 0,  44 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } } },
    { 12, { {  1, 0,  21 }, {  0, 22, 70 }, { -1,   0,  -1 }, {  0,  -1,   0 } }, { { -1,  0 }, { -1, 0 }, { -1, 0 }, {  0, 0 } } },
    { -1, { { -1, 0,   0 }, { -1,  0,  0 }, { -1,   0,   0 }, { -1,   0,  -1 } }, { {  0, -1 }, {  0, 0 }, {  0, 0 }, {  0, 0 } } }
};
MTBL_WORK en17_mtn_tbl2[7] = 
{
    { 15, { {   0, 74496 }, {  48,    74496 }, { 72, 74500 }, { 100, 74496 }, { 140, 74500 }, { 144, 74496 } } },
    {  1, { {   0, 74496 }, {  30,    74496 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    {  2, { {  32, 74499 }, {  35, 16786185 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 16, { { 132, 74499 }, { 160, 16786185 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 11, { {  19, 74503 }, {  22,    74499 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { 17, { {  25, 74499 }, {  -1,        0 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } },
    { -1, { {  -1,     0 }, {  -1,        0 }, { -1,     0 }, {  -1,     0 }, {  -1,     0 }, {  -1,     0 } } }
};
POS_WORK ply_mtn42_pos[20] = 
{
    { 0.0f,           0.0f },
    { 0.0f,   -2.12480998f },
    { 0.0f,   -2.18794179f },
    { 0.0f,     -2.072721f },
    { 0.0f,   -1.78017569f },
    { 0.0f,   -1.31060696f },
    { 0.0f,   -1.02873039f },
    { 0.0f,   -1.01653862f },
    { 0.0f,   -1.00815964f },
    { 0.0f,    -1.0035944f },
    { 0.0f,   -1.00283909f },
    { 0.0f,   -1.00589752f },
    { 0.0f,    -1.0127697f },
    { 0.0f,  -0.807430267f },
    { 0.0f,  -0.420703888f },
    { 0.0f,  -0.267501831f },
    { 0.0f,  -0.218467712f },
    { 0.0f,  -0.169967651f },
    { 0.0f,  -0.121238708f },
    { 0.0f, -0.0722846985f }
};
POS_WORK ply_mtn43_pos[20] = 
{
    { 0.0f,  5.57899809f },
    { 0.0f,  1.89403009f },
    { 0.0f,  1.89615822f },
    { 0.0f,  1.89056587f },
    { 0.0f,  1.87725449f },
    { 0.0f,  1.85622406f },
    { 0.0f,  1.82747269f },
    { 0.0f,  1.79100037f },
    { 0.0f,  1.45895195f },
    { 0.0f, 0.900272369f },
    { 0.0f, 0.492113113f },
    { 0.0f, 0.234746933f },
    { 0.0f, 0.128166199f },
    { 0.0f, 0.172372818f },
    { 0.0f, 0.339530945f },
    { 0.0f, 0.408201218f },
    { 0.0f, 0.416120529f },
    { 0.0f,  0.38740921f },
    { 0.0f, 0.322071075f },
    { 0.0f, 0.220104218f }
};
POS_WORK ply_mtn44_pos[51] = 
{
    {            0.0f,     -2.6063652f },
    { -0.00109499996f,  -0.0548400879f },
    { -0.00294700009f,  -0.0579090118f },
    {  -0.0042940001f,  -0.0601291656f },
    { -0.00513700023f,  -0.0614967346f },
    { -0.00547399931f,  -0.0620174408f },
    { -0.00530499965f,  -0.0616855621f },
    {  -0.0046310015f,  -0.0605049133f },
    { -0.00345199741f,   -0.058473587f },
    { -0.00176900253f,  -0.0555915833f },
    { 0.000421002507f,  -0.0518627167f },
    {  0.00311599858f,  -0.0472793579f },
    {  0.00631500036f,  -0.0418510437f },
    {   0.0100209992f,  -0.0355682373f },
    {   0.0142310001f,  -0.0284366608f },
    {   0.0187749993f,  -0.0231723785f },
    {   0.0229530018f,  -0.0203113556f },
    {   0.0265810005f,  -0.0173988342f },
    {   0.0296639949f,  -0.0144405365f },
    {   0.0321990028f,  -0.0114307404f },
    {   0.0341860056f,  -0.0083732605f },
    {   0.0356269926f, -0.00526809692f },
    {   0.0365200043f, -0.00211334229f },
    {   0.0368660092f,  0.00109100342f },
    {   0.0366629958f,  0.00434303284f },
    {   0.0359149873f,  0.00764274597f },
    {   0.0346190035f,   0.0109920502f },
    {   0.0327759981f,   0.0143909454f },
    {   0.0303840041f,   0.0178394318f },
    {   0.0274469852f,   0.0213336945f },
    {   0.0239610076f,   0.0248775482f },
    {   0.0188489854f,   0.0315227509f },
    {   0.0127390027f,   0.0407295227f },
    {  0.00702399015f,   0.0491752625f },
    {  0.00170201063f,   0.0568599701f },
    { -0.00322598219f,   0.0637836456f },
    { -0.00775802135f,   0.0699443817f },
    {  -0.0118969679f,   0.0753479004f },
    {  -0.0156410038f,   0.0799865723f },
    {  -0.0189909935f,   0.0838661194f },
    {   -0.021946013f,   0.0869846344f },
    {  -0.0245069861f,   0.0893440247f },
    {  -0.0266750157f,   0.0909385681f },
    {  -0.0303269923f,    0.106515884f },
    {  -0.0353450179f,    0.130146027f },
    {  -0.0397799909f,    0.144119263f },
    {  -0.0436370075f,    0.148435593f },
    {  -0.0469129831f,    0.143100739f },
    {  -0.0496090055f,    0.128105164f },
    {  -0.0517240018f,    0.103460312f },
    {  -0.0532590002f,   0.0691566467f }
};
POS_WORK ply_mtn45_pos[51] = 
{
    {            0.0f,    0.0815086365f },
    { 0.000188999998f,    0.0247268677f },
    { 0.000134999995f,    0.0163879395f },
    { -0.00057199999f,   0.00716018677f },
    { -0.00242500007f,  -0.00296020508f },
    { -0.00393699994f,    -0.013967514f },
    {  -0.0065960004f,   -0.0258655548f },
    { -0.00990600046f,   -0.0386543274f },
    {  -0.0138679985f,   -0.0523319244f },
    {  -0.0184790008f,   -0.0669002533f },
    {  -0.0237429962f,   -0.0823554993f },
    {  -0.0296570063f,   -0.0987052917f },
    {  -0.0419429988f,    -0.115940094f },
    {  -0.0572379977f,    -0.134067535f },
    {  -0.0681459904f,    -0.156576157f },
    {    -0.07466501f,     -0.18034935f },
    {  -0.0767939985f,    -0.200340271f },
    {  -0.0745350122f,    -0.216550827f },
    {  -0.0678870082f,    -0.228973389f },
    {  -0.0568509698f,    -0.237615585f },
    {   -0.041424036f,     -0.24247551f },
    {  -0.0216109753f,    -0.243551254f },
    { -0.00201100111f,    -0.240844727f },
    {   0.0130140185f,    -0.234354019f },
    {   0.0258889794f,    -0.224081039f },
    {   0.0366160274f,     -0.21002388f },
    {   0.0451929569f,    -0.200519562f },
    {   0.0516210198f,     -0.19443512f },
    {   0.0558989942f,     -0.18286705f },
    {   0.0580269992f,    -0.165821075f },
    {   0.0580070019f,    -0.143297195f },
    {   0.0557470024f,    -0.115289688f },
    {   0.0508189946f,   -0.0818042755f },
    {   0.0454149991f,   -0.0428390503f },
    {  0.04004999995f,   -0.0143680573f },
    {   0.0347240046f, -0.000867843628f },
    {   0.0294359997f,    0.0113964081f },
    {   0.0241890028f,    0.0224246979f },
    {   0.0189800002f,    0.0322189331f },
    {   0.0138109997f,    0.0407733917f },
    {  0.00868099928f,    0.0480957031f },
    {  0.00565600023f,    0.0541801453f },
    {  0.00475900061f,    0.0590305328f },
    {  0.00393799972f,    0.0626430511f },
    {  0.00319300033f,    0.0650215149f },
    {  0.00252299989f,    0.0661621094f },
    {  0.00192700000f,    0.0660686493f },
    {  0.00140899990f,    0.0647392273f },
    { 0.000964000006f,    0.0621738434f },
    { 0.000594999990f,    0.0583705902f },
    { 0.000302000000f,    0.0533351898f }
};
void (*bhEne17_Mode0[6])(BH_PWORK*) = 
{
	bhEne17_Init,
	bhEne17_Move,
	bhEne17_Nage,
	bhEne17_Damage,
	bhEne17_Die,
	bhEne_Event
};
void (*bhEne17_InitType[1])(BH_PWORK*) = { bhEne17_InitType00 };
void (*bhEne17_MoveType[1])(BH_PWORK*) = { bhEne17_MVType00 };
void (*bhEne17_BrainMode2[7])(BH_PWORK*) = 
{
	bhEne17_Brain00,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_DmmyBrain,
	bhEne17_Brain00
};
void (*bhEne17_MoveMode2[7])(BH_PWORK*) = 
{
	bhEne17_MV00,
	bhEne17_MV01,
	bhEne17_MV02,
	bhEne17_MV03,
	bhEne17_MV04,
	bhEne17_MV05,
	bhEne17_MV06
};
void (*bhEne17_DamageType[1])(BH_PWORK*) = { bhEne17_DGType00 };
void (*bhEne17_DamageMode2[1])(BH_PWORK*) = { bhEne17_DG00 };
/* unused below */
/*void (*bhEne17_NageType[1])(BH_PWORK*);
void (*bhEne17_NageMode2[1])(BH_PWORK*);
void (*bhEne17_DieType[1])(BH_PWORK*);
void (*bhEne17_DieMode2[1])(BH_PWORK*);
int eff_flg;*/

const char en17_flipTree[25] = { 0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 6, 7, 8, 9, 19, 20, 21, 22, 23, 14, 15, 16, 17, 18, 255 };
const char en17_tree[2][8] = { { 0, 1, 19, 20, 21, 22, 23, 255 }, { 0, 1, 14, 15, 16, 17, 18, 255 } };

// 100% matching!
void bhEne17_DmmyBrain()
{
}

// 100% matching!
void bhEne17(BH_PWORK* epw) {
    int i;
    O_WORK* owk;
    NJS_POINT3 ps;
    NJS_POINT3 pd;

    bhEne17_MainLoop(epw);
    if ((plp->mode0 == 4) || (plp->mode0 == 6)) {
        if (plp->mode2 == 0) {
            bhEne17_PlyDG00(plp, epw);
        } else {
            bhEne17_PlyDG01(plp, epw);
        }
    }

    bhEne17_EneToPlyDist(epw);
    if (epw->flg & 4) {
        for (i = 0; i < 64; i++) {
            epw->dam[i] = 0;
        }
        epw->flg = (epw->flg & ~4);
    }

    bhEne17_CollCheck(epw);
    bhEne17_CalcEnemy(epw);
    if (epw->mode0 < 5) {
        bhEne17_CameraControl(epw);
    }

    if (((int*)epw->exp0)[3] > 0) {
        ((int*)epw->exp0)[3] -= 1;
    }

    if (((int*)epw->exp0)[4] > 0) {
        ((int*)epw->exp0)[4] -= 1;
    }

    if (((int*)epw->exp0)[2] & 0x20000000) {
        owk = &((O_WRK*)epw->exp2)->mlwP->owP[1];
        ps.x = 0;
        ps.y = 0;
        ps.z = -17.4f;

        njCalcPoint(&owk->mtx, &ps, &pd);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);
        bhEff_SetPtcl2(epw, &pd, owk->mtx);

        ((int*)epw->exp0)[2] &= ~0x20000000;
        bhEne17_SetLight(epw, &pd);
        bhEne17_SePlay(epw, 0x01002309);
    }
}

// 100% matching!
void bhEne17_EneToPlyDist(BH_PWORK* epw) {
    O_WORK* owk;
    NJS_POINT3 pos;
    
    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    ((float*)epw->exp0)[5] = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
}

// 100% matching!
void bhEne17_MainLoop(BH_PWORK* epw) {
    bhEne17_DmgChk(epw);
    bhEne17_Mode0[epw->mode0](epw);
    bhEne17_SetMtn(epw);
}

// 100% matching!
int bhEne17_DmgChk(BH_PWORK* epw) {
    if ((epw->flg & 4) && !(epw->flg & 2)) {
        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if (epw->total_dam != 0) {
            bhEne17_DamageAdd(epw);
            
            if (EXP0_UC(1) != 0) {
                EXP0_I(8) |= 0x200;
                EXP0_C(1) = 0;
            } else {
                EXP0_C(1) = 1;
            }
            
            if (epw->mode0 == 1) {
                if (epw->comb_flg & 4) {
                    EXP0_I(8) |= 0x80;
                } else {
                    EXP0_I(8) &= ~0x80;
                }
                
                bhEne17_ChgDmgMode(epw);
            }
        }
    }
}

// 
// Start address: 0x1eaed0
void bhEne17_ChgDmgMode(BH_PWORK* epw)
{
	int act;
	WPNDAMAGE_WORK* wp_tbl;
	// Line 729, Address: 0x1eaed0, Func Offset: 0
	// Line 726, Address: 0x1eaed4, Func Offset: 0x4
	// Line 735, Address: 0x1eaedc, Func Offset: 0xc
	// Line 729, Address: 0x1eaee0, Func Offset: 0x10
	// Line 735, Address: 0x1eaef0, Func Offset: 0x20
	// Line 737, Address: 0x1eaef8, Func Offset: 0x28
	// Line 738, Address: 0x1eaf04, Func Offset: 0x34
	// Line 739, Address: 0x1eaf08, Func Offset: 0x38
	// Line 742, Address: 0x1eaf0c, Func Offset: 0x3c
	// Line 745, Address: 0x1eaf1c, Func Offset: 0x4c
	// Line 750, Address: 0x1eaf24, Func Offset: 0x54
	// Line 755, Address: 0x1eaf30, Func Offset: 0x60
	// Line 762, Address: 0x1eaf5c, Func Offset: 0x8c
	// Line 763, Address: 0x1eaf64, Func Offset: 0x94
	// Line 764, Address: 0x1eaf68, Func Offset: 0x98
	// Line 765, Address: 0x1eaf6c, Func Offset: 0x9c
	// Line 767, Address: 0x1eaf70, Func Offset: 0xa0
	// Func End, Address: 0x1eaf78, Func Offset: 0xa8
}

// 100% matching!
void bhEne17_DamageAdd(BH_PWORK *epw)
{
    WPNDAMAGE_WORK *wp_tbl = En17_WpnDamageTbl;
    int *d;
    int i;

    if (epw->hp >= 0) {
        bhEne17_SePlay(epw, 0x01002302);
        wp_tbl = &wp_tbl[epw->comb_wep];
        d = &epw->dam[1];

        for (i = 1; i < (int)epw->mlwP->obj_num; i++, d++) {
            if (*d > 0) {
                epw->djnt_no = i;
                if (!(wp_tbl->flg & 4)) {
                    if ((epw->comb_flg & 1) || (epw->hp < 0)) {
                        bhEne_SetBlood(epw, wp_tbl->cb_blood, en17prt_blood_tbl);
                    } else {
                        bhEne_SetBlood(epw, wp_tbl->nm_blood, en17prt_blood_tbl);
                    }
                }
            }
        }
    }

    if ((wp_tbl->flg & 1) || (wp_tbl->flg & 2)) {
        if (EXP0_I(16) <= 0) {
            EXP0_I(16) = 10;
            if (wp_tbl->flg & 2) {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en17prt_blood_tbl, 2);
            } else {
                bhEne_SetDFireEffect(epw, epw->djnt_no, en17prt_blood_tbl, 1);
            }
        }
    }

    if (wp_tbl->flg & 8) {
        if (EXP0_I(16) <= 0) {
            EXP0_I(16) = 10;
            bhEne_SetSanEffect(epw, epw->djnt_no, en17prt_blood_tbl);
        }
    }
}

// 
// Start address: 0x1eb150
int bhEne17_SetMtn(BH_PWORK* epw)
{
	//O_WORK* owk;
	//NJS_POINT3 ps;
	//int i;
	NJS_POINT3 ofs;
	int sfrm_no;
	int i;
	NJS_POINT3 ps;
	O_WORK* owk;
	BH_PWORK* armp;
	int lnk_obj;
	int frm;
	int ret;
	NJS_CNK_OBJECT* obj;
	// Line 869, Address: 0x1eb150, Func Offset: 0
	// Line 875, Address: 0x1eb174, Func Offset: 0x24
	// Line 873, Address: 0x1eb178, Func Offset: 0x28
	// Line 875, Address: 0x1eb17c, Func Offset: 0x2c
	// Line 880, Address: 0x1eb194, Func Offset: 0x44
	// Line 877, Address: 0x1eb19c, Func Offset: 0x4c
	// Line 880, Address: 0x1eb1a0, Func Offset: 0x50
	// Line 882, Address: 0x1eb1b8, Func Offset: 0x68
	// Line 887, Address: 0x1eb1e0, Func Offset: 0x90
	// Line 896, Address: 0x1eb1f8, Func Offset: 0xa8
	// Line 898, Address: 0x1eb200, Func Offset: 0xb0
	// Line 899, Address: 0x1eb214, Func Offset: 0xc4
	// Line 900, Address: 0x1eb228, Func Offset: 0xd8
	// Line 902, Address: 0x1eb230, Func Offset: 0xe0
	// Line 903, Address: 0x1eb234, Func Offset: 0xe4
	// Line 904, Address: 0x1eb23c, Func Offset: 0xec
	// Line 907, Address: 0x1eb240, Func Offset: 0xf0
	// Line 909, Address: 0x1eb248, Func Offset: 0xf8
	// Line 904, Address: 0x1eb250, Func Offset: 0x100
	// Line 909, Address: 0x1eb254, Func Offset: 0x104
	// Line 904, Address: 0x1eb258, Func Offset: 0x108
	// Line 905, Address: 0x1eb25c, Func Offset: 0x10c
	// Line 906, Address: 0x1eb260, Func Offset: 0x110
	// Line 909, Address: 0x1eb264, Func Offset: 0x114
	// Line 910, Address: 0x1eb278, Func Offset: 0x128
	// Line 912, Address: 0x1eb288, Func Offset: 0x138
	// Line 913, Address: 0x1eb294, Func Offset: 0x144
	// Line 914, Address: 0x1eb2a8, Func Offset: 0x158
	// Line 915, Address: 0x1eb2b0, Func Offset: 0x160
	// Line 921, Address: 0x1eb2b4, Func Offset: 0x164
	// Line 923, Address: 0x1eb2c4, Func Offset: 0x174
	// Line 925, Address: 0x1eb2d0, Func Offset: 0x180
	// Line 926, Address: 0x1eb2d4, Func Offset: 0x184
	// Line 925, Address: 0x1eb2d8, Func Offset: 0x188
	// Line 926, Address: 0x1eb2e4, Func Offset: 0x194
	// Line 928, Address: 0x1eb2e8, Func Offset: 0x198
	// Line 929, Address: 0x1eb2f0, Func Offset: 0x1a0
	// Line 931, Address: 0x1eb2fc, Func Offset: 0x1ac
	// Line 933, Address: 0x1eb308, Func Offset: 0x1b8
	// Line 934, Address: 0x1eb30c, Func Offset: 0x1bc
	// Line 933, Address: 0x1eb310, Func Offset: 0x1c0
	// Line 934, Address: 0x1eb31c, Func Offset: 0x1cc
	// Line 936, Address: 0x1eb320, Func Offset: 0x1d0
	// Line 937, Address: 0x1eb328, Func Offset: 0x1d8
	// Line 939, Address: 0x1eb334, Func Offset: 0x1e4
	// Line 941, Address: 0x1eb340, Func Offset: 0x1f0
	// Line 942, Address: 0x1eb344, Func Offset: 0x1f4
	// Line 941, Address: 0x1eb348, Func Offset: 0x1f8
	// Line 942, Address: 0x1eb354, Func Offset: 0x204
	// Line 944, Address: 0x1eb358, Func Offset: 0x208
	// Line 945, Address: 0x1eb360, Func Offset: 0x210
	// Line 947, Address: 0x1eb36c, Func Offset: 0x21c
	// Line 949, Address: 0x1eb378, Func Offset: 0x228
	// Line 950, Address: 0x1eb37c, Func Offset: 0x22c
	// Line 949, Address: 0x1eb380, Func Offset: 0x230
	// Line 950, Address: 0x1eb38c, Func Offset: 0x23c
	// Line 952, Address: 0x1eb390, Func Offset: 0x240
	// Line 953, Address: 0x1eb398, Func Offset: 0x248
	// Line 955, Address: 0x1eb3a4, Func Offset: 0x254
	// Line 957, Address: 0x1eb3d0, Func Offset: 0x280
	// Line 958, Address: 0x1eb3d4, Func Offset: 0x284
	// Line 957, Address: 0x1eb3d8, Func Offset: 0x288
	// Line 958, Address: 0x1eb3e4, Func Offset: 0x294
	// Line 964, Address: 0x1eb3ec, Func Offset: 0x29c
	// Line 966, Address: 0x1eb3fc, Func Offset: 0x2ac
	// Line 968, Address: 0x1eb410, Func Offset: 0x2c0
	// Line 969, Address: 0x1eb414, Func Offset: 0x2c4
	// Line 970, Address: 0x1eb41c, Func Offset: 0x2cc
	// Line 972, Address: 0x1eb434, Func Offset: 0x2e4
	// Line 976, Address: 0x1eb438, Func Offset: 0x2e8
	// Line 981, Address: 0x1eb44c, Func Offset: 0x2fc
	// Line 983, Address: 0x1eb450, Func Offset: 0x300
	// Line 984, Address: 0x1eb470, Func Offset: 0x320
	// Line 983, Address: 0x1eb474, Func Offset: 0x324
	// Line 985, Address: 0x1eb49c, Func Offset: 0x34c
	// Line 986, Address: 0x1eb4bc, Func Offset: 0x36c
	// Line 985, Address: 0x1eb4c4, Func Offset: 0x374
	// Line 986, Address: 0x1eb4d4, Func Offset: 0x384
	// Line 985, Address: 0x1eb4d8, Func Offset: 0x388
	// Line 986, Address: 0x1eb4ec, Func Offset: 0x39c
	// Line 987, Address: 0x1eb4f4, Func Offset: 0x3a4
	// Line 990, Address: 0x1eb504, Func Offset: 0x3b4
	// Line 991, Address: 0x1eb50c, Func Offset: 0x3bc
	// Line 993, Address: 0x1eb518, Func Offset: 0x3c8
	// Line 996, Address: 0x1eb520, Func Offset: 0x3d0
	// Line 997, Address: 0x1eb528, Func Offset: 0x3d8
	// Line 999, Address: 0x1eb534, Func Offset: 0x3e4
	// Line 1003, Address: 0x1eb538, Func Offset: 0x3e8
	// Line 1008, Address: 0x1eb544, Func Offset: 0x3f4
	// Line 1010, Address: 0x1eb554, Func Offset: 0x404
	// Line 1008, Address: 0x1eb558, Func Offset: 0x408
	// Line 1012, Address: 0x1eb55c, Func Offset: 0x40c
	// Line 1008, Address: 0x1eb564, Func Offset: 0x414
	// Line 1009, Address: 0x1eb568, Func Offset: 0x418
	// Line 1010, Address: 0x1eb570, Func Offset: 0x420
	// Line 1011, Address: 0x1eb574, Func Offset: 0x424
	// Line 1012, Address: 0x1eb57c, Func Offset: 0x42c
	// Line 1018, Address: 0x1eb58c, Func Offset: 0x43c
	// Line 1019, Address: 0x1eb5a0, Func Offset: 0x450
	// Line 1018, Address: 0x1eb5a4, Func Offset: 0x454
	// Line 1019, Address: 0x1eb5a8, Func Offset: 0x458
	// Line 1021, Address: 0x1eb5bc, Func Offset: 0x46c
	// Line 1023, Address: 0x1eb5c0, Func Offset: 0x470
	// Line 1021, Address: 0x1eb5cc, Func Offset: 0x47c
	// Line 1022, Address: 0x1eb5d0, Func Offset: 0x480
	// Line 1023, Address: 0x1eb5d4, Func Offset: 0x484
	// Line 1026, Address: 0x1eb5dc, Func Offset: 0x48c
	// Line 1029, Address: 0x1eb5e8, Func Offset: 0x498
	// Line 1030, Address: 0x1eb5f0, Func Offset: 0x4a0
	// Line 1032, Address: 0x1eb604, Func Offset: 0x4b4
	// Line 1034, Address: 0x1eb618, Func Offset: 0x4c8
	// Line 1035, Address: 0x1eb61c, Func Offset: 0x4cc
	// Func End, Address: 0x1eb644, Func Offset: 0x4f4
}

// 100% matching!
void bhEne17_MtnTblPlay(BH_PWORK* epw, int frm)
{
    MTBL_WRK* mtbl = en17_mtn_tbl;
    MTBL_WORK* mtbl2 = en17_mtn_tbl2;
    NJS_VECTOR vec  = { 0 };
    NJS_VECTOR vec1 = { 0 };
    NJS_VECTOR vec2 = { 0, -0.8f, -2.5f };
    int i;

    if (sys->rmthp != epw->mnwP) {
        if (epw->flg & 0x40000) {
            while(mtbl->no != -1) {
                if (mtbl->no == epw->mtn_no) {
                    for (i = 0; i < 4; i++) {
                        if (mtbl->fmtn[i].type != -1 &&
                            frm >= mtbl->fmtn[i].s_frm &&
                            frm <= mtbl->fmtn[i].e_frm) {

                            switch (mtbl->fmtn[i].type) {
                            case 0:
                                bhCalcFixOffset(epw, en17_tree[0], &vec2, &vec);
                                break;
                            case 1:
                                bhCalcFixOffset(epw, en17_tree[1], &vec2, &vec);
                                break;
                            case 2:
                                bhCalcFixOffset(epw, en17_tree[0], &vec1, &vec);
                                break;
                            case 3:
                                bhCalcFixOffset(epw, en17_tree[1], &vec1, &vec);
                                break;
                            }

                            if (epw->mtn_no == 0xF) {
                                epw->px -= 1.2f * vec.x;
                                epw->pz -= 1.2f * vec.z;
                            } else {
                                epw->px -= vec.x;
                                epw->pz -= vec.z;
                            }

                            break; 
                        }
                    }
                }

                mtbl++;
            }
        }

        while (mtbl2->no != -1) {
            if (mtbl2->no == epw->mtn_no) {
                for (i = 0; i < 6; i++) {
                    if (mtbl2->atb[i].frm == -1) {
                        break;
                    }
                    
                    if (mtbl2->atb[i].frm == frm) {
                        bhEne17_SePlay(epw, mtbl2->atb[i].act);
                    }
                }
            }
            
            mtbl2++;
        }
    }
}

// 100% matching!
void bhEne17_CollCheck(BH_PWORK* epw) 
{
    
    if (!(epw->flg & 2)) {
        if ((epw->flg & 8) && (((unsigned int*)epw->exp0)[2] & 0x10)) {
            bhCheckPlayer(epw);
        }
        bhEne17_CollCheckWall(epw);
    }
}

// 100% matching!
void bhEne17_CollCheckWall(BH_PWORK* ewp) 
{
    *(ATR_WORK**)((char*)ewp->exp0 + 0x40) = bhCheckWallType((NJS_POINT3*)&ewp->px, ewp->flg, ewp->ar, ewp->ah);
    
    if ((((unsigned int*)(ewp->exp0))[2] & 0xF) == 1 && (ewp->flg & 0x10)) {
        bhCheckDansa(ewp);
        bhCheckWall(ewp);
    }
}

// 100% matching!
void bhEne17_CalcEnemy(BH_PWORK* epw) {
    O_WORK* owk;
    
    bhCalcModel(epw);
    owk = &epw->mlwP->owP[5];
    epw->cah = epw->ah = owk->mtx[13] - epw->py;
    owk = &epw->mlwP->owP[5];
    
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13] - 5.0f;
    epw->watr.c1.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[16];
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[21];
    epw->watr.c2.x = (epw->watr.c2.x + owk->mtx[12]) / 2.0f;
    epw->watr.c2.y = (epw->watr.c2.y + owk->mtx[13]) / 2.0f;
    epw->watr.c2.z = (epw->watr.c2.z + owk->mtx[14]) / 2.0f;
    epw->watr.r = 4.0f;
}

// 
// Start address: 0x1ebb00
void bhEne17_Init(BH_PWORK* epw)
{
	int size;
	unsigned char* addr;
	int i;
	// Line 1266, Address: 0x1ebb00, Func Offset: 0
	// Line 1270, Address: 0x1ebb0c, Func Offset: 0xc
	// Line 1271, Address: 0x1ebb14, Func Offset: 0x14
	// Line 1272, Address: 0x1ebb1c, Func Offset: 0x1c
	// Line 1273, Address: 0x1ebb20, Func Offset: 0x20
	// Line 1274, Address: 0x1ebb24, Func Offset: 0x24
	// Line 1275, Address: 0x1ebb2c, Func Offset: 0x2c
	// Line 1276, Address: 0x1ebb30, Func Offset: 0x30
	// Line 1277, Address: 0x1ebb3c, Func Offset: 0x3c
	// Line 1278, Address: 0x1ebb40, Func Offset: 0x40
	// Line 1281, Address: 0x1ebb60, Func Offset: 0x60
	// Line 1282, Address: 0x1ebb64, Func Offset: 0x64
	// Line 1283, Address: 0x1ebb68, Func Offset: 0x68
	// Line 1286, Address: 0x1ebb6c, Func Offset: 0x6c
	// Line 1284, Address: 0x1ebb70, Func Offset: 0x70
	// Line 1286, Address: 0x1ebb74, Func Offset: 0x74
	// Line 1285, Address: 0x1ebb78, Func Offset: 0x78
	// Line 1286, Address: 0x1ebb7c, Func Offset: 0x7c
	// Line 1287, Address: 0x1ebb80, Func Offset: 0x80
	// Line 1290, Address: 0x1ebb84, Func Offset: 0x84
	// Line 1292, Address: 0x1ebb90, Func Offset: 0x90
	// Line 1293, Address: 0x1ebb9c, Func Offset: 0x9c
	// Line 1296, Address: 0x1ebbb0, Func Offset: 0xb0
	// Line 1299, Address: 0x1ebbc0, Func Offset: 0xc0
	// Line 1300, Address: 0x1ebbd8, Func Offset: 0xd8
	// Line 1303, Address: 0x1ebbe8, Func Offset: 0xe8
	// Line 1304, Address: 0x1ebc00, Func Offset: 0x100
	// Line 1306, Address: 0x1ebc10, Func Offset: 0x110
	// Line 1313, Address: 0x1ebc18, Func Offset: 0x118
	// Line 1315, Address: 0x1ebc1c, Func Offset: 0x11c
	// Line 1317, Address: 0x1ebc28, Func Offset: 0x128
	// Line 1318, Address: 0x1ebc2c, Func Offset: 0x12c
	// Line 1317, Address: 0x1ebc30, Func Offset: 0x130
	// Line 1318, Address: 0x1ebc34, Func Offset: 0x134
	// Line 1319, Address: 0x1ebc44, Func Offset: 0x144
	// Line 1323, Address: 0x1ebc48, Func Offset: 0x148
	// Line 1328, Address: 0x1ebc4c, Func Offset: 0x14c
	// Line 1323, Address: 0x1ebc50, Func Offset: 0x150
	// Line 1327, Address: 0x1ebc5c, Func Offset: 0x15c
	// Line 1328, Address: 0x1ebc68, Func Offset: 0x168
	// Line 1331, Address: 0x1ebc74, Func Offset: 0x174
	// Line 1333, Address: 0x1ebc84, Func Offset: 0x184
	// Line 1334, Address: 0x1ebcac, Func Offset: 0x1ac
	// Line 1338, Address: 0x1ebcb8, Func Offset: 0x1b8
	// Line 1339, Address: 0x1ebcc0, Func Offset: 0x1c0
	// Line 1340, Address: 0x1ebcc4, Func Offset: 0x1c4
	// Line 1339, Address: 0x1ebcc8, Func Offset: 0x1c8
	// Line 1340, Address: 0x1ebccc, Func Offset: 0x1cc
	// Line 1341, Address: 0x1ebcd0, Func Offset: 0x1d0
	// Line 1342, Address: 0x1ebcd8, Func Offset: 0x1d8
	// Line 1343, Address: 0x1ebce0, Func Offset: 0x1e0
	// Line 1344, Address: 0x1ebce8, Func Offset: 0x1e8
	// Line 1347, Address: 0x1ebcf0, Func Offset: 0x1f0
	// Line 1348, Address: 0x1ebcf4, Func Offset: 0x1f4
	// Line 1349, Address: 0x1ebcf8, Func Offset: 0x1f8
	// Line 1351, Address: 0x1ebcfc, Func Offset: 0x1fc
	// Line 1350, Address: 0x1ebd00, Func Offset: 0x200
	// Line 1351, Address: 0x1ebd04, Func Offset: 0x204
	// Line 1354, Address: 0x1ebd08, Func Offset: 0x208
	// Line 1360, Address: 0x1ebd10, Func Offset: 0x210
	// Line 1362, Address: 0x1ebd18, Func Offset: 0x218
	// Line 1354, Address: 0x1ebd1c, Func Offset: 0x21c
	// Line 1355, Address: 0x1ebd20, Func Offset: 0x220
	// Line 1356, Address: 0x1ebd24, Func Offset: 0x224
	// Line 1357, Address: 0x1ebd2c, Func Offset: 0x22c
	// Line 1360, Address: 0x1ebd34, Func Offset: 0x234
	// Line 1362, Address: 0x1ebd38, Func Offset: 0x238
	// Line 1365, Address: 0x1ebd44, Func Offset: 0x244
	// Line 1366, Address: 0x1ebd58, Func Offset: 0x258
	// Line 1368, Address: 0x1ebd60, Func Offset: 0x260
	// Func End, Address: 0x1ebd70, Func Offset: 0x270
}

// 100% matching!
void bhEne17_InitType00()
{
}

// 100% matching!
BH_PWORK* bhEne17_SetLinkWork(BH_PWORK* epw, int lnk_obj, int mdl_no, int id) 
{
    BH_PWORK* epp;
    EGG_WORK  lnk_tbl;

    npSetMemoryL((unsigned int*)&lnk_tbl, 9, 0);
    lnk_tbl.flg = 0x80A1;
    lnk_tbl.id  = (unsigned short)id;

    epp = bhSetEnemy(&lnk_tbl, rom->ene_n);

    epp->lkwkp = (unsigned char*)epw;
    epp->lkono = lnk_obj;
    epp->lox = 0.0f;
    epp->loy = 0.0f;
    epp->loz = 0.0f;

    epp->mdl[0] = epw->mdl[mdl_no];
    epp->mlwP   = &epp->mdl[0];

    epp->mnwP = epw->mnwP;

    return epp;
}

// 100% matching!
void bhEne17_Move(BH_PWORK* epw) 
{
    bhEne17_MoveType[0](epw);
}

// 100% matching!
void bhEne17_Damage(BH_PWORK* epw) 
{
    bhEne17_DamageType[0](epw);
}

// 100% matching!
void bhEne17_Nage()
{
}

// 100% matching!
void bhEne17_Die()
{
}

// 
// Start address: 0x1ebea0
void bhEne17_Brain(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	// Line 1492, Address: 0x1ebea0, Func Offset: 0
	// Line 1495, Address: 0x1ebeac, Func Offset: 0xc
	// Line 1498, Address: 0x1ebeb8, Func Offset: 0x18
	// Line 1501, Address: 0x1ebecc, Func Offset: 0x2c
	// Line 1503, Address: 0x1ebef0, Func Offset: 0x50
	// Line 1504, Address: 0x1ebefc, Func Offset: 0x5c
	// Line 1505, Address: 0x1ebf04, Func Offset: 0x64
	// Line 1509, Address: 0x1ebf0c, Func Offset: 0x6c
	// Line 1510, Address: 0x1ebf1c, Func Offset: 0x7c
	// Line 1509, Address: 0x1ebf20, Func Offset: 0x80
	// Line 1510, Address: 0x1ebf24, Func Offset: 0x84
	// Line 1514, Address: 0x1ebf34, Func Offset: 0x94
	// Line 1516, Address: 0x1ebf54, Func Offset: 0xb4
	// Func End, Address: 0x1ebf64, Func Offset: 0xc4
}

// 100% matching!
void bhEne17_Brain00(BH_PWORK* epw) 
{
    if (epw->mode3 != 0) {
        if (!(plp->flg & 2) && !(plp->flg & 4)) {
            
            if (!(EXP0_I(8) & 0x400)) {
                
                if (EXP0_F(20) < 24.0f &&
                    ikou3(epw, (NJS_POINT3*)&plp->px, 0x2000) == 0) {
                    
                    if (EXP0_F(20) < 15.5f && (plp->stflg & 0x400)) {
                        epw->mode1 = 0;
                        epw->mode2 = 4;
                        epw->mode3 = 0;
                    } else {
                        epw->mode1 = 0;
                        epw->mode2 = 3;
                        epw->mode3 = 0;
                    }
                } else {
                    epw->mode1 = 1;
                    epw->mode2 = 2;
                    epw->mode3 = 0;
                }
            }
        }
    }
}

// 100% matching!
void bhEne17_MVType00(BH_PWORK* epw) 
{
    if (epw->mode1 == 1) {
        bhEne17_Brain(epw);
    }
    bhEne17_MoveMode2[epw->mode2](epw);
}


// 100% matching!
void bhEne17_MV00(BH_PWORK* epw)
{
    switch (epw->mode3) {                      
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 7);
        EXP0_I(8) &= 0xBFFFFFFF;
        epw->mode1 = 1;
        
        if (EXP0_F(20) < 24.0f) {
            epw->ct0 = 10;
        } else {
            epw->ct0 = 1;
        }
        
        EXP0_I(8) |= 0x400;
        
        epw->ct0 += EXP0_I(4);
        epw->ct1 = 0;
        EXP0_I(4) = 0;
        epw->mode3 += 1;
        /* fallthrough */
        
    case 1:
        if (--epw->ct0 < 0) {
            EXP0_I(8) &= ~0x400;
        }
        
        if ((epw->wpnr_no != 14) && (epw->wpnr_no != 15) && (epw->wpnr_no != 16) && (epw->wpnr_no != 17) && (EXP0_I(8) & 0x400) && (plp->stflg & 0x400)) {
            if (++epw->ct1 > 10) {
                EXP0_I(8) &= ~0x400;
            }
        }
    }
}

// 100% matching!
void bhEne17_MV01(BH_PWORK *epw)
{
    switch (epw->mode3) {
    case 0:
        bhEne_ChgMtn(epw, 1, 1966080, 5);
        epw->flg |= 0x40000;
        epw->ct0 = 0;
        epw->mode3++;
        /* fallthrough */
    case 1:
        ikou(epw, (NJS_POINT3 *)&epw->exp0[28], 512);

        if (!(plp->flg & 2) && !(plp->flg & 4) &&
            EXP0_F(20) < 22.0f &&
            !ikou3(epw, (NJS_VECTOR *)&plp->px, 8192)) {
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne17_MV02(BH_PWORK* epw) 
{
    int frm;

    switch (epw->mode3) {                             
    case 0:
        bhEne_ChgMtn(epw, 15, 12320768, 56);
        epw->mtn_add = 262144;
        epw->flg |= 0x40000;
        EXP0_C(1) = 0;
        epw->ct0 = 0;
        epw->mode3 += 1;
        
    case 1:
        ikou(epw, (NJS_VECTOR* ) &plp->px, 728);
        frm = epw->frm_no / 65536;
        
        if ((frm >= 84) && (frm < 177) && (bhEne17_PlayerDGCheck(epw, plp) != 0)) {
            epw->ct0 = 1;
        }
        
        if ((epw->ct0 == 1) && ((epw->flg & 0x02000000) || (frm == 136))) {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
    }
}

// 100% matching1
void bhEne17_MV03(BH_PWORK* epw)
{
    NJS_VECTOR ofs;
    O_WORK* owp;
    int frm;
    int i;

    switch (epw->mode3) {                              
    case 0:
        bhEne_ChgMtn(epw, 16, 0, 80);
        epw->mtn_add = 262144;
        epw->flg  |= 0x40000;
        epw->flg2 |= 1;
        EXP0_UC(1) = 0;
        epw->mode3 += 1;
        
    case 1:
        frm = epw->frm_no / 65536;

        if (frm >= 72) {
            if (frm < 121) {
                ikou(epw, (NJS_POINT3*)&plp->px, 728);
            }
        }

        if (frm == 156) {
            ofs.x = -4.5f;
            ofs.y = 0.0f;
            ofs.z = -15.0f;
            bhEne17_SetSmokeEffect(epw, 0, &ofs);

            owp = &epw->mlwP->owP[1];
            ofs.x = owp->mtx[12];
            ofs.z = owp->mtx[14];
            
            ofs.y = 1.0f;

            for (i = 0; i < 4; i++) {
                bhEne17_SetSmokeEffect2(epw, &ofs, epw->ay + 20480 + (i * 8192));
            }
        }

        if (frm >= 156) {
            if (frm < 169) {
                for (i = 0; i < 2; i++) {
                    ofs.x = epw->px + ((80.0f * ((float)-rand() / -2147483648.0f)) - 40.0f);
                    ofs.y = 45.0f;
                    ofs.z = epw->pz + ((40.0f * ((float)-rand() / -2147483648.0f)) - 20.0f);
                    bhEff_SetPtcl(epw, &ofs, 8);
                }
            }
        }

        if (frm < 144) {
            /* nothing */
        } else if (frm < 169) {
            bhEne17_PlayerDGCheck(epw, plp);
        }

        if (!(EXP0_F(0x14) < 24.0f) && (plp->hp > 0)) {
            if (frm < 148 || frm > 220) {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                epw->flg2 &= ~1;
                return;
            }
        }

        if ((epw->frm_no / 65536) >= 312) {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            epw->flg2 &= ~1;
        }
    }
}

// 100% matching!
void bhEne17_MV04(BH_PWORK* epw) 
{
    int frm;

    switch (epw->mode3) {                          
    case 0:
        bhEne_ChgMtn(epw, 11, 0, 10);
        epw->flg |= 0x40000;
        epw->flg2 |= 1;
        EXP0_C(1) = 0;
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;
        
        if ((frm >= 21) && (frm < 29)) {
            bhEne17_PlayerDGCheck(epw, plp);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num) - 1) {
            epw->mode1 = 1;
            epw->mode2 = 6;
            epw->mode3 = 0;
            EXP0_I(4) = 0;
            epw->flg2 &= ~1;
        }
    }
}

void bhEne17_MV05(BH_PWORK* epw) 
{
    O_WORK* owk;
    NJS_POINT3 ofs;
    int i;
    int frm;

    switch (epw->mode3) {                        
    case 0:
        bhEne_ChgMtn(epw, 2, 0, 10);
        epw->flg |= 0x40000;
        EXP0_C(1) = 0;
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;
        
        if (frm >= 0) {
            if (frm < 23) {
                ikou(epw, (NJS_POINT3*)&plp->px, 728);
            }
        }
        
        if (frm >= 31) {
            if (frm < 37) {
                bhEne17_PlayerDGCheck(epw, plp);
            }
        }
        
        if (frm == 32) {
            ofs.x = 0.0f;
            ofs.y = 0.0f;
            ofs.z = -15.0f;
            bhEne17_SetSmokeEffect(epw, 0,  &ofs);
            owk = &epw->mlwP->owP[1];
            ofs.x = owk->mtx[12];
            ofs.z = owk->mtx[14];
            ofs.y = 1.0f;
            for(i = 0; i < 4; i++) {
                bhEne17_SetSmokeEffect2(epw, &ofs, epw->ay + 20480 + (i * 8192));
            }
        }
        
        if (frm >= 36) {
            if (frm <= 40) {
                for(i = 0; i < 2; i++) {
                    ofs.x = epw->px + ((80.0f * (-rand() / -2.1474836e9f)) - 40.0f);
                    ofs.y = 45.0f;
                    ofs.z = epw->pz + ((40.0f * (-rand() / -2.1474836e9f)) - 20.0f);
                    bhEff_SetPtcl(epw,  &ofs, 8);
                }
            }
        }
    }
}

// 100% matching!
void bhEne17_MV06(BH_PWORK* epw)
{
    switch (epw->mode3) {
    case 0:
        bhEne_ChgMtn(epw, 17, 0, 7);
        EXP0_I(8) &= 0xBFFFFFFF;
        epw->mode1 = 1;

        if (EXP0_F(20) < 24.0f) {
            epw->ct0 = 10;
        } else {
            epw->ct0 = 1;
        }

        EXP0_I(8) |= 0x400;
        epw->ct0 += EXP0_I(4);
        epw->ct1 = 0;
        EXP0_I(4) = 0;
        epw->mode3++;
        /* fallthrough */

    case 1:
        if (--epw->ct0 < 0) {
            EXP0_I(8) &= ~0x400;
        }

        if ((*(int*)&epw->exp0[8] & 0x400) && (plp->stflg & 0x400)) {
            if (++epw->ct1 > 10) {
                EXP0_I(8) &= ~0x400;
            }
        }
        break;
    }
}

// 100% matching!
void bhEne17_DGType00(BH_PWORK* epw)
{
    bhEne17_DamageMode2[epw->mode2](epw);
}

// 
// Start address: 0x1ecc60
void bhEne17_DG00(BH_PWORK* epw)
{
	int ang;
	int frm;
	int wcnt_tbl[4] = { 0, 5, 20, 35 };
	// Line 2230, Address: 0x1ecc60, Func Offset: 0
	// Line 2231, Address: 0x1ecc6c, Func Offset: 0xc
	// Line 2230, Address: 0x1ecc74, Func Offset: 0x14
	// Line 2231, Address: 0x1ecc78, Func Offset: 0x18
	// Line 2235, Address: 0x1ecc84, Func Offset: 0x24
	// Line 2238, Address: 0x1ecca4, Func Offset: 0x44
	// Line 2240, Address: 0x1eccb4, Func Offset: 0x54
	// Line 2241, Address: 0x1eccbc, Func Offset: 0x5c
	// Line 2243, Address: 0x1ecce8, Func Offset: 0x88
	// Line 2244, Address: 0x1eccfc, Func Offset: 0x9c
	// Line 2247, Address: 0x1ecd04, Func Offset: 0xa4
	// Line 2249, Address: 0x1ecd18, Func Offset: 0xb8
	// Line 2252, Address: 0x1ecd20, Func Offset: 0xc0
	// Line 2255, Address: 0x1ecd30, Func Offset: 0xd0
	// Line 2257, Address: 0x1ecd54, Func Offset: 0xf4
	// Line 2258, Address: 0x1ecd5c, Func Offset: 0xfc
	// Line 2259, Address: 0x1ecd60, Func Offset: 0x100
	// Line 2257, Address: 0x1ecd64, Func Offset: 0x104
	// Line 2258, Address: 0x1ecd70, Func Offset: 0x110
	// Line 2259, Address: 0x1ecd7c, Func Offset: 0x11c
	// Line 2260, Address: 0x1ecd88, Func Offset: 0x128
	// Line 2263, Address: 0x1ecd94, Func Offset: 0x134
	// Line 2265, Address: 0x1ecd9c, Func Offset: 0x13c
	// Line 2267, Address: 0x1ecda8, Func Offset: 0x148
	// Line 2268, Address: 0x1ecdb0, Func Offset: 0x150
	// Line 2267, Address: 0x1ecdb4, Func Offset: 0x154
	// Line 2268, Address: 0x1ecdbc, Func Offset: 0x15c
	// Line 2269, Address: 0x1ecdd0, Func Offset: 0x170
	// Line 2273, Address: 0x1ecde0, Func Offset: 0x180
	// Line 2275, Address: 0x1ece04, Func Offset: 0x1a4
	// Line 2278, Address: 0x1ece1c, Func Offset: 0x1bc
	// Line 2280, Address: 0x1ece40, Func Offset: 0x1e0
	// Line 2283, Address: 0x1ece78, Func Offset: 0x218
	// Line 2285, Address: 0x1ece80, Func Offset: 0x220
	// Line 2284, Address: 0x1ece84, Func Offset: 0x224
	// Line 2285, Address: 0x1ece88, Func Offset: 0x228
	// Line 2286, Address: 0x1ece8c, Func Offset: 0x22c
	// Line 2292, Address: 0x1ece90, Func Offset: 0x230
	// Line 2294, Address: 0x1ece9c, Func Offset: 0x23c
	// Line 2295, Address: 0x1ecea4, Func Offset: 0x244
	// Line 2296, Address: 0x1ecea8, Func Offset: 0x248
	// Line 2297, Address: 0x1eceac, Func Offset: 0x24c
	// Line 2300, Address: 0x1eceb0, Func Offset: 0x250
	// Line 2302, Address: 0x1ecec0, Func Offset: 0x260
	// Line 2303, Address: 0x1ecec8, Func Offset: 0x268
	// Line 2304, Address: 0x1eced0, Func Offset: 0x270
	// Line 2306, Address: 0x1ecee8, Func Offset: 0x288
	// Line 2307, Address: 0x1ecef0, Func Offset: 0x290
	// Line 2308, Address: 0x1ecef8, Func Offset: 0x298
	// Line 2310, Address: 0x1ecf08, Func Offset: 0x2a8
	// Line 2311, Address: 0x1ecf10, Func Offset: 0x2b0
	// Line 2314, Address: 0x1ecf18, Func Offset: 0x2b8
	// Line 2319, Address: 0x1ecf24, Func Offset: 0x2c4
	// Func End, Address: 0x1ecf38, Func Offset: 0x2d8
}

// 
// Start address: 0x1ecf40
void bhEne17_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
	int ang;
	NJS_POINT3 ps;
	NJS_VECTOR dv;
	O_WORK* owk;
	// Line 2340, Address: 0x1ecf40, Func Offset: 0
	// Line 2348, Address: 0x1ecf58, Func Offset: 0x18
	// Line 2351, Address: 0x1ecf78, Func Offset: 0x38
	// Line 2352, Address: 0x1ecf84, Func Offset: 0x44
	// Line 2353, Address: 0x1ecf88, Func Offset: 0x48
	// Line 2358, Address: 0x1ecf8c, Func Offset: 0x4c
	// Line 2351, Address: 0x1ecf90, Func Offset: 0x50
	// Line 2352, Address: 0x1ecf98, Func Offset: 0x58
	// Line 2366, Address: 0x1ecf9c, Func Offset: 0x5c
	// Line 2352, Address: 0x1ecfa0, Func Offset: 0x60
	// Line 2353, Address: 0x1ecfa8, Func Offset: 0x68
	// Line 2356, Address: 0x1ecfb4, Func Offset: 0x74
	// Line 2357, Address: 0x1ecfb8, Func Offset: 0x78
	// Line 2358, Address: 0x1ecfbc, Func Offset: 0x7c
	// Line 2359, Address: 0x1ecfc0, Func Offset: 0x80
	// Line 2360, Address: 0x1ecfc4, Func Offset: 0x84
	// Line 2361, Address: 0x1ecfc8, Func Offset: 0x88
	// Line 2362, Address: 0x1ecfcc, Func Offset: 0x8c
	// Line 2364, Address: 0x1ecfd0, Func Offset: 0x90
	// Line 2365, Address: 0x1ecfe0, Func Offset: 0xa0
	// Line 2366, Address: 0x1ecff0, Func Offset: 0xb0
	// Line 2368, Address: 0x1ed000, Func Offset: 0xc0
	// Line 2370, Address: 0x1ed014, Func Offset: 0xd4
	// Line 2371, Address: 0x1ed01c, Func Offset: 0xdc
	// Line 2372, Address: 0x1ed024, Func Offset: 0xe4
	// Line 2373, Address: 0x1ed04c, Func Offset: 0x10c
	// Line 2376, Address: 0x1ed054, Func Offset: 0x114
	// Line 2377, Address: 0x1ed05c, Func Offset: 0x11c
	// Line 2378, Address: 0x1ed060, Func Offset: 0x120
	// Line 2380, Address: 0x1ed084, Func Offset: 0x144
	// Line 2383, Address: 0x1ed088, Func Offset: 0x148
	// Line 2384, Address: 0x1ed098, Func Offset: 0x158
	// Line 2385, Address: 0x1ed0a0, Func Offset: 0x160
	// Line 2390, Address: 0x1ed0a8, Func Offset: 0x168
	// Line 2392, Address: 0x1ed0bc, Func Offset: 0x17c
	// Line 2393, Address: 0x1ed0c4, Func Offset: 0x184
	// Line 2392, Address: 0x1ed0c8, Func Offset: 0x188
	// Line 2393, Address: 0x1ed0d0, Func Offset: 0x190
	// Line 2394, Address: 0x1ed0e4, Func Offset: 0x1a4
	// Line 2397, Address: 0x1ed0f4, Func Offset: 0x1b4
	// Line 2399, Address: 0x1ed104, Func Offset: 0x1c4
	// Line 2401, Address: 0x1ed120, Func Offset: 0x1e0
	// Line 2404, Address: 0x1ed12c, Func Offset: 0x1ec
	// Line 2406, Address: 0x1ed130, Func Offset: 0x1f0
	// Line 2407, Address: 0x1ed134, Func Offset: 0x1f4
	// Line 2408, Address: 0x1ed138, Func Offset: 0x1f8
	// Line 2404, Address: 0x1ed13c, Func Offset: 0x1fc
	// Line 2405, Address: 0x1ed140, Func Offset: 0x200
	// Line 2406, Address: 0x1ed148, Func Offset: 0x208
	// Line 2407, Address: 0x1ed14c, Func Offset: 0x20c
	// Line 2408, Address: 0x1ed154, Func Offset: 0x214
	// Line 2410, Address: 0x1ed160, Func Offset: 0x220
	// Line 2413, Address: 0x1ed164, Func Offset: 0x224
	// Line 2410, Address: 0x1ed168, Func Offset: 0x228
	// Line 2411, Address: 0x1ed16c, Func Offset: 0x22c
	// Line 2412, Address: 0x1ed174, Func Offset: 0x234
	// Line 2413, Address: 0x1ed17c, Func Offset: 0x23c
	// Line 2416, Address: 0x1ed188, Func Offset: 0x248
	// Line 2419, Address: 0x1ed198, Func Offset: 0x258
	// Line 2420, Address: 0x1ed1a4, Func Offset: 0x264
	// Line 2422, Address: 0x1ed1a8, Func Offset: 0x268
	// Line 2419, Address: 0x1ed1ac, Func Offset: 0x26c
	// Line 2420, Address: 0x1ed1b4, Func Offset: 0x274
	// Line 2423, Address: 0x1ed1b8, Func Offset: 0x278
	// Line 2422, Address: 0x1ed1c0, Func Offset: 0x280
	// Line 2428, Address: 0x1ed1c4, Func Offset: 0x284
	// Line 2420, Address: 0x1ed1c8, Func Offset: 0x288
	// Line 2422, Address: 0x1ed1d0, Func Offset: 0x290
	// Line 2423, Address: 0x1ed1f0, Func Offset: 0x2b0
	// Line 2428, Address: 0x1ed1f4, Func Offset: 0x2b4
	// Line 2423, Address: 0x1ed1f8, Func Offset: 0x2b8
	// Line 2424, Address: 0x1ed200, Func Offset: 0x2c0
	// Line 2425, Address: 0x1ed20c, Func Offset: 0x2cc
	// Line 2426, Address: 0x1ed218, Func Offset: 0x2d8
	// Line 2427, Address: 0x1ed21c, Func Offset: 0x2dc
	// Line 2428, Address: 0x1ed224, Func Offset: 0x2e4
	// Line 2432, Address: 0x1ed22c, Func Offset: 0x2ec
	// Func End, Address: 0x1ed244, Func Offset: 0x304
}

// 
// Start address: 0x1ed250
void bhEne17_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
	int frm;
	int i;
	int rot;
	NJS_VECTOR dv;
	NJS_POINT3 key;
	O_WORK* owk;
	NJS_CNK_OBJECT* obj;
	POS_WORK* pos_p;
	POS_WORK* mtn_pos[4] = 
	{
		ply_mtn42_pos,
		ply_mtn43_pos,
		ply_mtn44_pos,
		ply_mtn45_pos
	};
	// Line 2450, Address: 0x1ed250, Func Offset: 0
	// Line 2451, Address: 0x1ed268, Func Offset: 0x18
	// Line 2450, Address: 0x1ed270, Func Offset: 0x20
	// Line 2451, Address: 0x1ed278, Func Offset: 0x28
	// Line 2466, Address: 0x1ed288, Func Offset: 0x38
	// Line 2469, Address: 0x1ed2b4, Func Offset: 0x64
	// Line 2470, Address: 0x1ed2c0, Func Offset: 0x70
	// Line 2471, Address: 0x1ed2c4, Func Offset: 0x74
	// Line 2477, Address: 0x1ed2c8, Func Offset: 0x78
	// Line 2469, Address: 0x1ed2cc, Func Offset: 0x7c
	// Line 2470, Address: 0x1ed2d4, Func Offset: 0x84
	// Line 2485, Address: 0x1ed2d8, Func Offset: 0x88
	// Line 2470, Address: 0x1ed2dc, Func Offset: 0x8c
	// Line 2471, Address: 0x1ed2e4, Func Offset: 0x94
	// Line 2474, Address: 0x1ed2f0, Func Offset: 0xa0
	// Line 2475, Address: 0x1ed2f8, Func Offset: 0xa8
	// Line 2476, Address: 0x1ed2fc, Func Offset: 0xac
	// Line 2477, Address: 0x1ed300, Func Offset: 0xb0
	// Line 2478, Address: 0x1ed304, Func Offset: 0xb4
	// Line 2479, Address: 0x1ed308, Func Offset: 0xb8
	// Line 2480, Address: 0x1ed30c, Func Offset: 0xbc
	// Line 2481, Address: 0x1ed310, Func Offset: 0xc0
	// Line 2483, Address: 0x1ed314, Func Offset: 0xc4
	// Line 2484, Address: 0x1ed324, Func Offset: 0xd4
	// Line 2485, Address: 0x1ed334, Func Offset: 0xe4
	// Line 2486, Address: 0x1ed344, Func Offset: 0xf4
	// Line 2488, Address: 0x1ed358, Func Offset: 0x108
	// Line 2489, Address: 0x1ed360, Func Offset: 0x110
	// Line 2490, Address: 0x1ed388, Func Offset: 0x138
	// Line 2493, Address: 0x1ed390, Func Offset: 0x140
	// Line 2494, Address: 0x1ed3b4, Func Offset: 0x164
	// Line 2495, Address: 0x1ed3bc, Func Offset: 0x16c
	// Line 2497, Address: 0x1ed3c4, Func Offset: 0x174
	// Line 2498, Address: 0x1ed3d0, Func Offset: 0x180
	// Line 2499, Address: 0x1ed3d8, Func Offset: 0x188
	// Line 2502, Address: 0x1ed3e0, Func Offset: 0x190
	// Line 2503, Address: 0x1ed3e8, Func Offset: 0x198
	// Line 2505, Address: 0x1ed3f4, Func Offset: 0x1a4
	// Line 2506, Address: 0x1ed3fc, Func Offset: 0x1ac
	// Line 2505, Address: 0x1ed400, Func Offset: 0x1b0
	// Line 2506, Address: 0x1ed408, Func Offset: 0x1b8
	// Line 2507, Address: 0x1ed41c, Func Offset: 0x1cc
	// Line 2510, Address: 0x1ed42c, Func Offset: 0x1dc
	// Line 2512, Address: 0x1ed438, Func Offset: 0x1e8
	// Line 2515, Address: 0x1ed43c, Func Offset: 0x1ec
	// Line 2512, Address: 0x1ed440, Func Offset: 0x1f0
	// Line 2513, Address: 0x1ed444, Func Offset: 0x1f4
	// Line 2514, Address: 0x1ed44c, Func Offset: 0x1fc
	// Line 2515, Address: 0x1ed454, Func Offset: 0x204
	// Line 2517, Address: 0x1ed458, Func Offset: 0x208
	// Line 2518, Address: 0x1ed470, Func Offset: 0x220
	// Line 2520, Address: 0x1ed478, Func Offset: 0x228
	// Line 2522, Address: 0x1ed47c, Func Offset: 0x22c
	// Line 2523, Address: 0x1ed48c, Func Offset: 0x23c
	// Line 2524, Address: 0x1ed49c, Func Offset: 0x24c
	// Line 2526, Address: 0x1ed4a0, Func Offset: 0x250
	// Line 2528, Address: 0x1ed4a8, Func Offset: 0x258
	// Line 2529, Address: 0x1ed4b8, Func Offset: 0x268
	// Line 2531, Address: 0x1ed4c4, Func Offset: 0x274
	// Line 2532, Address: 0x1ed4cc, Func Offset: 0x27c
	// Line 2534, Address: 0x1ed4d4, Func Offset: 0x284
	// Line 2537, Address: 0x1ed4dc, Func Offset: 0x28c
	// Line 2541, Address: 0x1ed4ec, Func Offset: 0x29c
	// Line 2545, Address: 0x1ed4f0, Func Offset: 0x2a0
	// Line 2548, Address: 0x1ed4f8, Func Offset: 0x2a8
	// Line 2547, Address: 0x1ed500, Func Offset: 0x2b0
	// Line 2541, Address: 0x1ed504, Func Offset: 0x2b4
	// Line 2547, Address: 0x1ed508, Func Offset: 0x2b8
	// Line 2554, Address: 0x1ed50c, Func Offset: 0x2bc
	// Line 2542, Address: 0x1ed510, Func Offset: 0x2c0
	// Line 2545, Address: 0x1ed518, Func Offset: 0x2c8
	// Line 2553, Address: 0x1ed51c, Func Offset: 0x2cc
	// Line 2545, Address: 0x1ed520, Func Offset: 0x2d0
	// Line 2547, Address: 0x1ed528, Func Offset: 0x2d8
	// Line 2548, Address: 0x1ed548, Func Offset: 0x2f8
	// Line 2553, Address: 0x1ed54c, Func Offset: 0x2fc
	// Line 2548, Address: 0x1ed550, Func Offset: 0x300
	// Line 2549, Address: 0x1ed558, Func Offset: 0x308
	// Line 2550, Address: 0x1ed564, Func Offset: 0x314
	// Line 2551, Address: 0x1ed570, Func Offset: 0x320
	// Line 2552, Address: 0x1ed574, Func Offset: 0x324
	// Line 2553, Address: 0x1ed57c, Func Offset: 0x32c
	// Line 2554, Address: 0x1ed584, Func Offset: 0x334
	// Line 2559, Address: 0x1ed590, Func Offset: 0x340
	// Line 2561, Address: 0x1ed5ac, Func Offset: 0x35c
	// Line 2562, Address: 0x1ed5b0, Func Offset: 0x360
	// Line 2568, Address: 0x1ed5b4, Func Offset: 0x364
	// Line 2561, Address: 0x1ed5b8, Func Offset: 0x368
	// Line 2562, Address: 0x1ed5c4, Func Offset: 0x374
	// Line 2564, Address: 0x1ed5d0, Func Offset: 0x380
	// Line 2565, Address: 0x1ed5d8, Func Offset: 0x388
	// Line 2566, Address: 0x1ed5dc, Func Offset: 0x38c
	// Line 2568, Address: 0x1ed5e0, Func Offset: 0x390
	// Line 2569, Address: 0x1ed5e8, Func Offset: 0x398
	// Line 2570, Address: 0x1ed5fc, Func Offset: 0x3ac
	// Line 2571, Address: 0x1ed610, Func Offset: 0x3c0
	// Line 2573, Address: 0x1ed620, Func Offset: 0x3d0
	// Func End, Address: 0x1ed640, Func Offset: 0x3f0
}

// 
// Start address: 0x1ed640
int bhEne17_PlayerDGCheck(BH_PWORK* epw, BH_PWORK* pl)
{
	NJS_VECTOR v;
	NJS_POINT3 pd;
	NJS_POINT3 ps;
	O_WORK* owk;
	int i;
	NJS_CAPSULE cap;
	// Line 2594, Address: 0x1ed640, Func Offset: 0
	// Line 2600, Address: 0x1ed660, Func Offset: 0x20
	// Line 2606, Address: 0x1ed6ac, Func Offset: 0x6c
	// Line 2611, Address: 0x1ed6b8, Func Offset: 0x78
	// Line 2613, Address: 0x1ed6c0, Func Offset: 0x80
	// Line 2614, Address: 0x1ed6c4, Func Offset: 0x84
	// Line 2615, Address: 0x1ed6c8, Func Offset: 0x88
	// Line 2619, Address: 0x1ed6cc, Func Offset: 0x8c
	// Line 2613, Address: 0x1ed6d0, Func Offset: 0x90
	// Line 2623, Address: 0x1ed6d8, Func Offset: 0x98
	// Line 2613, Address: 0x1ed6e0, Func Offset: 0xa0
	// Line 2614, Address: 0x1ed6e4, Func Offset: 0xa4
	// Line 2615, Address: 0x1ed6f4, Func Offset: 0xb4
	// Line 2616, Address: 0x1ed704, Func Offset: 0xc4
	// Line 2617, Address: 0x1ed714, Func Offset: 0xd4
	// Line 2618, Address: 0x1ed724, Func Offset: 0xe4
	// Line 2623, Address: 0x1ed734, Func Offset: 0xf4
	// Line 2626, Address: 0x1ed744, Func Offset: 0x104
	// Line 2627, Address: 0x1ed74c, Func Offset: 0x10c
	// Line 2642, Address: 0x1ed750, Func Offset: 0x110
	// Line 2627, Address: 0x1ed75c, Func Offset: 0x11c
	// Line 2628, Address: 0x1ed760, Func Offset: 0x120
	// Line 2629, Address: 0x1ed768, Func Offset: 0x128
	// Line 2642, Address: 0x1ed76c, Func Offset: 0x12c
	// Line 2645, Address: 0x1ed774, Func Offset: 0x134
	// Line 2648, Address: 0x1ed77c, Func Offset: 0x13c
	// Line 2650, Address: 0x1ed78c, Func Offset: 0x14c
	// Line 2652, Address: 0x1ed794, Func Offset: 0x154
	// Line 2651, Address: 0x1ed798, Func Offset: 0x158
	// Line 2652, Address: 0x1ed79c, Func Offset: 0x15c
	// Line 2653, Address: 0x1ed7a0, Func Offset: 0x160
	// Line 2654, Address: 0x1ed7a4, Func Offset: 0x164
	// Line 2655, Address: 0x1ed7b0, Func Offset: 0x170
	// Line 2656, Address: 0x1ed7bc, Func Offset: 0x17c
	// Line 2658, Address: 0x1ed7cc, Func Offset: 0x18c
	// Line 2660, Address: 0x1ed7d8, Func Offset: 0x198
	// Line 2662, Address: 0x1ed7e4, Func Offset: 0x1a4
	// Line 2663, Address: 0x1ed7e8, Func Offset: 0x1a8
	// Line 2666, Address: 0x1ed7f0, Func Offset: 0x1b0
	// Line 2668, Address: 0x1ed800, Func Offset: 0x1c0
	// Line 2677, Address: 0x1ed804, Func Offset: 0x1c4
	// Line 2680, Address: 0x1ed80c, Func Offset: 0x1cc
	// Line 2681, Address: 0x1ed814, Func Offset: 0x1d4
	// Line 2682, Address: 0x1ed818, Func Offset: 0x1d8
	// Line 2683, Address: 0x1ed81c, Func Offset: 0x1dc
	// Line 2684, Address: 0x1ed820, Func Offset: 0x1e0
	// Line 2686, Address: 0x1ed82c, Func Offset: 0x1ec
	// Line 2693, Address: 0x1ed838, Func Offset: 0x1f8
	// Line 2697, Address: 0x1ed840, Func Offset: 0x200
	// Line 2693, Address: 0x1ed848, Func Offset: 0x208
	// Line 2694, Address: 0x1ed854, Func Offset: 0x214
	// Line 2695, Address: 0x1ed858, Func Offset: 0x218
	// Line 2697, Address: 0x1ed85c, Func Offset: 0x21c
	// Line 2699, Address: 0x1ed868, Func Offset: 0x228
	// Line 2700, Address: 0x1ed874, Func Offset: 0x234
	// Line 2703, Address: 0x1ed878, Func Offset: 0x238
	// Line 2699, Address: 0x1ed880, Func Offset: 0x240
	// Line 2703, Address: 0x1ed884, Func Offset: 0x244
	// Line 2699, Address: 0x1ed888, Func Offset: 0x248
	// Line 2700, Address: 0x1ed890, Func Offset: 0x250
	// Line 2701, Address: 0x1ed894, Func Offset: 0x254
	// Line 2703, Address: 0x1ed8a0, Func Offset: 0x260
	// Line 2704, Address: 0x1ed8a8, Func Offset: 0x268
	// Line 2705, Address: 0x1ed8c0, Func Offset: 0x280
	// Line 2706, Address: 0x1ed8d8, Func Offset: 0x298
	// Line 2707, Address: 0x1ed8f0, Func Offset: 0x2b0
	// Line 2708, Address: 0x1ed908, Func Offset: 0x2c8
	// Line 2709, Address: 0x1ed920, Func Offset: 0x2e0
	// Line 2710, Address: 0x1ed938, Func Offset: 0x2f8
	// Line 2712, Address: 0x1ed950, Func Offset: 0x310
	// Line 2713, Address: 0x1ed954, Func Offset: 0x314
	// Line 2712, Address: 0x1ed95c, Func Offset: 0x31c
	// Line 2713, Address: 0x1ed960, Func Offset: 0x320
	// Line 2718, Address: 0x1ed96c, Func Offset: 0x32c
	// Line 2720, Address: 0x1ed974, Func Offset: 0x334
	// Line 2721, Address: 0x1ed984, Func Offset: 0x344
	// Func End, Address: 0x1ed9a8, Func Offset: 0x368
}

// 
// Start address: 0x1ed9b0
void bhEne17_SePlay(BH_PWORK* epw, int no)
{
	// Line 2794, Address: 0x1ed9b0, Func Offset: 0
	// Line 2795, Address: 0x1ed9bc, Func Offset: 0xc
	// Line 2797, Address: 0x1ed9d0, Func Offset: 0x20
	// Line 2798, Address: 0x1ed9ec, Func Offset: 0x3c
	// Func End, Address: 0x1ed9f8, Func Offset: 0x48
}

// 
// Start address: 0x1eda00
int bhEne17_CameraControl(BH_PWORK* epw)
{
	// Line 2819, Address: 0x1eda00, Func Offset: 0
	// Line 2820, Address: 0x1eda14, Func Offset: 0x14
	// Line 2822, Address: 0x1eda28, Func Offset: 0x28
	// Line 2825, Address: 0x1eda4c, Func Offset: 0x4c
	// Line 2827, Address: 0x1eda68, Func Offset: 0x68
	// Line 2825, Address: 0x1eda6c, Func Offset: 0x6c
	// Line 2827, Address: 0x1eda70, Func Offset: 0x70
	// Line 2825, Address: 0x1eda74, Func Offset: 0x74
	// Line 2827, Address: 0x1eda94, Func Offset: 0x94
	// Line 2828, Address: 0x1edaa4, Func Offset: 0xa4
	// Line 2831, Address: 0x1edaac, Func Offset: 0xac
	// Line 2832, Address: 0x1edab4, Func Offset: 0xb4
	// Line 2833, Address: 0x1edabc, Func Offset: 0xbc
	// Line 2834, Address: 0x1edac4, Func Offset: 0xc4
	// Line 2837, Address: 0x1edad8, Func Offset: 0xd8
	// Func End, Address: 0x1edaec, Func Offset: 0xec
}

// 
// Start address: 0x1edaf0
void bhEne17_AfterimageAxEffect(BH_PWORK* epw, NJS_MATRIX* mtx, NJS_POINT3* ofs, unsigned int argb)
{
	int eno;
	// Line 2842, Address: 0x1edaf0, Func Offset: 0
	// Line 2845, Address: 0x1edb04, Func Offset: 0x14
	// Line 2847, Address: 0x1edb30, Func Offset: 0x40
	// Line 2849, Address: 0x1edb3c, Func Offset: 0x4c
	// Line 2850, Address: 0x1edb40, Func Offset: 0x50
	// Line 2847, Address: 0x1edb44, Func Offset: 0x54
	// Line 2848, Address: 0x1edb50, Func Offset: 0x60
	// Line 2857, Address: 0x1edb58, Func Offset: 0x68
	// Line 2848, Address: 0x1edb64, Func Offset: 0x74
	// Line 2849, Address: 0x1edb70, Func Offset: 0x80
	// Line 2850, Address: 0x1edb84, Func Offset: 0x94
	// Line 2851, Address: 0x1edb98, Func Offset: 0xa8
	// Line 2852, Address: 0x1edbac, Func Offset: 0xbc
	// Line 2853, Address: 0x1edbc0, Func Offset: 0xd0
	// Line 2854, Address: 0x1edbd4, Func Offset: 0xe4
	// Line 2855, Address: 0x1edbe8, Func Offset: 0xf8
	// Line 2857, Address: 0x1edbfc, Func Offset: 0x10c
	// Line 2858, Address: 0x1edc14, Func Offset: 0x124
	// Line 2860, Address: 0x1edc2c, Func Offset: 0x13c
	// Line 2863, Address: 0x1edc38, Func Offset: 0x148
	// Line 2860, Address: 0x1edc3c, Func Offset: 0x14c
	// Line 2861, Address: 0x1edc54, Func Offset: 0x164
	// Line 2860, Address: 0x1edc60, Func Offset: 0x170
	// Line 2861, Address: 0x1edc68, Func Offset: 0x178
	// Line 2863, Address: 0x1edc6c, Func Offset: 0x17c
	// Line 2864, Address: 0x1edc7c, Func Offset: 0x18c
	// Line 2865, Address: 0x1edc94, Func Offset: 0x1a4
	// Line 2866, Address: 0x1edcc4, Func Offset: 0x1d4
	// Line 2867, Address: 0x1edcf4, Func Offset: 0x204
	// Line 2868, Address: 0x1edd24, Func Offset: 0x234
	// Line 2869, Address: 0x1edd38, Func Offset: 0x248
	// Line 2871, Address: 0x1edd48, Func Offset: 0x258
	// Func End, Address: 0x1edd60, Func Offset: 0x270
}

// 
// Start address: 0x1edd60
void bhEne17_SetSmokeEffect(BH_PWORK* epw, int lnk_onj, NJS_POINT3* ofs)
{
	int j;
	int i;
	int eno;
	NJS_POINT3 ps;
	O_WORK* owk;
	// Line 2877, Address: 0x1edd60, Func Offset: 0
	// Line 2884, Address: 0x1edd80, Func Offset: 0x20
	// Line 2894, Address: 0x1edd88, Func Offset: 0x28
	// Line 2884, Address: 0x1edd8c, Func Offset: 0x2c
	// Line 2894, Address: 0x1edd90, Func Offset: 0x30
	// Line 2884, Address: 0x1edd94, Func Offset: 0x34
	// Line 2894, Address: 0x1edda0, Func Offset: 0x40
	// Line 2885, Address: 0x1edda4, Func Offset: 0x44
	// Line 2887, Address: 0x1eddb0, Func Offset: 0x50
	// Line 2897, Address: 0x1eddb4, Func Offset: 0x54
	// Line 2885, Address: 0x1eddb8, Func Offset: 0x58
	// Line 2886, Address: 0x1eddc4, Func Offset: 0x64
	// Line 2899, Address: 0x1eddd0, Func Offset: 0x70
	// Line 2886, Address: 0x1eddd4, Func Offset: 0x74
	// Line 2887, Address: 0x1edde0, Func Offset: 0x80
	// Line 2888, Address: 0x1eddf4, Func Offset: 0x94
	// Line 2889, Address: 0x1ede08, Func Offset: 0xa8
	// Line 2890, Address: 0x1ede1c, Func Offset: 0xbc
	// Line 2891, Address: 0x1ede30, Func Offset: 0xd0
	// Line 2892, Address: 0x1ede48, Func Offset: 0xe8
	// Line 2894, Address: 0x1ede5c, Func Offset: 0xfc
	// Line 2895, Address: 0x1ede60, Func Offset: 0x100
	// Line 2894, Address: 0x1ede64, Func Offset: 0x104
	// Line 2895, Address: 0x1ede68, Func Offset: 0x108
	// Line 2896, Address: 0x1ede6c, Func Offset: 0x10c
	// Line 2894, Address: 0x1ede70, Func Offset: 0x110
	// Line 2896, Address: 0x1ede74, Func Offset: 0x114
	// Line 2897, Address: 0x1ede78, Func Offset: 0x118
	// Line 2901, Address: 0x1ede80, Func Offset: 0x120
	// Line 2902, Address: 0x1ede8c, Func Offset: 0x12c
	// Line 2901, Address: 0x1ede94, Func Offset: 0x134
	// Line 2902, Address: 0x1ede98, Func Offset: 0x138
	// Line 2901, Address: 0x1ede9c, Func Offset: 0x13c
	// Line 2902, Address: 0x1edea0, Func Offset: 0x140
	// Line 2903, Address: 0x1edeb4, Func Offset: 0x154
	// Line 2905, Address: 0x1edec0, Func Offset: 0x160
	// Line 2903, Address: 0x1edec4, Func Offset: 0x164
	// Line 2907, Address: 0x1eded0, Func Offset: 0x170
	// Line 2908, Address: 0x1edf30, Func Offset: 0x1d0
	// Line 2910, Address: 0x1edf58, Func Offset: 0x1f8
	// Line 2908, Address: 0x1edf5c, Func Offset: 0x1fc
	// Line 2910, Address: 0x1edf74, Func Offset: 0x214
	// Line 2908, Address: 0x1edf7c, Func Offset: 0x21c
	// Line 2910, Address: 0x1edfa0, Func Offset: 0x240
	// Line 2911, Address: 0x1edfb8, Func Offset: 0x258
	// Line 2913, Address: 0x1edfc4, Func Offset: 0x264
	// Line 2915, Address: 0x1edfe8, Func Offset: 0x288
	// Line 2913, Address: 0x1edfec, Func Offset: 0x28c
	// Line 2914, Address: 0x1edff4, Func Offset: 0x294
	// Line 2916, Address: 0x1ee000, Func Offset: 0x2a0
	// Line 2917, Address: 0x1ee028, Func Offset: 0x2c8
	// Line 2916, Address: 0x1ee02c, Func Offset: 0x2cc
	// Line 2917, Address: 0x1ee03c, Func Offset: 0x2dc
	// Line 2918, Address: 0x1ee040, Func Offset: 0x2e0
	// Line 2916, Address: 0x1ee048, Func Offset: 0x2e8
	// Line 2917, Address: 0x1ee05c, Func Offset: 0x2fc
	// Line 2918, Address: 0x1ee060, Func Offset: 0x300
	// Line 2919, Address: 0x1ee064, Func Offset: 0x304
	// Line 2921, Address: 0x1ee068, Func Offset: 0x308
	// Line 2922, Address: 0x1ee078, Func Offset: 0x318
	// Line 2923, Address: 0x1ee088, Func Offset: 0x328
	// Func End, Address: 0x1ee0ac, Func Offset: 0x34c
}

// 
// Start address: 0x1ee0b0
void bhEne17_SetSmokeEffect2(BH_PWORK* epw, NJS_POINT3* ofs, int rot)
{
	int i;
	int eno;
	// Line 2927, Address: 0x1ee0b0, Func Offset: 0
	// Line 2932, Address: 0x1ee0cc, Func Offset: 0x1c
	// Line 2933, Address: 0x1ee0dc, Func Offset: 0x2c
	// Line 2932, Address: 0x1ee0e0, Func Offset: 0x30
	// Line 2933, Address: 0x1ee0ec, Func Offset: 0x3c
	// Line 2935, Address: 0x1ee0f4, Func Offset: 0x44
	// Line 2944, Address: 0x1ee0fc, Func Offset: 0x4c
	// Line 2933, Address: 0x1ee104, Func Offset: 0x54
	// Line 2934, Address: 0x1ee110, Func Offset: 0x60
	// Line 2935, Address: 0x1ee124, Func Offset: 0x74
	// Line 2936, Address: 0x1ee138, Func Offset: 0x88
	// Line 2937, Address: 0x1ee14c, Func Offset: 0x9c
	// Line 2938, Address: 0x1ee160, Func Offset: 0xb0
	// Line 2939, Address: 0x1ee174, Func Offset: 0xc4
	// Line 2940, Address: 0x1ee188, Func Offset: 0xd8
	// Line 2942, Address: 0x1ee19c, Func Offset: 0xec
	// Line 2946, Address: 0x1ee1b4, Func Offset: 0x104
	// Line 2947, Address: 0x1ee208, Func Offset: 0x158
	// Line 2949, Address: 0x1ee230, Func Offset: 0x180
	// Line 2947, Address: 0x1ee234, Func Offset: 0x184
	// Line 2949, Address: 0x1ee24c, Func Offset: 0x19c
	// Line 2947, Address: 0x1ee254, Func Offset: 0x1a4
	// Line 2949, Address: 0x1ee26c, Func Offset: 0x1bc
	// Line 2950, Address: 0x1ee284, Func Offset: 0x1d4
	// Line 2952, Address: 0x1ee290, Func Offset: 0x1e0
	// Line 2954, Address: 0x1ee2b4, Func Offset: 0x204
	// Line 2952, Address: 0x1ee2b8, Func Offset: 0x208
	// Line 2953, Address: 0x1ee2c0, Func Offset: 0x210
	// Line 2955, Address: 0x1ee2cc, Func Offset: 0x21c
	// Line 2956, Address: 0x1ee2f4, Func Offset: 0x244
	// Line 2955, Address: 0x1ee2f8, Func Offset: 0x248
	// Line 2956, Address: 0x1ee308, Func Offset: 0x258
	// Line 2957, Address: 0x1ee30c, Func Offset: 0x25c
	// Line 2955, Address: 0x1ee314, Func Offset: 0x264
	// Line 2956, Address: 0x1ee328, Func Offset: 0x278
	// Line 2957, Address: 0x1ee32c, Func Offset: 0x27c
	// Line 2958, Address: 0x1ee330, Func Offset: 0x280
	// Line 2959, Address: 0x1ee334, Func Offset: 0x284
	// Line 2960, Address: 0x1ee338, Func Offset: 0x288
	// Line 2961, Address: 0x1ee348, Func Offset: 0x298
	// Func End, Address: 0x1ee368, Func Offset: 0x2b8
}

// 
// Start address: 0x1ee370
void bhEne17_SetSmokeEffect3(BH_PWORK* epw, NJS_POINT3* ofs, int rot)
{
	int eno;
	// Line 2965, Address: 0x1ee370, Func Offset: 0
	// Line 2968, Address: 0x1ee380, Func Offset: 0x10
	// Line 2969, Address: 0x1ee390, Func Offset: 0x20
	// Line 2968, Address: 0x1ee394, Func Offset: 0x24
	// Line 2969, Address: 0x1ee3a0, Func Offset: 0x30
	// Line 2971, Address: 0x1ee3a8, Func Offset: 0x38
	// Line 2969, Address: 0x1ee3ac, Func Offset: 0x3c
	// Line 2970, Address: 0x1ee3b8, Func Offset: 0x48
	// Line 2971, Address: 0x1ee3cc, Func Offset: 0x5c
	// Line 2972, Address: 0x1ee3e0, Func Offset: 0x70
	// Line 2973, Address: 0x1ee3f4, Func Offset: 0x84
	// Line 2974, Address: 0x1ee408, Func Offset: 0x98
	// Line 2975, Address: 0x1ee41c, Func Offset: 0xac
	// Line 2976, Address: 0x1ee430, Func Offset: 0xc0
	// Line 2978, Address: 0x1ee444, Func Offset: 0xd4
	// Line 2979, Address: 0x1ee45c, Func Offset: 0xec
	// Line 2980, Address: 0x1ee474, Func Offset: 0x104
	// Line 2982, Address: 0x1ee488, Func Offset: 0x118
	// Line 2983, Address: 0x1ee4e8, Func Offset: 0x178
	// Line 2985, Address: 0x1ee510, Func Offset: 0x1a0
	// Line 2983, Address: 0x1ee514, Func Offset: 0x1a4
	// Line 2985, Address: 0x1ee52c, Func Offset: 0x1bc
	// Line 2983, Address: 0x1ee534, Func Offset: 0x1c4
	// Line 2985, Address: 0x1ee558, Func Offset: 0x1e8
	// Line 2986, Address: 0x1ee570, Func Offset: 0x200
	// Line 2988, Address: 0x1ee57c, Func Offset: 0x20c
	// Line 2989, Address: 0x1ee5a0, Func Offset: 0x230
	// Line 2988, Address: 0x1ee5ac, Func Offset: 0x23c
	// Line 2989, Address: 0x1ee5b4, Func Offset: 0x244
	// Line 2990, Address: 0x1ee5b8, Func Offset: 0x248
	// Line 2989, Address: 0x1ee5c4, Func Offset: 0x254
	// Line 2990, Address: 0x1ee5c8, Func Offset: 0x258
	// Line 2989, Address: 0x1ee5cc, Func Offset: 0x25c
	// Line 2991, Address: 0x1ee5d0, Func Offset: 0x260
	// Line 2992, Address: 0x1ee60c, Func Offset: 0x29c
	// Line 2993, Address: 0x1ee620, Func Offset: 0x2b0
	// Line 2991, Address: 0x1ee630, Func Offset: 0x2c0
	// Line 2993, Address: 0x1ee63c, Func Offset: 0x2cc
	// Line 2994, Address: 0x1ee640, Func Offset: 0x2d0
	// Line 2991, Address: 0x1ee648, Func Offset: 0x2d8
	// Line 2994, Address: 0x1ee64c, Func Offset: 0x2dc
	// Line 2991, Address: 0x1ee650, Func Offset: 0x2e0
	// Line 2992, Address: 0x1ee658, Func Offset: 0x2e8
	// Line 2993, Address: 0x1ee65c, Func Offset: 0x2ec
	// Line 2994, Address: 0x1ee660, Func Offset: 0x2f0
	// Line 2996, Address: 0x1ee664, Func Offset: 0x2f4
	// Func End, Address: 0x1ee678, Func Offset: 0x308
}

// 
// Start address: 0x1ee680
void bhEne17_SetLight(BH_PWORK* epw, NJS_POINT3 *ofs)
{
	LGT_WORK* lp;
	// Line 3017, Address: 0x1ee680, Func Offset: 0
	// Line 3020, Address: 0x1ee688, Func Offset: 0x8
	// Line 3021, Address: 0x1ee68c, Func Offset: 0xc
	// Line 3022, Address: 0x1ee690, Func Offset: 0x10
	// Line 3017, Address: 0x1ee694, Func Offset: 0x14
	// Line 3023, Address: 0x1ee698, Func Offset: 0x18
	// Line 3024, Address: 0x1ee69c, Func Offset: 0x1c
	// Line 3027, Address: 0x1ee6a0, Func Offset: 0x20
	// Line 3020, Address: 0x1ee6a4, Func Offset: 0x24
	// Line 3021, Address: 0x1ee6a8, Func Offset: 0x28
	// Line 3022, Address: 0x1ee6ac, Func Offset: 0x2c
	// Line 3023, Address: 0x1ee6b0, Func Offset: 0x30
	// Line 3024, Address: 0x1ee6b4, Func Offset: 0x34
	// Line 3025, Address: 0x1ee6b8, Func Offset: 0x38
	// Line 3026, Address: 0x1ee6bc, Func Offset: 0x3c
	// Line 3028, Address: 0x1ee6c0, Func Offset: 0x40
	// Line 3027, Address: 0x1ee6c4, Func Offset: 0x44
	// Line 3028, Address: 0x1ee6c8, Func Offset: 0x48
	// Line 3029, Address: 0x1ee6cc, Func Offset: 0x4c
	// Line 3031, Address: 0x1ee6d0, Func Offset: 0x50
	// Line 3032, Address: 0x1ee6d4, Func Offset: 0x54
	// Line 3033, Address: 0x1ee6d8, Func Offset: 0x58
	// Line 3034, Address: 0x1ee6dc, Func Offset: 0x5c
	// Line 3035, Address: 0x1ee6e4, Func Offset: 0x64
	// Line 3036, Address: 0x1ee6ec, Func Offset: 0x6c
	// Line 3038, Address: 0x1ee6f4, Func Offset: 0x74
	// Line 3040, Address: 0x1ee6f8, Func Offset: 0x78
	// Func End, Address: 0x1ee700, Func Offset: 0x80
}
