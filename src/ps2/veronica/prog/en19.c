#include "../../../ps2/veronica/prog/en19.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/subpl.h"

// ENEMY: Tyrant T-078 

static void (*bhEne19_Mode0[6])(BH_PWORK*) = 
{ 
	bhEne19_Init,
	bhEne19_Move,
	bhEne19_Damage,
	bhEne19_Die,
	NULL,
	bhEne19_Event
};
static void (*bhEne19_BrainType[3])(BH_PWORK*) = 
{ 
	bhEne19_Br00,
	bhEne19_Br01,
	bhEne19_Br02
};
static TY_DMG_MODE(*bhEne19_CheckDmgLvl[3])(BH_PWORK*, FW_WORK*) = 
{ 
	bhEne19_CheckDmgLvl0,
	bhEne19_CheckDmgLvl1,
	bhEne19_CheckDmgLvl2
};

EA_WORK En19ActTbl[50] =
{
    {  1033,  8,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv08  },
    {  1034,  9,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv09  },
    {  2056,  7,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv07  },
    {  2308,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2309,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2310,  5, 56, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2564,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  2565,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  2566,  5, 22, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  2816,  0,  0, 0, 32,  1.0f, 0x00080020, bhEne19_Mv00  },
    {  2827, 10,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv10  },
    {  2832, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    {  3589,  4, 40, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3599, 14,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv14  },
    {  3845,  4,  4, 0,  6,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  3854, 13,  4, 0,  8,  0.9f, 0x00080020, bhEne19_Mv13  },
    {  4100,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4101,  4,  4, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4102,  5, 26, 0,  8,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  4356,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  4357,  4, 40, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    {  4358,  5, 58, 0, 10,  1.0f, 0x00080020, bhEne19_Mv05  },
    {  5124,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    {  5125,  4, 38, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65024,  0,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv00  },
    { 65028,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04a },
    { 65029,  4,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65030,  5,  0, 0,  0,  1.0f, 0x00080000, bhEne19_Mv04b },
    { 65280,  0,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv00  },
    { 65281,  1,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv01  },
    { 65282,  2,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv02  },
    { 65283,  3,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv03  },
    { 65284,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04a },
    { 65285,  4,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv04b },
    { 65286,  5,  0, 0, 12,  1.0f, 0x00080020, bhEne19_Mv05  },
    { 65287,  6,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv06  },
    { 65288,  7,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv07  },
    { 65289,  8,  0, 0,  8, 0.95f, 0x00080020, bhEne19_Mv08  },
    { 65290,  9,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv09  },
    { 65291, 10,  0, 0, 16,  1.0f, 0x00080020, bhEne19_Mv10  },
    { 65292, 11,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv11  },
    { 65293, 12,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv12  },
    { 65294, 13,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv13  },
    { 65295, 14,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv14  },
    { 65296, 15,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv15  },
    { 65297, 16,  0, 0,  8,  0.9f, 0x00080020, bhEne19_Mv16  },
    { 65298, 17,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv17  },
    { 65299, 18,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv18  },
    { 65300, 19,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv19  },
    { 65301, 20,  0, 0,  8,  1.0f, 0x00080020, bhEne19_Mv20  }
};
COMBWEP_WORK En19CombWepTbl[21] =
{
    {   0, {  0,  0,  0 },   0,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  90, { 10,  0,  0 }, 999, 100 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 100, { 12, 10,  6 }, 210, 200 },
    { 190, {  8,  6,  4 }, 300,   0 },
    { 500, { 10, 10, 10 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    { 520, { 10, 10, 10 }, 600,   0 },
    { 300, {  8,  6,  2 }, 400, 200 },
    {  56, { 10,  8,  4 },  80,   0 },
    { 560, {  6,  3,  1 }, 600,   0 },
    {  10, { 10, 10, 10 },  60,   0 },
    {  60, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {  20, { 10, 10,  0 }, 120,   0 },
    {   0, {  0,  0,  0 },   0,   0 },
    {  40, { 10, 10, 10 },  60,   0 },
    {   0, {  0,  0,  0 },   0,   0 }
};

static const char FlpTbl[26] =
{
    0, 1, 2, 3, 4, 5, 14, 15, 16, 17, 10, 11, 12, 13, 6, 7, 8, 9, 22, 23, 24, 25, 18, 19, 20, 21
};
static const CPCL Ene19CapColTbl[28] =
{
    {   1,  1, 20 },
    {   0, -8,  0 },
    {   1,  2, 10 },
    {   2,  3, 16 },
    {   3,  3, 12 },
    {   0, 15,  0 },
    {  14, 14, 20 },
    {  -6, 18,  8 },
    {   6,  6, 20 },
    {   6, 18,  8 },
    {   4,  5,  9 },
    {   5,  5, 12 },
    {   0,  9,  0 },
    {   7,  8,  9 },
    {   8,  9,  9 },
    {   9,  9, 15 },
    {  14,  0,  0 },
    {  15, 16,  9 },
    {  16, 17,  9 },
    {  17, 17, 15 },
    { -14,  0,  0 },
    {  18, 19, 10 },
    {  19, 20,  8 },
    {  20, 21,  8 },
    {  22, 23, 10 },
    {  23, 24,  8 },
    {  24, 25,  8 },
    {   0,  0,  0 }
};
static const ACT_TBL_WORK En19PlyActTbl[17] = 
{
    { 35, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 30, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg042     },
    { 31, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg043     },
    { 32, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg044     },
    { 33, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg045     },
    { 34, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 35, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg046_047 },
    { 36, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 37, 0, 0,  8, 255, -1, 0x20, NULL                  },
    { 38, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 39, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg050_051 },
    { 40, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 41, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg052_053 },
    { 42, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 43, 0, 0,  8, 255, -1, 0x20, bhEne19_PlyDmg117_118 },
    { 44, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     },
    { 45, 0, 0, 16, 255, -1, 0x20, bhEne19_PlyDmgFal     }
};
static const float En19OvlTbl[3] = 
{
    2.5f, 1.5f, 1.5f    
};
static const int En19HpTbl[4][3] = 
{
    { 500, 700, 900 },
    { 500, 700, 900 },
    { 300, 420, 540 },
    { 900, 900, 900 }
};
static const float En19AtkRng[3][4] = 
{
    { 13.0f, 11.0f, 15.0f, 13.0f },  
    { 11.0f, 15.0f, 13.0f, 17.0f },  
    { 12.0f, 13.0f, 14.0f, 15.0f }   
};
static const PMA_WORK Eff30aPrm1[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 728, 2.0f, 0.98f, 1456, 4.0f, 0.99f       
    },
    {
        2, 0, 1456, 4.0f, 0.99f, 728, 2.0f, 0.98f      
    }
};
static const PMA_WORK Eff30aPrm2[3] = 
{
    {
        1, 0, 0, 0.0f, 0.0f, 0, 0.0f, 0.0f        
    },
    {
        2, 16384, 8192, 1.0f, 0.9f, 8192, 2.0f, 0.94f      
    },
    {
        2, 0, 8192, 2.0f, 0.94f, 8192, 1.0f, 0.9f      
    }
};

static COMBJOINT_WORK En19CombJointTbl[26] = { 0 };
static PMA_WORK* Eff30aTbl[3] = 
{ 
	Eff30aPrm2,
	Eff30aPrm1,
	Eff30aPrm2
};

// 
// Start address: 0x1f0450
void bhEne19(BH_PWORK* ewP)
{
	ML_WORK* mlwP;
	EB_WORK* ebP;
	R49_WORK* r49P;
	int sts;
	FW_WORK* fwP;
	// Line 449, Address: 0x1f0450, Func Offset: 0
	// Line 453, Address: 0x1f0464, Func Offset: 0x14
	// Line 455, Address: 0x1f0470, Func Offset: 0x20
	// Line 458, Address: 0x1f0474, Func Offset: 0x24
	// Line 459, Address: 0x1f0498, Func Offset: 0x48
	// Line 462, Address: 0x1f04a0, Func Offset: 0x50
	// Line 463, Address: 0x1f04b0, Func Offset: 0x60
	// Line 467, Address: 0x1f04c8, Func Offset: 0x78
	// Line 471, Address: 0x1f04d8, Func Offset: 0x88
	// Line 472, Address: 0x1f04e8, Func Offset: 0x98
	// Line 474, Address: 0x1f04f4, Func Offset: 0xa4
	// Line 475, Address: 0x1f04f8, Func Offset: 0xa8
	// Line 476, Address: 0x1f04fc, Func Offset: 0xac
	// Line 480, Address: 0x1f0500, Func Offset: 0xb0
	// Line 481, Address: 0x1f0510, Func Offset: 0xc0
	// Line 483, Address: 0x1f0514, Func Offset: 0xc4
	// Line 484, Address: 0x1f0524, Func Offset: 0xd4
	// Line 483, Address: 0x1f052c, Func Offset: 0xdc
	// Line 484, Address: 0x1f0530, Func Offset: 0xe0
	// Line 485, Address: 0x1f0538, Func Offset: 0xe8
	// Line 508, Address: 0x1f054c, Func Offset: 0xfc
	// Line 510, Address: 0x1f056c, Func Offset: 0x11c
	// Line 514, Address: 0x1f0578, Func Offset: 0x128
	// Line 516, Address: 0x1f0584, Func Offset: 0x134
	// Func End, Address: 0x1f059c, Func Offset: 0x14c
	scePrintf("bhEne19 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f05a0
static void bhEne19_Init(BH_PWORK* ewP)
{
	O_WORK* owP;
	//NJS_CNK_OBJECT* objP;
	NJS_POINT3* posP;
	NJS_CNK_OBJECT* objP;
	float* rngP;
	FW_WORK* fwP;
	// Line 526, Address: 0x1f05a0, Func Offset: 0
	// Line 530, Address: 0x1f05b4, Func Offset: 0x14
	// Line 531, Address: 0x1f05d4, Func Offset: 0x34
	// Line 533, Address: 0x1f05e0, Func Offset: 0x40
	// Line 536, Address: 0x1f05e4, Func Offset: 0x44
	// Line 546, Address: 0x1f05e8, Func Offset: 0x48
	// Line 547, Address: 0x1f05ec, Func Offset: 0x4c
	// Line 550, Address: 0x1f05f0, Func Offset: 0x50
	// Line 536, Address: 0x1f05f4, Func Offset: 0x54
	// Line 537, Address: 0x1f05f8, Func Offset: 0x58
	// Line 538, Address: 0x1f05fc, Func Offset: 0x5c
	// Line 539, Address: 0x1f0600, Func Offset: 0x60
	// Line 540, Address: 0x1f0604, Func Offset: 0x64
	// Line 546, Address: 0x1f0608, Func Offset: 0x68
	// Line 547, Address: 0x1f060c, Func Offset: 0x6c
	// Line 548, Address: 0x1f0610, Func Offset: 0x70
	// Line 549, Address: 0x1f0614, Func Offset: 0x74
	// Line 550, Address: 0x1f0618, Func Offset: 0x78
	// Line 551, Address: 0x1f061c, Func Offset: 0x7c
	// Line 552, Address: 0x1f0620, Func Offset: 0x80
	// Line 553, Address: 0x1f0634, Func Offset: 0x94
	// Line 552, Address: 0x1f0638, Func Offset: 0x98
	// Line 553, Address: 0x1f063c, Func Offset: 0x9c
	// Line 554, Address: 0x1f0640, Func Offset: 0xa0
	// Line 552, Address: 0x1f0644, Func Offset: 0xa4
	// Line 567, Address: 0x1f0648, Func Offset: 0xa8
	// Line 552, Address: 0x1f064c, Func Offset: 0xac
	// Line 554, Address: 0x1f0664, Func Offset: 0xc4
	// Line 563, Address: 0x1f0668, Func Offset: 0xc8
	// Line 552, Address: 0x1f0670, Func Offset: 0xd0
	// Line 553, Address: 0x1f0678, Func Offset: 0xd8
	// Line 554, Address: 0x1f067c, Func Offset: 0xdc
	// Line 572, Address: 0x1f0680, Func Offset: 0xe0
	// Line 573, Address: 0x1f0684, Func Offset: 0xe4
	// Line 574, Address: 0x1f0688, Func Offset: 0xe8
	// Line 554, Address: 0x1f068c, Func Offset: 0xec
	// Line 576, Address: 0x1f0698, Func Offset: 0xf8
	// Line 577, Address: 0x1f069c, Func Offset: 0xfc
	// Line 578, Address: 0x1f06a0, Func Offset: 0x100
	// Line 554, Address: 0x1f06a4, Func Offset: 0x104
	// Line 557, Address: 0x1f06a8, Func Offset: 0x108
	// Line 558, Address: 0x1f06ac, Func Offset: 0x10c
	// Line 559, Address: 0x1f06b0, Func Offset: 0x110
	// Line 560, Address: 0x1f06b4, Func Offset: 0x114
	// Line 561, Address: 0x1f06b8, Func Offset: 0x118
	// Line 562, Address: 0x1f06bc, Func Offset: 0x11c
	// Line 563, Address: 0x1f06c0, Func Offset: 0x120
	// Line 587, Address: 0x1f06c4, Func Offset: 0x124
	// Line 566, Address: 0x1f06c8, Func Offset: 0x128
	// Line 587, Address: 0x1f06cc, Func Offset: 0x12c
	// Line 579, Address: 0x1f06d0, Func Offset: 0x130
	// Line 580, Address: 0x1f06d4, Func Offset: 0x134
	// Line 566, Address: 0x1f06d8, Func Offset: 0x138
	// Line 567, Address: 0x1f06e0, Func Offset: 0x140
	// Line 590, Address: 0x1f06e4, Func Offset: 0x144
	// Line 585, Address: 0x1f06e8, Func Offset: 0x148
	// Line 586, Address: 0x1f06ec, Func Offset: 0x14c
	// Line 590, Address: 0x1f06f0, Func Offset: 0x150
	// Line 567, Address: 0x1f06f4, Func Offset: 0x154
	// Line 568, Address: 0x1f06fc, Func Offset: 0x15c
	// Line 569, Address: 0x1f0708, Func Offset: 0x168
	// Line 572, Address: 0x1f0714, Func Offset: 0x174
	// Line 573, Address: 0x1f0718, Func Offset: 0x178
	// Line 574, Address: 0x1f071c, Func Offset: 0x17c
	// Line 575, Address: 0x1f0720, Func Offset: 0x180
	// Line 576, Address: 0x1f0724, Func Offset: 0x184
	// Line 577, Address: 0x1f0728, Func Offset: 0x188
	// Line 578, Address: 0x1f072c, Func Offset: 0x18c
	// Line 579, Address: 0x1f0730, Func Offset: 0x190
	// Line 580, Address: 0x1f073c, Func Offset: 0x19c
	// Line 583, Address: 0x1f0740, Func Offset: 0x1a0
	// Line 584, Address: 0x1f0744, Func Offset: 0x1a4
	// Line 585, Address: 0x1f0748, Func Offset: 0x1a8
	// Line 586, Address: 0x1f074c, Func Offset: 0x1ac
	// Line 587, Address: 0x1f0750, Func Offset: 0x1b0
	// Line 590, Address: 0x1f0764, Func Offset: 0x1c4
	// Line 592, Address: 0x1f0770, Func Offset: 0x1d0
	// Line 593, Address: 0x1f0778, Func Offset: 0x1d8
	// Line 594, Address: 0x1f0780, Func Offset: 0x1e0
	// Line 595, Address: 0x1f0788, Func Offset: 0x1e8
	// Line 599, Address: 0x1f0790, Func Offset: 0x1f0
	// Line 600, Address: 0x1f07a0, Func Offset: 0x200
	// Line 601, Address: 0x1f07a8, Func Offset: 0x208
	// Line 610, Address: 0x1f07c8, Func Offset: 0x228
	// Line 611, Address: 0x1f07d0, Func Offset: 0x230
	// Line 610, Address: 0x1f07dc, Func Offset: 0x23c
	// Line 612, Address: 0x1f07e0, Func Offset: 0x240
	// Line 611, Address: 0x1f07e4, Func Offset: 0x244
	// Line 612, Address: 0x1f07f0, Func Offset: 0x250
	// Line 613, Address: 0x1f0804, Func Offset: 0x264
	// Line 612, Address: 0x1f0808, Func Offset: 0x268
	// Line 613, Address: 0x1f080c, Func Offset: 0x26c
	// Line 614, Address: 0x1f0820, Func Offset: 0x280
	// Line 613, Address: 0x1f0824, Func Offset: 0x284
	// Line 614, Address: 0x1f0828, Func Offset: 0x288
	// Line 618, Address: 0x1f0840, Func Offset: 0x2a0
	// Line 622, Address: 0x1f084c, Func Offset: 0x2ac
	// Line 624, Address: 0x1f0850, Func Offset: 0x2b0
	// Line 627, Address: 0x1f0854, Func Offset: 0x2b4
	// Line 635, Address: 0x1f0858, Func Offset: 0x2b8
	// Line 622, Address: 0x1f085c, Func Offset: 0x2bc
	// Line 623, Address: 0x1f0860, Func Offset: 0x2c0
	// Line 624, Address: 0x1f0864, Func Offset: 0x2c4
	// Line 625, Address: 0x1f0870, Func Offset: 0x2d0
	// Line 626, Address: 0x1f087c, Func Offset: 0x2dc
	// Line 627, Address: 0x1f0888, Func Offset: 0x2e8
	// Line 630, Address: 0x1f0894, Func Offset: 0x2f4
	// Line 631, Address: 0x1f08a0, Func Offset: 0x300
	// Line 632, Address: 0x1f08ac, Func Offset: 0x30c
	// Line 633, Address: 0x1f08b8, Func Offset: 0x318
	// Line 635, Address: 0x1f08c4, Func Offset: 0x324
	// Line 639, Address: 0x1f08d0, Func Offset: 0x330
	// Line 642, Address: 0x1f08dc, Func Offset: 0x33c
	// Line 639, Address: 0x1f08e8, Func Offset: 0x348
	// Line 642, Address: 0x1f08f0, Func Offset: 0x350
	// Line 643, Address: 0x1f08f8, Func Offset: 0x358
	// Line 652, Address: 0x1f0910, Func Offset: 0x370
	// Line 654, Address: 0x1f0934, Func Offset: 0x394
	// Line 656, Address: 0x1f0950, Func Offset: 0x3b0
	// Func End, Address: 0x1f0964, Func Offset: 0x3c4
	scePrintf("bhEne19_Init - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f0970
static void bhEne19_Move(BH_PWORK* ewP)
{
	float ar_bak;
	float ah_bak;
	NJS_MATRIX* mtxP;
	NJS_POINT3 pos;
	NJS_CNK_OBJECT* objP;
	int* stsP;
	FW_WORK* fwP;
	// Line 666, Address: 0x1f0970, Func Offset: 0
	// Line 667, Address: 0x1f098c, Func Offset: 0x1c
	// Line 668, Address: 0x1f0994, Func Offset: 0x24
	// Line 685, Address: 0x1f0998, Func Offset: 0x28
	// Line 688, Address: 0x1f09a0, Func Offset: 0x30
	// Line 691, Address: 0x1f09c0, Func Offset: 0x50
	// Line 694, Address: 0x1f09cc, Func Offset: 0x5c
	// Line 695, Address: 0x1f09dc, Func Offset: 0x6c
	// Line 702, Address: 0x1f09e0, Func Offset: 0x70
	// Line 707, Address: 0x1f09e8, Func Offset: 0x78
	// Line 695, Address: 0x1f09ec, Func Offset: 0x7c
	// Line 697, Address: 0x1f09f0, Func Offset: 0x80
	// Line 702, Address: 0x1f09fc, Func Offset: 0x8c
	// Line 703, Address: 0x1f0a08, Func Offset: 0x98
	// Line 707, Address: 0x1f0a14, Func Offset: 0xa4
	// Line 712, Address: 0x1f0a20, Func Offset: 0xb0
	// Line 715, Address: 0x1f0a3c, Func Offset: 0xcc
	// Line 718, Address: 0x1f0a48, Func Offset: 0xd8
	// Line 721, Address: 0x1f0a5c, Func Offset: 0xec
	// Line 722, Address: 0x1f0a70, Func Offset: 0x100
	// Line 723, Address: 0x1f0a7c, Func Offset: 0x10c
	// Line 726, Address: 0x1f0a94, Func Offset: 0x124
	// Line 730, Address: 0x1f0aa4, Func Offset: 0x134
	// Line 728, Address: 0x1f0aac, Func Offset: 0x13c
	// Line 730, Address: 0x1f0ab0, Func Offset: 0x140
	// Line 728, Address: 0x1f0ab8, Func Offset: 0x148
	// Line 730, Address: 0x1f0abc, Func Offset: 0x14c
	// Line 728, Address: 0x1f0ac4, Func Offset: 0x154
	// Line 730, Address: 0x1f0ac8, Func Offset: 0x158
	// Line 732, Address: 0x1f0ad4, Func Offset: 0x164
	// Line 735, Address: 0x1f0af0, Func Offset: 0x180
	// Line 740, Address: 0x1f0afc, Func Offset: 0x18c
	// Line 736, Address: 0x1f0b00, Func Offset: 0x190
	// Line 735, Address: 0x1f0b04, Func Offset: 0x194
	// Line 736, Address: 0x1f0b08, Func Offset: 0x198
	// Line 738, Address: 0x1f0b10, Func Offset: 0x1a0
	// Line 736, Address: 0x1f0b14, Func Offset: 0x1a4
	// Line 738, Address: 0x1f0b18, Func Offset: 0x1a8
	// Line 739, Address: 0x1f0b20, Func Offset: 0x1b0
	// Line 741, Address: 0x1f0b24, Func Offset: 0x1b4
	// Line 740, Address: 0x1f0b28, Func Offset: 0x1b8
	// Line 741, Address: 0x1f0b2c, Func Offset: 0x1bc
	// Line 742, Address: 0x1f0b34, Func Offset: 0x1c4
	// Line 743, Address: 0x1f0b40, Func Offset: 0x1d0
	// Line 745, Address: 0x1f0b4c, Func Offset: 0x1dc
	// Line 746, Address: 0x1f0b58, Func Offset: 0x1e8
	// Line 745, Address: 0x1f0b5c, Func Offset: 0x1ec
	// Line 746, Address: 0x1f0b64, Func Offset: 0x1f4
	// Line 751, Address: 0x1f0b74, Func Offset: 0x204
	// Line 754, Address: 0x1f0b80, Func Offset: 0x210
	// Line 756, Address: 0x1f0b90, Func Offset: 0x220
	// Func End, Address: 0x1f0bb0, Func Offset: 0x240
	scePrintf("bhEne19_Move - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_Damage()
{

}

// 100% matching!
static void bhEne19_Die(BH_PWORK* ewP) 
{
    ewP->flg |= 0x2; 

    ewP->mtn_add = 0; 
}

// 100% matching!
static void bhEne19_Event(BH_PWORK* ewP)
{
    ((FW_WORK*)ewP->exp0)->status &= ~0x4;

    ewP->mlwP->owP[4].flg &= ~0x2;
    ewP->mlwP->owP[5].flg &= ~0x2;

    bhEne_Event(ewP);

    bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);

    bhEne19_CalcEnemy(ewP, (FW_WORK*)ewP->exp0);
}

// 
// Start address: 0x1f0c70
static void bhEne19_Br00(BH_PWORK* ewP)
{
	int lop;
	int act;
	int rte;
	int* wt1P;
	TY_BR_MODE2* br2P;
	TY_BR_MODE1* br1P;
	TY_BR_MODE0* br0P;
	int sts;
	int* pstP;
	int* stsP;
	FW_WORK* fwP;
	// Line 820, Address: 0x1f0c70, Func Offset: 0
	// Line 824, Address: 0x1f0c98, Func Offset: 0x28
	// Line 826, Address: 0x1f0ca4, Func Offset: 0x34
	// Line 834, Address: 0x1f0ca8, Func Offset: 0x38
	// Line 828, Address: 0x1f0cac, Func Offset: 0x3c
	// Line 834, Address: 0x1f0cb0, Func Offset: 0x40
	// Line 835, Address: 0x1f0cbc, Func Offset: 0x4c
	// Line 836, Address: 0x1f0cdc, Func Offset: 0x6c
	// Line 840, Address: 0x1f0ce8, Func Offset: 0x78
	// Line 844, Address: 0x1f0cf4, Func Offset: 0x84
	// Line 846, Address: 0x1f0d14, Func Offset: 0xa4
	// Line 847, Address: 0x1f0d18, Func Offset: 0xa8
	// Line 849, Address: 0x1f0d1c, Func Offset: 0xac
	// Line 850, Address: 0x1f0d20, Func Offset: 0xb0
	// Line 856, Address: 0x1f0d24, Func Offset: 0xb4
	// Line 861, Address: 0x1f0d2c, Func Offset: 0xbc
	// Line 857, Address: 0x1f0d30, Func Offset: 0xc0
	// Line 858, Address: 0x1f0d34, Func Offset: 0xc4
	// Line 859, Address: 0x1f0d40, Func Offset: 0xd0
	// Line 860, Address: 0x1f0d44, Func Offset: 0xd4
	// Line 862, Address: 0x1f0d48, Func Offset: 0xd8
	// Line 863, Address: 0x1f0d4c, Func Offset: 0xdc
	// Line 866, Address: 0x1f0d6c, Func Offset: 0xfc
	// Line 869, Address: 0x1f0da4, Func Offset: 0x134
	// Line 872, Address: 0x1f0ddc, Func Offset: 0x16c
	// Line 874, Address: 0x1f0de8, Func Offset: 0x178
	// Line 875, Address: 0x1f0df0, Func Offset: 0x180
	// Line 876, Address: 0x1f0df8, Func Offset: 0x188
	// Line 877, Address: 0x1f0e00, Func Offset: 0x190
	// Line 878, Address: 0x1f0e10, Func Offset: 0x1a0
	// Line 879, Address: 0x1f0e14, Func Offset: 0x1a4
	// Line 881, Address: 0x1f0e18, Func Offset: 0x1a8
	// Line 882, Address: 0x1f0e20, Func Offset: 0x1b0
	// Line 886, Address: 0x1f0e28, Func Offset: 0x1b8
	// Line 887, Address: 0x1f0e30, Func Offset: 0x1c0
	// Line 888, Address: 0x1f0e34, Func Offset: 0x1c4
	// Line 891, Address: 0x1f0e38, Func Offset: 0x1c8
	// Line 894, Address: 0x1f0e40, Func Offset: 0x1d0
	// Line 897, Address: 0x1f0e5c, Func Offset: 0x1ec
	// Line 898, Address: 0x1f0e74, Func Offset: 0x204
	// Line 899, Address: 0x1f0e7c, Func Offset: 0x20c
	// Line 900, Address: 0x1f0e8c, Func Offset: 0x21c
	// Line 901, Address: 0x1f0e90, Func Offset: 0x220
	// Line 902, Address: 0x1f0e98, Func Offset: 0x228
	// Line 903, Address: 0x1f0ea8, Func Offset: 0x238
	// Line 905, Address: 0x1f0eac, Func Offset: 0x23c
	// Line 906, Address: 0x1f0eb4, Func Offset: 0x244
	// Line 908, Address: 0x1f0eb8, Func Offset: 0x248
	// Line 909, Address: 0x1f0ebc, Func Offset: 0x24c
	// Line 912, Address: 0x1f0ec4, Func Offset: 0x254
	// Line 917, Address: 0x1f0ed4, Func Offset: 0x264
	// Line 920, Address: 0x1f0edc, Func Offset: 0x26c
	// Line 923, Address: 0x1f0ef8, Func Offset: 0x288
	// Line 925, Address: 0x1f0efc, Func Offset: 0x28c
	// Line 928, Address: 0x1f0f04, Func Offset: 0x294
	// Line 929, Address: 0x1f0f18, Func Offset: 0x2a8
	// Line 933, Address: 0x1f0f28, Func Offset: 0x2b8
	// Line 937, Address: 0x1f0f2c, Func Offset: 0x2bc
	// Line 941, Address: 0x1f0f34, Func Offset: 0x2c4
	// Line 944, Address: 0x1f0f50, Func Offset: 0x2e0
	// Line 946, Address: 0x1f0f54, Func Offset: 0x2e4
	// Line 949, Address: 0x1f0f5c, Func Offset: 0x2ec
	// Line 952, Address: 0x1f0f80, Func Offset: 0x310
	// Line 961, Address: 0x1f0f88, Func Offset: 0x318
	// Line 964, Address: 0x1f0fac, Func Offset: 0x33c
	// Line 965, Address: 0x1f0fbc, Func Offset: 0x34c
	// Line 966, Address: 0x1f0fd0, Func Offset: 0x360
	// Line 967, Address: 0x1f0fd8, Func Offset: 0x368
	// Line 970, Address: 0x1f0fe0, Func Offset: 0x370
	// Line 971, Address: 0x1f0fe8, Func Offset: 0x378
	// Line 974, Address: 0x1f0fec, Func Offset: 0x37c
	// Line 977, Address: 0x1f0ff4, Func Offset: 0x384
	// Line 979, Address: 0x1f1004, Func Offset: 0x394
	// Line 982, Address: 0x1f100c, Func Offset: 0x39c
	// Line 984, Address: 0x1f1018, Func Offset: 0x3a8
	// Line 987, Address: 0x1f1020, Func Offset: 0x3b0
	// Line 989, Address: 0x1f1030, Func Offset: 0x3c0
	// Line 990, Address: 0x1f1040, Func Offset: 0x3d0
	// Line 991, Address: 0x1f1044, Func Offset: 0x3d4
	// Line 994, Address: 0x1f1048, Func Offset: 0x3d8
	// Line 995, Address: 0x1f1050, Func Offset: 0x3e0
	// Line 996, Address: 0x1f1060, Func Offset: 0x3f0
	// Line 997, Address: 0x1f1064, Func Offset: 0x3f4
	// Line 999, Address: 0x1f1068, Func Offset: 0x3f8
	// Line 998, Address: 0x1f106c, Func Offset: 0x3fc
	// Line 1006, Address: 0x1f1070, Func Offset: 0x400
	// Line 1010, Address: 0x1f1078, Func Offset: 0x408
	// Line 1011, Address: 0x1f107c, Func Offset: 0x40c
	// Line 1014, Address: 0x1f10b0, Func Offset: 0x440
	// Line 1015, Address: 0x1f10bc, Func Offset: 0x44c
	// Line 1017, Address: 0x1f10c0, Func Offset: 0x450
	// Line 1018, Address: 0x1f10d0, Func Offset: 0x460
	// Line 1019, Address: 0x1f10d4, Func Offset: 0x464
	// Line 1021, Address: 0x1f10d8, Func Offset: 0x468
	// Line 1022, Address: 0x1f10e0, Func Offset: 0x470
	// Line 1023, Address: 0x1f10e4, Func Offset: 0x474
	// Line 1024, Address: 0x1f10ec, Func Offset: 0x47c
	// Line 1025, Address: 0x1f10f0, Func Offset: 0x480
	// Line 1028, Address: 0x1f10f4, Func Offset: 0x484
	// Line 1032, Address: 0x1f10fc, Func Offset: 0x48c
	// Line 1035, Address: 0x1f1118, Func Offset: 0x4a8
	// Line 1036, Address: 0x1f1130, Func Offset: 0x4c0
	// Line 1037, Address: 0x1f1138, Func Offset: 0x4c8
	// Line 1038, Address: 0x1f1148, Func Offset: 0x4d8
	// Line 1039, Address: 0x1f114c, Func Offset: 0x4dc
	// Line 1040, Address: 0x1f1154, Func Offset: 0x4e4
	// Line 1041, Address: 0x1f1164, Func Offset: 0x4f4
	// Line 1043, Address: 0x1f1168, Func Offset: 0x4f8
	// Line 1044, Address: 0x1f1170, Func Offset: 0x500
	// Line 1045, Address: 0x1f1174, Func Offset: 0x504
	// Line 1046, Address: 0x1f1178, Func Offset: 0x508
	// Line 1047, Address: 0x1f117c, Func Offset: 0x50c
	// Line 1050, Address: 0x1f1184, Func Offset: 0x514
	// Line 1055, Address: 0x1f1194, Func Offset: 0x524
	// Line 1059, Address: 0x1f119c, Func Offset: 0x52c
	// Line 1062, Address: 0x1f11b8, Func Offset: 0x548
	// Line 1063, Address: 0x1f11c8, Func Offset: 0x558
	// Line 1065, Address: 0x1f11cc, Func Offset: 0x55c
	// Line 1066, Address: 0x1f11d4, Func Offset: 0x564
	// Line 1067, Address: 0x1f11d8, Func Offset: 0x568
	// Line 1068, Address: 0x1f11dc, Func Offset: 0x56c
	// Line 1070, Address: 0x1f11e0, Func Offset: 0x570
	// Line 1073, Address: 0x1f11e8, Func Offset: 0x578
	// Line 1074, Address: 0x1f11f8, Func Offset: 0x588
	// Line 1075, Address: 0x1f11fc, Func Offset: 0x58c
	// Line 1080, Address: 0x1f1200, Func Offset: 0x590
	// Line 1083, Address: 0x1f1208, Func Offset: 0x598
	// Line 1086, Address: 0x1f1224, Func Offset: 0x5b4
	// Line 1087, Address: 0x1f1228, Func Offset: 0x5b8
	// Line 1090, Address: 0x1f122c, Func Offset: 0x5bc
	// Line 1091, Address: 0x1f1230, Func Offset: 0x5c0
	// Line 1092, Address: 0x1f1240, Func Offset: 0x5d0
	// Line 1093, Address: 0x1f1244, Func Offset: 0x5d4
	// Line 1100, Address: 0x1f1248, Func Offset: 0x5d8
	// Line 1104, Address: 0x1f1250, Func Offset: 0x5e0
	// Line 1109, Address: 0x1f1270, Func Offset: 0x600
	// Line 1110, Address: 0x1f1274, Func Offset: 0x604
	// Line 1107, Address: 0x1f1278, Func Offset: 0x608
	// Line 1112, Address: 0x1f127c, Func Offset: 0x60c
	// Line 1115, Address: 0x1f1284, Func Offset: 0x614
	// Line 1118, Address: 0x1f1298, Func Offset: 0x628
	// Line 1124, Address: 0x1f129c, Func Offset: 0x62c
	// Line 1127, Address: 0x1f12a4, Func Offset: 0x634
	// Line 1130, Address: 0x1f12c4, Func Offset: 0x654
	// Line 1134, Address: 0x1f12e4, Func Offset: 0x674
	// Line 1135, Address: 0x1f12e8, Func Offset: 0x678
	// Line 1133, Address: 0x1f12ec, Func Offset: 0x67c
	// Line 1135, Address: 0x1f12f0, Func Offset: 0x680
	// Line 1143, Address: 0x1f12f8, Func Offset: 0x688
	// Line 1146, Address: 0x1f1300, Func Offset: 0x690
	// Line 1149, Address: 0x1f1314, Func Offset: 0x6a4
	// Line 1150, Address: 0x1f1318, Func Offset: 0x6a8
	// Line 1157, Address: 0x1f131c, Func Offset: 0x6ac
	// Line 1158, Address: 0x1f1320, Func Offset: 0x6b0
	// Line 1161, Address: 0x1f132c, Func Offset: 0x6bc
	// Line 1164, Address: 0x1f1344, Func Offset: 0x6d4
	// Func End, Address: 0x1f1370, Func Offset: 0x700
	scePrintf("bhEne19_Br00 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f1370
static void bhEne19_Br01(BH_PWORK* ewP)
{
	ATR_WORK* htP;
	int lop;
	int act;
	int rte;
	int* wt1P;
	TY_BR_MODE2* br2P;
	TY_BR_MODE1* br1P;
	TY_BR_MODE0* br0P;
	int sts;
	int* pstP;
	int* stsP;
	FW_WORK* fwP;
	// Line 1174, Address: 0x1f1370, Func Offset: 0
	// Line 1175, Address: 0x1f139c, Func Offset: 0x2c
	// Line 1183, Address: 0x1f13a4, Func Offset: 0x34
	// Line 1177, Address: 0x1f13a8, Func Offset: 0x38
	// Line 1183, Address: 0x1f13ac, Func Offset: 0x3c
	// Line 1184, Address: 0x1f13b8, Func Offset: 0x48
	// Line 1185, Address: 0x1f13d8, Func Offset: 0x68
	// Line 1189, Address: 0x1f13e4, Func Offset: 0x74
	// Line 1193, Address: 0x1f13f0, Func Offset: 0x80
	// Line 1198, Address: 0x1f13f4, Func Offset: 0x84
	// Line 1194, Address: 0x1f13f8, Func Offset: 0x88
	// Line 1196, Address: 0x1f13fc, Func Offset: 0x8c
	// Line 1193, Address: 0x1f1400, Func Offset: 0x90
	// Line 1203, Address: 0x1f1404, Func Offset: 0x94
	// Line 1195, Address: 0x1f1408, Func Offset: 0x98
	// Line 1197, Address: 0x1f140c, Func Offset: 0x9c
	// Line 1199, Address: 0x1f1410, Func Offset: 0xa0
	// Line 1203, Address: 0x1f1414, Func Offset: 0xa4
	// Line 1207, Address: 0x1f1424, Func Offset: 0xb4
	// Line 1209, Address: 0x1f144c, Func Offset: 0xdc
	// Line 1211, Address: 0x1f1464, Func Offset: 0xf4
	// Line 1212, Address: 0x1f1470, Func Offset: 0x100
	// Line 1213, Address: 0x1f1478, Func Offset: 0x108
	// Line 1214, Address: 0x1f1480, Func Offset: 0x110
	// Line 1216, Address: 0x1f1484, Func Offset: 0x114
	// Line 1217, Address: 0x1f148c, Func Offset: 0x11c
	// Line 1218, Address: 0x1f1490, Func Offset: 0x120
	// Line 1219, Address: 0x1f1494, Func Offset: 0x124
	// Line 1220, Address: 0x1f1498, Func Offset: 0x128
	// Line 1227, Address: 0x1f149c, Func Offset: 0x12c
	// Line 1229, Address: 0x1f14b0, Func Offset: 0x140
	// Line 1230, Address: 0x1f14c4, Func Offset: 0x154
	// Line 1231, Address: 0x1f14dc, Func Offset: 0x16c
	// Line 1233, Address: 0x1f1504, Func Offset: 0x194
	// Line 1239, Address: 0x1f151c, Func Offset: 0x1ac
	// Line 1244, Address: 0x1f154c, Func Offset: 0x1dc
	// Line 1245, Address: 0x1f1568, Func Offset: 0x1f8
	// Line 1246, Address: 0x1f1570, Func Offset: 0x200
	// Line 1245, Address: 0x1f1578, Func Offset: 0x208
	// Line 1246, Address: 0x1f157c, Func Offset: 0x20c
	// Line 1251, Address: 0x1f15c0, Func Offset: 0x250
	// Line 1254, Address: 0x1f15e0, Func Offset: 0x270
	// Line 1257, Address: 0x1f1608, Func Offset: 0x298
	// Line 1259, Address: 0x1f1614, Func Offset: 0x2a4
	// Line 1260, Address: 0x1f161c, Func Offset: 0x2ac
	// Line 1261, Address: 0x1f1624, Func Offset: 0x2b4
	// Line 1262, Address: 0x1f162c, Func Offset: 0x2bc
	// Line 1263, Address: 0x1f163c, Func Offset: 0x2cc
	// Line 1265, Address: 0x1f1640, Func Offset: 0x2d0
	// Line 1266, Address: 0x1f1644, Func Offset: 0x2d4
	// Line 1267, Address: 0x1f164c, Func Offset: 0x2dc
	// Line 1268, Address: 0x1f167c, Func Offset: 0x30c
	// Line 1270, Address: 0x1f1680, Func Offset: 0x310
	// Line 1271, Address: 0x1f1684, Func Offset: 0x314
	// Line 1272, Address: 0x1f168c, Func Offset: 0x31c
	// Line 1276, Address: 0x1f1694, Func Offset: 0x324
	// Line 1277, Address: 0x1f169c, Func Offset: 0x32c
	// Line 1278, Address: 0x1f16a4, Func Offset: 0x334
	// Line 1279, Address: 0x1f16ac, Func Offset: 0x33c
	// Line 1281, Address: 0x1f16b4, Func Offset: 0x344
	// Line 1282, Address: 0x1f16b8, Func Offset: 0x348
	// Line 1283, Address: 0x1f16c0, Func Offset: 0x350
	// Line 1287, Address: 0x1f16c4, Func Offset: 0x354
	// Line 1288, Address: 0x1f16cc, Func Offset: 0x35c
	// Line 1290, Address: 0x1f16d0, Func Offset: 0x360
	// Line 1292, Address: 0x1f16d4, Func Offset: 0x364
	// Line 1295, Address: 0x1f16dc, Func Offset: 0x36c
	// Line 1298, Address: 0x1f1708, Func Offset: 0x398
	// Line 1299, Address: 0x1f1720, Func Offset: 0x3b0
	// Line 1300, Address: 0x1f1728, Func Offset: 0x3b8
	// Line 1302, Address: 0x1f1738, Func Offset: 0x3c8
	// Line 1303, Address: 0x1f1740, Func Offset: 0x3d0
	// Line 1306, Address: 0x1f1750, Func Offset: 0x3e0
	// Line 1307, Address: 0x1f1754, Func Offset: 0x3e4
	// Line 1308, Address: 0x1f175c, Func Offset: 0x3ec
	// Line 1311, Address: 0x1f1760, Func Offset: 0x3f0
	// Line 1314, Address: 0x1f1768, Func Offset: 0x3f8
	// Line 1317, Address: 0x1f1778, Func Offset: 0x408
	// Line 1321, Address: 0x1f1780, Func Offset: 0x410
	// Line 1322, Address: 0x1f17a0, Func Offset: 0x430
	// Line 1324, Address: 0x1f17a8, Func Offset: 0x438
	// Line 1325, Address: 0x1f17b0, Func Offset: 0x440
	// Line 1330, Address: 0x1f17c0, Func Offset: 0x450
	// Line 1334, Address: 0x1f17c8, Func Offset: 0x458
	// Line 1337, Address: 0x1f17e8, Func Offset: 0x478
	// Line 1338, Address: 0x1f17f0, Func Offset: 0x480
	// Line 1340, Address: 0x1f1800, Func Offset: 0x490
	// Line 1341, Address: 0x1f1808, Func Offset: 0x498
	// Line 1345, Address: 0x1f1818, Func Offset: 0x4a8
	// Line 1347, Address: 0x1f1820, Func Offset: 0x4b0
	// Line 1350, Address: 0x1f1828, Func Offset: 0x4b8
	// Line 1351, Address: 0x1f1864, Func Offset: 0x4f4
	// Line 1352, Address: 0x1f1874, Func Offset: 0x504
	// Line 1353, Address: 0x1f1878, Func Offset: 0x508
	// Line 1357, Address: 0x1f1890, Func Offset: 0x520
	// Line 1362, Address: 0x1f18a0, Func Offset: 0x530
	// Line 1366, Address: 0x1f18a8, Func Offset: 0x538
	// Line 1371, Address: 0x1f18c8, Func Offset: 0x558
	// Line 1374, Address: 0x1f18d0, Func Offset: 0x560
	// Line 1375, Address: 0x1f18e0, Func Offset: 0x570
	// Line 1377, Address: 0x1f1908, Func Offset: 0x598
	// Line 1381, Address: 0x1f1918, Func Offset: 0x5a8
	// Line 1385, Address: 0x1f191c, Func Offset: 0x5ac
	// Line 1389, Address: 0x1f1924, Func Offset: 0x5b4
	// Line 1394, Address: 0x1f194c, Func Offset: 0x5dc
	// Line 1397, Address: 0x1f1954, Func Offset: 0x5e4
	// Line 1399, Address: 0x1f196c, Func Offset: 0x5fc
	// Line 1405, Address: 0x1f197c, Func Offset: 0x60c
	// Line 1409, Address: 0x1f1984, Func Offset: 0x614
	// Line 1412, Address: 0x1f19b0, Func Offset: 0x640
	// Line 1414, Address: 0x1f19d0, Func Offset: 0x660
	// Line 1413, Address: 0x1f19d4, Func Offset: 0x664
	// Line 1415, Address: 0x1f19d8, Func Offset: 0x668
	// Line 1416, Address: 0x1f19e0, Func Offset: 0x670
	// Line 1417, Address: 0x1f19e8, Func Offset: 0x678
	// Line 1418, Address: 0x1f1a24, Func Offset: 0x6b4
	// Line 1422, Address: 0x1f1a28, Func Offset: 0x6b8
	// Line 1419, Address: 0x1f1a2c, Func Offset: 0x6bc
	// Line 1421, Address: 0x1f1a30, Func Offset: 0x6c0
	// Line 1424, Address: 0x1f1a34, Func Offset: 0x6c4
	// Line 1427, Address: 0x1f1a3c, Func Offset: 0x6cc
	// Line 1429, Address: 0x1f1a4c, Func Offset: 0x6dc
	// Line 1430, Address: 0x1f1a54, Func Offset: 0x6e4
	// Line 1431, Address: 0x1f1a60, Func Offset: 0x6f0
	// Line 1433, Address: 0x1f1a6c, Func Offset: 0x6fc
	// Line 1436, Address: 0x1f1a74, Func Offset: 0x704
	// Line 1437, Address: 0x1f1a84, Func Offset: 0x714
	// Line 1438, Address: 0x1f1a88, Func Offset: 0x718
	// Line 1445, Address: 0x1f1a8c, Func Offset: 0x71c
	// Line 1449, Address: 0x1f1a94, Func Offset: 0x724
	// Line 1452, Address: 0x1f1ad0, Func Offset: 0x760
	// Line 1454, Address: 0x1f1adc, Func Offset: 0x76c
	// Line 1455, Address: 0x1f1ae4, Func Offset: 0x774
	// Line 1456, Address: 0x1f1aec, Func Offset: 0x77c
	// Line 1457, Address: 0x1f1af4, Func Offset: 0x784
	// Line 1458, Address: 0x1f1afc, Func Offset: 0x78c
	// Line 1459, Address: 0x1f1b00, Func Offset: 0x790
	// Line 1461, Address: 0x1f1b04, Func Offset: 0x794
	// Line 1462, Address: 0x1f1b0c, Func Offset: 0x79c
	// Line 1463, Address: 0x1f1b10, Func Offset: 0x7a0
	// Line 1466, Address: 0x1f1b14, Func Offset: 0x7a4
	// Line 1467, Address: 0x1f1b1c, Func Offset: 0x7ac
	// Line 1468, Address: 0x1f1b20, Func Offset: 0x7b0
	// Line 1471, Address: 0x1f1b24, Func Offset: 0x7b4
	// Line 1474, Address: 0x1f1b2c, Func Offset: 0x7bc
	// Line 1477, Address: 0x1f1b50, Func Offset: 0x7e0
	// Line 1478, Address: 0x1f1b68, Func Offset: 0x7f8
	// Line 1479, Address: 0x1f1b70, Func Offset: 0x800
	// Line 1481, Address: 0x1f1b80, Func Offset: 0x810
	// Line 1482, Address: 0x1f1b88, Func Offset: 0x818
	// Line 1485, Address: 0x1f1b98, Func Offset: 0x828
	// Line 1486, Address: 0x1f1b9c, Func Offset: 0x82c
	// Line 1487, Address: 0x1f1ba4, Func Offset: 0x834
	// Line 1490, Address: 0x1f1ba8, Func Offset: 0x838
	// Line 1493, Address: 0x1f1bb0, Func Offset: 0x840
	// Line 1496, Address: 0x1f1bc0, Func Offset: 0x850
	// Line 1500, Address: 0x1f1bc8, Func Offset: 0x858
	// Line 1501, Address: 0x1f1be8, Func Offset: 0x878
	// Line 1503, Address: 0x1f1bf0, Func Offset: 0x880
	// Line 1504, Address: 0x1f1bf8, Func Offset: 0x888
	// Line 1509, Address: 0x1f1c08, Func Offset: 0x898
	// Line 1512, Address: 0x1f1c10, Func Offset: 0x8a0
	// Line 1516, Address: 0x1f1c2c, Func Offset: 0x8bc
	// Line 1517, Address: 0x1f1c30, Func Offset: 0x8c0
	// Line 1520, Address: 0x1f1c38, Func Offset: 0x8c8
	// Line 1523, Address: 0x1f1c48, Func Offset: 0x8d8
	// Line 1527, Address: 0x1f1c4c, Func Offset: 0x8dc
	// Line 1531, Address: 0x1f1c54, Func Offset: 0x8e4
	// Line 1536, Address: 0x1f1c74, Func Offset: 0x904
	// Line 1539, Address: 0x1f1c7c, Func Offset: 0x90c
	// Line 1542, Address: 0x1f1ca0, Func Offset: 0x930
	// Line 1546, Address: 0x1f1ca8, Func Offset: 0x938
	// Line 1549, Address: 0x1f1cc8, Func Offset: 0x958
	// Line 1553, Address: 0x1f1ce0, Func Offset: 0x970
	// Line 1552, Address: 0x1f1ce4, Func Offset: 0x974
	// Line 1553, Address: 0x1f1ce8, Func Offset: 0x978
	// Line 1556, Address: 0x1f1cec, Func Offset: 0x97c
	// Line 1557, Address: 0x1f1cf0, Func Offset: 0x980
	// Line 1559, Address: 0x1f1d00, Func Offset: 0x990
	// Line 1560, Address: 0x1f1d08, Func Offset: 0x998
	// Line 1561, Address: 0x1f1d14, Func Offset: 0x9a4
	// Line 1568, Address: 0x1f1d24, Func Offset: 0x9b4
	// Line 1569, Address: 0x1f1d28, Func Offset: 0x9b8
	// Line 1572, Address: 0x1f1d34, Func Offset: 0x9c4
	// Line 1575, Address: 0x1f1d50, Func Offset: 0x9e0
	// Func End, Address: 0x1f1d80, Func Offset: 0xa10
	scePrintf("bhEne19_Br01 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f1d80
static void bhEne19_Br02(BH_PWORK* ewP)
{
	int lop;
	int act;
	int rte;
	int* wt1P;
	TY_BR_MODE2* br2P;
	TY_BR_MODE1* br1P;
	TY_BR_MODE0* br0P;
	int sts;
	NJS_POINT3 pos;
	unsigned char rut;
	int* pstP;
	int* stsP;
	FW_WORK* fwP;
	// Line 1585, Address: 0x1f1d80, Func Offset: 0
	// Line 1586, Address: 0x1f1da8, Func Offset: 0x28
	// Line 1600, Address: 0x1f1db0, Func Offset: 0x30
	// Line 1588, Address: 0x1f1db4, Func Offset: 0x34
	// Line 1600, Address: 0x1f1db8, Func Offset: 0x38
	// Line 1609, Address: 0x1f1dc4, Func Offset: 0x44
	// Line 1610, Address: 0x1f1de8, Func Offset: 0x68
	// Line 1612, Address: 0x1f1df0, Func Offset: 0x70
	// Line 1617, Address: 0x1f1e00, Func Offset: 0x80
	// Line 1621, Address: 0x1f1e20, Func Offset: 0xa0
	// Line 1623, Address: 0x1f1e2c, Func Offset: 0xac
	// Line 1624, Address: 0x1f1e50, Func Offset: 0xd0
	// Line 1625, Address: 0x1f1e58, Func Offset: 0xd8
	// Line 1626, Address: 0x1f1e60, Func Offset: 0xe0
	// Line 1628, Address: 0x1f1e74, Func Offset: 0xf4
	// Line 1629, Address: 0x1f1e94, Func Offset: 0x114
	// Line 1630, Address: 0x1f1e9c, Func Offset: 0x11c
	// Line 1631, Address: 0x1f1ea4, Func Offset: 0x124
	// Line 1638, Address: 0x1f1eb4, Func Offset: 0x134
	// Line 1642, Address: 0x1f1ec0, Func Offset: 0x140
	// Line 1647, Address: 0x1f1ec8, Func Offset: 0x148
	// Line 1643, Address: 0x1f1ecc, Func Offset: 0x14c
	// Line 1644, Address: 0x1f1ed0, Func Offset: 0x150
	// Line 1645, Address: 0x1f1eec, Func Offset: 0x16c
	// Line 1646, Address: 0x1f1ef0, Func Offset: 0x170
	// Line 1648, Address: 0x1f1ef4, Func Offset: 0x174
	// Line 1649, Address: 0x1f1ef8, Func Offset: 0x178
	// Line 1653, Address: 0x1f1f18, Func Offset: 0x198
	// Line 1656, Address: 0x1f1f40, Func Offset: 0x1c0
	// Line 1659, Address: 0x1f1f68, Func Offset: 0x1e8
	// Line 1661, Address: 0x1f1f74, Func Offset: 0x1f4
	// Line 1662, Address: 0x1f1f7c, Func Offset: 0x1fc
	// Line 1663, Address: 0x1f1f84, Func Offset: 0x204
	// Line 1664, Address: 0x1f1f8c, Func Offset: 0x20c
	// Line 1665, Address: 0x1f1f9c, Func Offset: 0x21c
	// Line 1667, Address: 0x1f1fa0, Func Offset: 0x220
	// Line 1668, Address: 0x1f1fa4, Func Offset: 0x224
	// Line 1669, Address: 0x1f1fac, Func Offset: 0x22c
	// Line 1670, Address: 0x1f1fdc, Func Offset: 0x25c
	// Line 1672, Address: 0x1f1fe0, Func Offset: 0x260
	// Line 1673, Address: 0x1f1fe4, Func Offset: 0x264
	// Line 1674, Address: 0x1f1fec, Func Offset: 0x26c
	// Line 1678, Address: 0x1f1ff4, Func Offset: 0x274
	// Line 1679, Address: 0x1f1ffc, Func Offset: 0x27c
	// Line 1680, Address: 0x1f2004, Func Offset: 0x284
	// Line 1681, Address: 0x1f2014, Func Offset: 0x294
	// Line 1683, Address: 0x1f2018, Func Offset: 0x298
	// Line 1684, Address: 0x1f201c, Func Offset: 0x29c
	// Line 1685, Address: 0x1f2024, Func Offset: 0x2a4
	// Line 1689, Address: 0x1f2028, Func Offset: 0x2a8
	// Line 1690, Address: 0x1f2030, Func Offset: 0x2b0
	// Line 1691, Address: 0x1f2038, Func Offset: 0x2b8
	// Line 1693, Address: 0x1f2040, Func Offset: 0x2c0
	// Line 1694, Address: 0x1f2044, Func Offset: 0x2c4
	// Line 1695, Address: 0x1f204c, Func Offset: 0x2cc
	// Line 1699, Address: 0x1f2050, Func Offset: 0x2d0
	// Line 1702, Address: 0x1f2058, Func Offset: 0x2d8
	// Line 1705, Address: 0x1f2080, Func Offset: 0x300
	// Line 1706, Address: 0x1f2098, Func Offset: 0x318
	// Line 1707, Address: 0x1f20a0, Func Offset: 0x320
	// Line 1709, Address: 0x1f20b0, Func Offset: 0x330
	// Line 1710, Address: 0x1f20b8, Func Offset: 0x338
	// Line 1713, Address: 0x1f20c8, Func Offset: 0x348
	// Line 1714, Address: 0x1f20cc, Func Offset: 0x34c
	// Line 1715, Address: 0x1f20d4, Func Offset: 0x354
	// Line 1718, Address: 0x1f20d8, Func Offset: 0x358
	// Line 1721, Address: 0x1f20e0, Func Offset: 0x360
	// Line 1724, Address: 0x1f20f0, Func Offset: 0x370
	// Line 1727, Address: 0x1f20f8, Func Offset: 0x378
	// Line 1728, Address: 0x1f2118, Func Offset: 0x398
	// Line 1730, Address: 0x1f2120, Func Offset: 0x3a0
	// Line 1731, Address: 0x1f2128, Func Offset: 0x3a8
	// Line 1736, Address: 0x1f2138, Func Offset: 0x3b8
	// Line 1740, Address: 0x1f2140, Func Offset: 0x3c0
	// Line 1743, Address: 0x1f215c, Func Offset: 0x3dc
	// Line 1744, Address: 0x1f2164, Func Offset: 0x3e4
	// Line 1746, Address: 0x1f2174, Func Offset: 0x3f4
	// Line 1747, Address: 0x1f217c, Func Offset: 0x3fc
	// Line 1749, Address: 0x1f218c, Func Offset: 0x40c
	// Line 1751, Address: 0x1f2190, Func Offset: 0x410
	// Line 1753, Address: 0x1f2198, Func Offset: 0x418
	// Line 1756, Address: 0x1f21a0, Func Offset: 0x420
	// Line 1759, Address: 0x1f21f0, Func Offset: 0x470
	// Line 1760, Address: 0x1f21f4, Func Offset: 0x474
	// Line 1763, Address: 0x1f220c, Func Offset: 0x48c
	// Line 1768, Address: 0x1f221c, Func Offset: 0x49c
	// Line 1772, Address: 0x1f2224, Func Offset: 0x4a4
	// Line 1777, Address: 0x1f2240, Func Offset: 0x4c0
	// Line 1780, Address: 0x1f2248, Func Offset: 0x4c8
	// Line 1781, Address: 0x1f2258, Func Offset: 0x4d8
	// Line 1783, Address: 0x1f2280, Func Offset: 0x500
	// Line 1787, Address: 0x1f2290, Func Offset: 0x510
	// Line 1791, Address: 0x1f2294, Func Offset: 0x514
	// Line 1795, Address: 0x1f229c, Func Offset: 0x51c
	// Line 1800, Address: 0x1f22c4, Func Offset: 0x544
	// Line 1803, Address: 0x1f22cc, Func Offset: 0x54c
	// Line 1805, Address: 0x1f22e4, Func Offset: 0x564
	// Line 1811, Address: 0x1f22f4, Func Offset: 0x574
	// Line 1815, Address: 0x1f22fc, Func Offset: 0x57c
	// Line 1818, Address: 0x1f2324, Func Offset: 0x5a4
	// Line 1819, Address: 0x1f2334, Func Offset: 0x5b4
	// Line 1820, Address: 0x1f2344, Func Offset: 0x5c4
	// Line 1821, Address: 0x1f2348, Func Offset: 0x5c8
	// Line 1824, Address: 0x1f2350, Func Offset: 0x5d0
	// Line 1825, Address: 0x1f2358, Func Offset: 0x5d8
	// Line 1826, Address: 0x1f2360, Func Offset: 0x5e0
	// Line 1825, Address: 0x1f2364, Func Offset: 0x5e4
	// Line 1829, Address: 0x1f236c, Func Offset: 0x5ec
	// Line 1832, Address: 0x1f2374, Func Offset: 0x5f4
	// Line 1834, Address: 0x1f2384, Func Offset: 0x604
	// Line 1837, Address: 0x1f238c, Func Offset: 0x60c
	// Line 1839, Address: 0x1f2398, Func Offset: 0x618
	// Line 1842, Address: 0x1f23a0, Func Offset: 0x620
	// Line 1843, Address: 0x1f23ac, Func Offset: 0x62c
	// Line 1844, Address: 0x1f23b0, Func Offset: 0x630
	// Line 1851, Address: 0x1f23b4, Func Offset: 0x634
	// Line 1854, Address: 0x1f23bc, Func Offset: 0x63c
	// Line 1857, Address: 0x1f23d4, Func Offset: 0x654
	// Line 1861, Address: 0x1f23f0, Func Offset: 0x670
	// Line 1860, Address: 0x1f23f4, Func Offset: 0x674
	// Line 1863, Address: 0x1f23f8, Func Offset: 0x678
	// Line 1866, Address: 0x1f2400, Func Offset: 0x680
	// Line 1867, Address: 0x1f2410, Func Offset: 0x690
	// Line 1868, Address: 0x1f2414, Func Offset: 0x694
	// Line 1875, Address: 0x1f2418, Func Offset: 0x698
	// Line 1879, Address: 0x1f2420, Func Offset: 0x6a0
	// Line 1882, Address: 0x1f2440, Func Offset: 0x6c0
	// Line 1886, Address: 0x1f2460, Func Offset: 0x6e0
	// Line 1885, Address: 0x1f2464, Func Offset: 0x6e4
	// Line 1886, Address: 0x1f2468, Func Offset: 0x6e8
	// Line 1888, Address: 0x1f2470, Func Offset: 0x6f0
	// Line 1895, Address: 0x1f2478, Func Offset: 0x6f8
	// Line 1898, Address: 0x1f2480, Func Offset: 0x700
	// Line 1901, Address: 0x1f2494, Func Offset: 0x714
	// Line 1902, Address: 0x1f2498, Func Offset: 0x718
	// Line 1909, Address: 0x1f249c, Func Offset: 0x71c
	// Line 1910, Address: 0x1f24a0, Func Offset: 0x720
	// Line 1913, Address: 0x1f24ac, Func Offset: 0x72c
	// Line 1916, Address: 0x1f24c0, Func Offset: 0x740
	// Func End, Address: 0x1f24ec, Func Offset: 0x76c
	scePrintf("bhEne19_Br02 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_Mv00(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv01(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv02(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x4;
    }
}

// 100% matching!
static void bhEne19_Mv03(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne19_Mv04a(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP |= 0x4;
    }
}

// 100% matching!
static void bhEne19_Mv04b(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv05(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *flgP;

	stsP = &fwP->status;
	flgP = &fwP->act_flg;

    if (count == 0)
    {
        *stsP |= 0x4;
        *flgP |= 0x8;
    }
    
    if (fwP->tgt_ang < 5461)
    {
        fwP->trn_spd = 182;
    }
	else 
	{
		fwP->trn_spd = 327;
	}
}

// 100% matching!
static void bhEne19_Mv06(BH_PWORK* ewP, FW_WORK* fwP, int count) // parameters not present on DWARF
{

}

// 
// Start address: 0x1f2610
static void bhEne19_Mv07(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	int ang[3];
	float pos[3];
	int* stsP;
	// Line 2045, Address: 0x1f2610, Func Offset: 0
	// Line 2048, Address: 0x1f2624, Func Offset: 0x14
	// Line 2046, Address: 0x1f262c, Func Offset: 0x1c
	// Line 2048, Address: 0x1f2634, Func Offset: 0x24
	// Line 2050, Address: 0x1f2638, Func Offset: 0x28
	// Line 2051, Address: 0x1f2640, Func Offset: 0x30
	// Line 2054, Address: 0x1f2650, Func Offset: 0x40
	// Line 2056, Address: 0x1f266c, Func Offset: 0x5c
	// Line 2059, Address: 0x1f2684, Func Offset: 0x74
	// Line 2060, Address: 0x1f269c, Func Offset: 0x8c
	// Line 2061, Address: 0x1f26b4, Func Offset: 0xa4
	// Line 2070, Address: 0x1f26c0, Func Offset: 0xb0
	// Line 2071, Address: 0x1f26f0, Func Offset: 0xe0
	// Line 2072, Address: 0x1f2704, Func Offset: 0xf4
	// Line 2076, Address: 0x1f2708, Func Offset: 0xf8
	// Line 2072, Address: 0x1f2714, Func Offset: 0x104
	// Line 2073, Address: 0x1f2718, Func Offset: 0x108
	// Line 2074, Address: 0x1f2728, Func Offset: 0x118
	// Line 2076, Address: 0x1f272c, Func Offset: 0x11c
	// Line 2078, Address: 0x1f2734, Func Offset: 0x124
	// Line 2082, Address: 0x1f2748, Func Offset: 0x138
	// Line 2078, Address: 0x1f274c, Func Offset: 0x13c
	// Line 2079, Address: 0x1f275c, Func Offset: 0x14c
	// Line 2082, Address: 0x1f2774, Func Offset: 0x164
	// Line 2084, Address: 0x1f2790, Func Offset: 0x180
	// Func End, Address: 0x1f27a8, Func Offset: 0x198
	scePrintf("bhEne19_Mv07 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f27b0
static void bhEne19_Mv08(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
	NJS_MATRIX* mtxP;
	NJS_POINT3 pos;
	NJS_POINT3 dir;
	int* stsP;
	// Line 2096, Address: 0x1f27b0, Func Offset: 0
	// Line 2099, Address: 0x1f27c8, Func Offset: 0x18
	// Line 2097, Address: 0x1f27cc, Func Offset: 0x1c
	// Line 2099, Address: 0x1f27d0, Func Offset: 0x20
	// Line 2104, Address: 0x1f27dc, Func Offset: 0x2c
	// Line 2106, Address: 0x1f2804, Func Offset: 0x54
	// Line 2107, Address: 0x1f2820, Func Offset: 0x70
	// Line 2110, Address: 0x1f2828, Func Offset: 0x78
	// Line 2113, Address: 0x1f285c, Func Offset: 0xac
	// Line 2115, Address: 0x1f2864, Func Offset: 0xb4
	// Line 2113, Address: 0x1f286c, Func Offset: 0xbc
	// Line 2115, Address: 0x1f2870, Func Offset: 0xc0
	// Line 2113, Address: 0x1f2874, Func Offset: 0xc4
	// Line 2115, Address: 0x1f2878, Func Offset: 0xc8
	// Line 2113, Address: 0x1f2884, Func Offset: 0xd4
	// Line 2115, Address: 0x1f2888, Func Offset: 0xd8
	// Line 2116, Address: 0x1f2894, Func Offset: 0xe4
	// Line 2117, Address: 0x1f28a4, Func Offset: 0xf4
	// Line 2119, Address: 0x1f28b0, Func Offset: 0x100
	// Line 2120, Address: 0x1f28b4, Func Offset: 0x104
	// Line 2117, Address: 0x1f28b8, Func Offset: 0x108
	// Line 2122, Address: 0x1f28bc, Func Offset: 0x10c
	// Line 2117, Address: 0x1f28c8, Func Offset: 0x118
	// Line 2120, Address: 0x1f28d0, Func Offset: 0x120
	// Line 2117, Address: 0x1f28d8, Func Offset: 0x128
	// Line 2119, Address: 0x1f28ec, Func Offset: 0x13c
	// Line 2120, Address: 0x1f290c, Func Offset: 0x15c
	// Line 2122, Address: 0x1f292c, Func Offset: 0x17c
	// Line 2124, Address: 0x1f2934, Func Offset: 0x184
	// Line 2125, Address: 0x1f2938, Func Offset: 0x188
	// Line 2126, Address: 0x1f2940, Func Offset: 0x190
	// Line 2132, Address: 0x1f2948, Func Offset: 0x198
	// Func End, Address: 0x1f2960, Func Offset: 0x1b0
	scePrintf("bhEne19_Mv08 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f2960
static void bhEne19_Mv09(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
	NJS_MATRIX* mtxP;
	NJS_POINT3 pos;
	NJS_POINT3 dir;
	int* stsP;
	// Line 2144, Address: 0x1f2960, Func Offset: 0
	// Line 2148, Address: 0x1f2978, Func Offset: 0x18
	// Line 2145, Address: 0x1f297c, Func Offset: 0x1c
	// Line 2148, Address: 0x1f2980, Func Offset: 0x20
	// Line 2153, Address: 0x1f298c, Func Offset: 0x2c
	// Line 2155, Address: 0x1f29b0, Func Offset: 0x50
	// Line 2156, Address: 0x1f29cc, Func Offset: 0x6c
	// Line 2159, Address: 0x1f29d4, Func Offset: 0x74
	// Line 2162, Address: 0x1f2a08, Func Offset: 0xa8
	// Line 2164, Address: 0x1f2a10, Func Offset: 0xb0
	// Line 2162, Address: 0x1f2a18, Func Offset: 0xb8
	// Line 2164, Address: 0x1f2a1c, Func Offset: 0xbc
	// Line 2162, Address: 0x1f2a20, Func Offset: 0xc0
	// Line 2164, Address: 0x1f2a24, Func Offset: 0xc4
	// Line 2162, Address: 0x1f2a30, Func Offset: 0xd0
	// Line 2164, Address: 0x1f2a34, Func Offset: 0xd4
	// Line 2165, Address: 0x1f2a40, Func Offset: 0xe0
	// Line 2166, Address: 0x1f2a50, Func Offset: 0xf0
	// Line 2168, Address: 0x1f2a5c, Func Offset: 0xfc
	// Line 2169, Address: 0x1f2a60, Func Offset: 0x100
	// Line 2166, Address: 0x1f2a64, Func Offset: 0x104
	// Line 2171, Address: 0x1f2a68, Func Offset: 0x108
	// Line 2166, Address: 0x1f2a74, Func Offset: 0x114
	// Line 2169, Address: 0x1f2a7c, Func Offset: 0x11c
	// Line 2166, Address: 0x1f2a84, Func Offset: 0x124
	// Line 2168, Address: 0x1f2a98, Func Offset: 0x138
	// Line 2169, Address: 0x1f2ab8, Func Offset: 0x158
	// Line 2171, Address: 0x1f2ad8, Func Offset: 0x178
	// Line 2173, Address: 0x1f2ae0, Func Offset: 0x180
	// Line 2174, Address: 0x1f2ae4, Func Offset: 0x184
	// Line 2175, Address: 0x1f2aec, Func Offset: 0x18c
	// Line 2181, Address: 0x1f2af4, Func Offset: 0x194
	// Func End, Address: 0x1f2b0c, Func Offset: 0x1ac
	scePrintf("bhEne19_Mv09 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f2b10
static void bhEne19_Mv10(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	NJS_MATRIX* mtxP;
	//NJS_POINT3 dir;
	NJS_POINT3 dir;
	NJS_POINT3 pos;
	float mtx2P[16];
	float mtx0P[16];
	int* stsP;
	int* flgP;
	NJS_POINT3 off;
	NJS_POINT3 vct;
	// Line 2193, Address: 0x1f2b10, Func Offset: 0
	// Line 2194, Address: 0x1f2b30, Func Offset: 0x20
	// Line 2195, Address: 0x1f2b34, Func Offset: 0x24
	// Line 2197, Address: 0x1f2b38, Func Offset: 0x28
	// Line 2199, Address: 0x1f2b40, Func Offset: 0x30
	// Line 2201, Address: 0x1f2b48, Func Offset: 0x38
	// Line 2199, Address: 0x1f2b4c, Func Offset: 0x3c
	// Line 2200, Address: 0x1f2b54, Func Offset: 0x44
	// Line 2201, Address: 0x1f2b60, Func Offset: 0x50
	// Line 2208, Address: 0x1f2b64, Func Offset: 0x54
	// Line 2212, Address: 0x1f2b68, Func Offset: 0x58
	// Line 2208, Address: 0x1f2b70, Func Offset: 0x60
	// Line 2212, Address: 0x1f2b78, Func Offset: 0x68
	// Line 2213, Address: 0x1f2b80, Func Offset: 0x70
	// Line 2214, Address: 0x1f2ba8, Func Offset: 0x98
	// Line 2218, Address: 0x1f2bcc, Func Offset: 0xbc
	// Line 2226, Address: 0x1f2bdc, Func Offset: 0xcc
	// Line 2227, Address: 0x1f2bf0, Func Offset: 0xe0
	// Line 2228, Address: 0x1f2c04, Func Offset: 0xf4
	// Line 2229, Address: 0x1f2c20, Func Offset: 0x110
	// Line 2232, Address: 0x1f2c3c, Func Offset: 0x12c
	// Line 2233, Address: 0x1f2c58, Func Offset: 0x148
	// Line 2236, Address: 0x1f2c74, Func Offset: 0x164
	// Line 2238, Address: 0x1f2c88, Func Offset: 0x178
	// Line 2243, Address: 0x1f2c90, Func Offset: 0x180
	// Line 2246, Address: 0x1f2ca0, Func Offset: 0x190
	// Line 2248, Address: 0x1f2cc0, Func Offset: 0x1b0
	// Line 2249, Address: 0x1f2cdc, Func Offset: 0x1cc
	// Line 2251, Address: 0x1f2ce4, Func Offset: 0x1d4
	// Line 2255, Address: 0x1f2cec, Func Offset: 0x1dc
	// Line 2257, Address: 0x1f2cf4, Func Offset: 0x1e4
	// Line 2255, Address: 0x1f2cf8, Func Offset: 0x1e8
	// Line 2257, Address: 0x1f2d00, Func Offset: 0x1f0
	// Line 2255, Address: 0x1f2d0c, Func Offset: 0x1fc
	// Line 2258, Address: 0x1f2d10, Func Offset: 0x200
	// Line 2257, Address: 0x1f2d14, Func Offset: 0x204
	// Line 2258, Address: 0x1f2d1c, Func Offset: 0x20c
	// Line 2259, Address: 0x1f2d24, Func Offset: 0x214
	// Line 2266, Address: 0x1f2d38, Func Offset: 0x228
	// Func End, Address: 0x1f2d58, Func Offset: 0x248
	scePrintf("bhEne19_Mv10 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_Mv11(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(fwP->status & 0x8)) ? TY_ARM_RIGHT : TY_ARM_LEFT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 100% matching!
static void bhEne19_Mv12(BH_PWORK* ewP, FW_WORK* fwP, int count) // third parameter not present on DWARF
{
    if (((fwP->status & 0x40)) && ((bhEne19_AttackHitCheck(ewP, (!(fwP->status & 0x8)) ? TY_ARM_LEFT : TY_ARM_RIGHT, 4.0f, &fwP->trw_dir) != 0) && (bhEne19_PlySetDamage(plp, fwP, 1) != 0)))
    {
        fwP->trw_spd = 2.0f;
    }
}

// 
// Start address: 0x1f2e60
static void bhEne19_Mv13(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	NJS_POINT3* posP;
	NJS_MATRIX* mtxP;
	//NJS_POINT3 dir;
	int ang;
	float spd;
	int dmg;
	//NJS_POINT3 dir;
	ATR_WORK* htP;
	TY_ARM_NO arm_no;
	TY_OBJ_MODE obj_no;
	NJS_POINT3 dir;
	NJS_POINT3 pos;
	float mtx2P[16];
	float mtx0P[16];
	int* flgP;
	int* stsP;
	NJS_POINT3 off;
	NJS_POINT3 vct;
	// Line 2330, Address: 0x1f2e60, Func Offset: 0
	// Line 2331, Address: 0x1f2e80, Func Offset: 0x20
	// Line 2332, Address: 0x1f2e84, Func Offset: 0x24
	// Line 2330, Address: 0x1f2e88, Func Offset: 0x28
	// Line 2334, Address: 0x1f2e8c, Func Offset: 0x2c
	// Line 2335, Address: 0x1f2e94, Func Offset: 0x34
	// Line 2336, Address: 0x1f2e98, Func Offset: 0x38
	// Line 2335, Address: 0x1f2e9c, Func Offset: 0x3c
	// Line 2336, Address: 0x1f2ea4, Func Offset: 0x44
	// Line 2343, Address: 0x1f2ea8, Func Offset: 0x48
	// Line 2344, Address: 0x1f2ec8, Func Offset: 0x68
	// Line 2345, Address: 0x1f2ed0, Func Offset: 0x70
	// Line 2347, Address: 0x1f2edc, Func Offset: 0x7c
	// Line 2348, Address: 0x1f2ee4, Func Offset: 0x84
	// Line 2349, Address: 0x1f2ee8, Func Offset: 0x88
	// Line 2348, Address: 0x1f2eec, Func Offset: 0x8c
	// Line 2349, Address: 0x1f2ef0, Func Offset: 0x90
	// Line 2353, Address: 0x1f2ef8, Func Offset: 0x98
	// Line 2354, Address: 0x1f2f08, Func Offset: 0xa8
	// Line 2355, Address: 0x1f2f30, Func Offset: 0xd0
	// Line 2359, Address: 0x1f2f54, Func Offset: 0xf4
	// Line 2367, Address: 0x1f2f70, Func Offset: 0x110
	// Line 2368, Address: 0x1f2f84, Func Offset: 0x124
	// Line 2369, Address: 0x1f2f98, Func Offset: 0x138
	// Line 2372, Address: 0x1f2fb4, Func Offset: 0x154
	// Line 2373, Address: 0x1f2fd0, Func Offset: 0x170
	// Line 2378, Address: 0x1f2fec, Func Offset: 0x18c
	// Line 2382, Address: 0x1f2ffc, Func Offset: 0x19c
	// Line 2384, Address: 0x1f3008, Func Offset: 0x1a8
	// Line 2385, Address: 0x1f300c, Func Offset: 0x1ac
	// Line 2386, Address: 0x1f3014, Func Offset: 0x1b4
	// Line 2387, Address: 0x1f3018, Func Offset: 0x1b8
	// Line 2390, Address: 0x1f301c, Func Offset: 0x1bc
	// Line 2397, Address: 0x1f3038, Func Offset: 0x1d8
	// Line 2399, Address: 0x1f303c, Func Offset: 0x1dc
	// Line 2401, Address: 0x1f3058, Func Offset: 0x1f8
	// Line 2399, Address: 0x1f305c, Func Offset: 0x1fc
	// Line 2400, Address: 0x1f3068, Func Offset: 0x208
	// Line 2401, Address: 0x1f306c, Func Offset: 0x20c
	// Line 2405, Address: 0x1f3088, Func Offset: 0x228
	// Line 2401, Address: 0x1f3090, Func Offset: 0x230
	// Line 2405, Address: 0x1f309c, Func Offset: 0x23c
	// Line 2406, Address: 0x1f30a8, Func Offset: 0x248
	// Line 2408, Address: 0x1f30e0, Func Offset: 0x280
	// Line 2409, Address: 0x1f30e8, Func Offset: 0x288
	// Line 2411, Address: 0x1f30f0, Func Offset: 0x290
	// Line 2410, Address: 0x1f30f4, Func Offset: 0x294
	// Line 2411, Address: 0x1f30f8, Func Offset: 0x298
	// Line 2414, Address: 0x1f30fc, Func Offset: 0x29c
	// Line 2415, Address: 0x1f3114, Func Offset: 0x2b4
	// Line 2418, Address: 0x1f3134, Func Offset: 0x2d4
	// Line 2417, Address: 0x1f3138, Func Offset: 0x2d8
	// Line 2418, Address: 0x1f3140, Func Offset: 0x2e0
	// Line 2417, Address: 0x1f3150, Func Offset: 0x2f0
	// Line 2421, Address: 0x1f3154, Func Offset: 0x2f4
	// Line 2420, Address: 0x1f315c, Func Offset: 0x2fc
	// Line 2418, Address: 0x1f3160, Func Offset: 0x300
	// Line 2417, Address: 0x1f3164, Func Offset: 0x304
	// Line 2420, Address: 0x1f3168, Func Offset: 0x308
	// Line 2424, Address: 0x1f3174, Func Offset: 0x314
	// Line 2418, Address: 0x1f3178, Func Offset: 0x318
	// Line 2417, Address: 0x1f317c, Func Offset: 0x31c
	// Line 2420, Address: 0x1f3180, Func Offset: 0x320
	// Line 2421, Address: 0x1f318c, Func Offset: 0x32c
	// Line 2422, Address: 0x1f3198, Func Offset: 0x338
	// Line 2423, Address: 0x1f31a4, Func Offset: 0x344
	// Line 2424, Address: 0x1f31ac, Func Offset: 0x34c
	// Line 2426, Address: 0x1f31b4, Func Offset: 0x354
	// Line 2427, Address: 0x1f31b8, Func Offset: 0x358
	// Line 2428, Address: 0x1f31c0, Func Offset: 0x360
	// Line 2431, Address: 0x1f31c8, Func Offset: 0x368
	// Line 2436, Address: 0x1f31cc, Func Offset: 0x36c
	// Func End, Address: 0x1f31f0, Func Offset: 0x390
	scePrintf("bhEne19_Mv13 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f31f0
static void bhEne19_Mv14(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	NJS_POINT3* posP;
	NJS_MATRIX* mtxP;
	//NJS_POINT3 dir;
	int ang;
	float spd;
	int dmg;
	//NJS_POINT3 dir;
	ATR_WORK* htP;
	TY_ARM_NO arm_no;
	TY_OBJ_MODE obj_no;
	NJS_POINT3 dir;
	NJS_POINT3 pos;
	float mtx2P[16];
	float mtx0P[16];
	int* flgP;
	int* stsP;
	NJS_POINT3 off;
	NJS_POINT3 vct;
	// Line 2446, Address: 0x1f31f0, Func Offset: 0
	// Line 2447, Address: 0x1f3210, Func Offset: 0x20
	// Line 2448, Address: 0x1f3214, Func Offset: 0x24
	// Line 2446, Address: 0x1f3218, Func Offset: 0x28
	// Line 2450, Address: 0x1f321c, Func Offset: 0x2c
	// Line 2451, Address: 0x1f3224, Func Offset: 0x34
	// Line 2452, Address: 0x1f3228, Func Offset: 0x38
	// Line 2451, Address: 0x1f322c, Func Offset: 0x3c
	// Line 2452, Address: 0x1f3234, Func Offset: 0x44
	// Line 2459, Address: 0x1f3238, Func Offset: 0x48
	// Line 2460, Address: 0x1f3258, Func Offset: 0x68
	// Line 2461, Address: 0x1f3260, Func Offset: 0x70
	// Line 2463, Address: 0x1f326c, Func Offset: 0x7c
	// Line 2464, Address: 0x1f3274, Func Offset: 0x84
	// Line 2465, Address: 0x1f3278, Func Offset: 0x88
	// Line 2464, Address: 0x1f327c, Func Offset: 0x8c
	// Line 2465, Address: 0x1f3280, Func Offset: 0x90
	// Line 2469, Address: 0x1f3288, Func Offset: 0x98
	// Line 2470, Address: 0x1f3298, Func Offset: 0xa8
	// Line 2471, Address: 0x1f32c0, Func Offset: 0xd0
	// Line 2475, Address: 0x1f32e4, Func Offset: 0xf4
	// Line 2483, Address: 0x1f3300, Func Offset: 0x110
	// Line 2484, Address: 0x1f3314, Func Offset: 0x124
	// Line 2486, Address: 0x1f3328, Func Offset: 0x138
	// Line 2487, Address: 0x1f334c, Func Offset: 0x15c
	// Line 2490, Address: 0x1f3368, Func Offset: 0x178
	// Line 2491, Address: 0x1f3384, Func Offset: 0x194
	// Line 2498, Address: 0x1f33a0, Func Offset: 0x1b0
	// Line 2502, Address: 0x1f33b0, Func Offset: 0x1c0
	// Line 2503, Address: 0x1f33bc, Func Offset: 0x1cc
	// Line 2505, Address: 0x1f33c0, Func Offset: 0x1d0
	// Line 2507, Address: 0x1f33c8, Func Offset: 0x1d8
	// Line 2506, Address: 0x1f33cc, Func Offset: 0x1dc
	// Line 2510, Address: 0x1f33d0, Func Offset: 0x1e0
	// Line 2518, Address: 0x1f33ec, Func Offset: 0x1fc
	// Line 2520, Address: 0x1f33f0, Func Offset: 0x200
	// Line 2522, Address: 0x1f340c, Func Offset: 0x21c
	// Line 2520, Address: 0x1f3410, Func Offset: 0x220
	// Line 2521, Address: 0x1f341c, Func Offset: 0x22c
	// Line 2522, Address: 0x1f3420, Func Offset: 0x230
	// Line 2526, Address: 0x1f343c, Func Offset: 0x24c
	// Line 2522, Address: 0x1f3444, Func Offset: 0x254
	// Line 2526, Address: 0x1f3450, Func Offset: 0x260
	// Line 2527, Address: 0x1f345c, Func Offset: 0x26c
	// Line 2529, Address: 0x1f3494, Func Offset: 0x2a4
	// Line 2530, Address: 0x1f349c, Func Offset: 0x2ac
	// Line 2532, Address: 0x1f34a4, Func Offset: 0x2b4
	// Line 2531, Address: 0x1f34a8, Func Offset: 0x2b8
	// Line 2532, Address: 0x1f34ac, Func Offset: 0x2bc
	// Line 2535, Address: 0x1f34b0, Func Offset: 0x2c0
	// Line 2536, Address: 0x1f34c8, Func Offset: 0x2d8
	// Line 2539, Address: 0x1f34e8, Func Offset: 0x2f8
	// Line 2538, Address: 0x1f34ec, Func Offset: 0x2fc
	// Line 2539, Address: 0x1f34f4, Func Offset: 0x304
	// Line 2538, Address: 0x1f3504, Func Offset: 0x314
	// Line 2542, Address: 0x1f3508, Func Offset: 0x318
	// Line 2541, Address: 0x1f3510, Func Offset: 0x320
	// Line 2539, Address: 0x1f3514, Func Offset: 0x324
	// Line 2538, Address: 0x1f3518, Func Offset: 0x328
	// Line 2541, Address: 0x1f351c, Func Offset: 0x32c
	// Line 2545, Address: 0x1f3528, Func Offset: 0x338
	// Line 2539, Address: 0x1f352c, Func Offset: 0x33c
	// Line 2538, Address: 0x1f3530, Func Offset: 0x340
	// Line 2541, Address: 0x1f3534, Func Offset: 0x344
	// Line 2542, Address: 0x1f3540, Func Offset: 0x350
	// Line 2543, Address: 0x1f354c, Func Offset: 0x35c
	// Line 2544, Address: 0x1f3558, Func Offset: 0x368
	// Line 2545, Address: 0x1f3560, Func Offset: 0x370
	// Line 2547, Address: 0x1f3568, Func Offset: 0x378
	// Line 2548, Address: 0x1f356c, Func Offset: 0x37c
	// Line 2549, Address: 0x1f3574, Func Offset: 0x384
	// Line 2551, Address: 0x1f357c, Func Offset: 0x38c
	// Line 2556, Address: 0x1f3580, Func Offset: 0x390
	// Func End, Address: 0x1f35a4, Func Offset: 0x3b4
	scePrintf("bhEne19_Mv14 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_Mv15(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv16(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        if ((*bstP & 0x10000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv17(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP, *bstP;

	stsP = &fwP->status;
	bstP = &fwP->b_status;

	if (count == 0)
    {
        *stsP |= 0x100;

        if ((*bstP & 0x40000))
        {
            *stsP |=  0x8;
        }
        else
        {
            *stsP &= ~0x8;
        }
    }
}

// 100% matching!
static void bhEne19_Mv18(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg &= ~0x60;

        fwP->status &= ~0x100;
        fwP->status |=  0x200;
    }
}

// 100% matching!
static void bhEne19_Mv19(BH_PWORK* ewP, FW_WORK* fwP, int count) // first parameter not present on DWARF
{
	int* stsP;

	stsP = &fwP->status;

	if (count == 0)
    {
        *stsP &= ~0x100;
    }
}

// 100% matching!
static void bhEne19_Mv20(BH_PWORK* ewP, FW_WORK* fwP, int count)
{
	if (count == 0)
    {
        ewP->flg |= 0x60;
    }

    if (fwP->mtn_rte >= 65536)
    {
        fwP->status &= ~0x200;
        fwP->status |=  0x100;
    }
}

// 
// Start address: 0x1f3760
static EA_WORK* bhEne19_ActionSearch(int act_nw, int act_no)
{
	int middle;
	int val;
	int low;
	int high;
	int key;
	// Line 2694, Address: 0x1f3760, Func Offset: 0
	// Line 2695, Address: 0x1f376c, Func Offset: 0xc
	// Line 2694, Address: 0x1f3770, Func Offset: 0x10
	// Line 2696, Address: 0x1f3774, Func Offset: 0x14
	// Line 2703, Address: 0x1f3778, Func Offset: 0x18
	// Line 2702, Address: 0x1f3780, Func Offset: 0x20
	// Line 2703, Address: 0x1f3788, Func Offset: 0x28
	// Line 2705, Address: 0x1f379c, Func Offset: 0x3c
	// Line 2706, Address: 0x1f37a4, Func Offset: 0x44
	// Line 2708, Address: 0x1f37b4, Func Offset: 0x54
	// Line 2713, Address: 0x1f37c0, Func Offset: 0x60
	// Line 2716, Address: 0x1f37cc, Func Offset: 0x6c
	// Line 2717, Address: 0x1f37d0, Func Offset: 0x70
	// Func End, Address: 0x1f37d8, Func Offset: 0x78
	scePrintf("bhEne19_ActionSearch - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f37e0
static int bhEne19_ActionChange(BH_PWORK* ewP, FW_WORK* fwP, int act_dst)
{
	EA_WORK* eaP;
	// Line 2729, Address: 0x1f37e0, Func Offset: 0
	// Line 2736, Address: 0x1f37fc, Func Offset: 0x1c
	// Line 2737, Address: 0x1f3818, Func Offset: 0x38
	// Line 2738, Address: 0x1f3824, Func Offset: 0x44
	// Line 2743, Address: 0x1f3834, Func Offset: 0x54
	// Line 2745, Address: 0x1f383c, Func Offset: 0x5c
	// Line 2748, Address: 0x1f384c, Func Offset: 0x6c
	// Line 2751, Address: 0x1f3854, Func Offset: 0x74
	// Line 2754, Address: 0x1f3858, Func Offset: 0x78
	// Line 2755, Address: 0x1f3860, Func Offset: 0x80
	// Line 2756, Address: 0x1f3864, Func Offset: 0x84
	// Line 2759, Address: 0x1f386c, Func Offset: 0x8c
	// Line 2760, Address: 0x1f3874, Func Offset: 0x94
	// Line 2761, Address: 0x1f3880, Func Offset: 0xa0
	// Line 2762, Address: 0x1f38b4, Func Offset: 0xd4
	// Line 2764, Address: 0x1f38b8, Func Offset: 0xd8
	// Line 2762, Address: 0x1f38bc, Func Offset: 0xdc
	// Line 2764, Address: 0x1f38c0, Func Offset: 0xe0
	// Line 2766, Address: 0x1f38d8, Func Offset: 0xf8
	// Line 2767, Address: 0x1f38f4, Func Offset: 0x114
	// Line 2769, Address: 0x1f38fc, Func Offset: 0x11c
	// Line 2772, Address: 0x1f3900, Func Offset: 0x120
	// Line 2769, Address: 0x1f3908, Func Offset: 0x128
	// Line 2772, Address: 0x1f390c, Func Offset: 0x12c
	// Line 2775, Address: 0x1f391c, Func Offset: 0x13c
	// Line 2776, Address: 0x1f3928, Func Offset: 0x148
	// Line 2775, Address: 0x1f392c, Func Offset: 0x14c
	// Line 2776, Address: 0x1f3934, Func Offset: 0x154
	// Line 2790, Address: 0x1f3950, Func Offset: 0x170
	// Line 2797, Address: 0x1f395c, Func Offset: 0x17c
	// Line 2801, Address: 0x1f3960, Func Offset: 0x180
	// Func End, Address: 0x1f397c, Func Offset: 0x19c
	scePrintf("bhEne19_ActionChange - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f3980
static int bhEne19_ActionMain(BH_PWORK* ewP, FW_WORK* fwP)
{
	short* s16P;
	int ang;
	int mat;
	int* stsP;
	// Line 2812, Address: 0x1f3980, Func Offset: 0
	// Line 2817, Address: 0x1f399c, Func Offset: 0x1c
	// Line 2820, Address: 0x1f39a4, Func Offset: 0x24
	// Line 2821, Address: 0x1f39b0, Func Offset: 0x30
	// Line 2820, Address: 0x1f39b4, Func Offset: 0x34
	// Line 2821, Address: 0x1f39b8, Func Offset: 0x38
	// Line 2822, Address: 0x1f39d4, Func Offset: 0x54
	// Line 2824, Address: 0x1f39f0, Func Offset: 0x70
	// Line 2825, Address: 0x1f39fc, Func Offset: 0x7c
	// Line 2824, Address: 0x1f3a00, Func Offset: 0x80
	// Line 2825, Address: 0x1f3a04, Func Offset: 0x84
	// Line 2826, Address: 0x1f3a20, Func Offset: 0xa0
	// Line 2828, Address: 0x1f3a3c, Func Offset: 0xbc
	// Line 2830, Address: 0x1f3a48, Func Offset: 0xc8
	// Line 2831, Address: 0x1f3a64, Func Offset: 0xe4
	// Line 2833, Address: 0x1f3a74, Func Offset: 0xf4
	// Line 2834, Address: 0x1f3a90, Func Offset: 0x110
	// Line 2839, Address: 0x1f3aa0, Func Offset: 0x120
	// Line 2843, Address: 0x1f3ac8, Func Offset: 0x148
	// Line 2847, Address: 0x1f3ad8, Func Offset: 0x158
	// Line 2849, Address: 0x1f3ae8, Func Offset: 0x168
	// Line 2850, Address: 0x1f3b04, Func Offset: 0x184
	// Line 2861, Address: 0x1f3b20, Func Offset: 0x1a0
	// Line 2862, Address: 0x1f3b40, Func Offset: 0x1c0
	// Line 2867, Address: 0x1f3b50, Func Offset: 0x1d0
	// Line 2865, Address: 0x1f3b5c, Func Offset: 0x1dc
	// Line 2867, Address: 0x1f3b60, Func Offset: 0x1e0
	// Line 2868, Address: 0x1f3b7c, Func Offset: 0x1fc
	// Line 2874, Address: 0x1f3b88, Func Offset: 0x208
	// Line 2876, Address: 0x1f3bbc, Func Offset: 0x23c
	// Line 2874, Address: 0x1f3bc0, Func Offset: 0x240
	// Line 2877, Address: 0x1f3bc4, Func Offset: 0x244
	// Func End, Address: 0x1f3bdc, Func Offset: 0x25c
	scePrintf("bhEne19_ActionMain - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f3be0
static void bhEne19_TargetAnalyze(BH_PWORK* ewP, FW_WORK* fwP)
{
	NJS_MATRIX* mtxP;
	NJS_POINT3 pos;
	//int dlt;
	int ang;
	int dlt;
	float dst;
	int* stsP;
	// Line 2888, Address: 0x1f3be0, Func Offset: 0
	// Line 2893, Address: 0x1f3bf8, Func Offset: 0x18
	// Line 2889, Address: 0x1f3c00, Func Offset: 0x20
	// Line 2893, Address: 0x1f3c04, Func Offset: 0x24
	// Line 2895, Address: 0x1f3c10, Func Offset: 0x30
	// Line 2901, Address: 0x1f3c40, Func Offset: 0x60
	// Line 2904, Address: 0x1f3c50, Func Offset: 0x70
	// Line 2905, Address: 0x1f3c58, Func Offset: 0x78
	// Line 2904, Address: 0x1f3c60, Func Offset: 0x80
	// Line 2905, Address: 0x1f3c64, Func Offset: 0x84
	// Line 2904, Address: 0x1f3c68, Func Offset: 0x88
	// Line 2905, Address: 0x1f3c6c, Func Offset: 0x8c
	// Line 2906, Address: 0x1f3c84, Func Offset: 0xa4
	// Line 2907, Address: 0x1f3cb0, Func Offset: 0xd0
	// Line 2908, Address: 0x1f3cdc, Func Offset: 0xfc
	// Line 2913, Address: 0x1f3d08, Func Offset: 0x128
	// Line 2920, Address: 0x1f3d20, Func Offset: 0x140
	// Line 2922, Address: 0x1f3d34, Func Offset: 0x154
	// Line 2923, Address: 0x1f3d40, Func Offset: 0x160
	// Line 2924, Address: 0x1f3d48, Func Offset: 0x168
	// Line 2926, Address: 0x1f3d50, Func Offset: 0x170
	// Line 2931, Address: 0x1f3d54, Func Offset: 0x174
	// Line 2933, Address: 0x1f3d94, Func Offset: 0x1b4
	// Line 2936, Address: 0x1f3da0, Func Offset: 0x1c0
	// Line 2938, Address: 0x1f3db0, Func Offset: 0x1d0
	// Line 2939, Address: 0x1f3dc8, Func Offset: 0x1e8
	// Line 2941, Address: 0x1f3dd4, Func Offset: 0x1f4
	// Line 2942, Address: 0x1f3df0, Func Offset: 0x210
	// Line 2943, Address: 0x1f3e0c, Func Offset: 0x22c
	// Line 2944, Address: 0x1f3e28, Func Offset: 0x248
	// Line 2949, Address: 0x1f3e44, Func Offset: 0x264
	// Line 2951, Address: 0x1f3e48, Func Offset: 0x268
	// Line 2949, Address: 0x1f3e58, Func Offset: 0x278
	// Line 2953, Address: 0x1f3e5c, Func Offset: 0x27c
	// Line 2951, Address: 0x1f3e60, Func Offset: 0x280
	// Line 2949, Address: 0x1f3e68, Func Offset: 0x288
	// Line 2951, Address: 0x1f3e6c, Func Offset: 0x28c
	// Line 2953, Address: 0x1f3e70, Func Offset: 0x290
	// Line 2955, Address: 0x1f3e7c, Func Offset: 0x29c
	// Line 2956, Address: 0x1f3e8c, Func Offset: 0x2ac
	// Line 2957, Address: 0x1f3ea4, Func Offset: 0x2c4
	// Line 2959, Address: 0x1f3ec0, Func Offset: 0x2e0
	// Line 2960, Address: 0x1f3ec8, Func Offset: 0x2e8
	// Line 2961, Address: 0x1f3ee0, Func Offset: 0x300
	// Line 2970, Address: 0x1f3eec, Func Offset: 0x30c
	// Func End, Address: 0x1f3f08, Func Offset: 0x328
	scePrintf("bhEne19_TargetAnalyze - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f3f10
static void bhEne19_PositonFix(BH_PWORK* ewP, FW_WORK* fwP)
{
	NJS_POINT3* vzP;
	NJS_POINT3 vct;
	char** tblP;
	int sts;
	NJS_POINT3* vaP;
	char* FixDatTbl[2][4];
	// Line 2981, Address: 0x1f3f10, Func Offset: 0
	// Line 3015, Address: 0x1f3f28, Func Offset: 0x18
	// Line 3017, Address: 0x1f3f30, Func Offset: 0x20
	// Line 3012, Address: 0x1f3f34, Func Offset: 0x24
	// Line 3017, Address: 0x1f3f38, Func Offset: 0x28
	// Line 3020, Address: 0x1f3f44, Func Offset: 0x34
	// Line 3022, Address: 0x1f3f64, Func Offset: 0x54
	// Line 3023, Address: 0x1f3f74, Func Offset: 0x64
	// Line 3025, Address: 0x1f3f88, Func Offset: 0x78
	// Line 3027, Address: 0x1f3f9c, Func Offset: 0x8c
	// Line 3029, Address: 0x1f3fa4, Func Offset: 0x94
	// Line 3030, Address: 0x1f3fc8, Func Offset: 0xb8
	// Line 3031, Address: 0x1f3fd0, Func Offset: 0xc0
	// Line 3032, Address: 0x1f3ffc, Func Offset: 0xec
	// Line 3033, Address: 0x1f4004, Func Offset: 0xf4
	// Line 3043, Address: 0x1f4038, Func Offset: 0x128
	// Line 3045, Address: 0x1f4040, Func Offset: 0x130
	// Line 3046, Address: 0x1f404c, Func Offset: 0x13c
	// Line 3047, Address: 0x1f4060, Func Offset: 0x150
	// Line 3048, Address: 0x1f4074, Func Offset: 0x164
	// Line 3049, Address: 0x1f4080, Func Offset: 0x170
	// Line 3053, Address: 0x1f4090, Func Offset: 0x180
	// Line 3056, Address: 0x1f409c, Func Offset: 0x18c
	// Line 3057, Address: 0x1f40bc, Func Offset: 0x1ac
	// Line 3060, Address: 0x1f40d4, Func Offset: 0x1c4
	// Func End, Address: 0x1f40f0, Func Offset: 0x1e0
	scePrintf("bhEne19_PositonFix - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f40f0
static void bhEne19_HeadTurn(BH_PWORK* ewP, FW_WORK* fwP, int mode)
{
	int ang;
	int dlt;
	NJS_POINT3* posP;
	NJS_CNK_OBJECT* objP;
	O_WORK* owP;
	// Line 3072, Address: 0x1f40f0, Func Offset: 0
	// Line 3073, Address: 0x1f4108, Func Offset: 0x18
	// Line 3075, Address: 0x1f4110, Func Offset: 0x20
	// Line 3080, Address: 0x1f4118, Func Offset: 0x28
	// Line 3084, Address: 0x1f411c, Func Offset: 0x2c
	// Line 3083, Address: 0x1f412c, Func Offset: 0x3c
	// Line 3080, Address: 0x1f4130, Func Offset: 0x40
	// Line 3084, Address: 0x1f4134, Func Offset: 0x44
	// Line 3085, Address: 0x1f4168, Func Offset: 0x78
	// Line 3088, Address: 0x1f4170, Func Offset: 0x80
	// Line 3090, Address: 0x1f418c, Func Offset: 0x9c
	// Line 3093, Address: 0x1f419c, Func Offset: 0xac
	// Line 3096, Address: 0x1f41a0, Func Offset: 0xb0
	// Line 3098, Address: 0x1f41a4, Func Offset: 0xb4
	// Line 3099, Address: 0x1f41b0, Func Offset: 0xc0
	// Line 3100, Address: 0x1f41b8, Func Offset: 0xc8
	// Line 3101, Address: 0x1f41c0, Func Offset: 0xd0
	// Line 3102, Address: 0x1f41d0, Func Offset: 0xe0
	// Line 3105, Address: 0x1f41dc, Func Offset: 0xec
	// Func End, Address: 0x1f41f8, Func Offset: 0x108
	scePrintf("bhEne19_HeadTurn - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4200
static int bhEne19_AttackHitCheck(BH_PWORK* ewP, TY_ARM_NO arm_no, float ar, int* angP)
{
	int dir;
	FW_WORK* fwP;
	NJS_SPHERE spr;
	int hit;
	TY_OBJ_MODE AtkObj[2][2];
	NJS_POINT3 AtkOff[2];
	// Line 3116, Address: 0x1f4200, Func Offset: 0
	// Line 3134, Address: 0x1f4220, Func Offset: 0x20
	// Line 3143, Address: 0x1f4224, Func Offset: 0x24
	// Line 3140, Address: 0x1f4228, Func Offset: 0x28
	// Line 3143, Address: 0x1f422c, Func Offset: 0x2c
	// Line 3141, Address: 0x1f4238, Func Offset: 0x38
	// Line 3143, Address: 0x1f423c, Func Offset: 0x3c
	// Line 3144, Address: 0x1f4288, Func Offset: 0x88
	// Line 3150, Address: 0x1f42a4, Func Offset: 0xa4
	// Line 3151, Address: 0x1f42ac, Func Offset: 0xac
	// Line 3152, Address: 0x1f42e4, Func Offset: 0xe4
	// Line 3158, Address: 0x1f4300, Func Offset: 0x100
	// Line 3159, Address: 0x1f4308, Func Offset: 0x108
	// Line 3163, Address: 0x1f430c, Func Offset: 0x10c
	// Line 3165, Address: 0x1f4314, Func Offset: 0x114
	// Line 3167, Address: 0x1f4318, Func Offset: 0x118
	// Line 3165, Address: 0x1f431c, Func Offset: 0x11c
	// Line 3167, Address: 0x1f4320, Func Offset: 0x120
	// Line 3168, Address: 0x1f4334, Func Offset: 0x134
	// Line 3170, Address: 0x1f433c, Func Offset: 0x13c
	// Line 3172, Address: 0x1f4340, Func Offset: 0x140
	// Line 3174, Address: 0x1f4348, Func Offset: 0x148
	// Line 3175, Address: 0x1f434c, Func Offset: 0x14c
	// Func End, Address: 0x1f4370, Func Offset: 0x170
	scePrintf("bhEne19_AttackHitCheck - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4370
static void bhEne19_CalcEnemy(BH_PWORK* ewP, FW_WORK* fwP)
{
	O_WORK* owP;
	NJS_POINT3* dstP;
	NJS_POINT3* srcP;
	// Line 3186, Address: 0x1f4370, Func Offset: 0
	// Line 3192, Address: 0x1f4384, Func Offset: 0x14
	// Line 3195, Address: 0x1f438c, Func Offset: 0x1c
	// Line 3204, Address: 0x1f4390, Func Offset: 0x20
	// Line 3195, Address: 0x1f4398, Func Offset: 0x28
	// Line 3198, Address: 0x1f439c, Func Offset: 0x2c
	// Line 3195, Address: 0x1f43a0, Func Offset: 0x30
	// Line 3196, Address: 0x1f43b4, Func Offset: 0x44
	// Line 3198, Address: 0x1f43cc, Func Offset: 0x5c
	// Line 3201, Address: 0x1f43e4, Func Offset: 0x74
	// Line 3204, Address: 0x1f43fc, Func Offset: 0x8c
	// Line 3205, Address: 0x1f4410, Func Offset: 0xa0
	// Line 3206, Address: 0x1f4424, Func Offset: 0xb4
	// Line 3208, Address: 0x1f4438, Func Offset: 0xc8
	// Line 3210, Address: 0x1f4440, Func Offset: 0xd0
	// Func End, Address: 0x1f4454, Func Offset: 0xe4
	scePrintf("bhEne19_CalcEnemy - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4460
static void bhEne19_DmgCheck(BH_PWORK* ewP, FW_WORK* fwP)
{
	NJS_POINT3 dir;
	int dst;
	int flg;
	int eff_typ;
	DD_WORK* ddP;
	int* stsP;
	DD_WORK DmgDat[21];
	// Line 3221, Address: 0x1f4460, Func Offset: 0
	// Line 3250, Address: 0x1f4480, Func Offset: 0x20
	// Line 3251, Address: 0x1f44a4, Func Offset: 0x44
	// Line 3252, Address: 0x1f44b0, Func Offset: 0x50
	// Line 3253, Address: 0x1f44bc, Func Offset: 0x5c
	// Line 3255, Address: 0x1f44c8, Func Offset: 0x68
	// Line 3260, Address: 0x1f44d0, Func Offset: 0x70
	// Line 3263, Address: 0x1f44e0, Func Offset: 0x80
	// Line 3266, Address: 0x1f44ec, Func Offset: 0x8c
	// Line 3268, Address: 0x1f4504, Func Offset: 0xa4
	// Line 3271, Address: 0x1f4508, Func Offset: 0xa8
	// Line 3268, Address: 0x1f450c, Func Offset: 0xac
	// Line 3271, Address: 0x1f4520, Func Offset: 0xc0
	// Line 3272, Address: 0x1f4548, Func Offset: 0xe8
	// Line 3276, Address: 0x1f4564, Func Offset: 0x104
	// Line 3279, Address: 0x1f457c, Func Offset: 0x11c
	// Line 3280, Address: 0x1f4580, Func Offset: 0x120
	// Line 3279, Address: 0x1f458c, Func Offset: 0x12c
	// Line 3280, Address: 0x1f4590, Func Offset: 0x130
	// Line 3283, Address: 0x1f45ac, Func Offset: 0x14c
	// Line 3284, Address: 0x1f45c0, Func Offset: 0x160
	// Line 3285, Address: 0x1f45c4, Func Offset: 0x164
	// Line 3292, Address: 0x1f45c8, Func Offset: 0x168
	// Line 3293, Address: 0x1f45cc, Func Offset: 0x16c
	// Line 3294, Address: 0x1f45e0, Func Offset: 0x180
	// Line 3295, Address: 0x1f45f4, Func Offset: 0x194
	// Line 3297, Address: 0x1f4604, Func Offset: 0x1a4
	// Line 3299, Address: 0x1f462c, Func Offset: 0x1cc
	// Line 3302, Address: 0x1f463c, Func Offset: 0x1dc
	// Line 3305, Address: 0x1f4654, Func Offset: 0x1f4
	// Line 3306, Address: 0x1f4658, Func Offset: 0x1f8
	// Line 3305, Address: 0x1f465c, Func Offset: 0x1fc
	// Line 3306, Address: 0x1f467c, Func Offset: 0x21c
	// Line 3308, Address: 0x1f4688, Func Offset: 0x228
	// Line 3309, Address: 0x1f4694, Func Offset: 0x234
	// Line 3310, Address: 0x1f46a0, Func Offset: 0x240
	// Line 3313, Address: 0x1f46bc, Func Offset: 0x25c
	// Line 3317, Address: 0x1f46d4, Func Offset: 0x274
	// Line 3318, Address: 0x1f46e4, Func Offset: 0x284
	// Line 3320, Address: 0x1f4700, Func Offset: 0x2a0
	// Line 3323, Address: 0x1f4704, Func Offset: 0x2a4
	// Line 3325, Address: 0x1f470c, Func Offset: 0x2ac
	// Line 3326, Address: 0x1f471c, Func Offset: 0x2bc
	// Line 3328, Address: 0x1f4728, Func Offset: 0x2c8
	// Line 3330, Address: 0x1f4730, Func Offset: 0x2d0
	// Line 3336, Address: 0x1f4748, Func Offset: 0x2e8
	// Line 3337, Address: 0x1f475c, Func Offset: 0x2fc
	// Func End, Address: 0x1f477c, Func Offset: 0x31c
	scePrintf("bhEne19_DmgCheck - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4780
static void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, NJS_POINT3* dirP)
{
	//NJS_POINT3 off;
	//EO_WORK* eoP;
	//int i;
	//NJS_MATRIX* mtxP;
	//int i;
	NJS_MATRIX* mtxP;
	NJS_POINT3* posP;
	NJS_POINT3 dir;
	float scl;
	int djnt_no;
	//NJS_POINT3 off;
	//NJS_POINT3 off;
	//EO_WORK* eoP;
	int i;
	NJS_POINT3 vct;
	EO_WORK* eoP;
	NJS_POINT3 off;
	float off_z;
	int* effP;
	EO_WORK OffTbl[26];
	int EffTbl[12][4];
	// Line 3347, Address: 0x1f4780, Func Offset: 0
	// Line 3398, Address: 0x1f479c, Func Offset: 0x1c
	// Line 3347, Address: 0x1f47a4, Func Offset: 0x24
	// Line 3403, Address: 0x1f47a8, Func Offset: 0x28
	// Line 3398, Address: 0x1f47ac, Func Offset: 0x2c
	// Line 3403, Address: 0x1f47c0, Func Offset: 0x40
	// Line 3405, Address: 0x1f4808, Func Offset: 0x88
	// Line 3410, Address: 0x1f484c, Func Offset: 0xcc
	// Line 3412, Address: 0x1f4858, Func Offset: 0xd8
	// Line 3413, Address: 0x1f4898, Func Offset: 0x118
	// Line 3416, Address: 0x1f48b8, Func Offset: 0x138
	// Line 3413, Address: 0x1f48c0, Func Offset: 0x140
	// Line 3416, Address: 0x1f48d4, Func Offset: 0x154
	// Line 3413, Address: 0x1f48d8, Func Offset: 0x158
	// Line 3414, Address: 0x1f48e8, Func Offset: 0x168
	// Line 3416, Address: 0x1f48ec, Func Offset: 0x16c
	// Line 3418, Address: 0x1f4900, Func Offset: 0x180
	// Line 3425, Address: 0x1f4908, Func Offset: 0x188
	// Line 3426, Address: 0x1f4920, Func Offset: 0x1a0
	// Line 3428, Address: 0x1f4928, Func Offset: 0x1a8
	// Line 3429, Address: 0x1f4940, Func Offset: 0x1c0
	// Line 3430, Address: 0x1f4958, Func Offset: 0x1d8
	// Line 3431, Address: 0x1f4988, Func Offset: 0x208
	// Line 3435, Address: 0x1f49b0, Func Offset: 0x230
	// Line 3439, Address: 0x1f49bc, Func Offset: 0x23c
	// Line 3431, Address: 0x1f49c0, Func Offset: 0x240
	// Line 3432, Address: 0x1f49cc, Func Offset: 0x24c
	// Line 3439, Address: 0x1f49d4, Func Offset: 0x254
	// Line 3432, Address: 0x1f49dc, Func Offset: 0x25c
	// Line 3439, Address: 0x1f49e0, Func Offset: 0x260
	// Line 3432, Address: 0x1f49e4, Func Offset: 0x264
	// Line 3433, Address: 0x1f4a04, Func Offset: 0x284
	// Line 3434, Address: 0x1f4a1c, Func Offset: 0x29c
	// Line 3435, Address: 0x1f4a30, Func Offset: 0x2b0
	// Line 3441, Address: 0x1f4a68, Func Offset: 0x2e8
	// Line 3444, Address: 0x1f4a74, Func Offset: 0x2f4
	// Line 3445, Address: 0x1f4ab4, Func Offset: 0x334
	// Line 3448, Address: 0x1f4ad0, Func Offset: 0x350
	// Line 3445, Address: 0x1f4ad8, Func Offset: 0x358
	// Line 3448, Address: 0x1f4adc, Func Offset: 0x35c
	// Line 3445, Address: 0x1f4ae0, Func Offset: 0x360
	// Line 3448, Address: 0x1f4af0, Func Offset: 0x370
	// Line 3445, Address: 0x1f4af8, Func Offset: 0x378
	// Line 3448, Address: 0x1f4afc, Func Offset: 0x37c
	// Line 3445, Address: 0x1f4b08, Func Offset: 0x388
	// Line 3448, Address: 0x1f4b18, Func Offset: 0x398
	// Line 3449, Address: 0x1f4b20, Func Offset: 0x3a0
	// Line 3452, Address: 0x1f4b2c, Func Offset: 0x3ac
	// Line 3458, Address: 0x1f4b34, Func Offset: 0x3b4
	// Line 3460, Address: 0x1f4b40, Func Offset: 0x3c0
	// Line 3457, Address: 0x1f4b44, Func Offset: 0x3c4
	// Line 3460, Address: 0x1f4b48, Func Offset: 0x3c8
	// Line 3458, Address: 0x1f4b50, Func Offset: 0x3d0
	// Line 3460, Address: 0x1f4b54, Func Offset: 0x3d4
	// Line 3458, Address: 0x1f4b64, Func Offset: 0x3e4
	// Line 3460, Address: 0x1f4b68, Func Offset: 0x3e8
	// Line 3461, Address: 0x1f4b74, Func Offset: 0x3f4
	// Line 3462, Address: 0x1f4b80, Func Offset: 0x400
	// Line 3464, Address: 0x1f4b94, Func Offset: 0x414
	// Line 3472, Address: 0x1f4ba0, Func Offset: 0x420
	// Line 3464, Address: 0x1f4ba8, Func Offset: 0x428
	// Line 3465, Address: 0x1f4bb4, Func Offset: 0x434
	// Line 3472, Address: 0x1f4bc0, Func Offset: 0x440
	// Line 3465, Address: 0x1f4bc4, Func Offset: 0x444
	// Line 3466, Address: 0x1f4bd0, Func Offset: 0x450
	// Line 3467, Address: 0x1f4bf8, Func Offset: 0x478
	// Line 3468, Address: 0x1f4c0c, Func Offset: 0x48c
	// Line 3469, Address: 0x1f4c48, Func Offset: 0x4c8
	// Line 3470, Address: 0x1f4c60, Func Offset: 0x4e0
	// Line 3472, Address: 0x1f4c9c, Func Offset: 0x51c
	// Line 3474, Address: 0x1f4cb4, Func Offset: 0x534
	// Line 3483, Address: 0x1f4cbc, Func Offset: 0x53c
	// Line 3484, Address: 0x1f4cc0, Func Offset: 0x540
	// Line 3483, Address: 0x1f4cc4, Func Offset: 0x544
	// Line 3485, Address: 0x1f4ce4, Func Offset: 0x564
	// Line 3487, Address: 0x1f4cf8, Func Offset: 0x578
	// Line 3485, Address: 0x1f4cfc, Func Offset: 0x57c
	// Line 3487, Address: 0x1f4d04, Func Offset: 0x584
	// Line 3488, Address: 0x1f4d0c, Func Offset: 0x58c
	// Line 3489, Address: 0x1f4d20, Func Offset: 0x5a0
	// Line 3491, Address: 0x1f4d2c, Func Offset: 0x5ac
	// Line 3497, Address: 0x1f4d34, Func Offset: 0x5b4
	// Line 3499, Address: 0x1f4d40, Func Offset: 0x5c0
	// Line 3497, Address: 0x1f4d44, Func Offset: 0x5c4
	// Line 3501, Address: 0x1f4d48, Func Offset: 0x5c8
	// Line 3499, Address: 0x1f4d4c, Func Offset: 0x5cc
	// Line 3501, Address: 0x1f4d64, Func Offset: 0x5e4
	// Line 3504, Address: 0x1f4d6c, Func Offset: 0x5ec
	// Line 3505, Address: 0x1f4dac, Func Offset: 0x62c
	// Line 3508, Address: 0x1f4dcc, Func Offset: 0x64c
	// Line 3505, Address: 0x1f4dd4, Func Offset: 0x654
	// Line 3506, Address: 0x1f4df8, Func Offset: 0x678
	// Line 3508, Address: 0x1f4dfc, Func Offset: 0x67c
	// Line 3509, Address: 0x1f4e08, Func Offset: 0x688
	// Line 3513, Address: 0x1f4e14, Func Offset: 0x694
	// Line 3514, Address: 0x1f4e18, Func Offset: 0x698
	// Func End, Address: 0x1f4e3c, Func Offset: 0x6bc
	scePrintf("bhEne19_SetDmgEffect - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f4e40
static int bhEne19_CollisionCircle2Oval(NJS_MATRIX* basP, float ra, float rb, NJS_POINT3* posP, float rc)
{
	float dr;
	NJS_POINT3 dlt;
	NJS_POINT3 vct;
	float dst;
	float UniMtx[16];
	// Line 3524, Address: 0x1f4e40, Func Offset: 0
	// Line 3548, Address: 0x1f4e78, Func Offset: 0x38
	// Line 3553, Address: 0x1f4e88, Func Offset: 0x48
	// Line 3556, Address: 0x1f4e90, Func Offset: 0x50
	// Line 3553, Address: 0x1f4e94, Func Offset: 0x54
	// Line 3554, Address: 0x1f4e9c, Func Offset: 0x5c
	// Line 3555, Address: 0x1f4ea0, Func Offset: 0x60
	// Line 3556, Address: 0x1f4eac, Func Offset: 0x6c
	// Line 3566, Address: 0x1f4eb4, Func Offset: 0x74
	// Line 3556, Address: 0x1f4ebc, Func Offset: 0x7c
	// Line 3566, Address: 0x1f4ec0, Func Offset: 0x80
	// Line 3567, Address: 0x1f4ec8, Func Offset: 0x88
	// Line 3568, Address: 0x1f4ed4, Func Offset: 0x94
	// Line 3570, Address: 0x1f4ee8, Func Offset: 0xa8
	// Line 3571, Address: 0x1f4ef4, Func Offset: 0xb4
	// Line 3570, Address: 0x1f4ef8, Func Offset: 0xb8
	// Line 3571, Address: 0x1f4f14, Func Offset: 0xd4
	// Line 3572, Address: 0x1f4f1c, Func Offset: 0xdc
	// Line 3576, Address: 0x1f4f20, Func Offset: 0xe0
	// Line 3572, Address: 0x1f4f24, Func Offset: 0xe4
	// Line 3576, Address: 0x1f4f34, Func Offset: 0xf4
	// Line 3578, Address: 0x1f4f44, Func Offset: 0x104
	// Line 3579, Address: 0x1f4f54, Func Offset: 0x114
	// Line 3580, Address: 0x1f4f5c, Func Offset: 0x11c
	// Line 3582, Address: 0x1f4f64, Func Offset: 0x124
	// Line 3585, Address: 0x1f4f68, Func Offset: 0x128
	// Line 3582, Address: 0x1f4f74, Func Offset: 0x134
	// Line 3583, Address: 0x1f4f7c, Func Offset: 0x13c
	// Line 3584, Address: 0x1f4f88, Func Offset: 0x148
	// Line 3585, Address: 0x1f4f90, Func Offset: 0x150
	// Line 3587, Address: 0x1f4f98, Func Offset: 0x158
	// Line 3591, Address: 0x1f4fa0, Func Offset: 0x160
	// Line 3592, Address: 0x1f4fb0, Func Offset: 0x170
	// Line 3591, Address: 0x1f4fbc, Func Offset: 0x17c
	// Line 3592, Address: 0x1f4fc4, Func Offset: 0x184
	// Line 3595, Address: 0x1f4fcc, Func Offset: 0x18c
	// Line 3596, Address: 0x1f4fd0, Func Offset: 0x190
	// Func End, Address: 0x1f4ffc, Func Offset: 0x1bc
	scePrintf("bhEne19_CollisionCircle2Oval - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f5000
static void bhEne19_TyBloodSet(EB_WORK* ebP)
{
	float* prmP;
	int rnd;
	FW_WORK* fwP;
	BH_PWORK* ewP;
	float SetPrm[2][3];
	// Line 3606, Address: 0x1f5000, Func Offset: 0
	// Line 3607, Address: 0x1f5018, Func Offset: 0x18
	// Line 3608, Address: 0x1f501c, Func Offset: 0x1c
	// Line 3616, Address: 0x1f5024, Func Offset: 0x24
	// Line 3617, Address: 0x1f5040, Func Offset: 0x40
	// Line 3618, Address: 0x1f504c, Func Offset: 0x4c
	// Line 3622, Address: 0x1f5088, Func Offset: 0x88
	// Line 3618, Address: 0x1f508c, Func Offset: 0x8c
	// Line 3622, Address: 0x1f5090, Func Offset: 0x90
	// Line 3624, Address: 0x1f50b0, Func Offset: 0xb0
	// Line 3626, Address: 0x1f50c8, Func Offset: 0xc8
	// Line 3631, Address: 0x1f50d0, Func Offset: 0xd0
	// Line 3626, Address: 0x1f50d4, Func Offset: 0xd4
	// Line 3631, Address: 0x1f50d8, Func Offset: 0xd8
	// Line 3626, Address: 0x1f50dc, Func Offset: 0xdc
	// Line 3627, Address: 0x1f50e8, Func Offset: 0xe8
	// Line 3629, Address: 0x1f50f4, Func Offset: 0xf4
	// Line 3627, Address: 0x1f50f8, Func Offset: 0xf8
	// Line 3628, Address: 0x1f5104, Func Offset: 0x104
	// Line 3629, Address: 0x1f5118, Func Offset: 0x118
	// Line 3630, Address: 0x1f5134, Func Offset: 0x134
	// Line 3631, Address: 0x1f5148, Func Offset: 0x148
	// Line 3632, Address: 0x1f515c, Func Offset: 0x15c
	// Line 3633, Address: 0x1f5184, Func Offset: 0x184
	// Line 3632, Address: 0x1f5188, Func Offset: 0x188
	// Line 3633, Address: 0x1f5194, Func Offset: 0x194
	// Line 3634, Address: 0x1f51b8, Func Offset: 0x1b8
	// Line 3635, Address: 0x1f5210, Func Offset: 0x210
	// Line 3636, Address: 0x1f5268, Func Offset: 0x268
	// Line 3638, Address: 0x1f5290, Func Offset: 0x290
	// Line 3636, Address: 0x1f5294, Func Offset: 0x294
	// Line 3638, Address: 0x1f52a8, Func Offset: 0x2a8
	// Line 3636, Address: 0x1f52b0, Func Offset: 0x2b0
	// Line 3638, Address: 0x1f52e4, Func Offset: 0x2e4
	// Line 3639, Address: 0x1f52fc, Func Offset: 0x2fc
	// Line 3640, Address: 0x1f5304, Func Offset: 0x304
	// Line 3642, Address: 0x1f530c, Func Offset: 0x30c
	// Func End, Address: 0x1f5328, Func Offset: 0x328
	scePrintf("bhEne19_TyBloodSet - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f5330
static void bhEne19_ClawReset(BH_PWORK* ewP, FW_WORK* fwP)
{
	NJS_POINT3* posP;
	NJS_CNK_OBJECT* objP;
	// Line 3653, Address: 0x1f5330, Func Offset: 0
	// Line 3656, Address: 0x1f5334, Func Offset: 0x4
	// Line 3653, Address: 0x1f5340, Func Offset: 0x10
	// Line 3656, Address: 0x1f5344, Func Offset: 0x14
	// Line 3657, Address: 0x1f5350, Func Offset: 0x20
	// Line 3658, Address: 0x1f5368, Func Offset: 0x38
	// Line 3659, Address: 0x1f5380, Func Offset: 0x50
	// Line 3660, Address: 0x1f5394, Func Offset: 0x64
	// Func End, Address: 0x1f539c, Func Offset: 0x6c
	scePrintf("bhEne19_ClawReset - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f53a0
static void bhEne19_SoundSet(BH_PWORK* ewP, FW_WORK* fwP)
{
	//int sts;
	int obj_b;
	int obj_a;
	int i;
	int sts;
	int obj;
	int snd_no;
	int SndTbl[20];
	int EffTbl[15];
	NJS_POINT3 WlkOff;
	// Line 3670, Address: 0x1f53a0, Func Offset: 0
	// Line 3672, Address: 0x1f53b0, Func Offset: 0x10
	// Line 3670, Address: 0x1f53b4, Func Offset: 0x14
	// Line 3672, Address: 0x1f53bc, Func Offset: 0x1c
	// Line 3695, Address: 0x1f53f0, Func Offset: 0x50
	// Line 3697, Address: 0x1f53f4, Func Offset: 0x54
	// Line 3698, Address: 0x1f53fc, Func Offset: 0x5c
	// Line 3700, Address: 0x1f5424, Func Offset: 0x84
	// Line 3703, Address: 0x1f5428, Func Offset: 0x88
	// Line 3711, Address: 0x1f5464, Func Offset: 0xc4
	// Line 3712, Address: 0x1f5468, Func Offset: 0xc8
	// Line 3714, Address: 0x1f547c, Func Offset: 0xdc
	// Line 3716, Address: 0x1f5494, Func Offset: 0xf4
	// Line 3718, Address: 0x1f54ac, Func Offset: 0x10c
	// Line 3721, Address: 0x1f54b0, Func Offset: 0x110
	// Line 3722, Address: 0x1f54b8, Func Offset: 0x118
	// Line 3723, Address: 0x1f54f4, Func Offset: 0x154
	// Line 3724, Address: 0x1f5500, Func Offset: 0x160
	// Line 3726, Address: 0x1f5504, Func Offset: 0x164
	// Line 3723, Address: 0x1f5508, Func Offset: 0x168
	// Line 3724, Address: 0x1f5514, Func Offset: 0x174
	// Line 3727, Address: 0x1f551c, Func Offset: 0x17c
	// Line 3731, Address: 0x1f5520, Func Offset: 0x180
	// Line 3724, Address: 0x1f552c, Func Offset: 0x18c
	// Line 3725, Address: 0x1f5538, Func Offset: 0x198
	// Line 3726, Address: 0x1f5554, Func Offset: 0x1b4
	// Line 3727, Address: 0x1f5568, Func Offset: 0x1c8
	// Line 3728, Address: 0x1f55a4, Func Offset: 0x204
	// Line 3729, Address: 0x1f55b8, Func Offset: 0x218
	// Line 3730, Address: 0x1f55cc, Func Offset: 0x22c
	// Line 3731, Address: 0x1f55e0, Func Offset: 0x240
	// Line 3734, Address: 0x1f55f8, Func Offset: 0x258
	// Line 3748, Address: 0x1f5600, Func Offset: 0x260
	// Line 3749, Address: 0x1f5610, Func Offset: 0x270
	// Line 3748, Address: 0x1f5614, Func Offset: 0x274
	// Line 3749, Address: 0x1f5620, Func Offset: 0x280
	// Line 3752, Address: 0x1f5628, Func Offset: 0x288
	// Line 3749, Address: 0x1f5634, Func Offset: 0x294
	// Line 3750, Address: 0x1f564c, Func Offset: 0x2ac
	// Line 3752, Address: 0x1f5658, Func Offset: 0x2b8
	// Line 3750, Address: 0x1f5660, Func Offset: 0x2c0
	// Line 3753, Address: 0x1f5694, Func Offset: 0x2f4
	// Line 3755, Address: 0x1f569c, Func Offset: 0x2fc
	// Line 3757, Address: 0x1f56a0, Func Offset: 0x300
	// Line 3753, Address: 0x1f56ac, Func Offset: 0x30c
	// Line 3754, Address: 0x1f56b8, Func Offset: 0x318
	// Line 3755, Address: 0x1f56d4, Func Offset: 0x334
	// Line 3756, Address: 0x1f56e8, Func Offset: 0x348
	// Line 3757, Address: 0x1f5724, Func Offset: 0x384
	// Line 3756, Address: 0x1f5728, Func Offset: 0x388
	// Line 3757, Address: 0x1f5734, Func Offset: 0x394
	// Line 3758, Address: 0x1f5750, Func Offset: 0x3b0
	// Line 3757, Address: 0x1f5758, Func Offset: 0x3b8
	// Line 3758, Address: 0x1f575c, Func Offset: 0x3bc
	// Line 3760, Address: 0x1f5764, Func Offset: 0x3c4
	// Line 3767, Address: 0x1f576c, Func Offset: 0x3cc
	// Line 3765, Address: 0x1f5774, Func Offset: 0x3d4
	// Line 3767, Address: 0x1f5778, Func Offset: 0x3d8
	// Line 3768, Address: 0x1f577c, Func Offset: 0x3dc
	// Line 3767, Address: 0x1f5780, Func Offset: 0x3e0
	// Line 3768, Address: 0x1f578c, Func Offset: 0x3ec
	// Line 3771, Address: 0x1f5794, Func Offset: 0x3f4
	// Line 3774, Address: 0x1f5798, Func Offset: 0x3f8
	// Line 3768, Address: 0x1f579c, Func Offset: 0x3fc
	// Line 3769, Address: 0x1f57a8, Func Offset: 0x408
	// Line 3770, Address: 0x1f57c4, Func Offset: 0x424
	// Line 3771, Address: 0x1f57d8, Func Offset: 0x438
	// Line 3772, Address: 0x1f5814, Func Offset: 0x474
	// Line 3774, Address: 0x1f5824, Func Offset: 0x484
	// Line 3775, Address: 0x1f582c, Func Offset: 0x48c
	// Line 3777, Address: 0x1f5830, Func Offset: 0x490
	// Line 3778, Address: 0x1f5838, Func Offset: 0x498
	// Line 3779, Address: 0x1f583c, Func Offset: 0x49c
	// Line 3782, Address: 0x1f5840, Func Offset: 0x4a0
	// Line 3783, Address: 0x1f5848, Func Offset: 0x4a8
	// Line 3782, Address: 0x1f5850, Func Offset: 0x4b0
	// Line 3783, Address: 0x1f5860, Func Offset: 0x4c0
	// Line 3784, Address: 0x1f5870, Func Offset: 0x4d0
	// Line 3783, Address: 0x1f5878, Func Offset: 0x4d8
	// Line 3784, Address: 0x1f587c, Func Offset: 0x4dc
	// Line 3783, Address: 0x1f5880, Func Offset: 0x4e0
	// Line 3784, Address: 0x1f589c, Func Offset: 0x4fc
	// Line 3783, Address: 0x1f58a0, Func Offset: 0x500
	// Line 3784, Address: 0x1f58ac, Func Offset: 0x50c
	// Line 3785, Address: 0x1f58c0, Func Offset: 0x520
	// Line 3786, Address: 0x1f58c8, Func Offset: 0x528
	// Line 3785, Address: 0x1f58d0, Func Offset: 0x530
	// Line 3786, Address: 0x1f58e0, Func Offset: 0x540
	// Line 3787, Address: 0x1f58f0, Func Offset: 0x550
	// Line 3786, Address: 0x1f58f8, Func Offset: 0x558
	// Line 3787, Address: 0x1f58fc, Func Offset: 0x55c
	// Line 3786, Address: 0x1f5900, Func Offset: 0x560
	// Line 3787, Address: 0x1f591c, Func Offset: 0x57c
	// Line 3786, Address: 0x1f5920, Func Offset: 0x580
	// Line 3787, Address: 0x1f592c, Func Offset: 0x58c
	// Line 3792, Address: 0x1f5940, Func Offset: 0x5a0
	// Func End, Address: 0x1f595c, Func Offset: 0x5bc
	scePrintf("bhEne19_SoundSet - UNIMPLEMENTED!\n");
}

// 100% matching!
static int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP)
{
	unsigned short* atrP;

    atrP = ewP->mnwP[ewP->mtn_no].atrP;
  
    return (atrP != NULL) ? atrP[ewP->frm_no / 65536] : 0;
}

// 
// Start address: 0x1f59b0
static int bhEne19_PlySetDamage(BH_PWORK* plP, FW_WORK* fwP, int dmg_mod)
{
	int PlyDmgTbl[4];
	// Line 3821, Address: 0x1f59b0, Func Offset: 0
	// Line 3833, Address: 0x1f59b8, Func Offset: 0x8
	// Line 3835, Address: 0x1f59d8, Func Offset: 0x28
	// Line 3836, Address: 0x1f59e4, Func Offset: 0x34
	// Line 3837, Address: 0x1f59ec, Func Offset: 0x3c
	// Line 3835, Address: 0x1f59f0, Func Offset: 0x40
	// Line 3843, Address: 0x1f59f8, Func Offset: 0x48
	// Line 3836, Address: 0x1f59fc, Func Offset: 0x4c
	// Line 3843, Address: 0x1f5a00, Func Offset: 0x50
	// Line 3836, Address: 0x1f5a0c, Func Offset: 0x5c
	// Line 3837, Address: 0x1f5a14, Func Offset: 0x64
	// Line 3838, Address: 0x1f5a18, Func Offset: 0x68
	// Line 3839, Address: 0x1f5a1c, Func Offset: 0x6c
	// Line 3840, Address: 0x1f5a20, Func Offset: 0x70
	// Line 3843, Address: 0x1f5a24, Func Offset: 0x74
	// Line 3845, Address: 0x1f5a34, Func Offset: 0x84
	// Line 3847, Address: 0x1f5a4c, Func Offset: 0x9c
	// Line 3855, Address: 0x1f5a54, Func Offset: 0xa4
	// Line 3856, Address: 0x1f5a58, Func Offset: 0xa8
	// Line 3847, Address: 0x1f5a5c, Func Offset: 0xac
	// Line 3848, Address: 0x1f5a64, Func Offset: 0xb4
	// Line 3852, Address: 0x1f5a70, Func Offset: 0xc0
	// Line 3855, Address: 0x1f5a74, Func Offset: 0xc4
	// Line 3856, Address: 0x1f5a78, Func Offset: 0xc8
	// Line 3857, Address: 0x1f5a7c, Func Offset: 0xcc
	// Line 3860, Address: 0x1f5a80, Func Offset: 0xd0
	// Line 3861, Address: 0x1f5a84, Func Offset: 0xd4
	// Line 3863, Address: 0x1f5aa4, Func Offset: 0xf4
	// Line 3865, Address: 0x1f5ab0, Func Offset: 0x100
	// Line 3868, Address: 0x1f5ab8, Func Offset: 0x108
	// Line 3869, Address: 0x1f5abc, Func Offset: 0x10c
	// Func End, Address: 0x1f5ac8, Func Offset: 0x118
	scePrintf("bhEne19_PlySetDamage - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f5ad0
static void bhEne19_PlyMoveMain(BH_PWORK* plP, FW_WORK* fwP)
{
	ATR_WORK* htP;
	int act;
	int* stsP;
	// Line 3880, Address: 0x1f5ad0, Func Offset: 0
	// Line 3887, Address: 0x1f5aec, Func Offset: 0x1c
	// Line 3881, Address: 0x1f5afc, Func Offset: 0x2c
	// Line 3887, Address: 0x1f5b00, Func Offset: 0x30
	// Line 3889, Address: 0x1f5b08, Func Offset: 0x38
	// Line 3890, Address: 0x1f5b14, Func Offset: 0x44
	// Line 3891, Address: 0x1f5b2c, Func Offset: 0x5c
	// Line 3892, Address: 0x1f5b48, Func Offset: 0x78
	// Line 3893, Address: 0x1f5b64, Func Offset: 0x94
	// Line 3897, Address: 0x1f5b7c, Func Offset: 0xac
	// Line 3898, Address: 0x1f5b8c, Func Offset: 0xbc
	// Line 3900, Address: 0x1f5bb8, Func Offset: 0xe8
	// Line 3901, Address: 0x1f5bcc, Func Offset: 0xfc
	// Line 3902, Address: 0x1f5bd0, Func Offset: 0x100
	// Line 3903, Address: 0x1f5bd4, Func Offset: 0x104
	// Line 3907, Address: 0x1f5bdc, Func Offset: 0x10c
	// Line 3908, Address: 0x1f5bf0, Func Offset: 0x120
	// Line 3909, Address: 0x1f5bf4, Func Offset: 0x124
	// Line 3910, Address: 0x1f5bf8, Func Offset: 0x128
	// Line 3913, Address: 0x1f5c00, Func Offset: 0x130
	// Line 3914, Address: 0x1f5c14, Func Offset: 0x144
	// Line 3915, Address: 0x1f5c18, Func Offset: 0x148
	// Line 3916, Address: 0x1f5c1c, Func Offset: 0x14c
	// Line 3919, Address: 0x1f5c24, Func Offset: 0x154
	// Line 3920, Address: 0x1f5c58, Func Offset: 0x188
	// Line 3922, Address: 0x1f5c68, Func Offset: 0x198
	// Line 3923, Address: 0x1f5c78, Func Offset: 0x1a8
	// Line 3924, Address: 0x1f5c88, Func Offset: 0x1b8
	// Line 3925, Address: 0x1f5ca0, Func Offset: 0x1d0
	// Line 3927, Address: 0x1f5ca4, Func Offset: 0x1d4
	// Line 3929, Address: 0x1f5ca8, Func Offset: 0x1d8
	// Line 3930, Address: 0x1f5cb0, Func Offset: 0x1e0
	// Line 3931, Address: 0x1f5cbc, Func Offset: 0x1ec
	// Line 3932, Address: 0x1f5cd0, Func Offset: 0x200
	// Line 3933, Address: 0x1f5cd4, Func Offset: 0x204
	// Line 3935, Address: 0x1f5cdc, Func Offset: 0x20c
	// Line 3936, Address: 0x1f5cf0, Func Offset: 0x220
	// Line 3937, Address: 0x1f5d04, Func Offset: 0x234
	// Line 3938, Address: 0x1f5d08, Func Offset: 0x238
	// Line 3939, Address: 0x1f5d10, Func Offset: 0x240
	// Line 3940, Address: 0x1f5d24, Func Offset: 0x254
	// Line 3943, Address: 0x1f5d28, Func Offset: 0x258
	// Line 3947, Address: 0x1f5d30, Func Offset: 0x260
	// Line 3948, Address: 0x1f5d3c, Func Offset: 0x26c
	// Line 3950, Address: 0x1f5d4c, Func Offset: 0x27c
	// Line 3951, Address: 0x1f5d64, Func Offset: 0x294
	// Line 3953, Address: 0x1f5d68, Func Offset: 0x298
	// Line 3954, Address: 0x1f5d6c, Func Offset: 0x29c
	// Line 3955, Address: 0x1f5d74, Func Offset: 0x2a4
	// Line 3956, Address: 0x1f5d80, Func Offset: 0x2b0
	// Line 3957, Address: 0x1f5d94, Func Offset: 0x2c4
	// Line 3958, Address: 0x1f5d98, Func Offset: 0x2c8
	// Line 3960, Address: 0x1f5da0, Func Offset: 0x2d0
	// Line 3961, Address: 0x1f5db4, Func Offset: 0x2e4
	// Line 3962, Address: 0x1f5dc8, Func Offset: 0x2f8
	// Line 3963, Address: 0x1f5dcc, Func Offset: 0x2fc
	// Line 3964, Address: 0x1f5dd4, Func Offset: 0x304
	// Line 3965, Address: 0x1f5de8, Func Offset: 0x318
	// Line 3975, Address: 0x1f5dec, Func Offset: 0x31c
	// Line 3976, Address: 0x1f5dfc, Func Offset: 0x32c
	// Line 3977, Address: 0x1f5e18, Func Offset: 0x348
	// Line 3980, Address: 0x1f5e24, Func Offset: 0x354
	// Func End, Address: 0x1f5e40, Func Offset: 0x370
	scePrintf("bhEne19_PlyMoveMain - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f5e40
static void bhEne19_PlyDmg042(BH_PWORK* plP, FW_WORK* fwP)
{
	int obj;
	int dlt;
	float spd;
	int dir;
	int EffTbl[4];
	// Line 3991, Address: 0x1f5e40, Func Offset: 0
	// Line 3993, Address: 0x1f5e58, Func Offset: 0x18
	// Line 3996, Address: 0x1f5e6c, Func Offset: 0x2c
	// Line 4001, Address: 0x1f5e80, Func Offset: 0x40
	// Line 4003, Address: 0x1f5e84, Func Offset: 0x44
	// Line 4004, Address: 0x1f5e9c, Func Offset: 0x5c
	// Line 4006, Address: 0x1f5eac, Func Offset: 0x6c
	// Line 4004, Address: 0x1f5eb0, Func Offset: 0x70
	// Line 4006, Address: 0x1f5eb8, Func Offset: 0x78
	// Line 4008, Address: 0x1f5ecc, Func Offset: 0x8c
	// Line 4006, Address: 0x1f5ed0, Func Offset: 0x90
	// Line 4008, Address: 0x1f5ed4, Func Offset: 0x94
	// Line 4006, Address: 0x1f5ed8, Func Offset: 0x98
	// Line 4008, Address: 0x1f5edc, Func Offset: 0x9c
	// Line 4006, Address: 0x1f5ee4, Func Offset: 0xa4
	// Line 4008, Address: 0x1f5eec, Func Offset: 0xac
	// Line 4013, Address: 0x1f5ef8, Func Offset: 0xb8
	// Line 4014, Address: 0x1f5f0c, Func Offset: 0xcc
	// Line 4016, Address: 0x1f5f18, Func Offset: 0xd8
	// Line 4018, Address: 0x1f5f40, Func Offset: 0x100
	// Line 4022, Address: 0x1f5f58, Func Offset: 0x118
	// Line 4027, Address: 0x1f5f68, Func Offset: 0x128
	// Line 4029, Address: 0x1f5f74, Func Offset: 0x134
	// Line 4027, Address: 0x1f5f7c, Func Offset: 0x13c
	// Line 4029, Address: 0x1f5f8c, Func Offset: 0x14c
	// Line 4030, Address: 0x1f5f9c, Func Offset: 0x15c
	// Line 4037, Address: 0x1f5fa4, Func Offset: 0x164
	// Line 4030, Address: 0x1f5fac, Func Offset: 0x16c
	// Line 4031, Address: 0x1f5fbc, Func Offset: 0x17c
	// Line 4037, Address: 0x1f5fc0, Func Offset: 0x180
	// Line 4031, Address: 0x1f5fc4, Func Offset: 0x184
	// Line 4033, Address: 0x1f5fcc, Func Offset: 0x18c
	// Line 4038, Address: 0x1f5fd0, Func Offset: 0x190
	// Line 4031, Address: 0x1f5fd4, Func Offset: 0x194
	// Line 4038, Address: 0x1f5fd8, Func Offset: 0x198
	// Line 4031, Address: 0x1f5fe0, Func Offset: 0x1a0
	// Line 4032, Address: 0x1f5ff0, Func Offset: 0x1b0
	// Line 4033, Address: 0x1f6004, Func Offset: 0x1c4
	// Line 4034, Address: 0x1f602c, Func Offset: 0x1ec
	// Line 4035, Address: 0x1f6040, Func Offset: 0x200
	// Line 4037, Address: 0x1f605c, Func Offset: 0x21c
	// Line 4038, Address: 0x1f6088, Func Offset: 0x248
	// Line 4037, Address: 0x1f608c, Func Offset: 0x24c
	// Line 4038, Address: 0x1f6098, Func Offset: 0x258
	// Line 4041, Address: 0x1f60ac, Func Offset: 0x26c
	// Func End, Address: 0x1f60c8, Func Offset: 0x288
	scePrintf("bhEne19_PlyDmg042 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f60d0
static void bhEne19_PlyDmg043(BH_PWORK* plP, FW_WORK* fwP)
{
	// Line 4052, Address: 0x1f60d0, Func Offset: 0
	// Line 4053, Address: 0x1f60e4, Func Offset: 0x14
	// Line 4056, Address: 0x1f60ec, Func Offset: 0x1c
	// Line 4059, Address: 0x1f610c, Func Offset: 0x3c
	// Line 4060, Address: 0x1f6118, Func Offset: 0x48
	// Line 4063, Address: 0x1f611c, Func Offset: 0x4c
	// Line 4059, Address: 0x1f6120, Func Offset: 0x50
	// Line 4060, Address: 0x1f612c, Func Offset: 0x5c
	// Line 4068, Address: 0x1f6134, Func Offset: 0x64
	// Line 4060, Address: 0x1f6140, Func Offset: 0x70
	// Line 4061, Address: 0x1f614c, Func Offset: 0x7c
	// Line 4062, Address: 0x1f616c, Func Offset: 0x9c
	// Line 4063, Address: 0x1f6180, Func Offset: 0xb0
	// Line 4064, Address: 0x1f61a8, Func Offset: 0xd8
	// Line 4065, Address: 0x1f61bc, Func Offset: 0xec
	// Line 4067, Address: 0x1f61d8, Func Offset: 0x108
	// Line 4068, Address: 0x1f6200, Func Offset: 0x130
	// Line 4067, Address: 0x1f6204, Func Offset: 0x134
	// Line 4068, Address: 0x1f6210, Func Offset: 0x140
	// Line 4071, Address: 0x1f6224, Func Offset: 0x154
	// Func End, Address: 0x1f6238, Func Offset: 0x168
	scePrintf("bhEne19_PlyDmg043 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEne19_PlyDmg044(BH_PWORK* plP, FW_WORK* fwP)
{
    if (fwP->ply_act.p_act_frm < 18)
    {
        plP->flg |=  0xC0000;
    }
    else if (fwP->ply_act.p_act_frm <= 40)
    {
        plP->flg &= ~0x80000;
    }
    else
    {
        plP->flg |=  0xC0000;
    }
	
    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg045(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_act_frm >= 11)
    {
        plP->flg |=  0x40000;
        plP->flg &= ~0x80000;
    }

    bhEne19_PlyDmgRtn(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg046_047(BH_PWORK* plP, FW_WORK* fwP)
{
	bhEne19_PlyDmgDie(plP, fwP);
}

// 100% matching!
static void bhEne19_PlyDmg050_051(BH_PWORK* plP, FW_WORK* fwP)
{
	if (fwP->ply_act.p_mtn_rte == 0)
    {
        CallPlayerVoice(1025);
    }

    bhEne19_PlyDmgDie(plP, fwP);
}

// 
// Start address: 0x1f6340
static void bhEne19_PlyDmg052_053(BH_PWORK* plP, FW_WORK* fwP)
{
	//int i;
	int dlt;
	int i;
	ATR_WORK* htP;
	float spd;
	int dir;
	//int EffTbl[4];
	int EffTbl[4];
	// Line 4151, Address: 0x1f6340, Func Offset: 0
	// Line 4153, Address: 0x1f635c, Func Offset: 0x1c
	// Line 4155, Address: 0x1f6370, Func Offset: 0x30
	// Line 4157, Address: 0x1f637c, Func Offset: 0x3c
	// Line 4159, Address: 0x1f6384, Func Offset: 0x44
	// Line 4166, Address: 0x1f6388, Func Offset: 0x48
	// Line 4168, Address: 0x1f638c, Func Offset: 0x4c
	// Line 4169, Address: 0x1f63a4, Func Offset: 0x64
	// Line 4171, Address: 0x1f63b4, Func Offset: 0x74
	// Line 4169, Address: 0x1f63b8, Func Offset: 0x78
	// Line 4171, Address: 0x1f63c0, Func Offset: 0x80
	// Line 4173, Address: 0x1f63d4, Func Offset: 0x94
	// Line 4171, Address: 0x1f63d8, Func Offset: 0x98
	// Line 4173, Address: 0x1f63dc, Func Offset: 0x9c
	// Line 4171, Address: 0x1f63e0, Func Offset: 0xa0
	// Line 4173, Address: 0x1f63e4, Func Offset: 0xa4
	// Line 4171, Address: 0x1f63ec, Func Offset: 0xac
	// Line 4173, Address: 0x1f63f4, Func Offset: 0xb4
	// Line 4181, Address: 0x1f6400, Func Offset: 0xc0
	// Line 4182, Address: 0x1f642c, Func Offset: 0xec
	// Line 4184, Address: 0x1f6434, Func Offset: 0xf4
	// Line 4193, Address: 0x1f6440, Func Offset: 0x100
	// Line 4184, Address: 0x1f644c, Func Offset: 0x10c
	// Line 4194, Address: 0x1f6450, Func Offset: 0x110
	// Line 4197, Address: 0x1f6454, Func Offset: 0x114
	// Line 4200, Address: 0x1f6458, Func Offset: 0x118
	// Line 4184, Address: 0x1f645c, Func Offset: 0x11c
	// Line 4193, Address: 0x1f6460, Func Offset: 0x120
	// Line 4194, Address: 0x1f6470, Func Offset: 0x130
	// Line 4195, Address: 0x1f6484, Func Offset: 0x144
	// Line 4196, Address: 0x1f64a4, Func Offset: 0x164
	// Line 4197, Address: 0x1f64b8, Func Offset: 0x178
	// Line 4198, Address: 0x1f64e0, Func Offset: 0x1a0
	// Line 4199, Address: 0x1f64f4, Func Offset: 0x1b4
	// Line 4202, Address: 0x1f6510, Func Offset: 0x1d0
	// Line 4203, Address: 0x1f6520, Func Offset: 0x1e0
	// Line 4202, Address: 0x1f6528, Func Offset: 0x1e8
	// Line 4203, Address: 0x1f6554, Func Offset: 0x214
	// Line 4202, Address: 0x1f655c, Func Offset: 0x21c
	// Line 4203, Address: 0x1f6568, Func Offset: 0x228
	// Line 4204, Address: 0x1f657c, Func Offset: 0x23c
	// Line 4207, Address: 0x1f658c, Func Offset: 0x24c
	// Line 4209, Address: 0x1f65a0, Func Offset: 0x260
	// Line 4212, Address: 0x1f65b4, Func Offset: 0x274
	// Line 4218, Address: 0x1f65bc, Func Offset: 0x27c
	// Line 4219, Address: 0x1f65d0, Func Offset: 0x290
	// Line 4221, Address: 0x1f65dc, Func Offset: 0x29c
	// Line 4223, Address: 0x1f6604, Func Offset: 0x2c4
	// Line 4228, Address: 0x1f661c, Func Offset: 0x2dc
	// Line 4235, Address: 0x1f662c, Func Offset: 0x2ec
	// Line 4236, Address: 0x1f664c, Func Offset: 0x30c
	// Line 4239, Address: 0x1f6658, Func Offset: 0x318
	// Line 4243, Address: 0x1f665c, Func Offset: 0x31c
	// Line 4236, Address: 0x1f6660, Func Offset: 0x320
	// Line 4237, Address: 0x1f666c, Func Offset: 0x32c
	// Line 4238, Address: 0x1f668c, Func Offset: 0x34c
	// Line 4239, Address: 0x1f66a0, Func Offset: 0x360
	// Line 4240, Address: 0x1f66c8, Func Offset: 0x388
	// Line 4241, Address: 0x1f66dc, Func Offset: 0x39c
	// Line 4245, Address: 0x1f66f8, Func Offset: 0x3b8
	// Line 4246, Address: 0x1f6708, Func Offset: 0x3c8
	// Line 4245, Address: 0x1f6710, Func Offset: 0x3d0
	// Line 4246, Address: 0x1f673c, Func Offset: 0x3fc
	// Line 4245, Address: 0x1f6744, Func Offset: 0x404
	// Line 4246, Address: 0x1f6750, Func Offset: 0x410
	// Line 4247, Address: 0x1f6764, Func Offset: 0x424
	// Line 4248, Address: 0x1f6774, Func Offset: 0x434
	// Line 4250, Address: 0x1f6778, Func Offset: 0x438
	// Func End, Address: 0x1f6798, Func Offset: 0x458
	scePrintf("bhEne19_PlyDmg052_053 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f67a0
static void bhEne19_PlyDmg117_118(BH_PWORK* plP, FW_WORK* fwP)
{
	int obj;
	int dlt;
	float spd;
	int dir;
	int EffTbl[2];
	// Line 4261, Address: 0x1f67a0, Func Offset: 0
	// Line 4263, Address: 0x1f67b8, Func Offset: 0x18
	// Line 4266, Address: 0x1f67cc, Func Offset: 0x2c
	// Line 4271, Address: 0x1f67e0, Func Offset: 0x40
	// Line 4273, Address: 0x1f67e4, Func Offset: 0x44
	// Line 4274, Address: 0x1f67fc, Func Offset: 0x5c
	// Line 4276, Address: 0x1f680c, Func Offset: 0x6c
	// Line 4274, Address: 0x1f6810, Func Offset: 0x70
	// Line 4276, Address: 0x1f6818, Func Offset: 0x78
	// Line 4278, Address: 0x1f682c, Func Offset: 0x8c
	// Line 4276, Address: 0x1f6830, Func Offset: 0x90
	// Line 4278, Address: 0x1f6834, Func Offset: 0x94
	// Line 4276, Address: 0x1f6838, Func Offset: 0x98
	// Line 4278, Address: 0x1f683c, Func Offset: 0x9c
	// Line 4276, Address: 0x1f6844, Func Offset: 0xa4
	// Line 4278, Address: 0x1f684c, Func Offset: 0xac
	// Line 4283, Address: 0x1f6858, Func Offset: 0xb8
	// Line 4284, Address: 0x1f686c, Func Offset: 0xcc
	// Line 4286, Address: 0x1f6878, Func Offset: 0xd8
	// Line 4288, Address: 0x1f68a0, Func Offset: 0x100
	// Line 4293, Address: 0x1f68b8, Func Offset: 0x118
	// Line 4298, Address: 0x1f68dc, Func Offset: 0x13c
	// Line 4300, Address: 0x1f68f0, Func Offset: 0x150
	// Line 4298, Address: 0x1f68f4, Func Offset: 0x154
	// Line 4300, Address: 0x1f68f8, Func Offset: 0x158
	// Line 4298, Address: 0x1f68fc, Func Offset: 0x15c
	// Line 4300, Address: 0x1f6900, Func Offset: 0x160
	// Line 4301, Address: 0x1f6904, Func Offset: 0x164
	// Line 4300, Address: 0x1f6908, Func Offset: 0x168
	// Line 4301, Address: 0x1f6914, Func Offset: 0x174
	// Line 4308, Address: 0x1f691c, Func Offset: 0x17c
	// Line 4304, Address: 0x1f6928, Func Offset: 0x188
	// Line 4301, Address: 0x1f692c, Func Offset: 0x18c
	// Line 4302, Address: 0x1f6938, Func Offset: 0x198
	// Line 4309, Address: 0x1f6944, Func Offset: 0x1a4
	// Line 4302, Address: 0x1f6950, Func Offset: 0x1b0
	// Line 4303, Address: 0x1f6964, Func Offset: 0x1c4
	// Line 4304, Address: 0x1f6978, Func Offset: 0x1d8
	// Line 4305, Address: 0x1f69a0, Func Offset: 0x200
	// Line 4306, Address: 0x1f69b4, Func Offset: 0x214
	// Line 4308, Address: 0x1f69d0, Func Offset: 0x230
	// Line 4309, Address: 0x1f69fc, Func Offset: 0x25c
	// Line 4308, Address: 0x1f6a00, Func Offset: 0x260
	// Line 4309, Address: 0x1f6a0c, Func Offset: 0x26c
	// Line 4312, Address: 0x1f6a20, Func Offset: 0x280
	// Line 4313, Address: 0x1f6a2c, Func Offset: 0x28c
	// Func End, Address: 0x1f6a48, Func Offset: 0x2a8
	scePrintf("bhEne19_PlyDmg117_118 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6a50
static void bhEne19_PlyDmgDie(BH_PWORK* plP, FW_WORK* fwP)
{
	PAW_WORK* pawP;
	// Line 4328, Address: 0x1f6a50, Func Offset: 0
	// Line 4329, Address: 0x1f6a74, Func Offset: 0x24
	// Line 4331, Address: 0x1f6a7c, Func Offset: 0x2c
	// Line 4332, Address: 0x1f6a88, Func Offset: 0x38
	// Line 4333, Address: 0x1f6a8c, Func Offset: 0x3c
	// Line 4331, Address: 0x1f6a90, Func Offset: 0x40
	// Line 4332, Address: 0x1f6a98, Func Offset: 0x48
	// Line 4333, Address: 0x1f6aa4, Func Offset: 0x54
	// Line 4334, Address: 0x1f6aa8, Func Offset: 0x58
	// Line 4335, Address: 0x1f6aac, Func Offset: 0x5c
	// Line 4336, Address: 0x1f6ab0, Func Offset: 0x60
	// Line 4340, Address: 0x1f6ab4, Func Offset: 0x64
	// Line 4341, Address: 0x1f6ac8, Func Offset: 0x78
	// Line 4342, Address: 0x1f6ad8, Func Offset: 0x88
	// Line 4344, Address: 0x1f6adc, Func Offset: 0x8c
	// Func End, Address: 0x1f6ae4, Func Offset: 0x94
	scePrintf("bhEne19_PlyDmgDie - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6af0
static void bhEne19_PlyDmgRtn(BH_PWORK* plP, FW_WORK* fwP)
{
	// Line 4358, Address: 0x1f6af0, Func Offset: 0
	// Line 4360, Address: 0x1f6b04, Func Offset: 0x14
	// Line 4362, Address: 0x1f6b08, Func Offset: 0x18
	// Line 4363, Address: 0x1f6b10, Func Offset: 0x20
	// Line 4366, Address: 0x1f6b14, Func Offset: 0x24
	// Line 4360, Address: 0x1f6b1c, Func Offset: 0x2c
	// Line 4362, Address: 0x1f6b20, Func Offset: 0x30
	// Line 4364, Address: 0x1f6b24, Func Offset: 0x34
	// Line 4368, Address: 0x1f6b28, Func Offset: 0x38
	// Line 4374, Address: 0x1f6b2c, Func Offset: 0x3c
	// Line 4362, Address: 0x1f6b30, Func Offset: 0x40
	// Line 4363, Address: 0x1f6b38, Func Offset: 0x48
	// Line 4364, Address: 0x1f6b44, Func Offset: 0x54
	// Line 4365, Address: 0x1f6b50, Func Offset: 0x60
	// Line 4366, Address: 0x1f6b5c, Func Offset: 0x6c
	// Line 4368, Address: 0x1f6b68, Func Offset: 0x78
	// Line 4369, Address: 0x1f6b6c, Func Offset: 0x7c
	// Line 4370, Address: 0x1f6b70, Func Offset: 0x80
	// Line 4371, Address: 0x1f6b74, Func Offset: 0x84
	// Line 4374, Address: 0x1f6b78, Func Offset: 0x88
	// Line 4376, Address: 0x1f6b84, Func Offset: 0x94
	// Func End, Address: 0x1f6b8c, Func Offset: 0x9c
	scePrintf("bhEne19_PlyDmgRtn - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6b90
static void bhEne19_PlyDmgFal(BH_PWORK* plP, FW_WORK* fwP)
{
	float spd;
	int dir;
	int dlt;
	PF_WORK* pfP;
	PAW_WORK* pawP;
	PF_WORK PlyFal[3];
	// Line 4387, Address: 0x1f6b90, Func Offset: 0
	// Line 4405, Address: 0x1f6bb0, Func Offset: 0x20
	// Line 4407, Address: 0x1f6bbc, Func Offset: 0x2c
	// Line 4405, Address: 0x1f6bc0, Func Offset: 0x30
	// Line 4404, Address: 0x1f6bc4, Func Offset: 0x34
	// Line 4405, Address: 0x1f6bc8, Func Offset: 0x38
	// Line 4407, Address: 0x1f6bd0, Func Offset: 0x40
	// Line 4405, Address: 0x1f6bd4, Func Offset: 0x44
	// Line 4407, Address: 0x1f6be0, Func Offset: 0x50
	// Line 4410, Address: 0x1f6c04, Func Offset: 0x74
	// Line 4411, Address: 0x1f6c08, Func Offset: 0x78
	// Line 4410, Address: 0x1f6c0c, Func Offset: 0x7c
	// Line 4411, Address: 0x1f6c14, Func Offset: 0x84
	// Line 4412, Address: 0x1f6c20, Func Offset: 0x90
	// Line 4414, Address: 0x1f6c2c, Func Offset: 0x9c
	// Line 4415, Address: 0x1f6c44, Func Offset: 0xb4
	// Line 4420, Address: 0x1f6c50, Func Offset: 0xc0
	// Line 4421, Address: 0x1f6c70, Func Offset: 0xe0
	// Line 4422, Address: 0x1f6c7c, Func Offset: 0xec
	// Line 4423, Address: 0x1f6c80, Func Offset: 0xf0
	// Line 4421, Address: 0x1f6c84, Func Offset: 0xf4
	// Line 4422, Address: 0x1f6c8c, Func Offset: 0xfc
	// Line 4423, Address: 0x1f6c98, Func Offset: 0x108
	// Line 4424, Address: 0x1f6c9c, Func Offset: 0x10c
	// Line 4425, Address: 0x1f6ca0, Func Offset: 0x110
	// Line 4426, Address: 0x1f6ca4, Func Offset: 0x114
	// Line 4427, Address: 0x1f6ca8, Func Offset: 0x118
	// Line 4433, Address: 0x1f6cb4, Func Offset: 0x124
	// Line 4434, Address: 0x1f6cc8, Func Offset: 0x138
	// Line 4436, Address: 0x1f6cd4, Func Offset: 0x144
	// Line 4438, Address: 0x1f6cfc, Func Offset: 0x16c
	// Line 4442, Address: 0x1f6d14, Func Offset: 0x184
	// Line 4443, Address: 0x1f6d20, Func Offset: 0x190
	// Line 4444, Address: 0x1f6d40, Func Offset: 0x1b0
	// Line 4448, Address: 0x1f6d4c, Func Offset: 0x1bc
	// Line 4449, Address: 0x1f6d6c, Func Offset: 0x1dc
	// Line 4450, Address: 0x1f6d70, Func Offset: 0x1e0
	// Line 4453, Address: 0x1f6d74, Func Offset: 0x1e4
	// Line 4454, Address: 0x1f6d84, Func Offset: 0x1f4
	// Line 4453, Address: 0x1f6d88, Func Offset: 0x1f8
	// Line 4454, Address: 0x1f6d90, Func Offset: 0x200
	// Line 4456, Address: 0x1f6da8, Func Offset: 0x218
	// Line 4454, Address: 0x1f6db0, Func Offset: 0x220
	// Line 4456, Address: 0x1f6db8, Func Offset: 0x228
	// Line 4459, Address: 0x1f6dc0, Func Offset: 0x230
	// Line 4460, Address: 0x1f6dc4, Func Offset: 0x234
	// Line 4459, Address: 0x1f6dcc, Func Offset: 0x23c
	// Line 4460, Address: 0x1f6dd0, Func Offset: 0x240
	// Line 4462, Address: 0x1f6dd8, Func Offset: 0x248
	// Line 4464, Address: 0x1f6de0, Func Offset: 0x250
	// Line 4465, Address: 0x1f6df0, Func Offset: 0x260
	// Line 4470, Address: 0x1f6df4, Func Offset: 0x264
	// Line 4471, Address: 0x1f6e0c, Func Offset: 0x27c
	// Func End, Address: 0x1f6e30, Func Offset: 0x2a0
	scePrintf("bhEne19_PlyDmgFal - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6e30
static void bhEne_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num)
{
	// Line 4519, Address: 0x1f6e30, Func Offset: 0
	// Line 4521, Address: 0x1f6e34, Func Offset: 0x4
	// Line 4520, Address: 0x1f6e38, Func Offset: 0x8
	// Line 4521, Address: 0x1f6e3c, Func Offset: 0xc
	// Line 4522, Address: 0x1f6e40, Func Offset: 0x10
	// Line 4523, Address: 0x1f6e48, Func Offset: 0x18
	// Line 4524, Address: 0x1f6e4c, Func Offset: 0x1c
	// Func End, Address: 0x1f6e54, Func Offset: 0x24
	scePrintf("bhEne_PlyActionInit - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6e60
static void bhEne_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP)
{
	// Line 4535, Address: 0x1f6e60, Func Offset: 0
	// Line 4537, Address: 0x1f6e70, Func Offset: 0x10
	// Line 4538, Address: 0x1f6e88, Func Offset: 0x28
	// Line 4539, Address: 0x1f6e94, Func Offset: 0x34
	// Line 4543, Address: 0x1f6e9c, Func Offset: 0x3c
	// Line 4546, Address: 0x1f6ebc, Func Offset: 0x5c
	// Line 4549, Address: 0x1f6ed4, Func Offset: 0x74
	// Line 4552, Address: 0x1f6ee0, Func Offset: 0x80
	// Line 4553, Address: 0x1f6f00, Func Offset: 0xa0
	// Func End, Address: 0x1f6f14, Func Offset: 0xb4
	scePrintf("bhEne_PlyActionMain - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f6f20
static int bhEne_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no)
{
	ACT_TBL_WORK* paP;
	// Line 4565, Address: 0x1f6f20, Func Offset: 0
	// Line 4568, Address: 0x1f6f34, Func Offset: 0x14
	// Line 4566, Address: 0x1f6f38, Func Offset: 0x18
	// Line 4568, Address: 0x1f6f48, Func Offset: 0x28
	// Line 4571, Address: 0x1f6f60, Func Offset: 0x40
	// Line 4573, Address: 0x1f6f64, Func Offset: 0x44
	// Line 4576, Address: 0x1f6f68, Func Offset: 0x48
	// Line 4571, Address: 0x1f6f6c, Func Offset: 0x4c
	// Line 4572, Address: 0x1f6f70, Func Offset: 0x50
	// Line 4573, Address: 0x1f6f74, Func Offset: 0x54
	// Line 4576, Address: 0x1f6f78, Func Offset: 0x58
	// Line 4578, Address: 0x1f6f84, Func Offset: 0x64
	// Line 4579, Address: 0x1f6f8c, Func Offset: 0x6c
	// Line 4580, Address: 0x1f6f94, Func Offset: 0x74
	// Line 4581, Address: 0x1f6fa0, Func Offset: 0x80
	// Line 4582, Address: 0x1f6fa8, Func Offset: 0x88
	// Line 4583, Address: 0x1f6fdc, Func Offset: 0xbc
	// Line 4584, Address: 0x1f6fe4, Func Offset: 0xc4
	// Line 4590, Address: 0x1f6fe8, Func Offset: 0xc8
	// Line 4584, Address: 0x1f6fec, Func Offset: 0xcc
	// Line 4587, Address: 0x1f6ff0, Func Offset: 0xd0
	// Line 4588, Address: 0x1f7010, Func Offset: 0xf0
	// Line 4589, Address: 0x1f7018, Func Offset: 0xf8
	// Line 4590, Address: 0x1f7020, Func Offset: 0x100
	// Line 4591, Address: 0x1f7038, Func Offset: 0x118
	// Line 4592, Address: 0x1f7050, Func Offset: 0x130
	// Line 4595, Address: 0x1f705c, Func Offset: 0x13c
	// Line 4598, Address: 0x1f7068, Func Offset: 0x148
	// Line 4599, Address: 0x1f706c, Func Offset: 0x14c
	// Func End, Address: 0x1f7084, Func Offset: 0x164
	scePrintf("bhEne_PlyActionChange - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f7090
static int bhEne_CalcCombRate(BH_PWORK* ewP, COMBWEP_WORK* cwP)
{
	int cmb_lvl;
	// Line 4617, Address: 0x1f7090, Func Offset: 0
	// Line 4625, Address: 0x1f70a4, Func Offset: 0x14
	// Line 4627, Address: 0x1f70d4, Func Offset: 0x44
	// Line 4630, Address: 0x1f70e8, Func Offset: 0x58
	// Func End, Address: 0x1f70f0, Func Offset: 0x60
	scePrintf("bhEne_CalcCombRate - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f70f0
static TY_DMG_MODE bhEne19_CheckDmgLvl0(BH_PWORK* ewP, FW_WORK* fwP)
{
	int* flgP;
	int cmb_lvl;
	TY_DMG_MODE dmg_lvl;
	// Line 4640, Address: 0x1f70f0, Func Offset: 0
	// Line 4645, Address: 0x1f70f8, Func Offset: 0x8
	// Line 4640, Address: 0x1f7100, Func Offset: 0x10
	// Line 4645, Address: 0x1f7104, Func Offset: 0x14
	// Line 4648, Address: 0x1f710c, Func Offset: 0x1c
	// Line 4650, Address: 0x1f7128, Func Offset: 0x38
	// Line 4652, Address: 0x1f7134, Func Offset: 0x44
	// Line 4653, Address: 0x1f713c, Func Offset: 0x4c
	// Line 4655, Address: 0x1f714c, Func Offset: 0x5c
	// Line 4656, Address: 0x1f7154, Func Offset: 0x64
	// Line 4657, Address: 0x1f7170, Func Offset: 0x80
	// Line 4658, Address: 0x1f7174, Func Offset: 0x84
	// Line 4657, Address: 0x1f7178, Func Offset: 0x88
	// Line 4659, Address: 0x1f717c, Func Offset: 0x8c
	// Line 4660, Address: 0x1f7184, Func Offset: 0x94
	// Line 4661, Address: 0x1f71a0, Func Offset: 0xb0
	// Line 4662, Address: 0x1f71a4, Func Offset: 0xb4
	// Line 4661, Address: 0x1f71a8, Func Offset: 0xb8
	// Line 4663, Address: 0x1f71ac, Func Offset: 0xbc
	// Line 4664, Address: 0x1f71b4, Func Offset: 0xc4
	// Line 4668, Address: 0x1f71b8, Func Offset: 0xc8
	// Func End, Address: 0x1f71c4, Func Offset: 0xd4
	scePrintf("bhEne19_CheckDmgLvl0 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f71d0
static TY_DMG_MODE bhEne19_CheckDmgLvl1(BH_PWORK* ewP, FW_WORK* fwP)
{
	TY_DMG_MODE dmg_lvl;
	// Line 4678, Address: 0x1f71d0, Func Offset: 0
	// Line 4682, Address: 0x1f71d8, Func Offset: 0x8
	// Line 4678, Address: 0x1f71dc, Func Offset: 0xc
	// Line 4682, Address: 0x1f71e0, Func Offset: 0x10
	// Line 4684, Address: 0x1f71e8, Func Offset: 0x18
	// Line 4685, Address: 0x1f7204, Func Offset: 0x34
	// Line 4687, Address: 0x1f720c, Func Offset: 0x3c
	// Line 4688, Address: 0x1f7214, Func Offset: 0x44
	// Line 4689, Address: 0x1f726c, Func Offset: 0x9c
	// Line 4691, Address: 0x1f7274, Func Offset: 0xa4
	// Line 4692, Address: 0x1f727c, Func Offset: 0xac
	// Line 4693, Address: 0x1f7294, Func Offset: 0xc4
	// Line 4696, Address: 0x1f7298, Func Offset: 0xc8
	// Line 4697, Address: 0x1f72b4, Func Offset: 0xe4
	// Line 4698, Address: 0x1f72bc, Func Offset: 0xec
	// Line 4702, Address: 0x1f72c0, Func Offset: 0xf0
	// Func End, Address: 0x1f72cc, Func Offset: 0xfc
	scePrintf("bhEne19_CheckDmgLvl1 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f72d0
static TY_DMG_MODE bhEne19_CheckDmgLvl2(BH_PWORK* ewP, FW_WORK* fwP)
{
	int* flgP;
	int cmb_lvl;
	TY_DMG_MODE dmg_lvl;
	// Line 4712, Address: 0x1f72d0, Func Offset: 0
	// Line 4717, Address: 0x1f72d8, Func Offset: 0x8
	// Line 4712, Address: 0x1f72e0, Func Offset: 0x10
	// Line 4717, Address: 0x1f72e4, Func Offset: 0x14
	// Line 4720, Address: 0x1f72ec, Func Offset: 0x1c
	// Line 4722, Address: 0x1f7308, Func Offset: 0x38
	// Line 4724, Address: 0x1f7314, Func Offset: 0x44
	// Line 4725, Address: 0x1f731c, Func Offset: 0x4c
	// Line 4727, Address: 0x1f732c, Func Offset: 0x5c
	// Line 4728, Address: 0x1f7334, Func Offset: 0x64
	// Line 4729, Address: 0x1f7350, Func Offset: 0x80
	// Line 4730, Address: 0x1f7354, Func Offset: 0x84
	// Line 4729, Address: 0x1f7358, Func Offset: 0x88
	// Line 4731, Address: 0x1f735c, Func Offset: 0x8c
	// Line 4732, Address: 0x1f7364, Func Offset: 0x94
	// Line 4736, Address: 0x1f7368, Func Offset: 0x98
	// Func End, Address: 0x1f7374, Func Offset: 0xa4
	scePrintf("bhEne19_CheckDmgLvl2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f7380
static R0_WK* bhEne19_SetLeftClaw(ML_WORK* mlwP, TY_OBJ_MODE tgt_bas, TY_OBJ_MODE tgt_obj)
{
	NJS_CNK_OBJECT* objP;
	PRM_WRK prm;
	// Line 4750, Address: 0x1f7380, Func Offset: 0
	// Line 4746, Address: 0x1f7388, Func Offset: 0x8
	// Line 4750, Address: 0x1f738c, Func Offset: 0xc
	// Line 4746, Address: 0x1f7394, Func Offset: 0x14
	// Line 4750, Address: 0x1f7398, Func Offset: 0x18
	// Line 4751, Address: 0x1f739c, Func Offset: 0x1c
	// Line 4750, Address: 0x1f73a4, Func Offset: 0x24
	// Line 4751, Address: 0x1f73a8, Func Offset: 0x28
	// Line 4757, Address: 0x1f73b0, Func Offset: 0x30
	// Line 4750, Address: 0x1f73b4, Func Offset: 0x34
	// Line 4751, Address: 0x1f73b8, Func Offset: 0x38
	// Line 4752, Address: 0x1f73c4, Func Offset: 0x44
	// Line 4755, Address: 0x1f73c8, Func Offset: 0x48
	// Line 4757, Address: 0x1f73cc, Func Offset: 0x4c
	// Line 4752, Address: 0x1f73d0, Func Offset: 0x50
	// Line 4753, Address: 0x1f73d4, Func Offset: 0x54
	// Line 4757, Address: 0x1f73d8, Func Offset: 0x58
	// Line 4753, Address: 0x1f73dc, Func Offset: 0x5c
	// Line 4754, Address: 0x1f73e0, Func Offset: 0x60
	// Line 4755, Address: 0x1f73fc, Func Offset: 0x7c
	// Line 4757, Address: 0x1f7418, Func Offset: 0x98
	// Line 4758, Address: 0x1f7420, Func Offset: 0xa0
	// Line 4757, Address: 0x1f7424, Func Offset: 0xa4
	// Line 4758, Address: 0x1f7428, Func Offset: 0xa8
	// Func End, Address: 0x1f7430, Func Offset: 0xb0
	scePrintf("bhEne19_SetLeftClaw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1f7430
static void bhEne19_SetClawPlane(BH_PWORK* ewP, NJS_MATRIX* mtxP, int col, int tim, float src_x, float dst_x)
{
	EFFPRM_WORK Dat307;
	// Line 4768, Address: 0x1f7430, Func Offset: 0
	// Line 4771, Address: 0x1f7438, Func Offset: 0x8
	// Line 4772, Address: 0x1f743c, Func Offset: 0xc
	// Line 4773, Address: 0x1f7444, Func Offset: 0x14
	// Line 4774, Address: 0x1f7448, Func Offset: 0x18
	// Line 4775, Address: 0x1f7450, Func Offset: 0x20
	// Line 4776, Address: 0x1f7458, Func Offset: 0x28
	// Line 4777, Address: 0x1f745c, Func Offset: 0x2c
	// Line 4778, Address: 0x1f7460, Func Offset: 0x30
	// Line 4777, Address: 0x1f7464, Func Offset: 0x34
	// Line 4782, Address: 0x1f7468, Func Offset: 0x38
	// Line 4777, Address: 0x1f746c, Func Offset: 0x3c
	// Line 4778, Address: 0x1f7470, Func Offset: 0x40
	// Line 4779, Address: 0x1f7474, Func Offset: 0x44
	// Line 4780, Address: 0x1f7478, Func Offset: 0x48
	// Line 4782, Address: 0x1f747c, Func Offset: 0x4c
	// Line 4783, Address: 0x1f7488, Func Offset: 0x58
	// Func End, Address: 0x1f7494, Func Offset: 0x64
	scePrintf("bhEne19_SetClawPlane - UNIMPLEMENTED!\n");
}
