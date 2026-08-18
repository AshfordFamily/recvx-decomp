#include "../../../ps2/veronica/prog/en18.h"
#include "../../../ps2/veronica/prog/subpl.h"

// ENEMY: Alexia's Tentacle 

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne18_Mode0[6] =
{
    bhEne18_Init,
    bhEne18_Move,
    bhEne18_Nage,
    bhEne18_Damage,
    bhEne18_Die,
    bhEne_Event
};

MoveMode2_proc bhEne18_MoveMode2[6] =
{
    bhEne18_MV00,
    bhEne18_MV01,
    bhEne18_MV02,
    bhEne18_MV03,
    bhEne18_MV04,
    bhEne18_MV05
};

/*
_anon7 DmgReact[21];
_anon37 CombWepTbl[21];
_anon40 CombJointTbl[14];
_anon3 ENE18_EO_00[1];
_anon3 ENE18_EO_04[7];
_anon3 ENE18_EO_05[5];
_anon3 ENE18_EO_06[7];
_anon3 ENE18_EO_07[6];
_anon3 ENE18_EO_08[5];
_anon3 ENE18_EO_09[7];
_anon3 ENE18_EO_10[6];
_anon3 ENE18_EO_11[5];
_anon3 ENE18_EO_12[8];
_anon3 ENE18_EO_13[5];
_anon0 BloodTbl[14];
_anon16 CapColTab[31];
_anon27 HeartBeat[13];
_anon27 SpawnAttacker[15];
_anon27 Broken[5];
_anon27 Tentacle[11];
_anon27 Tentacle2[11];
_anon27 Tentacle3[11];
_anon27 Tentacle4[11];
*/

// 
// Start address: 0x1eec00
void bhEne18(BH_PWORK* epw)
{
	// Line 476, Address: 0x1eec00, Func Offset: 0
	// Line 478, Address: 0x1eec10, Func Offset: 0x10
	// Line 481, Address: 0x1eec30, Func Offset: 0x30
	// Line 482, Address: 0x1eec48, Func Offset: 0x48
	// Line 483, Address: 0x1eec54, Func Offset: 0x54
	// Line 487, Address: 0x1eec60, Func Offset: 0x60
	// Line 488, Address: 0x1eec6c, Func Offset: 0x6c
	// Func End, Address: 0x1eec7c, Func Offset: 0x7c
	scePrintf("bhEne18 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x1eec80
void bhEne18_Init(BH_PWORK* epw)
{
	int InitAction[10];
	_anon25 vec;
	BH_PWORK* ep;
	// Line 498, Address: 0x1eec80, Func Offset: 0
	// Line 501, Address: 0x1eec94, Func Offset: 0x14
	// Line 498, Address: 0x1eec9c, Func Offset: 0x1c
	// Line 501, Address: 0x1eeca0, Func Offset: 0x20
	// Line 515, Address: 0x1eecc0, Func Offset: 0x40
	// Line 516, Address: 0x1eecc4, Func Offset: 0x44
	// Line 518, Address: 0x1eece4, Func Offset: 0x64
	// Line 522, Address: 0x1eecec, Func Offset: 0x6c
	// Line 523, Address: 0x1eecf0, Func Offset: 0x70
	// Line 525, Address: 0x1eecf4, Func Offset: 0x74
	// Line 526, Address: 0x1eecf8, Func Offset: 0x78
	// Line 527, Address: 0x1eecfc, Func Offset: 0x7c
	// Line 522, Address: 0x1eed00, Func Offset: 0x80
	// Line 523, Address: 0x1eed08, Func Offset: 0x88
	// Line 530, Address: 0x1eed0c, Func Offset: 0x8c
	// Line 536, Address: 0x1eed10, Func Offset: 0x90
	// Line 523, Address: 0x1eed14, Func Offset: 0x94
	// Line 524, Address: 0x1eed1c, Func Offset: 0x9c
	// Line 525, Address: 0x1eed28, Func Offset: 0xa8
	// Line 526, Address: 0x1eed2c, Func Offset: 0xac
	// Line 527, Address: 0x1eed30, Func Offset: 0xb0
	// Line 530, Address: 0x1eed34, Func Offset: 0xb4
	// Line 531, Address: 0x1eed38, Func Offset: 0xb8
	// Line 532, Address: 0x1eed3c, Func Offset: 0xbc
	// Line 533, Address: 0x1eed50, Func Offset: 0xd0
	// Line 536, Address: 0x1eed54, Func Offset: 0xd4
	// Line 537, Address: 0x1eed58, Func Offset: 0xd8
	// Line 538, Address: 0x1eed5c, Func Offset: 0xdc
	// Line 539, Address: 0x1eed60, Func Offset: 0xe0
	// Line 540, Address: 0x1eed64, Func Offset: 0xe4
	// Line 544, Address: 0x1eed68, Func Offset: 0xe8
	// Line 547, Address: 0x1eedbc, Func Offset: 0x13c
	// Line 548, Address: 0x1eedc8, Func Offset: 0x148
	// Line 549, Address: 0x1eedd8, Func Offset: 0x158
	// Line 554, Address: 0x1eede0, Func Offset: 0x160
	// Line 557, Address: 0x1eede4, Func Offset: 0x164
	// Line 549, Address: 0x1eede8, Func Offset: 0x168
	// Line 550, Address: 0x1eedf0, Func Offset: 0x170
	// Line 551, Address: 0x1eee00, Func Offset: 0x180
	// Line 554, Address: 0x1eee10, Func Offset: 0x190
	// Line 555, Address: 0x1eee44, Func Offset: 0x1c4
	// Line 556, Address: 0x1eee68, Func Offset: 0x1e8
	// Line 557, Address: 0x1eee74, Func Offset: 0x1f4
	// Line 558, Address: 0x1eee80, Func Offset: 0x200
	// Line 559, Address: 0x1eee8c, Func Offset: 0x20c
	// Line 560, Address: 0x1eee98, Func Offset: 0x218
	// Line 561, Address: 0x1eeea4, Func Offset: 0x224
	// Line 564, Address: 0x1eeeb0, Func Offset: 0x230
	// Line 565, Address: 0x1eeec0, Func Offset: 0x240
	// Line 566, Address: 0x1eeecc, Func Offset: 0x24c
	// Line 569, Address: 0x1eeed8, Func Offset: 0x258
	// Line 572, Address: 0x1eef08, Func Offset: 0x288
	// Line 573, Address: 0x1eef0c, Func Offset: 0x28c
	// Line 578, Address: 0x1eef14, Func Offset: 0x294
	// Line 576, Address: 0x1eef18, Func Offset: 0x298
	// Line 572, Address: 0x1eef20, Func Offset: 0x2a0
	// Line 573, Address: 0x1eef24, Func Offset: 0x2a4
	// Line 581, Address: 0x1eef28, Func Offset: 0x2a8
	// Line 573, Address: 0x1eef30, Func Offset: 0x2b0
	// Line 574, Address: 0x1eef38, Func Offset: 0x2b8
	// Line 575, Address: 0x1eef40, Func Offset: 0x2c0
	// Line 576, Address: 0x1eef48, Func Offset: 0x2c8
	// Line 577, Address: 0x1eef54, Func Offset: 0x2d4
	// Line 578, Address: 0x1eef5c, Func Offset: 0x2dc
	// Line 582, Address: 0x1eef60, Func Offset: 0x2e0
	// Line 585, Address: 0x1eef68, Func Offset: 0x2e8
	// Line 586, Address: 0x1eef70, Func Offset: 0x2f0
	// Line 587, Address: 0x1eef7c, Func Offset: 0x2fc
	// Line 589, Address: 0x1eef88, Func Offset: 0x308
	// Line 590, Address: 0x1eef90, Func Offset: 0x310
	// Line 591, Address: 0x1eef9c, Func Offset: 0x31c
	// Line 593, Address: 0x1eefac, Func Offset: 0x32c
	// Line 597, Address: 0x1eefb4, Func Offset: 0x334
	// Line 598, Address: 0x1eefb8, Func Offset: 0x338
	// Line 599, Address: 0x1eefbc, Func Offset: 0x33c
	// Line 601, Address: 0x1eefc0, Func Offset: 0x340
	// Line 593, Address: 0x1eefc4, Func Offset: 0x344
	// Line 594, Address: 0x1eefcc, Func Offset: 0x34c
	// Line 595, Address: 0x1eefdc, Func Offset: 0x35c
	// Line 597, Address: 0x1eefec, Func Offset: 0x36c
	// Line 598, Address: 0x1eeff0, Func Offset: 0x370
	// Line 601, Address: 0x1eeff4, Func Offset: 0x374
	// Line 602, Address: 0x1eeffc, Func Offset: 0x37c
	// Line 603, Address: 0x1ef008, Func Offset: 0x388
	// Line 605, Address: 0x1ef018, Func Offset: 0x398
	// Line 609, Address: 0x1ef020, Func Offset: 0x3a0
	// Line 605, Address: 0x1ef024, Func Offset: 0x3a4
	// Line 606, Address: 0x1ef02c, Func Offset: 0x3ac
	// Line 607, Address: 0x1ef03c, Func Offset: 0x3bc
	// Line 609, Address: 0x1ef04c, Func Offset: 0x3cc
	// Line 611, Address: 0x1ef050, Func Offset: 0x3d0
	// Line 612, Address: 0x1ef058, Func Offset: 0x3d8
	// Line 615, Address: 0x1ef060, Func Offset: 0x3e0
	// Line 616, Address: 0x1ef068, Func Offset: 0x3e8
	// Line 617, Address: 0x1ef070, Func Offset: 0x3f0
	// Line 616, Address: 0x1ef074, Func Offset: 0x3f4
	// Line 619, Address: 0x1ef078, Func Offset: 0x3f8
	// Line 620, Address: 0x1ef084, Func Offset: 0x404
	// Line 621, Address: 0x1ef090, Func Offset: 0x410
	// Line 623, Address: 0x1ef0a0, Func Offset: 0x420
	// Line 627, Address: 0x1ef0a8, Func Offset: 0x428
	// Line 628, Address: 0x1ef0ac, Func Offset: 0x42c
	// Line 629, Address: 0x1ef0b0, Func Offset: 0x430
	// Line 631, Address: 0x1ef0b4, Func Offset: 0x434
	// Line 623, Address: 0x1ef0b8, Func Offset: 0x438
	// Line 624, Address: 0x1ef0c0, Func Offset: 0x440
	// Line 625, Address: 0x1ef0d0, Func Offset: 0x450
	// Line 627, Address: 0x1ef0e0, Func Offset: 0x460
	// Line 628, Address: 0x1ef0e4, Func Offset: 0x464
	// Line 631, Address: 0x1ef0e8, Func Offset: 0x468
	// Line 632, Address: 0x1ef0f0, Func Offset: 0x470
	// Line 633, Address: 0x1ef0fc, Func Offset: 0x47c
	// Line 635, Address: 0x1ef10c, Func Offset: 0x48c
	// Line 639, Address: 0x1ef114, Func Offset: 0x494
	// Line 635, Address: 0x1ef118, Func Offset: 0x498
	// Line 636, Address: 0x1ef120, Func Offset: 0x4a0
	// Line 637, Address: 0x1ef130, Func Offset: 0x4b0
	// Line 639, Address: 0x1ef140, Func Offset: 0x4c0
	// Line 641, Address: 0x1ef144, Func Offset: 0x4c4
	// Line 642, Address: 0x1ef14c, Func Offset: 0x4cc
	// Line 646, Address: 0x1ef154, Func Offset: 0x4d4
	// Line 645, Address: 0x1ef158, Func Offset: 0x4d8
	// Line 646, Address: 0x1ef15c, Func Offset: 0x4dc
	// Line 647, Address: 0x1ef164, Func Offset: 0x4e4
	// Line 649, Address: 0x1ef170, Func Offset: 0x4f0
	// Line 650, Address: 0x1ef178, Func Offset: 0x4f8
	// Line 651, Address: 0x1ef184, Func Offset: 0x504
	// Line 653, Address: 0x1ef194, Func Offset: 0x514
	// Line 659, Address: 0x1ef19c, Func Offset: 0x51c
	// Line 661, Address: 0x1ef1a0, Func Offset: 0x520
	// Line 653, Address: 0x1ef1a4, Func Offset: 0x524
	// Line 654, Address: 0x1ef1ac, Func Offset: 0x52c
	// Line 655, Address: 0x1ef1bc, Func Offset: 0x53c
	// Line 657, Address: 0x1ef1cc, Func Offset: 0x54c
	// Line 658, Address: 0x1ef1d0, Func Offset: 0x550
	// Line 661, Address: 0x1ef1d4, Func Offset: 0x554
	// Line 662, Address: 0x1ef1dc, Func Offset: 0x55c
	// Line 663, Address: 0x1ef1e8, Func Offset: 0x568
	// Line 665, Address: 0x1ef1f8, Func Offset: 0x578
	// Line 669, Address: 0x1ef200, Func Offset: 0x580
	// Line 665, Address: 0x1ef204, Func Offset: 0x584
	// Line 666, Address: 0x1ef20c, Func Offset: 0x58c
	// Line 667, Address: 0x1ef21c, Func Offset: 0x59c
	// Line 669, Address: 0x1ef22c, Func Offset: 0x5ac
	// Line 671, Address: 0x1ef230, Func Offset: 0x5b0
	// Line 672, Address: 0x1ef238, Func Offset: 0x5b8
	// Line 675, Address: 0x1ef240, Func Offset: 0x5c0
	// Line 676, Address: 0x1ef248, Func Offset: 0x5c8
	// Line 677, Address: 0x1ef254, Func Offset: 0x5d4
	// Line 679, Address: 0x1ef260, Func Offset: 0x5e0
	// Line 680, Address: 0x1ef268, Func Offset: 0x5e8
	// Line 681, Address: 0x1ef274, Func Offset: 0x5f4
	// Line 683, Address: 0x1ef284, Func Offset: 0x604
	// Line 687, Address: 0x1ef28c, Func Offset: 0x60c
	// Line 689, Address: 0x1ef290, Func Offset: 0x610
	// Line 691, Address: 0x1ef294, Func Offset: 0x614
	// Line 683, Address: 0x1ef298, Func Offset: 0x618
	// Line 684, Address: 0x1ef2a0, Func Offset: 0x620
	// Line 685, Address: 0x1ef2b0, Func Offset: 0x630
	// Line 687, Address: 0x1ef2c0, Func Offset: 0x640
	// Line 688, Address: 0x1ef2c4, Func Offset: 0x644
	// Line 691, Address: 0x1ef2c8, Func Offset: 0x648
	// Line 692, Address: 0x1ef2d0, Func Offset: 0x650
	// Line 693, Address: 0x1ef2dc, Func Offset: 0x65c
	// Line 695, Address: 0x1ef2ec, Func Offset: 0x66c
	// Line 699, Address: 0x1ef2f4, Func Offset: 0x674
	// Line 695, Address: 0x1ef2f8, Func Offset: 0x678
	// Line 696, Address: 0x1ef300, Func Offset: 0x680
	// Line 697, Address: 0x1ef310, Func Offset: 0x690
	// Line 699, Address: 0x1ef320, Func Offset: 0x6a0
	// Line 701, Address: 0x1ef324, Func Offset: 0x6a4
	// Line 702, Address: 0x1ef32c, Func Offset: 0x6ac
	// Line 705, Address: 0x1ef334, Func Offset: 0x6b4
	// Line 706, Address: 0x1ef33c, Func Offset: 0x6bc
	// Line 707, Address: 0x1ef348, Func Offset: 0x6c8
	// Line 709, Address: 0x1ef354, Func Offset: 0x6d4
	// Line 710, Address: 0x1ef35c, Func Offset: 0x6dc
	// Line 711, Address: 0x1ef368, Func Offset: 0x6e8
	// Line 713, Address: 0x1ef378, Func Offset: 0x6f8
	// Line 717, Address: 0x1ef380, Func Offset: 0x700
	// Line 719, Address: 0x1ef384, Func Offset: 0x704
	// Line 721, Address: 0x1ef388, Func Offset: 0x708
	// Line 713, Address: 0x1ef38c, Func Offset: 0x70c
	// Line 714, Address: 0x1ef394, Func Offset: 0x714
	// Line 715, Address: 0x1ef3a4, Func Offset: 0x724
	// Line 717, Address: 0x1ef3b4, Func Offset: 0x734
	// Line 718, Address: 0x1ef3b8, Func Offset: 0x738
	// Line 721, Address: 0x1ef3bc, Func Offset: 0x73c
	// Line 722, Address: 0x1ef3c4, Func Offset: 0x744
	// Line 723, Address: 0x1ef3d0, Func Offset: 0x750
	// Line 725, Address: 0x1ef3e0, Func Offset: 0x760
	// Line 729, Address: 0x1ef3e8, Func Offset: 0x768
	// Line 725, Address: 0x1ef3ec, Func Offset: 0x76c
	// Line 726, Address: 0x1ef3f4, Func Offset: 0x774
	// Line 727, Address: 0x1ef404, Func Offset: 0x784
	// Line 729, Address: 0x1ef414, Func Offset: 0x794
	// Line 731, Address: 0x1ef418, Func Offset: 0x798
	// Line 735, Address: 0x1ef424, Func Offset: 0x7a4
	// Func End, Address: 0x1ef440, Func Offset: 0x7c0
}

// 
// Start address: 0x1ef440
void bhEne18_Move(BH_PWORK* epw)
{
	// Line 758, Address: 0x1ef440, Func Offset: 0
	// Func End, Address: 0x1ef460, Func Offset: 0x20
}

// 
// Start address: 0x1ef460
void bhEne18_MV00(BH_PWORK* epw)
{
	// Line 770, Address: 0x1ef460, Func Offset: 0
	// Line 772, Address: 0x1ef474, Func Offset: 0x14
	// Line 774, Address: 0x1ef47c, Func Offset: 0x1c
	// Line 772, Address: 0x1ef480, Func Offset: 0x20
	// Line 773, Address: 0x1ef488, Func Offset: 0x28
	// Line 774, Address: 0x1ef48c, Func Offset: 0x2c
	// Line 775, Address: 0x1ef498, Func Offset: 0x38
	// Line 778, Address: 0x1ef4a4, Func Offset: 0x44
	// Func End, Address: 0x1ef4ac, Func Offset: 0x4c
}

// 
// Start address: 0x1ef4b0
void bhEne18_MV01(BH_PWORK* epw)
{
	// Line 788, Address: 0x1ef4b0, Func Offset: 0
	// Line 789, Address: 0x1ef4c0, Func Offset: 0x10
	// Line 791, Address: 0x1ef4e0, Func Offset: 0x30
	// Line 792, Address: 0x1ef4ec, Func Offset: 0x3c
	// Line 793, Address: 0x1ef4f0, Func Offset: 0x40
	// Line 795, Address: 0x1ef4fc, Func Offset: 0x4c
	// Line 796, Address: 0x1ef50c, Func Offset: 0x5c
	// Line 797, Address: 0x1ef528, Func Offset: 0x78
	// Line 798, Address: 0x1ef534, Func Offset: 0x84
	// Line 799, Address: 0x1ef53c, Func Offset: 0x8c
	// Line 800, Address: 0x1ef544, Func Offset: 0x94
	// Line 801, Address: 0x1ef550, Func Offset: 0xa0
	// Line 802, Address: 0x1ef55c, Func Offset: 0xac
	// Line 805, Address: 0x1ef568, Func Offset: 0xb8
	// Line 806, Address: 0x1ef574, Func Offset: 0xc4
	// Line 809, Address: 0x1ef588, Func Offset: 0xd8
	// Func End, Address: 0x1ef598, Func Offset: 0xe8
}

// 
// Start address: 0x1ef5a0
void bhEne18_MV02(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 819, Address: 0x1ef5a0, Func Offset: 0
	// Line 820, Address: 0x1ef5ac, Func Offset: 0xc
	// Line 819, Address: 0x1ef5b4, Func Offset: 0x14
	// Line 820, Address: 0x1ef5b8, Func Offset: 0x18
	// Line 827, Address: 0x1ef5d8, Func Offset: 0x38
	// Line 829, Address: 0x1ef5f8, Func Offset: 0x58
	// Line 830, Address: 0x1ef604, Func Offset: 0x64
	// Line 831, Address: 0x1ef608, Func Offset: 0x68
	// Line 835, Address: 0x1ef614, Func Offset: 0x74
	// Line 834, Address: 0x1ef618, Func Offset: 0x78
	// Line 835, Address: 0x1ef61c, Func Offset: 0x7c
	// Line 836, Address: 0x1ef620, Func Offset: 0x80
	// Line 835, Address: 0x1ef624, Func Offset: 0x84
	// Line 836, Address: 0x1ef628, Func Offset: 0x88
	// Line 837, Address: 0x1ef630, Func Offset: 0x90
	// Line 838, Address: 0x1ef63c, Func Offset: 0x9c
	// Line 839, Address: 0x1ef668, Func Offset: 0xc8
	// Line 841, Address: 0x1ef67c, Func Offset: 0xdc
	// Line 843, Address: 0x1ef688, Func Offset: 0xe8
	// Line 844, Address: 0x1ef698, Func Offset: 0xf8
	// Line 845, Address: 0x1ef6b4, Func Offset: 0x114
	// Line 848, Address: 0x1ef6b8, Func Offset: 0x118
	// Line 845, Address: 0x1ef6c0, Func Offset: 0x120
	// Line 846, Address: 0x1ef6c8, Func Offset: 0x128
	// Line 848, Address: 0x1ef6d4, Func Offset: 0x134
	// Line 849, Address: 0x1ef6f0, Func Offset: 0x150
	// Line 850, Address: 0x1ef714, Func Offset: 0x174
	// Line 854, Address: 0x1ef718, Func Offset: 0x178
	// Line 850, Address: 0x1ef71c, Func Offset: 0x17c
	// Line 851, Address: 0x1ef724, Func Offset: 0x184
	// Line 852, Address: 0x1ef730, Func Offset: 0x190
	// Line 854, Address: 0x1ef73c, Func Offset: 0x19c
	// Line 855, Address: 0x1ef744, Func Offset: 0x1a4
	// Line 858, Address: 0x1ef74c, Func Offset: 0x1ac
	// Line 856, Address: 0x1ef758, Func Offset: 0x1b8
	// Line 860, Address: 0x1ef75c, Func Offset: 0x1bc
	// Line 856, Address: 0x1ef764, Func Offset: 0x1c4
	// Line 857, Address: 0x1ef76c, Func Offset: 0x1cc
	// Line 858, Address: 0x1ef778, Func Offset: 0x1d8
	// Line 860, Address: 0x1ef784, Func Offset: 0x1e4
	// Line 863, Address: 0x1ef79c, Func Offset: 0x1fc
	// Line 866, Address: 0x1ef7a0, Func Offset: 0x200
	// Line 863, Address: 0x1ef7a4, Func Offset: 0x204
	// Line 866, Address: 0x1ef7ac, Func Offset: 0x20c
	// Line 867, Address: 0x1ef7b8, Func Offset: 0x218
	// Line 870, Address: 0x1ef7c4, Func Offset: 0x224
	// Line 871, Address: 0x1ef7d4, Func Offset: 0x234
	// Line 872, Address: 0x1ef7e4, Func Offset: 0x244
	// Line 875, Address: 0x1ef7e8, Func Offset: 0x248
	// Line 876, Address: 0x1ef7ec, Func Offset: 0x24c
	// Line 879, Address: 0x1ef7f0, Func Offset: 0x250
	// Line 883, Address: 0x1ef7fc, Func Offset: 0x25c
	// Func End, Address: 0x1ef810, Func Offset: 0x270
}

// 
// Start address: 0x1ef810
void bhEne18_MV03()
{
	// Line 924, Address: 0x1ef810, Func Offset: 0
	// Func End, Address: 0x1ef818, Func Offset: 0x8
}

// 
// Start address: 0x1ef820
void bhEne18_MV04(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 934, Address: 0x1ef820, Func Offset: 0
	// Line 935, Address: 0x1ef82c, Func Offset: 0xc
	// Line 934, Address: 0x1ef834, Func Offset: 0x14
	// Line 935, Address: 0x1ef838, Func Offset: 0x18
	// Line 942, Address: 0x1ef858, Func Offset: 0x38
	// Line 944, Address: 0x1ef878, Func Offset: 0x58
	// Line 945, Address: 0x1ef884, Func Offset: 0x64
	// Line 946, Address: 0x1ef888, Func Offset: 0x68
	// Line 947, Address: 0x1ef894, Func Offset: 0x74
	// Line 951, Address: 0x1ef8a0, Func Offset: 0x80
	// Line 950, Address: 0x1ef8a4, Func Offset: 0x84
	// Line 951, Address: 0x1ef8a8, Func Offset: 0x88
	// Line 952, Address: 0x1ef8ac, Func Offset: 0x8c
	// Line 951, Address: 0x1ef8b0, Func Offset: 0x90
	// Line 952, Address: 0x1ef8b4, Func Offset: 0x94
	// Line 953, Address: 0x1ef8bc, Func Offset: 0x9c
	// Line 954, Address: 0x1ef8c8, Func Offset: 0xa8
	// Line 955, Address: 0x1ef8f4, Func Offset: 0xd4
	// Line 957, Address: 0x1ef908, Func Offset: 0xe8
	// Line 959, Address: 0x1ef914, Func Offset: 0xf4
	// Line 961, Address: 0x1ef924, Func Offset: 0x104
	// Line 962, Address: 0x1ef934, Func Offset: 0x114
	// Line 964, Address: 0x1ef93c, Func Offset: 0x11c
	// Line 966, Address: 0x1ef950, Func Offset: 0x130
	// Line 967, Address: 0x1ef970, Func Offset: 0x150
	// Line 970, Address: 0x1ef974, Func Offset: 0x154
	// Line 967, Address: 0x1ef97c, Func Offset: 0x15c
	// Line 968, Address: 0x1ef984, Func Offset: 0x164
	// Line 970, Address: 0x1ef990, Func Offset: 0x170
	// Line 971, Address: 0x1ef9ac, Func Offset: 0x18c
	// Line 972, Address: 0x1ef9d0, Func Offset: 0x1b0
	// Line 976, Address: 0x1ef9d4, Func Offset: 0x1b4
	// Line 972, Address: 0x1ef9d8, Func Offset: 0x1b8
	// Line 973, Address: 0x1ef9e0, Func Offset: 0x1c0
	// Line 974, Address: 0x1ef9ec, Func Offset: 0x1cc
	// Line 976, Address: 0x1ef9f8, Func Offset: 0x1d8
	// Line 977, Address: 0x1efa00, Func Offset: 0x1e0
	// Line 980, Address: 0x1efa08, Func Offset: 0x1e8
	// Line 978, Address: 0x1efa14, Func Offset: 0x1f4
	// Line 982, Address: 0x1efa18, Func Offset: 0x1f8
	// Line 978, Address: 0x1efa20, Func Offset: 0x200
	// Line 979, Address: 0x1efa28, Func Offset: 0x208
	// Line 980, Address: 0x1efa34, Func Offset: 0x214
	// Line 982, Address: 0x1efa40, Func Offset: 0x220
	// Line 985, Address: 0x1efa58, Func Offset: 0x238
	// Line 988, Address: 0x1efa5c, Func Offset: 0x23c
	// Line 985, Address: 0x1efa60, Func Offset: 0x240
	// Line 988, Address: 0x1efa68, Func Offset: 0x248
	// Line 989, Address: 0x1efa74, Func Offset: 0x254
	// Line 993, Address: 0x1efa80, Func Offset: 0x260
	// Line 994, Address: 0x1efa90, Func Offset: 0x270
	// Line 995, Address: 0x1efaa0, Func Offset: 0x280
	// Line 998, Address: 0x1efaa4, Func Offset: 0x284
	// Line 999, Address: 0x1efaa8, Func Offset: 0x288
	// Line 1002, Address: 0x1efaac, Func Offset: 0x28c
	// Line 1006, Address: 0x1efab8, Func Offset: 0x298
	// Func End, Address: 0x1efacc, Func Offset: 0x2ac
}

// 
// Start address: 0x1efad0
void bhEne18_MV05(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 1016, Address: 0x1efad0, Func Offset: 0
	// Line 1017, Address: 0x1efadc, Func Offset: 0xc
	// Line 1016, Address: 0x1efae4, Func Offset: 0x14
	// Line 1017, Address: 0x1efae8, Func Offset: 0x18
	// Line 1024, Address: 0x1efb08, Func Offset: 0x38
	// Line 1026, Address: 0x1efb28, Func Offset: 0x58
	// Line 1027, Address: 0x1efb34, Func Offset: 0x64
	// Line 1028, Address: 0x1efb38, Func Offset: 0x68
	// Line 1029, Address: 0x1efb44, Func Offset: 0x74
	// Line 1033, Address: 0x1efb50, Func Offset: 0x80
	// Line 1032, Address: 0x1efb54, Func Offset: 0x84
	// Line 1033, Address: 0x1efb58, Func Offset: 0x88
	// Line 1034, Address: 0x1efb5c, Func Offset: 0x8c
	// Line 1033, Address: 0x1efb60, Func Offset: 0x90
	// Line 1034, Address: 0x1efb64, Func Offset: 0x94
	// Line 1035, Address: 0x1efb6c, Func Offset: 0x9c
	// Line 1036, Address: 0x1efb78, Func Offset: 0xa8
	// Line 1037, Address: 0x1efba4, Func Offset: 0xd4
	// Line 1039, Address: 0x1efbb8, Func Offset: 0xe8
	// Line 1041, Address: 0x1efbc4, Func Offset: 0xf4
	// Line 1043, Address: 0x1efbd4, Func Offset: 0x104
	// Line 1044, Address: 0x1efbe4, Func Offset: 0x114
	// Line 1046, Address: 0x1efbec, Func Offset: 0x11c
	// Line 1048, Address: 0x1efc00, Func Offset: 0x130
	// Line 1049, Address: 0x1efc20, Func Offset: 0x150
	// Line 1052, Address: 0x1efc24, Func Offset: 0x154
	// Line 1049, Address: 0x1efc2c, Func Offset: 0x15c
	// Line 1050, Address: 0x1efc34, Func Offset: 0x164
	// Line 1052, Address: 0x1efc40, Func Offset: 0x170
	// Line 1053, Address: 0x1efc5c, Func Offset: 0x18c
	// Line 1054, Address: 0x1efc80, Func Offset: 0x1b0
	// Line 1058, Address: 0x1efc84, Func Offset: 0x1b4
	// Line 1054, Address: 0x1efc88, Func Offset: 0x1b8
	// Line 1055, Address: 0x1efc90, Func Offset: 0x1c0
	// Line 1056, Address: 0x1efc9c, Func Offset: 0x1cc
	// Line 1058, Address: 0x1efca8, Func Offset: 0x1d8
	// Line 1059, Address: 0x1efcb0, Func Offset: 0x1e0
	// Line 1062, Address: 0x1efcb8, Func Offset: 0x1e8
	// Line 1060, Address: 0x1efcc4, Func Offset: 0x1f4
	// Line 1064, Address: 0x1efcc8, Func Offset: 0x1f8
	// Line 1060, Address: 0x1efcd0, Func Offset: 0x200
	// Line 1061, Address: 0x1efcd8, Func Offset: 0x208
	// Line 1062, Address: 0x1efce4, Func Offset: 0x214
	// Line 1064, Address: 0x1efcf0, Func Offset: 0x220
	// Line 1067, Address: 0x1efd08, Func Offset: 0x238
	// Line 1070, Address: 0x1efd0c, Func Offset: 0x23c
	// Line 1067, Address: 0x1efd10, Func Offset: 0x240
	// Line 1070, Address: 0x1efd18, Func Offset: 0x248
	// Line 1071, Address: 0x1efd24, Func Offset: 0x254
	// Line 1075, Address: 0x1efd30, Func Offset: 0x260
	// Line 1076, Address: 0x1efd40, Func Offset: 0x270
	// Line 1077, Address: 0x1efd50, Func Offset: 0x280
	// Line 1080, Address: 0x1efd54, Func Offset: 0x284
	// Line 1081, Address: 0x1efd58, Func Offset: 0x288
	// Line 1084, Address: 0x1efd5c, Func Offset: 0x28c
	// Line 1088, Address: 0x1efd68, Func Offset: 0x298
	// Func End, Address: 0x1efd7c, Func Offset: 0x2ac
}

// 
// Start address: 0x1efd80
void bhEne18_Nage()
{
	// Line 1099, Address: 0x1efd80, Func Offset: 0
	// Func End, Address: 0x1efd88, Func Offset: 0x8
}

// 
// Start address: 0x1efd90
void bhEne18_Damage()
{
	// Line 1110, Address: 0x1efd90, Func Offset: 0
	// Func End, Address: 0x1efd98, Func Offset: 0x8
}

// 
// Start address: 0x1efda0
void bhEne18_Die(BH_PWORK* epw)
{
	// Line 1121, Address: 0x1efda0, Func Offset: 0
	// Line 1125, Address: 0x1efda4, Func Offset: 0x4
	// Line 1121, Address: 0x1efda8, Func Offset: 0x8
	// Line 1123, Address: 0x1efdb0, Func Offset: 0x10
	// Line 1124, Address: 0x1efdc0, Func Offset: 0x20
	// Line 1125, Address: 0x1efdc4, Func Offset: 0x24
	// Line 1126, Address: 0x1efdd0, Func Offset: 0x30
	// Line 1127, Address: 0x1efde4, Func Offset: 0x44
	// Func End, Address: 0x1efdec, Func Offset: 0x4c
}

// 
// Start address: 0x1efdf0
int bhEne18_HitMark(BH_PWORK* epw)
{
	_anon3* eop;
	_anon0* blp;
	_anon25 ofp;
	int i;
	int range;
	// Line 1137, Address: 0x1efdf0, Func Offset: 0
	// Line 1144, Address: 0x1efe00, Func Offset: 0x10
	// Line 1137, Address: 0x1efe04, Func Offset: 0x14
	// Line 1144, Address: 0x1efe08, Func Offset: 0x18
	// Line 1137, Address: 0x1efe0c, Func Offset: 0x1c
	// Line 1144, Address: 0x1efe18, Func Offset: 0x28
	// Line 1137, Address: 0x1efe24, Func Offset: 0x34
	// Line 1144, Address: 0x1efe28, Func Offset: 0x38
	// Line 1147, Address: 0x1efe30, Func Offset: 0x40
	// Line 1148, Address: 0x1efe38, Func Offset: 0x48
	// Line 1147, Address: 0x1efe3c, Func Offset: 0x4c
	// Line 1148, Address: 0x1efe50, Func Offset: 0x60
	// Line 1149, Address: 0x1efe54, Func Offset: 0x64
	// Line 1150, Address: 0x1efe64, Func Offset: 0x74
	// Line 1151, Address: 0x1efe74, Func Offset: 0x84
	// Line 1152, Address: 0x1efe9c, Func Offset: 0xac
	// Line 1154, Address: 0x1efee8, Func Offset: 0xf8
	// Line 1155, Address: 0x1efeec, Func Offset: 0xfc
	// Line 1152, Address: 0x1efef0, Func Offset: 0x100
	// Line 1153, Address: 0x1efef4, Func Offset: 0x104
	// Line 1154, Address: 0x1efefc, Func Offset: 0x10c
	// Line 1155, Address: 0x1eff04, Func Offset: 0x114
	// Line 1156, Address: 0x1eff0c, Func Offset: 0x11c
	// Line 1157, Address: 0x1eff4c, Func Offset: 0x15c
	// Line 1158, Address: 0x1eff8c, Func Offset: 0x19c
	// Line 1160, Address: 0x1effcc, Func Offset: 0x1dc
	// Line 1170, Address: 0x1efffc, Func Offset: 0x20c
	// Line 1171, Address: 0x1f002c, Func Offset: 0x23c
	// Line 1173, Address: 0x1f0034, Func Offset: 0x244
	// Line 1178, Address: 0x1f0064, Func Offset: 0x274
	// Line 1179, Address: 0x1f008c, Func Offset: 0x29c
	// Line 1183, Address: 0x1f00a0, Func Offset: 0x2b0
	// Line 1184, Address: 0x1f00e4, Func Offset: 0x2f4
	// Line 1185, Address: 0x1f00e8, Func Offset: 0x2f8
	// Line 1187, Address: 0x1f0134, Func Offset: 0x344
	// Line 1188, Address: 0x1f0138, Func Offset: 0x348
	// Line 1185, Address: 0x1f013c, Func Offset: 0x34c
	// Line 1186, Address: 0x1f0140, Func Offset: 0x350
	// Line 1187, Address: 0x1f0148, Func Offset: 0x358
	// Line 1188, Address: 0x1f0150, Func Offset: 0x360
	// Line 1189, Address: 0x1f0158, Func Offset: 0x368
	// Line 1190, Address: 0x1f0198, Func Offset: 0x3a8
	// Line 1191, Address: 0x1f01d8, Func Offset: 0x3e8
	// Line 1192, Address: 0x1f0214, Func Offset: 0x424
	// Line 1193, Address: 0x1f029c, Func Offset: 0x4ac
	// Line 1194, Address: 0x1f02ac, Func Offset: 0x4bc
	// Line 1196, Address: 0x1f02b0, Func Offset: 0x4c0
	// Line 1197, Address: 0x1f02e4, Func Offset: 0x4f4
	// Line 1199, Address: 0x1f0330, Func Offset: 0x540
	// Line 1197, Address: 0x1f0334, Func Offset: 0x544
	// Line 1198, Address: 0x1f0338, Func Offset: 0x548
	// Line 1200, Address: 0x1f033c, Func Offset: 0x54c
	// Line 1198, Address: 0x1f0340, Func Offset: 0x550
	// Line 1199, Address: 0x1f0344, Func Offset: 0x554
	// Line 1200, Address: 0x1f034c, Func Offset: 0x55c
	// Line 1201, Address: 0x1f0354, Func Offset: 0x564
	// Line 1202, Address: 0x1f0394, Func Offset: 0x5a4
	// Line 1203, Address: 0x1f03d4, Func Offset: 0x5e4
	// Line 1204, Address: 0x1f03f0, Func Offset: 0x600
	// Line 1203, Address: 0x1f03f4, Func Offset: 0x604
	// Line 1204, Address: 0x1f0418, Func Offset: 0x628
	// Line 1207, Address: 0x1f0424, Func Offset: 0x634
	// Line 1208, Address: 0x1f0428, Func Offset: 0x638
	// Func End, Address: 0x1f0450, Func Offset: 0x660
}*/

