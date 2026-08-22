#include "../../../ps2/veronica/prog/en26.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/en01b.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/player.h"

#pragma optimization_level 4

// ENEMY: Anatomist Zombie 

/*typedef struct BH_PWORK;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct npobj;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;

typedef void(*type_6)(BH_PWORK*);
typedef void(*type_29)(BH_PWORK*);
typedef void(*type_59)(BH_PWORK*, BH_PWORK*);
typedef void(*type_85)(BH_PWORK*);
typedef void(*type_104)(void*);
typedef void(*type_136)(BH_PWORK*);
typedef void(*type_142)(BH_PWORK*);

typedef _anon28 type_0[32];
typedef _anon0* type_1[512];
typedef _anon0* type_2[128];
typedef _anon0* type_3[128];
typedef _anon0* type_4[128];
typedef _anon0* type_5[512];
typedef void(*type_7)(BH_PWORK*)[16];
typedef _anon0* type_8[512];
typedef _anon44 type_9[21];
typedef unsigned char type_10[64];
typedef float type_11[16];
typedef _anon0* type_12[512];
typedef unsigned int type_13[4];
typedef _anon0* type_14[32];
typedef _anon0* type_15[512];
typedef _anon6* type_16[16];
typedef _anon0* type_17[32];
typedef _anon0* type_18[512];
typedef _anon6* type_19[16][16];
typedef _anon6* type_20[16][16][100];
typedef char type_21[8];
typedef _anon0* type_22[32];
typedef _anon0* type_23[512];
typedef _anon6* type_24[1300];
typedef _anon0* type_25[512];
typedef char type_26[32];
typedef _anon6* type_27[200];
typedef _anon7 type_28[18];
typedef short type_30[32];
typedef _anon19 type_31[1];
typedef void(*type_32)(BH_PWORK*)[6];
typedef unsigned int type_33[1];
typedef _anon6* type_34[8];
typedef int* type_35[16];
typedef _anon3 type_36[14];
typedef _anon5 type_37[256];
typedef npobj* type_38[16];
typedef _anon6* type_39[16];
typedef int type_40[4];
typedef _anon13 type_41[16];
typedef unsigned int type_42[4];
typedef _anon18 type_43[0];
typedef int type_44[8];
typedef int type_45[8][4];
typedef char type_46[256];
typedef float type_47[16][0];
typedef float type_48[4];
typedef float type_49[4];
typedef _anon10* type_50[128];
typedef float type_51[4];
typedef unsigned char type_52[64];
typedef float type_53[0];
typedef _anon12 type_54[20];
typedef char type_55[21];
typedef float type_56[0];
typedef char type_57[8];
typedef float type_58[0];
typedef void* type_60[2];
typedef void(*type_61)(BH_PWORK*, BH_PWORK*)[1];
typedef _anon6* type_62[256];
typedef _anon45 type_63[20];
typedef BH_PWORK type_64[0];
typedef unsigned char* type_65[256];
typedef int type_66[4];
typedef unsigned int type_67[2];
typedef short type_68[256];
typedef _anon0 type_69[0];
typedef float type_70[3];
typedef _anon29 type_71[4];
typedef short type_72[256];
typedef int type_73[3];
typedef int type_74[8];
typedef float type_75[3];
typedef _anon6* type_76[256];
typedef _anon11 type_77[256];
typedef _anon28 type_78[8];
typedef _anon7 type_79[6];
typedef _anon27 type_80[3];
typedef _anon19 type_81[450];
typedef _anon23 type_82[17];
typedef _anon24 type_83[16];
typedef _anon31 type_84[4];
typedef short type_86[256];
typedef void(*type_87)(BH_PWORK*)[1];
typedef int type_88[64];
typedef _anon13 type_89[450];
typedef char type_90[3];
typedef short type_91[4];
typedef float type_92[5];
typedef _anon37 type_93[4];
typedef int type_94[5];
typedef _anon1 type_95[4];
typedef int type_96[450];
typedef _anon25 type_97[22];
typedef unsigned int type_98[8];
typedef unsigned char type_99[450];
typedef _anon36 type_100[5];
typedef char type_101[16];
typedef char type_102[4];
typedef unsigned int type_103[3];
typedef unsigned int type_105[32];
typedef _anon4 type_106[16];
typedef unsigned int type_107[16];
typedef unsigned int type_108[16];
typedef int type_109[16];
typedef unsigned char type_110[2];
typedef int type_111[16][2];
typedef _anon34 type_112[64];
typedef unsigned int type_113[32];
typedef char type_114[32];
typedef _anon34 type_115[64];
typedef int type_116[4];
typedef unsigned int type_117[16];
typedef char type_118[64];
typedef _anon34 type_119[64];
typedef BH_PWORK* type_120[16];
typedef unsigned int type_121[8];
typedef unsigned int type_122[1];
typedef unsigned int type_123[384];
typedef _anon28 type_124[8];
typedef unsigned int type_125[2];
typedef int type_126[3];
typedef _anon21* type_127[16];
typedef unsigned int type_128[4];
typedef int* type_129[16];
typedef npobj* type_130[16];
typedef _anon6* type_131[16];
typedef char type_132[8];
typedef char type_133[4];
typedef char type_134[8][8];
typedef _anon13 type_135[16];
typedef short type_137[4];
typedef void(*type_138)(BH_PWORK*)[1];
typedef char type_139[5];
typedef unsigned char type_140[4];
typedef char type_141[8];
typedef _anon35 type_143[16];
typedef char type_144[8][12];
typedef void(*type_145)(BH_PWORK*)[17];
typedef unsigned int type_146[32];
typedef _anon0* type_147[128];

struct BH_PWORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon6* txp[16];
	_anon13 mdl[16];
	_anon13* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon10* mnwP;
	_anon10* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	int wpnr_no;
	int wpnl_no;
	unsigned int at_flg;
	_anon43 watr;
	_anon23* cpcl;
	short wax;
	short way;
	short waz;
	short waxp;
	short wayp;
	short wazp;
	int hp;
	int dam[64];
	int djnt_no;
	int cpcl_no;
	int dax;
	int day;
	float dpx;
	float dpy;
	float dpz;
	float dvx;
	float dvy;
	float dvz;
	int flr_snd;
	int ko_num;
	int footeff;
	int src_no;
	unsigned char* kdnp;
	int kdnidx;
	void* dan_ap;
	unsigned int comb_flg;
	unsigned int comb_wep;
	int comb_pnt;
	int comb_timeout;
	int total_dam;
	unsigned int Dummy2[2];
};

struct _anon0
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon6* txp[16];
	_anon13 mdl[16];
	_anon13* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon10* mnwP;
	_anon10* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	unsigned char* objbak;
	_anon42 cspr;
	int pn;
	_anon37* pvp;
	_anon1* tvp;
	_anon37 pv[4];
	_anon1 tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
};

struct _anon1
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon2
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	_anon26* light;
};

struct _anon3
{
	int obj;
	float size;
	float len;
	_anon28 ofs;
};

struct npobj
{
	unsigned int evalflags;
	_anon30* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon4
{
	int no;
	_anon27 fmtn[3];
};

struct _anon5
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon6
{
	_anon19* textures;
	unsigned int nbTexture;
};

struct _anon7
{
	int no;
	_anon31 atb[4];
};

struct _anon8
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon9
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};

struct _anon10
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon22* md2P;
	unsigned short* atrP;
};

struct _anon11
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon12
{
	int lnk_obj;
	float x;
	float y;
	float z;
	float xlen;
	float ylen;
	float size;
	float len;
};

struct _anon13
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon6* texP;
	_anon8* owP;
};

struct _anon14
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon40* info;
};

struct _anon15
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
};

struct _anon16
{
	void* texaddr;
	_anon9 texsurface;
};

struct _anon17
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int sys_partid;
	unsigned int itm_partid;
	unsigned int fil_partid;
	unsigned int dor_partid;
	unsigned int ss_flg;
	int pdm_no;
	unsigned int typ_flg;
	unsigned short typ_md0;
	unsigned short typ_md1;
	void* typ_exp;
	unsigned int tk_flg;
	unsigned int ts_flg;
	unsigned int gm_flg;
	unsigned int st_flg;
	unsigned int cb_flg;
	unsigned int rm_flg;
	unsigned int pt_flg;
	unsigned int sp_flg;
	unsigned int ef_flg;
	unsigned int error;
	unsigned int version;
	int save_ct;
	char ply_id;
	char stg_no;
	char rom_no;
	char rcase;
	char pos_no;
	char cut_no;
	char flr_no;
	char reserve0;
	int gm_mode;
	unsigned int ev_flg[32];
	unsigned int it_flg[16];
	unsigned int ic_flg[16];
	unsigned int ed_flg[32];
	unsigned int ky_flg[16];
	unsigned int mp_flg[8];
	unsigned int itm[384];
	unsigned int ply_stflg[4];
	_anon28 ply_pos;
	int ply_ang;
	char ply_wno[4];
	short ply_hp[4];
	unsigned char evt_posno[4];
	int time;
	int stv_tm;
	short spray_ct;
	short retry_ct;
	short clear_ct;
	short reserve1;
	unsigned int save_end;
	char stg_nob;
	char rom_nob;
	char pos_nob;
	char rcase_b;
	unsigned int en_flg[4];
	_anon6* et_lp[16][16][100];
	_anon6* ot_lp[1300];
	_anon6* it_lp[200];
	int eft_n;
	_anon6* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon14* p1per;
	_anon14* p2per;
	_anon14* kbper;
	_anon14* msper;
	_anon14 ms_per;
	int pad_port;
	unsigned int pad_on;
	unsigned int pad_oncpy;
	unsigned int pad_ps;
	unsigned int pad_rs;
	unsigned int pad_old;
	unsigned int pad_onb;
	unsigned int pad_psb;
	unsigned int pad_oldb;
	short pad_ax;
	short pad_ay;
	short pad_dx;
	short pad_dy;
	unsigned short pad_ar;
	unsigned short pad_al;
	int fixcno;
	int fixkno;
	unsigned int exm_attr;
	short evc_no;
	short evc_kn;
	short evc_ono;
	short evc_okn;
	int evc_sc;
	unsigned char mn_mode0;
	unsigned char mn_mode1;
	unsigned char mn_mode2;
	unsigned char mn_mode3;
	unsigned char mn_md0;
	unsigned char mn_md1;
	unsigned char mn_md2;
	unsigned char mn_md3;
	int mn_setct;
	unsigned int mn_stack[8];
	unsigned int sdm_flg;
	unsigned int sdm_mode;
	unsigned char* ltc_bp;
	unsigned int ltc_tsbak;
	int ewk_n;
	unsigned int enow;
	unsigned int onow;
	unsigned int efnow;
	int vsyc_ct;
	int vsyc_flg;
	int fog_ct;
	int bcl_ct;
	int gfrm_ct;
	int gframe;
	int eor_ct;
	unsigned int pfm_cts;
	int evt_tmd;
	int evt_tim;
	int evt_tdg;
	int evt_fcd;
	unsigned int evt_fcdct;
	unsigned int fsize;
	unsigned int rdtsz;
	unsigned char* memp;
	unsigned char* mempb;
	unsigned char* endp;
	unsigned char* rdtp;
	unsigned char* plmdlp;
	unsigned char* lmmdlp;
	unsigned char* wrmdlp;
	unsigned char* wlmdlp;
	unsigned char* plmthp;
	unsigned char* plbmtp;
	unsigned char* plwmtp;
	unsigned char* plzmtp;
	unsigned char* plemtp;
	unsigned char* plexwp;
	unsigned char* plhdwp;
	unsigned char* pletcp;
	unsigned char* subtxp;
	unsigned char* doordp;
	unsigned char* sbs_sp;
	_anon0* obwp;
	_anon0* itwp;
	_anon10* emtp[128];
	_anon10* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon6* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon6* txblp[256];
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon19 ef_tex[450];
	_anon6 ef_tlist;
	_anon39 ef;
	short efid[256];
	_anon13 efm[450];
	int ef_ct;
	int ef_ctb;
	int ef_extn;
	int ef_tn[450];
	unsigned char ef_pbkb[450];
	int ef_pbnk;
	int ef_slow;
	int ef_ctrn;
	int yk_ct;
	int mg_ct;
	int bl_ct;
	int windr;
	float winds;
	int windrb;
	float windsb;
	unsigned int thunder;
	float gas_py;
	int en_objn;
	BH_PWORK* en_obj[16];
	int ef_poln;
	int ef_mdfn;
	int ef_linn;
	int ef_ntxn;
	int ef_trsn;
	int ef_pncn;
	int ef_opqn;
	int ef_thln;
	int ef_ntx2dn;
	int ef_trs2dn;
	int ef_pnc2dn;
	int ef_fncn;
	_anon0* ef_pol[512];
	_anon0* ef_mdf[128];
	_anon0* ef_lin[512];
	_anon0* ef_ntx[512];
	_anon0* ef_trs[512];
	_anon0* ef_pnc[512];
	_anon0* ef_opq[512];
	_anon0* ef_thl[512];
	_anon0* ef_ntx2d[128];
	_anon0* ef_trs2d[128];
	_anon0* ef_pnc2d[128];
	_anon0* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon0* ob_nlg[32];
	_anon0* ob_hlg[32];
	_anon0* ob_spc[32];
	unsigned int ren_gid;
	_anon16 ren_info;
	_anon19 ren_tex[1];
	_anon6 ren_tlist;
	_anon5 rpb[256];
	int ren_n;
	int ren_idx[4];
	int wt_nbpt;
	float wt_px;
	float wt_pz;
	int wt_xp;
	int wt_zp;
	int wt_minx;
	int wt_minz;
	int wt_maxx;
	int wt_maxz;
	unsigned char* wt_wvp;
	_anon38 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon2* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon29 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon24 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon34* pl_htp;
	int costume;
	_anon28 hd_pos;
	_anon28 apos;
	_anon34* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon34 mwalp[64];
	_anon34 metcp[64];
	_anon34 mflrp[64];
	int dla_n;
	_anon34* htp;
	int psh_snd;
	int fog_cngct;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float fade_ct;
	float fade_hkn;
	float fade_ao;
	float fade_an;
	float fade_ap;
	float fade_ro;
	float fade_rn;
	float fade_rp;
	float fade_go;
	float fade_gn;
	float fade_gp;
	float fade_bo;
	float fade_bn;
	float fade_bp;
	unsigned int fade_pbk;
	unsigned short ssv_md0;
	unsigned short ssv_md1;
	int ssv_tim;
	float ssv_ct;
	float ssv_hkn;
	float ssv_ao;
	float ssv_an;
	float ssv_ap;
	short fil_no;
	short fil_rt;
	float rvf_sc;
	float rvf_sn;
	unsigned int rvfc[4];
	float cine_an;
	float cine_ap;
	unsigned int sco_flg;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
	int sb_id;
	int sb_cmd;
	int sb_rdid;
	int sb_rdsz;
	void* sb_rdp;
	void* sb_mlb;
	void* sb_ppp;
	_anon6* sb_tlist;
	int ddmd;
	_anon15 door;
	int mpmd;
	int mp_prm[4];
	unsigned short gov_md0;
	unsigned short gov_md1;
	int gov_ct;
	void* gov_exp;
	unsigned int com_flg;
	unsigned short com_md0;
	unsigned short com_md1;
	unsigned int com_num;
	void* com_exp;
	short ond_tnm;
	short ond_ud;
	char ond_cx;
	char ond_n[3];
	unsigned char ufo_md;
	unsigned char ufo_flg;
	short ufo_oidx;
	_anon28 ufo_pos;
	unsigned int opt_flg;
	unsigned short opt_md0;
	unsigned short opt_md1;
	void* opt_exp;
	unsigned int etc_idx;
	unsigned int flr_idx;
	int mvi_no;
	int mvi_tp;
	unsigned short mvi_md;
	unsigned short mvi_flg;
	unsigned int mvi_tsb;
	unsigned int mvi_spb;
	unsigned char* mvi_memp;
	unsigned int dcg_tkbak;
	unsigned int dcg_tsbak;
	unsigned int pau_spbak;
	unsigned int pau_pad_on;
	unsigned int pau_pad_ps;
	unsigned int pau_pad_old;
	unsigned char* pdm_dp;
	unsigned char* pdm_pd;
	int pdm_keytpb;
	int gat_ct;
	_anon35 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon28 ghtp[32];
	unsigned short db_md0;
	unsigned short db_md1;
	char db_stgno;
	char db_romno;
	char db_rcase;
	char db_muteki;
	short db_px;
	short db_py;
	int db_mes;
	int calc_v;
	unsigned int brkfg;
	char brkfg_typ[32];
	short brkfg_bit[32];
	unsigned int brkfg_tkb;
	unsigned int brkfg_tsb;
	int brkfg_ct;
	unsigned int bmt_size;
	unsigned int lmt_size;
	unsigned int emt_size;
	unsigned int wmt_size;
	char mes[256];
	float sfx;
	float sfy;
	float sfxn;
	float sfyn;
	float sfct;
};

struct _anon18
{
	unsigned int flg;
	unsigned int atack_ct;
	unsigned int fend_ct;
	unsigned int at_cct;
	short ef_yct;
	short act_ct0;
	short act_ct1;
	short act_ct2;
	float r;
	float l;
	float rn;
	float rmax;
	_anon28 wp_fps1;
	_anon28 wp_fps2;
	_anon28 wp_cps;
	unsigned char ltp;
	unsigned char lr;
	unsigned char lg;
	unsigned char lb;
	unsigned short lnr;
	unsigned short lfr;
	float hrate;
	float ef_scale;
	short snd_wpno;
	short hiteff;
	unsigned short seno0;
	unsigned short seno1;
	char vib_tp;
	char vib_ct;
	char reserve1;
	char reserve2;
};

struct _anon19
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon20
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon21
{
	float x;
	float z;
};

struct _anon22
{
	void* p[2];
};

struct _anon23
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon24
{
	float x;
	float y;
};

struct _anon25
{
	int flg;
	int nm_act;
	int nm_blood;
	int cb_act;
	int cb_blood;
	int dw_act;
	int dw_blood;
};

struct _anon26
{
	float mtrx[16];
	_anon28 pnt;
	_anon28 vctr;
	int stat;
	int reserve;
	_anon32 ltcal;
	_anon41 attr;
};

struct _anon27
{
	int type;
	int s_frm;
	int e_frm;
};

struct _anon28
{
	float x;
	float y;
	float z;
};

struct _anon29
{
	_anon28 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon30
{
	int* vlist;
	short* plist;
	_anon28 center;
	float r;
};

struct _anon31
{
	int frm;
	unsigned int act;
};

struct _anon32
{
	float ratten;
	float ipd;
	float nrr;
	float frr;
	float cosi;
	float cose;
	float idev;
	float odev;
	float rate;
	float intns;
	int exp;
	int reserve;
	_anon28 lpnt;
	_anon28 lvctr;
	_anon28 lmvctr;
	_anon20 atten;
	_anon20 amb;
	_anon20 dif;
	_anon20 spc;
	_anon20 mamb;
	_anon20 mdif;
	_anon20 mspc;
};

struct _anon33
{
	_anon28 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon34
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
};

struct _anon35
{
	_anon28 c1;
	_anon28 c2;
	float r1;
	float r2;
};

struct _anon36
{
	int mtn_no;
	short frm[4];
};

*/

/*

struct _anon37
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon38
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon39
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
};

struct _anon40
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon41
{
	int lsrc;
	float iamb;
	float idif;
	float ispc;
	float nrang;
	float frang;
	void* func;
	int iang;
	int oang;
	_anon20 argb;
};

struct _anon42
{
	_anon28 c;
	float r;
};

struct _anon43
{
	_anon28 c1;
	_anon28 c2;
	float r;
};

struct _anon44 COMBWEP_WORK
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon45
{
	int flg;
	int correct;
};
*/

int En26_PlyMtn_OffsetTbl[4] =
{
    0x64, 0x64, 0x64, 0x64
};

const char en26_flipTree[21] =
{
    0x00, 0x01, 0x06, 0x07, 0x08, 0x09, 0x02, 0x03, 0x04, 0x05,
    0x0A, 0x0B, 0x0C, 0x0D, 0x11, 0x12, 0x13, 0x0E, 0x0F, 0x10,
    0xFF
};
/*
_anon4 en26_mtn_tbl[16];
_anon7 en26_mtn_tbl2[18];
_anon7 en26_mtn_tbl3[6];
*/
const char en26_tree[8][8] =
{
    { 0x00, 0x01, 0x06, 0x07, 0x08, 0xFF, 0x00, 0x00 }, 
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0xFF, 0x00, 0x00 }, 
    { 0x00, 0x01, 0x0A, 0x0B, 0x11, 0x12, 0x13, 0xFF }, 
    { 0x00, 0x01, 0x0A, 0x0B, 0x0E, 0x0F, 0x10, 0xFF }, 
    { 0x0A, 0x0B, 0x11, 0x12, 0x13, 0xFF, 0x00, 0x00 },
    { 0x0A, 0x0B, 0x0E, 0x0F, 0x10, 0xFF, 0x00, 0x00 },
    { 0x00, 0x01, 0x06, 0x07, 0xFF, 0x00, 0x00, 0x00 },
    { 0x00, 0x01, 0x0A, 0x0B, 0x0C, 0xFF, 0x00, 0x00 }
};

EN26_WPNDAMAGE_WORK En26_WpnDamageTbl[22] =
{
    {0x0000, 0, 0, 0, 0, 0, 0},
    {0x0000, 0, 0, 0, 0, 0, 0},
    {0x0C02, 0, 3, 2, 3, 5, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0112, 2, 7, 2, 3, 3, 3},
    {0x0112, 0, 1, 2, 3, 3, 3},
    {0x0EC2, 0, 7, 2, 3, 5, 3},
    {0x0FC2, 0, 7, 2, 3, 3, 3},
    {0x0FC2, 4, 7, 2, 3, 3, 3},
    {0x0039, 2, 9, 2, 9, 3, 9},
    {0x0EC2, 0, 7, 2, 3, 5, 3},
    {0x011D, 2, 3, 2, 3, 3, 3},
    {0x111C, 2, 1, 2, 3, 3, 3}, 
    {0xC100, 0, 1, 2, 3, 3, 3},
    {0x511C, 0, 1, 2, 3, 3, 3},
    {0x4000, 0, 1, 2, 3, 3, 3},
    {0x6000, 2, 1, 2, 3, 3, 3},
    {0x111C, 2, 1, 2, 3, 3, 3},
    {0x6000, 2, 1, 2, 3, 3, 3},
    {0x0FC2, 0, 1, 2, 3, 3, 3}
};

static COMBWEP_WORK CombWepTbl[21] =
{
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x5A, { 0x0A, 0x00, 0x00 }, 0x5A, 0x05 },
    { 0x19, { 0x09, 0x05, 0x04 }, 0x3C, 0x00 },
    { 0x19, { 0x09, 0x05, 0x04 }, 0x3C, 0x00 },
    { 0x19, { 0x09, 0x05, 0x04 }, 0x3C, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x19, { 0x09, 0x05, 0x04 }, 0x3C, 0x00 },
    { 0xB4, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x19, { 0x09, 0x05, 0x04 }, 0x00, 0x00 },
    { 0x28, { 0x08, 0x05, 0x04 }, 0x28, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x64, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 },
    { 0x00, { 0x00, 0x00, 0x00 }, 0x00, 0x00 }
};

static COMBJOINT_WORK CombJointTbl[20] =
{
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 }
};

/*
int en26_hp_tbl[16][2];
*/

EN26_FIRE_WORK en26_fire_tbl[14] =
{
    { 0x0B, 2.5f, 1.0f, {  0.5f,  3.0f, -1.0f } },
    { 0x0B, 1.5f, 1.0f, { -0.5f,  1.0f, -1.0f } },
    { 0x0B, 4.0f, 1.0f, {  0.5f,  2.5f,  1.0f } },
    { 0x0B, 2.0f, 1.0f, { -0.5f,  1.0f,  1.0f } },
    { 0x0E, 2.5f, 1.0f, {  0.0f,  0.0f,  0.0f } },
    { 0x0F, 2.0f, 1.0f, {  0.0f,  0.0f,  0.0f } },
    { 0x11, 2.0f, 1.0f, {  0.5f, -0.5f,  0.0f } },
    { 0x11, 2.5f, 1.0f, { -1.0f,  0.0f,  0.0f } },
    { 0x02, 1.5f, 2.0f, {  0.0f, -0.5f,  0.0f } },
    { 0x03, 2.5f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    { 0x04, 2.0f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    { 0x06, 3.0f, 1.0f, {  0.0f, -3.0f, -1.0f } },
    { 0x08, 2.5f, 1.5f, {  0.0f,  0.0f,  0.0f } },
    { 0x09, 3.0f, 1.0f, {  0.0f, -2.0f,  0.5f } },
};

CPCL Ene26CapColTab[17] =
{
    {  1, 11, 16 },
    { 11, 11, 18 }, 
    {  0, 16,  0 }, 
    { 11, 11, 18 }, 
    {  0, 30,  0 }, 
    { 12, 13,  6 }, 
    { 13, 13, 11 },
    {  0,  9, -2 },
    { 14, 15,  6 }, 
    { 15, 16,  5 }, 
    { 17, 18,  6 },
    { 18, 19,  5 },
    {  2,  3,  9 },
    {  3,  4,  8 },
    {  6,  7,  9 },
    {  7,  8,  8 },
    {  0,  0,  0 }
};

char En26SdwTab[5] =
{
    0x00, 0x03, 0x04, 0x0C, 0xFF
};

BT_WORK en26prt_blood_tbl[20] =
{
    // lnk_obj,   x,      y,      z,     xlen,   ylen,   size,   len
    {      0,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f }, // [0]
    {     11,   0.0f,   2.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, // [1]
    {      2,   0.0f,   0.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, // [2]
    {      3,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [3]
    {      4,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [4]
    {      3,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [5]
    {      6,   0.0f,   0.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, // [6]
    {      7,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [7]
    {      8,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [8]
    {      7,   0.0f,   2.0f,   1.0f,   1.0f,   2.0f,   5.0f,   1.5f }, // [9]
    {      0,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f }, // [10]
    {     11,   0.0f,   3.0f,   1.8f,   2.0f,   2.0f,   5.0f,   1.5f }, // [11]
    {     11,   0.0f,   3.5f,   1.8f,   2.0f,   1.0f,   5.0f,   1.5f }, // [12]
    {     11,   0.0f,   3.5f,   1.8f,   2.0f,   1.0f,   5.0f,   1.5f }, // [13]
    {     14,   0.0f,   0.0f,   0.5f,   0.2f,   0.5f,   5.0f,   1.5f }, // [14]
    {     15,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, // [15]
    {     16,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, // [16]
    {     17,   0.0f,   0.0f,   0.5f,   0.2f,   0.5f,   5.0f,   1.5f }, // [17]
    {     18,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }, // [18]
    {     19,   0.0f,   1.0f,   0.3f,   0.2f,   1.0f,   5.0f,   1.5f }  // [19]
};

EN26_KAMI_WORK en26_keff_tbl[5] =
{
    { 0x02, { 0x1C, 0x26, 0x3E, -1 } },
    { 0x0C, { 0x18, 0x26, 0x3C, -1 } },
    { 0x09, { 0x19, 0x2F, 0x42, -1 } },
    { 0x0E, { 0x09, 0x20, -1, -1 } },
    { -1, { -1, -1, -1, -1 } }
};

void (*bhEne26_Mode0[6])(BH_PWORK *) =
{
    bhEne26_Init,
    bhEne26_Move,
    bhEne26_Nage,
    bhEne26_Damage,
    bhEne26_Die,
    bhEne_Event
};

void(*bhEne26_MoveMode2[17])(BH_PWORK*) =
{
    bhEne26_MV00,
    bhEne26_MV01,
    bhEne26_MV02,
    bhEne26_MV03,   
    NULL,
    bhEne26_MV05,     
    bhEne26_MV06,
    bhEne26_MV07,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,    
    bhEne26_MV16 
};

void(*bhEne26_NageMode2[1])(BH_PWORK*) =
{
    bhEne26_NG00
};

void (*bhEne26_DamageMode2[16])(BH_PWORK*) =
{
    bhEne26_DG00, 
    bhEne26_DG01, 
    bhEne26_DG02, 
    bhEne26_DG03, 
    bhEne26_DG04, 
    NULL,         
    NULL, 
    NULL,
    NULL, 
    NULL,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    bhEne26_DG15
};

void(*bhEne26_DieMode2[1])(BH_PWORK*) =
{
    bhEne26_DD00
};

void(*bhEne26_PlyDmgMode[1])(BH_PWORK*, BH_PWORK*) =
{
    bhEne26_PlyDG00
};
/*
BH_PWORK* plp;
_anon18 WpnTab[0];
_anon0 eff[0];
_anon17* sys;
float en01_mogmog[0];
float en01_kamikami2[0];
float en01_kamikami[0];
BH_PWORK ene[0];
float lcmat[16][0];
_anon33 en01_BldTbl;*/

// 100% matching!
void bhEne26(BH_PWORK* epw)
{
    bhEne26_DmgCheck(epw);
    bhEne26_MainLoop(epw, plp);

    if (epw->flg & 4)
    {
        epw->flg = epw->flg & ~4;
    }

    if (EXP0_UC(0x2F) > 0)
    {
        EXP0_UC(0x2F)--;
    }

    if (EXP0_I(0x30) > 0)
    {
        EXP0_I(0x30)--;
    }

    if (EXP0_I(0x34) > 0)
    {
        EXP0_I(0x34)--;
    }
    bhEne26_CollCheck(epw);
    
    if (EXP0_I(0x40) & 0x80000)
    {
        bhEne26_PlayerLink(epw, plp);
    }
    
    bhEne26_CalcEnemy(epw);
}

// 100% matching!
void bhEne26_DmgCheck(BH_PWORK* epw)
{
    int ang;

    if ((epw->flg & 0x4) && !(epw->flg & 0x2) && (bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl), (epw->total_dam != 0)))         
    {    
        if ((EXP0_I(0x44) & 0x40) &&
        (epw->flr_no <= plp->flr_no) &&
        !(WpnTab[epw->wpnr_no].flg & 0x20) &&
        !(WpnTab[epw->wpnr_no].flg & 0x20000000) &&
        (plp->at_flg & 0x2))
        {
            return;
        }

        bhEne26_DamageAdd(epw, En26_WpnDamageTbl);
    
        if ((epw->mode0 >= 3) ||
            (EXP0_I(0x40) & 0x80) ||
            (EXP0_I(0x40) & 0x40000) && (epw->mode0 == 1) && (epw->mode3 == 0))
        {
            return;
        }
   
        EXP0_I(0x40) |= 0x200400;
        EXP0_I(0x48) = 0;
    
        if (epw->comb_flg & 4)
        {
            EXP0_I(0x40) |= 0x2000;
        } 
        else
        {
            EXP0_I(0x40) &= ~0x2000;
        }
    
        ang = njArcTan2(epw->dvx, epw->dvz);
    
        if ((unsigned short)(ang - epw->ay) <= NJM_DEG_ANG(180.0f))
        {
            EXP0_I(0x44) |= 0x20;
        } 
        else
        {
            EXP0_I(0x44) &= ~0x20;
        }
    
        bhEne26_DmgCheckType00(epw, En26_WpnDamageTbl);
        
        if (EXP0_I(0x78) != -1)
        {
            if (epw->hp < 0)
            {
                bhEne26_SePlay(epw, 16786197);
            } 
            else
            {
                bhEne26_SePlay(epw, 16786196);
            }
        }
        bhEne26_SetBlood(epw, En26_WpnDamageTbl);
    } 
}

// 100% matching!
void bhEne26_DamageAdd(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
	int* d;
	int low_flg;    
	int i;
 
    low_flg = 0;
    if (epw->hp >= 0)
    {
        epw->hp -= epw->total_dam;
    }

    wp_tbl += epw->comb_wep;

    for (d = &epw->dam[1], i = 1; i < (int)epw->mlwP->obj_num; i++, d++)
    {
        if (*d > 0)
        {
            if (epw->djnt_no == 3 || epw->djnt_no == 4 ||
                epw->djnt_no == 7 || epw->djnt_no == 8)
            {
                low_flg = 1;
            }
            if (epw->djnt_no == 13)
            {
                EXP0_I(0x78) += *d;
            }
        }
    }
    
    if ((wp_tbl->flg & 0x8000) && (EXP0_I(0x34) <= 0))
    {
        bhEne_SetSanEffect(epw, epw->djnt_no, en26prt_blood_tbl);
        EXP0_I(0x34) = 10;
    }

    if (wp_tbl->flg & 0x1000)
    {
        if (low_flg == 0)
        {
            bhEne26_LinkFireEffect(epw, (rand() % 4) + 4);
        }
        else
        {         
            bhEne26_LinkFireEffect(epw, (rand() % 4) + 8);
        }
        EXP0_I(0x40) |= 0x10000;
    }
    else if (wp_tbl->flg & 0x2000)
    {
        bhEne26_LinkFireEffect(epw, (rand() % 4) + 4);
        EXP0_I(0x40) |= 0x10000;
        EXP0_I(0x3C) = 0xFF000000U;
        epw->mdflg |= 0x400;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, EXP0_I(0x3C));
    }
}

// 100% matching!
void bhEne26_LinkFireEffect(BH_PWORK* epw, int type)
{
    EN26_FIRE_WORK* eff_p;
    char* ftbl_p;
    int eno;
    int i;   
    int time;
    int flg;  

    char fire_tbl[12][8] =
    {
        { 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x08, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x05, 0x06, 0x09, 0xFF },
        { 0x00, 0x01, 0x02, 0x03, 0x04, 0x07, 0x0B, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x05, 0x07, 0x0C, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0xFF, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x05, 0x06, 0xFF, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x04, 0x07, 0xFF, 0xFF }, 
        { 0x00, 0x01, 0x02, 0x03, 0x05, 0x07, 0xFF, 0xFF },
        { 0x0B, 0x0A, 0x0D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, 
        { 0x08, 0x0A, 0x0D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
        { 0x09, 0x0A, 0x0D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
        { 0x0A, 0x0C, 0x0D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }
    };

    sys->ef.id = 352;
    sys->ef.type = 0;
    sys->ef.flg = 1;
    sys->ef.sz = 0.0f;
    sys->ef.px = 0.0f;
    sys->ef.py = 0.0f;
    sys->ef.pz = 0.0f;
    sys->ef.ay = 0;
    
    for (i = 0, ftbl_p = fire_tbl[type]; i < 8; i++, ftbl_p++)
    {
        eff_p = &en26_fire_tbl[*ftbl_p];
        if (*ftbl_p != -1)
        {
            flg = 1 << *ftbl_p;
            if (!(EXP0_I(0x38) & flg))
            {
                EXP0_I(0x38) |= flg;
                time = rand() % 5;
                sys->ef.sy = sys->ef.sx = eff_p->size;
                sys->ef.type = 0;
                eno = bhSetEffectTb(&sys->ef, &eff_p->ofs, (unsigned char*)epw, eff_p->obj);
                if (eno != -1)
                {
                    eff[eno].zn = eff_p->len;
                    eff[eno].ct3 = time;
                }
                sys->ef.type = 1;
                eno = bhSetEffectTb(&sys->ef, &eff_p->ofs, (unsigned char*)epw, eff_p->obj);
                if (eno != -1)
                {
                    eff[eno].zn = eff_p->len;
                    eff[eno].ct3 = time;
                }
            }
        }
    } 
}

// 100% matching!
void bhEne26_DmgCheckType00(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
    int act;

    // not present in DWARF
    EN26_WPNDAMAGE_WORK* wp;
    
    wp = &wp_tbl[epw->wpnr_no];
    act = wp->nm_act;
    if ((wp->flg & 0x10) && !(EXP0_I(0x40) & 0x440000) && (bhEne26_CheckExpHead(epw) != 0))
    {
        epw->hp = -1;
        bhEne26_ExpHeadEffect(epw, 0);
        bhEne26_NeckBloodEffect(epw, 0);
        EXP0_I(0x78) = -1;
        bhEne26_SePlay(epw, 4869);
    }
    
    if (epw->hp < 0)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        act = wp->dw_act;
    } 
    else if (epw->comb_flg & 1)
    {
        epw->comb_pnt = 0;
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        act = wp->cb_act;
    }
    
    if (act == 0)
    {
        if (!(EXP0_I(0x40) & 0x8000000))
        {
            EXP0_I(0x40) |= 0x8000000;
            EXP0_UC(0x2C) = 0;
        }
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
    else if (act == 5)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 3;
        epw->mode3 = 0;
    }
    else if (act == 3)
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;

        if ((wp->flg & 0x100) && (epw->hp > 0))
        {
            if (rand() % 10 >= 3)
            {
                epw->mode2 = 2;
                return;
            }
        }

        if (epw->comb_flg & 4)
        {
            if (wp->flg & 0x200)
            {
                epw->mode2 = (rand() % 3 == 0) ? 3 : 4;
            } 
            else
            {
                epw->mode2 = 4;
            }
        } 
        else
        {
            epw->mode2 = 3;
        }

    }
}

// 100% matching!
int bhEne26_CheckExpHead(BH_PWORK* epw)
{
    if (EXP0_I(0x78) > 0)
    {
        return 1;
    }

    switch (epw->wpnr_no)
    {
    case 11:
    case 14:
        if ((epw->flr_no == plp->flr_no) && (EXP0_F(0x54) < 10.0f) && (plp->at_flg & 4))
        {
            return 1;
        }
        break;
        
    case 6:
        if (((epw->flr_no == plp->flr_no) &&
             (epw->comb_flg & 0x10)) &&
             (plp->at_flg & 6) &&
             (epw->djnt_no == 1 || ((epw->djnt_no == 10) || epw->djnt_no == 11 || epw->djnt_no == 12 || epw->djnt_no == 13)))
        {
          return 1;
        }
        break;
        
    case 19:
        if (((epw->djnt_no >= 10) && (19 >= epw->djnt_no)) || (epw->djnt_no == 1))
        {
          return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne26_SetBlood(BH_PWORK* epw, EN26_WPNDAMAGE_WORK* wp_tbl)
{
	O_WORK* owk;
	NJS_POINT3 ofp;    
	int obj_no;

    // not from DWARF
    EN26_WPNDAMAGE_WORK* wp;
    
    wp = &wp_tbl[epw->wpnr_no];
    if (!(wp->flg & 0x4000))
    {
        if ((epw->djnt_no == 11) || (epw->djnt_no == 1) || (epw->djnt_no == 10))
        {
            ofp.x = -epw->dvx;
            ofp.y = -epw->dvy;
            ofp.z = -epw->dvz;
            bhLinkBlood(epw, epw->djnt_no, &ofp, 0.5f);
        }
        
        if ((epw->comb_flg & 1) || (epw->hp < 0))
        {
            if ((EXP0_I(0x30) <= 0) && (EXP0_I(0x78) != -1))
            {
                EXP0_I(0x30) = 20;

                if ((1 < epw->djnt_no) && (epw->djnt_no < 10))
                {
                    ofp.z = 0.0f;
                    ofp.x = 0.0f;
                    ofp.y = -2.0f;
                    obj_no = 1;
                } 
                else
                {
                    ofp.z = 0.0f;
                    ofp.x = 0.0f;
                    ofp.y = 2.5f;
                    obj_no = 11;
                }

                if (wp->cb_blood == 9)
                {
                    if (epw->comb_flg & 0x40)
                    {
                        bhEne_SetBlood4(epw, obj_no, &ofp, 8, 3);
                    } 
                    else
                    {
                        bhEne_SetBlood4(epw, obj_no, &ofp, 8, 1);
                    }
                    
                    ofp.z = 0.0f;
                    ofp.x = 0.0f;
                    ofp.y = 2.5f;
                    bhEne_SetBlood2(epw, 9, &ofp, plp->way);
                } 
                else
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 0);
                }
            }
        }
        else
        {
            if (wp->nm_blood == 9)
            {
                bhEne_SetBlood2(epw, 9, &ofp, plp->way);

                if ((1 < epw->djnt_no) && (epw->djnt_no < 10))
                {
                    ofp.z = 0.0f;
                    ofp.x = 0.0f;
                    ofp.y = -2.0f;
                    obj_no = 1;
                } 
                else
                {
                    ofp.z = 0.0f;
                    ofp.x = 0.0f;
                    ofp.y = 2.5f;
                    obj_no = 11;
                }
                
                if (epw->comb_flg & 0x40)
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 3);
                } 
                else
                {
                    bhEne_SetBlood4(epw, obj_no, &ofp, 8, 0);
                }
            } 
            else
            {
                bhEne_SetBlood(epw, wp->nm_blood, en26prt_blood_tbl);
            }
        }
    }
    if ((wp->flg & 1) && !(epw->comb_flg & 0x40) && (EXP0_I(0x78) != -1) && (epw->hp < 0))
    {
        owk = &epw->mlwP->owP[epw->djnt_no];
        ofp.x = owk->mtx[12];
        ofp.y = owk->mtx[13];
        ofp.z = owk->mtx[14];
        bhEne_SetNikuhenEffect2(epw, 0, &ofp, 4, 7);
    }
}

// 100% matching!
void bhEne26_MainLoop(BH_PWORK* epw, BH_PWORK* pl)
{
    if (epw->mode0 != 6)
    {
        bhEne26_Mode0[epw->mode0](epw);
    }
    bhEne26_PlayerControl(epw, pl);
    bhEne26_SetMtn(epw);
    bhEne26_SearchNeck(epw, pl);
}

// 100 matching!
void bhEne26_PlayerControl(BH_PWORK* epw, BH_PWORK* pl)
{
    if ((EXP0_I(0x40) & 0x20000) && (pl->mode0 == 4 || pl->mode0 == 6))
    {
        bhEne26_PlyDmgMode[pl->mode2](pl, epw);
    }
}

// 100% matching!
int bhEne26_SetMtn(BH_PWORK* epw)
{
    static int rot_tbl[4][8] =
    {
        { 0x800, 0xA00, 0x1000, 0xE00, 0xC00, 0x800, 0x400, 0x200 },
        { -0x800, -0xA00, -0x1000, -0xE00, -0xC00, -0x800, -0x400, -0x200 },
        { 0x800, 0xA00, 0x1000, 0xE00, 0xC00, 0x800, 0x400, 0x200 },
        { -0x800, -0xA00, -0x1000, -0xE00, -0xC00, -0x800, -0x400, -0x200 }
    }; // @ 0x00320850

    NJS_CNK_OBJECT* obj;
    int ret;
    int frm;
    int h_count;   
    int frm_no;
   
    if (EXP0_I(0x40) & 0x10)
    {
        return 0;
    }
    
    frm = epw->frm_no / 65536;
    if (EXP0_I(0x40) & 0x8000000)
    {
        obj = &epw->mlwP->objP[10];
        if (EXP0_I(0x40) & 0x2000)
        {
            obj->ang[0] = rot_tbl[0][EXP0_UC(0x2C)];
            if (EXP0_I(0x44) & 0x20)
            {
                obj->ang[1] = rot_tbl[2][EXP0_UC(0x2C)];
            } 
            else
            {
                obj->ang[1] = rot_tbl[3][EXP0_UC(0x2C)];
            }
        } 
        else
        {
            obj->ang[0] = rot_tbl[1][EXP0_UC(0x2C)];
            if (EXP0_I(0x44) & 0x20)
            {
                obj->ang[1] = rot_tbl[3][EXP0_UC(0x2C)];
            } 
            else 
            {
                obj->ang[1] = rot_tbl[2][EXP0_UC(0x2C)];
            }
        }

        EXP0_UC(0x2C)++;
        if (EXP0_UC(0x2C) >= 8)
        {
            EXP0_I(0x40) &= ~0x8000000;
            EXP0_UC(0x2C) = 0;
        }
    }
    
    ret = bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if ((EXP0_I(0x44) & 0x80) && (epw->mtn_no == 25))
    {
        h_count = epw->hokan_count;
        frm_no = epw->frm_no;
        epw->mlwP->objP += 10;
        epw->mlwP->owP += 10;
        epw->mlwP->obj_num -= 10;
        epw->mtn_no = 23;
        epw->frm_no = EXP0_I(0x80);
        ret = bhSetMotion(epw, 65536, epw->mtn_md, epw->mtn_tp);
        EXP0_I(0x80) = epw->frm_no;
        epw->mtn_no = 25;
        epw->mlwP->obj_num += 10;
        epw->mlwP->owP -= 10;
        epw->mlwP->objP -= 10;
        epw->hokan_count = h_count;
        epw->frm_no = frm_no;
    }

    if (EXP0_I(0x40) & 0x1000000)
    {
        obj = epw->mlwP->objP;
        obj->pos[2] = 0.0f;
        obj->pos[0] = 0.0f;
        bhEne_GetTranslateMtn(epw, frm, 0);
    } 
    else if (EXP0_I(0x40) & 0x2000000)
    {
        obj = epw->mlwP->objP;
        obj->pos[2] = 0.0f;
        obj->pos[0] = 0.0f;
        bhEne_GetTranslateMtn2(epw, frm, 0);
        bhAddSpeed(epw, 0);
    }
    
    if (ret != 0)
    {
        epw->flg |= 0x2000000;
    } 
    else
    {
        epw->flg &= ~0x2000000;
    }

    if (epw->mode0 < 5)
    {
        bhEne26_KamiEffect(epw, frm);
    }
    
    if (EXP0_I(0x40) & 0x10000000)
    {

        if (epw->mtn_no == 2) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_kamikami[frm];
        } 
        else if (epw->mtn_no == 12) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_kamikami2[frm];
        } 
        else if (epw->mtn_no == 25 || epw->mtn_no == 16) 
        {
            epw->mdflg |= 2;
            epw->shp_ct = en01_mogmog[frm % 40];
        } 
        else 
        {
            epw->mdflg &= ~2;
            epw->shp_ct = 0.0f;
        }
    }
    bhEne26_CheckMtnTbl(epw, frm);
    return ret;
}


// 
// Start address: 0x20ab70
void bhEne26_CheckMtnTbl(BH_PWORK* epw, int frm)
{
	int i;
	//_anon28 vec2;
	//_anon28 vec1;
	//_anon28 vec;
	//_anon7* mtbl3;
	//_anon7* mtbl2;
	//_anon4* mtbl;
	// Line 1141, Address: 0x20ab70, Func Offset: 0
	// Line 1142, Address: 0x20ab90, Func Offset: 0x20
	// Line 1143, Address: 0x20ab98, Func Offset: 0x28
	// Line 1144, Address: 0x20aba0, Func Offset: 0x30
	// Line 1145, Address: 0x20aba8, Func Offset: 0x38
	// Line 1146, Address: 0x20abc0, Func Offset: 0x50
	// Line 1145, Address: 0x20abcc, Func Offset: 0x5c
	// Line 1147, Address: 0x20abd0, Func Offset: 0x60
	// Line 1145, Address: 0x20abd4, Func Offset: 0x64
	// Line 1147, Address: 0x20abd8, Func Offset: 0x68
	// Line 1146, Address: 0x20abdc, Func Offset: 0x6c
	// Line 1151, Address: 0x20abe8, Func Offset: 0x78
	// Line 1146, Address: 0x20abec, Func Offset: 0x7c
	// Line 1147, Address: 0x20abf4, Func Offset: 0x84
	// Line 1151, Address: 0x20ac08, Func Offset: 0x98
	// Line 1154, Address: 0x20ac24, Func Offset: 0xb4
	// Line 1156, Address: 0x20ac38, Func Offset: 0xc8
	// Line 1158, Address: 0x20ac40, Func Offset: 0xd0
	// Line 1160, Address: 0x20ac4c, Func Offset: 0xdc
	// Line 1162, Address: 0x20ac60, Func Offset: 0xf0
	// Line 1164, Address: 0x20ac70, Func Offset: 0x100
	// Line 1165, Address: 0x20ac88, Func Offset: 0x118
	// Line 1166, Address: 0x20ac98, Func Offset: 0x128
	// Line 1167, Address: 0x20aca4, Func Offset: 0x134
	// Line 1170, Address: 0x20acac, Func Offset: 0x13c
	// Line 1171, Address: 0x20acc4, Func Offset: 0x154
	// Line 1172, Address: 0x20acd4, Func Offset: 0x164
	// Line 1175, Address: 0x20ace0, Func Offset: 0x170
	// Line 1178, Address: 0x20ace8, Func Offset: 0x178
	// Line 1180, Address: 0x20acf0, Func Offset: 0x180
	// Line 1182, Address: 0x20acf8, Func Offset: 0x188
	// Line 1186, Address: 0x20ad28, Func Offset: 0x1b8
	// Line 1189, Address: 0x20ad70, Func Offset: 0x200
	// Line 1190, Address: 0x20ad80, Func Offset: 0x210
	// Line 1192, Address: 0x20ada0, Func Offset: 0x230
	// Line 1193, Address: 0x20adb8, Func Offset: 0x248
	// Line 1196, Address: 0x20adc0, Func Offset: 0x250
	// Line 1197, Address: 0x20add0, Func Offset: 0x260
	// Line 1199, Address: 0x20adf0, Func Offset: 0x280
	// Line 1200, Address: 0x20ae08, Func Offset: 0x298
	// Line 1203, Address: 0x20ae10, Func Offset: 0x2a0
	// Line 1204, Address: 0x20ae20, Func Offset: 0x2b0
	// Line 1206, Address: 0x20ae40, Func Offset: 0x2d0
	// Line 1207, Address: 0x20ae58, Func Offset: 0x2e8
	// Line 1210, Address: 0x20ae60, Func Offset: 0x2f0
	// Line 1211, Address: 0x20ae70, Func Offset: 0x300
	// Line 1213, Address: 0x20ae90, Func Offset: 0x320
	// Line 1217, Address: 0x20aea8, Func Offset: 0x338
	// Line 1219, Address: 0x20aeb8, Func Offset: 0x348
	// Line 1220, Address: 0x20aed4, Func Offset: 0x364
	// Line 1222, Address: 0x20aee0, Func Offset: 0x370
	// Line 1223, Address: 0x20aef0, Func Offset: 0x380
	// Line 1224, Address: 0x20aefc, Func Offset: 0x38c
	// Line 1226, Address: 0x20af04, Func Offset: 0x394
	// Line 1227, Address: 0x20af14, Func Offset: 0x3a4
	// Line 1228, Address: 0x20af18, Func Offset: 0x3a8
	// Line 1229, Address: 0x20af1c, Func Offset: 0x3ac
	// Line 1234, Address: 0x20af30, Func Offset: 0x3c0
	// Line 1236, Address: 0x20af38, Func Offset: 0x3c8
	// Line 1238, Address: 0x20af44, Func Offset: 0x3d4
	// Line 1240, Address: 0x20af50, Func Offset: 0x3e0
	// Line 1242, Address: 0x20af60, Func Offset: 0x3f0
	// Line 1244, Address: 0x20af68, Func Offset: 0x3f8
	// Line 1245, Address: 0x20af74, Func Offset: 0x404
	// Line 1246, Address: 0x20af78, Func Offset: 0x408
	// Line 1248, Address: 0x20af88, Func Offset: 0x418
	// Line 1249, Address: 0x20af8c, Func Offset: 0x41c
	// Line 1252, Address: 0x20afa0, Func Offset: 0x430
	// Line 1255, Address: 0x20afb0, Func Offset: 0x440
	// Line 1257, Address: 0x20afb8, Func Offset: 0x448
	// Line 1259, Address: 0x20afc4, Func Offset: 0x454
	// Line 1261, Address: 0x20afd0, Func Offset: 0x460
	// Line 1263, Address: 0x20afe0, Func Offset: 0x470
	// Line 1265, Address: 0x20afe8, Func Offset: 0x478
	// Line 1267, Address: 0x20aff0, Func Offset: 0x480
	// Line 1269, Address: 0x20b000, Func Offset: 0x490
	// Line 1270, Address: 0x20b004, Func Offset: 0x494
	// Line 1272, Address: 0x20b018, Func Offset: 0x4a8
	// Func End, Address: 0x20b03c, Func Offset: 0x4cc
    scePrintf("bhEne26_CheckMtnTbl - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne26_SearchNeck(BH_PWORK* epw, BH_PWORK* pl)
{
    NJS_CNK_OBJECT* obj;

    if (epw->mode0 < 5)
    {
        if (EXP0_I(0x40) & 0x1000)
        {
            obj = &epw->mlwP->objP[10];
            obj->ang[1] = epw->wax;
            obj = &epw->mlwP->objP[13];
            obj->ang[1] = EXP0_I(0x50);            
        } 
        else
        {
            if ((EXP0_I(0x40) & 0x800) && (EXP0_UC(0x28) & 0x40) && (EXP0_F(0x54) < 35.0f)) 
            {
                obj = &epw->mlwP->objP[13];
                obj->ang[1] = EXP0_I(0x50);
                bhEne01_RotNeck(epw, 13, pl, 5);
                EXP0_I(0x50) = obj->ang[1];
            }
            else
            {
                obj = &epw->mlwP->objP[13];
                if (EXP0_I(0x50) != 0)
                {
                    if (EXP0_I(0x50) < 32768)
                    {
                        EXP0_I(0x50) -= 910;
                        if (EXP0_I(0x50) < 0)
                        {
                            EXP0_I(0x50) = 0;
                        }
                    } 
                    else
                    {
                        EXP0_I(0x50) += 910;
                        if (EXP0_I(0x50) >= 65536)
                        {
                            EXP0_I(0x50) = 0;
                        }
                    }
                }
                obj->ang[1] = EXP0_I(0x50);  
            }
        }    
    }
}

// 100% matching!
void bhEne26_CollCheck(BH_PWORK* epw)
{
	O_WORK* owk;
	ATR_WORK* hp;

    if (!(epw->flg & 2))
    {
        if (epw->flg & 8)
        {
            if (EXP0_I(0x40) & 0x100)
            {
                bhEne01_CollCheckPush(epw, ene);
            } 
            else
            {
                if (epw->flg & 0x80)
                {
                    owk = epw->mlwP->owP;
                    epw->aox = owk->mtx[12] - epw->px;
                    epw->aoz = owk->mtx[14] - epw->pz;
                    epw->aoy = 0.0f;
                } 
                else
                {
                    epw->aox = 0.0f;
                    epw->aoy = 0.0f;
                    epw->aoz = 0.0f;
                }
                if (!(EXP0_I(0x40) & 0x40))
                {
                    bhCheckPlayer(epw);
                    bhCheckEnemies(epw);
                }
            }
        }
        bhEne26_CollCheckWall(epw);
    }
    
    if (sys->st_flg & 0x100)
    {
        epw->mdflg &= ~0x40;
        hp = bhCheckFloorEffect(epw->flr_no, epw->px, epw->pz);
        if ((hp != NULL) && (hp->prm0 == 2))
        {
            epw->mdflg |= 0x40;
        }
    }
}

// 99.92% matching
void bhEne26_CollCheckWall(BH_PWORK* epw)
{
    NJS_POINT3 ps; // r29+0x60    
    NJS_POINT3 ops; // r29+0x70    
    NJS_POINT3 pd; // r29+0x80
    NJS_POINT3 ps2; // r29+0x90
    NJS_POINT3 ops2; // r29+0xA0    
    NJS_POINT3 pd2; // r29+0xB0    
    O_WORK* owk; // r2

    // not present in DWARF
    int t;

    ps.x = plp->px;
    ps.y = plp->py;
    ps.z = plp->pz;
    
    *(ATR_WORK **)(epw->exp0 + 0x70) = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &ps);

    t = EXP0_I(0x40) & 0xF;
    
    if (t == 1 && epw->flg & 0x10)
    {
        ps.x = epw->px + epw->aox;
        ps.y = epw->py + epw->aoy;
        ps.z = epw->pz + epw->aoz;
        
        ops.x = epw->pxb + epw->aox;
        ops.y = epw->pyb + epw->aoy;
        ops.z = epw->pzb + epw->aoz;
        
        bhCheckDansa(epw);
        bhCheckWallEx(epw, &ps, &ops, epw->ar, epw->ah);
        
        epw->px += (ps.x - (epw->px + epw->aox));
        epw->py += (ps.y - (epw->py + epw->aoy));
        epw->pz += (ps.z - (epw->pz + epw->aoz));
        if (!(EXP0_I(0x40) & 0x8000000))
        {
            owk = epw->mlwP->owP;
            ops.x = owk[12].mtx[12];
            ops.z = owk[12].mtx[14];
            ops.y = epw->pyb;
            
            bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 5, 1);
            
            ps.y = epw->py;
            
            bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 2.0f, 2.0f);
            
            epw->px += pd.x;
            epw->py += pd.y;
            epw->pz += pd.z;
        }        
    }        
    else if (t == 2)
    {
        ps.x = epw->px + epw->aox;
        ps.y = epw->py + epw->aoy;
        ps.z = epw->pz + epw->aoz;
       
        ops.x = epw->pxb + epw->aox;
        ops.y = epw->pyb + epw->aoy;
        ops.z = epw->pzb + epw->aoz;
        bhCheckDansa(epw);
        bhCheckWallEx(epw, &ps, &ops, epw->ar, epw->ah);
        
        epw->px += (ps.x - (epw->px + epw->aox));
        epw->py += (ps.y - (epw->py + epw->aoy));
        epw->pz += (ps.z - (epw->pz + epw->aoz));
        
        owk = epw->mlwP->owP;
        ops.x = owk[16].mtx[12];
        ops.z = owk[16].mtx[14];
        
        owk = epw->mlwP->owP;
        ops.x = (ops.x + owk[19].mtx[12]) / 2.0f;
        ops.z = (ops.z + owk[19].mtx[14]) / 2.0f;
        ops.y = epw->pyb;        
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[2], 7, 1);
        bhEne_CalcPartsPos(epw, lcmat, &pd, en26_tree[3], 7, 1);
        
        ps.x = (ps.x + pd.x) / 2.0f;
        ps.z = (ps.z + pd.z) / 2.0f;
        ps.y = epw->py;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 3.0f, 2.0f);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }       
    else if (t == 3)
    {
        owk = epw->mlwP->owP;
        ops.x = owk[1].mtx[12];
        ops.z = owk[1].mtx[14];
        ops.y = epw->pyb;
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 2, 1);
        
        ps.y = epw->py;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, 1.5f, 2.0f);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }
        
    else if (t == 5)
    {
        owk = epw->mlwP->owP;
        ops.x = owk[0].mtx[12];
        ops.z = owk[0].mtx[14];
        ops.y = epw->pyb;
        
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 1, 1);
        
        ps.y = epw->py;        
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }
        
    else if (t == 6)        
    {
        bhEne_CalcPartsPos(epw, lcmat, &ps, en26_tree[7], 2, 1);
        owk =&epw->mlwP->owP[1];
        pd.x = 0.0f;
        pd.y = -5.0f;                
        pd.z = 0.0f;
        njCalcPoint(lcmat, &pd, &ps);
        njCalcPoint(&owk->mtx, &pd, &ops);
        
        pd2.x = 0.0f;
        pd2.y = 3.5f;
        pd2.z = 0.0f;
        njCalcPoint(lcmat, &pd2, &ps2);
        njCalcPoint(&owk->mtx, &pd2, &ops2);
        
        ps.y = ps2.y = epw->py;
        ops.y = ops2.y = epw->pyb;
        
        bhEne_CollisionCheckWall2(epw, &ps, &ops, &pd, epw->ar, epw->ah);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
        
        bhEne_CollisionCheckWall2(epw, &ps2, &ops2, &pd, epw->ar, epw->ah);
        
        epw->px += pd.x;
        epw->py += pd.y;
        epw->pz += pd.z;
    }    
}

// 100% matching!
void bhEne26_PlayerLink(BH_PWORK* epw, BH_PWORK* pl)
{	   
	NJS_POINT2_XZ* ply_pos_p;
	NJS_POINT3 pos;
	NJS_POINT3 ps;
	NJS_POINT3 pd;   
    int mtn_no;
          
    NJS_POINT2_XZ* ply_pos[16] =
    {
        cl_mtn01_xz,
        cl_mtn02_xz,
        cl_mtn04_xz,
        cl_mtn05_xz,
        ch_mtn01_xz,
        ch_mtn02_xz,
        ch_mtn04_xz,
        ch_mtn05_xz,
        st_mtn01_xz,
        st_mtn02_xz,
        st_mtn04_xz,
        st_mtn05_xz,
        ch_mtn01_xz,
        ch_mtn02_xz,
        ch_mtn04_xz,
        ch_mtn05_xz
    };
    
    njUnitMatrix(NULL);
    njTranslate(NULL, epw->px, epw->py, epw->pz);
    njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
    njCalcPoint(NULL, (NJS_POINT3*)(epw->exp0 + 0x64), &pd);
    pl->px = pd.x;
    pl->pz = pd.z;
    pl->ay = (unsigned short)(epw->ay + epw->waxp);
    if (pl->flg & 0x1000)
    {
		if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 1)) 
        {
            mtn_no = 0;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 2))
        {
            mtn_no = 1;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 4))
        {
            mtn_no = 2;
        }			
		else if (pl->mtn_no == (En26_PlyMtn_OffsetTbl[sys->ply_id] + 5))
        {
            mtn_no = 3;
        }
			
        ply_pos_p = ply_pos[(sys->ply_id * 4 + mtn_no)];
        ply_pos_p += pl->frm_no / 65536;
        
        ps.x = ply_pos_p->x;
        ps.y = 0.0f;
        ps.z = ply_pos_p->z;
        njUnitMatrix(NULL);
        njTranslate(NULL, pl->px, pl->py, pl->pz);
        njRotateXYZ(NULL, pl->ax, pl->ay, pl->az);
        njCalcPoint(NULL, &ps, &pos);
        njUnitMatrix(pl->mtx);
        njTranslate(pl->mtx, pos.x, pos.y, pos.z);
        njRotateXYZ(pl->mtx, pl->ax, pl->ayp, pl->az);
    }
}

// 100% matching!
void bhEne26_CalcEnemy(BH_PWORK* epw)
{
    O_WORK* owk;
    
    bhCalcModel(epw);
    owk = &epw->mlwP->owP[12];
    epw->watr.c1.x = owk->mtx[12];
    epw->watr.c1.y = owk->mtx[13];
    epw->watr.c1.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[4];
    epw->watr.c2.x = owk->mtx[12];
    epw->watr.c2.y = owk->mtx[13];
    epw->watr.c2.z = owk->mtx[14];
    
    owk = &epw->mlwP->owP[8];
    epw->watr.c2.x = (epw->watr.c2.x + owk->mtx[12]) / 2.0f;
    epw->watr.c2.y = (epw->watr.c2.y + owk->mtx[13]) / 2.0f;
    epw->watr.c2.z = (epw->watr.c2.z + owk->mtx[14]) / 2.0f;
    
    epw->watr.r = 2.0f;    
    epw->cah = epw->ah = epw->mlwP->owP[12].mtx[13] - epw->py;
}

#pragma mpwc_relax     on
// this was needed for bhSetShadow(En26SdwTab,(unsigned char *)epw, 1.0f, 6.0f, 5.0f, 5.0f);
// but apparently it matches even without it? I will leave it on for now

// 100% matching!
void bhEne26_Init(BH_PWORK* epw)
{
	int i;
	unsigned char* addr;
	int size;

    plp->flg &= ~4;
    epw->ar = 3.8f;
    epw->ah = 18.2f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 2.5f;
    epw->cah = 18.2f;
    epw->hp = 200;
    epw->stflg = 0;
    
	for (i = 0; i < 64; i++)
    {
    	epw->dam[i] = 0;
	}
    
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->frm_no = 0;
    epw->mtn_add = 65536;
    epw->mtn_no = 0;
    epw->mtn_tp = (unsigned char *)en26_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(160, 8);
        epw->exp1 = 0;
    } 
    else
    {
        addr = epw->exp0;
        size = 160;        
        while (size-- != 0)
        {
            *addr++ = 0;
        }
    }

    EXP0_I(0x40) |= 1;
    epw->flg |= 0x178;
    epw->flg &= ~2;
    epw->cpcl = Ene26CapColTab;
    epw->mlwP->objP = epw->mbp[0];
    epw->mdflg = 0;
    epw->obj_a = epw->mbp[0];
    epw->obj_b = epw->mbp[1];

    EXP0_I(0x40) |= 0x10000000;
    
    if (!(epw->flg & 0x800))
    {
        bhSetShadow(En26SdwTab,(unsigned char *)epw, 1.0f, 6.0f, 5.0f, 5.0f);
        epw->flg |= 0x800;
    }
    
    if ((EXP0_I(0x3C) & 0x00FFFFFF) == 0)
    {
        epw->mdflg &= ~0x400;
        EXP0_I(0x3C) = 0xFFB2B2B2U;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, EXP0_I(0x3C));
    }
    
    epw->clp_jno[0] = 13;
    epw->clp_jno[1] = 16;
    epw->clp_jno[2] = 19;
    epw->clp_jno[3] = 4;
    epw->clp_jno[4] = 8;
    epw->clp_jno[5] = -1;
    epw->mdflg |= 0x20;
    epw->lok_jno = 12;
    epw->comb_flg |= 2;
    bhClrUseKaidanFlag(epw);
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    bhEne26_CalcEnemy(epw);
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    epw->mlwP->owP[10].flg |= 2;
}

#pragma mpwc_relax     off

// 100% matching!
void bhEne26_Move(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	O_WORK* owk;

    EXP0_I(0x40) &= ~0x800;
    
    owk = plp->mlwP->owP;
    pos.x = owk->mtx[12];
    pos.y = plp->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x54) = njDistanceP2P(&pos,  (NJS_POINT3*)&epw->px);
    if (epw->mode2 != 9)
    {
        EXP0_I(0x40) |= 0x800;
    }
    
    bhEne26_MVType(epw);
}

// 100% matching!
void bhEne26_MVType(BH_PWORK* epw)
{
    if (bhEne_EnemyAtariCheck((NJS_POINT3*) &plp->px, plp->flr_no, epw->id, 0))
    {
        EXP0_I(0x40) |= 0x20000000;
    } 
    else
    {
        EXP0_I(0x40) &= ~0x20000000;
    }

    if (epw->mode1 == 1) 
    {
        bhEne26_Brain00(epw);
    }
    
    if (EXP0_I(0x70) == 0)
    {
        bhEne26_ActionModeCheck(epw);
    }
    
    if (epw->mode0 == 1)
    {
        bhEne26_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne26_EneSearch(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* neck_obj;
    O_WORK* neck_owk;
    NJS_POINT3 pos;

    neck_owk = &epw->mlwP->owP[13];
    neck_obj = &epw->mlwP->objP[13];

    pos.x = neck_owk->mtx[12];
    pos.y = 0.0f;
    pos.z = neck_owk->mtx[14];

    if ((EXP0_UC(0x28) & 0x1F) < 31)
    {
        if (bhSearchPlayer2(epw, &pos, epw->ay + neck_obj->ang[1], 14563) != -1)
        {
            EXP0_UC(0x28) |= 0x20;
        }
        
        if (EXP0_UC(0x28) & 0x20)
        {
            EXP0_UC(0x28) |= 0x40;
            EXP0_UC(0x28) &= 0xDF;
        } 
        else if ((EXP0_UC(0x28) & 0x1F) == 30)
        {
            EXP0_UC(0x28) &= 0xBF;
        }
    }
    
    EXP0_UC(0x28)++;
    if ((EXP0_UC(0x28) & 0x1F) >= 31)
    {
        EXP0_UC(0x28) &= 0xE0;
    }

    if (EXP0_UC(0x28) & 0x40)
    {
        EXP0_I(0x40) |= 0x400;
        EXP0_UC(0x29) = 15;
        return;
    }
    
    if (EXP0_I(0x40) & 0x400)
    {
        if (--EXP0_UC(0x29) < 0)
        {
            EXP0_I(0x40) &= ~0x400;
        }
    }
}

// 100% matching!
void bhEne26_Brain00(BH_PWORK* epw)
{
    unsigned char rid;
	NJS_POINT3 pos;

    bhEne26_EneSearch(epw);
    if (EXP0_I(0x40) & 0x400)
    {
        if ((EXP0_F(0x54) < 50.0f) && (EXP0_I(0x70) == 0) && (epw->flr_no == plp->flr_no))
        {
            EXP0_F(0x58) = plp->px;
            EXP0_F(0x60) = plp->pz;
            EXP0_UC(0x2A) = bhCheckRouteID((NJS_POINT3*) &epw->px);
            EXP0_UC(0x2B) = 0;
            return;            
        }
        
        rid = (unsigned char) bhCheckRouteID((NJS_POINT3*) &epw->px);
        EXP0_UC(0x2B)++;
        if ((EXP0_UC(0x2A) == rid) || (EXP0_UC(0x2B) >= 255))
        {
            rid = bhCheckRoute((NJS_POINT3*) &epw->px, (NJS_POINT3*) &plp->px, &pos);
            EXP0_F(0x58) = pos.x;
            EXP0_F(0x60) = pos.z;
            EXP0_UC(0x2A) = rid;
            EXP0_UC(0x2B) = 0;
        }
    }
}

// 100% matching!
int bhEne26_ActionModeCheck(BH_PWORK* epw)
{
    O_WORK* owk;
    
    if (((epw->mode2 == 0) || (epw->mode2 == 1 || epw->mode2 == 2)) &&
        (ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 4096) == 0) &&
        (EXP0_F(0x54) < 10.0f) && (plp->mode0 == 6) && (plp->hp < 0))
    {
        epw->mode1 = 0;
        epw->mode2 = 16;
        epw->mode3 = 0;
        return 1;
    }

    if ((plp->flg & 4) || (plp->flg & 2) || (plp->stflg & 0x80000000))
    {
        if (bhSearchPlayer2(epw, (NJS_POINT3*)&epw->px, epw->ay, 5461) != -1)
        {
            if ((EXP0_F(0x54) < 7.0f) &&
                (plp->flr_no == epw->flr_no) &&
                (((epw->mode2 == 0)) || (epw->mode2 == 1 || epw->mode2 == 2)))
            {
                epw->mode1 = 0;
                epw->mode2 = 6;
                epw->mode3 = 0;
                return 1;
            }             
        } 
        return 0;
    } 
    else
    {
        if ((epw->mode2 == 0) || (epw->mode2 == 1 || epw->mode2 == 2))
        {
            owk = plp->mlwP->owP;
            if (bhEne26_EatCheck(epw, 8192, 5.5f, 0) && (EXP0_UC(0x2F) == 0) && (epw->mtn_no == 16))
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                epw->flg &= ~0x20;
                plp->flg |= 0x10000;
                plp->flg |= 4;
                return 1;
            }
            
            if ((bhCdirCheck(epw->ay, plp->ay) == 0) &&
                (plp->mode2 == 6) &&
                ((rand() % 2) == 0) &&
                (bhEne26_EatCheck(epw, 5461, 11.0f, 0)))
            {
                epw->mode1 = 0;
                epw->mode2 = 5;
                epw->mode3 = 0;
                return 1;
            }
            
            if ((EXP0_F(0x54) < 11.0f) &&
                (epw->flr_no == plp->flr_no) &&
                (plp->hp >= 0) &&
                (ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 16384)) &&
                !(EXP0_I(0x40) & 0x20000000))
            {
                epw->mode1 = 0;
                epw->mode2 = 3;
                epw->mode3 = 0;
                return 1;
            }
            
            if ((epw->flg & 4) &&
                (epw->flr_no == plp->flr_no) &&
                !(EXP0_F(0x54) <= 15.0f) &&
                (ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 24576)))
            {
                epw->mode1 = 0;
                epw->mode2 = 7;
                epw->mode3 = 0;
                return 1;
            }
        }
    }
}

#pragma divbyzerocheck on
// 100% matching!
void bhEne26_MV00(BH_PWORK* epw)
{
    int frm_no;

    switch (epw->mode3)
    {
    case 0:
        frm_no = (rand() % epw->mnwP[epw->mtn_no].frm_num) * 65536;
        bhEne_ChgMtn(epw, 0, 0, 15);
        EXP0_I(0x40) &= ~0x3000000;
        epw->frm_no = frm_no;
        epw->flg |= 0x40000;
        epw->ct0 = ((rand() % 10) * 20) + 15;
        EXP0_I(0x40) &= ~0x400;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 1;
        epw->mode1 = 1;
        epw->mode3++;
        bhEne26_SePlay(epw, 16847639);

    case 1:
        epw->ct0 -= 1;
        if ((epw->ct0 <= 0) || (EXP0_I(0x40) & 0x400))
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        } 
        break;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne26_MV01(BH_PWORK* epw)
{
    int hit;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 25, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->way = 512;
        epw->flg |= 0x40000;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        epw->ct0 = (rand() % 128) + 200;
        epw->ct1 = 19;
        epw->ct3 = rand() % 120;
        epw->mode3 = 1;

    case 1:
        if (EXP0_F(0x54) < 30.0f || (EXP0_I(0x40) & 0x400))
        { 
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                bhEne26_SePlay(epw, 16847639);
                EXP0_I(0x40) |= 0x400;
        }
        else
        {
            if (bhEne_CheckDirWall(epw, 0, 8.0f))
            {
                hit = bhEne_CheckSideWall(epw, 8.0f, 0);  
                
                if (hit == 0)
                {
                    epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
                    epw->ayp = (unsigned short)(epw->ayp - epw->ay);
                    if (epw->ayp < 32769)
                    {
                        epw->way = 256;
                    } 
                    else 
                    {
                        epw->way = -256;
                    } 
                } 
                else
                {
                    epw->way = hit * 256;
                }
                epw->mode3 = 2;
            }
        }            
        break;
        
    case 2:
        if (bhEne_CheckDirWall(epw, 0, 8.0f) == NULL) 
        {
            epw->mode3 = 1;
        } 
        else
        {
            epw->ay += epw->way;
        }
        break;
    }

    if (--epw->ct3 < 0)
    {
        bhEne26_SePlay(epw, 16847639);
        epw->ct3 = (rand() % 120) + 180;
    }
}

// 100% matching!
void bhEne26_MV02(BH_PWORK* epw)
{
    int frm;
    
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 25, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->way = 0x100;
        epw->flg |= 0x40000;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = (rand() % 120) + 120;
        EXP0_I(0x84) = 0;
        EXP0_I(0x88) = 0;
        epw->ct3 = rand() % 120;
        EXP0_I(0x44) &= ~0x80;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        epw->mode3 = 2;
        break;
    case 1:
        bhEne_ChgMtn(epw, 16, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->way = 0x200;
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = (rand() % 120) + 120;
        EXP0_I(0x84) = 0;
        EXP0_I(0x88) = 0;
        epw->ct3 = rand() % 120;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 2;
        EXP0_I(0x40) |= 0x400;
        epw->mode3 = 2;
        break;
    case 2:
        if (epw->mtn_no == 25)
        {
            if (!(EXP0_I(0x44) & 0x80))
            {
                EXP0_I(0x7C) = 10;
                EXP0_I(0x80) = 0;
                if (epw->hokan_count < 10)
                {
                    epw->hokan_count = 10;
                }
                epw->ct1 = 19;
                EXP0_I(0x44) |= 0x80;
            } 
            else
            {
                if (--epw->ct1 < 0)
                {
                    frm = bhGetFrameNum(epw->mnwP[epw->mtn_no].frm_num, epw->mnwP[16].frm_num, epw->frm_no);
                    bhEne_ChgMtn(epw, 16, frm, 10);
                    EXP0_I(0x40) &= ~0x3000000;
                    epw->flg |= 0x40000;
                    epw->way = 0x200;
                }
            }
        }
        ikou(epw, (NJS_POINT3*)(epw->exp0 + 0x58), epw->way);
        break;
    case 3:
        if (bhEne_CheckDirWall(epw, 0, 8.0f) == NULL)
        {
            epw->mode3 = 2;
        } 
        else
        {
            epw->ay += epw->way;
        }
        break;
    }
    
    if (--epw->ct3 < 0)
    {
        bhEne26_SePlay(epw, 16847639);
        epw->ct3 = (rand() % 120) + 180;
    }
}

// 100% matching!
void bhEne26_MV03(BH_PWORK* epw)
{
	O_WORK* owk;
	int rot;
    
    switch (epw->mode3)
    { 
    case 0:
        bhEne_ChgMtn(epw, 13, 0, 8);
        EXP0_I(0x40) &= ~0x3000000;
        epw->mtn_add = 0;
        epw->ct0 = 6;
        epw->mode3++;

    case 1:
        owk = plp->mlwP->owP;
        rot = ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 4096);
        epw->ct0--;
        if ((epw->ct0 <= 0) || (rot == 0))
        {
            if (!ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 4096) && (EXP0_F(0x54) < 10.0f) && (plp->mode0 == 6) && (plp->hp < 0))
            {                               
                epw->mode1 = 0;
                epw->mode2 = 16; 
                epw->mode3 = 0;
            } 
            else
            {
                epw->mode1 = 0;
                epw->mode2 = 5;
                epw->mode3 = 0;
            }            
        }
        epw->ay += rot;
        break;
    }
}

// 100% matching!
void bhEne26_MV05(BH_PWORK* epw)
{
	BH_PWORK* pl;
	float hit;
	int frm;

    pl = plp;
    switch (epw->mode3)
    {
    case 0:
        if (sys->ply_id == 1)
        {
            bhEne_ChgMtn(epw, 13, 0, 8);
            EXP0_I(0x40) &= ~0x2000000;
            EXP0_I(0x40) |= 0x1000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 13, 0, 8);
            EXP0_I(0x40) &= ~0x2000000;
            EXP0_I(0x40) |= 0x1000000;
        }
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        EXP0_F(0x68) = 0.0f;
        EXP0_F(0x64) = epw->px;
        EXP0_F(0x6C) = epw->pz;
        bhEne26_SePlay(epw, 16782102);
        epw->mode3++;
        
    case 1:
        frm = epw->frm_no / 65536;

        if (frm < 13)
        {
            epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 1536);
        }
        
        hit = 0.0f;
        if (frm >= 8)
        {
            if ((frm < 0xD) && !(plp->flg & 4) && (bhEne26_EatCheck(epw, 3640, 5.5f, 0) != 0))
            {
                plp->flg |= 4;
                plp->flg |= 0x10000;
                epw->flg &= ~0x20;
                epw->flg &= ~0x40;
                
                *(int*)&pl->mode0 = 4;
                pl->mode3 = 4;
                
                EXP0_I(0x40) |= 0x20000;
                if (bhCdirCheck(plp->ay, epw->ay) == 0)
                {
                    EXP0_I(0x40) |= 0x4000;
                } 
                else
                {
                    EXP0_I(0x40) &= ~0x4000;
                }
                
                if (sys->ply_id == 1)
                {
                    bhEne_ChgMtn(epw, 12, 0, 5);
                    EXP0_I(0x40) &= ~0x3000000;
                } 
                else
                {
                    bhEne_ChgMtn(epw, 12, 0, 5);
                    EXP0_I(0x40) &= ~0x3000000;
                }
                
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 5;
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 2;
                epw->ct0 = 75;
                hit = 1.0f;
            }
        }
        if ((frm == 12) && (hit == 0.0f))
        {
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne26_MV06(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 15, 2949120, 15);
        EXP0_I(0x40) &= ~0x3000000;       
        epw->flg |= 0x40000;
        epw->ct0 = (rand() % 15) + 15;
        epw->mode1 = 1;
        epw->mode3++;

    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->px, 910);
        if (!(plp->flg & 4))
        {
            if (bhEne26_EatCheck(epw, 4551, 5.5f, 0))
            {
                epw->mode0 = 2;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                
                plp->flg |= 4;
                plp->flg |= 0x10000;
                epw->flg &= ~0x20;
                break;
            } 
            
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        } 
    }
}

// 100% matching!
void bhEne26_MV07(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 17, 0, 8);
        EXP0_I(0x40) &= ~0x3000000;
        epw->ayp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        epw->ayp = (unsigned short)(epw->ayp - epw->ay);
        
        if (epw->ayp < 0x8001)
        {
            epw->ayp /= 22;
        } 
        else
        {
            epw->ayp = (-(0x10000 - epw->ayp) / 22);
            epw->mtn_md |= 2;
        }
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 17) && (frm < 40))
        {
            epw->ay += epw->ayp;
        }
        if ((epw->frm_no / 65536) == 40)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_MV16(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 910);
        bhEne_ChgMtn(epw, 18, 0, 5);
        EXP0_I(0x40) &= ~0x2000000;
        EXP0_I(0x40) |= 0x1000000;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            bhEne_ChgMtn(epw, 14, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            epw->mode3++;
        }

    case 2:
        break;
    }
}

// 100% matching!
void bhEne26_Nage(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    bhEne26_NGType(epw);
}

// 100% matching!
void bhEne26_NGType(BH_PWORK* epw)
{
    if (epw->mode3 == 0)
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0)
        {
            EXP0_I(0x40) |= 0x4000;
        } 
        else
        {
            EXP0_I(0x40) &= ~0x4000;
        }
    }
    bhEne26_NageMode2[epw->mode2](epw);
}

// 99.95% matching
void bhEne26_NG00(BH_PWORK* epw)
{
    BH_PWORK* pl; // r16
    O_WORK* owk; // r3
    NJS_POINT3 ps; // r29+0x40
    int ang; // r18    
    int frm; // r3

    pl = plp;

    switch (epw->mode3)
    {
    case 0:
        if (sys->ply_id == 1)
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 2, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        }

        epw->ay = NitenDir_ck(epw->px, epw->pz, pl->px, pl->pz);
        epw->flg &= ~0x40;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 5;
        EXP0_I(0x40) &= ~0x4000000;
        pl->mode0 = 4;
        pl->mode1 = 0;
        pl->mode2 = 0;
        pl->mode3 = 0;
        epw->flg2 |= 1;
        ps.x = 0.0f;
        ps.y = 0.0f;
        
        if (EXP0_I(0x40) & 0x4000)
        {
            ps.z = -6.442887f;
            ang = (unsigned short)(epw->ay + NJM_DEG_ANG(180.0f));
        } 
        else
        {
            ps.z = 6.290813f;
            ang = epw->ay;
        }
        
        njUnitMatrix(NULL);
        njTranslate(NULL, pl->px, pl->py, pl->pz);
        njRotateY(NULL, ang);
        njCalcPoint(NULL, &ps, (NJS_POINT3*)&epw->px);
        EXP0_I(0x40) |= 0x20000;
        epw->mode3++;
        
    case 1:
        if ((epw->frm_no / 65536) == 20)
        {
            epw->ct0 = 60;
            epw->mode3++;            
        }
        break;
        
    case 2:
        frm = epw->frm_no / 65536;
        if ((frm == 25) || (frm == 60))
        {
            pl->hp -= 30;
            if (pl->hp < 0)
            {
                pl->stflg |= 0x40000;
            }
        }
        epw->ct0 -= bhEne_LeverCheck() + 1;
        if ((epw->ct0 <= 0) || (epw->flg & 0x2000000))
        {
            if (pl->hp < 0)
            {
                bhEne_ChgMtn(epw, 9, 0, 0);
                EXP0_I(0x40) &= ~0x3000000;
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 5;
                epw->mode3 = 5;
                pl->mode0 = 6;
                pl->mode3 = 6;
            } 
            else
            {
                bhEne_ChgMtn(epw, 1, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
                epw->flg |= 0x40000;
                epw->mode3++;
                pl->mode3 = 2;
                pl->ct1 = 0;
                EXP0_I(0x40) &= ~0xF;
                EXP0_I(0x40) |= 6;
                epw->ct0 = 0;
                epw->flg2 &= ~1;
            }
            epw->flg |= 0x20;
        }
        break;
        
    case 3:
        frm = epw->frm_no / 65536;
        if (17 < frm && frm < 31)
        {
            epw->spd = (1.5f - epw->ct0 * 0.14);
            if (epw->spd < 0.0f)
            {
                epw->spd = 0.05f;
            }
            bhAddSpeed(epw, 32768);
            epw->ct0++;            
        }
        
        if (frm == 20)
        {
            EXP0_I(0x40) |= 0x100;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 26, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            epw->flg |= 0x40000;
            EXP0_I(0x40) &= ~0x80;
            epw->flg |= 0x40;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mode3++;
        }
        break;
        
    case 4:
        frm = epw->frm_no / 65536;
        if (frm == 10)
        {
            EXP0_I(0x40) &= ~0x100;
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg2 &= ~1;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 1;
            epw->mtn_add = 0;
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
        
    case 5:
        if (epw->flg & 0x2000000)
        {
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            EXP0_I(0x40) &= ~0x80000;
            bhEne_ChgMtn(epw, 14, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
            EXP0_I(0x40) &= ~0xF;
            epw->mode3++;
        }
        break;
        
    case 6:
        break;
        
    }
}

// 100% matching!
void bhEne26_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
    static NJS_POINT3 ply_ofs_pos[8] =
    {
        {0.0f, 0.0f, -6.326351f},
        {0.0f, 0.0f, -6.326351f},
        {0.0f, 0.0f, -5.0f},
        {0.0f, 0.0f, -6.019392f},
        {0.167357f, 0.0f, -5.7556629f},
        {0.0f, 0.0f, -5.9214029f},
        {0.0f, 0.0f, -5.0f},
        {0.0f, 0.0f, -6.019392f}
    };
    
    static NJS_POINT3 ply_ofs_pos2[8] =
    {
        {0.469302f, 0.0f, -5.826981f},
        {0.469231f, 0.0f, -5.499186f},
        {0.2f, 0.0f, -4.5f},
        {0.4f, 0.0f, -5.1999998f},
        {0.469302f, 0.0f, -5.0f},
        {0.469231f, 0.0f, -4.9f},
        {0.2f, 0.0f, -4.5f},
        {0.4f, 0.0f, -5.1999998f}
    };
    
    unsigned int frm;

    switch (pl->mode3)
    {
    case 0:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg &= ~8;
        EXP1_I(0) |= 0x1E0;
        EXP1_I(0) &= ~4;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->ayp = (unsigned short)((epw->ay + 32768) - pl->ay);
            epw->waxp = -32768;
        } 
        else 
        {
            pl->ayp = (unsigned short)(epw->ay - pl->ay);
            epw->waxp = 0;
        }
        
        if (32768 < pl->ayp)
        {
            pl->ayp = (pl->ayp - 32768) - 32768;
        }
        epw->waxp -= pl->ayp;
        pl->ayp /= 5;
        pl->ct0 = 0;
        pl->mode3++;

    case 1:
        if (pl->ct0 < 5)
        {
            epw->waxp += pl->ayp;
        } 
        else if (pl->ct0 == 5)
        {
            if (EXP0_I(0x40) & 0x4000)
            {
                epw->waxp = -32768;
            } 
            else
            {
                epw->waxp = 0;
            }
        }
        
        pl->ct0++;
        frm = epw->frm_no / 65536;
        if (frm == 1)
        {            
            pl->mnwP = epw->mnwP;
            pl->frm_no = 0;
            pl->hokan_count = 5;
            pl->hokan_rate = 42598;
            pl->mtn_add = 65536;
            pl->mtn_md = 0;
            EXP0_I(0x40) |= 0x80;
            if (EXP0_I(0x40) & 0x4000)
            {
                pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 6;
                EXP0_F(0x64) = ply_ofs_pos[sys->ply_id * 2].x;
                EXP0_F(0x68) = ply_ofs_pos[sys->ply_id * 2].y;
                EXP0_F(0x6C) = ply_ofs_pos[sys->ply_id * 2].z;
                epw->waxp = -32768;
                EXP0_I(0x40) |= 0x80000;
                break;
            } 
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 7;
            EXP0_F(0x64) = ply_ofs_pos[sys->ply_id * 2 + 1].x;
            EXP0_F(0x68) = ply_ofs_pos[sys->ply_id * 2 + 1].y;
            EXP0_F(0x6C) = ply_ofs_pos[sys->ply_id * 2 + 1].z;
            epw->waxp = 0;
            EXP0_I(0x40) |= 0x80000;            
        } 
        else if (frm == 12)
        {
            bhEne_PlayerSePlay(epw, 1026);
        }
        break;
        
    case 2:
        EXP1_I(0) |= 4;
        pl->frm_no = 0;
        pl->hokan_count = 0;
        pl->hokan_rate = 32768;
        pl->mtn_add = 65536;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 10;
        } 
        else
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 11;
        }

        EXP0_I(0x40) &= ~0x80000;
        pl->mode3++;

    case 3:
        frm = pl->frm_no / 65536;
        if (frm == 14)
        {
            bhEne01_EnemyPushChk(epw, 1);
        } 
        else if (frm == 17)
        {
            bhEne01_EnemyPushChk(epw, 0);
        }
        
        if ((pl->frm_no / 65536) >= (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->flg |= 8;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->mnwP = pl->mnwPb;
            *(int*)&pl->mode0 = 1;
            plp->flg &= ~4;
            EXP0_I(0x40) &= ~0x4000;
            EXP0_I(0x40) &= ~0x20000;
        }
        break;
        
    case 4:
        pl->flg &= ~0x40000;
        pl->flg |= 0x10000;
        pl->flg &= ~8;
        EXP1_I(0) |= 0x1E0;
        EXP1_I(0) &= ~4;
        if (EXP0_I(0x40) & 0x4000)
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 8;
            EXP0_F(0x64) = ply_ofs_pos2[sys->ply_id * 2].x;
            EXP0_F(0x68) = ply_ofs_pos2[sys->ply_id * 2].y;
            EXP0_F(0x6C) = ply_ofs_pos2[sys->ply_id * 2].z;
            EXP0_I(0x40) |= 0x80000;
            pl->ayp = (unsigned short)((epw->ay + 32768) - pl->ay);
            epw->waxp = -32768;
        } 
        else
        {
            pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 9;
            EXP0_F(0x64) = ply_ofs_pos2[sys->ply_id * 2 + 1].x;
            EXP0_F(0x68) = ply_ofs_pos2[sys->ply_id * 2 + 1].y;
            EXP0_F(0x6C) = ply_ofs_pos2[sys->ply_id * 2 + 1].z;
            epw->waxp = 0;
            EXP0_I(0x40) |= 0x80000;
            pl->ayp = (unsigned short)(epw->ay - pl->ay);
            epw->waxp = 0;
        }
        
        pl->mnwP = epw->mnwP;
        pl->frm_no = 0;
        pl->hokan_count = 5;
        pl->hokan_rate = 42598;
        pl->mtn_add = 65536;
        pl->mtn_md = 0;
        EXP0_I(0x40) |= 0x80;
        bhEne_PlayerSePlay(epw, 1026);

        if (32768 < pl->ayp)
        {
            pl->ayp = (pl->ayp - 32768) - 32768;
        }
        epw->waxp -= pl->ayp;
        pl->ayp /= 5;
        pl->ct0 = 0;
        pl->mode3++;

    case 5:
        if (pl->ct0 < 5)
        {
            epw->waxp += pl->ayp;
        } 
        else if (pl->ct0 == 5)
        {
            if (EXP0_I(0x40) & 0x4000)
            {
                epw->waxp = -32768;
            } 
            else
            {
                epw->waxp = 0;
            }
        }
        pl->ct0++;
        break;
        
    case 6:
        pl->frm_no = 0;
        pl->hokan_count = 0;
        pl->hokan_rate = 32768;
        pl->mtn_add = 65536;
        pl->flg &= ~0x10;
        if (EXP0_I(0x40) & 0x4000)
        {
             pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 12;
        } 
        else
        {
             pl->mtn_no = En26_PlyMtn_OffsetTbl[sys->ply_id] + 13;
        }
        bhEne_PlayerSePlay(epw, 1025);
        pl->mode3++;

    case 7:
        frm = pl->frm_no / 65536;
        
        if (EXP0_I(0x40) & 0x4000)
        {
            if (frm == 22 || frm == 30)
            {
                bhEne26_SePlay(epw, 8963);
            }
        }
        else
        {
            if (frm == 16 || frm == 22)
            {
                bhEne26_SePlay(epw, 8963);
            }
        }
        
        if (frm >= (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            plp->mtn_add = 0;
            sys->pad_on &= ~0xF;
            pl->flg &= ~0x10000;
            pl->stflg &= ~0x10000;
            pl->at_flg = 0;
            pl->flg |= 2;
            EXP0_I(0x40) &= ~0x4000;
            EXP0_I(0x40) &= ~0x20000;
            EXP0_I(0x40) &= ~0x80000;
            plp->flg &= ~4;
        }
        break;
    }
}

// 100% matching!
void bhEne26_Damage(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    bhEne26_DGType(epw);
}

// 100% matching!
void bhEne26_DGType(BH_PWORK* epw)
{
    bhEne26_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne26_DG00(void)
{

}

// 100% matching!
void bhEne26_DG01(void)
{

}

// 100% matching!
void bhEne26_DG02(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        if (EXP0_I(0x40) & 0x2000)
        {
            if (epw->mtn_no == 0x10)
            {                
                bhEne_ChgMtn(epw, 27, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            } 
            else
            {
                bhEne_ChgMtn(epw, 5, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            }
        }
        else
        {
            if (epw->mtn_no == 16)
            {
                bhEne_ChgMtn(epw, 28, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;
            }
            else
            {
                bhEne_ChgMtn(epw, 6, 0, 5);
                EXP0_I(0x40) &= ~0x3000000;  
            }
  
        }
        
        epw->flg |= 0x40000;
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 0x1;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;

        if ((frm == 28 && epw->mtn_no == 5)  ||
            (frm == 28 && epw->mtn_no == 27) ||
            (frm == 30 && epw->mtn_no == 6)  ||
            (frm == 30 && epw->mtn_no == 28))
        {
            if ((epw->flr_no == plp->flr_no &&
                EXP0_F(0x54) > 15.0f &&
                ikou3(epw, (NJS_POINT3*)&plp->px, 24576)))
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 7;
                epw->mode3 = 0;
            }
            else
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }

            EXP0_I(0x40) &= ~0x200;
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 0x1;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {        
    case 0:
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 6;
        epw->spd = 0.0f;
        bhEne_ChgMtn(epw, 3, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) {
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mtn_add = 0;
            EXP0_I(0x40) &= ~0x8000;
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG04(BH_PWORK* epw)
{
	int frm;
	int ang;

    switch (epw->mode3)
    {
    case 0:
        EXP0_I(0x40) &= ~0xF;
        EXP0_I(0x40) |= 6;
        bhEne_ChgMtn(epw, 4, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        if (!(EXP0_I(0x40) & 0x200))
        {
            epw->ayp = (int)(10430.381f * atan2f(epw->dvx, epw->dvz));
        }
        epw->mode3++;

    case 1:
        
        frm = epw->frm_no / 65536;        
        if (!(EXP0_I(0x40) & 0x200))
        {
            if (frm < 10) {
                ang = (unsigned short)(epw->ayp - epw->ay);
                if (ang > NJM_DEG_ANG(180.0f))
                {
                    ang -= NJM_DEG_ANG(360.0f); 
                }
                epw->ay += (ang / 2);
            }
        }

        if (frm == 10)
        {
            EXP0_I(0x40) &= ~0x100;
        }
        
        if ((16 <= frm) && (frm < 21))
        {
            epw->spd = 0.49733332f;
            bhAddSpeed(epw, 32768);
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            EXP0_I(0x40) &= ~0xF;
            EXP0_I(0x40) |= 6;
            epw->mtn_add = 0;
            EXP0_I(0x40) |= 0x8000;
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_DG15(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 16, 0, 10);
        EXP0_I(0x40) &= ~0x3000000;
        epw->flg |= 0x40000;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x2000000)
        {
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne26_Die(BH_PWORK* epw)
{
    EXP0_I(0x40) &= ~0x800;
    if (EXP0_I(0x38) != 0) {
        if ((EXP0_I(0x3C) & 0x00FFFFFF) > 0)
        {
            EXP0_I(0x3C) += 0xFFFEFEFF;
        }
        epw->mdflg |= 0x400;
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, EXP0_I(0x3C));
    }
    bhEne26_DDType(epw);
}

// 100% matching!
void bhEne26_DDType(BH_PWORK* epw)
{
  bhEne26_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne26_DD00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (!(EXP0_I(0x40) & 0x8000))
        {
            bhEne_ChgMtn(epw, 10, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        } 
        else
        {
            bhEne_ChgMtn(epw, 11, 0, 0);
            EXP0_I(0x40) &= ~0x3000000;
        }
        
        epw->mtn_add = 0;
        epw->flg |= 2;
        epw->flg &= ~0x128;
        epw->ct0 = 0;
        epw->ct1 = (rand() % 5) + 10;
        bhSetBloodPoolLnk(epw, (NJS_POINT3*)&epw->px, epw->ay, &en01_BldTbl, 0);
        epw->mode3++;

    case 1:
        if (--epw->ct0 < 0)
        {
            epw->mtn_add = 65536;
            epw->mode3++;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            if (epw->ct1-- > 0)
            {
                epw->ct0 = (rand() % 50) + 10;
                epw->mode3 = 1;
            } 
            else
            {
                epw->mode3++;  
            }          
        }
    case 3:
        break;
    }
}

// 100% matching!
int bhEne26_EatCheck(BH_PWORK* epw, int rng, float dist, int mode)
{
    NJS_SPHERE at;
    O_WORK* owk;
    NJS_POINT3 ps;
    NJS_POINT3 eps;
    float ds;

    if (EXP0_I(0x40) & 0x20000000 || plp->flg & 2 || plp->stflg & 0x80000000)
    {
        return 0;
    }
    
    owk = &plp->mlwP->owP[3];
    ps.x = owk->mtx[12];
    ps.y = plp->py;
    ps.z = owk->mtx[14];
    owk = &epw->mlwP->owP[12];
    eps.x = owk->mtx[12];
    eps.y = plp->py;
    eps.z = owk->mtx[14];

    ds = njDistanceP2P(&ps, &eps);

    switch (mode)
    {
    case 0:
        if ((bhSearchPlayer2(epw,(NJS_POINT3*) &epw->px, epw->ay, rng) == -1) ||
            (ds >= dist) ||
            (plp->py != epw->py) ||
            (plp->hp < 0))
        {
            break;
        }
            
        return 1;

    case 1:
        if ((plp->py != epw->py) || (plp->hp < 0))
        {
            break;
        }
        
        return 1;

    case 2:
        owk = &epw->mlwP->owP[12];
        ps.x = 0.0f;
        ps.y = 0.0f;
        ps.z = -4.0f;
        njCalcPoint((NJS_MATRIX*)owk->mtx, &ps, &at.c);
        at.r = 1.0f;

        if (!npCollisionCheckSC(&at, &plp->watr) ||
           (plp->py != epw->py) ||
           (plp->flg & 2) ||
           (plp->stflg & 0x80000000) ||
           (plp->hp < 0))
        {
            break;            
        }
        return 1;
       
    }
    return 0;
}

// 100% matching!
void bhEne26_ExpHeadEffect(BH_PWORK* epw, int unused)
{
	NJS_VECTOR v;
	NJS_POINT3 ps;
	NJS_POINT3 pd;
	O_WORK* owk;
	int ang1;   
	int i;

	owk = &epw->mlwP->owP[12];
	ps.x = 0.0f;
	ps.y = 0.5f;
	ps.z = -1.0f;
	njCalcPoint(&owk->mtx, &ps, &pd);

	for (i = 0; i < 4; i++)
    {
		ang1 = (int)(NJM_DEG_ANG(45.0f) + epw->py + (i * NJM_DEG_ANG(90.0f)));
		v.x = -njSin(ang1) * njCos(NJM_DEG_ANG(22.5f));
		v.y = njSin(NJM_DEG_ANG(22.5f));
		v.z = -njCos(ang1) * njCos(NJM_DEG_ANG(22.5f));
		bhEne_SetNikuhenEffect(epw, 0, &pd, &v, 7);
	}
}

// 100% matching!
void bhEne26_NeckBloodEffect(BH_PWORK* epw, int type)
{
    NJS_POINT3 ofs = { 0.0f, 1.0f, 0.0f };
    NJS_VECTOR v;
    int i;
    // not present in DWARF
    int ang;
      
    for (i = 0, ang = NJM_DEG_ANG(45.0f); i < 4; ang += NJM_DEG_ANG(90.0f), i++)
    {
        ofs.y = -1.0f;
        if (type == 0)
        {
            ofs.y = 0.0f;
            
            v.x = -(njSin(ang) * njCos(NJM_DEG_ANG(56.25f)));
            v.y = njSin(NJM_DEG_ANG(56.25f));
            v.z = -(njCos(ang) * njCos(NJM_DEG_ANG(56.25f)));
            bhEne_SetBlood3(epw, 12, &ofs, &v, 6, 8, 1, i);
            
            v.x = -(njSin(ang) * njCos(NJM_DEG_ANG(22.5f)));
            v.y = njSin(NJM_DEG_ANG(22.5f));
            v.z = -(njCos(ang) * njCos(NJM_DEG_ANG(22.5f)));
            bhEne_SetBlood3(epw, 12, &ofs, &v, 3, 8, 3, i);
        }
    }     
}

// 100% matching!
// I would like to find a better match tbh
void bhEne26_KamiEffect(BH_PWORK* epw, int frm)
{
	EN26_KAMI_WORK* keff;
	NJS_POINT3 pd;
	int i;
	int j;

	i = 0;
	keff = en26_keff_tbl;
	while (true) 
	{
		if (keff->mtn_no == -1)
        {
            return;
        }
			
		if (epw->mtn_no == keff->mtn_no)
		{
            for (j = 0; j < 4; j++)
            {
                if (frm == keff->frm[j])
                {
                	pd.x = 0.0f;
                	pd.y = 0.0f;
                	pd.z = -1.8f;
                
                	epw->djnt_no = 13;
                	bhEne_SetBlood2(epw, 1, &pd, 0);
                
                	if (j == 0)
                	{
                		epw->djnt_no = 13;
                		bhEne_SetBlood2(epw, 4, &pd, epw->ay);
                	}
                
                	return;
                }
            }
		}
		i++;
		keff++;        
	}
}

// 100% matching!
void bhEne26_SePlay(BH_PWORK* epw, int no)
{    
    if (epw->flg & 0x10000)
    {
        return;
    }

    if (((unsigned char)no >= 20) && (((unsigned char)no == 20 || (unsigned char)no == 21)))
    {
        if ((ChechPlayEnemySe(sys->enow, no)) || (!(rand() % 2)))
        {
            return;
        }
    }

    RequestEnemySe(sys->enow, (NJS_POINT3*)&epw->px, no);
}
