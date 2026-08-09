#include "../../../ps2/veronica/prog/en06.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/en06sub.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: MOTH

/*typedef struct npobj;
typedef struct _anon0;
typedef struct BH_PWORK;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
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
typedef struct _anon46;
typedef struct _anon47;

typedef void(*type_10)(BH_PWORK*);
typedef void(*type_24)(BH_PWORK*);
typedef void(*type_44)(BH_PWORK*);
typedef void(*type_56)(BH_PWORK*);
typedef void(*type_81)(BH_PWORK*);
typedef void(*type_99)(BH_PWORK*);
typedef void(*type_105)(BH_PWORK*);
typedef void(*type_108)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon1* type_6[16][16];
typedef _anon1* type_7[16][16][100];
typedef char type_8[8];
typedef _anon0* type_9[32];
typedef _anon0* type_11[512];
typedef void(*type_12)(BH_PWORK*)[1];
typedef char type_13[8];
typedef _anon1* type_14[1300];
typedef char type_15[8][8];
typedef char type_16[32];
typedef float type_17[32];
typedef _anon0* type_18[512];
typedef int type_19[2];
typedef _anon1* type_20[200];
typedef char type_21[3];
typedef short type_22[32];
typedef _anon27 type_23[1];
typedef void(*type_25)(BH_PWORK*)[5];
typedef _anon0* type_26[128];
typedef char type_27[3];
typedef unsigned int type_28[1];
typedef _anon9 type_29[256];
typedef _anon1* type_30[8];
typedef int* type_31[16];
typedef _anon0* type_32[128];
typedef _anon47 type_33[16];
typedef npobj* type_34[16];
typedef _anon0* type_35[128];
typedef int type_36[4];
typedef _anon1* type_37[16];
typedef _anon7 type_38[21];
typedef unsigned int type_39[4];
typedef float type_40[4];
typedef _anon14 type_41[16];
typedef _anon0* type_42[512];
typedef float type_43[4];
typedef void(*type_45)(BH_PWORK*)[1];
typedef char type_46[256];
typedef float type_47[4];
typedef float type_48[4];
typedef char type_49[12];
typedef float type_50[4];
typedef float type_51[4];
typedef _anon6* type_52[128];
typedef unsigned char type_53[64];
typedef float type_54[16];
typedef float type_55[3];
typedef void(*type_57)(BH_PWORK*)[6];
typedef unsigned short type_58[3];
typedef char type_59[8];
typedef char type_60[4];
typedef int type_61[16];
typedef unsigned int type_62[3];
typedef void* type_63[2];
typedef _anon1* type_64[256];
typedef int type_65[4];
typedef unsigned char* type_66[256];
typedef unsigned int type_67[2];
typedef short type_68[256];
typedef BH_PWORK type_69[0];
typedef _anon32 type_70[4];
typedef float type_71[3];
typedef short type_72[256];
typedef _anon0 type_73[0];
typedef int type_74[3];
typedef int type_75[8];
typedef float type_76[3];
typedef char type_77[2];
typedef _anon1* type_78[256];
typedef _anon11 type_79[256];
typedef _anon27 type_80[450];
typedef void(*type_82)(BH_PWORK*)[11];
typedef _anon34 type_83[16];
typedef short type_84[256];
typedef char type_85[3];
typedef int type_86[64];
typedef _anon14 type_87[450];
typedef unsigned int type_88[16];
typedef unsigned int type_89[8];
typedef char type_90[4];
typedef _anon39 type_91[4];
typedef _anon36 type_92[23];
typedef _anon2 type_93[4];
typedef int type_94[450];
typedef unsigned int type_95[8];
typedef unsigned char type_96[450];
typedef float type_97[128];
typedef float type_98[5];
typedef void(*type_100)(BH_PWORK*)[2];
typedef int type_101[5];
typedef char type_102[6];
typedef char type_103[6][1];
typedef char type_104[16];
typedef char type_106[4];
typedef char type_107[4];
typedef unsigned int type_109[32];
typedef _anon25 type_110[2];
typedef _anon28 type_111[8];
typedef unsigned char type_112[256];
typedef unsigned int type_113[16];
typedef _anon22 type_114[64];
typedef unsigned int type_115[16];
typedef _anon22 type_116[64];
typedef unsigned int type_117[32];
typedef _anon22 type_118[64];
typedef unsigned int type_119[16];
typedef unsigned int type_120[3];
typedef BH_PWORK* type_121[16];
typedef unsigned int type_122[8];
typedef unsigned int type_123[1];
typedef unsigned int type_124[384];
typedef unsigned int type_125[2];
typedef unsigned char type_126[2];
typedef unsigned int type_127[4];
typedef int* type_128[16];
typedef char type_129[32];
typedef npobj* type_130[16];
typedef char type_131[64];
typedef _anon1* type_132[16];
typedef char type_133[4];
typedef _anon14 type_134[16];
typedef short type_135[4];
typedef unsigned char type_136[4];
typedef _anon37 type_137[16];
typedef unsigned int type_138[8];
typedef unsigned int type_139[32];
typedef unsigned int type_140[4];
typedef _anon35 type_141[32];
typedef _anon0* type_142[512];
typedef _anon0* type_143[128];
typedef _anon0* type_144[512];
typedef unsigned char type_145[64];
typedef _anon0* type_146[512];

struct npobj
{
	unsigned int evalflags;
	_anon33* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
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
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon45 cspr;
	int pn;
	_anon39* pvp;
	_anon2* tvp;
	_anon39 pv[4];
	_anon2 tv[4];
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
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon46 watr;
	CPCL* cpcl;
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

struct _anon1
{
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon3 // NJS_MKEY 
{
	float key[3];
};

struct _anon4
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon5
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon6
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon7
{
	char type[3];
	char bloodstain[3];
	char exef;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon47 keyf[16];
};

struct _anon9
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon10
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
	_anon13* cutp;
	_anon17* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon21* effp;
	_anon22* walp;
	_anon22* etcp;
	_anon22* flrp;
	_anon5* posp;
	_anon22* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon8* evcp;
	unsigned int* mesp;
	_anon17* evlp;
	unsigned char* dmp00;
	unsigned char* dmp01;
	unsigned char* dmp02;
	unsigned char* dmp03;
	unsigned char* dmp04;
	unsigned char* dmp05;
	unsigned char* dmp06;
	unsigned char* dmp07;
	unsigned char* dmp08;
	unsigned char* dmp09;
	unsigned char* dmp10;
	unsigned char* dmp11;
	unsigned char* dmp12;
	unsigned char* dmp13;
	unsigned char* dmp14;
	unsigned char* dmp15;
	int cut_n;
	int lgt_n;
	int ene_n;
	int obj_n;
	int itm_n;
	int eff_n;
	int wal_n;
	int etc_n;
	int flr_n;
	int pos_n;
	int rut_n;
	int evc_n;
	int mes_n;
	int evl_n;
	int dmy00;
	int dmy01;
	int dmy02;
	int dmy03;
	int dmy04;
	int dmy05;
	int dmy06;
	int dmy07;
	int dmy08;
	int dmy09;
	int dmy10;
	int dmy11;
	int dmy12;
	int dmy13;
	int dmy14;
	int dmy15;
	int dmy16;
	int dmy17;
	unsigned int flg;
	unsigned int bak_col;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float w;
	float h;
	float d;
	float grand[32];
	_anon14 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};



struct _anon13
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon16* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon4* owP;
};

struct _anon15
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
	_anon43* info;
};

struct _anon16
{
	unsigned int attr;
	char flr_no;
	char reserve0;
	char reserve1;
	char atr_tp;
	float h;
	float dmy;
	float minx;
	float minz;
	float maxx;
	float maxz;
};

struct _anon17
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
	_anon31* light;
};

struct _anon18 ETTY_WORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	unsigned char mdlver;
	unsigned char wrk_no;
	char prm1;
	float px;
	float py;
	float pz;
	short ax;
	short az;
	short ay;
	short aspd;
	char hide[4];
};

struct _anon19
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

struct _anon20
{
	unsigned short key[3];
};

struct _anon21
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
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
};

struct _anon22
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

struct _anon23
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
	_anon35 ply_pos;
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
	_anon1* et_lp[16][16][100];
	_anon1* ot_lp[1300];
	_anon1* it_lp[200];
	int eft_n;
	_anon1* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon15* p1per;
	_anon15* p2per;
	_anon15* kbper;
	_anon15* msper;
	_anon15 ms_per;
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
	_anon6* emtp[128];
	_anon6* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon1* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon1* txblp[256];
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon1 ef_tlist;
	_anon41 ef;
	short efid[256];
	_anon14 efm[450];
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
	_anon24 ren_info;
	_anon27 ren_tex[1];
	_anon1 ren_tlist;
	_anon9 rpb[256];
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
	_anon42 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon17* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon32 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon34 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon22* pl_htp;
	int costume;
	_anon35 hd_pos;
	_anon35 apos;
	_anon22* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon22 mwalp[64];
	_anon22 metcp[64];
	_anon22 mflrp[64];
	int dla_n;
	_anon22* htp;
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
	_anon1* sb_tlist;
	int ddmd;
	_anon19 door;
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
	_anon35 ufo_pos;
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
	_anon37 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon35 ghtp[32];
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

struct _anon24
{
	void* texaddr;
	_anon10 texsurface;
};

struct _anon25
{
	unsigned short flg;
	unsigned char lgtclip;
	char spd;
	float px;
	float py;
	float pz;
	float ln;
	float w;
	float h;
	float d;
	float y0;
	float y1;
	float y2;
	float y3;
	float am_spd;
	int ax;
	int ay;
	int az;
	int lax;
	int lay;
	short laz0;
	short laz1;
	short laz2;
	short laz3;
	char aa_spd;
	char fil_no;
	char fil_rt;
	char reserve;
	int pers;
	unsigned int hidobj[16];
	unsigned int hidlgt[8];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
};

struct _anon26
{
	void* p[2];
};

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon29
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon30
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon31
{
	float mtrx[16];
	_anon35 pnt;
	_anon35 vctr;
	int stat;
	int reserve;
	_anon38 ltcal;
	_anon44 attr;
};

struct _anon32
{
	_anon35 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon33
{
	int* vlist;
	short* plist;
	_anon35 center;
	float r;
};

struct _anon34
{
	float x;
	float y;
};

struct _anon35
{
	float x;
	float y;
	float z;
};

struct _anon36
{
	int flg;
	_anon35 ofp;
	float rx;
	float ry;
	float rz;
};

struct _anon37
{
	_anon35 c1;
	_anon35 c2;
	float r1;
	float r2;
};

struct _anon38
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
	_anon35 lpnt;
	_anon35 lvctr;
	_anon35 lmvctr;
	_anon30 atten;
	_anon30 amb;
	_anon30 dif;
	_anon30 spc;
	_anon30 mamb;
	_anon30 mdif;
	_anon30 mspc;
};

struct _anon39
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon40
{
	_anon35 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon41
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

struct _anon42
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon43
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

struct _anon44
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
	_anon30 argb;
};

struct _anon45
{
	_anon35 c;
	float r;
};

struct _anon46
{
	_anon35 c1;
	_anon35 c2;
	float r;
};

struct _anon47
{
	unsigned short flg;
	short frame;
	float px;
	float py;
	float pz;
	short ax;
	short ay;
	short az;
	short pers;
	unsigned int hidobj[8];
	unsigned int hidlgt[4];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	short lkflg;
	short lkno;
	short lkono;
	short nxt_no;
	float lx;
	float ly;
	float lz;
	float prm_0;
	float prm_1;
	float prm_2;
	float prm_3;
	float prm_4;
	unsigned char* recp;
};

*/
static int ENE06_HITPOINT[16] = 
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1
};

static char junction_tree[1][6] =
{
    { 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 }
};

/*
char player_junction_tree[8][8];  // unused?
*/

static char SdwTab[2] = { 0x00, 0xFF };

static ETTY_WORK ene06_child =
{
    0x8001,                                 /* flg */
    0x1F,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};

static char BrokenParts[12] = {0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};

static ETTY_WORK ene27 =
{
    0x8001,                                 /* flg */
    0x1B,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};


static ETTY_WORK ene06_leader =
{
    0x01008001,                             /* flg */
    0x06,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};

static BP_WORK BloodParam =
{
    {0.0f, 0.01f, 0.0f},                    /* off_pos */
    0,                                      /* srd_dir */
    0.0f,                                   /* srd_pos */
    0.05f,                                  /* bld_spd */
    {0.3f, 0.7f, 0.5f, 0.7f, 0.4f},         /* srt_spd */
    {0, 3, 6, 9, 12}                        /* srt_dir */
};

static CPCL CapColTab[8] =
{
    { 1,  1,  5 },                          /* [0] */
    { 0,  0, -6 },                          /* [1] */
    { 1,  2,  5 },                          /* [2] */
    { 2,  4,  6 },                          /* [3] */
    { 4,  6,  7 },                          /* [4] */
    { 6,  8,  7 },                          /* [5] */
    { 8, 10,  6 },                          /* [6] */
    { 0,  0,  0 }                           /* [7] */
};

static DMG_REACT DmgReact[21] =
{
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 0] */
    { {  0,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 1] */
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          /* [ 2] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 3] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 4] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 5] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 6] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 7] */
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          /* [ 8] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [ 9] */
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          /* [10] */
    { {  2,  1,  0 }, {  1,  0,  0 }, 0 },          /* [11] */
    { {  0,  0,  0 }, {  0,  0,  0 }, 0 },          /* [12] */
    { {  1,  1,  0 }, {  0,  0,  0 }, 0 },          /* [13] */
    { {  2,  1,  0 }, {  1,  1,  1 }, 1 },          /* [14] */
    { { -1, -1, -1 }, {  0,  0,  0 }, 2 },          /* [15] */
    { { -1, -1, -1 }, {  0,  0,  0 }, 1 },          /* [16] */
    { { -1, -1, -1 }, {  0,  0,  0 }, 0 },          /* [17] */
    { {  2,  2,  2 }, {  1,  1,  1 }, 5 },          /* [18] */
    { {  2,  2,  2 }, {  0,  0,  0 }, 1 },          /* [19] */
    { {  2,  2,  2 }, {  1,  1,  1 }, 5 }           /* [20] */
};

static BLOOD_TBL BloodTbl[23] =
{
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [ 0] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 1] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 2] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 3] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 4] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 5] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 6] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 7] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 8] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [ 9] */
    { 1, {  0.0f,  0.0f,  0.0f },  1.0f,  1.0f,  1.0f },     /* [10] */
    { 0, {  2.0f,  0.0f, -1.0f },  1.0f,  0.0f,  1.0f },     /* [11] */
    { 0, { -2.0f,  0.0f, -1.0f },  1.0f,  0.0f,  1.0f },     /* [12] */
    { 0, {  1.0f,  0.0f,  1.0f },  1.0f,  0.0f,  1.0f },     /* [13] */
    { 0, { -1.0f,  0.0f,  1.0f },  1.0f,  0.0f,  1.0f },     /* [14] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [15] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [16] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [17] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [18] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [19] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [20] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f },     /* [21] */
    { 1, {  0.0f,  0.0f,  0.0f },  0.0f,  0.0f,  0.0f }      /* [22] */
};

typedef void (*bhEne06_Mode0_proc)(BH_PWORK*);
typedef void (*bhEne06_BrainType_proc)(BH_PWORK*);
typedef void (*bhEne06_MoveMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_NageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DamageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DeadMode2_proc)(BH_PWORK*);

bhEne06_Mode0_proc bhEne06_Mode0[6] =
{
    bhEne06_Init,                           
    bhEne06_Move,                           
    bhEne06_Nage,                           
    bhEne06_Damage,                         
    bhEne06_Die,                            
    bhEne_Event                             
};

bhEne06_BrainType_proc bhEne06_BrainType[1] =
{
    bhEne06_BR00
};

bhEne06_MoveMode2_proc bhEne06_MoveMode2[11] =
{
    bhEne06_MV00,                           
    bhEne06_MV01,                           
    bhEne06_MV02,                           
    bhEne06_MV03,                           
    bhEne06_MV04,
    bhEne06_MV05,
    bhEne06_MV06,
    bhEne06_MV07,
    bhEne06_MV08,
    bhEne06_MV09,
    bhEne06_MV10 
};

bhEne06_NageMode2_proc bhEne06_NageMode2[1] =
{
    bhEne06_NG00
};

bhEne06_DamageMode2_proc bhEne06_DamageMode2[2] =
{
    bhEne06_DG00,
    bhEne06_DG01
};

bhEne06_DeadMode2_proc bhEne06_DeadMode2[5] =
{
    bhEne06_DD00,
    bhEne06_DD01, 
    bhEne06_DD02,
    bhEne06_DD03,
    bhEne06_DD04
};

/*
BH_PWORK* plp;
_anon0 eff[0];
void(*bhEne06s)(BH_PWORK*);
_anon12* rom;
_anon23* sys;
BH_PWORK ene[0];*/

// 100% matching!
void bhEne06(BH_PWORK* epw)
{
    if ((epw->flg & 0x1000000))
    {
        if ((*(int*)epw->exp1 & 1) != 0)
        {
            if(plp->mode0 == 4)
            {
                bhEne06_PlayerControl(epw);
            }
        }
    } 
    else 
    {
        bhEne06_Mode0[epw->mode0](epw);
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->car += ((EXP0_F(0x70) - epw->car) / 8.0f);
        
        bhCheckPlayer(epw);
        
        if (epw->flg & 8)
        {
            bhEne_CheckEnemiesBall(epw);
        }
        
        bhEne06_FloorCollision(epw);
        
        if (epw->flg & 0x10)
        {
            bhEne06_CollisionWalls(epw);
        }
        
        bhCalcModel(epw);
        
        bhEne_SetWeponAtr(epw, 10, 1, 2.0f);
        
        return;
    }
}

// 99.69% matching
void bhEne06_Init(BH_PWORK* epw)
{
	int sdw;
	int i;
	BH_PWORK* ep_leader;
	BH_PWORK* ep;
	BH_PWORK** epw2;
	O_WORK* owk;
    
    // not present in DWARF
	int ene_n;

	epw->flg |= 0x78;
	epw->flg &= ~0x9006;
	epw->flg &= ~0x800000;

	epw->ar = 5.0f;
	epw->ah = 1.0f;
	epw->car = 3.0f;
	epw->cah = 3.0f;

	epw->hp = ENE06_HITPOINT[(int)(16.0f * njRandom())];

	epw->hokan_rate = 65536;
	epw->hokan_count = 0;
	epw->mtn_no = 4;
	epw->mtn_md = 0;
	epw->mtn_add = 65536;
	epw->frm_no = 0;

	epw->mode0 = 1;
	epw->mode1 = 0;
	epw->mode2 = 0;
	epw->mode3 = 0;

	owk = epw->mlwP->owP;
	for (i = 0; i < epw->mnwP->obj_num; i++, owk++)
    {
		owk->flg &= ~3;
	}

	if (epw->exp0 == NULL)
    {
		epw->exp0 = (unsigned char*)bhEne_CallocWork(176, 8);
		ep = (BH_PWORK*)ene;
		for (i = 0; i < sys->ewk_n; i++, ep++)
        {
			if ((ep->flg & 1) && ep->id == 6)
            {
				if (ep->exp1 != NULL)
                {
					epw->exp1 = ep->exp1;
				} 
                else
                {
					epw->exp1 = (unsigned char*)bhEne_CallocWork(12, 8);
				}

				if (ep->exp2 != NULL)
                {
					epw->exp2 = ep->exp2;
				} 
                else
                {
					ene_n = rom->ene_n;
					ep_leader = bhSetEnemy((EGG_WORK*)&ene06_leader, ene_n);
					epw->exp2 = (unsigned char*)ep_leader;
					ep_leader->mdflg |= 0x21;
					ep_leader->exp1 = epw->exp1;
					ep_leader->mnwP = epw->mnwP;
				}
				break;
			}
		}

		epw2 = (BH_PWORK**)(epw->exp0 + 0x34);
		for (i = 0; i < 14; i++, epw2++)
        {
			ene_n = rom->ene_n;
			*epw2 = bhSetEnemy((EGG_WORK*)&ene06_child, ene_n);
			(*epw2)->lkwkp = (unsigned char*)epw;
			(*epw2)->lkono = i;
			(*epw2)->lox = 0.0f;
			(*epw2)->loy = 0.0f;
			(*epw2)->loz = 0.0f;
			(*epw2)->mdflg |= 1;
			(*epw2)->mtx = &epw->mlwP->owP[BrokenParts[i]].mtx;
        }
		bhEne_SetCallFunc((void (*)(BH_PWORK*))&bhEne06s, 31);
	}

	EXP0_F(0x6c) = epw->ar;
	EXP0_F(0x70) = epw->car;
	EXP0_I(0x74) = (int)(30.0f * njRandom()) + 20;

	if (!(epw->flg & 0x800))
    {
		sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 5.0f, 4.0f, 4.0f);
		eff[sdw].mdlver = 1;
		epw->flg |= 0x800;
		*(O_WRK **)((epw->exp0 + 0x84)) = &eff[sdw];
	}

	epw->stflg &= ~8;
	epw->clp_jno[0] = 11;
	epw->clp_jno[1] = 12;
	epw->clp_jno[2] = 13;
	epw->clp_jno[3] = 14;
	epw->clp_jno[4] = 1;
	epw->clp_jno[5] = 2;
	epw->clp_jno[6] = -1;

	epw->cpcl = CapColTab;
	epw->flg |= 0x100000;

	epw->mlwP->objP[1].evalflags &= ~8;
	epw->mlwP->objP[2].evalflags &= ~8;
}

// 100% matching!
void bhEne06_Brain(BH_PWORK* epw)
{ 
    bhEne06_BrainType[epw->type](epw); 
}

// Start address: 0x1b9de0
void bhEne06_BR00(BH_PWORK* epw)
{
	// Line 608, Address: 0x1b9de0, Func Offset: 0
	// Line 610, Address: 0x1b9dec, Func Offset: 0xc
	// Line 613, Address: 0x1b9df4, Func Offset: 0x14
	// Line 617, Address: 0x1b9e08, Func Offset: 0x28
	// Line 618, Address: 0x1b9e38, Func Offset: 0x58
	// Line 619, Address: 0x1b9e40, Func Offset: 0x60
	// Line 620, Address: 0x1b9e44, Func Offset: 0x64
	// Line 624, Address: 0x1b9e48, Func Offset: 0x68
	// Line 625, Address: 0x1b9e74, Func Offset: 0x94
	// Line 628, Address: 0x1b9e7c, Func Offset: 0x9c
	// Line 632, Address: 0x1b9ea0, Func Offset: 0xc0
	// Line 636, Address: 0x1b9f44, Func Offset: 0x164
	// Line 637, Address: 0x1b9f48, Func Offset: 0x168
	// Line 638, Address: 0x1b9f4c, Func Offset: 0x16c
	// Line 639, Address: 0x1b9f50, Func Offset: 0x170
	// Line 642, Address: 0x1b9f54, Func Offset: 0x174
	// Line 643, Address: 0x1b9f68, Func Offset: 0x188
	// Line 642, Address: 0x1b9f6c, Func Offset: 0x18c
	// Line 643, Address: 0x1b9f74, Func Offset: 0x194
	// Line 647, Address: 0x1b9f84, Func Offset: 0x1a4
	// Func End, Address: 0x1b9f94, Func Offset: 0x1b4
    scePrintf("bhEne06_BR00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_Move(BH_PWORK* epw)
{
    bhEne06_MoveMode2[epw->mode2](epw);
    if ((epw->flg & 4) && !(epw->flg & 2))
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;      
        epw->flg &= ~4;        
        bhEne06_Damage(epw);
        return;
    }
    if (epw->mode1 == 1)
    {
        bhEne06_Brain(epw);
    }
}

// 100% matching!
void bhEne06_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->mtn_no = 4;
        epw->frm_no = epw->mnwP[epw->mtn_no].frm_num * (32768.0f * njRandom());
        epw->hokan_count = 0;
        
        epw->flg |= 0x180000;
        epw->flg &= ~0x400000;
        
        if (njRandom() < 0.8f)
        {
            epw->ct0 = (int)(30.0f * njRandom()) + 30;
        } 
        else
        {
            epw->ct0 = (int)(90.0f * njRandom()) + 120;
        }
        epw->mode3++;

    case 1:
        epw->ax += (short)-epw->ax / 8;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_MV01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->ct1 = (njRandom() > 0.5f);
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x580000;
        epw->ar = 0.1f;
        EXP0_F(0x6C) = 5.0f;
        epw->spd = 1.0f;
        
        if (epw->ct1 != 0)
        {
          epw->ayp = epw->ay + 16384;
        }
        else
        {
          epw->ayp = epw->ay - 16384;
        }
        
        epw->ct0 = 14;
        epw->ct2 = 8;
        epw->mode3++;
        break;
        
    case 1:
        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ct0--;
        } 
        else
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;                        
        } 
        else
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;
    
                }
            }
        }

        if (epw->ct2 != 0)
        {
            ((BH_PWORK*)EXP0_I(0x84))->sy += (4.0f - ((BH_PWORK*)EXP0_I(0x84))->sy) / (float)epw->ct2;
            epw->ct2--;
        }
    }
}

#pragma divbyzerocheck off

// 99.95% matching
void bhEne06_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        epw->flg |= 0x580000;
        epw->flg &= ~0x2180000;
        epw->spd = 1.0f;
        epw->ct0 = (int)(128.0f * njRandom()) + 90;
        epw->ct1 = (njRandom() > 0.5f) ? 1 : -1; 
        epw->ct2 = 20;
        epw->ct3 = (int)(20.0f * njRandom()) + 10;
        epw->yn = 10.0f + plp->py + (20.0f * njRandom());
        epw->ayp = (int)(epw->ay + ((7281.0f * njRandom()) - 3640.0f));
        EXP0_F(0x20) = 0.0f;
        epw->mode3++;

    case 1:
        EXP0_F(0x20) += 0.1f * (epw->yn - epw->py);

        if (EXP0_F(0x20) > 0.4f)
        {
            EXP0_F(0x20) = 0.4f;
        }
        
        if (EXP0_F(0x20) < -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-3640 - epw->ax) / 16;
        } 
        else
        {
            epw->ax += (short)(-10922 - epw->ax) / 16;
        }
        
        bhAddSpeed(epw, 0);
        epw->ct0 = epw->ct0;
        if (epw->ct0 > 0)
        {
            epw->ct0--;
            if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
            {
                epw->flg |= 0x2000000;
            } 
            else if (!(epw->flg & 0x2000000))
            {
                epw->ay += (short)(epw->ayp - epw->ay) / 16;
            }
        } 
        else if (bhEne06_CheckLeaningWall(epw) != 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 8;
            epw->mode3 = 0;
        } 
        else if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
        {
            epw->flg |= 0x2000000;
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->ay += (short)(epw->ayp - epw->ay) / 16;
        }

        if (epw->ct3-- == 0)
        {
            epw->yn = 15.0f + plp->py + (10.0f * njRandom());
            epw->ayp = (int)(epw->ay + ((7281.0f * njRandom()) - 3640.0f));
            epw->ct3 = (int)(10.0f * njRandom()) + 20;
            epw->flg &= ~0x2000000;
        }
        
        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74497);
            epw->ct2 = (int)(5.0f * njRandom()) + 20;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;
        } 
        else 
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;    
                }
            } 
        }
    }
}

// 99.97% matching
void bhEne06_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 0)
        {
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg |= 0x580000;
        epw->flg &= ~0x2180000;
        epw->spd = 1.0f;
        
        epw->ct0 = (int) (63.0f * njRandom()) + 20;
        epw->ct1 = (njRandom() > 0.5f) ? 1 : -1;       
        epw->ct2 = 20;
        epw->ct3 = (int)(20.0f * njRandom()) + 10;
        
        epw->yn = 15.0f + plp->py + (10.0f * njRandom());
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        EXP0_F(0x20) = 0.0f;
        epw->mode3++;

    case 1:
        EXP0_F(0x20) += (0.1f * (epw->yn - epw->py));

        if (EXP0_F(0x20) > 0.4f)
        {
             EXP0_F(0x20) = 0.4f;
        }

        if (EXP0_F(0x20)< -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-epw->ax) / 8;
        } 
        else
        {
            epw->ax += (short)(-3640 - epw->ax) / 8;
        }
        
        bhAddSpeed(epw, 0);
        if (bhEne06_AvoidWall(epw, epw->ct1) != 0)
        {
            epw->flg |= 0x2000000;
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->ay += (short)(epw->ayp - epw->ay) / 16;
        }

        if (epw->ct3-- == 0)
        {
            epw->yn = 10.0f + plp->py + (10.0f * njRandom());
            epw->ayp = (int)(bhArcTan2(epw->px - plp->px, epw->pz - plp->pz) + ((7281.0f * njRandom()) - 3640.0f));
            epw->ct3 = (int)(10.0f * njRandom()) + 20;
        }

        if (epw->ct2-- == 0) {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74497);
            epw->ct2 = 20;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        if (plp->flg & 4)
        {
            EXP0_I(0x74) = (int)(30.0f * njRandom()) + 60;
        } 
        else
        {
            EXP0_I(0x74)--;
            if (EXP0_I(0x74) < 0)
            {
                bhEne06_SetRinpunEffect(epw, 1, 0);
                if (EXP0_I(0x74) < -5)
                {
                    EXP0_I(0x74) = (int)(30.0f * njRandom()) + 30;
                }
            }
        }
    }
}

// 100% matching!
void bhEne06_MV04(void)
{

}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mode3++;
        
        epw->ct0 = (int)(8.0f * njRandom()) + 14;
        epw->ayp = epw->ay + 32768;
        epw->spd = 1.0f;
        epw->flg |= 0x50;
        epw->car = 0.1f;
        
        EXP0_F(0x70) = 3.0f;
        epw->ar = 0.1f;
        EXP0_F(0x6C) = 5.0f;
        epw->yn = 15.0f + plp->py + (20.0f * njRandom());
        EXP0_F(0x20) = 0.0f;
        
    case 1:
        EXP0_F(0x20) += (0.1f * (epw->yn - epw->py));

        if (EXP0_F(0x20) > 0.4f)
        {
            EXP0_F(0x20) = 0.4f;
        }

        if (EXP0_F(0x20) < -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-epw->ax) / 8;
        } 
        else
        {
            epw->ax += (short)(-3640 - epw->ax) / 8;
        }

        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ct0--;
            break;
        }
        
        epw->car = 3.0f;
        
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        
        epw->ax = 0;

    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne06_MV06(void)
{

}

// 100% matching!
void bhEne06_MV07(void)
{

}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_MV08(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        
        epw->flg |= 0x580000;
        epw->flg &= ~0x400000;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 8;
        epw->mode3++;
        
    case 1:
        if (epw->ct1 != 0)
        {
            epw->ax += (short)-epw->ax / epw->ct1;
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
            
            epw->px = epw->px + ((EXP0_F(0x28)- epw->px) / epw->ct1);   
            epw->pz = epw->pz + ((EXP0_F(0x30) - epw->pz) / epw->ct1);
            
            ((BH_PWORK*)EXP0_I(0x84))->sy += (2.0f - ((BH_PWORK*)EXP0_I(0x84))->sy) / (float)epw->ct1;
            
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->ay = epw->ayp;
            
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->mtn_no = 4;
            epw->frm_no = 0;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne06_MV09(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 15)
        {
            epw->mtn_no = 15;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 100% matching!
void bhEne06_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 16)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 100% matching!
void bhEne06_Nage(BH_PWORK* epw)
{
    bhEne06_NageMode2[epw->mode2](epw);
}

// 
// Start address: 0x1bbd70
void bhEne06_NG00(BH_PWORK* epw)
{
	unsigned int flg[3];
	int type;
	int i;
	BH_PWORK* epw2;
	//_anon4* owk;
	//_anon35 v;
	//_anon35 offset;
	//_anon35 pos;
	// Line 1343, Address: 0x1bbd70, Func Offset: 0
	// Line 1346, Address: 0x1bbd84, Func Offset: 0x14
	// Line 1349, Address: 0x1bbda4, Func Offset: 0x34
	// Line 1351, Address: 0x1bbdac, Func Offset: 0x3c
	// Line 1350, Address: 0x1bbdb0, Func Offset: 0x40
	// Line 1351, Address: 0x1bbdb4, Func Offset: 0x44
	// Line 1352, Address: 0x1bbdb8, Func Offset: 0x48
	// Line 1355, Address: 0x1bbdc0, Func Offset: 0x50
	// Line 1357, Address: 0x1bbdc4, Func Offset: 0x54
	// Line 1356, Address: 0x1bbdc8, Func Offset: 0x58
	// Line 1357, Address: 0x1bbdd0, Func Offset: 0x60
	// Line 1355, Address: 0x1bbdd4, Func Offset: 0x64
	// Line 1356, Address: 0x1bbde0, Func Offset: 0x70
	// Line 1357, Address: 0x1bbde8, Func Offset: 0x78
	// Line 1360, Address: 0x1bbdf4, Func Offset: 0x84
	// Line 1357, Address: 0x1bbdf8, Func Offset: 0x88
	// Line 1360, Address: 0x1bbe00, Func Offset: 0x90
	// Line 1363, Address: 0x1bbe28, Func Offset: 0xb8
	// Line 1364, Address: 0x1bbe2c, Func Offset: 0xbc
	// Line 1371, Address: 0x1bbe30, Func Offset: 0xc0
	// Line 1360, Address: 0x1bbe34, Func Offset: 0xc4
	// Line 1363, Address: 0x1bbe38, Func Offset: 0xc8
	// Line 1364, Address: 0x1bbe44, Func Offset: 0xd4
	// Line 1367, Address: 0x1bbe50, Func Offset: 0xe0
	// Line 1368, Address: 0x1bbe70, Func Offset: 0x100
	// Line 1370, Address: 0x1bbe7c, Func Offset: 0x10c
	// Line 1371, Address: 0x1bbe80, Func Offset: 0x110
	// Line 1374, Address: 0x1bbe84, Func Offset: 0x114
	// Line 1376, Address: 0x1bbe90, Func Offset: 0x120
	// Line 1374, Address: 0x1bbe94, Func Offset: 0x124
	// Line 1376, Address: 0x1bbe9c, Func Offset: 0x12c
	// Line 1378, Address: 0x1bbea8, Func Offset: 0x138
	// Line 1382, Address: 0x1bbeb4, Func Offset: 0x144
	// Line 1383, Address: 0x1bbec4, Func Offset: 0x154
	// Line 1384, Address: 0x1bbed8, Func Offset: 0x168
	// Line 1387, Address: 0x1bbedc, Func Offset: 0x16c
	// Line 1384, Address: 0x1bbee0, Func Offset: 0x170
	// Line 1383, Address: 0x1bbee4, Func Offset: 0x174
	// Line 1384, Address: 0x1bbee8, Func Offset: 0x178
	// Line 1383, Address: 0x1bbeec, Func Offset: 0x17c
	// Line 1384, Address: 0x1bbef0, Func Offset: 0x180
	// Line 1388, Address: 0x1bbef8, Func Offset: 0x188
	// Line 1384, Address: 0x1bbefc, Func Offset: 0x18c
	// Line 1387, Address: 0x1bbf04, Func Offset: 0x194
	// Line 1388, Address: 0x1bbf14, Func Offset: 0x1a4
	// Line 1390, Address: 0x1bbf1c, Func Offset: 0x1ac
	// Line 1392, Address: 0x1bbf28, Func Offset: 0x1b8
	// Line 1396, Address: 0x1bbf34, Func Offset: 0x1c4
	// Line 1392, Address: 0x1bbf38, Func Offset: 0x1c8
	// Line 1396, Address: 0x1bbf3c, Func Offset: 0x1cc
	// Line 1392, Address: 0x1bbf44, Func Offset: 0x1d4
	// Line 1393, Address: 0x1bbf54, Func Offset: 0x1e4
	// Line 1394, Address: 0x1bbf74, Func Offset: 0x204
	// Line 1396, Address: 0x1bbf94, Func Offset: 0x224
	// Line 1397, Address: 0x1bbf9c, Func Offset: 0x22c
	// Line 1398, Address: 0x1bbfb8, Func Offset: 0x248
	// Line 1400, Address: 0x1bbfdc, Func Offset: 0x26c
	// Line 1401, Address: 0x1bc010, Func Offset: 0x2a0
	// Line 1403, Address: 0x1bc044, Func Offset: 0x2d4
	// Line 1404, Address: 0x1bc04c, Func Offset: 0x2dc
	// Line 1406, Address: 0x1bc054, Func Offset: 0x2e4
	// Line 1407, Address: 0x1bc05c, Func Offset: 0x2ec
	// Line 1408, Address: 0x1bc064, Func Offset: 0x2f4
	// Line 1411, Address: 0x1bc06c, Func Offset: 0x2fc
	// Line 1412, Address: 0x1bc078, Func Offset: 0x308
	// Line 1413, Address: 0x1bc084, Func Offset: 0x314
	// Line 1417, Address: 0x1bc08c, Func Offset: 0x31c
	// Line 1413, Address: 0x1bc098, Func Offset: 0x328
	// Line 1414, Address: 0x1bc09c, Func Offset: 0x32c
	// Line 1415, Address: 0x1bc0a8, Func Offset: 0x338
	// Line 1417, Address: 0x1bc0b0, Func Offset: 0x340
	// Line 1418, Address: 0x1bc0b8, Func Offset: 0x348
	// Line 1419, Address: 0x1bc0d4, Func Offset: 0x364
	// Line 1423, Address: 0x1bc0f8, Func Offset: 0x388
	// Line 1425, Address: 0x1bc108, Func Offset: 0x398
	// Line 1426, Address: 0x1bc10c, Func Offset: 0x39c
	// Line 1428, Address: 0x1bc110, Func Offset: 0x3a0
	// Line 1430, Address: 0x1bc114, Func Offset: 0x3a4
	// Line 1425, Address: 0x1bc118, Func Offset: 0x3a8
	// Line 1426, Address: 0x1bc120, Func Offset: 0x3b0
	// Line 1428, Address: 0x1bc12c, Func Offset: 0x3bc
	// Line 1429, Address: 0x1bc130, Func Offset: 0x3c0
	// Line 1430, Address: 0x1bc134, Func Offset: 0x3c4
	// Line 1431, Address: 0x1bc138, Func Offset: 0x3c8
	// Line 1435, Address: 0x1bc13c, Func Offset: 0x3cc
	// Line 1436, Address: 0x1bc150, Func Offset: 0x3e0
	// Line 1439, Address: 0x1bc160, Func Offset: 0x3f0
	// Line 1446, Address: 0x1bc174, Func Offset: 0x404
	// Line 1439, Address: 0x1bc180, Func Offset: 0x410
	// Line 1446, Address: 0x1bc184, Func Offset: 0x414
	// Line 1449, Address: 0x1bc190, Func Offset: 0x420
	// Line 1450, Address: 0x1bc1cc, Func Offset: 0x45c
	// Line 1449, Address: 0x1bc1d4, Func Offset: 0x464
	// Line 1450, Address: 0x1bc1d8, Func Offset: 0x468
	// Line 1451, Address: 0x1bc1dc, Func Offset: 0x46c
	// Line 1452, Address: 0x1bc1f8, Func Offset: 0x488
	// Line 1453, Address: 0x1bc1fc, Func Offset: 0x48c
	// Line 1455, Address: 0x1bc204, Func Offset: 0x494
	// Line 1456, Address: 0x1bc208, Func Offset: 0x498
	// Line 1457, Address: 0x1bc218, Func Offset: 0x4a8
	// Line 1460, Address: 0x1bc228, Func Offset: 0x4b8
	// Line 1463, Address: 0x1bc240, Func Offset: 0x4d0
	// Line 1461, Address: 0x1bc244, Func Offset: 0x4d4
	// Line 1463, Address: 0x1bc248, Func Offset: 0x4d8
	// Line 1467, Address: 0x1bc24c, Func Offset: 0x4dc
	// Func End, Address: 0x1bc260, Func Offset: 0x4f0
    scePrintf("bhEne06_NG00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_Damage(BH_PWORK* epw)
{
    int i;
    int dir;
    int dam;

    for (i = 0, dam = 0; i < epw->mnwP->obj_num; i++)
    {
        if (epw->dam[i])
        {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }
    
    epw->hp -= dam;

    if (epw->mode3 == 0)
    {
        bhEne06_HitMark(epw);
        bhEne06_SetRinpunEffect(epw, 8, 1);
        dir = bhEne_DGDirCheck(epw);

        if ((dam < 31) && (epw->flg & 0x400000) && (njRandom() < 0.4f))
        {
            epw->mode2 = (dir != 0) ? 0 : 1;
        } 
        else
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            if (epw->flg & 0x800000)
            {
                epw->mode2 = 4;
            } 
            else if (30 < dam)
            {
                epw->mode2 = 3;
                epw->dpx = epw->px;
                epw->dpy = epw->py;
                epw->dpz = epw->pz;
                bhEne_SetMinceEffect2(epw, 2, 0.3f, 6);
                bhEne_SetMinceEffect2(epw, 259, 0.3f, 8);
            } 
            else if (epw->flg & 0x400000)
            {
                epw->mode2 = (dir != 0) ? 1 : 2;
            } 
            else
            {
                epw->mode2 = 0;
            }
            
            epw->flg |= 2;
            epw->flg &= ~0x28;
            bhEne06_Die(epw);
            return;
        }        
    }
    bhEne06_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne06_DG00(BH_PWORK* epw) {
	NJS_POINT3 pos;
	int pno;
	O_WORK* owk;
	char parts[4] = { 0xB, 0xC, 0xD, 0xE }; 
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 10;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));
        EXP0_F(0x20) *= 0.5f;
        
        owk = epw->mlwP->owP;
        pno = (int)(4.0f * njRandom());
        owk[parts[pno]].flg |= 3;
        
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[12] = 1;
	    (*(unsigned char **)((char *)epw->exp0 + 0x34 + pno * 4))[14] = 1;
        
        EXP0_F(0x70) = 1.0f;
        
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8964);
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0) {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 12;
            epw->frm_no = 0;
            
            epw->flg &= ~0x80000;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 14;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        }
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 10;
            epw->mode3 = 0;
            epw->flg &= ~0x40;
        }
    }
    epw->ax += (short)(-epw->ax) / 8;
}

// 
// Start address: 0x1bc880
void bhEne06_DG01(BH_PWORK* epw)
{
	//_anon35 trans;
	//_anon3* mkfP;
	char parts[4];
	//_anon4* owk;
	int pno;
	//_anon35 pos;
	// Line 1691, Address: 0x1bc880, Func Offset: 0
	// Line 1695, Address: 0x1bc88c, Func Offset: 0xc
	// Line 1691, Address: 0x1bc890, Func Offset: 0x10
	// Line 1695, Address: 0x1bc894, Func Offset: 0x14
	// Line 1691, Address: 0x1bc898, Func Offset: 0x18
	// Line 1695, Address: 0x1bc89c, Func Offset: 0x1c
	// Line 1702, Address: 0x1bc8ac, Func Offset: 0x2c
	// Line 1704, Address: 0x1bc8e4, Func Offset: 0x64
	// Line 1706, Address: 0x1bc8ec, Func Offset: 0x6c
	// Line 1705, Address: 0x1bc8f0, Func Offset: 0x70
	// Line 1706, Address: 0x1bc8f4, Func Offset: 0x74
	// Line 1707, Address: 0x1bc8f8, Func Offset: 0x78
	// Line 1709, Address: 0x1bc900, Func Offset: 0x80
	// Line 1710, Address: 0x1bc908, Func Offset: 0x88
	// Line 1709, Address: 0x1bc910, Func Offset: 0x90
	// Line 1710, Address: 0x1bc918, Func Offset: 0x98
	// Line 1715, Address: 0x1bc924, Func Offset: 0xa4
	// Line 1716, Address: 0x1bc930, Func Offset: 0xb0
	// Line 1717, Address: 0x1bc93c, Func Offset: 0xbc
	// Line 1718, Address: 0x1bc948, Func Offset: 0xc8
	// Line 1719, Address: 0x1bc954, Func Offset: 0xd4
	// Line 1720, Address: 0x1bc958, Func Offset: 0xd8
	// Line 1724, Address: 0x1bc960, Func Offset: 0xe0
	// Line 1720, Address: 0x1bc964, Func Offset: 0xe4
	// Line 1721, Address: 0x1bc970, Func Offset: 0xf0
	// Line 1724, Address: 0x1bc974, Func Offset: 0xf4
	// Line 1727, Address: 0x1bc978, Func Offset: 0xf8
	// Line 1728, Address: 0x1bc97c, Func Offset: 0xfc
	// Line 1729, Address: 0x1bc9b8, Func Offset: 0x138
	// Line 1730, Address: 0x1bc9c0, Func Offset: 0x140
	// Line 1734, Address: 0x1bc9c4, Func Offset: 0x144
	// Line 1729, Address: 0x1bc9cc, Func Offset: 0x14c
	// Line 1730, Address: 0x1bc9e0, Func Offset: 0x160
	// Line 1734, Address: 0x1bc9e4, Func Offset: 0x164
	// Line 1729, Address: 0x1bc9e8, Func Offset: 0x168
	// Line 1730, Address: 0x1bc9f0, Func Offset: 0x170
	// Line 1731, Address: 0x1bca00, Func Offset: 0x180
	// Line 1734, Address: 0x1bca0c, Func Offset: 0x18c
	// Line 1736, Address: 0x1bca14, Func Offset: 0x194
	// Line 1737, Address: 0x1bca34, Func Offset: 0x1b4
	// Line 1740, Address: 0x1bca40, Func Offset: 0x1c0
	// Line 1745, Address: 0x1bca50, Func Offset: 0x1d0
	// Line 1746, Address: 0x1bca64, Func Offset: 0x1e4
	// Line 1752, Address: 0x1bca68, Func Offset: 0x1e8
	// Line 1750, Address: 0x1bca6c, Func Offset: 0x1ec
	// Line 1752, Address: 0x1bca70, Func Offset: 0x1f0
	// Line 1758, Address: 0x1bca74, Func Offset: 0x1f4
	// Line 1746, Address: 0x1bca78, Func Offset: 0x1f8
	// Line 1747, Address: 0x1bca7c, Func Offset: 0x1fc
	// Line 1759, Address: 0x1bca80, Func Offset: 0x200
	// Line 1761, Address: 0x1bca84, Func Offset: 0x204
	// Line 1747, Address: 0x1bca88, Func Offset: 0x208
	// Line 1748, Address: 0x1bca8c, Func Offset: 0x20c
	// Line 1750, Address: 0x1bca94, Func Offset: 0x214
	// Line 1751, Address: 0x1bca98, Func Offset: 0x218
	// Line 1752, Address: 0x1bca9c, Func Offset: 0x21c
	// Line 1755, Address: 0x1bcaa8, Func Offset: 0x228
	// Line 1756, Address: 0x1bcab0, Func Offset: 0x230
	// Line 1755, Address: 0x1bcab4, Func Offset: 0x234
	// Line 1756, Address: 0x1bcac8, Func Offset: 0x248
	// Line 1755, Address: 0x1bcad4, Func Offset: 0x254
	// Line 1756, Address: 0x1bcad8, Func Offset: 0x258
	// Line 1757, Address: 0x1bcae0, Func Offset: 0x260
	// Line 1758, Address: 0x1bcae8, Func Offset: 0x268
	// Line 1759, Address: 0x1bcaf0, Func Offset: 0x270
	// Line 1761, Address: 0x1bcaf4, Func Offset: 0x274
	// Line 1762, Address: 0x1bcafc, Func Offset: 0x27c
	// Line 1763, Address: 0x1bcb08, Func Offset: 0x288
	// Line 1765, Address: 0x1bcb18, Func Offset: 0x298
	// Line 1772, Address: 0x1bcb20, Func Offset: 0x2a0
	// Line 1765, Address: 0x1bcb24, Func Offset: 0x2a4
	// Line 1766, Address: 0x1bcb2c, Func Offset: 0x2ac
	// Line 1767, Address: 0x1bcb3c, Func Offset: 0x2bc
	// Line 1769, Address: 0x1bcb4c, Func Offset: 0x2cc
	// Line 1772, Address: 0x1bcb58, Func Offset: 0x2d8
	// Line 1776, Address: 0x1bcb64, Func Offset: 0x2e4
	// Line 1777, Address: 0x1bcb78, Func Offset: 0x2f8
	// Line 1778, Address: 0x1bcb80, Func Offset: 0x300
	// Line 1779, Address: 0x1bcb84, Func Offset: 0x304
	// Line 1780, Address: 0x1bcb88, Func Offset: 0x308
	// Line 1781, Address: 0x1bcb90, Func Offset: 0x310
	// Line 1780, Address: 0x1bcb94, Func Offset: 0x314
	// Line 1782, Address: 0x1bcbb0, Func Offset: 0x330
	// Line 1784, Address: 0x1bcbb8, Func Offset: 0x338
	// Line 1787, Address: 0x1bcbbc, Func Offset: 0x33c
	// Line 1784, Address: 0x1bcbc4, Func Offset: 0x344
	// Line 1787, Address: 0x1bcbc8, Func Offset: 0x348
	// Line 1784, Address: 0x1bcbcc, Func Offset: 0x34c
	// Line 1785, Address: 0x1bcbd8, Func Offset: 0x358
	// Line 1786, Address: 0x1bcbec, Func Offset: 0x36c
	// Line 1787, Address: 0x1bcc00, Func Offset: 0x380
	// Line 1789, Address: 0x1bcc0c, Func Offset: 0x38c
	// Line 1791, Address: 0x1bcc14, Func Offset: 0x394
	// Line 1793, Address: 0x1bcc24, Func Offset: 0x3a4
	// Line 1794, Address: 0x1bcc2c, Func Offset: 0x3ac
	// Line 1795, Address: 0x1bcc30, Func Offset: 0x3b0
	// Line 1798, Address: 0x1bcc38, Func Offset: 0x3b8
	// Line 1796, Address: 0x1bcc3c, Func Offset: 0x3bc
	// Line 1798, Address: 0x1bcc40, Func Offset: 0x3c0
	// Line 1799, Address: 0x1bcc44, Func Offset: 0x3c4
	// Line 1800, Address: 0x1bcc48, Func Offset: 0x3c8
	// Line 1803, Address: 0x1bcc4c, Func Offset: 0x3cc
	// Line 1805, Address: 0x1bcc50, Func Offset: 0x3d0
	// Line 1803, Address: 0x1bcc54, Func Offset: 0x3d4
	// Line 1805, Address: 0x1bcc60, Func Offset: 0x3e0
	// Line 1810, Address: 0x1bcc6c, Func Offset: 0x3ec
	// Line 1811, Address: 0x1bcc88, Func Offset: 0x408
	// Func End, Address: 0x1bcca0, Func Offset: 0x420
    scePrintf("bhEne06_DG01 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_Die(BH_PWORK* epw)
{
    bhEne06_DeadMode2[epw->mode2](epw); 
}

// 100% matching!
void bhEne06_DD00(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 8;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x180000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        
        epw->ar = 0.0f;
        EXP0_F(0x6C) = 5.0f;
        
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;            
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 13;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD01(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 10;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;        
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));        
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;        
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 12;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;  
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 14;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD02(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY* mkfP;
	NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        
        epw->flg |= 0x200000;
        epw->flg &= ~0x580000;
        
        EXP0_F(0x1C) = epw->dvx;
        EXP0_F(0x20) = epw->dvy;
        EXP0_F(0x24) = epw->dvz;
        njUnitVector((NJS_VECTOR*)(epw->exp0 + 0x1C));        
        EXP0_F(0x20) *= 0.5f;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        bhEne_CallSE(epw, (NJS_VECTOR*)&epw->px, 8964);
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->flg &= ~0x80000;
            
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            mkfP += epw->frm_no / 65536;
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            
            epw->mode3++;
            epw->flg |= 0x200000;
        }

    case 2:
        if (!(epw->flg & 0x200000))
        {
            epw->mtn_no = 13;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 = 3;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.2f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x78;
            epw->mtn_add = 0;
            epw->mode3++;
            bhEne_BloodPool(epw, (NJS_VECTOR*)&epw->px, epw->ay, &BloodParam);
        }
    }

    epw->ax += (short)(-epw->ax) / 8;
}

// 100% matching!
void bhEne06_DD03(BH_PWORK* epw)
{
    O_WORK* owk;
	int i;
	
    switch (epw->mode3)
    {
    case 0:
        owk = epw->mlwP->owP;
        for (i = 0; i < 12U; i++)
        {
            owk[BrokenParts[i]].flg |= 3;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xC) = 1;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xE) = (i < 4);
        }
        
        epw->mlwP->objP[1].evalflags |= 8;
        epw->mlwP->objP[2].evalflags |= 8;
        
        epw->stflg |= 8;
        epw->flg &= ~0x78;
        epw->flg |= 0x8000;
        
        epw->mtn_add = 0;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8960);
        epw->mode3++;        
    } 
}

// 100% matching!
void bhEne06_DD04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->frm_no = 0;
        epw->mtn_add = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->flg |= 2;
        epw->flg &= ~0x28;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;
    }
}

// 100% matching!
void bhEne06_SearchPlayer(BH_PWORK* epw)
{
    float dx;
    float dz;
    
    EXP0_C(0x16) = 0;
    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0) = njSqrt(dx * dx + dz * dz);
    EXP0_C(0x16) = 1;
}

// 100% matching!
void bhEne06_CollisionWalls(BH_PWORK* epw)
{
    NJS_VECTOR ofp;
    NJS_VECTOR trans;
    NJS_MKEY_A_MOD* mkaP;
	NJS_CNK_OBJECT* objP;
	
    epw->ar += (EXP0_F(0x6C) - epw->ar) / 8.0f;
    if (epw->flg & 0x400000)
    {
        ofp.z = 0.0f;
        ofp.y = 0.0f;
        ofp.x = 0.0f;
    } 
    else
    {
        ofp.z = 0.0f;
        ofp.x = 0.0f;
        ofp.y = epw->ar;
        if (epw->flg & 0x100000)
        {
            mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            mkaP += (epw->frm_no / 65536); 
            
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
            njCalcVector(NULL, &ofp, &ofp);
        }
    }
    objP = epw->mlwP->objP;
    trans.x = objP->pos[0];
    trans.y = objP->pos[1];
    trans.z = objP->pos[2];
    
    if (!(epw->flg & 0x80000))
    {
        trans.y = 0.0f;
    }
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &trans, &trans);
    
    epw->px += trans.x;
    epw->py += trans.y;
    epw->pz += trans.z;
    
    epw->px += ofp.x;
    epw->py += ofp.y;
    epw->pz += ofp.z;
    
    *(ATR_WORK**)((char *)epw->exp0 + 0x18) = bhEne03_Collision(epw);
    
    epw->px -= ofp.x;
    epw->py -= ofp.y;
    epw->pz -= ofp.z;
    
    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;
}

// 100% matching!
void bhEne06_FloorCollision(BH_PWORK* epw)
{
    ATR_WORK* hp;

    hp = (ATR_WORK*)bhCollisionCheckLine((NJS_VECTOR*)&epw->pxb, (NJS_VECTOR*)&epw->px);
    
    if (hp != NULL)
    {
        bhGetHitCollisionNormal((NJS_VECTOR*)((char *)epw->exp0 + 0x78));
        njUnitVector((NJS_VECTOR*)((char *)epw->exp0 + 0x78));
        *(ATR_WORK**)((char *)epw->exp0 + 0x18) = hp;
        
        if (EXP0_F(0x7C) > 0.9f)
        {
            epw->flg &= ~0x200000; 
            
            if (hp->type == 7)
            {
                if (hp->py > epw->py)
                {
                    epw->py = hp->py;
                }
            } 
            else
            {
                float tmp = hp->py + ((hp->h) ? hp->h : rom->h);
                if (tmp > epw->py)
                {
                    epw->py = tmp;
                }
            }
        }
        
        if (EXP0_F(0x7C) < -0.9f)
        {
            EXP0_I(0x20) = 0;
        }
        
        if (fabsf(EXP0_F(0x7C)) < 0.3f)
        {
            EXP0_I(0x1C) = 0;
            EXP0_I(0x24) = 0;
        }
    }
}

// 100% matching!
int bhEne06_CheckLeaningWall(BH_PWORK* epw)
{
	NJS_VECTOR vec;
	NJS_POINT3 pos;
	ATR_WORK* hp;
	NJS_VECTOR n; 
	BH_PWORK* ep;
	float dist;    
	int i;

    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = -10.0f;
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &vec, &vec);
    ep = ene;
    i = 0;
    pos.x = epw->px + vec.x;
    pos.y = epw->py;
    pos.z = epw->pz + vec.z;

    while (i < sys->ewk_n)
    {
        if ((ep->flg & 1) && (ep->id == 6) && (ep != epw))
        {
            dist = njDistanceP2P((NJS_POINT3*)&ep->px, &pos);
            if (dist < 10.0f)
            {
                return 0;
            }
        }
        
        i++;
        ep++;
    }

    hp = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &pos);
    if ((hp != NULL) && !(hp->attr & 8))
    {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        epw->ayp = bhArcTan2(n.x, n.z);
        EXP0_F(0x28) = pos.x + n.x;
        EXP0_F(0x2C) = pos.y + n.y;
        EXP0_F(0x30) = pos.z + n.z;
        return 1;
    }

    return 0;
}


// 
// Start address: 0x1bded0
int bhEne06_AvoidWall(BH_PWORK* epw, int dir)
{
	//npobj* objP;
	float wdist;
	float dist;
	BH_PWORK* ep2;
	BH_PWORK* ep;
	int i;
	//_anon20* mkaP;
	int ret;
	//_anon35 trans;
	//_anon35 ofp;
	//_anon22* hp2;
	//_anon22* hp1;
	//_anon35 pos2;
	//_anon35 pos1;
	// Line 2410, Address: 0x1bded0, Func Offset: 0
	// Line 2425, Address: 0x1bdefc, Func Offset: 0x2c
	// Line 2410, Address: 0x1bdf04, Func Offset: 0x34
	// Line 2415, Address: 0x1bdf10, Func Offset: 0x40
	// Line 2424, Address: 0x1bdf14, Func Offset: 0x44
	// Line 2425, Address: 0x1bdf18, Func Offset: 0x48
	// Line 2426, Address: 0x1bdf20, Func Offset: 0x50
	// Line 2427, Address: 0x1bdf40, Func Offset: 0x70
	// Line 2430, Address: 0x1bdf64, Func Offset: 0x94
	// Line 2431, Address: 0x1bdf88, Func Offset: 0xb8
	// Line 2432, Address: 0x1bdfa0, Func Offset: 0xd0
	// Line 2433, Address: 0x1bdfa4, Func Offset: 0xd4
	// Line 2436, Address: 0x1bdfa8, Func Offset: 0xd8
	// Line 2438, Address: 0x1bdfd0, Func Offset: 0x100
	// Line 2439, Address: 0x1be004, Func Offset: 0x134
	// Line 2440, Address: 0x1be01c, Func Offset: 0x14c
	// Line 2441, Address: 0x1be030, Func Offset: 0x160
	// Line 2442, Address: 0x1be038, Func Offset: 0x168
	// Line 2452, Address: 0x1be050, Func Offset: 0x180
	// Line 2453, Address: 0x1be064, Func Offset: 0x194
	// Line 2454, Address: 0x1be06c, Func Offset: 0x19c
	// Line 2455, Address: 0x1be074, Func Offset: 0x1a4
	// Line 2456, Address: 0x1be07c, Func Offset: 0x1ac
	// Line 2457, Address: 0x1be080, Func Offset: 0x1b0
	// Line 2456, Address: 0x1be084, Func Offset: 0x1b4
	// Line 2457, Address: 0x1be088, Func Offset: 0x1b8
	// Line 2459, Address: 0x1be098, Func Offset: 0x1c8
	// Line 2460, Address: 0x1be0a0, Func Offset: 0x1d0
	// Line 2462, Address: 0x1be0a4, Func Offset: 0x1d4
	// Line 2459, Address: 0x1be0a8, Func Offset: 0x1d8
	// Line 2460, Address: 0x1be0c0, Func Offset: 0x1f0
	// Line 2462, Address: 0x1be0d0, Func Offset: 0x200
	// Line 2463, Address: 0x1be0d8, Func Offset: 0x208
	// Line 2464, Address: 0x1be0e4, Func Offset: 0x214
	// Line 2465, Address: 0x1be0f8, Func Offset: 0x228
	// Line 2471, Address: 0x1be108, Func Offset: 0x238
	// Line 2474, Address: 0x1be10c, Func Offset: 0x23c
	// Line 2478, Address: 0x1be110, Func Offset: 0x240
	// Line 2471, Address: 0x1be114, Func Offset: 0x244
	// Line 2473, Address: 0x1be118, Func Offset: 0x248
	// Line 2474, Address: 0x1be120, Func Offset: 0x250
	// Line 2475, Address: 0x1be128, Func Offset: 0x258
	// Line 2478, Address: 0x1be134, Func Offset: 0x264
	// Line 2480, Address: 0x1be148, Func Offset: 0x278
	// Line 2481, Address: 0x1be154, Func Offset: 0x284
	// Line 2482, Address: 0x1be160, Func Offset: 0x290
	// Line 2488, Address: 0x1be170, Func Offset: 0x2a0
	// Line 2489, Address: 0x1be17c, Func Offset: 0x2ac
	// Line 2492, Address: 0x1be180, Func Offset: 0x2b0
	// Line 2489, Address: 0x1be184, Func Offset: 0x2b4
	// Line 2488, Address: 0x1be188, Func Offset: 0x2b8
	// Line 2490, Address: 0x1be18c, Func Offset: 0x2bc
	// Line 2493, Address: 0x1be190, Func Offset: 0x2c0
	// Line 2488, Address: 0x1be194, Func Offset: 0x2c4
	// Line 2494, Address: 0x1be198, Func Offset: 0x2c8
	// Line 2488, Address: 0x1be1a0, Func Offset: 0x2d0
	// Line 2489, Address: 0x1be1a4, Func Offset: 0x2d4
	// Line 2492, Address: 0x1be1b0, Func Offset: 0x2e0
	// Line 2490, Address: 0x1be1b4, Func Offset: 0x2e4
	// Line 2489, Address: 0x1be1b8, Func Offset: 0x2e8
	// Line 2490, Address: 0x1be1c4, Func Offset: 0x2f4
	// Line 2492, Address: 0x1be1dc, Func Offset: 0x30c
	// Line 2490, Address: 0x1be1e0, Func Offset: 0x310
	// Line 2491, Address: 0x1be1e4, Func Offset: 0x314
	// Line 2492, Address: 0x1be1ec, Func Offset: 0x31c
	// Line 2493, Address: 0x1be1f8, Func Offset: 0x328
	// Line 2494, Address: 0x1be1fc, Func Offset: 0x32c
	// Line 2504, Address: 0x1be208, Func Offset: 0x338
	// Line 2505, Address: 0x1be210, Func Offset: 0x340
	// Line 2506, Address: 0x1be218, Func Offset: 0x348
	// Line 2505, Address: 0x1be220, Func Offset: 0x350
	// Line 2507, Address: 0x1be224, Func Offset: 0x354
	// Line 2505, Address: 0x1be228, Func Offset: 0x358
	// Line 2506, Address: 0x1be234, Func Offset: 0x364
	// Line 2507, Address: 0x1be250, Func Offset: 0x380
	// Line 2509, Address: 0x1be26c, Func Offset: 0x39c
	// Line 2510, Address: 0x1be284, Func Offset: 0x3b4
	// Line 2509, Address: 0x1be288, Func Offset: 0x3b8
	// Line 2510, Address: 0x1be290, Func Offset: 0x3c0
	// Line 2511, Address: 0x1be2a8, Func Offset: 0x3d8
	// Line 2512, Address: 0x1be2c0, Func Offset: 0x3f0
	// Line 2511, Address: 0x1be2c8, Func Offset: 0x3f8
	// Line 2512, Address: 0x1be2cc, Func Offset: 0x3fc
	// Line 2524, Address: 0x1be2d8, Func Offset: 0x408
	// Line 2528, Address: 0x1be2e0, Func Offset: 0x410
	// Line 2524, Address: 0x1be2e8, Func Offset: 0x418
	// Line 2526, Address: 0x1be2ec, Func Offset: 0x41c
	// Line 2524, Address: 0x1be2f0, Func Offset: 0x420
	// Line 2530, Address: 0x1be2f4, Func Offset: 0x424
	// Line 2524, Address: 0x1be2fc, Func Offset: 0x42c
	// Line 2525, Address: 0x1be304, Func Offset: 0x434
	// Line 2526, Address: 0x1be31c, Func Offset: 0x44c
	// Line 2528, Address: 0x1be334, Func Offset: 0x464
	// Line 2526, Address: 0x1be338, Func Offset: 0x468
	// Line 2527, Address: 0x1be33c, Func Offset: 0x46c
	// Line 2528, Address: 0x1be344, Func Offset: 0x474
	// Line 2529, Address: 0x1be350, Func Offset: 0x480
	// Line 2530, Address: 0x1be354, Func Offset: 0x484
	// Line 2540, Address: 0x1be35c, Func Offset: 0x48c
	// Line 2541, Address: 0x1be364, Func Offset: 0x494
	// Line 2542, Address: 0x1be36c, Func Offset: 0x49c
	// Line 2541, Address: 0x1be374, Func Offset: 0x4a4
	// Line 2543, Address: 0x1be378, Func Offset: 0x4a8
	// Line 2541, Address: 0x1be37c, Func Offset: 0x4ac
	// Line 2542, Address: 0x1be388, Func Offset: 0x4b8
	// Line 2543, Address: 0x1be3a4, Func Offset: 0x4d4
	// Line 2545, Address: 0x1be3c0, Func Offset: 0x4f0
	// Line 2546, Address: 0x1be3d8, Func Offset: 0x508
	// Line 2545, Address: 0x1be3dc, Func Offset: 0x50c
	// Line 2546, Address: 0x1be3e4, Func Offset: 0x514
	// Line 2547, Address: 0x1be3fc, Func Offset: 0x52c
	// Line 2548, Address: 0x1be414, Func Offset: 0x544
	// Line 2547, Address: 0x1be41c, Func Offset: 0x54c
	// Line 2548, Address: 0x1be420, Func Offset: 0x550
	// Line 2560, Address: 0x1be428, Func Offset: 0x558
	// Line 2561, Address: 0x1be438, Func Offset: 0x568
	// Line 2562, Address: 0x1be450, Func Offset: 0x580
	// Line 2561, Address: 0x1be454, Func Offset: 0x584
	// Line 2562, Address: 0x1be458, Func Offset: 0x588
	// Line 2564, Address: 0x1be460, Func Offset: 0x590
	// Line 2565, Address: 0x1be470, Func Offset: 0x5a0
	// Line 2566, Address: 0x1be480, Func Offset: 0x5b0
	// Line 2567, Address: 0x1be494, Func Offset: 0x5c4
	// Line 2568, Address: 0x1be49c, Func Offset: 0x5cc
	// Line 2570, Address: 0x1be4bc, Func Offset: 0x5ec
	// Line 2571, Address: 0x1be4c8, Func Offset: 0x5f8
	// Line 2570, Address: 0x1be4cc, Func Offset: 0x5fc
	// Line 2573, Address: 0x1be4d8, Func Offset: 0x608
	// Line 2574, Address: 0x1be4e8, Func Offset: 0x618
	// Line 2575, Address: 0x1be4f8, Func Offset: 0x628
	// Line 2576, Address: 0x1be514, Func Offset: 0x644
	// Line 2577, Address: 0x1be51c, Func Offset: 0x64c
	// Line 2579, Address: 0x1be534, Func Offset: 0x664
	// Line 2580, Address: 0x1be540, Func Offset: 0x670
	// Line 2579, Address: 0x1be544, Func Offset: 0x674
	// Line 2584, Address: 0x1be550, Func Offset: 0x680
	// Line 2585, Address: 0x1be568, Func Offset: 0x698
	// Line 2584, Address: 0x1be56c, Func Offset: 0x69c
	// Line 2585, Address: 0x1be574, Func Offset: 0x6a4
	// Line 2586, Address: 0x1be598, Func Offset: 0x6c8
	// Line 2587, Address: 0x1be5b0, Func Offset: 0x6e0
	// Line 2586, Address: 0x1be5bc, Func Offset: 0x6ec
	// Line 2587, Address: 0x1be5c0, Func Offset: 0x6f0
	// Line 2588, Address: 0x1be5dc, Func Offset: 0x70c
	// Line 2589, Address: 0x1be5f4, Func Offset: 0x724
	// Line 2588, Address: 0x1be5f8, Func Offset: 0x728
	// Line 2596, Address: 0x1be600, Func Offset: 0x730
	// Line 2597, Address: 0x1be604, Func Offset: 0x734
	// Func End, Address: 0x1be638, Func Offset: 0x768
    scePrintf("bhEne06_AvoidWall - UNIMPLEMENTED!\n");
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_PlayerControl(BH_PWORK* epw)
{
    // Not present in DWARF
    float dx, dz;

    switch (plp->mode2)
    {
    case 0:
        break;
    default:
        return;
    }

    switch (plp->mode3)
    {        
    case 0:
        plp->flg &= ~0x40000;
        plp->flg |= 0x10004;
        plp->mnwP = epw->mnwP;
        plp->mtn_no = 20;
        plp->frm_no = 0;
        plp->hokan_count = 5;
        plp->hokan_rate = 52428;
        plp->mtn_add = 65536;
        plp->ct1 = 8;
        plp->mode3++;
        break;
        
    case 1:

        if (plp->ct1 > 0)
        {
            plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
            plp->ct1--;
        }
        if (plp->frm_no == 0)
        {
            plp->mnwP = plp->mnwPb;
            
            plp->flg &= ~0x10004;
            plp->flg |= 8;
            plp->at_flg = 0;
            plp->stflg &= ~0x10000;
            
            *(int*)&plp->mode0 = 1;
            *(int*)epw->exp1 &= ~1;
        }
        
        dx = plp->mlwP->owP[5].mtx[12] - plp->px;
        dz = plp->mlwP->owP[5].mtx[14] - plp->pz;
        
        plp->px += dx;
        plp->pz += dz;
        
        bhCheckWall(plp);
        
        plp->px -= dx;
        plp->pz -= dz;
    }
}

#pragma divbyzerocheck off

// 99.95% matching
void bhEne06_SetRinpunEffect(BH_PWORK* epw, int num, int flg)
{
    int eno;
	float size;
	
    while (0 < num)
    {
        sys->ef.id = 260;
        sys->ef.flg = 1;
        sys->ef.type = flg;
        size = 0.6f + (0.4f * njRandom());
        sys->ef.sy = sys->ef.sx = size;
        sys->ef.sz = 1.0f;
        sys->ef.ay = (int)((epw->ay + 18204) + (29127.0f * njRandom()));
        size = 8.0f * njRandom();
        sys->ef.px = epw->px - (size * njSin(sys->ef.ay));
        sys->ef.pz = epw->pz - (size * njCos(sys->ef.ay));
        sys->ef.py = (epw->py + (8.0f * njRandom())) - 4.0f;
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {            
            eff[eno].stflg |= 0x20;            
            eff[eno].txp[0] = epw->mdl[1].texP;
            eff[eno].tex_id = 1;            
        }
        break;
    }     
}

// 100% matching!
void bhEne06_HitMark(BH_PWORK* epw)
{
	int i;
	int range;
	BLOOD_TBL* blp;    
	NJS_POINT3 ofp;

    blp = &BloodTbl[epw->djnt_no];   
	i = 0;
	if (epw->comb_flg & 0x10) i = 0;
	if (epw->comb_flg & 0x20) i = 1;
	if (epw->comb_flg & 0x40) i = 2;
    
    if (DmgReact[epw->wpnr_no].type[i] >= 0)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[i], epw->djnt_no, &ofp, 0);
        if (DmgReact[epw->wpnr_no].bloodstain[i] != 0)
        {
            bhEne_SetBloodstain(epw, 0, epw->djnt_no, &ofp);
        }
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0))
    {
        range = 0;
        do
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;
            ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
            ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * njRandom()), (int)(40.0f * njRandom()) + 20);
            range++;
        } while (range < 4);
    }
    
    if (DmgReact[epw->wpnr_no].exef & 2)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        ofp.x += ((blp->rx * njRandom()) - (blp->rx / 2.0f));
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if (DmgReact[epw->wpnr_no].exef & 4)
    {
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF201010U);
        epw->mdflg |= 0x400;
    }
}

// 100% matching!
int bhEne06_DeadCheck(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_VECTOR vec;
    int ang;
    int w;
    float mov;
    O_WORK* owk;
    int i;     
    int joint[2] = { 11, 15 };

    for (i = 0; i < 2; i++)
    {
        owk = &plp->mlwP->owP[joint[i]];
        pos.x = owk->mtx[12];
        pos.y = owk->mtx[13];
        pos.z = owk->mtx[14];
        
        vec.x = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x88)) - pos.x;
        vec.y = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x8C)) - pos.y;
        vec.z = (*(float *)((char *)epw->exp0 + ((i) * 12) + 0x90)) - pos.z;
        
        mov = njScalor(&vec);

        w = bhArcTan2(owk->mtx[8], owk->mtx[10]);

        ang = (short)(w - *(int *)((char *)epw->exp0 + ((i) * 4) + 0xA0));
        if (ang < 0)
        {
            ang = -ang;
        }

        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x88) = pos.x;
        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x8C) = pos.y;
        *(float *)((char *)epw->exp0 + ((i) * 12) + 0x90) = pos.z;
       
        *(int *)((char *)epw->exp0 + ((i) * 4) + 0xA0) = w;
    
        if ((mov > 0.1f || 182 < ang) && (njDistanceP2P((NJS_POINT3*)&epw->px, &pos) < 2.0f))
        {
            return 1;            
        }
    }
    return 0;
}
