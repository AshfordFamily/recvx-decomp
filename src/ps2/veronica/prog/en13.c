#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"

// ENEMY: Second Form Alexia 

static EGG_WORK ene18 = 
{
    0x8081, 18, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};

static EGG_WORK ene13B = 
{
    0x8081, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};

void (*bhEne13_Mode0[6])(BH_PWORK*) = 
{
	bhEne13_Init,
	bhEne13_Move,
	bhEne13_Nage,
	bhEne13_Damage,
	bhEne13_Die,
	bhEne_Event
};       

void (*bhEne13_BrainType[2])(BH_PWORK*) = 
{
	bhEne13_BR00,
	bhEne13_BR01
};

void (*bhEne13_MoveMode2[4])(BH_PWORK*) = 
{
	bhEne13_MV00,
	bhEne13_MV01,
	bhEne13_MV02,
	bhEne13_MV03
};   

void (*bhEne13_DamageMode2[1])(BH_PWORK*) = 
{
	bhEne13_DG00
}; 

void bhEne13(BH_PWORK* epw) 
{
    bhEne13_Mode0[epw->mode0](epw);
    bhSetMotion(epw, epw->mtn_add, (int)epw->mtn_md, epw->mtn_tp);
    bhCalcModel(epw);
    bhEne13_CameraControl(epw);
    bhEne13_PlayerControl(epw);
}

// 
// Start address: 0x1da3b0
void bhEne13_Init(BH_PWORK* epw)
{
	int i;
	BH_PWORK* ep;
	// Line 229, Address: 0x1da3b0, Func Offset: 0
	// Line 234, Address: 0x1da3c4, Func Offset: 0x14
	// Line 235, Address: 0x1da3c8, Func Offset: 0x18
	// Line 238, Address: 0x1da3cc, Func Offset: 0x1c
	// Line 239, Address: 0x1da3d0, Func Offset: 0x20
	// Line 240, Address: 0x1da3d4, Func Offset: 0x24
	// Line 234, Address: 0x1da3d8, Func Offset: 0x28
	// Line 235, Address: 0x1da3e0, Func Offset: 0x30
	// Line 241, Address: 0x1da3e4, Func Offset: 0x34
	// Line 235, Address: 0x1da3ec, Func Offset: 0x3c
	// Line 236, Address: 0x1da3f4, Func Offset: 0x44
	// Line 237, Address: 0x1da400, Func Offset: 0x50
	// Line 238, Address: 0x1da40c, Func Offset: 0x5c
	// Line 239, Address: 0x1da410, Func Offset: 0x60
	// Line 240, Address: 0x1da414, Func Offset: 0x64
	// Line 241, Address: 0x1da418, Func Offset: 0x68
	// Line 244, Address: 0x1da438, Func Offset: 0x88
	// Line 245, Address: 0x1da440, Func Offset: 0x90
	// Line 246, Address: 0x1da444, Func Offset: 0x94
	// Line 247, Address: 0x1da448, Func Offset: 0x98
	// Line 250, Address: 0x1da44c, Func Offset: 0x9c
	// Line 251, Address: 0x1da454, Func Offset: 0xa4
	// Line 252, Address: 0x1da458, Func Offset: 0xa8
	// Line 253, Address: 0x1da45c, Func Offset: 0xac
	// Line 254, Address: 0x1da460, Func Offset: 0xb0
	// Line 255, Address: 0x1da464, Func Offset: 0xb4
	// Line 258, Address: 0x1da468, Func Offset: 0xb8
	// Line 259, Address: 0x1da474, Func Offset: 0xc4
	// Line 262, Address: 0x1da484, Func Offset: 0xd4
	// Line 263, Address: 0x1da4a0, Func Offset: 0xf0
	// Line 269, Address: 0x1da4a4, Func Offset: 0xf4
	// Line 272, Address: 0x1da4a8, Func Offset: 0xf8
	// Line 262, Address: 0x1da4ac, Func Offset: 0xfc
	// Line 263, Address: 0x1da4b0, Func Offset: 0x100
	// Line 272, Address: 0x1da4b4, Func Offset: 0x104
	// Line 263, Address: 0x1da4b8, Func Offset: 0x108
	// Line 264, Address: 0x1da4c0, Func Offset: 0x110
	// Line 265, Address: 0x1da4cc, Func Offset: 0x11c
	// Line 266, Address: 0x1da4d8, Func Offset: 0x128
	// Line 267, Address: 0x1da4e4, Func Offset: 0x134
	// Line 268, Address: 0x1da4f0, Func Offset: 0x140
	// Line 269, Address: 0x1da4fc, Func Offset: 0x14c
	// Line 272, Address: 0x1da508, Func Offset: 0x158
	// Line 273, Address: 0x1da51c, Func Offset: 0x16c
	// Line 279, Address: 0x1da520, Func Offset: 0x170
	// Line 282, Address: 0x1da524, Func Offset: 0x174
	// Line 272, Address: 0x1da528, Func Offset: 0x178
	// Line 273, Address: 0x1da52c, Func Offset: 0x17c
	// Line 282, Address: 0x1da530, Func Offset: 0x180
	// Line 273, Address: 0x1da534, Func Offset: 0x184
	// Line 274, Address: 0x1da53c, Func Offset: 0x18c
	// Line 275, Address: 0x1da548, Func Offset: 0x198
	// Line 276, Address: 0x1da554, Func Offset: 0x1a4
	// Line 277, Address: 0x1da560, Func Offset: 0x1b0
	// Line 278, Address: 0x1da56c, Func Offset: 0x1bc
	// Line 279, Address: 0x1da578, Func Offset: 0x1c8
	// Line 282, Address: 0x1da584, Func Offset: 0x1d4
	// Line 283, Address: 0x1da598, Func Offset: 0x1e8
	// Line 289, Address: 0x1da59c, Func Offset: 0x1ec
	// Line 292, Address: 0x1da5a0, Func Offset: 0x1f0
	// Line 282, Address: 0x1da5a4, Func Offset: 0x1f4
	// Line 283, Address: 0x1da5a8, Func Offset: 0x1f8
	// Line 292, Address: 0x1da5ac, Func Offset: 0x1fc
	// Line 283, Address: 0x1da5b0, Func Offset: 0x200
	// Line 284, Address: 0x1da5b8, Func Offset: 0x208
	// Line 285, Address: 0x1da5c4, Func Offset: 0x214
	// Line 286, Address: 0x1da5d0, Func Offset: 0x220
	// Line 287, Address: 0x1da5dc, Func Offset: 0x22c
	// Line 288, Address: 0x1da5e8, Func Offset: 0x238
	// Line 289, Address: 0x1da5f4, Func Offset: 0x244
	// Line 292, Address: 0x1da600, Func Offset: 0x250
	// Line 299, Address: 0x1da614, Func Offset: 0x264
	// Line 308, Address: 0x1da618, Func Offset: 0x268
	// Line 292, Address: 0x1da620, Func Offset: 0x270
	// Line 293, Address: 0x1da624, Func Offset: 0x274
	// Line 294, Address: 0x1da630, Func Offset: 0x280
	// Line 295, Address: 0x1da63c, Func Offset: 0x28c
	// Line 296, Address: 0x1da648, Func Offset: 0x298
	// Line 297, Address: 0x1da654, Func Offset: 0x2a4
	// Line 298, Address: 0x1da660, Func Offset: 0x2b0
	// Line 299, Address: 0x1da66c, Func Offset: 0x2bc
	// Line 302, Address: 0x1da678, Func Offset: 0x2c8
	// Line 303, Address: 0x1da68c, Func Offset: 0x2dc
	// Line 304, Address: 0x1da6a0, Func Offset: 0x2f0
	// Line 305, Address: 0x1da6b4, Func Offset: 0x304
	// Line 309, Address: 0x1da6c8, Func Offset: 0x318
	// Line 310, Address: 0x1da6e4, Func Offset: 0x334
	// Line 317, Address: 0x1da6e8, Func Offset: 0x338
	// Line 316, Address: 0x1da6ec, Func Offset: 0x33c
	// Line 309, Address: 0x1da6f0, Func Offset: 0x340
	// Line 310, Address: 0x1da6f8, Func Offset: 0x348
	// Line 317, Address: 0x1da6fc, Func Offset: 0x34c
	// Line 310, Address: 0x1da700, Func Offset: 0x350
	// Line 311, Address: 0x1da70c, Func Offset: 0x35c
	// Line 312, Address: 0x1da71c, Func Offset: 0x36c
	// Line 313, Address: 0x1da72c, Func Offset: 0x37c
	// Line 314, Address: 0x1da73c, Func Offset: 0x38c
	// Line 315, Address: 0x1da74c, Func Offset: 0x39c
	// Line 316, Address: 0x1da75c, Func Offset: 0x3ac
	// Line 317, Address: 0x1da76c, Func Offset: 0x3bc
	// Line 321, Address: 0x1da774, Func Offset: 0x3c4
	// Line 335, Address: 0x1da790, Func Offset: 0x3e0
	// Line 328, Address: 0x1da794, Func Offset: 0x3e4
	// Line 335, Address: 0x1da798, Func Offset: 0x3e8
	// Line 321, Address: 0x1da79c, Func Offset: 0x3ec
	// Line 322, Address: 0x1da7a0, Func Offset: 0x3f0
	// Line 335, Address: 0x1da7a4, Func Offset: 0x3f4
	// Line 322, Address: 0x1da7a8, Func Offset: 0x3f8
	// Line 323, Address: 0x1da7b0, Func Offset: 0x400
	// Line 324, Address: 0x1da7bc, Func Offset: 0x40c
	// Line 325, Address: 0x1da7c8, Func Offset: 0x418
	// Line 326, Address: 0x1da7d4, Func Offset: 0x424
	// Line 327, Address: 0x1da7e0, Func Offset: 0x430
	// Line 328, Address: 0x1da7ec, Func Offset: 0x43c
	// Line 329, Address: 0x1da7f8, Func Offset: 0x448
	// Line 330, Address: 0x1da808, Func Offset: 0x458
	// Line 331, Address: 0x1da814, Func Offset: 0x464
	// Line 332, Address: 0x1da824, Func Offset: 0x474
	// Line 335, Address: 0x1da830, Func Offset: 0x480
	// Line 339, Address: 0x1da838, Func Offset: 0x488
	// Line 340, Address: 0x1da83c, Func Offset: 0x48c
	// Line 339, Address: 0x1da840, Func Offset: 0x490
	// Line 340, Address: 0x1da844, Func Offset: 0x494
	// Line 341, Address: 0x1da860, Func Offset: 0x4b0
	// Line 342, Address: 0x1da880, Func Offset: 0x4d0
	// Line 343, Address: 0x1da8a0, Func Offset: 0x4f0
	// Line 344, Address: 0x1da8c0, Func Offset: 0x510
	// Line 350, Address: 0x1da8d8, Func Offset: 0x528
	// Line 354, Address: 0x1da8dc, Func Offset: 0x52c
	// Line 350, Address: 0x1da8e0, Func Offset: 0x530
	// Line 351, Address: 0x1da8f0, Func Offset: 0x540
	// Line 352, Address: 0x1da904, Func Offset: 0x554
	// Line 353, Address: 0x1da918, Func Offset: 0x568
	// Line 354, Address: 0x1da92c, Func Offset: 0x57c
	// Line 355, Address: 0x1da940, Func Offset: 0x590
	// Line 356, Address: 0x1da958, Func Offset: 0x5a8
	// Line 357, Address: 0x1da970, Func Offset: 0x5c0
	// Line 358, Address: 0x1da988, Func Offset: 0x5d8
	// Line 360, Address: 0x1da9a0, Func Offset: 0x5f0
	// Line 361, Address: 0x1da9a4, Func Offset: 0x5f4
	// Line 362, Address: 0x1da9ac, Func Offset: 0x5fc
	// Line 360, Address: 0x1da9b0, Func Offset: 0x600
	// Line 362, Address: 0x1da9b4, Func Offset: 0x604
	// Line 364, Address: 0x1da9c0, Func Offset: 0x610
	// Line 365, Address: 0x1da9dc, Func Offset: 0x62c
	// Line 366, Address: 0x1da9f0, Func Offset: 0x640
	// Line 368, Address: 0x1daa00, Func Offset: 0x650
	// Line 369, Address: 0x1daa04, Func Offset: 0x654
	// Line 372, Address: 0x1daa08, Func Offset: 0x658
	// Line 373, Address: 0x1daa24, Func Offset: 0x674
	// Line 374, Address: 0x1daa2c, Func Offset: 0x67c
	// Line 376, Address: 0x1daa30, Func Offset: 0x680
	// Line 379, Address: 0x1daa58, Func Offset: 0x6a8
	// Line 380, Address: 0x1daa60, Func Offset: 0x6b0
	// Line 381, Address: 0x1daa64, Func Offset: 0x6b4
	// Line 379, Address: 0x1daa68, Func Offset: 0x6b8
	// Line 380, Address: 0x1daa6c, Func Offset: 0x6bc
	// Line 382, Address: 0x1daa70, Func Offset: 0x6c0
	// Line 380, Address: 0x1daa74, Func Offset: 0x6c4
	// Line 381, Address: 0x1daa78, Func Offset: 0x6c8
	// Line 382, Address: 0x1daa80, Func Offset: 0x6d0
	// Line 383, Address: 0x1daa98, Func Offset: 0x6e8
	// Func End, Address: 0x1daab0, Func Offset: 0x700
	scePrintf("bhEne13_Init - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1daab0
void bhEne13_Brain(BH_PWORK* epw)
{
	scePrintf("bhEne13_Brain - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1daad0
void bhEne13_BR00(BH_PWORK* epw)
{
	float dist;
	int j;
	int i;
	BH_PWORK* ep;
	// Line 405, Address: 0x1daad0, Func Offset: 0
	// Line 411, Address: 0x1daadc, Func Offset: 0xc
	// Line 414, Address: 0x1daae8, Func Offset: 0x18
	// Line 417, Address: 0x1dab14, Func Offset: 0x44
	// Line 418, Address: 0x1dab34, Func Offset: 0x64
	// Line 419, Address: 0x1dab54, Func Offset: 0x84
	// Line 422, Address: 0x1dab74, Func Offset: 0xa4
	// Line 424, Address: 0x1daba0, Func Offset: 0xd0
	// Line 423, Address: 0x1daba4, Func Offset: 0xd4
	// Line 424, Address: 0x1daba8, Func Offset: 0xd8
	// Line 428, Address: 0x1dabac, Func Offset: 0xdc
	// Line 429, Address: 0x1dabc8, Func Offset: 0xf8
	// Line 430, Address: 0x1dabd0, Func Offset: 0x100
	// Line 431, Address: 0x1dabd8, Func Offset: 0x108
	// Line 433, Address: 0x1dabe4, Func Offset: 0x114
	// Line 437, Address: 0x1dabec, Func Offset: 0x11c
	// Line 438, Address: 0x1dac08, Func Offset: 0x138
	// Line 444, Address: 0x1dac64, Func Offset: 0x194
	// Line 445, Address: 0x1dac6c, Func Offset: 0x19c
	// Line 447, Address: 0x1dac88, Func Offset: 0x1b8
	// Line 449, Address: 0x1dacd0, Func Offset: 0x200
	// Line 450, Address: 0x1dacd8, Func Offset: 0x208
	// Line 452, Address: 0x1dace0, Func Offset: 0x210
	// Line 455, Address: 0x1dacf0, Func Offset: 0x220
	// Line 454, Address: 0x1dacf4, Func Offset: 0x224
	// Line 455, Address: 0x1dacf8, Func Offset: 0x228
	// Line 456, Address: 0x1dacfc, Func Offset: 0x22c
	// Line 457, Address: 0x1dad00, Func Offset: 0x230
	// Line 459, Address: 0x1dad0c, Func Offset: 0x23c
	// Line 460, Address: 0x1dad20, Func Offset: 0x250
	// Line 461, Address: 0x1dad28, Func Offset: 0x258
	// Line 462, Address: 0x1dad30, Func Offset: 0x260
	// Line 464, Address: 0x1dad34, Func Offset: 0x264
	// Line 470, Address: 0x1dad3c, Func Offset: 0x26c
	// Line 472, Address: 0x1dad4c, Func Offset: 0x27c
	// Line 473, Address: 0x1dad88, Func Offset: 0x2b8
	// Line 472, Address: 0x1dad90, Func Offset: 0x2c0
	// Line 474, Address: 0x1dad94, Func Offset: 0x2c4
	// Line 473, Address: 0x1dad98, Func Offset: 0x2c8
	// Line 475, Address: 0x1dad9c, Func Offset: 0x2cc
	// Line 477, Address: 0x1dadb8, Func Offset: 0x2e8
	// Line 479, Address: 0x1dadc0, Func Offset: 0x2f0
	// Line 480, Address: 0x1dadc4, Func Offset: 0x2f4
	// Line 481, Address: 0x1dadd8, Func Offset: 0x308
	// Line 482, Address: 0x1dade8, Func Offset: 0x318
	// Line 483, Address: 0x1dadfc, Func Offset: 0x32c
	// Line 484, Address: 0x1dae10, Func Offset: 0x340
	// Line 485, Address: 0x1dae18, Func Offset: 0x348
	// Line 487, Address: 0x1dae30, Func Offset: 0x360
	// Line 488, Address: 0x1dae34, Func Offset: 0x364
	// Line 489, Address: 0x1dae38, Func Offset: 0x368
	// Line 491, Address: 0x1dae3c, Func Offset: 0x36c
	// Line 492, Address: 0x1dae44, Func Offset: 0x374
	// Line 494, Address: 0x1dae50, Func Offset: 0x380
	// Line 496, Address: 0x1dae64, Func Offset: 0x394
	// Line 497, Address: 0x1dae68, Func Offset: 0x398
	// Func End, Address: 0x1dae78, Func Offset: 0x3a8
	scePrintf("bhEne13_BR00 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dae80
void bhEne13_BR01(BH_PWORK* epw)
{
	float dist;
	int j;
	// Line 507, Address: 0x1dae80, Func Offset: 0
	// Line 513, Address: 0x1dae8c, Func Offset: 0xc
	// Line 516, Address: 0x1dae98, Func Offset: 0x18
	// Line 519, Address: 0x1daec4, Func Offset: 0x44
	// Line 520, Address: 0x1daee4, Func Offset: 0x64
	// Line 523, Address: 0x1daf04, Func Offset: 0x84
	// Line 524, Address: 0x1daf2c, Func Offset: 0xac
	// Line 525, Address: 0x1daf30, Func Offset: 0xb0
	// Line 526, Address: 0x1daf34, Func Offset: 0xb4
	// Line 528, Address: 0x1daf38, Func Offset: 0xb8
	// Line 529, Address: 0x1daf40, Func Offset: 0xc0
	// Line 533, Address: 0x1daf48, Func Offset: 0xc8
	// Line 539, Address: 0x1dafa0, Func Offset: 0x120
	// Line 540, Address: 0x1dafa8, Func Offset: 0x128
	// Line 542, Address: 0x1dafc4, Func Offset: 0x144
	// Line 544, Address: 0x1db00c, Func Offset: 0x18c
	// Line 545, Address: 0x1db014, Func Offset: 0x194
	// Line 547, Address: 0x1db01c, Func Offset: 0x19c
	// Line 550, Address: 0x1db02c, Func Offset: 0x1ac
	// Line 549, Address: 0x1db030, Func Offset: 0x1b0
	// Line 550, Address: 0x1db034, Func Offset: 0x1b4
	// Line 551, Address: 0x1db038, Func Offset: 0x1b8
	// Line 552, Address: 0x1db03c, Func Offset: 0x1bc
	// Line 554, Address: 0x1db048, Func Offset: 0x1c8
	// Line 555, Address: 0x1db05c, Func Offset: 0x1dc
	// Line 556, Address: 0x1db064, Func Offset: 0x1e4
	// Line 557, Address: 0x1db06c, Func Offset: 0x1ec
	// Line 562, Address: 0x1db070, Func Offset: 0x1f0
	// Func End, Address: 0x1db080, Func Offset: 0x200
	scePrintf("bhEne13_BR01 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db080
void bhEne13_Move(BH_PWORK* epw)
{
	// Line 572, Address: 0x1db080, Func Offset: 0
	// Line 574, Address: 0x1db08c, Func Offset: 0xc
	// Line 575, Address: 0x1db09c, Func Offset: 0x1c
	// Line 579, Address: 0x1db0a4, Func Offset: 0x24
	// Line 582, Address: 0x1db0c4, Func Offset: 0x44
	// Line 589, Address: 0x1db168, Func Offset: 0xe8
	// Line 591, Address: 0x1db174, Func Offset: 0xf4
	// Func End, Address: 0x1db184, Func Offset: 0x104
	scePrintf("bhEne13_Move - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db190
void bhEne13_MV00(BH_PWORK* epw)
{
	// Line 602, Address: 0x1db190, Func Offset: 0
	// Line 604, Address: 0x1db1a4, Func Offset: 0x14
	// Line 606, Address: 0x1db1a8, Func Offset: 0x18
	// Line 605, Address: 0x1db1ac, Func Offset: 0x1c
	// Line 606, Address: 0x1db1b0, Func Offset: 0x20
	// Line 607, Address: 0x1db1b4, Func Offset: 0x24
	// Line 608, Address: 0x1db1bc, Func Offset: 0x2c
	// Line 610, Address: 0x1db1c8, Func Offset: 0x38
	// Func End, Address: 0x1db1d0, Func Offset: 0x40
	scePrintf("bhEne13_MV00 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db1d0
void bhEne13_MV01(BH_PWORK* epw)
{
	BH_PWORK* ep;
	// Line 623, Address: 0x1db1d0, Func Offset: 0
	// Line 626, Address: 0x1db1f0, Func Offset: 0x20
	// Line 628, Address: 0x1db1f4, Func Offset: 0x24
	// Line 627, Address: 0x1db1f8, Func Offset: 0x28
	// Line 628, Address: 0x1db1fc, Func Offset: 0x2c
	// Line 629, Address: 0x1db200, Func Offset: 0x30
	// Line 632, Address: 0x1db208, Func Offset: 0x38
	// Line 633, Address: 0x1db21c, Func Offset: 0x4c
	// Line 634, Address: 0x1db220, Func Offset: 0x50
	// Line 637, Address: 0x1db22c, Func Offset: 0x5c
	// Line 638, Address: 0x1db234, Func Offset: 0x64
	// Line 639, Address: 0x1db23c, Func Offset: 0x6c
	// Line 641, Address: 0x1db244, Func Offset: 0x74
	// Line 643, Address: 0x1db250, Func Offset: 0x80
	// Line 644, Address: 0x1db254, Func Offset: 0x84
	// Line 645, Address: 0x1db258, Func Offset: 0x88
	// Line 647, Address: 0x1db25c, Func Offset: 0x8c
	// Line 649, Address: 0x1db26c, Func Offset: 0x9c
	// Line 650, Address: 0x1db270, Func Offset: 0xa0
	// Line 649, Address: 0x1db274, Func Offset: 0xa4
	// Line 650, Address: 0x1db294, Func Offset: 0xc4
	// Line 651, Address: 0x1db298, Func Offset: 0xc8
	// Line 655, Address: 0x1db29c, Func Offset: 0xcc
	// Func End, Address: 0x1db2a4, Func Offset: 0xd4
	scePrintf("bhEne13_MV01 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db2b0
void bhEne13_MV02(BH_PWORK* epw)
{
	// Line 666, Address: 0x1db2b0, Func Offset: 0
	// Line 668, Address: 0x1db2d0, Func Offset: 0x20
	// Line 670, Address: 0x1db2d8, Func Offset: 0x28
	// Line 669, Address: 0x1db2dc, Func Offset: 0x2c
	// Line 670, Address: 0x1db2e0, Func Offset: 0x30
	// Line 671, Address: 0x1db2e4, Func Offset: 0x34
	// Line 674, Address: 0x1db2ec, Func Offset: 0x3c
	// Line 675, Address: 0x1db300, Func Offset: 0x50
	// Line 676, Address: 0x1db304, Func Offset: 0x54
	// Line 679, Address: 0x1db310, Func Offset: 0x60
	// Line 680, Address: 0x1db334, Func Offset: 0x84
	// Line 681, Address: 0x1db33c, Func Offset: 0x8c
	// Line 683, Address: 0x1db344, Func Offset: 0x94
	// Line 685, Address: 0x1db354, Func Offset: 0xa4
	// Line 686, Address: 0x1db358, Func Offset: 0xa8
	// Line 687, Address: 0x1db35c, Func Offset: 0xac
	// Line 692, Address: 0x1db360, Func Offset: 0xb0
	// Func End, Address: 0x1db368, Func Offset: 0xb8
	scePrintf("bhEne13_MV02 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db370
void bhEne13_MV03(BH_PWORK* epw)
{
	BH_PWORK* ep;
	// Line 705, Address: 0x1db370, Func Offset: 0
	// Line 708, Address: 0x1db390, Func Offset: 0x20
	// Line 710, Address: 0x1db394, Func Offset: 0x24
	// Line 709, Address: 0x1db398, Func Offset: 0x28
	// Line 710, Address: 0x1db39c, Func Offset: 0x2c
	// Line 711, Address: 0x1db3a0, Func Offset: 0x30
	// Line 714, Address: 0x1db3a8, Func Offset: 0x38
	// Line 715, Address: 0x1db3bc, Func Offset: 0x4c
	// Line 716, Address: 0x1db3c0, Func Offset: 0x50
	// Line 719, Address: 0x1db3cc, Func Offset: 0x5c
	// Line 720, Address: 0x1db3d4, Func Offset: 0x64
	// Line 721, Address: 0x1db3dc, Func Offset: 0x6c
	// Line 723, Address: 0x1db3e4, Func Offset: 0x74
	// Line 725, Address: 0x1db3f0, Func Offset: 0x80
	// Line 726, Address: 0x1db3f4, Func Offset: 0x84
	// Line 727, Address: 0x1db3f8, Func Offset: 0x88
	// Line 729, Address: 0x1db3fc, Func Offset: 0x8c
	// Line 731, Address: 0x1db40c, Func Offset: 0x9c
	// Line 732, Address: 0x1db430, Func Offset: 0xc0
	// Line 733, Address: 0x1db434, Func Offset: 0xc4
	// Line 735, Address: 0x1db448, Func Offset: 0xd8
	// Line 736, Address: 0x1db44c, Func Offset: 0xdc
	// Line 738, Address: 0x1db454, Func Offset: 0xe4
	// Line 743, Address: 0x1db45c, Func Offset: 0xec
	// Func End, Address: 0x1db464, Func Offset: 0xf4
	scePrintf("bhEne13_MV03 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db470
void bhEne13_Nage()
{
	// Line 754, Address: 0x1db470, Func Offset: 0
	// Func End, Address: 0x1db478, Func Offset: 0x8
	scePrintf("bhEne13_Nage - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db480
void bhEne13_Damage(BH_PWORK* epw)
{
	int max_dam;
	int i;
	int dam;
	// Line 764, Address: 0x1db480, Func Offset: 0
	// Line 768, Address: 0x1db498, Func Offset: 0x18
	// Line 776, Address: 0x1db53c, Func Offset: 0xbc
	// Line 779, Address: 0x1db540, Func Offset: 0xc0
	// Line 780, Address: 0x1db548, Func Offset: 0xc8
	// Line 781, Address: 0x1db564, Func Offset: 0xe4
	// Line 787, Address: 0x1db570, Func Offset: 0xf0
	// Line 788, Address: 0x1db580, Func Offset: 0x100
	// Line 789, Address: 0x1db58c, Func Offset: 0x10c
	// Line 792, Address: 0x1db590, Func Offset: 0x110
	// Line 794, Address: 0x1db5a0, Func Offset: 0x120
	// Line 795, Address: 0x1db5c4, Func Offset: 0x144
	// Line 796, Address: 0x1db5d0, Func Offset: 0x150
	// Line 797, Address: 0x1db5dc, Func Offset: 0x15c
	// Line 798, Address: 0x1db5e8, Func Offset: 0x168
	// Line 806, Address: 0x1db5ec, Func Offset: 0x16c
	// Line 809, Address: 0x1db5f8, Func Offset: 0x178
	// Line 810, Address: 0x1db618, Func Offset: 0x198
	// Func End, Address: 0x1db634, Func Offset: 0x1b4
	scePrintf("bhEne13_Damage - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db640
void bhEne13_DG00(BH_PWORK* epw)
{
	// Line 821, Address: 0x1db640, Func Offset: 0
	// Line 823, Address: 0x1db660, Func Offset: 0x20
	// Line 825, Address: 0x1db668, Func Offset: 0x28
	// Line 824, Address: 0x1db66c, Func Offset: 0x2c
	// Line 825, Address: 0x1db670, Func Offset: 0x30
	// Line 826, Address: 0x1db674, Func Offset: 0x34
	// Line 827, Address: 0x1db67c, Func Offset: 0x3c
	// Line 828, Address: 0x1db6a0, Func Offset: 0x60
	// Line 830, Address: 0x1db6ac, Func Offset: 0x6c
	// Line 831, Address: 0x1db6bc, Func Offset: 0x7c
	// Line 832, Address: 0x1db6c4, Func Offset: 0x84
	// Line 833, Address: 0x1db6c8, Func Offset: 0x88
	// Line 834, Address: 0x1db6cc, Func Offset: 0x8c
	// Line 836, Address: 0x1db6d0, Func Offset: 0x90
	// Line 841, Address: 0x1db6e0, Func Offset: 0xa0
	// Line 842, Address: 0x1db6fc, Func Offset: 0xbc
	// Line 845, Address: 0x1db708, Func Offset: 0xc8
	// Func End, Address: 0x1db710, Func Offset: 0xd0
	scePrintf("bhEne13_DG00 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db710
void bhEne13_Die(BH_PWORK* epw)
{
	int i;
	// Line 855, Address: 0x1db710, Func Offset: 0
	// Line 858, Address: 0x1db718, Func Offset: 0x8
	// Line 861, Address: 0x1db738, Func Offset: 0x28
	// Line 867, Address: 0x1db740, Func Offset: 0x30
	// Line 861, Address: 0x1db748, Func Offset: 0x38
	// Line 862, Address: 0x1db750, Func Offset: 0x40
	// Line 863, Address: 0x1db75c, Func Offset: 0x4c
	// Line 864, Address: 0x1db768, Func Offset: 0x58
	// Line 868, Address: 0x1db774, Func Offset: 0x64
	// Line 872, Address: 0x1db778, Func Offset: 0x68
	// Line 868, Address: 0x1db780, Func Offset: 0x70
	// Line 869, Address: 0x1db78c, Func Offset: 0x7c
	// Line 870, Address: 0x1db79c, Func Offset: 0x8c
	// Line 871, Address: 0x1db7ac, Func Offset: 0x9c
	// Line 872, Address: 0x1db7bc, Func Offset: 0xac
	// Line 875, Address: 0x1db7c4, Func Offset: 0xb4
	// Line 876, Address: 0x1db7cc, Func Offset: 0xbc
	// Line 880, Address: 0x1db7d4, Func Offset: 0xc4
	// Line 876, Address: 0x1db7dc, Func Offset: 0xcc
	// Line 877, Address: 0x1db7e8, Func Offset: 0xd8
	// Line 878, Address: 0x1db7f8, Func Offset: 0xe8
	// Line 879, Address: 0x1db808, Func Offset: 0xf8
	// Line 880, Address: 0x1db818, Func Offset: 0x108
	// Line 881, Address: 0x1db820, Func Offset: 0x110
	// Line 882, Address: 0x1db828, Func Offset: 0x118
	// Line 884, Address: 0x1db830, Func Offset: 0x120
	// Line 885, Address: 0x1db888, Func Offset: 0x178
	// Line 887, Address: 0x1db890, Func Offset: 0x180
	// Func End, Address: 0x1db89c, Func Offset: 0x18c
	scePrintf("bhEne13_Die - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1db8a0
void bhEne13_InitDamage(BH_PWORK* epw)
{
	int flg;
	int dflg;
	int wep_no;
	int i;
	int max_dam;
	int dam2;
	int dam1;
	int dam0;
	int dam;
	// Line 897, Address: 0x1db8a0, Func Offset: 0
	// Line 901, Address: 0x1db8d0, Func Offset: 0x30
	// Line 904, Address: 0x1db8e0, Func Offset: 0x40
	// Line 905, Address: 0x1db8e8, Func Offset: 0x48
	// Line 906, Address: 0x1db904, Func Offset: 0x64
	// Line 914, Address: 0x1db910, Func Offset: 0x70
	// Line 915, Address: 0x1db920, Func Offset: 0x80
	// Line 917, Address: 0x1db92c, Func Offset: 0x8c
	// Line 916, Address: 0x1db930, Func Offset: 0x90
	// Line 917, Address: 0x1db934, Func Offset: 0x94
	// Line 918, Address: 0x1db940, Func Offset: 0xa0
	// Line 921, Address: 0x1db948, Func Offset: 0xa8
	// Line 923, Address: 0x1db958, Func Offset: 0xb8
	// Line 924, Address: 0x1db97c, Func Offset: 0xdc
	// Line 925, Address: 0x1db988, Func Offset: 0xe8
	// Line 926, Address: 0x1db994, Func Offset: 0xf4
	// Line 928, Address: 0x1db9a0, Func Offset: 0x100
	// Line 929, Address: 0x1db9a4, Func Offset: 0x104
	// Line 927, Address: 0x1db9a8, Func Offset: 0x108
	// Line 929, Address: 0x1db9ac, Func Offset: 0x10c
	// Line 928, Address: 0x1db9b4, Func Offset: 0x114
	// Line 929, Address: 0x1db9b8, Func Offset: 0x118
	// Line 928, Address: 0x1db9bc, Func Offset: 0x11c
	// Line 929, Address: 0x1db9c0, Func Offset: 0x120
	// Line 933, Address: 0x1db9c4, Func Offset: 0x124
	// Line 937, Address: 0x1db9e4, Func Offset: 0x144
	// Line 941, Address: 0x1dba10, Func Offset: 0x170
	// Line 943, Address: 0x1dba18, Func Offset: 0x178
	// Line 981, Address: 0x1dba28, Func Offset: 0x188
	// Line 982, Address: 0x1dba38, Func Offset: 0x198
	// Line 983, Address: 0x1dba40, Func Offset: 0x1a0
	// Line 986, Address: 0x1dba50, Func Offset: 0x1b0
	// Line 987, Address: 0x1dba64, Func Offset: 0x1c4
	// Line 988, Address: 0x1dba6c, Func Offset: 0x1cc
	// Line 991, Address: 0x1dba7c, Func Offset: 0x1dc
	// Line 992, Address: 0x1dba90, Func Offset: 0x1f0
	// Line 993, Address: 0x1dba98, Func Offset: 0x1f8
	// Line 996, Address: 0x1dbaa8, Func Offset: 0x208
	// Line 997, Address: 0x1dbab0, Func Offset: 0x210
	// Line 998, Address: 0x1dbab8, Func Offset: 0x218
	// Line 999, Address: 0x1dbac4, Func Offset: 0x224
	// Line 1004, Address: 0x1dbac8, Func Offset: 0x228
	// Line 1005, Address: 0x1dbad0, Func Offset: 0x230
	// Line 1006, Address: 0x1dbad8, Func Offset: 0x238
	// Line 1007, Address: 0x1dbadc, Func Offset: 0x23c
	// Line 1008, Address: 0x1dbae0, Func Offset: 0x240
	// Line 1011, Address: 0x1dbae4, Func Offset: 0x244
	// Line 1012, Address: 0x1dbaf8, Func Offset: 0x258
	// Line 1014, Address: 0x1dbb04, Func Offset: 0x264
	// Line 1015, Address: 0x1dbb08, Func Offset: 0x268
	// Line 1016, Address: 0x1dbb0c, Func Offset: 0x26c
	// Line 1015, Address: 0x1dbb10, Func Offset: 0x270
	// Line 1016, Address: 0x1dbb18, Func Offset: 0x278
	// Line 1017, Address: 0x1dbb24, Func Offset: 0x284
	// Line 1018, Address: 0x1dbb2c, Func Offset: 0x28c
	// Line 1020, Address: 0x1dbb34, Func Offset: 0x294
	// Line 1021, Address: 0x1dbb38, Func Offset: 0x298
	// Line 1022, Address: 0x1dbb44, Func Offset: 0x2a4
	// Line 1023, Address: 0x1dbb50, Func Offset: 0x2b0
	// Line 1028, Address: 0x1dbb5c, Func Offset: 0x2bc
	// Func End, Address: 0x1dbb8c, Func Offset: 0x2ec
	scePrintf("bhEne13_InitDamage - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dbb90
void bhEne13_Finish(BH_PWORK* epw)
{
	int i;
	int obj_n;
	int ono;
	NJS_CNK_OBJECT* pObj;
	// Line 1038, Address: 0x1dbb90, Func Offset: 0
	// Line 1043, Address: 0x1dbbb4, Func Offset: 0x24
	// Line 1044, Address: 0x1dbbbc, Func Offset: 0x2c
	// Line 1045, Address: 0x1dbbcc, Func Offset: 0x3c
	// Line 1044, Address: 0x1dbbd0, Func Offset: 0x40
	// Line 1046, Address: 0x1dbbd4, Func Offset: 0x44
	// Line 1047, Address: 0x1dbbe0, Func Offset: 0x50
	// Line 1048, Address: 0x1dbbe8, Func Offset: 0x58
	// Line 1047, Address: 0x1dbbf4, Func Offset: 0x64
	// Line 1048, Address: 0x1dbbfc, Func Offset: 0x6c
	// Line 1049, Address: 0x1dbc08, Func Offset: 0x78
	// Line 1050, Address: 0x1dbc18, Func Offset: 0x88
	// Line 1053, Address: 0x1dbc28, Func Offset: 0x98
	// Line 1054, Address: 0x1dbc2c, Func Offset: 0x9c
	// Line 1053, Address: 0x1dbc30, Func Offset: 0xa0
	// Line 1055, Address: 0x1dbc34, Func Offset: 0xa4
	// Line 1056, Address: 0x1dbc40, Func Offset: 0xb0
	// Line 1059, Address: 0x1dbc88, Func Offset: 0xf8
	// Line 1060, Address: 0x1dbc94, Func Offset: 0x104
	// Line 1062, Address: 0x1dbc9c, Func Offset: 0x10c
	// Line 1063, Address: 0x1dbcac, Func Offset: 0x11c
	// Line 1064, Address: 0x1dbcbc, Func Offset: 0x12c
	// Line 1065, Address: 0x1dbccc, Func Offset: 0x13c
	// Line 1066, Address: 0x1dbcd0, Func Offset: 0x140
	// Line 1067, Address: 0x1dbce4, Func Offset: 0x154
	// Line 1068, Address: 0x1dbcf8, Func Offset: 0x168
	// Func End, Address: 0x1dbd1c, Func Offset: 0x18c
	scePrintf("bhEne13_Finish - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dbd20
void bhEne13_ScaleModel(NJS_CNK_OBJECT* pObj, float sx, float sy, float sz)
{
	HDR_PS* pHdr;
	NJS_POINT4* p;
	int i;
	int nVtx;
	// Line 1087, Address: 0x1dbd20, Func Offset: 0
	// Line 1089, Address: 0x1dbd2c, Func Offset: 0xc
	// Line 1093, Address: 0x1dbd30, Func Offset: 0x10
	// Line 1091, Address: 0x1dbd34, Func Offset: 0x14
	// Line 1093, Address: 0x1dbd38, Func Offset: 0x18
	// Line 1094, Address: 0x1dbd44, Func Offset: 0x24
	// Line 1102, Address: 0x1dbd48, Func Offset: 0x28
	// Line 1094, Address: 0x1dbd50, Func Offset: 0x30
	// Line 1095, Address: 0x1dbd58, Func Offset: 0x38
	// Line 1096, Address: 0x1dbd64, Func Offset: 0x44
	// Line 1098, Address: 0x1dbd70, Func Offset: 0x50
	// Line 1099, Address: 0x1dbd7c, Func Offset: 0x5c
	// Line 1100, Address: 0x1dbd88, Func Offset: 0x68
	// Line 1102, Address: 0x1dbd94, Func Offset: 0x74
	// Line 1103, Address: 0x1dbd9c, Func Offset: 0x7c
	// Line 1104, Address: 0x1dbda0, Func Offset: 0x80
	// Func End, Address: 0x1dbda8, Func Offset: 0x88
	scePrintf("bhEne13_ScaleModel - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dbdb0
int bhEne13_StoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	HDR_PS* pHdr;
	NJS_POINT4* pd;
	NJS_POINT4* ps;
	int nVtx;
	NJS_CNK_MODEL* pModel;
	int i;
	int obj_n;
	int ono;
	NJS_CNK_OBJECT* pObj;
	// Line 1142, Address: 0x1dbdb0, Func Offset: 0
	// Line 1152, Address: 0x1dbdd8, Func Offset: 0x28
	// Line 1153, Address: 0x1dbde0, Func Offset: 0x30
	// Line 1152, Address: 0x1dbde4, Func Offset: 0x34
	// Line 1154, Address: 0x1dbde8, Func Offset: 0x38
	// Line 1155, Address: 0x1dbe0c, Func Offset: 0x5c
	// Line 1156, Address: 0x1dbe14, Func Offset: 0x64
	// Line 1157, Address: 0x1dbe1c, Func Offset: 0x6c
	// Line 1160, Address: 0x1dbe24, Func Offset: 0x74
	// Line 1161, Address: 0x1dbe28, Func Offset: 0x78
	// Line 1162, Address: 0x1dbe30, Func Offset: 0x80
	// Line 1165, Address: 0x1dbe34, Func Offset: 0x84
	// Line 1164, Address: 0x1dbe38, Func Offset: 0x88
	// Line 1165, Address: 0x1dbe3c, Func Offset: 0x8c
	// Line 1168, Address: 0x1dbe48, Func Offset: 0x98
	// Line 1167, Address: 0x1dbe4c, Func Offset: 0x9c
	// Line 1169, Address: 0x1dbe50, Func Offset: 0xa0
	// Line 1170, Address: 0x1dbe60, Func Offset: 0xb0
	// Line 1180, Address: 0x1dbe64, Func Offset: 0xb4
	// Line 1170, Address: 0x1dbe6c, Func Offset: 0xbc
	// Line 1171, Address: 0x1dbe70, Func Offset: 0xc0
	// Line 1172, Address: 0x1dbe78, Func Offset: 0xc8
	// Line 1175, Address: 0x1dbe80, Func Offset: 0xd0
	// Line 1176, Address: 0x1dbe88, Func Offset: 0xd8
	// Line 1177, Address: 0x1dbe90, Func Offset: 0xe0
	// Line 1178, Address: 0x1dbe98, Func Offset: 0xe8
	// Line 1180, Address: 0x1dbe9c, Func Offset: 0xec
	// Line 1181, Address: 0x1dbea4, Func Offset: 0xf4
	// Line 1182, Address: 0x1dbea8, Func Offset: 0xf8
	// Line 1184, Address: 0x1dbec8, Func Offset: 0x118
	// Line 1185, Address: 0x1dbecc, Func Offset: 0x11c
	// Func End, Address: 0x1dbef8, Func Offset: 0x148
	scePrintf("bhEne13_StoreObject - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dbf00
int bhEne13_RestoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	HDR_PS* pHdr;
	NJS_POINT4* pd;
	NJS_POINT4* ps;
	int nVtx;
	NJS_CNK_MODEL* pModel;
	int i;
	int obj_n;
	int ono;
	NJS_CNK_OBJECT* pObj;
	// Line 1250, Address: 0x1dbf00, Func Offset: 0
	// Line 1251, Address: 0x1dbf04, Func Offset: 0x4
	// Line 1250, Address: 0x1dbf08, Func Offset: 0x8
	// Line 1252, Address: 0x1dbf0c, Func Offset: 0xc
	// Line 1253, Address: 0x1dbf30, Func Offset: 0x30
	// Line 1254, Address: 0x1dbf38, Func Offset: 0x38
	// Line 1255, Address: 0x1dbf40, Func Offset: 0x40
	// Line 1258, Address: 0x1dbf48, Func Offset: 0x48
	// Line 1259, Address: 0x1dbf4c, Func Offset: 0x4c
	// Line 1260, Address: 0x1dbf54, Func Offset: 0x54
	// Line 1264, Address: 0x1dbf58, Func Offset: 0x58
	// Line 1266, Address: 0x1dbf5c, Func Offset: 0x5c
	// Line 1262, Address: 0x1dbf60, Func Offset: 0x60
	// Line 1266, Address: 0x1dbf64, Func Offset: 0x64
	// Line 1267, Address: 0x1dbf70, Func Offset: 0x70
	// Line 1277, Address: 0x1dbf74, Func Offset: 0x74
	// Line 1267, Address: 0x1dbf7c, Func Offset: 0x7c
	// Line 1268, Address: 0x1dbf80, Func Offset: 0x80
	// Line 1269, Address: 0x1dbf88, Func Offset: 0x88
	// Line 1272, Address: 0x1dbf90, Func Offset: 0x90
	// Line 1273, Address: 0x1dbf98, Func Offset: 0x98
	// Line 1274, Address: 0x1dbfa0, Func Offset: 0xa0
	// Line 1275, Address: 0x1dbfa8, Func Offset: 0xa8
	// Line 1277, Address: 0x1dbfac, Func Offset: 0xac
	// Line 1278, Address: 0x1dbfb4, Func Offset: 0xb4
	// Line 1279, Address: 0x1dbfb8, Func Offset: 0xb8
	// Line 1282, Address: 0x1dbfd8, Func Offset: 0xd8
	// Func End, Address: 0x1dbfe0, Func Offset: 0xe0
	scePrintf("bhEne13_RestoreObject - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dbfe0
void bhEne13_PutAttacker(BH_PWORK* epw, int no)
{
	// already inversed DWARF order
	BH_PWORK* ep;
	int i;
	NJS_POINT3 wp;
	NJS_POINT3 pos[3] = 
	{
		{   0.0f,   0.0f, -25.0f },
		{ -20.0f,   0.0f, -13.0f },
		{  20.0f,   0.0f, -13.0f }
	};
	int ang[3] = { 0, 8192, 0xFFFFE000 };
	// Line 1337, Address: 0x1dbfe0, Func Offset: 0
	// Line 1341, Address: 0x1dbff0, Func Offset: 0x10
	// Line 1337, Address: 0x1dbff8, Func Offset: 0x18
	// Line 1341, Address: 0x1dbffc, Func Offset: 0x1c
	// Line 1346, Address: 0x1dc010, Func Offset: 0x30
	// Line 1341, Address: 0x1dc018, Func Offset: 0x38
	// Line 1346, Address: 0x1dc024, Func Offset: 0x44
	// Line 1352, Address: 0x1dc034, Func Offset: 0x54
	// Line 1346, Address: 0x1dc03c, Func Offset: 0x5c
	// Line 1352, Address: 0x1dc044, Func Offset: 0x64
	// Line 1353, Address: 0x1dc054, Func Offset: 0x74
	// Line 1354, Address: 0x1dc05c, Func Offset: 0x7c
	// Line 1357, Address: 0x1dc074, Func Offset: 0x94
	// Line 1356, Address: 0x1dc078, Func Offset: 0x98
	// Line 1357, Address: 0x1dc07c, Func Offset: 0x9c
	// Line 1361, Address: 0x1dc080, Func Offset: 0xa0
	// Line 1362, Address: 0x1dc08c, Func Offset: 0xac
	// Line 1363, Address: 0x1dc098, Func Offset: 0xb8
	// Line 1364, Address: 0x1dc0b8, Func Offset: 0xd8
	// Line 1369, Address: 0x1dc0c0, Func Offset: 0xe0
	// Line 1372, Address: 0x1dc0c8, Func Offset: 0xe8
	// Line 1364, Address: 0x1dc0d0, Func Offset: 0xf0
	// Line 1372, Address: 0x1dc0d4, Func Offset: 0xf4
	// Line 1364, Address: 0x1dc0dc, Func Offset: 0xfc
	// Line 1365, Address: 0x1dc0e4, Func Offset: 0x104
	// Line 1366, Address: 0x1dc0f8, Func Offset: 0x118
	// Line 1369, Address: 0x1dc10c, Func Offset: 0x12c
	// Line 1372, Address: 0x1dc118, Func Offset: 0x138
	// Line 1374, Address: 0x1dc120, Func Offset: 0x140
	// Line 1376, Address: 0x1dc12c, Func Offset: 0x14c
	// Line 1377, Address: 0x1dc140, Func Offset: 0x160
	// Func End, Address: 0x1dc158, Func Offset: 0x178
	scePrintf("bhEne13_PutAttacker - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc160
void bhEne13_Tentacle(BH_PWORK* epw, int no)
{
	// Line 1389, Address: 0x1dc160, Func Offset: 0
	// Line 1390, Address: 0x1dc170, Func Offset: 0x10
	// Line 1391, Address: 0x1dc17c, Func Offset: 0x1c
	// Line 1392, Address: 0x1dc188, Func Offset: 0x28
	// Line 1394, Address: 0x1dc194, Func Offset: 0x34
	// Line 1395, Address: 0x1dc19c, Func Offset: 0x3c
	// Func End, Address: 0x1dc1a4, Func Offset: 0x44
	scePrintf("bhEne13_Tentacle - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc1b0
int bhEne13_GetHatchNo(BH_PWORK* epw)
{
	// Line 1406, Address: 0x1dc1b0, Func Offset: 0
	// Line 1407, Address: 0x1dc1b4, Func Offset: 0x4
	// Func End, Address: 0x1dc1bc, Func Offset: 0xc
	scePrintf("bhEne13_GetHatchNo - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc1c0
int bhEne13_GetTentaNo(BH_PWORK* epw)
{
	// Line 1418, Address: 0x1dc1c0, Func Offset: 0
	// Line 1419, Address: 0x1dc1c4, Func Offset: 0x4
	// Func End, Address: 0x1dc1cc, Func Offset: 0xc
	scePrintf("bhEne13_GetTentaNo - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc1d0
BH_PWORK** bhEne13_GetChild(BH_PWORK* epw, int* num)
{
	// Line 1431, Address: 0x1dc1d0, Func Offset: 0
	// Line 1432, Address: 0x1dc1dc, Func Offset: 0xc
	// Line 1433, Address: 0x1dc1e0, Func Offset: 0x10
	// Func End, Address: 0x1dc1e8, Func Offset: 0x18
	scePrintf("bhEne13_GetChild - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc1f0
void bhEne13_CameraControl(BH_PWORK* epw)
{
	// Line 1443, Address: 0x1dc1f0, Func Offset: 0
	// Line 1445, Address: 0x1dc204, Func Offset: 0x14
	// Line 1446, Address: 0x1dc214, Func Offset: 0x24
	// Line 1447, Address: 0x1dc228, Func Offset: 0x38
	// Line 1448, Address: 0x1dc26c, Func Offset: 0x7c
	// Line 1449, Address: 0x1dc2b0, Func Offset: 0xc0
	// Line 1450, Address: 0x1dc2f0, Func Offset: 0x100
	// Line 1451, Address: 0x1dc2f8, Func Offset: 0x108
	// Line 1452, Address: 0x1dc31c, Func Offset: 0x12c
	// Line 1453, Address: 0x1dc35c, Func Offset: 0x16c
	// Line 1454, Address: 0x1dc3a0, Func Offset: 0x1b0
	// Line 1455, Address: 0x1dc3c0, Func Offset: 0x1d0
	// Line 1454, Address: 0x1dc3c4, Func Offset: 0x1d4
	// Line 1455, Address: 0x1dc3c8, Func Offset: 0x1d8
	// Line 1454, Address: 0x1dc3cc, Func Offset: 0x1dc
	// Line 1455, Address: 0x1dc3ec, Func Offset: 0x1fc
	// Line 1456, Address: 0x1dc3fc, Func Offset: 0x20c
	// Line 1457, Address: 0x1dc404, Func Offset: 0x214
	// Line 1461, Address: 0x1dc41c, Func Offset: 0x22c
	// Func End, Address: 0x1dc430, Func Offset: 0x240
	scePrintf("bhEne13_CameraControl - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc430
void bhEne13_SetCamera(BH_PWORK* epw, float f)
{
	// Line 1472, Address: 0x1dc430, Func Offset: 0
	// Line 1473, Address: 0x1dc434, Func Offset: 0x4
	// Func End, Address: 0x1dc43c, Func Offset: 0xc
	scePrintf("bhEne13_SetCamera - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc440
int bhEne13_SelectTentacle(BH_PWORK* epw)
{
	int ang;
	// Line 1483, Address: 0x1dc440, Func Offset: 0
	// Line 1486, Address: 0x1dc44c, Func Offset: 0xc
	// Line 1488, Address: 0x1dc480, Func Offset: 0x40
	// Line 1489, Address: 0x1dc4c8, Func Offset: 0x88
	// Line 1490, Address: 0x1dc4dc, Func Offset: 0x9c
	// Line 1492, Address: 0x1dc4f0, Func Offset: 0xb0
	// Line 1493, Address: 0x1dc4f4, Func Offset: 0xb4
	// Func End, Address: 0x1dc504, Func Offset: 0xc4
	scePrintf("bhEne13_SelectTentacle - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1dc510
void bhEne13_PlayerControl(BH_PWORK* epw)
{
	// already inversed DWARF order
	int mtn[3][8] = 
	{
		{ 10, 11, 12, 13, 15, 14,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 } 
	};
	NJS_POINT3* trans[3][3] = 
	{
		{ cler_042, cler_043, cler_045 },
		{ cher_060, cher_061, cher_063 },
		{ cher_060, cher_061, cher_063 }
	};
	// Line 1503, Address: 0x1dc510, Func Offset: 0
	// Line 1504, Address: 0x1dc514, Func Offset: 0x4
	// Line 1503, Address: 0x1dc51c, Func Offset: 0xc
	// Line 1504, Address: 0x1dc520, Func Offset: 0x10
	// Line 1509, Address: 0x1dc534, Func Offset: 0x24
	// Line 1504, Address: 0x1dc53c, Func Offset: 0x2c
	// Line 1509, Address: 0x1dc554, Func Offset: 0x44
	// Line 1515, Address: 0x1dc558, Func Offset: 0x48
	// Line 1504, Address: 0x1dc560, Func Offset: 0x50
	// Line 1509, Address: 0x1dc568, Func Offset: 0x58
	// Line 1515, Address: 0x1dc580, Func Offset: 0x70
	// Line 1516, Address: 0x1dc590, Func Offset: 0x80
	// Line 1519, Address: 0x1dc5b0, Func Offset: 0xa0
	// Line 1521, Address: 0x1dc5dc, Func Offset: 0xcc
	// Line 1522, Address: 0x1dc5e8, Func Offset: 0xd8
	// Line 1521, Address: 0x1dc5ec, Func Offset: 0xdc
	// Line 1522, Address: 0x1dc5f4, Func Offset: 0xe4
	// Line 1523, Address: 0x1dc5fc, Func Offset: 0xec
	// Line 1522, Address: 0x1dc600, Func Offset: 0xf0
	// Line 1523, Address: 0x1dc608, Func Offset: 0xf8
	// Line 1525, Address: 0x1dc610, Func Offset: 0x100
	// Line 1523, Address: 0x1dc614, Func Offset: 0x104
	// Line 1525, Address: 0x1dc618, Func Offset: 0x108
	// Line 1526, Address: 0x1dc628, Func Offset: 0x118
	// Line 1527, Address: 0x1dc640, Func Offset: 0x130
	// Line 1528, Address: 0x1dc648, Func Offset: 0x138
	// Line 1530, Address: 0x1dc664, Func Offset: 0x154
	// Line 1531, Address: 0x1dc66c, Func Offset: 0x15c
	// Line 1532, Address: 0x1dc670, Func Offset: 0x160
	// Line 1533, Address: 0x1dc674, Func Offset: 0x164
	// Line 1536, Address: 0x1dc678, Func Offset: 0x168
	// Line 1530, Address: 0x1dc67c, Func Offset: 0x16c
	// Line 1531, Address: 0x1dc680, Func Offset: 0x170
	// Line 1539, Address: 0x1dc688, Func Offset: 0x178
	// Line 1531, Address: 0x1dc68c, Func Offset: 0x17c
	// Line 1532, Address: 0x1dc690, Func Offset: 0x180
	// Line 1533, Address: 0x1dc69c, Func Offset: 0x18c
	// Line 1534, Address: 0x1dc6a8, Func Offset: 0x198
	// Line 1536, Address: 0x1dc6b4, Func Offset: 0x1a4
	// Line 1534, Address: 0x1dc6b8, Func Offset: 0x1a8
	// Line 1536, Address: 0x1dc6c0, Func Offset: 0x1b0
	// Line 1539, Address: 0x1dc6c4, Func Offset: 0x1b4
	// Line 1541, Address: 0x1dc6cc, Func Offset: 0x1bc
	// Line 1543, Address: 0x1dc6d8, Func Offset: 0x1c8
	// Line 1545, Address: 0x1dc6e0, Func Offset: 0x1d0
	// Line 1546, Address: 0x1dc6e8, Func Offset: 0x1d8
	// Line 1548, Address: 0x1dc71c, Func Offset: 0x20c
	// Line 1551, Address: 0x1dc748, Func Offset: 0x238
	// Line 1552, Address: 0x1dc75c, Func Offset: 0x24c
	// Line 1553, Address: 0x1dc788, Func Offset: 0x278
	// Line 1552, Address: 0x1dc78c, Func Offset: 0x27c
	// Line 1553, Address: 0x1dc794, Func Offset: 0x284
	// Line 1556, Address: 0x1dc7a4, Func Offset: 0x294
	// Line 1557, Address: 0x1dc7b8, Func Offset: 0x2a8
	// Line 1558, Address: 0x1dc7c4, Func Offset: 0x2b4
	// Line 1559, Address: 0x1dc7cc, Func Offset: 0x2bc
	// Line 1558, Address: 0x1dc7d0, Func Offset: 0x2c0
	// Line 1559, Address: 0x1dc7d4, Func Offset: 0x2c4
	// Line 1558, Address: 0x1dc7d8, Func Offset: 0x2c8
	// Line 1559, Address: 0x1dc7e8, Func Offset: 0x2d8
	// Line 1560, Address: 0x1dc7f4, Func Offset: 0x2e4
	// Line 1561, Address: 0x1dc7fc, Func Offset: 0x2ec
	// Line 1563, Address: 0x1dc818, Func Offset: 0x308
	// Line 1565, Address: 0x1dc828, Func Offset: 0x318
	// Line 1567, Address: 0x1dc830, Func Offset: 0x320
	// Line 1569, Address: 0x1dc838, Func Offset: 0x328
	// Line 1570, Address: 0x1dc84c, Func Offset: 0x33c
	// Line 1572, Address: 0x1dc860, Func Offset: 0x350
	// Line 1573, Address: 0x1dc874, Func Offset: 0x364
	// Line 1574, Address: 0x1dc890, Func Offset: 0x380
	// Line 1576, Address: 0x1dc89c, Func Offset: 0x38c
	// Line 1578, Address: 0x1dc8c8, Func Offset: 0x3b8
	// Line 1582, Address: 0x1dc8e4, Func Offset: 0x3d4
	// Line 1584, Address: 0x1dc8f8, Func Offset: 0x3e8
	// Line 1585, Address: 0x1dc8fc, Func Offset: 0x3ec
	// Line 1586, Address: 0x1dc908, Func Offset: 0x3f8
	// Line 1584, Address: 0x1dc90c, Func Offset: 0x3fc
	// Line 1585, Address: 0x1dc910, Func Offset: 0x400
	// Line 1589, Address: 0x1dc914, Func Offset: 0x404
	// Line 1590, Address: 0x1dc918, Func Offset: 0x408
	// Line 1585, Address: 0x1dc91c, Func Offset: 0x40c
	// Line 1586, Address: 0x1dc920, Func Offset: 0x410
	// Line 1585, Address: 0x1dc924, Func Offset: 0x414
	// Line 1586, Address: 0x1dc92c, Func Offset: 0x41c
	// Line 1587, Address: 0x1dc934, Func Offset: 0x424
	// Line 1586, Address: 0x1dc938, Func Offset: 0x428
	// Line 1587, Address: 0x1dc940, Func Offset: 0x430
	// Line 1588, Address: 0x1dc948, Func Offset: 0x438
	// Line 1587, Address: 0x1dc94c, Func Offset: 0x43c
	// Line 1588, Address: 0x1dc954, Func Offset: 0x444
	// Line 1589, Address: 0x1dc95c, Func Offset: 0x44c
	// Line 1590, Address: 0x1dc968, Func Offset: 0x458
	// Line 1589, Address: 0x1dc96c, Func Offset: 0x45c
	// Line 1590, Address: 0x1dc974, Func Offset: 0x464
	// Line 1596, Address: 0x1dc97c, Func Offset: 0x46c
	// Line 1597, Address: 0x1dc990, Func Offset: 0x480
	// Line 1598, Address: 0x1dc9a4, Func Offset: 0x494
	// Line 1601, Address: 0x1dc9c4, Func Offset: 0x4b4
	// Line 1603, Address: 0x1dc9fc, Func Offset: 0x4ec
	// Line 1604, Address: 0x1dca08, Func Offset: 0x4f8
	// Line 1603, Address: 0x1dca0c, Func Offset: 0x4fc
	// Line 1604, Address: 0x1dca14, Func Offset: 0x504
	// Line 1605, Address: 0x1dca1c, Func Offset: 0x50c
	// Line 1604, Address: 0x1dca20, Func Offset: 0x510
	// Line 1605, Address: 0x1dca28, Func Offset: 0x518
	// Line 1607, Address: 0x1dca30, Func Offset: 0x520
	// Line 1605, Address: 0x1dca34, Func Offset: 0x524
	// Line 1607, Address: 0x1dca38, Func Offset: 0x528
	// Line 1608, Address: 0x1dca48, Func Offset: 0x538
	// Line 1609, Address: 0x1dca60, Func Offset: 0x550
	// Line 1610, Address: 0x1dca68, Func Offset: 0x558
	// Line 1612, Address: 0x1dca84, Func Offset: 0x574
	// Line 1613, Address: 0x1dca8c, Func Offset: 0x57c
	// Line 1614, Address: 0x1dca90, Func Offset: 0x580
	// Line 1615, Address: 0x1dca94, Func Offset: 0x584
	// Line 1618, Address: 0x1dca98, Func Offset: 0x588
	// Line 1612, Address: 0x1dca9c, Func Offset: 0x58c
	// Line 1613, Address: 0x1dcaa0, Func Offset: 0x590
	// Line 1621, Address: 0x1dcaa8, Func Offset: 0x598
	// Line 1613, Address: 0x1dcaac, Func Offset: 0x59c
	// Line 1614, Address: 0x1dcab0, Func Offset: 0x5a0
	// Line 1615, Address: 0x1dcabc, Func Offset: 0x5ac
	// Line 1616, Address: 0x1dcac8, Func Offset: 0x5b8
	// Line 1618, Address: 0x1dcad4, Func Offset: 0x5c4
	// Line 1616, Address: 0x1dcad8, Func Offset: 0x5c8
	// Line 1618, Address: 0x1dcae0, Func Offset: 0x5d0
	// Line 1621, Address: 0x1dcae4, Func Offset: 0x5d4
	// Line 1623, Address: 0x1dcaec, Func Offset: 0x5dc
	// Line 1625, Address: 0x1dcaf8, Func Offset: 0x5e8
	// Line 1627, Address: 0x1dcb00, Func Offset: 0x5f0
	// Line 1628, Address: 0x1dcb08, Func Offset: 0x5f8
	// Line 1630, Address: 0x1dcb3c, Func Offset: 0x62c
	// Line 1633, Address: 0x1dcb68, Func Offset: 0x658
	// Line 1634, Address: 0x1dcb7c, Func Offset: 0x66c
	// Line 1635, Address: 0x1dcba8, Func Offset: 0x698
	// Line 1634, Address: 0x1dcbac, Func Offset: 0x69c
	// Line 1635, Address: 0x1dcbb4, Func Offset: 0x6a4
	// Line 1638, Address: 0x1dcbc4, Func Offset: 0x6b4
	// Line 1639, Address: 0x1dcbd8, Func Offset: 0x6c8
	// Line 1640, Address: 0x1dcbe8, Func Offset: 0x6d8
	// Line 1641, Address: 0x1dcc00, Func Offset: 0x6f0
	// Line 1642, Address: 0x1dcc08, Func Offset: 0x6f8
	// Line 1644, Address: 0x1dcc24, Func Offset: 0x714
	// Line 1645, Address: 0x1dcc34, Func Offset: 0x724
	// Line 1644, Address: 0x1dcc38, Func Offset: 0x728
	// Line 1645, Address: 0x1dcc54, Func Offset: 0x744
	// Line 1647, Address: 0x1dcc60, Func Offset: 0x750
	// Line 1649, Address: 0x1dcc68, Func Offset: 0x758
	// Line 1650, Address: 0x1dcc78, Func Offset: 0x768
	// Line 1651, Address: 0x1dcc80, Func Offset: 0x770
	// Line 1650, Address: 0x1dcc84, Func Offset: 0x774
	// Line 1651, Address: 0x1dcc88, Func Offset: 0x778
	// Line 1652, Address: 0x1dcc94, Func Offset: 0x784
	// Line 1654, Address: 0x1dcca4, Func Offset: 0x794
	// Line 1656, Address: 0x1dccac, Func Offset: 0x79c
	// Line 1658, Address: 0x1dccbc, Func Offset: 0x7ac
	// Line 1664, Address: 0x1dccd0, Func Offset: 0x7c0
	// Line 1666, Address: 0x1dcce8, Func Offset: 0x7d8
	// Func End, Address: 0x1dccf4, Func Offset: 0x7e4
	scePrintf("bhEne13_PlayerControl - UNIMPLEMENTED!\n");
}
